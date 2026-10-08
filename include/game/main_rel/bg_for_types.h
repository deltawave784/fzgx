#ifndef GAME_MAIN_REL_BG_FOR_TYPES_H
#define GAME_MAIN_REL_BG_FOR_TYPES_H

// Types (and the externs that name them) of bg_for.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).

#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_for.h"

typedef struct fn_1_DCF54_Vec3 {
    u32 x;
    u32 y;
    u32 z;
} fn_1_DCF54_Vec3;

typedef struct State {
    fn_1_DCF54_Vec3 a;
    u8 pad[12];
    fn_1_DCF54_Vec3 b;
    fn_1_DCF54_Vec3 c;
} State;

struct fn_1_DCE60_lbl_1_rodata_6750 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2C;
};

extern State lbl_1_bss_7ADE8;
extern struct fn_1_DCE60_lbl_1_rodata_6750 lbl_1_rodata_6750;

#endif  // GAME_MAIN_REL_BG_FOR_TYPES_H
