#ifndef GAME_MAIN_REL_ENEMY_CTRL_TYPES_H
#define GAME_MAIN_REL_ENEMY_CTRL_TYPES_H

// Types (and the externs that name them) of enemy_ctrl.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).

#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/enemy_ctrl.h"
#include "font.h"

struct FzgxCopy_88 { u32 words[22]; };

typedef struct fn_1_C771C_EnemyCtrl {
    u8 pad_000[0x118];
    int field_118;
    u8 pad_11c[0xd0];
    u8 field_1ec;
    u8 field_1ed;
    u16 field_1ee;
} fn_1_C771C_EnemyCtrl;

typedef struct fn_1_C72D4_EnemyCtrl {
    unsigned char pad_000[0x118];
    int field_118;
    unsigned char pad_11c[0xd0];
    unsigned char field_1ec;
    unsigned char field_1ed;
    unsigned short field_1ee;
} fn_1_C72D4_EnemyCtrl;

struct fn_1_CC280_lbl_1_rodata_5C00 {
    f64 unk_0;
};

struct fn_1_CC280_lbl_1_rodata_5EC0 {
    u32 unk_0[10];
};

typedef struct fn_1_CD6C0_object {
    s32 flags;
    u16 pad4;
    s16 state;
    u8 pad8[0x2c];
    f32 value;
    u8 pad38[0x28];
    void *controller;
} fn_1_CD6C0_object;

struct fn_1_D0E74_lbl_1_rodata_6080 {
    f64 unk_0;
};

struct Sig_fn_8003432C_fn_8003432C_Arg2 {
    u32 unk_0;
};

struct Sig_GXPeekZ_GXPeekZ_Arg2 {
    u32 unk_0;
};

extern void fn_1_CD6C0(fn_1_CD6C0_object *object);
extern struct fn_1_CC280_lbl_1_rodata_5EC0 lbl_1_rodata_5EC0;
extern struct fn_1_D0E74_lbl_1_rodata_6080 lbl_1_rodata_6080;
extern u32 fn_8003432C(u32, u32, struct Sig_fn_8003432C_fn_8003432C_Arg2 *);
extern u32 GXPeekZ(u32, u32, struct Sig_GXPeekZ_GXPeekZ_Arg2 *);

#endif  // GAME_MAIN_REL_ENEMY_CTRL_TYPES_H
