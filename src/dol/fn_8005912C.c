#include "types.h"

typedef struct {
    void (*fn)(u32, void *);
    u32 arg;
} Cb_X;

extern u8 lbl_80092384[];
extern char *strncpy(char *, const char *, size_t);
extern void SVM_CallErr(const char *, ...);

static inline void callcb(Cb_X *c) {
    ((void (*)(u32))c->fn)(c->arg);
}
static inline void callcb2(Cb_X *c, void *s) {
    c->fn(c->arg, s);
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

extern u8 lbl_80092350__fzgx_offset_0[];
static const u32 fzgx_pool_rodata_lbl_80092350[13] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0xA53564D, 0x2F474320, 0x5665722E, 0x312E3531, 0x20427569, 0x6C643A4D, 0x61792020, 0x39203230,
    0x30332031, 0x373A3130, 0x3A31310A, 0x0, (u32)lbl_80092350__fzgx_offset_0
};
static const u32 fzgx_pool_rodata_lbl_80092384[39] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x32313033, 0x3130323A, 0x53564D3A, 0x73766D5F, 0x756E6C6F, 0x636B3A6C, 0x6F636B20, 0x74797065,
    0x206D6973, 0x73206D61, 0x7463682E, 0x28747970, 0x65206F72, 0x673D2564, 0x2C207479, 0x7065206E,
    0x6F773D25, 0x64290000, 0x31303731, 0x3330313A, 0x53564D5F, 0x45786563, 0x53767246, 0x756E6349,
    0x643A696C, 0x6C656761, 0x6C206964, 0x0, 0x31303731, 0x3330323A, 0x53564D5F, 0x45786563,
    0x53767246, 0x756E6349, 0x643A696C, 0x6C656761, 0x6C207376, 0x74797065, 0x0
};
static const u32 fzgx_pool_rodata_lbl_80092350_D0[9] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x31303731, 0x3230313A, 0x53564D5F, 0x53657443, 0x62537672, 0x49643A69, 0x6C6C6567, 0x616C2069,
    0x64000000
};
static const u32 fzgx_pool_rodata_lbl_80092350_F4[10] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x31303731, 0x3230323A, 0x53564D5F, 0x53657443, 0x62537672, 0x49643A69, 0x6C6C6567, 0x616C2073,
    0x76747970, 0x65000000
};
static const u32 fzgx_pool_rodata_lbl_80092350_11C[14] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x32313030, 0x3830313A, 0x53564D5F, 0x53657443, 0x62537672, 0x49643A6F, 0x76657220, 0x77726974,
    0x65206361, 0x6C6C6261, 0x636B2066, 0x756E6374, 0x696F6E2E, 0x0
};
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_80092350(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .data objects in retail order */
    s = *(u8 *)fzgx_pool_rodata_lbl_80092350;
    s = *(u8 *)fzgx_pool_rodata_lbl_80092384;
    s = *(u8 *)fzgx_pool_rodata_lbl_80092350_D0;
    s = *(u8 *)fzgx_pool_rodata_lbl_80092350_F4;
    s = *(u8 *)fzgx_pool_rodata_lbl_80092350_11C;
}
#pragma section code_type ".text"

void fn_8005912C(s32 arg0, s32 arg1, u32 arg2, u32 arg3) {
    u32 *e;
    void (*callback)(u32, void *);
    
    if (arg1 < 0 || arg1 >= 6) {
        strncpy((char *)lbl_8018FEE0, ((char *)fzgx_pool_rodata_lbl_80092350_D0), 127);
        if (lbl_8018FF60.fn != 0) {
            callcb2(&lbl_8018FF60, lbl_8018FEE0);
        }
    }
    if (arg0 < 0 || arg1 >= 8) {
        strncpy((char *)lbl_8018FEE0, ((char *)fzgx_pool_rodata_lbl_80092350_F4), 127);
        if (lbl_8018FF60.fn != 0) {
            callcb2(&lbl_8018FF60, lbl_8018FEE0);
        }
    }
    if (lbl_8018FF70.fn != 0) {
        callcb(&lbl_8018FF70);
        if (lbl_8018FEB0_4 == 0) {
            lbl_8018FEB0_8 = 1;
        }
        lbl_8018FEB0_4 = lbl_8018FEB0_4 + 1;
    }
    e = (u32 *)(((arg1 * 8) + ((arg0 * 0x30) + ((u8 *)&lbl_8018FF78_40[0]))));
    if (e[0] != 0) {
        strncpy((char *)lbl_8018FEE0, ((char *)fzgx_pool_rodata_lbl_80092350_11C), 127);
        if (lbl_8018FF60.fn != 0) {
            callcb2(&lbl_8018FF60, lbl_8018FEE0);
        }
    }
    callback = lbl_8018FF68.fn;
    e[0] = arg2;
    e[1] = arg3;
    if (callback != 0) {
        lbl_8018FEB0_4 = lbl_8018FEB0_4 - 1;
        if (lbl_8018FEB0_4 == 0) {
            if (lbl_8018FEB0_8 != 1) {
                SVM_CallErr(((char *)fzgx_pool_rodata_lbl_80092384), lbl_8018FEB0_8, 1);
            }
            lbl_8018FEB0_8 = 0;
        }
        callcb(&lbl_8018FF68);
    }
}
