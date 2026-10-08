#include "types.h"

struct fn_12_32DBC_Arg0 {
    u32 unk_0;
    u32 unk_4;
    u8 pad_8[0x4];
    u32 unk_C;
};
struct fn_12_32DBC_Arg2 {
    u32 unk_0;
};

static inline s32 state_valid(s32 state) {
    s32 result = 0;
    switch (state) {
    case -1:
    case 0:
    case 1:
        return 0;
        break;
    default:
        result = 1;
        break;
    }
    return result;
}

static inline u32 find_entry(u32 base, u32 key) {
    s32 i;
    u32 e;
    u32 found;
    found = 0;
    for (i = 0; i < 26; i++) {
        e = (u32)((u8 *)base + 384 + i * 64);
        if (*(u8 *)(e + 24) == (u8)key) {
            found = e;
            break;
        }
    }
    return found;
}

s32 fn_12_32DBC(struct fn_12_32DBC_Arg0 *arg0, u8 arg1, struct fn_12_32DBC_Arg2 *arg2) {
    s32 v5;
    u32 v6;
    u32 v7;
    u32 v1;
    u32 v0;
    s32 v2;
    u32 v3;
    u32 v4;
    s32 valid;
    arg2->unk_0 = 0;
    v0 = arg0->unk_0;
    v1 = arg0->unk_4;
    v2 = state_valid((s32)v0);
    if (v2 == 0) {
        valid = 0;
    } else {
        s32 flag;
        s32 kind;
        kind = (s32)arg0->unk_C;
        flag = 0;
        if (kind == 107 || kind >= 110) flag = 1;
        if (flag == 0) valid = 0;
        else valid = 1;
    }
    if (valid == 0) return 0;
    v7 = find_entry(v1, arg1);
    if (v7 != 0) arg2->unk_0 = 1;
    else arg2->unk_0 = 0;
    return 1;
}
