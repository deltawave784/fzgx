#include "types.h"

struct fn_12_313A8_Arg0 {
    u32 unk_0;
    u32 unk_4;
    u8 pad_8[0x4];
    u32 unk_C;
    u8 pad_10[0x10];
    u8 unk_20;
    u8 pad_21[1];
    u8 unk_22;
};
struct fn_12_313A8_Arg2 {
    u32 unk_0;
};

static inline int fn_12_313A8_a(struct fn_12_313A8_Arg0 *a) {
    int r;
    switch ((s32)a->unk_0) {
    case -1:
    case 0:
    case 1:
        r = 0;
        break;
    default:
        r = 1;
        break;
    }
    return r;
}
static inline int fn_12_313A8_b(struct fn_12_313A8_Arg0 *a) {
    int ok;
    if (!fn_12_313A8_a(a)) return 0;
    ok = 0;
    if ((s32)a->unk_C == 107 || (s32)a->unk_C >= 110) ok = 1;
    if (!ok) return 0;
    return 1;
}
static inline u8 *fn_12_313A8_find(struct fn_12_313A8_Arg0 *a, u8 ch) {
    int i;
    u8 *e;
    u8 *found;
    u8 *base = (u8 *)a->unk_4;
    if (!fn_12_313A8_b(a)) return 0;
    found = 0;
    for (i = 0; i < 26; i++) {
        e = base + i * 0x40 + 0x180;
        if (e[0x18] == ch) {
            found = e;
            break;
        }
    }
    return found;
}
static inline u32 fn_12_313A8_cls(u32 c) {
    if (c >= 0xc0 && c <= 0xdf) return 0xc0;
    if (c >= 0xe0 && c <= 0xef) return 0xe0;
    if (c == 0xbd || c == 0xbf) return 0xbd;
    return 0;
}
static inline int fn_12_313A8_d(struct fn_12_313A8_Arg0 *a, u32 c) {
    u32 v;
    if (fn_12_313A8_cls(c) != 0xe0) return 0;
    v = a->unk_20;
    if (v > 1) return 0;
    if (v == 0) return 0;
    return 1;
}
s32 fn_12_313A8(struct fn_12_313A8_Arg0 *arg0, u8 arg1, struct fn_12_313A8_Arg2 *arg2) {
    u8 *found = fn_12_313A8_find(arg0, (u8)arg1);
    if (found == 0) return 0;
    if (!fn_12_313A8_d((struct fn_12_313A8_Arg0 *)found, (u8)arg1)) return 0;
    arg2->unk_0 = ((struct fn_12_313A8_Arg0 *)found)->unk_22;
    return 1;
}
