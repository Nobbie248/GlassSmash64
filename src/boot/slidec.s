/*
 * MIPS YAY0 decoder created by devwizard64.
 */

#define inbuf       $s0
#define outbuf      $s1
#define bits_left   $s2
#define msb_check   $s3
#define loaded_amt  $s4
#define outbuf_end  $s5

#define cp_curr     $t0
#define cp_limit    $t1
#define cp_scr_b1   $t2
#define cp_scr_b2   $t3
#define rle_b2      $t4
#define rle_b1      $t5

#define check       $t9

#define dma_ctx     $s6
#define dma_ptr     $v0

# Read one bit from CC, and jump to target if it matches
# the specified value
.macro dma_check value
    sub check, \value, dma_ptr                    # check if we need to wait for dma
    bgezal check, dma_read_ctx                    # if inbuf >= dma_ptr, wait for dma
    move $a0, dma_ctx
.endm

    .section .text.slidstart
	.p2align 5
    .globl slidstart 
    .func slidstart
    .set at
    .set noreorder

slidstart:
    addiu $sp, $sp, -0x38
    sw $ra, 0x14($sp)
    sw $s0, 0x18($sp)
    sw $s1, 0x1c($sp)
    sw $s2, 0x20($sp)
    sw $s3, 0x24($sp)
    sw $s4, 0x28($sp)
    sw $s5, 0x2C($sp)
    sw $s6, 0x30($sp)

    move inbuf, $a0
    move outbuf, $a2

    add     outbuf_end, outbuf, $a1
    move    bits_left, $0

    # initialize V0 with the first data, we are going to need it immediately
    move $a0, $a3
    bal dma_read_ctx
    move dma_ctx, $a3

.Lloop:
    bnez    bits_left, .Lhandle_group
    add     inbuf, 1
    dma_check inbuf
    lwl     msb_check, -1(inbuf)
    lwr     msb_check, 2(inbuf)
    li      loaded_amt, 1
    add     inbuf, 4
    li      bits_left, 32
.Lhandle_group:
    bgez    msb_check, .Lbackref
    sub     loaded_amt, 1

# copy byte to output if it was not copied yet
    bnez    loaded_amt, .Lnext_bit
    add     outbuf, 1
    dma_check inbuf
    ldl     cp_scr_b2, -1(inbuf)
    ldr     cp_scr_b2, 6(inbuf)
    li      loaded_amt, 8
    sdl     cp_scr_b2, -1(outbuf)
    sdr     cp_scr_b2, 6(outbuf)
    sll     msb_check, 1
    bne     outbuf, outbuf_end, .Lloop
    sub     bits_left, 1

# RLE from decompressed output
.Lbackref:
    # need to parse NRRR or 0RRRMM
    dma_check inbuf
    li      loaded_amt, 1
    lwl     $t8, -1(inbuf)
    lwr     $t8, 2(inbuf)       # t8 = ?RRRMM--
    add     inbuf, 1
    srl     rle_b1, $t8, 16
    and     rle_b1, 0xFFF       # rle_b1 = RRR
    srl     $t7, $t8, 28        # t7 = ?
    bnez    $t7, .Lprepare_memcpy2
    add     rle_b2, $t7, 2
    add     inbuf, 1
    srl     rle_b2, $t8, 8
    and     rle_b2, 0xff        # rle_b2 = MM
    add     rle_b2, 18          # rle_b2 = MM + 18
.Lprepare_memcpy2:

    # rle_b1 = offset, rle_b2 = amount
    sub     cp_curr, outbuf, rle_b1
    sub     check, rle_b1, 6
    bgez    check, .Lmemcpy_loop8
    add     cp_limit, outbuf, rle_b2
    beqz    rle_b1, .Lmemset # lbu t1 is needed for memset

.Lmemcpy_loop:
    lbu     cp_scr_b2, -1(cp_curr)
    add     cp_curr, 1
    add     outbuf, 1
    bne     outbuf, cp_limit, .Lmemcpy_loop
    sb      cp_scr_b2, -1(outbuf)
    b       .Lnext_bit
    nop

.Lmemset:
    dsll cp_scr_b1, cp_scr_b2, 8                            # duplicate the LSB into all bytes
    or cp_scr_b2, cp_scr_b1
    dsll cp_scr_b1, cp_scr_b2, 16
    or cp_scr_b2, cp_scr_b1
    dsll cp_scr_b1, cp_scr_b2, 32
    or cp_scr_b1, cp_scr_b2

.Lmemset_loop:
    sdl cp_scr_b1, 0(outbuf)
    sdr cp_scr_b1, 7(outbuf)
    add outbuf, 8
    sub check, outbuf, cp_limit
    bltz check, .Lmemset_loop
    nop
    b       .Lnext_bit
    move outbuf, cp_limit

.Lmemcpy_loop8:
    ldl cp_scr_b2, -1(cp_curr)
    ldr cp_scr_b2, 6(cp_curr)
    add outbuf, 8
    sub check, outbuf, cp_limit
    sdl cp_scr_b2, -8(outbuf)                          # store 8 bytes
    sdr cp_scr_b2, -1(outbuf)
    bltz check, .Lmemcpy_loop8
    add cp_curr, 8
    move outbuf, cp_limit

.Lnext_bit:
    sll     msb_check, 1
    bne     outbuf, outbuf_end, .Lloop
    sub     bits_left, 1

    lw $ra, 0x14($sp)
    lw $s0, 0x18($sp)
    lw $s1, 0x1c($sp)
    lw $s2, 0x20($sp)
    lw $s3, 0x24($sp)
    lw $s4, 0x28($sp)
    lw $s5, 0x2C($sp)
    lw $s6, 0x30($sp)
    jr $ra
    addiu $sp, $sp, 0x38

.endfunc
