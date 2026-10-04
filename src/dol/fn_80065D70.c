#include "types.h"

struct fn_80065D70_Entry {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u8 unk_C;
    u8 unk_D;
    u8 unk_E;
    u8 unk_F;
};

struct fn_80065D70_State {
    struct fn_80065D70_Entry entries[0x10];
    u8 pad_100[0x4];
    u32 unk_104[0x10];
    u8 pad_144[0x40];
    u8 unk_184[0x10];
    u8 pad_194[0x18];
    u32 unk_1AC[0x10];
    u8 pad_1EC[0x40];
    u8 unk_22C[0x10];
    u8 pad_23C[0x224];
    u8 unk_460;
};

extern struct fn_80065D70_State *lbl_801A6C80;
extern void fn_8006060C(u32);
extern void fn_80064D4C(u8, u32);

s32 fn_80065D70(u32 idx) {
    s32 result = 0;
    s32 i;

    if (idx >= 0x10) {
        result = -1;
    } else if (lbl_801A6C80->entries[idx].unk_0 != 0xFFFFFFFF) {
        fn_8006060C(idx);
        fn_80064D4C(idx, 0);
        fn_80064D4C(idx, 1);
        lbl_801A6C80->unk_460 -= lbl_801A6C80->entries[idx].unk_C;
        lbl_801A6C80->entries[idx].unk_0 = 0xFFFFFFFF;
        lbl_801A6C80->entries[idx].unk_E = 0xFF;
        lbl_801A6C80->entries[idx].unk_D = 0xFF;
        lbl_801A6C80->entries[idx].unk_C = 0;
        for (i = 0; i < 16; i += 2) {
            if (lbl_801A6C80->unk_104[i] == lbl_801A6C80->entries[idx].unk_8) {
                lbl_801A6C80->unk_184[i] = 0;
                lbl_801A6C80->entries[idx].unk_8 = 0;
            }
            if (lbl_801A6C80->unk_1AC[i] == lbl_801A6C80->entries[idx].unk_4) {
                lbl_801A6C80->unk_22C[i] = 0;
                lbl_801A6C80->entries[idx].unk_4 = 0;
            }
            if (lbl_801A6C80->unk_104[i + 1] == lbl_801A6C80->entries[idx].unk_8) {
                lbl_801A6C80->unk_184[i + 1] = 0;
                lbl_801A6C80->entries[idx].unk_8 = 0;
            }
            if (lbl_801A6C80->unk_1AC[i + 1] == lbl_801A6C80->entries[idx].unk_4) {
                lbl_801A6C80->unk_22C[i + 1] = 0;
                lbl_801A6C80->entries[idx].unk_4 = 0;
            }
        }
    } else {
        result = -2;
    }
    return result;
}
