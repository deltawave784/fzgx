#include "types.h"

extern void *memset(void *, int, u32);

typedef struct {
    s32 unk_0;
    u8 pad_4[0x28];
    u32 unk_2C;
    u8 pad_30[0x88];
    u8 unk_B8[8];
    u8 unk_C0[8];
    u8 pad_C8[0x1C0];
    u8 unk_288[0x20];
    u32 unk_2A8[6];
} Obj_8018FEB0;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
__declspec(section ".data") s32 fzgx_obj_lbl_8018FEB0;
__declspec(section ".data") u32 lbl_8018FEB0_fill_8018FEB4[10];
__declspec(section ".data") u32 lbl_8018FEB0_2C;
__declspec(section ".data") u32 lbl_8018FEE0[32];
__declspec(section ".data") u32 lbl_8018FF60[2];
__declspec(section ".data") u8 lbl_8018FF68[8];
__declspec(section ".data") u8 lbl_8018FF70[8];
__declspec(section ".data") u32 lbl_8018FF78[112];
__declspec(section ".data") u8 lbl_8018FF78_1C0[0x20];
__declspec(section ".data") u32 lbl_8018FF78_1E0[6];
__declspec(section ".data") u32 lbl_8018FF78_fill_80190170[2];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_8018FEB0;
    s = *(u8 *)&lbl_8018FEB0_fill_8018FEB4;
    s = *(u8 *)&lbl_8018FEB0_2C;
    s = *(u8 *)&lbl_8018FEE0;
    s = *(u8 *)&lbl_8018FF60;
    s = *(u8 *)&lbl_8018FF68;
    s = *(u8 *)&lbl_8018FF70;
    s = *(u8 *)&lbl_8018FF78;
    s = *(u8 *)&lbl_8018FF78_1C0;
    s = *(u8 *)&lbl_8018FF78_1E0;
    s = *(u8 *)&lbl_8018FF78_fill_80190170;
}
#pragma section code_type ".text"

#pragma opt_propagation off
void fn_80058BFC(void) {
    
    if (fzgx_obj_lbl_8018FEB0 == 0) {
        memset(lbl_8018FF78_1C0, 0, 0x20);
        memset(lbl_8018FF70, 0, 8);
        memset(lbl_8018FF68, 0, 8);
        {
            u32 *q = lbl_8018FF78_1E0;
            q[0] = 0;
            q[1] = 0;
            q[2] = 0;
            q[3] = 0;
            q[4] = 0;
            q[5] = 0;
        }
        lbl_8018FEB0_2C = 0;
    }
    fzgx_obj_lbl_8018FEB0 = fzgx_obj_lbl_8018FEB0 + 1;
}
#pragma opt_propagation reset

