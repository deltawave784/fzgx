#include "types.h"
  /* volatile: retail rereads this state word on every access */  /* volatile: retail rereads this state word on every access */  /* volatile: retail rereads this state word on every access */  /* volatile: retail rereads this state word on every access */
typedef struct {
    void (*fn)(void *);
    void *arg;
} fn_800596D4_Cb;

typedef struct {
    u32 unk_0;
    volatile s32 unk_4;  /* volatile: retail rereads this state word on every access */
    volatile s32 unk_8;  /* volatile: retail rereads this state word on every access */
    u8 pad_C[0xAC];
    fn_800596D4_Cb cb;
} fn_800596D4_Obj;

extern u8 lbl_80092384[];
extern void SVM_CallErr(const char *, ...);

static void fn_800596D4_Call(fn_800596D4_Cb *c) {
    c->fn(c->arg);
}

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
__declspec(section ".data") u32 fzgx_obj_lbl_8018FEB0;
__declspec(section ".data") volatile s32 lbl_8018FEB0_4;  /* volatile: retail rereads this state word on every access */
__declspec(section ".data") volatile s32 lbl_8018FEB0_8;  /* volatile: retail rereads this state word on every access */
__declspec(section ".data") u32 lbl_8018FEB0_fill_8018FEBC[9];
__declspec(section ".data") u32 lbl_8018FEE0[32];
__declspec(section ".data") u32 lbl_8018FF60[2];
__declspec(section ".data") fn_800596D4_Cb lbl_8018FF68;
__declspec(section ".data") u32 lbl_8018FF70[2];
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

void fn_800596D4(void) {
    
    fn_800596D4_Cb *cb;
    if (lbl_8018FF68.fn != 0) {
        lbl_8018FEB0_4 = lbl_8018FEB0_4 - 1;
        if (lbl_8018FEB0_4 == 0) {
            if (lbl_8018FEB0_8 != 5) {
                SVM_CallErr((const char *)lbl_80092384, lbl_8018FEB0_8, 5);
            }
            lbl_8018FEB0_8 = 0;
        }
        fn_800596D4_Call(&lbl_8018FF68);
    }
}
