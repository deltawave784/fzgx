#include "types.h"
#pragma use_lmw_stmw on
#pragma opt_propagation off
typedef struct Sig_fn_80041BF8_fn_80041BF8_Obj Sig_fn_80041BF8_fn_80041BF8_Obj;
struct Sig_fn_80041BF8_fn_80041BF8_Obj { void **vtable; };
struct Sig_fn_80045414_fn_80045414_Arg0 { u8 pad_0[4]; u32 unk_4; };
struct Sig_fn_80041BF8_fn_80041BF8_Arg0;
struct Sig_fn_80044E7C_fn_80044E7C_Arg0 { u8 pad_0[0x98]; s16 unk_98; };
struct Sig_fn_8004550C_fn_8004550C_Arg0 { u8 pad_0[0x18]; u32 unk_18; };
struct Sig_fn_80045304_fn_80045304_Arg0 { u8 pad_0[0x94]; u32 unk_94; };
typedef struct { u8 pad[0x90]; u32 field; } Sig_fn_800452FC_Fn800452FCObject;
struct Sig_fn_800589BC_fn_800589BC_Arg2 { u32 unk_0; u32 unk_4; };
struct Sig_fn_800589BC_fn_800589BC_Arg3 { u32 unk_0; u32 unk_4; };
struct Sig_fn_80045588_fn_80045588_Arg0 { u8 pad_0[0xE]; u8 unk_E; };
struct Sig_fn_8004530C_fn_8004530C_Arg0 { u8 pad_0[4]; u32 unk_4; };
typedef u32 (*fn_80041990_Fn0)(u32,u32,void *);
typedef u32 (*fn_80041990_Fn1)(u32,u32,void *);
typedef u32 (*fn_80041990_Fn2)(u32,u32,u32,u32);
typedef u32 (*fn_80041990_Fn3)(u32,u32,void *);
typedef u32 (*fn_80041990_Fn4)(u32,u32,void *);
struct fn_80041990_Arg0 { u8 pad_0[1]; u8 unk_1; };
extern s32 fn_80045588(struct Sig_fn_80045588_fn_80045588_Arg0 *);
extern u32 fn_80041EF8(u32);
extern u32 fn_800452FC(Sig_fn_800452FC_Fn800452FCObject *);
extern u32 fn_80045304(struct Sig_fn_80045304_fn_80045304_Arg0 *);
extern u32 fn_8004530C(struct Sig_fn_8004530C_fn_8004530C_Arg0 *);
extern s32 fn_80045414(struct Sig_fn_80045414_fn_80045414_Arg0 *);
extern u32 fn_8004550C(struct Sig_fn_8004550C_fn_8004550C_Arg0 *);
extern u32 fn_800589BC(u32,u32,struct Sig_fn_800589BC_fn_800589BC_Arg2 *,struct Sig_fn_800589BC_fn_800589BC_Arg3 *);
extern void fn_80041BF8(struct Sig_fn_80041BF8_fn_80041BF8_Arg0 *);
extern void fn_80044E7C(struct Sig_fn_80044E7C_fn_80044E7C_Arg0 *);
void fn_80041990(struct fn_80041990_Arg0 *arg0) {
    struct { u32 value; } value1;
#define v1 value1.value
    struct { u32 value; } value5;
#define v5 value5.value
    u32 v2;
    u32 v4;
    u32 v3;
    u32 v16;
    s32 v11;
    u32 v10;
    u32 v9;
    u32 shift;
    u32 v6;
    u32 v12;
    s32 v15;
    u32 v17;
    u32 v18;
    u32 v19;
    struct Sig_fn_800589BC_fn_800589BC_Arg3 loc_10;
    struct Sig_fn_800589BC_fn_800589BC_Arg2 loc_8;
    if ((s8)arg0->unk_1 == 2) {
        v1 = *(u32 *)((u8 *)arg0 + 4);
        if (fn_80045414((struct Sig_fn_80045414_fn_80045414_Arg0 *)v1) == 0)
            fn_80041BF8((struct Sig_fn_80041BF8_fn_80041BF8_Arg0 *)arg0);
        fn_80044E7C((struct Sig_fn_80044E7C_fn_80044E7C_Arg0 *)v1);
        if (fn_80045414((struct Sig_fn_80045414_fn_80045414_Arg0 *)v1) == 3) {
            v2 = *(u32 *)((u8 *)arg0 + 4);
            v3 = *(u32 *)((u8 *)arg0 + 8);
            v4 = fn_8004550C((struct Sig_fn_8004550C_fn_8004550C_Arg0 *)v2);
            v5 = fn_80045304((struct Sig_fn_80045304_fn_80045304_Arg0 *)v2);
            v6 = fn_800452FC((Sig_fn_800452FC_Fn800452FCObject *)v2);
            v4 -= *(u32 *)((u8 *)arg0 + 52);
            if ((s32)v6 < (s32)v4) v4 = v6;
            fn_800589BC((u32)arg0 + 20, v5, &loc_8, &loc_10);
            ((fn_80041990_Fn0)((void **) *(u32 *)v3)[8])(v3, 0, &loc_8);
            ((fn_80041990_Fn1)((void **) *(u32 *)v3)[7])(v3, 1, &loc_10);
            v10 = (u32)arg0;
            v9 = (u32)arg0;
            shift = v4 << 1;
            for (v11 = 0; v11 < fn_80045588((struct Sig_fn_80045588_fn_80045588_Arg0 *)*(u32 *)((u8 *)arg0 + 4)); v11++) {
                fn_800589BC(v10 + 28, shift, &loc_8, &loc_10);
                v12 = *(u32 *)((u8 *)arg0 + 80);
                if (v12) ((fn_80041990_Fn2)v12)(*(u32 *)((u8 *)arg0 + 84), v11, loc_8.unk_0, loc_8.unk_4);
                v3 = *(u32 *)(v9 + 12);
                ((fn_80041990_Fn3)((void **) *(u32 *)v3)[8])(v3, 1, &loc_8);
                v3 = *(u32 *)(v9 + 12);
                ((fn_80041990_Fn4)((void **) *(u32 *)v3)[7])(v3, 0, &loc_10);
                v10 += 8;
                v9 += 4;
            }
            *(u32 *)((u8 *)arg0 + 44) += v4;
            *(u32 *)((u8 *)arg0 + 48) += v5;
            *(u32 *)((u8 *)arg0 + 52) += v4;
            *(u32 *)((u8 *)arg0 + 64) += v4;
            *(u32 *)((u8 *)arg0 + 68) += v5;
            fn_8004530C((struct Sig_fn_8004530C_fn_8004530C_Arg0 *)v2);
        }
        v15 = *(s16 *)(v1 + 152);
        if (v15 == 10) goto update; /* Shared update block matches retail branch chain. */
        if (v15 == 20) goto update; /* Shared update block matches retail branch chain. */
        if (v15 == 11) goto update; /* Shared update block matches retail branch chain. */
        if (v15 != 15) goto done; /* Skip update for all remaining stream states. */
        update: {
            v16 = *(u32 *)((u8 *)arg0 + 4);
            v17 = fn_8004550C((struct Sig_fn_8004550C_fn_8004550C_Arg0 *)v16);
            v18 = fn_80045304((struct Sig_fn_80045304_fn_80045304_Arg0 *)v16);
            v19 = fn_800452FC((Sig_fn_800452FC_Fn800452FCObject *)v16);
            v17 -= *(u32 *)((u8 *)arg0 + 52);
            if ((s32)v19 < (s32)v17) v17 = v19;
            *(u32 *)((u8 *)arg0 + 44) += v17;
            *(u32 *)((u8 *)arg0 + 48) += v18;
            *(u32 *)((u8 *)arg0 + 52) += v17;
        }
        done:;
    } else if ((s8)arg0->unk_1 == 1) {
        fn_80041EF8((u32)arg0);
    }
}
