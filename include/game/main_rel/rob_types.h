#ifndef GAME_MAIN_REL_ROB_TYPES_H
#define GAME_MAIN_REL_ROB_TYPES_H

// Types (and the externs that name them) of rob.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).

#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/rob.h"

struct fn_1_95EF0_lbl_801A6410 {
    u32 unk_0;
};

typedef struct Fn197174Root Fn197174Root;

struct Fn197174Root {
    u8 unk_00[0x08];
    u16 count;
};

typedef struct Fn197174Entry Fn197174Entry;

struct Fn197174Entry {
    u8 unk_00[0x1C];
    u32 offset;
};

typedef struct Fn197174Owner Fn197174Owner;

struct Fn197174Owner {
    u8 unk_00[0x14];
    u8 *base;
};

typedef struct Fn197F80Object Fn197F80Object;

struct Fn197F80Object {
    u8 unk_000[0x488];
    u8 unk_488;
    u8 unk_489;
    u8 unk_48A[0x1A];
    void *unk_4A4;
    void *unk_4A8;
    void *unk_4AC;
    void *unk_4B0;
    void *unk_4B4;
};

typedef struct Fn198104Obj {
    u8 unk_00[0x1C];
    u32 value_1C;
    u8 unk_20[0x0C];
    u32 value_2C;
} Fn198104Obj;

extern Fn197174Root *fn_1_41BDC(void);
extern Fn197174Entry *fn_1_41B18(Fn197174Owner *owner, void *arg1, s32 index);
extern u32 fn_1_97F80(Fn197F80Object *rob, const char *name);

#endif  // GAME_MAIN_REL_ROB_TYPES_H
