#ifndef GAME_MAIN_REL_GHOST_TYPES_H
#define GAME_MAIN_REL_GHOST_TYPES_H

// Types (and the externs that name them) of ghost.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).

#include "types.h"
#include "dolphin/types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/ghost.h"
#include "dolphin/ar.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct {
    u32 field_0;
    s16 field_4;
    s16 field_6;
    u8 _pad8[0x74];
    Vec3 field_7c;
    u8 _pad88[0x64];
    u8 _pad_ec[0x60];
    u8 field_14c[0xb4];
    f32 field_200;
    u8 _pad204[0x20];
    f32 field_224;
    u8 _pad228[0x24d];
    u8 field_475;
} FnObject;

typedef struct {
    u32 unk_0;
    u8 unk_4;
    u8 pad_5[0xF];
    u8 unk_14;
    u8 pad_15[0x33];
} fn_1_EF4F8_Obj_1_bss_7ECB4;

extern void fn_1_F143C(FnObject *obj, s32 index, const f32 *a, const f32 *b, void *arg5);
extern s32 fn_1_BA144(fn_1_EF4F8_Obj_1_bss_7ECB4 *);
extern void fn_1_BC310(fn_1_EF4F8_Obj_1_bss_7ECB4 *);

#endif  // GAME_MAIN_REL_GHOST_TYPES_H
