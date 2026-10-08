#ifndef GAME_MAIN_REL_BG_COMMON_TYPES_H
#define GAME_MAIN_REL_BG_COMMON_TYPES_H

// Types (and the externs that name them) of bg_common.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).

#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_common.h"

typedef void (*Fn103FCC)(void);

typedef struct Fn1_103F58_Object {
    u8 pad0[4];
    Fn103FCC callback;
    void *context;
} Fn1_103F58_Object;


#endif  // GAME_MAIN_REL_BG_COMMON_TYPES_H
