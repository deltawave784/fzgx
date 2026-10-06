#include "types.h"

#pragma section sconst_type ".rodata" ".rodata" data_mode=far_abs

struct fn_80053610_Arg0 {
    f32 unk_0; u8 pad_4[0x17C];
    f32 unk_180; u8 pad_184[0x7C];
    f32 unk_200; u8 pad_204[0x17C];
    f32 unk_380; u8 pad_384[0x7C];
    f32 unk_400; u8 pad_404[0x17C];
    f32 unk_580; u8 pad_584[0x7C];
    f32 unk_600; u8 pad_604[0x17C];
    f32 unk_780; u8 pad_784[0x7C];
    f32 unk_800; u8 pad_804[0x17C];
    f32 unk_980; u8 pad_984[0x7C];
    f32 unk_A00; u8 pad_A04[0x17C];
    f32 unk_B80; u8 pad_B84[0x7C];
    f32 unk_C00; u8 pad_C04[0x17C];
    f32 unk_D80;
};
struct fn_80053610_Arg1 {
    f32 unk_0, unk_4, unk_8, unk_C, unk_10, unk_14, unk_18, unk_1C;
    f32 unk_20, unk_24, unk_28, unk_2C, unk_30, unk_34, unk_38, unk_3C;
};
struct fn_80053610_Arg2 { u16 unk_0; };

void fn_80053610(struct fn_80053610_Arg0 *arg0, struct fn_80053610_Arg1 *arg1, struct fn_80053610_Arg2 *arg2) {
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
        sum += arg1->unk_10 * arg0->unk_400;
        sum += arg1->unk_14 * arg0->unk_580;
        sum += arg1->unk_18 * arg0->unk_600;
        sum += arg1->unk_1C * arg0->unk_780;
        sum += arg1->unk_20 * arg0->unk_800;
        sum += arg1->unk_24 * arg0->unk_980;
        sum += arg1->unk_28 * arg0->unk_A00;
        sum += arg1->unk_2C * arg0->unk_B80;
        sum += arg1->unk_30 * arg0->unk_C00;
        sum += arg1->unk_34 * arg0->unk_D80;
        sum += arg1->unk_38 * *(f32 *)((u8 *)arg0 - 512);
        sum += arg1->unk_3C * *(f32 *)((u8 *)arg0 - 128);
        arg1++;
        arg0 = (struct fn_80053610_Arg0 *)((u8 *)arg0 + 4);
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
