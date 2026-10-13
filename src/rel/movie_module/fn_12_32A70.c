#include "types.h"

typedef struct MovieContext {
    s32 state;
    u32 movie;
    u8 pad_8[0x4];
    s32 kind;
} MovieContext;

static inline s32 state_valid(s32 state) {
    s32 result = 0;
    switch (state) {
    case -1:
    case 0:
    case 1:
        return 0;
        break;
    default:
        result = 1;
        break;
    }
    return result;
}

static inline u32 classify(u32 c) {
    if (c >= 0xC0 && c <= 0xDF) {
        return 0xC0;
    } else if (c >= 0xE0 && c <= 0xEF) {
        return 0xE0;
    } else if (c == 0xBD || c == 0xBF) {
        return 0xBD;
    }
    return 0;
}

static inline u32 find_entry(u32 base, u32 key) {
    s32 i;
    u32 e;
    u32 found;
    found = 0;
    for (i = 0; i < 26; i++) {
        e = (u32)((u8 *)base + 384 + i * 64);
        if (*(u8 *)(e + 24) == (u8)key) {
            found = e;
            break;
        }
    }
    return found;
}

static inline u32 lookup(MovieContext *self, u8 key) {
    u32 movie;
    s32 valid;
    movie = self->movie;
    if (state_valid(self->state) == 0) {
        valid = 0;
    } else {
        s32 kind;
        s32 ok;
        kind = self->kind;
        ok = 0;
        if (kind == 107 || kind >= 110) ok = 1;
        if (ok == 0) valid = 0;
        else valid = 1;
    }
    if (valid == 0) {
        return 0;
    }
    return find_entry(movie, key);
}

static inline u32 entry_flag(u32 entry, u8 key, u32 type) {
    u8 b;
    if (classify(key) != type) {
        return 0;
    }
    b = *(u8 *)(entry + 0x20);
    if (b > 1) {
        return 0;
    } else if (b == 0) {
        return 0;
    }
    return 1;
}

s32 fn_12_32A70(MovieContext *self, u8 key, u32 *out) {
    u32 entry;
    if (self->kind < 110) {
        return 0;
    }
    switch (classify(key)) {
    case 0xC0:
        entry = lookup(self, key);
        if (entry == 0) {
            return 0;
        }
        *out = entry_flag(entry, key, 0xC0);
        break;
    case 0xE0:
        entry = lookup(self, key);
        if (entry == 0) {
            return 0;
        }
        *out = entry_flag(entry, key, 0xE0);
        break;
    default:
        return 0;
    }
    return 1;
}
