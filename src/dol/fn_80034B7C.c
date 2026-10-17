#include "dolphin/types.h"

typedef struct GXState {
    u8 pad[0x1E8];
    volatile u32 copyStride; /* GX register shadow: preserve the sequential read/modify/write accesses. */
} GXState;

extern GXState* const gx;

void fn_80034B7C(u16 width, u16 height)
{
    u16 stride = width * 2;
    gx->copyStride = 0;
    gx->copyStride = (gx->copyStride & ~0x3FF) | (stride >> 5);
    gx->copyStride = (gx->copyStride & 0x00FFFFFF) | 0x4D000000;
}
