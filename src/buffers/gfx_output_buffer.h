#ifndef GFX_OUTPUT_BUFFER_H
#define GFX_OUTPUT_BUFFER_H

#include <PR/ultratypes.h>
#include "config/config_memory.h"

extern u64 gGfxSPTaskOutputBuffer[GFX_FIFO_POOL_SIZE  / sizeof(u64)];

#endif // GFX_OUTPUT_BUFFER_H
