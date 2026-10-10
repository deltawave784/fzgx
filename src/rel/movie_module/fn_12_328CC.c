#include "types.h"

typedef struct MovieContext {
    int state;
    void *movie;
} MovieContext;

extern char lbl_12_rodata_10DC[5];
extern void * memset(void *, int, u32);
extern void * memcpy(void *, const void *, u32);
extern u8 * fn_80083970(u8 *, const u8 *);

static inline int fn_12_328CC_is_digit(int c) {
    int digit = 0;
    if (c >= '0' && c <= '9') {
        digit = 1;
    }
    return digit;
}

/* Parses a decimal field up to '.', ' ', NUL or a non-digit. */
static inline s32 fn_12_328CC_parse(char **pp) {
    char *p = *pp;
    int c;
    s32 n = 0;

    for (;;) {
        c = *p;
        if (c == '.' || c == ' ' || c == '\0' || !fn_12_328CC_is_digit(c)) {
            break;
        }
        n = n * 10 + c;
        n -= '0';
        p++;
    }
    *pp = p;
    return n;
}

int fn_12_328CC(MovieContext *self, s32 *major, s32 *minor) {
    char *p;
    int ok;
    char buf[33];
    u8 *src = (u8 *)self->movie + 0x60;

    switch (self->state) {
    case -1: case 0: case 1:
        ok = 0;
        break;
    default:
        ok = 1;
        break;
    }

    if (ok == 0) {
        ok = 0;
    } else {
        memset(buf, 0, sizeof(buf));
        memcpy(buf, src, 0x20);
        ok = 1;
    }

    if (ok == 0) {
        return 0;
    }

    p = (char *)fn_80083970((u8 *)buf, (const u8 *)lbl_12_rodata_10DC);
    if (p == NULL) {
        ok = 0;
    } else {
        p += 4;
        *major = fn_12_328CC_parse(&p);
        p++;
        *minor = fn_12_328CC_parse(&p);
        ok = 1;
    }

    if (ok == 0) {
        return 0;
    }
    return 1;
}
#pragma peephole reset
