#include "types.h"

struct fn_8004AE94_Arg0 {
    u8 pad_0[0x10];
    s32 unk_10;
    u8 pad_14[0x40];
    volatile s32 unk_54; /* Stream limit is reloaded after writes, as required by retail. */
};

s32 fn_8004AE94(struct fn_8004AE94_Arg0 *arg0, s32 arg1) {
    arg0->unk_54 = arg1;
    if ((arg0->unk_54 << 11) > arg0->unk_10) {
        arg0->unk_54 = arg0->unk_10 / 2048 + (arg0->unk_10 % 2048 > 0);
    }
    return arg0->unk_54;
}
