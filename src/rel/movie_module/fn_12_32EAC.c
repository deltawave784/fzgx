#include "types.h"

typedef struct SfdHeaderInfo {
    s32 state;
    u8 *buf;
    u32 size;
    s32 version;
} SfdHeaderInfo;

extern char lbl_12_rodata_10E4[25];
extern char lbl_12_rodata_10DC[5];
extern s32 fn_8008023C(u8 *, char *, u32);
extern void *memset(void *, int, u32);
extern void *memcpy(void *, const void *, u32);
extern s8 *fn_80083970(s8 *, char *);

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

static inline s32 is_closed(s32 state) {
    return state == 0;
}

static inline s32 read_header(SfdHeaderInfo *info, s8 *buf) {
    s32 state = info->state;
    u8 *src = info->buf + 0x60;
    if (state_valid(state) == 0) {
        return 0;
    }
    memset(buf, 0, 33);
    memcpy(buf, src, 32);
    return 1;
}

static inline s32 is_digit(s32 c) {
    s32 result = 0;
    if (c >= '0' && c <= '9') {
        result = 1;
    }
    return result;
}

static inline s8 *parse_num(s8 *s, s32 *out) {
    s32 c;
    s32 v = 0;
    for (;;) {
        c = *s;
        if (c == '.' || c == ' ' || c == '\0') {
            break;
        }
        if (is_digit(c) == 0) {
            break;
        }
        v = v * 10 + c;
        v -= '0';
        s++;
    }
    *out = v;
    return s;
}

static inline s32 parse_version(s8 *buf, s32 *major, s32 *minor) {
    s8 *p = fn_80083970(buf, lbl_12_rodata_10DC);
    if (p == 0) {
        return 0;
    }
    p = parse_num(p + 4, major);
    parse_num(p + 1, minor);
    return 1;
}

static inline s32 get_version(SfdHeaderInfo *info, s32 *major, s32 *minor) {
    s8 buf[33];
    if (read_header(info, buf) == 0) {
        return 0;
    }
    if (parse_version(buf, major, minor) == 0) {
        return 0;
    }
    return 1;
}

s32 fn_12_32EAC(SfdHeaderInfo *info, s32 *ok) {
    s32 major;
    s32 minor;
    u8 *hdr;

    *ok = 0;
    hdr = info->buf + 0x20;
    if (is_closed(info->state) == 1) {
        return 0;
    }
    if (info->size < 0x800) {
        info->state = -1;
        return 0;
    }
    if (fn_8008023C(hdr, lbl_12_rodata_10E4, 24) != 0) {
        info->state = -1;
        return 0;
    }
    info->state = 2;
    if (get_version(info, &major, &minor) == 0) {
        return 0;
    }
    info->version = minor + major * 100;
    *ok = 1;
    return 1;
}
