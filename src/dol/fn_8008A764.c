#include "types.h"

extern char lbl_80095A6C[];
extern char lbl_80095A74[];
extern void MWTRACE(u32, ...);

void fn_8008A764(u8 *arg0, s32 arg1) {
    s32 i;
    for (i = 0; i < arg1; i++) {
        MWTRACE(8, lbl_80095A6C, arg0[i]);
        if (i % 16 == 15) {
            MWTRACE(8, lbl_80095A74);
        }
    }
    MWTRACE(8, lbl_80095A74);
}
