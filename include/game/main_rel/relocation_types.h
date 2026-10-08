#ifndef GAME_MAIN_REL_RELOCATION_TYPES_H
#define GAME_MAIN_REL_RELOCATION_TYPES_H

// Types (and the externs that name them) of relocation.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).

#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/relocation.h"
#include "dolphin/os/OSTime.h"

struct fn_1_A6480_d58 {
    u8 pad[8];
    u16 unk_8;
    u16 unk_A;
};

extern struct fn_1_A6480_d58 lbl_1_bss_D58;

#endif  // GAME_MAIN_REL_RELOCATION_TYPES_H
