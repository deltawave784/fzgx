#include "types.h"

extern u8 lbl_12_rodata_15D0[];
extern void MWSFSVM_Error(const char *, ...);
typedef struct Sig_fn_12_339B4_MovieOutput {
    u32 field_00, field_04, field_08, field_0C, field_10, field_14;
} Sig_fn_12_339B4_MovieOutput;
extern void fn_12_339B4(u32, u32, u32, Sig_fn_12_339B4_MovieOutput *);
struct Sig_fn_12_7E8_fn_12_7E8_Arg0 { u8 pad_0[0x10]; u32 unk_10, unk_14, unk_18; };
struct Sig_fn_12_7E8_fn_12_7E8_Arg1 { u32 unk_0; };
struct Sig_fn_12_7E8_fn_12_7E8_Arg2 { u32 unk_0; };
extern u32 fn_12_7E8(struct Sig_fn_12_7E8_fn_12_7E8_Arg0 *, struct Sig_fn_12_7E8_fn_12_7E8_Arg1 *, struct Sig_fn_12_7E8_fn_12_7E8_Arg2 *);
#define IN(off) (*(u32 *)((u8 *)arg1 + (off)))
#define SELF(off) (*(u32 *)((u8 *)arg0 + (off)))
#define OUT(off) (*(u32 *)((u8 *)arg2 + (off)))
#pragma opt_propagation off
void fn_12_35B08(u32 self, u32 arg1, u32 out) {
    u32 arg2 = out;
    u32 arg0 = self;
    u8 *p_lbl_12_rodata_15D0;
    u32 v0;
    u32 width;
    u32 height;
    Sig_fn_12_339B4_MovieOutput local;
    struct Sig_fn_12_7E8_fn_12_7E8_Arg2 b;
    struct Sig_fn_12_7E8_fn_12_7E8_Arg1 a;
    p_lbl_12_rodata_15D0 = (u8 *)&lbl_12_rodata_15D0;
    v0 = IN(4);
    switch ((s32)v0) {
    case 1: v0 = 1; break;
    case 2: v0 = 2; break;
    case 3: v0 = 3; break;
    default: MWSFSVM_Error((const char *)(p_lbl_12_rodata_15D0 + 0x790)); v0 = 3; break;
    }
    OUT(0) = v0;
    width = IN(8);
    height = IN(12);
    OUT(0x44) = width;
    OUT(0x48) = height;
    if ((s32)IN(4) != 3) {
        OUT(4) = IN(0);
        OUT(8) = width;
        OUT(12) = height;
    } else {
        fn_12_339B4(IN(0), width, height, &local);
        width = local.field_0C;
        v0 = local.field_00;
        OUT(4) = v0;
        OUT(8) = width;
        OUT(12) = height;
        v0 = local.field_04;
        width = local.field_10;
        OUT(0x14) = v0;
        OUT(0x18) = width;
        OUT(0x1c) = height;
        width = local.field_14;
        v0 = local.field_08;
        OUT(0x24) = v0;
        OUT(0x28) = width;
        OUT(0x2c) = height;
    }
    OUT(0x4c) = IN(0x30);
    fn_12_7E8((struct Sig_fn_12_7E8_fn_12_7E8_Arg0 *)SELF(0xa8), &a, &b);
    OUT(0x50) = a.unk_0;
    OUT(0x54) = b.unk_0;
    OUT(0x58) = 0;
    OUT(0x5c) = 0;
    v0 = 3;
    switch ((s32)SELF(0x88)) {
    case 1: v0 = 1; break;
    case 2: v0 = 2; break;
    case 3: v0 = 3; break;
    default: MWSFSVM_Error((const char *)(p_lbl_12_rodata_15D0 + 0x768)); break;
    }
    OUT(0x60) = v0;
    v0 = 1;
    switch ((s32)SELF(0x8c)) {
    case 1: v0 = 1; break;
    case 2: v0 = 2; break;
    case 3: v0 = 3; break;
    default: MWSFSVM_Error((const char *)(p_lbl_12_rodata_15D0 + 0x744)); break;
    }
    OUT(0x64) = v0;
    OUT(0x68) = SELF(0x90);
    OUT(0x6c) = SELF(0x94);
    OUT(0x70) = SELF(0x98);
    v0 = 1;
    switch ((s32)SELF(0x9c)) {
    case 0: v0 = 0; break;
    case 1: v0 = 1; break;
    default: MWSFSVM_Error((const char *)(p_lbl_12_rodata_15D0 + 0x724)); break;
    }
    OUT(0x74) = v0;
    v0 = 1;
    switch ((s32)SELF(0xa0)) {
    case 0: v0 = 0; break;
    case 1: v0 = 1; break;
    default: MWSFSVM_Error((const char *)(p_lbl_12_rodata_15D0 + 0x724)); break;
    }
    OUT(0x78) = v0;
}
