#ifndef GAME_MAIN_REL_EFFECT_CAR_TYPES_H
#define GAME_MAIN_REL_EFFECT_CAR_TYPES_H

// Types (and the externs that name them) of effect_car.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).

#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/effect_car.h"
#include "dolphin/hw_regs.h"

struct fn_1_72318_EffectCar {
    u8 pad_18[0x18];
    s16 field_18;
    u8 pad_1a[0x1e];
    u32 field_38;
    u8 pad_3c[0x7c];
    u8 field_b8;
};

struct fn_1_6F404_lbl_1_rodata_2D70 {
    f32 unk_0;
    u8 pad_4[0x14];
    f32 unk_18;
    f32 unk_1C;
    u8 pad_20[0x8];
    f32 unk_28;
    u8 pad_2C[0x48];
    f32 unk_74;
    u8 pad_78[0x4];
    f32 unk_7C;
    u8 pad_80[0x10];
    f32 unk_90;
    u8 pad_94[0x18];
    f32 unk_AC;
    f32 unk_B0;
    u8 pad_B4[0x24];
    f32 unk_D8;
    u8 pad_DC[0x1BC];
    f32 unk_298;
    u8 pad_29C[0x74];
    u32 unk_310;
    u32 unk_314;
    u32 unk_318;
    f32 unk_31C;
    f32 unk_320;
};

typedef struct Fn1_714A8Vec {
    f32 x;
    f32 y;
    f32 z;
} Fn1_714A8Vec;

struct Fn1_714A8Car {
    u8 pad_00[0x38];
    u8 *field_38;
    f32 field_3c;
    f32 field_40;
    f32 field_44;
    Fn1_714A8Vec field_48;
};

extern struct fn_1_6F404_lbl_1_rodata_2D70 lbl_1_rodata_2D70;
extern void fn_1_714A8(struct Fn1_714A8Car *car, f32 *axis, u32 arg2, f32 size);

#endif  // GAME_MAIN_REL_EFFECT_CAR_TYPES_H
