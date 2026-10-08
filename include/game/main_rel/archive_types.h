#ifndef GAME_MAIN_REL_ARCHIVE_TYPES_H
#define GAME_MAIN_REL_ARCHIVE_TYPES_H

// Types (and the externs that name them) of archive.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).

#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/archive.h"

struct fn_1_12B120_lbl_1_rodata_8178 {
    f64 unk_0;
};

typedef struct {
    u16 unk0;
    u32 unk4;
    u8 unk8;
    u8 pad9[3];
    u32 unkC;
    u32 unk10;
    u32 unk14;
    u32 unk18;
} fn_1_12C0EC_FnData;

typedef struct Fn1_12F30CState {
    s32 value;
} Fn1_12F30CState;

struct Ent {
    u8 b;
    u8 pad[3];
    u32 v[1];
};

struct Blk {
    u8 pad[0x81A4];
    struct Ent e[3];
    u8 pad2[4];
};

typedef struct {
    u8 pad0[5];
    u8 id;
    u8 pad6[0x819a];
    u8 value;
    u8 pad_a1[0x1f];
} fn_1_12C7B8_FnEntry;

typedef struct {
    u8 pad0[5];
    u8 id;
    u8 pad6[0x819a];
    u8 value;
    u8 pad_a1[0x1f];
} fn_1_12CB04_FnEntry;

typedef struct {
    u8 pad0[5];
    u8 id;
    u8 pad6[0x819a];
    u8 value;
    u8 pad_a1[0x1f];
} fn_1_12CCB0_FnEntry;

typedef struct {
    u8 pad0[5];
    u8 id;
    u8 pad6[0x819a];
    u8 value;
    u8 pad_a1[0x1f];
} fn_1_12ECA8_FnEntry;

typedef struct {
    s16 values[6];
} Entry;

typedef struct {
    Entry entries[11];
} EntryTable;

struct Table {
    s16 values[66];
};

typedef struct ArchiveEntry {
    u8 field_0[0x4c];
    u8 data[0x20];
} ArchiveEntry;

typedef struct lbl_1_bss_897AC_t {
    ArchiveEntry entries[1];
    u8 pad_6C[0x1ac8];
} lbl_1_bss_897AC_t;

typedef struct Sig_fn_1_41488_Fn41488Data {
    u32 count;
    char *strings;
} Sig_fn_1_41488_Fn41488Data;

typedef struct {
    u8 pad_0[0x24];
    Sig_fn_1_41488_Fn41488Data *strings;
} Fn12E0B8_Names;

typedef struct {
    u8 pad_0[0x18];
    u32 flags;
    u8 pad_1C[0x148 - 0x1C];
    u8 event[0x8];
    Fn12E0B8_Names *names;
    u8 pad_154[0x4E0 - 0x154];
} Fn12E0B8_Car;

typedef struct {
    u8 pad_0[0x5];
    u8 id;
    u8 pad_6[0x81A0 - 0x6];
    u8 kind;
    u8 pad_81A1[0x81C0 - 0x81A1];
} Fn12E0B8_Entry;

typedef struct { s32 v[41]; } Tbl;
extern Tbl lbl_1_rodata_8180;
extern int fn_1_41488(Sig_fn_1_41488_Fn41488Data *, const char *);
extern void fn_1_933D8(Fn12E0B8_Car *, void *, u16);
extern struct fn_1_12B120_lbl_1_rodata_8178 lbl_1_rodata_8178;
extern void fn_1_12C0EC(fn_1_12C0EC_FnData *arg);
extern EntryTable lbl_1_rodata_8338;
extern const struct Table lbl_1_rodata_8230;

#endif  // GAME_MAIN_REL_ARCHIVE_TYPES_H
