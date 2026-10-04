#include "types.h"

extern s16 lbl_8019E014[];
#pragma optimize_for_size on

void fn_8006C634(s32 arg0, u32 arg1, s32 *arg2) {
    u32 idx;
    s32 val;
    s32 prod;
    s32 round;
    s32 scaled;

    idx = arg1 & 0xFF;
    if (idx < 0x40) {
        val = lbl_8019E014[idx];
    } else if (idx < 0x80) {
        val = lbl_8019E014[0x7F - idx];
    } else if (idx < 0xC0) {
        val = -lbl_8019E014[idx - 0x80];
    } else {
        val = -lbl_8019E014[0xFF - idx];
    }
    prod = arg0 * val;
    round = 0x20000 - 0x200;
    if (prod < 0) {
        round = -0x20000 + 0x200;
    }
    scaled = prod * 0x7F;
    scaled += round;
    {
        s32 div = 0x3FC00;
        *arg2 = -(scaled / div);
    }
}
