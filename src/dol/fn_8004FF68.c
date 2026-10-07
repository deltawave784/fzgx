#include "types.h"
struct Sig_fn_800502A0_Buffer { u8 *ptr; s32 size; };
struct Sig_fn_800502A0_fn_800502A0_Arg0 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    s32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    struct Sig_fn_800502A0_Buffer unk_1C;
    s32 unk_24;
    u8 *unk_28;
};
typedef u32 (*fn_8004FF68_Fn0)(u32, u32);
struct fn_8004FF68_Arg0 {
    u32 unk_0;
    u32 unk_4;
    s32 unk_8;
    s32 unk_C;
    u32 unk_10;
    u8 pad_14[0x10];
    s32 unk_24;
};
extern u32 lbl_801309C0[];
extern u32 lbl_80186FA8[4];
extern void fn_800502A0();
#pragma use_lmw_stmw on
#pragma opt_propagation off
static inline u32 read_bits(struct fn_8004FF68_Arg0 *arg0, s32 count) {
    u32 *counter_p;
    u32 counter;
    u32 result;
    s32 shift;
    u32 *tbl;
    counter_p = lbl_80186FA8;
    counter = *counter_p;
    *counter_p = counter + 1;
    if (arg0->unk_C < count) fn_800502A0((struct Sig_fn_800502A0_fn_800502A0_Arg0 *)arg0);
    shift = arg0->unk_C;
    if (shift < count) {
        arg0->unk_10 += shift;
        arg0->unk_C = 0;
        return 0;
    }
    tbl = lbl_801309C0;
    shift -= count;
    result = arg0->unk_8 >> shift;
    result &= tbl[count];
    arg0->unk_C = shift;
    arg0->unk_10 += count;
    return result;
}
#pragma opt_propagation on
s32 fn_8004FF68(struct fn_8004FF68_Arg0 *arg0) {
    struct { u32 *value; } counter_base;
    struct { u32 *value; } table_base;
#define p_lbl_80186FA8 counter_base.value
#define p_lbl_801309C0 table_base.value
    u32 v8;
    s32 v1;
    u32 v0;
    u32 v2;
    s32 v3;
    s32 v4;
    u32 v5;
    s32 v6;
    u32 v7;
    s32 v9;
    u32 v10;
    u32 v11;
    u32 v12;
    u32 t3;
    { u32 *tbl; tbl = lbl_801309C0; v0 = tbl[12]; }
    if ((arg0->unk_10 & 7) != 0) {
        v1 = 8 - (arg0->unk_10 & 7);
        { u32 *counter_p; counter_p = lbl_80186FA8; v2 = *counter_p; *counter_p = v2 + 1; }
        if (arg0->unk_C < v1) fn_800502A0((struct Sig_fn_800502A0_fn_800502A0_Arg0 *)arg0, v2);
        v3 = arg0->unk_C;
        if (v1 > v3) {
            arg0->unk_10 += v3;
            arg0->unk_C = 0;
        } else {
            arg0->unk_C = v3 - v1;
            arg0->unk_10 += v1;
        }
    }
    v5 = read_bits(arg0, 12);
    p_lbl_801309C0 = lbl_801309C0;
    p_lbl_80186FA8 = lbl_80186FA8;
    v8 = v5;
    /* Enter at the EOF test before scanning the first code. */
    goto test;
    while (1) {
        if ((v8 & v0) == 4095) return 1;
        if (v8 + 0x7FFF0000 == 12) return 2;
        v8 <<= 4;
        v8 |= read_bits(arg0, 4);
    test:
        v9 = arg0->unk_4;
        v12 = *(u32 *)v9;
        t3 = ((fn_8004FF68_Fn0)*(u32 *)((u8 *)v12 + 36))(v9, 1);
        if ((s32)t3 == 0 && arg0->unk_C == 0 && arg0->unk_24 == 0) v9 = 1;
        else v9 = 0;
        if ((s32)v9) return 0;
    }
}
#pragma opt_propagation reset
