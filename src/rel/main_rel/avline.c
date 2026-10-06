#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/avline.h"
#include "dolphin/hw_regs.h"

typedef struct AvLineDrawState {
    u8 unk_0;
    u8 pad_1[3];
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
} AvLineDrawState;
extern AvLineDrawState lbl_1_data_1C670;
extern u32 lbl_801A6D00;
extern void GXLoadPosMtxImm(u32, u32);
extern void fn_800720B0(u32);
extern void lbl_8006DCA4(void);
extern void fn_8003462C(u32 arg0, u32 arg1, u32 arg2);
extern void fn_8007245C(u32 value);
extern void fn_800728A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_80072EDC(s32 arg0, s32 arg1);
extern void fn_800734A8(u32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_80073678(u32 arg0);
extern void fn_80073898(u32 arg0);
extern void fn_80073C6C(s32 index);
extern void fn_80074660(u32 arg0);
extern void fn_80074788(u32 arg0);
extern void fn_800747D0(u32 arg0, u32 arg1, s32 arg2, s32 arg3, u32 arg4, s32 arg5, s32 arg6);
extern void fn_80074918(u8 arg0, s32 arg1, u8 arg2);
extern void fn_800746A8();
extern s16 fn_1_3F0C8(void);
extern void fn_1_3BDC(s32);
extern void fn_1_3C18(s32);
extern u32 lbl_801A6410;
extern s32 fn_1_45D0();
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern u8 lbl_1_data_1D62C[148];
extern void fn_1_9F870(void);
extern void fn_1_58158(void);
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);

/* fzgx:begin fn_1_58114 */
void fn_1_58114(void) {
    lbl_1_bss_6C840 = (u32)fn_1_45D0(lbl_801A6410, 0x6590, lbl_1_data_1C68C, 0x39f);
}
/* fzgx:end fn_1_58114 */

/* fzgx:begin fn_1_58158 */
// fn_1_58158: loads global values and calls fn_1_46B4.
void fn_1_58158(void) {
    u32 v1 = lbl_801A6410;
    u32 v2 = lbl_1_bss_6C840;
    fn_1_46B4(v1, v2, (const char *)(void *)(&lbl_1_data_1C68C), 0x3a6);
}
/* fzgx:end fn_1_58158 */

/* fzgx:begin fn_1_5819C */
void fn_1_5819C(void) {
    lbl_1_bss_6C844 = 0;
}
/* fzgx:end fn_1_5819C */

/* fzgx:begin fn_1_581AC */

typedef struct fn_1_581AC_AvLineEntry {
    u16 unk_00;
    u16 unk_02;
    u8 unk_04[0x100];
} fn_1_581AC_AvLineEntry;

#pragma opt_propagation off
s32 fn_1_581AC(u16 value, u16 type, void* data) {
    fn_1_581AC_AvLineEntry *entry;
    u8 *p;

    if (lbl_1_bss_6C844 == 0x64) {
        return 0;
    }

    ((fn_1_581AC_AvLineEntry*)lbl_1_bss_6C840)[lbl_1_bss_6C844].unk_00 = value;
    p = (u8*)lbl_1_bss_6C840 + lbl_1_bss_6C844 * 0x104;
    entry = (fn_1_581AC_AvLineEntry*)p;
    entry->unk_02 = type;
    fn_80008BA8( (u32)(void*)(((fn_1_581AC_AvLineEntry*)lbl_1_bss_6C840)[lbl_1_bss_6C844].unk_04), (u32)(void*)(data), 0x100);
    lbl_1_bss_6C844++;
    return 1;
}
#pragma opt_propagation reset
/* fzgx:end fn_1_581AC */

/* fzgx:begin fn_1_58248 */

typedef struct AvLineVertex {
    f32 x;
    f32 y;
    f32 z;
    u8 r;
    s8 g;
    u8 b;
    u8 a;
} AvLineVertex;

typedef struct fn_1_58248_AvLineEntry {
    u16 unk_00;
    u16 unk_02;
    AvLineVertex verts[16];
} fn_1_58248_AvLineEntry;

typedef union {
    volatile u8 u8;  // fzgx-allow: S2 GX write-gather FIFO
    volatile f32 f32;  // fzgx-allow: S2 GX write-gather FIFO
} AvLineFifo;

#define WGFIFO (*(AvLineFifo *)GX_FIFO_BASE)

static inline void FifoPosition3f32(f32 x, f32 y, f32 z) {
    WGFIFO.f32 = x;
    WGFIFO.f32 = y;
    WGFIFO.f32 = z;
}

static inline void FifoColor4u8(u8 r, u8 g, s8 b, s8 a) {
    WGFIFO.u8 = r;
    WGFIFO.u8 = g;
    WGFIFO.u8 = b;
    WGFIFO.u8 = a;
}


static inline f32 fn_1_58248_read_pointer(AvLineVertex * owner) { return owner->x; }
#pragma opt_loop_invariants off
void fn_1_58248(void) {
    AvLineVertex *v;
    s32 i;
    s32 j;
    struct { u16 value; } n;
    u32 off;
    fn_1_58248_AvLineEntry *entry;
    AvLineDrawState *st = &lbl_1_data_1C670;

    st->unk_4 = 1;
    st->unk_8 = 1;
    st->unk_C = 1;
    st->unk_10 = 0;
    lbl_8006DCA4();
    fn_80074918(1, 3, 1);
    fn_800746A8(lbl_1_data_1C670.unk_0, lbl_1_data_1C670.unk_14);
    fn_8007245C(0xa00);
    fn_800728A8(st->unk_4, st->unk_8, st->unk_C, st->unk_10);
    fn_800720B0(0);
    fn_800747D0(4, 0, 1, 1, 0, 2, 1);
    fn_800734A8(0, 0xff, 0xff, 4);
    fn_80072EDC(0, 4);
    fn_80073C6C(0);
    fn_80073678(1);
    fn_80074660(0);
    fn_80073898(0);
    fn_80074788(1);
    GXLoadPosMtxImm(lbl_801A6D00, 0);

    i = 0;
    off = 0;
    while (i < lbl_1_bss_6C844) {
        entry = (fn_1_58248_AvLineEntry *)(lbl_1_bss_6C840 + off);
        lbl_1_data_1C670.unk_0 = entry->unk_00;
        v = entry->verts;
        n.value = entry->unk_02;
        if (n.value >= 2) {
            fn_8003462C(0xb0, 0, n.value);
            for (j = 0; j < n.value; j++, v++) {
                FifoPosition3f32(fn_1_58248_read_pointer(v), v->y, v->z);
                FifoColor4u8(v->r, v->g, v->b, v->a);
            }
        }
        off += sizeof(fn_1_58248_AvLineEntry);
        i++;
    }
    lbl_1_bss_6C844 = 0;
}
#pragma opt_loop_invariants reset
/* fzgx:end fn_1_58248 */

/* fzgx:begin fn_1_584AC */
// fn_1_584AC: linear congruential generator.
u32 fn_1_584AC(void) {
    u32 state = lbl_1_data_1D628;
    u32 next = state * 0x41c64e6du + 0x3039u;
    lbl_1_data_1D628 = next;
    return (next >> 16) & 0x7FFFu;
}
/* fzgx:end fn_1_584AC */

/* fzgx:begin fn_1_58694 noprologue */
#include "types.h"

typedef struct AvlineVec3 {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
} AvlineVec3;

typedef struct AvlineEntry {
    s8 unk_00;
    u8 _pad01[0x0b];
    s16 unk_0c;
    u8 _pad0e[0x02];
    s32 unk_10;
    u8 _pad14[0x28];
    AvlineVec3 unk_3c;
    u8 _pad48[0x18];
    AvlineVec3 unk_60;
    u8 _pad6c[0x7c];
} AvlineEntry;

typedef struct AvlineState {
    AvlineEntry *unk_00;
    AvlineEntry *unk_04;
    u8 _pad08[0x0c];
    s32 unk_14;
    s32 unk_18;
    s32 unk_1c;
    s32 unk_20;
} AvlineState;

typedef void (*AvlineHandler)(AvlineEntry *);

extern AvlineState lbl_1_bss_6C848;
extern AvlineHandler lbl_1_data_1D514[];
extern AvlineHandler lbl_1_data_1D2EC[];
extern s16 fn_1_3F0C8(void);
extern void fn_1_3BDC(s32);
extern void fn_1_3C18(s32);

void fn_1_58694(void) {
    AvlineState *state = &lbl_1_bss_6C848;
    s32 count;
    AvlineEntry *entry;

    if (fn_1_3F0C8() != 0x28) {
        entry = state->unk_00;
        state->unk_14 = 0;
        state->unk_18 = 0;
        state->unk_1c = 0;
        state->unk_20 = 0;
        fn_1_3BDC(9);
        for (count = 0xbe; count > 0; count--) {
            if (entry->unk_00 != 0) {
                entry->unk_10 -= 1;
                if (entry->unk_10 == 0 || entry->unk_00 == 3) {
                    lbl_1_data_1D514[entry->unk_0c](entry);
                    entry->unk_00 = 0;
                } else {
                    entry->unk_60 = entry->unk_3c;
                    lbl_1_data_1D2EC[entry->unk_0c](entry);
                }
            }
            entry++;
        }
        entry = state->unk_04;
        for (count = 0xc8; count > 0; count--) {
            if (entry->unk_00 != 0) {
                entry->unk_10 -= 1;
                if (entry->unk_10 == 0 || entry->unk_00 == 3) {
                    lbl_1_data_1D514[entry->unk_0c](entry);
                    entry->unk_00 = 0;
                } else {
                    entry->unk_60 = entry->unk_3c;
                    lbl_1_data_1D2EC[entry->unk_0c](entry);
                }
            }
            entry++;
        }
        fn_1_3C18(9);
    }
}
/* fzgx:end fn_1_58694 */

/* fzgx:begin fn_1_58854 */
typedef struct {
    s8 unk_0;
    u8 pad_1[0xb];
    s16 unk_C;
} AvlineObj;

typedef void (*AvlineCallback)(void *);

void fn_1_58854(void) {
    s32 count;
    AvlineObj *obj;
    s32 index;
    AvlineCallback callback;

    fn_1_9F870();
    fn_1_58158();

    obj = *(AvlineObj **)&lbl_1_bss_6C848;
    count = 0xbe;
    index = 0;
    while (count > 0) {
        if (obj->unk_0 != 0) {
            callback = ((AvlineCallback *)lbl_1_data_1D514)[obj->unk_C];
            callback(obj);
            obj->unk_0 = index;
        }
        count--;
        obj = (AvlineObj *)((u8 *)obj + 0xe8);
    }

    obj = (AvlineObj *)lbl_1_bss_6C84C;
    count = 0xc8;
    index = 0;
    while (count > 0) {
        if (obj->unk_0 != 0) {
            callback = ((AvlineCallback *)lbl_1_data_1D514)[obj->unk_C];
            callback(obj);
            obj->unk_0 = index;
        }
        count--;
        obj = (AvlineObj *)((u8 *)obj + 0xe8);
    }

    fn_1_46B4(lbl_801A6410, *(u32 *)&lbl_1_bss_6C848, (const char *)(void *)(lbl_1_data_1D62C), 0x156);
    fn_1_46B4(lbl_801A6410, *(u32 *)&lbl_1_bss_6C84C, (const char *)(void *)(lbl_1_data_1D62C), 0x157);

    *(u32 *)&lbl_1_bss_6C848 = 0;
    lbl_1_bss_6C84C = 0;
}
/* fzgx:end fn_1_58854 */

/* fzgx:begin fn_1_591A0 */
typedef struct {
    s8 unk_0;
    u8 pad_1[0x7];
    u32 unk_8;
    s16 unk_C;
    u8 pad_E[0xDA];
} Fn591A0Obj;

void fn_1_591A0(s32 id) {
    {
        Fn591A0Obj *obj;
        void (**table)(void *);
        s32 count;
        s32 zero;

        obj = *(Fn591A0Obj **)&lbl_1_bss_6C848;
        table = (void (**)(void *))lbl_1_data_1D514;
        zero = 0;
        for (count = 0xbe; count > 0; count--) {
            if (obj->unk_0 && obj->unk_C == id) {
                table[obj->unk_C](obj);
                obj->unk_8 |= (u32)0x8000 << 16;
                obj->unk_0 = zero;
            }
            obj++;
        }
    }
    {
        s32 count;
        Fn591A0Obj *obj;
        void (**table)(void *);
        s32 zero;

        obj = (Fn591A0Obj *)lbl_1_bss_6C84C;
        table = (void (**)(void *))lbl_1_data_1D514;
        zero = 0;
        for (count = 0xc8; count > 0; count--) {
            if (obj->unk_0 && obj->unk_C == id) {
                table[obj->unk_C](obj);
                obj->unk_8 |= (u32)0x8000 << 16;
                obj->unk_0 = zero;
            }
            obj++;
        }
    }
}
/* fzgx:end fn_1_591A0 */
