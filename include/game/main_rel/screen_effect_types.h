#ifndef GAME_MAIN_REL_SCREEN_EFFECT_TYPES_H
#define GAME_MAIN_REL_SCREEN_EFFECT_TYPES_H

// Types (and the externs that name them) of screen_effect.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).

#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/screen_effect.h"

typedef struct fn_1_76650_ScreenEffect {
    u8 pad_00[0xa0];
    s32 field_a0;
    s32 field_a4;
    s32 field_a8;
    s32 field_ac;
    s32 field_b0;
    u8 pad_b4[0x14];
    s32 field_c8;
    s32 field_cc;
    s32 field_d0;
    s32 field_d4;
    s32 field_d8;
    s32 field_dc;
    s32 field_e0;
    f32 field_e4;
    s16 field_e8;
    s16 field_ea;
    s16 field_ec;
    s16 field_ee;
    s16 field_f0;
    s16 field_f2;
    s32 field_f4;
    s16 field_f8;
    s16 field_fa;
    s16 field_fc;
    s16 field_fe;
    s16 field_100;
    s16 field_102;
    s32 field_104;
    u8 field_108;
} fn_1_76650_ScreenEffect;

typedef struct {
    u8 pad_0[0xdc];
    u32 unk_dc;
} Fn_1_72980_Obj;

struct fn_1_729F8_Arg0 {
    u8 pad_0[0xDC];
    s32 unk_DC;
    s32 unk_E0;
    f32 unk_E4;
    u16 unk_E8;
    u16 unk_EA;
    s16 unk_EC;
    s16 unk_EE;
    u16 unk_F0;
    u16 unk_F2;
    u32 unk_F4;
    u16 unk_F8;
    u16 unk_FA;
    u16 unk_FC;
    u16 unk_FE;
    u16 unk_100;
    u16 unk_102;
    u32 unk_104;
};

typedef struct {
    u8 unk00[0x2c];
    f32 value;
} GlobalData;

struct fn_1_761B8_Arg0 {
    u8 pad_0[0xE0];
    u32 unk_E0;
};

typedef struct {
    u8 pad_0[0xa0];
    u32 unk_a0[5];
    u32 unk_b4[5];
    s32 unk_c8[5];
    u32 unk_dc;
    u32 unk_e0;
    f32 unk_e4;
    u16 unk_e8;
    u16 unk_ea;
    u16 unk_ec;
    u16 unk_ee;
    u16 unk_f0;
    u16 unk_f2;
    u32 unk_f4;
    u16 unk_f8;
    u16 unk_fa;
    u16 unk_fc;
    u16 unk_fe;
    u16 unk_100;
    u16 unk_102;
    u32 unk_104;
    u8 unk_108;
} FnScreenEffect;

struct Sig_fn_8004E278_fn_8004E278_Arg0 {
    u32 unk_0;
};

struct fn_1_76448_Arg0 {
    u8 pad_0[0xA0];
    u32 unk_A0[1];
    u8 pad_A4[0x38];
    u32 unk_DC;
    u8 pad_E0[0x18];
    s16 unk_F8;
};

typedef u8 Sig_GXGetTexBufferSize_GXBool;

typedef struct {
    u32 flags;
    s32 count;
    void *nodes;
} EffectManager;

typedef struct {
    f32 x, y, z;
} Vec3f;

extern s32 fn_1_79C88(EffectManager *manager, u32 *out, s32 reverse, f32 value);
extern void fn_1_76650(fn_1_76650_ScreenEffect *effect);
extern void fn_1_72980(Fn_1_72980_Obj *arg0);
extern void *fn_1_729F8(struct fn_1_729F8_Arg0 *arg0);
extern void fn_1_761B8(struct fn_1_761B8_Arg0 *arg0, u32 arg1);
extern void DCInvalidateRange(struct Sig_fn_8004E278_fn_8004E278_Arg0 *, u32);
extern void fn_1_76448(struct fn_1_76448_Arg0 *arg0, u32 arg1);
extern u32 GXGetTexBufferSize(u16, u16, u32, Sig_GXGetTexBufferSize_GXBool, u8);

#endif  // GAME_MAIN_REL_SCREEN_EFFECT_TYPES_H
