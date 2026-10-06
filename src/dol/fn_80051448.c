#include "types.h"
struct Sig_fn_800501F4_fn_800501F4_Arg0 {
    u8 pad_0[0x8];
    s32 unk_8;
    s32 unk_C;
    s32 unk_10;
};
struct WordTriple { u32 a, b, c; };
struct fn_80051448_Arg0 {
    u8 pad_0[0x34C];
    u32 unk_34C;
};
extern s32 fn_800501F4(struct Sig_fn_800501F4_fn_800501F4_Arg0 *, s32);
extern s32 fn_800519B0(void *, u32, void *, void *);
extern u8 lbl_80187130[512];
extern void *memset(void *, int, u32);
#pragma opt_propagation off
void fn_80051448(struct fn_80051448_Arg0 *arg0) {
    u8 *v3;
    u8 *v2;
    u32 v0;
    u32 loaded;
    struct { u8 a[64]; } loc_C;
    u32 loc_8;
    loaded = arg0->unk_34C;
    v0 = loaded;
    if (loaded != 0) {
        memset(&loc_C, 0, 64);
        loc_8 = 0;
        v3 = lbl_80187130;
        v2 = lbl_80187130 + 4;
        while (v3 != v2) {
            *v3 = fn_800501F4((struct Sig_fn_800501F4_fn_800501F4_Arg0 *)v0, 8);
            v3++;
        }
        fn_800519B0(lbl_80187130, 4, &loc_8, 0);
        v2 += loc_8;
        while (v3 != v2) {
            *v3 = fn_800501F4((struct Sig_fn_800501F4_fn_800501F4_Arg0 *)v0, 8);
            v3++;
        }
        if (fn_800519B0(lbl_80187130, 512, &loc_8, &loc_C) >= 0) {
            *(u32 *)((u8 *)arg0 + 904) = (s8)loc_C.a[3];
            *(u32 *)((u8 *)arg0 + 908) = *(u32 *)(loc_C.a + 4);
            *(u32 *)((u8 *)arg0 + 912) = *(u32 *)(loc_C.a + 8);
            *(struct WordTriple *)((u8 *)arg0 + 928) = *(struct WordTriple *)(loc_C.a + 36);
            *(struct WordTriple *)((u8 *)arg0 + 940) = *(struct WordTriple *)(loc_C.a + 48);
            *(u32 *)((u8 *)arg0 + 900) = 1;
        }
    }
}
