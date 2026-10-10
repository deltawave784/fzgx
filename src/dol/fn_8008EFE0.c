#include "types.h"

extern u32 fn_8008E770(u32, u32, u32, u32);
extern u32 fn_8008E9B4(u32);
extern u32 fn_8008EBF8(u32);
extern u32 fn_8008EC78(void);
extern int printf(const char *, ...);
extern char lbl_8015B900[];
extern s32 lbl_801A6E1C;
extern u8 *lbl_801A6680;

u32 fn_8008EFE0(u8 *buf, u32 len) {
    u32 i;
    u32 odd;
    s32 rem;
    s32 off;
    s32 ok;
    s32 status;
    u32 n;
    u32 size;
    s32 j;
    s32 count;
    u32 word;
    u32 loc_1C;
    u32 loc_14[2];

    if (lbl_801A6E1C != 0) {
        ok = 1;
    } else {
        status = 0;
        while (status == 0) {
            status = fn_8008EBF8(5);
        }
        ok = status;
        if (status == 0) {
            printf(lbl_8015B900);
            ok = 0;
        } else {
            lbl_801A6E1C = 1;
            loc_14[0] = 0;
            fn_8008E9B4(fn_8008E770((u32)loc_14, 2, 1, 0));
            fn_8008E9B4(fn_8008E770((u32)&loc_1C, 2, 0, 0));
        }
    }
    if (ok == 0) {
        return 1;
    }

    n = (len >> 2) + ((len & 3) ? 1 : 0);
    odd = (len & 3) + (len & 1);
    rem = (s32)len % 4;
    off = 0;
    i = 0;
    while (off < len) {
        if (i < n - 1) {
            size = 4;
        } else if (odd == 2) {
            size = 2;
        } else {
            size = 4;
        }
        fn_8008E9B4(fn_8008E770((u32)&word, size, 0, 0));
        if (len - off >= 4) {
            count = 4;
        } else {
            count = rem;
        }
        for (j = 0; j < count; j++) {
            buf[off + j] = word >> ((3 - j) * 8);
        }
        i++;
        off += 4;
    }
    fn_8008EC78();
    lbl_801A6E1C = 0;
    *lbl_801A6680 = 0;
    return 0;
}
