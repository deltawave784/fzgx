#include "types.h"

extern s32 lbl_801A6C88;
extern u8 lbl_80199670[0x4920];

extern void fn_8006AA20(u32, u32);
extern void fn_8006B92C(void *);
extern void fn_8006B048(void *, s32);
extern s32 fn_80013428(s32, void *);
extern u32 fn_800137C4(s32, void *);
extern void fn_8006AF94(void);
extern u32 fn_80013994(void *);

#pragma opt_strength_reduction off
#pragma opt_propagation off
#pragma use_lmw_stmw on
void fn_8006B188(void) {
    s32 off;
    void *callback;
    u8 *base;
    u8 *p;
    s32 i;
    if (lbl_801A6C88 == 0) {
        base = lbl_80199670;
        callback = (void *)fn_8006AA20;
        i = 0;
        for (; i < 4; i++) {
            off = i * 0x1248;
            p = base + off;
            fn_8006B92C(p + 0x50);
            fn_8006B048(p, i);
            fn_80013428(i, (void *)fn_8006AA20);
            fn_800137C4(i, p + 0xc);
        }
        fn_80013994((void *)fn_8006AF94);
        lbl_801A6C88 = 1;
    }
}
