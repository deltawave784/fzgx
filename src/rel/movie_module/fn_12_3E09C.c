#include "types.h"

typedef struct Sig_fn_12_339B4_MovieOutput {
    u32 field_00;
    u32 field_04;
    u32 field_08;
    u32 field_0C;
    u32 field_10;
    u32 field_14;
} Sig_fn_12_339B4_MovieOutput;

extern void fn_12_339B4(u32, u32, u32, Sig_fn_12_339B4_MovieOutput *);

/* Two luma bytes of y interleaved with one chroma byte of c (Y C Y C). */
#define PACK_HI(y, c) (((y) & 0xFF000000) | (((y) >> 8) & 0xFF00) | (((c) << 8) & 0xFF0000) | ((c) >> 8))
#define PACK_LO(y, c) ((((y) << 16) & 0xFF000000) | (((y) & 0xFF) << 8) | (((c) << 16) & 0xFF0000) | ((c) & 0xFF))

/* One 8-byte row into each of the two output tiles. */
#define PUT_ROW(off, pa, pb)              \
    do {                                  \
        u32 ya = *(u32 *)yB;              \
        u32 ca = *(pa);                   \
        u32 yb = *(u32 *)yA;              \
        u32 cb = *(pb);                   \
        dst[(off) + 1] = PACK_LO(ya, ca); \
        dst2[(off) + 1] = PACK_LO(yb, cb); \
        dst[(off)] = PACK_HI(ya, ca);     \
        dst2[(off)] = PACK_HI(yb, cb);    \
    } while (0)

#define CLEAR_ROWS(off)       \
    do {                      \
        dst[(off)] = 0;       \
        dst2[(off)] = 0;      \
        dst[(off) + 1] = 0;   \
        dst2[(off) + 1] = 0;  \
        dst[(off) + 2] = 0;   \
        dst2[(off) + 2] = 0;  \
        dst[(off) + 3] = 0;   \
        dst2[(off) + 3] = 0;  \
    } while (0)

void fn_12_3E09C(u32 arg0, u32 *buf, s32 width, s32 height) {
    Sig_fn_12_339B4_MovieOutput out;
    u32 *dst;
    u32 *dst2;
    u8 *yA;
    u8 *yB;
    u16 *cA;
    u16 *cB;
    u32 ystride;
    u32 cstride;
    s32 w4;
    s32 h4;
    s32 i;
    s32 j;

    fn_12_339B4(arg0, width, height, &out);
    w4 = width / 4;
    yA = (u8 *)out.field_00;
    yB = (u8 *)out.field_00 + (((out.field_04 - out.field_00) >> 1) & ~3);
    h4 = height / 4;
    cA = (u16 *)out.field_04;
    cB = (u16 *)out.field_08;
    ystride = out.field_0C;
    ystride &= ~3;
    cstride = out.field_10;
    cstride = cstride & ~1;
    dst = buf;
    dst2 = buf + 8;
    for (j = 0; j < h4; j++) {
        for (i = 0; i < w4; i++, dst += 16, dst2 += 16) {
            if (i >= 0 && i < w4) {
                PUT_ROW(0, cA, cB);
                PUT_ROW(2, cA, cB);
            } else {
                CLEAR_ROWS(0);
            }
            yA += ystride;
            yB += ystride;
            if (i >= 0 && i < w4) {
                PUT_ROW(4, (u16 *)((u8 *)cA + cstride), (u16 *)((u8 *)cB + cstride));
                PUT_ROW(6, cA, cB);
            } else {
                CLEAR_ROWS(4);
            }
            yA += ystride;
            yB += ystride;
            cA++;
            cB++;
            yA = yA + 4 - ystride * 2;
            yB = yB + 4 - ystride * 2;
        }
        yA += ystride;
        yB += ystride;
        cA = (u16 *)((u8 *)cA + cstride);
        cB = (u16 *)((u8 *)cB + cstride);
    }
}
