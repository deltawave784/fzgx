#include "types.h"
#include "dol/globals.h"

extern void fn_800370A0(s32, s32, s32, s32, s32);
extern void fn_800370E4(s32, s32, s32, s32, s32);
extern void fn_80037128(s32, s32, s32, s32, u8, s32);
extern void fn_80037190(s32, s32, s32, s32, u8, s32);

/* Inline copies of the cached setters fn_80072C24 / fn_80072CC4 / fn_80072E20. */
static inline void setA0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u32 *entry;

    entry = (u32 *)(lbl_801A6D38 + (arg0 << 4) + 0xf0);
    if ((s32)entry[0] == arg1 &&
        (s32)entry[1] == arg2 &&
        (s32)entry[2] == arg3 &&
        (s32)entry[3] == arg4) {
        return;
    }

    fn_800370A0(arg0, arg1, arg2, arg3, arg4);
    entry[0] = arg1;
    entry[1] = arg2;
    entry[2] = arg3;
    entry[3] = arg4;
}

static inline void setE4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u32 *entry;

    entry = (u32 *)(lbl_801A6D38 + (arg0 << 4) + 0x1f0);
    if ((s32)entry[0] == arg1 &&
        (s32)entry[1] == arg2 &&
        (s32)entry[2] == arg3 &&
        (s32)entry[3] == arg4) {
        return;
    }

    fn_800370E4(arg0, arg1, arg2, arg3, arg4);
    entry[0] = arg1;
    entry[1] = arg2;
    entry[2] = arg3;
    entry[3] = arg4;
}

static inline void set28(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5) {
    u8 *entry;

    entry = (u8 *)lbl_801A6D38 + arg0 * 0x14 + 0x2f0;
    if (*(s32 *)(entry + 0x10) == arg5 &&
        *(s32 *)(entry + 0x8) == arg3 &&
        *(u8 *)(entry + 0xc) == arg4 &&
        *(s32 *)(entry + 0x0) == arg1 &&
        *(s32 *)(entry + 0x4) == arg2) {
        return;
    }

    fn_80037128(arg0, arg1, arg2, arg3, arg4, arg5);
    *(s32 *)(entry + 0x0) = arg1;
    *(s32 *)(entry + 0x4) = arg2;
    *(s32 *)(entry + 0x8) = arg3;
    *(u8 *)(entry + 0xc) = arg4;
    *(s32 *)(entry + 0x10) = arg5;
}

static inline void set90(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5) {
    u8 *entry;

    entry = (u8 *)lbl_801A6D38 + arg0 * 0x14 + 0x430;
    if (*(s32 *)(entry + 0x10) == arg5 &&
        *(s32 *)(entry + 0x8) == arg3 &&
        *(u8 *)(entry + 0xc) == arg4 &&
        *(s32 *)(entry + 0x0) == arg1 &&
        *(s32 *)(entry + 0x4) == arg2) {
        return;
    }

    fn_80037190(arg0, arg1, arg2, arg3, arg4, arg5);
    *(s32 *)(entry + 0x0) = arg1;
    *(s32 *)(entry + 0x4) = arg2;
    *(s32 *)(entry + 0x8) = arg3;
    *(u8 *)(entry + 0xc) = arg4;
    *(s32 *)(entry + 0x10) = arg5;
}

void fn_80072EDC(s32 arg0, s32 arg1) {
    s32 v0;
    s32 v1;

    if (arg0 == 0) {
        v0 = 10;
        v1 = 5;
    } else {
        v0 = 0;
        v1 = 0;
    }

    switch (arg1) {
    case 1:
        setA0(arg0, v0, 8, 9, 15);
        setE4(arg0, 7, 7, 7, v1);
        break;
    case 0:
        setA0(arg0, 15, 8, v0, 15);
        setE4(arg0, 7, 4, v1, 7);
        break;
    case 3:
        setA0(arg0, 15, 15, 15, 8);
        setE4(arg0, 7, 7, 7, 4);
        break;
    case 4:
        setA0(arg0, 15, 15, 15, v0);
        setE4(arg0, 7, 7, 7, v1);
        break;
    case 2:
        setA0(arg0, v0, 15, 8, 8);
        setE4(arg0, 7, 4, v1, 7);
        break;
    }

    set28(arg0, 0, 0, 0, 1, 0);
    set90(arg0, 0, 0, 0, 1, 0);
}
