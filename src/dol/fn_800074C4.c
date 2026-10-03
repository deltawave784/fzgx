#include "types.h"

extern u32 fn_80007654(u32);
extern u32 fn_80007730(u32);
extern char lbl_801221A0[26];
extern char lbl_801A6400[6];
extern void OSPanic(const char *, int, const char *, ...);
extern void fn_80007664(void *, u32, u32);

typedef struct Entry {
    u32 a : 1;
    u32 b : 24;
    u32 c : 1;
    u32 d : 6;
    u8 pad[3];
    u8 e : 1;
    u8 f : 1;
    u8 g : 1;
    u8 h : 3;
    u8 i : 2;
} Entry;

void fn_800074C4(u32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5) {
    u32 v3;
    u32 v2;
    u32 v1 = arg3 & 0xFF;
    Entry *t0;
    u32 v7;
    u32 v6;
    u32 i;
    u32 n;
    v2 = arg4 & 0xFF;
    v3 = arg5 & 0xFF;

    n = (((0xFFF) + ((arg2) + ((arg1 & 0xFFF))))) >> 12;
    i = 0;
    v7 = arg0;
    v6 = arg1;
    for (; i < n; i++) {
        t0 = (Entry *)fn_80007730(v7);
        if (t0 == 0) {
            OSPanic(lbl_801A6400, 461, lbl_801221A0);
        }
        t0->b = fn_80007654(v7);
        t0->d = v7 >> 22;
        t0->f = v1;
        t0->g = v2;
        t0->i = v3;
        fn_80007664(t0, v7, v6);
        v7 += 0x1000;
        v6 += 0x1000;
    }
}
