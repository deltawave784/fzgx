#ifndef GAME_MAIN_REL_FACE_TYPES_H
#define GAME_MAIN_REL_FACE_TYPES_H

// Types (and the externs that name them) of face.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).

#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/face.h"

typedef struct { u32 a, b, c; } V3;

typedef struct Output {
    void* data;
    void* aux;
} Output;

typedef struct LocalData {
    u8 unk_0[0x34];
    u32 size;
} LocalData;

extern V3 lbl_1_rodata_60A0;
extern void fn_1_D3020(void* unused, Output* output);
extern int DVDOpen(void*, LocalData*);

#endif  // GAME_MAIN_REL_FACE_TYPES_H
