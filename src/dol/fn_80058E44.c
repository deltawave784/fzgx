#include "types.h"
#include "dol/globals.h"

typedef s32 (*Callback_80058E44)(u32);
typedef struct {
    Callback_80058E44 callback;
    u32 arg;
} CallbackEntry_80058E44;

static inline s32 runCallbacks_80058E44(Obj_8018FEB0 *active,
    CallbackEntry_80058E44 *callbacks, s32 zero) {
    s32 i;
    s32 result = zero;
    s32 clear = zero;
    callbacks += 12;
    for (i = zero; i < 6; i++, callbacks++) {
        Callback_80058E44 callback = callbacks->callback;
        if (callback != 0) {
            active->unk_8 = 1;
            result |= callback(callbacks->arg);
            active->unk_8 = clear;
        }
    }
    return result;
}

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
__declspec(section ".data") u32 fzgx_obj_lbl_8018FEB0[12];
__declspec(section ".data") u32 lbl_8018FEE0[32];
__declspec(section ".data") u32 lbl_8018FF60[2];
__declspec(section ".data") u32 lbl_8018FF68[2];
__declspec(section ".data") u32 lbl_8018FF70[2];
__declspec(section ".data") u32 lbl_8018FF78[16];
__declspec(section ".data") u8 lbl_8018FF78_40;
__declspec(section ".data") u8 lbl_8018FF78_fill_8018FFB9;
__declspec(section ".data") u16 lbl_8018FF78_fill_8018FFBA;
__declspec(section ".data") u32 lbl_8018FF78_fill_8018FFBC[95];
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
    s = *(u8 *)&lbl_8018FEE0;
    s = *(u8 *)&lbl_8018FF60;
    s = *(u8 *)&lbl_8018FF68;
    s = *(u8 *)&lbl_8018FF70;
    s = *(u8 *)&lbl_8018FF78;
    s = *(u8 *)&lbl_8018FF78_40;
    s = *(u8 *)&lbl_8018FF78_fill_8018FFB9;
    s = *(u8 *)&lbl_8018FF78_fill_8018FFBA;
    s = *(u8 *)&lbl_8018FF78_fill_8018FFBC;
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

s32 fn_80058E44(void) {
    s32 result;
    Obj_8018FEB0 * lab_t0;
    
    lab_t0 = (Obj_8018FEB0 *)&lbl_8018FF78_1C0;
    result = runCallbacks_80058E44(lab_t0, (CallbackEntry_80058E44 *)&lbl_8018FF78_40, 0);
    ((Obj_8018FEB0 *)&lbl_8018FF78_1E0)->unk_8++;
    return result;
}
