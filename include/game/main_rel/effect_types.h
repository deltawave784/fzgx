#ifndef GAME_MAIN_REL_EFFECT_TYPES_H
#define GAME_MAIN_REL_EFFECT_TYPES_H

// Types (and the externs that name them) of effect.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).

#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/effect.h"

typedef struct fn_1_58D38_EffectEntry {
    s8 unk_00;
    u8 pad_01[7];
    u32 unk_08;
    s16 unk_0C;
    u8 pad_0E[0x0C];
    u16 unk_1A;
    u8 pad_1C[0xCC];
} fn_1_58D38_EffectEntry;

struct fn_1_5BF70_lbl_1_rodata_2950 {
    u8 pad_0[0x8];
    f32 unk_8;
    u8 pad_C[0x14];
    f64 unk_20;
    u8 pad_28[0xC8];
    f64 unk_F0;
    f64 unk_F8;
    u8 pad_100[0x30];
    f64 unk_130;
};

typedef struct {
    u8 unk00[0x18];
    s16 value18;
    u8 unk1A[2];
    f32 value1C;
    f32 value20;
    f32 value24;
    f32 value28;
    u8 unk2C[8];
    void *field34;
    u8 unk38[0x1c];
    s16 value54;
    s16 value56;
} fn_1_5FEBC_EffectData;

typedef struct {
    u8 unk00[8];
    fn_1_5FEBC_EffectData *data;
} fn_1_5FEBC_EffectObject;

typedef struct {
    u8 pad_0[0x10];
    u32 unk_10;
    u8 pad_14[0x20];
    u32 unk_34;
    void *unk_38;
    u8 pad_3c[0x18];
    s16 unk_54;
    u8 pad_56[0x4];
    u16 unk_5a;
    u8 pad_5c[0x58];
    f32 unk_b4;
} fn_1_61D08_EffectObject;

typedef struct {
    u8 pad_00[0x8];
    void *unk_08;
} fn_1_652F4_Effect;

typedef struct {
    u8 pad20[0x20];
    void *unk_20;
} Fn1_61E60Node;

typedef struct {
    u8 pad38[0x38];
    Fn1_61E60Node *unk_38;
} Fn1_61E60Object;

extern void fn_1_5FEBC(fn_1_5FEBC_EffectObject *object);
extern void fn_1_652F4(fn_1_652F4_Effect *effect);
extern void fn_1_62360(fn_1_58D38_EffectEntry *arg0);

#endif  // GAME_MAIN_REL_EFFECT_TYPES_H
