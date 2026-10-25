#include "types.h"
#include "dol/globals.h"

typedef void (*fn_800599E4_Callback)(u32);

typedef struct {
    fn_800599E4_Callback callback;
    u32 argument;
} fn_800599E4_CallbackData;

#pragma opt_propagation off
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
__declspec(section ".data") u32 fzgx_obj_lbl_8018FEB0;
__declspec(section ".data") u32 lbl_8018FEB0_4;
__declspec(section ".data") u32 lbl_8018FEB0_8;
__declspec(section ".data") u32 lbl_8018FEB0_fill_8018FEBC[9];
__declspec(section ".data") u32 lbl_8018FEE0[32];
__declspec(section ".data") u32 lbl_8018FF60[2];
__declspec(section ".data") u32 lbl_8018FF68[2];
__declspec(section ".data") u8 lbl_8018FF70;
__declspec(section ".data") u8 lbl_8018FF70_fill_8018FF71;
__declspec(section ".data") u16 lbl_8018FF70_fill_8018FF72;
__declspec(section ".data") u32 lbl_8018FF70_fill_8018FF74;
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
    s = *(u8 *)&lbl_8018FF70_fill_8018FF71;
    s = *(u8 *)&lbl_8018FF70_fill_8018FF72;
    s = *(u8 *)&lbl_8018FF70_fill_8018FF74;
    s = *(u8 *)&lbl_8018FF78;
}
#pragma section code_type ".text"

void fn_800599E4(void) {
    
    fn_800599E4_Callback callback = ((fn_800599E4_CallbackData *)((u8 *)&lbl_8018FF70))->callback;
    if (callback != 0) {
        fn_800599E4_CallbackData *entry = (fn_800599E4_CallbackData *)((u8 *)&lbl_8018FF70);
        callback(entry->argument);
        if ((s32)lbl_8018FEB0_4 == 0) {
            lbl_8018FEB0_8 = 3;
        }
        lbl_8018FEB0_4++;
    }
}
