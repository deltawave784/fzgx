#include "types.h"

typedef struct MovieBlockOffsets {
    u32 luma;
    u32 chroma;
} MovieBlockOffsets;

typedef struct MovieFrameBuffer {
    u8 *luma_top;
    u8 *luma_bottom;
    u8 *chroma;
    s16 luma_stride;
    s16 chroma_stride;
} MovieFrameBuffer;

/* Copies six decoded 8x8 blocks (as rows of 8 bytes) into the frame
 * buffer: two luma blocks stacked, two Cb/Cr block pairs interleaved. */
void fn_12_7E58(f64 *blocks, MovieBlockOffsets *offsets, MovieFrameBuffer *frame) {
    s32 stride;
    u8 *dst;
    u8 *dst2;
    f64 *src;
    f64 *cr;

    src = blocks;
    stride = frame->luma_stride & ~7;
    dst = frame->luma_top + offsets->luma;
    *(f64 *)dst = *src++; dst += stride;
    *(f64 *)dst = *src++; dst += stride;
    *(f64 *)dst = *src++; dst += stride;
    *(f64 *)dst = *src++; dst += stride;
    *(f64 *)dst = *src++; dst += stride;
    *(f64 *)dst = *src++; dst += stride;
    *(f64 *)dst = *src++; dst += stride;
    *(f64 *)dst = *src++;

    dst = frame->luma_bottom + offsets->luma;
    *(f64 *)dst = *src++; dst += stride;
    *(f64 *)dst = *src++; dst += stride;
    *(f64 *)dst = *src++; dst += stride;
    *(f64 *)dst = *src++; dst += stride;
    *(f64 *)dst = *src++; dst += stride;
    *(f64 *)dst = *src++; dst += stride;
    *(f64 *)dst = *src++; dst += stride;
    *(f64 *)dst = *src++;

    stride = frame->chroma_stride & ~7;
    dst = frame->chroma + offsets->chroma;
    dst2 = dst + 8;
    cr = src + 8;
    *(f64 *)dst = *src++; dst += stride;
    *(f64 *)dst2 = *cr++; dst2 += stride;
    *(f64 *)dst = *src++; dst += stride;
    *(f64 *)dst2 = *cr++; dst2 += stride;
    *(f64 *)dst = *src++; dst += stride;
    *(f64 *)dst2 = *cr++; dst2 += stride;
    *(f64 *)dst = *src++; dst += stride;
    *(f64 *)dst2 = *cr++; dst2 += stride;
    *(f64 *)dst = *src++; dst += stride;
    *(f64 *)dst2 = *cr++; dst2 += stride;
    *(f64 *)dst = *src++; dst += stride;
    *(f64 *)dst2 = *cr++; dst2 += stride;
    *(f64 *)dst = *src++; dst += stride;
    *(f64 *)dst2 = *cr++; dst2 += stride;
    *(f64 *)dst = *src++; dst += stride;
    *(f64 *)dst2 = *cr++; dst2 += stride;
    src += 8;
    cr += 8;
    *(f64 *)dst = *src++; dst += stride;
    *(f64 *)dst2 = *cr++; dst2 += stride;
    *(f64 *)dst = *src++; dst += stride;
    *(f64 *)dst2 = *cr++; dst2 += stride;
    *(f64 *)dst = *src++; dst += stride;
    *(f64 *)dst2 = *cr++; dst2 += stride;
    *(f64 *)dst = *src++; dst += stride;
    *(f64 *)dst2 = *cr++; dst2 += stride;
    *(f64 *)dst = *src++; dst += stride;
    *(f64 *)dst2 = *cr++; dst2 += stride;
    *(f64 *)dst = *src++; dst += stride;
    *(f64 *)dst2 = *cr++; dst2 += stride;
    *(f64 *)dst = *src++; dst += stride;
    *(f64 *)dst2 = *cr++; dst2 += stride;
    *(f64 *)dst = *src;
    *(f64 *)dst2 = *cr;
}
