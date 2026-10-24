#include "types.h"

struct fn_12_323B0_Arg0 {
    u32 unk_0;
    void *unk_4;
    u8 pad_8[0x4];
    u32 unk_C;
};
struct fn_12_323B0_Arg1 {
    u32 unk_0;
};

static inline u32 fn_12_323B0_array_read(u32 v1) {
    u32 unk_3 = (v1 << 8) & 0xff0000;
    unk_3 = __rlwimi(unk_3, v1, 24, 0, 7);
    unk_3 = __rlwimi(unk_3, v1, 24, 16, 23);
    return __rlwimi(unk_3, v1, 8, 24, 31);
}

#pragma peephole off
#pragma opt_lifetimes off
s32 fn_12_323B0(struct fn_12_323B0_Arg0 *arg0, struct fn_12_323B0_Arg1 *arg1) {
    u32 v1;
    int unk_1;
    u8 *movie = (u8 *)arg0->unk_4;
    int kind;
    int unk_2;
    u32 unk_3;

    switch ((s32)arg0->unk_0) {
    case -1: case 0: case 1:
        unk_2 = 0;
        break;
    default:
        unk_2 = 1;
        break;
    }
    if (unk_2 == 0) {
        unk_2 = 0;
    } else {
        kind = (s32)arg0->unk_C;
        unk_1 = 0;
        if (kind == 0x6b || kind >= 0x6e) {
            unk_1 = 1;
        }
        if (!(unk_1 != 0)) {
            unk_2 = 0;
        } else {
            unk_2 = 1;
        }
    }
    if (unk_2 == 0) {
        return 0;
    }
    if ((s32)arg0->unk_C < 0x6e) {
        return 0;
    }
    kind = *(u32 *)(movie + 0xb4);
    unk_3 = ((u32)kind << 8) & 0xff0000;
    unk_3 = __rlwimi(unk_3, kind, 24, 0, 7);
    unk_3 = __rlwimi(unk_3, kind, 24, 16, 23);
    unk_3 = __rlwimi(unk_3, kind, 8, 24, 31);
    arg1->unk_0 = unk_3;
    return 1;
}
#pragma peephole reset
