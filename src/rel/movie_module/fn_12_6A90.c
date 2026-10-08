#include "types.h"

typedef struct MovieState { s32 state; } MovieState;
typedef struct MovieError { void (*callback)(void *, s32); void *arg; s32 error; } MovieError;
extern u32 lbl_12_bss_4DB0;
extern u32 lbl_12_bss_4DB8[2];

s32 fn_12_6A90(MovieState *module) {
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
