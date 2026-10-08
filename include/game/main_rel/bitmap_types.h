#ifndef GAME_MAIN_REL_BITMAP_TYPES_H
#define GAME_MAIN_REL_BITMAP_TYPES_H

// Types (and the externs that name them) of bitmap.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).

#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bitmap.h"

typedef struct {
    s32 unk_0;
    u8 pad_4[0x24];
} BitmapEntry;

typedef struct {
    s32 unk_0;
    u8 pad_4[0x24];
} Fn147EE4Entry;

typedef struct {
    s32 unk_0;
    u8 pad_4[0x24];
} Fn147F74Entry;

extern void fn_1_47AD4(BitmapEntry *, s32, s32, s32);

#endif  // GAME_MAIN_REL_BITMAP_TYPES_H
