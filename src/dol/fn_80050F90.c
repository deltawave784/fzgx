#include "types.h"

struct fn_80050F90_Obj {
    u8 *unk_0;
    u8 pad_4[0x344];
    s32 unk_348;
    void *unk_34c;
    void *unk_350;
    u8 pad_354[0x30];
    u8 unk_384[4];
    s32 unk_388;
    u8 pad_38c[0x2c];
    u8 unk_3b8[0x200];
    u8 unk_5b8[4];
};

extern int fn_80053A30(void);
extern u32 lbl_80187118[6];
extern void fn_80050698(void *a, void *b, void *c, void *d, s32 e, void *f);
extern void fn_80053DB4(void *a, void *b, s32 c, void *d);

s32 fn_80050F90(struct fn_80050F90_Obj *obj, u8 *dst0, u8 *dst1) {
    s32 mode;
    s32 i;

    mode = obj->unk_388;
    if (obj->unk_348 == 12) {
        return 0;
    }
    lbl_80187118[0] = fn_80053A30();
    fn_80050698(obj->unk_34c, obj->unk_384, obj->unk_3b8, obj->unk_5b8, obj->unk_348 >> 2, obj->unk_0);
    lbl_80187118[3] = fn_80053A30();
    for (i = 0; i < 3; i++) {
        fn_80053DB4(obj->unk_350, obj->unk_0 + i * 0x80, 0, dst0 + i * 0x40);
    }
    lbl_80187118[4] = fn_80053A30();
    if (mode >= 2) {
        for (i = 0; i < 3; i++) {
            fn_80053DB4(obj->unk_350, obj->unk_0 + 0x180 + i * 0x80, 1, dst1 + i * 0x40);
        }
    }
    lbl_80187118[5] = fn_80053A30();
    obj->unk_348++;
    return 0x60;
}
