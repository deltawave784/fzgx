#include "types.h"
#include "dol/globals.h"

typedef u32 (*Callback)(u32);
typedef struct {
    Callback callback;
    u32 argument;
} CallbackEntry;
typedef struct {
    u8 pad_0[0xF0];
    CallbackEntry entries[18];
} CallbackBlock;
typedef struct {
    u8 pad_0[0x14];
    u32 value;
    u8 pad_18[8];
} StatusBlock;

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


static inline u32 invoke_callbacks(CallbackBlock *callbacks, StatusBlock *status, u32 initial) {
    s32 i;
    u32 result;
    u32 zero;
    u32 one;
    Callback callback;
    CallbackEntry *entries;
    result = initial;
    one = 1;
    i = initial;
    zero = initial;
    entries = callbacks->entries;
    for (; i < 6; i++) {
        callback = entries[i].callback;
        if (callback != 0) {
            status->value = one;
            result |= callback(entries[i].argument);
            status->value = zero;
        }
    }
    return result;
}

static inline void increment_counter(StatusBlock *counter) {
    counter->value++;
}

u32 fn_80058D24(void) {
    u32 result;
    result = invoke_callbacks(&(*(CallbackBlock *)&lbl_8018FF78_40), &(*(StatusBlock *)&lbl_8018FF78_1C0), 0);
    increment_counter(&(*(StatusBlock *)&lbl_8018FF78_1E0));
    return result;
}
