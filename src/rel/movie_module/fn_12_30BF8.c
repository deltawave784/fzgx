#include "types.h"

struct fn_12_30BF8_Arg0 {
    u32 unk_0;
    u32 unk_4;
    u8 pad_8[0x4];
    u32 unk_C;
};
struct fn_12_30BF8_Arg2 {
    u32 unk_0;
};

static inline s32 kind_valid(s32 kind) {
    s32 flag = 0;
    if (kind == 107 || kind >= 110) flag = 1;
    return flag;
}
static inline s32 state_valid(struct fn_12_30BF8_Arg0 *arg0) {
    s32 v;
    switch ((s32)arg0->unk_0) {
    case -1: case 0: case 1: v = 0; break;
    default: v = 1; break;
    }
    if (!v) return 0;
    if (!kind_valid((s32)arg0->unk_C)) return 0;
    return 1;
}
static inline u32 classify(u8 key) {
    u32 value = key;
    if (value >= 192 && value <= 223) return 192;
    if (value >= 224 && value <= 239) return 224;
    if (value == 189 || value == 191) return 189;
    return 0;
}
static inline s32 entry_valid(u8 *entry, u8 key) {
    if (classify(key) != 224) return 0;
    if (entry[0x20] > 1) return 0;
    if (entry[0x20] == 0) return 0;
    return 1;
}
static inline u8 *find_entry(struct fn_12_30BF8_Arg0 *arg0, u8 key) {
    s32 i;
    u8 *e;
    u8 *found;
    u8 *base;
    base = (u8 *)arg0->unk_4;
    if (!state_valid(arg0)) return 0;
    found = 0;
    for (i = 0; i < 26; i++) {
        e = base + 0x180 + i * 0x40;
        if (e[0x18] == (u8)key) {
            found = e;
            break;
        }
    }
    return found;
}
s32 fn_12_30BF8(struct fn_12_30BF8_Arg0 *arg0, u8 arg1, struct fn_12_30BF8_Arg2 *arg2, u32 arg3, u32 arg4, u32 arg5, u32 arg6) {
    u8 *v1 = find_entry(arg0, arg1);
    if (v1 == 0) return 0;
    if (!entry_valid(v1, arg1)) return 0;
    arg2->unk_0 = v1[0x26];
    if ((s32)arg2->unk_0 > 63) arg2->unk_0 = -1;
    return 1;
}
