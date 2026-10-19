#include "types.h"
#include "dol/globals.h"

typedef void (*fn_80059AB4_Callback)(u32);
struct fn_80059AB4_CallbackData {
    fn_80059AB4_Callback callback;
    u32 argument;
};

extern u8 lbl_80092384[288];
extern void SVM_CallErr(const char *, ...);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
__declspec(section ".data") u32 fzgx_obj_lbl_8018FEB0;
__declspec(section ".data") u32 lbl_8018FEB0_4;
__declspec(section ".data") u32 lbl_8018FEB0_8;
__declspec(section ".data") u32 lbl_8018FEB0_fill_8018FEBC[9];
__declspec(section ".data") u32 lbl_8018FEE0[32];
__declspec(section ".data") u32 lbl_8018FF60[2];
__declspec(section ".data") u8 lbl_8018FF68;
__declspec(section ".data") u8 lbl_8018FF68_fill_8018FF69;
__declspec(section ".data") u16 lbl_8018FF68_fill_8018FF6A;
__declspec(section ".data") u32 lbl_8018FF68_fill_8018FF6C;
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
    s = *(u8 *)&lbl_8018FF68_fill_8018FF69;
    s = *(u8 *)&lbl_8018FF68_fill_8018FF6A;
    s = *(u8 *)&lbl_8018FF68_fill_8018FF6C;
    s = *(u8 *)&lbl_8018FF70;
    s = *(u8 *)&lbl_8018FF78;
}
#pragma section code_type ".text"

void fn_80059AB4(void) {
    
    if (*(fn_80059AB4_Callback *)((u8 *)&lbl_8018FF68) != 0) {
        --*(volatile u32 *)&lbl_8018FEB0_4;  /* fzgx-allow: S2 volatile view keeps the verified load order */
        if ((s32)*(volatile u32 *)&lbl_8018FEB0_4 == 0) {  /* fzgx-allow: S2 volatile view keeps the verified load order */
            if ((s32)*(volatile u32 *)&lbl_8018FEB0_8 != 1) {  /* fzgx-allow: S2 volatile view keeps the verified load order */
                SVM_CallErr((const char *)lbl_80092384, lbl_8018FEB0_8, 1);
            }
            lbl_8018FEB0_8 = 0;
        }
        ((struct fn_80059AB4_CallbackData *)((u8 *)&lbl_8018FF68))->callback(
            ((struct fn_80059AB4_CallbackData *)((u8 *)&lbl_8018FF68))->argument);
    }
}
