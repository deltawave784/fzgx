#include "types.h"
typedef struct Sig_fn_8006A554_Fn8006A9B4Entry {
    u32 flags;
    u32 b;
    u32 c;
} Sig_fn_8006A554_Fn8006A9B4Entry;
typedef struct Sig_fn_8006A554_Fn8006A9B4Data {
    u8 _pad0[4];
    Sig_fn_8006A554_Fn8006A9B4Entry *entries;
    u8 _pad8[8];
    u8 *strings;
    u32 unk14;
    s32 index;
} Sig_fn_8006A554_Fn8006A9B4Data;
extern s32 fn_8007ED90(s32);

static inline s32 isdir(u32 flags) {
    if ((flags & 0xFF000000) == 0) return 0;
    else return 1;
}
static inline Sig_fn_8006A554_Fn8006A9B4Entry *getEntry(Sig_fn_8006A554_Fn8006A9B4Entry *entries, u32 index) {
    return &entries[index];
}
static inline s32 hasSlash(u8 *p) {
    if (*p == 0) return 0;
    else return 1;
}
static inline u32 nextEntry(Sig_fn_8006A554_Fn8006A9B4Entry *entries, u32 index) {
    if (isdir(entries[index].flags)) return entries[index].c;
    return index + 1;
}
static inline s32 same(u8 *path, u8 *name) {
    s32 ch;
    s32 other;
    while (*name != 0) {
        ch = fn_8007ED90(*name++);
        other = fn_8007ED90(*path++);
        if (other != ch) return 0;
    }
    if (*path == '/' || *path == 0) return 1;
    else return 0;
}
u32 fn_8006A554(Sig_fn_8006A554_Fn8006A9B4Data *arg0, u32 arg1) {
    s32 v8;
    Sig_fn_8006A554_Fn8006A9B4Entry *v11;
    u32 v9;
    u32 v12;
    Sig_fn_8006A554_Fn8006A9B4Entry *v0;
    u8 *v3 = (u8 *)arg1;
    u32 v2;
    u8 *v6;
    u32 flags;
    v2 = arg0->index;
    v0 = arg0->entries;
    for (;;) {
        if (*v3 == 0) return v2;
        if (*v3 == '/') {
            v2 = 0;
            v3++;
            continue;
        }
        if (*v3 == '.') {
            if (v3[1] == '.') {
                if (v3[2] == '/') {
                    v2 = v0[v2].b;
                    v3 += 3;
                    continue;
                }
                if (v3[2] == 0) return v0[v2].b;
            } else {
                if (v3[1] == '/') {
                    v3 += 2;
                    continue;
                }
                if (v3[1] == 0) return v2;
            }
        }
        v6 = v3;
        while (*v6 != 0 && *v6 != '/') v6++;
        v8 = hasSlash(v6);
        v9 = v6 - v3;
        v12 = v2 + 1;
        v11 = getEntry(v0, v2);
        while (v12 < v11->c) {
            Sig_fn_8006A554_Fn8006A9B4Entry *v13ptr = &v0[v12];
            flags = v13ptr->flags;
            if (isdir(flags) != 0 || v8 != 1) {
                /* A successful component skips the search-failure return. */
                if (same(v3, arg0->strings + (flags & 0xFFFFFF)) == 1) goto found;
            }
            v12 = nextEntry(v0, v12);
        }
        return -1;
found:
        if (v8 == 0) return v12;
        v3 = (u8 *)(v9 + (u32)v3);
        v2 = v12;
        v3++;
    }
}
