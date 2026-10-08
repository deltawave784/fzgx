#ifndef GAME_MAIN_REL_BG_LIG_TYPES_H
#define GAME_MAIN_REL_BG_LIG_TYPES_H

// Types (and the externs that name them) of bg_lig.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).

#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_lig.h"

typedef struct {
    u8 pad_000[0x6c0];
    f32 threshold;
} fn_1_D8784_LigObject;

typedef struct {
    u8 pad_00[0x68];
    u32 field_68;
    u8 pad_6c[0x40];
} fn_1_D8CA8_LigEntry;

typedef struct {
    u8 pad_00[0x6d4];
    s32 count;
    fn_1_D8CA8_LigEntry entries[1];
} fn_1_D8CA8_LigObject;

typedef struct {
    u8 pad0[0x24];
    f32 value;
    u8 pad28[0x4];
    s16 count;
    u8 pad2e[0x2];
} fn_1_D7B7C_LigEntry;

typedef struct {
    u8 pad0[0x4];
    void (*callback)(void);
    fn_1_D7B7C_LigEntry *entry;
} LigEvent;

typedef struct {
    u8 data[0xac];
} fn_1_D8D08_LigEntry;

typedef struct {
    u8 pad[0x6d4];
    s32 count;
    fn_1_D8D08_LigEntry entries[1];
} LigContainer;

typedef struct {
    u8 unk_0[0xac];
} fn_1_D8EEC_LigEntry;

typedef struct {
    u8 unk_0[0x6d4];
    s32 unk_6d4;
    fn_1_D8EEC_LigEntry unk_6d8[1];
} fn_1_D8EEC_LigObject;

struct fn_1_D66F8_lbl_801A66A0 {
    u32 unk_0;
};

typedef struct {
    u8 pad_000[0x2c];
    f32 x;
    f32 y;
    f32 z;
    u8 pad_038[0x74];
} fn_1_D8D58_LigEntry;

typedef struct {
    f32 pos[3];
    f32 vel[3];
    f32 scale[3];
    f32 value;
    s16 phase;
    s16 step;
    s16 count;
    u8 pad2e[0x2];
} fn_1_D7A10_LigEntry;

typedef struct {
    u8 pad_000[0x6d4];
    s32 count;
    fn_1_D8D58_LigEntry entries[1];
} LigObject;

extern void fn_1_D8CA8(fn_1_D8CA8_LigObject *obj);
extern void fn_1_D7B7C(fn_1_D7B7C_LigEntry *base);
extern void fn_1_D8D08(LigContainer *container);
extern void fn_1_D8784(fn_1_D8784_LigObject *obj);
extern void fn_1_D8EEC(fn_1_D8EEC_LigObject *obj, void *arg);
extern void *fn_1_5448C(fn_1_D7B7C_LigEntry *entry);
extern void fn_1_103090(fn_1_D8CA8_LigEntry *entry);
extern void fn_1_1030A4(fn_1_D8D08_LigEntry *entry);
extern struct fn_1_D66F8_lbl_801A66A0 lbl_801A66A0;
extern void fn_1_1030D4(fn_1_D8D58_LigEntry *entry, void *arg);
extern void fn_1_103264(fn_1_D8EEC_LigEntry *entry, void *arg);
extern void fn_1_D7A10(fn_1_D7A10_LigEntry *base);
extern void fn_1_D8D58(LigObject *obj, void *arg);

#endif  // GAME_MAIN_REL_BG_LIG_TYPES_H
