#include "dol/globals.h"
  /* volatile: retail rereads this state word on every access */  /* volatile: retail rereads this state word on every access */  /* volatile: retail rereads this state word on every access */  /* volatile: retail rereads this state word on every access */
extern u8 lbl_80092384[288];
extern void SVM_CallErr(const char *, ...);

typedef struct {
    void (*fn)(u32);
    u32 arg;
} Cb;

typedef struct {
    u32 unk_0;
    volatile s32 cnt;  /* volatile: retail rereads this state word on every access */
    volatile s32 state;  /* volatile: retail rereads this state word on every access */
    u8 pad_C[0x20];
    u32 (*fn2C)(void);
    u8 pad_30[0x88];
    Cb cbB8;
    Cb cbC0;
} Obj_Local;

#define callcb(c) ((c)->fn((c)->arg))

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
__declspec(section ".data") u32 fzgx_obj_lbl_8018FEB0;
__declspec(section ".data") volatile s32 lbl_8018FEB0_4;  /* volatile: retail rereads this state word on every access */
__declspec(section ".data") volatile s32 lbl_8018FEB0_8;  /* volatile: retail rereads this state word on every access */
__declspec(section ".data") u32 lbl_8018FEB0_fill_8018FEBC[8];
__declspec(section ".data") u32 (*lbl_8018FEB0_2C)(void);
__declspec(section ".data") u32 lbl_8018FEE0[32];
__declspec(section ".data") u32 lbl_8018FF60[2];
__declspec(section ".data") Cb lbl_8018FF68;
__declspec(section ".data") Cb lbl_8018FF70;
__declspec(section ".data") u32 lbl_8018FF78[128];

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
}
#pragma section code_type ".text"

u32 fn_80058A40(u32 *p) {
    
    u32 old;
    u32 r = (u32)p;
    if (lbl_8018FEB0_2C != 0) {
        r = lbl_8018FEB0_2C();
    } else {
        if (lbl_8018FF70.fn != 0) {
            callcb(&lbl_8018FF70);
            if (lbl_8018FEB0_4 == 0) {
                lbl_8018FEB0_8 = 1;
            }
            lbl_8018FEB0_4 = lbl_8018FEB0_4 + 1;
        }
        old = *p;
        *p = 1;
        r = (old != 1);
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
    }
    return r;
}
