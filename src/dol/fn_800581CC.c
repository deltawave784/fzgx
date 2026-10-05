#include "types.h"

typedef void (*fn_800581CC_Fn0)(s32, s32);

struct fn_800581CC_Arg0 {
    u8 pad_0[0xc];
    s32 unk_C;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    u8 *unk_1C;
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    u8 pad_2C[0x4];
    s32 unk_30;
    u8 pad_34[0x4];
    fn_800581CC_Fn0 unk_38;
    s32 unk_3C;
};

struct fn_800581CC_Arg3 {
    u8 *unk_0;
    s32 unk_4;
};

extern u32 fn_800576DC(void);
extern u32 fn_80057728(void);

void fn_800581CC(struct fn_800581CC_Arg0 *arg0, s32 arg1, s32 arg2, struct fn_800581CC_Arg3 *arg3) {
    s32 n;

    fn_80057728();
    if (arg1 == 0) {
        n = arg0->unk_24 + (arg0->unk_20 - arg0->unk_14);
        arg3->unk_4 = (arg0->unk_10 < n) ? arg0->unk_10 : n;
        arg3->unk_4 = (arg3->unk_4 < arg2) ? arg3->unk_4 : arg2;
        arg3->unk_0 = arg0->unk_1C + arg0->unk_14;
        arg0->unk_14 = (arg0->unk_14 + arg3->unk_4) % arg0->unk_20;
        arg0->unk_10 -= arg3->unk_4;
        arg0->unk_28 += arg3->unk_4;
    } else if (arg1 == 1) {
        n = arg0->unk_24 + (arg0->unk_20 - arg0->unk_18);
        arg3->unk_4 = (arg0->unk_C < n) ? arg0->unk_C : n;
        arg3->unk_4 = (arg3->unk_4 < arg2) ? arg3->unk_4 : arg2;
        arg3->unk_0 = arg0->unk_1C + arg0->unk_18;
        arg0->unk_18 = (arg0->unk_18 + arg3->unk_4) % arg0->unk_20;
        arg0->unk_C -= arg3->unk_4;
        arg0->unk_30 += arg3->unk_4;
    } else {
        arg3->unk_4 = 0;
        arg3->unk_0 = NULL;
        if (arg0->unk_38 != NULL) {
            arg0->unk_38(arg0->unk_3C, -3);
        }
    }
    fn_800576DC();
}
