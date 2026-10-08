#ifndef GAME_MAIN_REL_AVLINE_TYPES_H
#define GAME_MAIN_REL_AVLINE_TYPES_H

// Types (and the externs that name them) of avline.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).

#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/avline.h"
#include "dolphin/hw_regs.h"

typedef struct AvLineDrawState {
    u8 unk_0;
    u8 pad_1[3];
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
} AvLineDrawState;

extern AvLineDrawState lbl_1_data_1C670;

#endif  // GAME_MAIN_REL_AVLINE_TYPES_H
