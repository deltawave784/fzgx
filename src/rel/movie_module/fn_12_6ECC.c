#include "types.h"

struct fn_12_6ECC_lbl_12_bss_4DB8 {
    u32 unk_0;
};
extern struct fn_12_6ECC_lbl_12_bss_4DB8 lbl_12_bss_4DB8;
extern u32 lbl_12_bss_4DB4;
extern u32 lbl_12_rodata_668;
extern void fn_12_33428(u32 *, u32, u32);
extern void fn_12_6708(void);
extern void fn_12_6A8C(void);

static inline void init_slots(u32 v1, s32 arg0) {
    s32 i;
    for (i = 0; i < arg0; i++) {
        *(u32 *)((u8 *)v1 + i * 192) = 1;
    }
}

static inline s32 init_pool(int arg0, void *arg1) {
    u32 v0;
    u32 v1;
    s32 i;
    lbl_12_bss_4DB4 = (u32)&lbl_12_rodata_668;
    lbl_12_bss_4DB8.unk_0 = (u32)arg1;
    fn_12_33428((u32 *)arg1, 0, (u32)((arg0 - 1) * 192 + 208) >> 2);
    v0 = lbl_12_bss_4DB8.unk_0;
    *(u32 *)((u8 *)v0 + 0) = 0;
    *(u32 *)((u8 *)v0 + 4) = 0;
    *(u32 *)((u8 *)v0 + 8) = 0;
    *(u32 *)((u8 *)lbl_12_bss_4DB8.unk_0 + 12) = arg0;
    v1 = lbl_12_bss_4DB8.unk_0 + 16;
    init_slots(v1, arg0);
    return 0;
}

s32 fn_12_6ECC(int arg0, void *arg1) {
    s32 result = init_pool(arg0, arg1);
    if (result != 0) {
        return result;
    }
    fn_12_6708();
    fn_12_6A8C();
    return 0;
}
