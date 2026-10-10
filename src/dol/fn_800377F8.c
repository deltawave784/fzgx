#include "types.h"

#define GX_FIFO_ADDR ((volatile void*)0xCC008000) // fzgx-allow: A1 hardware FIFO register  /* fzgx-allow: A2 unnamed OS/hardware memory */

/* GXSetFog */

typedef union PPCWGPipe {
    u8 u8;
    u16 u16;
    u32 u32;
    s8 s8;
    s16 s16;
    s32 s32;
    f32 f32;
    f64 f64;
} PPCWGPipe;

volatile PPCWGPipe GXWGFifo : 0xCC008000; /* fzgx-allow: A1,A2,S2 write-gather pipe */

typedef struct GXContext {
    u8 pad_0[2];
    u16 bpSentNot;
} GXContext;

typedef struct GXColor {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} GXColor;

extern GXContext* const gx;
extern u32 __cvt_fp2unsigned(f32);

#define SET_REG_FIELD(reg, size, shift, val) \
    ((reg) = ((u32)(reg) & ~(((1 << (size)) - 1) << (shift))) | ((u32)(val) << (shift)))

#define GX_WRITE_RAS_REG(value)                                                    \
    do {                                                                           \
        GXWGFifo.u8 = 0x61; \
        GXWGFifo.u32 = (value); \
    } while (0)

void fn_800377F8(u32 type, GXColor color, f32 startz, f32 endz, f32 nearz, f32 farz) {
    u32 fogclr;
    u32 fog0;
    u32 fog1;
    u32 fog2;
    u32 fog3;
    f32 A;
    f32 B;
    f32 B_mant;
    f32 C;
    f32 a;
    f32 c;
    u32 B_expn;
    u32 b_m;
    u32 b_s;
    u32 a_hex;
    u32 c_hex;
    u32 fsel;
    u32 proj;

    fogclr = 0;
    fog0 = 0;
    fog1 = 0;
    fog2 = 0;
    fog3 = 0;
    fsel = type & 7;
    proj = (type >> 3) & 1;

    if (proj) {
        /* orthographic */
        if (farz == nearz || endz == startz) {
            a = 0.0f;
            c = 0.0f;
        } else {
            A = 1.0f / (endz - startz);
            a = A * (farz - nearz);
            c = A * (startz - nearz);
        }
    } else {
        if (farz == nearz || endz == startz) {
            A = 0.0f;
            B = 0.5f;
            C = 0.0f;
        } else {
            A = (farz * nearz) / ((farz - nearz) * (endz - startz));
            B = farz / (farz - nearz);
            C = startz / (endz - startz);
        }

        B_mant = B;
        B_expn = 0;
        while (B_mant > 1.0) {
            B_mant *= 0.5f;
            B_expn++;
        }
        while (B_mant > 0.0f && B_mant < 0.5) {
            B_mant *= 2.0f;
            B_expn--;
        }

        a = A / (f32)(1 << (B_expn + 1));
        b_m = 8.388638e6f * B_mant;
        b_s = B_expn + 1;
        c = C;

        SET_REG_FIELD(fog1, 24, 0, b_m);
        SET_REG_FIELD(fog1, 8, 24, 0xEF);
        SET_REG_FIELD(fog2, 5, 0, b_s);
        SET_REG_FIELD(fog2, 8, 24, 0xF0);
    }

    a_hex = *(u32*)&a;
    c_hex = *(u32*)&c;

    SET_REG_FIELD(fog0, 11, 0, (a_hex >> 12) & 0x7FF);
    SET_REG_FIELD(fog0, 8, 11, (a_hex >> 23) & 0xFF);
    SET_REG_FIELD(fog0, 1, 19, (a_hex >> 31));
    SET_REG_FIELD(fog0, 8, 24, 0xEE);

    SET_REG_FIELD(fog3, 11, 0, (c_hex >> 12) & 0x7FF);
    SET_REG_FIELD(fog3, 8, 11, (c_hex >> 23) & 0xFF);
    SET_REG_FIELD(fog3, 1, 19, (c_hex >> 31));
    SET_REG_FIELD(fog3, 1, 20, proj);
    SET_REG_FIELD(fog3, 3, 21, fsel);
    SET_REG_FIELD(fog3, 8, 24, 0xF1);

    SET_REG_FIELD(fogclr, 8, 0, color.b);
    SET_REG_FIELD(fogclr, 8, 8, color.g);
    SET_REG_FIELD(fogclr, 8, 16, color.r);
    SET_REG_FIELD(fogclr, 8, 24, 0xF2);

    GX_WRITE_RAS_REG(fog0);
    GX_WRITE_RAS_REG(fog1);
    GX_WRITE_RAS_REG(fog2);
    GX_WRITE_RAS_REG(fog3);
    GX_WRITE_RAS_REG(fogclr);
    gx->bpSentNot = 0;
}
