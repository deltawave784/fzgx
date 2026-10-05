#include "types.h"

extern void fn_8005A648(void);
extern void fn_8005A628(void);
extern void fn_800230A4(void *, s32);
extern void fn_80023438(u32, void *);

typedef struct H {
    u8 pad0[2];
    s8 channels;
    u8 pad3[5];
    u32 voices[1];
} H;

#pragma use_lmw_stmw on
#pragma opt_loop_invariants off
void fn_8005A7F8(u8 *h, s32 vol) {
    u32 *p;
    s32 a;
    s32 b;
    s32 c;
    s32 i;
    u16 loc[7];
    if (h != 0) {
        *(s32 *)(h + 0x24) = vol;
        p = (u32 *)h;
        a = (vol * 1124 + 1124) / 1125;
        b = vol / 32000;
        c = ((vol << 8) / 125) & 0xFFFF;
        for (i = 0; i < *(s8 *)(h + 2); i++) {
            fn_8005A648();
            if (p[2] != 0) {
                if (*(s16 *)(h + 0xa0) == 1) {
                    if (vol == 32000 && *(s16 *)(h + 0xa2) == 0 && h != 0) {
                        *(s32 *)(h + 0xa4) = 0;
                        *(s16 *)(h + 0xa2) = 1;
                    }
                    loc[0] = ((u32)a) / 32000;
                    loc[1] = ((u32)(a << 8)) / 125;
                } else {
                    loc[0] = b;
                    loc[1] = c;
                }
                loc[2] = 0;
                loc[3] = 0;
                loc[4] = 0;
                loc[5] = 0;
                loc[6] = 0;
                fn_800230A4((void *)p[2], *(s32 *)(h + 0xa4));
                fn_80023438(p[2], loc);
            }
            fn_8005A628();
            p++;
        }
    }
}
