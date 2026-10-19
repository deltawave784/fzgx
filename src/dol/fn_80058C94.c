#include "types.h"
#include "dol/globals.h"

typedef struct {
    u32 (*callback)(u32);
    u32 arg;
} CallbackEntry;

typedef struct {
    u8 pad_0[0x18];
    u32 unk_18;
} CallbackState;

#pragma opt_propagation off
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

static inline u32 run_callbacks(u32 zero) {
    s32 i;
    u32 result;
    struct { CallbackEntry *p; } entry;
    struct { CallbackState *p; } state;
    struct { CallbackState *p; } counter;
    
    result = zero;
    entry.p = (CallbackEntry *)&lbl_8018FF78_40;
    state.p = (CallbackState *)&lbl_8018FF78_1C0;
    entry.p += 36;
    for (i = zero; i < 6; i++, entry.p++) {
        u32 (*callback)(u32) = entry.p->callback;
        if (callback != 0) {
            state.p->unk_18 = 1;
            result |= callback(entry.p->arg);
            state.p->unk_18 = zero;
        }
    }
    counter.p = (CallbackState *)&lbl_8018FF78_1E0;
    counter.p->unk_18++;
    return result;
}

u32 fn_80058C94(void) {
    return run_callbacks(0);
}
