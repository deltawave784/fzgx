#include "types.h"

typedef int (*Fn)(int, int, int, int);

typedef struct Tbl {
    Fn *items[15];
} Tbl;

static inline int fn_12_2F7AC_fzgx_inl(Tbl *dst, Tbl *src, int result) {
    int i = 0;

    *dst = *src;
    for (; i < 15; i++) {
        Fn *o = src->items[i];
        if (o == 0) {
            break;
        }
        result = (*o)(0, 0, 0, 0);
        if (result != 0) {
            break;
        }
    }
    return result;
}

int fn_12_2F7AC(Tbl *dst, Tbl *src) {
    return fn_12_2F7AC_fzgx_inl(dst, src, 0);
}
