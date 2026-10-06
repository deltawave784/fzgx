#include "types.h"
#pragma peephole off
#pragma stack_alignment 8
struct Sig_fn_80025440_fn_80025440_Arg0 {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1c;
    u32 unk_20;
    u8 unk_24;
    u8 pad_25[3];
    u32 unk_28;
    u32 unk_2c;
    u32 unk_30;
    u32 unk_34;
    u32 unk_38;
    u32 unk_3c;
    u32 unk_40;
    u32 unk_44;
    u32 unk_48;
    u32 unk_4c;
    u32 unk_50;
    u32 unk_54;
    u32 unk_58;
    u32 unk_5c;
    u32 unk_60;
    u32 unk_64;
    u32 unk_68;
    u8 pad_6c[0x1c];
    u32 unk_88;
    u32 unk_8c;
    u32 unk_90;
    u32 unk_94;
    u32 unk_98;
};
typedef u32 (*fn_800251F0_Fn0)(u32);
extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL);
extern u32 fn_80025440(struct Sig_fn_80025440_fn_80025440_Arg0 *);
extern u32 (*lbl_801A64F8)(u32);
s32 fn_800251F0(struct Sig_fn_80025440_fn_80025440_Arg0 *arg0) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v4;
    u32 *p1;
    u32 *v5;
    u32 *v6;
    BOOL t0;
    u32 t1;
    u32 t3;
    t0 = OSDisableInterrupts();
    t1 = lbl_801A64F8(5760);
    arg0->unk_00 = t1;
    v0 = arg0->unk_00;
    v1 = v0;
    if (v0 != 0) {
    arg0->unk_0c = (v1 + 1920);
    v1 = arg0->unk_0c;
    arg0->unk_18 = (v1 + 1920);
    v1 = arg0->unk_00;
    arg0->unk_04 = (v1 + 640);
    v1 = arg0->unk_0c;
    arg0->unk_10 = (v1 + 640);
    v1 = arg0->unk_18;
    arg0->unk_1c = (v1 + 640);
    v1 = arg0->unk_00;
    arg0->unk_08 = (v1 + 1280);
    v1 = arg0->unk_0c;
    arg0->unk_14 = (v1 + 1280);
    v1 = arg0->unk_18;
    arg0->unk_20 = (v1 + 1280);
    p1 = (u32 *)*(u32 *)((u8 *)arg0 + 0);
    v5 = (u32 *)*(u32 *)((u8 *)arg0 + 12);
    v6 = (u32 *)*(u32 *)((u8 *)arg0 + 24);
    for (v4 = 0; v4 < 320; v4++) {
        *p1++ = 0;
        *v5++ = 0;
        *v6++ = 0;
    }
    arg0->unk_24 = 1;
    v1 = t0;
    arg0->unk_34 = 0;
    arg0->unk_30 = 0;
    arg0->unk_2c = 0;
    arg0->unk_28 = 0;
    arg0->unk_44 = 0;
    arg0->unk_40 = 0;
    arg0->unk_3c = 0;
    arg0->unk_38 = 0;
    arg0->unk_54 = 0;
    arg0->unk_50 = 0;
    arg0->unk_4c = 0;
    arg0->unk_48 = 0;
    arg0->unk_88 = 480;
    arg0->unk_8c = 0;
    OSRestoreInterrupts(v1);
    v1 = (u32)arg0;
    t3 = fn_80025440((struct Sig_fn_80025440_fn_80025440_Arg0 *)v1);
    v1 = t3;
    } else {
    v1 = t0;
    OSRestoreInterrupts(v1);
    v1 = 0;
    }
    return v1;
}
