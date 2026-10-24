#include "dolphin/gx.h"
#include "types.h"

struct fn_800720B0_lbl_8019E250 {
    u8 pad_0[0xC];
    u32 unk_C;
    u8 pad_10[0x14];
    u32 unk_24;
    u8 pad_28[0x4];
    u32 unk_2C;
};

struct fn_800720B0_gx {
    u8 pad_0[2];
    u16 unk_2;
};

extern struct fn_800720B0_lbl_8019E250 lbl_8019E250[];
extern struct fn_800720B0_gx *gx;

#pragma opt_common_subs off
#pragma opt_propagation off
static inline void fn_800720B0_write_bp_impl(u32 value) {
    u32 data = value;
    u32 command = 0x61;
    gx->unk_2 = 0;
    GXWGFifo.u8 = command;  /* fzgx-allow: S2 volatile view keeps the verified load order */
    GXWGFifo.u32 = data;  /* fzgx-allow: S2 volatile view keeps the verified load order */
}
#define fn_800720B0_write_bp(value, command) fn_800720B0_write_bp_impl(value)

void fn_800720B0(s32 arg0) {
    u32 flags;
    u32 mode;
    u32 v;
    struct fn_800720B0_lbl_8019E250 *p;
    if (arg0 != 0) {
        p = lbl_8019E250;
        flags = p->unk_2C;
        if (flags & 1) {
            return;
        }
        v = p->unk_24;
        mode = p->unk_C;
        p->unk_2C = flags | 1;
        if (((v >> 21) & 7) == mode) {
            return;
        }
        fn_800720B0_write_bp(p->unk_24 = (v & 0xFF1FFFFF) | (mode << 21), 0x61);
    } else {
        p = lbl_8019E250;
        if (!(p->unk_2C & 1)) {
            return;
        }
        v = p->unk_24;
        p->unk_2C = p->unk_2C & ~1;
        if (((v >> 21) & 7) == 0) {
            return;
        }
        fn_800720B0_write_bp(p->unk_24 = v & 0xFF1FFFFF, 0x61);
    }
}
#pragma opt_common_subs reset

