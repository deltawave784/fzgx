#include "types.h"

typedef struct Object {
    u8 active;
    u8 index;
    u8 pad[2];
    u32 a;
    u32 b;
    u32 c;
    u32 d;
} Object;
typedef struct State {
    u32 refs;
    u32 init;
    u32 table1;
    u32 table2;
    Object *slots[16];
} State;
extern void *memset(void *dest, int value, u32 size);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
__declspec(section ".data") u32 lbl_80187370[2];
__declspec(section ".data") u32 lbl_80187370_8;
__declspec(section ".data") u32 lbl_80187370_C;
__declspec(section ".data") Object *lbl_80187380[16];
__declspec(section ".data") u32 lbl_801873C0[6];
__declspec(section ".data") u32 lbl_801873D8;
__declspec(section ".data") u32 lbl_801873DC[4];
__declspec(section ".data") u32 lbl_801873EC[17];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&lbl_80187370;
    s = *(u8 *)&lbl_80187370_8;
    s = *(u8 *)&lbl_80187370_C;
    s = *(u8 *)&lbl_80187380;
    s = *(u8 *)&lbl_801873C0;
    s = *(u8 *)&lbl_801873D8;
    s = *(u8 *)&lbl_801873DC;
    s = *(u8 *)&lbl_801873EC;
}
#pragma section code_type ".text"

Object *fn_80053A84(Object *arg0, u32 size) {
    
    s32 i;
    Object *obj;
    Object **slots = lbl_80187380;
    for (i = 0; i < 16; i++) {
        if (slots[i] == 0) break;
    }
    if (i == 16) return 0;
    memset(arg0, 0, size);
    lbl_80187380[i] = arg0;
    obj = lbl_80187380[i];
    obj->index = i;
    obj->b = 0x40;
    obj->a = 0x40;
    obj->d = lbl_80187370_8;
    obj->c = lbl_80187370_C;
    obj->active = 1;
    return obj;
}
