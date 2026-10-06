#include "types.h"

extern u32 fn_8008E770(u32, u32, u32, u32);
extern u32 fn_8008E9B4(u32);
extern u32 fn_8008EBF8(u32);
extern u32 fn_8008EC78(void);

u32 fn_8008F29C(u32 *buf, u32 arg1) {
    u32 len = arg1;
    u32 cmd;
    u32 loc_18[3];
    u32 loc_10[2];
    s32 status;
    u32 i;
    u32 *p;
    u32 n;
    u32 size;

    status = 0;
    while (status == 0) {
        status = fn_8008EBF8(5);
    }
    if (status == 0) {
        return 1;
    }

    loc_18[0] = 0x80000000;
    fn_8008E9B4(fn_8008E770((u32)loc_18, 2, 1, 0));
    fn_8008E9B4(fn_8008E770((u32)&len, 4, 1, 0));

    n = (len >> 2) + ((len & 3) ? 1 : 0);
    p = buf;
    for (i = 0; i < n; i++) {
        if (i < n - 1) {
            size = 4;
        } else if ((len & 3) + (len & 1) == 2) {
            size = 2;
        } else {
            size = 4;
        }
        fn_8008E9B4(fn_8008E770((u32)p++, size, 1, 0));
    }
    fn_8008EC78();

    status = 0;
    while (status == 0) {
        status = fn_8008EBF8(5);
    }
    if (status == 0) {
        return 1;
    }

    loc_10[0] = 0x10000;
    fn_8008E9B4(fn_8008E770((u32)loc_10, 2, 1, 0));
    fn_8008E9B4(fn_8008E770((u32)&cmd, 2, 0, 0));
    do {
        fn_8008E9B4(fn_8008E770((u32)&cmd, 2, 0, 0));
    } while (((cmd >> 16) & 1) == 0);
    fn_8008EC78();
    return 0;
}
