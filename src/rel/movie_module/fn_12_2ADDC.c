#include "types.h"

struct M {
    u8 pad_0[0x48];
    s32 state;
    s32 mode;
    u8 pad_50[4];
    s32 count;
};

extern void fn_12_2DFF0(struct M *, s32);
extern s32 fn_12_2F210(struct M *, u32, u32, u32, u32);

static inline s32 helper(struct M *m, s32 k) {
    s32 r;
    if (m->mode != 3 && m->mode != 4) {
        r = 0;
    } else {
        s32 t;
        fn_12_2DFF0(m, k);
        t = fn_12_2F210(m, 7, 8, k, 0);
        r = 0;
        if (t != 0) {
            r = t;
        }
    }
    return r;
}

s32 fn_12_2ADDC(struct M *m, s32 arg1) {
    s32 ret = 0;
    switch (arg1) {
    case 2:
        if (m->state == 4) {
            ret = helper(m, 2);
        }
        break;
    case 1:
        if (m->count++ == 0) {
            ret = helper(m, 1);
        }
        break;
    case 0:
        if (--m->count == 0) {
            ret = helper(m, 0);
        }
        break;
    }
    return ret;
}
