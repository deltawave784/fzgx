#include "types.h"
extern s32 lbl_801A6E10[2];
extern u32 lbl_80095E0C[];
extern u32 lbl_80095E34[];
extern u8 lbl_801A6378[32];
extern void MWTRACE(u32, ...);
extern s32 fn_8008F748(void);
extern u32 fn_8008F6BC(void *, u32);
extern u32 fn_8008E21C(u8 *, void *, u32);
extern u32 fn_8008E374(u8 *);
extern u32 fn_8008E114(u8 *, u32, u32);

#pragma use_lmw_stmw on
#pragma opt_propagation off
u32 gdev_cc_read(u32 arg0, u32 arg1) {
    u8 loc_8[0x500];
    u32 v1;
    u32 v2;
    s32 len;
    v2 = 0;
    if (lbl_801A6E10[0] == 0) {
        return -10001;
    }
    MWTRACE(1, (u32)&lbl_80095E0C, arg1, arg1);
    v1 = arg1;
    len = arg1;
    while (fn_8008E374(lbl_801A6378) < len) {
        v2 = 0;
        arg1 = fn_8008F748();
        if (arg1 != 0) {
            v2 = fn_8008F6BC(loc_8, len);
            if (v2 == 0) {
                fn_8008E21C(lbl_801A6378, loc_8, arg1);
            }
        }
    }
    if (v2 == 0) {
        fn_8008E114(lbl_801A6378, arg0, v1);
    } else {
        MWTRACE(8, (u32)&lbl_80095E34, v2);
    }
    return v2;
}
