#ifndef GAME_MAIN_REL_LIGHT_TYPES_H
#define GAME_MAIN_REL_LIGHT_TYPES_H

// Types (and the externs that name them) of light.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).

#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/light.h"

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
} Triple_80074D28;

extern void fn_80074D28(Triple_80074D28 *);

#endif  // GAME_MAIN_REL_LIGHT_TYPES_H
