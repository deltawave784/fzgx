#include "types.h"

/* Half-pixel (rounded) average of two 16x16 reference blocks into an
 * 8x8-block laid-out destination; src1/src2 share the same misalignment. */
typedef struct {
    u8 pad_0[0x18];
    u8 *dst;      /* 0x18 */
    u8 pad_1C[0x4];
    s32 stride;   /* 0x20 */
    u8 *src1;     /* 0x24 */
    u8 *src2;     /* 0x28 */
} fn_12_1F61C_Ctx;

#define AVG4(a, b) ((((a) ^ (b)) & 0x01010101) + (((a) & (b)) + (((((a) ^ (b)) & 0xFEFEFEFE) >> 1))))
#define INITMASKS

#pragma opt_propagation on
void fn_12_1F61C(fn_12_1F61C_Ctx *ctx) {
    u8 *dst;
    u8 *src1;
    u8 *src2;
    s32 i;
    s32 stride;
    u32 a0, b0, a1, b1, a2, b2, a3, b3, a4, b4;
    src2 = ctx->src2;
    src1 = ctx->src1;
    dst = ctx->dst;
    stride = ctx->stride;

    __dcbt(src2, 0);
    { s32 alignment = (u32)src1 & 3;
    switch (alignment) {
    case 0: {
        INITMASKS
        for (i = 0; i < 16; i++) {
            __dcbt(src2, stride);
            a0 = *(u32 *)(src1 + 0);
            b0 = *(u32 *)(src2 + 0);
            a1 = *(u32 *)(src1 + 4);
            b1 = *(u32 *)(src2 + 4);
            a2 = *(u32 *)(src1 + 8);
            b2 = *(u32 *)(src2 + 8);
            a3 = *(u32 *)(src1 + 12);
            b3 = *(u32 *)(src2 + 12);
            *(u32 *)(dst + 0x00) = AVG4(a0, b0);
            *(u32 *)(dst + 0x04) = AVG4(a1, b1);
            *(u32 *)(dst + 0x40) = AVG4(a2, b2);
            *(u32 *)(dst + 0x44) = AVG4(a3, b3);
            src1 += stride;
            src2 += stride;
            dst += 8;
            if (i == 7) {
                dst += 0x40;
            }
        }
        break;
    }
    case 1: {
        INITMASKS
        src1 -= 1;
        src2 -= 1;
        for (i = 0; i < 16; i++) {
            __dcbt(src2, stride);
            a0 = *(u32 *)(src1 + 0);
            b0 = *(u32 *)(src2 + 0);
            a1 = *(u32 *)(src1 + 4);
            b1 = *(u32 *)(src2 + 4);
            a2 = *(u32 *)(src1 + 8);
            b2 = *(u32 *)(src2 + 8);
            a3 = *(u32 *)(src1 + 12);
            b3 = *(u32 *)(src2 + 12);
            a4 = *(u8 *)(src1 + 16);
            b4 = *(u8 *)(src2 + 16);
            a0 = (a0 << 8) | (a1 >> 24);
            b0 = (b0 << 8) | (b1 >> 24);
            a1 = (a1 << 8) | (a2 >> 24);
            b1 = (b1 << 8) | (b2 >> 24);
            a2 = (a2 << 8) | (a3 >> 24);
            b2 = (b2 << 8) | (b3 >> 24);
            a4 = (a3 << 8) | a4;
            b4 = (b3 << 8) | b4;
            *(u32 *)(dst + 0x00) = AVG4(a0, b0);
            *(u32 *)(dst + 0x04) = AVG4(a1, b1);
            *(u32 *)(dst + 0x40) = AVG4(a2, b2);
            *(u32 *)(dst + 0x44) = AVG4(a4, b4);
            src1 += stride;
            src2 += stride;
            dst += 8;
            if (i == 7) {
                dst += 0x40;
            }
        }
        break;
    }
    case 2: {
        INITMASKS
        src1 -= 2;
        src2 -= 2;
        for (i = 0; i < 16; i++) {
            __dcbt(src2, stride);
            a0 = *(u32 *)(src1 + 0);
            b0 = *(u32 *)(src2 + 0);
            a1 = *(u32 *)(src1 + 4);
            b1 = *(u32 *)(src2 + 4);
            a2 = *(u32 *)(src1 + 8);
            b2 = *(u32 *)(src2 + 8);
            a3 = *(u32 *)(src1 + 12);
            b3 = *(u32 *)(src2 + 12);
            a4 = *(u16 *)(src1 + 16);
            b4 = *(u16 *)(src2 + 16);
            a0 = (a0 << 16) | (a1 >> 16);
            b0 = (b0 << 16) | (b1 >> 16);
            a1 = (a1 << 16) | (a2 >> 16);
            b1 = (b1 << 16) | (b2 >> 16);
            a2 = (a2 << 16) | (a3 >> 16);
            b2 = (b2 << 16) | (b3 >> 16);
            a4 = (a3 << 16) | a4;
            b4 = (b3 << 16) | b4;
            *(u32 *)(dst + 0x00) = AVG4(a0, b0);
            *(u32 *)(dst + 0x04) = AVG4(a1, b1);
            *(u32 *)(dst + 0x40) = AVG4(a2, b2);
            *(u32 *)(dst + 0x44) = AVG4(a4, b4);
            src1 += stride;
            src2 += stride;
            dst += 8;
            if (i == 7) {
                dst += 0x40;
            }
        }
        break;
    }
    case 3: {
        INITMASKS
        src1 -= 3;
        src2 -= 3;
        for (i = 0; i < 16; i++) {
            __dcbt(src2, stride);
            a0 = *(u32 *)(src1 + 0);
            b0 = *(u32 *)(src2 + 0);
            a1 = *(u32 *)(src1 + 4);
            b1 = *(u32 *)(src2 + 4);
            a2 = *(u32 *)(src1 + 8);
            b2 = *(u32 *)(src2 + 8);
            a3 = *(u32 *)(src1 + 12);
            b3 = *(u32 *)(src2 + 12);
            a4 = *(u32 *)(src1 + 16);
            b4 = *(u32 *)(src2 + 16);
            a0 = (a0 << 24) | (a1 >> 8);
            b0 = (b0 << 24) | (b1 >> 8);
            a1 = (a1 << 24) | (a2 >> 8);
            b1 = (b1 << 24) | (b2 >> 8);
            a2 = (a2 << 24) | (a3 >> 8);
            b2 = (b2 << 24) | (b3 >> 8);
            a4 = (a3 << 24) | (a4 >> 8);
            b4 = (b3 << 24) | (b4 >> 8);
            *(u32 *)(dst + 0x00) = AVG4(a0, b0);
            *(u32 *)(dst + 0x04) = AVG4(a1, b1);
            *(u32 *)(dst + 0x40) = AVG4(a2, b2);
            *(u32 *)(dst + 0x44) = AVG4(a4, b4);
            src1 += stride;
            src2 += stride;
            dst += 8;
            if (i == 7) {
                dst += 0x40;
            }
        }
        break;
    }
    }
    }
}
