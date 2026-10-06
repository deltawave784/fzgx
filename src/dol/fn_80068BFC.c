#include "types.h"
#pragma use_lmw_stmw on
#include "dol/globals.h"
#include "dolphin/ar.h"

struct InitState {
    u8 pad_0[0x100];
    u32 unk_100;
    u32 unk_104;
    u8 pad_108[0x8c];
    u32 unk_194;
    u8 pad_198[8];
    u32 unk_1a0;
    u32 unk_1a4;
    u32 unk_1a8;
    u32 unk_1ac;
    u8 pad_1b0[0x8c];
    u32 unk_23c;
    u8 pad_240[0x214];
    u32 unk_454;
};
extern u8 lbl_80193B48[23336];
extern u8 lbl_80193B28[32];
extern const u32 lbl_801A7328;
extern u32 lbl_801A7348;
extern u32 lbl_801A6C78;
extern volatile s32 lbl_801A6C7C; /* Updated asynchronously by the ARQ callbacks while polling. */
extern u32 lbl_801A6410;
extern void fn_80067F68(u32,u32,u32,u32,u32,u32);
extern void fn_800631EC(void);
extern u32 fn_8001E954(u32);
extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL);
extern u32 fn_80008E34(u32,u32);
extern void fn_80065AD0(ARQRequest *);
extern void fn_80065AC4(ARQRequest *);
extern void fn_800211E0(u32,u32);
extern void fn_800211EC(u32,u32);
#define STATE ((struct InitState *)lbl_801A6C80)
s32 fn_80068BFC(u32 arg0,u32 arg1,u32 arg2,u32 arg3,u32 arg4,u32 arg5) {
    BOOL enabled;
    u32 *buffer;
    u32 i;
    arg5 = lbl_801A7328;
    lbl_801A6C78 = 0;
    lbl_801A6C7C = 0;
    lbl_801A6C80 = (u32)lbl_80193B48;
    fn_80067F68(arg0,arg1,arg2,arg3,arg4,arg5);
    fn_800631EC();
    if (arg1 == 0) return -1;
    if (arg2 == 0) return -2;
    STATE->unk_194 = arg1;
    STATE->unk_23c = arg2 - 0x21e0;
    STATE->unk_454 = arg0;
    if (arg0 != 0) {
        if (arg3 == 0) return -3;
        if (arg4 == 0) return -4;
        STATE->unk_1a0 = arg4;
        STATE->unk_1a4 = STATE->unk_1a0;
        STATE->unk_100 = arg3;
    } else {
        STATE->unk_1a0 = fn_8001E954(arg2);
        STATE->unk_1a4 = STATE->unk_1a0;
        enabled = OSDisableInterrupts();
        STATE->unk_100 = fn_80008E34(lbl_801A6410,arg1);
        OSRestoreInterrupts(enabled);
    }
    arg4 = OSDisableInterrupts();
    buffer = (u32 *)fn_80008E34(lbl_801A6410,0x100);
    OSRestoreInterrupts(arg4);
    for (i = 0; i < 64; i++) buffer[i] = 0;
    lbl_801A6C7C = 1;
    ARQPostRequest((ARQRequest *)lbl_80193B28,0,0,1,(u32)buffer,STATE->unk_1a4,0x100,fn_80065AD0);
    while (lbl_801A6C7C != 0) {}
    lbl_801A6C7C = 1;
    ARQPostRequest((ARQRequest *)lbl_80193B28,0,0,1,lbl_801A7348,STATE->unk_1a4 + 0x100,0x20e0,fn_80065AC4);
    while (lbl_801A6C7C != 0) {}
    STATE->unk_1ac = STATE->unk_1a4 + 0x21e0;
    STATE->unk_1a8 = STATE->unk_1a4 + 0x100;
    STATE->unk_104 = STATE->unk_100;
    fn_800211E0(0,0);
    fn_800211EC(0,0);
    return 0;
}
