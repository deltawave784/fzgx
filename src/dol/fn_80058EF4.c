#include "types.h"

typedef struct {
    void (*fn)(u32, void *);
    u32 arg;
} Cb_X;

extern u8 lbl_80092384[];
extern void SVM_CallErr(const char *, ...);

static inline void callcb(Cb_X *c) {
    ((void (*)(u32))c->fn)(c->arg);
}

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
__declspec(section ".data") u32 fzgx_obj_lbl_8018FEB0;
__declspec(section ".data") volatile s32 lbl_8018FEB0_4; /* fzgx-allow: S2 retail reloads callback nesting depth after updating it. */
__declspec(section ".data") volatile s32 lbl_8018FEB0_8; /* fzgx-allow: S2 retail reloads shared callback state for the error diagnostic. */
__declspec(section ".data") u32 lbl_8018FEB0_fill_8018FEBC[9];
__declspec(section ".data") u8 lbl_8018FEE0[0x80];
__declspec(section ".data") Cb_X lbl_8018FF60;
__declspec(section ".data") Cb_X lbl_8018FF68;
__declspec(section ".data") Cb_X lbl_8018FF70;
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

void fn_80058EF4(u32 arg0, u32 arg1) {
    void (*callback)(u32, void *);
    if (lbl_8018FF70.fn != 0) {
        callcb(&lbl_8018FF70);
        if (lbl_8018FEB0_4 == 0) {
            lbl_8018FEB0_8 = 1;
        }
        lbl_8018FEB0_4 = lbl_8018FEB0_4 + 1;
    }
    callback = lbl_8018FF68.fn;
    *(u32 *)&lbl_8018FF60.fn = arg0;
    lbl_8018FF60.arg = arg1;
    if (callback != 0) {
        lbl_8018FEB0_4 = lbl_8018FEB0_4 - 1;
        if (lbl_8018FEB0_4 == 0) {
            if (lbl_8018FEB0_8 != 1) {
                SVM_CallErr((const char *)lbl_80092384, lbl_8018FEB0_8, 1);
            }
            lbl_8018FEB0_8 = 0;
        }
        callcb(&lbl_8018FF68);
    }
}
