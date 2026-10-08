#ifndef GAME_MAIN_REL_MEMCARD_TYPES_H
#define GAME_MAIN_REL_MEMCARD_TYPES_H

// Types (and the externs that name them) of memcard.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).

#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/memcard.h"
#include "dolphin/card.h"
#include "dolphin/card/CARDPriv.h"
#include "dolphin/dvd.h"
#include "dolphin/os/OSTime.h"
#include "font.h"

typedef struct MgrRoot {
    u32 unk_0;
} MgrRoot;

typedef struct MemcardDvdFileInfo {
    u8 pad_0[0x3C];
} MemcardDvdFileInfo;

typedef struct Sig_DVDOpen_DVDFileInfo Sig_DVDOpen_DVDFileInfo;
typedef void (*Sig_DVDOpen_DVDCallback)(s32 result, Sig_DVDOpen_DVDFileInfo *fileInfo);

struct Sig_DVDOpen_DVDFileInfo {
    DVDCommandBlock cb;
    u32 startAddr;
    u32 length;
    Sig_DVDOpen_DVDCallback callback;
};

typedef struct Sig_fn_800174D0_Fn800174D0Object {
    u8 pad30[0x30];
    u32 field30;
    u32 field34;
    void *field38;
} Sig_fn_800174D0_Fn800174D0Object;

typedef struct {
    u8 pad_0[0x14];
    s8 type;
    s16 first;
    s16 second;
    s16 third;
    s16 fourth;
} Fn1C0510Obj;

typedef struct {
    u8 unk0[0x16];
    s16 unk16;
} Fn1C132CObject;

typedef struct TimeParts {
    u32 unused;
    u32 field_4;
    u32 field_8;
    u32 field_C;
    u32 field_10;
    u32 field_14;
    u32 spare_18;
    u32 spare_1C;
} TimeParts;

extern s32 DVDOpen(const char *, MemcardDvdFileInfo *);
extern s32 fn_80006354(MemcardDvdFileInfo *, void *, u32, u32);
extern void fn_1_C062C(Fn1C0510Obj *, void *, void *);
extern void fn_1_C0B0C(Fn1C0510Obj *, void *, void *);
extern void fn_1_C0E00(Fn1C0510Obj *, void *, void *);

#endif  // GAME_MAIN_REL_MEMCARD_TYPES_H
