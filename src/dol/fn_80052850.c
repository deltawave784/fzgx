#include "types.h"

#pragma section sconst_type ".rodata" ".rodata" data_mode=far_abs

struct fn_80052850_Arg0 {
    f32 unk_0;
    u8 pad_4[0x17C];
    f32 unk_180;
    u8 pad_184[0x7C];
    f32 unk_200;
    u8 pad_204[0x17C];
    f32 unk_380;
};
struct fn_80052850_Arg1 {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2C;
    f32 unk_30;
    f32 unk_34;
    f32 unk_38;
    f32 unk_3C;
};
struct fn_80052850_Arg2 {
    u16 unk_0;
};
extern f32 lbl_80091338[6];

void fn_80052850(struct fn_80052850_Arg0 *arg0, struct fn_80052850_Arg1 *arg1, struct fn_80052850_Arg2 *arg2) {
    s32 n;
    f32 sum;
    s32 value;
    n = 32;
    do {
        sum = 0.0f;
        sum += arg1->unk_0 * arg0->unk_0;
        sum += arg1->unk_4 * arg0->unk_180;
        sum += arg1->unk_8 * arg0->unk_200;
        sum += arg1->unk_C * arg0->unk_380;
        sum += arg1->unk_10 * ((f32 *)arg0)[-768];
        sum += arg1->unk_14 * ((f32 *)arg0)[-672];
        sum += arg1->unk_18 * ((f32 *)arg0)[-640];
        sum += arg1->unk_1C * ((f32 *)arg0)[-544];
        sum += arg1->unk_20 * ((f32 *)arg0)[-512];
        sum += arg1->unk_24 * ((f32 *)arg0)[-416];
        sum += arg1->unk_28 * ((f32 *)arg0)[-384];
        sum += arg1->unk_2C * ((f32 *)arg0)[-288];
        sum += arg1->unk_30 * ((f32 *)arg0)[-256];
        sum += arg1->unk_34 * ((f32 *)arg0)[-160];
        sum += arg1->unk_38 * ((f32 *)arg0)[-128];
        sum += arg1->unk_3C * ((f32 *)arg0)[-32];
        arg1++;
        arg0 = (struct fn_80052850_Arg0 *)((f32 *)arg0 + 1);
        if (sum > 2147483648.0f) {
            sum = 2147483648.0f;
        } else if (sum < -2147483648.0f) {
            sum = -2147483648.0f;
        }
        value = (s32)sum >> 16;
        arg2->unk_0 = (s16)(f32)value;
        arg2++;
    } while (--n != 0);
}
