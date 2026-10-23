#include "types.h"

typedef struct MovieContext {
    int state;
    u8 *movie;
    u8 _pad[4];
    int kind;
} MovieContext;

static inline u8 *fn_12_31CA4_find(u8 *movie, u32 code) {
    int i;
    u8 *e;
    u8 *r;
    u8 *base = movie;
    r = 0;
    for (i = 0; i < 26; i++) {
        e = base + i * 0x40 + 0x180;
        if (e[0x18] == (u8)code) {
            r = e;
            break;
        }
    }
    return r;
}
#pragma peephole off
static inline u32 fn_12_31CA4_swap(const u8 *p) {
    u32 v = *(const u32 *)(p + 0x1c);
    u32 rotated;
    u32 r = __rlwinm(v, 8, 8, 15);
    r = __rlwimi(r, v, 24, 0, 7);
    r = __rlwimi(r, v, 24, 16, 23);
    rotated = __rlwinm(v, 8, 0, 31);
    r = __rlwimi(r, rotated, 0, 24, 31);
    return r;
}
#pragma peephole on
static inline u8 * fn_12_31CA4_read_pointer(MovieContext * owner) { return owner->movie; }
int fn_12_31CA4(MovieContext *self, u8 code, u32 *result) {
    int kind_ok;
    int kind;
    u8 *movie = fn_12_31CA4_read_pointer(self);
    int ok;
    u8 *found;
    int i;
    u8 c;
    u8 *p;
    u32 v;
    u32 cls;

    switch (self->state) {
    case -1: case 0: case 1: {
        ok = 0;
    } break;
    default: {
        ok = 1;
    } break;
    }

    if (ok == 0) {
        ok = 0;
    } else {
        kind = self->kind;
        kind_ok = 0;
        if (kind == 0x6b || kind >= 0x6e) {
            kind_ok = 1;
        }
        if (!(kind_ok != 0)) {
            ok = 0;
        } else {
            ok = 1;
        }
    }

    if (ok == 0) {
        found = 0;
    } else {
        found = fn_12_31CA4_find(movie, code);
    }
    if (found == 0) {
        return 0;
    }

    c = (u8)code;
    if (c >= 0xc0 && c <= 0xdf) {
        cls = 0xc0;
    } else if (c >= 0xe0 && c <= 0xef) {
        cls = 0xe0;
    } else if (c == 0xbd || c == 0xbf) {
        cls = 0xbd;
    } else {
        cls = 0;
    }
    if (cls != 0xc0) {
        return 0;
    }
    *result = fn_12_31CA4_swap(found);
    return 1;
}
#pragma peephole reset
