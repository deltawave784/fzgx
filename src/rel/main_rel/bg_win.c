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

/* fzgx:begin fn_1_15F618 */
void *fn_1_15F618(s32 index) {
    return (u8 *)&lbl_1_bss_8FDA8 + index * 0x34;
}
/* fzgx:end fn_1_15F618 */
