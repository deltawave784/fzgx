#include "types.h"

typedef struct Sig_fn_12_3E394_Matrix3 {
    f32 m[9];
} Sig_fn_12_3E394_Matrix3;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
Sig_fn_12_3E394_Matrix3 lbl_12_bss_1E088;
f32 lbl_12_bss_1E088_24[12];
u8 lbl_12_bss_1E088_54[256];
u8 lbl_12_bss_1E088_154[256];
u8 lbl_12_bss_1E088_254[256];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&lbl_12_bss_1E088;
    s = *(u8 *)&lbl_12_bss_1E088_24;
    s = *(u8 *)&lbl_12_bss_1E088_54;
    s = *(u8 *)&lbl_12_bss_1E088_154;
    s = *(u8 *)&lbl_12_bss_1E088_254;
}
static void fzgx_pool_layout(void) {
    volatile f32 f;  /* fzgx-allow: S2 pool primer sink: MWCC lays out literals in first-use order */
    volatile u32 u;  /* fzgx-allow: S2 pool primer sink */
    f = 255.0f;
    f = 128.0f;
    f = (f32)u;
}
static void fzgx_pool_layout2(void) {
    volatile f32 f;  /* fzgx-allow: S2 pool primer sink */
    f = 16.5f;
    f = 0.0f;
    f = 128.5f;
}
#pragma section code_type ".text"

extern u8 lbl_12_data_EA0[36];
extern u8 lbl_12_data_EC4[36];
extern void fn_12_3E688(u8 *, u8 *, u8 *);
extern void fn_12_3E500(void *, void *);
extern void fn_12_3E394(const Sig_fn_12_3E394_Matrix3 *, const Sig_fn_12_3E394_Matrix3 *, Sig_fn_12_3E394_Matrix3 *);

static inline u32 clamp_u8(f32 v, f32 lo, f32 hi)
{
    if (v < lo) {
        v = lo;
    }
    if (v > hi) {
        v = hi;
    }
    return (u32)v;
}

void fn_12_3D968(u8 *arg0)
{
    u32 *table;
    u32 *t1;
    u32 *t2;
    u32 *t3;
    Sig_fn_12_3E394_Matrix3 *mtx;
    f32 m0;
    f32 m4;
    f32 m8;
    u32 c;
    s32 i;

    table = (u32 *)arg0;
    t1 = table + 0x100;
    t2 = t1 + 0x100;
    fn_12_3E688(lbl_12_bss_1E088_254, lbl_12_bss_1E088_154, lbl_12_bss_1E088_54);
    fn_12_3E500(lbl_12_data_EA0, lbl_12_bss_1E088_24);
    fn_12_3E394((Sig_fn_12_3E394_Matrix3 *)lbl_12_data_EC4, (Sig_fn_12_3E394_Matrix3 *)lbl_12_bss_1E088_24,
                &lbl_12_bss_1E088);

    mtx = &lbl_12_bss_1E088;
    m4 = mtx->m[4];
    m8 = mtx->m[8];
    m0 = lbl_12_bss_1E088.m[0];
    t3 = t2 + 0x100;
    for (i = 0; i < 0x100; i++) {
        c = clamp_u8(m0 * (f32)lbl_12_bss_1E088_254[i] + 16.5f, 0.0f, 255.0f);
        table[i] = c << 24;
        t1[i] = c << 8;
        t2[i] = clamp_u8(128.5f + (m4 * (f32)lbl_12_bss_1E088_154[i] - 128.0f * m4), 0.0f, 255.0f) << 16;
        t3[i] = clamp_u8(128.5f + (m8 * (f32)lbl_12_bss_1E088_54[i] - 128.0f * m8), 0.0f, 255.0f);
    }
}
