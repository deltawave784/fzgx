#include "types.h"

typedef struct MovieObj {
    u8 pad_000[0xf24];
    s32 f24;
    u8 pad_f28[0xf4c - 0xf28];
    s32 f4c;
    u8 pad_f50[0xf58 - 0xf50];
    s32 f58;
    s32 f5c;
} MovieObj;

extern s32 fn_12_2D73C(MovieObj *, int);
extern u32 lbl_12_bss_7C64[137];
extern s32 fn_12_24A88(MovieObj *, s32);

#pragma opt_propagation off
s32 fn_12_2EAC4(MovieObj *self) {
    s32 n;
    s32 ok;
    s32 end;
    s32 diff;
    s32 start;
    s32 div;
    u32 *tbl;

    if (fn_12_2D73C(self, 6) == 0) {
        ok = 0;
    } else {
        n = fn_12_2D73C(self, 0x33);
        if (n == 0) {
            ok = 0;
        } else {
            tbl = (u32 *)&lbl_12_bss_7C64;
            if (fn_12_2D73C(self, 0x47) == 1) {
                diff = self->f24 - self->f4c;
                div = tbl[0x1b8 / 4];
            } else {
                end = self->f58;
                start = self->f4c;
                diff = end - start;
                div = self->f5c;
            }
            if (diff / div > n) {
                ok = 1;
            } else {
                ok = 0;
            }
        }
    }
    if (ok != 0) {
        fn_12_24A88(self, 0xff000222);
        return 1;
    }
    return 0;
}
