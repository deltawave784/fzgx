#include "types.h"

typedef struct {
    void (*fn)(u32, void *);
    u32 arg;
} Cb_80059428;
typedef struct {
    u32 unk_0;
    volatile s32 unk_4; /* fzgx-allow: S2 retail reloads callback nesting depth after updating it. */
    volatile s32 unk_8; /* fzgx-allow: S2 retail reloads shared callback state for the error diagnostic. */
    u8 pad_C[0x24];
    u8 unk_30[0x80];
    Cb_80059428 c_b0;
    Cb_80059428 c_b8;
    Cb_80059428 c_c0;
    u8 pad_c8[0x40];
    u32 tab[1];
} Obj_80059428;

extern u8 lbl_800924C4[];
extern u8 lbl_80092384[];
extern char *strncpy(char *, const char *, size_t);
extern void SVM_CallErr(const char *, ...);

static inline void callcb(Cb_80059428 *c) {
    ((void (*)(u32))c->fn)(c->arg);
}
static inline void callcb2(Cb_80059428 *c, void *s) {
    c->fn(c->arg, s);
}

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
__declspec(section ".data") u32 fzgx_obj_lbl_8018FEB0;
__declspec(section ".data") volatile s32 lbl_8018FEB0_4; /* fzgx-allow: S2 retail reloads callback nesting depth after updating it. */
__declspec(section ".data") volatile s32 lbl_8018FEB0_8; /* fzgx-allow: S2 retail reloads shared callback state for the error diagnostic. */
__declspec(section ".data") u32 lbl_8018FEB0_fill_8018FEBC[9];
__declspec(section ".data") u8 lbl_8018FEE0[0x80];
__declspec(section ".data") Cb_80059428 lbl_8018FF60;
__declspec(section ".data") Cb_80059428 lbl_8018FF68;
__declspec(section ".data") Cb_80059428 lbl_8018FF70;
__declspec(section ".data") u32 lbl_8018FF78[16];
__declspec(section ".data") u32 lbl_8018FF78_40[1];
__declspec(section ".data") u32 lbl_8018FF78_fill_8018FFBC[111];

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
    s = *(u8 *)&lbl_8018FF78_40;
    s = *(u8 *)&lbl_8018FF78_fill_8018FFBC;
}
#pragma section code_type ".text"

s32 fn_80059428(s32 arg0, u32 arg1, u32 arg2) {
    
    s32 i;
    u32 *e;

    if (lbl_8018FF70.fn != 0) {
        callcb(&lbl_8018FF70);
        if (lbl_8018FEB0_4 == 0) {
            lbl_8018FEB0_8 = 1;
        }
        lbl_8018FEB0_4 = lbl_8018FEB0_4 + 1;
    }
    e = (u32 *)((u8 *)&lbl_8018FF78_40[0] + arg0 * 0x30);
    for (i = 0; i < 6; i++) {
        if (e[0] == 0) {
            e[0] = arg1;
            e[1] = arg2;
            break;
        }
        e += 2;
    }
    if (i == 6) {
        strncpy((char *)lbl_8018FEE0, (const char *)lbl_800924C4, 127);
        if (lbl_8018FF60.fn != 0) {
            callcb2(&lbl_8018FF60, lbl_8018FEE0);
        }
    }
    if (lbl_8018FF68.fn != 0) {
        lbl_8018FEB0_4 = lbl_8018FEB0_4 - 1;
        if (lbl_8018FEB0_4 == 0) {
            if (lbl_8018FEB0_8 != 1) {
                SVM_CallErr((const char *)lbl_80092384, lbl_8018FEB0_8, 1);
            }
            lbl_8018FEB0_8 = 0;
        }
        callcb(&lbl_8018FF68);
    }
    if (i == 6) {
        return -1;
    }
    return i;
}
