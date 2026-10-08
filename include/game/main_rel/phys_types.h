#ifndef GAME_MAIN_REL_PHYS_TYPES_H
#define GAME_MAIN_REL_PHYS_TYPES_H

// Types (and the externs that name them) of phys.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).

#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/phys.h"

typedef struct Sig_fn_1_8D168_Fn1_8D168State {
    u8 pad[0x60];
    u32 field_60;
} Sig_fn_1_8D168_Fn1_8D168State;

struct fn_1_E35F0_lbl_801A6410 {
    u32 unk_0;
};

struct fn_1_E7E00_lbl_801A6410 {
    u32 unk_0;
};

typedef struct LocalStruct {
    u32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    u8 pad_18[0x14];
    f32 unk_2C;
    u32 unk_30;
    u32 unk_34;
    u32 unk_38;
    u8 pad_3C[0x1C];
} LocalStruct;

typedef struct Obj_1A8 {
    u8 pad_0[0xA];
    s16 unk_A;
    u8 pad_C[2];
    s16 unk_E;
    u8 pad_10[0x128];
    u64 unk_138;
    u8 pad_140[0x1A8 - 0x140];
} Obj_1A8;

typedef struct {
    u8 unk0[0x100];
    s32 value;
} E573CObj;

typedef struct {
    u8 pad_0[0x8];
    f32 unk_8;
    f32 unk_C;
} Camera;

typedef void (*Cb)(void *, ...);
extern void fn_1_8D168(Sig_fn_1_8D168_Fn1_8D168State *);
extern void fn_1_E4A38(u32 arg0, u16 arg1, u16 arg2, Cb arg3);
extern const LocalStruct lbl_1_rodata_26F8;
extern void fn_1_4E92C(LocalStruct *, u32, u16, u16, u32);
extern s16 fn_1_E573C(E573CObj *self);
extern Camera *game_camera_get(void);

#endif  // GAME_MAIN_REL_PHYS_TYPES_H
