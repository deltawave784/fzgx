#include "dolphin/types.h"

extern BOOL fn_8008FC3C(void *, s32, u32);
#include "sdk_addresses.h"
vu32 __EXIRegs[16] : FZGX_ADDR___EXIRegs;

static inline BOOL fn_8008FB90_call_fn_8008FC3C(void * a0, s32 a1, u32 a2) { return fn_8008FC3C(a0, a1, a2); }
BOOL fn_8008FB90(u32 *arg0) {
    vu32 *v1;
    u32 v2;
    u32 v3;
    u32 loc_18;
    BOOL t0;
    BOOL t1;
    u32 pad0;
    u32 pad1;

    v1 = &__EXIRegs[10];
    v3 = __EXIRegs[10];
    v3 &= 0x405;
    v3 |= 0xC0;
    __EXIRegs[10] = v3;
    loc_18 = 0x60000000;
    t0 = fn_8008FC3C((void *)&loc_18, 2, 1);
    v2 = !t0;
    while (__EXIRegs[13] & 1) {}
    t1 = fn_8008FB90_call_fn_8008FC3C((arg0), 4, 0);
    v2 |= !t1;
    while (__EXIRegs[13] & 1) {}
    *v1 = *v1 & 0x405;
    return !v2;
}
