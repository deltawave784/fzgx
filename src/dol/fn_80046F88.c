#include "types.h"

extern char * fn_80083CF4(char *, const char *, size_t);
extern size_t strlen(const char *);
extern char lbl_80090970[];
extern u8 lbl_8017B038[288];

#pragma opt_strength_reduction off
void fn_80046F88(s32 arg0, s32 arg1, void *arg2, s32 arg3) {
    s32 v4;
    size_t t0;
    s32 v22;
    s32 v26;
    size_t t1;
    size_t t3;
    size_t t4;
    s32 v41;
    void *v42;
    s32 v46;
    s32 v47;
    s32 v65;
    s32 v69;
    size_t t5;
    for (v4 = 0; v4 < 32; v4++) {
        ((u8 *)arg2)[v4] = arg0 % 10;
        arg0 /= 10;
        if (arg0 == 0) {
            *(u8 *)((u8 *)arg2 + v4) = 0;
            break;
        }
    }
    t0 = strlen((const char *)lbl_8017B038);
    v22 = (s32)t0 < arg3 - 1 ? (s32)t0 : arg3 - 1;
    for (v26 = 0; v26 < v22; v26++) {
        ((u8 *)arg2)[v26] = lbl_8017B038[v22 - 1 - v26];
    }
    *(u8 *)((u8 *)arg2 + v26) = 0;
    t1 = arg3 - strlen((const char *)arg2);
    fn_80083CF4((char *)arg2, lbl_80090970, t1 - 1);
    t3 = strlen((const char *)arg2);
    arg3 = 4 - t3;
    t4 = strlen((const char *)arg2);
    arg2 = (u8 *)arg2 + t4;
    v47 = arg1;
    for (v46 = 0; v46 < 32; v46++) {
        ((u8 *)arg2)[v46] = v47 % 10;
        v47 /= 10;
        if (v47 == 0) {
            *(u8 *)((u8 *)arg2 + v46) = 0;
            break;
        }
    }
    t5 = strlen((const char *)lbl_8017B038);
    v65 = arg3 - 1;
    if ((s32)t5 < v65) {
        v65 = t5;
    }
    for (v69 = 0; v69 < v65; v69++) {
        ((u8 *)arg2)[v69] = lbl_8017B038[v65 - 1 - v69];
    }
    *(u8 *)((u8 *)arg2 + v69) = 0;
}
