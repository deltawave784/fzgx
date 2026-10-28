#include "dolphin/types.h"
#include "dolphin/os/OSTime.h"
#include "sdk_addresses.h"

struct fn_80033EB0_gx_T {
    u8 pad_0[0x4F2];
    u8 unk_4F2;
};

extern OSTime OSGetTime(void);
extern vu16 *__memReg;
extern struct fn_80033EB0_gx_T *gx;
extern u32 fn_80032368(void);
extern vu32 __PIRegs[];

static inline u32 rd(void) {
    vu16 *p1 = __memReg + 0x27;
    vu16 *p2 = __memReg + 0x28;
    u32 hi, lo, prev;
    hi = __memReg[0x27];
    do {
        prev = hi;
        hi = *p1;
        lo = *p2;
    } while (hi != prev);
    return (hi << 16) | lo;
}

void fn_80033EB0(void) {
    u32 v;
    s64 t;
    u32 o;
    struct { vu32 *value; } pi;
    if (gx->unk_4F2 != 0 && fn_80032368() != 0) {
        v = rd();
        do {
            t = OSGetTime();
            o = v;
            while (OSGetTime() - t <= 8) {
            }
            v = rd();
        } while (v != o);
    }
    pi.value = (vu32 *)FZGX_ADDR___PIRegs;
    *(pi.value += 6) = 1;
    t = OSGetTime();
    while (OSGetTime() - t <= 50) {
    }
    *pi.value = 0;
    t = OSGetTime();
    while (OSGetTime() - t <= 5) {
    }
}
