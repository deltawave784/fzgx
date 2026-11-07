#include "types.h"
#include "game/main_rel/live_camera_types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/live_camera.h"
#include "psvec.h"
#include "dolphin/hw_regs.h"
#include "font.h"

typedef struct {
    f32 unk_0;
    u8 pad_4[0x10];
    f32 unk_14;
    u8 pad_18[0x34];
    f32 unk_4C;
} LcPool;

typedef struct {
    u8 pad_0[0x8];
    f32 unk_8;
    u8 pad_C[0x8];
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    u8 pad_20[0x60];
    f32 unk_80;
    f32 unk_84;
    f32 unk_88;
    f32 unk_8C;
    f32 unk_90;
    f32 unk_94;
    f32 unk_98;
} fn_1_F3D0_Rodata;

typedef struct {
    u8 pad_0[0x6];
    u16 unk_6;
    u8 pad_8[0x8];
    u16 unk_10;
    u16 unk_12;
    u16 unk_14;
    u8 pad_16[0x2];
    u32 unk_18;
    u8 pad_1C[0x48];
    u16 unk_64;
} Fn_1_101D0_State;

typedef struct V3_FB50 {
    f32 x, y, z;
} V3_FB50;

typedef struct LiveCam_FB50 {
    u8 pad_00[0x1c];
    V3_FB50 position;
    u8 pad_28[0x84];
    s32 mode;
    s32 timer;
    V3_FB50 saved;
    V3_FB50 offset;
    V3_FB50 velocity;
} LiveCam_FB50;

typedef struct {
    f32 m[3][4];
} LcMtx;

typedef struct { f32 x, y, z; } V3;

typedef struct {
    u8 type;
    u8 pad_1[3];
    s16 unk_4;
    s16 unk_6;
    u8 pad_8[0xC];
    s16 unk_14;
    u8 pad_16[6];
    u8 unk_1C[0x30];
    V3 unk_4C;
    f32 unk_58;
    s16 unk_5C;
    u8 pad_5E[0x12];
    f32 unk_70;
    f32 unk_74;
    f32 unk_78;
    u8 unk_7C[0x40];
} Cam;

typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 pad_2[2];
    s16 unk_4;
    s16 unk_6;
    u8 pad_8[0xC];
    s16 unk_14;
    u8 pad_16[6];
    f32 unk_1C;
    u8 pad_20[0x14];
    Vec3 unk_34;
    u8 pad_40[0xC];
    Vec3 unk_4C;
    f32 unk_58;
    s16 unk_5C;
    u8 pad_5E[0x12];
    f32 unk_70;
    u8 pad_74[8];
    f32 unk_7C;
} fn_1_11ABC_LiveCamera;

typedef struct {
    f32 x, y, z;
} Cam11E98Vec;

typedef struct {
    u8 state;          /* 0x00 */
    u8 pad_1[3];
    s16 unk_4;         /* 0x04 */
    s16 unk_6;         /* 0x06 */
    u8 pad_8[0xA];
    s16 unk_12;        /* 0x12 */
    s16 unk_14;        /* 0x14 */
    u8 pad_16[2];
    u32 unk_18;        /* 0x18 */
    Cam11E98Vec pos;   /* 0x1C */
    u8 pad_28[0x24];
    Cam11E98Vec unk_4C; /* 0x4C */
    u8 pad_58[0x24];
    u8 unk_7C[4];      /* 0x7C */
} Cam11E98;

typedef struct {
    u8 pad_0[4];
    s16 unk_4;
    u8 pad_6[0x16];
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    u8 pad_28[0x24];
    u32 unk_4C;
    u32 unk_50;
    u32 unk_54;
    f32 unk_58;
    s16 unk_5C;
    u8 pad_5E[0x6];
    s16 unk_64;
} Camera_1_10268;

typedef struct {
    u8 unk_0;
    u8 pad_1[0x3];
    s16 unk_4;
    s16 unk_6;
    u8 pad_8[0xC];
    s16 unk_14;
    u8 pad_16[0x6];
    u8 unk_1C[0x30];
    fn_1_11544_LiveCamVec pos;        /* 0x4C */
    u8 pad_58[0x18];
    fn_1_11544_LiveCamVec target;     /* 0x70 */
} fn_1_11544_LiveCamera;

typedef struct {
    f32 x, y, z;
} LcVec;

typedef struct {
    u8 mode;
    u8 pad_1[3];
    s16 unk_4;
    s16 unk_6;
    u8 pad_8[0xC];
    s16 unk_14;
    u8 pad_16[6];
    LcVec unk_1C;
    u8 pad_28[0x24];
    LcVec unk_4C;
    u8 pad_58[4];
    s16 unk_5C;
    u8 pad_5E[0x12];
    f32 unk_70;
    f32 unk_74;
    u8 pad_78[4];
    LcMtx unk_7C;
} LcState;

typedef struct {
    f32 x, y, z;
} Lc1212CVec;

typedef struct {
    u8 state;            /* 0x00 */
    u8 pad_1[3];
    s16 unk_4;           /* 0x04 */
    s16 unk_6;           /* 0x06 */
    u8 pad_8[0xA];
    s16 unk_12;          /* 0x12 */
    s16 unk_14;          /* 0x14 */
    u8 pad_16[2];
    u32 unk_18;          /* 0x18 */
    Lc1212CVec pos;      /* 0x1C */
    u8 pad_28[0x24];
    Lc1212CVec unk_4C;   /* 0x4C */
    f32 fov;             /* 0x58 */
    s16 unk_5C;          /* 0x5C */
    u8 pad_5E[0x12];
    Lc1212CVec target;   /* 0x70 */
    u8 mtx[0x30];        /* 0x7C */
} Lc1212C;

typedef struct {
    f32 x, y, z;
} fn_1_103B0_LiveCamVec;

typedef struct {
    u8 unk_0;
    u8 pad_1[0x3];
    s16 unk_4;
    u8 pad_6[0xE];
    s16 unk_14;
    u8 pad_16[0x6];
    fn_1_103B0_LiveCamVec pos;
    u8 pad_28[0x24];
    fn_1_103B0_LiveCamVec target;
    f32 fov;
    s16 roll;
    u8 pad_5E[0x6];
    u16 unk_64;
} LiveCamState;
extern u8 fn_1_A5848(void);
extern s32 fn_1_40BB4(void);
extern f32 lbl_1_rodata_4E0[];
extern u8 lbl_1_bss_17C0;
extern void fn_1_101D0(Fn_1_101D0_State *self);
extern void fn_1_FCB0();
extern void fn_1_A5858(u8 value);
extern s32 camera_get_state(void);
extern u32 fn_1_8627C(s32 index);
extern s16 fn_1_7B054(void);
extern u32 fn_1_584AC(void);
extern void fn_1_6DD0(u8 index);
extern void fn_1_FB50(LiveCam_FB50 *cam);
extern void lbl_8006DD14(void *, void *);
extern void fn_8006F1F0(void *, void *, void *);
extern void fn_8006F038(Vec3 *arg0, Vec3 *arg1, s16 arg2);
extern void lbl_8006DB74(void *);
extern void fn_8006F4E0(s16 *arg0);
extern void fn_1_549F4(void *, void *, f32, f32, f32, f32);
extern void fn_1_54DCC(u8 *data);
extern const FontDrawPacket lbl_1_rodata_26F8;
extern s32 fn_1_F2F34(void);
extern u32 fn_1_E688(f32);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16 index);
extern void fn_1_495B0(u32 value);
extern void fn_1_495C8(u8 value);
extern void fn_1_49590(f32 value);
extern void fn_1_496FC(f32 value1, f32 value2);
extern void fn_1_495A0(f32 value);
extern void fn_1_A8F40(u8 arg0);
extern f32 fn_1_8652C(int index);
extern void fn_1_520A0(void);
extern void fn_1_52070(u32 value);
extern void fn_1_4966C(f32 value1, f32 value2);
extern void fn_1_520CC(void);
extern void fn_1_1138C(Cam *c);
extern void fn_1_11748(void);
extern void fn_1_11ABC(fn_1_11ABC_LiveCamera *camera);
extern void fn_1_11E98(Cam11E98 *cam);
extern void fn_1_10268(Camera_1_10268 *arg);
extern void fn_1_DA34(void);
extern void fn_1_11544(fn_1_11544_LiveCamera *cam);
extern void fn_1_1189C(LcState *state);
extern void fn_1_11C08(void);
extern void fn_1_1212C(Lc1212C *cam);
extern void fn_1_10AF0(void);
extern void fn_1_103B0(LiveCamState *cam);
extern u32 lbl_801A63C0;
extern const f64 lbl_1_rodata_540;
extern void fn_1_8636C(int index, void *arg);
extern u32 fn_1_862A8(u32, V3 *);
extern void lbl_8006DC6C(void *);
extern void lbl_8006E1B0(void *, void *);
extern const f32 lbl_1_rodata_608[13];
extern const f32 lbl_1_rodata_604;
extern void fn_1_8645C(int index, void *arg);
extern u32 fn_1_20A5C(void *, void *);
extern void lbl_8006DBAC(void *);
extern void fn_8006FA24(void *, void *, void *, f32);
extern void lbl_8006E1F0(f32 *, f32, f32, f32);
extern s32 lbl_8006D24C(f32, f32);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern u8 fn_1_86624(void);
extern Cam11E98Vec lbl_1_rodata_63C;
extern void fn_8006ED0C(Vec3 *arg0, Vec3 *arg1, s16 *arg2);
extern void mathutil_mtxA_rotate_y(s16);
extern void mathutil_mtxA_rotate_x(s16);
extern void lbl_8006D7DC(Lc1212CVec *);
extern u8 fn_1_1350C(void *a, u8 *buf);
extern u32 *fn_1_1304C(Obj_1_bss_3B30 *, u32);
extern void fn_1_45964(void *a, void *buf, int n, u32 off, void *cb);
extern void fn_1_1383C(void);
extern void DCInvalidateRange(void *addr, u32 len);
extern void fn_8000659C(void);
extern void fn_1_3308(void);
extern void fn_1_D3214(void);
extern void fn_8001AF64(void);
extern void fn_1_10138();
extern void fn_1_8840(void);
extern void fn_1_A1CE8(u32 arg0);
extern u8 fn_1_3F1F8(void);
extern u32 fn_1_4630();
extern void fn_80006E10(u32 arg0);
extern int sprintf(char *s, const char *format, ...);
extern u32 lbl_801A6410;
extern const f64 lbl_1_rodata_580;
extern const f64 lbl_1_rodata_588;
extern u32 lbl_1_bss_F5C;
extern u32 fn_1_864E8(int index);
extern void camera_set_result(s16 value);
extern void camera_set_selected_value(u8 value);
extern s8 fn_1_5370(s8 arg0, s16 arg1);
extern s32 fn_80008E30(u32);
extern void *lbl_8006D5A4(void *, void *, void *, f32);
extern int fn_1_4C10(void);
extern u32 fn_1_F45A4(void);
extern u32 fn_1_F4594(void);
extern void *fn_1_86254(int index);
extern void fn_1_8A0C(s16 index);
extern void fn_1_56B8(void);
extern f32 lbl_1_bss_1160[403];
extern void fn_1_A1964(u8 arg);
extern void fn_1_A2D84(u32 arg0);
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern u8 lbl_1_bss_17B4[12];
extern char *fn_80083DB0(char *dst, const char *src);
extern u8 lbl_1_bss_1810[8984];
extern u32 OSIsThreadTerminated(u8 *);
extern u32 *fn_1_1289C(u32 *state);
extern f32 lbl_1_rodata_4F4[19];
extern const f64 lbl_1_rodata_548[2];

/* fzgx:begin fn_1_DA34 */
// Reports the camera source location and message used by this routine.
void fn_1_DA34(void) {
    OSPanic( (const char *)(u8 *)(lbl_1_data_4420), 0x34, (const char *)(u8 *)(lbl_1_data_4430));
}
/* fzgx:end fn_1_DA34 */

/* fzgx:begin fn_1_DA6C */
typedef struct {
    u8 pad_0[6];
    s16 unk_6;
    s16 unk_8;
} DA6CArg;

// Cycle the live camera target, wrapping indices and skipping unavailable entries.
void fn_1_DA6C(DA6CArg *state) {
    s16 originalIndex;
    s32 direction;
    struct { s32 value; } targetIndex;
    u32 flags;
    s32 count;
    u32 selectionDeadline;

    if (lbl_1_bss_115C == 0) {
        return;
    }
    if (fn_1_4C10() != 0) {
        return;
    }
    if (fn_1_40BB4() != 0) {
        return;
    }
    if ((s32)fn_1_F2F34() == 0) {
        return;
    }
    selectionDeadline = fn_1_F45A4() - 30;
    if (fn_1_F4594() >= selectionDeadline) {
        return;
    }

    direction = 1;
    if ((lbl_1_bss_9F8.unk_A >> 6) & 1) {
        direction = 1;
        *(s8 *)((u8 *)fn_1_86254(state->unk_6) + 0x475) = -1;
        state->unk_6++;
        count = (s8)fn_1_86624();
        if (state->unk_6 > count - 1) {
            targetIndex.value = 0;
        } else if (state->unk_6 < 0) {
            targetIndex.value = (s8)fn_1_86624() - 1;
        } else {
            targetIndex.value = state->unk_6;
        }
        *(s8 *)((u8 *)fn_1_86254(targetIndex.value) + 0x475) = 0;
        fn_1_6DD0( (u8)(void *)(0));
        fn_1_8A0C(0);
        fn_1_56B8();
    }
    if (state->unk_6 >= (s8)fn_1_86624()) {
        state->unk_6 = 0;
    }
    if (state->unk_6 < 0) {
        state->unk_6 = (s8)fn_1_86624() - 1;
    }
    state->unk_8 = state->unk_6;

    if ((lbl_1_bss_9F8.unk_A >> 7) & 1) {
        direction = -1;
        *(s8 *)((u8 *)fn_1_86254(state->unk_6) + 0x475) = -1;
        state->unk_6--;
        count = (s8)fn_1_86624();
        if (state->unk_6 > count - 1) {
            targetIndex.value = 0;
        } else if (state->unk_6 < 0) {
            targetIndex.value = (s8)fn_1_86624() - 1;
        } else {
            targetIndex.value = state->unk_6;
        }
        *(s8 *)((u8 *)fn_1_86254(targetIndex.value) + 0x475) = 0;
        fn_1_6DD0( (u8)(void *)(0));
        fn_1_8A0C(0);
        fn_1_56B8();
    }
    if (state->unk_6 >= (s8)fn_1_86624()) {
        state->unk_6 = 0;
    }
    if (state->unk_6 < 0) {
        state->unk_6 = (s8)fn_1_86624() - 1;
    }
    state->unk_8 = state->unk_6;

    flags = fn_1_864E8(state->unk_6);
    if ((flags & 0x800) && !(flags & 1)) {
        originalIndex = state->unk_6;
        do {
            *(s8 *)((u8 *)fn_1_86254(state->unk_6) + 0x475) = -1;
            state->unk_6 += direction;
            if (state->unk_6 > (s8)fn_1_86624() - 1) {
                targetIndex.value = 0;
            } else if (state->unk_6 < 0) {
                targetIndex.value = (s8)fn_1_86624() - 1;
            } else {
                targetIndex.value = state->unk_6;
            }
            *(s8 *)((u8 *)fn_1_86254(targetIndex.value) + 0x475) = 0;
            if (state->unk_6 >= (s8)fn_1_86624()) {
                state->unk_6 = 0;
            }
            if (state->unk_6 < 0) {
                state->unk_6 = (s8)fn_1_86624() - 1;
            }
        } while ((fn_1_864E8(state->unk_6) & 0x800) &&
                 originalIndex != state->unk_6);

        if (state->unk_6 >= (s8)fn_1_86624()) {
            state->unk_6 = 0;
        }
        if (state->unk_6 < 0) {
            state->unk_6 = (s8)fn_1_86624() - 1;
        }
        state->unk_8 = state->unk_6;
        if (originalIndex == state->unk_6) {
            camera_set_selected_value(1);
            camera_set_result(state->unk_6);
            fn_1_5370(0, 0);
            camera_set_result(state->unk_6);
            camera_set_selected_value(0);
            return;
        }
        fn_1_56B8();
    }

    if (state->unk_6 >= (s8)fn_1_86624()) {
        state->unk_6 = 0;
    }
    if (state->unk_6 < 0) {
        state->unk_6 = (s8)fn_1_86624() - 1;
    }
    state->unk_8 = state->unk_6;
    camera_set_result(state->unk_6);
}
/* fzgx:end fn_1_DA6C */

/* fzgx:begin fn_1_DE14 */
typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 pad_2[4];
    s16 unk_6;
    u8 pad_8[4];
    u32 unk_C;
    u8 pad_10[0x54];
    u16 unk_64;
} Fn1DE14State;

void fn_1_DE14(Fn1DE14State *state) {
    u8 enabled;

    if (lbl_1_bss_115C == 0) {
        return;
    }
    if (fn_1_4C10() != 0) {
        return;
    }
    if (fn_1_40BB4() != 0) {
        return;
    }
    if ((s32)fn_1_F2F34() == 0) {
        return;
    }
    if (fn_1_F4594() >= fn_1_F45A4() - 0x1e) {
        return;
    }

    enabled = 0;
    if ((lbl_1_bss_9F8.unk_8 >> 8) & 1) {
        enabled = 1;
    }
    if (enabled == 0) {
        return;
    }

    lbl_1_bss_1160[0] = lbl_1_rodata_4E0[0];
    if (state->unk_1 == 0) {
        state->unk_0++;
    } else {
        state->unk_1++;
    }
    if (state->unk_0 >= 4) {
        state->unk_0 = 0;
        state->unk_1 = 1;
    }

    switch (state->unk_1) {
    case 1:
        fn_1_5370( (s32)(0), state->unk_6);
        break;
    case 2:
        fn_1_5370( (s32)(1), state->unk_6);
        state->unk_1 = 0;
    default:
        fn_1_5370( (s32)(1), state->unk_6);
    case 0:
        break;
    }

    state->unk_64 = 0;
    state->unk_C &= ~0x00200000;
    fn_1_6DD0( (u8)((void *)(u32)(0)));
}
/* fzgx:end fn_1_DE14 */

/* fzgx:begin fn_1_DF74 pool noprologue */
#include "rel/main_rel/live_camera.h"

extern f32 lbl_1_rodata_4E0[];
extern u32 lbl_1_data_212A8[45];
extern s32 fn_1_A5DC4(void);
extern s32 fn_1_F7BE4(s32);
extern u8 fn_1_F8CF0(s32);
extern void *memset(void *, int, u32);
extern int sprintf(char *, const char *, ...);

#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_strength_reduction off
static inline void camera_store(s16 *ids, s16 n, s16 id) {
    struct { s16 *value; } destination;
    s16 index = n;
    s16 value = id;
    destination.value = ids;
    destination.value[index] = value;
}
static inline void camera_plain(char *rows, s16 *ids,
                                u8 *data, s16 n, s16 id, s32 offset) {
    char *format;
    format = (char *)ids;
    ((s16 *)format)[n] = id;
    format = (char *)data + offset;
    rows += n * 34;
    sprintf(rows, format);
}
static inline void camera_named(char *rows, const char *format, u32 name,
                                s16 *ids, s16 n, s16 id) {
    ids += n;
    *ids = id;
    rows += n * 34;
    sprintf(rows, format, name);
}
typedef struct { f32 x, y, z; } CameraResetVector;
static inline void camera_reset(register CameraResetVector *v, f32 value) {
    f32 *out = &v->x;
    *out++ = value;
    *out++ = value;
    *out = value;
}
#pragma opt_common_subs off
#pragma peephole on
#pragma opt_strength_reduction off
#pragma opt_pointer_analysis off
#pragma opt_lifetimes off
#pragma opt_strength_reduction off
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_1148[2];
f32 lbl_1_bss_1148_8;
f32 lbl_1_bss_1148_C;
f32 lbl_1_bss_1148_10;
u8 fzgx_obj_lbl_1_bss_115C;
u8 lbl_1_bss_1148_gap_115D;
u16 lbl_1_bss_1148_gap_115D_fill_115E;
u8 lbl_1_bss_1160[0xc];
f32 lbl_1_bss_1160_C;
u8 lbl_1_bss_1160_10[0x4];
s16 lbl_1_bss_1160_14;
s16 lbl_1_bss_1160_16;
u8 lbl_1_bss_1160_18[0x5D8];
s16 lbl_1_bss_1160_5F0;
u16 lbl_1_bss_1160_fill_1752;
u8 lbl_1_bss_1160_5F4[0x58];
u8 fzgx_obj_lbl_1_bss_17AC;
u8 lbl_1_bss_1148_gap_17AD;
u16 lbl_1_bss_1148_gap_17AD_fill_17AE;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_1148;
    s = *(u8 *)&lbl_1_bss_1148_8;
    s = *(u8 *)&lbl_1_bss_1148_C;
    s = *(u8 *)&lbl_1_bss_1148_10;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_115C;
    s = *(u8 *)&lbl_1_bss_1148_gap_115D;
    s = *(u8 *)&lbl_1_bss_1148_gap_115D_fill_115E;
    s = *(u8 *)&lbl_1_bss_1160;
    s = *(u8 *)&lbl_1_bss_1160_C;
    s = *(u8 *)&lbl_1_bss_1160_10;
    s = *(u8 *)&lbl_1_bss_1160_14;
    s = *(u8 *)&lbl_1_bss_1160_16;
    s = *(u8 *)&lbl_1_bss_1160_18;
    s = *(u8 *)&lbl_1_bss_1160_5F0;
    s = *(u8 *)&lbl_1_bss_1160_fill_1752;
    s = *(u8 *)&lbl_1_bss_1160_5F4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_17AC;
    s = *(u8 *)&lbl_1_bss_1148_gap_17AD;
    s = *(u8 *)&lbl_1_bss_1148_gap_17AD_fill_17AE;
}
#pragma section code_type ".text"

extern u8 fn_1_10268__fzgx_offset_0[];
extern u8 fn_1_103B0__fzgx_offset_0[];
extern u8 fn_1_107B8__fzgx_offset_0[];
extern u8 fn_1_10AF0__fzgx_offset_0[];
extern u8 fn_1_1138C__fzgx_offset_0[];
extern u8 fn_1_11544__fzgx_offset_0[];
extern u8 fn_1_11748__fzgx_offset_0[];
extern u8 fn_1_1189C__fzgx_offset_0[];
extern u8 fn_1_11ABC__fzgx_offset_0[];
extern u8 fn_1_11C08__fzgx_offset_0[];
extern u8 fn_1_11E98__fzgx_offset_0[];
extern u8 fn_1_1212C__fzgx_offset_0[];
extern u8 fn_1_DA34__fzgx_offset_0[];
extern u8 lbl_1_data_43B8__fzgx_offset_0[];
extern u8 lbl_1_data_43C4__fzgx_offset_0[];
extern u8 lbl_1_data_43CC__fzgx_offset_0[];
extern u8 lbl_1_data_43D8__fzgx_offset_0[];
extern u8 lbl_1_data_43E0__fzgx_offset_0[];
extern u8 lbl_1_data_43EC__fzgx_offset_0[];
extern u8 lbl_1_data_43F4__fzgx_offset_0[];
extern u8 lbl_1_data_43FC__fzgx_offset_0[];
extern u8 lbl_1_data_4508__fzgx_offset_0[];
extern u8 lbl_1_data_4514__fzgx_offset_0[];
extern u8 lbl_1_data_4524__fzgx_offset_0[];
extern u8 lbl_1_data_4530__fzgx_offset_0[];
extern u8 lbl_1_data_4540__fzgx_offset_0[];
extern u8 lbl_1_data_4554__fzgx_offset_0[];
extern u8 lbl_1_data_4568__fzgx_offset_0[];
static u32 fzgx_pool_data_lbl_1_data_43B8[118] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4F564552, 0x54414B45, 0x0, 0x4A554D50, 0x0, 0x454E454D, 0x59484954, 0x0,
    0x57414C4C, 0x48495400, 0x53494445, 0x42595349, 0x44450000, 0x53544152, 0x54000000, 0x474F414C,
    0x0, 0x4C415000, (u32)lbl_1_data_43B8__fzgx_offset_0, (u32)lbl_1_data_43C4__fzgx_offset_0, (u32)lbl_1_data_43CC__fzgx_offset_0, (u32)lbl_1_data_43D8__fzgx_offset_0, (u32)lbl_1_data_43E0__fzgx_offset_0, (u32)lbl_1_data_43EC__fzgx_offset_0,
    (u32)lbl_1_data_43F4__fzgx_offset_0, (u32)lbl_1_data_43FC__fzgx_offset_0, 0x6C697665, 0x5F63616D, 0x6572612E, 0x63000000, 0x6C697665, 0x63616D20,
    0x6572726F, 0x720A0000, (u32)fn_1_1138C__fzgx_offset_0, (u32)fn_1_11748__fzgx_offset_0, (u32)fn_1_11ABC__fzgx_offset_0, (u32)fn_1_11E98__fzgx_offset_0, (u32)fn_1_107B8__fzgx_offset_0, (u32)fn_1_10268__fzgx_offset_0,
    (u32)fn_1_DA34__fzgx_offset_0, (u32)fn_1_11544__fzgx_offset_0, (u32)fn_1_1189C__fzgx_offset_0, (u32)fn_1_11C08__fzgx_offset_0, (u32)fn_1_1212C__fzgx_offset_0, (u32)fn_1_10AF0__fzgx_offset_0, (u32)fn_1_103B0__fzgx_offset_0, (u32)fn_1_DA34__fzgx_offset_0,
    0x110000, 0xC1100, 0xC1100, 0x10000, 0x1, 0x3, 0x5, 0x7,
    0x8, 0x9, 0xA, 0xB, 0xD, 0xE, 0xF, 0x10,
    0x11, 0x15, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D,
    0x1F, 0x20, 0x21, 0x22, 0x23, 0x24, 0x1, 0xFFFFFFFF,
    0xFFFFFFFF, 0xFFFFFFFF, 0x2A002A, 0x3C0000, 0x4155544F, 0x2043414D, 0x45524100, 0x434F5552,
    0x53452043, 0x414D4552, 0x41000000, 0x43415220, 0x43414D45, 0x52410000, 0x53454C45, 0x43542043,
    0x414D4552, 0x41000000, 0x4C495645, 0x43414D20, 0x4D4F4445, 0x204D4158, 0x0, 0x4F4C4420,
    0x52414E44, 0x4F4D2043, 0x414D4552, 0x41000000, 0x5441424C, 0x45204D4F, 0x44450000, (u32)lbl_1_data_4508__fzgx_offset_0,
    (u32)lbl_1_data_4514__fzgx_offset_0, (u32)lbl_1_data_4524__fzgx_offset_0, (u32)lbl_1_data_4530__fzgx_offset_0, (u32)lbl_1_data_4540__fzgx_offset_0, (u32)lbl_1_data_4554__fzgx_offset_0, (u32)lbl_1_data_4568__fzgx_offset_0
};
static u32 fzgx_pool_data_lbl_1_data_43B8_1D8[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x81F42573, 0x0
};
static u32 fzgx_pool_data_lbl_1_data_43B8_1E0[4] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x81F44272, 0x61696E20, 0x436C6561, 0x6E657200
};
static u32 fzgx_pool_data_lbl_1_data_43B8_1F0[8] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x81F4436F, 0x76657220, 0x6F66204D, 0x75746520, 0x43697479, 0x27732074, 0x68656D65, 0x0
};
static u32 fzgx_pool_data_lbl_1_data_43B8_210[99] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x81F4436F, 0x76657220, 0x6F662042, 0x69672042, 0x6C756527, 0x73207468, 0x656D6500, 0x25730000,
    0x5D000000, 0x5B000000, 0x90A0B0C, 0xD000000, 0x47414D45, 0x2043414D, 0x4552410A, 0x0,
    0x4C495645, 0x20574954, 0x48204741, 0x4D452043, 0x414D4552, 0x410A0000, 0x53454C45, 0x43542043,
    0x414D4552, 0x410A0000, 0x25730A00, 0x25346400, 0x63616D00, 0x6C697665, 0x63616D5F, 0x73746167,
    0x655F6465, 0x6D6F5F25, 0x642E6269, 0x6E000000, 0x6C697665, 0x63616D5F, 0x73746167, 0x655F6465,
    0x6D6F5F31, 0x2E62696E, 0x0, 0x6C697665, 0x63616D5F, 0x73746167, 0x655F3530, 0x5F34702E,
    0x62696E00, 0x6C697665, 0x63616D5F, 0x73746167, 0x655F3530, 0x5F33702E, 0x62696E00, 0x6C697665,
    0x63616D5F, 0x73746167, 0x655F3530, 0x5F32702E, 0x62696E00, 0x6C697665, 0x63616D5F, 0x73746167,
    0x655F6465, 0x6D6F5F35, 0x305F656E, 0x642E6269, 0x6E000000, 0x6C697665, 0x63616D5F, 0x73746167,
    0x655F2564, 0x2E62696E, 0x0, 0x6C697665, 0x63616D5F, 0x73746167, 0x655F312E, 0x62696E00,
    0x2E2E0000, 0x6C697665, 0x63616D5F, 0x25642E62, 0x696E0000, 0x6C697665, 0x63616D5F, 0x312E6269,
    0x6E000000, 0x6C697665, 0x63616D5F, 0x62616C6C, 0x5F25642E, 0x62696E00, 0x6C697665, 0x63616D5F,
    0x62616C6C, 0x5F312E62, 0x696E0000
};
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_1_data_43B8(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .data objects in retail order */
    s = *(u8 *)fzgx_pool_data_lbl_1_data_43B8;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_43B8_1D8;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_43B8_1E0;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_43B8_1F0;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_43B8_210;
}
#pragma section code_type ".text"

void fn_1_DF74(void) {
    
    
    f32 *pool = lbl_1_rodata_4E0;
    s32 i;
    struct { s16 *value; } ids;
    s16 n;
    s16 n41, n42, n43;
    struct { u32 *value; } table;
    s16 *lab_t2;
    s16 *lab_t3;
    s16 *lab_t4;
    if ((s8)fn_1_A5DC4()) {
        lbl_1_bss_1160_C = pool[1];
        *(f32 *)lbl_1_bss_1160_10 = pool[2];
    } else {
        lbl_1_bss_1160_C = pool[3];
        *(f32 *)lbl_1_bss_1160_10 = pool[4];
    }
    lbl_1_bss_1160_14 = 0;
    lbl_1_bss_1160_16 = 0;
    lbl_1_bss_1148_C = pool[5];
    lbl_1_bss_1148_10 = lbl_1_bss_1160_C * pool[6];
    memset(lbl_1_bss_1160_18, 0, 0x5D8);
    lbl_1_bss_1160_5F0 = 0;
    ids.value = (s16 *)((u8 *)&lbl_1_bss_1160_5F4);
    table.value = lbl_1_data_212A8;
    for (i = 0; (s16)i < 41; i++) {
        if (fn_1_F7BE4(i)) {
            struct { const char *value; } format;
            n = lbl_1_bss_1160_5F0;
            format.value = (char *)((u8 *)fzgx_pool_data_lbl_1_data_43B8_1D8);
            camera_named((char *)lbl_1_bss_1160_18, format.value,
                         *table.value, ids.value, n, i);
            lbl_1_bss_1160_5F0++;
        }
        table.value++;
    }
    n41 = lbl_1_bss_1160_5F0;
    camera_plain((char *)lbl_1_bss_1160_18, ((s16 *)((u8 *)&lbl_1_bss_1160_5F4)), ((u8 *)fzgx_pool_data_lbl_1_data_43B8_1E0), n41, 41, 0);
    lbl_1_bss_1160_16 = lbl_1_bss_1160_5F0++;
    if (fn_1_F8CF0(0)) {
        n42 = lbl_1_bss_1160_5F0;
        camera_plain((char *)lbl_1_bss_1160_18, ((s16 *)((u8 *)&lbl_1_bss_1160_5F4)), ((u8 *)fzgx_pool_data_lbl_1_data_43B8_1F0), n42, 42, 0);
        lbl_1_bss_1160_5F0++;
    }
    if (fn_1_F8CF0(1)) {
        n43 = lbl_1_bss_1160_5F0;
        camera_plain((char *)lbl_1_bss_1160_18, ((s16 *)((u8 *)&lbl_1_bss_1160_5F4)), ((u8 *)fzgx_pool_data_lbl_1_data_43B8_210), n43, 43, 0);
        lbl_1_bss_1160_5F0++;
    }
#pragma opt_common_subs off
    {
        f32 zero = pool[5];
        lbl_1_bss_1148_8 = zero;
        camera_reset((CameraResetVector *)((u32)(u8 *)&lbl_1_bss_1160), zero);
    }
}
/* fzgx:end fn_1_DF74 */

/* fzgx:begin fn_1_E174 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/live_camera.h"
#include "psvec.h"
#include "dolphin/hw_regs.h"
#include "game/main_rel/live_camera_types.h"

extern u32 fn_1_A1CE8(u32);
extern s32 fn_1_F2F34(void);
extern s32 fn_1_40BB4(void);
extern f32 lbl_1_rodata_4E0[];
extern u32 fn_1_A1964(u32);
extern void fn_1_A2D84(u32 arg0);

#pragma opt_lifetimes off
#pragma opt_propagation off
#pragma opt_strength_reduction off
static inline void fn_1_E174_store(s16 value, s16 *destination) { *destination = value; }
void fn_1_E174(f32 arg0) {
    f32 fzgx_live;
    s16 fzgx_value;
    Obj_1_bss_1148 *p_lbl_1_bss_1148;
    Obj_1_data_43B8 *p_lbl_1_data_43B8;
    struct fn_1_E174_lbl_1_rodata_4E0 *p_lbl_1_rodata_4E0;
    Obj_1_bss_9F8 *p_lbl_1_bss_9F8;
    s16 v0;
    u32 v1;
    s32 v2;
    f32 v3;
    u32 v5;
    s16 v4;
    u32 v6;
    f32 v7;
    u32 v8;
    f32 v9;
    s32 v10;
    s16 v11;
    u32 v12;
    u32 v13;
    f32 v14;
    f32 v15;
    f32 v16;
    s32 v17;
    u32 t7;
    u32 t8;
    u32 t9;
    u32 t10;
    u32 t11;
    u32 t12;
    u32 t13;
    u32 t14;
    u32 t15;
    u32 t16;
    u32 t19;
    u32 t20;
    u32 t21;
    u32 t22;
    u32 t23;
    u32 t24;
    u32 t25;
    u32 t26;
    p_lbl_1_data_43B8 = (Obj_1_data_43B8 *)&lbl_1_data_43B8;
    p_lbl_1_bss_1148 = (Obj_1_bss_1148 *)&lbl_1_bss_1148;
    p_lbl_1_rodata_4E0 = (struct fn_1_E174_lbl_1_rodata_4E0 *)&lbl_1_rodata_4E0;
    if (((10) == (*(s16 *)&lbl_1_bss_960))) {
    fn_1_A1CE8((p_lbl_1_data_43B8->unk_148 & 0xFF));
    } else {
    if (((12) == (*(s16 *)&lbl_1_bss_960)) || (s32)fn_1_F2F34() != 0) {
    v0 = p_lbl_1_data_43B8->unk_148;
    v1 = (v0 - 41);
    switch ((s32)v1) {
    case 1:
    fn_1_A1CE8(((((1) + (v0))) & 0xFF));
    break;
    case 2:
    fn_1_A1CE8(((((1) + (v0))) & 0xFF));
    break;
    default:
    fn_1_A1CE8((v0 & 0xFF));
    }
    }
    }
    v3 = arg0;
    if (p_lbl_1_bss_1148->unk_14 != 0 && (s32)fn_1_40BB4() == 0 && (s32)fn_1_F2F34() != 0) {
    if (p_lbl_1_bss_1148->unk_664 != 0) {
    p_lbl_1_data_43B8->unk_14A = 41;
    p_lbl_1_bss_1148->unk_664 = 0;
    if (p_lbl_1_data_43B8->unk_148 != 41) {
    p_lbl_1_data_43B8->unk_148 = 41;
    lbl_1_bss_6F243 = 0;
    }
    v2 = p_lbl_1_data_43B8->unk_148;
    if (v2 < 41) {
    v2 = (v2 & 0xFF);
    t7 = fn_1_A1964(v2);
    v2 = t7;
    v2 = (p_lbl_1_data_43B8->unk_148 & 0xFF);
    t8 = fn_1_A1CE8(v2);
    v2 = t8;
    } else {
    v5 = (v2 - 41);
    switch ((s32)v5) {
    case 0:
    v2 = (u32)&lbl_1_bss_6EAD0;
    v2 = *(u32 *)((u8 *)v2 + 0);
    v2 = *(u32 *)((u8 *)v2 + 0);
    t9 = fn_1_A1588((Sig_ADXT_Stop_ADXTHandle *)v2, 38);
    v2 = t9;
    v2 = (p_lbl_1_data_43B8->unk_148 & 0xFF);
    t10 = fn_1_A1CE8(v2);
    v2 = t10;
    break;
    case 1:
    v2 = (u32)&lbl_1_bss_6EAD0;
    v2 = *(u32 *)((u8 *)v2 + 0);
    v2 = *(u32 *)((u8 *)v2 + 0);
    t11 = fn_1_A1588((Sig_ADXT_Stop_ADXTHandle *)v2, 44);
    v2 = t11;
    v2 = p_lbl_1_data_43B8->unk_148;
    v2 = ((v2 + 1) & 0xFF);
    t12 = fn_1_A1CE8(v2);
    v2 = t12;
    break;
    case 2:
    v2 = (u32)&lbl_1_bss_6EAD0;
    v2 = *(u32 *)((u8 *)v2 + 0);
    v2 = *(u32 *)((u8 *)v2 + 0);
    t13 = fn_1_A1588((Sig_ADXT_Stop_ADXTHandle *)v2, 43);
    v2 = t13;
    v2 = p_lbl_1_data_43B8->unk_148;
    v2 = ((v2 + 1) & 0xFF);
    t14 = fn_1_A1CE8(v2);
    v2 = t14;
    break;
    default:
    v2 = (u32)&lbl_1_bss_6EAD0;
    v2 = *(u32 *)((u8 *)v2 + 0);
    v2 = *(u32 *)((u8 *)v2 + 0);
    t15 = fn_1_A1588((Sig_ADXT_Stop_ADXTHandle *)v2, 38);
    v2 = t15;
    v2 = (p_lbl_1_data_43B8->unk_148 & 0xFF);
    t16 = fn_1_A1CE8(v2);
    v2 = t16;
    }
    }
    }
    if (((12) == (*(s16 *)&lbl_1_bss_960))) {
    p_lbl_1_bss_9F8 = (Obj_1_bss_9F8 *)&lbl_1_bss_9F8;
    if (((p_lbl_1_bss_9F8->unk_12 >> 9) & 0x1) != 0) {
    v3 = (p_lbl_1_rodata_4E0->unk_1C);
    v2 = 0xA9010000;
    v6 = (p_lbl_1_bss_1148->unk_2E + 1);
    v7 = p_lbl_1_bss_1148->unk_24;
    p_lbl_1_bss_1148->unk_2E = v6;
    v2 += 1536;
    p_lbl_1_data_43B8->unk_14C = 60;
    p_lbl_1_bss_1148->unk_8 = v3;
    p_lbl_1_bss_1148->unk_C = v7;
    fn_1_A2D84(v2);
    }
    if (((p_lbl_1_bss_9F8->unk_12 >> 8) & 0x1) != 0) {
    v2 = 0xA9010000;
    v3 = (p_lbl_1_rodata_4E0->unk_1C);
    v8 = (p_lbl_1_bss_1148->unk_2E - 1);
    v9 = (-p_lbl_1_bss_1148->unk_24);
    fn_1_E174_store(60, &(p_lbl_1_data_43B8->unk_14C));
    v2 += 1536;
    fzgx_value = v8;
    p_lbl_1_bss_1148->unk_2E = fzgx_value;
    p_lbl_1_bss_1148->unk_8 = v3;
    p_lbl_1_bss_1148->unk_C = v9;
    fn_1_A2D84(v2);
    }
    }
    v2 = p_lbl_1_data_43B8->unk_14C;
    if (v2 != 0) {
    p_lbl_1_data_43B8->unk_14C = (v2 - 1);
    } else {
    v3 = p_lbl_1_bss_1148->unk_8;
    if (v3 != (p_lbl_1_rodata_4E0->unk_14)) {
    p_lbl_1_bss_1148->unk_8 = (v3 - (p_lbl_1_rodata_4E0->unk_20));
    }
    }
    if (p_lbl_1_bss_1148->unk_2E < 0) {
    v2 = p_lbl_1_bss_1148->unk_608;
    p_lbl_1_bss_1148->unk_2E = (v2 - 1);
    }
    v2 = p_lbl_1_bss_1148->unk_608;
    if (p_lbl_1_bss_1148->unk_2E > (s32)(v2 - 1)) {
    p_lbl_1_bss_1148->unk_2E = 0;
    }
    v2 = (u32)((u8 *)(u32)p_lbl_1_bss_1148 + 1548);
    v10 = (s16)(*(s16 *)((u8 *)v2 + (p_lbl_1_bss_1148->unk_2E << 1)));
    p_lbl_1_data_43B8->unk_14A = v10;
    if (v10 < 0) {
    p_lbl_1_data_43B8->unk_14A = 43;
    }
    if (p_lbl_1_data_43B8->unk_14A >= 44) {
    p_lbl_1_data_43B8->unk_14A = 0;
    }
    if (p_lbl_1_data_43B8->unk_148 != (v11 = p_lbl_1_data_43B8->unk_14A) && ((0) == (p_lbl_1_data_43B8->unk_14C))) {
    p_lbl_1_data_43B8->unk_148 = v11;
    lbl_1_bss_6F243 = 0;
    if (v11 < 41) {
    v2 = (v11 & 0xFF);
    t19 = fn_1_A1964(v2);
    v2 = t19;
    } else {
    v12 = (v11 - 41);
    switch ((s32)v12) {
    case 0:
    v2 = (u32)&lbl_1_bss_6EAD0;
    v2 = *(u32 *)((u8 *)v2 + 0);
    v2 = *(u32 *)((u8 *)v2 + 0);
    t20 = fn_1_A1588((Sig_ADXT_Stop_ADXTHandle *)v2, 38);
    v2 = t20;
    break;
    case 1:
    v2 = (u32)&lbl_1_bss_6EAD0;
    v2 = *(u32 *)((u8 *)v2 + 0);
    v2 = *(u32 *)((u8 *)v2 + 0);
    t21 = fn_1_A1588((Sig_ADXT_Stop_ADXTHandle *)v2, 44);
    v2 = t21;
    break;
    case 2:
    v2 = (u32)&lbl_1_bss_6EAD0;
    v2 = *(u32 *)((u8 *)v2 + 0);
    v2 = *(u32 *)((u8 *)v2 + 0);
    t22 = fn_1_A1588((Sig_ADXT_Stop_ADXTHandle *)v2, 43);
    v2 = t22;
    break;
    default:
    v2 = (u32)&lbl_1_bss_6EAD0;
    v2 = *(u32 *)((u8 *)v2 + 0);
    v2 = *(u32 *)((u8 *)v2 + 0);
    t23 = fn_1_A1588((Sig_ADXT_Stop_ADXTHandle *)v2, 38);
    v2 = t23;
    }
    }
    }
    v2 = p_lbl_1_data_43B8->unk_148;
    v13 = (v2 - 41);
    switch ((s32)v13) {
    case 1:
    v2 = ((v2 + 1) & 0xFF);
    t24 = fn_1_A1CE8(v2);
    v2 = t24;
    break;
    case 2:
    v2 = ((v2 + 1) & 0xFF);
    t25 = fn_1_A1CE8(v2);
    v2 = t25;
    break;
    default:
    v2 = (v2 & 0xFF);
    t26 = fn_1_A1CE8(v2);
    v2 = t26;
    }
    v2 = (u32)&lbl_1_bss_9F8;
    if (((*(u16 *)((u8 *)v2 + 16) >> 4) & 0x1) != 0) {
    v2 = p_lbl_1_bss_1148->unk_2C;
    p_lbl_1_bss_1148->unk_2C = (v2 + 1);
    }
    if (p_lbl_1_bss_1148->unk_2C >= 4) {
    p_lbl_1_bss_1148->unk_2C = 0;
    }
    v4 = p_lbl_1_bss_1148->unk_2C;
    v2 = (u32)((u8 *)(u32)p_lbl_1_bss_1148 + 24);
    v14 = (p_lbl_1_rodata_4E0->unk_14);
    fzgx_live = p_lbl_1_rodata_4E0->unk_0;
    v15 = (fzgx_live);
    v16 = (p_lbl_1_rodata_4E0->unk_24);
    v17 = 0;
    while ((s16)v17 < 3) {
    if (((s16)v17) == v4) {
    v3 = *(f32 *)((u8 *)v2 + 0);
    v3 = (v3 + v16);
    *(f32 *)((u8 *)v2 + 0) = v3;
    } else {
    v3 = *(f32 *)((u8 *)v2 + 0);
    v3 = (v3 - v16);
    *(f32 *)((u8 *)v2 + 0) = v3;
    }
    v3 = *(f32 *)((u8 *)v2 + 0);
    if (v3 < v14) {
    *(f32 *)((u8 *)v2 + 0) = v14;
    }
    v3 = *(f32 *)((u8 *)v2 + 0);
    if (v3 > v15) {
    *(f32 *)((u8 *)v2 + 0) = v15;
    }
    v2 = (u32)((u8 *)v2 + 4);
    v17++;
    }
    }
}
#pragma opt_strength_reduction reset

#pragma opt_propagation reset

#pragma opt_lifetimes reset
/* fzgx:end fn_1_E174 */

/* fzgx:begin fn_1_E688 pool noprologue */
typedef signed char s8;
typedef signed short s16;
typedef signed long s32;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef float f32;
typedef double f64;

typedef struct FontDrawPacket FontDrawPacket;
typedef struct FontVertex {
f32 x, y, z;
} FontVertex;
struct FontDrawPacket {
u32 image;
f32 x, y, z;
f32 scale_x, scale_y;
f32 u0, v0, u1, v1;
s16 rotation_z, rotation_y;
f32 alpha;
u32 flags;
f32 depth;
u8 color[4], color_add[4];
u32 format;
u16 width, height;
void* pixels;
FontDrawPacket* secondary;
void (*vertex_callback)(FontDrawPacket* packet, FontVertex* vertices);
u32 unk_54;
};
void fn_1_4A0D8(const char* text);
void fn_1_4AE0C(const char* format, ...);
int fn_1_4F734(FontDrawPacket* packet);
void fn_1_4EDAC(FontDrawPacket* packet, f32 width, f32 height);
void fn_1_51678(FontDrawPacket* packet, u32 image, s16 x, s16 y, s16 width, s16 height);
void fn_1_517EC(FontDrawPacket* packet, s16 x, s16 y, s16 width, s16 height,
s16 texture_width, s16 texture_height);
struct fn_1_E688_Copy88 { u32 a[22]; };
struct fn_1_E688_lbl_1_rodata_4E0 {
f32 unk_0;
u8 pad_4[0x4];
f32 unk_8;
u8 pad_C[0x8];
f32 unk_14;
f32 unk_18;
f32 unk_1C;
u8 pad_20[0x8];
u32 unk_28;
u32 unk_2C;
u32 unk_30;
u8 pad_34[0x4];
f64 unk_38;
f32 unk_40;
f32 unk_44;
f32 unk_48;
f32 unk_4C;
f32 unk_50;
f32 unk_54;
f32 unk_58;
f32 unk_5C;
f64 unk_60;
f64 unk_68;
};

extern f32 fn_1_4B068(const char *);
extern int fn_1_4F734(FontDrawPacket *);
extern int sprintf(char *, const char *, ...);
extern s32 fn_1_A5DC4(void);
extern const struct fn_1_E688_lbl_1_rodata_4E0 lbl_1_rodata_4E0;
extern u16 fn_1_48690(u32);
extern u16 fn_1_486C4(u32);
extern u32 lbl_1_rodata_26F8;
extern void fn_1_49410(void);
extern void fn_1_49514(u32 *);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_49590(f32);
extern void fn_1_495A0(f32);
extern void fn_1_495B0(u32);
extern void fn_1_495C8(u8);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4A0D8(const char *);
extern void fn_1_50190(void *, f32, f32, f32, f32, f32, f32);

/* Generated by `fzgx headers --module main_rel --tu live_camera.c`: globals of live_camera.c (referenced by its */
/* functions or living in its .data block), layouts recovered from every access in the module. */
/* lbl_1_data_43B8: .data size 0xC, 11 refs from live_camera.c */
/* one view of the TU's .data run from 0x43B8 (strings follow at +0x68 and +0x280..) */
typedef struct {
u8 pad_0[0x13C];
u32 unk_13C;
u32 unk_140;
u32 unk_144;
s16 unk_148;
s16 unk_14A;
s16 unk_14C;
} Obj_1_data_43B8;
/* typedefs.json decl override */
/* lbl_1_bss_1148: .bss size 0x14, 9 refs from live_camera.c */
/* one view of the TU's .bss run from 0x1148: fn_1_E174 and fn_1_FA84 address it off one base */
typedef struct {
u8 unk_0;
u8 pad_1[0x7];
f32 unk_8;
f32 unk_C;
f32 unk_10;
u8 unk_14;
u8 pad_15[0xF];
f32 unk_24;
u8 pad_28[0x4];
s16 unk_2C;
s16 unk_2E;
u8 pad_30[0x5D8];
s16 unk_608;
u8 pad_60A[0x5A];
u8 unk_664;
u8 pad_665[0x17];
u32 unk_67C;
u32 unk_680;
u32 unk_684;
} Obj_1_bss_1148;
extern u8 fn_1_10268__fzgx_offset_0[];
extern u8 fn_1_103B0__fzgx_offset_0[];
extern u8 fn_1_107B8__fzgx_offset_0[];
extern u8 fn_1_10AF0__fzgx_offset_0[];
extern u8 fn_1_1138C__fzgx_offset_0[];
extern u8 fn_1_11544__fzgx_offset_0[];
extern u8 fn_1_11748__fzgx_offset_0[];
extern u8 fn_1_1189C__fzgx_offset_0[];
extern u8 fn_1_11ABC__fzgx_offset_0[];
extern u8 fn_1_11C08__fzgx_offset_0[];
extern u8 fn_1_11E98__fzgx_offset_0[];
extern u8 fn_1_1212C__fzgx_offset_0[];
extern u8 fn_1_DA34__fzgx_offset_0[];
extern u8 lbl_1_data_43B8__fzgx_offset_0[];
extern u8 lbl_1_data_43C4__fzgx_offset_0[];
extern u8 lbl_1_data_43CC__fzgx_offset_0[];
extern u8 lbl_1_data_43D8__fzgx_offset_0[];
extern u8 lbl_1_data_43E0__fzgx_offset_0[];
extern u8 lbl_1_data_43EC__fzgx_offset_0[];
extern u8 lbl_1_data_43F4__fzgx_offset_0[];
extern u8 lbl_1_data_43FC__fzgx_offset_0[];
extern u8 lbl_1_data_4508__fzgx_offset_0[];
extern u8 lbl_1_data_4514__fzgx_offset_0[];
extern u8 lbl_1_data_4524__fzgx_offset_0[];
extern u8 lbl_1_data_4530__fzgx_offset_0[];
extern u8 lbl_1_data_4540__fzgx_offset_0[];
extern u8 lbl_1_data_4554__fzgx_offset_0[];
extern u8 lbl_1_data_4568__fzgx_offset_0[];

#pragma section code_type ".fzgxpool"
static const f32 fzgx_one[1] = {1.0f};
static const f32 fzgx_three_hundred[1] = {300.0f};
static const f32 fzgx_center[1] = {320.0f};
static const f32 fzgx_unused_234[1] = {234.0f};
static const f32 fzgx_unused_230[1] = {230.0f};
static const f32 fzgx_zero[1] = {0.0f};
static const f32 fzgx_half[1] = {0.5f};
static const f32 fzgx_two[1] = {2.0f};
static const f32 fzgx_unused_01[1] = {0.009999999776482582f};
static const f32 fzgx_unused_02[1] = {0.019999999552965164f};
static const u32 fzgx_pool_table2[1] = {0x0032FFFF};
static const u32 fzgx_pool_table3[1] = {0x000000FF};
static const u32 fzgx_pool_table4[1] = {0x000000FF};
static const u32 fzgx_pool_table5[1] = {0};
static const f64 fzgx_smooth_double[1] = {0.2};
static const f32 fzgx_text_scale[1] = {0.6000000238418579f};
static const f32 fzgx_y[1] = {62.0f};
static const f32 fzgx_padding[1] = {16.0f};
static const f32 fzgx_smooth[1] = {0.20000000298023224f};
static const f32 fzgx_three[1] = {3.0f};
static const f32 fzgx_wide[1] = {940.0f};
static const f32 fzgx_narrow[1] = {650.0f};
static const f32 fzgx_height[1] = {36.0f};
__declspec(section ".fzgxpool") static void fzgx_pool_prime_all(void) {
volatile f32 s; volatile f64 d; volatile u32 w; /* fzgx-allow: S2 pool primer sinks */
s = fzgx_one[0];
s = fzgx_three_hundred[0];
s = fzgx_center[0];
s = fzgx_unused_234[0];
s = fzgx_unused_230[0];
s = fzgx_zero[0];
s = fzgx_half[0];
s = fzgx_two[0];
s = fzgx_unused_01[0];
s = fzgx_unused_02[0];
w = fzgx_pool_table2[0];
w = fzgx_pool_table3[0];
w = fzgx_pool_table4[0];
w = fzgx_pool_table5[0];
d = fzgx_smooth_double[0];
s = fzgx_text_scale[0];
s = fzgx_y[0];
s = fzgx_padding[0];
s = fzgx_smooth[0];
s = fzgx_three[0];
s = fzgx_wide[0];
s = fzgx_narrow[0];
s = fzgx_height[0];
d = 4503601774854144.0;
d = 4503599627370496.0;
}
#pragma section code_type ".text"

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_1148[3];
f32 lbl_1_bss_1148_C;
f32 lbl_1_bss_1148_10;
u8 fzgx_obj_lbl_1_bss_115C;
u8 lbl_1_bss_1148_gap_115D;
u16 lbl_1_bss_1148_gap_115D_fill_115E;
u32 lbl_1_bss_1160[3];
f32 lbl_1_bss_1160_C;
u8 lbl_1_bss_1160_10[0x4];
u16 lbl_1_bss_1160_fill_1174;
s16 lbl_1_bss_1160_16;
u8 lbl_1_bss_1160_18[0x5D8];
s16 lbl_1_bss_1160_5F0;
u16 lbl_1_bss_1160_fill_1752;
u32 lbl_1_bss_1160_fill_1754[22];
u8 fzgx_obj_lbl_1_bss_17AC;
u8 lbl_1_bss_1148_gap_17AD;
u16 lbl_1_bss_1148_gap_17AD_fill_17AE;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_1148;
    s = *(u8 *)&lbl_1_bss_1148_C;
    s = *(u8 *)&lbl_1_bss_1148_10;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_115C;
    s = *(u8 *)&lbl_1_bss_1148_gap_115D;
    s = *(u8 *)&lbl_1_bss_1148_gap_115D_fill_115E;
    s = *(u8 *)&lbl_1_bss_1160;
    s = *(u8 *)&lbl_1_bss_1160_C;
    s = *(u8 *)&lbl_1_bss_1160_10;
    s = *(u8 *)&lbl_1_bss_1160_fill_1174;
    s = *(u8 *)&lbl_1_bss_1160_16;
    s = *(u8 *)&lbl_1_bss_1160_18;
    s = *(u8 *)&lbl_1_bss_1160_5F0;
    s = *(u8 *)&lbl_1_bss_1160_fill_1752;
    s = *(u8 *)&lbl_1_bss_1160_fill_1754;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_17AC;
    s = *(u8 *)&lbl_1_bss_1148_gap_17AD;
    s = *(u8 *)&lbl_1_bss_1148_gap_17AD_fill_17AE;
}
#pragma section code_type ".text"

static u32 fzgx_pool_data_lbl_1_data_43B8[139] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4F564552, 0x54414B45, 0x0, 0x4A554D50, 0x0, 0x454E454D, 0x59484954, 0x0,
    0x57414C4C, 0x48495400, 0x53494445, 0x42595349, 0x44450000, 0x53544152, 0x54000000, 0x474F414C,
    0x0, 0x4C415000, (u32)lbl_1_data_43B8__fzgx_offset_0, (u32)lbl_1_data_43C4__fzgx_offset_0, (u32)lbl_1_data_43CC__fzgx_offset_0, (u32)lbl_1_data_43D8__fzgx_offset_0, (u32)lbl_1_data_43E0__fzgx_offset_0, (u32)lbl_1_data_43EC__fzgx_offset_0,
    (u32)lbl_1_data_43F4__fzgx_offset_0, (u32)lbl_1_data_43FC__fzgx_offset_0, 0x6C697665, 0x5F63616D, 0x6572612E, 0x63000000, 0x6C697665, 0x63616D20,
    0x6572726F, 0x720A0000, (u32)fn_1_1138C__fzgx_offset_0, (u32)fn_1_11748__fzgx_offset_0, (u32)fn_1_11ABC__fzgx_offset_0, (u32)fn_1_11E98__fzgx_offset_0, (u32)fn_1_107B8__fzgx_offset_0, (u32)fn_1_10268__fzgx_offset_0,
    (u32)fn_1_DA34__fzgx_offset_0, (u32)fn_1_11544__fzgx_offset_0, (u32)fn_1_1189C__fzgx_offset_0, (u32)fn_1_11C08__fzgx_offset_0, (u32)fn_1_1212C__fzgx_offset_0, (u32)fn_1_10AF0__fzgx_offset_0, (u32)fn_1_103B0__fzgx_offset_0, (u32)fn_1_DA34__fzgx_offset_0,
    0x110000, 0xC1100, 0xC1100, 0x10000, 0x1, 0x3, 0x5, 0x7,
    0x8, 0x9, 0xA, 0xB, 0xD, 0xE, 0xF, 0x10,
    0x11, 0x15, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D,
    0x1F, 0x20, 0x21, 0x22, 0x23, 0x24, 0x1, 0xFFFFFFFF,
    0xFFFFFFFF, 0xFFFFFFFF, 0x2A002A, 0x3C0000, 0x4155544F, 0x2043414D, 0x45524100, 0x434F5552,
    0x53452043, 0x414D4552, 0x41000000, 0x43415220, 0x43414D45, 0x52410000, 0x53454C45, 0x43542043,
    0x414D4552, 0x41000000, 0x4C495645, 0x43414D20, 0x4D4F4445, 0x204D4158, 0x0, 0x4F4C4420,
    0x52414E44, 0x4F4D2043, 0x414D4552, 0x41000000, 0x5441424C, 0x45204D4F, 0x44450000, (u32)lbl_1_data_4508__fzgx_offset_0,
    (u32)lbl_1_data_4514__fzgx_offset_0, (u32)lbl_1_data_4524__fzgx_offset_0, (u32)lbl_1_data_4530__fzgx_offset_0, (u32)lbl_1_data_4540__fzgx_offset_0, (u32)lbl_1_data_4554__fzgx_offset_0, (u32)lbl_1_data_4568__fzgx_offset_0, 0x81F42573, 0x0,
    0x81F44272, 0x61696E20, 0x436C6561, 0x6E657200, 0x81F4436F, 0x76657220, 0x6F66204D, 0x75746520,
    0x43697479, 0x27732074, 0x68656D65, 0x0, 0x81F4436F, 0x76657220, 0x6F662042, 0x69672042,
    0x6C756527, 0x73207468, 0x656D6500
};
static u32 fzgx_pool_data_lbl_1_data_43B8_22C[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x25730000
};
static u32 fzgx_pool_data_lbl_1_data_43B8_230[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x5D000000
};
static u32 fzgx_pool_data_lbl_1_data_43B8_234[90] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x5B000000, 0x90A0B0C, 0xD000000, 0x47414D45, 0x2043414D, 0x4552410A, 0x0, 0x4C495645,
    0x20574954, 0x48204741, 0x4D452043, 0x414D4552, 0x410A0000, 0x53454C45, 0x43542043, 0x414D4552,
    0x410A0000, 0x25730A00, 0x25346400, 0x63616D00, 0x6C697665, 0x63616D5F, 0x73746167, 0x655F6465,
    0x6D6F5F25, 0x642E6269, 0x6E000000, 0x6C697665, 0x63616D5F, 0x73746167, 0x655F6465, 0x6D6F5F31,
    0x2E62696E, 0x0, 0x6C697665, 0x63616D5F, 0x73746167, 0x655F3530, 0x5F34702E, 0x62696E00,
    0x6C697665, 0x63616D5F, 0x73746167, 0x655F3530, 0x5F33702E, 0x62696E00, 0x6C697665, 0x63616D5F,
    0x73746167, 0x655F3530, 0x5F32702E, 0x62696E00, 0x6C697665, 0x63616D5F, 0x73746167, 0x655F6465,
    0x6D6F5F35, 0x305F656E, 0x642E6269, 0x6E000000, 0x6C697665, 0x63616D5F, 0x73746167, 0x655F2564,
    0x2E62696E, 0x0, 0x6C697665, 0x63616D5F, 0x73746167, 0x655F312E, 0x62696E00, 0x2E2E0000,
    0x6C697665, 0x63616D5F, 0x25642E62, 0x696E0000, 0x6C697665, 0x63616D5F, 0x312E6269, 0x6E000000,
    0x6C697665, 0x63616D5F, 0x62616C6C, 0x5F25642E, 0x62696E00, 0x6C697665, 0x63616D5F, 0x62616C6C,
    0x5F312E62, 0x696E0000
};

#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_1_data_43B8(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .data objects in retail order */
    s = *(u8 *)fzgx_pool_data_lbl_1_data_43B8;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_43B8_22C;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_43B8_230;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_43B8_234;
}
#pragma section code_type ".text"
#pragma fp_contract off
void fn_1_E688(f32 arg0) {
const struct fn_1_E688_lbl_1_rodata_4E0 *p_lbl_1_rodata_4E0;
f32 v0;
f32 v1;
f64 v2;
s16 v6;
void * v4;
s16 v5;
void * v10;
s16 v7;
f32 v8;
int v9;
s32 v3;
s32 v11;
f32 v12;
f32 v13;
f32 v14;
f32 v15;
f64 v16;
f32 v17;
s32 v18;
f64 v19;
f32 v20;
f32 v21;
f32 v22;
f64 v23;
f32 v24;
s32 v25;
f64 v26;
f32 v27;
f32 v28;
f32 v29;
f32 v30;
f32 v31;
char loc_64[5][35];
struct fn_1_E688_Copy88 loc_C;
u32 loc_8;
int t0;
int t1;
f32 t11;
s32 t17;
u16 t18;
u16 t19;
int t20;
int t21;
u16 t22;
u16 t23;
int t24;
int t25;
s32 t26;


p_lbl_1_rodata_4E0 = &lbl_1_rodata_4E0;
v0 = arg0 < fzgx_zero[0] ? fzgx_zero[0] :
arg0 > fzgx_one[0] ? fzgx_one[0] : arg0;
v1 = lbl_1_bss_1148_C ;
v2 = fzgx_smooth_double[0];
lbl_1_bss_1148_C = (f32)(f64)((f64)(v1) + (f64)((f64)((f64)(v2) * (f64)((-v1)))));
v3 = 0;
v10 = &loc_64;
v4 = v10;
while ((s16)v3 < 5) {
v5 = (s16)((v3 - 2) + lbl_1_bss_1160_16 );
if (v5 < 0) {
v5 = (s16)(v5 + lbl_1_bss_1160_5F0 );
} else {
v6 = lbl_1_bss_1160_5F0 ;
if (v5 > (s32)(v6 - 1)) {
v5 = (s16)(v5 - v6);
}
}
if ((s16)v3 == 2) {
{
char *messages = (char *)lbl_1_bss_1160_18;
sprintf((char *)v4, (const char *)(((u8 *)fzgx_pool_data_lbl_1_data_43B8_22C)) , messages + v5 * 34);
}
} else {
{
char *messages = (char *)lbl_1_bss_1160_18;
sprintf((char *)v4, (const char *)(((u8 *)fzgx_pool_data_lbl_1_data_43B8_22C)) , messages + v5 * 34);
}
}
v4 = (void *)(((u8 *)v4 + 35));
v3++;
}
if (!(v0 <= fzgx_zero[0])) {
fn_1_49410();
v8 = (f32)(fzgx_two[0]);
fn_1_4954C(v8);
v8 = (f32)(fzgx_text_scale[0]);
fn_1_4955C(v8, v8);
v8 = (f32)(v0);
fn_1_495A0(v8);
v8 = (f32)(fzgx_half[0]);
fn_1_49590(v8);
v9 = 9;
fn_1_495C8(v9);
v9 = (0xC000u << 16);
fn_1_495B0(v9);
v15 = fzgx_center[0];
v11 = 0;
while ((s16)v11 < 5) {
v9 = (s16)v11;
fn_1_496FC(lbl_1_bss_1148_C + (f32)(v15 + (f32)(lbl_1_bss_1160_C * (f32)(v9 - 2))), fzgx_y[0]);
v9 = (int)(v10);
fn_1_4A0D8((const char *)v9);
v10 = (void *)(((u8 *)v10 + 35));
v11++;
}
v9 = (u32)&loc_64[2];
t11 = fn_1_4B068((const char *)v9);
v9 = (u32)&loc_8;
v8 = (f32)(fzgx_padding[0] + t11);
loc_8 = fzgx_pool_table2[0];
v13 = fzgx_smooth[0];
lbl_1_bss_1148_10 += v13 * (f32)((f32)(v8 * fzgx_half[0]) - lbl_1_bss_1148_10);
fn_1_49514((u32 *)v9);
v8 = (f32)(fzgx_center[0]);
v8 = (f32)((f32)(v8 + lbl_1_bss_1148_10 ));
fn_1_496FC(v8, fzgx_y[0]);
v9 = (u32)((u8 *)(u32)((u8 *)(((u8 *)fzgx_pool_data_lbl_1_data_43B8_230)) ));
fn_1_4A0D8((const char *)v9);
v8 = (f32)(fzgx_center[0]);
v8 = (f32)((f32)(v8 - lbl_1_bss_1148_10 ));
fn_1_496FC(v8, fzgx_y[0]);
v9 = (u32)((u8 *)(u32)((u8 *)(((u8 *)fzgx_pool_data_lbl_1_data_43B8_234)) ));
fn_1_4A0D8((const char *)v9);
t17 = fn_1_A5DC4();
v9 = t17;
if ((s8)v9 != 0) {
v9 = (u32)&lbl_1_rodata_26F8;
loc_C = *(struct fn_1_E688_Copy88 *)v9;
v9 = 5;
v8 = fzgx_center[0] - lbl_1_bss_1160_C * fzgx_half[0];
loc_C.a[0] = 5;
*(f32 *)((u8 *)&loc_C + 8) = fzgx_y[0];
*(f32 *)((u8 *)&loc_C + 4) = v8;
loc_C.a[14] = fzgx_pool_table3[0];
v8 = (*(f32 *)lbl_1_bss_1160_10) / (f32)fn_1_48690(v9);
*(f32 *)((u8 *)&loc_C + 16) *= v8;
*(f32 *)((u8 *)&loc_C + 20) *= (f32)(32 / fn_1_486C4(loc_C.a[0]));
*(f32 *)((u8 *)&loc_C + 44) = v0;
*(f32 *)((u8 *)&loc_C + 12) = fzgx_one[0];
loc_C.a[12] = (0x80000 + 11);
t20 = fn_1_4F734((FontDrawPacket *)&loc_C);
v9 = t20;
loc_C.a[12] = 9;
*(f32 *)((u8 *)&loc_C + 4) = fzgx_center[0] + lbl_1_bss_1160_C * fzgx_half[0];
t21 = fn_1_4F734((FontDrawPacket *)&loc_C);
v9 = t21;
} else {
v9 = (u32)&lbl_1_rodata_26F8;
loc_C = *(struct fn_1_E688_Copy88 *)v9;
v9 = 5;
v8 = fzgx_center[0] - lbl_1_bss_1160_C * fzgx_half[0];
loc_C.a[0] = 5;
*(f32 *)((u8 *)&loc_C + 8) = fzgx_y[0];
*(f32 *)((u8 *)&loc_C + 4) = v8;
loc_C.a[14] = fzgx_pool_table4[0];
v8 = (*(f32 *)lbl_1_bss_1160_10) / (f32)fn_1_48690(v9);
*(f32 *)((u8 *)&loc_C + 16) *= v8;
*(f32 *)((u8 *)&loc_C + 20) *= (f32)(32 / fn_1_486C4(loc_C.a[0]));
*(f32 *)((u8 *)&loc_C + 44) = v0;
*(f32 *)((u8 *)&loc_C + 12) = fzgx_one[0];
loc_C.a[12] = (0x80000 + 11);
t24 = fn_1_4F734((FontDrawPacket *)&loc_C);
v9 = t24;
loc_C.a[12] = 9;
*(f32 *)((u8 *)&loc_C + 4) = fzgx_center[0] + lbl_1_bss_1160_C * fzgx_half[0];
t25 = fn_1_4F734((FontDrawPacket *)&loc_C);
v9 = t25;
}
v9 = (u32)&lbl_1_rodata_26F8;
loc_C = *(struct fn_1_E688_Copy88 *)v9;
v9 = 0x10000;
v9 -= 27129;
loc_C.a[0] = v9;
*(f32 *)((u8 *)&loc_C + 4) = fzgx_center[0];
*(f32 *)((u8 *)&loc_C + 8) = fzgx_y[0];
*(f32 *)((u8 *)&loc_C + 12) = fzgx_three[0];
loc_C.a[12] = 10;
*(f32 *)((u8 *)&loc_C + 44) = v0;
t26 = fn_1_A5DC4();
v9 = t26;
if ((s8)v9 != 0) {
v8 = (f32)(fzgx_wide[0]);
} else {
v8 = (f32)(fzgx_narrow[0]);
}
v30 = fzgx_zero[0];
v31 = fzgx_three[0];
fn_1_50190((void *)&loc_C, v8, fzgx_height[0], v30, v30, v31, v31);
}
return;
}
/* fzgx:end fn_1_E688 */

/* fzgx:begin fn_1_EBE4 */
typedef struct {
    f32 x, y, z;
} CamVec3;

/* live camera state object (first argument) */
typedef struct {
    u8 state;        /* 0x00 */
    u8 unk_1;        /* 0x01 */
    u8 pad_2[4];
    s16 unk_6;       /* 0x06 */
    s16 unk_8;       /* 0x08 */
    u8 pad_A[2];
    u32 flags;       /* 0x0C */
    s16 unk_10;      /* 0x10 */
    s16 unk_12;      /* 0x12 */
    s16 unk_14;      /* 0x14 */
    u8 pad_16[2];
    u32 unk_18;      /* 0x18 */
    CamVec3 pos;     /* 0x1C */
    CamVec3 target;  /* 0x28 */
    u8 pad_34[0x28];
    s16 unk_5C;      /* 0x5C */
    u8 pad_5E[2];
    f32 unk_60;      /* 0x60 */
    s16 unk_64;      /* 0x64 */
    u8 pad_66[4];
    s16 unk_6A;      /* 0x6A */
} fn_1_EBE4_LiveCamera;

/* wider views of the TU's shared state than the generated header carries */
typedef struct {
    u8 unk_0;
    u8 pad_1[0xB];
    f32 unk_C;
    u8 pad_10[4];
    u8 unk_14;
    u8 pad_15[0x64F];
    u8 unk_664;
    u8 pad_665;
    s16 unk_666;
    s32 unk_668;
    u8 unk_66C;
    u8 pad_66D[3];
    u32 unk_670;
    u32 unk_674;
    u8 unk_678;
} LiveCameraState;

typedef struct {
    u8 pad_0[0xD0];
    s32 ids[0x1A];   /* 0xD0 */
    u8 pad_138[0x10];
    s16 unk_148;
    s16 unk_14A;
    s16 unk_14C;
} LiveCameraData;

void fn_1_EBE4(fn_1_EBE4_LiveCamera *cam, s16 id, s32 mode, f32 value) {
    LiveCameraData *dat = (LiveCameraData *)&lbl_1_data_43B8;
    LiveCameraState *st = (LiveCameraState *)&lbl_1_bss_1148;
    s32 *ids;
    u32 i;

    st->unk_666 = 0;
    st->unk_668 = -1;
    dat->unk_14C = 0x3C;
    st->unk_C = 0.0f;
    st->unk_14 = 0;
    st->unk_0 = 0;
    st->unk_66C = 0;
    cam->flags &= ~0x00080000;
    for (i = 0, ids = dat->ids; i < 0x1A; i++, ids++) {
        if (*ids == fn_1_7B054()) {
            cam->flags |= 0x00080000;
        }
    }

    if (mode) {
        cam->state = 6;
        cam->unk_12 = 5;
        cam->unk_14 = 0;
        cam->unk_18 = 0;
        cam->unk_10 = 0;
        fn_1_10138(cam);
    } else {
        cam->state = 5;
        cam->unk_12 = 2;
        cam->unk_14 = 9;
        cam->unk_18 = 0;
        cam->unk_10 = 0;
    }
    cam->unk_1 = 0;
    cam->unk_64 = 0xD2;
    cam->unk_6A = 0;
    cam->flags &= ~0x00200000;
    cam->unk_60 = value;
    cam->unk_5C = 0;
    cam->target = cam->pos;
    cam->unk_8 = id;
    cam->unk_6 = id;
    st->unk_670 = 0;
    st->unk_674 = 0;
    fn_1_8840();

    if (*(s16 *)&lbl_1_bss_960 == 10 && !mode) {
        st->unk_664 = 0;
        st->unk_678 = 2;
        cam->state = 0;
        dat->unk_14A = 0x2A;
        lbl_1_bss_6F243 = 0;
        if (dat->unk_148 != 0x2A) {
            dat->unk_148 = 0x2A;
        }
        fn_1_A1588( (Sig_ADXT_Stop_ADXTHandle *)(u32)(lbl_1_bss_6EAD0.unk_0->unk_0), 1);
        fn_1_A1CE8((u8)dat->unk_148);
    } else if (fn_1_F2F34() && !mode) {
        cam->state = 0;
    }

    if (st->unk_664) {
        st->unk_678 = 2;
    }
}
/* fzgx:end fn_1_EBE4 */

/* fzgx:begin fn_1_EE04 */
typedef struct {
    u8 pad[2];
    s16 state;
} Fn1EE04Context;

typedef void (*Fn1EE04Handler)(Fn1EE04Context *, void *);

// Dispatch the active live-camera handler, then advance camera processing.
void fn_1_EE04(Fn1EE04Context *context) {
    ((Fn1EE04Handler *)lbl_1_data_4440)[context->state](
        context, lbl_1_data_4440);
    fn_1_6DD0( (u8)(void *)(0));
}
/* fzgx:end fn_1_EE04 */

/* fzgx:begin fn_1_EE44 */
struct fn_1_EE44_Arg0 {
    u8 unk_0;
    u8 pad_1;
    s16 unk_2, unk_4, unk_6, unk_8;
    u8 pad_A[2];
    u32 unk_C;
    u8 pad_10[2];
    s16 unk_12, unk_14;
    u8 pad_16[6];
    u32 unk_1C, unk_20, unk_24;
    u32 unk_28, unk_2C, unk_30;
    u8 pad_34[0x18];
    f32 unk_4C[3];
    f32 unk_58;
    s16 unk_5C;
    u8 pad_5E[2];
    f32 unk_60;
    u16 unk_64;
    u8 pad_66[4];
    u16 unk_6A;
    u8 pad_6C[4];
    f32 unk_70[3];
    u8 pad_7C[0x80];
    u8 unk_FC[0x30];
    u8 unk_12C[0x30];
    u8 unk_15C[4];
};
struct fn_1_EE44_Object {
    u8 pad_0[0x7C];
    u32 unk_7C;
    u8 pad_80[0x80];
    f32 unk_100;
};
typedef void (*Fn1EE44Handler)(struct fn_1_EE44_Arg0 *, void *);

static inline void update_mode(struct fn_1_EE44_Arg0 *arg0, u8 *pool) {
    struct fn_1_EE44_Object *obj;
    if (arg0->unk_6 != 255 && arg0->unk_6 >= 0 &&
        arg0->unk_2 != 5 && arg0->unk_2 != -1) {
        obj = (void *)fn_1_8627C(arg0->unk_6);
        if (obj != 0) {
            if (obj->unk_7C & 0x01000000) {
                if ((obj->unk_7C & 1) && fn_1_7B054() != 35)
                    return;
                if ((u16)fn_1_584AC() % 2)
                    arg0->unk_12 = 1;
                else
                    arg0->unk_12 = 3;
                arg0->unk_C &= 0xFFDFFFFF;
            }
            if (fn_1_7B054() != 11)
                return;
            if (*(f32 *)(pool + 0x70) < obj->unk_100)
                return;
            if (obj->unk_100 < *(f32 *)(pool + 0x74))
                return;
            {
                if ((u16)fn_1_584AC() % 2)
                    arg0->unk_12 = 1;
                else
                    arg0->unk_12 = 3;
                arg0->unk_C &= 0xFFDFFFFF;
            }
        }
    }
}

#pragma opt_propagation off
void fn_1_EE44(struct fn_1_EE44_Arg0 *arg0, f32 arg1) {
    Obj_1_data_43B8 *p_lbl_1_data_43B8;
    u8 *p_lbl_1_rodata_4E0;
    u32 v0;
    u16 v1;
    u8 v2;
    u16 v3;
    f64 value;
    s16 rotation;
    union { f64 d; struct { u32 hi, lo; } w; } conversion;
    p_lbl_1_data_43B8 = (Obj_1_data_43B8 *)&lbl_1_data_43B8;
    p_lbl_1_rodata_4E0 = (u8 *)&lbl_1_rodata_4E0;
    arg0->unk_C &= 0x7FFFFFFF;
    {
        typedef struct { u32 x, y, z; } Copy3;
        *(Copy3 *)&arg0->unk_28 = *(Copy3 *)&arg0->unk_1C;
    }
    v1 = arg0->unk_64;
    if (v1 != 0)
        arg0->unk_64 = v1 - *(s16 *)((u8 *)p_lbl_1_data_43B8 + 0xCC);
    v2 = arg0->unk_0;
    switch (v2) {
    case 3:
        if (fn_1_40BB4() == 0) {
            if ((lbl_1_bss_9F8.unk_A >> 2) & 1) {
                arg0->unk_12++;
                arg0->unk_14 = 0;
            }
            if ((lbl_1_bss_9F8.unk_A >> 3) & 1) {
                arg0->unk_12--;
                arg0->unk_14 = 0;
            }
            if (arg0->unk_12 >= 4)
                arg0->unk_12 = 0;
            if (arg0->unk_12 < 0)
                arg0->unk_12 = 3;
        }
        break;
    case 6:
        fn_1_101D0( (Fn_1_101D0_State *)((Sig_fn_1_101D0_Fn_1_101D0_State *)arg0));
        break;
    case 0:
    case 1:
    case 2:
    case 5:
        if (v2 == 0) {
            v3 = arg0->unk_6A;
            arg0->unk_6A = v3 + 1;
            arg0->unk_C &= 0xFFDFFFFF;
            if (fn_1_A5848()) {
                if (lbl_1_bss_17C0)
                    lbl_1_bss_17C0--;
                else {
                    fn_1_FCB0((Sig_fn_1_101D0_Fn_1_101D0_State *)arg0);
                    fn_1_A5858(0);
                    arg0->unk_6A = 0;
                }
            }
            if (arg0->unk_6A > 240) {
                arg0->unk_6A = 0;
                fn_1_FCB0((Sig_fn_1_101D0_Fn_1_101D0_State *)arg0);
                fn_1_A5858(0);
            }
        } else {
            if (arg0->unk_64 != 0) {
                f64 bias = *(f64 *)(p_lbl_1_rodata_4E0 + 0x68);
                conversion.w.lo = arg0->unk_64;
                conversion.w.hi = 0x43300000;
                {
                    value = conversion.d;
                    if (!(value - bias >
                        *(f64 *)(p_lbl_1_rodata_4E0 + 0x78)))
                        goto mode_done; /* Join the common per-frame update. */
                }
            }
            if (!(arg0->unk_C & 0x00200000))
                fn_1_FCB0((Sig_fn_1_101D0_Fn_1_101D0_State *)arg0);
        }
        break;
    }
mode_done:
    if ((s8)camera_get_state() == 6 && arg0->unk_12 == 2)
        arg0->unk_12 = (arg0->unk_12 + 1) % 3;
    if (arg0->unk_2 != arg0->unk_12) {
        update_mode(arg0, p_lbl_1_rodata_4E0);
        arg0->unk_2 = arg0->unk_12;
        ((Fn1EE44Handler *)((u8 *)p_lbl_1_data_43B8 + 0x88))[arg0->unk_2](arg0, (u8 *)p_lbl_1_data_43B8 + 0x88);
        fn_1_6DD0( (u8)(void *)(0));
    }
    if (arg0->unk_4 != arg0->unk_14) {
        update_mode(arg0, p_lbl_1_rodata_4E0);
        arg0->unk_4 = arg0->unk_14;
        ((Fn1EE44Handler *)((u8 *)p_lbl_1_data_43B8 + 0x88))[arg0->unk_2](arg0, (u8 *)p_lbl_1_data_43B8 + 0x88);
        fn_1_6DD0( (u8)(void *)(0));
    }
    if (arg0->unk_2 == 5 || arg0->unk_2 == -1)
        arg0->unk_6 = -1;
    else
        arg0->unk_6 = arg0->unk_8;
    ((Fn1EE44Handler *)((u8 *)p_lbl_1_data_43B8 + 0xA4))[arg0->unk_2](arg0, (u8 *)p_lbl_1_data_43B8 + 0xA4);
    fn_1_FB50( (LiveCam_FB50 *)(void *)(arg0));
    lbl_8006DD14(arg0->unk_12C, arg0->unk_FC);
    if (arg0->unk_2 == 1 || arg0->unk_2 == 2)
        fn_8006F1F0(&arg0->unk_1C, arg0->unk_70, arg0->unk_4C);
    else
        fn_8006F038( (Vec3 *)(void *)(&arg0->unk_1C), (Vec3 *)(void *)(arg0->unk_4C), arg0->unk_5C);
    lbl_8006DB74(arg0->unk_12C);
    fn_8006F4E0(&rotation);
    fn_1_549F4(&arg0->unk_1C, &rotation, arg0->unk_58, arg0->unk_60,
        *(f32 *)(p_lbl_1_rodata_4E0 + 0x14), *(f32 *)(p_lbl_1_rodata_4E0 + 0x14));
    fn_1_54DCC(arg0->unk_15C);
}
/* fzgx:end fn_1_EE44 */

/* fzgx:begin fn_1_F3D0 pool noprologue */
#include "types.h"
#include "font.h"

typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 pad_2[0x4];
    s16 unk_6;
    u8 pad_8[0xA];
    s16 unk_12;
} fn_1_F3D0_Arg;

typedef struct {
    u8 pad_0[0x8];
    f32 unk_8;
    u8 pad_C[0x8];
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    u8 pad_20[0x60];
    f32 unk_80;
    f32 unk_84;
    f32 unk_88;
    f32 unk_8C;
    f32 unk_90;
    f32 unk_94;
    f32 unk_98;
} fn_1_F3D0_Rodata;

extern fn_1_F3D0_Rodata lbl_1_rodata_4E0;
extern const FontDrawPacket lbl_1_rodata_26F8;
extern s16 lbl_1_bss_960;

extern s32 fn_1_F2F34(void);
extern s32 fn_1_40BB4(void);
extern u32 fn_1_E688(f32);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_495B0(u32);
extern void fn_1_495C8(u8);
extern void fn_1_49590(f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_495A0(f32);
extern void fn_1_A8F40(u8);
extern f32 fn_1_8652C(int);
extern void fn_1_520A0(void);
extern void fn_1_52070(u32);
extern void fn_1_4966C(f32, f32);
extern void fn_1_520CC(void);

/* camera mode handlers stored in the retail .data table at lbl_1_data_43B8+0x88 */
extern void fn_1_1138C(void);
extern void fn_1_11748(void);
extern void fn_1_11ABC(void);
extern void fn_1_11E98(void);
extern void fn_1_107B8(void);
extern void fn_1_10268(void);
extern void fn_1_DA34(void);
extern void fn_1_11544(void);
extern void fn_1_1189C(void);
extern void fn_1_11C08(void);
extern void fn_1_1212C(void);
extern void fn_1_10AF0(void);
extern void fn_1_103B0(void);

/* file-scope .data objects of the retail TU (lbl_1_data_43B8 .. +0x39C), in retail order:
 * MWCC addresses them off one section base, and the name table at +0x1BC is its own object */
char fzgx_obj_lbl_1_data_43B8[12] = "OVERTAKE";
char fzgx_obj_lbl_1_data_43C4[8] = "JUMP";
char fzgx_obj_lbl_1_data_43CC[12] = "ENEMYHIT";
char fzgx_obj_lbl_1_data_43D8[8] = "WALLHIT";
char fzgx_obj_lbl_1_data_43E0[12] = "SIDEBYSIDE";
char fzgx_obj_lbl_1_data_43EC[8] = "START";
char fzgx_obj_lbl_1_data_43F4[8] = "GOAL";
char fzgx_obj_lbl_1_data_43FC[4] = "LAP";
const char *fzgx_obj_lbl_1_data_4400[8] = {
    fzgx_obj_lbl_1_data_43B8, fzgx_obj_lbl_1_data_43C4, fzgx_obj_lbl_1_data_43CC,
    fzgx_obj_lbl_1_data_43D8, fzgx_obj_lbl_1_data_43E0, fzgx_obj_lbl_1_data_43EC,
    fzgx_obj_lbl_1_data_43F4, fzgx_obj_lbl_1_data_43FC,
};
char fzgx_obj_lbl_1_data_4420[16] = "live_camera.c";
char fzgx_obj_lbl_1_data_4430[16] = "livecam error\n";
void (*fzgx_obj_lbl_1_data_4440[14])(void) = {
    fn_1_1138C, fn_1_11748, fn_1_11ABC, fn_1_11E98, fn_1_107B8, fn_1_10268, fn_1_DA34,
    fn_1_11544, fn_1_1189C, fn_1_11C08, fn_1_1212C, fn_1_10AF0, fn_1_103B0, fn_1_DA34,
};
u32 fzgx_obj_lbl_1_data_4478[3] = { 0x00110000, 0x000C1100, 0x000C1100 };
u32 fzgx_obj_lbl_1_data_4484[28] = {
    0x00010000, 0x1, 0x3, 0x5, 0x7, 0x8, 0x9, 0xA, 0xB, 0xD, 0xE, 0xF, 0x10, 0x11,
    0x15, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1F, 0x20, 0x21, 0x22, 0x23, 0x24, 0x1,
};
u32 fzgx_obj_lbl_1_data_44F4[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
u16 fzgx_obj_lbl_1_data_4500[4] = { 0x2A, 0x2A, 0x3C, 0 };
char fzgx_obj_lbl_1_data_4508[12] = "AUTO CAMERA";
char fzgx_obj_lbl_1_data_4514[16] = "COURSE CAMERA";
char fzgx_obj_lbl_1_data_4524[12] = "CAR CAMERA";
char fzgx_obj_lbl_1_data_4530[16] = "SELECT CAMERA";
char fzgx_obj_lbl_1_data_4540[20] = "LIVECAM MODE MAX";
char fzgx_obj_lbl_1_data_4554[20] = "OLD RANDOM CAMERA";
char fzgx_obj_lbl_1_data_4568[12] = "TABLE MODE";
const char *fzgx_obj_lbl_1_data_4574[7] = {
    fzgx_obj_lbl_1_data_4508, fzgx_obj_lbl_1_data_4514, fzgx_obj_lbl_1_data_4524,
    fzgx_obj_lbl_1_data_4530, fzgx_obj_lbl_1_data_4540, fzgx_obj_lbl_1_data_4554,
    fzgx_obj_lbl_1_data_4568,
};
char fzgx_obj_lbl_1_data_4590[8] = "\x81\xF4%s";
char fzgx_obj_lbl_1_data_4598[16] = "\x81\xF4" "Brain Cleaner";
char fzgx_obj_lbl_1_data_45A8[32] = "\x81\xF4" "Cover of Mute City's theme";
char fzgx_obj_lbl_1_data_45C8[28] = "\x81\xF4" "Cover of Big Blue's theme";
char fzgx_obj_lbl_1_data_45E4[4] = "%s";
char fzgx_obj_lbl_1_data_45E8[4] = "]";
char fzgx_obj_lbl_1_data_45EC[4] = "[";
char fzgx_obj_lbl_1_data_45F0[8] = "\t\n\v\f\r";
char fzgx_obj_lbl_1_data_45F8[16] = "GAME CAMERA\n";
char fzgx_obj_lbl_1_data_4608[24] = "LIVE WITH GAME CAMERA\n";
char fzgx_obj_lbl_1_data_4620[16] = "SELECT CAMERA\n";
char fzgx_obj_lbl_1_data_4630[4] = "%s\n";
char fzgx_obj_lbl_1_data_4634[4] = "%4d";
char fzgx_obj_lbl_1_data_4638[4] = "cam";
char fzgx_obj_lbl_1_data_463C[28] = "livecam_stage_demo_%d.bin";
char fzgx_obj_lbl_1_data_4658[28] = "livecam_stage_demo_1.bin";
char fzgx_obj_lbl_1_data_4674[24] = "livecam_stage_50_4p.bin";
char fzgx_obj_lbl_1_data_468C[24] = "livecam_stage_50_3p.bin";
char fzgx_obj_lbl_1_data_46A4[24] = "livecam_stage_50_2p.bin";
char fzgx_obj_lbl_1_data_46BC[32] = "livecam_stage_demo_50_end.bin";
char fzgx_obj_lbl_1_data_46DC[24] = "livecam_stage_%d.bin";
char fzgx_obj_lbl_1_data_46F4[20] = "livecam_stage_1.bin";
char fzgx_obj_lbl_1_data_4708[4] = "..";
char fzgx_obj_lbl_1_data_470C[16] = "livecam_%d.bin";
char fzgx_obj_lbl_1_data_471C[16] = "livecam_1.bin";
char fzgx_obj_lbl_1_data_472C[20] = "livecam_ball_%d.bin";
char fzgx_obj_lbl_1_data_4740[20] = "livecam_ball_1.bin";

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_1148[2];
f32 lbl_1_bss_1148_8;
u32 lbl_1_bss_1148_fill_1154[2];
u8 fzgx_obj_lbl_1_bss_115C;
u8 lbl_1_bss_1148_gap_115D;
u16 lbl_1_bss_1148_gap_115D_fill_115E;
f32 lbl_1_bss_1160[3];
u32 lbl_1_bss_1160_fill_116C[400];
u8 fzgx_obj_lbl_1_bss_17AC;
u8 lbl_1_bss_1148_gap_17AD;
u16 lbl_1_bss_1148_gap_17AD_fill_17AE;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_1148;
    s = *(u8 *)&lbl_1_bss_1148_8;
    s = *(u8 *)&lbl_1_bss_1148_fill_1154;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_115C;
    s = *(u8 *)&lbl_1_bss_1148_gap_115D;
    s = *(u8 *)&lbl_1_bss_1148_gap_115D_fill_115E;
    s = *(u8 *)&lbl_1_bss_1160;
    s = *(u8 *)&lbl_1_bss_1160_fill_116C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_17AC;
    s = *(u8 *)&lbl_1_bss_1148_gap_17AD;
    s = *(u8 *)&lbl_1_bss_1148_gap_17AD_fill_17AE;
}
#pragma section code_type ".text"

void fn_1_F3D0(fn_1_F3D0_Arg *arg) {
    fn_1_F3D0_Rodata *ro = &lbl_1_rodata_4E0;
    f32 alpha;
    s32 value;
    FontDrawPacket packet1;
    FontDrawPacket packet2;

    if (fn_1_F2F34() != 0 && arg->unk_12 != 5 && fn_1_40BB4() == 0) {
        fzgx_obj_lbl_1_bss_115C = 1;
        fn_1_E688(lbl_1_bss_1148_8);
        alpha = lbl_1_bss_1160[0];
        fn_1_49410();
        fn_1_494DC(6);
        fn_1_495B0((u32)0xC0 << 24);  /* colour/flag word, not an address */
        fn_1_495C8(9);
        fn_1_49590(ro->unk_18);
        fn_1_496FC(ro->unk_8, ro->unk_80);
        fn_1_495A0(alpha);

        if (arg->unk_1 != 0) {
            switch (arg->unk_1) {
            case 1:
                fn_1_4AE0C(fzgx_obj_lbl_1_data_45F8);
                break;
            case 2:
                fn_1_4AE0C(fzgx_obj_lbl_1_data_4608);
                break;
            case 0:
                break;
            }
        } else {
            switch (arg->unk_0) {
            case 3:
                fn_1_4AE0C(fzgx_obj_lbl_1_data_4620);
                break;
            default:
                fn_1_A8F40(0x33);
                fn_1_4AE0C(fzgx_obj_lbl_1_data_4630, fzgx_obj_lbl_1_data_4574[arg->unk_0]);
                fn_1_A8F40(0xFF);
                break;
            }
        }

        alpha = lbl_1_bss_1160[1];
        value = fn_1_8652C(arg->unk_6);
        fn_1_49410();
        if (lbl_1_bss_960 == 12) {
            fn_1_494DC(0x2B);
        } else {
            fn_1_494DC(0xF);
        }
        fn_1_520A0();
        fn_1_52070(0x220);
        fn_1_496FC(ro->unk_84, ro->unk_88);
        fn_1_4966C(ro->unk_1C, ro->unk_14);
        fn_1_495A0(alpha);
        fn_1_4AE0C(fzgx_obj_lbl_1_data_4634, value);

        packet1 = lbl_1_rodata_26F8;
        packet1.image = (lbl_1_bss_960 == 12) ? 0x9601 : 0x9401;
        packet1.x = ro->unk_8C;
        packet1.y = ro->unk_90;
        packet1.alpha = alpha;
        fn_1_4F734(&packet1);
        fn_1_520CC();

        alpha = lbl_1_bss_1160[2];
        packet2 = lbl_1_rodata_26F8;
        packet2.image = (lbl_1_bss_960 == 12) ? 0x9602 : 0x941F;
        fn_1_520A0();
        fn_1_52070(0x220);
        packet2.x = ro->unk_94;
        packet2.y = ro->unk_98;
        packet2.alpha = alpha;
        fn_1_4F734(&packet2);
        fn_1_520CC();
    }
}
/* fzgx:end fn_1_F3D0 */

/* fzgx:begin fn_1_F6A8 */
#define ALIGN32(n) (((n) + 0x1F) & ~0x1F)

/* Retail rematerialises the __FILE__ string address (dat + 0x68) at each
 * allocation; keep MWCC from hoisting it into a saved register. */
#pragma opt_common_subs off
#pragma opt_propagation off
/* Load the three live-camera data files into freshly allocated buffers. */
void fn_1_F6A8(void) {
    Obj_1_data_43B8 *dat = (Obj_1_data_43B8 *)&lbl_1_data_43B8;
    Obj_1_bss_1148 *st = (Obj_1_bss_1148 *)&lbl_1_bss_1148;
    u32 size;
    s32 mode;
    u32 n;
    char path[128];
    Sig_fn_1_45730_LoadResult file;

    if ((s32)dat->unk_13C >= 0 && (s32)dat->unk_140 >= 0 && (s32)dat->unk_144 >= 0) {
        return;
    }

    fn_80006E10( (u32)((const char *)dat + 0x280));
    dat->unk_13C = 0;
    st->unk_67C = 0;
    dat->unk_140 = 0;
    st->unk_680 = 0;
    dat->unk_144 = 0;
    st->unk_684 = 0;

    mode = (u32)&lbl_1_bss_960;
    mode = *(s16 *)mode;
    if (mode == 10) {
        sprintf(path, (const char *)dat + 0x284, fn_1_3F1F8());
        if (fn_1_45730(path, &file) == 0) {
            sprintf(path, (const char *)dat + 0x2A0);
            fn_1_45730(path, &file);
        }
    } else if (mode == 14) {
        if (lbl_1_bss_525C.unk_191 & 2) {
            switch (lbl_1_bss_525C.unk_192) {
            case 4:
                sprintf(path, (const char *)dat + 0x2BC);
                break;
            case 3:
                sprintf(path, (const char *)dat + 0x2D4);
                break;
            case 2:
                sprintf(path, (const char *)dat + 0x2EC);
                break;
            default:
                sprintf(path, (const char *)dat + 0x2EC);
                break;
            }
        } else {
            sprintf(path, (const char *)dat + 0x304);
        }
        fn_1_45730(path, &file);
    } else {
        sprintf(path, (const char *)dat + 0x324, fn_1_3F1F8());
        if (fn_1_45730(path, &file) == 0) {
            sprintf(path, (const char *)dat + 0x33C);
            fn_1_45730(path, &file);
        }
    }

    dat->unk_13C = fn_1_45B2C(&file) / 84;
    n = ALIGN32(fn_1_45B2C(&file));
    size = n;
    st->unk_67C = (u32)fn_1_4630(lbl_801A6410, n, (const char *)dat + 0x68, 0x58D);
    fn_1_458A0(&file, (void *)st->unk_67C, size, 0);
    fn_1_45850(&file);

    if (fn_1_7B054() == 50) {
        fn_80006E10( (u32)((const char *)dat + 0x350));
        return;
    }

    sprintf(path, (const char *)dat + 0x354, fn_1_3F1F8());
    if (fn_1_45730(path, &file) == 0) {
        sprintf(path, (const char *)dat + 0x364);
        fn_1_45730(path, &file);
    }
    dat->unk_140 = fn_1_45B2C(&file) / 40;
    mode = ALIGN32(fn_1_45B2C(&file));
    size = mode;
    st->unk_680 = (u32)fn_1_4630(lbl_801A6410, size, (const char *)dat + 0x68, 0x5A5);
    fn_1_458A0(&file, (void *)st->unk_680, size, 0);
    fn_1_45850(&file);

    sprintf(path, (const char *)dat + 0x374, fn_1_3F1F8());
    if (fn_1_45730(path, &file) == 0) {
        sprintf(path, (const char *)dat + 0x388);
        fn_1_45730(path, &file);
    }
    dat->unk_144 = fn_1_45B2C(&file) / 12;
    n = ALIGN32(fn_1_45B2C(&file));
    size = n;
    st->unk_684 = (u32)fn_1_4630(lbl_801A6410, size, (const char *)dat + 0x68, 0x5B6);
    fn_1_458A0(&file, (void *)st->unk_684, size, 0);
    fn_1_45850(&file);

    fn_80006E10( (u32)((const char *)dat + 0x350));
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_F6A8 */

/* fzgx:begin fn_1_FA84 */
void fn_1_FA84(void) {
    Obj_1_data_43B8 *p_lbl_1_data_43B8;
    Obj_1_bss_1148 *p_lbl_1_bss_1148;
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v4;
    u32 v5;
    u32 v6;
    s32 v7;
    u32 v8;
    p_lbl_1_data_43B8 = (Obj_1_data_43B8 *)&lbl_1_data_43B8;
    p_lbl_1_bss_1148 = (Obj_1_bss_1148 *)&lbl_1_bss_1148;
    v1 = 0;
    v3 = 0;
    if ((s32)p_lbl_1_data_43B8->unk_13C > 0) {
    v0 = (u32)&lbl_801A6410;
    p_lbl_1_data_43B8->unk_13C = -1;
    v0 = *(u32 *)((u8 *)v0 + 0);
    v1 = (u32)((u8 *)(u32)p_lbl_1_data_43B8 + 104);
    v2 = p_lbl_1_bss_1148->unk_67C;
    v3 = 1472;
    fn_1_46B4(v0, v2, (const char *)((u32)v1), v3);
    }
    v4 = v0;
    v5 = v1;
    v6 = v2;
    v7 = v3;
    if ((s32)p_lbl_1_data_43B8->unk_140 > 0) {
    v4 = (u32)&lbl_801A6410;
    p_lbl_1_data_43B8->unk_140 = -1;
    v4 = *(u32 *)((u8 *)v4 + 0);
    v5 = (u32)((u8 *)(u32)p_lbl_1_data_43B8 + 104);
    v6 = p_lbl_1_bss_1148->unk_680;
    v7 = 1473;
    fn_1_46B4(v4, v6, (const char *)((u32)v5), v7);
    }
    v8 = v4;
    if ((s32)p_lbl_1_data_43B8->unk_144 > 0) {
    v8 = (u32)&lbl_801A6410;
    p_lbl_1_data_43B8->unk_144 = -1;
    v8 = *(u32 *)((u8 *)v8 + 0);
    fn_1_46B4(v8, p_lbl_1_bss_1148->unk_684, (const char *)((u32)((u8 *)(u32)p_lbl_1_data_43B8 + 104)), 1474);
    }
}
/* fzgx:end fn_1_FA84 */

/* fzgx:begin fn_1_FB50 */
void fn_1_FB50(LiveCam_FB50 *cam) {
    if (cam->mode == 0) {
        cam->saved = cam->position;
        return;
    }
    if ((lbl_1_bss_F5C & 0x50000000) == 0) {
        f64 t0, t1, t2;
        t0 = lbl_1_rodata_580 * cam->offset.x;
        cam->velocity.x = cam->velocity.x - t0;
        t1 = lbl_1_rodata_580 * cam->offset.y;
        cam->velocity.y = cam->velocity.y - t1;
        t2 = lbl_1_rodata_580 * cam->offset.z;
        cam->velocity.z = cam->velocity.z - t2;
        cam->velocity.x = cam->velocity.x * lbl_1_rodata_588;
        cam->velocity.y = cam->velocity.y * lbl_1_rodata_588;
        cam->velocity.z = cam->velocity.z * lbl_1_rodata_588;
        cam->offset.x = cam->offset.x + cam->velocity.x;
        cam->offset.y = cam->offset.y + cam->velocity.y;
        cam->offset.z = cam->offset.z + cam->velocity.z;
    }
    {
        psvec_add(&cam->saved, &cam->offset, &cam->position);
    }
    if ((lbl_1_bss_F5C & 0x50000000) == 0) {
        if (cam->timer > 0) {
            cam->timer--;
            if (cam->timer == 0) {
                fn_1_8840();
            }
        }
    }
}
/* fzgx:end fn_1_FB50 */

/* fzgx:begin fn_1_FCB0 */
#define NEXT_RAND() (lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 13259)
#define RAND15(v) ((s32)(((v) >> 16) & 0x7FFF))

void fn_1_FCB0(arg0, arg1)
Sig_fn_1_101D0_Fn_1_101D0_State * arg0;
f32 arg1;
{
    s32 rnd;
    s16 prev14;
    u32 mask;
    s32 start;
    u8 kind;

    kind = arg0->unk_0;
    if (kind == 1 && (arg0->unk_C & 0x80000) != 0) {
        arg0->unk_12 = 4;
        if ((f64)(u32)arg0->unk_64 > 210.0) {
            arg0->unk_64 = 0;
        } else {
            arg0->unk_64 = 210;
        }
        return;
    }
    if (kind == 0) {
        if ((arg0->unk_C & 0x80000) == 0) {
            arg0->unk_12 = (s16)(RAND15(NEXT_RAND()) % 4);
            if ((s32)arg0->unk_12 == arg0->unk_2) {
                arg0->unk_12 = (s16)((arg0->unk_2 + 1) % 4);
            }
        } else {
            arg0->unk_12 = (s16)(RAND15(NEXT_RAND()) % 6);
            if ((s32)arg0->unk_12 >= 5) {
                arg0->unk_12 = 4;
            }
            if ((s32)arg0->unk_12 == arg0->unk_2) {
                if ((s32)arg0->unk_12 == 4) {
                    prev14 = arg0->unk_4;
                    fn_1_107B8(arg0);
                    if (prev14 == (s32)arg0->unk_14) {
                        arg0->unk_12 = (s16)((arg0->unk_2 + 1) % 5);
                    }
                } else {
                    arg0->unk_12 = (s16)((arg0->unk_2 + 1) % 5);
                }
            }
        }
    } else {
        arg0->unk_12 = (s16)(RAND15(NEXT_RAND()) % 6);
        if ((s32)arg0->unk_12 == arg0->unk_2) {
            arg0->unk_12 = (s16)((arg0->unk_2 + 1) % 6);
        }
        if ((s32)arg0->unk_12 == 5) {
            arg0->unk_12 = 4;
        }
        if ((s32)arg0->unk_12 == 4) {
            if ((arg0->unk_C & 0x80000) == 0) {
                arg0->unk_12 = 3;
            }
            if (arg0->unk_0 == 2) {
                arg0->unk_12 = (s16)((arg0->unk_2 + 1) % 3);
            }
        }
        if ((s8)camera_get_state() == 6) {
            if ((s32)arg0->unk_12 == 2) {
                arg0->unk_12 = (s16)(((s32)arg0->unk_12 + 1) % 3);
            }
        }
    }
    if ((f64)(u32)arg0->unk_64 > 210.0) {
        arg0->unk_64 = 0;
    } else {
        arg0->unk_64 = 210;
    }
    if ((s8)camera_get_state() == 6) {
        rnd = RAND15(NEXT_RAND());
        arg0->unk_6 = (s16)(rnd % (s32)(s8)fn_1_86624());
        if ((fn_1_864E8(arg0->unk_6) & 0x1) == 0) {
            mask = 0x8000880;
            if ((fn_1_864E8(arg0->unk_6) & mask) != 0) {
                start = arg0->unk_6;
                do {
                    arg0->unk_6++;
                    if ((s32)arg0->unk_6 >= (s32)(s8)fn_1_86624()) {
                        arg0->unk_6 = 0;
                    }
                    if ((s32)arg0->unk_6 < 0) {
                        arg0->unk_6 = (s8)fn_1_86624() - 1;
                    }
                } while ((fn_1_864E8(arg0->unk_6) & mask) != 0 && start != (s32)arg0->unk_6);
                if (start == (s32)arg0->unk_6) {
                    camera_set_selected_value(1);
                    camera_set_result(arg0->unk_6);
                    fn_1_5370(0, 0);
                    camera_set_result(arg0->unk_6);
                    camera_set_selected_value(0);
                    return;
                }
            }
        }
        arg0->unk_8 = arg0->unk_6;
    }
}
/* fzgx:end fn_1_FCB0 */

/* fzgx:begin fn_1_10138 */
void fn_1_10138(void) {
    Obj_1_bss_17C4_At0 *obj;
    u32 i;
    u32 count;

    lbl_1_bss_17B0 = 0;
    count = lbl_1_data_44F4.unk_0;
    obj = lbl_1_bss_17C4.unk_0;
    i = 0;
    while (i < count) {
        lbl_1_bss_17B0 += (u32)fn_80008E30(obj->unk_0);
        i++;
        obj++;
    }
}
/* fzgx:end fn_1_10138 */

/* fzgx:begin fn_1_101C0 */
u32 fn_1_101C0(void) {
    return lbl_1_bss_17B0;
}
/* fzgx:end fn_1_101C0 */

/* fzgx:begin fn_1_101D0 */
void fn_1_101D0(Fn_1_101D0_State *self) {
    Obj_1_bss_17C4_At0 *base;
    u32 count;
    u32 off;

    count = lbl_1_data_44F4.unk_0;
    base = lbl_1_bss_17C4.unk_0;

    if (self->unk_64 == 0) {
        self->unk_10++;
        off = self->unk_10 * 0x54;
        if (self->unk_10 < count) {
            self->unk_64 = (u32)fn_80008E30(*(u32 *)((u8 *)base + off));
            self->unk_12 = 5;
            self->unk_14 = self->unk_10;
            self->unk_6 = 0;
            self->unk_18 = 1;
        }
        return;
    }
    self->unk_18 = 0;
}
/* fzgx:end fn_1_101D0 */

/* fzgx:begin fn_1_10268 */
typedef struct {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
} Bss_1_17D0;

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    f32 unk_1C;
    s16 unk_20;
} Copy_1_10268;


void fn_1_10268(Camera_1_10268 *arg) {
    Obj_1_bss_17C4_At0 *e;
    Copy_1_10268 t;
    u32 n;
    u32 m;
    f32 a;
    f32 b;

    e = &lbl_1_bss_17C4.unk_0[arg->unk_4];
    t = *(Copy_1_10268 *)((u8 *)e + 8);

    n = (u32)fn_80008E30(e->unk_0);

    ((Bss_1_17D0 *)&lbl_1_bss_17D0)->unk_0 = lbl_1_rodata_4F4[0];
    ((Bss_1_17D0 *)&lbl_1_bss_17D0)->unk_4 = lbl_1_rodata_4E0[0];
    ((Bss_1_17D0 *)&lbl_1_bss_17D0)->unk_10 = lbl_1_rodata_4F4[0];
    ((Bss_1_17D0 *)&lbl_1_bss_17D0)->unk_14 = lbl_1_rodata_4E0[0] / (f32)((n * n) >> 2);
    a = (f32)n;
    ((Bss_1_17D0 *)&lbl_1_bss_17D0)->unk_C = a;
    ((Bss_1_17D0 *)&lbl_1_bss_17D0)->unk_8 = a;

    arg->unk_64 = (u32)fn_80008E30(e->unk_0);

    arg->unk_1C = t.unk_4;
    arg->unk_20 = t.unk_8;
    arg->unk_24 = t.unk_C;
    arg->unk_4C = t.unk_10;
    arg->unk_50 = t.unk_14;
    arg->unk_54 = t.unk_18;
    arg->unk_5C = t.unk_20;
    arg->unk_58 = t.unk_1C;
}
/* fzgx:end fn_1_10268 */

/* fzgx:begin fn_1_103B0 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0f;
    s = 300.0f;
    s = 320.0f;
    s = 234.0f;
    s = 230.0f;
    s = 0.0f;
    s = 0.5f;
    s = 2.0f;
    s = 0.009999999776482582f;
    s = 0.019999999552965164f;
}
static const u32 fzgx_pool_table2[4] = {0x0032FFFF, 0x000000FF, 0x000000FF, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.2;
    s = 0.6000000238418579f;
    s = 62.0f;
    s = 16.0f;
    s = 0.20000000298023224f;
    s = 3.0f;
    s = 940.0f;
    s = 650.0f;
    s = 36.0f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
    s = 9350.0f;
    s = 1800.0f;
    d = 210.0;
    s = 32.0f;
    s = 484.0f;
    s = 424.0f;
    s = 588.0f;
    s = 443.0f;
    s = 480.0f;
    s = 430.0f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.75;
    s = 1.8249999284744263f;
}
static const u32 fzgx_pool_table6[1] = {0x9999999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.0;
}
#pragma section code_type ".text"


/* one keyframe endpoint: position/target pair plus fov and roll */
typedef struct {
    u32 unk_0;
    fn_1_103B0_LiveCamVec pos;
    fn_1_103B0_LiveCamVec target;
    f32 fov;
    s16 roll;
    s16 pad_22;
} LiveCamFrame;

/* lbl_1_bss_17C4.unk_0 element, 0x54 bytes */
typedef struct {
    u32 duration;
    f32 rate;
    LiveCamFrame from;
    LiveCamFrame to;
    s16 mode;
    s16 pad_52;
} LiveCamKey;



void fn_1_103B0(LiveCamState *cam) {
    LiveCamKey *key;
    s32 count;
    s32 last;
    u32 raw;
    LiveCamFrame from;
    LiveCamFrame to;
    f32 t;

    raw = lbl_1_data_44F4.unk_0;
    key = &((LiveCamKey *)lbl_1_bss_17C4.unk_0)[cam->unk_4];
    if (cam->unk_0 == 3) {
        count = (s16)raw;
        if (fn_1_40BB4() == 0) {
            if ((lbl_1_bss_9F8.unk_A >> 1) & 1) {
                cam->unk_14++;
            }
            if (lbl_1_bss_9F8.unk_A & 1) {
                cam->unk_14--;
            }
            last = count - 1;
            if (cam->unk_14 > last) {
                cam->unk_14 = 0;
            }
            if (cam->unk_14 < 0) {
                cam->unk_14 = last;
            }
        }
    }
    if (cam->unk_64 != 0) {
        from = key->from;
        to = key->to;
        switch (key->mode) {
        case 0:
            t = 1.0 - (f32)cam->unk_64 / (f32)fn_80008E30(key->duration);
            lbl_8006D5A4(&from.pos, &to.pos, &cam->pos, t);
            lbl_8006D5A4(&from.target, &to.target, &cam->target, t);
            cam->fov = from.fov + (f32)(t * (to.fov - from.fov));
            cam->roll = from.roll + (s16)(s32)(t * (f32)(to.roll - from.roll));
            break;
        case 3:
            lbl_1_bss_17D0.unk_8 -= 1.0f;
            if (lbl_1_bss_17D0.unk_8 < lbl_1_bss_17D0.unk_C / 2.0f) {
                lbl_1_bss_17D0.unk_10 -= lbl_1_bss_17D0.unk_14;
            } else {
                lbl_1_bss_17D0.unk_10 += lbl_1_bss_17D0.unk_14;
            }
            t = (lbl_1_bss_17D0.unk_0 += lbl_1_bss_17D0.unk_10);
            lbl_8006D5A4(&from.pos, &to.pos, &cam->pos, t);
            lbl_8006D5A4(&from.target, &to.target, &cam->target, t);
            cam->fov = from.fov + (f32)(t * (to.fov - from.fov));
            cam->roll = from.roll + (s16)(s32)(t * (f32)(to.roll - from.roll));
            break;
        case 2:
            lbl_8006D5A4(&cam->pos, &to.pos, &cam->pos, key->rate);
            lbl_8006D5A4(&cam->target, &to.target, &cam->target, key->rate);
            cam->fov = cam->fov + (f32)(key->rate * (to.fov - cam->fov));
            cam->roll = cam->roll + (s32)(key->rate * (f32)(to.roll - cam->roll));
            break;
        }
    }
}
/* fzgx:end fn_1_103B0 */

/* fzgx:begin fn_1_107B8 pool noprologue */
typedef signed short s16;
typedef signed long s32;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef float f32;

 /* typedefs.json decl override */
/* lbl_1_bss_1148: .bss size 0x14, 9 refs from live_camera.c */
/* one view of the TU's .bss run from 0x1148: fn_1_E174 and fn_1_FA84 address it off one base */
typedef struct {
u8 unk_0;
u8 pad_1[0x7];
f32 unk_8;
f32 unk_C;
f32 unk_10;
u8 unk_14;
u8 pad_15[0xF];
f32 unk_24;
u8 pad_28[0x4];
s16 unk_2C;
s16 unk_2E;
u8 pad_30[0x5D8];
s16 unk_608;
u8 pad_60A[0x5A];
u8 unk_664;
u8 pad_665[0x17];
u32 unk_67C;
u32 unk_680;
u32 unk_684;
} Obj_1_bss_1148;

typedef struct {
f32 x;
f32 y;
f32 z;
} Vec3;
extern u32 lbl_801A63C0;
extern void fn_1_862D4(s16, Vec3 *);
extern void fn_1_862A8(s16, void *);
typedef struct {
u8 unk_0;
u8 pad_1;
s16 unk_2;
s16 unk_4;
s16 unk_6;
u16 unk_8;
u8 pad_A[0x2];
u32 unk_C;
u16 unk_10;
s16 unk_12;
s16 unk_14;
u8 pad_16[0x2];
u32 unk_18;
Vec3 pos; /* 0x1C */
u8 pad_28[0x24];
Vec3 target; /* 0x4C */
f32 unk_58;
s16 unk_5C;
u8 pad_5E[0x8];
u16 unk_66;
u8 pad_68[0x8];
Vec3 unk_70;
} Fn_1_107B8_Cam;
typedef struct {
u32 id; /* 0x00 */
Vec3 pos; /* 0x04 */
Vec3 target; /* 0x10 */
s16 unk_1C;
u8 pad_1E[2];
f32 unk_20;
u8 kind; /* 0x24 */
u8 pad_25[3];
} Fn_1_107B8_Entry;

typedef struct {
u8 pad_0[0x66C];
u8 unk_66C;
u8 pad_66D[0x3];
s32 unk_670;
u32 unk_674;
u8 pad_678[0x8];
Fn_1_107B8_Entry *unk_680;
Vec3 *unk_684;
f32 lim[6]; /* 0x688 */
f32 unk_6A0;
f32 unk_6A4;
} Fn_1_107B8_State;
struct fn_1_107B8_lbl_1_rodata_4E0 {
f32 unk_0;
u8 pad_4[0x10];
f32 unk_14;
u8 pad_18[0xA0];
f32 unk_B8;
f32 unk_BC;
};

static const u32 fzgx_pool_rodata_lbl_1_rodata_4E0[5] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3F800000, 0x43960000, 0x43A00000, 0x436A0000, 0x43660000
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_4F4[19] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0x3F000000, 0x40000000, 0x3C23D70A, 0x3CA3D70A, 0x32FFFF, 0xFF, 0xFF,
    0x0, 0x3FC99999, 0x9999999A, 0x3F19999A, 0x42780000, 0x41800000, 0x3E4CCCCD, 0x40400000,
    0x446B0000, 0x44228000, 0x42100000
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_540[22] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x43300000, 0x80000000, 0x43300000, 0x0, 0x46121800, 0x44E10000, 0x406A4000, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x42000000, 0x43F20000, 0x43D40000, 0x44130000, 0x43DD8000, 0x43F00000, 0x43D70000, 0x0,
    0x3FE80000, 0x0, 0x3FE99999, 0x9999999A, 0x3FF00000, 0x0
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_4E0_B8[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x38D1B717
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_4E0_BC[26] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x43480000, 0x0, 0x0, 0x0, 0x40E00000, 0x46FFFE00, 0x0, 0x0,
    0x0, 0x3FE00000, 0x0, 0x3FEC0000, 0x0, 0xBE000000, 0x41F00000, 0x3F947AE1,
    0x47AE147B, 0x40504000, 0x0, 0x3FA99999, 0x9999999A, 0x40240000, 0x0, 0x40100000,
    0x0, 0x40800000
};
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_1_rodata_4E0(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .data objects in retail order */
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_4E0;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_4F4;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_540;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_4E0_B8;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_4E0_BC;
}
#pragma section code_type ".text"

extern u8 fn_1_10268__fzgx_offset_0[];
extern u8 fn_1_103B0__fzgx_offset_0[];
extern u8 fn_1_107B8__fzgx_offset_0[];
extern u8 fn_1_10AF0__fzgx_offset_0[];
extern u8 fn_1_1138C__fzgx_offset_0[];
extern u8 fn_1_11544__fzgx_offset_0[];
extern u8 fn_1_11748__fzgx_offset_0[];
extern u8 fn_1_1189C__fzgx_offset_0[];
extern u8 fn_1_11ABC__fzgx_offset_0[];
extern u8 fn_1_11C08__fzgx_offset_0[];
extern u8 fn_1_11E98__fzgx_offset_0[];
extern u8 fn_1_1212C__fzgx_offset_0[];
extern u8 fn_1_DA34__fzgx_offset_0[];
extern u8 lbl_1_data_43B8__fzgx_offset_0[];
extern u8 lbl_1_data_43C4__fzgx_offset_0[];
extern u8 lbl_1_data_43CC__fzgx_offset_0[];
extern u8 lbl_1_data_43D8__fzgx_offset_0[];
extern u8 lbl_1_data_43E0__fzgx_offset_0[];
extern u8 lbl_1_data_43EC__fzgx_offset_0[];
extern u8 lbl_1_data_43F4__fzgx_offset_0[];
extern u8 lbl_1_data_43FC__fzgx_offset_0[];
static u32 fzgx_pool_native_lbl_1_data_43B8_gap_0[78] = {0x4F564552, 0x54414B45, 0x00000000, 0x4A554D50, 0x00000000, 0x454E454D, 0x59484954, 0x00000000, 0x57414C4C, 0x48495400, 0x53494445, 0x42595349, 0x44450000, 0x53544152, 0x54000000, 0x474F414C, 0x00000000, 0x4C415000, (u32)lbl_1_data_43B8__fzgx_offset_0, (u32)lbl_1_data_43C4__fzgx_offset_0, (u32)lbl_1_data_43CC__fzgx_offset_0, (u32)lbl_1_data_43D8__fzgx_offset_0, (u32)lbl_1_data_43E0__fzgx_offset_0, (u32)lbl_1_data_43EC__fzgx_offset_0, (u32)lbl_1_data_43F4__fzgx_offset_0, (u32)lbl_1_data_43FC__fzgx_offset_0, 0x6C697665, 0x5F63616D, 0x6572612E, 0x63000000, 0x6C697665, 0x63616D20, 0x6572726F, 0x720A0000, (u32)fn_1_1138C__fzgx_offset_0, (u32)fn_1_11748__fzgx_offset_0, (u32)fn_1_11ABC__fzgx_offset_0, (u32)fn_1_11E98__fzgx_offset_0, (u32)fn_1_107B8__fzgx_offset_0, (u32)fn_1_10268__fzgx_offset_0, (u32)fn_1_DA34__fzgx_offset_0, (u32)fn_1_11544__fzgx_offset_0, (u32)fn_1_1189C__fzgx_offset_0, (u32)fn_1_11C08__fzgx_offset_0, (u32)fn_1_1212C__fzgx_offset_0, (u32)fn_1_10AF0__fzgx_offset_0, (u32)fn_1_103B0__fzgx_offset_0, (u32)fn_1_DA34__fzgx_offset_0, 0x00110000, 0x000C1100, 0x000C1100, 0x00010000, 0x00000001, 0x00000003, 0x00000005, 0x00000007, 0x00000008, 0x00000009, 0x0000000A, 0x0000000B, 0x0000000D, 0x0000000E, 0x0000000F, 0x00000010, 0x00000011, 0x00000015, 0x00000018, 0x00000019, 0x0000001A, 0x0000001B, 0x0000001C, 0x0000001D, 0x0000001F, 0x00000020, 0x00000021, 0x00000022, 0x00000023, 0x00000024}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u32 fzgx_pool_native_lbl_1_data_43B8_unk_138 = 0x00000001; /* fzgx-allow: A1 measured pool bytes and bindings */
static u32 fzgx_pool_native_lbl_1_data_43B8_gap_13C[1] = {0xFFFFFFFF}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u32 fzgx_pool_native_lbl_1_data_43B8_unk_140 = 0xFFFFFFFF; /* fzgx-allow: A1 measured pool bytes and bindings */
static u32 fzgx_pool_native_lbl_1_data_43B8_unk_144 = 0xFFFFFFFF; /* fzgx-allow: A1 measured pool bytes and bindings */
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_1148[5];
u8 fzgx_obj_lbl_1_bss_115C;
u8 lbl_1_bss_1148_gap_115D;
u16 lbl_1_bss_1148_gap_115D_fill_115E;
u32 lbl_1_bss_1160[403];
u8 fzgx_obj_lbl_1_bss_17AC;
u8 lbl_1_bss_1148_gap_17AD;
u16 lbl_1_bss_1148_gap_17AD_fill_17AE;
u32 fzgx_obj_lbl_1_bss_17B0;
u8 lbl_1_bss_17B4;
u8 lbl_1_bss_17B4_fill_17B5;
u16 lbl_1_bss_17B4_fill_17B6;
s32 lbl_1_bss_17B4_4;
u32 lbl_1_bss_17B4_8;
u8 lbl_1_bss_17C0;
u8 lbl_1_bss_1148_gap_17C1;
u16 lbl_1_bss_1148_gap_17C1_fill_17C2;
u32 fzgx_obj_lbl_1_bss_17C4;
Fn_1_107B8_Entry *lbl_1_bss_17C4_4;
Vec3 *lbl_1_bss_17C4_8;
f32 fzgx_obj_lbl_1_bss_17D0[6];
f32 lbl_1_bss_17D0_18;
f32 lbl_1_bss_17D0_1C;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_1148;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_115C;
    s = *(u8 *)&lbl_1_bss_1148_gap_115D;
    s = *(u8 *)&lbl_1_bss_1148_gap_115D_fill_115E;
    s = *(u8 *)&lbl_1_bss_1160;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_17AC;
    s = *(u8 *)&lbl_1_bss_1148_gap_17AD;
    s = *(u8 *)&lbl_1_bss_1148_gap_17AD_fill_17AE;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_17B0;
    s = *(u8 *)&lbl_1_bss_17B4;
    s = *(u8 *)&lbl_1_bss_17B4_fill_17B5;
    s = *(u8 *)&lbl_1_bss_17B4_fill_17B6;
    s = *(u8 *)&lbl_1_bss_17B4_4;
    s = *(u8 *)&lbl_1_bss_17B4_8;
    s = *(u8 *)&lbl_1_bss_17C0;
    s = *(u8 *)&lbl_1_bss_1148_gap_17C1;
    s = *(u8 *)&lbl_1_bss_1148_gap_17C1_fill_17C2;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_17C4;
    s = *(u8 *)&lbl_1_bss_17C4_4;
    s = *(u8 *)&lbl_1_bss_17C4_8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_17D0;
    s = *(u8 *)&lbl_1_bss_17D0_18;
    s = *(u8 *)&lbl_1_bss_17D0_1C;
}
#pragma section code_type ".text"

#pragma opt_propagation off
static inline void fn_1_107B8_select(Fn_1_107B8_Entry **entries, u32 count, s32 *bestIdx, u32 **lp, u32 *list) {
u32 j;
u8 none;
u32 m;
*lp = list;
m = 0;
none = 1;
j = 0;
for (; j < count; (*entries)++, j++) {
if (*bestIdx == (*entries)->id) {
**lp = j;
none = 0;
(*lp)++;
m++;
}
}
if (none) {
lbl_1_bss_17B4_8 = 0;
} else {
count = list[((u32)((((lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 13259)) >> 16) & 0x7FFF)) % m];
lbl_1_bss_17B4_8 = count;
}
return;
}
#pragma opt_propagation reset
#pragma inline_max_size(4096)
#pragma opt_propagation off
void fn_1_107B8(Fn_1_107B8_Cam *arg0) {
u8 none;
Fn_1_107B8_Cam *cam = arg0;
struct { u32 value; } count;
u32 n;
Vec3 *pts;
Fn_1_107B8_Entry *entry;
u8 kind;
u32 i;
Fn_1_107B8_Entry *entries;
u32 j;
Vec3 *p;
s32 bestIdx;
u32 *lp;
u32 m;
s32 changed;
f32 best;
f32 d;
f32 dz, dy, dx;
f32 big, eps, one, zero;
u32 list[21];
Vec3 loc_20;
Vec3 loc_14;
Vec3 loc_8;
fzgx_pool_native_lbl_1_data_43B8_unk_138 = 1;
kind = cam->unk_0;
entries = lbl_1_bss_17C4_4;
entry = &entries[cam->unk_4];
if (kind == 5 || kind <= 1 || kind == 2) {
count.value = fzgx_pool_native_lbl_1_data_43B8_unk_140;
fn_1_862D4(cam->unk_6, &loc_14);
n = fzgx_pool_native_lbl_1_data_43B8_unk_144;
pts = lbl_1_bss_17C4_8;
fn_1_862D4(cam->unk_6, &loc_8);
dz = pts[0].z;
dy = pts[0].y;
dx = pts[0].x;
dz -= loc_8.z;
dy -= loc_8.y;
dx -= loc_8.x;
best = dx * dx;
best += dy * dy;
best += dz * dz;
bestIdx = 0;
for (i = 1, p = pts + 1; i < n; p++, i++) {
dz = p->z;
dy = p->y;
dx = p->x;
dz -= loc_8.z;
dy -= loc_8.y;
dx -= loc_8.x;
d = dx * dx;
d += dy * dy;
d += dz * dz;
if (!(best < d)) {
best = d;
bestIdx = i;
}
}
changed = 0;
if (lbl_1_bss_17B4_4 != bestIdx) {
lbl_1_bss_17B4_4 = bestIdx;
changed = 1;
}
if (changed) {
fn_1_107B8_select(&entries, count.value, &bestIdx, &lp, list);
cam->unk_18 = 1;
}
cam->unk_14 = lbl_1_bss_17B4_8;
cam->unk_C |= 0x200000;
}
fn_1_862D4(cam->unk_6, &loc_20);
fn_1_862A8(cam->unk_6, &cam->unk_70);
cam->pos = entry->pos;
if (entry->kind == 3) {
cam->target = entry->target;
} else {
cam->target = loc_20;
}
lbl_1_bss_17B4 = entry->kind;
cam->unk_5C = entry->unk_1C;
cam->unk_58 = entry->unk_20;
dz = cam->pos.z;
dy = cam->pos.y;
dx = cam->pos.x;
dz -= loc_20.z;
dy -= loc_20.y;
dx -= loc_20.x;
d = dx * dx;
d += dy * dy;
d += dz * dz;
lbl_1_bss_17D0_18 = d;
lbl_1_bss_17D0_1C = d;
switch (entry->kind) {
case 1:
case 2:
case 5:
cam->unk_66 = 180;
break;
case 4:
cam->unk_66 = 200;
zero = (*(f32 *)(((u8 *)fzgx_pool_rodata_lbl_1_rodata_4F4)));
one = (*(f32 *)(((u8 *)fzgx_pool_rodata_lbl_1_rodata_4E0)));
eps = (*(f32 *)(((u8 *)fzgx_pool_rodata_lbl_1_rodata_4E0_B8)));
big = (*(f32 *)(((u8 *)fzgx_pool_rodata_lbl_1_rodata_4E0_BC)));
fzgx_obj_lbl_1_bss_17D0[0] = zero;
fzgx_obj_lbl_1_bss_17D0[1] = one;
fzgx_obj_lbl_1_bss_17D0[4] = zero;
fzgx_obj_lbl_1_bss_17D0[5] = eps;
fzgx_obj_lbl_1_bss_17D0[3] = big;
fzgx_obj_lbl_1_bss_17D0[2] = big;
break;
default:
cam->unk_66 = 120;
break;
}
    return;
}
#pragma opt_propagation reset
/* fzgx:end fn_1_107B8 */

/* fzgx:begin fn_1_1138C */
#pragma opt_propagation off
static inline void fn_1_1138C_read_pointer(Cam *c, Obj_1_data_4754 *base, s32 index)
{
    Obj_1_data_4754 *entry = (Obj_1_data_4754 *)((u8 *)base + (index << 4));
    c->unk_5C = entry->unk_C;
    c->unk_58 = lbl_1_rodata_608[0];
}
#pragma opt_strength_reduction on
void fn_1_1138C(Cam *c)
{
    V3 b;
    V3 a;
    u32 r;
    u32 state;
    struct { f32 value; } t;

    if (c->type == 5 || c->type <= 1 || c->type == 2) {
        state = lbl_801A63C0 * 0x676a4b6b + 0x33cb;
        lbl_801A63C0 = state;
        r = (state >> 16) & 0x7fff;
        c->unk_14 = r % 6;
        c->unk_4 = r % 6;
    }
    fn_1_8636C(c->unk_6, c->unk_7C);
    fn_1_862D4(c->unk_6, (Vec3 *)(V3 *)(&a));
    lbl_8006DC6C(c->unk_7C);
    {
        f32 az;
        f32 ay;
        f32 ax;
        /* Read the translation column before updating locked cache. */
        ax = *(volatile f32 *)&a.x;
        ay = a.y;
        az = a.z;
        *(f32 *)(0xE000000C) = ax;
        *(f32 *)(0xE000001C) = ay;
        *(f32 *)(0xE000002C) = az;
    }
    lbl_8006E1B0((u8 *)&lbl_1_data_4754 + c->unk_4 * 16, c->unk_1C);
    c->unk_4C = a;
    fn_1_862A8(c->unk_6, &b);
    t.value = (f32)lbl_1_data_4484.unk_0;
    c->unk_70 = c->unk_70 + (f32)(t.value * (f32)(lbl_1_rodata_604 * (b.x - c->unk_70)));
    c->unk_74 = c->unk_74 + (f32)(t.value * (f32)(lbl_1_rodata_604 * (b.y - c->unk_74)));
    c->unk_78 = c->unk_78 + (f32)(t.value * (f32)(lbl_1_rodata_604 * (b.z - c->unk_78)));
    {
        Obj_1_data_4754 *base = &lbl_1_data_4754;
        fn_1_1138C_read_pointer(c, base, c->unk_4);
    }
}
#pragma opt_strength_reduction reset
/* fzgx:end fn_1_1138C */

/* fzgx:begin fn_1_11544 */
typedef struct {
    u8 pad_0[0xA];
    u16 unk_A;
} LiveCamInput;

typedef struct {
    u8 pad_0[0x10];
} LiveCamEntry;



/* Translation column of the current matrix in the locked cache. Like psvec_set, the
   components are passed z, y, x: the arguments are all loaded before the stores and
   MWCC numbers the first parameter highest, which is the register order retail has. */
static inline void LiveCam_SetCurMtxTrans(const volatile fn_1_11544_LiveCamVec *v) { /* volatile: pins the three loads in source order ahead of the stores, retail's register order (x f2, y f1, z f0) */
    f32 x = v->x;
    f32 y = v->y;
    f32 z = v->z;
    *(f32 *)(0xE0000000 + 0x0C) = x;
    *(f32 *)(0xE0000000 + 0x1C) = y;
    *(f32 *)(0xE0000000 + 0x2C) = z;
}

void fn_1_11544(fn_1_11544_LiveCamera *cam) {
    LiveCamMtx mtx;
    fn_1_11544_LiveCamVec eye;
    fn_1_11544_LiveCamVec at;
    fn_1_11544_LiveCamVec pos;
    fn_1_11544_LiveCamVec out;
    u32 handle;
    u32 info;
    f32 rate;
    f32 cx, cy, cz;

    if (cam->unk_0 == 3 && fn_1_40BB4() == 0) {
        if (((*((LiveCamInput *)&lbl_1_bss_9F8)).unk_A >> 1) & 1) {
            cam->unk_14++;
        }
        if ((*((LiveCamInput *)&lbl_1_bss_9F8)).unk_A & 1) {
            cam->unk_14--;
        }
        if (cam->unk_14 > 5) {
            cam->unk_14 = 0;
        }
        if (cam->unk_14 < 0) {
            cam->unk_14 = 5;
        }
    }

    fn_1_862D4( (s32)(cam->unk_6), (Vec3 *)(fn_1_11544_LiveCamVec *)(&eye));
    fn_1_8636C(cam->unk_6, (void *)(LiveCamMtx *)(&mtx));
    fn_1_862A8( (s16)((s32)(cam->unk_6)), (V3 *)((void *)(fn_1_11544_LiveCamVec *)(&at)));
    lbl_8006DC6C( (void *)(LiveCamMtx *)(&mtx));

    LiveCam_SetCurMtxTrans(&eye);

    lbl_8006E1B0((u8 *)&(*((LiveCamEntry *)&lbl_1_data_4754)) + (cam->unk_4 << 4), cam->unk_1C);

    cam->pos = eye;

    rate = (f32)(*((s16 *)&lbl_1_data_4484));
    cx = cam->target.x;
    cam->target.x = cx + (f32)(rate * (0.05f * (at.x - cx)));
    cy = cam->target.y;
    cam->target.y = cy + (f32)(rate * (0.05f * (at.y - cy)));
    cz = cam->target.z;
    cam->target.z = cz + (f32)(rate * (0.05f * (at.z - cz)));

    lbl_8006DAEC();
    handle = fn_1_20A5C(cam->unk_1C, &info);
    pos = cam->pos;
    fn_1_15578(cam->unk_1C, &pos, &info, &out, 0x40005, &handle, 1, 0, 0, 0);
    lbl_8006DB30();
}
/* fzgx:end fn_1_11544 */

/* fzgx:begin fn_1_11748 noprologue */
#include "types.h"

typedef struct {
    f32 x, y, z;
} V3;

#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[5] = {0x3F800000, 0x43960000, 0x43A00000, 0x436A0000, 0x43660000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s;  /* fzgx-allow: S2 pool primer sink */
    s = 0.0f;
}
static const u32 fzgx_pool_table3[68] = {0x3F000000, 0x40000000, 0x3C23D70A, 0x3CA3D70A, 0x0032FFFF, 0x000000FF, 0x000000FF, 0x00000000, 0x3FC99999, 0x9999999A, 0x3F19999A, 0x42780000, 0x41800000, 0x3E4CCCCD, 0x40400000, 0x446B0000, 0x44228000, 0x42100000, 0x43300000, 0x80000000, 0x43300000, 0x00000000, 0x46121800, 0x44E10000, 0x406A4000, 0x00000000, 0x42000000, 0x43F20000, 0x43D40000, 0x44130000, 0x43DD8000, 0x43F00000, 0x43D70000, 0x00000000, 0x3FE80000, 0x00000000, 0x3FE99999, 0x9999999A, 0x3FF00000, 0x00000000, 0x38D1B717, 0x43480000, 0x00000000, 0x00000000, 0x00000000, 0x40E00000, 0x46FFFE00, 0x00000000, 0x00000000, 0x00000000, 0x3FE00000, 0x00000000, 0x3FEC0000, 0x00000000, 0xBE000000, 0x41F00000, 0x3F947AE1, 0x47AE147B, 0x40504000, 0x00000000, 0x3FA99999, 0x9999999A, 0x40240000, 0x00000000, 0x40100000, 0x00000000, 0x40800000, 0x3D4CCCCD};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s;  /* fzgx-allow: S2 pool primer sink */
    s = 55.0f;
}
static const u32 fzgx_pool_table5[9] = {0x00000000, 0x40310000, 0x00000000, 0xBFF00000, 0x00000000, 0x3ECCCCCD, 0x00000000, 0x3FD99999, 0x9999999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

typedef struct {
    u8 pad_0[0x1C];
    s32 unk_1C;
} Entry;

typedef struct {
    u8 unk_0;
    u8 pad_1[3];
    s16 unk_4;
    s16 unk_6;
    u8 pad_8[0xC];
    s16 unk_14;
    u8 pad_16[6];
    u8 unk_1C[0x18];
    V3 unk_34;
    u8 pad_40[0x18];
    f32 unk_58;
    u8 pad_5C[0xC];
    s16 unk_68;
    u8 pad_6A[4];
    s16 unk_6E;
    V3 unk_70;
    u8 unk_7C[0x40];
} Cam;

extern f32 lbl_1_bss_17F0;
extern f32 lbl_1_bss_17F4;
extern u32 lbl_801A63C0;
extern Entry lbl_1_data_47B4[];
extern void fn_1_862A8(int, V3 *);
extern void fn_1_8636C(int, void *);
extern void fn_1_862D4(int, V3 *);
extern void fn_1_8645C(int, void *);
extern void lbl_8006DBAC(void *);
extern void lbl_8006E1B0(void *, void *);

void fn_1_11748(Cam *c)
{
    V3 pos;
    u32 state;
    u32 r;

    if (c->unk_0 == 5 || c->unk_0 <= 1 || c->unk_0 == 2) {
        state = lbl_801A63C0 * 0x676a4b6b + 0x33cb;
        lbl_801A63C0 = state;
        r = (state >> 16) & 0x7fff;
        c->unk_14 = r % 20;
        c->unk_4 = r % 20;
    }
    c->unk_68 = 2;
    {
        V3 v = {0.0f, 0.0f, 0.0f};

        c->unk_34 = v;
    }
    c->unk_6E = 0;
    lbl_1_bss_17F0 = 0.0f;
    lbl_1_bss_17F4 = 0.0f;
    fn_1_862A8(c->unk_6, &c->unk_70);
    fn_1_8636C(c->unk_6, c->unk_7C);
    c->unk_58 = 55.0f;
    fn_1_862D4(c->unk_6, &pos);
    if (lbl_1_data_47B4[c->unk_4].unk_1C != 0) {
        fn_1_8645C(c->unk_6, c->unk_7C);
        lbl_8006DBAC(c->unk_7C);
        lbl_8006E1B0(&lbl_1_data_47B4[c->unk_4], c->unk_1C);
    }
}
/* fzgx:end fn_1_11748 */

/* fzgx:begin fn_1_1189C noprologue */
#include "types.h"

typedef struct {
    f32 x, y, z;
} LcVec;

typedef struct {
    f32 m[3][4];
} LcMtx;

typedef struct {
    u8 mode;
    u8 pad_1[3];
    s16 unk_4;
    s16 unk_6;
    u8 pad_8[0xC];
    s16 unk_14;
    u8 pad_16[6];
    LcVec unk_1C;
    u8 pad_28[0x24];
    LcVec unk_4C;
    u8 pad_58[4];
    s16 unk_5C;
    u8 pad_5E[0x12];
    f32 unk_70;
    f32 unk_74;
    u8 pad_78[4];
    LcMtx unk_7C;
} LcState;

typedef struct {
    LcVec a;
    LcVec b;
    s16 unk_18;
    u8 pad_1A[2];
    s32 unk_1C;
} LcEntry;

typedef struct {
    u8 pad_0[0xA];
    u16 unk_A;
} LcInput;

typedef struct {
    f32 unk_0;
    u8 pad_4[0x10];
    f32 unk_14;
    u8 pad_18[0x34];
    f32 unk_4C;
} LcPool;

extern LcPool lbl_1_rodata_4E0;
extern LcInput lbl_1_bss_9F8;
extern LcEntry lbl_1_data_47B4[];

extern s32 fn_1_40BB4(void);
extern void fn_1_862D4(int, LcVec *);
extern void fn_1_8645C(int, void *);
extern void fn_1_8636C(int, void *);
extern u32 fn_1_20A5C(void *, void *);
extern void fn_1_15578(void *, LcVec *, void *, void *, u32, void *, u32, u32, u32, u32);
extern void lbl_8006DBAC(void *);
extern void lbl_8006DB74(LcMtx *);
extern void fn_8006FA24(LcMtx *, void *, LcMtx *, f32);
extern void lbl_8006DC6C(LcMtx *);
extern void lbl_8006E1B0(LcVec *, LcVec *);
extern void lbl_8006E1F0(f32 *, f32, f32, f32);
extern s32 lbl_8006D24C(f32, f32);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);

static inline f32 fn_1_1189C_read_pointer(LcVec * owner) { return owner->z; }
#pragma opt_propagation off
void fn_1_1189C(LcState *state) {
    LcPool *pool;
    LcMtx mtx;
    LcVec pos;
    LcVec target;
    u32 buf18[3];
    u32 id;
    u32 buf10;
    f32 v;
    f32 y, z, x;

    pool = &lbl_1_rodata_4E0;
    if (state->mode == 3 && fn_1_40BB4() == 0) {
        if ((lbl_1_bss_9F8.unk_A >> 1) & 1) {
            state->unk_14++;
        }
        if (lbl_1_bss_9F8.unk_A & 1) {
            state->unk_14--;
        }
        if (state->unk_14 > 19) {
            state->unk_14 = 0;
        }
        if (state->unk_14 < 0) {
            state->unk_14 = 19;
        }
    }
    fn_1_862D4(state->unk_6, &pos);
    if (lbl_1_data_47B4[state->unk_4].unk_1C != 0) {
        fn_1_8645C(state->unk_6, &mtx);
        lbl_8006DBAC(&mtx);
        lbl_8006DB74(&state->unk_7C);
    } else {
        fn_1_8636C(state->unk_6, &mtx);
        fn_8006FA24(&state->unk_7C, &mtx, &state->unk_7C, pool->unk_4C);
        lbl_8006DC6C(&state->unk_7C);
        x = pos.x;
        y = pos.y;
        z = fn_1_1189C_read_pointer(&pos);
        *(f32 *)(0xE0000000 + 0x0C) = x;
        *(f32 *)(0xE0000000 + 0x1C) = y;
        *(f32 *)(0xE0000000 + 0x2C) = z;
    }
    lbl_8006E1B0(&lbl_1_data_47B4[state->unk_4].a, &state->unk_1C);
    lbl_8006E1B0(&lbl_1_data_47B4[state->unk_4].b, &state->unk_4C);
    v = pool->unk_14;
    lbl_8006E1F0(&state->unk_70, v, pool->unk_0, v);
    state->unk_5C = lbl_1_data_47B4[state->unk_4].unk_18 - lbl_8006D24C(state->unk_70, state->unk_74);
    lbl_8006DAEC();
    id = fn_1_20A5C(&state->unk_1C, &buf10);
    target = state->unk_4C;
    fn_1_15578(&state->unk_1C, &target, &buf10, buf18, 0x40005, &id, 1, 0, 0, 0);
    lbl_8006DB30();
}
#pragma opt_propagation reset
/* fzgx:end fn_1_1189C */

/* fzgx:begin fn_1_11ABC */
typedef struct {
    Vec3 v;              /* 0x00 */
    u8 pad_C[0x14];
} CameraData;            /* 32 bytes */



#pragma opt_propagation off
void fn_1_11ABC(fn_1_11ABC_LiveCamera *camera) {
    Vec3 first;
    Vec3 second;
    u8 mode = camera->unk_0;

    if (mode == 5 || mode <= 1 || mode == 2) {
        u32 value;
        u32 next = lbl_801A63C0 * 0x676A4B6Bu + 0x33CB;
        s16 result;

        value = (next << 1) >> 17;
        result = (s16)(value % 9);
        lbl_801A63C0 = next;
        camera->unk_14 = result;
        camera->unk_4 = result;
    }

    fn_1_862D4(camera->unk_6, &first);
    fn_1_8636C(camera->unk_6, &camera->unk_7C);
    fn_1_862A8(camera->unk_6, (V3 *)(void *)(&camera->unk_70));

    camera->unk_34 = (*(CameraData (*)[])&lbl_1_data_4AA0)[camera->unk_4].v;

    {
        f32 m2, m1, m0;
        f32 *mtx = (f32 *)(LC_BASE + 0x0);
        m0 = first.x;
        m1 = first.y;
        m2 = first.z;
        mtx[3] = m0;
        mtx[7] = m1;
        mtx[11] = m2;
    }

    lbl_8006DC6C(&camera->unk_7C);
    lbl_8006E1B0(&camera->unk_34, &camera->unk_1C);
    fn_8006E2B0(&camera->unk_70, &second);

    camera->unk_4C = first;
    camera->unk_5C = (s16)-lbl_8006D24C(second.x, second.y);
    camera->unk_58 = 55.0f;
}
#pragma opt_propagation reset
/* fzgx:end fn_1_11ABC */

/* fzgx:begin fn_1_11E98 */
typedef void (*Cam11E98Handler)(Cam11E98 *, void *);


static inline f32 fn_1_11E98_dist2(Cam11E98Vec *a, Cam11E98Vec *b) {
    f32 x = a->x;
    f32 y = a->y;
    f32 z = a->z;
    x -= b->x;
    y -= b->y;
    z -= b->z;
    x *= x;
    x += y * y;
    x += z * z;
    return x;
}

// Write a translation into the current (locked-cache) matrix.
static inline void fn_1_11E98_set_trans(f32 x, f32 y, f32 z) {
    *(f32 *)(0xE0000000 + 0x0C) = x;
    *(f32 *)(0xE0000000 + 0x1C) = y;
    *(f32 *)(0xE0000000 + 0x2C) = z;
}

// Pick the camera point nearest to the current target point and aim the camera from it.
#pragma opt_propagation off
void fn_1_11E98(Cam11E98 *cam) {
    u8 mtx[0x30];
    Cam11E98Vec target;
    Cam11E98Vec point;
    Cam11E98Vec up;
    f32 best;
    f32 dist;
    f32 dx, dy, dz;
    u32 i;

    if ((s8)fn_1_86624() == 1) {
        fn_1_FCB0(cam);
    }
    if (cam->state == 5 || cam->state <= 1 || cam->state == 2) {
        lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
        cam->unk_4 = cam->unk_14 = (s32)((lbl_801A63C0 >> 16) & 0x7FFF) % 2;
    }
    fn_1_862D4(cam->unk_6, (Vec3 *)(Cam11E98Vec *)(&target));
    if (cam->unk_6 == (s32)lbl_1_bss_17F8) {
        lbl_1_bss_17F8 = (s32)(lbl_1_bss_17F8 + 1) % (s8)fn_1_86624();
    }
    fn_1_862D4(lbl_1_bss_17F8, (Vec3 *)(Cam11E98Vec *)(&point));
    best = fn_1_11E98_dist2(&point, &target);
    for (i = 0; i < (s8)fn_1_86624(); i++) {
        if (i != cam->unk_6) {
            fn_1_862D4(i, (Vec3 *)(Cam11E98Vec *)(&point));
            dist = fn_1_11E98_dist2(&point, &target);
            if (!(best < dist)) {
                best = dist;
                lbl_1_bss_17F8 = i;
            }
        }
    }
    if (best > 5000.0f) {
        cam->unk_12 = 0;
        cam->unk_18 = 1;
        ((Cam11E98Handler *)lbl_1_data_4440)[cam->unk_12](cam, lbl_1_data_4440);
        return;
    }
    fn_1_8636C(lbl_1_bss_17F8, mtx);
    lbl_8006DD14(mtx, cam->unk_7C);
    fn_1_862D4(lbl_1_bss_17F8, (Vec3 *)(Cam11E98Vec *)(&point));
    lbl_8006DC6C(mtx);
    {
        {
            f32 fzgx_lc0_z;
            f32 fzgx_lc0_y;
            f32 fzgx_lc0_x;
            fzgx_lc0_x = (point.x);
            fzgx_lc0_y = (point.y);
            fzgx_lc0_z = (point.z);
            *(f32 *)(0xE0000000 + 0x0C) = fzgx_lc0_x;
            *(f32 *)(0xE0000000 + 0x1C) = fzgx_lc0_y;
            *(f32 *)(0xE0000000 + 0x2C) = fzgx_lc0_z;
        }
    }
    up = lbl_1_rodata_63C;
    lbl_8006E1B0( (void *)(Cam11E98Vec *)(&up), (void *)(Cam11E98Vec *)(&cam->pos));
    cam->unk_4C = target;
}
#pragma opt_propagation reset
/* fzgx:end fn_1_11E98 */

/* fzgx:begin fn_1_1212C */
/* Primes the TU's shared literal pool (lbl_1_rodata_4E0) up to this function's own literals. */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0f;
    s = 300.0f;
    s = 320.0f;
    s = 234.0f;
    s = 230.0f;
    s = 0.0f;
    s = 0.5f;
    s = 2.0f;
    s = 0.009999999776482582f;
    s = 0.019999999552965164f;
}
static const u32 fzgx_pool_table2[4] = {0x0032FFFF, 0x000000FF, 0x000000FF, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.2;
    s = 0.6000000238418579f;
    s = 62.0f;
    s = 16.0f;
    s = 0.20000000298023224f;
    s = 3.0f;
    s = 940.0f;
    s = 650.0f;
    s = 36.0f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
    s = 9350.0f;
    s = 1800.0f;
    d = 210.0;
    s = 32.0f;
    s = 484.0f;
    s = 424.0f;
    s = 588.0f;
    s = 443.0f;
    s = 480.0f;
    s = 430.0f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.75;
    d = 0.8;
    d = 1.0;
}
static const u32 fzgx_pool_table6[7] = {0x38D1B717, 0x43480000, 0x00000000, 0x00000000, 0x00000000, 0x40E00000, 0x46FFFE00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 0.5;
}
static const u32 fzgx_pool_table8[16] = {0x3FEC0000, 0x00000000, 0xBE000000, 0x41F00000, 0x3F947AE1, 0x47AE147B, 0x40504000, 0x00000000, 0x3FA99999, 0x9999999A, 0x40240000, 0x00000000, 0x40100000, 0x00000000, 0x40800000, 0x3D4CCCCD};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 55.0f;
}
static const u32 fzgx_pool_table10[15] = {0x00000000, 0x40310000, 0x00000000, 0xBFF00000, 0x00000000, 0x3ECCCCCD, 0x00000000, 0x3FD99999, 0x9999999A, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3FC00000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 5000.0f;
}
#pragma section code_type ".text"




/* Translation column of the current matrix in the locked cache. */
static inline void Lc1212C_SetCurMtxTrans(const volatile Lc1212CVec *v) {
    f32 x = v->x;
    f32 y = v->y;
    f32 z = v->z;
    *(f32 *)(0xE0000000 + 0x0C) = x;
    *(f32 *)(0xE0000000 + 0x1C) = y;
    *(f32 *)(0xE0000000 + 0x2C) = z;
}

/* Squared distance between two points. */
static inline f32 Lc1212C_Dist2(Lc1212CVec *a, Lc1212CVec *b) {
    f32 x = a->x;
    f32 y = a->y;
    f32 z = a->z;
    x -= b->x;
    y -= b->y;
    z -= b->z;
    {
        f32 d = x * x;
        d += y * y;
        d += z * z;
        return d;
    }
}

/* Move dst a frame-scaled step toward src. */
static inline void Lc1212C_Follow(Lc1212CVec *dst, Lc1212CVec *src, f32 rate) {
    dst->x = dst->x + (f32)(rate * (0.01f * (src->x - dst->x)));
    dst->y = dst->y + (f32)(rate * (0.01f * (src->y - dst->y)));
    dst->z = dst->z + (f32)(rate * (0.01f * (src->z - dst->z)));
}

/* The point to track, falling back to the camera's own look-at point. */
static inline Lc1212CVec Lc1212C_Pick(Lc1212C *cam, Lc1212CVec *p) {
    Lc1212CVec v;

    if (p == NULL) {
        v = cam->unk_4C;
    } else {
        v = *p;
    }
    return v;
}

void fn_1_1212C(Lc1212C *cam) {
    u8 mtx[0x30];
    Lc1212CVec eye;
    Lc1212CVec pt;
    Lc1212CVec at;
    Lc1212CVec up;
    Lc1212CVec a;
    Lc1212CVec b;
    Lc1212CVec pos;
    Lc1212CVec out;
    s16 rot[4];
    u32 handle;
    u32 info;
    Lc1212CVec *src;
    f32 dx, dy, dz;
    f32 dist;
    f32 t;
    f64 d;
    f64 h;
    f32 c;
    f32 rate;

    fn_1_862D4(cam->unk_6, (Vec3 *)(Lc1212CVec *)(&eye));
    fn_1_862D4(lbl_1_bss_17F8, (Vec3 *)(Lc1212CVec *)(&pt));
    fn_1_8636C(lbl_1_bss_17F8, mtx);
    dist = Lc1212C_Dist2(&eye, &pt);
    fn_8006FA24(cam->mtx, mtx, cam->mtx, 0.2f);

    switch (cam->state) {
    case 3:
        if (cam->state == 3 && fn_1_40BB4() == 0) {
            if ((lbl_1_bss_9F8.unk_A >> 1) & 1) {
                cam->unk_14++;
            }
            if (lbl_1_bss_9F8.unk_A & 1) {
                cam->unk_14--;
            }
            if (cam->unk_14 > 1) {
                cam->unk_14 = 0;
            }
            if (cam->unk_14 < 0) {
                cam->unk_14 = 1;
            }
        }
        if (dist > 5000.0f) {
            cam->unk_12 = 0;
            cam->unk_18 = 1;
        }
        break;
    case 0:
    case 1:
    case 2:
    case 5:
        if (dist > 20000.0f) {
            cam->unk_12 = 2;
            cam->unk_18 = 1;
        }
        break;
    case 4:
    case 6:
        break;
    }

    switch (cam->unk_4) {
    case 0:
        Lc1212C_SetCurMtxTrans(&pt);
        lbl_8006DC6C(mtx);
        {
            Lc1212CVec v = {0.0f, 2.5f, 5.0f};
            up = v;
        }
        lbl_8006E1B0( (void *)(Lc1212CVec *)(&up), (void *)(Lc1212CVec *)(&cam->pos));
        cam->fov = 45.0f;
        break;
    case 1:
    case 3:
    case 4:
        Lc1212C_SetCurMtxTrans(&pt);
        lbl_8006DC6C(mtx);
        fn_8006ED0C( (Vec3 *)(Lc1212CVec *)(&pt), (Vec3 *)(Lc1212CVec *)(&eye), rot);
        mathutil_mtxA_rotate_y(rot[1]);
        mathutil_mtxA_rotate_x(rot[0]);
        t = (dist / 1000.0 < 0.0) ? 0.0 : ((dist / 1000.0 > 1.0) ? 1.0 : dist / 1000.0);
        {
            Lc1212CVec v = {0.0f, 0.0f, -3.0f};
            a = v;
        }
        a.y = 2.5 + t;
        up = a;
        if (cam->unk_4 == 3) {
            Lc1212CVec v = {0.0f, 0.0f, 0.0f};
            b = v;
            h = t / 2.0;
            b.y = h - 0.3;
            b.z = 2.0 + t;
            up = b;
        }
        if (cam->unk_4 == 4) {
            Lc1212CVec v = {0.0f, -0.3f, 1.0f};
            up = v;
        }
        lbl_8006E1B0( (void *)(Lc1212CVec *)(&up), (void *)(Lc1212CVec *)(&cam->pos));
        cam->fov = 55.0f;
        break;
    default:
        lbl_8006D7DC(&pt);
        cam->pos = pt;
        cam->fov = 55.0f;
        break;
    }

    cam->unk_4C = eye;
    fn_1_862A8(lbl_1_bss_17F8, (V3 *)(void *)(&at));
    Lc1212C_Follow(&cam->target, &at, lbl_1_data_4484.unk_0);
    cam->unk_5C = -lbl_8006D24C(cam->target.x, cam->target.y);
    lbl_8006DAEC();
    handle = fn_1_20A5C(&cam->pos, &info);
    pos = Lc1212C_Pick(cam, &pt);
    fn_1_15578(&cam->pos, (fn_1_11544_LiveCamVec *)(Lc1212CVec *)(&pos), &info, &out, 0x40005, &handle, 1, 0, 0, 0);
    lbl_8006DB30();
}
/* fzgx:end fn_1_1212C */

/* fzgx:begin fn_1_12620 */
// Prints the live-camera status text for the current camera event.
#pragma opt_common_subs off
void fn_1_12620(s32 arg0) {
    u8 *base = (u8 *)&lbl_1_data_43B8;
    char buf[0x74];

    fn_80006E10((u32)(base + 0x280));
    if (*(s16 *)&lbl_1_bss_960 == 0xA) {
        sprintf(buf, (const char *)(base + 0x284), arg0);
        if (fn_1_465D0((s32)buf, 1) == -1) {
            sprintf(buf, (const char *)(base + 0x2A0));
            fn_1_465D0((s32)buf, 1);
        }
    } else if (*(s16 *)&lbl_1_bss_960 == 0xE) {
        if (lbl_1_bss_525C.unk_191 & 2) {
            switch (lbl_1_bss_525C.unk_192) {
            case 4:
                sprintf(buf, (const char *)(base + 0x2BC));
                break;
            case 3:
                sprintf(buf, (const char *)(base + 0x2D4));
                break;
            case 2:
                sprintf(buf, (const char *)(base + 0x2EC));
                break;
            default:
                sprintf(buf, (const char *)(base + 0x2EC));
                break;
            }
        } else {
            sprintf(buf, (const char *)(base + 0x304));
        }
        fn_1_465D0((s32)buf, 1);
    } else {
        sprintf(buf, (const char *)(base + 0x324), arg0);
        if (fn_1_465D0((s32)buf, 1) == -1) {
            sprintf(buf, (const char *)(base + 0x33C));
            fn_1_465D0((s32)buf, 1);
        }
    }
    if (arg0 == 0x32) {
        fn_80006E10((u32)(base + 0x350));
        return;
    }
    sprintf(buf, (const char *)(base + 0x354), arg0);
    if (fn_1_465D0((s32)buf, 1) == -1) {
        sprintf(buf, (const char *)(base + 0x364));
        fn_1_465D0((s32)buf, 1);
    }
    sprintf(buf, (const char *)(base + 0x374), arg0);
    if (fn_1_465D0((s32)buf, 1) == -1) {
        sprintf(buf, (const char *)(base + 0x388));
        fn_1_465D0((s32)buf, 1);
    }
    fn_80006E10((u32)(base + 0x350));
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_12620 */

/* fzgx:begin fn_1_12850 */
u8 fn_1_12850(void) {
    return lbl_1_bss_17B4[0];
}
/* fzgx:end fn_1_12850 */

/* fzgx:begin fn_1_12860 */
// Initializes the live-camera state before returning the active camera result.
u32 fn_1_12860(u32 arg0, u32 arg1) {
    u32 *state = (u32 *)lbl_1_bss_1800;

    state[0] = arg0;
    state[1] = arg1;
    state[2] = 0;
    return fn_1_1289C(state)[0];
}
/* fzgx:end fn_1_12860 */

/* fzgx:begin fn_1_1289C */
#define LZ_N 4096
#define LZ_F 18
#define LZ_THRESHOLD 2

/* Okumura-style LZSS decoder over a little-endian sized blob. */
u32 *fn_1_1289C(u32 *state) {
    u8 text_buf[LZ_N + LZ_F - 1];
    int j, k, r, c;
    long i;
    u8 *cur;
    u8 *out;
    u32 flags;
    u32 limit;
    u8 *src;
    void (*done)(u32);
    u8 *dst;
    u32 out_size;

    src = (u8 *)state[0];
    done = (void (*)(u32))state[2];
    dst = (u8 *)state[1];
    limit = __lwbrx((u32 *)src, 0) + 8;
    out_size = __lwbrx((u32 *)src, 4);

    if (limit == 0 || out_size == 0) {
        return 0;
    }

    out = dst;
    cur = src + 8;

    for (i = 0; i < LZ_N - LZ_F; i++) {
        text_buf[i] = 0;
    }

    r = LZ_N - LZ_F;
    flags = 0;

    for (;;) {
        if (((flags >>= 1) & 0x100) == 0) {
            if ((u32)(cur - src) >= limit) break;
            c = *cur++;
            flags = c | 0xff00;
        }

        if (flags & 1) {
            if ((u32)(cur - src) >= limit) break;
            c = *cur++;
            *out++ = c;
            text_buf[r++] = c;
            r &= LZ_N - 1;
        } else {
            if ((u32)(cur - src) >= limit) break;
            i = cur[0];
            if ((u32)((cur + 1) - src) >= limit) break;
            j = cur[1];
            cur += 2;
            i |= (j & 0xf0) << 4;
            j = (j & 0x0f) + LZ_THRESHOLD;
            for (k = 0; k <= j; k++) {
                c = text_buf[(i + k) & (LZ_N - 1)];
                *out++ = c;
                text_buf[r++] = c;
                r &= LZ_N - 1;
            }
        }
    }

    if (done != 0) {
        done(out_size);
    }
    return &out_size;
}
/* fzgx:end fn_1_1289C */

/* fzgx:begin fn_1_12B88 */
static inline void lz_clear(u8 *buf, int n) {
    int i;

    for (i = 0; i < n; i++) {
        buf[i] = 0;
    }
}

// Loads an LZSS-compressed file (Okumura layout: N = 4096 ring window, F = 18,
// start position N - F): an 8-byte header (compressed size, decompressed size)
// followed by flag-byte coded literals and 12/4-bit back references.
// Returns the decompressed size, or 0 on failure.
u32 fn_1_12B88(char *path, u8 *out, u8 *ctx) {
    Sig_fn_1_45730_LoadResult file;
    u32 hdr[2];
    u8 window[0x1000 + 18 - 1];
    u32 offset;
    u32 r;
    u32 pos;
    u8 *dst;
    u32 flags;
    u32 end;
    u32 size;
    int len;
    int k;
    s32 i;
    int n = 0x1000 - 18;
    u8 c;

    lbl_1_bss_3B28 = 0;
    lbl_1_bss_3B2C = 0;
    if (fn_1_45730(path, &file) == 0) {
        return 0;
    }
    // Header words are stored big-endian in the stream and read back little-endian.
    hdr[0] = fn_1_1350C( (void *)(Sig_fn_1_45730_LoadResult *)(&file), ctx) << 24;
    hdr[0] |= (u32)fn_1_1350C( (void *)(Sig_fn_1_45730_LoadResult *)(&file), ctx) << 16;
    hdr[0] |= (u32)fn_1_1350C( (void *)(Sig_fn_1_45730_LoadResult *)(&file), ctx) << 8;
    hdr[0] |= (u32)fn_1_1350C( (void *)(Sig_fn_1_45730_LoadResult *)(&file), ctx);
    hdr[1] = fn_1_1350C( (void *)(Sig_fn_1_45730_LoadResult *)(&file), ctx) << 24;
    hdr[1] |= (u32)fn_1_1350C( (void *)(Sig_fn_1_45730_LoadResult *)(&file), ctx) << 16;
    hdr[1] |= (u32)fn_1_1350C( (void *)(Sig_fn_1_45730_LoadResult *)(&file), ctx) << 8;
    hdr[1] |= (u32)fn_1_1350C( (void *)(Sig_fn_1_45730_LoadResult *)(&file), ctx);
    end = __lwbrx(hdr, 0) + 8;
    size = __lwbrx(hdr, 4);
    if (end == 0 || size == 0) {
        return 0;
    }
    dst = out;
    pos = 8;
    for (i = 0; i < n; i++) {
        window[i] = 0;
    }
    r = n;
    flags = 0;
    for (;;) {
        flags >>= 1;
        if (!(flags & 0x100)) {
            if (pos >= end) {
                break;
            }
            flags = fn_1_1350C( (void *)(Sig_fn_1_45730_LoadResult *)(&file), ctx) | 0xFF00;
            pos++;
        }
        if (flags & 1) {
            if (pos >= end) {
                break;
            }
            c = fn_1_1350C( (void *)(Sig_fn_1_45730_LoadResult *)(&file), ctx);
            *dst++ = c;
            pos++;
            window[r++] = c;
            r &= 0xFFF;
        } else {
            if (pos >= end) {
                break;
            }
            offset = fn_1_1350C( (void *)(Sig_fn_1_45730_LoadResult *)(&file), ctx);
            if (pos + 1 >= end) {
                break;
            }
            c = fn_1_1350C( (void *)(Sig_fn_1_45730_LoadResult *)(&file), ctx);
            offset |= (c & 0xF0) << 4;
            len = (c & 0x0F) + 2;
            pos += 2;
            for (k = 0; k <= len; k++) {
                c = window[(offset + k) & 0xFFF];
                *dst++ = c;
                window[r++] = c;
                r &= 0xFFF;
            }
        }
    }
    fn_1_45850(&file);
    return size;
}
/* fzgx:end fn_1_12B88 */

/* fzgx:begin fn_1_12F78 */
u32 fn_1_12F78(void *arg0, u32 arg1) {
    fn_80083DB0( (char *)(Obj_1_bss_3B30 *)(&lbl_1_bss_3B30), (const char *)(void *)(arg0));
    lbl_1_bss_3B30.unk_80 = arg1;
    lbl_1_bss_3B30.unk_84 = 0;
    return *fn_1_1304C(&lbl_1_bss_3B30, 0);
}
/* fzgx:end fn_1_12F78 */

/* fzgx:begin fn_1_12FD4 */
u32 fn_1_12FD4(u32 arg0, u32 arg1, u32 arg2) {
    u32 *t0;
    /* Publish the cleared header before updating the request fields. */
    volatile Obj_1_bss_3B30 *obj = &lbl_1_bss_3B30;
    obj->unk_0 = 0;
    obj->unk_80 = arg1;
    obj->unk_84 = 0;
    t0 = fn_1_1304C(&lbl_1_bss_3B30, arg0);
    return *t0;
}
/* fzgx:end fn_1_12FD4 */

/* fzgx:begin fn_1_13018 */
s32 fn_1_13018(void) {
    fn_8000659C();
    return OSIsThreadTerminated(lbl_1_bss_1810) == 0;
}
/* fzgx:end fn_1_13018 */

/* fzgx:begin fn_1_1350C */
/* volatile: retail reloads these globals at every access (matches codegen) */
#define V(x) (*(volatile u32 *)&(x))

u8 fn_1_1350C(void *a, u8 *buf) {
    s32 n;
    if (V(lbl_1_bss_3B28) == 0) {
        n = V(lbl_1_data_5180);
        if (V(lbl_1_bss_3B2C) + V(lbl_1_data_5180) > (u32)fn_1_45B2C(a)) {
            n = ((u32)fn_1_45B2C(a) - V(lbl_1_bss_3B2C) + 0x1f) & ~0x1f;
        }
        if (n > 0) {
            fn_1_458A0(a, buf, n, V(lbl_1_bss_3B2C));
        }
        V(lbl_1_bss_3B2C) = V(lbl_1_bss_3B2C) + V(lbl_1_data_5180);
    }
    {
        u8 r = buf[V(lbl_1_bss_3B28)];
        V(lbl_1_bss_3B28) = V(lbl_1_bss_3B28) + 1;
        if (V(lbl_1_bss_3B28) >= V(lbl_1_data_5180)) {
            V(lbl_1_bss_3B28) = 0;
        }
        return r;
    }
}
/* fzgx:end fn_1_1350C */

/* fzgx:begin fn_1_1361C noprologue */
#include "types.h"

extern u32 fn_1_45B2C(void *p);
extern void fn_1_45964(void *a, void *buf, int n, u32 off, void *cb);
extern void fn_1_1383C(void);
extern void DCInvalidateRange(void *addr, u32 len);
extern void fn_8000659C(void);
extern void fn_1_3308(void);
extern void fn_1_D3214(void);
extern void fn_8001AF64(void);

extern volatile u32 lbl_1_data_5184;  // volatile: retail reloads it on every access

typedef struct {
    u8 _0[0x2328];
    volatile u32 w2328;   // 0x2328  read cursor (active buffer)
    volatile u32 w232c;   // 0x232c  write offset
    u8 _pad1[0x23b8 - 0x232c - 4];
    volatile u8 b23b8;    // 0x23b8  buffer toggle
    u8 _pad2[3];
    volatile s32 w23bc;   // 0x23bc  DMA-ready flag
} SomRing;

extern SomRing lbl_1_bss_1800;

u8 fn_1_1361C(void *a, u32 *b) {
    SomRing *s = &lbl_1_bss_1800;
    int n;

    if (s->w232c == 0) {
        n = lbl_1_data_5184;
        s->b23b8 = 0;
        if (s->w232c + lbl_1_data_5184 > fn_1_45B2C(a)) {
            n = ((fn_1_45B2C(a) - s->w232c) + 0x1f) & ~0x1f;
        }
        if (n > 0) {
            DCInvalidateRange((void *)b[s->b23b8], lbl_1_data_5184);
            s->w23bc = 0;
            fn_1_45964(a, (void *)b[s->b23b8], n, s->w232c, fn_1_1383C);
        }
        s->w232c += lbl_1_data_5184;
        s->b23b8 = 1 - s->b23b8;
    }

    if (s->w2328 == 0) {
        n = lbl_1_data_5184;
        if (s->w232c + lbl_1_data_5184 > fn_1_45B2C(a)) {
            n = ((fn_1_45B2C(a) - s->w232c) + 0x1f) & ~0x1f;
        }
        while (s->w23bc == 0) {
            fn_8000659C();
            fn_1_3308();
            fn_1_D3214();
            fn_8001AF64();
        }
        if (n > 0) {
            DCInvalidateRange((void *)b[s->b23b8], lbl_1_data_5184);
            s->w23bc = 0;
            fn_1_45964(a, (void *)b[s->b23b8], n, s->w232c, fn_1_1383C);
        }
        s->w232c += lbl_1_data_5184;
        s->b23b8 = 1 - s->b23b8;
    }

    {
        u8 *buf = (u8 *)b[s->b23b8];
        u8 ret = buf[s->w2328];
        s->w2328 = s->w2328 + 1;
        if (s->w2328 >= lbl_1_data_5184) s->w2328 = 0;
        return ret;
    }
}
/* fzgx:end fn_1_1361C */
