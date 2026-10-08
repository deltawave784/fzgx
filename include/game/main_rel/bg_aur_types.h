#ifndef GAME_MAIN_REL_BG_AUR_TYPES_H
#define GAME_MAIN_REL_BG_AUR_TYPES_H

// Types (and the externs that name them) of bg_aur.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).

#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_aur.h"

struct fn_1_151C9C_lbl_1_rodata_D4F8 {
    f32 unk_0;
};

struct fn_1_151C9C_lbl_1_rodata_D500 {
    f64 unk_0;
};

typedef struct {
    s32 count;
    u8 pad_004[0x100];
    s32 counter[64];
    f32 timer[64];
    f32 progress[64];
    f32 cooldown[64];
} Fn153B24Data;

extern struct fn_1_151C9C_lbl_1_rodata_D4F8 lbl_1_rodata_D4F8;
extern struct fn_1_151C9C_lbl_1_rodata_D500 lbl_1_rodata_D500;

#endif  // GAME_MAIN_REL_BG_AUR_TYPES_H
