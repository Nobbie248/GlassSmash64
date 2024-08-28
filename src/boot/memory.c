#include <PR/ultratypes.h>

#include "sm64.h"

#include "buffers/buffers.h"
#include "slidec.h"
#include "game/emutest.h"
#include "game/game_init.h"
#include "game/main.h"
#include "game/memory.h"
#include "segment_symbols.h"
#include "segments.h"
#ifdef GZIP
#include "aplib.h"
#endif
#ifdef RNC1
#include "shrinkler.h"
#endif
#if defined(RNC1) || defined(RNC2)
#include <rnc.h>
#endif
#ifdef UNF
#include "usb/usb.h"
#include "usb/debug.h"
#endif
#include "game/puppyprint.h"

#include "memory_layout.h"

#define	DOWN(s, align)	(((u32)(s)) & ~((align)-1))
#define DOWN4(s) DOWN(s, 4)

#ifndef MAIN_POOL_SINGLE_REGION

#if MEMORY_FRAGMENTATION_NO_FRAGMENTATION == MEMORY_FRAGMENTATION_LEVEL
// One giant region encompassing all of the ram. Memory layout follows vanilla implementation
// -zbuffer-|-game/engine data-|-framebuffers-|-main pool region-
#define MAIN_POOL_REGIONS_COUNT 1
#endif

#if MEMORY_FRAGMENTATION_ZBUFFER_AND_FRAMEBUFFERS == MEMORY_FRAGMENTATION_LEVEL
// Region before zbuffer and region after the framebuffer2
// -game/engine data-|-main pool region 0-|-zbuffer-|-framebuffers-|-main pool region 1-
//                                                  ^
//                                       0x80300000 or 0x80700000
#define MAIN_POOL_REGIONS_COUNT 2
#endif

#if MEMORY_FRAGMENTATION_ZBUFFER_AND_FRAMEBUFFERS_SPLIT == MEMORY_FRAGMENTATION_LEVEL
// Region after 0x80600000, before zbuffer, after the framebuffer2
// -game/engine data-|-main pool region 1-|-zbuffer-|-framebuffers-|-main pool region 1-|-main pool region 0-
//                                                  ^                                   ^
//                                             0x80500000                          0x80600000
#define MAIN_POOL_REGIONS_COUNT 3
#endif

#if MEMORY_FRAGMENTATION_ZBUFFER_AND_EACH_FRAMEBUFFER == MEMORY_FRAGMENTATION_LEVEL
// Region before zbuffer, between fb0/fb1, after fb2
// -game/engine data-|-main pool region 0-|-zb-|-fb0-|-main pool region 1-|-fb1-|-fb2-|-main pool region 2-
//                                             ^                                ^
//                                        0x80500000                       0x80700000
#define MAIN_POOL_REGIONS_COUNT 3
#endif

#else
#define MAIN_POOL_REGIONS_COUNT 1
#endif

struct MainPoolContext {
    struct MainPoolRegion regions[MAIN_POOL_REGIONS_COUNT];
};

struct MainPoolState {
    struct MainPoolContext ctx;
    struct MainPoolState* prev;
};

// Multichar constants AL and AR
#define MAIN_POOL_FREEABLE_HEADER_MAGIC_LEFT 0x414c
#define MAIN_POOL_FREEABLE_HEADER_MAGIC_RIGHT 0x4152

struct MainPoolFreeableHeader {
    u16 magic;
    u16 id;
    // either a pointer to 'start' or 'end'
    u8* ptr;
    u8 data[0];
};

struct MemoryBlock {
    struct MemoryBlock *next;
    u32 size;
};

struct MemoryPool {
    u32 totalSpace;
    struct MemoryBlock *firstBlock;
    struct MemoryBlock freeList;
};

extern uintptr_t sSegmentTable[32];


/**
 * Memory pool for small graphical effects that aren't connected to Objects.
 * Used for colored text, paintings, and environmental snow and bubbles.
 */
struct MemoryPool *gEffectsMemoryPool __attribute__((section(".data")));



uintptr_t sSegmentTable[32];
uintptr_t sSegmentROMTable[32];
#ifndef MAIN_POOL_SINGLE_REGION
static struct MainPoolContext sMainPool;
struct MainPoolRegion* gMainPoolCurrentRegion;
#else
struct MainPoolContext sMainPool;
#endif

static struct MainPoolState *gMainPoolState = NULL;

uintptr_t set_segment_base_addr(s32 segment, void *addr) {
    sSegmentTable[segment] = ((uintptr_t) addr & 0x1FFFFFFF);
    return sSegmentTable[segment];
}

UNUSED void *get_segment_base_addr(s32 segment) {
    return (void *) (sSegmentTable[segment] | 0x80000000);
}

#ifndef NO_SEGMENTED_MEMORY
void *segmented_to_virtual(const void *addr) {
    if ((intptr_t) addr < 0)
        return addr;

    size_t segment = ((uintptr_t) addr >> 24);
    size_t offset  = ((uintptr_t) addr & 0x00FFFFFF);

    return (void *) ((sSegmentTable[segment] + offset) | 0x80000000);
}

void *virtual_to_segmented(u32 segment, const void *addr) {
    size_t offset = ((uintptr_t) addr & 0x1FFFFFFF) - sSegmentTable[segment];

    return (void *) ((segment << 24) + offset);
}

void move_segment_table_to_dmem(void) {
    Gfx *tempGfxHead = gDisplayListHead;

    for (s32 i = 0; i < 16; i++) {
        gSPSegment(tempGfxHead++, i, sSegmentTable[i]);
    }

    gDisplayListHead = tempGfxHead;
}
#else
void *segmented_to_virtual(const void *addr) {
    return (void *) addr;
}

void *virtual_to_segmented(u32 segment, const void *addr) {
    return (void *) addr;
}

void move_segment_table_to_dmem(void) {
}
#endif

extern u8 _framebuffer2SegmentBssEnd[];
extern u8 _goddardSegmentStart[];
extern u8 _sbssSegmentBssEnd[];

#define ZBUFFER_END ZBUFFER_START + RENDER_BUFFER_BUFFER_SIZE
#define FRAMEBUFFER0_END FRAMEBUFFER0_START + RENDER_BUFFER_BUFFER_SIZE
#define FRAMEBUFFER1_END FRAMEBUFFER1_START + RENDER_BUFFER_BUFFER_SIZE
#define FRAMEBUFFER2_END FRAMEBUFFER2_START + RENDER_BUFFER_BUFFER_SIZE

extern u8 _poolStart[];

/**
 * Initialize the main memory pool. This pool is conceptually regions
 * that grow inward from the left and right. It therefore only supports
 * freeing the object that was most recently allocated from a side.
 */
void main_pool_init() {
#define SET_REGION(id, bufStart, bufEnd) \
    sMainPool.regions[id].start = (u8 *) ALIGN4((uintptr_t)(bufStart)); \
    sMainPool.regions[id].end = (u8 *) DOWN4((uintptr_t)(bufEnd));

#if MEMORY_FRAGMENTATION_NO_FRAGMENTATION == MEMORY_FRAGMENTATION_LEVEL
    // One giant region encompassing all of the ram
    SET_REGION(0, _framebuffer2SegmentBssEnd, _goddardSegmentStart);
#endif

#if MEMORY_FRAGMENTATION_ZBUFFER_AND_FRAMEBUFFERS == MEMORY_FRAGMENTATION_LEVEL
    // Region before zbuffer and region after the framebuffer2
    SET_REGION(0, _poolStart, ZBUFFER_START);
#ifndef MAIN_POOL_SINGLE_REGION
    SET_REGION(1, FRAMEBUFFER2_END, _goddardSegmentStart);
#endif
#endif

#if MEMORY_FRAGMENTATION_ZBUFFER_AND_FRAMEBUFFERS_SPLIT == MEMORY_FRAGMENTATION_LEVEL
    // Regions before zbuffer, after the framebuffer2, between zbuffer and framebuffer0
    SET_REGION(0, 0x80600000, _goddardSegmentStart);
#ifndef MAIN_POOL_SINGLE_REGION
    SET_REGION(1, _poolStart, ZBUFFER_START);
    SET_REGION(2, FRAMEBUFFER2_END, 0x80600000);
#endif
#endif

#if MEMORY_FRAGMENTATION_ZBUFFER_AND_EACH_FRAMEBUFFER == MEMORY_FRAGMENTATION_LEVEL
    // Region before zbuffer, between fb0/fb1, after fb2
    SET_REGION(0, _poolStart, GFXFIFO_START);
#ifndef MAIN_POOL_SINGLE_REGION
    SET_REGION(1, FRAMEBUFFER0_END, FRAMEBUFFER1_START);
    SET_REGION(2, FRAMEBUFFER2_END, _goddardSegmentStart);
#endif
#endif

#undef SET_REGION

#ifndef MAIN_POOL_SINGLE_REGION
    gMainPoolCurrentRegion = &sMainPool.regions[0];
#endif

#ifdef PUPPYPRINT_DEBUG
    mempool = main_pool_available();
#endif
}

// all 'try_alloc' functions expect size to be ALIGN4

// takes the at least first 'size' bytes from 'region' and return pointer aligned on 'alignment'
static void* main_pool_region_try_alloc_from_start_aligned(struct MainPoolRegion* region, u32 size, u32 alignment) {
    u8* ret = (u8*) ALIGN(region->start, alignment);
    u8* newStart = ret + size;
    u8* regionEnd = region->end;
    if (newStart > regionEnd)
        return NULL;

    size = newStart - region->start;
    region->start = newStart;
    return ret;
}

static void* main_pool_region_try_alloc_from_end_freeable(struct MainPoolRegion* region, u8 id, u32 sizeWithHeader) {
    u32 size = region->end - region->start;
    if (size < sizeWithHeader)
        return NULL;

    u8* regionEnd = region->end;

    struct MainPoolFreeableHeader* header = (struct MainPoolFreeableHeader*) (regionEnd - sizeWithHeader);
    header->magic = MAIN_POOL_FREEABLE_HEADER_MAGIC_RIGHT;
    header->id = id;
    header->ptr = regionEnd;

    region->end -= sizeWithHeader;

    return header->data;
}

static void* main_pool_region_try_alloc_from_end_aligned_freeable(struct MainPoolRegion* region, u8 id, u32 size, u32 alignment) {
    u8* region_end = region->end;
    u8* new_end = (u8*) DOWN(region_end - size, alignment) - sizeof(struct MainPoolFreeableHeader);
    if (new_end < region->start)
        return NULL;

    size = region_end - new_end;

    struct MainPoolFreeableHeader* header = (struct MainPoolFreeableHeader*) new_end;
    header->magic = MAIN_POOL_FREEABLE_HEADER_MAGIC_RIGHT;
    header->id = id;
    header->ptr = region_end;

    region->end -= size;

    return header->data;
}

void *main_pool_alloc_slow(u32 size) {
#ifndef MAIN_POOL_SINGLE_REGION
    gMainPoolCurrentRegion = NULL;
#endif

    for (int i = 0; i < MAIN_POOL_REGIONS_COUNT; i++) {
        struct MainPoolRegion* region = &sMainPool.regions[i];
#ifndef MAIN_POOL_SINGLE_REGION
        // Find region that has at least 'MAIN_POOL_SMALL_ALLOC_LIMIT' bytes left
        if (!gMainPoolCurrentRegion && region->end - region->start >= MAIN_POOL_SMALL_ALLOC_LIMIT)
            gMainPoolCurrentRegion = region;
#endif

        void* ret = main_pool_region_try_alloc_from_start(region, size);
        if (__builtin_expect(!ret, 0))
            continue;

        return ret;
    }

    DEBUG_ASSERT("Failed to allocate memory");
    return NULL;
}

void *main_pool_alloc_aligned(u32 size, u32 alignment) {
    if (!alignment)
        alignment = 16;

    size = ALIGN4(size);
    for (int i = 0; i < MAIN_POOL_REGIONS_COUNT; i++) {
        struct MainPoolRegion* region = &sMainPool.regions[i];
        void* ret = main_pool_region_try_alloc_from_start_aligned(region, size, alignment);
        if (!ret)
            continue;

        return ret;
    }

    DEBUG_ASSERT("Failed to allocate memory");
    return NULL;
}

void *main_pool_alloc_freeable(u32 size) {
    size = ALIGN4(size) + sizeof(struct MainPoolFreeableHeader);
    for (int i = 0; i < MAIN_POOL_REGIONS_COUNT; i++) {
        struct MainPoolRegion* region = &sMainPool.regions[i];
        void* ret = main_pool_region_try_alloc_from_end_freeable(region, i, size);
        if (!ret)
            continue;

        return ret;
    }

    DEBUG_ASSERT("Failed to allocate memory");
    return NULL;
}

void *main_pool_alloc_aligned_freeable(u32 size, u32 alignment) {
    if (!alignment)
        alignment = 16;

    size = ALIGN4(size);
    for (int i = 0; i < MAIN_POOL_REGIONS_COUNT; i++) {
        struct MainPoolRegion* region = &sMainPool.regions[i];
        void* ret = main_pool_region_try_alloc_from_end_aligned_freeable(region, i, size, alignment);
        if (!ret)
            continue;

        return ret;
    }

    DEBUG_ASSERT("Failed to allocate memory");
    return NULL;
}

/**
 * Free a block of memory that was allocated from the pool. The block must be
 * the most recently allocated block from its end of the pool, otherwise all
 * newer blocks are freed as well.
 */
void main_pool_free(void *addr) {
    const struct MainPoolFreeableHeader* header = (struct MainPoolFreeableHeader*) ((u8*) addr - sizeof(struct MainPoolFreeableHeader));
    if (header->magic == MAIN_POOL_FREEABLE_HEADER_MAGIC_RIGHT) {
        struct MainPoolRegion* region = &sMainPool.regions[header->id];
        region->end = header->ptr;
    } else {
        DEBUG_ASSERT("Incorrect magic for free");
    }
}

/**
 * Return the size of the largest block that can currently be allocated from the
 * pool.
 */
u32 main_pool_available(void) {
    s32 size = 0;
    for (int i = 0; i < MAIN_POOL_REGIONS_COUNT; i++) {
        struct MainPoolRegion* region = &sMainPool.regions[i];
        size += region->end - region->start;
    }

    return size;
}

/**
 * Push pool state, to be restored later. Return the amount of free space left
 * in the pool.
 */
void main_pool_push_state(void) {
    struct MainPoolState *prevState = gMainPoolState;
    struct MainPoolContext ctx = sMainPool;

    gMainPoolState = main_pool_alloc(sizeof(*gMainPoolState));
    gMainPoolState->ctx = ctx;
    gMainPoolState->prev = prevState;
}

/**
 * Restore pool state from a previous call to main_pool_push_state. Return the
 * amount of free space left in the pool.
 */
void main_pool_pop_state(void) {
    sMainPool = gMainPoolState->ctx;
    gMainPoolState = gMainPoolState->prev;
}

/**
 * Perform a DMA read from ROM. The transfer is split into 4KB blocks, and this
 * function blocks until completion.
 */
void dma_read(u8 *dest, u8 *srcStart, u8 *srcEnd) {
    u32 size = ALIGN16(srcEnd - srcStart);

    osInvalDCache(dest, size);
    while (size != 0) {
        u32 copySize = (size >= 0x1000) ? 0x1000 : size;

        osPiStartDma(&gDmaIoMesg, OS_MESG_PRI_NORMAL, OS_READ, (uintptr_t) srcStart, dest, copySize,
                     &gDmaMesgQueue);
        osRecvMesg(&gDmaMesgQueue, &gMainReceivedMesg, OS_MESG_BLOCK);

        dest += copySize;
        srcStart += copySize;
        size -= copySize;
    }
}

struct DMAContext {
    u8* srcStart;
    u8* dest;
    u32 size;
};

// Starts to DMA the first block
static void dma_ctx_init(struct DMAContext* ctx, u8 *dest, u8 *srcStart, u8 *srcEnd) {
    u32 size = ALIGN16(srcEnd - srcStart);
    osInvalDCache(dest, size);

    u32 copySize = (size >= 0x1000) ? 0x1000 : size;

    osPiStartDma(&gDmaIoMesg, OS_MESG_PRI_NORMAL, OS_READ, (uintptr_t) srcStart, dest, copySize, &gDmaMesgQueue);

    dest += copySize;
    srcStart += copySize;
    size -= copySize;
    
    ctx->srcStart = srcStart;
    ctx->dest = dest;
    ctx->size = size;
}

// Starts to DMA the next block and waits for the previous block
void* dma_read_ctx(struct DMAContext* ctx) {
    // wait for the previous DMA issued
    osRecvMesg(&gDmaMesgQueue, &gMainReceivedMesg, OS_MESG_BLOCK);

    // start the new DMA transfer
    u32 copySize = (ctx->size >= 0x1000) ? 0x1000 : ctx->size;
    if (copySize == 0) {
        // we are done, return a dummy address that is so gigantic that we will never be called again
        return (void*) 0x80800000;
    }
    osPiStartDma(&gDmaIoMesg, OS_MESG_PRI_NORMAL, OS_READ, (uintptr_t) ctx->srcStart, ctx->dest, copySize, &gDmaMesgQueue);

    const u32 margin = 16;
    void* ret = ctx->dest - margin;
    ctx->dest += copySize;
    ctx->srcStart += copySize;
    ctx->size -= copySize;

    return ret;
}

/**
 * Perform a DMA read from ROM, allocating space in the memory pool to write to.
 * Return the destination address.
 */
void *dynamic_dma_read(u8 *srcStart, u8 *srcEnd, u32 alignment, u32 bssLength) {
    u32 size = ALIGN16(srcEnd - srcStart);
    void* dest = main_pool_alloc_aligned(size + bssLength, alignment);
    if (dest != NULL) {
        dma_read(((u8 *)dest), srcStart, srcEnd);
        if (bssLength) {
            bzero(((u8 *)dest + size), bssLength);
        }
    }
    return dest;
}

static void *dynamic_dma_read_freeable(u8 *srcStart, u8 *srcEnd, u32 alignment, u32 bssLength) {
    u32 size = ALIGN16(srcEnd - srcStart);
    void* dest = main_pool_alloc_aligned_freeable(size + bssLength, alignment);
    if (dest != NULL) {
        dma_read(((u8 *)dest), srcStart, srcEnd);
        if (bssLength) {
            bzero(((u8 *)dest + size), bssLength);
        }
    }
    return dest;
}

#define TLB_PAGE_SIZE 4096 // Blocksize of TLB transfers. Larger values can be faster to transfer, but more wasteful of RAM.
s32 gTlbEntries = 0;
u8 gTlbSegments[NUM_TLB_SEGMENTS] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

void mapTLBPages(uintptr_t virtualAddress, uintptr_t physicalAddress, s32 length, s32 segment) {
    while (length > 0) {
        if (length > TLB_PAGE_SIZE) {
            osMapTLB(gTlbEntries++, OS_PM_4K, (void *)virtualAddress, physicalAddress, (physicalAddress + TLB_PAGE_SIZE), -1);
            virtualAddress  += TLB_PAGE_SIZE;
            physicalAddress += TLB_PAGE_SIZE;
            length          -= TLB_PAGE_SIZE;
            gTlbSegments[segment]++;
        } else {
            osMapTLB(gTlbEntries++, OS_PM_4K, (void *)virtualAddress, physicalAddress, -1, -1);
            gTlbSegments[segment]++;
        }
        virtualAddress  += TLB_PAGE_SIZE;
        physicalAddress += TLB_PAGE_SIZE;
        length          -= TLB_PAGE_SIZE;
    }
}

#ifndef NO_SEGMENTED_MEMORY
/**
 * Load data from ROM into a newly allocated block, and set the segment base
 * address to this block.
 */
void *load_segment(s32 segment, u8 *srcStart, u8 *srcEnd, u8 *bssStart, u8 *bssEnd) {
    void *addr;

    if ((bssStart != NULL)) {
        addr = dynamic_dma_read(srcStart, srcEnd, TLB_PAGE_SIZE, ((uintptr_t)bssEnd - (uintptr_t)bssStart));
        if (addr != NULL) {
            u8 *realAddr = (u8 *)ALIGN(addr, TLB_PAGE_SIZE);
            set_segment_base_addr(segment, realAddr); sSegmentROMTable[segment] = (uintptr_t) srcStart;
            mapTLBPages((segment << 24), VIRTUAL_TO_PHYSICAL(realAddr), ((srcEnd - srcStart) + ((uintptr_t)bssEnd - (uintptr_t)bssStart)), segment);
        }
    } else {
        addr = dynamic_dma_read(srcStart, srcEnd, 0, 0);
        if (addr != NULL) {
            set_segment_base_addr(segment, addr); sSegmentROMTable[segment] = (uintptr_t) srcStart;
        }
    }
#ifdef PUPPYPRINT_DEBUG
    u32 ppSize = ALIGN16(srcEnd - srcStart);
    set_segment_memory_printout(segment, ppSize);
#endif
    return addr;
}

/*
 * Allocate a block of memory starting at destAddr and ending at the end of
 * the memory pool. Then copy srcStart through srcEnd from ROM to this block.
 * If this block is not large enough to hold the ROM data, or that portion
 * of the pool is already allocated, return NULL.
 */
void *load_to_fixed_pool_addr(u8 *destAddr, u8 *srcStart, u8 *srcEnd) {
    u8* dest = (u8*) DOWN(destAddr, 16);
    u32 srcSize = ALIGN16(srcEnd - srcStart);
    u32 destSize = (u8*) RAM_END - srcStart;
    if (srcSize <= destSize) {
#ifdef USE_EXT_RAM
        bzero(dest, ((u8*)0x80800000) - dest);
#else
        bzero(dest, ((u8*)0x80400000) - dest);
#endif
        osWritebackDCacheAll();
        dma_read(dest, srcStart, srcEnd);
        if (EMU_WIIVC != gEmulator)
        {
            osInvalICache(dest, destSize);
            osInvalDCache(dest, destSize);
        }
    } else {
        DEBUG_ASSERT("Fixed addr is not be loaded");
    }
    return dest;
}

#define PACKED __attribute__((packed))

#define __GET_UNALIGNED_T(type, ptr) ({						\
	const struct { type x; } PACKED *__pptr = (typeof(__pptr))(ptr);	\
	__pptr->x;								\
})

#define __PUT_UNALIGNED_T(type, val, ptr) do {					\
	struct { type x; } PACKED *__pptr = (typeof(__pptr))(ptr);		\
	__pptr->x = (val);							\
} while (0)

#define GET_UNALIGNED8(ptr)	__GET_UNALIGNED_T(uint64_t, (ptr))
#define PUT_UNALIGNED8(val, ptr) __PUT_UNALIGNED_T(uint64_t, (val), (ptr))
#define GET_UNALIGNED4(ptr)	__GET_UNALIGNED_T(uint32_t, (ptr))
#define GET_UNALIGNED4S(ptr)	__GET_UNALIGNED_T(int32_t, (ptr))
#define PUT_UNALIGNED4(val, ptr) __PUT_UNALIGNED_T(uint32_t, (val), (ptr))

#define EXPECT(expr,value)    (__builtin_expect ((expr),(value)) )
#define LIKELY(expr)     EXPECT((expr) != 0, 1)
#define UNLIKELY(expr)   EXPECT((expr) != 0, 0)

// For testing purposes the following inline asm can be used for 64bit ops
#if 0
// this a lie, data is actually 64bit register
register uint32_t data;
__asm__ volatile (
    "ldl %0, 0(%1)\n\t"
    "ldr %0, 7(%1)\n\t"
    : "=&r" (data)
    : "r" (copySrc)
    : "memory"
);

__asm__ volatile (
    "sdl %1, -8(%0)\n\t"
    "sdr %1, -1(%0)\n\t"
    :
    : "r" (dst), "r" (data)
    : "memory"
);
#endif

#ifdef LZ4
static int lz4_read_length(const uint8_t** inbuf, const uint8_t** dmaLimit, struct DMAContext* ctx)
{
    int size = 0;
    uint8_t byte;

    do
    {
        if (UNLIKELY(*inbuf > *dmaLimit)) { *dmaLimit = dma_read_ctx(ctx); }
        byte = **inbuf;
        (*inbuf)++;
        size += byte;
    }
    while (UNLIKELY(byte == 0xFF));

    return size;
}

static void lz4_unpack(const uint8_t* inbuf, u32 inbufSize, uint8_t* dst, struct DMAContext* ctx)
{
    const uint8_t* inbufEnd = inbuf + inbufSize;
    const uint8_t* dmaLimit = inbuf - 16; 
    while (1)
    {
        if (UNLIKELY(inbuf > dmaLimit)) { dmaLimit = dma_read_ctx(ctx); }
        uint8_t token = *inbuf;
        inbuf++;

        {
            int literalSize = token >> 4;
            if (LIKELY(literalSize))
            {
                if (UNLIKELY(literalSize == 0xF))
                    literalSize += lz4_read_length(&inbuf, &dmaLimit, ctx);

                const uint8_t* copySrc = inbuf;
                inbuf += literalSize;
                do
                {
                    if (UNLIKELY((uint8_t*) copySrc > dmaLimit)) { dmaLimit = dma_read_ctx(ctx); }
                    const uint64_t data = GET_UNALIGNED8(copySrc);
                    copySrc += 8;
                    PUT_UNALIGNED8(data, dst);
                    dst += 8;
                    literalSize -= 8;
                } while (literalSize > 0);
                dst += literalSize;
            }
        }

        if (UNLIKELY(inbuf >= inbufEnd)) break;

        {
            if (UNLIKELY(inbuf > dmaLimit)) { dmaLimit = dma_read_ctx(ctx); }
            uint16_t b1 = inbuf[1];
            inbuf += 2;
            uint16_t b0 = inbuf[-2];
            b1 <<= 8;
            uint16_t matchOffset = b0 | b1;
            
            int matchSize = token & 0xF;
            if (UNLIKELY(matchSize == 0xF))
                matchSize += lz4_read_length(&inbuf, &dmaLimit, ctx);
            
            matchSize += 4;
            const uint8_t* copySrc = dst - matchOffset;
            if (matchOffset > matchSize || matchOffset >= 8)
            {
                do
                {
                    const uint64_t data = GET_UNALIGNED8(copySrc);
                    copySrc += 8;
                    PUT_UNALIGNED8(data, dst);
                    dst += 8;
                    matchSize -= 8;
                } while (matchSize > 0);
                dst += matchSize;
            }
            else
            {
                do
                {
                    uint8_t data = *copySrc;
                    copySrc++;
                    *dst = data;
                    dst++;
                    matchSize--;
                } while (matchSize > 0);
            }
        }
    }
}
#endif

#define LZ4T 1
#ifdef LZ4T
static __attribute__((noinline)) void lz4t_unpack(const uint8_t* restrict inbuf, int32_t nibbles, uint8_t* restrict dst, struct DMAContext* ctx)
{
#define LOAD_FRESH_NIBBLES() if (nibbles == 0) { nibbles = GET_UNALIGNED4S(inbuf); if (UNLIKELY(!nibbles)) { return; } inbuf += 4; }
    // DMA checks is checking whether dmaLimit will be exceeded after reading the data.
    // 'dma_read_ctx' will wait for the current DMA request and fire the next DMA request
#define DMA_CHECK(v) if (UNLIKELY(v > dmaLimit)) { dmaLimit = dma_read_ctx(ctx); }

    const uint8_t* dmaLimit = inbuf - 16;
    for (;; nibbles <<= 4)
    {
        // we will need to read the data (literal or offset) so might as well do it unconditionally from the start
        DMA_CHECK(inbuf);

        // matchLim will define the max amount of size encoded in a single nibble
        // If it is a match after guaranteed literal, it is 15, otherwise 7 (we checked for nibbles >= 0)
        int matchLim = 7;

        LOAD_FRESH_NIBBLES();

        // Each nibble is either 0xxx or 1xxx, xxx is a length
        int len = 7 & (nibbles >> 28);

        // If highest bit of current nibble is set to 1, then it is a literal load
        // Conveniently check for that using '<0' condition
        // Condition for matches will fallthru this check
        if (nibbles < 0)
        {
            // If length is 0, it is an extended match which will be bit encoded
            if (0 != len)
            {
                // Load full 8 byte literals, similar to LZ4 fast dec loop
                // No need to check for DMA limit here, we are still within the range
                const uint64_t data = GET_UNALIGNED8(inbuf);
                inbuf += len;
                PUT_UNALIGNED8(data, dst);
                dst += len;

                // It is unknown whether next nibble will be match or literal so continue
                if (len == matchLim)
                    continue;
                
                // ...otherwise fallthru to matches with extended matchLim
            }
            else
            {
                // Load more than 8 byte literals with a bit encoding loop
                len = 0;
                int shift = 0;
                while (1)
                {
                    int8_t next = *(int8_t*) (inbuf);
                    inbuf++;
                    len |= (next & 0x7f) << shift;
                    shift += 7;
                    if (next >= 0)
                    {
                        break;
                    }
                }

                len += 22;
                const uint8_t* copySrc = inbuf;
                inbuf += len;
                do
                {
                    // TODO: This is unnecessary for the first loop, we are already in the range
                    DMA_CHECK(copySrc);
                    const uint64_t data = GET_UNALIGNED8(copySrc);
                    copySrc += 8;
                    PUT_UNALIGNED8(data, dst);
                    dst += 8;
                    len -= 8;
                } while (len > 0);
                dst += len;

                // ... and fallthru to matches with extended limit
            }
        }
        else
        {
            // This is ugly, but it is the easiest way to do it
            goto matches;
        }

        // here is a fallthru for matches with extended limit so clear out the nibble
        nibbles <<= 4;
        LOAD_FRESH_NIBBLES();

        // match limit is 15 because it is after guaranteed literal
        matchLim = 15;
        // we are here after a literal was loaded so check DMA before loading offset in
        DMA_CHECK(inbuf);
        // cast like this is valid - signed to unsigned will just properly overflow
        len = (((uint32_t) nibbles) >> 28);

matches:
        // pull in offset and potentially the first size
        uint32_t matchCombo = GET_UNALIGNED4(inbuf);
        inbuf += 2;
        // It is 16 bit valid offset that fits in 'int', no need to do casts
        int matchOffset = matchCombo >> 16;
        // If it is 'regular' match, len='7 & (nibbles >> 28)', otherwise extended match '(nibbles >> 28)'
        // We need to start preparing the value for 'matchLen' which is 'matchLim + 3 + exSize'
        int matchLen = 3 + len;
        if (matchLim == len)
        {
            // we want extended matchLen so pull it from data
            // conveniently we have the first 'next' already
            // but I want a sign extended matchCombo 2nd byte so I am doing some ugly stuff
            int8_t next = ((((int) (matchCombo)) << 16) >> 24);
            int exLen = next & 0x7f;
            int shift = 7;
            inbuf++;
            while (next < 0)
            {
                next = *(int8_t*) (inbuf);
                inbuf++;
                exLen |= (next & 0x7f) << shift;
                shift += 7;
            }

            matchLen += exLen;
        }

        const uint8_t* copySrc = dst - matchOffset;
        if (matchOffset > matchLen || matchOffset >= 8)
        {
            do
            {
                const uint64_t data = GET_UNALIGNED8(copySrc);
                copySrc += 8;
                PUT_UNALIGNED8(data, dst);
                dst += 8;
                matchLen -= 8;
            } while (matchLen > 0);
            dst += matchLen;
        }
        else
        {
            if (1 == matchOffset)
            {
                uint64_t data = *copySrc;
                data |= data << 8;
                data |= data << 16;
                data |= data << 32;
                do
                {
                    PUT_UNALIGNED8(data, dst);
                    dst += 8;
                    matchLen -= 8;
                } while (matchLen > 0);
                dst += matchLen;            
            }
            else
            {
                do
                {
                    uint8_t data = *copySrc;
                    copySrc++;
                    *dst = data;
                    dst++;
                    matchLen--;
                } while (matchLen > 0);
            }
        }

        // repeat the loop...
    }

#undef DMA_CHECK
#undef LOAD_FRESH_NIBBLES
}
#endif

/**
 * Decompress the block of ROM data from srcStart to srcEnd and return a
 * pointer to an allocated buffer holding the decompressed data. Set the
 * base address of segment to this address.
 */
void *load_segment_decompress(s32 segment, u8 *srcStart, u8 *srcEnd) {
    void *dest = NULL;

#ifdef GZIP
    u32 compSize = ALIGN16(srcEnd - srcStart + 8);
#elif defined(RNC1)
#else
    u32 compSize = ALIGN16(srcEnd - srcStart);
#endif

#if 0
    u8 *compressed = main_pool_alloc_aligned_freeable(compSize, 0);
#else
    u8 *compressed = 0x80425800;
#endif

#ifdef GZIP
    struct {
        u32 destLength;
        u32 bufferLength;
        u64 padding;
    } ApLibHeader;

    dma_read((u8*)&ApLibHeader, srcStart, srcStart + 16); // We must extract this data from the header
    u32 *size = &ApLibHeader.destLength;
#elif defined(RNC1)
    struct {
        s8 magic[4];
        s8 majorVersion;
        s8 minorVersion;
        u16 headerSize;
        u32 compressedSize;
        u32 uncompressedSize;
        u32 safetyMargin;
        u32 flags;
        u64 pad; // Alignment
    } ShrinklerHeader;
    dma_read((u8*)&ShrinklerHeader, srcStart, srcStart + sizeof(ShrinklerHeader)); // We must extract this data from the header
    u32 *size = &ShrinklerHeader.uncompressedSize;
    u32 compSize = ShrinklerHeader.compressedSize;
    osSyncPrintf("Segment size: %u", ShrinklerHeader.uncompressedSize);
#else
    // Decompressed size from header (This works for non-mio0 because they also have the size in same place)
    u32 *size = (u32 *) (compressed + 4);
#endif
    if (compressed != NULL) {

#ifdef UNCOMPRESSED
        dest = main_pool_alloc_aligned(compSize, 0);
        dma_read(dest, srcStart, srcEnd);
#elif defined(GZIP)
        dest = main_pool_alloc_aligned(*size, 0);
#elif defined(RNC1)
        dma_read(compressed, srcStart + sizeof(ShrinklerHeader), srcEnd);
        dest = main_pool_alloc_aligned(*size, 0);
#else
        u32 margin = 0;
#if defined(LZ4) || defined(LZ4T)
        margin = 16;
#endif

#if defined(LZ4) || defined(LZ4T) || defined(YAZ0)
        // read the header for LZ4 decompression
        dma_read(compressed, srcStart, srcStart + 16);
#else
        // Read the whole compressed content
        dma_read(compressed, srcStart, srcEnd);
#endif

        dest = main_pool_alloc_aligned(*size + margin, 0);
#endif

	if (dest != NULL) {
            osSyncPrintf("start decompress\n");
#ifdef GZIP
            struct DMAContext ctx;
            dma_ctx_init(&ctx, compressed, srcStart + 8, srcEnd);
            decompress_aplib_full_fast(compressed, srcEnd - srcStart - 8, dest, &ctx);
#elif RNC1
            decompress_shrinkler_full_fast(compressed, ShrinklerHeader.compressedSize, dest, *size);
#elif RNC2
            Propack_UnpackM2(compressed, dest);
#elif YAZ0
            struct DMAContext ctx;
            dma_ctx_init(&ctx, compressed + 16, srcStart + 16, srcEnd);
            slidstart(compressed + 16, *size, dest, &ctx);
#elif MIO0
            decompress(compressed, dest);
#elif LZ4
            struct DMAContext ctx;
            u32 lz4CompSize = *(u32 *) (compressed + 8);
            dma_ctx_init(&ctx, compressed + 16, srcStart + 16, srcStart + 16 + lz4CompSize);
            extern int decompress_lz4_full_fast(const void *inbuf, int insize, void *outbuf, void* dmaCtx);
            decompress_lz4_full_fast(compressed + 16, lz4CompSize, dest, &ctx);
#elif LZ4T
            struct DMAContext ctx;
            u32 lz4CompSize = *(u32 *) (compressed + 8);
            dma_ctx_init(&ctx, compressed + 16, srcStart + 16, srcStart + 16 + lz4CompSize);
            extern int decompress_lz4t_full_fast(const void *inbuf, int insize, void *outbuf, void* dmaCtx);
            if (LIKELY(gIsConsole))
                decompress_lz4t_full_fast(compressed + 16, *(int32_t *) (compressed + 12), dest, &ctx);
            else
                lz4t_unpack(compressed + 16, *(int32_t *) (compressed + 12), dest, &ctx);
#endif
            osSyncPrintf("end decompress\n");
            set_segment_base_addr(segment, dest); sSegmentROMTable[segment] = (uintptr_t) srcStart;
            
#if 0
            main_pool_free(compressed);
#endif
        }
    }
#ifdef PUPPYPRINT_DEBUG
    u32 ppSize = ALIGN16((u32)*size);
    set_segment_memory_printout(segment, ppSize);
#endif
    return dest;
}

extern u8 _gp[];
extern u8 _sdataSegmentStart[];
extern u8 _sdataSegmentEnd[];
extern u8 _sdataSegmentRomStart[];
extern u8 _sdataSegmentRomEnd[];

void load_sdata(void) {
    void *startAddr = (void *) _sdataSegmentStart;
    u32 totalSize = _sdataSegmentEnd - _sdataSegmentStart;

    bzero(startAddr, totalSize);
    osWritebackDCacheAll();
    dma_read(startAddr, _sdataSegmentRomStart, _sdataSegmentRomEnd);
    osInvalDCache(startAddr, totalSize);
}

void load_engine_code_segment(void) {
    void *startAddr = (void *) _engineSegmentStart;
    u32 totalSize = _engineSegmentEnd - _engineSegmentStart;
    // UNUSED u32 alignedSize = ALIGN16(_engineSegmentRomEnd - _engineSegmentRomStart);

    bzero(startAddr, totalSize);
    osWritebackDCacheAll();
    dma_read(startAddr, _engineSegmentRomStart, _engineSegmentRomEnd);
    osInvalICache(startAddr, totalSize);
    osInvalDCache(startAddr, totalSize);
}
#endif

/**
 * Allocate a memory pool from the main pool. This pool supports arbitrary
 * order for allocation/freeing.
 * Return NULL if there is not enough space in the main pool.
 */
struct MemoryPool *mem_pool_init(u32 size) {
    void *addr;
    struct MemoryBlock *block;
    struct MemoryPool *pool = NULL;

    size = ALIGN4(size);
    addr = main_pool_alloc(size + sizeof(struct MemoryPool));
    if (addr != NULL) {
        pool = (struct MemoryPool *) addr;

        pool->totalSpace = size;
        pool->firstBlock = (struct MemoryBlock *) ((u8 *) addr + sizeof(struct MemoryPool));
        pool->freeList.next = (struct MemoryBlock *) ((u8 *) addr + sizeof(struct MemoryPool));

        block = pool->firstBlock;
        block->next = NULL;
        block->size = pool->totalSpace;
    }
#ifdef PUPPYPRINT_DEBUG
    gPoolMem += ALIGN16(size) + 16;
#endif
    return pool;
}

/**
 * Allocate from a memory pool. Return NULL if there is not enough space.
 */
void *mem_pool_alloc(struct MemoryPool *pool, u32 size) {
    struct MemoryBlock *freeBlock = &pool->freeList;
    void *addr = NULL;

    size = ALIGN4(size) + sizeof(struct MemoryBlock);
    while (freeBlock->next != NULL) {
        if (freeBlock->next->size >= size) {
            addr = (u8 *) freeBlock->next + sizeof(struct MemoryBlock);
            if (freeBlock->next->size - size <= sizeof(struct MemoryBlock)) {
                freeBlock->next = freeBlock->next->next;
            } else {
                struct MemoryBlock *newBlock = (struct MemoryBlock *) ((u8 *) freeBlock->next + size);
                newBlock->size = freeBlock->next->size - size;
                newBlock->next = freeBlock->next->next;
                freeBlock->next->size = size;
                freeBlock->next = newBlock;
            }
            break;
        }
        freeBlock = freeBlock->next;
    }
    return addr;
}

/**
 * Free a block that was allocated using mem_pool_alloc.
 */
void mem_pool_free(struct MemoryPool *pool, void *addr) {
    struct MemoryBlock *block = (struct MemoryBlock *) ((u8 *) addr - sizeof(struct MemoryBlock));
    struct MemoryBlock *freeList = pool->freeList.next;

    if (pool->freeList.next == NULL) {
        pool->freeList.next = block;
        block->next = NULL;
    } else {
        if (block < pool->freeList.next) {
            if ((u8 *) pool->freeList.next == (u8 *) block + block->size) {
                block->size += freeList->size;
                block->next = freeList->next;
                pool->freeList.next = block;
            } else {
                block->next = pool->freeList.next;
                pool->freeList.next = block;
            }
        } else {
            while (freeList->next != NULL) {
                if (freeList < block && block < freeList->next) {
                    break;
                }
                freeList = freeList->next;
            }
            if ((u8 *) freeList + freeList->size == (u8 *) block) {
                freeList->size += block->size;
                block = freeList;
            } else {
                block->next = freeList->next;
                freeList->next = block;
            }
            if (block->next != NULL && (u8 *) block->next == (u8 *) block + block->size) {
                block->size = block->size + block->next->size;
                block->next = block->next->next;
            }
        }
    }
}

void *alloc_display_list(u32 size) {
    void *ptr = NULL;

    size = ALIGN8(size);
    if (gGfxPoolEnd - size >= (u8 *) gDisplayListHead) {
        gGfxPoolEnd -= size;
        ptr = gGfxPoolEnd;
    }
    return ptr;
}

static struct DmaTable *load_dma_table_address(u8 *srcAddr) {
    struct DmaTable *table = dynamic_dma_read_freeable(srcAddr, srcAddr + sizeof(u32), 0, 0);
    u32 size = table->count * sizeof(struct OffsetSizePair) +
        sizeof(struct DmaTable) - sizeof(struct OffsetSizePair);
    main_pool_free(table);

    table = dynamic_dma_read(srcAddr, srcAddr + size, 0, 0);
    table->srcAddr = srcAddr;
    return table;
}

void setup_dma_table_list(struct DmaHandlerList *list, void *srcAddr, void *buffer) {
    if (srcAddr != NULL) {
        list->dmaTable = load_dma_table_address(srcAddr);
    }
    list->currentAddr = NULL;
    list->bufTarget = buffer;
}

s32 load_patchable_table(struct DmaHandlerList *list, s32 index) {
    struct DmaTable *table = list->dmaTable;

    if ((u32)index < table->count) {
        u8 *addr = table->srcAddr + table->anim[index].offset;
        s32 size = table->anim[index].size;

        if (list->currentAddr != addr) {
            dma_read(list->bufTarget, addr, addr + size);
            list->currentAddr = addr;
            return TRUE;
        }
    }
    return FALSE;
}
