#ifndef GAME_MAIN_REL_BURNER_TYPES_H
#define GAME_MAIN_REL_BURNER_TYPES_H

// Types (and the externs that name them) of burner.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).

#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/burner.h"

typedef struct Node {
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct fn_1_984F0_BurnerNode fn_1_984F0_BurnerNode;

struct fn_1_984F0_BurnerNode {
    u8 pad_0[0x4];
    fn_1_984F0_BurnerNode *next;
    u32 index;
    u8 pad_C[0x3C];
    u32 key;
};

typedef struct {
    u8 pad[0x60];
} fn_1_9CD6C_GlobalState;

typedef struct {
    f32 x, y, z;
} fn_1_98E18_Vec;

typedef struct {
    u8 pad0[0x4c];
    fn_1_98E18_Vec dir;
    fn_1_98E18_Vec pos;
    u8 pad64[0x10];
    f32 radius;
} fn_1_98E18_Burner;

typedef struct {
    u8 pad0[0x4];
    void (*callback)(void);
    fn_1_98E18_Burner *entry;
} fn_1_98E18_Event;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} fn_1_9CCE8_Vec3;

typedef struct {
    u8 pad[0x1e];
    u8 count;
} Burner;

struct FormatTable {
    const char *fmt[44][6];
};

struct FormatEntry {
    s16 f[5];
};

struct EntryTable {
    struct FormatEntry e[44];
};

struct fn_1_98804_Arg0 {
    u32 unk_0;
    u32 unk_4;
};

typedef struct {
    u8 pad[8];
    u8 *entries;
} fn_1_9D360_BurnerTable;

extern void fn_1_98840(Node *node);
extern void *fn_1_5448C(fn_1_98E18_Vec *pos);
extern void fn_8006E294(fn_1_9CCE8_Vec3 *);
extern void fn_80077F8C(Burner *);
extern const struct FormatTable lbl_1_rodata_7050;
extern const struct EntryTable lbl_1_rodata_6E38;
extern void fn_1_98804(struct fn_1_98804_Arg0 *arg0);
extern void fn_1_9D360(Burner *burner, fn_1_9D360_BurnerTable *table, u8 *indices);

#endif  // GAME_MAIN_REL_BURNER_TYPES_H
