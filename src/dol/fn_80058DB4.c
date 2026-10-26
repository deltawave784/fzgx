#include "types.h"
#include "dol/globals.h"

typedef struct {
    u32 (*callback)(u32);
    u32 argument;
} CallbackEntry;

/* file-scope objects of the retail TU (from a matched sibling), in retail order: MWCC addresses them off one section base */
__declspec(section ".data") u32 fzgx_obj_lbl_8018FEB0;
__declspec(section ".data") volatile s32 lbl_8018FEB0_4; /* volatile: retail rereads this state word on every access */
__declspec(section ".data") volatile s32 lbl_8018FEB0_8; /* volatile: retail rereads this state word on every access */
__declspec(section ".data") u32 lbl_8018FEB0_fill_8018FEBC[8];
__declspec(section ".data") u32 lbl_8018FEB0_2C;
__declspec(section ".data") u32 lbl_8018FEE0[32];
__declspec(section ".data") u32 lbl_8018FF60[2];
__declspec(section ".data") u32 lbl_8018FF68[2];
__declspec(section ".data") u32 lbl_8018FF70[2];
__declspec(section ".data") u32 lbl_8018FF78[16];
__declspec(section ".data") u32 lbl_8018FF78_40[1];
__declspec(section ".data") u32 lbl_8018FF78_fill_8018FFBC[95];
__declspec(section ".data") u8 lbl_8018FF78_1C0[0x20];
__declspec(section ".data") u32 lbl_8018FF78_1E0[6];
__declspec(section ".data") u32 lbl_8018FF78_fill_80190170[2];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_8018FEB0;
    s = *(u8 *)&lbl_8018FEB0_4;
    s = *(u8 *)&lbl_8018FEB0_8;
    s = *(u8 *)&lbl_8018FEB0_fill_8018FEBC;
    s = *(u8 *)&lbl_8018FEB0_2C;
    s = *(u8 *)&lbl_8018FEE0;
    s = *(u8 *)&lbl_8018FF60;
    s = *(u8 *)&lbl_8018FF68;
    s = *(u8 *)&lbl_8018FF70;
    s = *(u8 *)&lbl_8018FF78;
    s = *(u8 *)&lbl_8018FF78_40;
    s = *(u8 *)&lbl_8018FF78_fill_8018FFBC;
    s = *(u8 *)&lbl_8018FF78_1C0;
    s = *(u8 *)&lbl_8018FF78_1E0;
    s = *(u8 *)&lbl_8018FF78_fill_80190170;
}
#pragma section code_type ".text"


static inline u32 run_callbacks(u32 zero) {
    CallbackEntry *entries;
    s32 i;
    u32 result;
    result = zero;
    entries = ((CallbackEntry (*)[6])&lbl_8018FF78_40)[4];
    for (i = zero; i < 6; i++, entries++) {
        u32 (*callback)(u32) = entries->callback;
        if (callback != 0) {
            ((u32 *)&lbl_8018FF78_1C0)[4] = 1;
            result |= callback(entries->argument);
            ((u32 *)&lbl_8018FF78_1C0)[4] = zero;
        }
    }
    return result;
}

u32 fn_80058DB4(void) {
    u32 result;
    result = run_callbacks(0);
    ((u32 *)&lbl_8018FF78_1E0)[4]++;
    return result;
}
