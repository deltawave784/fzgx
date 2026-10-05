#include "types.h"

typedef void (*fn_8005782C_Fn0)(u32, s32);

struct fn_8005782C_Arg0 {
    u8 pad_0[0xc];
    s32 unk_c;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    fn_8005782C_Fn0 unk_1c;
    u32 unk_20;
};

struct fn_8005782C_Arg2 {
    u32 unk_0;
    s32 unk_4;
};

extern u32 fn_800576DC(void);
extern u32 fn_80057728(void);

/* Returns arg0 untouched when nothing is pending, else fn_800576DC's result
 * (same shape as fn_8005795C). */
u32 fn_8005782C(u32 arg0, s32 arg1, struct fn_8005782C_Arg2 *arg2) {
    struct fn_8005782C_Arg0 *p = (struct fn_8005782C_Arg0 *)arg0;
    s32 t;
    s32 n;

    if (arg2->unk_4 > 0) {
        if (arg2->unk_0 == 0) {
            return arg0;
        }
        fn_80057728();
        if (arg1 == 0) {
            if (p->unk_1c != NULL) {
                p->unk_1c(p->unk_20, -3);
            }
        } else if (arg1 == 1) {
            t = (p->unk_10 - arg2->unk_4 > 0) ? p->unk_10 - arg2->unk_4 : 0;
            p->unk_10 = t;
            n = p->unk_c + arg2->unk_4;
            p->unk_c = (p->unk_18 < n) ? p->unk_18 : n;
            if (t != (s32)(arg2->unk_0 - p->unk_14)) {
                if (p->unk_1c != NULL) {
                    p->unk_1c(p->unk_20, -3);
                }
            }
        } else {
            arg2->unk_4 = 0;
            arg2->unk_0 = 0;
            if (p->unk_1c != NULL) {
                p->unk_1c(p->unk_20, -3);
            }
        }
        return fn_800576DC();
    }
    return arg0;
}
