#include "types.h"

struct fn_800674FC_state {
    u8 pad_0[0x240];
    u32 unk_240[64];
    u8 pad_340[0x101];
    u8 unk_441;
    u8 pad_442;
    u8 unk_443;
    u8 pad_444[0x20];
    s8 unk_464;
    u8 pad_465[0x55AD];
    s16 unk_5A12;
    u8 pad_5A14[0xA0];
    s16 unk_5AB4[16];
    s16 unk_5AD4[16];
};
extern struct fn_800674FC_state *lbl_801A6C80;
extern u32 lbl_801A6C78;
extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL);

s32 fn_800674FC(u32 arg0, s32 arg1, s16 arg2) {
    s32 ret;
    u32 value;
    u16 channel;
    s32 i;
    channel = arg0;
    value = (arg0 & 0x1F) + arg1;
    if (arg1 & 0x00FF0000) {
        switch (arg1) {
        case (s32)0xA0010000:
        case (s32)0xA0040000:
        case (s32)0xA0090000:
        case (s32)0xA00A0000:
        case (s32)0xA0100000:
        case (s32)0xA0190000:
        case (s32)0xA01C0000:
            value += (arg2 & 0x7F) << 8;
            break;
        case (s32)0xA0050000:
        case (s32)0xA0070000:
        case (s32)0xA0110000:
            value += ((arg2 + 0x40) & 0x7F) << 8;
            break;
        case (s32)0xA0280000:
        case (s32)0xA0290000:
            value += ((arg2 - 1) & 0xF) << 8;
            break;
        case (s32)0xA0310000:
            lbl_801A6C80->unk_5A12 = arg2;
            break;
        case (s32)0xA0340000:
            if (channel & 0x10) {
                for (i = 0; i < 16; i++) {
                    lbl_801A6C80->unk_5AB4[i] = arg2;
                }
            } else {
                lbl_801A6C80->unk_5AB4[(u16)arg0] = arg2;
            }
            break;
        case (s32)0xA0400000:
            if (channel & 0x10) {
                for (i = 0; i < 16; i++) {
                    lbl_801A6C80->unk_5AD4[i] = arg2;
                }
            } else {
                lbl_801A6C80->unk_5AD4[(u16)arg0] = arg2;
            }
            break;
        case (s32)0xA0020000:
        case (s32)0xA0030000:
            break;
        default:
            return -2;
        }
    }
    ret = 0;
    if (lbl_801A6C80->unk_464 != 0) {
        ret = -3;
    } else {
        lbl_801A6C80->unk_464 = -1;
        if ((value & 0x80000000) == 0) {
            ret = -2;
        } else {
            lbl_801A6C78 = OSDisableInterrupts();
            if (lbl_801A6C80->unk_441 < 64 && lbl_801A6C80->unk_240[lbl_801A6C80->unk_443] == 0) {
                lbl_801A6C80->unk_240[lbl_801A6C80->unk_443] = value;
                lbl_801A6C80->unk_443 = (lbl_801A6C80->unk_443 + 1) & 0x3F;
                lbl_801A6C80->unk_441 = lbl_801A6C80->unk_441 + 1;
            } else {
                ret = -1;
            }
            OSRestoreInterrupts(lbl_801A6C78);
        }
        lbl_801A6C80->unk_464 = 0;
    }
    return ret;
}
