#include "types.h"
struct fn_80065B08_lbl_801A6C80_T {
    u8 pad_0[0x104];
    u32 unk_104;
    u8 pad_108[0x78];
    u32 unk_180;
    u8 pad_184[0x10];
    u32 unk_194;
    u32 unk_198;
    u32 unk_19C;
    u8 pad_1A0[0xC];
    u32 unk_1AC;
    u8 pad_1B0[0x78];
    u32 unk_228;
    u8 pad_22C[0x10];
    u32 unk_23C;
    u8 pad_240[0x21F];
    u8 unk_45F;
};
extern struct fn_80065B08_lbl_801A6C80_T *lbl_801A6C80;
s32 fn_80065B08(u32 arg0) {
    u32 v0;
    s32 v4;
    u32 v8;
    s32 v1;
    u32 v2;
    s32 v3;
    u32 v5;
    u32 v7;
    u32 v6;
    u32 v17;
    s32 v22;
    u32 v26;
    u32 v18;
    u32 v23;
    u32 v25;
    u32 v24;
    s32 result = 0;
    v1 = 0;
    v2 = arg0;
    for (v4 = 1; v4 < 16; v4++) {
    v5 = *(u32 *)v2;
    v6 = (u32)lbl_801A6C80 + v4 * 4;
    v7 = *(u32 *)((u8 *)v6 + 256);
    v1 += v5;
    *(u32 *)((u8 *)v6 + 320) = v5;
    v8 = v7 + v5;
    if (v8 <= lbl_801A6C80->unk_104 + lbl_801A6C80->unk_194) {
        ((u32 *)lbl_801A6C80)[v4 + 65] = v8;
    } else {
        result = -1;
        goto first_done; /* exit on overflow */
    }
    v2 += 4;
    }
first_done:
    if (result == 0) {
    v17 = *(u32 *)((u8 *)v2 + 0);
    v1 += v17;
    lbl_801A6C80->unk_180 = v17;
    lbl_801A6C80->unk_198 = (lbl_801A6C80->unk_104 + v1);
    lbl_801A6C80->unk_19C = (lbl_801A6C80->unk_194 - v1);
    v2 = v2 + 4;
    for (v22 = 1; v22 < 16; v22++) {
    v23 = *(u32 *)v2;
    v24 = (u32)lbl_801A6C80 + v22 * 4;
    v25 = *(u32 *)((u8 *)v24 + 424);
    *(u32 *)((u8 *)v24 + 488) = v23;
    v26 = v25 + v23;
    if (v26 <= lbl_801A6C80->unk_1AC + lbl_801A6C80->unk_23C) {
        ((u32 *)lbl_801A6C80)[v22 + 107] = v26;
    } else {
        result = -1;
        goto second_done; /* exit on overflow */
    }
    v2 += 4;
    }
second_done:
    if (result == 0) {
    lbl_801A6C80->unk_228 = *(u32 *)((u8 *)v2 + 0);
    }
    }
    if (result == 0) {
    lbl_801A6C80->unk_45F = 1;
    }
    return result;
}
