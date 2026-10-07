#include "types.h"

struct M {
    u8 pad_0[0x44];
    s32 dirty;
    s32 state;
    s32 mode;
    s32 paused;
    s32 count;
};

extern s32 fn_12_24990(struct M *);
extern s32 fn_12_24A88(s32, u32);
extern void fn_12_2DFF0(struct M *, s32);
extern s32 fn_12_2F210(struct M *, u32, u32, u32, u32);

#pragma opt_propagation off
static inline void helper(struct M *m, s32 k, s32 *r) {
    s32 old = *r;
    if (m->mode != 3 && m->mode != 4) {
        *r = old;
    } else {
        s32 t;
        fn_12_2DFF0(m, k);
        t = fn_12_2F210(m, 7, 8, k, 0);
        *r = 0;
        if (t != 0) {
            *r = t;
        }
    }
}

s32 fn_12_2AF5C(struct M *m, s32 pause) {
    s32 action;
    s32 ret;
    if (fn_12_24990(m)) {
        return fn_12_24A88(0, 0xff000142);
    }
    {
    s32 old_pause = m->paused;
    if (pause == 0) {
        if (old_pause == 0) {
            return 0;
        }
        action = 0;
    } else {
        if (old_pause == 0) {
            action = 1;
        } else {
            action = 2;
        }
    }
    }
    m->paused = pause;
    ret = 0;
    switch (action) {
    case 2:
        if (m->state == 4) {
            helper(m, 2, &ret);
        }
        break;
    case 1:
        if (m->count++ == 0) {
            helper(m, 1, &ret);
        }
        break;
    case 0:
        if (--m->count == 0) {
            helper(m, 0, &ret);
        }
        break;
    }
    m->dirty = 1;
    return ret;
}
