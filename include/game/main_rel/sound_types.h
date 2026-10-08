#ifndef GAME_MAIN_REL_SOUND_TYPES_H
#define GAME_MAIN_REL_SOUND_TYPES_H

// Types (and the externs that name them) of sound.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).

#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/sound.h"
#include "sofdec/adxt.h"

typedef struct {
    u8 unk_0[0x3A0];
    void *unk_3A0;
} SoundObject;

extern SoundObject *fn_1_86854(s8 arg0);

#endif  // GAME_MAIN_REL_SOUND_TYPES_H
