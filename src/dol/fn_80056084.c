#include "types.h"
#include "dolphin/dvd.h"

typedef struct Sig_DVDOpen_DVDFileInfo Sig_DVDOpen_DVDFileInfo;
typedef void (*Sig_DVDOpen_DVDCallback)(s32 result, Sig_DVDOpen_DVDFileInfo *fileInfo);
struct Sig_DVDOpen_DVDFileInfo {
    DVDCommandBlock cb;
    u32 startAddr;
    u32 length;
    Sig_DVDOpen_DVDCallback callback;
};

typedef void (*fn_80056084_ErrFn)(u32, char *, u32);

typedef struct Fn80056084_File {
    s8 used;
    u8 pad1;
    u8 unk2;
    u8 pad3[5];
    u32 unk8;
    u8 padC[4];
    s32 sectorSize;
    s32 length;
    s32 sectorCount;
    u32 unk1C;
    u32 unk20;
    u32 unk24;
    Sig_DVDOpen_DVDFileInfo info;
} Fn80056084_File;

typedef struct Fn80056084_Mgr {
    u8 pad0[0xC];
    u32 errCtx;
    fn_80056084_ErrFn errFn;
    Fn80056084_File files[40];
} Fn80056084_Mgr;

extern Fn80056084_Mgr lbl_801878B8;
extern u8 lbl_80188870[];
extern char lbl_80091F50[];
extern BOOL DVDOpen(const char *, Sig_DVDOpen_DVDFileInfo *);
extern char *fn_80083DB0(char *, const char *);
extern char *strcat(char *, const char *);
extern size_t strlen(const char *);
extern void *memset(void *, int, u32);

static inline Fn80056084_File *fn_80056084_FindFree(Fn80056084_File *files) {
    Fn80056084_File *found;
    Fn80056084_File *scan;
    s32 i;

    found = 0;
    scan = files;
    for (i = 0; i < 40; scan++, i++) {
        if (scan->used == 0) {
            found = files;
            found += i;
            break;
        }
    }
    return found;
}

static inline s32 fn_80056084_DivUp(s32 unit, s32 size) {
    return (unit - 1 + size) / unit;
}

Fn80056084_File *fn_80056084(char *name, u32 arg1, s32 mode) {
    struct { u32 a[65]; } buf;
    Fn80056084_File *file;
    Fn80056084_Mgr *mgr;
    char *base;
    char *p;
    Fn80056084_File *files;
    u32 n;
    s32 i;
    s32 len;

    base = lbl_80091F50;
    mgr = &lbl_801878B8;
    if (name == 0) {
        if (mgr->errFn != 0) {
            mgr->errFn(mgr->errCtx, base + 0x110, 0);
        }
        return 0;
    }
    if (mode != 0) {
        if (mgr->errFn != 0) {
            mgr->errFn(mgr->errCtx, base + 0x134, 0);
        }
        return 0;
    }
    file = fn_80056084_FindFree(mgr->files);
    if (file == 0) {
        if (mgr->errFn != 0) {
            mgr->errFn(mgr->errCtx, base + 0x158, 0);
        }
        return 0;
    }
    fn_80083DB0((char *)&buf, (const char *)lbl_80188870);
    strcat((char *)&buf, name);
    n = strlen((char *)&buf);
    p = (char *)&buf;
    for (i = 0; i < n; i++) {
        if ((s32)p[i] == '\\') {
            p[i] = '/';
        }
    }
    if (!DVDOpen((char *)&buf, &file->info)) {
        if (mgr->errFn != 0) {
            mgr->errFn(mgr->errCtx, base + 0x188, 0);
        }
        memset(file, 0, sizeof(Fn80056084_File));
        return 0;
    }
    file->sectorSize = 0x800;
    len = file->info.length;
    if (len & ~0x7fffffff) {
        len = 0x7fffffff;
    }
    file->length = len;
    file->sectorCount = fn_80056084_DivUp(file->sectorSize, file->length);
    file->unk1C = 0;
    file->unk8 = 0;
    file->unk24 = 0;
    file->unk20 = 0;
    file->unk2 = 0;
    file->used = 1;
    return file;
}
