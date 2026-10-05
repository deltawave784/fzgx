#include "types.h"

typedef void (*fn_80058070_Fn0)(s32, s32);

struct fn_80058070_Arg0 {
    u8 pad_0[0xc];
    s32 unk_C;
    s32 unk_10;
    u8 pad_14[0x8];
    u8 *unk_1C;
    s32 unk_20;
    s32 unk_24;
    u8 pad_28[0x4];
    s32 unk_2C;
    u8 pad_30[0x4];
    s32 unk_34;
    fn_80058070_Fn0 unk_38;
    s32 unk_3C;
};

struct fn_80058070_Arg2 {
    u8 *unk_0;
    s32 unk_4;
};

extern u32 fn_800576DC(void);
extern u32 fn_80057728(void);
extern void *memcpy(void *, const void *, u32);

void fn_80058070(struct fn_80058070_Arg0 *arg0, s32 arg1, struct fn_80058070_Arg2 *arg2) {
    s32 off;
    s32 n;
    u32 start;
    u8 *base;

    if (arg2->unk_4 <= 0 || arg2->unk_0 == NULL) {
        return;
    }
    {
        fn_80057728();
        if (arg1 == 1) {
            arg0->unk_C += arg2->unk_4;
            off = arg2->unk_0 - arg0->unk_1C;
            if (off < arg0->unk_24) {
                n = arg0->unk_24 - off;
                if (arg2->unk_4 < n) {
                    n = arg2->unk_4;
                }
                /* pointer canonicalisation keeps the int terms in source order */
                memcpy((u8 *)arg0->unk_20 + off + (u32)arg0->unk_1C, arg2->unk_0, n);
            }
            base = arg0->unk_1C;
            off = arg2->unk_4 + (arg2->unk_0 - base);
            if (off > arg0->unk_20) {
                n = off - arg0->unk_20;
                if (arg2->unk_4 < n) {
                    n = arg2->unk_4;
                }
                memcpy(base, base + (off - n), n);
            }
            arg0->unk_34 += arg2->unk_4;
        } else if (arg1 == 0) {
            arg0->unk_10 += arg2->unk_4;
            arg0->unk_2C += arg2->unk_4;
        } else {
            arg2->unk_4 = 0;
            arg2->unk_0 = NULL;
            if (arg0->unk_38 != NULL) {
                arg0->unk_38(arg0->unk_3C, -3);
            }
        }
        fn_800576DC();
    }
}
