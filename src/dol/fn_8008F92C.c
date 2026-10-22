#include "dolphin/types.h"

extern BOOL fn_8008FC3C(void *, s32, u32);
#include "sdk_addresses.h"

vu32 __EXIRegs[16] : FZGX_ADDR___EXIRegs;

static inline BOOL fn_8008F92C_call_fn_8008FC3C(u32 a2, s32 a1, void * a0) { return fn_8008FC3C(a0, a1, a2); }
BOOL fn_8008F92C(u32 *arg0) {
    vu32 *v1;
    u32 loc_18;
    struct { u32 value; u32 padding; } v2;
    vu32 *v3;
    BOOL t0;
    BOOL t1;
    u32 v4;

    v1 = &__EXIRegs[10];
    v4 = __EXIRegs[10];
    v4 &= 0x405;
    v4 |= 0xC0;
    __EXIRegs[10] = v4;
    loc_18 = 0x40000000;
    t0 = fn_8008FC3C((void *)&loc_18, 2, 1);
    v2.value = !t0;
    while (__EXIRegs[13] & 1) {}
    v3 = &__EXIRegs[13];
    t1 = fn_8008F92C_call_fn_8008FC3C(0, 4, (arg0));
    v2.value |= !t1;
    while (*v3 & 1) {}
    *v1 = *v1 & 0x405;
    return !v2.value;
}
