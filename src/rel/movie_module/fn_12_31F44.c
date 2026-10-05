#include "types.h"

struct fn_12_31F44_Arg0 {
    s32 unk_0;
    u8 *unk_4;
    u8 pad_8[0x4];
    s32 unk_C;
    u8 pad_10[0x9];
    u8 unk_19;
    u8 unk_1A;
};

static inline int fn_12_31F44_a(struct fn_12_31F44_Arg0 *a) {
    int r;
    switch (a->unk_0) {
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

static inline int fn_12_31F44_b(struct fn_12_31F44_Arg0 *a) {
    int ok;
    if (!fn_12_31F44_a(a)) {
        return 0;
    }
    ok = 0;
    if (a->unk_C == 107 || a->unk_C >= 110) {
        ok = 1;
    }
    if (!ok) {
        return 0;
    }
    return 1;
}

/* retail is this loop unrolled by two (26 trips, stride 0x40). */
static inline u8 *fn_12_31F44_find(struct fn_12_31F44_Arg0 *a, u8 ch) {
    int i;
    u8 *e;
    u8 *found;
    u8 *base = a->unk_4;
    if (!fn_12_31F44_b(a)) {
        return 0;
    }
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

static inline u32 fn_12_31F44_cls(u32 c) {
    if (c >= 0xc0 && c <= 0xdf) {
        return 0xc0;
    }
    if (c >= 0xe0 && c <= 0xef) {
        return 0xe0;
    }
    if (c == 0xbd || c == 0xbf) {
        return 0xbd;
    }
    return 0;
}

static inline int fn_12_31F44_d(struct fn_12_31F44_Arg0 *a, u32 c) {
    if (fn_12_31F44_cls(c) != 0xc0) {
        return 0;
    }
    if (a->unk_19 != 1) {
        return 0;
    }
    return 1;
}

int fn_12_31F44(struct fn_12_31F44_Arg0 *arg0, u8 arg1, u32 *arg2) {
    u8 *found = fn_12_31F44_find(arg0, (u8)arg1);
    if (found == 0) {
        return 0;
    }
    if (fn_12_31F44_cls((u8)arg1) != 0xc0) {
        return 0;
    }
    if (((struct fn_12_31F44_Arg0 *)found)->unk_19 != 1) {
        return 0;
    }
    *arg2 = ((struct fn_12_31F44_Arg0 *)found)->unk_1A;
    return 1;
}
