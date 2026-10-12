#include "types.h"

/* DCT cosine tables: direct [row][col] and transposed [col][row], then the scan table pointer. */
typedef struct DctFsriTables {
    f64 cosine_row0[8]; f64 cosine_row1[8]; f64 cosine_row2[8]; f64 cosine_row3[8]; f64 cosine_row4[8]; f64 cosine_row5[8]; f64 cosine_row6[8]; f64 cosine_row7[8];
    f64 cosineT_row0[8]; f64 cosineT_row1[8]; f64 cosineT_row2[8]; f64 cosineT_row3[8]; f64 cosineT_row4[8]; f64 cosineT_row5[8]; f64 cosineT_row6[8]; f64 cosineT_row7[8];
    void *scanTable;
} DctFsriTables;

extern void *fn_12_4E14(void);
extern f64 fn_80087E80(f64);
extern const f64 lbl_12_rodata_598;  /* 0.5 */
extern const f64 lbl_12_rodata_5A8;  /* 1/sqrt(8) */
extern const f64 lbl_12_rodata_5B0;  /* pi/8 */

#pragma opt_propagation off
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
f64 lbl_12_bss_798[8];
u32 lbl_12_bss_798_fill_7D8[112];
f64 lbl_12_bss_798_200[8];
u32 lbl_12_bss_798_fill_9D8[112];
void *lbl_12_bss_798_400;
u32 lbl_12_bss_798_fill_B9C;
u32 lbl_12_bss_BA0[2];
u32 lbl_12_bss_BA8;
u32 lbl_12_bss_798_gap_BAC;
u32 lbl_12_bss_BB0[128];
u32 lbl_12_bss_DB0[4096];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&lbl_12_bss_798;
    s = *(u8 *)&lbl_12_bss_798_fill_7D8;
    s = *(u8 *)&lbl_12_bss_798_200;
    s = *(u8 *)&lbl_12_bss_798_fill_9D8;
    s = *(u8 *)&lbl_12_bss_798_400;
    s = *(u8 *)&lbl_12_bss_798_fill_B9C;
    s = *(u8 *)&lbl_12_bss_BA0;
    s = *(u8 *)&lbl_12_bss_BA8;
    s = *(u8 *)&lbl_12_bss_798_gap_BAC;
    s = *(u8 *)&lbl_12_bss_BB0;
    s = *(u8 *)&lbl_12_bss_DB0;
}
#pragma section code_type ".text"

void fn_12_4D14(void) {
    /* one-member wrapper: the table address is one value held across the call, not a copied local */
    struct { DctFsriTables *value; } tables;
    f64 *rowEntry;
    f64 *columnEntry;
    f64 *row;
    f64 *column;
    s32 i;
    s32 j;
    f64 scale;
    f64 step;
    f64 value;

    
    lbl_12_bss_798_400 = fn_12_4E14();
    row = lbl_12_bss_798;
    column = lbl_12_bss_798_200;
    for (i = 0; i < 8; i++) {
        if (i == 0) {
            scale = lbl_12_rodata_5A8;
        } else {
            scale = lbl_12_rodata_598;
        }
        step = lbl_12_rodata_5B0 * (f64)i;
        rowEntry = row;
        columnEntry = column;
        for (j = 0; j < 8; j++) {
            value = scale * fn_80087E80(step * (lbl_12_rodata_598 + (f64)j));
            *rowEntry = value;
            rowEntry++;
            *columnEntry = value;
            columnEntry += 8;
        }
        row += 8;
        column++;
    }
}
