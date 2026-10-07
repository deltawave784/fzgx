#include "types.h"

struct fn_12_6B8_Arg0 {
    u32 unk_0;
    u8 *unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u8 *unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    u8 *unk_24;
    u32 unk_28;
    u32 unk_2C;
};

void fn_12_6B8(struct fn_12_6B8_Arg0 *arg0, u32 arg1) {
    u32 remain;
    u32 v1;
    s32 v2;
    v1 = ((s32)arg1 / 2) * 2;
    v2 = (s32)v1 / 2;
    {
        remain = arg0->unk_C;
        arg0->unk_4 += v1 * arg0->unk_8;
        arg0->unk_C = remain - v1;
    }
    {
        u32 remain = arg0->unk_1C;
        arg0->unk_14 += v2 * arg0->unk_18;
        arg0->unk_1C = remain - v2;
    }
    {
        u32 remain = arg0->unk_2C;
        arg0->unk_24 += v2 * arg0->unk_28;
        arg0->unk_2C = remain - v2;
    }
}
