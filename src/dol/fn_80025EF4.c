#include "types.h"

struct fn_80025D5C_Obj {
    void *unk0;
    u32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    u16 unk38;
    u16 unk3A;
    u16 unk3C;
    u16 unk3E;
    u16 unk40;
    u16 unk42;
    u16 unk44;
    u16 unk46;
    u16 unk48;
    u16 unk4A;
    u16 unk4C;
    u16 unk4E;
    u16 unk50;
    u16 unk52;
    u16 unk54;
    u16 unk56;
    u16 unk58;
    u16 unk5A;
    u16 unk5C;
};

struct fn_80025EF4_lbl_80128990 {
    u8 pad_0[0x710];
    u16 unk_710[512];
};

struct fn_80025EF4_Arg0 {
    u8 pad_0[0x18];
    u32 unk_18;
};

extern struct fn_80025EF4_lbl_80128990 lbl_80128990;
extern u8 lbl_80176160[];
extern u32 lbl_801A6B88[2];

extern void fn_80025D5C(struct fn_80025D5C_Obj *);
extern void *OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(void *);

static inline u16 fn_80025EF4_attn(s32 value, struct fn_80025EF4_lbl_80128990 *table) {
    if (value <= -0x388) return 0;
    if (value >= 0x3C) return 0xFF64;
    return table->unk_710[value];
}
#define ATTN(v) fn_80025EF4_attn((v), tbl)

static inline void fn_80025EF4_store(void *destination, s32 value) { *(s32 *)destination = value; }
static inline void fn_80025EF4_store_(s32 *destination, s32 value) { *destination = value; }
static inline void fn_80025EF4_call_fn_80025D5C(struct fn_80025D5C_Obj * a0) { fn_80025D5C(a0); }
#pragma opt_common_subs on
#pragma opt_propagation off
void fn_80025EF4(struct fn_80025EF4_Arg0 *arg0, u32 arg1, s32 arg2, s32 arg3, s32 arg4, u32 arg5, u32 arg6, u32 arg7) {
    struct fn_80025EF4_lbl_80128990 *tbl;
    struct { struct fn_80025D5C_Obj * value; } p;
    u32 fzgx_frame_pad[42];  /* fzgx: retail frame home */
    u16 fzgx_value;
    s16 flags;
    u32 v;

    tbl = &lbl_80128990;
    p.value = (struct fn_80025D5C_Obj *)((u8 *)lbl_80176160 + (arg0->unk_18 * 0x60));
    p.value->unk0 = (void *)arg0;
    p.value->unk4 = arg1 & 7;
    p.value->unk8 = arg2;
    fn_80025EF4_store_(&(p.value->unkC), arg3);
    p.value->unk10 = arg4;
    p.value->unk14 = arg5;
    fn_80025EF4_store(&(p.value->unk18), arg6);
    p.value->unk1C = arg7;
    fn_80025EF4_call_fn_80025D5C(p.value);
    if (p.value->unk4 & 4) {
        p.value->unk38 = 0;
    } else {
        p.value->unk38 = ATTN(arg2);
    }
    flags = 0;
    switch ((*((0) + (lbl_801A6B88)))) {
    case 0:
        p.value->unk3C = ATTN(p.value->unk1C + p.value->unk28);
        p.value->unk40 = ATTN(p.value->unk1C + p.value->unk28);
        p.value->unk44 = ATTN(p.value->unk1C + p.value->unk2C - 0x1E);
        if (p.value->unk4 & 1) {
            p.value->unk48 = ATTN(p.value->unkC + p.value->unk28);
            p.value->unk4C = ATTN(p.value->unkC + p.value->unk28);
            p.value->unk50 = ATTN(p.value->unkC + p.value->unk2C - 0x1E);
        } else {
            p.value->unk48 = ATTN(p.value->unk1C + p.value->unkC + p.value->unk28);
            p.value->unk4C = ATTN(p.value->unk1C + p.value->unkC + p.value->unk28);
            p.value->unk50 = ATTN(p.value->unk1C + p.value->unkC + p.value->unk2C - 0x1E);
        }
        if (p.value->unk4 & 2) {
            p.value->unk54 = ATTN(p.value->unk10 + p.value->unk28);
            p.value->unk58 = ATTN(p.value->unk10 + p.value->unk28);
            p.value->unk5C = ATTN(p.value->unk10 + p.value->unk2C - 0x1E);
        } else {
            p.value->unk54 = ATTN(p.value->unk1C + p.value->unk10 + p.value->unk28);
            p.value->unk58 = ATTN(p.value->unk1C + p.value->unk10 + p.value->unk28);
            p.value->unk5C = ATTN(p.value->unk1C + p.value->unk10 + p.value->unk2C - 0x1E);
        }
        break;
    case 1:
    case 2:
        fzgx_value = ATTN(p.value->unk1C + p.value->unk20 + p.value->unk28);
        p.value->unk3C = fzgx_value;
        p.value->unk40 = ATTN(p.value->unk1C + p.value->unk24 + p.value->unk28);
        p.value->unk44 = ATTN(p.value->unk1C + p.value->unk2C - 0x1E);
        if (p.value->unk4 & 1) {
            p.value->unk48 = ATTN(p.value->unkC + p.value->unk20 + p.value->unk28);
            p.value->unk4C = ATTN(p.value->unkC + p.value->unk24 + p.value->unk28);
            p.value->unk50 = ATTN(p.value->unkC + p.value->unk2C - 0x1E);
        } else {
            p.value->unk48 = ATTN(p.value->unk1C + p.value->unkC + p.value->unk20 + p.value->unk28);
            p.value->unk4C = ATTN(p.value->unk1C + p.value->unkC + p.value->unk24 + p.value->unk28);
            p.value->unk50 = ATTN(p.value->unk1C + p.value->unkC + p.value->unk2C - 0x1E);
        }
        if (p.value->unk4 & 2) {
            p.value->unk54 = ATTN(p.value->unk10 + p.value->unk20 + p.value->unk28);
            p.value->unk58 = ATTN(p.value->unk10 + p.value->unk24 + p.value->unk28);
            p.value->unk5C = ATTN(p.value->unk10 + p.value->unk2C - 0x1E);
        } else {
            p.value->unk54 = ATTN(p.value->unk1C + p.value->unk10 + p.value->unk20 + p.value->unk28);
            p.value->unk58 = ATTN(p.value->unk1C + p.value->unk10 + p.value->unk24 + p.value->unk28);
            p.value->unk5C = ATTN(p.value->unk1C + p.value->unk10 + p.value->unk2C - 0x1E);
        }
        break;
    case 3:
        p.value->unk3C = ATTN(p.value->unk1C + p.value->unk20 + p.value->unk28);
        p.value->unk40 = ATTN(p.value->unk1C + p.value->unk24 + p.value->unk28);
        p.value->unk54 = ATTN(p.value->unk1C + p.value->unk30 + p.value->unk2C);
        p.value->unk58 = ATTN(p.value->unk1C + p.value->unk34 + p.value->unk2C);
        if (p.value->unk4 & 1) {
            p.value->unk48 = ATTN(p.value->unkC + p.value->unk20 + p.value->unk28);
            p.value->unk4C = ATTN(p.value->unkC + p.value->unk24 + p.value->unk28);
            p.value->unk50 = ATTN(p.value->unkC + p.value->unk30 + p.value->unk2C);
            p.value->unk5C = ATTN(p.value->unkC + p.value->unk34 + p.value->unk2C);
        } else {
            p.value->unk48 = ATTN(p.value->unk1C + p.value->unkC + p.value->unk20 + p.value->unk28);
            p.value->unk4C = ATTN(p.value->unk1C + p.value->unkC + p.value->unk24 + p.value->unk28);
            p.value->unk50 = ATTN(p.value->unk1C + p.value->unkC + p.value->unk30 + p.value->unk2C);
            p.value->unk5C = ATTN(p.value->unk1C + p.value->unkC + p.value->unk34 + p.value->unk2C);
        }
        flags |= 0x4000;
        break;
    }

    {
        void *oldInts;
        u16 *q;

        oldInts = OSDisableInterrupts();
        *(u16 *)((u8 *)arg0 + 0x19C) = p.value->unk38;
        *(u16 *)((u8 *)arg0 + 0x19E) = 0;
        q = (u16 *)((u8 *)arg0 + 0x14A);
        v = (u16)(p.value->unk3C);
        q[0] = v;
        q += 1;
        if (v != 0) {
            flags |= 1;
        }
        q[0] = 0;
        v = (u16)(p.value->unk40);
        q[1] = v;
        q += 2;
        if (v != 0) {
            flags |= 2;
        }
        q[0] = 0;
        v = (u16)(p.value->unk48);
        q[1] = v;
        q += 2;
        if (v != 0) {
            flags |= 0x10;
        }
        q[0] = 0;
        v = (u16)(p.value->unk4C);
        q[1] = v;
        q += 2;
        if (v != 0) {
            flags |= 0x20;
        }
        q[0] = 0;
        v = (u16)(p.value->unk54);
        q[1] = v;
        q += 2;
        if (v != 0) {
            flags |= 0x200;
        }
        q[0] = 0;
        v = (u16)(p.value->unk58);
        q[1] = v;
        q += 2;
        if (v != 0) {
            flags |= 0x400;
        }
        q[0] = 0;
        v = (u16)(p.value->unk5C);
        q[1] = v;
        q += 2;
        if (v != 0) {
            flags |= 0x1000;
        }
        q[0] = 0;
        v = (u16)(p.value->unk44);
        q[1] = v;
        q += 2;
        if (v != 0) {
            flags |= 4;
        }
        q[0] = 0;
        v = (u16)(p.value->unk50);
        q[1] = v;
        q += 2;
        if (v != 0) {
            flags |= 0x80;
        }
        q[0] = 0;
        *(s16 *)((u8 *)arg0 + 0x144) = flags;
        *(u32 *)((u8 *)arg0 + 0x1C) = *(u32 *)((u8 *)arg0 + 0x1C) | 0x212;
        OSRestoreInterrupts(oldInts);
    }
}
#pragma opt_propagation reset

#pragma opt_common_subs reset

