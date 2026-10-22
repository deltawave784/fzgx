#include "types.h"

/* TU-local objects of the movie colour-conversion block (lbl_12_bss_1E088). */
u8 lbl_12_bss_1E088[0x24];
static f32 s_matrix[9];   /* 0x24: 3x3 colour matrix */
static f32 *s_tab2;       /* 0x48 */
static f32 *s_tab1;       /* 0x4C */
static f32 *s_tab0;       /* 0x50 */
static u8 s_c[256];       /* 0x54 */
static u8 s_b[256];       /* 0x154 */
static u8 s_a[256];       /* 0x254 */

/* Layout primer: fixes the retail .bss order (first access order); dropped at link. */
#pragma section RX ".fzgxpool"
__declspec(section ".fzgxpool") void fzgx_bss_primer(void) {
    volatile u32 sink; /* volatile: keeps each primer read */
    sink = lbl_12_bss_1E088[0];
    sink = *(u32 *)s_matrix;
    sink = (u32)s_tab2;
    sink = (u32)s_tab1;
    sink = (u32)s_tab0;
    sink = s_c[0];
    sink = s_b[0];
    sink = s_a[0];
}

extern const f32 lbl_12_rodata_2E78; /* 255.0f */
extern const f32 lbl_12_rodata_2E7C; /* 128.0f */
extern u8 lbl_12_data_EA0[36];
extern void fn_12_3E688(u8 *a, u8 *b, u8 *c);
extern void fn_12_3E500(void *src, f32 *dst);

void fn_12_3D740(f32 *buf) {
    s32 i;
    s32 tmp_cse1;

    s_tab0 = buf;
    s_tab1 = (f32 *)((u8 *)buf + 0x1000);
    s_tab2 = (f32 *)((u8 *)buf + 0x2000);
    fn_12_3E688(s_a, s_b, s_c);
    fn_12_3E500(lbl_12_data_EA0, s_matrix);
    for (i = 0; i < 256; i++) {
        s_tab0[(tmp_cse1 = i * 4) + 1] = s_matrix[0] * (f32)s_a[i];
        s_tab0[tmp_cse1 + 2] = s_matrix[3] * (f32)s_a[i];
        s_tab0[tmp_cse1 + 3] = s_matrix[6] * (f32)s_a[i];
        s_tab0[tmp_cse1 + 0] = lbl_12_rodata_2E78;
        s_tab1[tmp_cse1 + 1] = s_matrix[1] * ((f32)s_b[i] - lbl_12_rodata_2E7C);
        s_tab1[tmp_cse1 + 2] = s_matrix[4] * ((f32)s_b[i] - lbl_12_rodata_2E7C);
        s_tab1[tmp_cse1 + 3] = s_matrix[7] * ((f32)s_b[i] - lbl_12_rodata_2E7C);
        s_tab2[tmp_cse1 + 1] = s_matrix[2] * ((f32)s_c[i] - lbl_12_rodata_2E7C);
        s_tab2[tmp_cse1 + 2] = s_matrix[5] * ((f32)s_c[i] - lbl_12_rodata_2E7C);
        s_tab2[tmp_cse1 + 3] = s_matrix[8] * ((f32)s_c[i] - lbl_12_rodata_2E7C);
    }
}
