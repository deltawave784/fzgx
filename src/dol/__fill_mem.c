#include "types.h"

__declspec(section ".init") void __fill_mem(void * arg0, int arg1, u32 arg2) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v5;
    char *byteDest;
    u32 v4;
    u32 *wordDest;
    v0 = (u32)arg0 - 1;
    v1 = (arg1 & 0xFF);
    v2 = (u32)(arg0);
    v3 = arg2;
    v4 = (u8)arg1;
    v5 = v0;
    byteDest = (char *)v5;
    if (arg2 >= 32) {
        v2 = (~(u32)byteDest) & 3;
        if (v2 != 0) {
            v3 = (v3 - v2);
            do {
                *++byteDest = v4;
            } while (--v2 != 0);
        }
        if (v4 != 0) {
            v4 = (v4 << 24) | (v4 << 16) | (v4 << 8) | v4;
        }
        v2 = v3 >> 5;
        wordDest = (u32 *)(byteDest - 3);
        if (v2 != 0) {
            do {
                *++wordDest = v4;
                *++wordDest = v4;
                *++wordDest = v4;
                *++wordDest = v4;
                *++wordDest = v4;
                *++wordDest = v4;
                *++wordDest = v4;
                *++wordDest = v4;
            } while (--v2 != 0);
        }
        v2 = (v3 >> 2) & 7;
        if (v2 != 0) {
            do {
                *++wordDest = v4;
            } while (--v2 != 0);
        }
        byteDest = (char *)wordDest + 3;
        v3 &= 3;
    }
    if (v3 != 0) {
        do {
            *++byteDest = v4;
        } while (--v3 != 0);
    }
}
