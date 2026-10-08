#include "types.h"

typedef u32 (*fn_80078360_Fn0)(void *);
struct fn_80078360_Arg0 { u32 unk_0; };
struct fn_80078360_Arg2 { u8 pad_0[0x8]; u32 unk_8; };

extern u32 fn_80075908(u32, u32);
extern u32 fn_80078344(u32, u32);
extern u32 fn_80078884(u32, u32, u32, u32);
extern u32 fn_80078944(u32, u32, u32, u32);
extern u32 lbl_801A6D90;
extern u32 lbl_801A6D94;
extern u32 lbl_801A6D98;
extern void fn_80033E7C(void);
extern void fn_8003458C(void);
extern void fn_800723B8(u32, u32);
extern u32 fn_800723D8(void);
extern void fn_8007245C(u32);
extern void fn_80078D60(s32);

u32 fn_80078360(struct fn_80078360_Arg0 *arg0, u32 arg1, struct fn_80078360_Arg2 *arg2, u32 arg3, u32 arg4) {
    u32 v4;
    s32 v3;
    s32 v6;
    u32 v2;
    struct { u32 value; } v0;
    u32 v7;
    u32 v1;
    u8 result;
    struct { u32 a[12]; } loc_8;
    #pragma opt_propagation off
    v0.value = arg0->unk_0 & 2;
    v1 = arg2->unk_8;
    v2 = (u32)arg2 + v1;
    v7 = lbl_801A6D98 ^ 2;
    if (v0.value) v7 = 0;
    v6 = v7;
    fn_8007245C(*(u32 *)((u8 *)arg0 + 28));
    if (lbl_801A6D90 != 0) {
        loc_8.a[1] = (u32)arg0;
        loc_8.a[2] = arg1;
        result = ((fn_80078360_Fn0)lbl_801A6D90)(&loc_8);
    } else {
        if ((s32)lbl_801A6D94 == 0) fn_80075908((u32)arg0, arg1);
        result = 1;
    }
    if (result) {
        fn_8003458C();
        v3 = 0;
        v4 = (u32)arg0;
        do {
            if ((*(u8 *)((u8 *)arg0 + 19) & (1 << v3)) != 0) {
                fn_80078D60(v6);
                if ((*(u32 *)((u8 *)arg4 + 4) & 0x40) != 0) {
                    fn_80078344(*(u32 *)((u8 *)v4 + 72), *(u32 *)((u8 *)v4 + 80));
                } else {
                    if ((*(u32 *)((u8 *)arg4 + 4) & 0x20) != 0) {
                        *(u32 *)((u8 *)v4 + 72) = (*(u32 *)((u8 *)arg4 + 48) + 31) & ~0x1F;
                        fn_800723B8(*(u32 *)((u8 *)v4 + 72), 0x80000);
                        fn_80033E7C();
                    }
                    if ((*(u32 *)((u8 *)arg2 + 28) & 1) != 0) {
                        fn_80078944(*(u32 *)((u8 *)arg0 + 28), v2, arg3, *(u32 *)((u8 *)v4 + 40));
                        arg3 += *(u32 *)((u8 *)v4 + 40) << 1;
                    } else {
                        fn_80078884(*(u32 *)((u8 *)arg0 + 28), v2, arg3, *(u32 *)((u8 *)v4 + 40));
                        arg3 += *(u32 *)((u8 *)v4 + 40) << 2;
                    }
                    if ((*(u32 *)((u8 *)arg4 + 4) & 0x20) != 0) {
                        *(u32 *)((u8 *)v4 + 80) = fn_800723D8();
                        fn_80078344(*(u32 *)((u8 *)v4 + 72), *(u32 *)((u8 *)v4 + 80));
                        *(u32 *)((u8 *)arg4 + 48) = *(u32 *)((u8 *)v4 + 72) + *(u32 *)((u8 *)v4 + 80);
                        v7 = *(u32 *)((u8 *)arg4 + 52) + *(u32 *)((u8 *)v4 + 80);
                        *(u32 *)((u8 *)arg4 + 52) = v7;
                    }
                }
            }
            if (v6 != 0) v6 = lbl_801A6D98 ^ 1;
            v3++;
            v4 += 4;
        } while (v3 < 2);
    }
    return arg3;
}
