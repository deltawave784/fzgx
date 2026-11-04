#include "types.h"
typedef struct Sig_fn_12_C2C8_MovieObject Sig_fn_12_C2C8_MovieObject;
typedef struct Sig_fn_12_CA84_MovieObject {
    u8 pad_0000[0x1338];
    u32 field_1338, field_133c, field_1340;
} Sig_fn_12_CA84_MovieObject;
typedef struct Sig_fn_12_C2C8_MovieVTable {
    u8 pad_0000[0x0c];
    void (*method_000c)(Sig_fn_12_C2C8_MovieObject *);
    u8 pad_0010[0x14];
    s32 (*method_0024)(Sig_fn_12_C2C8_MovieObject *, s32);
} Sig_fn_12_C2C8_MovieVTable;
struct Sig_fn_12_C2C8_MovieObject { Sig_fn_12_C2C8_MovieVTable *vtable; };
typedef void (*Sig_fn_12_24A88_MovieCallback)(void *, s32);
typedef struct Sig_fn_12_24A88_MovieObject {
    u8 pad_0000[0x48];
    s32 state;
    u8 pad_004c[0x940];
    Sig_fn_12_24A88_MovieCallback callback;
    void *callback_context;
    s32 callback_data;
} Sig_fn_12_24A88_MovieObject;
typedef struct Sig_fn_12_21E20_MovieEntry {
    char unk00[0x2c]; int value; char unk30[0x44];
} Sig_fn_12_21E20_MovieEntry;
typedef struct Sig_fn_12_21E20_MovieModule {
    char unk0000[0x1148]; Sig_fn_12_21E20_MovieEntry entries[1];
} Sig_fn_12_21E20_MovieModule;
typedef struct Sig_fn_12_CA60_MovieObject {
    u8 pad_0000[0x1338]; u32 field_1338, field_133c, field_1340;
} Sig_fn_12_CA60_MovieObject;
struct Sig_fn_12_2CDD0_fn_12_2CDD0_Arg3 { u32 unk_0; };
typedef struct Sig_fn_12_AB00_MovieObject {
    u8 pad_0[0x278]; u32 value_278;
} Sig_fn_12_AB00_MovieObject;
typedef struct Sig_fn_12_21F38_MovieEntry {
    int value; u8 pad[0x70];
} Sig_fn_12_21F38_MovieEntry;
typedef struct Sig_fn_12_21F38_MovieModule {
    u8 pad[0x115c]; Sig_fn_12_21F38_MovieEntry entries[1];
} Sig_fn_12_21F38_MovieModule;
struct fn_12_284F8_Arg0 { u8 pad_0[0x1B30]; u32 unk_1B30; };
struct fn_12_284F8_Copy12 { u32 a[3]; };
struct fn_12_284F8_Copy28 { u32 a[7]; };
struct fn_12_284F8_Copy32 { u32 a[8]; };
struct fn_12_284F8_Copy40 { u32 a[10]; };

extern int fn_12_21F38(Sig_fn_12_21F38_MovieModule *, int);
extern int fn_12_AA38(void *, void *, void *, void *);
extern s32 fn_12_24A88(Sig_fn_12_24A88_MovieObject *, s32);
extern s32 fn_12_2CDD0(void *, s32, u32, struct Sig_fn_12_2CDD0_fn_12_2CDD0_Arg3 *);
extern s32 fn_12_AB00(Sig_fn_12_AB00_MovieObject *, u32 *);
extern s32 fn_12_AB60(u32, u32);
extern s32 fn_12_C2C8(void *, Sig_fn_12_C2C8_MovieObject *);
extern s32 fn_8008023C(u32, u32, u32);
extern u32 fn_12_27C58(u32, u32, u32, u32);
extern u32 fn_12_28304(u32, u32, u32, u32);
extern u32 fn_12_2D73C(u8 *, int);
extern u32 fn_80057D88(u32, u32, u32);
extern const s32 lbl_12_rodata_E10[9];
extern u8 *fn_12_A0D8(u8 *, s32, u32);
extern unsigned int UTY_MulDiv(int, int, int);
extern void *fn_12_57F0(void *, const void *, u32);
extern void fn_12_21E20(Sig_fn_12_21E20_MovieModule *, int, int);
extern void fn_12_2D7DC(u8 *, int, int);
extern void fn_12_2E374(u32, u32, u32);
extern void fn_12_CA60(Sig_fn_12_CA60_MovieObject *, u32 *, u32 *);
extern void fn_12_CA84(Sig_fn_12_CA84_MovieObject *, u32, u32);

#pragma opt_common_subs off
static inline s32 fn_12_284F8_ready(struct fn_12_284F8_Arg0 *arg0, u32 v2) {
    struct fn_12_284F8_Copy28 loc_40;
    u32 loc_8, loc_C, loc_10;
    s32 t19;
    s32 span, pos, start;
    if (*(s32 *)((u8 *)arg0 + 3332) == 0) return 0;
    loc_40.a[0] = *(u32 *)((u8 *)v2 + 16);
    loc_40.a[1] = *(u32 *)((u8 *)v2 + 28);
    loc_40.a[2] = *(u32 *)((u8 *)v2 + 32);
    loc_40.a[3] = *(u32 *)((u8 *)v2 + 36);
    loc_40.a[4] = *(u32 *)((u8 *)v2 + 40);
    loc_40.a[5] = *(u32 *)((u8 *)v2 + 44);
    loc_40.a[6] = *(u32 *)((u8 *)v2 + 20);
    fn_12_2E374((u32)&loc_40, (u32)&loc_8, (u32)&loc_10);
    fn_12_2E374((u32)arg0 + 3336, (u32)&loc_C, (u32)&loc_10);
    t19 = fn_12_2D73C((u8 *)arg0, 53);
    pos = loc_8;
    start = loc_C;
    span = loc_10 * t19;
    if (pos <= start) return 1;
    if (pos >= start + span) return 1;
    return 0;
}

u32 fn_12_284F8(struct fn_12_284F8_Arg0 *arg0, u8 *arg1, u32 arg2, u32 arg3) {
    u32 v23, v24;
    u32 v6, v7, picture_changed;
    u32 v27;
    s32 v12, v11;
    u32 v30;
    s32 v9;
    u32 v0;
    s32 v3, v4;
    u32 v5, v8;
    s32 v13, v14;
    u32 v28, v29;
    s32 v31;
    u32 v1, v2;
    struct fn_12_284F8_Copy28 loc_78;
    struct fn_12_284F8_Copy28 loc_5C;
    struct fn_12_284F8_Copy28 loc_40;
    u32 loc_34[3];
    u32 loc_30, loc_2C, loc_28, loc_24, loc_20, loc_1C, loc_18, loc_14, loc_10, loc_C, loc_8;
    u32 t1;
    s32 t2;
    u32 t3;
    s32 t9;
    u8 *t11;
    s32 t14;
    unsigned int t15;
    s32 t24;
    s32 t25;
    u32 t27;
    int t28;
    u32 t30;
    u32 timer;

    v0 = arg0->unk_1B30;
    v1 = *(u32 *)((u8 *)v0 + 0);
    v2 = v0 + 140;
    fn_12_CA84((Sig_fn_12_CA84_MovieObject *)v1, *(u32 *)((u8 *)v0 + 2244), *(u32 *)((u8 *)v0 + 2240));
    t1 = fn_80057D88(arg2, 0, 1);
    t2 = fn_12_C2C8((void *)v1, (Sig_fn_12_C2C8_MovieObject *)arg2);
    t3 = fn_80057D88(arg2, 0, 1);
    v3 = t3 - t1;
    v4 = t2;
    switch (v4) {
    case 0: v4 = 0; break;
    case -2:
        if (v3 > 0) v4 = 0;
        else v4 = fn_12_24A88((Sig_fn_12_24A88_MovieObject *)arg0, -2);
        break;
    case -3:
        if (v3 > 0) v4 = 0;
        else v4 = fn_12_24A88((Sig_fn_12_24A88_MovieObject *)arg0, -3);
        break;
    default:
        v4 = fn_12_24A88((Sig_fn_12_24A88_MovieObject *)arg0, 0xFF000F04);
        break;
    }
    fn_12_21E20((Sig_fn_12_21E20_MovieModule *)arg0, *(u32 *)((u8 *)arg0 + 6968), v3);
    if (v4 != 0) return v4;
    fn_12_CA60((Sig_fn_12_CA60_MovieObject *)v1, (u32 *)0, (u32 *)(v0 + 2248));
    t9 = fn_12_AB60(v1, v2);
    if (t9 != 0) return fn_12_24A88((Sig_fn_12_24A88_MovieObject *)arg0, 0xFF000F05);
    if (*(s32 *)((u8 *)v0 + 220) != (s32)(v5 = *(u32 *)((u8 *)v2 + 48))) {
        *(u32 *)((u8 *)v0 + 220) = v5;
        *(u32 *)((u8 *)v0 + 224) = 1;
    } else {
        *(u32 *)((u8 *)v0 + 224) = 0;
    }
    v6 = *(u32 *)((u8 *)v0 + 224);
    v7 = *(u32 *)((u8 *)arg0 + 6960);
    v8 = *(u32 *)((u8 *)arg0 + 6968);
    v9 = -1;
    t11 = fn_12_A0D8((u8 *)*(u32 *)arg1, *(u32 *)((u8 *)arg1 + 4), 4);
    if (t11 != 0) {
        fn_12_2CDD0((void *)arg0, v8, (u32)t11, (struct Sig_fn_12_2CDD0_fn_12_2CDD0_Arg3 *)loc_34);
        if ((s32)loc_34[0] >= 0) {
            v11 = *(u32 *)((u8 *)v2 + 20);
            v12 = lbl_12_rodata_E10[*(u32 *)((u8 *)v2 + 16)];
            if ((s32)*(u32 *)((u8 *)arg0 + 3540) < 0) {
                v5 = loc_34[0] - UTY_MulDiv(v11, 22500000, v12);
                *(u32 *)((u8 *)arg0 + 3540) = (s32)v5 > 0 ? v5 : 0;
            }
            v13 = loc_34[0] - *(u32 *)((u8 *)arg0 + 3540);
            v9 = v13 > 0 ? v13 : 0;
            t14 = fn_8008023C(v7 + 244, (u32)loc_34, 4);
            if (t14 != 0) {
                *(struct fn_12_284F8_Copy12 *)(v7 + 244) = *(struct fn_12_284F8_Copy12 *)loc_34;
                *(u32 *)((u8 *)v7 + 236) = 0;
                *(u32 *)((u8 *)v7 + 232) = v11;
                if ((s32)*(u32 *)((u8 *)v2 + 24) == 3) {
                    *(u32 *)((u8 *)v7 + 240) = 1;
                } else {
                    *(u32 *)((u8 *)v7 + 240) = 0;
                }
            } else {
                if ((s32)v6 != 0) {
                    *(u32 *)((u8 *)v7 + 236) = *(u32 *)((u8 *)v7 + 236) + (*(u32 *)((u8 *)v7 + 240) + 1);
                    *(u32 *)((u8 *)v7 + 240) = 0;
                    *(u32 *)((u8 *)v7 + 232) = 0;
                }
                v5 = *(u32 *)((u8 *)v7 + 240);
                v14 = v11 - *(u32 *)((u8 *)v7 + 232);
                *(u32 *)((u8 *)v7 + 240) = (s32)v5 > v14 ? v5 : v14;
                t15 = UTY_MulDiv(*(u32 *)((u8 *)v7 + 236) + v14, 22500000, v12);
                v9 += t15;
                v9 = v9 > 0 ? v9 : 0;
            }
        }
    }
    {
    if ((s32)arg3 == 0) return 0;
    picture_changed = *(u32 *)((u8 *)v0 + 224);
    arg3 = fn_12_2D73C((u8 *)arg0, 52);
    if (arg3 == 0 && (v9 >= 0 || ((s32)picture_changed != 0 && fn_12_284F8_ready(arg0, v2)))) {
        fn_12_2D7DC((u8 *)arg0, 52, 1);
        arg3 = 1;
    }
    if ((s32)arg3 == 1) fn_12_28304((u32)arg0, v2, v9, picture_changed);
    }
    if ((s32)*(u32 *)((u8 *)arg0 + 3292) == 0) {
        loc_78.a[0] = *(u32 *)((u8 *)v2 + 16);
        loc_78.a[1] = *(u32 *)((u8 *)v2 + 28);
        loc_78.a[2] = *(u32 *)((u8 *)v2 + 32);
        loc_78.a[3] = *(u32 *)((u8 *)v2 + 36);
        loc_78.a[4] = *(u32 *)((u8 *)v2 + 40);
        loc_78.a[5] = *(u32 *)((u8 *)v2 + 44);
        loc_78.a[6] = *(u32 *)((u8 *)v2 + 20);
        loc_78.a[6] = 0;
        fn_12_2E374((u32)&loc_78, (u32)&loc_2C, (u32)&loc_30);
        *(struct fn_12_284F8_Copy28 *)((u8 *)arg0 + 3296) = loc_78;
        *(u32 *)((u8 *)arg0 + 3324) = loc_2C;
        *(u32 *)((u8 *)arg0 + 3328) = loc_30;
        *(u32 *)((u8 *)arg0 + 3292) = 1;
    }
    timer = (u32)arg0 + 0xCC0;
    v23 = timer + 0x44;
    v24 = timer + 0x94;
    loc_5C.a[0] = *(u32 *)((u8 *)v2 + 16);
    loc_5C.a[1] = *(u32 *)((u8 *)v2 + 28);
    loc_5C.a[2] = *(u32 *)((u8 *)v2 + 32);
    loc_5C.a[3] = *(u32 *)((u8 *)v2 + 36);
    loc_5C.a[4] = *(u32 *)((u8 *)v2 + 40);
    loc_5C.a[5] = *(u32 *)((u8 *)v2 + 44);
    loc_5C.a[6] = *(u32 *)((u8 *)v2 + 20);
    fn_12_2E374((u32)&loc_5C, (u32)&loc_24, (u32)&loc_28);
    *(struct fn_12_284F8_Copy28 *)(v24 + 4) = loc_5C;
    *(u32 *)(v24 + 32) = loc_24 - *(u32 *)((u8 *)arg0 + 3324);
    *(u32 *)(v24 + 36) = loc_28;
    *(u32 *)(v24 + 0) = 1;
    if ((s32)*(u32 *)(v23 + 32) <= (s32)*(u32 *)(v24 + 32)) {
        *(struct fn_12_284F8_Copy40 *)v23 = *(struct fn_12_284F8_Copy40 *)v24;
    }
    v27 = (u32)arg0 + 2316;
    v28 = *(u32 *)((u8 *)arg0 + 6960);
    if ((s32)*(u32 *)((u8 *)v27 + 16) != 0) return 0;
    t24 = fn_12_AB00((Sig_fn_12_AB00_MovieObject *)v1, &loc_14);
    if (t24 != 0) return fn_12_24A88((Sig_fn_12_24A88_MovieObject *)arg0, 0xFF000F16);
    fn_12_AA38((void *)v1, &loc_18, &loc_1C, &loc_20);
    t27 = fn_12_2D73C((u8 *)arg0, 60);
    if ((s32)t27 == 0) {
        *(u32 *)((u8 *)v28 + 228) = 0;
    } else {
        t28 = fn_12_21F38((Sig_fn_12_21F38_MovieModule *)arg0, 1);
        if ((s32)loc_20 == -1) loc_20 = loc_18;
        if ((s32)loc_20 < t28) t28 = loc_20;
        *(u32 *)((u8 *)v28 + 228) = t28;
    }
    v29 = *(u32 *)((u8 *)arg0 + 10504);
    v28 = loc_14;
    v5 = *(u32 *)((u8 *)arg0 + 6960);
    if (v29 == 0) v30 = 0;
    else if ((s32)*(u32 *)((u8 *)v5 + 136) > 0) v30 = 0;
    else v30 = v29 + 2756;
    if (v30 != 0 && (s32)*(u32 *)((u8 *)v30 + 0) == 0) {
        t25 = *(u32 *)((u8 *)arg1 + 4);
        v5 = v30 + 52;
        *(u32 *)((u8 *)v5 + 512) = t25 < 512 ? t25 : 512;
        fn_12_57F0((void *)v5, (const void *)*(u32 *)arg1, *(u32 *)((u8 *)v5 + 512));
        if (v28 - 0x30000 == 65535) {
            *(u32 *)((u8 *)v30 + 4) = 0;
            *(u32 *)((u8 *)v30 + 8) = 0;
        } else {
            *(u32 *)((u8 *)v30 + 4) = v28 * 50;
            *(u32 *)((u8 *)v30 + 8) = 1;
        }
        *(struct fn_12_284F8_Copy40 *)(v30 + 12) = *(struct fn_12_284F8_Copy40 *)((u8 *)arg0 + 3292);
        *(u32 *)((u8 *)v30 + 0) = 1;
    }
    t30 = loc_18;
    v31 = loc_14;
    v5 = v31;
    *(u32 *)((u8 *)v27 + 0) = *(u32 *)((u8 *)v2 + 0);
    *(u32 *)((u8 *)v27 + 4) = *(u32 *)((u8 *)v2 + 4);
    *(u32 *)((u8 *)v27 + 8) = *(u32 *)((u8 *)v2 + 8);
    *(u32 *)((u8 *)v27 + 12) = *(u32 *)((u8 *)v2 + 12);
    *(u32 *)((u8 *)v27 + 20) = *(u32 *)((u8 *)v2 + 16);
    *(u32 *)((u8 *)v27 + 16) = v5;
    *(u32 *)((u8 *)v27 + 32) = t30;
    return fn_12_27C58((u32)arg0, v27, v5, t30);
}
