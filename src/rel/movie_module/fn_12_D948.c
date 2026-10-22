#include "types.h"

/* Motion-compensation context: averages two 8x8 predictions into a packed block. */
typedef struct {
    u8 pad_0[0x18];
    u32 *dst;
    u8 pad_1C[0x4];
    s32 stride;
    u8 *src1;
    u8 *src2;
} McAvgCtx;

/* Rounded-up per-byte average of four packed bytes. */
static inline u32 AveragePackedBytes(u32 a, u32 b, u32 round, u32 mask) {
    u32 x = a ^ b;
    return ((a & b) + ((x & mask) >> 1)) + (x & round);
}
#define AVG4(a, b) AveragePackedBytes(a, b, 0x01010101, 0xFEFEFEFE)
#define AVGX(a, b, x) (((a) & (b)) + (((x) & 0x01010101) + (((x) & 0xFEFEFEFE) >> 1)))

#define W(p, off) (*(u32 *)((p) + (off)))

void fn_12_D948(McAvgCtx *ctx) {
    u32 *dst;
    u8 *s1;
    u8 *s2;
    s32 stride;
    s32 i;
    u32 p0, p1, q1;
    u32 q0, p2, q2;
    u32 a0, a1;

    s1 = ctx->src1;
    s2 = ctx->src2;
    dst = ctx->dst;
    stride = ctx->stride;

    switch ((s32)((u32)s1 & 3)) {
    case 0:
        for (i = 0; i < 8; i++) {
            p0 = W(s1, 0);
            q0 = W(s2, 0);
            p1 = W(s1, 4);
            q1 = W(s2, 4);
            s1 += stride;
            s2 += stride;
            q0 = AVG4(p0, q0);
            q1 = AVG4(p1, q1);
            dst[0] = q0;
            dst[1] = q1;
            dst += 2;
        }
        break;
    case 1:
        s1 -= 1;
        s2 -= 1;
        for (i = 0; i < 8; i++) {
            p0 = W(s1, 0);
            p1 = W(s1, 4);
            p2 = s1[8];
            q0 = W(s2, 0);
            q1 = W(s2, 4);
            q2 = s2[8];
            p0 = (p0 << 8) | (p1 >> 24);
            p2 = (p1 << 8) | p2;
            q0 = (q0 << 8) | (q1 >> 24);
            q2 = (q1 << 8) | q2;
            s1 += stride;
            s2 += stride;
            a0 = AVG4(p0, q0);
            a1 = AVG4(p2, q2);
            dst[0] = a0;
            dst[1] = a1;
            dst += 2;
        }
        break;
    case 2:
        s1 -= 2;
        s2 -= 2;
        for (i = 0; i < 8; i++) {
            p0 = W(s1, 0);
            p1 = W(s1, 4);
            p2 = *(u16 *)(s1 + 8);
            q0 = W(s2, 0);
            q1 = W(s2, 4);
            q2 = *(u16 *)(s2 + 8);
            p0 = (p0 << 16) | (p1 >> 16);
            p2 = (p1 << 16) | p2;
            q0 = (q0 << 16) | (q1 >> 16);
            q2 = (q1 << 16) | q2;
            s1 += stride;
            s2 += stride;
            a0 = AVG4(p0, q0);
            a1 = AVG4(p2, q2);
            dst[0] = a0;
            dst[1] = a1;
            dst += 2;
        }
        break;
    case 3:
        s1 -= 3;
        s2 -= 3;
        for (i = 0; i < 8; i++) {
            p0 = W(s1, 0);
            p1 = W(s1, 4);
            p2 = W(s1, 8);
            q0 = W(s2, 0);
            q1 = W(s2, 4);
            q2 = W(s2, 8);
            p0 = (p0 << 24) | (p1 >> 8);
            p2 = (p1 << 24) | (p2 >> 8);
            q0 = (q0 << 24) | (q1 >> 8);
            q2 = (q1 << 24) | (q2 >> 8);
            s1 += stride;
            s2 += stride;
            a0 = AVG4(p0, q0);
            a1 = AVG4(p2, q2);
            dst[0] = a0;
            dst[1] = a1;
            dst += 2;
        }
        break;
    }
}
