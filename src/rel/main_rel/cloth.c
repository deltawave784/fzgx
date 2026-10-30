#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/cloth.h"
#include "game/main_rel/cloth_types.h"

extern u32 fn_1_435C(u32 value);
extern u32 fn_1_46B4(u32, u32, void *, u32);
extern void fn_1_41A8(void);
extern void fn_800711A8(void *);
extern void fn_80071718(void *);
extern void fn_1_105744(void);
extern s32 fn_1_106DB4(u32 arg0, u32 arg1);
extern void fn_1_9D0EC(u32, u32, void*, void*);
extern void fn_1_103AA8(void);
extern u32 lbl_1_bss_85288[2];
extern void fn_1_103AD4(void);
extern void fn_1_105768(void);
extern void fn_1_9E5B8(void *);
extern u32 fn_1_45D0(u32, u32, void *, u32);
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);

/* fzgx:begin fn_1_101AE8 */
struct fn_1_101AE8_lbl_1_bss_85250 {
    u8 pad_0[0xC];
    u32 unk_C;
    u32 unk_10;
    u8 pad_14[0x4];
    u32 unk_18;
    u8 pad_1C[0x4];
    u32 unk_20;
};


void fn_1_101AE8(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    struct fn_1_101AE8_lbl_1_bss_85250 *p_lbl_1_bss_85250;
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v4;
    u32 v5;
    u32 v6;
    u32 v7;
    u32 t6, t7;
    p_lbl_1_bss_85250 = (struct fn_1_101AE8_lbl_1_bss_85250 *)&(*((struct fn_1_101AE8_lbl_1_bss_85250 *)&lbl_1_bss_85250));
    fn_1_435C(arg0);
    fn_1_41A8();
    fn_1_435C(arg1);
    fn_1_41A8();
    v0 = p_lbl_1_bss_85250->unk_C;
    if (v0 != 0) {
    fn_80071718((void *)v0);
    p_lbl_1_bss_85250->unk_C = 0;
    }
    v1 = p_lbl_1_bss_85250->unk_10;
    if (v1 != 0) {
    fn_800711A8((void *)v1);
    p_lbl_1_bss_85250->unk_10 = 0;
    }
    v2 = p_lbl_1_bss_85250->unk_18;
    v5 = arg3;
    if (v2 != 0) {
    v5 = (u32)&(*((struct fn_1_101AE8_lbl_801A6410 *)&lbl_801A6410));
    v3 = (u32)&lbl_1_data_3F17C;
    v4 = *(u32 *)((u8 *)v5 + 0);
    v5 = 257;
    t6 = fn_1_46B4(v4, v2, (void *)((u32)v3), v5);
    v4 = t6;
    p_lbl_1_bss_85250->unk_18 = 0;
    }
    v6 = p_lbl_1_bss_85250->unk_20;
    v7 = v4;
    if (v6 != 0) {
    v7 = (*((struct fn_1_101AE8_lbl_801A6410 *)&lbl_801A6410)).unk_0;
    t7 = fn_1_46B4(v7, v6, (void *)((u32)&lbl_1_data_3F17C), 258);
    v7 = t7;
    p_lbl_1_bss_85250->unk_20 = 0;
    }
}
/* fzgx:end fn_1_101AE8 */

/* fzgx:begin fn_1_101BC4 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/cloth.h"
#include "game/main_rel/cloth_types.h"

struct Sig_fn_80077B64_fn_80077B64_Arg0 {
    u8 pad_0[4]; u32 unk_4;
};
struct Sig_fn_80077B14_fn_80077B14_Arg0 {
    u8 pad_0[4]; u32 unk_4; u8 pad_8[0x18]; u32 unk_20;
};
typedef struct Sig_fn_1_1024C4_Point1024C4 {
    u8 pad[0x10]; f32 v[3];
} Sig_fn_1_1024C4_Point1024C4;
struct fn_1_101BC4_Copy12 { u32 a[3]; };
struct fn_1_101BC4_lbl_1_rodata_77F8 {
    u8 pad_0[0x38];
    struct fn_1_101BC4_Copy12 unk_38;
    u8 pad_44[4];
    const f64 unk_48;
    const f32 unk_50, unk_54, unk_58;
    u8 pad_5C[4];
    const f64 unk_60, unk_68;
    const f32 unk_70;
    u8 pad_74[4];
    const f64 unk_78, unk_80;
    const f64 unk_88;
    const f32 unk_90, unk_94, unk_98;
};
extern const struct fn_1_101BC4_lbl_1_rodata_77F8 lbl_1_rodata_77F8;
extern f32 fn_1_1024C4(const Sig_fn_1_1024C4_Point1024C4 *, const Sig_fn_1_1024C4_Point1024C4 *);
extern f64 __fabs(f64);
extern s32 fn_80077B14(struct Sig_fn_80077B14_fn_80077B14_Arg0 *);
extern void *fn_80077B64(struct Sig_fn_80077B64_fn_80077B64_Arg0 *);
extern u32 fn_1_4630(u32, u32, void *, u32);
extern u32 fn_1_46B4(u32, u32, void *, u32);
extern void fn_1_10240C(u32, u32, u32);
extern void fn_80008BEC(void *, int, u32);

/* Preserve the ordered accesses of the chained vector copies. */
static inline void fn_1_101BC4_copy12(volatile struct fn_1_101BC4_Copy12 *dst, const volatile struct fn_1_101BC4_Copy12 *src) {
    *dst = *src;
}

void fn_1_101BC4(u32 arg0) {
    const struct fn_1_101BC4_lbl_1_rodata_77F8 *p_lbl_1_rodata_77F8;
    Obj_1_bss_85250 *p_lbl_1_bss_85250;
    struct { u32 value; } v0;
    u32 v4;
    u32 v2;
    f64 v3;
    f64 v5;
    u32 v6;
    struct { u32 value; } v1;
    u32 v6_2;
#define v1 v1.value
    u32 v7;
    u32 v8;
    s32 v9;
    u32 v11;
    s32 v14;
    u32 v12;
    u32 v13;
    u32 v10;
    f32 v15;
    f32 v16;
    u32 v17;
    u32 v18;
    u32 v19;
    u32 v20;
    u32 v21;
    u32 v22;
    u32 v23;
    u8 v24;
    u32 v26;
    u32 v27;
    f32 v28;
    f64 v29;
    f32 v30;
    f32 v31;
    u32 v33;
    u32 v35;
    u32 v37;
    u32 v39;
    f64 v40;
    u32 v41;
    u32 v44;
    f32 v46;
    f32 v45;
    u32 v47;
    u32 v48;
    u32 v49;
    f32 v50;
    u32 v51;
    u32 v52;
    f32 v53;
    u32 v54;
    u32 v55;
    u32 v59;
    u32 v60;
    u32 v61;
    f32 v62;
    u32 v63;
    u32 v64;
    f32 dz, dy, dx;
    p_lbl_1_rodata_77F8 = &lbl_1_rodata_77F8;
    p_lbl_1_bss_85250 = &lbl_1_bss_85250;
    if (arg0 != 0) {
        v7 = (u32)p_lbl_1_bss_85250->unk_18;
        if (v7 != 0) {
            fn_1_46B4(*(u32 *)&lbl_801A6410, v7, &lbl_1_data_3F17C, 281);
            p_lbl_1_bss_85250->unk_18 = 0;
        }
        v8 = (u32)p_lbl_1_bss_85250->unk_20;
        if (v8 != 0) {
            fn_1_46B4(*(u32 *)&lbl_801A6410, v8, &lbl_1_data_3F17C, 282);
            p_lbl_1_bss_85250->unk_20 = 0;
        }
        v1 = (u32)fn_80077B64((struct Sig_fn_80077B64_fn_80077B64_Arg0 *)arg0);
        v2 = fn_80077B14((struct Sig_fn_80077B14_fn_80077B14_Arg0 *)arg0);
        p_lbl_1_bss_85250->unk_18 = (Obj_1_bss_85250_At18 *)
            fn_1_4630(*(u32 *)&lbl_801A6410, *(u32 *)v1 * 68, &lbl_1_data_3F17C, 287);
        v3 = p_lbl_1_rodata_77F8->unk_48;
        v4 = 0;
        p_lbl_1_bss_85250->unk_1C = 0;
        while (v4 < *(u32 *)v1) {
            v10 = (u32)p_lbl_1_bss_85250->unk_18;
            v0.value = p_lbl_1_bss_85250->unk_1C;
            v14 = -1;
            v13 = v10;
            for (v12 = 0; v12 < v0.value; v12++, v13 += 68) {
                dx = *(f32 *)(v13 + 16);
                dy = *(f32 *)(v13 + 20);
                dz = *(f32 *)(v13 + 24);
                dx -= *(f32 *)v2;
                dy -= *(f32 *)(v2 + 4);
                dz -= *(f32 *)(v2 + 8);
                dx *= dx;
                dx = dy * dy + dx;
                dx = dz * dz + dx;
                if (dx < v3) {
                    v14 = v12;
                    break;
                }
            }
            if ((v14 + 0x10000U) != 65535) {
                v17 = v10 + v14 * 68;
                v0.value = ((Obj_1_bss_85250_At18 *)v17)->unk_2 << 1;
                *(u16 *)(v17 + v0.value + 4) = v4;
                ((Obj_1_bss_85250_At18 *)((u8 *)p_lbl_1_bss_85250->unk_18 + v14 * 68))->unk_2++;
            } else {
                v20 = v0.value * 68;
                v6 = v10 + v20;
                fn_1_101BC4_copy12((struct fn_1_101BC4_Copy12 *)(v6 + 40), (struct fn_1_101BC4_Copy12 *)v2);
                fn_1_101BC4_copy12((struct fn_1_101BC4_Copy12 *)(v6 + 28), (struct fn_1_101BC4_Copy12 *)(v6 + 40));
                fn_1_101BC4_copy12((struct fn_1_101BC4_Copy12 *)(v6 + 16), (struct fn_1_101BC4_Copy12 *)(v6 + 28));
                fn_1_101BC4_copy12((struct fn_1_101BC4_Copy12 *)(v6 + 52), &p_lbl_1_rodata_77F8->unk_38);
                ((Obj_1_bss_85250_At18 *)v6)->unk_0 = *(u8 *)(v2 + 53);
                ((Obj_1_bss_85250_At18 *)v6)->unk_2 = 1;
                fn_80008BEC((void *)(v6 + 4), 255, 10);
                ((Obj_1_bss_85250_At18 *)v6)->unk_4 = v4;
                ((Obj_1_bss_85250_At18 *)v6)->unk_40 = p_lbl_1_rodata_77F8->unk_50;
                p_lbl_1_bss_85250->unk_1C++;
            }
            v4++;
            v2 += 64;
        }
        v26 = (u32)p_lbl_1_bss_85250->unk_18;
        v27 = 0;
        while (v27 < p_lbl_1_bss_85250->unk_1C) {
            if ((((Obj_1_bss_85250_At18 *)v26)->unk_0 & 1) != 0) {
                ((Obj_1_bss_85250_At18 *)v26)->unk_0 = 1;
                v28 = p_lbl_1_rodata_77F8->unk_54;
                ((Obj_1_bss_85250_At18 *)v26)->unk_1 = 0;
                ((Obj_1_bss_85250_At18 *)v26)->unk_40 = v28;
            } else if (*(f32 *)(v26 + 16) > p_lbl_1_rodata_77F8->unk_58) {
                v29 = p_lbl_1_rodata_77F8->unk_60;
                ((Obj_1_bss_85250_At18 *)v26)->unk_1 = 1;
                v5 = ((Obj_1_bss_85250_At18 *)v26)->unk_18;
                if (v5 > v29 || v5 < p_lbl_1_rodata_77F8->unk_68) {
                    v28 = p_lbl_1_rodata_77F8->unk_54;
                    ((Obj_1_bss_85250_At18 *)v26)->unk_0 = 1;
                    ((Obj_1_bss_85250_At18 *)v26)->unk_40 = v28;
                }
                if (((Obj_1_bss_85250_At18 *)v26)->unk_14 > p_lbl_1_rodata_77F8->unk_70) {
                    v5 = __fabs(((Obj_1_bss_85250_At18 *)v26)->unk_18);
                    if (v5 > p_lbl_1_rodata_77F8->unk_78 && v5 < p_lbl_1_rodata_77F8->unk_80) {
                        v28 = p_lbl_1_rodata_77F8->unk_54;
                        ((Obj_1_bss_85250_At18 *)v26)->unk_0 = 1;
                        ((Obj_1_bss_85250_At18 *)v26)->unk_40 = v28;
                    }
                }
            } else if (((Obj_1_bss_85250_At18 *)v26)->unk_14 > p_lbl_1_rodata_77F8->unk_70) {
                ((Obj_1_bss_85250_At18 *)v26)->unk_1 = 2;
            } else if (((Obj_1_bss_85250_At18 *)v26)->unk_18 > p_lbl_1_rodata_77F8->unk_54) {
                ((Obj_1_bss_85250_At18 *)v26)->unk_1 = 3;
            } else {
                ((Obj_1_bss_85250_At18 *)v26)->unk_1 = 4;
            }
            v27++;
            v26 += 68;
        }
        v2 = 0;
        v33 = (u32)p_lbl_1_bss_85250->unk_18;
        while (v2 < p_lbl_1_bss_85250->unk_1C) {
            v12 = v2 + 1;
            v1 = (u32)p_lbl_1_bss_85250->unk_18 + v2 * 68 + 68;
            while (v12 < p_lbl_1_bss_85250->unk_1C) {
                if (((Obj_1_bss_85250_At18 *)v33)->unk_1 > ((Obj_1_bss_85250_At18 *)v1)->unk_1)
                    fn_1_10240C(v33, v1, 68);
                v12++;
                v1 += 68;
            }
            v2++;
            v33 += 68;
        }
        v2 = 0;
        v1 = (u32)p_lbl_1_bss_85250->unk_18;
        while (v2 < p_lbl_1_bss_85250->unk_1C) {
            v35 = (u32)p_lbl_1_bss_85250->unk_18 + v2 * 68 + 68;
            v6 = v2 + 1;
            while (v6 < p_lbl_1_bss_85250->unk_1C) {
                if (((Obj_1_bss_85250_At18 *)v1)->unk_1 == ((Obj_1_bss_85250_At18 *)v35)->unk_1 &&
                    ((Obj_1_bss_85250_At18 *)v1)->unk_14 > ((Obj_1_bss_85250_At18 *)v35)->unk_14)
                    fn_1_10240C(v1, v35, 68);
                v6++;
                v35 += 68;
            }
            v2++;
            v1 += 68;
        }
        v2 = 0;
        v1 = (u32)p_lbl_1_bss_85250->unk_18;
        v3 = p_lbl_1_rodata_77F8->unk_88;
        while (v2 < p_lbl_1_bss_85250->unk_1C) {
            v37 = (u32)p_lbl_1_bss_85250->unk_18 + v2 * 68 + 68;
            v6 = v2 + 1;
            while (v6 < p_lbl_1_bss_85250->unk_1C) {
                if (((Obj_1_bss_85250_At18 *)v1)->unk_1 == ((Obj_1_bss_85250_At18 *)v37)->unk_1 &&
                    __fabs((f32)(((Obj_1_bss_85250_At18 *)v1)->unk_14 - ((Obj_1_bss_85250_At18 *)v37)->unk_14)) < v3 &&
                    ((Obj_1_bss_85250_At18 *)v1)->unk_18 > ((Obj_1_bss_85250_At18 *)v37)->unk_18)
                    fn_1_10240C(v1, v37, 68);
                v6++;
                v37 += 68;
            }
            v2++;
            v1 += 68;
        }
        v2 = 0;
        v1 = (u32)p_lbl_1_bss_85250->unk_18;
        while (v2 < p_lbl_1_bss_85250->unk_1C) {
            v39 = (u32)p_lbl_1_bss_85250->unk_18 + v2 * 68 + 68;
            v6 = v2 + 1;
            while (v6 < p_lbl_1_bss_85250->unk_1C) {
                if (((Obj_1_bss_85250_At18 *)v1)->unk_1 == ((Obj_1_bss_85250_At18 *)v39)->unk_1) {
                    v40 = p_lbl_1_rodata_77F8->unk_88;
                    if (__fabs((f32)(((Obj_1_bss_85250_At18 *)v1)->unk_14 - ((Obj_1_bss_85250_At18 *)v39)->unk_14)) < v40 &&
                        __fabs((f32)(((Obj_1_bss_85250_At18 *)v1)->unk_18 - ((Obj_1_bss_85250_At18 *)v39)->unk_18)) < v40 &&
                        *(f32 *)(v1 + 16) > *(f32 *)(v39 + 16))
                        fn_1_10240C(v1, v39, 68);
                }
                v6++;
                v39 += 68;
            }
            v2++;
            v1 += 68;
        }
        v41 = p_lbl_1_bss_85250->unk_1C;
        p_lbl_1_bss_85250->unk_28 = 0;
        v44 = (u32)p_lbl_1_bss_85250->unk_18;
        p_lbl_1_bss_85250->unk_2C = 0;
        for (v11 = 0; v11 < v41 - 1; v11++) {
            if (((Obj_1_bss_85250_At18 *)v44)->unk_1 == 1 && ((Obj_1_bss_85250_At18 *)v44)->unk_45 == 1) {
                v45 = ((Obj_1_bss_85250_At18 *)v44)->unk_14;
                v46 = ((Obj_1_bss_85250_At18 *)v44)->unk_58;
                v5 = p_lbl_1_rodata_77F8->unk_88;
                if (__fabs((f32)(v45 - v46)) < v5) {
                    if (__fabs(v45) < v5 && __fabs(v46) < v5)
                        p_lbl_1_bss_85250->unk_28++;
                    p_lbl_1_bss_85250->unk_2C++;
                }
            }
            v44 += 68;
        }
        v47 = p_lbl_1_bss_85250->unk_28;
        v48 = p_lbl_1_bss_85250->unk_2C / v47 - 1;
        p_lbl_1_bss_85250->unk_2C = v48;
        v49 = v47 * (v48 + 1) + v48 * (v47 + 1);
        p_lbl_1_bss_85250->unk_24 = v49;
        p_lbl_1_bss_85250->unk_20 = (Obj_1_bss_85250_At20 *)
            fn_1_4630(*(u32 *)&lbl_801A6410, v49 * 24, &lbl_1_data_3F17C, 433);
        v2 = 0;
        v4 = (u32)p_lbl_1_bss_85250->unk_18;
        v6_2 = 0;
        while (v2 < p_lbl_1_bss_85250->unk_1C - 1) {
            if (((Obj_1_bss_85250_At18 *)v4)->unk_1 == 1 && ((Obj_1_bss_85250_At18 *)v4)->unk_45 == 1) {
                v50 = ((Obj_1_bss_85250_At18 *)v4)->unk_14;
                if (__fabs((f32)(v50 - ((Obj_1_bss_85250_At18 *)v4)->unk_58)) < p_lbl_1_rodata_77F8->unk_88) {
                    v51 = v4 + 68;
                    *(u32 *)((u32)p_lbl_1_bss_85250->unk_20 + v6_2 * 24) = v4;
                    *(u32 *)((u32)p_lbl_1_bss_85250->unk_20 + v6_2 * 24 + 4) = v51;
                    v15 = fn_1_1024C4((const Sig_fn_1_1024C4_Point1024C4 *)v4, (const Sig_fn_1_1024C4_Point1024C4 *)v51);
                    v0.value = (u32)p_lbl_1_bss_85250->unk_20;
                    v53 = p_lbl_1_rodata_77F8->unk_90;
                    *(f32 *)(v0.value + v6_2 * 24 + 8) = v15;
                    v16 = p_lbl_1_rodata_77F8->unk_94;
                    v52 = (u32)p_lbl_1_bss_85250->unk_20;
                    v28 = p_lbl_1_rodata_77F8->unk_98;
                    *(f32 *)(v52 + v6_2 * 24 + 12) = v53;
                    *(f32 *)((u32)p_lbl_1_bss_85250->unk_20 + v6_2 * 24 + 16) = v16;
                    *(f32 *)((u32)p_lbl_1_bss_85250->unk_20 + v6_2 * 24 + 20) = v28;
                    v6_2++;
                }
            }
            v2++;
            v4 += 68;
        }
        v2 = 0;
        v4 = (u32)p_lbl_1_bss_85250->unk_18;
        v3 = p_lbl_1_rodata_77F8->unk_88;
        while (v2 < p_lbl_1_bss_85250->unk_1C) {
            v60 = v2 + 1;
            v59 = (u32)p_lbl_1_bss_85250->unk_18 + v2 * 68 + 68;
            for (; v60 < p_lbl_1_bss_85250->unk_1C; v60++, v59 += 68) {
                if (((Obj_1_bss_85250_At18 *)v4)->unk_1 == 1 && ((Obj_1_bss_85250_At18 *)v59)->unk_1 == 1 &&
                    __fabs((f32)(((Obj_1_bss_85250_At18 *)v4)->unk_18 - ((Obj_1_bss_85250_At18 *)v59)->unk_18)) < v3) {
                    *(u32 *)((u32)p_lbl_1_bss_85250->unk_20 + v6_2 * 24) = v4;
                    *(u32 *)((u32)p_lbl_1_bss_85250->unk_20 + v6_2 * 24 + 4) = v59;
                    v15 = fn_1_1024C4((const Sig_fn_1_1024C4_Point1024C4 *)v4, (const Sig_fn_1_1024C4_Point1024C4 *)v59);
                    v0.value = (u32)p_lbl_1_bss_85250->unk_20;
                    v62 = p_lbl_1_rodata_77F8->unk_90;
                    *(f32 *)(v0.value + v6_2 * 24 + 8) = v15;
                    v16 = p_lbl_1_rodata_77F8->unk_94;
                    v52 = (u32)p_lbl_1_bss_85250->unk_20;
                    v28 = p_lbl_1_rodata_77F8->unk_98;
                    *(f32 *)(v52 + v6_2 * 24 + 12) = v62;
                    *(f32 *)((u32)p_lbl_1_bss_85250->unk_20 + v6_2 * 24 + 16) = v16;
                    *(f32 *)((u32)p_lbl_1_bss_85250->unk_20 + v6_2 * 24 + 20) = v28;
                    v6_2++;
                    break;
                }
            }
            v2++;
            v4 += 68;
        }
    }
}
/* fzgx:end fn_1_101BC4 */

/* fzgx:begin fn_1_10240C */
void fn_1_10240C(u32 arg0, u32 arg1, s32 arg2) {
    u32 t0;
    t0 = fn_1_45D0(lbl_801A6410.unk_0, arg2, &lbl_1_data_3F17C, 561);
    fn_80008BA8(t0, arg0, arg2);
    fn_80008BA8(arg0, arg1, arg2);
    fn_80008BA8(arg1, t0, arg2);
    fn_1_46B4(lbl_801A6410.unk_0, t0, &lbl_1_data_3F17C, 565);
}
/* fzgx:end fn_1_10240C */

/* fzgx:begin fn_1_1024C4 */
typedef struct Point1024C4 {
    u8 pad[0x10];
    f32 v[3];
} Point1024C4;

f32 fn_1_1024C4(const Point1024C4 *a, const Point1024C4 *b) {
    f32 dz = a->v[2] - b->v[2];
    f32 dy = a->v[1] - b->v[1];
    f32 dx = a->v[0] - b->v[0];
    f32 result = dx * dx;
    result += dy * dy;
    result += dz * dz;
    return result;
}
/* fzgx:end fn_1_1024C4 */

/* fzgx:begin fn_1_1024F8 */
struct Sig_fn_80077B14_fn_80077B14_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
    u8 pad_8[0x18];
    u32 unk_20;
};

typedef struct ClothVec {
    f32 x, y, z;
} ClothVec;

typedef struct ClothPoint {
    u8 flags;
    u8 type;
    u8 count;
    u8 pad_3;
    u16 idx[6];
    ClothVec pos;
    u8 pad_1C[0xC];
    ClothVec rest;
    u8 pad_34[0x10];
} ClothPoint;

typedef struct ClothMeshEntry {
    struct Sig_fn_80077B14_fn_80077B14_Arg0 *mesh;
    u32 unk_4;
} ClothMeshEntry;

extern f32 lbl_8006D188(s16);
extern s32 fn_80077B14(struct Sig_fn_80077B14_fn_80077B14_Arg0 *);
extern s32 lbl_801A66A0;

void fn_1_1024F8(void) {
    Obj_1_bss_85250 *p = &lbl_1_bss_85250;
    struct Sig_fn_80077B14_fn_80077B14_Arg0 *mesh;
    u8 *verts;
    s32 sq;
    u32 i;
    u32 j;
    f64 d;

    mesh = ((ClothMeshEntry *)p->unk_10->unk_8)[p->unk_4].mesh;
    if (mesh == NULL) {
        return;
    }
    verts = (u8 *)fn_80077B14(mesh);
    if (mesh->unk_4 & 0x10) {
        for (i = 0; i < p->unk_1C; i++) {
            ((ClothPoint *)p->unk_18)[i].pos = ((ClothPoint *)p->unk_18)[i].rest;
            for (j = 0; j < ((ClothPoint *)p->unk_18)[i].count; j++) {
                *(ClothVec *)(verts + (((ClothPoint *)p->unk_18)[i].idx[j] << 6)) =
                    ((ClothPoint *)p->unk_18)[i].pos;
            }
        }
    }
    for (i = 0; i < p->unk_1C; i++) {
        if (((ClothPoint *)p->unk_18)[i].type == 1 && !(((ClothPoint *)p->unk_18)[i].flags & 1)) {
            d = 0.01 * lbl_8006D188((lbl_801A66A0 + i * i) << 8);
            ((ClothPoint *)p->unk_18)[i].pos.x += d;
            d = 0.01 * lbl_8006D188(((lbl_801A66A0 + i * i + i) << 7) + 0x4000);
            ((ClothPoint *)p->unk_18)[i].pos.y += d;
            d = 0.01 * lbl_8006D188((lbl_801A66A0 + i * (i * i)) << 9);
            ((ClothPoint *)p->unk_18)[i].pos.z += d;
            for (j = 0; j < ((ClothPoint *)p->unk_18)[i].count; j++) {
                *(ClothVec *)(verts + (((ClothPoint *)p->unk_18)[i].idx[j] << 6)) =
                    ((ClothPoint *)p->unk_18)[i].pos;
            }
        }
    }
}
/* fzgx:end fn_1_1024F8 */

/* fzgx:begin fn_1_102FD0 */
// Initialize the cloth subsystem and reset its shared state.
void fn_1_102FD0(void) {
    fn_1_105744();
    fn_1_9D0EC(lbl_1_bss_3BE0->unk_54, lbl_1_bss_3BE0->unk_48,
               lbl_1_data_3F244, fn_1_106DB4);
    fn_1_103AA8();
    lbl_1_bss_85288[0] = -1;
    lbl_1_bss_85288[1] = -1;
}
/* fzgx:end fn_1_102FD0 */

/* fzgx:begin fn_1_10302C */
// fn_1_10302C: empty in retail (single blr).
void fn_1_10302C(void) {
}
/* fzgx:end fn_1_10302C */

/* fzgx:begin fn_1_103030 */
void fn_1_103030(void) {
    fn_1_103AD4();
    fn_1_105768();
}
/* fzgx:end fn_1_103030 */

/* fzgx:begin fn_1_103054 */
// fn_1_103054: empty in retail (single blr).
void fn_1_103054(void) {
}
/* fzgx:end fn_1_103054 */

/* fzgx:begin fn_1_103058 */
// Runs the cloth update unless the global state is one of the inactive modes.
void fn_1_103058(void) {
    s16 state = *(s16 *)(void *)&lbl_1_bss_960;

    if (state != 10 && state != 14) {
        fn_1_10576C();
    }
}
/* fzgx:end fn_1_103058 */

/* fzgx:begin fn_1_103090 */
typedef struct ClothState {
    u8 _pad68[0x68];
    void *field_68;
    u8 _pad6c[8];
    void *field_74;
    void *field_78;
    u8 field_7c;
} ClothState;

void fn_1_103090(ClothState *self) {
    self->field_74 = self->field_68;
    self->field_78 = &self->field_7c;
}
/* fzgx:end fn_1_103090 */

/* fzgx:begin fn_1_1030A4 */
typedef struct Cloth {
    u8 pad_00[0x68];
    s32 field_68;
    u8 field_6c[4];
    u8 field_70[1];
} Cloth;

void fn_1_1030A4(Cloth *self) {
    if (self->field_68 != 0) {
        fn_1_9E5B8(&self->field_70);
    }
}
/* fzgx:end fn_1_1030A4 */

/* fzgx:begin fn_1_1050D0 noprologue */
#include "types.h"
#include "dolphin/gx.h"
#include "rel/main_rel/cloth.h"

typedef struct { f32 x, y, z; } Vec;

struct fn_1_1050D0_lbl_1_rodata_78D0 {
    u8 pad_0[0x4];
    f32 unk_4;
    u8 pad_8[0x8];
    f32 unk_10;
    u8 pad_14[0x4];
    f32 unk_18;
    u8 pad_1C[0x8];
    f32 unk_24;
    u8 pad_28[0xE4];
    f32 unk_10C;
};
extern struct fn_1_1050D0_lbl_1_rodata_78D0 lbl_1_rodata_78D0;
extern s32 fn_1_58C4(void);
extern s32 fn_1_5910(void);
extern u16 lbl_1_bss_85298[272];
extern u32 lbl_801A66A0;
extern void *lbl_801A6D00;
extern u32 camera_get_status(void);
extern u32 fn_1_7BEAC(u32);
extern u32 fn_1_F2F34(void);
extern void lbl_8006D7F4(f32, f32, f32);
extern void lbl_8006DAEC(void);
extern void lbl_8006DBE4(void);
extern void lbl_8006DCA4(void);
extern void lbl_8006DFC4(void *);
extern void lbl_8006E0A4(void *);
extern void mathutil_mtxA_rotate_x(s32);
extern void mathutil_mtxA_rotate_y(s32);
extern void fn_1_556B8(void *);
extern void fn_1_56000(u8, u8, u8);
extern void fn_1_560F0(s32, void *);
extern void fn_8003462C(u32, u32, u32);
extern void fn_8007245C(u32);
extern void fn_800724C8(void);
extern void fn_80072558(void);
extern void fn_80072864(u32);
extern void fn_800728A8(s32, s32, s32, s32);
extern void fn_80072EDC(s32, s32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_80073678(u32);
extern void fn_80074918(u8, s32, u8);
extern void fn_80077BBC(s32);
extern void lbl_8006D758(void);
extern void lbl_8006DB30(void);
extern void lbl_8006E0B4(f32, f32, f32);
extern void lbl_8006E15C(f32, f32, f32);
#define __WGPIPE GXWGFifo.f32

void fn_1_1050D0(void) {
    struct fn_1_1050D0_lbl_1_rodata_78D0 *p_lbl_1_rodata_78D0 = &lbl_1_rodata_78D0;
    Vec *p_lbl_1_data_3F2EC;
    Obj_1_data_3F28C *p_lbl_1_data_3F28C;
    Obj_1_bss_38460 *p_lbl_1_bss_38460;
    u8 *state;
    s32 v3;
    s32 v19;
    s32 i;
    Vec loc[4];
    Obj_1_data_3F2EC *v4, *v5, *v6, *v9;

    state = (u8 *)lbl_1_bss_85298 + fn_1_5910() * 136;
    v3 = 0;
    if (state[127] == 0 && (s16)camera_get_status() == 1) {
    switch ((s32)fn_1_F2F34()) {
    case 0:
    if ((u32)fn_1_58C4() == 4) v3 = 1;
    fn_1_7BEAC(0);
    lbl_8006DCA4();
    lbl_8006E0A4(state);
    mathutil_mtxA_rotate_y(*(s16 *)(state + 128));
    lbl_8006DFC4(state + 72);
    fn_80072558();
    fn_800724C8();
    fn_8007245C(512);
    fn_80073678(1);
    fn_800734A8(0, 255, 255, 255);
    fn_80072EDC(0, 4);
    fn_800728A8(1, 0, 1, 0);
    fn_80074918(1, 7, 1);
    fn_80072864(1);
    for (i = 0; i < 6; i++) {
        p_lbl_1_data_3F28C = (Obj_1_data_3F28C *)((u8 *)&lbl_1_data_3F28C + i * 16);
        p_lbl_1_data_3F2EC = (Vec *)&lbl_1_data_3F2EC.unk_0;
        loc[0] = p_lbl_1_data_3F2EC[p_lbl_1_data_3F28C->unk_0];
        loc[1] = p_lbl_1_data_3F2EC[p_lbl_1_data_3F28C->unk_1];
        loc[2] = p_lbl_1_data_3F2EC[p_lbl_1_data_3F28C->unk_2];
        loc[3] = p_lbl_1_data_3F2EC[p_lbl_1_data_3F28C->unk_3];
        fn_8003462C(128, 0, 4);
        __WGPIPE = loc[0].x;
        __WGPIPE = loc[0].y;
        __WGPIPE = loc[0].z;
        __WGPIPE = loc[1].x;
        __WGPIPE = loc[1].y;
        __WGPIPE = loc[1].z;
        __WGPIPE = loc[2].x;
        __WGPIPE = loc[2].y;
        __WGPIPE = loc[2].z;
        __WGPIPE = loc[3].x;
        __WGPIPE = loc[3].y;
        __WGPIPE = loc[3].z;
    }
    fn_80072864(0);
    fn_1_56000(1, 1, 1);
    p_lbl_1_bss_38460 = &lbl_1_bss_38460;
    v19 = 0;
    goto loop_test; /* Test the pass limit before the first iteration. */
    do {
        lbl_8006DCA4();
        lbl_8006E0A4(state);
        mathutil_mtxA_rotate_y(*(s16 *)(state + 128));
        lbl_8006DFC4(state + 72);
        if (v19 == 1) {
            lbl_8006E15C(p_lbl_1_rodata_78D0->unk_24, p_lbl_1_rodata_78D0->unk_10, p_lbl_1_rodata_78D0->unk_10);
            fn_80077BBC(1);
        }
        lbl_8006DAEC();
        if (v19 != 2) {
            if (v3 == 0 || v19 != 0) {
                lbl_8006DBE4();
                mathutil_mtxA_rotate_x((s16)(((lbl_801A66A0 % 300) << 16) / 300));
                if (v3) lbl_8006E0B4(p_lbl_1_rodata_78D0->unk_10C, p_lbl_1_rodata_78D0->unk_18, p_lbl_1_rodata_78D0->unk_18);
                fn_80072558();
                fn_1_556B8((void *)*(u32 *)(p_lbl_1_bss_38460->unk_8->unk_8 + 8));
            }
            lbl_8006DBE4();
            mathutil_mtxA_rotate_x((s16)(-((lbl_801A66A0 % 300) << 16) / 300));
            if (v3) lbl_8006E0B4(p_lbl_1_rodata_78D0->unk_10C, p_lbl_1_rodata_78D0->unk_18, p_lbl_1_rodata_78D0->unk_18);
            fn_80072558();
            fn_1_556B8((void *)*(u32 *)(p_lbl_1_bss_38460->unk_8->unk_8 + 16));
            lbl_8006DBE4();
            mathutil_mtxA_rotate_x((s16)(-((lbl_801A66A0 % 100) << 16) / 100));
            if (v3) lbl_8006E0B4(p_lbl_1_rodata_78D0->unk_10C, p_lbl_1_rodata_78D0->unk_18, p_lbl_1_rodata_78D0->unk_18);
            fn_80072558();
            fn_1_556B8((void *)*(u32 *)(p_lbl_1_bss_38460->unk_8->unk_8 + 24));
            lbl_8006DBE4();
            mathutil_mtxA_rotate_x((s16)(((lbl_801A66A0 % 60) << 16) / 60));
            if (v3) lbl_8006E0B4(p_lbl_1_rodata_78D0->unk_10C, p_lbl_1_rodata_78D0->unk_18, p_lbl_1_rodata_78D0->unk_18);
            fn_80072558();
            fn_1_556B8((void *)*(u32 *)(p_lbl_1_bss_38460->unk_8->unk_8 + 32));
            lbl_8006DBE4();
            if (v3) lbl_8006E0B4(p_lbl_1_rodata_78D0->unk_10C, p_lbl_1_rodata_78D0->unk_18, p_lbl_1_rodata_78D0->unk_18);
            fn_80072558();
            fn_1_556B8((void *)*(u32 *)(p_lbl_1_bss_38460->unk_8->unk_8 + 40));
        }
        if (v19 == 0) {
            lbl_8006D758();
            fn_1_560F0(0, lbl_801A6D00);
            lbl_8006DBE4();
            mathutil_mtxA_rotate_x((s32)(p_lbl_1_rodata_78D0->unk_4 * *(f32 *)(state + 120)));
            if (v3) lbl_8006E0B4(p_lbl_1_rodata_78D0->unk_10C, p_lbl_1_rodata_78D0->unk_18, p_lbl_1_rodata_78D0->unk_18);
            fn_80072558();
            fn_1_556B8((void *)*(u32 *)(p_lbl_1_bss_38460->unk_8->unk_8 + 48));
        } else if (v19 == 2) {
            lbl_8006D758();
            fn_1_560F0(0, lbl_801A6D00);
            lbl_8006DBE4();
            mathutil_mtxA_rotate_x((s32)(p_lbl_1_rodata_78D0->unk_4 * *(f32 *)(state + 120)));
            fn_80072558();
            fn_1_556B8((void *)*(u32 *)(p_lbl_1_bss_38460->unk_8->unk_8 + 144));
            lbl_8006DBE4();
            mathutil_mtxA_rotate_x((s32)(p_lbl_1_rodata_78D0->unk_4 * *(f32 *)(state + 120)));
            fn_80072558();
            fn_1_556B8((void *)*(u32 *)(p_lbl_1_bss_38460->unk_8->unk_8 + 56));
        } else if (v19 == 1) {
            lbl_8006D7F4(p_lbl_1_rodata_78D0->unk_10, p_lbl_1_rodata_78D0->unk_18, p_lbl_1_rodata_78D0->unk_18);
            lbl_8006E15C(p_lbl_1_rodata_78D0->unk_24, p_lbl_1_rodata_78D0->unk_10, p_lbl_1_rodata_78D0->unk_10);
            fn_1_560F0(0, lbl_801A6D00);
            lbl_8006DBE4();
            mathutil_mtxA_rotate_x((s32)(p_lbl_1_rodata_78D0->unk_4 * *(f32 *)(state + 120)));
            if (v3) lbl_8006E0B4(p_lbl_1_rodata_78D0->unk_10C, p_lbl_1_rodata_78D0->unk_18, p_lbl_1_rodata_78D0->unk_18);
            fn_80072558();
            fn_1_556B8((void *)*(u32 *)(p_lbl_1_bss_38460->unk_8->unk_8 + 48));
        }
        lbl_8006DB30();
        if (v19 == 1) fn_80077BBC(0);
        v19++;
loop_test:
        i = 2;
        if (v3 != 0) i = 1;
    } while (v19 <= i);
    fn_1_56000(1, 3, 1);
    }
    }
}
/* fzgx:end fn_1_1050D0 */

/* fzgx:begin fn_1_106CAC */
typedef struct Sig_fn_8003C1A4_JpegDec Sig_fn_8003C1A4_JpegDec;
typedef struct {
    Obj_1_bss_85280 base;
    u8 pad_8[0x240];
    s32 unk_248;
    u8 pad_24C[0x6BC];
    u8 unk_908;
} BgJpegState;
extern int fn_1_151AF0(u8 *, int, void *, void *, void *, Sig_fn_8003C1A4_JpegDec *);

s32 fn_1_106CAC(void) {
    BgJpegState *p = (BgJpegState *)&lbl_1_bss_85280;
    if ((s32)p->unk_248 == 2) {
        return 0;
    }
    fn_1_151AF0((u8 *)p->base.unk_4, 0,
        (void *)(&lbl_1_data_3F284.unk_0)[p->unk_908], 0, 0,
        (Sig_fn_8003C1A4_JpegDec *)p->base.unk_0);
    p->unk_908 = 1 - p->unk_908;
    p->unk_248 = 1;
    return 0;
}
/* fzgx:end fn_1_106CAC */
