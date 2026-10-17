#include "dolphin/types.h"

extern BOOL fn_8008FC3C(void *, s32, u32);
#include "sdk_addresses.h"

vu32 __EXIRegs[16] : FZGX_ADDR___EXIRegs;

BOOL fn_8008FAB4(u32 arg0, u32 arg1, s32 arg2) {
    vu32 *v2;
    u32 v3;
    u32 v7;
    u32 v6;
    u32 loc_24;
    u32 loc_20;
    BOOL t0;
    BOOL t1;
    u32 v0;
    u32 v1;
    u32 v4;

    v6 = arg1;
    v2 = &__EXIRegs[10];
    v3 = __EXIRegs[10];
    v3 &= 0x405;
    v3 |= 0xC0;
    __EXIRegs[10] = v3;
    loc_24 = ((arg0 << 8) & 0x1FFFC00) | 0x20000000;
    t0 = fn_8008FC3C((void *)&loc_24, 4, 1);
    v7 = !t0;
    while (__EXIRegs[13] & 1) {}
    while (arg2 != 0) {
        t1 = fn_8008FC3C((void *)&loc_20, 4, 0);
        v7 |= !t1;
        while (__EXIRegs[13] & 1) {}
        arg2 -= 4;
        *(u32 *)v6 = loc_20;
        v6 += 4;
        if (arg2 < 0) {
            arg2 = 0;
        }
    }
    *v2 = *v2 & 0x405;
    return !v7;
}
