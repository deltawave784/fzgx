#include "types.h"

struct fn_12_316A8_Arg0 {
    u32 unk_0;
    u32 unk_4;
    u8 pad_8[0x4];
    u32 unk_C;
};
struct fn_12_316A8_Arg2 { u32 unk_0; };

static inline int fn_12_316A8_a(struct fn_12_316A8_Arg0 *a) {
    int r;
    switch ((s32)a->unk_0) {
    case -1:
    case 0:
    case 1: r = 0; break;
    default: r = 1; break;
    }
    return r;
}
static inline int fn_12_316A8_b(struct fn_12_316A8_Arg0 *a) {
    int ok;
    if (!fn_12_316A8_a(a)) return 0;
    ok = 0;
    if ((s32)a->unk_C == 107 || (s32)a->unk_C >= 110) ok = 1;
    if (!ok) return 0;
    return 1;
}
static inline u8 *fn_12_316A8_find(struct fn_12_316A8_Arg0 *a, u8 ch) {
    int i;
    u8 *e;
    u8 *found;
    u8 *base = (u8 *)a->unk_4;
    if (!fn_12_316A8_b(a)) return 0;
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
static inline u32 fn_12_316A8_cls(u32 c) {
    if (c >= 0xc0 && c <= 0xdf) return 0xc0;
    if (c >= 0xe0 && c <= 0xef) return 0xe0;
    if (c == 0xbd || c == 0xbf) return 0xbd;
    return 0;
}
s32 fn_12_316A8(struct fn_12_316A8_Arg0 *arg0, u8 arg1, struct fn_12_316A8_Arg2 *arg2, u32 arg3, u32 arg4, u32 arg5, u32 arg6) {
    u32 v0;
    u8 *found = fn_12_316A8_find(arg0, (u8)arg1);
    if (found == 0) return 0;
    if (fn_12_316A8_cls((u8)arg1) != 0xe0) return 0;
    switch ((u32)found[0x1f]) {
    case 1: v0 = 23976; break;
    case 2: v0 = 24000; break;
    case 3: v0 = 25000; break;
    case 4: v0 = 29970; break;
    case 5: v0 = 30000; break;
    case 6: v0 = 50000; break;
    case 7: v0 = 59940; break;
    case 8: v0 = 60000; break;
    default: v0 = 0; break;
    }
    arg2->unk_0 = v0;
    return 1;
}
