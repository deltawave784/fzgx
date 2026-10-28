#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_win.h"
#include "font.h"
extern s32 fn_1_5910(void);
extern void fn_80038F10(f32* out);
extern void fn_1_15EFEC(int);
extern void fn_1_15DFD4(int index, int flags);
extern u32 fn_1_485A8(s32 index);
extern void fn_1_49410(void);
extern void fn_1_49728(u8 value);
extern void fn_1_1420A4(void);
extern f32 lbl_1_rodata_DD6C[11];
extern f32 lbl_1_rodata_DE50[39];
extern void fn_1_496FC(f32 value1, f32 value2);
extern void fn_1_495FC(void);
extern void fn_1_495C8(u8 value);
extern void fn_1_15DD7C(s32 timer);
extern void fn_1_15C6C0(u16, int);
extern void fn_1_49614(void);
extern void fn_1_A4C9C(s32 index, u8 value);
extern FontDrawPacket lbl_1_rodata_26F8;
extern u32 fn_1_58C4(void);
extern f32 fn_1_519FC(f32 value);
extern f32 fn_1_51AC0(f32 value);
extern u32 fn_1_435C(u32 value);
extern s32 fn_1_3F8C(u32 arg3, u32 arg0, u32 arg1, u32 index);
extern void fn_1_15E220(u8 *value);
extern u32 lbl_1_bss_8FD60[2];
extern int fn_1_15BCDC(void *);
extern u32 fn_1_4060(void);
extern u32 lbl_1_bss_8FE80[8];
extern u32 lbl_1_bss_8FEA0;
extern u8 lbl_1_bss_8FE7C;
extern size_t strlen(const char *str);
extern s32 fn_8006FC1C(const char *a, const char *b);
extern void fn_1_15E1E8(u8 *value);

/* fzgx:begin fn_1_15B70C */
typedef struct {
    u32 x, y, z;
} BgWinVec;

typedef struct {
    u8 pad_0[0xC];
    BgWinVec pos;
    u8 pad_18[0x24];
    u32 unk_3C;
} BgWinItem;

extern void OSPanic(const char *, int, const char *, ...);

#define BGWIN_ADD(obj, count, max, base, item) \
    do {                                       \
        if ((obj)->count < (max)) {            \
            (&(obj)->base)[(obj)->count] = (u32)(item); \
        }                                      \
        (obj)->count++;                        \
    } while (0)

s32 fn_1_15B70C(u32 kind, BgWinItem *item) {
    /* held in a struct so the string base stays one materialization */
    Obj_1_data_2A7E0_At3C *obj;

    obj = lbl_1_data_2A7E0.unk_3C;

    switch (kind) {
    case 0:
        *(BgWinVec *)&obj->unk_4 = item->pos;
        break;
    case 1:
        *(BgWinVec *)&obj->unk_10 = item->pos;
        break;
    case 2:
        item->unk_3C = 0;
        *(BgWinVec *)&obj->unk_1C = item->pos;
        obj->unk_4C = (u32)item;
        BGWIN_ADD(obj, unk_5D, 20, unk_74, item);
        break;
    case 3:
        item->unk_3C = 0;
        *(BgWinVec *)&obj->unk_28 = item->pos;
        obj->unk_50 = (u32)item;
        BGWIN_ADD(obj, unk_5D, 20, unk_74, item);
        break;
    case 4:
        item->unk_3C = 0;
        *(BgWinVec *)&obj->unk_34 = item->pos;
        obj->unk_54 = (u32)item;
        BGWIN_ADD(obj, unk_5D, 20, unk_74, item);
        break;
    case 5:
        item->unk_3C = 0;
        *(u32 *)&obj->unk_58 = (u32)item;
        BGWIN_ADD(obj, unk_5D, 20, unk_74, item);
        break;
    case 6:
        BGWIN_ADD(obj, unk_5C, 5, unk_60, item);
    case 7:
        BGWIN_ADD(obj, unk_5D, 20, unk_74, item);
        break;
    case 8:
    case 9:
    case 10:
        BGWIN_ADD(obj, unk_5E, 20, unk_C4, item);
        break;
    }
    if (obj->unk_5E >= 20) {
        OSPanic("bg_win.c", 0x163, "win gr over");
    }
    if (obj->unk_5D >= 20) {
        OSPanic("bg_win.c", 0x164, "win bg over");
    }
    return 1;
}
/* fzgx:end fn_1_15B70C */

/* fzgx:begin fn_1_15B970 */
typedef struct {
    u8 pad_0[0x8];
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
} WinObject;

static inline u32 swap32(u32 value) {
    u32 temp;

    temp = value;
    return __lwbrx(&temp, 0);
}

void fn_1_15B970(WinObject *obj) {
    u32 offset;
    u32 count;

    lbl_1_bss_8F8D0.unk_0 = (u32)obj;
    if (obj != 0) {
        obj->unk_8 = swap32(obj->unk_8);
        obj->unk_C = swap32(obj->unk_C);
        obj->unk_10 = swap32(obj->unk_10);
        obj->unk_14 = swap32(obj->unk_14);
        obj->unk_18 = swap32(obj->unk_18);

        count = 0;
        offset = 0;
        while (count < obj->unk_8) {
            u32 *a = (u32 *)((u8 *)obj + obj->unk_C + offset);
            u32 *b = (u32 *)((u8 *)obj + obj->unk_10 + offset);

            a[1] = swap32(a[1]);
            a[0] = swap32(a[0]);
            b[1] = swap32(b[1]);
            b[0] = swap32(b[0]);

            offset += 8;
            count++;
        }
    }
}
/* fzgx:end fn_1_15B970 */

/* fzgx:begin fn_1_15BA78 */
typedef struct {
    u8 pad_00[0x08];
    u32 count;
    u32 entries_offset;
    u32 results_offset;
} StringTable;

#pragma opt_common_subs off
char *fn_1_15BA78(char *name) {
    struct { StringTable * value; } table;
    u32 index;
    struct { u32 value; } entry_offset;
    struct { u32 value; } name_length;

    { StringTable * __reg_value_table = (*(StringTable * *)&lbl_1_bss_8F8D0); table.value = __reg_value_table; }
    if (table.value == 0) {
        return name;
    }

    name_length.value = (u32)strlen(name);
    index = 0;
    entry_offset.value = 0;
    while (index < table.value->count) {
        u8 *entry = ((((entry_offset.value)) + ((((u8 *)table.value)) + ((table.value->entries_offset)))));
        if (name_length.value == *(u32 *)entry &&
            fn_8006FC1C((char *)table.value + *(u32 *)(entry + 4), name) != 0) {
            u32 result_offset = *(u32 *)((u8 *)table.value + table.value->results_offset + index * 8 + 4);
            return (char *)table.value + result_offset;
        }
        entry_offset.value += 8;
        index++;
    }
    return name;
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_15BA78 */

/* fzgx:begin fn_1_15BB34 pool noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_win.h"

extern void fn_80008BEC(void *, int, u32);

typedef struct {
    u8 pad_0[0x20];
    u8 a[0x20];
    u8 pad_40[0x60];
    u8 b[0x20];
    u8 c[0x3C0];
    u32 unk_480;
    u16 unk_484;
    u16 unk_486;
} WinState;

#pragma opt_lifetimes off
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_8F8E0[8];
u8 lbl_1_bss_8F8E0_20[0x20];
u32 lbl_1_bss_8F8E0_fill_8F920[24];
u8 lbl_1_bss_8F980[0x20];
u8 lbl_1_bss_8F9A0[0x3C0];
u32 lbl_1_bss_8FD60;
u16 lbl_1_bss_8FD60_4;
u16 lbl_1_bss_8FD60_6;
u32 fzgx_obj_lbl_1_bss_8FD68[16];
u32 fzgx_obj_lbl_1_bss_8FDA8[53];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8F8E0;
    s = *(u8 *)&lbl_1_bss_8F8E0_20;
    s = *(u8 *)&lbl_1_bss_8F8E0_fill_8F920;
    s = *(u8 *)&lbl_1_bss_8F980;
    s = *(u8 *)&lbl_1_bss_8F9A0;
    s = *(u8 *)&lbl_1_bss_8FD60;
    s = *(u8 *)&lbl_1_bss_8FD60_4;
    s = *(u8 *)&lbl_1_bss_8FD60_6;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8FD68;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8FDA8;
}
#pragma section code_type ".text"

void fn_1_15BB34(u32 arg0) {
    u8 * fzgx_live;
    
    u32 lab_t2;
    lab_t2 = 0x20;
    fn_80008BEC(&fzgx_obj_lbl_1_bss_8F8E0, 0, lab_t2);
    lab_t2 = 0x20;
    fn_80008BEC(lbl_1_bss_8F8E0_20, 0, lab_t2);
    lab_t2 = 0x20;
    fn_80008BEC(lbl_1_bss_8F980, 0, lab_t2);
    fzgx_live = lbl_1_bss_8F9A0;
    lab_t2 = 0x3C0;
    fn_80008BEC(fzgx_live, 0, lab_t2);
    lbl_1_bss_8FD60_4 = 0xFFFF;
    lbl_1_bss_8FD60 = arg0;
    lbl_1_bss_8FD60_6 = 0;
}
#pragma opt_lifetimes reset
/* fzgx:end fn_1_15BB34 */

/* fzgx:begin fn_1_15BCDC noprologue */
#include "types.h"

extern u16 lbl_1_bss_8F980[16];
extern u16 lbl_1_bss_8F9A0[480];

s32 fn_1_15BCDC(u32 *p) {
    s32 j;
    s32 base;
    u32 *q;
    s32 n;
    u16 a;
    u16 *row;
    struct { s32 value; } i;
    u16 b;
    u32 v;

    a = 0;
    q = p;
    b = 0;
    n = 0;

    while (*q != 0xFFFFFFFF) {
        v = *q;
        if (a == 0) {
            a = v & 0xF;
        }
        if ((v >> 24) == 2) {
            b = b | ((v >> 4) & 0xFFFF);
        }
        q++;
        n++;
    }
    if (n == 0) {
        return 0;
    }
    base = lbl_1_bss_8F980[a];
    row = lbl_1_bss_8F9A0 + (a - 1) * 32;
    base = base + 0x20;
    j = 0;
    for (i.value = 0; i.value < n; i.value++) {
        s32 k = (base - j) % 32;
        u32 v = p[(u16)(n - i.value - 1)];
        u32 f = (v >> 4) & 0xFFFF;
        u16 cur = row[(u16)k];
        if ((v >> 24) != 2) {
            if (b != 0 && cur == b) {
                j++;
                cur = row[(u16)((base - j) % 32)];
            }
            if ((s32)cur != (s32)(f | b)) {
                return 0;
            }
            j++;
        }
    }
    return 1;
}
/* fzgx:end fn_1_15BCDC */

/* fzgx:begin fn_1_15BE38 */
typedef struct {
    u32 count;
    void **items;
} ItemList;

u32 fn_1_15BE38(void) {
    u32 offset;
    u32 index;

    offset = 0;
    index = 0;
    while (index < (*(ItemList **)&lbl_1_bss_8FD60)->count) {
        if (fn_1_15BCDC((*(ItemList **)&lbl_1_bss_8FD60)->items[offset >> 2]) != 0) {
            return index & 0xffff;
        }
        offset += 4;
        index++;
    }
    return 0xffff;
}
/* fzgx:end fn_1_15BE38 */

/* fzgx:begin fn_1_15BEBC */
typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
    u16 unk_4;
    u16 unk_6;
} Entry;

void fn_1_15BEBC(u16 mask, Obj_1_bss_8F8E0 *state) {
    Entry *p;
    u32 max;
    u32 sel;
    u32 cnt;
    Entry *first;
    u32 i;

    p = (Entry *)&lbl_1_bss_8F8E0;
    max = 0;
    sel = 0;
    cnt = 0;
    first = 0;
    for (i = 0; i < 4; i++) {
        if ((1 << i) & mask) {
            if (first == 0) {
                first = p;
            }
            if (p->unk_4 == 0) {
                cnt++;
            } else {
                if (sel == 0) {
                    sel = p->unk_4;
                } else if (sel != p->unk_4) {
                    sel = 0x8000;
                    break;
                }
                if (max < p->unk_1) {
                    max = p->unk_1;
                }
            }
        }
        p++;
    }

    if (sel != 0x8000) {
        if (sel == 0) {
            state->pad_3[0] = 0;
        } else if (cnt != 0) {
            u32 cur = state->pad_3[0];
            if (cur < 10) {
                sel = 0;
            } else {
                sel = 0x8000;
            }
            if (cur == 0) {
                state->pad_3[0] = 1;
            } else {
                state->pad_3[0] = cur + ((cur - 0x78) >> 31);
            }
        } else if (max < 10) {
            state->pad_3[0] = 0;
        } else {
            if (state->unk_4 == 0x8000) {
                sel = 0x8000;
            }
            if (state->pad_3[0] != 0) {
                u32 v = state->pad_3[0];
                state->pad_3[0] = v + ((v - 0x78) >> 31);
            }
        }
    }

    if (sel != state->unk_4) {
        state->unk_6 = state->unk_4;
        state->unk_4 = sel;
        state->unk_1 = 0;
        state->unk_2 = 0;
    } else {
        u32 t = state->unk_1;
        state->unk_1 = t + 1;
        t = state->unk_2;
        state->unk_2 = t + 1;
    }
}
/* fzgx:end fn_1_15BEBC */

/* fzgx:begin fn_1_15C0AC */
typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
    u16 unk_4;
    u16 unk_6;
} WinEntry;

#pragma opt_loop_invariants off
void fn_1_15C0AC(void) {
    u8 *in;
    struct { WinEntry * value; } out;
    u16 a;
    u16 b;
    u32 i;

    { WinEntry * __reg_value_out = (WinEntry *)&lbl_1_bss_8F8E0; out.value = __reg_value_out; }
    in = (u8 *)&lbl_1_bss_9F8;
    for (i = 0; i < 4; i++) {
        a = 0;
        b = 0;
        if (((1) & ((*(volatile u16 *)(in + 8) >> 4)))) {  /* fzgx-allow: S2 memory-mapped register */
            a |= 1;
        }
        if ((*(volatile u16 *)(in + 8) >> 10) & 1) {  /* fzgx-allow: S2 memory-mapped register */
            a |= 2;
        }
        if ((*(volatile u16 *)(in + 8) >> 11) & 1) {  /* fzgx-allow: S2 memory-mapped register */
            a |= 4;
        }
        if (*(volatile u16 *)(in + 8) & 1) {  /* fzgx-allow: S2 memory-mapped register */
            a |= 8;
        }
        if ((*(volatile u16 *)(in + 8) >> 1) & 1) {  /* fzgx-allow: S2 memory-mapped register */
            a |= 0x10;
        }
        if ((*(volatile u16 *)(in + 8) >> 8) & 1) {  /* fzgx-allow: S2 memory-mapped register */
            a |= 0x20;
        }
        if ((*(volatile u16 *)(in + 10) >> 7) & 1) {  /* fzgx-allow: S2 memory-mapped register */
            a |= 0x100;
        }
        if ((*(volatile u16 *)(in + 10) >> 6) & 1) {  /* fzgx-allow: S2 memory-mapped register */
            a |= 0x200;
        }
        if ((*(volatile u16 *)(in + 10) >> 4) & 1) {  /* fzgx-allow: S2 memory-mapped register */
            a |= 0x400;
        }
        if ((*(volatile u16 *)(in + 10) >> 5) & 1) {  /* fzgx-allow: S2 memory-mapped register */
            a |= 0x800;
        }
        if ((*(volatile u16 *)(in + 8) >> 6) & 1) {  /* fzgx-allow: S2 memory-mapped register */
            a |= 0x40;
        }
        if ((*(volatile u16 *)(in + 8) >> 5) & 1) {  /* fzgx-allow: S2 memory-mapped register */
            a |= 0x80;
        }
        if ((*(volatile u16 *)(in + 0) >> 4) & 1) {  /* fzgx-allow: S2 memory-mapped register */
            b |= 1;
        }
        if ((*(volatile u16 *)(in + 0) >> 10) & 1) {  /* fzgx-allow: S2 memory-mapped register */
            b |= 2;
        }
        if ((*(volatile u16 *)(in + 0) >> 11) & 1) {  /* fzgx-allow: S2 memory-mapped register */
            b |= 4;
        }
        if (*(volatile u16 *)(in + 0) & 1) {  /* fzgx-allow: S2 memory-mapped register */
            b |= 8;
        }
        if ((*(volatile u16 *)(in + 0) >> 1) & 1) {  /* fzgx-allow: S2 memory-mapped register */
            b |= 0x10;
        }
        if ((*(volatile u16 *)(in + 0) >> 8) & 1) {  /* fzgx-allow: S2 memory-mapped register */
            b |= 0x20;
        }
        if ((*(volatile u16 *)(in + 2) >> 7) & 1) {  /* fzgx-allow: S2 memory-mapped register */
            b |= 0x100;
        }
        if ((*(volatile u16 *)(in + 2) >> 6) & 1) {  /* fzgx-allow: S2 memory-mapped register */
            b |= 0x200;
        }
        if ((*(volatile u16 *)(in + 2) >> 4) & 1) {  /* fzgx-allow: S2 memory-mapped register */
            b |= 0x400;
        }
        if ((*(volatile u16 *)(in + 2) >> 5) & 1) {  /* fzgx-allow: S2 memory-mapped register */
            b |= 0x800;
        }
        if ((*(volatile u16 *)(in + 0) >> 6) & 1) {  /* fzgx-allow: S2 memory-mapped register */
            b |= 0x40;
        }
        if ((*(volatile u16 *)(in + 0) >> 5) & 1) {  /* fzgx-allow: S2 memory-mapped register */
            b |= 0x80;
        }
        if ((a ^ b) != 0 && ((a & out.value->unk_4) == 0 || out.value->unk_1 >= 0xa)) {
            a = 0;
        }
        if (a != 0) {
            out.value->unk_0 = out.value->unk_2;
            out.value->unk_2 = 0;
            out.value->unk_1 = 0;
        } else {
            u8 t = out.value->unk_2;
            out.value->unk_2 = t + (((u32)t - 0x78) >> 31);
            if (b != 0) {
                u8 t2 = out.value->unk_1;
                out.value->unk_1 = t2 + (((u32)t2 - 0x78) >> 31);
            } else {
                out.value->unk_1 = 0;
            }
        }
        {
            u16 t3 = out.value->unk_4;
            if (t3 != b) {
                out.value->unk_6 = t3;
                out.value->unk_4 = b;
            }
        }
        out.value++;
        in += 0x14;
    } while (--i);
}
#pragma opt_loop_invariants reset
/* fzgx:end fn_1_15C0AC */

/* fzgx:begin fn_1_15C35C */
s32 fn_1_15C35C(s32 a, s32 b, s32 c, s32 d) {
    return a * b - c + d;
}
/* fzgx:end fn_1_15C35C */

/* fzgx:begin fn_1_15C36C noprologue */
#include "types.h"

extern int fn_1_5910(void);
extern void fn_80038F10(f32 *);
extern void fn_1_15EFEC(int);
extern void fn_1_15DFD4(int, int);
extern int fn_1_485A8(int);
extern void fn_1_49410(void);
extern void fn_1_49728(int);
extern void fn_1_1420A4(void);

extern u32 lbl_1_bss_3C30;
extern u8 lbl_1_bss_26B18;
extern u8 lbl_1_bss_26B19;
extern u8 lbl_1_bss_26B1A;
extern u8 lbl_1_bss_26B1E;
extern u32 lbl_1_data_3D544[];
extern u16 lbl_1_bss_50EC[];

typedef struct {
    f32 x, y, z, w;
} BgWinVec4;

typedef struct {
    u8 unk_0;
    u8 pad_1[0x33];
} BgWin34;

extern BgWinVec4 lbl_1_bss_8FD68[];
extern BgWin34 lbl_1_bss_8FDA8[];

void fn_1_15C36C(void) {
    struct { int value; } idx;
    u8 mask;
    int hit;
    u8 flags;
    f32 vec[4];

    idx.value = fn_1_5910();
    mask = 1 << idx.value;
    if (lbl_1_bss_3C30 & 0x800) {
        return;
    }

    fn_80038F10(vec);
    lbl_1_bss_8FD68[idx.value].x = vec[0];
    lbl_1_bss_8FD68[idx.value].y = vec[1];
    lbl_1_bss_8FD68[idx.value].z = vec[2];
    lbl_1_bss_8FD68[idx.value].w = vec[3];

    flags = lbl_1_bss_26B1E | lbl_1_bss_26B19 | lbl_1_bss_26B1A | lbl_1_bss_26B18;
    hit = flags & mask;
    if (hit) {
        lbl_1_data_3D544[idx.value] &= 0x3c2;
    }
    if (!hit && !(lbl_1_bss_8FDA8[idx.value].unk_0 & 0x4)) {
        fn_1_15EFEC(idx.value);
    }

    if (lbl_1_bss_3C30 & 0x8) {
        return;
    }
    if (hit) {
        fn_1_15DFD4(idx.value, mask);
    }
    if (lbl_1_bss_3C30 & 0x1000) {
        if (fn_1_485A8(0x97) && lbl_1_bss_50EC[idx.value] == 0) {
            fn_1_49410();
            fn_1_49728(1);
            fn_1_1420A4();
            fn_1_49728(0);
        }
    }
}
/* fzgx:end fn_1_15C36C */

/* fzgx:begin fn_1_15C5A4 noprologue */
#include "types.h"

extern f32 lbl_1_rodata_DD58;
extern f64 lbl_1_rodata_DD60;
extern u32 __cvt_fp2unsigned(f32);
extern u32 fn_80074188(u32, u32, u32, u32);
extern u32 lbl_1_bss_8FD68;

#pragma opt_common_subs off
#pragma opt_dead_assignments off
f32 fn_1_15C5A4(void * arg0, void * arg1) {
    s32 v0;
    u32 v1;
    s32 v2;
    f32 v3;
    f32 v4;
    f32 v5;
    v0 = (s32)(f32)(*(f32 *)((u8 *)arg0 + 84) / lbl_1_rodata_DD58);
    v1 = (v0 << 4);
    fn_80074188(__cvt_fp2unsigned(*(f32 *)((u8 *)&lbl_1_bss_8FD68 + v1)),
        __cvt_fp2unsigned(*(f32 *)((u8 *)&lbl_1_bss_8FD68 + v1 + 4)),
        __cvt_fp2unsigned(*(f32 *)((u8 *)&lbl_1_bss_8FD68 + v1 + 8)),
        __cvt_fp2unsigned(*(f32 *)((u8 *)&lbl_1_bss_8FD68 + v1 + 12)));
    v2 = (v0 * (0xF0000 + 16960));
    v3 = *(f32 *)((u8 *)arg0 + 84);
    v4 = *(f32 *)((u8 *)arg1 + 0);
    *(f32 *)((u8 *)arg1 + 0) = (f32)(v4 + (f32)(v3 - (f32)(s32)v2));
    v5 = *(f32 *)((u8 *)arg1 + 12);
    *(f32 *)((u8 *)arg1 + 12) = (f32)(v5 + (f32)(v3 - (f32)(s32)v2));
    return v5;
}
#pragma opt_dead_assignments reset

#pragma opt_common_subs reset
/* fzgx:end fn_1_15C5A4 */

/* fzgx:begin fn_1_15DD7C */
/* Literal-pool primer: this TU's shared pool (retail lbl_1_rodata_DD58) is laid out in
 * first-use order across the whole TU, so the words that precede this function's own
 * literals are referenced here, in retail order, from a section the link drops. */
#pragma section RX ".fzgxpool"

__declspec(section ".fzgxpool") void fzgx_pool_primer_0(void) {
    fn_1_519FC(1000000.0f);
}

__declspec(section ".fzgxpool") void fzgx_pool_primer_1(void) {
    fn_1_519FC((f32)(s32)lbl_1_bss_3C30.unk_0);
}

static const u32 fzgx_pool_word_10[1] = { 0xFFFFFF00 };

__declspec(section ".fzgxpool") void fzgx_pool_primer_2(void) {
    fn_1_58C4();
    fn_1_519FC(320.0f);
    fn_1_519FC(240.0f);
    fn_1_519FC(1.0f);
    fn_1_519FC(0.8f);
    fn_1_519FC(464.0f);
    fn_1_519FC(5.0f);
    fn_1_519FC(0.7f);
    fn_1_519FC(255.0f);
    fn_1_519FC(3.3f);
    fn_1_519FC(20.0f);
    fn_1_519FC(0.5f);
    fn_1_519FC(0.0f);
    fn_1_519FC(800.0f);
    fn_1_519FC(42.0f);
    fn_1_519FC(30.0f);
    fn_1_519FC(16384.0f);
    fn_1_519FC(32768.0f);
    fn_1_519FC(0.001f);
    fn_1_519FC(3.0f);
    fn_1_519FC(8.0f);
    fn_1_49728(fzgx_pool_word_10[0]);
}

static const u32 fzgx_pool_table_64[24] = {
    0, 0, 75, 100, 76, 0, 35, 100, 152, 0, 75, 100,
    76, 0, 35, 100, 228, 0, 75, 100, 304, 0, 75, 100,
};

__declspec(section ".fzgxpool") void fzgx_pool_primer_3(void) {
    fn_1_519FC(120.0f);
    fn_1_519FC(10.0f);
    fn_1_519FC(2.0f);
    fn_1_519FC(-10.0f);
    fn_1_519FC(0.25f);
    fn_1_519FC(100.0f);
    fn_1_519FC(60.0f);
    fn_1_49728(fzgx_pool_table_64[2]);
}

void fn_1_15DD7C(s32 timer) {
    FontDrawPacket packet;
    f32 fade;

    packet = lbl_1_rodata_26F8;
    if (lbl_1_bss_3C30.unk_0 & 0x8000) {
        return;
    }

    packet.x = 320.0f;
    packet.y = 240.0f;
    packet.image = 0x942B;
    packet.flags = 10;

    if (fn_1_58C4() > 1 || lbl_1_bss_3C30.unk_13F6 == 0) {
        if (240.0f < (f32)timer) {
            packet.alpha = 2.0f * (((f32)timer - 240.0f) / 60.0f);
            if (packet.alpha > 1.0f) {
                packet.alpha = 1.0f;
            }
            packet.alpha = 1.0f - packet.alpha;
        } else {
            packet.alpha = 1.0f;
        }
    } else {
        if (240.0f < (f32)timer) {
            fade = ((f32)timer - 240.0f) / 60.0f;
            if (fade > 1.0f) {
                fade = 1.0f;
            }
            packet.alpha = 1.0f - fade;
        } else if ((f32)timer < 60.0f) {
            packet.alpha = (f32)timer / 60.0f;
        } else {
            packet.alpha = 1.0f;
        }
    }

    packet.scale_y = 1.0f;
    packet.scale_x = 1.0f;
    packet.x = fn_1_519FC(packet.x);
    packet.y = fn_1_51AC0(packet.y);
    packet.z = 2.0f;
    packet.scale_x *= (fn_1_58C4() == 1) ? 1.0f : 0.8f;
    packet.scale_y *= (fn_1_58C4() == 1) ? 1.0f : 0.8f;
    fn_1_4F734(&packet);
}
/* fzgx:end fn_1_15DD7C */

/* fzgx:begin fn_1_15DFD4 noprologue */
#include "types.h"

extern f32 lbl_1_rodata_DD6C[11];
extern f32 lbl_1_rodata_DE50[39];
extern void fn_1_496FC(f32, f32);
extern void fn_1_49410(void);
extern void fn_1_49728(int);
extern void fn_1_495FC(void);
extern void fn_1_495C8(int);
extern void fn_1_15DD7C(u16);
extern void fn_1_15C6C0(u16, int);
extern void fn_1_49614(void);
extern void fn_1_A4C9C(int, u8);

extern u8 lbl_1_bss_26B18;
extern u8 lbl_1_bss_26B1A;
extern u8 lbl_1_bss_26B19;
extern u8 lbl_1_bss_26B1E;
extern u32 lbl_1_bss_3C30;

typedef struct {
    u8 pad_0[0xB];
    u8 unk_B;
    u8 pad_C[0x28];
} BgWin38;

extern BgWin38 lbl_1_bss_8FDA8[];
extern u16 lbl_1_bss_50EC[];

void fn_1_15DFD4(int index, int flags) {
    int state;

    flags &= 0xff;
    if (lbl_1_bss_26B18 & flags) {
        state = 4;
    } else if (lbl_1_bss_26B1A & flags) {
        state = 2;
    } else if (lbl_1_bss_26B19 & flags) {
        state = 1;
    } else if (lbl_1_bss_26B1E & flags) {
        state = 3;
    } else {
        return;
    }

    if (lbl_1_bss_3C30 & 0x1000) {
        lbl_1_bss_8FDA8[index].unk_B = 0;
    } else {
        lbl_1_bss_8FDA8[index].unk_B = 1;
    }

    fn_1_496FC(lbl_1_rodata_DD6C[0], lbl_1_rodata_DE50[0]);
    fn_1_49410();
    fn_1_49728(1);
    fn_1_495FC();
    fn_1_495C8(9);

    switch (state) {
    case 1: {
        u16 v = lbl_1_bss_50EC[index];
        if (lbl_1_bss_8FDA8[index].unk_B != 0) {
            fn_1_15DD7C(v);
        }
        break;
    }
    case 2: {
        u16 v = lbl_1_bss_50EC[index];
        if (lbl_1_bss_8FDA8[index].unk_B != 0) {
            fn_1_15DD7C(v);
        }
        break;
    }
    case 3:
        fn_1_15C6C0(lbl_1_bss_50EC[index], index);
        break;
    case 4: {
        u16 v = lbl_1_bss_50EC[index];
        if (lbl_1_bss_8FDA8[index].unk_B != 0) {
            fn_1_15DD7C(v);
        }
        break;
    }
    }

    fn_1_49614();
    fn_1_49728(0);
    fn_1_A4C9C(index, state);
}
/* fzgx:end fn_1_15DFD4 */

/* fzgx:begin fn_1_15E1D0 */
// Returns the float field of the indexed background-window entry.
f32 fn_1_15E1D0(u32 index) {
    return *(f32 *)((u8 *)(&lbl_1_bss_8FDA8.unk_30) + index * 0x34);
}
/* fzgx:end fn_1_15E1D0 */

/* fzgx:begin fn_1_15E1E8 */
void fn_1_15E1E8(u8 *value) {
    u8 state = *value;

    if (state == 0) {
        fn_1_4060();
    } else {
        *value = state - 1;
    }
}
/* fzgx:end fn_1_15E1E8 */

/* fzgx:begin fn_1_15E220 */
void fn_1_15E220(u8 *value) {
    u8 state = *value;

    if (state == 0) {
        fn_1_4060();
    } else if (state != 0xff) {
        *value = state - 1;
    }
}
/* fzgx:end fn_1_15E220 */

/* fzgx:begin fn_1_15E260 */
// Marks the indexed background-window entry as active.
void fn_1_15E260(s32 index) {
    (&lbl_1_bss_8FDA8.unk_0)[index * 0x34] |= 4;
}
/* fzgx:end fn_1_15E260 */

/* fzgx:begin fn_1_15E330 */
void fn_1_15E330(s32 index, u32 value, void *arg) {
    if (lbl_1_bss_3C30.unk_13F4 - (&lbl_1_bss_8FDA8.unk_8)[index * 0x34] < 4) {
        void *result;

        (&lbl_1_bss_8FDA8.unk_0)[index * 0x34] |= 8;
        (&lbl_1_bss_8FDA8.unk_C)[index * 13] = value;
        result = (void *)fn_1_435C( (u32)(void *)(arg));
        fn_1_3F8C( (u32)(void *)(lbl_1_data_4C980), (u32)(void *)(fn_1_15E1E8), (u32)(u8 *)(&(&lbl_1_bss_8FDA8.unk_9)[index * 0x34]), 13);
        (&lbl_1_bss_8FDA8.unk_9)[index * 0x34] = 0x3c;
        fn_1_435C( (u32)(void *)(result));
    }
}
/* fzgx:end fn_1_15E330 */

/* fzgx:begin fn_1_15E3E0 */
// Records the selected window index and updates its value when the index is valid.
void fn_1_15E3E0(s32 index, u32 value) {
    s32 slot = (lbl_1_bss_3C30.unk_13F4 - 1) % 4;

    lbl_1_bss_8FE80[slot] = index;
    if (index != -1) {
        (&lbl_1_bss_8FDA8.unk_C)[index * 13] = value;
    }
}
/* fzgx:end fn_1_15E3E0 */

/* fzgx:begin fn_1_15E434 */
void fn_1_15E434(u32 value) {
    lbl_1_bss_8FE7C = 1;
    lbl_1_bss_8FEA0 = value;
}
/* fzgx:end fn_1_15E434 */

/* fzgx:begin fn_1_15E44C pool noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_win.h"
#include "font.h"

extern u32 fn_1_435C(u32 value);
extern s32 fn_1_3F8C(u32, u32, u32, u32);
extern void fn_1_15E1E8(u8 *value);

typedef struct {
    Obj_1_bss_8FD68 header;
    Obj_1_bss_8FDA8 entries;
    u8 unk_114;
    u8 pad_115[3];
    s32 unk_118;
    u8 pad_11C[0x1c];
    u32 unk_138;
} WindowState;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_8FD68[16];
Obj_1_bss_8FDA8 fzgx_obj_lbl_1_bss_8FDA8;
u8 lbl_1_bss_8FE7C;
u8 lbl_1_bss_8FD68_gap_8FE7D;
u16 lbl_1_bss_8FD68_gap_8FE7D_fill_8FE7E;
s32 lbl_1_bss_8FE80;
u32 lbl_1_bss_8FE80_fill_8FE84[7];
u32 lbl_1_bss_8FEA0;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8FD68;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8FDA8;
    s = *(u8 *)&lbl_1_bss_8FE7C;
    s = *(u8 *)&lbl_1_bss_8FD68_gap_8FE7D;
    s = *(u8 *)&lbl_1_bss_8FD68_gap_8FE7D_fill_8FE7E;
    s = *(u8 *)&lbl_1_bss_8FE80;
    s = *(u8 *)&lbl_1_bss_8FE80_fill_8FE84;
    s = *(u8 *)&lbl_1_bss_8FEA0;
}
#pragma section code_type ".text"

void fn_1_15E44C(void) {
    
    u8 state = lbl_1_bss_3C30.unk_13F5;
    s32 index = *(s32 *)((u32)&lbl_1_bss_8FE80 + ((state - 1) % 4) * 4);
    u32 value = lbl_1_bss_8FEA0;
    void *result;

    if (lbl_1_bss_8FE7C) {
        s32 count = lbl_1_bss_3C30.unk_13F4;
        lbl_1_bss_8FE7C = 0;
        if (count - state < 4 && index != -1) {
            s32 offset = index * 0x34;
            Obj_1_bss_8FDA8 *entry = (Obj_1_bss_8FDA8 *)((u32)&fzgx_obj_lbl_1_bss_8FDA8 + offset);
            entry->unk_0 |= 0x10;
            result = (void *)fn_1_435C(value);
            fn_1_3F8C((u32)lbl_1_data_4C980, (u32)fn_1_15E1E8, (u32)&entry->unk_9, 13);
            (&fzgx_obj_lbl_1_bss_8FDA8.unk_9)[offset] = 0x3c;
            fn_1_435C((u32)result);
        }
    }
}
/* fzgx:end fn_1_15E44C */

/* fzgx:begin fn_1_15E540 */
// Initializes a background-window entry once, then marks it ready for reuse.
void fn_1_15E540(s32 index, void *arg) {
    if (!((&lbl_1_bss_8FDA8.unk_0)[index * 0x34] & 1)) {
        void *value = (void *)fn_1_435C( (u32)(void *)(arg));

        fn_1_3F8C( (u32)(void *)(lbl_1_data_4C994), (u32)(void *)(fn_1_15E220), (u32)(u8 *)(&lbl_1_bss_8FDA8.unk_1 + index * 0x34), 13);
        (&lbl_1_bss_8FDA8.unk_1)[index * 0x34] = 0xff;
        fn_1_435C( (u32)(void *)(value));
        (&lbl_1_bss_8FDA8.unk_0)[index * 0x34] |= 1;
    }
}
/* fzgx:end fn_1_15E540 */

/* fzgx:begin fn_1_15E5E4 */
// Initializes a background-window entry once, then marks it ready for reuse.
void fn_1_15E5E4(s32 index, void *arg) {
    Obj_1_bss_8FDA8 *obj;
    s32 offset = index * 0x34;

    obj = (Obj_1_bss_8FDA8 *)((u8 *)&lbl_1_bss_8FDA8 + offset);

    if (!(obj->unk_0 & 2)) {
        void *value = (void *)fn_1_435C( (u32)(void *)(arg));

        fn_1_3F8C( (u32)(void *)(lbl_1_data_4C994), (u32)(void *)(fn_1_15E220), (u32)(u8 *)(&obj->unk_2), 13);
        (&lbl_1_bss_8FDA8.unk_2)[offset] = 0xff;
        fn_1_435C( (u32)(void *)(value));
        obj->unk_0 |= 2;
    }
}
/* fzgx:end fn_1_15E5E4 */

/* fzgx:begin fn_1_15E688 */
void fn_1_15E688(s32 index, u32 value, u8 state, void *arg) {
    void *obj;
    Obj_1_bss_8FDA8 *entry;

    obj = (void *)fn_1_435C( (u32)(void *)(arg));
    fn_1_3F8C( (u32)(void *)(lbl_1_data_4C980), (u32)(void *)(fn_1_15E1E8), (u32)(u8 *)(&(&lbl_1_bss_8FDA8.unk_0)[index * 0x34] + 3), 13);
    (&lbl_1_bss_8FDA8.unk_0)[index * 0x34 + 3] = 0x5a;
    fn_1_435C( (u32)(void *)(obj));
    entry = (Obj_1_bss_8FDA8 *)((u8 *)&lbl_1_bss_8FDA8 + index * 0x34);
    ((u32 *)&entry->unk_10)[(state - 1) % 8] = value;
    entry->unk_4 = value;
    entry->unk_8 = state;
}
/* fzgx:end fn_1_15E688 */

/* fzgx:begin fn_1_15E764 */
// Initializes the entry's 13-byte block, then marks it ready for reuse.
void fn_1_15E764(s32 index, void *arg) {
    void *value = (void *)fn_1_435C( (u32)(void *)(arg));

    fn_1_3F8C( (u32)(void *)(lbl_1_data_4C994), (u32)(void *)(fn_1_15E220), (u32)(u8 *)(&lbl_1_bss_8FDA8.unk_A + index * 0x34), 13);
    (&lbl_1_bss_8FDA8.unk_A)[index * 0x34] = 0xff;
    fn_1_435C( (u32)(void *)(value));
    (&lbl_1_bss_8FDA8.unk_A)[index * 0x34] = 0xff;
}
/* fzgx:end fn_1_15E764 */

/* fzgx:begin fn_1_15EC40 */
typedef struct {
    u8 r, g, b, a;
} BgWinColor;

typedef struct {
    u8 flags;
    u8 pad_1[0x7];
    u8 slot;
    u8 timer;
    u8 pad_A[0x2];
    u32 time;
} BgWinTimeEntry;

extern void fn_1_49514(BgWinColor *);
extern void fn_1_494DC(s16);
extern void fn_1_495B0(u32);
extern void fn_1_495A0(f32);
extern u32 fn_1_58C4(void);
extern void fn_1_4955C(f32, f32);
extern f32 fn_1_51AC0(f32);
extern f32 fn_1_519FC(f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_49728(u8 value);

/* Literal-pool primer: this TU's shared pool (retail lbl_1_rodata_DD58) is laid out in
 * first-use order across the whole TU, so the words that precede this function's own
 * literals are referenced here, in retail order, from a section the link drops. */
#pragma section RX ".fzgxpool"

__declspec(section ".fzgxpool") void fzgx_pool_primer_0(void) {
    fn_1_519FC(1000000.0f);
}

__declspec(section ".fzgxpool") void fzgx_pool_primer_1(void) {
    fn_1_519FC((f32)(s32)lbl_1_bss_3C30.unk_0);
}

static const u32 fzgx_pool_word_10[1] = { 0xFFFFFF00 };

__declspec(section ".fzgxpool") void fzgx_pool_primer_2(void) {
    fn_1_58C4();
    fn_1_519FC(320.0f);
    fn_1_519FC(240.0f);
    fn_1_519FC(1.0f);
    fn_1_519FC(0.8f);
    fn_1_519FC(464.0f);
    fn_1_519FC(5.0f);
    fn_1_519FC(0.7f);
    fn_1_519FC(255.0f);
    fn_1_519FC(3.3f);
    fn_1_519FC(20.0f);
    fn_1_519FC(0.5f);
    fn_1_519FC(0.0f);
    fn_1_519FC(800.0f);
    fn_1_519FC(42.0f);
    fn_1_519FC(30.0f);
    fn_1_519FC(16384.0f);
    fn_1_519FC(32768.0f);
    fn_1_519FC(0.001f);
    fn_1_519FC(3.0f);
    fn_1_519FC(8.0f);
    fn_1_49728(fzgx_pool_word_10[0]);
}

static const u32 fzgx_pool_table_64[24] = {
    0, 0, 75, 100, 76, 0, 35, 100, 152, 0, 75, 100,
    76, 0, 35, 100, 228, 0, 75, 100, 304, 0, 75, 100,
};

__declspec(section ".fzgxpool") void fzgx_pool_primer_3(void) {
    fn_1_519FC(120.0f);
    fn_1_519FC(10.0f);
    fn_1_519FC(2.0f);
    fn_1_519FC(-10.0f);
    fn_1_519FC(0.25f);
    fn_1_519FC(100.0f);
    fn_1_519FC(60.0f);
    fn_1_49728(fzgx_pool_table_64[2]);
}

static const u32 fzgx_pool_table_E0[3] = { 0x45A00000, 0x3FC00000, 0x43500000 };

__declspec(section ".fzgxpool") void fzgx_pool_primer_4(void) {
    fn_1_49728(fzgx_pool_table_E0[0]);
    fn_1_519FC(0.9f);
}

static const u32 fzgx_pool_table_F0[6] = { 0x42480000, 0x43B90000, 0x43000000, 0x43160000, 0x3E000000, 0 };

__declspec(section ".fzgxpool") void fzgx_pool_primer_5(void) {
    fn_1_49728(fzgx_pool_table_F0[0]);
    fn_1_519FC((f32)lbl_1_bss_3C30.unk_0);
}

static const u32 fzgx_pool_table_110[24] = {
    0x0000000F, 0x00000007, 0x0000000D, 0x00000005, 0x00000000, 0x00000000,
    0x3F000000, 0x3F000000, 0x00000000, 0x3F000000, 0x3F000000, 0x3F800000,
    0x3F000000, 0x00000000, 0x3F800000, 0x3F000000, 0x3F000000, 0x3F000000,
    0x3F800000, 0x3F800000, 0x42200000, 0x43AF0000, 0x3FB33333, 0x42B40000,
};

__declspec(section ".fzgxpool") void fzgx_pool_primer_6(void) {
    fn_1_49728(fzgx_pool_table_110[0]);
    fn_1_519FC(15.0f);
}

static const u32 fzgx_pool_table_174[1] = { 0x43960000 };

__declspec(section ".fzgxpool") void fzgx_pool_primer_7(void) {
    fn_1_49728(fzgx_pool_table_174[0]);
}

#pragma section RX ".text"

/* packed time: minutes in bits 20-27, seconds in 12-19, milliseconds in 0-11 */
static inline u32 bgwin_time_ms(u32 t) {
    u32 min = (t >> 20) & 0xFF;
    u32 sec = (t >> 12) & 0xFF;
    u32 ms = (sec + min * 60) * 1000;
    ms = (t & 0xFFF) + ms;
    return ms;
}

static inline u32 bgwin_time_diff(u32 a, u32 b) {
    u32 ms_a = bgwin_time_ms(a);
    u32 ms_b;
    u32 frac_b = b & 0xFFF;
    u32 d;
    ms_b = ((b >> 12) & 0xFF) + ((b >> 20) & 0xFF) * 60;
    ms_b *= 1000;
    ms_b = frac_b + ms_b;
    d = ms_a - ms_b;
    if (ms_b > ms_a) {
        d = ms_b - ms_a;
    }
    return ((d / 60000) << 20) | (((d / 1000) % 60) << 12) | (d % 1000);
}

void fn_1_15EC40(BgWinTimeEntry *entry) {
    f32 scale;
    f32 t;
    u32 diff;
    u8 sign;
    s32 ahead;
    u32 a;
    struct { u32 value; } b;
    u8 n;
    f32 s0;
    f32 s1;

    ahead = 1;
    n = entry->timer;
    if (n > 45) {
        t = (f32)(s32)(60 - n) / 15.0f;
        scale = 0.5f * t;
    } else if (n < 15) {
        t = (f32)n / 15.0f;
        scale = 0.5f * t;
    } else {
        scale = 0.5f;
        t = 1.0f;
    }

    if (entry->flags & 8) {
        a = (&lbl_1_bss_3C30.unk_13B4)[(entry->slot - 1) % 4];
        if (a == 0 || (b.value = entry->time) == 0) {
            return;
        }
        diff = bgwin_time_diff(a, b.value);
        if (a < b.value) {
            ahead = 0;
        }
    } else {
        s32 i = (lbl_1_bss_3C30.unk_13F5 - 1) % 4;
        a = (&lbl_1_bss_3C30.unk_13B4)[i];
        b.value = (&lbl_1_bss_3C30.unk_13D4)[i];
        if (a == 0 || b.value == 0) {
            return;
        }
        diff = bgwin_time_diff(a, b.value);
        if (a > b.value) {
            ahead = 0;
        }
    }

    if (ahead) {
        BgWinColor c = {0x00, 0xFF, 0x00, 0x00};
        fn_1_49514(&c);
        sign = ';';
    } else {
        BgWinColor c = {0xE6, 0x00, 0x00, 0xFF};
        fn_1_49514(&c);
        sign = ':';
    }
    fn_1_494DC(10);
    fn_1_495B0(0x80000000);
    fn_1_495A0(scale);
    s0 = (fn_1_58C4() == 1) ? 1.0f : 0.8f;
    s1 = (fn_1_58C4() == 1) ? 1.0f : 0.8f;
    fn_1_4955C(0.885f * t * s1, 0.9f * s0);
    fn_1_496FC(fn_1_519FC(315.0f), fn_1_51AC0(250.0f));
    fn_1_4AE0C((const char *)lbl_1_data_4C9B0, sign, (diff >> 20) & 0xFF, (diff >> 12) & 0xFF, diff & 0xFFF);
    {
        BgWinColor c = {0xFF, 0xFF, 0xFF, 0x00};
        fn_1_49514(&c);
    }
}
/* fzgx:end fn_1_15EC40 */

/* fzgx:begin fn_1_15EFEC pool noprologue */
#include "types.h"
#include "font.h"
#include "rel/main_rel/bg_win.h"

struct fn_1_15EFEC_lbl_1_rodata_DD58 {
 u8 pad_0[8]; f64 unk_8; u8 pad_10[4]; f32 unk_14; u8 pad_18[4]; f32 unk_1C; f32 unk_20;
 u8 pad_24[12]; f32 unk_30; u8 pad_34[8]; f32 unk_3C; u8 pad_40[24]; f32 unk_58; f32 unk_5C;
 u8 pad_60[132]; f32 unk_E4; u8 pad_E8[4]; f32 unk_EC; u8 pad_F0[12]; f32 unk_FC; f32 unk_100; u8 pad_104[4]; f64 unk_108; u8 pad_110[96]; f32 unk_170; f32 unk_174; u8 pad_178[24]; f32 unk_190;
};
/* Shared literal-pool primer: lays the TU's pool out in retail order so this
 * function's literals land on the retail offsets. Dropped at integration. */
#pragma section code_type ".fzgxpool"
static const u32 lbl_1_rodata_DD58[2] = { /* fzgx-allow: A1 exact retail literal-pool bytes */
 0x49742400, 0x00000000
};
static void fzgx_fn_1_15EFEC_pool_8(void) {
 volatile f64 value = 4503601774854144.0; /* volatile: materializes this shared-pool constant before the next data object */
}
static const u32 pool_pad_10[1] = { /* fzgx-allow: A1 exact retail literal-pool bytes */
 0xFFFFFF00
};
static void fzgx_fn_1_15EFEC_pool_14(void) {
 volatile f32 value = 320.0f; /* volatile: materializes this shared-pool constant before the next data object */
}
static const u32 pool_pad_18[1] = { /* fzgx-allow: A1 exact retail literal-pool bytes */
 0x43700000
};
static void fzgx_fn_1_15EFEC_pool_1c(void) {
 volatile f32 value = 1.0f; /* volatile: materializes this shared-pool constant before the next data object */
}
static void fzgx_fn_1_15EFEC_pool_20(void) {
 volatile f32 value = 0.800000011920929f; /* volatile: materializes this shared-pool constant before the next data object */
}
static const u32 pool_pad_24[3] = { /* fzgx-allow: A1 exact retail literal-pool bytes */
 0x43E80000, 0x40A00000, 0x3F333333
};
static void fzgx_fn_1_15EFEC_pool_30(void) {
 volatile f32 value = 255.0f; /* volatile: materializes this shared-pool constant before the next data object */
}
static const u32 pool_pad_34[2] = { /* fzgx-allow: A1 exact retail literal-pool bytes */
 0x40533333, 0x41A00000
};
static void fzgx_fn_1_15EFEC_pool_3c(void) {
 volatile f32 value = 0.5f; /* volatile: materializes this shared-pool constant before the next data object */
}
static const u32 pool_pad_40[6] = { /* fzgx-allow: A1 exact retail literal-pool bytes */
 0x00000000, 0x44480000, 0x42280000, 0x41F00000, 0x46800000, 0x47000000
};
static void fzgx_fn_1_15EFEC_pool_58(void) {
 volatile f32 value = 0.0010000000474974513f; /* volatile: materializes this shared-pool constant before the next data object */
}
static void fzgx_fn_1_15EFEC_pool_5c(void) {
 volatile f32 value = 3.0f; /* volatile: materializes this shared-pool constant before the next data object */
}
static const u32 pool_pad_60[33] = {
 0x41000000, 0x00000000, 0x00000000, 0x0000004B, 0x00000064, 0x0000004C, 0x00000000, 0x00000023, 0x00000064, 0x00000098, 0x00000000, 0x0000004B, 0x00000064, 0x0000004C, 0x00000000, 0x00000023, 0x00000064, 0x000000E4, 0x00000000, 0x0000004B, 0x00000064, 0x00000130, 0x00000000, 0x0000004B, 0x00000064, 0x42F00000, 0x41200000, 0x40000000, 0xC1200000, 0x3E800000, 0x42C80000, 0x42700000, 0x45A00000 /* fzgx-allow: A1 exact retail literal-pool bytes (-10.0f) */
};
static void fzgx_fn_1_15EFEC_pool_e4(void) {
 volatile f32 value = 1.5f; /* volatile: materializes this shared-pool constant before the next data object */
}
static const u32 pool_pad_e8[1] = { /* fzgx-allow: A1 exact retail literal-pool bytes */
 0x43500000
};
static void fzgx_fn_1_15EFEC_pool_ec(void) {
 volatile f32 value = 0.8999999761581421f; /* volatile: materializes this shared-pool constant before the next data object */
}
static const u32 pool_pad_f0[3] = { /* fzgx-allow: A1 exact retail literal-pool bytes */
 0x42480000, 0x43B90000, 0x43000000
};
static void fzgx_fn_1_15EFEC_pool_fc(void) {
 volatile f32 value = 150.0f; /* volatile: materializes this shared-pool constant before the next data object */
}
static void fzgx_fn_1_15EFEC_pool_100(void) {
 volatile f32 value = 0.125f; /* volatile: materializes this shared-pool constant before the next data object */
}
static const u32 pool_pad_104[1] = { /* fzgx-allow: A1 exact retail literal-pool bytes */
 0x00000000
};
static void fzgx_fn_1_15EFEC_pool_108(void) {
 volatile f64 value = 4503599627370496.0; /* volatile: materializes this shared-pool constant before the next data object */
}
static const u32 pool_pad_110[24] = { /* fzgx-allow: A1 exact retail literal-pool bytes */
 0x0000000F, 0x00000007, 0x0000000D, 0x00000005, 0x00000000, 0x00000000, 0x3F000000, 0x3F000000, 0x00000000, 0x3F000000, 0x3F000000, 0x3F800000, 0x3F000000, 0x00000000, 0x3F800000, 0x3F000000, 0x3F000000, 0x3F000000, 0x3F800000, 0x3F800000, 0x42200000, 0x43AF0000, 0x3FB33333, 0x42B40000
};
static void fzgx_fn_1_15EFEC_pool_170(void) {
 volatile f32 value = 15.0f; /* volatile: materializes this shared-pool constant before the next data object */
}
static void fzgx_fn_1_15EFEC_pool_174(void) {
 volatile f32 value = 300.0f; /* volatile: materializes this shared-pool constant before the next data object */
}
static const u32 pool_pad_178[6] = { /* fzgx-allow: A1 exact retail literal-pool bytes */
 0x00FF0000, 0xE60000FF, 0xFFFFFF00, 0x3F628F5C, 0x439D8000, 0x437A0000
};
static void fzgx_fn_1_15EFEC_pool_190(void) {
 volatile f32 value = 0.009999999776482582f; /* volatile: materializes this shared-pool constant before the next data object */
}
#pragma section code_type ".text"
#define pool_14 (320.0f)
#define pool_1c (1.0f)
#define pool_20 (0.800000011920929f)
#define pool_30 (255.0f)
#define pool_3c (0.5f)
#define pool_58 (0.0010000000474974513f)
#define pool_5c (3.0f)
#define pool_e4 (1.5f)
#define pool_ec (0.8999999761581421f)
#define pool_fc (150.0f)
#define pool_100 (0.125f)
#define pool_170 (15.0f)
#define pool_174 (300.0f)
#define pool_190 (0.009999999776482582f)
extern FontDrawPacket lbl_1_rodata_26F8;
extern f32 fn_1_519FC(f32);
extern f32 fn_1_51AC0(f32);
extern f32 lbl_8006D0B4(f32);
extern f32 lbl_8006D188(u32);
extern int fn_1_4F734(FontDrawPacket*);
extern u32 fn_1_58C4(void);
extern u32 fn_1_15C4EC(void*);
extern u32 fn_1_15E7F4(void*,u32);
extern u32 fn_1_15EC40(void*);
extern s32 fn_1_3F864(void);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_4955C(f32,f32);
extern void fn_1_495A0(f32);
extern void fn_1_495B0(u32);
extern void fn_1_495C8(u8);
extern void fn_1_495FC(void);
extern void fn_1_496FC(f32,f32);
extern void fn_1_49728(u8);
extern void fn_1_4AE0C(const char*,...);
extern void fn_1_A2D84(u32);
void fn_1_15EFEC(s32 arg0) {
 u32 *p_lbl_1_data_3D544;
 s32 v4 = 1;
 struct { Obj_1_bss_8FDA8 *p; } player;
 s32 index;
 u32 v2;
 f32 v9,v10,v12,v14,v15,v16,v17,v23,v24,v25,v26,v29,v30,v31,v32,v39,v46;
 f32 v35;
 f32 v34;
 f32 sy;
 u8 v11,v27,v33;
 s32 v13,v28;
 f32 t10,t11,t21,t30;
 u32 v40;
 FontDrawPacket loc_60;
 FontDrawPacket loc_8;
 index = arg0;
 player.p = (Obj_1_bss_8FDA8 *)((u8 *)&lbl_1_bss_8FDA8 + index * 52);
 fn_1_49410();
 fn_1_495FC();
 fn_1_495C8(9);
 v2 = index;
 p_lbl_1_data_3D544 = (u32 *)&lbl_1_data_3D544;
 if (p_lbl_1_data_3D544[v2] & 4) {
 if (player.p->unk_A != 0) {
 if (player.p->unk_A == 255) {
 if (fn_1_3F864()) { fn_1_A2D84(0xA9061A00); fn_1_A2D84(0xA9092800); }
 player.p->unk_A = 120;
 }
 loc_60 = lbl_1_rodata_26F8;
 loc_60.x = fn_1_519FC(pool_14);
 loc_60.y = fn_1_51AC0(pool_fc);
 loc_60.z = pool_190;
 loc_60.image = 0x9431;
 loc_60.flags = 0x400000A;
 loc_60.vertex_callback = (void (*)(FontDrawPacket*,FontVertex*))fn_1_15C4EC;
 *(f32*)((u8*)&loc_60+84) = (f32)index;
 v9 = fn_1_58C4() == 1 ? pool_1c : pool_20;
 loc_60.scale_x *= v9;
 v10 = fn_1_58C4() == 1 ? pool_1c : pool_20;
 v11 = player.p->unk_A;
 v12 = loc_60.scale_y * v10;
 loc_60.scale_y = v12;
 if (v11 > 90) {
 t10 = lbl_8006D188((s16)((120-v11)*1092));
 t11 = lbl_8006D0B4(pool_1c - (f32)(t10*t10));
 loc_60.scale_y *= t11;
 v13 = (s32)(pool_30 * t10);
 loc_60.color_add[2] = v13; loc_60.color_add[1] = v13; loc_60.color_add[0] = v13;
 } else if (v11 < 8) {
 v14 = pool_100;
 v15 = pool_5c;
 v16 = (f32)(u32)v11*v14;
 loc_60.alpha = v16;
 v17 = v12*v16;
 loc_60.scale_y = v17;
 loc_60.scale_x *= v15 - (f32)(pool_e4*v16);
 }
 fn_1_4F734(&loc_60);
 v4=0;
 }
 if (v4) {
 if (player.p->unk_2) { fn_1_15E7F4(player.p,index); }
 else if (player.p->unk_1) {
 if (player.p->unk_1==255) {
 if (fn_1_3F864()) fn_1_A2D84(0xA9061600);
 player.p->unk_1=120;
 }
 loc_8 = lbl_1_rodata_26F8;
 loc_8.x = fn_1_519FC(pool_14);
 loc_8.y = fn_1_51AC0(pool_fc);
 loc_8.z = pool_58;
 loc_8.image = 0x940B;
 loc_8.flags = 0x400000A;
 loc_8.vertex_callback = (void (*)(FontDrawPacket*,FontVertex*))fn_1_15C4EC;
 *(f32*)((u8*)&loc_8+84) = (f32)index;
 v23 = fn_1_58C4()==1 ? pool_1c : pool_20;
 loc_8.scale_x *= (f32)(pool_ec*v23);
 v24 = fn_1_58C4()==1 ? pool_1c : pool_20;
 loc_8.scale_y *= (f32)(pool_ec*v24);
 if (fn_1_58C4()>1) {
 v25 = pool_20;
 v26 = loc_8.scale_x*v25;
 loc_8.scale_x = v26;
 loc_8.scale_y *= v25;
 }
 v27 = player.p->unk_1;
 if (v27>90) {
 t21 = lbl_8006D188((s16)((120-v27)*1092));
 v28 = (s32)(pool_30*t21);
 loc_8.color_add[2]=v28; loc_8.color_add[1]=v28; loc_8.color_add[0]=v28;
 } else if (v27<8) {
 v29=pool_100;
 v30=pool_5c;
 v31=(f32)(u32)v27*v29;
 loc_8.alpha=v31;
 v32=loc_8.scale_y*v31;
 loc_8.scale_y=v32;
 loc_8.scale_x *= v30-(f32)(pool_e4*v31);
 }
 fn_1_4F734(&loc_8);
 }
 }
 }
 v33=player.p->unk_3;
 if (v33 && (p_lbl_1_data_3D544[v2]&0x1000000)) {
 if (v33>75) {
 v34=(f32)(s32)(90-v33)/pool_170;
 v35=pool_3c*v34;
 } else if (v33<15) {
 v34=(f32)(u32)v33/pool_170;
 v35=pool_3c*v34;
 } else { v35=pool_3c; v34=pool_1c; }
 fn_1_494DC(10);
 fn_1_495B0(0x80000000);
 /* if/else (not ?:) keeps the y scale a declared web below v35/v34 (f29). */
 if (fn_1_58C4()==1) { sy = pool_1c; } else { sy = pool_20; }
 fn_1_4955C(v34*(fn_1_58C4()==1 ? pool_1c : pool_20),sy);
 fn_1_495A0(v35);
 v35=fn_1_51AC0(pool_174);
 t30=fn_1_519FC(pool_14);
 fn_1_496FC(t30,v35);
 v40=player.p->unk_4;
 fn_1_4AE0C((const char*)lbl_1_data_4C9A0,(v40>>20)&255,(v40>>12)&255,v40&4095);
 }
 if (player.p->unk_9 && (p_lbl_1_data_3D544[v2]&0x400000)) fn_1_15EC40(player.p);
 else player.p->unk_0 &= ~0x18;
 v34=(f32)(u32)player.p->unk_3/pool_170;
 if (v34>pool_1c) v34=pool_1c;
 player.p->unk_30 = (f32)(u32)player.p->unk_8-v34;
 fn_1_49728(0);
}
/* fzgx:end fn_1_15EFEC */

/* fzgx:begin fn_1_15F618 */
void *fn_1_15F618(s32 index) {
    return (u8 *)&lbl_1_bss_8FDA8 + index * 0x34;
}
/* fzgx:end fn_1_15F618 */
