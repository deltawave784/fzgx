#include "types.h"
#include "game/main_rel/cloth_types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/cloth.h"
#include "dolphin/gx.h"

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

typedef struct Point1024C4 {
    u8 pad[0x10];
    f32 v[3];
} Point1024C4;

struct fn_1_101BC4_Sig_fn_80077B14_fn_80077B14_Arg0 {
    u8 pad_0[4]; u32 unk_4; u8 pad_8[0x18]; u32 unk_20;
};

struct fn_1_1024F8_Sig_fn_80077B14_fn_80077B14_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
    u8 pad_8[0x18];
    u32 unk_20;
};

struct Sig_fn_80077B64_fn_80077B64_Arg0 {
    u8 pad_0[4]; u32 unk_4;
};

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
extern const struct fn_1_101BC4_lbl_1_rodata_77F8 lbl_1_rodata_77F8;
extern f32 fn_1_1024C4(const Point1024C4 *a, const Point1024C4 *b);
extern f64 __fabs(f64);
extern s32 fn_80077B14(struct fn_1_101BC4_Sig_fn_80077B14_fn_80077B14_Arg0 *);
extern void *fn_80077B64(struct Sig_fn_80077B64_fn_80077B64_Arg0 *);
extern u32 fn_1_4630();
extern u32 fn_1_46B4(u32, u32, void *, u32);
extern void fn_1_10240C(u32 arg0, u32 arg1, s32 arg2);
extern void fn_80008BEC(void *dest, int value, u32 size);
extern f32 lbl_8006D188(s16);
extern s32 lbl_801A66A0;
extern struct fn_1_1050D0_lbl_1_rodata_78D0 lbl_1_rodata_78D0;
extern s32 fn_1_58C4(void);
extern s32 fn_1_5910(void);
extern u16 lbl_1_bss_85298[272];
extern void *lbl_801A6D00;
extern u32 camera_get_status(void);
extern void fn_1_7BEAC();
extern u32 fn_1_F2F34(void);
extern void lbl_8006D7F4(f32, f32, f32);
extern void lbl_8006DAEC(void);
extern void lbl_8006DBE4(void);
extern void lbl_8006DCA4(void);
extern void lbl_8006DFC4(void *);
extern void lbl_8006E0A4(void *);
extern void mathutil_mtxA_rotate_x(s32);
extern void mathutil_mtxA_rotate_y(s32);
extern void fn_1_556B8(void *value);
extern void fn_1_56000(u8 value0, u8 value1, u8 value2);
extern void fn_1_560F0(s32 index, void *arg);
extern void fn_8003462C(u32 arg0, u32 arg1, u32 arg2);
extern void fn_8007245C(u32 value);
extern void fn_800724C8(void);
extern void fn_80072558(void);
extern void fn_80072864(u32 arg0);
extern void fn_800728A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_80072EDC(s32 arg0, s32 arg1);
extern void fn_800734A8(u32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_80073678(u32 arg0);
extern void fn_80074918(u8 arg0, s32 arg1, u8 arg2);
extern void fn_80077BBC(s32 arg0);
extern void lbl_8006D758(void);
extern void lbl_8006DB30(void);
extern void lbl_8006E0B4(f32, f32, f32);
extern void lbl_8006E15C(f32, f32, f32);
extern int fn_1_151AF0(void *arg0, int mode, void *arg2, void *arg3, void *arg4, void *arg5);
extern u32 fn_1_435C(u32 value);
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

/* fzgx:begin fn_1_101BC4 */
typedef struct Sig_fn_1_1024C4_Point1024C4 {
    u8 pad[0x10]; f32 v[3];
} Sig_fn_1_1024C4_Point1024C4;

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
        v2 = fn_80077B14((struct fn_1_101BC4_Sig_fn_80077B14_fn_80077B14_Arg0 *)arg0);
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
                    v15 = fn_1_1024C4( (const Point1024C4 *)((const Sig_fn_1_1024C4_Point1024C4 *)v4), (const Point1024C4 *)((const Sig_fn_1_1024C4_Point1024C4 *)v51));
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
                    v15 = fn_1_1024C4( (const Point1024C4 *)((const Sig_fn_1_1024C4_Point1024C4 *)v4), (const Point1024C4 *)((const Sig_fn_1_1024C4_Point1024C4 *)v59));
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
    struct fn_1_1024F8_Sig_fn_80077B14_fn_80077B14_Arg0 *mesh;
    u32 unk_4;
} ClothMeshEntry;


void fn_1_1024F8(void) {
    Obj_1_bss_85250 *p = &lbl_1_bss_85250;
    struct fn_1_1024F8_Sig_fn_80077B14_fn_80077B14_Arg0 *mesh;
    u8 *verts;
    s32 sq;
    u32 i;
    u32 j;
    f64 d;

    mesh = ((ClothMeshEntry *)p->unk_10->unk_8)[p->unk_4].mesh;
    if (mesh == NULL) {
        return;
    }
    verts = (u8 *)fn_80077B14( (struct fn_1_101BC4_Sig_fn_80077B14_fn_80077B14_Arg0 *)(struct fn_1_1024F8_Sig_fn_80077B14_fn_80077B14_Arg0 *)(mesh));
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

/* fzgx:begin fn_1_102750 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/cloth.h"

extern void fn_1_105744(void);
extern void fn_1_106DB4(void);
extern void fn_1_9D0EC(u32, u32, void*, void*);
extern void fn_1_103AA8(void);
extern u32 lbl_1_bss_85288[2];
extern void fn_1_103AD4(void);
extern void fn_1_105768(void);
extern void fn_1_9E5B8(void *);
extern struct fn_1_10240C_lbl_801A6410 lbl_801A6410;
extern u32 fn_1_45D0(u32, u32, void *, u32);
extern u32 fn_1_46B4(u32, u32, void *, u32);
extern u32 fn_80008BA8(u32, u32, u32);

typedef struct {
    f32 x, y, z;
} fn_1_102750_Vec;

typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u16 unk_4[6];
    fn_1_102750_Vec unk_10;
    fn_1_102750_Vec unk_1C;
    fn_1_102750_Vec unk_28;
    fn_1_102750_Vec unk_34;
    f32 unk_40;
} fn_1_102750_Node;

typedef struct {
    fn_1_102750_Node *unk_0;
    fn_1_102750_Node *unk_4;
    f32 unk_8;
    u8 pad_C[0xC];
} fn_1_102750_Edge;

typedef struct {
    fn_1_102750_Vec unk_0;
    u8 pad_C[0x34];
} fn_1_102750_Vertex;

typedef struct {
    u8 pad_0[0x8];
    struct Sig_fn_80077B14_fn_80077B14_Arg0 **unk_8;
} fn_1_102750_Table;

/* lbl_1_bss_85250 seen from here: node records of 0x44 bytes at unk_18, edges of 0x18 bytes at unk_20 */
typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    fn_1_102750_Table *unk_10;
    u32 unk_14;
    fn_1_102750_Node *unk_18;
    u32 unk_1C;
    fn_1_102750_Edge *unk_20;
    u32 unk_24;
} fn_1_102750_State;

typedef struct {
    u8 pad_0[0x10];
    fn_1_102750_Vec unk_10;
} fn_1_102750_Camera;

struct Sig_fn_80077B14_fn_80077B14_Arg0;
extern fn_1_102750_Vertex *fn_80077B14(struct Sig_fn_80077B14_fn_80077B14_Arg0 *);
extern fn_1_102750_Camera *camera_get_state_object(void);
extern f32 lbl_8006D118(f32, f32 *);
extern f32 lbl_8006D0B4(f32);

/* retail .rodata 0x77F8-0x789F ahead of this function's constants, so they land at their retail offsets; the
 * function reuses the literal 1.0f (0x7888) */
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_rodata_77F8[36] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFF0000FF, 0x00FF00FF, 0xFF0000FF, 0x00FF00FF, 0x41A00000, 0x42480000, 0x3F000000, 0x3F7FF972, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3E7AD7F2, 0x9ABCAF48, 0xBF800000, 0x00000000, 0x4187999A, 0x00000000, 0x3FFF3333, 0x33333333, 0xBFFF3333, 0x33333333, 0x3FC00000, 0x00000000, 0x3FE00000, 0x00000000, 0x3FE33333, 0x33333333, 0x3F1A36E2, 0xE0000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep_77F8(void) { const u32 *volatile cp; cp = fzgx_pool_rodata_77F8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime_7888(void) { volatile f32 s; s = 1.0f; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_rodata_788C[5] = {0x3F8CCCCD, 0x3F733333, 0x00000000, 0x3F847AE1, 0x47AE147B};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep_788C(void) { const u32 *volatile cp; cp = fzgx_pool_rodata_788C; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

/* Cloth test mode 1 ("buranburan (dangling) mode" in the mode-name table), run by fn_1_10161C's switch on unk_14:
 * moves the nodes of kind 1 with bit 0 clear by their y velocity, which drops 0.0027 a step, pulls together the
 * two nodes of each edge whose squared length passes unk_8, pushes nodes out to 0.55 from the camera, stores each
 * node's displacement this step in unk_34 and copies the positions into the model's vertices */
void fn_1_102750(void) {
    fn_1_102750_State *st = (fn_1_102750_State *)&lbl_1_bss_85250;
    struct Sig_fn_80077B14_fn_80077B14_Arg0 *model;
    fn_1_102750_Vertex *out;
    fn_1_102750_Camera *cam;
    fn_1_102750_Edge *e;
    u32 i;
    u32 j;
    fn_1_102750_Node *n;

    model = st->unk_10->unk_8[st->unk_4 * 2];
    if (model == NULL) {
        return;
    }
    out = fn_80077B14(model);
    for (i = 0, n = st->unk_18; i < st->unk_1C; i++, n++) {
        if (n->unk_1 == 1 && (n->unk_0 & 1) == 0) {
            n->unk_1C = n->unk_10;
            n->unk_10.y += n->unk_34.y - 0.0013611111376020642;
            if (n->unk_10.y < 0.01f) {
                n->unk_10.y = 0.01f;
            }
            n->unk_34.y -= 0.0027222223579883575f;
        }
    }
    for (i = 0, e = st->unk_20; i < st->unk_24; i++, e++) {
        fn_1_102750_Node *a;
        fn_1_102750_Node *b;
        fn_1_102750_Vec delta;
        f32 len;
        fn_1_102750_Vec *dp = &delta;
        f32 y, z, x;
        f32 d;
        a = e->unk_0;
        b = e->unk_4;
        x = a->unk_10.x - b->unk_10.x;
        y = a->unk_10.y - b->unk_10.y;
        z = a->unk_10.z - b->unk_10.z;
        dp->x = x;
        dp->y = y;
        dp->z = z;
        d = x * x;
        d += y * y;
        d += z * z;
        len = d;
        if (len - 0.0001f > e->unk_8) {
            f32 inv, r, s, k, wa, wb;
            inv = lbl_8006D118(len, &len);
            r = lbl_8006D0B4(e->unk_8);
            s = inv * (len - r);
            len = s;
            dp->x *= s;
            dp->y *= s;
            dp->z *= s;
            k = 1.0f / (a->unk_40 + b->unk_40);
            wa = a->unk_40 * k;
            wb = b->unk_40 * k;
            a->unk_10.x -= (f32)(dp->x * wa);
            a->unk_10.y -= (f32)(dp->y * wa);
            a->unk_10.z -= (f32)(dp->z * wa);
            b->unk_10.x += (f32)(dp->x * wb);
            b->unk_10.y += (f32)(dp->y * wb);
            b->unk_10.z += (f32)(dp->z * wb);
        }
    }
    cam = camera_get_state_object();
    for (i = 0, e = st->unk_20; i < st->unk_24; i++, e++) {
        fn_1_102750_Node *a;
        fn_1_102750_Node *b;
        fn_1_102750_Vec v;
        f32 x, y, z, d;
        f32 da, db;
        s32 near;
        a = e->unk_0;
        b = e->unk_4;
        near = 0;
        z = a->unk_10.z - cam->unk_10.z;
        y = a->unk_10.y - cam->unk_10.y;
        x = a->unk_10.x - cam->unk_10.x;
        d = x * x;
        d += y * y;
        d += z * z;
        da = lbl_8006D0B4(d);
        z = b->unk_10.z - cam->unk_10.z;
        /* a compound subtraction here: it gives retail's float registers for this distance */
        y = b->unk_10.y;
        y -= cam->unk_10.y;
        x = b->unk_10.x - cam->unk_10.x;
        d = x * x;
        d += y * y;
        d += z * z;
        db = lbl_8006D0B4(d);
        if (da < 0.55f || db < 0.55f) {
            near = 1;
        }
        if (near) {
            da = 0.55f / da;
            db = 0.55f / db;
            if ((a->unk_0 & 1) == 0 && da > 1.0f) {
                v.x = a->unk_10.x - cam->unk_10.x;
                v.y = a->unk_10.y - cam->unk_10.y;
                v.z = a->unk_10.z - cam->unk_10.z;
                v.x *= da;
                v.y *= da;
                v.z *= da;
                a->unk_10.x = v.x + cam->unk_10.x;
                a->unk_10.y = v.y + cam->unk_10.y;
                a->unk_10.z = v.z + cam->unk_10.z;
            }
            if ((b->unk_0 & 1) == 0 && db > 1.0f) {
                v.x = b->unk_10.x - cam->unk_10.x;
                v.y = b->unk_10.y - cam->unk_10.y;
                v.z = b->unk_10.z - cam->unk_10.z;
                v.x *= db;
                v.y *= db;
                v.z *= db;
                b->unk_10.x = v.x + cam->unk_10.x;
                b->unk_10.y = v.y + cam->unk_10.y;
                b->unk_10.z = v.z + cam->unk_10.z;
            }
        }
    }
    for (i = 0, n = st->unk_18; i < st->unk_1C; i++, n++) {
        n->unk_34.x = n->unk_10.x - n->unk_1C.x;
        n->unk_34.y = n->unk_10.y - n->unk_1C.y;
        n->unk_34.z = n->unk_10.z - n->unk_1C.z;
    }
    for (i = 0, n = st->unk_18; i < st->unk_1C; i++, n++) {
        if (n->unk_1 == 1 && (n->unk_0 & 1) == 0) {
            for (j = 0; j < n->unk_2; j++) {
                out[n->unk_4[j]].unk_0 = n->unk_10;
            }
        }
    }
}
/* fzgx:end fn_1_102750 */

/* fzgx:begin fn_1_102C08 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/cloth.h"

extern void fn_1_105744(void);
extern void fn_1_106DB4(void);
extern void fn_1_9D0EC(u32, u32, void*, void*);
extern void fn_1_103AA8(void);
extern u32 lbl_1_bss_85288[2];
extern void fn_1_103AD4(void);
extern void fn_1_105768(void);
extern void fn_1_9E5B8(void *);
extern struct fn_1_10240C_lbl_801A6410 lbl_801A6410;
extern u32 fn_1_45D0(u32, u32, void *, u32);
extern u32 fn_1_46B4(u32, u32, void *, u32);
extern u32 fn_80008BA8(u32, u32, u32);

typedef struct {
    f32 x, y, z;
} fn_1_102C08_Vec;

typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u16 unk_4[6];
    fn_1_102C08_Vec unk_10;
    fn_1_102C08_Vec unk_1C;
    fn_1_102C08_Vec unk_28;
    fn_1_102C08_Vec unk_34;
    f32 unk_40;
} fn_1_102C08_Node;

typedef struct {
    fn_1_102C08_Node *unk_0;
    fn_1_102C08_Node *unk_4;
    f32 unk_8;
    u8 pad_C[0xC];
} fn_1_102C08_Edge;

typedef struct {
    fn_1_102C08_Vec unk_0;
    u8 pad_C[0x34];
} fn_1_102C08_Vertex;

typedef struct {
    u8 pad_0[0x8];
    struct Sig_fn_80077B14_fn_80077B14_Arg0 **unk_8;
} fn_1_102C08_Table;

/* lbl_1_bss_85250 seen from here: node records of 0x44 bytes at unk_18, edges of 0x18 bytes at unk_20 */
typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    fn_1_102C08_Table *unk_10;
    u32 unk_14;
    fn_1_102C08_Node *unk_18;
    u32 unk_1C;
    fn_1_102C08_Edge *unk_20;
    u32 unk_24;
} fn_1_102C08_State;

struct Sig_fn_80077B14_fn_80077B14_Arg0;
extern fn_1_102C08_Vertex *fn_80077B14(struct Sig_fn_80077B14_fn_80077B14_Arg0 *);
extern f32 lbl_8006D118(f32, f32 *);
extern f32 lbl_8006D0B4(f32);

extern f32 lbl_1_bss_BF0[32];
extern void lbl_8006D758(void);
extern void lbl_8006E0B4(f32, f32, f32);
extern void mathutil_mtxA_rotate_y(s32);
extern void mathutil_mtxA_rotate_z(s32);
extern void lbl_8006DB74(void *);
extern void lbl_8006DFC4(void *);
extern void lbl_8006E1B0(fn_1_102C08_Vec *, fn_1_102C08_Vec *);

/* retail .rodata 0x77F8-0x78B7 ahead of this function's constants, so they land at their retail offsets; the
 * function reuses the literals 0.0f (0x784C) and 1.0f (0x7888) and fn_1_102750's constants (0x78A0-0x78B4) */
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_rodata_77F8[21] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFF0000FF, 0x00FF00FF, 0xFF0000FF, 0x00FF00FF, 0x41A00000, 0x42480000, 0x3F000000, 0x3F7FF972, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3E7AD7F2, 0x9ABCAF48, 0xBF800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep_77F8(void) { const u32 *volatile cp; cp = fzgx_pool_rodata_77F8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime_784C(void) { volatile f32 s; s = 0.0f; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_rodata_7850[14] = {0x4187999A, 0x00000000, 0x3FFF3333, 0x33333333, 0xBFFF3333, 0x33333333, 0x3FC00000, 0x00000000, 0x3FE00000, 0x00000000, 0x3FE33333, 0x33333333, 0x3F1A36E2, 0xE0000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep_7850(void) { const u32 *volatile cp; cp = fzgx_pool_rodata_7850; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime_7888(void) { volatile f32 s; s = 1.0f; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_rodata_788C[5] = {0x3F8CCCCD, 0x3F733333, 0x00000000, 0x3F847AE1, 0x47AE147B};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep_788C(void) { const u32 *volatile cp; cp = fzgx_pool_rodata_788C; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime_78A0(void) { volatile f64 d; volatile f32 s; d = 0.0013611111376020642; s = 0.01f; s = 0.0027222223579883575f; s = 0.0001f; s = 0.55f; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

/* Cloth test mode 2 ("guruguru (spinning) mode (PAD1)" in the mode-name table), run by fn_1_10161C's switch on
 * unk_14: builds a matrix that turns by port 1's axis values (lbl_1_bss_BF0 port 1, values 2 and 3) between the
 * calls with (16.4, 0.75, 0) and (-16.4, -0.75, 0), steps the nodes of kind 1 with bit 0 clear as mode 1 does,
 * places every other node at its unk_28 point through that matrix, applies the edges, stores each node's
 * displacement this step in unk_34 and copies all positions into the model's vertices */
void fn_1_102C08(void) {
    fn_1_102C08_State *st = (fn_1_102C08_State *)&lbl_1_bss_85250;
    struct Sig_fn_80077B14_fn_80077B14_Arg0 *model;
    fn_1_102C08_Vertex *out;
    fn_1_102C08_Edge *e;
    u32 i;
    u32 j;
    fn_1_102C08_Node *n;
    f32 mtx[3][4];

    lbl_8006D758();
    lbl_8006E0B4(16.4f, 0.75f, 0.0f);
    mathutil_mtxA_rotate_y(32768.0f * lbl_1_bss_BF0[10]);
    mathutil_mtxA_rotate_z(32768.0f * lbl_1_bss_BF0[11]);
    lbl_8006E0B4(-16.4f, -0.75f, 0.0f);
    lbl_8006DB74(mtx);
    model = st->unk_10->unk_8[st->unk_4 * 2];
    if (model == NULL) {
        return;
    }
    out = fn_80077B14(model);
    for (i = 0, n = st->unk_18; i < st->unk_1C; i++, n++) {
        if (n->unk_1 == 1 && (n->unk_0 & 1) == 0) {
            n->unk_1C = n->unk_10;
            n->unk_10.y += n->unk_34.y - 0.0013611111376020642;
            if (n->unk_10.y < 0.01f) {
                n->unk_10.y = 0.01f;
            }
            n->unk_34.y -= 0.0027222223579883575f;
        }
    }
    for (i = 0, n = st->unk_18; i < st->unk_1C; i++, n++) {
        if (n->unk_1 != 1 || (n->unk_0 & 1) != 0) {
            lbl_8006D758();
            lbl_8006DFC4(mtx);
            lbl_8006E1B0(&n->unk_28, &n->unk_10);
        }
    }
    for (i = 0, e = st->unk_20; i < st->unk_24; i++, e++) {
        fn_1_102C08_Node *a;
        fn_1_102C08_Node *b;
        fn_1_102C08_Vec delta;
        f32 len;
        fn_1_102C08_Vec *dp = &delta;
        f32 y, z, x;
        f32 d;
        a = e->unk_0;
        b = e->unk_4;
        x = a->unk_10.x - b->unk_10.x;
        y = a->unk_10.y - b->unk_10.y;
        z = a->unk_10.z - b->unk_10.z;
        dp->x = x;
        dp->y = y;
        dp->z = z;
        d = x * x;
        d += y * y;
        d += z * z;
        len = d;
        if (len - 0.0001f > e->unk_8) {
            f32 inv, r, s, k, wa, wb;
            inv = lbl_8006D118(len, &len);
            r = lbl_8006D0B4(e->unk_8);
            s = inv * (len - r);
            len = s;
            dp->x *= s;
            dp->y *= s;
            dp->z *= s;
            k = 1.0f / (a->unk_40 + b->unk_40);
            wa = a->unk_40 * k;
            wb = b->unk_40 * k;
            a->unk_10.x -= (f32)(dp->x * wa);
            a->unk_10.y -= (f32)(dp->y * wa);
            a->unk_10.z -= (f32)(dp->z * wa);
            b->unk_10.x += (f32)(dp->x * wb);
            b->unk_10.y += (f32)(dp->y * wb);
            b->unk_10.z += (f32)(dp->z * wb);
        }
    }
    for (i = 0, n = st->unk_18; i < st->unk_1C; i++, n++) {
        n->unk_34.x = n->unk_10.x - n->unk_1C.x;
        n->unk_34.y = n->unk_10.y - n->unk_1C.y;
        n->unk_34.z = n->unk_10.z - n->unk_1C.z;
    }
    for (i = 0, n = st->unk_18; i < st->unk_1C; i++, n++) {
        for (j = 0; j < n->unk_2; j++) {
            out[n->unk_4[j]].unk_0 = n->unk_10;
        }
    }
}
/* fzgx:end fn_1_102C08 */

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

/* fzgx:begin fn_1_1050D0 */
typedef struct { f32 x, y, z; } Vec;

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
                mathutil_mtxA_rotate_x((s16)((((*((u32 *)&lbl_801A66A0)) % 300) << 16) / 300));
                if (v3) lbl_8006E0B4(p_lbl_1_rodata_78D0->unk_10C, p_lbl_1_rodata_78D0->unk_18, p_lbl_1_rodata_78D0->unk_18);
                fn_80072558();
                fn_1_556B8((void *)*(u32 *)(p_lbl_1_bss_38460->unk_8->unk_8 + 8));
            }
            lbl_8006DBE4();
            mathutil_mtxA_rotate_x((s16)(-(((*((u32 *)&lbl_801A66A0)) % 300) << 16) / 300));
            if (v3) lbl_8006E0B4(p_lbl_1_rodata_78D0->unk_10C, p_lbl_1_rodata_78D0->unk_18, p_lbl_1_rodata_78D0->unk_18);
            fn_80072558();
            fn_1_556B8((void *)*(u32 *)(p_lbl_1_bss_38460->unk_8->unk_8 + 16));
            lbl_8006DBE4();
            mathutil_mtxA_rotate_x((s16)(-(((*((u32 *)&lbl_801A66A0)) % 100) << 16) / 100));
            if (v3) lbl_8006E0B4(p_lbl_1_rodata_78D0->unk_10C, p_lbl_1_rodata_78D0->unk_18, p_lbl_1_rodata_78D0->unk_18);
            fn_80072558();
            fn_1_556B8((void *)*(u32 *)(p_lbl_1_bss_38460->unk_8->unk_8 + 24));
            lbl_8006DBE4();
            mathutil_mtxA_rotate_x((s16)((((*((u32 *)&lbl_801A66A0)) % 60) << 16) / 60));
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

/* fzgx:begin fn_1_10688C pool noprologue */
#include "types.h"

typedef struct {
    u32 dummy[8];
} GXTexObj_10688C;

typedef struct {
    u8 pad_0[0x8];
    GXTexObj_10688C *obj;
    u8 pad_C[0x1];
    u8 kind;
    u8 pad_E[0x12];
} ClothTexEntry;

typedef struct {
    u8 pad_0[0x18];
    u16 count;
    u8 pad_1A[0x26];
    ClothTexEntry entries[1];
} ClothTexSet;

typedef struct {
    u8 pad_0[0x30];
    ClothTexSet *set0;
    u8 pad_34[0x4];
    ClothTexSet *set1;
} ClothModel;

typedef struct {
    u8 pad_0[0x8];
    ClothModel *model;
} ClothModelHolder;

typedef struct {
    u8 pad_0[0x8];
    ClothModelHolder *holder;
} ClothBss38460;

typedef struct {
    u8 pad_0[0xFC];
    void *buffers[2];
    u8 pad_104[0x1C4 - 0x104];
    char file[0x30];
    char archive[0x10];
    char fmt[0x1C];
    char missing[0xC];
    char panic[0x10];
    char heap_used[0x24];
    char buf_used[1];
} ClothData;

typedef struct {
    void *work;
    void *heap;
    u8 pad_8[0x240];
    u32 ready;
    u32 sizes[218];
    void *data[210];
    s32 archive_id;
    u32 max_size;
    u32 tex_size;
    u8 sel;
    u8 tex_count;
    u8 pad_90A[0x2];
    GXTexObj_10688C *tex[1];
} ClothBss;

typedef struct {
    u8 buf[0x5C];
} ClothFile;

extern ClothBss lbl_1_bss_85280;
extern ClothBss38460 lbl_1_bss_38460;
extern u32 lbl_801A6410;

extern s32 fn_1_465D0(char *, s32);
extern void fn_1_451E4(void);
extern void fn_1_D3214(void);
extern s32 fn_1_467F4(void);
extern s32 fn_1_46C70(char *);
extern int fn_1_45730(char *, ClothFile *);
extern u32 fn_1_45B2C(ClothFile *);
extern void *fn_1_45B68(ClothFile *);
extern void fn_1_45850(ClothFile *);
extern void *fn_1_45D0(u32, u32, char *, int);
extern void *fn_1_4630(u32, u32, char *, int);
extern int sprintf(char *, const char *, ...);
extern void OSReport(const char *, ...);
extern void OSPanic(const char *, int, const char *, ...);
extern u32 GXGetTexBufferSize(u16, u16, u32, u8, u8);
extern void GXInitTexObj(GXTexObj_10688C *, void *, u16, u16, int, int, int, u8);

/* retail .bss cluster at lbl_1_bss_85280: one TU object per field */
void *fzgx_obj_lbl_1_bss_85280;
void *fzgx_obj_lbl_1_bss_85284;
u8 fzgx_obj_lbl_1_bss_85288[0x240];
u32 fzgx_obj_lbl_1_bss_854C8;
u32 fzgx_obj_lbl_1_bss_854CC[218];
void *fzgx_obj_lbl_1_bss_85834[210];
s32 fzgx_obj_lbl_1_bss_85B7C;
u32 fzgx_obj_lbl_1_bss_85B80;
u32 fzgx_obj_lbl_1_bss_85B84;
u8 fzgx_obj_lbl_1_bss_85B88;
u8 fzgx_obj_lbl_1_bss_85B89;
GXTexObj_10688C *fzgx_obj_lbl_1_bss_85B8C[1];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout_lbl_1_bss_85280(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .bss objects in retail order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_85280;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_85284;
    s = *(u8 *)fzgx_obj_lbl_1_bss_85288;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_854C8;
    s = *(u8 *)fzgx_obj_lbl_1_bss_854CC;
    s = *(u8 *)fzgx_obj_lbl_1_bss_85834;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_85B7C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_85B80;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_85B84;
    s = fzgx_obj_lbl_1_bss_85B88;
    s = fzgx_obj_lbl_1_bss_85B89;
    s = *(u8 *)fzgx_obj_lbl_1_bss_85B8C;
}
#pragma section code_type ".text"

#pragma opt_propagation off
static inline void InitClothTexture(GXTexObj_10688C **textures, void **buffers, ClothTexEntry *entries) {
    u8 index = fzgx_obj_lbl_1_bss_85B89;
    GXTexObj_10688C *obj = entries->obj;
    u32 selected = fzgx_obj_lbl_1_bss_85B88;
    fzgx_obj_lbl_1_bss_85B89 = index + 1;
    textures[index] = obj;
    GXInitTexObj(entries->obj, buffers[selected], 0x80, 0x80, 6, 0, 0, 0);
}

#pragma opt_propagation on
#pragma opt_common_subs on
#pragma opt_lifetimes off
extern u8 lbl_1_data_3F188__fzgx_offset_0[];
extern u8 lbl_1_data_3F194__fzgx_offset_0[];
extern u8 lbl_1_data_3F19C__fzgx_offset_0[];
extern u8 lbl_1_data_3F1A8__fzgx_offset_0[];
extern u8 lbl_1_data_3F1B0__fzgx_offset_0[];
extern u8 lbl_1_data_3F1BC__fzgx_offset_0[];
extern u8 lbl_1_data_3F1C4__fzgx_offset_0[];
extern u8 lbl_1_data_3F1CC__fzgx_offset_0[];
extern u8 lbl_1_data_3F1F8__fzgx_offset_0[];
extern u8 lbl_1_data_3F200__fzgx_offset_0[];
extern u8 lbl_1_data_3F20C__fzgx_offset_0[];
extern u8 lbl_1_data_3F218__fzgx_offset_0[];
extern u8 lbl_1_data_3F224__fzgx_offset_0[];
extern u8 lbl_1_data_3F230__fzgx_offset_0[];
extern u8 lbl_1_data_3F238__fzgx_offset_0[];
static u32 fzgx_pool_data_lbl_1_data_3F188[63] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4F564552, 0x54414B45, 0x0, 0x4A554D50, 0x0, 0x454E454D, 0x59484954, 0x0,
    0x57414C4C, 0x48495400, 0x53494445, 0x42595349, 0x44450000, 0x53544152, 0x54000000, 0x474F414C,
    0x0, 0x4C415000, (u32)lbl_1_data_3F188__fzgx_offset_0, (u32)lbl_1_data_3F194__fzgx_offset_0, (u32)lbl_1_data_3F19C__fzgx_offset_0, (u32)lbl_1_data_3F1A8__fzgx_offset_0, (u32)lbl_1_data_3F1B0__fzgx_offset_0, (u32)lbl_1_data_3F1BC__fzgx_offset_0,
    (u32)lbl_1_data_3F1C4__fzgx_offset_0, (u32)lbl_1_data_3F1CC__fzgx_offset_0, 0x3, 0x0, 0x5F4E4F49, 0x53450000, 0x47415445, 0x57414B55,
    0x30310000, 0x47415445, 0x57414B55, 0x30320000, 0x47415445, 0x50414E45, 0x4C303100, 0x47415445,
    0x50414E45, 0x4C303200, 0x464C4147, 0x0, 0x52455041, 0x4952504F, 0x494E5400, 0x2,
    (u32)lbl_1_data_3F1F8__fzgx_offset_0, 0x0, (u32)lbl_1_data_3F200__fzgx_offset_0, 0x0, (u32)lbl_1_data_3F20C__fzgx_offset_0, 0x0, (u32)lbl_1_data_3F218__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_3F224__fzgx_offset_0, 0x0, (u32)lbl_1_data_3F230__fzgx_offset_0, 0x0, (u32)lbl_1_data_3F238__fzgx_offset_0, 0x3, 0x0
};
static u32 fzgx_pool_data_lbl_1_data_3F284[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0x0
};
static u32 fzgx_pool_data_lbl_1_data_3F28C[48] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x10302, 0x3F800000, 0x0, 0x0, 0x40501, 0x0, 0x3F800000, 0x0,
    0x20604, 0x0, 0x0, 0x3F800000, 0x4060705, 0xBF800000, 0x0, 0x0,
    0x2030706, 0x0, 0xBF800000, 0x0, 0x1050703, 0x0, 0x0, 0xBF800000,
    0x41B26666, 0x40F9999A, 0x4169999A, 0x41B26666, 0x40F9999A, 0xC0D66666, 0x41B26666, 0xC0E00000,  /* fzgx-allow: A1 retail data bytes */
    0x4169999A, 0x41B26666, 0xC0E00000, 0xC0D66666, 0xC1B26666, 0x40F9999A, 0x4169999A, 0xC1B26666,  /* fzgx-allow: A1 retail data bytes */
    0x40F9999A, 0xC0D66666, 0xC1B26666, 0xC0E00000, 0x4169999A, 0xC1B26666, 0xC0E00000, 0xC0D66666  /* fzgx-allow: A1 retail data bytes */
};
static u32 fzgx_pool_data_lbl_1_data_3F34C[3] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x62675F63, 0x6F6D6D6F, 0x6E2E6300
};
static u32 fzgx_pool_data_lbl_1_data_3F358[9] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x53504F54, 0x204C4947, 0x48542044, 0x49535020, 0x4F564552, 0x286C656E, 0x6774682F, 0x77696474,
    0x68290000
};
static u32 fzgx_pool_data_lbl_1_data_3F188_1F4[4] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x6A706567, 0x2F636F6D, 0x706F2E61, 0x72630000
};
static u32 fzgx_pool_data_lbl_1_data_3F188_204[7] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x6A706567, 0x2F636F6D, 0x706F2F63, 0x6F6D706F, 0x25303364, 0x2E6A7067, 0x0
};
static u32 fzgx_pool_data_lbl_1_data_3F188_220[3] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x66696C65, 0x20272573, 0x27200000
};
static u32 fzgx_pool_data_lbl_1_data_3F188_22C[4] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x6973206E, 0x6F742069, 0x6E204152, 0x414D0000
};
static u32 fzgx_pool_data_lbl_1_data_3F188_23C[9] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x616C7265, 0x61647920, 0x616C6C6F, 0x63617465, 0x64206A70, 0x65675F64, 0x65636F64, 0x655F7261,
    0x6D210A00
};
static u32 fzgx_pool_data_lbl_1_data_3F188_260[8] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x616C7265, 0x61647920, 0x616C6C6F, 0x63617465, 0x64206A70, 0x65675F62, 0x75666621, 0xA000000
};
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_1_data_3F188(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .data objects in retail order */
    s = *(u8 *)fzgx_pool_data_lbl_1_data_3F188;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_3F284;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_3F28C;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_3F34C;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_3F358;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_3F188_1F4;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_3F188_204;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_3F188_220;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_3F188_22C;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_3F188_23C;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_3F188_260;
}
#pragma section code_type ".text"

void fn_1_10688C(void) {
    void **datas;
    u32 *sizes;
    void **bufs;
    s32 j;
    ClothTexSet *set;
    s16 k;
    s16 i;
    ClothTexEntry *entries;
    u32 size;
    ClothTexSet *sets[2];
    char name[0x80];
    ClothFile file;

    
    fn_1_465D0(((char *)(((u8 *)fzgx_pool_data_lbl_1_data_3F188_1F4))), 3);
    while (fn_1_467F4() != 0) {
        fn_1_451E4();
        fn_1_D3214();
    }
    fzgx_obj_lbl_1_bss_85B7C = fn_1_46C70(((char *)(((u8 *)fzgx_pool_data_lbl_1_data_3F188_1F4))));
    sizes = fzgx_obj_lbl_1_bss_854CC;
    datas = fzgx_obj_lbl_1_bss_85834;
    fzgx_obj_lbl_1_bss_85B80 = 0;
    for (i = 0; i < 210; i++) {
        sprintf(name, ((char *)(((u8 *)fzgx_pool_data_lbl_1_data_3F188_204))), i + 1);
        if (fn_1_45730(name, &file) == 0) {
            OSReport(((char *)(((u8 *)fzgx_pool_data_lbl_1_data_3F188_220))), name);
            OSPanic(((char *)(((u8 *)fzgx_pool_data_lbl_1_data_3F34C))), 0x83A, ((char *)(((u8 *)fzgx_pool_data_lbl_1_data_3F188_22C))));
        }
        sizes[i] = fn_1_45B2C(&file);
        datas[i] = fn_1_45B68(&file);
        fn_1_45850(&file);
        if (fzgx_obj_lbl_1_bss_85B80 < sizes[i]) {
            fzgx_obj_lbl_1_bss_85B80 = sizes[i];
        }
    }
    if (fzgx_obj_lbl_1_bss_85284 != NULL) {
        OSReport(((char *)(((u8 *)fzgx_pool_data_lbl_1_data_3F188_23C))));
    } else {
        fzgx_obj_lbl_1_bss_85284 = fn_1_45D0(lbl_801A6410, fzgx_obj_lbl_1_bss_85B80, ((char *)(((u8 *)fzgx_pool_data_lbl_1_data_3F34C))), 0x847);
    }
    size = GXGetTexBufferSize(0x80, 0x80, 6, 0, 0);
    fzgx_obj_lbl_1_bss_85B84 = size;
    if (((void * *)(((u8 *)fzgx_pool_data_lbl_1_data_3F284)))[0] != NULL || (bufs = ((void * *)(((u8 *)fzgx_pool_data_lbl_1_data_3F284))))[1] != NULL || fzgx_obj_lbl_1_bss_85280 != NULL) {
        OSReport(((char *)(((u8 *)fzgx_pool_data_lbl_1_data_3F188_260))));
    } else {
        ((void * *)(((u8 *)fzgx_pool_data_lbl_1_data_3F284)))[0] = fn_1_4630(lbl_801A6410, size, ((char *)(((u8 *)fzgx_pool_data_lbl_1_data_3F34C))), 0x84F);
        bufs[1] = fn_1_4630(lbl_801A6410, fzgx_obj_lbl_1_bss_85B84, ((char *)(((u8 *)fzgx_pool_data_lbl_1_data_3F34C))), 0x850);
        fzgx_obj_lbl_1_bss_85280 = fn_1_4630(lbl_801A6410, 0x4000, ((char *)(((u8 *)fzgx_pool_data_lbl_1_data_3F34C))), 0x851);
    }
    fzgx_obj_lbl_1_bss_85B88 = 0;
    fzgx_obj_lbl_1_bss_85B89 = 0;
    fzgx_obj_lbl_1_bss_854C8 = 1;
    sets[0] = lbl_1_bss_38460.holder->model->set0;
    sets[1] = lbl_1_bss_38460.holder->model->set1;
    for (j = 0; j < 2; j++) {
        set = sets[j];
        entries = set->entries;
        for (k = 0; k < set->count; entries++, k++) {
            if (entries->kind == 1) {
                fzgx_obj_lbl_1_bss_85B8C[fzgx_obj_lbl_1_bss_85B89++] = entries->obj;
                GXInitTexObj(entries->obj, ((void **)fzgx_pool_data_lbl_1_data_3F284)[fzgx_obj_lbl_1_bss_85B88], 0x80, 0x80, 6, 0, 0, 0);
            }
        }
    }
}
/* fzgx:end fn_1_10688C */

/* fzgx:begin fn_1_106CAC */
typedef struct Sig_fn_8003C1A4_JpegDec Sig_fn_8003C1A4_JpegDec;
typedef struct {
    Obj_1_bss_85280 base;
    u8 pad_8[0x240];
    s32 unk_248;
    u8 pad_24C[0x6BC];
    u8 unk_908;
} BgJpegState;

s32 fn_1_106CAC(void) {
    BgJpegState *p = (BgJpegState *)&lbl_1_bss_85280;
    if ((s32)p->unk_248 == 2) {
        return 0;
    }
    fn_1_151AF0( (void *)((u8 *)p->base.unk_4), 0,
        (void *)(&lbl_1_data_3F284.unk_0)[p->unk_908], 0, 0, (void *)((Sig_fn_8003C1A4_JpegDec *)p->base.unk_0));
    p->unk_908 = 1 - p->unk_908;
    p->unk_248 = 1;
    return 0;
}
/* fzgx:end fn_1_106CAC */
