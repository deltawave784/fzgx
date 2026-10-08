#ifndef GAME_MAIN_REL_MDLLOAD_TYPES_H
#define GAME_MAIN_REL_MDLLOAD_TYPES_H

// Types (and the externs that name them) of mdlload.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).

#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/mdlload.h"

typedef struct {
    u32 unk_00;
    void *resource;
} ModelReleaseEntry;

typedef struct {
    s32 entry_count;
    u8 unk_04[4];
    ModelReleaseEntry *entry_table;
} ModelReleaseList;

struct Entry {
    s8 flag[0x18];
};

struct Base {
    char pad[0xe780];
    struct Entry entries[1];
};

extern void *fn_1_D3B6C(ModelReleaseList *list);
extern void fn_1_D47D8(struct Base *base, s32 index);

#endif  // GAME_MAIN_REL_MDLLOAD_TYPES_H
