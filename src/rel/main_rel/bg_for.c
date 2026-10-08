#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_for.h"
#include "game/main_rel/bg_for_types.h"

extern void OSPanic(const char *file, int line, const char *msg, ...);
extern void lbl_8006DAEC(void);
extern void lbl_8006DD14(void *, void *);
extern void fn_1_A7024(f32, f32, f32, f32);
extern void fn_8006F1F0(void *, void *, void *);
extern void lbl_8006DB74(void *);
extern void lbl_8006DCDC(void);
extern void lbl_8006DB30(void);
extern void fn_1_E1408(void *, void *);

/* fzgx:begin fn_1_DCBF4 */
#pragma opt_dead_assignments off
s32 fn_1_DCBF4(s32 value, s32 data) {
    Obj_1_data_2A7E0_At3C *obj;
    Obj_1_data_2A7E0_At3C *entry;
    u32 n;

    obj = lbl_1_data_2A7E0.unk_3C;
    switch (value) {
    case 0:
        obj->unk_1588 = data;
        break;
    case 1:
        entry = (Obj_1_data_2A7E0_At3C *)((u8 *)obj + obj->unk_0 * 0xAC);
        entry->unk_C |= 0x40000000;
        entry = (Obj_1_data_2A7E0_At3C *)((u8 *)obj + obj->unk_0 * 0xAC);
        entry->unk_C |= 0x10000000;
        n = obj->unk_0;
        entry = (Obj_1_data_2A7E0_At3C *)((u8 *)obj + n * 0xAC);
        entry->unk_4 = data;
        obj->unk_0 = obj->unk_0 + 1;
        if ((s32)obj->unk_0 >= 0x20) {
            OSPanic((const char *)lbl_1_data_3DC78, 0x21D, (const char *)&lbl_1_data_3DC84);
        }
        break;
    case 2:
        entry = (Obj_1_data_2A7E0_At3C *)((u8 *)obj + obj->unk_0 * 0xAC);
        entry->unk_C |= 0x40000000;
        entry = (Obj_1_data_2A7E0_At3C *)((u8 *)obj + obj->unk_0 * 0xAC);
        entry->unk_C |= 0x20000000;
        n = obj->unk_0;
        entry = (Obj_1_data_2A7E0_At3C *)((u8 *)obj + n * 0xAC);
        entry->unk_4 = data;
        obj->unk_0 = obj->unk_0 + 1;
        if ((s32)obj->unk_0 >= 0x20) {
            OSPanic((const char *)lbl_1_data_3DC78, 0x224, (const char *)&lbl_1_data_3DC84);
        }
        break;
    case 3:
        entry = (Obj_1_data_2A7E0_At3C *)((u8 *)obj + obj->unk_0 * 0xAC);
        entry->unk_C |= 0x40000000;
        entry = (Obj_1_data_2A7E0_At3C *)((u8 *)obj + obj->unk_0 * 0xAC);
        entry->unk_C |= 0x10000000;
        entry = (Obj_1_data_2A7E0_At3C *)((u8 *)obj + obj->unk_0 * 0xAC);
        entry->unk_C |= 0x08000000;
        n = obj->unk_0;
        entry = (Obj_1_data_2A7E0_At3C *)((u8 *)obj + n * 0xAC);
        entry->unk_4 = data;
        obj->unk_0 = obj->unk_0 + 1;
        if ((s32)obj->unk_0 >= 0x20) {
            OSPanic((const char *)lbl_1_data_3DC78, 0x22C, (const char *)&lbl_1_data_3DC84);
        }
        break;
    case 4:
        entry = (Obj_1_data_2A7E0_At3C *)((u8 *)obj + obj->unk_0 * 0xAC);
        entry->unk_C |= 0x40000000;
        entry = (Obj_1_data_2A7E0_At3C *)((u8 *)obj + obj->unk_0 * 0xAC);
        entry->unk_C |= 0x20000000;
        entry = (Obj_1_data_2A7E0_At3C *)((u8 *)obj + obj->unk_0 * 0xAC);
        entry->unk_C |= 0x08000000;
        n = obj->unk_0;
        entry = (Obj_1_data_2A7E0_At3C *)((u8 *)obj + n * 0xAC);
        entry->unk_4 = data;
        obj->unk_0 = obj->unk_0 + 1;
        if ((s32)obj->unk_0 >= 0x20) {
            OSPanic((const char *)lbl_1_data_3DC78, 0x234, (const char *)&lbl_1_data_3DC84);
        }
        break;
    }
    return 1;
}
#pragma opt_dead_assignments reset
/* fzgx:end fn_1_DCBF4 */

/* fzgx:begin fn_1_DCE60 */
struct fn_1_DCE60_Arg0 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
    u32 unk_2C;
    f32 unk_30;
    f32 unk_34;
    f32 unk_38;
    f32 unk_3C;
};
struct fn_1_DCE60_Copy24 { u32 a[6]; };
struct fn_1_DCE60_Copy12 { u32 a[3]; };

#pragma opt_propagation off
f32 fn_1_DCE60(struct fn_1_DCE60_Arg0 *arg0, f32 arg1) {
    u32 v0;
    u32 v4;
    f32 v3;
    f32 v2;
    f32 v1;

    v4 = lbl_1_rodata_6750.unk_0;
    v0 = lbl_1_rodata_6750.unk_4;
    v1 = lbl_1_rodata_6750.unk_24;
    arg0->unk_0 = v4;
    v2 = lbl_1_rodata_6750.unk_28;
    arg0->unk_4 = v0;
    v3 = lbl_1_rodata_6750.unk_2C;
    arg0->unk_8 = lbl_1_rodata_6750.unk_8;
    *(struct fn_1_DCE60_Copy12 *)((u8 *)(u32)arg0 + 24) = *(struct fn_1_DCE60_Copy12 *)((u8 *)&lbl_1_rodata_6750 + 12);
    *(struct fn_1_DCE60_Copy12 *)((u8 *)(u32)arg0 + 36) = *(struct fn_1_DCE60_Copy12 *)((u8 *)&lbl_1_rodata_6750 + 24);
    arg0->unk_30 = v1;
    arg0->unk_34 = arg1;
    arg0->unk_38 = v2;
    arg0->unk_3C = v3;
    return arg1;
}
#pragma opt_propagation reset
/* fzgx:end fn_1_DCE60 */

/* fzgx:begin fn_1_DCED0 */
typedef struct fn_1_DCED0_Vec3 {
    u32 x;
    u32 y;
    u32 z;
} fn_1_DCED0_Vec3;

typedef struct BgForObject {
    fn_1_DCED0_Vec3 value00;
    fn_1_DCED0_Vec3 value0c;
    u8 unk18[0xc];
    u32 value24;
    u8 unk28[0x8];
    f32 value30;
    f32 value34;
    f32 value38;
    f32 value3c;
    u8 unk40[0x30];
    u8 unk70[1];
} BgForObject;

void fn_1_DCED0(BgForObject *object) {
    lbl_8006DAEC();
    object->value0c = object->value00;
    lbl_8006DD14(&object->unk70, &object->unk40);
    fn_1_A7024(object->value30, object->value34, object->value38, object->value3c);
    fn_8006F1F0(object, &object->value24, &object->unk18);
    lbl_8006DB74(&object->unk70);
    lbl_8006DCDC();
    lbl_8006DB30();
}
/* fzgx:end fn_1_DCED0 */

/* fzgx:begin fn_1_DCF54 */
void fn_1_DCF54(fn_1_DCF54_Vec3 *a, fn_1_DCF54_Vec3 *b, fn_1_DCF54_Vec3 *c) {
    lbl_1_bss_7ADE8.a = *a;
    lbl_1_bss_7ADE8.b = *b;
    lbl_1_bss_7ADE8.c = *c;
}
/* fzgx:end fn_1_DCF54 */

/* fzgx:begin fn_1_DCFA4 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_for.h"
#include "game/main_rel/bg_for_types.h"
#include "psvec.h"

#pragma fp_contract on

extern u8 lbl_1_rodata_6780[];
extern void fn_80008BA8(void *, const void *, u32);
extern void fn_1_57714(u8);
extern void lbl_8006D758(void);
extern void lbl_8006E1B0(void *, void *);
extern void lbl_8006DCA4(void);
extern void fn_80072558(void);
extern void fn_1_57810(u32, void *, void *);
extern void lbl_8006D784(void *);
extern void lbl_8006DBAC(void *);
extern void lbl_8006DFE8(void *);
extern void fn_1_DDF80(void *, void *, void *, void *, f32, f32);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern void fn_1_56298(f32, f32, f32, f32);
extern f32 lbl_8006D0B4(f32);
extern void fn_8006EE70(const void *, s16 *);
extern void mathutil_mtxA_rotate_z(s32);
extern void mathutil_mtxA_rotate_y(s32);
extern void mathutil_mtxA_rotate_x(s32);
extern void lbl_8006E15C(f32, f32, f32);
extern void fn_1_556B8(void *);
extern f64 fabs(f64);

typedef struct DCFA4Vec { f32 x,y,z; } DCFA4Vec;
typedef struct DCFA4Mtx { f32 m[3][4]; } DCFA4Mtx;
static inline void matrix_translation(DCFA4Mtx *m) {
    f32 x, y, z;
    u32 locked_cache_base = 0xE0000000;
    x = *(volatile f32 *)(locked_cache_base + 0xC); /* volatile: locked-cache current matrix */
    y = *(volatile f32 *)(locked_cache_base + 0x1C); /* volatile: locked-cache current matrix */
    z = *(volatile f32 *)(locked_cache_base + 0x2C); /* volatile: locked-cache current matrix */
    m->m[0][3] = x;
    m->m[1][3] = y;
    m->m[2][3] = z;
}
static inline void draw_color(u8 *p, u32 first) {
    f32 a, b;
    if (first) {
        a = *(f32 *)(p+0x28);
        b = *(f32 *)(p+0x20);
        fn_1_56298(a,b,b,a);
    } else {
        a = *(f32 *)(p+0x20);
        b = *(f32 *)(p+0x28);
        fn_1_56298(a,b,a,b);
    }
}

static inline void draw_vec(DCFA4Vec *v, s16 *angles, u8 *pool) {
    f32 x;
    f32 y;
    f32 len;
    f32 z;
    f32 scale;
    f32 max;
    f32 min;
    x = v->x;
    y = v->y;
    len = x*x;
    z = v->z;
    len = __fmadds(y, y, len);
    len = __fmadds(z, z, len);
    len = lbl_8006D0B4(len);
    if (!(__fabs(len) < *(f64 *)(pool + 0x18))) {
        fn_8006EE70(v, angles);
        mathutil_mtxA_rotate_z(angles[2]);
        mathutil_mtxA_rotate_y(angles[1]);
        mathutil_mtxA_rotate_x(angles[0]);
        max = *(f32 *)(pool+0x24);
        min = *(f32 *)(pool+0x20);
        scale = max * len;
        scale = scale < min ? min : scale > max ? max : scale;
        lbl_8006E15C(*(f32 *)(pool+0x28), *(f32 *)(pool+0x28), scale);
        fn_80072558();
        fn_1_556B8(*(void **)(lbl_1_bss_38454->unk_8 + 0x38));
    }
}

void fn_1_DCFA4(u32 arg0, f32 arg1) {
    u8 *p_lbl_1_rodata_6780;
    u32 v1;
    f32 v2;
    u32 v3;
    u32 v4;
    u64 flags;
    u32 v0;
    DCFA4Mtx m1;
    DCFA4Mtx m2;
    DCFA4Vec screen2;
    DCFA4Vec screen1;
    DCFA4Vec loc_74;
    DCFA4Vec delta1;
    DCFA4Vec delta2;
    DCFA4Vec out2;
    DCFA4Vec out1;
    DCFA4Vec out4;
    DCFA4Vec out3;
    s16 angles1[3];
    s16 angles2[3];
    s16 angles3[3];
    s16 angles4[3];
    u32 color;
    p_lbl_1_rodata_6780 = (u8 *)&lbl_1_rodata_6780;
    v2 = arg1;
    if (*(u32 *)(arg0+324) != 0) {
        flags = *(u64 *)((u8 *)arg0 + 312);
        if ((flags & 0x20000000ULL) != 0) {
            fn_80008BA8(&loc_74, (void *)(*(u32 *)(arg0+324) + 84), 12);
        } else if ((flags & 0x80000000ULL) != 0) {
            fn_80008BA8(&loc_74, (void *)(*(u32 *)(arg0+324) + 124), 12);
        } else {
            return;
        }
        fn_1_57714(20);
        lbl_8006D758();
        lbl_8006E1B0((void *)(arg0+0x54), &screen1);
        lbl_8006E1B0(&loc_74, &screen2);
        lbl_8006DCA4();
        fn_80072558();
        color = *(u32 *)(p_lbl_1_rodata_6780+0x2c);
        fn_1_57810(2, &screen1, &color);
        psvec_sub(&loc_74, (void *)(arg0+0x54), &delta1);
        lbl_8006D784(&m1);
        lbl_8006DBAC((void *)(arg0+0xc4));
        matrix_translation(&m1);
        lbl_8006DFE8(&m1);
        fn_1_DDF80((void *)(arg0+0x44), &delta1, &out1, &out2,
                   *(f32 *)(arg0+0x50), *(f32 *)(arg0+0x50));
        lbl_8006DAEC();
        draw_color(p_lbl_1_rodata_6780, 1);
        draw_vec(&out1, angles1, p_lbl_1_rodata_6780);
        lbl_8006DB30();
        draw_color(p_lbl_1_rodata_6780, 0);
        draw_vec(&out2, angles2, p_lbl_1_rodata_6780);
        fn_1_56298(*(f32 *)(p_lbl_1_rodata_6780+0x20), *(f32 *)(p_lbl_1_rodata_6780+0x20), *(f32 *)(p_lbl_1_rodata_6780+0x20), *(f32 *)(p_lbl_1_rodata_6780+0x20));
        if ((*(u64 *)((u8 *)arg0+312) & 0x80000000ULL) != 0) {
            v0 = *(u32 *)(arg0+0x144);
            psvec_sub(&loc_74, (void *)(arg0+0x54), &delta2);
            lbl_8006D784(&m2);
            lbl_8006DBAC((void *)(v0+0x14c));
            matrix_translation(&m2);
            lbl_8006DFE8(&m2);
            fn_1_DDF80((void *)(v0+0x94), &delta2, &out3, &out4, *(f32 *)(v0+0x17c), *(f32 *)(v0+0x17c));
            lbl_8006DAEC();
            draw_color(p_lbl_1_rodata_6780, 1);
            draw_vec(&out3, angles3, p_lbl_1_rodata_6780);
            lbl_8006DB30();
            draw_color(p_lbl_1_rodata_6780, 0);
            draw_vec(&out4, angles4, p_lbl_1_rodata_6780);
            fn_1_56298(*(f32 *)(p_lbl_1_rodata_6780+0x20), *(f32 *)(p_lbl_1_rodata_6780+0x20), *(f32 *)(p_lbl_1_rodata_6780+0x20), *(f32 *)(p_lbl_1_rodata_6780+0x20));
        }
    }
}
/* fzgx:end fn_1_DCFA4 */

/* fzgx:begin fn_1_E1934 */
typedef struct {
    u8 pad0[0x8];
    s16 field8;
    s16 fieldA;
    u8 padC[0x12c];
    u64 field138;
    u8 pad140[0x68];
} Fn1E1934Object;

void fn_1_E1934(Fn1E1934Object *obj, Fn1E1934Object *base, s16 limit) {
    s16 index;

    if ((obj->field138 & 0x40) != 0) {
        return;
    }

    if (obj->fieldA != base->fieldA) {
        index = 0;
    } else {
        index = obj->field8 + 1;
    }

    while ((s16)index < limit) {
        fn_1_E1408(obj, &base[index]);
        index++;
    }
}
/* fzgx:end fn_1_E1934 */
