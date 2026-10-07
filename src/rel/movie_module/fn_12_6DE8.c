#include "types.h"

typedef struct MovieState {
    s32 state;
    u8 padding[188];
} MovieState;
typedef struct MovieError {
    void (*callback)(void *, s32);
    void *arg;
    s32 error;
    s32 count;
    MovieState slots[1];
} MovieError;
extern u32 lbl_12_bss_4DB0;
extern u32 lbl_12_bss_4DB8[2];
extern void fn_12_6704(void);
extern void fn_12_6A88(void);

static inline s32 reset_movie(MovieState *module) {
    s32 invalid;
    MovieError *handler;
    lbl_12_bss_4DB0 = (u32)module;
    if (module == 0) invalid = -1;
    else if (module->state == 1) invalid = -1;
    else invalid = 0;
    if (invalid) {
        handler = (MovieError *)lbl_12_bss_4DB8[0];
        handler->error = 0xff020103;
        if (handler->callback) handler->callback(handler->arg, 0xff020103);
        return 0xff020103;
    }
    module->state = 1;
    return 0;
}

void fn_12_6DE8(void) {
    s32 i;
    s32 count;
    MovieError *pool;
    MovieState *slots;
    pool = (MovieError *)lbl_12_bss_4DB8[0];
    count = pool->count;
    slots = pool->slots;
    for (i = 0; i < count; i++) {
        if (slots[i].state != 1) reset_movie(&slots[i]);
    }
    fn_12_6704();
    fn_12_6A88();
}
