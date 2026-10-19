#include "types.h"
#include "dol/globals.h"

extern void *memset(void *, int, u32);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
__declspec(section ".data") u32 fzgx_obj_lbl_8018FEB0;
__declspec(section ".data") u32 lbl_8018FEB0_fill_8018FEB4[10];
__declspec(section ".data") u32 lbl_8018FEB0_2C;
__declspec(section ".data") u32 lbl_8018FEE0[32];
__declspec(section ".data") u8 lbl_8018FF60;
__declspec(section ".data") u8 lbl_8018FF60_fill_8018FF61;
__declspec(section ".data") u16 lbl_8018FF60_fill_8018FF62;
__declspec(section ".data") u32 lbl_8018FF60_fill_8018FF64;
__declspec(section ".data") u8 lbl_8018FF68;
__declspec(section ".data") u8 lbl_8018FF68_fill_8018FF69;
__declspec(section ".data") u16 lbl_8018FF68_fill_8018FF6A;
__declspec(section ".data") u32 lbl_8018FF68_fill_8018FF6C;
__declspec(section ".data") u8 lbl_8018FF70;
__declspec(section ".data") u8 lbl_8018FF70_fill_8018FF71;
__declspec(section ".data") u16 lbl_8018FF70_fill_8018FF72;
__declspec(section ".data") u32 lbl_8018FF70_fill_8018FF74;
__declspec(section ".data") u32 lbl_8018FF78[112];
__declspec(section ".data") u8 lbl_8018FF78_1C0;
__declspec(section ".data") u8 lbl_8018FF78_fill_80190139;
__declspec(section ".data") u16 lbl_8018FF78_fill_8019013A;
__declspec(section ".data") u32 lbl_8018FF78_fill_8019013C[7];
__declspec(section ".data") u8 lbl_8018FF78_1E0;
__declspec(section ".data") u8 lbl_8018FF78_fill_80190159;
__declspec(section ".data") u16 lbl_8018FF78_fill_8019015A;
__declspec(section ".data") u32 lbl_8018FF78_fill_8019015C[7];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_8018FEB0;
    s = *(u8 *)&lbl_8018FEB0_fill_8018FEB4;
    s = *(u8 *)&lbl_8018FEB0_2C;
    s = *(u8 *)&lbl_8018FEE0;
    s = *(u8 *)&lbl_8018FF60;
    s = *(u8 *)&lbl_8018FF60_fill_8018FF61;
    s = *(u8 *)&lbl_8018FF60_fill_8018FF62;
    s = *(u8 *)&lbl_8018FF60_fill_8018FF64;
    s = *(u8 *)&lbl_8018FF68;
    s = *(u8 *)&lbl_8018FF68_fill_8018FF69;
    s = *(u8 *)&lbl_8018FF68_fill_8018FF6A;
    s = *(u8 *)&lbl_8018FF68_fill_8018FF6C;
    s = *(u8 *)&lbl_8018FF70;
    s = *(u8 *)&lbl_8018FF70_fill_8018FF71;
    s = *(u8 *)&lbl_8018FF70_fill_8018FF72;
    s = *(u8 *)&lbl_8018FF70_fill_8018FF74;
    s = *(u8 *)&lbl_8018FF78;
    s = *(u8 *)&lbl_8018FF78_1C0;
    s = *(u8 *)&lbl_8018FF78_fill_80190139;
    s = *(u8 *)&lbl_8018FF78_fill_8019013A;
    s = *(u8 *)&lbl_8018FF78_fill_8019013C;
    s = *(u8 *)&lbl_8018FF78_1E0;
    s = *(u8 *)&lbl_8018FF78_fill_80190159;
    s = *(u8 *)&lbl_8018FF78_fill_8019015A;
    s = *(u8 *)&lbl_8018FF78_fill_8019015C;
}
#pragma section code_type ".text"

void fn_80058B54(void) {
    
    u32 *q;
    (*(volatile u32 *)&fzgx_obj_lbl_8018FEB0)--;  /* fzgx-allow: S2 volatile view keeps the verified load order */
    if ((s32)*(volatile u32 *)&fzgx_obj_lbl_8018FEB0 == 0) {  /* fzgx-allow: S2 volatile view keeps the verified load order */
        memset((u8 *)&lbl_8018FF78_1C0, 0, 0x20);
        memset((u8 *)&lbl_8018FF70, 0, 8);
        memset((u8 *)&lbl_8018FF68, 0, 8);
        q = (u32 *)((u8 *)&lbl_8018FF78_1E0);
        q[0] = 0;
        q[1] = 0;
        q[2] = 0;
        q[3] = 0;
        q[4] = 0;
        q[5] = 0;
        lbl_8018FEB0_2C = 0;
        memset((u8 *)&lbl_8018FF60, 0, 8);
    }
}
