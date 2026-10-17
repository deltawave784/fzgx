#include "types.h"
extern int fn_12_23F34(void *);
extern s32 fn_12_24A88(void *, s32);
extern void fn_12_20CE8(void);
extern s32 fn_8004B9A4(u8 *, s32, s32 *);
extern s32 fn_8004B974(u8 *, u32, u32 *);
typedef struct Movie {
    u8 pad_0000[0x3c];
    void (*field_003c)(void);
} Movie;
typedef struct MovieModule {
    u8 pad_0000[0x1b74];
    Movie *field_1b74;
} MovieModule;
static inline s32 find_start(MovieModule *arg0, u8 *arg1, s32 arg2, s32 zero) {
    u8 *start;
    u8 *scan;
    u8 *end;
    u8 *bestStart;
    u8 *best;
    s32 found;
    u32 info;

    found = zero;
    start = arg1;
    best = (u8 *)found;
    end = arg1 + arg2;
    bestStart = (u8 *)found;
    while (start < arg1 + 0x24) {
        found = 0;
        for (scan = start; scan < end; scan += 0x12) {
            if ((s8)*scan < 0) {
                found = 1;
                if (fn_8004B974(scan, 0x12, &info) && best < scan) {
                    best = scan;
                    bestStart = start;
                }
                break;
            }
        }
        if (!found) break;
        start += 2;
    }
    if (found) {
        if (bestStart == 0) {
            fn_12_24A88(arg0, 0xff000c0a);
            start = arg1;
        } else {
            start = bestStart;
        }
    }
    return start - arg1;
}

void fn_12_20B90(MovieModule *arg0, u8 *arg1, s32 arg2, s32 *arg3) {
    Movie *movie;
    s32 result;
    s32 count;

    *arg3 = 0;
    movie = arg0->field_1b74;
    if (arg2 >= 0x120) {
        if (fn_8004B9A4(arg1, arg2, &count)) {
            result = count;
        } else if (fn_12_23F34(arg0) >= 0x6c) {
            result = 0;
        } else {
            result = find_start(arg0, arg1, arg2, 0);
        }
        movie->field_003c = fn_12_20CE8;
        *arg3 = result;
    }
}
