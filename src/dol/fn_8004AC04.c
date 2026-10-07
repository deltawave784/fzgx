#include "types.h"

struct fn_8004AC04_Arg0 {
    u8 pad_0[0x10];
    s32 unk_10;
    u8 pad_14[0x18];
    s32 unk_2c;
};

void fn_8004AC04(struct fn_8004AC04_Arg0 *arg0, s32 arg1) {
    if (arg1 >= 0) {
        arg0->unk_2c = arg1;
    } else {
        s32 value = arg0->unk_10;
        s32 remainder = value % 2048;
        arg1 = value / 2048;
        remainder = remainder > 0;
        arg0->unk_2c = arg1 + remainder;
    }
}
