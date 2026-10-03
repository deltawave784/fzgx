#include "types.h"

typedef struct FstEntry {
    u32 nameOffset; /* low 24 bits: offset in the string table */
    u32 parent;
    u32 next;
} FstEntry;

typedef struct FstInfo {
    u8 pad_0[0x4];
    FstEntry *entries;
    u8 pad_8[0x8];
    u8 *strings;
} FstInfo;

static u32 myStrncpy(u8 *dest, u8 *src, u32 maxlen) {
    u32 i = maxlen;

    while ((i > 0) && (*src != 0)) {
        *dest++ = *src++;
        i--;
    }
    return maxlen - i;
}

/* Builds the "/dir/.../name" path of an FST entry; returns its length. */
u32 fn_8006A768(FstInfo *fst, u32 entry, u8 *path, u32 maxlen) {
    u8 *name;
    u32 loc;
    FstEntry *entries = fst->entries;

    if (entry == 0) {
        return 0;
    }
    name = fst->strings + (entries[entry].nameOffset & 0xFFFFFF);
    loc = fn_8006A768(fst, entries[entry].parent, path, maxlen);
    if (loc == maxlen) {
        return loc;
    }
    *(path + loc++) = '/';
    loc += myStrncpy(path + loc, name, maxlen - loc);
    return loc;
}
