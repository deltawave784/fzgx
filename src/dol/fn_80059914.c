#include "types.h"

typedef struct {
    void (*fn)(u32);
    u32 arg;
} Cb;

typedef struct {
    u32 unk_0;
    s32 unk_4;
    u32 unk_8;
    u8 pad_C[0xB4];
    Cb cb;
} Obj_8018FEB0;

#pragma opt_strength_reduction off
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
__declspec(section ".data") u32 fzgx_obj_lbl_8018FEB0;
__declspec(section ".data") s32 lbl_8018FEB0_4;
__declspec(section ".data") u32 lbl_8018FEB0_8;
__declspec(section ".data") u32 lbl_8018FEB0_fill_8018FEBC[9];
__declspec(section ".data") u32 lbl_8018FEE0[32];
__declspec(section ".data") u32 lbl_8018FF60[2];
__declspec(section ".data") u32 lbl_8018FF68[2];
__declspec(section ".data") Cb lbl_8018FF70;
__declspec(section ".data") u32 lbl_8018FF78[128];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_8018FEB0;
    s = *(u8 *)&lbl_8018FEB0_4;
    s = *(u8 *)&lbl_8018FEB0_8;
    s = *(u8 *)&lbl_8018FEB0_fill_8018FEBC;
    s = *(u8 *)&lbl_8018FEE0;
    s = *(u8 *)&lbl_8018FF60;
    s = *(u8 *)&lbl_8018FF68;
    s = *(u8 *)&lbl_8018FF70;
    s = *(u8 *)&lbl_8018FF78;
}
#pragma section code_type ".text"

void fn_80059914(void) {
    
    if (lbl_8018FF70.fn) {
        Cb *c = &lbl_8018FF70;
        c->fn(c->arg);
        if (!(lbl_8018FEB0_4)) {
            lbl_8018FEB0_8 = 5;
        }
        lbl_8018FEB0_4 = lbl_8018FEB0_4 + 1;
    }
}
#pragma opt_strength_reduction reset

