#ifndef GAME_MAIN_REL_ALLOC_TYPES_H
#define GAME_MAIN_REL_ALLOC_TYPES_H

// Types (and the externs that name them) of alloc.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).

#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/alloc.h"

typedef struct {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
} Fn1_4928Entry;

typedef struct Fn14D14Data {
    u8 value0;
    u8 value1;
    u8 unk2;
    u8 flags;
    u16 value4;
} Fn14D14Data;

extern Fn1_4928Entry lbl_1_bss_DCC[32];
extern f32 fn_1_4D14(Fn14D14Data *data);

#endif  // GAME_MAIN_REL_ALLOC_TYPES_H
