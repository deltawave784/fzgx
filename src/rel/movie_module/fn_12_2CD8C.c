#include "types.h"

extern const u32 lbl_12_rodata_C78[102];
typedef void (*Sig_fn_12_24A88_MovieCallback)(void *, s32);
typedef struct Sig_fn_12_24A88_MovieObject {
    u8 pad_0000[0x48];
    s32 state;
    u8 pad_004c[0x940];
    Sig_fn_12_24A88_MovieCallback callback;
    void *callback_context;
    s32 callback_data;
} Sig_fn_12_24A88_MovieObject;
extern s32 fn_12_24A88(Sig_fn_12_24A88_MovieObject *, s32);

void fn_12_2CD8C(void) {
    struct { const u32 *value; } table;
    table.value = lbl_12_rodata_C78;
    if (table.value[0x49] != 0x5a5a5a5a) {
        fn_12_24A88(0, 0xff000201);
    }
}
