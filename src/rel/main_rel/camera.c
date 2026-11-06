#include "types.h"
#include "game/main_rel/camera_types.h"
#include "game/main_rel/car_test_types.h"
#include "game/main_rel/car_types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/camera.h"
#include "psvec.h"
#include "game/vec3.h"
#include "dolphin/hw_regs.h"




typedef struct {
    s32 counter;
    s32 state;
    s32 total;
    f32 rate;
    u8 pad_10[0x30];
} CamCtl;

typedef struct fn_1_8D08_Vec { f32 x, y, z; } fn_1_8D08_Vec;

typedef struct fn_1_8D08_Camera {
    s16 unk_00;
    s16 index;            /* 0x02 */
    s16 unk_04;
    s16 angle;            /* 0x06 */
    f32 unk_08;
    f32 unk_0C;
    fn_1_8D08_Vec pos;    /* 0x10 */
    u8 pad_1C[0xC];
    fn_1_8D08_Vec look;   /* 0x28 */
    f32 mtx[3][4];        /* 0x34 */
    fn_1_8D08_Vec unk_64;
    f32 lerp;             /* 0x70 */
    u8 pad_74[4];
    s16 unk_78;
    u8 pad_7A[2];
    f32 unk_7C;
    f32 unk_80;
    f32 unk_84;
    s32 unk_88;
    fn_1_8D08_Vec target; /* 0x8C */
    fn_1_8D08_Vec unk_98;
    s16 mode;             /* 0xA4 */
    s16 prevMode;         /* 0xA6 */
    u16 unk_A8;
    u8 pad_AA[0x1E4 - 0xAA];
    fn_1_8D08_Vec unk_1E4;
    f32 unk_1F0;
    f32 unk_1F4;
    s16 unk_1F8;
    s16 unk_1FA;
} fn_1_8D08_Camera;

typedef struct {
    u8 unk_0;
    u8 unk_1;
    s16 unk_2;
    s16 unk_4;
    s16 unk_6;
    s16 unk_8;
    u8 pad_A[0x8];
    s16 unk_12;
    s16 unk_14;
    u8 pad_16[0x1E0 - 0x16];
} fn_1_56B8_Camera;

typedef struct { s16 pad0; s16 id; u8 pad4[0x6C]; f32 val; } Cam;

typedef struct fn_1_8B10_CameraObject {
    s16 pad_00;
    s16 kind;
    u8 pad_04[0xA0];
    s16 index;
} fn_1_8B10_CameraObject;

typedef struct CameraOutput {
    f32 x0;
    f32 y0;
    s16 flags0;
    u8 pad_0A[2];
    f32 x1;
    f32 y1;
    s16 flags1;
    u8 pad_16[2];
    f32 x2;
    f32 y2;
    s16 flags2;
} CameraOutput;

typedef struct fn_1_ABAC_fn_1_ABAC_Target {
    u8 pad_0[0x214];
    u16 unk_214;
} fn_1_ABAC_fn_1_ABAC_Target;

typedef struct {
    f32 x, y, z;
} CamVec;

typedef struct { u8 r, g, b, a; } fn_1_CC5C_Color;
extern u32 fn_1_434C(void);
extern s8 fn_1_86624();
extern u32 fn_1_435C(u32 value);
extern void fn_1_426C(u32 idx);
extern void fn_1_8298();
extern void fn_1_847C(s8 mode);
extern void fn_1_857C();
extern void fn_1_90E0(void);
extern void fn_1_EE44(void);
extern f32 fn_1_A6FE8(void);
extern const f64 lbl_1_rodata_178;
extern const f64 lbl_1_rodata_180;
extern void fn_1_8D08();
extern s32 fn_1_3F8C(u32 arg3, u32 arg0, u32 arg1, u32 index);
extern void fn_1_EBE4(LiveCamera *, s16, s32, f32);
extern void fn_1_8A0C(s16 index);
extern void fn_1_EE04(fn_1_56B8_Camera *);
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern s32 fn_1_6514(s32 value);
extern void fn_1_BD54(void);
extern void fn_1_B870(void);
extern CameraState * camera_get_state_object(void);
extern u8* camera_get_extended_state_storage();
extern void lbl_8006DCDC(void);
extern void fn_1_550A8(void);
extern void fn_1_550E0(void);
extern void fn_1_54E00(void *value);
extern s32 fn_1_54E34(void *arg0, f32 arg1);
extern u32 lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern void lbl_8006DD14(void *, u32);
extern s16 fn_1_6B48(s32 index);
extern void *fn_1_86254(int index);
extern u32 fn_1_6D2C(u32 index);
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern s32 lbl_1_bss_F78;
extern void fn_1_A2DF4(s32 arg0, void *arg1, s32 arg2);
extern u8 fn_1_86634(int index);
extern u8 lbl_1_bss_F74;
extern u8 lbl_1_bss_F75;
extern const f32 lbl_1_rodata_188;
extern s32 fn_1_8708(s32 mode, f32 *value0, f32 *value1);
extern f32 lbl_1_bss_1040;
extern f32 lbl_1_bss_1044;
extern void OSReport(const char *format, ...);
extern u8 lbl_1_bss_103C[4];
extern u8 lbl_1_bss_108C[52];
extern u8 lbl_1_bss_1014;
extern f32 lbl_1_rodata_2E0[32];
extern f32 lbl_8006D6FC(f32 *value, void *target);
extern f64 lbl_1_rodata_478;
extern f32 lbl_1_rodata_49C;
extern f32 lbl_1_bss_10C0[6];
extern void camera_set_entry_field_0xa8(u8 index, s16 value);
extern void fn_1_715C(u8, s16);
extern s16 camera_get_entry_field_0xa8(u32 index);
extern s16 camera_get_entry_field_0xa4(u32);
extern u8 lbl_1_bss_6F244[128];
extern u8 lbl_1_bss_6EAC6[10];
extern s32 fn_1_3F864(void);
extern int fn_1_4C10(void);
extern s16 fn_1_3F0C8(void);
extern void fn_1_739C(void *, u32, u32);
extern u32 lbl_1_bss_7ADE8[40];
extern void *lbl_1_data_3310;
extern void fn_1_DCE60(void *);
extern void fn_1_DCED0(void);
extern const f32 lbl_1_rodata_194;
extern void *fn_1_868C0(s8 index);
extern s32 fn_1_A5DC4(void);
extern const f32 lbl_1_rodata_200;
extern const f32 lbl_1_rodata_204;
extern f32 fn_1_A888(Cam *cam);
extern s32 fn_1_58C4(void);
extern s32 fn_1_5910(void);
extern u32 fn_1_F2F34(void);
extern void lbl_8006E1C0(fn_1_8D08_Vec *, fn_1_8D08_Vec *);
extern void mathutil_mtxA_rotate_x(s16);
extern u8 fn_1_FA4C0(void);
extern void lbl_8006DC6C(void *);
extern void fn_1_8636C(int index, void *arg);
extern void fn_1_8B10(fn_1_8B10_CameraObject *camera, CameraOutput *output);
extern u32 fn_1_8627C(s32 index);
extern u32 fn_1_20A5C(void *, void *);
extern void fn_1_15578(void *, void *, void *, void *, u32, void *, u32, u32, u32, u32);
extern u8 fn_1_86678(int index);
extern u32 fn_1_864E8(int index);
extern f64 lbl_1_rodata_360;
extern u16 fn_1_8664C(int index);
extern u8 fn_1_40BB4(void);
extern u8 lbl_1_bss_CC0[152];
extern f32 lbl_1_rodata_230[44];
extern void fn_1_863E4(int index, void *arg);
extern void fn_80008DB4(void *first, f32 amount, void *second, void *out);
extern void lbl_8006D5A4(CamVec *a, CamVec *b, CamVec *out, f32 t);
extern u32 lbl_1_bss_F5C;
extern void fn_1_8840(void);
extern void fn_1_C770(void);
extern void fn_8006EDBC(Vec3 *arg0, Vec3 *arg1, s16 *arg2, s16 *arg3);
extern void lbl_8006D7DC(Vec3f *);
extern void mathutil_mtxA_rotate_y(s16);
extern void mathutil_mtxA_rotate_z(s16);
extern f32 lbl_8006D0E8(f32);
extern f32 lbl_8006D0B4(f32);
extern void fzgx_touch_f(f32);
extern void fzgx_touch(void *);
extern void fn_1_CC5C(void);
extern void fn_1_55FC4(f32 value);
extern void fn_1_55FF0(f32 value);
extern void lbl_8006E14C(f32);
extern void fn_80072558(void);
extern u32 lbl_801A6CE0;
extern f32 lbl_1_bss_BF0[32];
extern void camera_save_slot(u8 index);
extern void camera_snapshot(void);
extern void fn_1_C038(s32 value, f32 start, f32 end);
extern void fn_1_C10C(u8 idx);
extern void fn_1_C178(void *self);
extern void camera_report_position(void);
extern void fn_1_C268(s32 arg);
extern void fn_1_C304(s32 arg);
extern void fn_1_C3B8(void);
extern void fn_1_49410(void);
extern void fn_1_49514(u32 *value);
extern void fn_1_4954C(f32 value);
extern void fn_1_4955C(f32 value1, f32 value2);
extern void fn_1_495FC(void);
extern void fn_1_496FC(f32 value1, f32 value2);
extern void fn_1_4A0D8(const char *);
extern void fn_1_4AE0C(const char *, ...);
extern f64 lbl_1_rodata_4A8[7];

/* fzgx:begin fn_1_5370 noprologue */
#include "types.h"
#include "rel/main_rel/camera.h"

extern u32 fn_1_434C(void);
extern u8 fn_1_86624(void);
extern u32 fn_1_435C(u32);
extern void fn_1_426C(u32);
extern void fn_1_8298(s8);
extern void fn_1_847C(s8);
extern void fn_1_857C(s8);
extern void fn_1_90E0(void);
extern void fn_1_EE44(void);
extern f32 fn_1_A6FE8(void);
extern const f64 lbl_1_rodata_178;
extern const f64 lbl_1_rodata_180;
extern void fn_1_8D08(void *, f32);
extern u16 fn_1_3F8C(u8 *, void (*)(void), void *, u32);
extern void fn_1_EBE4(LiveCamera *, s16, s32, f32);

s8 fn_1_5370(s8 arg0, s16 arg1) {
    Obj_1_bss_F68_Target **base = &lbl_1_bss_F68;
    u32 i;
    s8 old;
    u32 count = 0;
    u32 extra = 0;
    u32 saved;
    u8 *obj;
    s16 id;
    u32 j;
    f32 value;
    if (*base == 0) return -1;
    saved = fn_1_434C();
    fn_1_86624();
    old = (s8)(*base)->unk_4D;
    (*base)->unk_4D = arg0;
    fn_1_435C((*base)->unk_50);
    {
        Obj_1_bss_F68_Target *state;
        for (j = 0; j < (u32)(state = *base)->unk_22; j++)
            fn_1_426C(*(s16 *)((u8 *)state + 4 + j * 2));
        state->unk_22 = 0;
    }
    fn_1_435C((*base)->unk_54);
    {
        Obj_1_bss_F68_Target *state;
        for (j = 0; j < (u32)(state = *base)->unk_44; j++)
            fn_1_426C(*(s16 *)((u8 *)state + 0x26 + j * 2));
        state->unk_44 = 0;
    }
    switch (arg0) {
    case 0: fn_1_8298(arg0); break;
    case 1: case 2: case 4: fn_1_847C(arg0); break;
    case 3: fn_1_857C(arg0); break;
    }
    {
    Obj_1_bss_F68_Target *state = *base;
    switch ((s8)state->unk_48) {
    case 0: count = 1; break;
    case 1: case 2: count = 2; break;
    case 3: case 4: case 5: case 7: count = 3; break;
    case 6: count = 3; extra = 1; break;
    case 8: count = 4; break;
    case 9: extra = 1; break;
    case 10: count = 1; extra = 1; break;
    case 11: count = 0; extra = 0; break;
    }
    state->unk_49 = count + extra;
    }
    obj = *(u8 **)((u8 *)base + 4);
#pragma opt_common_subs off
    for (i = 0; i < count; i++) {
        u8 mode;

        value = fn_1_A6FE8();
        mode = (*base)->unk_48;
        if ((s8)mode == 1 ||
            (i == 0 && (s8)mode == 3) ||
            (i == 1 && (s8)mode == 4) ||
            (i == 2 && (s8)mode == 5))
            value *= lbl_1_rodata_178;
        if ((s8)mode == 2) value *= lbl_1_rodata_180;
        if ((s8)mode == 0) *(s16 *)(obj + 2) = arg1;
        fn_1_8D08(obj, value);
        fn_1_435C((*base)->unk_50);
        id = fn_1_3F8C(lbl_1_data_33CC, fn_1_90E0, obj, 0x14);
        obj += 0x1FC;
        {
            Obj_1_bss_F68_Target *state = *base;
            j = state->unk_22;
            state->unk_22 = j + 1;
            *(s16 *)((u8 *)state + 4 + j * 2) = id;
        }
    }
    if (extra != 0) {
        value = fn_1_A6FE8();
        if (arg0 == 4)
            fn_1_EBE4(*(LiveCamera **)((u8 *)base + 8), -1, 1, value);
        else
            fn_1_EBE4(*(LiveCamera **)((u8 *)base + 8), arg1, 0, value);
        fn_1_435C((*base)->unk_50);
        id = fn_1_3F8C(lbl_1_data_33DC, fn_1_EE44, *(void **)((u8 *)base + 8), 0x14);
        {
            s16 index;
            Obj_1_bss_F68_Target *state = *base;
            index = state->unk_22;
            state->unk_22 = index + 1;
            ((s16 *)&state->unk_4)[index] = id;
        }
    }
    fn_1_435C(saved);
    return old;
}
/* fzgx:end fn_1_5370 */

/* fzgx:begin fn_1_56B8 */
/* lbl_1_bss_F68 heads a run of three camera pointers */
typedef struct {
    Obj_1_bss_F68_Target *target;
    GameCameraEntry *entries;
    fn_1_56B8_Camera *live;
} fn_1_56B8_Cluster;


#pragma opt_common_subs off
void fn_1_56B8(void) {
    GameCameraEntry *entry;
    fn_1_56B8_Cluster *c = (fn_1_56B8_Cluster *)&lbl_1_bss_F68;
    u32 count = 0;
    u32 reset;
    u8 i;
    u8 mode;
    f32 scale;
    reset = 0;

    switch ((s8)c->target->unk_48) {
    case 0:
        count = 1;
        break;
    case 1:
    case 2:
        count = 2;
        break;
    case 3:
    case 4:
    case 5:
    case 7:
        count = 3;
        break;
    case 6:
        count = 3;
        reset = 1;
        break;
    case 8:
        count = 4;
        break;
    case 9:
        reset = 1;
        break;
    case 10:
        count = 1;
        reset = 1;
        break;
    case 11:
        count = 0;
        reset = 0;
        break;
    }

    entry = c->entries;
    for (i = 0; i < count; i++, entry++) {
        scale = fn_1_A6FE8();
        mode = c->target->unk_48;
        if ((s8)mode == 1 || (i == 0 && (s8)mode == 3) ||
            (i == 1 && (s8)mode == 4) ||
            (i == 2 && (s8)mode == 5)) {
            scale *= 2.0;
        }
        if ((s8)mode == 2) {
            scale *= 0.5;
        }
        fn_1_8D08( (fn_1_8D08_Camera *)(GameCameraEntry *)(entry), scale);
        fn_1_8A0C(i);
    }

    if (reset) {
        fn_1_56B8_Camera saved;
        fn_1_56B8_Camera *live;

        scale = fn_1_A6FE8();
        live = c->live;
        saved = *live;
        fn_1_EBE4( (LiveCamera *)(fn_1_56B8_Camera *)(live), 0, 0, scale);
        c->live->unk_0 = saved.unk_0;
        c->live->unk_1 = saved.unk_1;
        c->live->unk_2 = saved.unk_2;
        c->live->unk_4 = saved.unk_4;
        c->live->unk_6 = saved.unk_6;
        c->live->unk_8 = saved.unk_8;
        c->live->unk_12 = saved.unk_12;
        c->live->unk_14 = saved.unk_14;
        fn_1_EE04(c->live);
    }
}
/* fzgx:end fn_1_56B8 */

/* fzgx:begin fn_1_5948 noprologue */
#include "types.h"
#include "rel/main_rel/camera.h"

struct Sig_fn_1_549F4_Sig_fn_8006F1F0_fn_8006F1F0_Arg0 { f32 unk_0; f32 unk_4; f32 unk_8; };
struct Sig_fn_1_549F4_fn_1_549F4_Arg1 { u32 unk_0; u16 unk_4; };
extern CameraState *camera_get_state_object(void);
extern u32 camera_update_state(CameraState *);
extern f32 fn_1_A6FE8(void);
extern void fn_1_549F4(struct Sig_fn_1_549F4_Sig_fn_8006F1F0_fn_8006F1F0_Arg0 *, struct Sig_fn_1_549F4_fn_1_549F4_Arg1 *, f32, f32, f32, f32);
extern void fn_8006F4E0(s16 *);
extern u32 fn_1_A7024(f32, f32, f32, f32);
extern u16 fn_1_A5D88(void);
extern u16 fn_1_A5DB0(void);
extern s32 fn_1_A5DC4(void);
extern void fn_1_54E00(void *);
extern void fn_1_727C(void);
extern void lbl_8006DD14(void *, void *);
extern void *lbl_8006D784(void *);
extern void OSReport(const char *, ...);
extern void OSPanic(const char *, int, const char *, ...);
extern u32 fn_80038EEC(f32, f32, f32, f32, f32, f32);
extern u32 fn_80074188(u32, u32, u32, u32);
extern s32 fn_80007CDC(f32 *);
extern s32 fn_80007D58(f32 *);
extern void *lbl_801A66CC;
extern void *lbl_801A6D00;
extern u8 lbl_1_data_32A8[12];
extern const f32 lbl_1_rodata_188;
extern const f32 lbl_1_rodata_18C;
extern const f32 lbl_1_rodata_190;
extern const f32 lbl_1_rodata_194;
extern const f32 lbl_1_rodata_198;
extern const f32 lbl_1_rodata_19C;
extern const f32 lbl_1_rodata_1A0;
extern const f32 lbl_1_rodata_1A4;
extern const f32 lbl_1_rodata_1A8;
extern const f32 lbl_1_rodata_1AC;
extern const f64 lbl_1_rodata_1B0;
extern const f32 lbl_1_rodata_1B8;
extern const f64 lbl_1_rodata_1C0;
extern const f32 lbl_1_rodata_1C8;
extern const f64 lbl_1_rodata_1D0;
extern const f32 lbl_1_rodata_1D8;

/* camera mode byte; retail reads it as a signed char */
#define CAM_MODE (*(s8 *)&(*p_lbl_1_bss_F68)->unk_48)

typedef struct {
    u8 pad_0[0x58];
    struct { f32 x; f32 y; } vp[4];
} CamViewport;

#pragma opt_propagation off
void fn_1_5948(u32 arg0) {
    struct Sig_fn_1_549F4_fn_1_549F4_Arg1 * lab_t1_;
    struct Sig_fn_1_549F4_Sig_fn_8006F1F0_fn_8006F1F0_Arg0 *lab_t0_;
    register f32 v6;
    f32 v7;
    Obj_1_bss_F68_Target **p_lbl_1_bss_F68;
    u8 *p_lbl_1_data_32A8;
    f32 lab_t1;
    f32 v9, v10;
    f32 v14, v11, v12, v13, v15, v16;
    f32 v40, v38;
    f32 *v39, *v41, *v42;
    void *v43;
    f32 v47;
    CameraState *v4;
    u8 *v1;
    f32 loc_C, loc_8;
    struct Sig_fn_1_549F4_fn_1_549F4_Arg1 loc_10;

    p_lbl_1_bss_F68 = &lbl_1_bss_F68;
    p_lbl_1_data_32A8 = lbl_1_data_32A8;
    if (CAM_MODE == 11) return;
    (*p_lbl_1_bss_F68)->unk_4A = arg0;
    if (((*p_lbl_1_bss_F68)->unk_0 & 0x80000000) != 0) {
        lbl_8006DD14((u8 *)lbl_801A6D00 + 0x30, lbl_801A66CC);
        v4 = camera_get_state_object();
        camera_update_state(v4);
        fn_8006F4E0((s16 *)&loc_10);
        {
            fn_1_549F4((void *)&((f32 *)v4)[1], &loc_10, *(f32 *)((u8 *)v4 + 0x1C), (v6 = fn_1_A6FE8()), 0.0f, 0.0f);
        }
        fn_1_A7024(*(f32 *)((u8 *)v4 + 0x1C), (v7 = fn_1_A6FE8()), lbl_1_rodata_18C, lbl_1_rodata_190);
        return;
    }
    v9 = (f32)(u32)fn_1_A5D88();
    v10 = (f32)(u32)fn_1_A5DB0();
    switch ((s32)arg0) {
    case 0:
        switch (CAM_MODE) {
        case 0: case 9: break;
        case 1: case 3:
            v11 = lbl_1_rodata_188;
            v12 = lbl_1_rodata_194;
            v13 = lbl_1_rodata_198;
            v14 = v11;
            (*p_lbl_1_bss_F68)->unk_58 = v12;
            v15 = v11;
            (*p_lbl_1_bss_F68)->unk_5C = v13;
            break;
        case 2:
            v11 = lbl_1_rodata_188;
            v12 = lbl_1_rodata_198;
            v13 = lbl_1_rodata_194;
            v14 = v11;
            v15 = v11;
            break;
        case 4:
            v14 = lbl_1_rodata_188;
            v11 = lbl_1_rodata_198;
            v13 = v11;
            v15 = v14;
            v12 = v11;
            break;
        case 5: case 6: case 7: case 8:
            v11 = lbl_1_rodata_188;
            v13 = lbl_1_rodata_198;
            v14 = v11;
            v12 = v13;
            v15 = v11;
            break;
        case 10:
            v11 = lbl_1_rodata_188;
            v13 = lbl_1_rodata_194;
            v12 = v13;
            v15 = lbl_1_rodata_19C;
            v14 = v11;
            break;
        default:
            OSReport((char *)p_lbl_1_data_32A8 + 0x1A4, arg0, CAM_MODE);
            OSPanic((char *)p_lbl_1_data_32A8 + 0x70, 0x252, (char *)p_lbl_1_data_32A8 + 0x1B8);
            break;
        }
        v16 = lbl_1_rodata_194;
        break;
    case 1:
        switch (CAM_MODE) {
        case 1:
            v14 = lbl_1_rodata_188;
            v11 = lbl_1_rodata_198;
            v12 = lbl_1_rodata_194;
            v13 = v11;
            v16 = v12;
            break;
        case 2:
            v14 = lbl_1_rodata_198;
            v11 = lbl_1_rodata_188;
            v13 = lbl_1_rodata_194;
            v16 = v13;
            v12 = v14;
            break;
        case 3:
            v14 = lbl_1_rodata_188;
            v11 = lbl_1_rodata_198;
            v16 = lbl_1_rodata_194;
            v13 = v11;
            v12 = v11;
            break;
        case 4:
            v11 = lbl_1_rodata_188;
            v12 = lbl_1_rodata_194;
            v16 = v12;
            v13 = lbl_1_rodata_198;
            v14 = v11;
            break;
        case 5: case 6: case 7: case 8:
            v14 = lbl_1_rodata_198;
            v11 = lbl_1_rodata_188;
            v16 = lbl_1_rodata_194;
            v13 = v14;
            v12 = v14;
            break;
        case 10:
            v11 = lbl_1_rodata_1A0;
            v13 = lbl_1_rodata_1A4;
            v12 = v13;
            v16 = lbl_1_rodata_19C;
            v14 = v11;
            break;
        default:
            OSReport((char *)p_lbl_1_data_32A8 + 0x1A4, arg0, CAM_MODE);
            OSPanic((char *)p_lbl_1_data_32A8 + 0x70, 0x28E, (char *)p_lbl_1_data_32A8 + 0x1B8);
            break;
        }
        v15 = lbl_1_rodata_188;
        break;
    case 2:
        switch (CAM_MODE) {
        case 3: case 4:
            v11 = lbl_1_rodata_198;
            v14 = v11;
            v13 = v11;
            v12 = v11;
            break;
        case 5:
            v14 = lbl_1_rodata_188;
            v11 = lbl_1_rodata_198;
            v12 = lbl_1_rodata_194;
            v13 = v11;
            break;
        case 6: case 7: case 8:
            v14 = lbl_1_rodata_188;
            v11 = lbl_1_rodata_198;
            v13 = v11;
            v12 = v11;
            break;
        default:
            OSReport((char *)p_lbl_1_data_32A8 + 0x1A4, arg0, CAM_MODE);
            OSPanic((char *)p_lbl_1_data_32A8 + 0x70, 0x2B1, (char *)p_lbl_1_data_32A8 + 0x1DC);
            break;
        }
        v15 = lbl_1_rodata_188;
        v16 = lbl_1_rodata_194;
        break;
    case 3:
        switch (CAM_MODE) {
        case 6: case 8:
            v11 = lbl_1_rodata_198;
            v14 = v11;
            v13 = v11;
            v12 = v11;
            break;
        default:
            OSReport((char *)p_lbl_1_data_32A8 + 0x1A4, arg0, CAM_MODE);
            OSPanic((char *)p_lbl_1_data_32A8 + 0x70, 0x2C6, (char *)p_lbl_1_data_32A8 + 0x200);
            break;
        }
        v15 = lbl_1_rodata_188;
        v16 = lbl_1_rodata_194;
        break;
    }
    if (CAM_MODE == 0 || CAM_MODE == 9) {
        Obj_1_bss_F68_Target *viewport;
        viewport = (Obj_1_bss_F68_Target *)((u8 *)*p_lbl_1_bss_F68 + arg0 * 8);
        viewport->unk_58 = lbl_1_rodata_194;
        viewport = (Obj_1_bss_F68_Target *)((u8 *)*p_lbl_1_bss_F68 + arg0 * 8);
        viewport->unk_5C = lbl_1_rodata_194;
        lab_t1 = lbl_1_rodata_188;
        fn_80038EEC(lbl_1_rodata_188, lab_t1, v9, v10, lbl_1_rodata_188, lbl_1_rodata_194);
        fn_80074188(0, 0, (u32)v9, (u32)v10);
    } else {
        Obj_1_bss_F68_Target *viewport;
        u32 viewportOffset;
        viewportOffset = arg0 * 8;
        v14 *= v9;
        v11 *= v10;
        viewport = (Obj_1_bss_F68_Target *)((u8 *)*p_lbl_1_bss_F68 + viewportOffset);
        viewport->unk_58 = v12;
        v12 *= v9;
        viewport = (Obj_1_bss_F68_Target *)((u8 *)*p_lbl_1_bss_F68 + viewportOffset);
        viewport->unk_5C = v13;
        v13 *= v10;
        lab_t1 = v11;
        fn_80038EEC(v14, lab_t1, v12, v13, v15, v16);
        fn_80074188((u32)v14, (u32)v11, (u32)v12, (u32)v13);
    }
    if ((arg0 == 0 && (CAM_MODE == 9 || (u8)(CAM_MODE - 9) <= 1)) ||
        (arg0 == 3 && CAM_MODE == 6)) {
        v1 = (u8 *)p_lbl_1_bss_F68[2];
        v38 = *(f32 *)(v1 + 0x58);
        v39 = (f32 *)(v1 + 0xFC);
        v40 = *(f32 *)(v1 + 0x60);
        v41 = (f32 *)(v1 + 0x12C);
        v42 = (f32 *)(v1 + 0x1C);
        v43 = v1 + 0x15C;
    } else if (arg0 == 1 && CAM_MODE == 10) {
        v1 = (u8 *)p_lbl_1_bss_F68[1];
        v38 = *(f32 *)(v1 + 8);
        v39 = (f32 *)(v1 + 0xAC);
        v40 = *(f32 *)(v1 + 0xC);
        v41 = (f32 *)(v1 + 0xDC);
        v42 = (f32 *)(v1 + 0x10);
        v43 = v1 + 0x15C;
    } else {
        v1 = (u8 *)p_lbl_1_bss_F68[1] + arg0 * 0x1FC;
        v38 = *(f32 *)(v1 + 8);
        v39 = (f32 *)(v1 + 0xAC);
        v40 = *(f32 *)(v1 + 0xC);
        v41 = (f32 *)(v1 + 0xDC);
        v42 = (f32 *)(v1 + 0x10);
        v43 = v1 + 0x15C;
    }
    if (fn_80007CDC(v42) != 0 || fn_80007D58(v41) != 0 ||
        (loc_C = v38, (*(u32 *)&loc_C & 0x7F800000) == 0x7F800000) ||
        (loc_8 = v40, (*(u32 *)&loc_8 & 0x7F800000) == 0x7F800000)) {
        OSReport((char *)p_lbl_1_data_32A8 + 0x224);
        OSReport((char *)p_lbl_1_data_32A8 + 0x240, CAM_MODE);
        OSReport((char *)p_lbl_1_data_32A8 + 0x250, arg0);
        OSReport((char *)p_lbl_1_data_32A8 + 0x260, v42[0]);
        OSReport((char *)p_lbl_1_data_32A8 + 0x270, v42[1]);
        OSReport((char *)p_lbl_1_data_32A8 + 0x280, v42[2]);
        OSReport((char *)p_lbl_1_data_32A8 + 0x290, v38);
        OSReport((char *)p_lbl_1_data_32A8 + 0x2A0, v40);
        v42[0] = lbl_1_rodata_188;
        v42[1] = lbl_1_rodata_188;
        v42[2] = lbl_1_rodata_188;
        lbl_8006D784(v41);
        v38 = lbl_1_rodata_1A8;
        v40 = fn_1_A6FE8();
    }
    lbl_8006DD14(v39, lbl_801A66CC);
    lbl_8006DD14(v41, (u8 *)lbl_801A6D00 + 0x30);
    fn_1_54E00(v43);
    v47 = lbl_1_rodata_18C;
    if (v38 < lbl_1_rodata_1AC) v47 = (f32)(v47 * lbl_1_rodata_1B0);
    else if (v38 < lbl_1_rodata_1B8) v47 = (f32)(v47 * lbl_1_rodata_1C0);
    else if (v38 < lbl_1_rodata_1C8) v47 = (f32)(v47 * lbl_1_rodata_1D0);
    if ((s8)fn_1_A5DC4() != 0) {
        switch (*((u8 *)p_lbl_1_bss_F68 + 0xD)) {
        case 0: break;
        case 1: v38 *= lbl_1_rodata_1D8; break;
        case 2: v38 *= lbl_1_rodata_1A0; break;
        }
    }
    fn_1_A7024(v38, v40, v47, lbl_1_rodata_190);
    fn_1_727C();
}
#pragma opt_propagation reset
/* fzgx:end fn_1_5948 */

/* fzgx:begin fn_1_6400 */
typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
} F68State;

// Report and clear the three pending camera state values.
void fn_1_6400(void) {
    F68State *state;

    state = (F68State *)&lbl_1_bss_F68;
    fn_1_46B4(lbl_801A6410.unk_0, state->unk_8, (const char *)(void *)((*(u8 (*)[180])&lbl_1_data_3318)), 0x396);
    fn_1_46B4(lbl_801A6410.unk_0, state->unk_4, (const char *)(void *)((*(u8 (*)[180])&lbl_1_data_3318)), 0x397);
    fn_1_46B4(lbl_801A6410.unk_0, state->unk_0, (const char *)(void *)((*(u8 (*)[180])&lbl_1_data_3318)), 0x398);
    state->unk_8 = 0;
    state->unk_4 = 0;
    state->unk_0 = 0;
}
/* fzgx:end fn_1_6400 */

/* fzgx:begin camera_get_state */
// Return the camera state byte, or -1 when no camera state is active.
s32 camera_get_state(void) {
    Obj_1_bss_F68_Target *camera = lbl_1_bss_F68;

    if (camera == 0) {
        return -1;
    }

    return camera->unk_48;
}
/* fzgx:end camera_get_state */

/* fzgx:begin camera_get_status */
// Return the camera status when a camera exists and is not marked inactive.
u32 camera_get_status(void) {
    Obj_1_bss_F68_Target *camera = lbl_1_bss_F68;
    u32 status;

    if (camera == 0) {
        status = 0;
    } else if ((camera->unk_0 & ((u32)1 << 31)) != 0) {
        status = 0;
    } else {
        status = camera->unk_4A;
    }

    return fn_1_6514(status);
}
/* fzgx:end camera_get_status */

/* fzgx:begin fn_1_6514 */
s32 fn_1_6514(s32 value) {
    Obj_1_bss_F68_Target *camera = lbl_1_bss_F68;
    s8 mode;

    if (camera == 0) {
        return -1;
    }
    if ((camera->unk_0 & ((u32)1 << 31)) != 0) {
        return 0;
    }

    mode = (s8)camera->unk_48;
    switch (mode) {
    case 9:
        return 2;
    case 10:
        return (value == 0) + 1;
    case 6:
        return (value == 3) + 1;
    }

    switch (game_camera_entries[value].unk_A8) {
    case 0:
        return 1;
    case 1:
    case 2:
        return 3;
    case 3:
        return 4;
    case 4:
        return 5;
    case 5:
        return 6;
    default:
        return -1;
    }
}
/* fzgx:end fn_1_6514 */

/* fzgx:begin camera_get_flags */
u32 camera_get_flags(void) {
    // Reports the active camera object's top-bit flag, or zero when no object is active.
    if (lbl_1_bss_F68 != 0) {
        return lbl_1_bss_F68->unk_0 & (1u << 31);
    }

    return 0;
}
/* fzgx:end camera_get_flags */

/* fzgx:begin camera_update */
// Dispatches the camera update according to the camera state flag.
void camera_update(void) {
    CameraState *state = camera_get_state_object();

    if (((state->unk_0 >> 30) & 1) != 0) {
        fn_1_BD54();
    } else {
        fn_1_B870();
    }
}
/* fzgx:end camera_update */

/* fzgx:begin camera_update_state noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/camera.h"
#include "game/main_rel/camera_types.h"

extern u8* camera_get_extended_state_storage();
extern void lbl_8006DBAC(void);
extern void lbl_8006DCDC(void);

// Updates the camera state through the active or standard camera path.
void camera_update_state(__typeof__(lbl_1_bss_F68) state) {
    if ((state->unk_0 >> 30) & 1) {
        camera_get_extended_state_storage(state);
        lbl_8006DBAC();
    } else {
        fn_8006F038( (Vec3 *)(void *)(&state->unk_4), (Vec3 *)(void *)(&state->unk_4 + 6),
                     *((s16 *)&state->unk_4 + 14));
    }

    lbl_8006DCDC();
}
/* fzgx:end camera_update_state */

/* fzgx:begin fn_1_66B8 */
typedef Obj_1_bss_F68_Target fn_1_66B8_Obj;

struct fn_1_66B8_Global {
	u8 *unk_0;
	u8 *unk_4;
	u8 *unk_8;
};

struct fn_1_66B8_Vec {
	f32 x;
	f32 y;
	f32 z;
};

#pragma opt_propagation off
s32 fn_1_66B8(void *arg0, f32 arg1) {
	struct fn_1_66B8_Vec v;
	u8 *a;
	struct fn_1_66B8_Global *g = (struct fn_1_66B8_Global *)&lbl_1_bss_F68;
	u32 off;
	u32 i;
	u8 *sel;
	s32 ret = 0;
	void *p = arg0;

	if (g->unk_0 == 0) {
		return 0;
	}
	if (p == 0) {
		p = &v;
		psvec_set(&v, *(f32 *)(0xE0000000 + 0x2C), *(f32 *)(0xE0000000 + 0x1C),
				 *(f32 *)(0xE0000000 + 0xC));
	}
	fn_1_550A8();
	lbl_8006DAEC();
	for (i = 0, off = 0; i < ((fn_1_66B8_Obj *)g->unk_0)->unk_49; i++) {
		if ((i == 0 && ((s8)((fn_1_66B8_Obj *)g->unk_0)->unk_48 == 9
					  || (s8)((fn_1_66B8_Obj *)g->unk_0)->unk_48 == 10))
			|| (i == 3 && (s32)((fn_1_66B8_Obj *)g->unk_0)->unk_48 == 6)) {
			sel = g->unk_8 + 0x12C;
			a = g->unk_8 + 0x15C;
		} else if (i == 1 && (s32)((fn_1_66B8_Obj *)g->unk_0)->unk_48 == 10) {
			sel = g->unk_4 + 0xDC;
			a = g->unk_4 + 0x15C;
		} else {
			sel = g->unk_4 + off + 0xDC;
			a = g->unk_4 + off + 0x15C;
		}
		fn_1_54E00(a);
		lbl_8006DBAC( (Vec3 *)(void *)(sel));
		if (fn_1_54E34(p, arg1) != 0) {
			ret = 1;
			break;
		}
		off += 0x1FC;
	}
	lbl_8006DB30();
	fn_1_550E0();
	return ret;
}
#pragma opt_propagation reset
/* fzgx:end fn_1_66B8 */

/* fzgx:begin fn_1_681C */
struct fn_1_681C_Copy12 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
};

struct fn_1_681C_Entry {
    u8 pad_0[0x10];
    struct fn_1_681C_Copy12 unk_10;
    u8 pad_1C[0x1FC - 0x1C];
};

struct fn_1_681C_Other {
    u8 pad_0[0x1C];
    struct fn_1_681C_Copy12 unk_1C;
};

struct fn_1_681C_Globals {
    u32 state;
    struct fn_1_681C_Entry *entries;
    struct fn_1_681C_Other *other;
};



#pragma peephole off
void fn_1_681C(u32 index, u32 *output) {
    struct fn_1_681C_Globals *globals = &(*(struct fn_1_681C_Globals *)&lbl_1_bss_F68);
    u32 state = globals->state;
    s8 mode;

    if (state == 0) {
        return;
    }

    mode = *(s8 *)((u8 *)state + 0x48);

    switch (mode) {
    case 9:
    case 10:
        *(struct fn_1_681C_Copy12 *)output = globals->other->unk_1C;
        return;
    default:
        *(struct fn_1_681C_Copy12 *)output = globals->entries[index & 0xff].unk_10;
        return;
    }
}
#pragma peephole reset
/* fzgx:end fn_1_681C */

/* fzgx:begin fn_1_6898 */
struct fn_1_6898_Copy12 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
};

struct fn_1_6898_Entry {
    u8 pad_0[0x1C];
    struct fn_1_6898_Copy12 unk_1C;
    u8 pad_28[0x1FC - 0x28];
};

struct fn_1_6898_Other {
    u8 pad_0[0x28];
    struct fn_1_6898_Copy12 unk_28;
};

struct fn_1_6898_Globals {
    u32 state;
    struct fn_1_6898_Entry *entries;
    struct fn_1_6898_Other *other;
};



#pragma peephole off
void fn_1_6898(u32 index, u32 *output) {
    struct fn_1_6898_Globals *globals = &(*(struct fn_1_6898_Globals *)&lbl_1_bss_F68);
    u32 state = globals->state;
    s8 mode;

    if (state == 0) {
        return;
    }

    mode = *(s8 *)((u8 *)state + 0x48);

    switch (mode) {
    case 9:
    case 10:
        *(struct fn_1_6898_Copy12 *)output = globals->other->unk_28;
        return;
    default:
        *(struct fn_1_6898_Copy12 *)output = globals->entries[index & 0xff].unk_1C;
        return;
    }
}
#pragma peephole reset
/* fzgx:end fn_1_6898 */

/* fzgx:begin fn_1_6914 */
struct fn_1_6914_Copy12 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
};

struct fn_1_6914_Entry {
    u8 pad_0[0x28];
    struct fn_1_6914_Copy12 unk_28;
    u8 pad_34[0x1FC - 0x34];
};

struct fn_1_6914_Other {
    u8 pad_0[0x4C];
    struct fn_1_6914_Copy12 unk_4C;
};

struct fn_1_6914_Globals {
    u32 state;
    struct fn_1_6914_Entry *entries;
    struct fn_1_6914_Other *other;
};



#pragma peephole off
void fn_1_6914(u32 index, u32 *output) {
    struct fn_1_6914_Globals *globals = &(*(struct fn_1_6914_Globals *)&lbl_1_bss_F68);
    u32 state = globals->state;
    s8 mode;

    if (state == 0) {
        return;
    }

    mode = *(s8 *)((u8 *)state + 0x48);

    switch (mode) {
    case 9:
    case 10:
        *(struct fn_1_6914_Copy12 *)output = globals->other->unk_4C;
        return;
    default:
        *(struct fn_1_6914_Copy12 *)output = globals->entries[index & 0xff].unk_28;
        return;
    }
}
#pragma peephole reset
/* fzgx:end fn_1_6914 */

/* fzgx:begin fn_1_6990 */
struct fn_1_6990_Copy12 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
};

struct fn_1_6990_Entry {
    u8 pad_0[0x64];
    struct fn_1_6990_Copy12 unk_64;
    u8 pad_70[0x1FC - 0x70];
};

struct fn_1_6990_Other {
    u8 pad_0[0x70];
    struct fn_1_6990_Copy12 unk_70;
};

struct fn_1_6990_Globals {
    u32 state;
    struct fn_1_6990_Entry *entries;
    struct fn_1_6990_Other *other;
};



#pragma peephole off
void fn_1_6990(u32 index, u32 *output) {
    struct fn_1_6990_Globals *globals = &(*(struct fn_1_6990_Globals *)&lbl_1_bss_F68);
    u32 state = globals->state;
    s8 mode;

    if (state == 0) {
        return;
    }

    mode = *(s8 *)((u8 *)state + 0x48);

    switch (mode) {
    case 9:
    case 10:
        *(struct fn_1_6990_Copy12 *)output = globals->other->unk_70;
        return;
    default:
        *(struct fn_1_6990_Copy12 *)output = globals->entries[index & 0xff].unk_64;
        return;
    }
}
#pragma peephole reset
/* fzgx:end fn_1_6990 */

/* fzgx:begin fn_1_6A0C pool */
#pragma force_active on
Obj_1_bss_F68_Target *lbl_1_bss_F68;
u8 *lbl_1_bss_F6C;
u8 *lbl_1_bss_F70;

/* Prime the native BSS pool in retail address order. */
#pragma section code_type ".fzgxpool"
static void *fzgx_fn_1_6A0C_bss_order(u32 index) {
    if (index == 0) {
        return lbl_1_bss_F68;
    }
    if (index == 1) {
        return lbl_1_bss_F6C;
    }
    return lbl_1_bss_F70;
}
#pragma section code_type ".text"
#pragma force_active reset

#pragma peephole on
#pragma opt_strength_reduction off
void fn_1_6A0C(u32 index, u32 arg) {
    u8 * fzgx_live;
    Obj_1_bss_F68_Target *state = lbl_1_bss_F68;

    if (state == 0) {
        return;
    }

    switch ((s8)state->unk_48) {
    case 9:
    case 10:
        lbl_8006DD14(lbl_1_bss_F70 + 0x7c, arg);
        return;
    default:
        fzgx_live = lbl_1_bss_F6C;
        lbl_8006DD14(((0x34) + (((index & 0xff) * 0x1fc) + (fzgx_live))), arg);
        return;
    }
}
#pragma opt_strength_reduction reset
/* fzgx:end fn_1_6A0C */

/* fzgx:begin camera_get_mode */
// Return the normalized camera status, treating inactive states as zero.
s16 camera_get_mode(void) {
    Obj_1_bss_F68_Target *state = lbl_1_bss_F68;
    s32 index;
    s16 value;

    if (state == 0) {
        index = 0;
    } else if ((state->unk_0 & ((s32)1 << 31)) != 0) {
        index = 0;
    } else {
        index = state->unk_4A;
    }

    value = fn_1_6B48(index);
    if (value == 0xff) {
        value = -1;
    }

    return value;
}
/* fzgx:end camera_get_mode */

/* fzgx:begin camera_get_output */
s16 camera_get_output(void) {
    Obj_1_bss_F68_Target *state = lbl_1_bss_F68;
    u32 result;

    // Return the camera output only when the state is active and ready.
    if ((s8)state->unk_48 == 6) {
        if (state == 0) {
            result = 0;
        } else if ((state->unk_0 & ((s32)1 << 31)) != 0) {
            result = 0;
        } else {
            result = state->unk_4A;
        }

        if (result == 3) {
            return live_camera->unk_6;
        }
    }

    return -1;
}
/* fzgx:end camera_get_output */

/* fzgx:begin fn_1_6B48 */
/* The three camera pointers are one cluster of this TU's .bss; retail
 * addresses them off a single base register. MWCC lays .bss out in
 * first-access order, so the primer below (a section mwld ignores) fixes
 * retail's order: lbl_1_bss_F68, game_camera_entries, live_camera. */
Obj_1_bss_F68_Target *lbl_1_bss_F68;
__typeof__(game_camera_entries) game_camera_entries;
__typeof__(live_camera) live_camera;

#pragma section ".fzgxpool"
__declspec(section ".fzgxpool") void fn_1_6B48_bss_primer(void *out[3]) {
    out[0] = lbl_1_bss_F68;
    out[1] = game_camera_entries;
    out[2] = live_camera;
}

s16 fn_1_6B48(s32 index) {
    Obj_1_bss_F68_Target *state = lbl_1_bss_F68;

    if (state == 0) {
        return -1;
    }
    if ((state->unk_0 & ((s32)1 << 31)) != 0) {
        return -1;
    }
    switch ((s8)state->unk_48) {
    case 9:
    case 10:
        return live_camera->unk_6;
    case 11:
        return -1;
    default:
        return game_camera_entries[index].unk_2;
    }
}
/* fzgx:end fn_1_6B48 */

/* fzgx:begin fn_1_6BC0 */
// lbl_1_bss_9F8.unk_8 read as a 16-bit button word; bits 0/1 select previous/next camera
typedef struct {
    u8 pad_0[0x8];
    u16 buttons : 16;
} CameraSelectInput;

#define CAMERA_SELECT_INPUT ((CameraSelectInput *)&lbl_1_bss_9F8)

#pragma opt_common_subs off
void fn_1_6BC0(void) {
    s32 cur;
    s16 next;

    if (lbl_1_bss_F68 == NULL) {
        return;
    }
    if (*(s8 *)&lbl_1_bss_F68->unk_48 != 0) {
        return;
    }

    cur = game_camera_entries->unk_2;
    next = cur;
    if ((CAMERA_SELECT_INPUT->buttons >> 1) & 1) {
        next++;
        if (next == (s8)fn_1_86624()) {
            next = 0;
        }
    } else if (CAMERA_SELECT_INPUT->buttons & 1) {
        next--;
        if (next < 0) {
            next = (s8)fn_1_86624() - 1;
        }
    }

    if (next != cur) {
        game_camera_entries->unk_2 = next;
        *(s8 *)((u8 *)fn_1_86254(cur) + 0x475) = -1;
        *(s8 *)((u8 *)fn_1_86254(next) + 0x475) = 0;
    }
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_6BC0 */

/* fzgx:begin camera_set_result */
void camera_set_result(s16 value) {
    // Update the camera result only while the camera state is active.
    if (lbl_1_bss_F68 != 0) {
        game_camera_entries->unk_2 = value;
    }
}
/* fzgx:end camera_set_result */

/* fzgx:begin camera_forward_status */
// Forward the camera state's status to the next update stage.
void camera_forward_status(void) {
    Obj_1_bss_F68_Target *state = lbl_1_bss_F68;
    u32 value;

    if (state == 0) {
        value = 0;
    } else if ((state->unk_0 & ((u32)1 << 31)) != 0) {
        value = 0;
    } else {
        value = state->unk_4A;
    }

    fn_1_6D2C(value);
}
/* fzgx:end camera_forward_status */

/* fzgx:begin fn_1_6D2C */
typedef struct {
    u32 unk_0;
    u8 unk_4;
    u8 pad_5[0x1F7];
} F6D2CEntry;

typedef struct {
    u32 unk_0;
    u8 pad[8];
    u32 unk_C;
} F6D2COther;

typedef struct {
    Obj_1_bss_F68_Target *state;
    F6D2CEntry *entries;
    F6D2COther *other;
} F6D2CBss;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
Obj_1_bss_F68_Target *fzgx_obj_lbl_1_bss_F68;
F6D2CEntry *fzgx_obj_game_camera_entries;
F6D2COther *fzgx_obj_live_camera;
u8 lbl_1_bss_F74;
u8 lbl_1_bss_F75;
u8 lbl_1_bss_F76;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_F68;
    s = *(u8 *)&fzgx_obj_game_camera_entries;
    s = *(u8 *)&fzgx_obj_live_camera;
    s = *(u8 *)&lbl_1_bss_F74;
    s = *(u8 *)&lbl_1_bss_F75;
    s = *(u8 *)&lbl_1_bss_F76;
}
#pragma section code_type ".text"

u32 fn_1_6D2C(u32 index) {
    
    Obj_1_bss_F68_Target *state = fzgx_obj_lbl_1_bss_F68;
    s8 mode;

    if (state == 0) {
        OSPanic( (const char *)((u8 *)lbl_1_data_3318), 0x546, (const char *)((u8 *)&lbl_1_data_35B0));
        return 0;
    }
    if ((fzgx_obj_lbl_1_bss_F68->unk_0 & ((u32)1 << 31)) != 0) {
        return *(u32 *)camera_get_state_object();
    }
    mode = (s8)fzgx_obj_lbl_1_bss_F68->unk_48;
    switch (mode) {
    case 9:
    case 10:
        return fzgx_obj_live_camera->unk_C;
    default:
        return fzgx_obj_game_camera_entries[index].unk_4;
    }
}
/* fzgx:end fn_1_6D2C */

/* fzgx:begin fn_1_6DD0 */
typedef struct {
    u32 unk_0;
    u8 unk_4;
} F6DD0Entry;

typedef struct {
    u32 unk_0;
    u8 pad[8];
    u32 unk_C;
} F6DD0Other;

typedef struct {
    Obj_1_bss_F68_Target *state;
    u8 *entries;
    F6DD0Other *other;
} F6DD0Bss;

/* volatile: retail preserves the flag-byte read and write even with a zero mask. */
static inline void F6DD0SetFlag(volatile F6DD0Entry *e, u8 flag) {
    e->unk_4 = e->unk_4 | flag;
}

void fn_1_6DD0(u8 index) {
    F6DD0Bss *bss = (F6DD0Bss *)&lbl_1_bss_F68;
    s8 mode;

    lbl_8006DD14( (void *)((u32)((u8 *)((u32 *)lbl_801A6D00) + 0x30)), (u32)(void *)(((void *)lbl_801A66CC)));
    if (bss->state == 0) {
        OSPanic( (const char *)((u8 *)lbl_1_data_3318), 0x564, (const char *)((u8 *)&lbl_1_data_35B0));
    }
    if ((bss->state->unk_0 & ((u32)1 << 31)) != 0) {
        *(u32 *)camera_get_state_object() |= ((u32)1 << 31);
    }
    mode = (s8)bss->state->unk_48;
    switch (mode) {
    case 9:
    case 10:
        bss->other->unk_C |= ((u32)1 << 31);
        break;
    default: {
        /* volatile: retail preserves this byte read/modify/write for a zero mask. */
        F6DD0SetFlag((volatile F6DD0Entry *)(bss->entries + index * 0x1FC), 0);
        break;
    }
    }
}
/* fzgx:end fn_1_6DD0 */

/* fzgx:begin fn_1_6EC0 */
u32 fn_1_6EC0(u8 index) {
    Obj_1_bss_F68_Target *state = lbl_1_bss_F68;

    if (state == 0) {
        return 0;
    }
    if ((state->unk_0 & ((u32)1 << 31)) != 0) {
        return 0;
    }

    switch ((s8)state->unk_48) {
    case 9:
    case 10:
        return 0;
    }

    return game_camera_entries[index].unk_A8 == 0;
}
/* fzgx:end fn_1_6EC0 */

/* fzgx:begin camera_is_mode_0x0b */
// Return whether the camera state is active and has the expected mode.
u32 camera_is_mode_0x0b(void) {
    Obj_1_bss_F68_Target *state = lbl_1_bss_F68;

    if (state == 0) {
        return 0;
    }
    if ((state->unk_0 & ((u32)1 << 31)) != 0) {
        return 0;
    }
    return (s8)state->unk_48 == 0x0B;
}
/* fzgx:end camera_is_mode_0x0b */

/* fzgx:begin fn_1_6F84 */
s32 fn_1_6F84(void) {
    Obj_1_bss_F68_Target *state = lbl_1_bss_F68;
    if (state == 0) {
        return 0;
    }
    if ((state->unk_0 & ((u32)1 << 31)) != 0) {
        return 0;
    }

    switch ((s8)state->unk_48) {
    case 9:
    case 10:
        if (live_camera->unk_2 == 4) {
            return 1;
        }
        return 0;
    }

    return 0;
}
/* fzgx:end fn_1_6F84 */

/* fzgx:begin fn_1_7000 */
s32 fn_1_7000(void) {
    Obj_1_bss_F68_Target *state = lbl_1_bss_F68;

    if (state == 0) {
        return 0;
    }
    if ((state->unk_0 & ((u32)1 << 31)) != 0) {
        return 0;
    }

    switch ((s8)state->unk_48) {
    case 9:
    case 10:
        if (live_camera->unk_2 == 5) {
            return 1;
        }
        return 0;
    }

    return 0;
}
/* fzgx:end fn_1_7000 */

/* fzgx:begin fn_1_707C */
typedef struct {
    u8 pad_0[2];
    s16 unk_2;
    u8 pad_4[0x1F8];
} fn_1_707C_Entry;

typedef struct {
    u8 pad_0[0x6];
    s16 unk_6;
} fn_1_707C_Flag;

#pragma peephole on
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
Obj_1_bss_F68_Target *fzgx_obj_lbl_1_bss_F68;
u8 *fzgx_obj_game_camera_entries;
u8 *fzgx_obj_live_camera;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_F68;
    s = *(u8 *)&fzgx_obj_game_camera_entries;
    s = *(u8 *)&fzgx_obj_live_camera;
}
#pragma section code_type ".text"

static inline fn_1_707C_Flag * fn_1_707C_read_pointer(void) { return (fn_1_707C_Flag *)(void *)fzgx_obj_live_camera; }
#pragma opt_dead_assignments off
s32 fn_1_707C(u8 arg0) {
    u32 i;
    s32 value;
    fn_1_707C_Entry *cur;
    u32 count;
    u32 id;
    fn_1_707C_Entry *entries;
    fn_1_707C_Flag *flags;
    Obj_1_bss_F68_Target *obj;
    fn_1_707C_Entry * fzgx_live;

    if ((obj = (Obj_1_bss_F68_Target *)(void *)fzgx_obj_lbl_1_bss_F68) == 0) {
        return 0;
    }

    fzgx_live = (fn_1_707C_Entry *)(void *)fzgx_obj_game_camera_entries;
    entries = fzgx_live;
    i = 0;
    id = arg0;
    count = obj->unk_49;
    flags = fn_1_707C_read_pointer();
    cur = entries;

    {
    u32 fzgx_loop_i_1063;
for (fzgx_loop_i_1063 = 0; fzgx_loop_i_1063 < count; fzgx_loop_i_1063++) {
        if ((fzgx_loop_i_1063 == 0 && ((s8)obj->unk_48 == 9 || (s8)obj->unk_48 == 10)) ||
            (fzgx_loop_i_1063 == 3 && (s8)obj->unk_48 == 6)) {
            value = flags->unk_6;
        } else if (fzgx_loop_i_1063 == 1 && (s8)obj->unk_48 == 10) {
            value = entries->unk_2;
        } else {
            value = cur->unk_2;
        }
        if ((u32)value == id) {
            return 1;
        }
        cur = (fn_1_707C_Entry *)((u8 *)cur + 0x1FC);
    }
    i = fzgx_loop_i_1063;
}
    return 0;
}
#pragma opt_dead_assignments reset

#pragma peephole reset
/* fzgx:end fn_1_707C */

/* fzgx:begin camera_set_entry_field_0xa8 */
void camera_set_entry_field_0xa8(u8 index, s16 value) {
    // Store the selected camera entry's parameter.
    game_camera_entries[index].unk_A8 = value;
}
/* fzgx:end camera_set_entry_field_0xa8 */

/* fzgx:begin fn_1_715C */
void fn_1_715C(u8 index, s16 value) {
    // Toggle the camera effect associated with this entry before storing its state.
    if (game_camera_entries[index].unk_A8 == 0 && index < 4) {
        if (value == 0) {
            if (lbl_1_bss_F78 == 0) {
                fn_1_A2DF4(index, (void *)(u32)(0xa5000000), 8);
                lbl_1_bss_F78 = 1;
            }
        } else if (game_camera_entries[index].unk_A4 == 0 &&
                   lbl_1_bss_F78 != 0) {
            fn_1_A2DF4(index, (void *)(u32)(0xa5000000),
                       (&lbl_1_bss_6F1E4.unk_8)[index * 10]);
            lbl_1_bss_F78 = 0;
        }
    }

    game_camera_entries[index].unk_A4 = value;
}
/* fzgx:end fn_1_715C */

/* fzgx:begin camera_get_entry_field_0xa8 */
s16 camera_get_entry_field_0xa8(u32 index) {
    // Return the selected camera entry's stored value.
    return game_camera_entries[(u8)index].unk_A8;
}
/* fzgx:end camera_get_entry_field_0xa8 */

/* fzgx:begin camera_get_entry_field_0xa4 */
s16 camera_get_entry_field_0xa4(u32 index) {
    // Return the selected camera entry's stored value.
    return game_camera_entries[(u8)index].unk_A4;
}
/* fzgx:end camera_get_entry_field_0xa4 */

/* fzgx:begin fn_1_727C */
typedef struct {
    u8 pad_0[0x48];
    s8 unk_48;
    u8 unk_49;
    u8 unk_4A;
} fn_1_727C_CameraObject;

typedef struct {
    u8 pad_0[0x10];
    u8 unk_10[0x1EC];
} fn_1_727C_CameraEntry;

typedef struct {
    u8 pad_0[0x1C];
    u8 unk_1C;
} fn_1_727C_CameraTable;

typedef struct {
    fn_1_727C_CameraObject *unk_0;
    fn_1_727C_CameraEntry *unk_4;
    fn_1_727C_CameraTable *unk_8;
} fn_1_727C_CameraState;

typedef struct {
    u32 unk_0;
    u8 pad_4[0xE];
} fn_1_727C_Obj_1_bss_6EAB4;



void fn_1_727C(void) {
    fn_1_727C_CameraState *state;
    u8 mode;
    u8 idx;

    state = (fn_1_727C_CameraState *)&(*((fn_1_727C_CameraState *)&lbl_1_bss_F68));
    mode = (s32)fn_1_86624();
    idx = state->unk_0->unk_4A;
    if (state->unk_0 == NULL) {
        return;
    }
    if (mode == 0) {
        return;
    }
    if ((*((fn_1_727C_Obj_1_bss_6EAB4 *)&lbl_1_bss_6EAB4)).unk_0 & 0x20) {
        return;
    }
    if (fn_1_3F864() == 0) {
        return;
    }
    if (fn_1_4C10() != 0) {
        return;
    }
    if (lbl_1_bss_6F244[0] == 0 || lbl_1_bss_6EAC6[0] == 0) {
        return;
    }
    switch (fn_1_3F0C8()) {
    case 0x25:
        return;
    }
    switch (state->unk_0->unk_48) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 10:
        fn_1_739C(&state->unk_4[idx].unk_10, mode, 4);
        break;
    case 9:
        fn_1_739C(&state->unk_8->unk_1C, mode, 4);
        break;
    }
}
/* fzgx:end fn_1_727C */

/* fzgx:begin camera_compare_values */
s32 camera_compare_values(const u8 *lhs_index, const u8 *rhs_index) {
    f32 *camera_values = &lbl_1_bss_6F524.unk_0;
    f32 lhs_value = camera_values[*lhs_index];
    f32 rhs_value = camera_values[*rhs_index];

    // Orders two camera indices by their associated values.
    if (lhs_value < rhs_value) {
        return -1;
    }
    if (lhs_value == rhs_value) {
        return 0;
    }
    return 1;
}
/* fzgx:end camera_compare_values */

/* fzgx:begin fn_1_8298 */
extern GameCameraEntry *game_camera_entries;  // array of 0x1FC-byte records

// Initializes camera entry selections and updates the camera mode from the available entries.
void fn_1_8298(void) {
    s8 found;
    s8 count;
    s32 i;

    found = 0;
    count = fn_1_86624();

    for (i = 0; i < 4; i++) {
        game_camera_entries[i].unk_2 = -1;
    }

    for (i = 0; i < count; i++) {
        s8 index = (s8)fn_1_86634(i);

        if (index != -1) {
            found++;
            game_camera_entries[index].unk_2 = i;
        }
    }

    switch (found) {
    case 0:
        OSPanic( (const char *)(u8 *)(lbl_1_data_3318), 0x7d2, (const char *)(u8 *)(lbl_1_data_35E8));
        break;
    case 1:
        lbl_1_bss_F68->unk_48 = 0;
        break;
    case 2:
        switch (lbl_1_bss_F68->unk_4B) {
        case 0:
            lbl_1_bss_F68->unk_48 = 1;
            break;
        case 1:
            lbl_1_bss_F68->unk_48 = 2;
            break;
        }
        break;
    case 3:
        switch (lbl_1_bss_F68->unk_4C) {
        case 0:
            lbl_1_bss_F68->unk_48 = 3;
            break;
        case 1:
            lbl_1_bss_F68->unk_48 = 4;
            break;
        case 2:
            lbl_1_bss_F68->unk_48 = 5;
            break;
        case 3:
            lbl_1_bss_F68->unk_48 = 6;
            break;
        case 4:
            lbl_1_bss_F68->unk_48 = 6;
            break;
        }
        break;
    case 4:
        lbl_1_bss_F68->unk_48 = 8;
        break;
    }
}
/* fzgx:end fn_1_8298 */

/* fzgx:begin fn_1_847C noprologue */
#include "types.h"

typedef struct {
    u8 pad_0[0x48];
    u8 unk_48;
} CameraObject;

typedef struct {
    u8 pad_0[0x6];
    s16 unk_6;
    u8 pad_8[0x4];
    u32 unk_C;
    u8 pad_10[0x8];
    s32 unk_18;
} CameraTable;

typedef struct {
    u8 pad_0[0x2];
    s16 unk_2;
} CameraEntry;

typedef struct {
    CameraObject *unk_0;
    CameraEntry *unk_4;
    CameraTable *unk_8;
    u8 pad_C[0x8];
    s8 unk_14;
} CameraState;

extern CameraState lbl_1_bss_F68;
extern s8 fn_1_86624(s8 mode);
extern s8 fn_1_86634(s32 index);

#pragma opt_propagation off
void fn_1_847C(s8 mode) {
    CameraState *state;
    s32 i;

    state = &lbl_1_bss_F68;
    state->unk_14 = fn_1_86624(mode);
    state->unk_8->unk_6 = -1;
    i = 0;
    while (i < state->unk_14) {
        if (fn_1_86634(i) == 0) {
            state->unk_8->unk_6 = (s16)i;
            break;
        }
        i++;
    }
    if (state->unk_8->unk_18 != 0) {
        state->unk_8->unk_C |= 0x100000;
    }
    if (mode == 1) {
        state->unk_0->unk_48 = 9;
    } else if (mode == 2) {
        state->unk_0->unk_48 = 10;
        state->unk_4->unk_2 = state->unk_8->unk_6;
    } else if (mode == 4) {
        state->unk_0->unk_48 = 9;
    }
}
#pragma opt_propagation reset
/* fzgx:end fn_1_847C */

/* fzgx:begin fn_1_857C */
typedef struct {
    u32 unk_0;
    u16 entries[15];
    s16 unk_22;
    u16 unk_24;
    u8 pad_26[0x1E];
    s16 unk_44;
    u16 unk_46;
    u8 unk_48;
    u8 unk_49;
    u8 unk_4A;
    u8 unk_4B;
    u8 unk_4C;
    u8 unk_4D;
    u8 pad_4E[2];
    u32 unk_50;
} fn_1_857C_CameraState;







#pragma opt_propagation off
void fn_1_857C(void) {
    s16 index;
    s16 result;

    (*(fn_1_857C_CameraState * *)&lbl_1_bss_F68)->unk_48 = 0xb;
    lbl_1_data_3310 = lbl_1_bss_7ADE8;
    fn_1_A6FE8();
    fn_1_DCE60(lbl_1_data_3310);
    fn_1_435C((*(fn_1_857C_CameraState * *)&lbl_1_bss_F68)->unk_50);
    result = (s16)fn_1_3F8C( (u32)(char *)((*(char (*)[14])&lbl_1_data_35FC)), (u32)(void *)(fn_1_DCED0), (u32)(void *)(lbl_1_data_3310), 0x14);
    {
        fn_1_857C_CameraState *camera = (*(fn_1_857C_CameraState * *)&lbl_1_bss_F68);
        index = camera->unk_22;
        camera->unk_22 = index + 1;
        camera->entries[index] = result;
    }
}
#pragma opt_propagation reset
/* fzgx:end fn_1_857C */

/* fzgx:begin camera_get_entry_field_0x2 */
// Returns the selected camera entry value for an 8-bit camera index.
s16 camera_get_entry_field_0x2(u32 index) {
    return game_camera_entries[(u8)index].unk_2;
}
/* fzgx:end camera_get_entry_field_0x2 */

/* fzgx:begin camera_set_selected_value */
// Cache the selected camera value for subsequent camera processing.
void camera_set_selected_value(u8 value) {
    lbl_1_bss_F74 = value;
}
/* fzgx:end camera_set_selected_value */

/* fzgx:begin camera_set_state_flag */
// Store the camera state flag used by subsequent camera updates.
void camera_set_state_flag(u8 value) {
    lbl_1_bss_F75 = value;
}
/* fzgx:end camera_set_state_flag */

/* fzgx:begin camera_get_values */
// Reads the camera values, falling back when the camera state cannot provide them.
s32 camera_get_values(f32 *value0, f32 *value1) {
    f32 result0;
    f32 result1;
    s32 mode;
    Obj_1_bss_F68_Target *obj;
    f32 fallback;

    obj = lbl_1_bss_F68;
    if (obj == 0) {
        mode = 0;
    } else if ((obj->unk_0 & ((u32)1 << 31)) != 0) {
        mode = 0;
    } else {
        mode = obj->unk_4A;
    }

    if (fn_1_8708(mode, &result0, &result1) != 0) {
        *value0 = result0;
        *value1 = result1;
        return 1;
    }

    fallback = (*((f32 *)&lbl_1_rodata_188));
    *value0 = fallback;
    *value1 = fallback;
    return -1;
}
/* fzgx:end camera_get_values */

/* fzgx:begin fn_1_8708 */
s32 fn_1_8708(s32 mode, f32 *value0, f32 *value1) {
    Obj_1_bss_F68_Target **pp;
    Obj_1_bss_F68_Target *obj;

    pp = &lbl_1_bss_F68;
    if (*pp == 0) {
        return -1;
    }
    obj = *pp;
    if ((obj->unk_0 & 0x80000000) != 0) {
        *value0 = lbl_1_rodata_194;
        *value1 = lbl_1_rodata_194;
        return 1;
    }
    *value0 = ((f32 (*)[2])((u8 *)obj + 0x58))[mode][0];
    *value1 = ((f32 (*)[2])((u8 *)*pp + 0x58))[mode][1];
    return 1;
}
/* fzgx:end fn_1_8708 */

/* fzgx:begin live_camera_set_shake */
// Marks the camera state active, accumulates a position delta, and tracks the highest value.
void live_camera_set_shake(s32 value, const f32 *delta) {
    LiveCamera *state;

    if (live_camera == 0) {
        OSPanic( (const char *)(u8 *)(lbl_1_data_3318), 0x89a, (const char *)(u8 *)(lbl_1_data_360C));
    }

    state = live_camera;
    state->unk_AC = 1;
    state->unk_CC += delta[0];
    state->unk_D0 += delta[1];
    state->unk_D4 += delta[2];

    if (value < 0 || (s32)state->unk_B0 < 0) {
        state->unk_B0 = -1;
    } else if ((s32)state->unk_B0 < value) {
        state->unk_B0 = value;
    }
}
/* fzgx:end live_camera_set_shake */

/* fzgx:begin fn_1_8840 */
void fn_1_8840(void) {
    LiveCamera *state;
    f32 value;

    if (live_camera == 0) {
        OSPanic( (const char *)(u8 *)(lbl_1_data_3318), 0x8b6, (const char *)(u8 *)(lbl_1_data_3630));
    }

    state = live_camera;
    value = lbl_1_rodata_188;
    state->unk_AC = 0;
    state->unk_B0 = 0;
    state->unk_C0 = value;
    state->unk_C4 = value;
    state->unk_C8 = value;
    state->unk_CC = value;
    state->unk_D0 = value;
    state->unk_D4 = value;
    state->unk_E4 = value;
    state->unk_E8 = value;
    state->unk_EC = value;
    state->unk_E4 = value;
    state->unk_E8 = value;
    state->unk_EC = value;
}
/* fzgx:end fn_1_8840 */

/* fzgx:begin game_camera_set_shake */
extern GameCameraEntry *game_camera_entries;  // array of 0x1FC-byte records

// Updates the selected camera state with a movement delta and tracks its highest value.
void game_camera_set_shake(s16 index, s16 mode, s32 value, const f32 *delta) {
    GameCameraEntry *camera;

    if (index < 0) {
        return;
    }

    if (game_camera_entries + index == 0) {
        OSPanic( (const char *)(u8 *)(lbl_1_data_3318), 0x8d1, (const char *)(u8 *)(lbl_1_data_3654));
    }

    camera = game_camera_entries + index;
    if (mode != camera->unk_2) {
        fn_1_8A0C(index);
        return;
    }

    camera->unk_10C = 1;
    camera->unk_12C += delta[0];
    camera->unk_130 += delta[1];
    camera->unk_134 += delta[2];
    camera->unk_150 += delta[2];
    camera->unk_154 += delta[1];
    camera->unk_158 += delta[0];

    if (value < 0 || (s32)camera->unk_110 < 0) {
        camera->unk_110 = -1;
    } else if ((s32)camera->unk_110 < value) {
        camera->unk_110 = value;
    }
}
/* fzgx:end game_camera_set_shake */

/* fzgx:begin fn_1_8A0C */
void fn_1_8A0C(s16 index) {
    GameCameraEntry *entry;
    f32 value;

    if (index >= 0) {
        if (game_camera_entries + index == 0) {
            OSPanic( (const char *)(u8 *)(lbl_1_data_3318), 0x8f8, (const char *)(u8 *)(lbl_1_data_3654));
        }
        entry = game_camera_entries + index;
        value = lbl_1_rodata_188;
        entry->unk_10C = 0;
        entry->unk_110 = 0;
        entry->unk_120 = value;
        entry->unk_124 = value;
        entry->unk_128 = value;
        entry->unk_12C = value;
        entry->unk_130 = value;
        entry->unk_134 = value;
        entry->unk_144 = value;
        entry->unk_148 = value;
        entry->unk_14C = value;
        entry->unk_144 = value;
        entry->unk_148 = value;
        entry->unk_14C = value;
    }
}
/* fzgx:end fn_1_8A0C */

/* fzgx:begin camera_init */
// Initialize camera state before passing the shared camera object onward.
void camera_init(void) {
    fn_1_A6FE8();
    fn_1_8D08(game_camera_entries);
}
/* fzgx:end camera_init */

/* fzgx:begin live_camera_get */
// Return the shared camera object used by the camera system.
LiveCamera *live_camera_get(void) {
    return live_camera;
}
/* fzgx:end live_camera_get */

/* fzgx:begin game_camera_get */
// Return the current camera target object.
GameCameraEntry *game_camera_get(void) {
    return game_camera_entries;
}
/* fzgx:end game_camera_get */

/* fzgx:begin fn_1_8B10 */
typedef struct CameraData {
    u8 pad_000[0x118];
    f32 x;
    f32 y;
} CameraData;

typedef struct fn_1_8B10_CameraEntry {
    f32 x;
    f32 y;
    s16 flags0;
    u8 pad_0A[2];
    f32 x1;
    f32 y1;
    s16 flags1;
    u8 pad_16[2];
    f32 x2;
    f32 y2;
    s16 flags2;
    u8 pad_22[2];
} fn_1_8B10_CameraEntry;





void fn_1_8B10(fn_1_8B10_CameraObject *camera, CameraOutput *output) {
    CameraTarget *target;
    CameraData *data;

    target = (CameraTarget *)fn_1_868C0((s8)camera->kind);
    if (camera->index == 0 && target != 0 && (data = target->data) != 0) {
        output->x0 = lbl_1_rodata_200 + data->x;
        output->y0 = data->y;
        output->flags0 = 0;
        output->x1 = lbl_1_rodata_200 + data->x;
        output->y1 = data->y;
        output->flags1 = 0;
        output->x2 = lbl_1_rodata_200 + data->x;
        output->y2 = data->y;
        output->flags2 = 0x1AAA;
    } else {
        output->x0 = (*(fn_1_8B10_CameraEntry (*)[])&lbl_1_data_36EC)[camera->index].x;
        output->y0 = (*(fn_1_8B10_CameraEntry (*)[])&lbl_1_data_36EC)[camera->index].y;
        output->flags0 = (*(fn_1_8B10_CameraEntry (*)[])&lbl_1_data_36EC)[camera->index].flags0;
        output->x1 = (*(fn_1_8B10_CameraEntry (*)[])&lbl_1_data_36EC)[camera->index].x1;
        output->y1 = (*(fn_1_8B10_CameraEntry (*)[])&lbl_1_data_36EC)[camera->index].y1;
        output->flags1 = (*(fn_1_8B10_CameraEntry (*)[])&lbl_1_data_36EC)[camera->index].flags1;
        output->x2 = (*(fn_1_8B10_CameraEntry (*)[])&lbl_1_data_36EC)[camera->index].x2;
        output->y2 = (*(fn_1_8B10_CameraEntry (*)[])&lbl_1_data_36EC)[camera->index].y2;
        output->flags2 = (*(fn_1_8B10_CameraEntry (*)[])&lbl_1_data_36EC)[camera->index].flags2;

        if ((s8)fn_1_A5DC4() != 0) {
            f32 adjust;
            switch (camera->index) {
            case 1:
                adjust = lbl_1_rodata_200;
                break;
            case 2:
                adjust = lbl_1_rodata_204;
                break;
            case 3:
                adjust = lbl_1_rodata_204;
                break;
            default:
                adjust = lbl_1_rodata_200;
                break;
            }
            output->x0 -= adjust;
            output->x1 -= adjust;
            output->x2 -= adjust;
        }
    }
}
/* fzgx:end fn_1_8B10 */

/* fzgx:begin fn_1_8D08 pool noprologue */
#include "types.h"
#include "game/main_rel/car_test_types.h"
#include "game/main_rel/car_types.h"

typedef struct Sig_fn_1_8B10_CameraOutput {
    f32 x0;
    f32 y0;
    s16 flags0;
    u8 pad_0A[2];
    f32 x1;
    f32 y1;
    s16 flags1;
    u8 pad_16[2];
    f32 x2;
    f32 y2;
    s16 flags2;
} Sig_fn_1_8B10_CameraOutput;
typedef struct Sig_fn_1_8B10_fn_1_8B10_CameraObject {
    s16 pad_00;
    s16 kind;
    u8 pad_04[0xA0];
    s16 index;
} Sig_fn_1_8B10_fn_1_8B10_CameraObject;

typedef struct fn_1_8D08_Vec { f32 x, y, z; } fn_1_8D08_Vec;

typedef struct fn_1_8D08_Camera {
    s16 unk_00;
    s16 index;            /* 0x02 */
    s16 unk_04;
    s16 angle;            /* 0x06 */
    f32 unk_08;
    f32 unk_0C;
    fn_1_8D08_Vec pos;    /* 0x10 */
    u8 pad_1C[0xC];
    fn_1_8D08_Vec look;   /* 0x28 */
    f32 mtx[3][4];        /* 0x34 */
    fn_1_8D08_Vec unk_64;
    f32 lerp;             /* 0x70 */
    u8 pad_74[4];
    s16 unk_78;
    u8 pad_7A[2];
    f32 unk_7C;
    f32 unk_80;
    f32 unk_84;
    s32 unk_88;
    fn_1_8D08_Vec target; /* 0x8C */
    fn_1_8D08_Vec unk_98;
    s16 mode;             /* 0xA4 */
    s16 prevMode;         /* 0xA6 */
    u16 unk_A8;
    u8 pad_AA[0x1E4 - 0xAA];
    fn_1_8D08_Vec unk_1E4;
    f32 unk_1F0;
    f32 unk_1F4;
    s16 unk_1F8;
    s16 unk_1FA;
} fn_1_8D08_Camera;

extern f32 fn_1_A888(fn_1_8D08_Camera *);
extern s32 fn_1_58C4(void);
extern s32 fn_1_5910(void);
extern u32 fn_1_F2F34(void);
extern void lbl_8006E1C0(fn_1_8D08_Vec *, fn_1_8D08_Vec *);
extern void mathutil_mtxA_rotate_x(s16);
extern u8 fn_1_FA4C0(void);
extern void lbl_8006DC6C(void *);
extern void fn_1_862D4(s16, fn_1_8D08_Vec *);
extern void fn_1_8636C(s16, void *);
extern void fn_1_8A0C(s16);
extern void fn_1_8B10(Sig_fn_1_8B10_fn_1_8B10_CameraObject *, Sig_fn_1_8B10_CameraOutput *);

/* Native shared literal pool, including the preceding camera literals. */
const f32 fzgx_camera_literal_0 = 0.3f;
const f32 fzgx_camera_literal_1 = 1.1f;
const u32 fzgx_camera_up_x[1] = {0};
const u32 fzgx_camera_up_y[1] = {0x3F800000};
const u32 fzgx_camera_up_z[1] = {0};
const fn_1_8D08_Vec fzgx_camera_target = {0.0f, 0.0f, 0.0f};
const u32 fzgx_camera_fwd_x[1] = {0};
const u32 fzgx_camera_fwd_y[1] = {0};
const u32 fzgx_camera_fwd_z[1] = {0xBF800000};
const f32 fzgx_camera_height[1] = {55.0f};
const f32 fzgx_camera_zero[1] = {0.0f};
const f32 fzgx_camera_distance[1] = {-10.0f};
const f64 fzgx_camera_half[1] = {0.5};

/* translate the locked-cache matrix A */
static inline void mtxA_set_translate(fn_1_8D08_Vec *v) {
    f32 x = v->x;
    f32 y = v->y;
    f32 z = v->z;
    *(f32 *)(0xE0000000 + 0x0C) = x;
    *(f32 *)(0xE0000000 + 0x1C) = y;
    *(f32 *)(0xE0000000 + 0x2C) = z;
}

/* look point: matrix A applied to (0, 0, -10) */
#define camera_update_look(cam) { \
    /* Read the scale before the locked-cache matrix column. */ \
    dist = *(volatile f32 *)fzgx_camera_distance; \
    /* Preserve locked-cache matrix access order. */ \
    x = *(volatile f32 *)(0xE0000000 + 0x08); \
    x = x * dist + *(f32 *)(0xE0000000 + 0x0C); \
    y = *(f32 *)(0xE0000000 + 0x18); \
    y = y * dist + *(f32 *)(0xE0000000 + 0x1C); \
    z = *(f32 *)(0xE0000000 + 0x28); \
    z = z * dist + *(f32 *)(0xE0000000 + 0x2C); \
    cam->look.x = x; \
    cam->look.y = y; \
    cam->look.z = z; \
}

static inline f32 fn_1_8D08_look_z(f32 distance) {
    f32 value = *(f32 *)(0xE0000000 + 0x28);
    value = value * distance + *(f32 *)(0xE0000000 + 0x2C);
    return value;
}
static inline f32 fn_1_8D08_read_pointer(fn_1_8D08_Camera * owner) { return owner->lerp; }
static inline f32 (* fn_1_8D08_read_pointer_(fn_1_8D08_Camera * owner))[4] { return owner->mtx; }
static inline f32 (* fn_1_8D08_read_pointer__(fn_1_8D08_Camera * owner))[4] { return owner->mtx; }
#pragma opt_lifetimes off
void fn_1_8D08(fn_1_8D08_Camera *cam, f32 arg1) {
    f32 z;
    f32 y;
    f32 x;
    f32 dist;
    Sig_fn_1_8B10_CameraOutput out;
    f32 mtx[3][4];
    fn_1_8D08_Vec pos;

    cam->unk_A8 = 0;
    cam->mode = 1;
    if ((u32)fn_1_58C4() == 1 && (s32)fn_1_F2F34() == 0) {
        cam->mode = fn_1_FA4C0();
    }
    cam->prevMode = cam->mode;
    fn_1_8B10((Sig_fn_1_8B10_fn_1_8B10_CameraObject *)cam, &out);
    fn_1_862D4(cam->index, &pos);
    fn_1_8636C(cam->index, fn_1_8D08_read_pointer__(cam));
    lbl_8006DC6C(fn_1_8D08_read_pointer_(cam));
    {
        f32 fzgx_lc0_z;
        f32 fzgx_lc0_y;
        f32 fzgx_lc0_x;
        /* Capture the first coordinate before the remaining matrix-translation loads. */
        fzgx_lc0_x = *(volatile f32 *)&((&pos)->x);
        fzgx_lc0_y = (&pos)->y;
        fzgx_lc0_z = (&pos)->z;
        /* Locked-cache stores must complete before copying the pool vector. */
        /* Preserve locked-cache matrix access order. */
        *(volatile f32 *)(0xE0000000 + 0x0C) = fzgx_lc0_x;
        /* Preserve locked-cache matrix access order. */
        *(volatile f32 *)(0xE0000000 + 0x1C) = fzgx_lc0_y;
        /* Preserve locked-cache matrix access order. */
        *(volatile f32 *)(0xE0000000 + 0x2C) = fzgx_lc0_z;
    }
    {
        fn_1_8D08_Vec up;
        u32 c, b, a;
        /* Ordered word copy following the locked-cache stores. */
        /* Preserve ordered vector initialization around the locked-cache accesses. */
        a = *(volatile const u32 *)fzgx_camera_up_x;
        /* Preserve ordered vector initialization around the locked-cache accesses. */
        b = *(volatile const u32 *)fzgx_camera_up_y;
        /* Preserve ordered vector initialization around the locked-cache accesses. */
        c = *(volatile const u32 *)fzgx_camera_up_z;
        /* Preserve ordered vector initialization around the locked-cache accesses. */
        ((volatile u32 *)&up)[0] = a;
        /* Preserve ordered vector initialization around the locked-cache accesses. */
        ((volatile u32 *)&up)[1] = b;
        /* Preserve ordered vector initialization around the locked-cache accesses. */
        ((volatile u32 *)&up)[2] = c;
        lbl_8006E1C0(&up, &cam->unk_64);
    }
    {
        fn_1_8D08_Vec target = fzgx_camera_target;
        target.y = out.x0;
        target.z = out.y0;
        cam->target = target;
    }
    cam->angle = out.flags0;
    cam->unk_08 = fzgx_camera_height[0];
    cam->unk_0C = arg1;
    cam->unk_84 = fzgx_camera_zero[0];
    cam->unk_78 = 0;
    cam->unk_7C = fzgx_camera_zero[0];
    cam->unk_80 = fzgx_camera_zero[0];
    cam->unk_88 = 0;
    lbl_8006DC6C(fn_1_8D08_read_pointer__(cam));
    {
        f32 fzgx_lc1_z;
        f32 fzgx_lc1_y;
        f32 fzgx_lc1_x;
        /* Capture the first coordinate before the remaining matrix-translation loads. */
        fzgx_lc1_x = *(volatile f32 *)&((&pos)->x);
        fzgx_lc1_y = (&pos)->y;
        fzgx_lc1_z = (&pos)->z;
        *(f32 *)(0xE0000000 + 0x0C) = fzgx_lc1_x;
        *(f32 *)(0xE0000000 + 0x1C) = fzgx_lc1_y;
        *(f32 *)(0xE0000000 + 0x2C) = fzgx_lc1_z;
    }
    lbl_8006E1B0((Fn183D28Vec3 *)&cam->target, (Fn183D28Vec3 *)&cam->pos);
    lbl_8006DC6C(fn_1_8D08_read_pointer__(cam));
    {
        f32 fzgx_lc2_z;
        f32 fzgx_lc2_y;
        f32 fzgx_lc2_x;
        /* Capture the first coordinate before the remaining matrix-translation loads. */
        fzgx_lc2_x = *(volatile f32 *)&((&cam->pos)->x);
        fzgx_lc2_y = (&cam->pos)->y;
        fzgx_lc2_z = (&cam->pos)->z;
        *(f32 *)(0xE0000000 + 0x0C) = fzgx_lc2_x;
        *(f32 *)(0xE0000000 + 0x1C) = fzgx_lc2_y;
        *(f32 *)(0xE0000000 + 0x2C) = fzgx_lc2_z;
    }
    mathutil_mtxA_rotate_x(cam->angle);
    camera_update_look(cam);
    cam->unk_1E4 = cam->pos;
    cam->unk_1F0 = fzgx_camera_zero[0];
    cam->unk_1F4 = fzgx_camera_zero[0];
    cam->unk_1FA = 0;
    /* Complete initialization before the ordered forward-vector copy. */
    /* Preserve ordered vector initialization around the locked-cache accesses. */
    *(volatile s16 *)&cam->unk_1F8 = -1;
    {
        u32 b, a;
        /* Preserve ordered vector initialization around the locked-cache accesses. */
        a = *(volatile const u32 *)fzgx_camera_fwd_x;
        /* Preserve ordered vector initialization around the locked-cache accesses. */
        b = *(volatile const u32 *)fzgx_camera_fwd_y;
        /* Preserve ordered vector initialization around the locked-cache accesses. */
        ((volatile u32 *)&cam->unk_98)[0] = a;
        /* Preserve ordered vector initialization around the locked-cache accesses. */
        ((volatile u32 *)&cam->unk_98)[1] = b;
        /* Preserve ordered vector initialization around the locked-cache accesses. */
        b = *(volatile const u32 *)fzgx_camera_fwd_z;
        /* Preserve ordered vector initialization around the locked-cache accesses. */
        ((volatile u32 *)&cam->unk_98)[2] = b;
    }
    {
        fn_1_8D08_Vec pos2;
        fn_1_862D4(cam->index, &pos2);
        fn_1_8636C(cam->index, mtx);
        lbl_8006DC6C(mtx);
        {
            f32 fzgx_lc3_z;
            f32 fzgx_lc3_y;
            f32 fzgx_lc3_x;
            /* Capture the first coordinate before the remaining matrix-translation loads. */
            fzgx_lc3_x = *(volatile f32 *)&((&pos2)->x);
            fzgx_lc3_y = (&pos2)->y;
            fzgx_lc3_z = (&pos2)->z;
            *(f32 *)(0xE0000000 + 0x0C) = fzgx_lc3_x;
            *(f32 *)(0xE0000000 + 0x1C) = fzgx_lc3_y;
            *(f32 *)(0xE0000000 + 0x2C) = fzgx_lc3_z;
        }
    }
    cam->lerp = fn_1_A888(cam);
    cam->unk_78 = 0;
    if (cam->mode < 5) {
        cam->target.y = cam->target.y + (f32)(cam->lerp * (out.x2 - cam->target.y));
        cam->target.z = cam->target.z + (f32)(cam->lerp * (out.y2 - cam->target.y));
        {
            f64 angle = cam->angle;
            f32 delta;
            f32 weight = fn_1_8D08_read_pointer(cam);
            f32 step;
            f64 half;
            delta = out.flags2 - cam->angle;
            step = weight * delta;
            half = step * fzgx_camera_half[0];
#pragma fp_contract off
            cam->angle = angle + half;
#pragma fp_contract on
        }
        lbl_8006DC6C(fn_1_8D08_read_pointer__(cam));
        {
            f32 fzgx_lc4_z;
            f32 fzgx_lc4_y;
            f32 fzgx_lc4_x;
            /* Capture the first coordinate before the remaining matrix-translation loads. */
            fzgx_lc4_x = *(volatile f32 *)&((&pos)->x);
            fzgx_lc4_y = (&pos)->y;
            fzgx_lc4_z = (&pos)->z;
            *(f32 *)(0xE0000000 + 0x0C) = fzgx_lc4_x;
            *(f32 *)(0xE0000000 + 0x1C) = fzgx_lc4_y;
            *(f32 *)(0xE0000000 + 0x2C) = fzgx_lc4_z;
        }
        lbl_8006E1B0((Fn183D28Vec3 *)&cam->target, (Fn183D28Vec3 *)&cam->pos);
        lbl_8006DC6C(fn_1_8D08_read_pointer__(cam));
        {
            f32 fzgx_lc5_z;
            f32 fzgx_lc5_y;
            f32 fzgx_lc5_x;
            /* Capture the first coordinate before the remaining matrix-translation loads. */
            fzgx_lc5_x = *(volatile f32 *)&((&cam->pos)->x);
            fzgx_lc5_y = (&cam->pos)->y;
            fzgx_lc5_z = (&cam->pos)->z;
            *(f32 *)(0xE0000000 + 0x0C) = fzgx_lc5_x;
            *(f32 *)(0xE0000000 + 0x1C) = fzgx_lc5_y;
            *(f32 *)(0xE0000000 + 0x2C) = fzgx_lc5_z;
        }
        mathutil_mtxA_rotate_x(cam->angle);
        {
            f32 look_z;
            /* Read the scale before the locked-cache matrix column. */
            dist = *(volatile f32 *)fzgx_camera_distance;
            /* Preserve locked-cache matrix access order. */
            x = *(volatile f32 *)(0xE0000000 + 0x08);
            x = x * dist + *(f32 *)(0xE0000000 + 0x0C);
            y = *(f32 *)(0xE0000000 + 0x18);
            /* Preserve matrix-column load order. */
            /* Preserve locked-cache matrix access order. */
            z = *(volatile f32 *)(0xE0000000 + 0x1C);
            y = y * dist + z;
            look_z = *(f32 *)(0xE0000000 + 0x28);
            look_z = look_z * dist + *(f32 *)(0xE0000000 + 0x2C);
            cam->look.x = x;
            cam->look.y = y;
            cam->look.z = look_z;
        }
    }
    fn_1_8A0C(fn_1_5910());
}
#pragma opt_lifetimes reset
/* fzgx:end fn_1_8D08 */

/* fzgx:begin fn_1_90E0 noprologue */
#include "dolphin/hw_regs.h"
#include "sdk_addresses.h"

typedef signed char s8;
typedef signed short s16;
typedef signed long s32;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef float f32;
typedef double f64;

/* lbl_1_data_3678: .data size 0xC, 1 refs from camera.c (own data block) */

typedef struct Vec3 {
f32 x;
f32 y;
f32 z;
} Vec3;
typedef struct Vec3f {
f32 x, y, z;
} Vec3f;
typedef struct camera_reset_transition_Camera {
u8 pad_00[0xA4];
s16 unk_A4;
} camera_reset_transition_Camera;
typedef struct camera_update_transition_Camera {
u8 pad_00[0x78];
s16 unk_78;
u8 pad_7A[0x2A];
s16 unk_A4;
} camera_update_transition_Camera;
typedef struct Transform {
u8 pad_08[0x8];
f32 unk_08;
u8 pad_0c[0xc];
f32 unk_18;
u8 pad_1c[0xc];
f32 unk_28;
u8 pad_2c[0x24];
u8 unk_50[0x2c];
u32 unk_7C;
} Transform;

extern void fn_1_862D4(int index, Vec3 *out);

extern void fn_8006F038(Vec3 *arg0, Vec3 *arg1, s16 arg2);

 /* fzgx-allow: S2 SDK asynchronous state */


u32 __OSCoreClock : FZGX_ADDR___OSCoreClock;

typedef struct {
u32 x;
u32 y;
u32 z;
} Triple;

typedef struct Fn1967A8Resource Fn1967A8Resource;
struct Fn1967A8Resource {
u8 unk_00;
u8 unk_01[0x07];
u32 unk_08;
u8 unk_0C[0x10];
u32 unk_1C;
};

extern void fn_1_41F58(Fn1967A8Resource *arg0, s32 arg1, void (*arg2)(void), void *arg3);

extern void fn_8006E250(Vec3f *, Vec3f *);

extern void lbl_8006DBAC(Vec3 *a);

#pragma fp_contract off
typedef struct Sig_camera_get_target_orientation_camera_get_target_orientation_CameraObject {
u8 pad_0[0xEC];
f32 unk_EC[3][4];
u8 pad_11C[0xAC];
f32 unk_1C8;
u8 pad_1CC[0x2D0];
Transform *unk_49C;
u8 pad_4A0[0x38];
f32 unk_4D8;
u8 pad_4DC[0xB0];
u32 unk_58C;
u8 pad_590[4];
f32 unk_594[3][4];
} Sig_camera_get_target_orientation_camera_get_target_orientation_CameraObject;
typedef Vec3 V90;
typedef struct M90 { f32 m[3][4]; } M90;
struct fn_1_90E0_Arg0 {
u8 pad_0[2];
s16 unk_2;
s16 unk_4, unk_6;
f32 unk_8, unk_C;
V90 unk_10, unk_1C, unk_28;
M90 unk_34;
V90 unk_64;
f32 unk_70, unk_74;
s16 unk_78;
u8 pad_7A[2];
f32 unk_7C, unk_80, unk_84;
s32 unk_88;
V90 unk_8C;
u8 pad_98[0xC];
s16 unk_A4, unk_A6, unk_A8;
u8 pad_AA[2];
M90 unk_AC, unk_DC;
u8 pad_10C[0xD4];
s32 unk_1E0;
V90 unk_1E4;
f32 unk_1F0, unk_1F4;
s16 unk_1F8, unk_1FA;
};
struct C90 {
u8 pad_0[0x50];
V90 unk_50;
u8 pad_5C[0x20];
u32 unk_7C;
u8 pad_80[0x88];
f32 unk_108;
};
typedef struct Output90 {
f32 x0, y0; s16 a0; u8 pad_A[2];
f32 x1, y1; s16 a1; u8 pad_16[2];
f32 x2, y2; s16 a2; u8 pad_22[2];
} Output90;

static const u32 fzgx_pool_rodata_lbl_1_rodata_200[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3E99999A
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_204[10] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3F8CCCCD, 0x0, 0x3F800000, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xBF800000
};
#pragma section code_type ".fzgxpool"
/* places the native literal 55.0f at retail's pool offset 0x2C */
static void fzgx_pool_literals_lbl_1_rodata_200_2C(void) {
    volatile f32 s;  /* fzgx-allow: S2 layout primer sink */
    s = 55.0f;
}
#pragma section code_type ".text"
static const u32 fzgx_pool_rodata_lbl_1_rodata_230[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_34[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0xC1200000  /* fzgx-allow: A1 retail data bytes */
};
#pragma section code_type ".fzgxpool"
/* places the native literal 0.5 at retail's pool offset 0x38 and MWCC's signed
   int-to-float constant (0x4330000080000000) at 0x40 */
static void fzgx_pool_conversion_lbl_1_rodata_200_40(void) {
    volatile s32 i;  /* fzgx-allow: S2 layout primer sink */
    volatile u8 b;  /* fzgx-allow: S2 layout primer sink */
    volatile f32 s;  /* fzgx-allow: S2 layout primer sink */
    volatile f64 d;  /* fzgx-allow: S2 layout primer sink */
    b = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200;
    b = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_204;
    b = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_230;
    b = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_34;
    d = 0.5;
    s = (f32)i;
}
#pragma section code_type ".text"
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_48[3] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0x3F800000, 0x0
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_54[3] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0x0, 0x0
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_60[3] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0x3F800000, 0x0
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_6C[3] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0x3F800000, 0x0
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_78[3] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0x0, 0x0
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_84[3] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0x40400000, 0x0
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_90[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x44BB8000
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_94[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x42540000
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_98[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x40400000
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_9C[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3C23D70A
};
#pragma section code_type ".fzgxpool"
/* places the native literals 0.05 and 4e-5f at retail's pool offsets 0xA0, 0xA8 */
static void fzgx_pool_literals_lbl_1_rodata_200_A0(void) {
    volatile f32 s;  /* fzgx-allow: S2 layout primer sink */
    volatile f64 d;  /* fzgx-allow: S2 layout primer sink */
    d = 0.05;
    s = 4e-5f;
}
#pragma section code_type ".text"
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_AC[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x42A00000
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_B0[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x42D80000
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_B4[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3FACCCCD
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_B8[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x42B40000
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_BC[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3F99999A
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_C0[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3E4CCCCD, 0x0
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_C8[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3F847AE1, 0x47AE147B
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_D0[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3D4CCCCD
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_D4[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3DCCCCCD
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_D8[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3FC33333, 0x33333333
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_2E0[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3F800000
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_E4[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x43360B61
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_E8[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3ECCCCCD, 0x0
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_F0[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3FBEB851, 0xEB851EB8
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_F8[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x459C4000, 0x0
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_100[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3FF33333, 0x33333333
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_108[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3FF66666, 0x66666666
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_110[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3FFB3333, 0x33333333
};
#pragma section code_type ".fzgxpool"
/* places the native literals 0.08, 0.2 and 0.04 at retail's pool offsets 0x118, 0x120, 0x128 */
static void fzgx_pool_literals_lbl_1_rodata_200_118(void) {
    volatile f64 d;  /* fzgx-allow: S2 layout primer sink */
    d = 0.08;
    d = 0.2;
    d = 0.04;
}
#pragma section code_type ".text"
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_130[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3F000000, 0x0
};
#pragma section code_type ".fzgxpool"
/* places the native literal 0.1 at retail's pool offset 0x138 */
static void fzgx_pool_literals_lbl_1_rodata_200_138(void) {
    volatile f64 d;  /* fzgx-allow: S2 layout primer sink */
    d = 0.1;
}
#pragma section code_type ".text"
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_140[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3FC00000
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_144[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x40133333
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_148[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3F333333, 0x0
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_150[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3FD33333, 0x33333333
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_158[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x404B8000, 0x0
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_360[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4062C000, 0x0
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_168[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x42820000
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_16C[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x39782F05
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_170[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x42700000
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_174[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3991A2B4
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_178[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x401CC28F, 0x5C28F5C3
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_180[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x40A00000
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_184[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x403C28F6
};
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_1_rodata_200(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .data objects in retail order */
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_204;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_230;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_34;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_48;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_54;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_60;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_6C;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_78;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_84;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_90;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_94;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_98;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_9C;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_AC;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_B0;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_B4;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_B8;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_BC;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_C0;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_C8;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_D0;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_D4;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_D8;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_2E0;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_E4;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_E8;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_F0;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_F8;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_100;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_108;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_110;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_130;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_140;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_144;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_148;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_150;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_158;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_360;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_168;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_16C;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_170;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_174;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_178;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_180;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_184;
}
#pragma section code_type ".text"

extern u8 lbl_1_data_3684__fzgx_offset_0[];
extern u8 lbl_1_data_3690__fzgx_offset_0[];
extern u8 lbl_1_data_3698__fzgx_offset_0[];
extern u8 lbl_1_data_36A4__fzgx_offset_0[];
extern u8 lbl_1_data_36AC__fzgx_offset_0[];
extern u8 lbl_1_data_36B8__fzgx_offset_0[];
extern u8 lbl_1_data_36C0__fzgx_offset_0[];
extern u8 lbl_1_data_36C8__fzgx_offset_0[];
static u32 fzgx_pool_data_lbl_1_data_3678[83] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x10507, 0x80C0D10, 0x12170000, 0x4F564552, 0x54414B45, 0x0, 0x4A554D50, 0x0,
    0x454E454D, 0x59484954, 0x0, 0x57414C4C, 0x48495400, 0x53494445, 0x42595349, 0x44450000,
    0x53544152, 0x54000000, 0x474F414C, 0x0, 0x4C415000, (u32)lbl_1_data_3684__fzgx_offset_0, (u32)lbl_1_data_3690__fzgx_offset_0, (u32)lbl_1_data_3698__fzgx_offset_0,
    (u32)lbl_1_data_36A4__fzgx_offset_0, (u32)lbl_1_data_36AC__fzgx_offset_0, (u32)lbl_1_data_36B8__fzgx_offset_0, (u32)lbl_1_data_36C0__fzgx_offset_0, (u32)lbl_1_data_36C8__fzgx_offset_0, 0x3FC00000, 0x0, 0xFF2C0000,
    0x3FC00000, 0x0, 0xFF2C0000, 0x3FC00000, 0x0, 0x1AAA0000, 0x403C28F6, 0x40E6147B,
    0xF7EF0000, 0x40800000, 0x40A00000, 0xFA000000, 0x404F5C29, 0x410EB852, 0x9000000, 0x40F33333,
    0x4144CCCD, 0xF2000000, 0x410CCCCD, 0x40BCCCCD, 0xEF000000, 0x40833333, 0x41100000, 0x10000000,
    0x41480000, 0x416B0A3D, 0xEE080000, 0x41480000, 0x416B0A3D, 0xEE080000, 0x41080000, 0x41A80000,
    0x13000000, 0x3FC00000, 0x40C00000, 0xFCDE0000, 0x3FE66666, 0x4089999A, 0x660000, 0x40133333,
    0x40E00000, 0x11050000, 0x40C00000, 0x41200000, 0xF4F90000, 0x40C00000, 0x4124CCCD, 0xFD080000,
    0x40923D71, 0x41711EB8, 0x11050000
};
static u32 fzgx_pool_data_lbl_1_data_3678_14C[96] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3F000000, 0x3FC00000, 0x40A00000, 0x3F000000, 0x3FC00000, 0x0, 0x20000000, 0x0,
    0xBF000000, 0x3FC00000, 0x40A00000, 0xBF000000, 0x3FC00000, 0x0, LC_BASE, 0x0,
    0x40800000, 0x41200000, 0xC1500000, 0x0, 0x3E4CCCCD, 0x41500000, 0x15550000, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0xC0800000, 0x41200000, 0xC1500000, 0x0, 0x3E4CCCCD, 0x41500000, 0xEAAB0000, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x40800000, 0x3F000000, 0x40A00000, 0x0, 0x3F666666, 0x0, 0xE380000, 0x0,
    0xC0800000, 0x3F000000, 0x40A00000, 0x80000000, 0x3F666666, 0x0, 0xF1C80000, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x41000000, 0x40400000, 0xC0A00000, 0x0, 0x40000000, 0x0, 0x0, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0xC1000000, 0x40400000, 0xC0A00000, 0x0, 0x40000000, 0x0, 0x0, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0xC0200000, 0x40000000, 0x41000000, 0xBF800000, 0x3FE66666, 0xBF800000, 0x0, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x40200000, 0x40000000, 0x41000000, 0x3F800000, 0x3FE66666, 0xBF800000, 0x0, 0x0,
    0xBFC00000, 0x40000000, 0xC0733333, 0x3E4CCCCD, 0x3FCCCCCD, 0x0, 0x0, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x3FC00000, 0x40000000, 0xC0733333, 0xBE4CCCCD, 0x3FCCCCCD, 0x0, 0x0, 0x0  /* fzgx-allow: A1 retail data bytes */
};
static u32 fzgx_pool_data_lbl_1_data_3678_2CC[4] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4E614E20, 0x63616D5F, 0x6D74780A, 0x0
};
static u32 fzgx_pool_data_lbl_1_data_3678_2DC[5] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4E614E20, 0x63616D5F, 0x6F6C645F, 0x6D74780A, 0x0
};
static u32 fzgx_pool_data_lbl_1_data_3678_2F0[4] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4E614E20, 0x63616D5F, 0x706F730A, 0x0
};
static u32 fzgx_pool_data_lbl_1_data_3678_300[4] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4E614E20, 0x63616D5F, 0x75705F76, 0x65630A00
};
static u32 fzgx_pool_data_lbl_1_data_3678_310[4] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4E614E20, 0x63616D5F, 0x696E7472, 0xA000000
};
static u32 fzgx_pool_data_lbl_1_data_3678_320[4] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4E614E20, 0x63616D5F, 0x70657273, 0xA000000
};
static u32 fzgx_pool_data_lbl_1_data_3678_330[4] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4E614E20, 0x63616D5F, 0x6173700A, 0x0
};
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_1_data_3678(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .data objects in retail order */
    s = *(u8 *)fzgx_pool_data_lbl_1_data_3678;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_3678_14C;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_3678_2CC;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_3678_2DC;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_3678_2F0;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_3678_300;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_3678_310;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_3678_320;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_3678_330;
}
#pragma section code_type ".text"

/* pool reads */
#define P32(s) (*(f32 *)((u8 *)s))
#define P64(s) (*(f64 *)((u8 *)s))
#define PV(s) (*(V90 *)((u8 *)s))
#define PVV(s) (*(volatile V90 *)((u8 *)s))  /* fzgx-allow: S2 volatile view keeps the verified load order */

extern u8 fn_1_86678(int);
extern u8 fn_1_3BB0(u32);
extern Sig_camera_get_target_orientation_camera_get_target_orientation_CameraObject *fn_1_86254(int);
extern struct C90 *fn_1_8627C(s32);
extern void fn_1_8636C(int, void *);
extern f32 fn_1_8652C(int);
extern u32 fn_1_864E8(int);
extern void fn_1_AA54(void *);
extern void fn_1_ABAC(void *);
extern void fn_1_8B10(void *, Output90 *);
extern s32 camera_get_state(void);
extern void fn_1_A888(void *);
extern void camera_get_position_delta(u32, void *);
extern s32 fn_1_8677C(u32);
extern f32 fn_1_8655C(int);
extern f32 camera_get_target_orientation(Sig_camera_get_target_orientation_camera_get_target_orientation_CameraObject *);
extern s16 fn_1_8683C(int);
extern void fn_1_869E0(int, void *);
extern f32 fn_1_86574(int);
extern s16 fn_1_7B054(void);
extern u32 fn_1_58C4(void);
extern s32 fn_1_F2F34(void);
extern void fn_1_FA450(s32);
extern void fn_1_B4D4(void *);
extern void camera_reset_transition(camera_reset_transition_Camera *);
extern void camera_update_transition(camera_update_transition_Camera *);
extern u16 fn_1_8664C(int);
extern void fn_1_A8EB0(int,int);
extern void fn_1_A8E78(void *);
extern f32 fn_1_A6FE8(void);
extern void fn_1_862A8(int,void *);
extern void fn_1_549F4(void *,void *,f32,f32,f32,f32);
extern void fn_1_54DCC(void *);
extern void lbl_8006DAEC(void);
extern void fn_80008C20(void *,void *,void *);
extern void lbl_8006DB74(void *);
extern void lbl_8006DC6C(void *);
extern void fn_8006E2B0(void *,void *);
extern void fn_8006EE70(void *,void *);
extern void fn_8006EFB4(void *,void *,f32);
extern void lbl_8006DB30(void);
extern void lbl_8006E1C0(void *,void *);
extern void lbl_8006DD14(void *,void *);
extern void mathutil_mtxA_rotate_y(s32);
extern void fn_80008DB4(void *,void *,void *,f32);
extern void lbl_8006E1B0(void *,void *);
extern void mathutil_mtxA_rotate_x(s16);
extern void lbl_8006D5A4(void *,void *,void *,f32);
extern void lbl_8006E0B4(f32,f32,f32);
extern s32 fn_80007D58(void *);
extern s32 fn_80007CDC(void *);
extern void lbl_8006D784(void *);
extern void fn_8006EDBC(void *,void *,s16 *,s16 *);
extern void lbl_8006D1BC(s16,f32 *,f32 *);
extern void lbl_8006D8E4(f32,f32);
extern void mathutil_mtxA_rotate_x__fzgx_offset_C(f32,f32);
/* case 3's camera object */
#define OBJ90 ((Sig_camera_get_target_orientation_camera_get_target_orientation_CameraObject *)v3)
extern s16 lbl_8006D24C(f32,f32);
extern void fn_8006F1F0(void *,void *,void *);
extern void fn_8006F4E0(void *);
static inline int bad90(f32 x) {
return (*(u32 *)&x & 0x7F800000) == 0x7F800000;
}
static inline void set90(V90 *v, f32 x, f32 y, f32 z) {
v->x = x;
v->y = y;
v->z = z;
}
static inline void trans90(V90 *v) {
struct { u32 value; } fzgx_lc;
f32 x = *(volatile f32 *)&v->x;  /* fzgx-allow: S2 volatile view keeps the verified load order */
f32 y = v->y;
f32 z = v->z;
fzgx_lc.value = LC_BASE;
((volatile f32 *)fzgx_lc.value)[3] = x;  /* fzgx-allow: S2 volatile view keeps the verified load order */
((volatile f32 *)fzgx_lc.value)[7] = y;  /* fzgx-allow: S2 volatile view keeps the verified load order */
((volatile f32 *)fzgx_lc.value)[11] = z;  /* fzgx-allow: S2 volatile view keeps the verified load order */
}
/* mtxA column 2 scaled plus the translation column */
static inline void project90(V90 *v, f32 scale) {
f32 x, cx, y, cy, z, cz;
x = ((f32 *)LC_BASE)[2];
cx = ((f32 *)LC_BASE)[3];
y = ((f32 *)LC_BASE)[6];
cy = ((f32 *)LC_BASE)[7];
z = ((f32 *)LC_BASE)[10];
cz = ((f32 *)LC_BASE)[11];
x = __fmadds(x, scale, cx);
y = __fmadds(y, scale, cy);
z = __fmadds(z, scale, cz);
v->x = x;
v->y = y;
v->z = z;
}
/* eased approach rate: shrinks as `cur` nears 3.0, clamped to [0.08, hi] */
#define RATE90(cur) (0.2 - 0.04 * (f32)(P32(fzgx_pool_rodata_lbl_1_rodata_200_98) - (cur)))
#define CLAMP90(cur, hi) ((RATE90(cur) < 0.08) ? 0.08 : (RATE90(cur) > (hi)) ? (hi) : RATE90(cur))
/* speed-dependent fov blend rate, clamped to [0.01, 0.05] */
#define FOVRATE90(speed) (0.05 - 4e-5f * (speed))
#pragma opt_propagation off
#pragma opt_lifetimes off
#pragma opt_dead_assignments on
static inline void fn_1_90E0_call_lbl_8006E0B4(f32 a0, f32 a1, f32 a2) { lbl_8006E0B4(a0, a1, a2); }
#pragma opt_propagation on
#pragma opt_lifetimes on
static inline void camera_get_transition_target90(struct fn_1_90E0_Arg0 *camera, Output90 *output, signed int *target) {
*target = (signed int)fn_1_86254(camera->unk_2);
fn_1_8B10(camera, output);
}
#pragma opt_propagation off
#pragma opt_lifetimes off
void fn_1_90E0(struct fn_1_90E0_Arg0 *arg0) {
register struct { Sig_camera_get_target_orientation_camera_get_target_orientation_CameraObject *value; } obj3;
register Sig_camera_get_target_orientation_camera_get_target_orientation_CameraObject *t3;
s8 v0;
s32 v1;
u32 v2;
signed int v3;
register struct { Sig_camera_get_target_orientation_camera_get_target_orientation_CameraObject *value; } target_state90;
s16 v4;
M90 loc_134;
Output90 loc_110;
M90 loc_E0;
Triple loc_D4;
V90 loc_C8;
V90 loc_BC;
V90 loc_B0;
V90 loc_A4;
V90 loc_98;
V90 loc_8C;
V90 loc_80;
V90 loc_74;
V90 loc_68;
V90 loc_5C;
V90 loc_50;
s16 loc_30[4];
s16 loc_28[4];
f32 loc_24, loc_20, loc_1C, loc_18;
s16 loc_A, loc_8;
struct C90 *t4;
f32 t7;
u32 t8;
f32 x, y, fov, k;
f32 fovt;
f32 rate;
s16 angle;
register u8 *entry;
register union {
s32 invalid;
Sig_camera_get_target_orientation_camera_get_target_orientation_CameraObject *object;
} transition_state90;
#define bad transition_state90.invalid

v0 = (s8)fn_1_86678(arg0->unk_2);
if ((u32)v0 == 0xFFFFFFFF) {
v1 = 0;
} else {
switch (fn_1_3BB0(v0) & 0xFF) {
case 2: case 3: case 4: v1 = 1; break;
default: v1 = 0; break;
}
}
lbl_8006DAEC();
arg0->unk_1C = arg0->unk_10;
t3 = fn_1_86254(arg0->unk_2);
t4 = fn_1_8627C(arg0->unk_2);
fn_1_862D4(arg0->unk_2, (Vec3 *)&loc_D4);
fn_1_8636C(arg0->unk_2, &loc_134);
t7 = fn_1_8652C(arg0->unk_2);
t8 = fn_1_864E8(arg0->unk_2);
if (t4) {
if (t4->unk_7C & 0x1000000) v3 = 1;
else v3 = 0;
} else v3 = 0;
fn_1_AA54(arg0);
switch (arg0->unk_A8) {
case 0: {
arg0->unk_1E0 = 0;
fn_1_ABAC(arg0);
fn_1_8B10(arg0, &loc_110);
fovt = ((t7) < (P32(fzgx_pool_rodata_lbl_1_rodata_230))) ? (P32(fzgx_pool_rodata_lbl_1_rodata_230)) : (t7) > (P32(fzgx_pool_rodata_lbl_1_rodata_200_90)) ? (P32(fzgx_pool_rodata_lbl_1_rodata_200_90)) : (t7) ;
if (bad90(fovt)) fovt = P32(fzgx_pool_rodata_lbl_1_rodata_230) ;
fovt /= P32(fzgx_pool_rodata_lbl_1_rodata_200_90) ;
fov = P32(fzgx_pool_rodata_lbl_1_rodata_200_94) * (f32)(fovt * fovt);
x = loc_110.x0 + (f32)(fovt * (loc_110.x1 - loc_110.x0));
y = loc_110.y0 + (f32)(fovt * (loc_110.y1 - loc_110.y0));
angle = loc_110.a0 + (f32)(fovt * (loc_110.a1 - loc_110.a0));
if ((s8)camera_get_state() == 1) fov /= P32(fzgx_pool_rodata_lbl_1_rodata_200_98) ;
fov = 55.0f + fov;
if (arg0->unk_A4 == 3) {
fov = 55.0f;
x = loc_110.x0;
y = loc_110.y0;
angle = loc_110.a0;
}
if (arg0->unk_A4 < 5) {
fn_1_A888(arg0);
x += (f32)(arg0->unk_70 * (loc_110.x2 - x));
y += (f32)(arg0->unk_70 * (loc_110.y2 - y));
angle = angle + (f32)(arg0->unk_70 * (loc_110.a2 - angle)) / 2.0;
}
rate = (FOVRATE90(t7) < P32(fzgx_pool_rodata_lbl_1_rodata_200_9C)) ? P32(fzgx_pool_rodata_lbl_1_rodata_200_9C) : (FOVRATE90(t7) > 0.05) ? 0.05 : FOVRATE90(t7);
if (t8 & 0x400040) {
arg0->unk_74 = (((f32)(arg0->unk_8 * P32(fzgx_pool_rodata_lbl_1_rodata_200_B4))) < (P32(fzgx_pool_rodata_lbl_1_rodata_200_AC)) ? (P32(fzgx_pool_rodata_lbl_1_rodata_200_AC)) : ((f32)(arg0->unk_8 * P32(fzgx_pool_rodata_lbl_1_rodata_200_B4))) > (P32(fzgx_pool_rodata_lbl_1_rodata_200_B0)) ? (P32(fzgx_pool_rodata_lbl_1_rodata_200_B0)) : ((f32)(arg0->unk_8 * P32(fzgx_pool_rodata_lbl_1_rodata_200_B4)))) ;
if ((s8)camera_get_state() == 1)
arg0->unk_74 = (((f32)(arg0->unk_8 * P32(fzgx_pool_rodata_lbl_1_rodata_200_BC))) < (arg0->unk_8) ? (arg0->unk_8) : ((f32)(arg0->unk_8 * P32(fzgx_pool_rodata_lbl_1_rodata_200_BC))) > (P32(fzgx_pool_rodata_lbl_1_rodata_200_B8)) ? (P32(fzgx_pool_rodata_lbl_1_rodata_200_B8)) : ((f32)(arg0->unk_8 * P32(fzgx_pool_rodata_lbl_1_rodata_200_BC)))) ;
} else if ((t8 & 0x20) && arg0->unk_A4 != 3) {
if (arg0->unk_88 < 20) arg0->unk_88++;
if (arg0->unk_88 > 10) {
if (arg0->unk_84 < t7)
arg0->unk_8 = ((arg0->unk_8) + (f32)((P32(fzgx_pool_rodata_lbl_1_rodata_200_C0)) * ((arg0->unk_74) - (arg0->unk_8)))) ;
else
arg0->unk_8 = ((f32)((arg0->unk_8) + ((fov) - (arg0->unk_8)) * (P64(fzgx_pool_rodata_lbl_1_rodata_200_C8)))) ;
arg0->unk_84 = t7;
} else {
if (arg0->unk_A4 == 2)
arg0->unk_8 = ((arg0->unk_8) + (f32)((P32(fzgx_pool_rodata_lbl_1_rodata_200_D0)) * ((P32(fzgx_pool_rodata_lbl_1_rodata_200_AC)) - (arg0->unk_8)))) ;
else
arg0->unk_8 = ((arg0->unk_8) + (f32)((P32(fzgx_pool_rodata_lbl_1_rodata_200_D4)) * ((P32(fzgx_pool_rodata_lbl_1_rodata_200_AC)) - (arg0->unk_8)))) ;
if ((s8)camera_get_state() == 1)
arg0->unk_8 = ((arg0->unk_8) + (f32)((P32(fzgx_pool_rodata_lbl_1_rodata_200_D4)) * ((fov) - (arg0->unk_8)))) ;
}
} else {
if (arg0->unk_88 > 0) arg0->unk_88--;
if (arg0->unk_88 > 10) {
if (arg0->unk_84 < t7)
arg0->unk_8 = ((arg0->unk_8) + (f32)((P32(fzgx_pool_rodata_lbl_1_rodata_200_C0)) * ((arg0->unk_74) - (arg0->unk_8)))) ;
else
arg0->unk_8 = ((f32)((arg0->unk_8) + ((fov) - (arg0->unk_8)) * (P64(fzgx_pool_rodata_lbl_1_rodata_200_C8)))) ;
arg0->unk_84 = t7;
} else
arg0->unk_8 = ((arg0->unk_8) + (f32)((rate) * ((fov) - (arg0->unk_8)))) ;
}
arg0->unk_8C.y = ((f32)((arg0->unk_8C.y) + ((x) - (arg0->unk_8C.y)) * (P64(fzgx_pool_rodata_lbl_1_rodata_200_D8)))) ;
arg0->unk_8C.z = ((f32)((arg0->unk_8C.z) + ((y) - (arg0->unk_8C.z)) * (P64(fzgx_pool_rodata_lbl_1_rodata_200_D8)))) ;
arg0->unk_6 = arg0->unk_6 + P64(fzgx_pool_rodata_lbl_1_rodata_200_D8) * (angle - arg0->unk_6);
camera_get_position_delta((u8)arg0->unk_2, &loc_B0);
if (!v1 && fn_1_8677C(arg0->unk_2) == 1 && arg0->unk_A4 != 0 && !(t8 & 0x100)) {
fn_80008C20(&arg0->unk_10, &arg0->unk_64, &loc_B0);
lbl_8006DB74(&loc_E0);
} else if ((t8 & 2) && arg0->unk_A4 != 0 && P32(fzgx_pool_rodata_lbl_1_rodata_230) == t3->unk_1C8) {
lbl_8006DC6C(&loc_134);
fn_8006E2B0(&loc_B0, &loc_B0);
fn_8006EE70(&loc_B0, &loc_28);
if (loc_28[0] > -0x100) loc_28[0] = -0x100;
if (loc_28[0] < -0x500) loc_28[0] = -0x500;
if (loc_28[1] > 100) loc_28[1] = 100;
if (loc_28[1] < -100) loc_28[1] = -100;
lbl_8006DAEC();
fn_8006EFB4(&loc_28, &loc_B0, P32(fzgx_pool_rodata_lbl_1_rodata_2E0) );
lbl_8006DB30();
lbl_8006E1C0(&loc_B0, &loc_B0);
fn_80008C20(&arg0->unk_10, &arg0->unk_64, &loc_B0);
lbl_8006DB74(&loc_E0);
} else {
lbl_8006DD14(&loc_134, &loc_E0);
}
lbl_8006DBAC((Vec3 *)&loc_E0);
mathutil_mtxA_rotate_y((s32)(P32(fzgx_pool_rodata_lbl_1_rodata_200_E4) * (s16)(s32)(P32(fzgx_pool_rodata_lbl_1_rodata_200_E8) * t3->unk_4D8)));
lbl_8006DB74(&loc_E0);
k = (((f32)(t7 / P32(fzgx_pool_rodata_lbl_1_rodata_200_F8))) < 0.05) ? 0.05 : ((f32)(t7 / P32(fzgx_pool_rodata_lbl_1_rodata_200_F8))) > (P64(fzgx_pool_rodata_lbl_1_rodata_200_F0)) ? (P64(fzgx_pool_rodata_lbl_1_rodata_200_F0)) : ((f32)(t7 / P32(fzgx_pool_rodata_lbl_1_rodata_200_F8))) ;
k *= fn_1_8655C(arg0->unk_2);
if (arg0->unk_A4 == 2) k *= P64(fzgx_pool_rodata_lbl_1_rodata_200_100) ;
if (arg0->unk_A4 == 3) k *= P64(fzgx_pool_rodata_lbl_1_rodata_200_108) ;
if (arg0->unk_A4 == 0) k = P32(fzgx_pool_rodata_lbl_1_rodata_200_C0) ;
if (v3) {
camera_get_target_orientation(t3);
k = P32(fzgx_pool_rodata_lbl_1_rodata_200_C0) ;
}
if (fn_1_8683C(arg0->unk_2) == 0)
fn_80008DB4(&arg0->unk_34, &loc_E0, &arg0->unk_34, k);
lbl_8006DC6C(&arg0->unk_34);
trans90((V90 *)&loc_D4);
lbl_8006E1B0(&arg0->unk_8C, &arg0->unk_10);
trans90(&arg0->unk_10);
mathutil_mtxA_rotate_x(arg0->unk_6);
#pragma fp_contract on
project90(&arg0->unk_28, P32(fzgx_pool_rodata_lbl_1_rodata_200_34) );
#pragma fp_contract off
if (fn_1_8683C(arg0->unk_2) != 0)
fn_1_869E0(arg0->unk_2, &loc_C8);
else {
lbl_8006DC6C(&loc_134);
trans90((V90 *)&loc_D4);
loc_C8 = PVV(fzgx_pool_rodata_lbl_1_rodata_200_48) ;
lbl_8006E1C0(&loc_C8, &loc_C8);
}
v2 = t8 & 2;
k = P32(fzgx_pool_rodata_lbl_1_rodata_200_D4) ;
if (v2) k = P32(fzgx_pool_rodata_lbl_1_rodata_200) ;
k *= fn_1_86574(arg0->unk_2);
if (arg0->unk_A4 == 2) k *= P64(fzgx_pool_rodata_lbl_1_rodata_200_100) ;
if (arg0->unk_A4 == 3) k *= P64(fzgx_pool_rodata_lbl_1_rodata_200_110) ;
if (arg0->unk_A4 == 0) k = P32(fzgx_pool_rodata_lbl_1_rodata_200_C0) ;
lbl_8006D5A4(&arg0->unk_64, &loc_C8, &arg0->unk_64, k);
if (arg0->unk_A4 == 1 || arg0->unk_A4 == 2 || arg0->unk_A4 == 4) {
s32 active = 0;
if (v2) {
if (arg0->unk_78 < 5) arg0->unk_78++;
} else arg0->unk_78 = 0;
if (arg0->unk_78 > 1) active = 1;
if (active) {
s32 special;
if (v3) goto special_camera90; /* Keep the verified branch to special_camera90. */
{
s16 c = fn_1_7B054();
special = 0;
if (c == 0x21 || c == 0x57) special = 1;
}
if (special) {
special_camera90:
switch (arg0->unk_A4) {
case 4:
arg0->unk_7C += (-P32(fzgx_pool_rodata_lbl_1_rodata_200_130) - arg0->unk_7C) * CLAMP90(arg0->unk_7C, 0.2);
arg0->unk_80 += (P32(fzgx_pool_rodata_lbl_1_rodata_200_130) - arg0->unk_80) * CLAMP90(arg0->unk_80, 0.2);
break;
case 1:
arg0->unk_7C += (-P32(fzgx_pool_rodata_lbl_1_rodata_200_140) - arg0->unk_7C) * CLAMP90(arg0->unk_7C, 0.1);
arg0->unk_80 += (P32(fzgx_pool_rodata_lbl_1_rodata_200_140) - arg0->unk_80) * CLAMP90(arg0->unk_80, 0.1);
break;
case 2:
arg0->unk_7C += (f32)(P32(fzgx_pool_rodata_lbl_1_rodata_200_C0) * (-P32(fzgx_pool_rodata_lbl_1_rodata_200_144) - arg0->unk_7C));
arg0->unk_80 += (f32)(P32(fzgx_pool_rodata_lbl_1_rodata_200_C0) * (P32(fzgx_pool_rodata_lbl_1_rodata_200_144) - arg0->unk_80));
break;
default:
arg0->unk_7C += (f32)(P32(fzgx_pool_rodata_lbl_1_rodata_200_C0) * (-P32(fzgx_pool_rodata_lbl_1_rodata_200_144) - arg0->unk_7C));
arg0->unk_80 += (f32)(P32(fzgx_pool_rodata_lbl_1_rodata_200_C0) * (P32(fzgx_pool_rodata_lbl_1_rodata_200_144) - arg0->unk_80));
break;
}
} else {
switch (arg0->unk_A4) {
case 4:
arg0->unk_7C += (P32(fzgx_pool_rodata_lbl_1_rodata_200_130) - arg0->unk_7C) * CLAMP90(arg0->unk_7C, 0.2);
arg0->unk_80 += (P32(fzgx_pool_rodata_lbl_1_rodata_200_130) - arg0->unk_80) * CLAMP90(arg0->unk_80, 0.2);
break;
case 1:
arg0->unk_7C += (P32(fzgx_pool_rodata_lbl_1_rodata_200_140) - arg0->unk_7C) * CLAMP90(arg0->unk_7C, 0.2);
arg0->unk_80 += (P32(fzgx_pool_rodata_lbl_1_rodata_200_140) - arg0->unk_80) * CLAMP90(arg0->unk_80, 0.2);
break;
case 2:
arg0->unk_7C += (f32)(P32(fzgx_pool_rodata_lbl_1_rodata_200_C0) * (P32(fzgx_pool_rodata_lbl_1_rodata_200_144) - arg0->unk_7C));
arg0->unk_80 += (f32)(P32(fzgx_pool_rodata_lbl_1_rodata_200_C0) * (P32(fzgx_pool_rodata_lbl_1_rodata_200_144) - arg0->unk_80));
break;
default:
arg0->unk_7C += (f32)(P32(fzgx_pool_rodata_lbl_1_rodata_200_C0) * (P32(fzgx_pool_rodata_lbl_1_rodata_200_144) - arg0->unk_7C));
arg0->unk_80 += (f32)(P32(fzgx_pool_rodata_lbl_1_rodata_200_C0) * (P32(fzgx_pool_rodata_lbl_1_rodata_200_144) - arg0->unk_80));
break;
}
}
} else {
arg0->unk_7C += (f32)(P32(fzgx_pool_rodata_lbl_1_rodata_200_D0) * -arg0->unk_7C);
arg0->unk_80 += (f32)(P32(fzgx_pool_rodata_lbl_1_rodata_200_D0) * -arg0->unk_80);
}
lbl_8006DC6C(&arg0->unk_34);
trans90((V90 *)&loc_D4);
loc_A4 = arg0->unk_8C;
loc_A4.y -= arg0->unk_7C;
lbl_8006E1B0(&loc_A4, &arg0->unk_10);
fn_8006E250((Vec3f *)&arg0->unk_28, (Vec3f *)&loc_A4);
loc_A4.y -= (f32)(arg0->unk_80 * P32(fzgx_pool_rodata_lbl_1_rodata_200_148) );
lbl_8006E1B0(&loc_A4, &arg0->unk_28);
}
if (fn_1_58C4() == 1 && fn_1_F2F34() == 0) fn_1_FA450(arg0->unk_A6);
fn_1_B4D4(arg0);
break;
}
case 1: {
register u8 *entry;
fn_1_ABAC(arg0);
entry = (u8 *)fzgx_pool_data_lbl_1_data_3678_14C;
entry += arg0->unk_A4 * 0x20;
lbl_8006DC6C(&loc_134);
trans90((V90 *)&loc_D4);
lbl_8006E1B0(entry, &arg0->unk_10);
lbl_8006E1B0(entry + 0xC, &arg0->unk_28);
arg0->unk_8 = ((f32)((arg0->unk_8) + ((P64(fzgx_pool_rodata_lbl_1_rodata_200_158)) - (arg0->unk_8)) * (P64(fzgx_pool_rodata_lbl_1_rodata_200_150)))) ;
break;
case 2:
if (!arg0->unk_1E0) camera_reset_transition((camera_reset_transition_Camera *)arg0);
camera_update_transition((camera_update_transition_Camera *)arg0);
arg0->unk_1E0++;
break;
case 3: {
#define obj3 target_state90
if (P64(fzgx_pool_rodata_lbl_1_rodata_360) == fn_1_8664C(arg0->unk_2)) {
arg0->unk_1E4 = arg0->unk_10;
arg0->unk_1F0 = P32(fzgx_pool_rodata_lbl_1_rodata_230) ;
arg0->unk_1F4 = P32(fzgx_pool_rodata_lbl_1_rodata_230) ;
}
entry = (u8 *)fn_1_86254(arg0->unk_2);
fn_1_8B10(arg0, &loc_110);
{
#undef OBJ90
#define OBJ90 ((Sig_camera_get_target_orientation_camera_get_target_orientation_CameraObject *)entry)
{
V90 v = PV(fzgx_pool_rodata_lbl_1_rodata_200_54) ;
v.y = loc_110.x0;
v.z = loc_110.y0;
loc_80 = v;
}
lbl_8006DBAC((Vec3 *)(entry + (s32)&((Sig_camera_get_target_orientation_camera_get_target_orientation_CameraObject *)0)->unk_594));
lbl_8006E1B0(&loc_80, &loc_BC);
loc_C8 = PV(fzgx_pool_rodata_lbl_1_rodata_200_60) ;
lbl_8006E1C0(&loc_C8, &loc_C8);
lbl_8006DC6C(&loc_134);
trans90((V90 *)&loc_D4);
lbl_8006E1B0(&loc_80, &loc_8C);
trans90(&loc_8C);
mathutil_mtxA_rotate_x(loc_110.a0);
#pragma fp_contract on
project90(&loc_98, P32(fzgx_pool_rodata_lbl_1_rodata_200_34) );
#pragma fp_contract off
if ((f32)(u32)(fn_1_8664C(arg0->unk_2) - 20) < P32(fzgx_pool_rodata_lbl_1_rodata_200_168) ) arg0->unk_1F4 -= P32(fzgx_pool_rodata_lbl_1_rodata_200_16C) ;
else arg0->unk_1F4 += P32(fzgx_pool_rodata_lbl_1_rodata_200_16C) ;
arg0->unk_1F0 += arg0->unk_1F4;
arg0->unk_1F0 = ((arg0->unk_1F0) < (P32(fzgx_pool_rodata_lbl_1_rodata_230)) ? (P32(fzgx_pool_rodata_lbl_1_rodata_230)) : (arg0->unk_1F0) > (P32(fzgx_pool_rodata_lbl_1_rodata_2E0)) ? (P32(fzgx_pool_rodata_lbl_1_rodata_2E0)) : (arg0->unk_1F0)) ;
lbl_8006D5A4(&arg0->unk_1E4, &loc_BC, &arg0->unk_10, arg0->unk_1F0);
lbl_8006D5A4(&arg0->unk_28, &loc_98, &arg0->unk_28, P32(fzgx_pool_rodata_lbl_1_rodata_200_C0) );
lbl_8006D5A4(&arg0->unk_64, &loc_C8, &arg0->unk_64, P32(fzgx_pool_rodata_lbl_1_rodata_200_C0) );
lbl_8006DD14((void *)(entry + (s32)&((Sig_camera_get_target_orientation_camera_get_target_orientation_CameraObject *)0)->unk_EC), &arg0->unk_34);
arg0->unk_8 = ((f32)((arg0->unk_8) + ((P64(fzgx_pool_rodata_lbl_1_rodata_200_158)) - (arg0->unk_8)) * (P64(fzgx_pool_rodata_lbl_1_rodata_200_150)))) ;
break;
}
}
}
case 5:
if (!(t3->unk_58C & 0x10))
lbl_8006D5A4(&arg0->unk_28, &loc_D4, &arg0->unk_28, P32(fzgx_pool_rodata_lbl_1_rodata_200_C0) );
fn_1_B4D4(arg0);
break;
case 6: {
if (arg0->unk_1F8 < 0) {
arg0->unk_1E4 = arg0->unk_10;
arg0->unk_1F0 = P32(fzgx_pool_rodata_lbl_1_rodata_230) ;
arg0->unk_1F4 = P32(fzgx_pool_rodata_lbl_1_rodata_230) ;
arg0->unk_1F8 = 120;
}
if (arg0->unk_1F8) arg0->unk_1F8--;
t3 = fn_1_86254(arg0->unk_2);
lbl_8006DC6C(&loc_134);
trans90((V90 *)&loc_D4);
loc_C8 = PVV(fzgx_pool_rodata_lbl_1_rodata_200_6C) ;
lbl_8006E1C0(&loc_C8, &loc_C8);
arg0->unk_A4 = 5;
fn_1_8B10(arg0, &loc_110);
{
V90 v = PV(fzgx_pool_rodata_lbl_1_rodata_200_78) ;
v.y = loc_110.x0;
v.z = loc_110.y0;
loc_68 = v;
}
fn_80008C20(&loc_D4, &loc_C8, &t4->unk_50);
if (!(t4->unk_7C & 0x1000000))
fn_1_90E0_call_lbl_8006E0B4(-t4->unk_108, P32(fzgx_pool_rodata_lbl_1_rodata_230) , P32(fzgx_pool_rodata_lbl_1_rodata_230) );
lbl_8006E1B0(&loc_68, &loc_BC);
lbl_8006DC6C(&loc_134);
trans90((V90 *)&loc_D4);
loc_68 = PVV(fzgx_pool_rodata_lbl_1_rodata_200_84) ;
lbl_8006E1B0(&loc_68, &loc_74);
if ((f32)(u32)arg0->unk_1F8 < P32(fzgx_pool_rodata_lbl_1_rodata_200_170) ) arg0->unk_1F4 -= P32(fzgx_pool_rodata_lbl_1_rodata_200_174) ;
else arg0->unk_1F4 += P32(fzgx_pool_rodata_lbl_1_rodata_200_174) ;
arg0->unk_1F0 += arg0->unk_1F4;
arg0->unk_1F0 = ((arg0->unk_1F0) < (P32(fzgx_pool_rodata_lbl_1_rodata_230)) ? (P32(fzgx_pool_rodata_lbl_1_rodata_230)) : (arg0->unk_1F0) > (P32(fzgx_pool_rodata_lbl_1_rodata_2E0)) ? (P32(fzgx_pool_rodata_lbl_1_rodata_2E0)) : (arg0->unk_1F0)) ;
if (arg0->unk_1F8 == 0) arg0->unk_1F0 = P32(fzgx_pool_rodata_lbl_1_rodata_2E0) ;
lbl_8006D5A4(&arg0->unk_1E4, &loc_BC, &arg0->unk_10, arg0->unk_1F0);
lbl_8006D5A4(&arg0->unk_28, &loc_74, &arg0->unk_28, P32(fzgx_pool_rodata_lbl_1_rodata_200_C0) );
lbl_8006D5A4(&arg0->unk_64, &loc_C8, &arg0->unk_64, P32(fzgx_pool_rodata_lbl_1_rodata_200_C0) );
lbl_8006DD14(&t3->unk_EC, &arg0->unk_34);
arg0->unk_8 = ((f32)((arg0->unk_8) + ((P64(fzgx_pool_rodata_lbl_1_rodata_200_158)) - (arg0->unk_8)) * (P64(fzgx_pool_rodata_lbl_1_rodata_200_150)))) ;
fn_1_B4D4(arg0);
break;
}
}
bad = 0;
fn_1_A8EB0(20,5);
if (fn_80007D58(&arg0->unk_DC)) { fn_1_A8E78(((u8 *)fzgx_pool_data_lbl_1_data_3678_2CC)); bad = 1; }
if (fn_80007D58(&arg0->unk_AC)) { fn_1_A8E78(((u8 *)fzgx_pool_data_lbl_1_data_3678_2DC)); bad = 1; }
if (fn_80007CDC(&arg0->unk_10)) { fn_1_A8E78(((u8 *)fzgx_pool_data_lbl_1_data_3678_2F0)); bad = 1; }
if (fn_80007CDC(&arg0->unk_64)) { fn_1_A8E78(((u8 *)fzgx_pool_data_lbl_1_data_3678_300)); bad = 1; }
if (fn_80007CDC(&arg0->unk_28)) { fn_1_A8E78(((u8 *)fzgx_pool_data_lbl_1_data_3678_310)); bad = 1; }
if (bad90(arg0->unk_8)) { fn_1_A8E78(((u8 *)fzgx_pool_data_lbl_1_data_3678_320)); bad = 1; }
if (bad90(arg0->unk_C)) { fn_1_A8E78(((u8 *)fzgx_pool_data_lbl_1_data_3678_330)); bad = 1; }
if (bad) {
lbl_8006D784(&arg0->unk_DC);
lbl_8006D784(&arg0->unk_AC);
lbl_8006D784(&arg0->unk_34);
set90(&arg0->unk_10, P32(fzgx_pool_rodata_lbl_1_rodata_230) , P32(fzgx_pool_rodata_lbl_1_rodata_200_184) , P64(fzgx_pool_rodata_lbl_1_rodata_200_178) + (f32)(P32(fzgx_pool_rodata_lbl_1_rodata_200_180) *arg0->unk_2));
set90(&arg0->unk_1C, P32(fzgx_pool_rodata_lbl_1_rodata_230) , P32(fzgx_pool_rodata_lbl_1_rodata_200_184) , P64(fzgx_pool_rodata_lbl_1_rodata_200_178) + (f32)(P32(fzgx_pool_rodata_lbl_1_rodata_200_180) *arg0->unk_2));
set90(&arg0->unk_28, P32(fzgx_pool_rodata_lbl_1_rodata_230) , P32(fzgx_pool_rodata_lbl_1_rodata_2E0) , P32(fzgx_pool_rodata_lbl_1_rodata_200_180) *arg0->unk_2);
arg0->unk_64.x = P32(fzgx_pool_rodata_lbl_1_rodata_230) ;
arg0->unk_64.y = P32(fzgx_pool_rodata_lbl_1_rodata_2E0) ;
arg0->unk_64.z = P32(fzgx_pool_rodata_lbl_1_rodata_230) ;
arg0->unk_8 = 55.0f;
arg0->unk_C = fn_1_A6FE8();
}
lbl_8006DD14(&arg0->unk_DC, &arg0->unk_AC);
if (arg0->unk_A8 == 2) {
fn_1_862A8(arg0->unk_2, &loc_50);
fn_8006EDBC(&arg0->unk_10, &arg0->unk_28, &loc_A, &loc_8);
lbl_8006D1BC(loc_A, &loc_24, &loc_20);
lbl_8006D1BC(loc_8, &loc_1C, &loc_18);
lbl_8006D8E4(loc_1C, loc_18);
mathutil_mtxA_rotate_x__fzgx_offset_C(loc_24, loc_20);
fn_8006E2B0(&loc_50, &loc_5C);
{
s16 yaw = -lbl_8006D24C(loc_5C.x, loc_5C.y);
fn_8006F038(&arg0->unk_10, &arg0->unk_28, (s16)(arg0->unk_1FA + yaw));
}
} else {
fn_8006F1F0(&arg0->unk_10, &arg0->unk_64, &arg0->unk_28);
}
lbl_8006DB74(&arg0->unk_DC);
fn_8006F4E0(&loc_30);
fn_1_549F4(&arg0->unk_10, &loc_30, arg0->unk_8, arg0->unk_C, P32(fzgx_pool_rodata_lbl_1_rodata_230) , P32(fzgx_pool_rodata_lbl_1_rodata_230) );
fn_1_54DCC((u8 *)arg0 + 0x15C);
lbl_8006DB30();
}
#pragma opt_propagation reset
/* fzgx:end fn_1_90E0 */

/* fzgx:begin fn_1_A888 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.30000001192092896f;
    s = 1.100000023841858f;
}
static const unsigned long fzgx_pool_table2[9] = {0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xBF800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 55.0f;
    s = 0.0f;
    s = -10.0f;
    d = 0.5;
    d = 4503601774854144.0;
}
static const unsigned long fzgx_pool_table4[18] = {0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x40400000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1500.0f;
    s = 53.0f;
    s = 3.0f;
    s = 0.009999999776482582f;
    d = 0.05;
    s = 3.9999998989515007e-05f;
    s = 80.0f;
    s = 108.0f;
    s = 1.350000023841858f;
    s = 90.0f;
    s = 1.2000000476837158f;
    s = 0.20000000298023224f;
}
static const unsigned long fzgx_pool_table6[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.01;
    s = 0.05000000074505806f;
    s = 0.10000000149011612f;
    d = 0.15;
    s = 1.0f;
    s = 182.04444885253906f;
    s = 0.4000000059604645f;
}
static const unsigned long fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const unsigned long *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.12;
    s = 5000.0f;
}
static const unsigned long fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const unsigned long *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.2;
    d = 1.4;
    d = 1.7;
    d = 0.08;
    d = 0.2;
    d = 0.04;
    s = 0.5f;
}
static const unsigned long fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const unsigned long *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.1;
    s = 1.5f;
    s = 2.299999952316284f;
    s = 0.699999988079071f;
}
static const unsigned long fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const unsigned long *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.3;
    d = 55.0;
    d = 150.0;
    s = 65.0f;
    s = 0.00023668639187235385f;
    s = 60.0f;
    s = 0.00027777778450399637f;
    d = 7.19;
    s = 5.0f;
    s = 2.940000057220459f;
    d = 4503599627370496.0;
    s = -13.0f;
    s = -20.0f;
    s = 13.0f;
}
static const unsigned long fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const unsigned long *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 3.0;
}
#pragma section code_type ".text"

typedef struct { f32 x, y, z; } V3;
typedef struct { u8 pad[0x7c]; u32 flags; } Obj;


static inline f64 fn_1_A888_clamp(f64 value) {
    if (value < 0.0) {
        return 0.0;
    }
    if (value > 3.0) {
        return 3.0;
    }
    return value;
}

#pragma opt_propagation off
f32 fn_1_A888(Cam *cam) {
    V3 loc48;
    struct { u32 a[15]; } loc54;
    V3 loc3C;
    V3 loc30;
    V3 loc24;
    u32 loc18[3];
    u32 loc14;
    u32 loc10;
    Obj *obj;
    s32 flag;
    f32 r;
    f64 c;
    f64 t;
    lbl_8006DAEC();
    obj = (Obj *)fn_1_8627C(cam->id);
    if (obj == 0) {
        return 0.0f;
    }
    flag = (obj->flags >> 24) & 1;
    fn_1_862D4(cam->id, (Vec3 *)(V3 *)(&loc48));
    fn_1_8636C(cam->id, &loc54);
    lbl_8006DC6C(&loc54);
    {
        f32 fzgx_lc0_z;
        f32 fzgx_lc0_y;
        f32 fzgx_lc0_x;
        fzgx_lc0_x = loc48.x;
        fzgx_lc0_y = loc48.y;
        fzgx_lc0_z = loc48.z;
        *(f32 *)(0xE0000000 + 0x0C) = fzgx_lc0_x;
        *(f32 *)(0xE0000000 + 0x1C) = fzgx_lc0_y;
        *(f32 *)(0xE0000000 + 0x2C) = fzgx_lc0_z;
    }
    loc3C.x = 0.0f;
    loc3C.y = -13.0f;
    loc3C.z = -20.0f;
    lbl_8006E1B0( (Fn183D28Vec3 *)(V3 *)(&loc3C), (Fn183D28Vec3 *)(V3 *)(&loc30));
    loc3C.y = 13.0f;
    lbl_8006E1B0( (Fn183D28Vec3 *)(V3 *)(&loc3C), (Fn183D28Vec3 *)(V3 *)(&loc24));
    loc14 = fn_1_20A5C(&loc24, &loc10);
    fn_1_15578(&loc30, &loc24, &loc10, loc18, 0x80001, &loc14, 1, 0, 0, 0);
    lbl_8006DC6C(&loc54);
    {
        f32 fzgx_lc1_z;
        f32 fzgx_lc1_y;
        f32 fzgx_lc1_x;
        fzgx_lc1_x = loc48.x;
        fzgx_lc1_y = loc48.y;
        fzgx_lc1_z = loc48.z;
        *(f32 *)(0xE0000000 + 0x0C) = fzgx_lc1_x;
        *(f32 *)(0xE0000000 + 0x1C) = fzgx_lc1_y;
        *(f32 *)(0xE0000000 + 0x2C) = fzgx_lc1_z;
    }
    fn_8006E250( (Vec3f *)(V3 *)(&loc30), (Vec3f *)(V3 *)(&loc30));
    r = (f32)fn_1_A888_clamp(1.2 + loc30.y) / 3.0;
    if (flag != 0) {
        r = 0.3f;
    }
    {
        f32 old = cam->val;
        f64 d = 0.08 * (r - old);
        cam->val = old + d;
    }
    lbl_8006DB30();
    return r;
}
#pragma opt_propagation reset
/* fzgx:end fn_1_A888 */

/* fzgx:begin fn_1_AA54 */
struct fn_1_AA54_Arg0 {
    u8 pad_0[0x2];
    s16 unk_2;
};


void fn_1_AA54(void *arg0) {
    s16 temp_r28;
    u8 temp_r31;
    u8 temp_r3;

    temp_r31 = fn_1_86678((s32) (*(s16 *)((u8 *)(arg0) + 2)));
    temp_r3 = (s8)fn_1_86634((s32) (*(s16 *)((u8 *)(arg0) + 2)));
    temp_r28 = camera_get_entry_field_0xa8((u32) temp_r3);
    if (((s16) (*(s16 *)((u8 *)(&(*((s16 *)&lbl_1_bss_960))) + 0)) != 9) && (fn_1_864E8((s32) (*(s16 *)((u8 *)(arg0) + 2))) & 0x10000)) {
        camera_set_entry_field_0xa8(temp_r3, 2);
        return;
    }
    if (!(fn_1_864E8((s32) (*(s16 *)((u8 *)(arg0) + 2))) & 1)) {
        if (fn_1_864E8((s32) (*(s16 *)((u8 *)(arg0) + 2))) & 0x800) {
            camera_set_entry_field_0xa8(temp_r3, 5);
            return;
        }
        if (!(fn_1_864E8((s32) (*(s16 *)((u8 *)(arg0) + 2))) & 0x80)) {
            goto block_7; /* Preserves the retail branch. */
        }
    } else {
block_7:
        if ((f64) (*(f64 *)((u8 *)(&lbl_1_rodata_360) + 0)) == (f64) (f64) fn_1_8664C((s32) (*(s16 *)((u8 *)(arg0) + 2)))) {
            camera_set_entry_field_0xa8(temp_r3, 3);
            return;
        }
        if (fn_1_8664C((s32) (*(s16 *)((u8 *)(arg0) + 2))) == 0x14) {
            camera_set_entry_field_0xa8(temp_r3, 0);
            return;
        }
        if ((s8) temp_r31 >= 0) {
            camera_set_entry_field_0xa8(temp_r3, temp_r28);
        }
    }
}
/* fzgx:end fn_1_AA54 */

/* fzgx:begin fn_1_ABAC noprologue */
#include "types.h"

typedef struct fn_1_ABAC_Camera {
    u8 pad_0[0x2];
    s16 unk_2;
    u8 pad_4[0xA2];
    s16 unk_A6;
    s16 unk_A8;
} fn_1_ABAC_Camera;

typedef struct fn_1_ABAC_Target {
    u8 pad_0[0x214];
    u16 unk_214;
} fn_1_ABAC_Target;

// Pad input state: retail reloads the button words between the bit tests, so
// the fields are volatile.
typedef struct fn_1_ABAC_PadEntry {
    u8 pad_0[0x10];
    volatile u16 unk_10;  // volatile: pad input, retail reloads it at every bit test
    volatile u16 unk_12;  // volatile: pad input, retail reloads it at every bit test
} fn_1_ABAC_PadEntry;

extern fn_1_ABAC_Target *fn_1_86254(s32 index);
extern s32 fn_1_F2F34(void);
extern s16 camera_get_entry_field_0xa4(u32);
extern s8 fn_1_86678(int index);
extern s8 fn_1_86634(int index);
extern void fn_1_715C(u8, s16);
extern u32 fn_1_864E8(int index);
extern s32 fn_1_40BB4(void);
extern s16 lbl_1_bss_960;
extern fn_1_ABAC_PadEntry lbl_1_bss_9F8[];
extern u8 lbl_1_bss_CC0[152];

// Button byte per player, reloaded at every test like the pad words.
#define FN_1_ABAC_BUTTONS(p) (((volatile u8 *)lbl_1_bss_CC0)[p])

// Steps the camera view selection from the player's pad input.
void fn_1_ABAC(fn_1_ABAC_Camera *camera) {
    s16 view;
    s8 slot;
    fn_1_ABAC_Target *target;
    s8 player;

    target = fn_1_86254(camera->unk_2);
    if (fn_1_F2F34() != 0) {
        player = 0;
        slot = 0;
        view = camera_get_entry_field_0xa4(0);
    } else {
        player = fn_1_86678(camera->unk_2);
        slot = fn_1_86634(camera->unk_2);
        view = camera_get_entry_field_0xa4((u8)slot);
    }

    if (target->unk_214 > 1) {
        fn_1_715C(slot, 5);
        return;
    }
    if (target->unk_214 == 1) {
        fn_1_715C(slot, camera->unk_A6);
        return;
    }
    if (fn_1_864E8(camera->unk_2) & 0x80) {
        fn_1_715C(slot, 5);
        return;
    }

    camera->unk_A6 = view;
    if (player == -1) {
        return;
    }
    if (lbl_1_bss_960 == 10) {
        return;
    }
    if (fn_1_40BB4() != 0) {
        return;
    }

    if (fn_1_F2F34() != 0) {
        if (((lbl_1_bss_9F8[player].unk_10 >> 2) & 1) || ((lbl_1_bss_9F8[player].unk_12 >> 2) & 1)) {
            view++;
        }
        if (((lbl_1_bss_9F8[player].unk_10 >> 3) & 1) || ((lbl_1_bss_9F8[player].unk_12 >> 3) & 1)) {
            view--;
        }
    } else {
        if ((FN_1_ABAC_BUTTONS(player) >> 1) & 1) {
            view++;
        }
        if (FN_1_ABAC_BUTTONS(player) & 1) {
            view--;
        }
    }

    if (view <= 0) {
        view = 0;
    }
    if (camera->unk_A8 == 1) {
        if ((u32)view >= 12) {
            view = 11;
        }
    } else {
        if ((u32)view >= 4) {
            view = 3;
        }
    }
    fn_1_715C(slot, view);
}
/* fzgx:end fn_1_ABAC */

/* fzgx:begin camera_get_position_delta */
// Computes the displacement between two camera positions.
void camera_get_position_delta(u32 index, Vec3 *out) {
    u8 idx = (u8)index;
    Vec3 first;
    Vec3 second;

    fn_1_862D4(idx, &first);
    fn_1_8658C(idx, &second);
    out->x = first.x - second.x;
    out->y = first.y - second.y;
    out->z = first.z - second.z;
}
/* fzgx:end camera_get_position_delta */

/* fzgx:begin camera_reset_transition */
// Resets the camera transition state before refreshing the camera.
void camera_reset_transition(camera_reset_transition_Camera *camera) {
    camera->unk_A4 = 0;
    fn_1_AEB8(camera);
}
/* fzgx:end camera_reset_transition */

/* fzgx:begin camera_update_transition */
// Advances the camera's transition state and updates its active view.
void camera_update_transition(camera_update_transition_Camera *camera) {
    if (camera->unk_78 == 0) {
        camera->unk_A4++;
        if (camera->unk_A4 >= camera_transition_count) {
            camera->unk_A4 = 0;
        }
        fn_1_AEB8( (camera_reset_transition_Camera *)(camera_update_transition_Camera *)(camera));
    }

    fn_1_AFC8(camera);

    if (camera->unk_78 != 0) {
        camera->unk_78--;
    }
}
/* fzgx:end camera_update_transition */

/* fzgx:begin fn_1_AEB8 noprologue */
#include "rel/main_rel/camera.h"

extern f32 lbl_1_rodata_230[44];

typedef struct { f32 x, y, z; } Vec;

typedef struct {
    u8 pad_0[0x8];
    f32 unk_8;
    u8 pad_C[0x6C];
    s16 unk_78;
    u8 pad_7A[0x12];
    Vec unk_8C;
    Vec unk_98;
    s16 unk_A4;
    u8 pad_A6[0x13E];
    Vec unk_1E4;
    f32 unk_1F0;
    f32 unk_1F4;
    u8 pad_1F8[2];
    s16 unk_1FA;
} Camera;

typedef struct {
    u32 unk_0;
    Vec position;
    Vec target;
    f32 value;
    s16 count;
    s16 pad;
} TransitionConfig;

typedef struct {
    s32 mode;
    f32 unk_4;
    TransitionConfig config;
    u8 pad_2C[0x28];
} TransitionPreset;

void fn_1_AEB8(Camera *camera) {
    TransitionPreset *preset;
    TransitionConfig config;
    Vec position;
    s32 index = camera->unk_A4;
    if (lbl_1_bss_960 == 14) {
        camera_transition_count = 14;
        preset = &((TransitionPreset *)lbl_1_data_3BD0)[index];
    } else {
        camera_transition_count = 5;
        preset = &((TransitionPreset *)&lbl_1_data_3A2C)[index];
    }
    config = preset->config;
    position = config.position;
    camera->unk_1E4 = position;
    camera->unk_1F0 = 0.0f;
    camera->unk_1F4 = 0.0f;
    camera->unk_78 = preset->mode;
    camera->unk_8C = config.position;
    camera->unk_98 = config.target;
    camera->unk_1FA = config.count;
    camera->unk_8 = config.value;
    camera->unk_1FA = config.count;
}
/* fzgx:end fn_1_AEB8 */

/* fzgx:begin fn_1_AFC8 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/camera.h"
#include "dolphin/hw_regs.h"

/* the TU's .rodata pool from lbl_1_rodata_200 in retail bytes, with this function's literals primed at their
 * retail offsets, so MWCC addresses them off one pool base */
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[12] = {0x3E99999A, 0x3F8CCCCD, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xBF800000, 0x425C0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
}
static const u32 fzgx_pool_table2[3] = {0xC1200000, 0x3FE00000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table3[35] = {0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x40400000, 0x00000000, 0x44BB8000, 0x42540000, 0x40400000, 0x3C23D70A, 0x3FA99999, 0x9999999A, 0x3827C5AC, 0x42A00000, 0x42D80000, 0x3FACCCCD, 0x42B40000, 0x3F99999A, 0x3E4CCCCD, 0x00000000, 0x3F847AE1, 0x47AE147B, 0x3D4CCCCD};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.10000000149011612f;
}
static const u32 fzgx_pool_table4[2] = {0x3FC33333, 0x33333333};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0f;
}
static const u32 fzgx_pool_table5[19] = {0x43360B61, 0x3ECCCCCD, 0x00000000, 0x3FBEB851, 0xEB851EB8, 0x459C4000, 0x00000000, 0x3FF33333, 0x33333333, 0x3FF66666, 0x66666666, 0x3FFB3333, 0x33333333, 0x3FB47AE1, 0x47AE147B, 0x3FC99999, 0x9999999A, 0x3FA47AE1, 0x47AE147B};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
}
static const u32 fzgx_pool_table6[21] = {0x00000000, 0x3FB99999, 0x9999999A, 0x3FC00000, 0x40133333, 0x3F333333, 0x00000000, 0x3FD33333, 0x33333333, 0x404B8000, 0x00000000, 0x4062C000, 0x00000000, 0x42820000, 0x39782F05, 0x42700000, 0x3991A2B4, 0x401CC28F, 0x5C28F5C3, 0x40A00000, 0x403C28F6};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
}
static const u32 fzgx_pool_table7[20] = {0xC1500000, 0xC1A00000, 0x41500000, 0x00000000, 0x00000000, 0x00000000, 0x40080000, 0x00000000, 0x3F947AE1, 0x47AE147B, 0x42800000, 0x00000000, 0x4060E000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.0;
}
#pragma section code_type ".text"

typedef struct {
    f32 x, y, z;
} CamVec;

typedef struct {
    u32 unk_0;
    CamVec pos;
    CamVec at;
    f32 unk_1C;
    s16 unk_20;
} CamKey;

/* one 0x54-byte entry of the transition tables lbl_1_data_3A2C / lbl_1_data_3BD0 */
typedef struct {
    s32 unk_0;
    f32 unk_4;
    CamKey unk_8;
    CamKey unk_2C;
    s16 unk_50;
} CamPreset;

/* one 0x1FC-byte game_camera_entries record (camera.h) */
typedef struct {
    u8 pad_0[0x2];
    s16 unk_2;
    u8 pad_4[0x4];
    f32 unk_8;
    u8 pad_C[0x4];
    CamVec unk_10;
    u8 pad_1C[0xC];
    CamVec unk_28;
    f32 unk_34[3][4];
    u8 pad_64[0x14];
    s16 unk_78;
    u8 pad_7A[0x12];
    CamVec unk_8C;
    CamVec unk_98;
    s16 unk_A4;
    u8 pad_A6[0x14A];
    f32 unk_1F0;
    f32 unk_1F4;
    u8 pad_1F8[0x2];
    s16 unk_1FA;
} Camera;

extern void fn_1_862D4(s16 index, CamVec *out);
extern void fn_1_863E4(s16 index, f32 (*out)[4]);
extern void fn_80008DB4(f32 (*a)[4], f32 (*b)[4], f32 (*out)[4], f32 t);
extern void lbl_8006DC6C(f32 (*m)[4]);
extern void lbl_8006E1B0(CamVec *in, CamVec *out);
extern void lbl_8006D5A4(CamVec *a, CamVec *b, CamVec *out, f32 t);

static inline f32 fn_1_AFC8_clamp(f32 x, f32 lo, f32 hi) {
    if (x < lo) {
        return lo;
    }
    if (x > hi) {
        return hi;
    }
    return x;
}

/* While cam->unk_78 (counted down by camera_update_transition) is positive, blends the camera toward the current
 * transition preset (lbl_1_data_3BD0 entry cam->unk_A4 in game mode 14, else lbl_1_data_3A2C): mode 0 from unk_8
 * to unk_2C by the elapsed fraction, mode 3 by the eased value unk_1F0 (step unk_1F4), mode 2 by the fixed
 * fraction unk_4 from where the camera is. Then it passes unk_34, car cam->unk_2's orientation (fn_1_863E4) and
 * 0.1 to fn_80008DB4, loads unk_34 into mtxA with the car's position (fn_1_862D4) as translation, and passes
 * unk_8C/unk_10 and unk_98/unk_28 to lbl_8006E1B0. */
void fn_1_AFC8(Camera *cam) {
    CamPreset *preset;
    CamKey from;
    CamKey to;
    CamVec pos;
    f32 mtx[3][4];
    f32 t;
    u32 n;
    f32 z;
    f32 y;
    f32 x;
    s32 index;
    f32 step;

    index = cam->unk_A4;
    if (*(s16 *)&lbl_1_bss_960 == 14) {
        camera_transition_count = 14;
        preset = &((CamPreset *)lbl_1_data_3BD0)[index];
    } else {
        camera_transition_count = 5;
        preset = &((CamPreset *)&lbl_1_data_3A2C)[index];
    }
    from = preset->unk_8;
    to = preset->unk_2C;
    if (cam->unk_78 > 0) {
        switch (preset->unk_50) {
        case 0:
            t = 1.0 - (f32)cam->unk_78 / (f32)preset->unk_0;
            lbl_8006D5A4(&from.pos, &to.pos, &cam->unk_8C, t);
            lbl_8006D5A4(&from.at, &to.at, &cam->unk_98, t);
            cam->unk_8 = from.unk_1C + (f32)(t * (to.unk_1C - from.unk_1C));
            cam->unk_1FA = from.unk_20 + (s16)(t * (to.unk_20 - from.unk_20));
            break;
        case 3:
            n = preset->unk_0;
            step = 1.0f / (n * n / 4);
            if ((u32)cam->unk_78 < n / 2.0f) {
                cam->unk_1F4 -= step;
            } else {
                cam->unk_1F4 += step;
            }
            cam->unk_1F0 += cam->unk_1F4;
            cam->unk_1F0 = fn_1_AFC8_clamp(cam->unk_1F0, 0.0f, 1.0f);
            t = cam->unk_1F0;
            lbl_8006D5A4(&from.pos, &to.pos, &cam->unk_8C, t);
            lbl_8006D5A4(&from.at, &to.at, &cam->unk_98, t);
            cam->unk_8 = from.unk_1C + (f32)(t * (to.unk_1C - from.unk_1C));
            cam->unk_1FA = from.unk_20 + (s16)(t * (to.unk_20 - from.unk_20));
            break;
        case 2:
            lbl_8006D5A4(&cam->unk_8C, &to.pos, &cam->unk_8C, preset->unk_4);
            lbl_8006D5A4(&cam->unk_98, &to.at, &cam->unk_98, preset->unk_4);
            cam->unk_8 += (f32)(preset->unk_4 * (to.unk_1C - cam->unk_8));
            cam->unk_1FA += (s32)(preset->unk_4 * (to.unk_20 - cam->unk_1FA));
            break;
        }
        fn_1_862D4(cam->unk_2, &pos);
        fn_1_863E4(cam->unk_2, mtx);
        fn_80008DB4(cam->unk_34, mtx, cam->unk_34, 0.1f);
        lbl_8006DC6C(cam->unk_34);
        /* mtxA's translation column in the locked cache */
        x = *(volatile f32 *)&pos.x;  /* fzgx-allow: S2 volatile view keeps the verified load order */
        y = pos.y;
        z = pos.z;
        *(f32 *)(LC_BASE + 0xC) = x;
        *(f32 *)(LC_BASE + 0x1C) = y;
        *(f32 *)(LC_BASE + 0x2C) = z;
        lbl_8006E1B0(&cam->unk_8C, &cam->unk_10);
        lbl_8006E1B0(&cam->unk_98, &cam->unk_28);
    }
}
/* fzgx:end fn_1_AFC8 */

/* fzgx:begin camera_get_target_orientation */
typedef struct camera_get_target_orientation_CameraObject {
    u8 pad_49c[0x49c];
    Transform *unk_49C;
} camera_get_target_orientation_CameraObject;


// Updates the camera orientation from the active target transform.
f32 camera_get_target_orientation(camera_get_target_orientation_CameraObject *camera) {
    Transform *target = camera->unk_49C;

    if (target == 0) {
        return lbl_1_rodata_2E0[0];
    }
    if ((target->unk_7C & 0x01800000) == 0) {
        return lbl_1_rodata_2E0[0];
    }

    lbl_801A66CC->unk_D4 = -lbl_801A6D00->unk_08;
    lbl_801A66CC->unk_D8 = -lbl_801A6D00->unk_18;
    lbl_801A66CC->unk_DC = -lbl_801A6D00->unk_28;
    return lbl_8006D6FC(&lbl_801A66CC->unk_D4, &target->unk_50);
}
/* fzgx:end camera_get_target_orientation */

/* fzgx:begin fn_1_B4D4 pool */
typedef struct {
    f32 x, y, z;
} fn_1_B4D4_Vec;

struct fn_1_B4D4_Camera {
    u8 pad_0[0x10];
    fn_1_B4D4_Vec pos;           /* 0x10 */
    u8 pad_1C[0xC];
    fn_1_B4D4_Vec target;        /* 0x28 */
    u8 pad_34[0x74];
    s16 unk_A8;
    u8 pad_AA[0x62];
    s32 unk_10C;
    s32 unk_110;
    fn_1_B4D4_Vec posBase;       /* 0x114 */
    fn_1_B4D4_Vec posOfs;        /* 0x120 */
    fn_1_B4D4_Vec posVel;        /* 0x12C */
    fn_1_B4D4_Vec targetBase;    /* 0x138 */
    fn_1_B4D4_Vec targetOfs;     /* 0x144 */
    fn_1_B4D4_Vec targetVel;     /* 0x150 */
};


/* stands in for the camera TU's literal pool ahead of this function's constants */
const struct {
    f32 f[88];
    f64 d[17];
} fn_1_B4D4_pool_head = {
    {
        0.3f,
        1.1f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 55.0f,
        0.0f, -10.0f, 1.75f, 0.0f, 176.0f, -0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 3.0f, 0.0f,
        1500.0f, 53.0f, 3.0f, 0.01f, 1.3249999f, -0.000000000000000000000015881868f,
        0.00004f, 80.0f, 108.0f, 1.35f, 90.0f, 1.2f, 0.2f, 0.0f, 1.035f, 89128.96f,
        0.05f, 0.1f, 1.525f, 0.00000004172325f,
        1.0f, 182.04445f, 0.4f, 0.0f, 1.4899999f, -321864400000000000000000000.0f,
        5000.0f, 0.0f, 1.9f, 0.00000004172325f, 1.925f, 272008300000000000000000.0f,
        1.9625f, 0.00000004172325f, 1.41f, 89128.96f, 1.5749999f,
        -0.000000000000000000000015881868f, 1.285f, 89128.96f, 0.5f, 0.0f, 1.4499999f,
        -0.000000000000000000000015881868f, 1.5f, 2.3f, 0.7f, 0.0f, 1.65f,
        0.00000004172325f, 3.1796875f, 0.0f,
    },
    {
        150.0, 2473901633285.8774, 1099511863578.169, 7.19, 2048.000490074158,
        4503599627370496.0, -4194307.025390625, 4194304.0, 0.0, 3.0, 0.02,
        2199023255552.0, 135.0, 0.0, 0.0, 0.0, 1.0,
    },
};

#pragma fp_contract off
void fn_1_B4D4(struct fn_1_B4D4_Camera *cam) {
    if (cam->unk_10C == 0) {
        cam->posBase = cam->pos;
        cam->targetBase = cam->target;
        return;
    }
    if (!(lbl_1_bss_F5C & 0x50000000)) {
        cam->posVel.x = cam->posVel.x - 0.75 * cam->posOfs.x;
        cam->posVel.y = cam->posVel.y - 0.75 * cam->posOfs.y;
        cam->posVel.z = cam->posVel.z - 0.75 * cam->posOfs.z;
        cam->posVel.x *= 0.8;
        cam->posVel.y *= 0.8;
        cam->posVel.z *= 0.8;
        cam->posOfs.x = cam->posOfs.x + cam->posVel.x;
        cam->posOfs.y = cam->posOfs.y + cam->posVel.y;
        cam->posOfs.z = cam->posOfs.z + cam->posVel.z;
        cam->targetVel.x = cam->targetVel.x - 0.72 * cam->targetOfs.x;
        cam->targetVel.y = cam->targetVel.y - 0.72 * cam->targetOfs.y;
        cam->targetVel.z = cam->targetVel.z - 0.72 * cam->targetOfs.z;
        cam->targetVel.x *= 0.75;
        cam->targetVel.y *= 0.75;
        cam->targetVel.z *= 0.75;
        cam->targetOfs.x = cam->targetOfs.x + cam->targetVel.x;
        cam->targetOfs.y = cam->targetOfs.y + cam->targetVel.y;
        cam->targetOfs.z = cam->targetOfs.z + cam->targetVel.z;
    }
    psvec_add(&cam->posBase, &cam->posOfs, &cam->pos);
    if (cam->unk_A8 == 0) {
        psvec_add(&cam->targetBase, &cam->targetOfs, &cam->target);
    }
    if (!(lbl_1_bss_F5C & 0x50000000) && cam->unk_110 > 0) {
        cam->unk_110--;
        if (cam->unk_110 == 0) {
            fn_1_8840();
        }
    }
}
#pragma fp_contract reset
/* fzgx:end fn_1_B4D4 */

/* fzgx:begin fn_1_B724 pool noprologue */
#include "types.h"

extern f64 lbl_1_rodata_400[15];
extern f32 lbl_8006D0B4(f32);

typedef struct { f32 x, y, z; } B724Vec;
typedef struct {
    u32 unk_0;
    B724Vec start;
    B724Vec end;
    f32 duration;
    s16 mode;
} B724Transition;
typedef struct {
    s32 unk_0;
    s32 unk_4;
    s32 unk_8;
    f32 unk_C;
} B724Fade;

/* retail lbl_1_bss_1010 cluster: each field is its own TU object */
static s32 fzgx_obj_lbl_1_bss_1010;
static u8 fzgx_obj_lbl_1_bss_1014;
static u8 fzgx_obj_lbl_1_bss_1015;
static B724Transition fzgx_obj_lbl_1_bss_1018;
static f32 fzgx_obj_lbl_1_bss_103C;
static f32 fzgx_obj_lbl_1_bss_1040;
static f32 fzgx_obj_lbl_1_bss_1044;
static u8 fzgx_obj_lbl_1_bss_1048;
static u8 fzgx_obj_lbl_1_bss_1049;
static B724Fade fzgx_obj_lbl_1_bss_104C;

#pragma section code_type ".fzgxpool"
void fzgx_layout_B724(void)
{
    volatile s32 sink;  /* fzgx-allow: S2 volatile keeps the verified access order */
    sink = fzgx_obj_lbl_1_bss_1010;
    sink = fzgx_obj_lbl_1_bss_1014;
    sink = fzgx_obj_lbl_1_bss_1015;
    sink = fzgx_obj_lbl_1_bss_1018.unk_0;
    sink = fzgx_obj_lbl_1_bss_103C;
    sink = fzgx_obj_lbl_1_bss_1040;
    sink = fzgx_obj_lbl_1_bss_1044;
    sink = fzgx_obj_lbl_1_bss_1048;
    sink = fzgx_obj_lbl_1_bss_1049;
    sink = fzgx_obj_lbl_1_bss_104C.unk_0;
}
#pragma section code_type ".text"

static inline f32 B724SetTransition(B724Transition *transition, B724Vec *start, B724Vec *end, f32 duration, s16 mode)
{
    B724Vec delta;
    transition->start = *start;
    transition->end = *end;
    transition->duration = duration;
    transition->mode = mode;
    delta.z = transition->start.z;
    delta.y = transition->start.y;
    delta.x = transition->start.x;
    delta.x -= transition->end.x;
    delta.y -= transition->end.y;
    delta.z -= transition->end.z;
    delta.x = delta.x * delta.x;
    delta.x = delta.x + delta.y * delta.y;
    delta.x = delta.x + delta.z * delta.z;
    return lbl_8006D0B4(delta.x);
}

void fn_1_B724(B724Vec *start, B724Vec *end, f32 duration, s16 mode)
{
    fzgx_obj_lbl_1_bss_103C = B724SetTransition(&fzgx_obj_lbl_1_bss_1018, start, end, duration, mode);
    fzgx_obj_lbl_1_bss_1040 = 1.0f;
    fzgx_obj_lbl_1_bss_1044 = 0.1f;
    fzgx_obj_lbl_1_bss_1048 = 1;
    fzgx_obj_lbl_1_bss_1049 = 1;
    fzgx_obj_lbl_1_bss_1014 = 0;
    fzgx_obj_lbl_1_bss_1015 = 0;
    fzgx_obj_lbl_1_bss_104C.unk_0 = 0;
    fzgx_obj_lbl_1_bss_104C.unk_4 = 0;
    fzgx_obj_lbl_1_bss_104C.unk_8 = 200;
    fzgx_obj_lbl_1_bss_104C.unk_C = 0.01f;
}
/* fzgx:end fn_1_B724 */

/* fzgx:begin fn_1_B81C noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/camera.h"
#include "game/main_rel/camera_types.h"

struct fn_1_B81C_Copy12 { u32 a[3]; };

void fn_1_B81C(struct fn_1_B81C_Copy12 *first, struct fn_1_B81C_Copy12 *second, u32 value) {
    *(struct fn_1_B81C_Copy12 *)((u8 *)&camera_state + 4) = *first;
    *(struct fn_1_B81C_Copy12 *)((u8 *)&camera_state + 16) = *second;
    camera_state.unk_20 = value;
}
/* fzgx:end fn_1_B81C */

/* fzgx:begin camera_save_parameters */
// Saves the two current camera parameters for later processing.
void camera_save_parameters(f32 first_parameter, f32 second_parameter) {
    lbl_1_bss_1040 = first_parameter;
    lbl_1_bss_1044 = second_parameter;
}
/* fzgx:end camera_save_parameters */

/* fzgx:begin fn_1_B870 pool */
typedef struct B870Camera {
    u8 pad_0[0x4];
    Vec3f pos;    /* 0x04 */
    Vec3f lookAt; /* 0x10 */
    f32 fov;      /* 0x1C */
    s16 rotZ;     /* 0x20 */
} B870Camera;

typedef struct {
    u8 pad_0[0x8];
    u16 unk_8;
} B870Bss_D58;

typedef struct {
    s8 stick[4];
    u8 unk_4;
} B870Bss_A48;

typedef struct {
    u16 unk_0;
    u16 unk_2;
    u8 pad_4[0x4];
    u16 unk_8;
} B870Bss_9F8;


/* camera.c's .bss cluster at lbl_1_bss_1010, addressed off one section base. */
u32 fzgx_obj_lbl_1_bss_1010;
u8 lbl_1_bss_1014;
B870Camera lbl_1_bss_1018;
f32 fzgx_obj_lbl_1_bss_103C;
f32 lbl_1_bss_1040;
f32 lbl_1_bss_1044;
u8 lbl_1_bss_1048;
u8 lbl_1_bss_1049;


/* Primer: the .bss order and the literals of earlier camera.c functions, as in retail. */
#pragma section RX ".fzgxpool"
__declspec(section ".fzgxpool") void fzgx_pool_primer(void) {
    fzgx_touch(&fzgx_obj_lbl_1_bss_1010);
    fzgx_touch(&lbl_1_bss_1014);
    fzgx_touch(&lbl_1_bss_1018);
    fzgx_touch(&fzgx_obj_lbl_1_bss_103C);
    fzgx_touch(&lbl_1_bss_1040);
    fzgx_touch(&lbl_1_bss_1044);
    fzgx_touch(&lbl_1_bss_1048);
    fzgx_touch(&lbl_1_bss_1049);
    fzgx_touch_f(1.0f);
    fzgx_touch_f(0.1f);
    fzgx_touch_f(0.01f);
    fzgx_touch_f(55.0f);
}

#pragma opt_lifetimes off
void fn_1_B870(void) {
    f32 speed;
    f32 clamped;
    f32 scale;
    s32 rot;
    s32 zoom;
    u32 buttons;
    s16 rotX;
    s16 rotY;

    if (((*((B870Bss_D58 *)&lbl_1_bss_D58)).unk_8 >> 10) & 1) {
        lbl_1_bss_1048 ^= 1;
    }
    if (lbl_1_bss_1014 != 0) {
        fn_1_C770();
        return;
    }
    fn_8006EDBC( (Vec3 *)(Vec3f *)(&lbl_1_bss_1018.pos), (Vec3 *)(Vec3f *)(&lbl_1_bss_1018.lookAt), &rotX, &rotY);
    speed = fzgx_obj_lbl_1_bss_103C;
    speed = 0.040000000000000008 * speed;
    speed = speed * (1.0 + 4.0 * (*((B870Bss_A48 *)&lbl_1_bss_A48)).unk_4 / 140.0);
    clamped = (speed > 50.0) ? 50.0 : speed;
    {
        Vec3f offsetA = {0.0f, 0.0f, 0.0f};
        Vec3f offsetB = {0.0f, 0.0f, 0.0f};
        Vec3f tmp;

        if (lbl_1_bss_1049 != 0 && !(((*((B870Bss_9F8 *)&lbl_1_bss_9F8)).unk_0 >> 6) & 1)) {
            offsetA.x = speed * (*((0) + ((*((B870Bss_A48 *)&lbl_1_bss_A48)).stick))) / 60.0;
            if (((*((B870Bss_9F8 *)&lbl_1_bss_9F8)).unk_2 >> 9) & 1) {
                offsetA.y = clamped * (*((1) + ((*((B870Bss_A48 *)&lbl_1_bss_A48)).stick))) / 60.0;
            } else {
                offsetA.z = -clamped * (*((1) + ((*((B870Bss_A48 *)&lbl_1_bss_A48)).stick))) / 60.0;
            }
            offsetB.x = speed * (*((2) + ((*((B870Bss_A48 *)&lbl_1_bss_A48)).stick))) / 60.0;
            if (((*(volatile u16 *)&(*((B870Bss_9F8 *)&lbl_1_bss_9F8)).unk_2) >> 9) & 1) { /* Retail reloads the mode for the second stick. */
                offsetB.y = clamped * (*((3) + ((*((B870Bss_A48 *)&lbl_1_bss_A48)).stick))) / 60.0;
            } else {
                offsetB.z = -clamped * (*((3) + ((*((B870Bss_A48 *)&lbl_1_bss_A48)).stick))) / 60.0;
            }
        }
        lbl_8006D7DC(&lbl_1_bss_1018.pos);
        mathutil_mtxA_rotate_y(rotY);
        mathutil_mtxA_rotate_x(rotX);
        mathutil_mtxA_rotate_z(lbl_1_bss_1018.rotZ);
        lbl_8006E1B0( (Fn183D28Vec3 *)(Vec3f *)(&offsetA), (Fn183D28Vec3 *)(Vec3f *)(&lbl_1_bss_1018.pos));
        fn_8006E250(&lbl_1_bss_1018.lookAt, &tmp);
        tmp.x += offsetB.x;
        tmp.y += offsetB.y;
        tmp.z += offsetB.z;
        lbl_8006E1B0( (Fn183D28Vec3 *)(Vec3f *)(&tmp), (Fn183D28Vec3 *)(Vec3f *)(&lbl_1_bss_1018.lookAt));
        tmp.x = lbl_1_bss_1018.lookAt.x - lbl_1_bss_1018.pos.x;
        tmp.y = lbl_1_bss_1018.lookAt.y - lbl_1_bss_1018.pos.y;
        tmp.z = lbl_1_bss_1018.lookAt.z - lbl_1_bss_1018.pos.z;
        if (__fmadds(tmp.z, tmp.z, __fmadds(tmp.y, tmp.y, tmp.x * tmp.x)) < 0.09) {
            scale = 0.3 * lbl_8006D0E8(__fmadds(tmp.z, tmp.z, __fmadds(tmp.y, tmp.y, tmp.x * tmp.x)));
            lbl_1_bss_1018.lookAt.x = lbl_1_bss_1018.pos.x + (f32)(tmp.x * scale);
            lbl_1_bss_1018.lookAt.y = lbl_1_bss_1018.pos.y + (f32)(tmp.y * scale);
            lbl_1_bss_1018.lookAt.z = lbl_1_bss_1018.pos.z + (f32)(tmp.z * scale);
        }
    }
    {
        Vec3f *pos = &lbl_1_bss_1018.pos;
        Vec3f *lookAt = &lbl_1_bss_1018.lookAt;
        f32 dx = pos->x;
        f32 dz = pos->z;
        f32 dy = pos->y;
        dx -= lookAt->x;
        dy -= lookAt->y;
        dz -= lookAt->z;
        dx = dx * dx;
        dx = dy * dy + dx;
        dx = dz * dz + dx;
        fzgx_obj_lbl_1_bss_103C = lbl_8006D0B4(dx);
    }
    if ((((*((B870Bss_9F8 *)&lbl_1_bss_9F8)).unk_2 >> 9) & 1) && lbl_1_bss_1049 != 0) {
        buttons = (*(u16 volatile *)&((*((B870Bss_9F8 *)&lbl_1_bss_9F8)).unk_0)) /* Retail reloads this field. */;
        if (buttons & 1) {
            rot = 0x800;
        } else {
            rot = ((buttons >> 1) & 1) ? -0x800 : 0;
        }
{
    B870Camera *cam = &lbl_1_bss_1018;
        cam->rotZ += rot;
}
        buttons = (*((B870Bss_9F8 *)&lbl_1_bss_9F8)).unk_0;
        if ((buttons >> 2) & 1) {
            zoom = 1;
        } else {
            zoom = ((buttons >> 3) & 1) ? -1 : 0;
        }
        lbl_1_bss_1018.fov += zoom;
        lbl_1_bss_1018.fov = (lbl_1_bss_1018.fov < 0.1) ? 0.1
                           : (lbl_1_bss_1018.fov > 90000.0) ? 90000.0 : lbl_1_bss_1018.fov;
        if (((*((B870Bss_9F8 *)&lbl_1_bss_9F8)).unk_8 >> 9) & 1) {
            lbl_1_bss_1018.rotZ = 0;
            lbl_1_bss_1018.fov = 55.0f;
        }
    }
}
#pragma opt_lifetimes reset
/* fzgx:end fn_1_B870 */

/* fzgx:begin fn_1_BD54 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/camera.h"
#include "dolphin/hw_regs.h"
#include "psvec.h"

extern void fn_1_BD54(void);
extern void fn_1_B870(void);
extern void camera_get_extended_state_storage(__typeof__(lbl_1_bss_F68));
extern void lbl_8006DBAC(void);
extern void fn_8006F038(void *, void *, s16);
extern void lbl_8006DCDC(void);
extern s16 fn_1_6B48(s16 value);
extern void fn_1_6D2C(u32);
extern s32 lbl_1_bss_F78;
extern void fn_1_A2DF4(u32, u32, u32);
extern s8 fn_1_86624(void);
extern s8 fn_1_86634(s32 index);
extern void OSPanic(u8 *file, int line, u8 *message, ...);
extern u8 lbl_1_bss_F74;
extern u8 lbl_1_bss_F75;
extern f32 lbl_1_rodata_188;
extern s32 fn_1_8708(u8 mode, f32 *value0, f32 *value1);
extern void fn_1_8A0C(s16 index);
extern void fn_1_A6FE8(void);
extern void fn_1_8D08(GameCameraEntry *value);
extern f32 lbl_1_bss_1040;
extern f32 lbl_1_bss_1044;
extern void OSReport(const unsigned char *, ...);
extern u8 lbl_1_bss_103C[4];
extern u8 lbl_1_bss_108C[52];
extern u8 lbl_1_bss_1014;

extern s8 fn_1_86624(void);
extern s8 fn_1_86634(s32 index);
extern void OSPanic(u8 *file, int line, u8 *message, ...);
extern void fn_1_8A0C(s16 index);
extern void OSReport(const unsigned char *, ...);

extern f32 lbl_1_rodata_2E0[32];
extern f32 lbl_8006D6FC(f32 *value, void *target);
u32 fn_1_6514(u32);
extern struct fn_1_6400_lbl_801A6410 lbl_801A6410;
extern u32 fn_1_46B4(u32, u32, void *, u32);
extern f64 lbl_1_rodata_478;
extern f32 lbl_1_rodata_49C;
extern f32 lbl_1_bss_10C0[6];


/* the camera TU's .rodata pool in retail order, ahead of this function's constants */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s;  /* fzgx-allow: S2 pool primer sink */
    s = 1.0f;
    s = 0.10000000149011612f;
    s = 0.009999999776482582f;
    s = 55.0f;
}
static const u32 fzgx_pool_table2[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.04000000000000001;
    d = 1.0;
    d = 4.0;
    d = 140.0;
    d = 50.0;
    d = 60.0;
    d = 0.09;
    d = 0.3;
    d = 0.1;
    d = 90000.0;
    d = 4503599627370496.0;
    d = 4503601774854144.0;
    d = 0.02;
    s = 60.0f;
    s = 15.0f;
    s = 0.8999999761581421f;
    s = 0.0f;
}
#pragma section code_type ".text"

#define MTXA ((f32(*)[4])LC_BASE)

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} BD54Vec;

typedef struct {
    u32 unk_0;
    BD54Vec unk_4;
    BD54Vec unk_10;
    f32 unk_1C;
    s16 unk_20;
} BD54Camera;

extern u32 fn_1_10780C(BD54Vec *, BD54Vec *, BD54Vec *, f32 *);
extern u32 fn_80008C20(void *, void *, void *);
extern void lbl_8006E0B4(f32, f32, f32);
extern void mathutil_mtxA_rotate_x(s16);
extern void fn_8006FB20(void *, f32);
extern void lbl_8006DB74(void *);
extern void fn_8006F3E4(s16 *, s16 *, s16 *);
extern void lbl_8006DF44(void);

/* the retail TU's .bss objects this function uses, at their retail offsets, so MWCC addresses them off one
 * section base; the fzgx_pool_gap_ objects span the retail objects in between, which this function does not touch */
f32 fzgx_obj_lbl_1_bss_1010;
u8 fzgx_pool_gap_1014[4];
BD54Camera fzgx_obj_camera_state;
u8 fzgx_pool_gap_103C[0x10];
u8 fzgx_obj_lbl_1_bss_104C[0x10];
u8 lbl_1_bss_104C__fzgx_offset_10[0x30];
u8 lbl_1_bss_108C[52];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_1010;
    s = *(u8 *)&fzgx_pool_gap_1014;
    s = *(u8 *)&fzgx_obj_camera_state;
    s = *(u8 *)&fzgx_pool_gap_103C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_104C;
    s = *(u8 *)&lbl_1_bss_104C__fzgx_offset_10;
    s = *(u8 *)&lbl_1_bss_108C;
}

#pragma section code_type ".text"

static inline void track_follow(BD54Vec *t, BD54Vec *a) {
    f32 (*src)[4];
    f32 (*dst)[4];
    f32 x;
    f32 z;
    f32 y;

    /* one name for the reads, one for the writes: as a chained pair the locked-cache matrix address stays a
     * real local, which gives retail's saved-register order (.bss base r29, flags r30) */
    dst = src = MTXA;
    psvec_set(t, src[2][3], src[1][3], src[0][3]);
    x = fzgx_obj_camera_state.unk_4.x += 0.1 * (t->x - fzgx_obj_camera_state.unk_4.x);
    y = fzgx_obj_camera_state.unk_4.y += 0.1 * (t->y - fzgx_obj_camera_state.unk_4.y);
    z = fzgx_obj_camera_state.unk_4.z += 0.1 * (t->z - fzgx_obj_camera_state.unk_4.z);
    fzgx_obj_camera_state.unk_10.x += 0.1 * (a->x - fzgx_obj_camera_state.unk_10.x);
    fzgx_obj_camera_state.unk_10.y += 0.1 * (a->y - fzgx_obj_camera_state.unk_10.y);
    fzgx_obj_camera_state.unk_10.z += 0.1 * (a->z - fzgx_obj_camera_state.unk_10.z);
    dst[0][3] = x;
    dst[1][3] = y;
    dst[2][3] = z;
}

/* retail multiplies and adds in separate fmul/fadd steps; with contraction MWCC fuses them into fmadd */
#pragma fp_contract off
void fn_1_BD54(void) {
    s16 rotY;
    s16 rotX;
    BD54Vec t;
    BD54Vec a;
    BD54Vec b;
    BD54Vec c;
    f32 value;
    u32 flags;

    lbl_1_data_4068 += (s8)lbl_1_bss_A48.unk_3 * 2;
    fzgx_obj_lbl_1_bss_1010 += 0.02 * (s8)lbl_1_bss_A48.unk_2;
    flags = fn_1_10780C(&a, &b, &c, &value);
    fn_80008C20(&a, &b, &c);
    if ((flags & 0x1400000) && !(flags & 1)) {
        lbl_8006E0B4(fzgx_obj_lbl_1_bss_1010, value, 60.0f);
    } else {
        lbl_8006E0B4(fzgx_obj_lbl_1_bss_1010, 15.0f, 60.0f);
    }
    mathutil_mtxA_rotate_x((s16)lbl_1_data_4068);
    track_follow(&t, &a);
    fn_8006FB20(lbl_1_bss_104C__fzgx_offset_10, 0.9f);
    lbl_8006DB74(lbl_1_bss_104C__fzgx_offset_10);
    fn_8006F3E4(&rotX, &rotY, &fzgx_obj_camera_state.unk_20);
    lbl_8006DF44();
    lbl_8006DB74(lbl_1_bss_108C);
}
#pragma fp_contract reset
/* fzgx:end fn_1_BD54 */

/* fzgx:begin fn_1_BFA0 pool */
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_1010;
u8 lbl_1_bss_1014;
u8 lbl_1_bss_1010_gap_1015;
u16 lbl_1_bss_1010_gap_1015_fill_1016;
CamEntry fzgx_obj_camera_state[2];
u32 camera_state_fill_1038;
u8 lbl_1_bss_103C[4];
f32 lbl_1_bss_1040;
f32 lbl_1_bss_1044;
u8 fzgx_obj_camera_flag_0;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_1010;
    s = *(u8 *)&lbl_1_bss_1014;
    s = *(u8 *)&lbl_1_bss_1010_gap_1015;
    s = *(u8 *)&lbl_1_bss_1010_gap_1015_fill_1016;
    s = *(u8 *)&fzgx_obj_camera_state;
    s = *(u8 *)&camera_state_fill_1038;
    s = *(u8 *)&lbl_1_bss_103C;
    s = *(u8 *)&lbl_1_bss_1040;
    s = *(u8 *)&lbl_1_bss_1044;
    s = *(u8 *)&fzgx_obj_camera_flag_0;
}
#pragma section code_type ".text"

/* Per-frame camera update: runs the pending callback and refreshes the camera state. */
void fn_1_BFA0(void) {
    if (lbl_1_bss_1014 != 0) {
        fn_1_CC5C();
    }
    if (fzgx_obj_camera_flag_0 != 0) {
        lbl_8006D9D8(&fzgx_obj_camera_state[1]);
        lbl_8006E14C(lbl_1_bss_1044);
        fn_1_55FC4(lbl_1_bss_1044);
        fn_80072558();
        fn_1_55FF0(lbl_1_bss_1040);
        if (lbl_801A6CE0 & 1) {
            fn_1_55210( (struct Model *)(u32)(lbl_1_bss_38454->unk_8->unk_20));
        }
    }
}
/* fzgx:end fn_1_BFA0 */

/* fzgx:begin fn_1_C038 */
void fn_1_C038(s32 value, f32 start, f32 end) {
    f32 difference;
    f32 ratio;
    f32 converted;

    difference = end - start;
    ratio = difference / (f32)(((u32)(value * value)) >> 2);

    lbl_1_bss_10C0[0] = start;
    lbl_1_bss_10C0[1] = end;
    lbl_1_bss_10C0[4] = lbl_1_rodata_49C;

    lbl_1_bss_10C0[5] = ratio;
    converted = (f32)(u32)value;
    lbl_1_bss_10C0[3] = converted;
    lbl_1_bss_10C0[2] = converted;
}
/* fzgx:end fn_1_C038 */

/* fzgx:begin camera_save_slot */
typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
} CameraSlot;

// Copies the current camera parameters into the selected camera slot.
void camera_save_slot(u8 index) {
    CameraSlot *dst = (CameraSlot *)&lbl_1_bss_10D8 + index;

    dst->unk_0 = camera_state.unk_0;
    dst->unk_4 = camera_state.unk_4;
    dst->unk_8 = camera_state.unk_8;
    dst->unk_C = camera_state.unk_C;
    dst->unk_10 = camera_state.unk_10;
    dst->unk_14 = camera_state.unk_14;
    dst->unk_18 = camera_state.unk_18;
    dst->unk_1C = camera_state.unk_1C;
    dst->unk_20 = *(u32 *)&camera_state.unk_20;
}
/* fzgx:end camera_save_slot */

/* fzgx:begin fn_1_C10C pool noprologue */
#include "types.h"

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
} CameraPreset;

typedef struct {
    u8 pad_0[0x5];
    u8 unk_5;
    u8 pad_6[0x2];
    CameraPreset current;
    u8 pad_2C[0x9C];
    CameraPreset presets[1];
} CameraState;


/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_1010;
u8 lbl_1_bss_1014;
u8 lbl_1_bss_1010_gap_1015;
u16 lbl_1_bss_1010_gap_1015_fill_1016;
CameraPreset fzgx_obj_camera_state;
u32 lbl_1_bss_103C;
u32 lbl_1_bss_1040;
u32 lbl_1_bss_1044;
u8 fzgx_obj_camera_flag_0;
u8 fzgx_obj_camera_flag_1;
u16 lbl_1_bss_1010_gap_104A;
u32 lbl_1_bss_104C[16];
u32 lbl_1_bss_108C[13];
u32 lbl_1_bss_10C0[6];
CameraPreset fzgx_obj_lbl_1_bss_10D8[1];
u32 lbl_1_bss_10D8_fill_10FC[19];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_1010;
    s = *(u8 *)&lbl_1_bss_1014;
    s = *(u8 *)&lbl_1_bss_1010_gap_1015;
    s = *(u8 *)&lbl_1_bss_1010_gap_1015_fill_1016;
    s = *(u8 *)&fzgx_obj_camera_state;
    s = *(u8 *)&lbl_1_bss_103C;
    s = *(u8 *)&lbl_1_bss_1040;
    s = *(u8 *)&lbl_1_bss_1044;
    s = *(u8 *)&fzgx_obj_camera_flag_0;
    s = *(u8 *)&fzgx_obj_camera_flag_1;
    s = *(u8 *)&lbl_1_bss_1010_gap_104A;
    s = *(u8 *)&lbl_1_bss_104C;
    s = *(u8 *)&lbl_1_bss_108C;
    s = *(u8 *)&lbl_1_bss_10C0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_10D8;
    s = *(u8 *)&lbl_1_bss_10D8_fill_10FC;
}
#pragma section code_type ".text"

void fn_1_C10C(u8 idx) {
    lbl_1_bss_1010_gap_1015 = 0;
    fzgx_obj_camera_state = fzgx_obj_lbl_1_bss_10D8[idx];
}
/* fzgx:end fn_1_C10C */

/* fzgx:begin fn_1_C178 */
typedef struct {
    u8 pad_0[0x4]; f32 unk_4; f32 unk_8; f32 unk_C; f32 unk_10; f32 unk_14; f32 unk_18; f32 unk_1C;
    s16 unk_20; u8 pad_22[0x6]; f32 unk_28; f32 unk_2C; f32 unk_30; f32 unk_34; f32 unk_38; f32 unk_3C; f32 unk_40;
    s16 unk_44; u8 pad_46[0x2A];
} Obj_1_bss_10D8;

void fn_1_C178(void *self) {
    OSReport((((char *)&lbl_1_data_406C)), lbl_1_bss_104C.unk_8, lbl_1_bss_104C.unk_C,
        (*((Obj_1_bss_10D8 *)&lbl_1_bss_10D8)).unk_4, (*((Obj_1_bss_10D8 *)&lbl_1_bss_10D8)).unk_8, (*((Obj_1_bss_10D8 *)&lbl_1_bss_10D8)).unk_C,
        (*((Obj_1_bss_10D8 *)&lbl_1_bss_10D8)).unk_10, (*((Obj_1_bss_10D8 *)&lbl_1_bss_10D8)).unk_14, (*((Obj_1_bss_10D8 *)&lbl_1_bss_10D8)).unk_18,
        (*((Obj_1_bss_10D8 *)&lbl_1_bss_10D8)).unk_1C, (*((Obj_1_bss_10D8 *)&lbl_1_bss_10D8)).unk_20);
    OSReport((((char *)&lbl_1_data_40C8)), (*((Obj_1_bss_10D8 *)&lbl_1_bss_10D8)).unk_28, (*((Obj_1_bss_10D8 *)&lbl_1_bss_10D8)).unk_2C,
        (*((Obj_1_bss_10D8 *)&lbl_1_bss_10D8)).unk_30, (*((Obj_1_bss_10D8 *)&lbl_1_bss_10D8)).unk_34, (*((Obj_1_bss_10D8 *)&lbl_1_bss_10D8)).unk_38,
        (*((Obj_1_bss_10D8 *)&lbl_1_bss_10D8)).unk_3C, (*((Obj_1_bss_10D8 *)&lbl_1_bss_10D8)).unk_40, (*((Obj_1_bss_10D8 *)&lbl_1_bss_10D8)).unk_44,
        self);
}
/* fzgx:end fn_1_C178 */

/* fzgx:begin camera_report_position */
// Reports the camera's current position values for debugging.
void camera_report_position(void) {
    OSReport((const char *)lbl_1_data_4128, lbl_1_bss_10D8.unk_10,
             lbl_1_bss_10D8.unk_14, lbl_1_bss_10D8.unk_18);
}
/* fzgx:end camera_report_position */

/* fzgx:begin fn_1_C268 */
#pragma opt_common_subs off
#pragma opt_strength_reduction off
void fn_1_C268(s32 arg) {
    if ((55.0) == lbl_1_bss_10D8.unk_1C) {
        OSReport((char *)lbl_1_data_4144, lbl_1_bss_10D8.unk_4,
                 lbl_1_bss_10D8.unk_8, lbl_1_bss_10D8.unk_C,
                 lbl_1_bss_10D8.unk_28, lbl_1_bss_10D8.unk_2C,
                 lbl_1_bss_10D8.unk_30, lbl_1_bss_10D8.unk_20, arg,
                 lbl_1_bss_10D8.unk_1C);
    } else {
        OSReport((char *)lbl_1_data_4198, lbl_1_bss_10D8.unk_4,
                 lbl_1_bss_10D8.unk_8, lbl_1_bss_10D8.unk_C,
                 lbl_1_bss_10D8.unk_28, lbl_1_bss_10D8.unk_2C,
                 lbl_1_bss_10D8.unk_30, lbl_1_bss_10D8.unk_20, arg,
                 lbl_1_bss_10D8.unk_1C);
    }
}
#pragma opt_strength_reduction reset

#pragma opt_common_subs reset
/* fzgx:end fn_1_C268 */

/* fzgx:begin fn_1_C304 */
// Reports the camera parameters and caller-supplied value for debugging.
void fn_1_C304(s32 arg) {
    OSReport((const char *)lbl_1_data_4198,
             lbl_1_bss_10D8.unk_4, lbl_1_bss_10D8.unk_8,
             lbl_1_bss_10D8.unk_C, lbl_1_bss_10D8.unk_10,
             lbl_1_bss_10D8.unk_14, lbl_1_bss_10D8.unk_18,
             lbl_1_bss_10D8.unk_20, arg,
             lbl_1_bss_10D8.unk_1C);
}
/* fzgx:end fn_1_C304 */

/* fzgx:begin camera_snapshot */
// Copies the live camera state into its snapshot and resets the snapshot flag.
void camera_snapshot(void) {
    lbl_1_bss_1010.unk_8 = lbl_1_bss_1010.unk_C8;
    lbl_1_bss_1010.unk_C = lbl_1_bss_1010.unk_CC;
    lbl_1_bss_1010.unk_10 = lbl_1_bss_1010.unk_D0;
    lbl_1_bss_1010.unk_14 = lbl_1_bss_1010.unk_D4;
    lbl_1_bss_1010.unk_18 = lbl_1_bss_1010.unk_D8;
    lbl_1_bss_1010.unk_1C = lbl_1_bss_1010.unk_DC;
    lbl_1_bss_1010.unk_20 = lbl_1_bss_1010.unk_E0;
    lbl_1_bss_1010.unk_24 = lbl_1_bss_1010.unk_E4;
    lbl_1_bss_1010.unk_28 = lbl_1_bss_1010.unk_E8;
    lbl_1_bss_1010.unk_3C = 0;
}
/* fzgx:end camera_snapshot */

/* fzgx:begin fn_1_C3B8 pool noprologue */
#include "types.h"

typedef struct {
    f32 x, y, z;
} CamVec;

typedef struct {
    u32 unk_0;
    CamVec pos;
    CamVec at;
    f32 unk_1C;
    s16 unk_20;
} CamKey;

typedef struct {
    s32 counter;
    s32 state;
    s32 total;
    f32 rate;
    u8 pad_10[0x30];
} CamCtl;

typedef struct {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
} CamSway;

extern void lbl_8006D5A4(CamVec *a, CamVec *b, CamVec *out, f32 t);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_1010;
u8 lbl_1_bss_1014;
u8 lbl_1_bss_1010_gap_1015;
u16 lbl_1_bss_1010_gap_1015_fill_1016;
CamKey fzgx_obj_camera_state;
u32 lbl_1_bss_103C;
u32 lbl_1_bss_1040;
u32 lbl_1_bss_1044;
u8 fzgx_obj_camera_flag_0;
u8 fzgx_obj_camera_flag_1;
u16 lbl_1_bss_1010_gap_104A;
CamCtl lbl_1_bss_104C;
u32 lbl_1_bss_108C[13];
CamSway lbl_1_bss_10C0;
CamKey fzgx_obj_lbl_1_bss_10D8[2];
u32 lbl_1_bss_10D8_fill_1120[10];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_1010;
    s = *(u8 *)&lbl_1_bss_1014;
    s = *(u8 *)&lbl_1_bss_1010_gap_1015;
    s = *(u8 *)&lbl_1_bss_1010_gap_1015_fill_1016;
    s = *(u8 *)&fzgx_obj_camera_state;
    s = *(u8 *)&lbl_1_bss_103C;
    s = *(u8 *)&lbl_1_bss_1040;
    s = *(u8 *)&lbl_1_bss_1044;
    s = *(u8 *)&fzgx_obj_camera_flag_0;
    s = *(u8 *)&fzgx_obj_camera_flag_1;
    s = *(u8 *)&lbl_1_bss_1010_gap_104A;
    s = *(u8 *)&lbl_1_bss_104C;
    s = *(u8 *)&lbl_1_bss_108C;
    s = *(u8 *)&lbl_1_bss_10C0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_10D8;
    s = *(u8 *)&lbl_1_bss_10D8_fill_1120;
}
#pragma section code_type ".text"

void fn_1_C3B8(void) {
    CamKey from = fzgx_obj_lbl_1_bss_10D8[0];
    CamKey to = fzgx_obj_lbl_1_bss_10D8[1];
    f32 t;

    switch (lbl_1_bss_104C.state) {
    case 0:
        t = (f32)lbl_1_bss_104C.counter / (f32)lbl_1_bss_104C.total;
        lbl_8006D5A4(&from.pos, &to.pos, &fzgx_obj_camera_state.pos, t);
        lbl_8006D5A4(&from.at, &to.at, &fzgx_obj_camera_state.at, t);
        fzgx_obj_camera_state.unk_1C = from.unk_1C + (f32)(t * (to.unk_1C - from.unk_1C));
        fzgx_obj_camera_state.unk_20 = from.unk_20 + (s16)(t * (to.unk_20 - from.unk_20));
        if (lbl_1_bss_104C.counter >= lbl_1_bss_104C.total) {
            lbl_1_bss_1010_gap_1015 = 0;
        }
        break;
    case 3:
        lbl_1_bss_10C0.unk_8 -= 1.0f;
        if (lbl_1_bss_10C0.unk_8 < lbl_1_bss_10C0.unk_C / 2.0f) {
            lbl_1_bss_10C0.unk_10 -= lbl_1_bss_10C0.unk_14;
        } else {
            lbl_1_bss_10C0.unk_10 += lbl_1_bss_10C0.unk_14;
        }
        t = lbl_1_bss_10C0.unk_0 + lbl_1_bss_10C0.unk_10;
        lbl_1_bss_10C0.unk_0 = t;
        lbl_8006D5A4(&from.pos, &to.pos, &fzgx_obj_camera_state.pos, t);
        lbl_8006D5A4(&from.at, &to.at, &fzgx_obj_camera_state.at, t);
        fzgx_obj_camera_state.unk_1C = from.unk_1C + (f32)(t * (to.unk_1C - from.unk_1C));
        fzgx_obj_camera_state.unk_20 = from.unk_20 + (s16)(t * (to.unk_20 - from.unk_20));
        if (lbl_1_bss_104C.counter >= lbl_1_bss_104C.total) {
            lbl_1_bss_1010_gap_1015 = 0;
        }
        break;
    case 2:
        lbl_8006D5A4(&fzgx_obj_camera_state.pos, &to.pos, &fzgx_obj_camera_state.pos, lbl_1_bss_104C.rate);
        lbl_8006D5A4(&fzgx_obj_camera_state.at, &to.at, &fzgx_obj_camera_state.at, lbl_1_bss_104C.rate);
        fzgx_obj_camera_state.unk_1C += (f32)(lbl_1_bss_104C.rate * (to.unk_1C - fzgx_obj_camera_state.unk_1C));
        fzgx_obj_camera_state.unk_20 += (s32)(lbl_1_bss_104C.rate * (to.unk_20 - fzgx_obj_camera_state.unk_20));
        break;
    }
    lbl_1_bss_104C.counter++;
}
/* fzgx:end fn_1_C3B8 */

/* fzgx:begin fn_1_C770 pool noprologue */
#include "types.h"

typedef struct {
    u16 unk_0;
    u8 pad_2[0x6];
    u16 unk_8;
    u8 pad_A[0x6];
    u16 unk_10;
} PadState;

typedef struct {
    u32 w[9];
} CamKey;

typedef struct {
    s32 counter;
    s32 state;
    s32 total;
    f32 rate;
    u8 pad_10[0x30];
} CamCtl;

typedef struct {
    u8 pad_0[0x14];
    f32 unk_14;
} Obj_BF0;

extern PadState lbl_1_bss_D58;
extern f32 lbl_1_bss_BF0[32];
extern void OSReport(const char *, ...);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_1010;
u8 lbl_1_bss_1014;
u8 lbl_1_bss_1010_gap_1015;
u16 lbl_1_bss_1010_gap_1015_fill_1016;
CamKey fzgx_obj_camera_state;
u32 lbl_1_bss_103C;
u32 lbl_1_bss_1040;
u32 lbl_1_bss_1044;
u8 fzgx_obj_camera_flag_0;
u8 fzgx_obj_camera_flag_1;
u16 lbl_1_bss_1010_gap_104A;
CamCtl lbl_1_bss_104C;
u32 lbl_1_bss_108C[13];
u32 lbl_1_bss_10C0[6];
CamKey fzgx_obj_lbl_1_bss_10D8[2];
CamKey lbl_1_bss_1120;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_1010;
    s = *(u8 *)&lbl_1_bss_1014;
    s = *(u8 *)&lbl_1_bss_1010_gap_1015;
    s = *(u8 *)&lbl_1_bss_1010_gap_1015_fill_1016;
    s = *(u8 *)&fzgx_obj_camera_state;
    s = *(u8 *)&lbl_1_bss_103C;
    s = *(u8 *)&lbl_1_bss_1040;
    s = *(u8 *)&lbl_1_bss_1044;
    s = *(u8 *)&fzgx_obj_camera_flag_0;
    s = *(u8 *)&fzgx_obj_camera_flag_1;
    s = *(u8 *)&lbl_1_bss_1010_gap_104A;
    s = *(u8 *)&lbl_1_bss_104C;
    s = *(u8 *)&lbl_1_bss_108C;
    s = *(u8 *)&lbl_1_bss_10C0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_10D8;
    s = *(u8 *)&lbl_1_bss_1120;
}

/* the camera TU's literal pool in retail order, ahead of this function's constants */
static void fzgx_pool_head(f32 *f) {
    f[0] = 1.0f;
    f[1] = 0.1f;
    f[2] = 0.01f;
    f[3] = 55.0f;
}

static const u32 fzgx_pool_table_10[6] = { 0, 0, 0, 0, 0, 0 };

static void fzgx_pool_tail(f64 *d, f32 *f) {
    d[0] = fzgx_pool_table_10[0];
    d[1] = 0.040000000000000008;
    d[2] = 1.0;
    d[3] = 4.0;
    d[4] = 140.0;
    d[5] = 50.0;
    d[6] = 60.0;
    d[7] = 0.09;
    d[8] = 0.3;
    d[9] = 0.1;
    d[10] = 90000.0;
    d[11] = 4503599627370496.0;
    d[12] = 4503601774854144.0;
    d[13] = 0.02;
    f[0] = 60.0f;
    f[1] = 15.0f;
    f[2] = 0.9f;
    f[3] = 0.0f;
    f[4] = 0.5f;
    d[14] = 55.0;
    f[5] = 10.0f;
    d[15] = 0.0;
    d[16] = 0.5;
    d[17] = 0.0001;
}
#pragma section code_type ".text"

u16 lbl_1_data_4068 = 0xF000;
u8 lbl_1_data_406A = 9;
u8 lbl_1_data_406B = 3;

#pragma section code_type ".fzgxpool"
/* this TU's .data in retail order: the menu bytes, then the report strings ahead of this function's */
static void fzgx_data_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink */
    s = lbl_1_data_4068;
    s = lbl_1_data_406A;
    s = lbl_1_data_406B;
    OSReport("\t{ %3d, %1.3f, {  0,{  %8.3f, %8.3f, %8.3f }, {  %8.3f, %8.3f, %8.3f },  %5.1f, %5d, 0,},\n");
    OSReport("\t              {  0,{  %8.3f, %8.3f, %8.3f }, {  %8.3f, %8.3f, %8.3f },  %5.1f, %5d, 0,}, %s},\n");
    OSReport("\t{  %8.3f, %8.3f, %8.3f },\n");
    OSReport("\t{ 00,{  %8.3f, %8.3f, %8.3f }, {  %8.3f, %8.3f, %8.3f }, %5d,  PERS_DEGREE, %s},\n");
    OSReport("\t{ 00,{  %8.3f, %8.3f, %8.3f }, {  %8.3f, %8.3f, %8.3f }, %5d,  %11.3f, %s},\n");
}
#pragma section code_type ".text"

extern void camera_save_slot(u8);
extern void camera_snapshot(void);
extern void fn_1_C038(f32, f32, s32);
extern void fn_1_C10C(u8);
extern void fn_1_C178(void *);
extern void camera_report_position(void);
extern void fn_1_C268(s32);
extern void fn_1_C304(s32);
extern void fn_1_C3B8(void);

/* step v past one end of [lo, hi] and it restarts from the other */
#define WRAP(v, lo, hi) ((v) > (hi) ? (lo) : ((v) < (lo) ? (hi) : (v)))

#pragma opt_common_subs off
static inline s32 menu_wrap(s32 value, s32 direction, s32 amount) {
    value += direction * amount;
    return WRAP(value, 0, 15);
}

static inline s32 menu_prev(s32 item) {
    if (item - 1 > 38) return 0;
    --item;
    return item < 0 ? 38 : item;
}
static inline s32 menu_next(s32 item) {
    if (item + 1 > 38) return 0;
    ++item;
    return item < 0 ? 38 : item;
}
#pragma opt_common_subs on

/* Debug camera menu: up/down picks an item, left/right edits or triggers it. */
void fn_1_C770(void) {
    PadState *pad = &lbl_1_bss_D58;
    s32 item;
    s32 dir;
    s32 step;
    s32 n;
    s32 v;
    f64 f;
    f64 d;

    dir = 0;
    step = 1;
    if ((pad->unk_10 >> 8) & 1) {
        dir = 1;
    } else if ((pad->unk_10 >> 9) & 1) {
        dir = -1;
    }
    if (lbl_1_bss_BF0[5]) {
        step = 10.0f * lbl_1_bss_BF0[5];
    }

    item = lbl_1_data_406B;
    if (item == 1) {
        n = lbl_1_data_406A;
        n += dir * step;
        if (n > 15) {
            v = 0;
        } else {
            v = n < 0 ? 15 : n;
        }
        lbl_1_data_406A = v;
    }
    if (item == 2 && dir != 0) {
        lbl_1_bss_1014 = 0;
    }
    if (item == 3 && dir != 0) {
        camera_save_slot(0);
    }
    if ((s32)lbl_1_data_406B == 4 && dir != 0) {
        camera_save_slot(1);
    }
    if ((s32)lbl_1_data_406B == 5) {
        d = 0.0001 * dir * step;
        f = WRAP(lbl_1_bss_104C.rate + d, 0.0, 0.5);
        lbl_1_bss_104C.rate = f;
    }
    if ((s32)lbl_1_data_406B == 6) {
        v = lbl_1_bss_104C.total + dir * step;
        lbl_1_bss_104C.total = WRAP(v, 0, 1000);
    }
    if ((s32)lbl_1_data_406B == 7 && dir != 0) {
        lbl_1_bss_1010_gap_1015 = 1;
        lbl_1_bss_1120 = fzgx_obj_camera_state;
        lbl_1_bss_104C.state = 0;
        camera_snapshot();
    }
    if ((s32)lbl_1_data_406B == 8 && dir != 0) {
        lbl_1_bss_1010_gap_1015 = 1;
        lbl_1_bss_1120 = fzgx_obj_camera_state;
        lbl_1_bss_104C.state = 3;
        fn_1_C038(0.0f, 1.0f, lbl_1_bss_104C.total);
        camera_snapshot();
    }
    if ((s32)lbl_1_data_406B == 9 && dir != 0) {
        lbl_1_bss_1010_gap_1015 = 1;
        lbl_1_bss_1120 = fzgx_obj_camera_state;
        lbl_1_bss_104C.state = 2;
        camera_snapshot();
    }
    if ((s32)lbl_1_data_406B == 10 && dir != 0) {
        fn_1_C10C(0);
    }
    if ((s32)lbl_1_data_406B == 11 && dir != 0) {
        fn_1_C10C(1);
    }
    if ((s32)lbl_1_data_406B == 12 && dir != 0) {
        lbl_1_bss_1014 = 0;
    }
    if ((s32)lbl_1_data_406B == 13 && dir != 0) {
        fn_1_C178("NORMAL");
    }
    if ((s32)lbl_1_data_406B == 14 && dir != 0) {
        fn_1_C178("EASE_OUT");
    }
    if ((s32)lbl_1_data_406B == 15 && dir != 0) {
        fn_1_C178("EASE_IN_OUT");
    }
    if ((s32)lbl_1_data_406B == 16 && dir != 0) {
        camera_report_position();
    }
    if ((s32)lbl_1_data_406B == 17 && dir != 0) {
        fn_1_C268((s32)"STATIC_MOVE_PERS");
    }
    if ((s32)lbl_1_data_406B == 18 && dir != 0) {
        fn_1_C304((s32)"STATIC_FIX");
    }

    if ((pad->unk_10 >> 3) & 1) {
        lbl_1_data_406B = menu_prev(lbl_1_data_406B);
    } else if ((pad->unk_10 >> 2) & 1) {
        lbl_1_data_406B = menu_next(lbl_1_data_406B);
    }

    if (lbl_1_bss_1010_gap_1015 != 0) {
        fn_1_C3B8();
    }
    if (((lbl_1_bss_D58.unk_0 >> 10) & 1) && ((lbl_1_bss_D58.unk_8 >> 11) & 1)) {
        lbl_1_bss_1010_gap_1015 = 0;
        lbl_1_bss_1014 = 0;
    }
}
/* fzgx:end fn_1_C770 */

/* fzgx:begin fn_1_CC5C pool noprologue */
#include "types.h"
#include "rel/main_rel/camera.h"

/* RGBA colour, passed by value (MWCC copies it to the stack per call) */
typedef struct { u8 r, g, b, a; } fn_1_CC5C_Color;

/* camera debug menu: cursor/selection bytes followed by the row format strings */
typedef struct {
    u8 pad_0[0x2];
    u8 cursor;
    u8 selected;
    u8 pad_4[0x1BC];
    char fmt_1C0[0x10];
    char fmt_1D0[0x8];
    char fmt_1D8[0x8];
    char fmt_1E0[0x10];
    char fmt_1F0[0x10];
    char fmt_200[0xC];
    char fmt_20C[0xC];
    char fmt_218[0x14];
    char fmt_22C[0x14];
    char fmt_240[0x14];
    char fmt_254[0x10];
    char fmt_264[0x10];
    char fmt_274[0xC];
    char fmt_280[0x8];
    char fmt_288[0x8];
    char fmt_290[0xC];
    char fmt_29C[0x8];
    char fmt_2A4[0x8];
    char fmt_2AC[0x10];
    char fmt_2BC[0x4];
    char fmt_2C0[0xC];
    char fmt_2CC[0xC];
    char fmt_2D8[0x10];
    char fmt_2E8[0x10];
    char fmt_2F8[0xC];
    char fmt_304[0xC];
    char fmt_310[0x10];
    char fmt_320[0x10];
    char fmt_330[0x10];
    char fmt_340[0x10];
} fn_1_CC5C_DebugMenu;


u16 lbl_1_data_4068 = 0xF000;
u8 fn_1_CC5C_menu_cursor = 9;
u8 fn_1_CC5C_menu_selected = 3;
u8 fn_1_CC5C_menu_data_pad[0x1BC] = {
    0x09, 0x7B, 0x20, 0x25, 0x33, 0x64, 0x2C, 0x20, 0x25, 0x31, 0x2E, 0x33, 0x66, 0x2C, 0x20, 0x7B,
    0x20, 0x20, 0x30, 0x2C, 0x7B, 0x20, 0x20, 0x25, 0x38, 0x2E, 0x33, 0x66, 0x2C, 0x20, 0x25, 0x38,
    0x2E, 0x33, 0x66, 0x2C, 0x20, 0x25, 0x38, 0x2E, 0x33, 0x66, 0x20, 0x7D, 0x2C, 0x20, 0x7B, 0x20,
    0x20, 0x25, 0x38, 0x2E, 0x33, 0x66, 0x2C, 0x20, 0x25, 0x38, 0x2E, 0x33, 0x66, 0x2C, 0x20, 0x25,
    0x38, 0x2E, 0x33, 0x66, 0x20, 0x7D, 0x2C, 0x20, 0x20, 0x25, 0x35, 0x2E, 0x31, 0x66, 0x2C, 0x20,
    0x25, 0x35, 0x64, 0x2C, 0x20, 0x30, 0x2C, 0x7D, 0x2C, 0x0A, 0x00, 0x00, 0x09, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x7B, 0x20, 0x20, 0x30, 0x2C,
    0x7B, 0x20, 0x20, 0x25, 0x38, 0x2E, 0x33, 0x66, 0x2C, 0x20, 0x25, 0x38, 0x2E, 0x33, 0x66, 0x2C,
    0x20, 0x25, 0x38, 0x2E, 0x33, 0x66, 0x20, 0x7D, 0x2C, 0x20, 0x7B, 0x20, 0x20, 0x25, 0x38, 0x2E,
    0x33, 0x66, 0x2C, 0x20, 0x25, 0x38, 0x2E, 0x33, 0x66, 0x2C, 0x20, 0x25, 0x38, 0x2E, 0x33, 0x66,
    0x20, 0x7D, 0x2C, 0x20, 0x20, 0x25, 0x35, 0x2E, 0x31, 0x66, 0x2C, 0x20, 0x25, 0x35, 0x64, 0x2C,
    0x20, 0x30, 0x2C, 0x7D, 0x2C, 0x20, 0x25, 0x73, 0x7D, 0x2C, 0x0A, 0x00, 0x09, 0x7B, 0x20, 0x20,
    0x25, 0x38, 0x2E, 0x33, 0x66, 0x2C, 0x20, 0x25, 0x38, 0x2E, 0x33, 0x66, 0x2C, 0x20, 0x25, 0x38,
    0x2E, 0x33, 0x66, 0x20, 0x7D, 0x2C, 0x0A, 0x00, 0x09, 0x7B, 0x20, 0x30, 0x30, 0x2C, 0x7B, 0x20,
    0x20, 0x25, 0x38, 0x2E, 0x33, 0x66, 0x2C, 0x20, 0x25, 0x38, 0x2E, 0x33, 0x66, 0x2C, 0x20, 0x25,
    0x38, 0x2E, 0x33, 0x66, 0x20, 0x7D, 0x2C, 0x20, 0x7B, 0x20, 0x20, 0x25, 0x38, 0x2E, 0x33, 0x66,
    0x2C, 0x20, 0x25, 0x38, 0x2E, 0x33, 0x66, 0x2C, 0x20, 0x25, 0x38, 0x2E, 0x33, 0x66, 0x20, 0x7D,
    0x2C, 0x20, 0x25, 0x35, 0x64, 0x2C, 0x20, 0x20, 0x50, 0x45, 0x52, 0x53, 0x5F, 0x44, 0x45, 0x47,
    0x52, 0x45, 0x45, 0x2C, 0x20, 0x25, 0x73, 0x7D, 0x2C, 0x0A, 0x00, 0x00, 0x09, 0x7B, 0x20, 0x30,
    0x30, 0x2C, 0x7B, 0x20, 0x20, 0x25, 0x38, 0x2E, 0x33, 0x66, 0x2C, 0x20, 0x25, 0x38, 0x2E, 0x33,
    0x66, 0x2C, 0x20, 0x25, 0x38, 0x2E, 0x33, 0x66, 0x20, 0x7D, 0x2C, 0x20, 0x7B, 0x20, 0x20, 0x25,
    0x38, 0x2E, 0x33, 0x66, 0x2C, 0x20, 0x25, 0x38, 0x2E, 0x33, 0x66, 0x2C, 0x20, 0x25, 0x38, 0x2E,
    0x33, 0x66, 0x20, 0x7D, 0x2C, 0x20, 0x25, 0x35, 0x64, 0x2C, 0x20, 0x20, 0x25, 0x31, 0x31, 0x2E,
    0x33, 0x66, 0x2C, 0x20, 0x25, 0x73, 0x7D, 0x2C, 0x0A, 0x00, 0x00, 0x00, 0x4E, 0x4F, 0x52, 0x4D,
    0x41, 0x4C, 0x00, 0x00, 0x45, 0x41, 0x53, 0x45, 0x5F, 0x4F, 0x55, 0x54, 0x00, 0x00, 0x00, 0x00,
    0x45, 0x41, 0x53, 0x45, 0x5F, 0x49, 0x4E, 0x5F, 0x4F, 0x55, 0x54, 0x00, 0x53, 0x54, 0x41, 0x54,
    0x49, 0x43, 0x5F, 0x4D, 0x4F, 0x56, 0x45, 0x5F, 0x50, 0x45, 0x52, 0x53, 0x00, 0x00, 0x00, 0x00,
    0x53, 0x54, 0x41, 0x54, 0x49, 0x43, 0x5F, 0x46, 0x49, 0x58, 0x00, 0x00,
};
char fn_1_CC5C_fmt_1C0[0x10] = { 0x43, 0x41, 0x4D, 0x83, 0x47, 0x83, 0x66, 0x83, 0x42, 0x83, 0x5E, 0x0A, 0x00, 0x00, 0x00, 0x00 };
char fn_1_CC5C_fmt_1D0[0x8] = { 0x82, 0xA2, 0x82, 0xC7, 0x82, 0xA4, 0x20, 0x00 };
char fn_1_CC5C_fmt_1D8[0x8] = { 0x82, 0xC6, 0x82, 0xB6, 0x82, 0xE9, 0x0A, 0x00 };
char fn_1_CC5C_fmt_1E0[0x10] = { 0x83, 0x5A, 0x83, 0x62, 0x83, 0x67, 0x20, 0x83, 0x4A, 0x83, 0x81, 0x83, 0x89, 0x41, 0x0A, 0x00 };
char fn_1_CC5C_fmt_1F0[0x10] = { 0x83, 0x5A, 0x83, 0x62, 0x83, 0x67, 0x20, 0x83, 0x4A, 0x83, 0x81, 0x83, 0x89, 0x42, 0x0A, 0x00 };
char fn_1_CC5C_fmt_200[0xC] = { 0x91, 0xAC, 0x93, 0x78, 0x20, 0x25, 0x31, 0x2E, 0x33, 0x66, 0x0A, 0x00 };
char fn_1_CC5C_fmt_20C[0xC] = { 0x83, 0x52, 0x83, 0x7D, 0x20, 0x25, 0x33, 0x64, 0x0A, 0x00, 0x00, 0x00 };
char fn_1_CC5C_fmt_218[0x14] = { 0x4E, 0x4F, 0x52, 0x4D, 0x41, 0x4C, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x3A, 0x20, 0x50, 0x4C, 0x41, 0x59, 0x0A, 0x00 };
char fn_1_CC5C_fmt_22C[0x14] = { 0x45, 0x41, 0x53, 0x45, 0x5F, 0x49, 0x4E, 0x5F, 0x4F, 0x55, 0x54, 0x20, 0x3A, 0x20, 0x50, 0x4C, 0x41, 0x59, 0x0A, 0x00 };
char fn_1_CC5C_fmt_240[0x14] = { 0x45, 0x41, 0x53, 0x45, 0x5F, 0x4F, 0x55, 0x54, 0x20, 0x20, 0x20, 0x20, 0x3A, 0x20, 0x50, 0x4C, 0x41, 0x59, 0x0A, 0x00 };
char fn_1_CC5C_fmt_254[0x10] = { 0x83, 0x4A, 0x83, 0x81, 0x83, 0x89, 0x41, 0x82, 0xC9, 0x88, 0xDA, 0x93, 0xAE, 0x0A, 0x00, 0x00 };
char fn_1_CC5C_fmt_264[0x10] = { 0x83, 0x4A, 0x83, 0x81, 0x83, 0x89, 0x42, 0x82, 0xC9, 0x88, 0xDA, 0x93, 0xAE, 0x0A, 0x00, 0x00 };
char fn_1_CC5C_fmt_274[0xC] = { 0x82, 0xC6, 0x82, 0xB6, 0x82, 0xE9, 0x0A, 0x0A, 0x00, 0x00, 0x00, 0x00 };
char fn_1_CC5C_fmt_280[0x8] = { 0x20, 0x4E, 0x4F, 0x52, 0x4D, 0x41, 0x4C, 0x00 };
char fn_1_CC5C_fmt_288[0x8] = { 0x20, 0x4F, 0x55, 0x54, 0x00, 0x00, 0x00, 0x00 };
char fn_1_CC5C_fmt_290[0xC] = { 0x20, 0x49, 0x4E, 0x5F, 0x4F, 0x55, 0x54, 0x0A, 0x00, 0x00, 0x00, 0x00 };
char fn_1_CC5C_fmt_29C[0x8] = { 0x20, 0x43, 0x41, 0x4D, 0x5F, 0x42, 0x00, 0x00 };
char fn_1_CC5C_fmt_2A4[0x8] = { 0x20, 0x53, 0x54, 0x41, 0x54, 0x49, 0x43, 0x00 };
char fn_1_CC5C_fmt_2AC[0x10] = { 0x20, 0x53, 0x54, 0x41, 0x54, 0x49, 0x43, 0x5F, 0x46, 0x49, 0x58, 0x0A, 0x00, 0x00, 0x00, 0x00 };
char fn_1_CC5C_fmt_2BC[0x4] = { 0x0A, 0x00, 0x00, 0x00 };
char fn_1_CC5C_fmt_2C0[0xC] = { 0x54, 0x49, 0x4D, 0x45, 0x52, 0x3A, 0x25, 0x64, 0x0A, 0x00, 0x00, 0x00 };
char fn_1_CC5C_fmt_2CC[0xC] = { 0x20, 0x70, 0x65, 0x72, 0x73, 0x3A, 0x25, 0x35, 0x2E, 0x33, 0x66, 0x00 };
char fn_1_CC5C_fmt_2D8[0x10] = { 0x20, 0x7A, 0x61, 0x6E, 0x67, 0x3A, 0x25, 0x30, 0x34, 0x68, 0x78, 0x0A, 0x00, 0x00, 0x00, 0x00 };
char fn_1_CC5C_fmt_2E8[0x10] = { 0x83, 0x4A, 0x83, 0x81, 0x83, 0x89, 0x41, 0x20, 0x78, 0x3A, 0x25, 0x35, 0x2E, 0x33, 0x66, 0x00 };
char fn_1_CC5C_fmt_2F8[0xC] = { 0x20, 0x79, 0x3A, 0x25, 0x35, 0x2E, 0x33, 0x66, 0x00, 0x00, 0x00, 0x00 };
char fn_1_CC5C_fmt_304[0xC] = { 0x20, 0x7A, 0x3A, 0x25, 0x35, 0x2E, 0x33, 0x66, 0x0A, 0x00, 0x00, 0x00 };
char fn_1_CC5C_fmt_310[0x10] = { 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x20, 0x20, 0x78, 0x3A, 0x25, 0x35, 0x2E, 0x33, 0x66, 0x00 };
char fn_1_CC5C_fmt_320[0x10] = { 0x20, 0x20, 0x70, 0x65, 0x72, 0x73, 0x3A, 0x25, 0x35, 0x2E, 0x33, 0x66, 0x0A, 0x00, 0x00, 0x00 };
char fn_1_CC5C_fmt_330[0x10] = { 0x20, 0x20, 0x7A, 0x61, 0x6E, 0x67, 0x3A, 0x25, 0x30, 0x34, 0x68, 0x78, 0x0A, 0x00, 0x00, 0x00 };
char fn_1_CC5C_fmt_340[0x10] = { 0x83, 0x4A, 0x83, 0x81, 0x83, 0x89, 0x42, 0x20, 0x78, 0x3A, 0x25, 0x35, 0x2E, 0x33, 0x66, 0x00 };
extern void fn_1_49410(void);
extern void fn_1_49514(fn_1_CC5C_Color);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495FC(void);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4A0D8(const char *);
extern void fn_1_4AE0C(const char *, ...);

#pragma opt_common_subs off
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_1010;
u8 lbl_1_bss_1014;
u8 lbl_1_bss_1010_gap_1015;
u16 lbl_1_bss_1010_gap_1015_fill_1016;
u8 fzgx_obj_camera_state;
u8 camera_state_fill_1019;
u16 camera_state_fill_101A;
u32 camera_state_fill_101C[8];
u32 lbl_1_bss_103C;
u32 lbl_1_bss_1040;
u32 lbl_1_bss_1044;
u8 fzgx_obj_camera_flag_0;
u8 fzgx_obj_camera_flag_1;
u16 lbl_1_bss_1010_gap_104A;
u32 fzgx_obj_lbl_1_bss_104C;
u32 lbl_1_bss_104C_fill_1050[15];
u32 lbl_1_bss_108C[13];
u32 lbl_1_bss_10C0[6];
u8 fzgx_obj_lbl_1_bss_10D8;
u8 lbl_1_bss_10D8_fill_10D9;
u16 lbl_1_bss_10D8_fill_10DA;
u32 lbl_1_bss_10D8_fill_10DC[26];
u8 lbl_1_bss_10D8_6C;
u8 lbl_1_bss_10D8_fill_1145;
u16 lbl_1_bss_10D8_fill_1146;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_1010;
    s = *(u8 *)&lbl_1_bss_1014;
    s = *(u8 *)&lbl_1_bss_1010_gap_1015;
    s = *(u8 *)&lbl_1_bss_1010_gap_1015_fill_1016;
    s = *(u8 *)&fzgx_obj_camera_state;
    s = *(u8 *)&camera_state_fill_1019;
    s = *(u8 *)&camera_state_fill_101A;
    s = *(u8 *)&camera_state_fill_101C;
    s = *(u8 *)&lbl_1_bss_103C;
    s = *(u8 *)&lbl_1_bss_1040;
    s = *(u8 *)&lbl_1_bss_1044;
    s = *(u8 *)&fzgx_obj_camera_flag_0;
    s = *(u8 *)&fzgx_obj_camera_flag_1;
    s = *(u8 *)&lbl_1_bss_1010_gap_104A;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_104C;
    s = *(u8 *)&lbl_1_bss_104C_fill_1050;
    s = *(u8 *)&lbl_1_bss_108C;
    s = *(u8 *)&lbl_1_bss_10C0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_10D8;
    s = *(u8 *)&lbl_1_bss_10D8_fill_10D9;
    s = *(u8 *)&lbl_1_bss_10D8_fill_10DA;
    s = *(u8 *)&lbl_1_bss_10D8_fill_10DC;
    s = *(u8 *)&lbl_1_bss_10D8_6C;
    s = *(u8 *)&lbl_1_bss_10D8_fill_1145;
    s = *(u8 *)&lbl_1_bss_10D8_fill_1146;
}

/* literal pool of the retail TU in retail order; this function's own
 * colour table and 2.0f follow the 0.0001 double. */
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0f;
    s = 0.10000000149011612f;
    s = 0.009999999776482582f;
    s = 55.0f;
}
static const unsigned long fzgx_pool_table2[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.04000000000000001;
    d = 1.0;
    d = 4.0;
    d = 140.0;
    d = 50.0;
    d = 60.0;
    d = 0.09;
    d = 0.3;
    d = 0.1;
    d = 90000.0;
    d = 4503599627370496.0;
    d = 4503601774854144.0;
    d = 0.02;
    s = 60.0f;
    s = 15.0f;
    s = 0.8999999761581421f;
    s = 0.0f;
    s = 0.5f;
}
static const unsigned long fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 55.0;
    s = 10.0f;
}
static const unsigned long fzgx_pool_table6[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 0.5;
    d = 0.0001;
}
#pragma section code_type ".text"

/* one past the camera state block: a field address equal to it has no value to show */
#define END_ADDR ((u32)&lbl_1_bss_10D8_6C)

/* the field address is advanced through a pointer cast so the offset stays on the
 * address variable (retail: addi r3, r3, 0xc; lfs f1, 0x0(r3)) */
#define ADVANCE(off) p = (u32)((u8 *)p + (off))
#define FIELD(type) (*(type *)p)

#define SELECT_COLOR(n) \
    if ((s32)fn_1_CC5C_menu_selected == (n)) fn_1_49514(colors[0]); else fn_1_49514(colors[2])

#define PRINT_VALUE(fmt, val) \
    if (p != END_ADDR) fn_1_4AE0C(fmt, val); else fn_1_4A0D8(fmt)

#define PRINT_VALUE2(fmt, val) \
    if (p != END_ADDR) { \
        if (p == END_ADDR) fn_1_4AE0C(fmt, val); else fn_1_4AE0C(fmt, val); \
    } else fn_1_4A0D8(fmt)

void fn_1_CC5C(void) {
    fn_1_CC5C_Color colors[3] = { { 0x00, 0xFF, 0x00, 0xFF }, { 0x80, 0x80, 0x80, 0xFF }, { 0xFF, 0xFF, 0xFF, 0xFF } };
    u8 idx;
    u16 x;
    u16 y;
    u32 p;

    idx = fn_1_CC5C_menu_cursor;
    x = (idx % 4) * 150;
    y = ((idx >> 2) & 0x3F) * 60;
    if (((lbl_1_bss_D58.unk_2 >> 8) & 1) == 0) {
        fn_1_49410();
        fn_1_4954C(2.0f);
        fn_1_4955C(0.5f, 0.5f);
        fn_1_495FC();
        fn_1_496FC((f32)x, (f32)y);

        SELECT_COLOR(0);
        fn_1_4A0D8(fn_1_CC5C_fmt_1C0);
        SELECT_COLOR(1);
        p = (u32)&fn_1_CC5C_menu_cursor;
        PRINT_VALUE(fn_1_CC5C_fmt_1D0, fn_1_CC5C_menu_cursor);
        SELECT_COLOR(2);
        fn_1_4A0D8(fn_1_CC5C_fmt_1D8);
        SELECT_COLOR(3);
        fn_1_4A0D8(fn_1_CC5C_fmt_1E0);
        SELECT_COLOR(4);
        fn_1_4A0D8(fn_1_CC5C_fmt_1F0);
        SELECT_COLOR(5);
        p = (u32)&fzgx_obj_lbl_1_bss_104C;
        ADVANCE(12);
        PRINT_VALUE2(fn_1_CC5C_fmt_200, FIELD(f32));
        SELECT_COLOR(6);
        p = (u32)&fzgx_obj_lbl_1_bss_104C;
        ADVANCE(8);
        PRINT_VALUE2(fn_1_CC5C_fmt_20C, FIELD(u32));
        SELECT_COLOR(7);
        fn_1_4A0D8(fn_1_CC5C_fmt_218);
        SELECT_COLOR(8);
        fn_1_4A0D8(fn_1_CC5C_fmt_22C);
        SELECT_COLOR(9);
        fn_1_4A0D8(fn_1_CC5C_fmt_240);
        SELECT_COLOR(10);
        fn_1_4A0D8(fn_1_CC5C_fmt_254);
        SELECT_COLOR(11);
        fn_1_4A0D8(fn_1_CC5C_fmt_264);
        SELECT_COLOR(12);
        fn_1_4A0D8(fn_1_CC5C_fmt_274);
        SELECT_COLOR(13);
        fn_1_4A0D8(fn_1_CC5C_fmt_280);
        SELECT_COLOR(14);
        fn_1_4A0D8(fn_1_CC5C_fmt_288);
        SELECT_COLOR(15);
        fn_1_4A0D8(fn_1_CC5C_fmt_290);
        SELECT_COLOR(16);
        fn_1_4A0D8(fn_1_CC5C_fmt_29C);
        SELECT_COLOR(17);
        fn_1_4A0D8(fn_1_CC5C_fmt_2A4);
        SELECT_COLOR(18);
        fn_1_4A0D8(fn_1_CC5C_fmt_2AC);
        SELECT_COLOR(19);
        fn_1_4A0D8(fn_1_CC5C_fmt_2BC);
        SELECT_COLOR(20);
        p = (u32)&fzgx_obj_lbl_1_bss_104C;
        PRINT_VALUE(fn_1_CC5C_fmt_2C0, fzgx_obj_lbl_1_bss_104C);
        SELECT_COLOR(21);
        p = (u32)&fzgx_obj_camera_state;
        ADVANCE(28);
        PRINT_VALUE(fn_1_CC5C_fmt_2CC, FIELD(f32));
        SELECT_COLOR(22);
        p = (u32)&fzgx_obj_camera_state;
        ADVANCE(32);
        PRINT_VALUE(fn_1_CC5C_fmt_2D8, FIELD(s16));
        SELECT_COLOR(23);
        p = (u32)&fzgx_obj_lbl_1_bss_10D8;
        ADVANCE(4);
        PRINT_VALUE(fn_1_CC5C_fmt_2E8, FIELD(f32));
        SELECT_COLOR(24);
        p = (u32)&fzgx_obj_lbl_1_bss_10D8;
        ADVANCE(8);
        PRINT_VALUE(fn_1_CC5C_fmt_2F8, FIELD(f32));
        SELECT_COLOR(25);
        p = (u32)&fzgx_obj_lbl_1_bss_10D8;
        ADVANCE(12);
        PRINT_VALUE(fn_1_CC5C_fmt_304, FIELD(f32));
        SELECT_COLOR(26);
        p = (u32)&fzgx_obj_lbl_1_bss_10D8;
        ADVANCE(16);
        PRINT_VALUE(fn_1_CC5C_fmt_310, FIELD(f32));
        SELECT_COLOR(27);
        p = (u32)&fzgx_obj_lbl_1_bss_10D8;
        ADVANCE(20);
        PRINT_VALUE(fn_1_CC5C_fmt_2F8, FIELD(f32));
        SELECT_COLOR(28);
        p = (u32)&fzgx_obj_lbl_1_bss_10D8;
        ADVANCE(24);
        PRINT_VALUE(fn_1_CC5C_fmt_304, FIELD(f32));
        SELECT_COLOR(29);
        p = (u32)&fzgx_obj_lbl_1_bss_10D8;
        ADVANCE(28);
        PRINT_VALUE(fn_1_CC5C_fmt_320, FIELD(f32));
        SELECT_COLOR(30);
        p = (u32)&fzgx_obj_lbl_1_bss_10D8;
        ADVANCE(32);
        PRINT_VALUE(fn_1_CC5C_fmt_330, FIELD(s16));
        SELECT_COLOR(31);
        p = (u32)&fzgx_obj_lbl_1_bss_10D8;
        ADVANCE(40);
        PRINT_VALUE(fn_1_CC5C_fmt_340, FIELD(f32));
        SELECT_COLOR(32);
        p = (u32)&fzgx_obj_lbl_1_bss_10D8;
        ADVANCE(44);
        PRINT_VALUE(fn_1_CC5C_fmt_2F8, FIELD(f32));
        SELECT_COLOR(33);
        p = (u32)&fzgx_obj_lbl_1_bss_10D8;
        ADVANCE(48);
        PRINT_VALUE(fn_1_CC5C_fmt_304, FIELD(f32));
        SELECT_COLOR(34);
        p = (u32)&fzgx_obj_lbl_1_bss_10D8;
        ADVANCE(52);
        PRINT_VALUE(fn_1_CC5C_fmt_310, FIELD(f32));
        SELECT_COLOR(35);
        p = (u32)&fzgx_obj_lbl_1_bss_10D8;
        ADVANCE(56);
        PRINT_VALUE(fn_1_CC5C_fmt_2F8, FIELD(f32));
        SELECT_COLOR(36);
        p = (u32)&fzgx_obj_lbl_1_bss_10D8;
        ADVANCE(60);
        PRINT_VALUE(fn_1_CC5C_fmt_304, FIELD(f32));
        SELECT_COLOR(37);
        p = (u32)&fzgx_obj_lbl_1_bss_10D8;
        ADVANCE(64);
        PRINT_VALUE(fn_1_CC5C_fmt_320, FIELD(f32));
        SELECT_COLOR(38);
        p = (u32)&fzgx_obj_lbl_1_bss_10D8;
        ADVANCE(68);
        PRINT_VALUE(fn_1_CC5C_fmt_330, FIELD(s16));
    }
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_CC5C */

/* fzgx:begin camera_get_state_object */
// Returns the camera state object's base address.
CameraState * camera_get_state_object(void) {
    return &camera_state;
}
/* fzgx:end camera_get_state_object */

/* fzgx:begin camera_get_state_field_0x4 */
// Returns the address of the camera state field at offset 4.
u32* camera_get_state_field_0x4(void) {
    return &camera_state.unk_4;
}
/* fzgx:end camera_get_state_field_0x4 */

/* fzgx:begin camera_get_state_field_0x8 */
// Returns the address of the camera state field at offset 0x8.
u32* camera_get_state_field_0x8(void) {
    return &camera_state.unk_8;
}
/* fzgx:end camera_get_state_field_0x8 */

/* fzgx:begin camera_get_state_field_0xc */
// Returns a pointer to the camera object's field at offset 0xC.
u32* camera_get_state_field_0xc(void) {
    return &camera_state.unk_C;
}
/* fzgx:end camera_get_state_field_0xc */

/* fzgx:begin camera_get_state_field_0x10 */
// Returns a pointer to the camera object's state field.
u32* camera_get_state_field_0x10(void) {
    return &camera_state.unk_10;
}
/* fzgx:end camera_get_state_field_0x10 */

/* fzgx:begin camera_get_state_field_0x14 */
// Returns a pointer to the camera object's field at offset 0x14.
u32* camera_get_state_field_0x14(void) {
    return &camera_state.unk_14;
}
/* fzgx:end camera_get_state_field_0x14 */

/* fzgx:begin camera_get_state_field_0x18 */
// Returns a pointer to the camera object's state field at offset 0x18.
u32* camera_get_state_field_0x18(void) {
    return &camera_state.unk_18;
}
/* fzgx:end camera_get_state_field_0x18 */

/* fzgx:begin camera_get_state_storage */
// Returns the camera state storage used by the surrounding camera code.
u8* camera_get_state_storage(void) {
    return lbl_1_bss_103C;
}
/* fzgx:end camera_get_state_storage */

/* fzgx:begin camera_get_extended_state_storage */
// Returns the storage reserved for the camera's extended state.
u8* camera_get_extended_state_storage(void) {
    return lbl_1_bss_108C;
}
/* fzgx:end camera_get_extended_state_storage */

/* fzgx:begin camera_get_state_flag */
// Returns the current camera state flag.
u8 camera_get_state_flag(void) {
    return lbl_1_bss_1014;
}
/* fzgx:end camera_get_state_flag */

/* fzgx:begin camera_enable_flags */
// Enables the camera state flags.
void camera_enable_flags(void) {
    camera_flag_1 = 1;
    camera_flag_0 = 1;
}
/* fzgx:end camera_enable_flags */

/* fzgx:begin camera_disable_flags */
// Clears the camera state flags.
void camera_disable_flags(void) {
    camera_flag_1 = 0;
    camera_flag_0 = 0;
}
/* fzgx:end camera_disable_flags */

/* fzgx:begin camera_are_flags_enabled */
// Returns whether the camera state flag is set.
u8 camera_are_flags_enabled(void) {
    return camera_flag_1;
}
/* fzgx:end camera_are_flags_enabled */
