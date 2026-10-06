#include "types.h"

typedef struct MovieContext {
    int state;
    void *movie;
    u8 _pad[4];
    int kind;
} MovieContext;

static inline s16 fn_12_32714_array_read(s16 *array, s32 index) {
    s16 value = array[index];
    return (s16)(u16)(((value << 8) & 0xff00) | ((value >> 8) & 0xff));
}
#pragma peephole off
int fn_12_32714(MovieContext *self, s32 *result) {
    int kind_ok;
    int kind;
    s16 *movie = (s16 *)self->movie;
    int ok;

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
        kind = self->kind;
        kind_ok = 0;
        if (kind == 0x6b || kind >= 0x6e) {
            kind_ok = 1;
        }
        if (!(kind_ok != 0)) {
            ok = 0;
        } else {
            ok = 1;
        }
    }
    if (ok == 0) {
        return 0;
    }
#pragma peephole on
    *result = fn_12_32714_array_read(movie, 0x44);
    return 1;
}
#pragma peephole reset
