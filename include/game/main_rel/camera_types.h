#ifndef GAME_MAIN_REL_CAMERA_TYPES_H
#define GAME_MAIN_REL_CAMERA_TYPES_H

// Types (and the externs that name them) of camera.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).

#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/camera.h"

struct fn_1_6400_lbl_801A6410 {
    u32 unk_0;
};

typedef struct CameraTarget {
    u8 pad_000[0x394];
    void *data;
} CameraTarget;

struct fn_1_AA54_lbl_1_rodata_388 {
    f64 unk_0;
};

typedef struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

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

typedef struct CameraStateLocal {
    u8 pad_d4[0xd4];
    f32 unk_D4;
    f32 unk_D8;
    f32 unk_DC;
} CameraStateLocal;

typedef struct { u8 pad_0[0x4]; f32 unk_4; u32 unk_8; f32 unk_C; } Bss_104C;

typedef struct fn_1_ABAC_Target {
    u8 pad_0[0x214];
    u16 unk_214;
} fn_1_ABAC_Target;

typedef struct { u8 pad_0[0x20]; u32 unk_20; } Inner;
typedef struct { u8 pad_0[0x8]; Inner *unk_8; } Outer;

typedef struct {
    u8 data[0x10];
} CamEntry;

extern Outer *lbl_1_bss_38454;
extern void lbl_8006D9D8(CamEntry *);
extern struct fn_1_6400_lbl_801A6410 lbl_801A6410;
extern struct fn_1_AA54_lbl_1_rodata_388 lbl_1_rodata_388;
extern void fn_1_862D4(u8 index, Vec3 *out);
extern void fn_1_8658C(u8 index, Vec3 *out);
extern void fn_1_AEB8(camera_reset_transition_Camera *);
extern void fn_1_AFC8(camera_update_transition_Camera *);
extern Transform *lbl_801A6D00;
extern CameraStateLocal *lbl_801A66CC;
extern Bss_104C lbl_1_bss_104C;
extern void fn_8006F038(Vec3 *arg0, Vec3 *arg1, s16 arg2);

#endif  // GAME_MAIN_REL_CAMERA_TYPES_H
