#include "types.h"

extern u32 fn_800744F8(void *value, u32 mask);
extern void fn_80008204(u32 *value);

extern u32 lbl_801A6408;
extern u32 lbl_801A6728;

void fn_80007AB4(u32 *arg) {
    u32 loc_8[2];

    u8 first;
    u8 global_first;
#pragma opt_propagation off
    first = ((u8 *)arg)[0];
    global_first = ((u8 *)&lbl_801A6408)[0];
    if (global_first != first ||
        ((u8 *)&lbl_801A6408)[1] != ((u8 *)arg)[1] ||
        ((u8 *)&lbl_801A6408)[2] != ((u8 *)arg)[2] ||
        ((u8 *)&lbl_801A6408)[3] != ((u8 *)arg)[3]) {
        loc_8[1] = *arg;
        ((u8 *)&lbl_801A6408)[0] = ((u8 *)&loc_8[1])[0];
        ((u8 *)&lbl_801A6408)[1] = ((u8 *)&loc_8[1])[1];
        ((u8 *)&lbl_801A6408)[2] = ((u8 *)&loc_8[1])[2];
        ((u8 *)&lbl_801A6408)[3] = ((u8 *)&loc_8[1])[3];
        loc_8[0] = lbl_801A6408;
        fn_800744F8(loc_8, 0x00ffffff);
        fn_80008204(&lbl_801A6408);
    }
    lbl_801A6728 = 1;
}
