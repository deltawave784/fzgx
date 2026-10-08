#ifndef GAME_MAIN_REL_BACKGROUND_TYPES_H
#define GAME_MAIN_REL_BACKGROUND_TYPES_H

// Types (and the externs that name them) of background.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).

#include "types.h"
#include "dolphin/types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/background.h"
#include "dolphin/hw_regs.h"

typedef struct {
    s32 type;     /* 0: constant, 1: linear, else: hermite */
    f32 time;
    f32 value;
    f32 tanIn;
    f32 tanOut;
} CurveKey;


#endif  // GAME_MAIN_REL_BACKGROUND_TYPES_H
