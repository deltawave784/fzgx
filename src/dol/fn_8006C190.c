#include "types.h"
#pragma optimize_for_size on
struct Sig_fn_8006C6E8_fn_8006C6E8_Arg0 {
    u8 pad_0[0x24]; u32 unk_24; u8 pad_28[0x10]; u32 unk_38; u32 unk_3C;
};
struct Sig_fn_8006C6E8_fn_8006C6E8_Arg1 {
    u8 pad_0[2]; u8 unk_2; u8 unk_3; s16 unk_4; s16 unk_6;
};
struct fn_8006C190_Arg0 {
    u8 unk_0; u8 pad_1[3]; u32 unk_4; u32 unk_8;
    s16 unk_C; u16 unk_E; u16 unk_10; u16 unk_12; s16 unk_14; u8 pad_16[0x12];
    u32 unk_28; u32 unk_2C; u32 unk_30; s32 unk_34; u32 unk_38;
};
extern s32 fn_8006C6E8(struct Sig_fn_8006C6E8_fn_8006C6E8_Arg0 *, struct Sig_fn_8006C6E8_fn_8006C6E8_Arg1 *);
extern s32 fn_8006C570(struct fn_8006C190_Arg0 *, void *, s32);
extern s32 fn_8006C788(struct fn_8006C190_Arg0 *, void *);
extern s16 lbl_8019E014[];
extern s16 lbl_8019E094[];
extern void fn_8006C634(s32, u32, s32 *);
s32 fn_8006C190(struct fn_8006C190_Arg0 *arg0, u32 arg1) {
    s32 v3;
    u32 v2;
    s32 v4;
    s32 v5;
    s32 v6;
    s16 v9;
    u32 v10;
    s32 v8;
    if (arg0->unk_28 & 1) {
        if (arg0->unk_30 != 0) {
            arg0->unk_30 -= arg1;
            if ((s32)arg0->unk_30 < 0) arg0->unk_30 = 0;
        } else {
            arg0->unk_2C += arg1;
            if (arg0->unk_4 != -1 && arg0->unk_4 < arg0->unk_2C) {
                if (arg0->unk_28 & 2) arg0->unk_28 &= ~1;
            }
        }
    }
    arg0->unk_28 |= 2;
    v3 = 0;
    v2 = arg0->unk_28;
    if ((v2 & 1) && arg0->unk_30 == 0) v3 = 1;
    if (v3 != 0) {
        if (v2 & 0x10) {
            v4 = fn_8006C570(arg0, &arg0->unk_10, arg0->unk_C);
            fn_8006C634(v4, (u16)arg0->unk_E, &arg0->unk_34);
        } else if (v2 & 0x20) {
            s32 delta;
            s32 elapsed;
            s32 duration;
            s32 start;
            s32 rounding;
            s32 end;
            start = arg0->unk_C;
            end = *(s16 *)&arg0->unk_E;
            duration = arg0->unk_4;
            delta = end - start;
            elapsed = arg0->unk_2C;
            rounding = duration / 2;
            if (delta < 0) rounding = -rounding;
            delta *= elapsed;
            delta += rounding;
            fn_8006C634(start + delta / duration, arg0->unk_10, &arg0->unk_34);
        } else if (v2 & 0x40) {
            u32 phase;
            u32 increment;
            u32 period;
            period = arg0->unk_10;
            increment = arg1 << 24;
            phase = arg0->unk_38;
            increment /= period;
            arg0->unk_38 = phase + increment;
            if (arg0->unk_38 >= 0x1000000) arg0->unk_38 -= arg0->unk_38 & ~0xFFFFFF;
            v9 = fn_8006C570(arg0, (u8 *)arg0 + 0x18, *(u8 *)&arg0->unk_C);
            switch (arg0->unk_0) {
            case 2:
                v10 = (arg0->unk_38 >> 16) & 0xFF;
                if (v10 < 0x40) v4 = lbl_8019E014[v10];
                else if (v10 < 0x80) v4 = lbl_8019E014[0x7F - v10];
                else if (v10 < 0xC0) v4 = -lbl_8019E014[v10 - 0x80];
                else v4 = -lbl_8019E014[0xFF - v10];
                v8 = v4;
                break;
            case 3:
                v8 = -1024;
                if ((arg0->unk_38 >> 16) < 128) v8 = 1024;
                break;
            case 4:
                v10 = (arg0->unk_38 >> 16) & 0xFF;
                if (v10 < 0x40) v4 = lbl_8019E094[v10];
                else if (v10 < 0x80) v4 = lbl_8019E094[0x7F - v10];
                else if (v10 < 0xC0) v4 = -lbl_8019E094[v10 - 0x80];
                else v4 = -lbl_8019E094[0xFF - v10];
                v8 = v4;
                break;
            case 5:
                v8 = lbl_8019E094[(arg0->unk_38 >> 18) & 0x3F];
                break;
            case 6:
                v8 = lbl_8019E094[(255 - ((arg0->unk_38 >> 16) & 255)) >> 2];
                break;
            default: v8 = 0;
            }
            {
                s32 rounding;
                s32 product;
                rounding = 512;
                if (v8 < 0) rounding = -512;
                product = v8 * v9;
                product += rounding;
                fn_8006C634(product / 1024 + arg0->unk_14, arg0->unk_E, &arg0->unk_34);
            }
        } else if (v2 & 0x80) {
            void *params = &arg0->unk_C;
            switch (arg0->unk_0) {
            case 7:
                arg0->unk_34 = fn_8006C6E8((struct Sig_fn_8006C6E8_fn_8006C6E8_Arg0 *)arg0, (struct Sig_fn_8006C6E8_fn_8006C6E8_Arg1 *)params);
                break;
            case 8:
                arg0->unk_34 = fn_8006C788(arg0, &arg0->unk_C);
                if (arg0->unk_34 == 0) arg0->unk_34 = arg0->unk_34 + 1;
                break;
            default: arg0->unk_34 = 0;
            }
        } else return 0;
    } else arg0->unk_34 = 0;
    return 1;
}
