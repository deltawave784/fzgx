#include "types.h"

typedef struct Obj {
    int pad;
    int (*fn)(int, int, int, int);
} Obj;

static inline int fn_12_2F730_fzgx_inl(Obj **list, int result) {
    int i;
    Obj **p = list;

    {
    int fzgx_loop_i_198;
for (fzgx_loop_i_198 = 0; fzgx_loop_i_198 < 15; fzgx_loop_i_198++, p++) {
        if (*p == 0) {
            break;
        }
        result = (*p)->fn(0, 0, 0, 0);
        if (result != 0) {
            break;
        }
    }
    i = fzgx_loop_i_198;
}
    return result;
}

int fn_12_2F730(Obj **list) {
    return fn_12_2F730_fzgx_inl(list, 0);
}
