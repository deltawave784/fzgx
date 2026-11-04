#include "dolphin/gx.h"
#include "types.h"

struct fn_80072168_S {
    u8 pad_0[0xc];
    u32 unk_c;
    u8 pad_10[0x14];
    u32 unk_24;
    u8 pad_28[4];
    u32 unk_2c;
};

struct fn_80072168_GX {
    u16 pad_0;
    u16 unk_2;
};

extern struct fn_80072168_S lbl_8019E250[];
extern struct fn_80072168_GX *gx;

#pragma opt_common_subs off
#pragma opt_propagation off
static inline void fn_80072168_flush(u32 value) {
    u32 data = value;
    u32 command = 0x61;
    gx->unk_2 = 0;
    GXWGFifo.u8 = command;
    GXWGFifo.u32 = data;
}

void fn_80072168(s32 arg0) {
    struct fn_80072168_S *p;
    u32 v;
    u32 mode;
    p = lbl_8019E250;
    if (!(p->unk_2c & 1)) {
        return;
    }
    if (arg0 != 0) {
        v = p->unk_24;
        mode = p->unk_c;
        if (((v >> 21) & 7) == mode) {
            return;
        }
        fn_80072168_flush(p->unk_24 = (v & 0xFF1FFFFF) | (mode << 21));
    } else {
        v = p->unk_24;
        if (((v >> 21) & 7) == 0) {
            return;
        }
        fn_80072168_flush(p->unk_24 = v & 0xFF1FFFFF);
    }
}
#pragma opt_common_subs reset
#pragma opt_propagation reset
