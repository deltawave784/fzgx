#include "types.h"

typedef struct Fn8006A9B4Entry {
    u32 flags;
    u32 b;
    u32 c;
} Fn8006A9B4Entry;

typedef struct Fn8006A9B4Data {
    u8 _pad0[4];
    Fn8006A9B4Entry *entries;
    u8 _pad8[0x10];
    s32 index;
} Fn8006A9B4Data;

extern s32 fn_8006A554(Fn8006A9B4Data *data);

static inline s32 entryActive(Fn8006A9B4Entry *e, s32 idx) {
    if ((e[idx].flags & 0xFF000000) == 0) {
        return 0;
    }
    return 1;
}

s32 fn_8006A9B4(Fn8006A9B4Data *data) {
    s32 idx = fn_8006A554(data);
    Fn8006A9B4Entry *e = data->entries;
    if (idx < 0 || !entryActive(e, idx)) {
        return 0;
    }
    data->index = idx;
    return 1;
}
