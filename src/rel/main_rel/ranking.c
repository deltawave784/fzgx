#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/ranking.h"
#include "game/main_rel/ranking_types.h"

extern void fn_1_12EF80(s16 value, s16 *out_0, s16 *out_1);
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern void fn_80008BEC(void *dest, int value, u32 size);
extern void fn_1_3EF14(void *arg1);
extern char *strncpy(char *dst, const char *src, size_t n);
extern f32 lbl_1_rodata_D8C8[18];
extern void fn_1_1569E8(void *entry);
extern s32 fn_8006B55C(void *, u32 *, void *);
extern s32 fn_8006B628(u32 value, u32 param);
extern s32 fn_8006B6F8(u32 value);
extern const f32 lbl_1_rodata_D910;
extern f32 lbl_1_rodata_D914[3];
extern s32 fn_8006B7B4(u32 value);
extern f32 lbl_1_rodata_D920;
extern u32 fn_1_157920(void);
extern void fn_1_4060(void);
extern void fn_1_157950(void);
extern void fn_1_157FC8(void);
extern void fn_1_4811C(int arg);
extern f32 lbl_1_rodata_DAE8;
extern f64 lbl_1_rodata_DAF0;
extern s16 fn_1_14F01C(s16 value);
extern u32 lbl_801A6410[];
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern Obj_1_bss_8EF20_At0 *fn_1_4630(u32, u32, u8 *, u32);
extern u32 fn_1_451C(void);
extern void fn_1_A1340(void);
extern s16 lbl_1_bss_962;
extern s16 lbl_1_bss_96A;
extern void fn_1_A1360(void);
extern void fn_1_A1364(void);
extern u8 lbl_1_bss_8F420[8];
extern void fn_1_1574E0();
extern s32 fn_8006B870();
extern u32 lbl_1_bss_8F57C[3];
extern void fn_1_9AD88(void);
extern void fn_1_1594AC(int index, int flag);
extern void OSReport(const char *format, ...);
extern s32 fn_1_465D0(s32 arg0, s32 arg1);
extern void fn_1_9AD54(void);
extern s32 fn_1_156218(u32 arg, void *out0, void *out1, void *out2);
extern u32 lbl_1_bss_8F3FC[9];
extern void fn_1_48004(s32 index, s32 image);
extern u32 lbl_1_rodata_DAF8[16];
extern void fn_1_9A508(void);
extern int lbl_801A66B4;
extern s32 fn_1_46DC4(s32 value);

/* fzgx:begin fn_1_1554D0 */
// Rebuild the ranking object when the previous one has been consumed.
void fn_1_1554D0(void) {
    Obj_1_bss_8EF20_At0 *obj = lbl_1_bss_8EF20.unk_0;

    if (obj != 0) {
        fn_1_46B4(lbl_801A6410[0], (u32)(Obj_1_bss_8EF20_At0 *)(obj), (const char *)(u8 *)(lbl_1_data_49B08), 0xD50);
        lbl_1_bss_8EF20.unk_0 = 0;
    }

    if (lbl_1_bss_8EF20.unk_0 == 0) {
        lbl_1_bss_8EF20.unk_0 =
            fn_1_4630(lbl_801A6410[0], 0x230, lbl_1_data_49B08, 0xD55);
    }
}
/* fzgx:end fn_1_1554D0 */

/* fzgx:begin fn_1_15555C */
void fn_1_15555C(void) {
    Obj_1_bss_8EF20_At0 *obj = lbl_1_bss_8EF20.unk_0;
    if (obj != 0) {
        fn_1_46B4(lbl_801A6410[0], (u32)(Obj_1_bss_8EF20_At0 *)(obj), (const char *)(u8 *)(lbl_1_data_49B08), 0xD63);
        lbl_1_bss_8EF20.unk_0 = 0;
    }
}
/* fzgx:end fn_1_15555C */

/* fzgx:begin fn_1_1555B0 */
s32 fn_1_1555B0(s32 value) {
    u32 state = (u32)&lbl_1_bss_8EF20;
    s16 index_0;
    s16 index_1;
    u32 table;
    u32 i;
    s32 j;
    u8 *dst;

    if (*(u32 *)state == 0) {
        return 0;
    }

    *(u32 *)(state + 0x40) = value;
    fn_1_12EF80((s16)value, &index_0, &index_1);
    table = (u32)&lbl_1_bss_7F0C0 + (index_1 + index_0 * 6) * 0x180;

    for (i = 0; i < 10; i++) {
        fn_80008BA8( (u32)((void *)(*(u32 *)state + i * 0x38)), (u32)((void *)(table + i * 0x20 + 0xf8)), 0x20);
    }

    fn_80008BEC((void *)(state + 0x48), 0, 0x230);
    dst = (u8 *)state + 0x48;

    for (j = 0; j < 10; j++, dst += 0x38) {
        fn_80008BA8( (u32)(void *)(dst), (u32)((void *)(*(u32 *)state + j * 0x38)), 0x38);
    }

    return 1;
}
/* fzgx:end fn_1_1555B0 */

/* fzgx:begin fn_1_155F7C */
u32 fn_1_155F7C(void) {
    return lbl_1_bss_8F3E0;
}
/* fzgx:end fn_1_155F7C */

/* fzgx:begin fn_1_155F8C */
u32 fn_1_155F8C(void) {
    return lbl_1_bss_8F3E4.unk_0;
}
/* fzgx:end fn_1_155F8C */

/* fzgx:begin fn_1_155F9C */
void fn_1_155F9C(u32 value) {
    lbl_1_bss_8F3E0 = value;
}
/* fzgx:end fn_1_155F9C */

/* fzgx:begin fn_1_155FA8 */
void fn_1_155FA8(u32 value) {
    lbl_1_bss_8F3E4.unk_0 = value;
}
/* fzgx:end fn_1_155FA8 */

/* fzgx:begin fn_1_155FB4 pool noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"

extern void fn_1_3EF14(void *);
extern char *strncpy(char *, const char *, size_t);

typedef struct {
    u32 id;          // 0x0
    u8 pad_4[0x4];
    char name[0x10]; // 0x8
    u16 unk_18;
    u8 unk_1A;
    u8 unk_1B;
    u8 unk_1C;
    u8 unk_1D;
    u8 unk_1E;
    u8 unk_1F;
    u8 pad_20[0x18];
} RankEntry; // 0x38

typedef struct {
    RankEntry *entries;  // 0x0
    u8 pad_4[0x44];
} RankState;

// Retail lays these out one after another in ranking.c's .bss and addresses
// them off one section base register.
RankState lbl_1_bss_8EF20;
RankEntry lbl_1_bss_8EF68[10];
u8 fzgx_obj_gap_8F198[0x248];
u32 lbl_1_bss_8F3E0;
u32 lbl_1_bss_8F3E4;
char lbl_1_bss_8F3E8[0x11];

typedef struct {
    u32 flags;       // 0x0
    u8 pad_4[0x1440];
    u32 id;          // 0x1444
    u8 pad_1448[0x14];
    u16 unk_145C;
    u8 unk_145E;
    u8 unk_145F;
    u8 unk_1460;
    u8 unk_1461;
    u8 unk_1462;
    u8 unk_1463;
    u8 pad_1464[0x5C];
} RankQuery;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") void fzgx_primer(void) {
    fn_1_3EF14(&lbl_1_bss_8EF20);
    fn_1_3EF14(lbl_1_bss_8EF68);
    fn_1_3EF14(fzgx_obj_gap_8F198);
    fn_1_3EF14(&lbl_1_bss_8F3E0);
    fn_1_3EF14(&lbl_1_bss_8F3E4);
    fn_1_3EF14(lbl_1_bss_8F3E8);
}

void fn_1_155FB4(const char *name) {
    RankEntry *entries;
    RankEntry *e;
    RankQuery q;
    RankQuery *qp = &q;
    s32 i;

    strncpy(lbl_1_bss_8F3E8, name, 0x10);
    lbl_1_bss_8F3E8[0x10] = 0;
    fn_1_3EF14(qp);
    if (qp->flags & 0x1000) {
        entries = lbl_1_bss_8EF20.entries;
        for (i = 9; i >= 0; i--) {
            e = &entries[i];
            if (qp->id == e->id && qp->unk_145C == e->unk_18 && qp->unk_145E == e->unk_1A &&
                qp->unk_145F == e->unk_1B && qp->unk_1460 == e->unk_1C && qp->unk_1461 == e->unk_1D &&
                qp->unk_1462 == e->unk_1E && qp->unk_1463 == e->unk_1F) {
                strncpy(entries[i].name, name, 0x10);
                break;
            }
        }
        for (i = 9; i >= 0; i--) {
            e = &lbl_1_bss_8EF68[i];
            if (qp->id == e->id && qp->unk_145C == e->unk_18 && qp->unk_145E == e->unk_1A &&
                qp->unk_145F == e->unk_1B && qp->unk_1460 == e->unk_1C && qp->unk_1461 == e->unk_1D &&
                qp->unk_1462 == e->unk_1E && qp->unk_1463 == e->unk_1F) {
                strncpy(lbl_1_bss_8EF68[i].name, name, 0x10);
                break;
            }
        }
    }
}
/* fzgx:end fn_1_155FB4 */

/* fzgx:begin fn_1_156198 */
u32 *fn_1_156198(u32 arg0) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v4;
    u32 v5;
    u32 v6;
    struct { u32 a[14]; } loc_78;
    struct { u32 a[14]; } loc_40;
    struct { u32 a[14]; } loc_8;
    /* frame */
    u32 t0;
    t0 = fn_1_156218(arg0, (void *)&loc_78, (void *)&loc_40, (void *)&loc_8);
    v0 = t0;
    if ((s32)t0 == 0) {
        v0 = 0;
    } else {
        v1 = loc_78.a[2];
        v2 = loc_78.a[3];
        v3 = loc_78.a[4];
        v4 = loc_78.a[5];
        v5 = loc_78.a[6];
        v6 = loc_78.a[7];
        lbl_1_bss_8F3FC[0] = loc_78.a[0];
        lbl_1_bss_8F3FC[1] = loc_78.a[1];
        lbl_1_bss_8F3FC[2] = v1;
        lbl_1_bss_8F3FC[3] = v2;
        lbl_1_bss_8F3FC[4] = v3;
        lbl_1_bss_8F3FC[5] = v4;
        lbl_1_bss_8F3FC[6] = v5;
        lbl_1_bss_8F3FC[7] = v6;
        v0 = (u32)&lbl_1_bss_8F3FC;
    }
    return (u32 *)v0;
}
/* fzgx:end fn_1_156198 */

/* fzgx:begin fn_1_1563E8 */
u16 fn_1_1563E8(u8 *data, s32 len) {
    u16 table[256];
    u32 i;
    u32 j;
    u16 crc;

    for (i = 0; i <= 0xff; i++) {
        crc = i;
        for (j = 0; j < 8; j++) {
            crc = (crc & 1) ? ((crc >> 1) ^ 0x8408) : (crc >> 1);
        }
        table[i] = crc;
    }

    crc = 0xFFFF;
    while (--len >= 0) {
        crc = (crc >> 8) ^ table[(crc & 0xff) ^ *data++];
    }

    return (crc ^ 0xFFFF) & 0xFFFF;
}
/* fzgx:end fn_1_1563E8 */

/* fzgx:begin fn_1_1564D0 */
void fn_1_1564D0(void) {
    fn_1_451C();
    fn_1_A1340();
    if (lbl_1_bss_962 != 0x7d) {
        lbl_1_bss_96A = 0x7d;
    }
}
/* fzgx:end fn_1_1564D0 */

/* fzgx:begin fn_1_156510 */
void fn_1_156510(void) {
    fn_1_A1360();
}
/* fzgx:end fn_1_156510 */

/* fzgx:begin fn_1_156530 */
// fn_1_156530: empty in retail (single blr).
void fn_1_156530(void) {
}
/* fzgx:end fn_1_156530 */

/* fzgx:begin fn_1_156534 */
void fn_1_156534(void) {
    fn_1_A1364();
}
/* fzgx:end fn_1_156534 */

/* fzgx:begin fn_1_156554 */
// fn_1_156554: empty in retail (single blr).
void fn_1_156554(void) {
}
/* fzgx:end fn_1_156554 */

/* fzgx:begin fn_1_156558 */
// fn_1_156558: empty in retail (single blr).
void fn_1_156558(void) {
}
/* fzgx:end fn_1_156558 */

/* fzgx:begin fn_1_15655C */
// fn_1_15655C: empty in retail (single blr).
void fn_1_15655C(void) {
}
/* fzgx:end fn_1_15655C */

/* fzgx:begin fn_1_156560 */
// fn_1_156560: empty in retail (single blr).
void fn_1_156560(void) {
}
/* fzgx:end fn_1_156560 */

/* fzgx:begin fn_1_156564 */
// fn_1_156564: empty in retail (single blr).
void fn_1_156564(void) {
}
/* fzgx:end fn_1_156564 */

/* fzgx:begin fn_1_156568 */
// fn_1_156568: empty in retail (single blr).
void fn_1_156568(void) {
}
/* fzgx:end fn_1_156568 */

/* fzgx:begin fn_1_15656C */
void fn_1_15656C(void) {
    lbl_1_bss_8F420[0] = 0;
}
/* fzgx:end fn_1_15656C */

/* fzgx:begin fn_1_15657C */
// fn_1_15657C: empty in retail (single blr).
void fn_1_15657C(void) {
}
/* fzgx:end fn_1_15657C */

/* fzgx:begin fn_1_156580 */
// fn_1_156580: empty in retail (single blr).
void fn_1_156580(void) {
}
/* fzgx:end fn_1_156580 */

/* fzgx:begin fn_1_156584 */
// fn_1_156584: empty in retail (single blr).
void fn_1_156584(void) {
}
/* fzgx:end fn_1_156584 */

/* fzgx:begin fn_1_156588 */
// fn_1_156588: empty in retail (single blr).
void fn_1_156588(void) {
}
/* fzgx:end fn_1_156588 */

/* fzgx:begin fn_1_15658C */
// fn_1_15658C: empty in retail (single blr).
void fn_1_15658C(void) {
}
/* fzgx:end fn_1_15658C */

/* fzgx:begin fn_1_156590 */
// fn_1_156590: empty in retail (single blr).
void fn_1_156590(void) {
}
/* fzgx:end fn_1_156590 */

/* fzgx:begin fn_1_156594 */
// fn_1_156594: empty in retail (single blr).
void fn_1_156594(void) {
}
/* fzgx:end fn_1_156594 */

/* fzgx:begin fn_1_156598 */
// fn_1_156598: empty in retail (single blr).
void fn_1_156598(void) {
}
/* fzgx:end fn_1_156598 */

/* fzgx:begin fn_1_15659C */
typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
    u32 unk_2C;
    u8 unk_30;
    u8 pad_31[3];
    f32 unk_34;
    u8 pad_38[0x1c];
    u32 unk_54;
    u32 unk_58;
    u32 unk_5C;
    u32 unk_60;
    u32 unk_64;
    u32 unk_68;
    u32 unk_6C;
    u32 unk_70;
    u32 unk_74;
    u32 unk_78;
    u32 unk_7C;
    u8 unk_80;
    u8 pad_81[3];
    f32 unk_84;
    u8 pad_88[0x18];
} fn_1_15659C_RankingEntry;


// Clears both ranking entries to their default sentinel values.
void fn_1_15659C(void) {
    fn_1_15659C_RankingEntry *obj;
    f32 value;
    int i;

    fn_80008BEC(&lbl_1_bss_8F428, 0, 0x140);
    obj = (fn_1_15659C_RankingEntry *)&lbl_1_bss_8F428;
    value = lbl_1_rodata_D8C8[0];
    for (i = 0; i < 2; i++) {
        obj->unk_4 = -1;
        obj->unk_C = -1;
        obj->unk_10 = -1;
        obj->unk_14 = -1;
        obj->unk_1C = -1;
        obj->unk_20 = -1;
        obj->unk_18 = -1;
        obj->unk_8 = -1;
        obj->unk_24 = -1;
        obj->unk_28 = -1;
        obj->unk_2C = -1;
        obj->unk_34 = value;
        obj->unk_30 = 0;
        obj->unk_54 = -1;
        obj->unk_5C = -1;
        obj->unk_60 = -1;
        obj->unk_64 = -1;
        obj->unk_6C = -1;
        obj->unk_70 = -1;
        obj->unk_68 = -1;
        obj->unk_58 = -1;
        obj->unk_74 = -1;
        obj->unk_78 = -1;
        obj->unk_7C = -1;
        obj->unk_84 = value;
        obj->unk_80 = 0;
        obj++;
    }
}
/* fzgx:end fn_1_15659C */

/* fzgx:begin fn_1_15665C */
typedef Obj_1_bss_8F428 RankingEntry;

// Initializes one ranking entry and registers it with the ranking system.
void fn_1_15665C(void *owner, s32 index) {
    RankingEntry *entry;

    entry = (RankingEntry *)((u8 *)&lbl_1_bss_8F428 + index * 0x50);
    fn_80008BEC(entry, 0, 0x50);
    entry->unk_0 = 0;
    entry->unk_4 = (u32)owner;
    entry->unk_8 = -1;
    entry->unk_C = -1;
    entry->unk_10 = -1;
    entry->unk_14 = -1;
    entry->unk_1C = -1;
    entry->unk_20 = -1;
    entry->unk_18 = -1;
    entry->unk_24 = -1;
    entry->unk_28 = -1;
    entry->unk_2C = -1;
    entry->unk_34 = lbl_1_rodata_D8C8[0];
    fn_1_1568C4( (fn_1_1568C4_RankingState *)(void *)(entry));
}
/* fzgx:end fn_1_15665C */

/* fzgx:begin fn_1_1566F8 */
// Updates the indexed ranking entry's value through the shared ranking helper.
void fn_1_1566F8(s32 index, void *arg) {
    fn_80008BA8( (u32)(void *)(&lbl_1_bss_8F428.unk_34 + index * 0x14), (u32)(void *)(arg), 0x1c);
}
/* fzgx:end fn_1_1566F8 */

/* fzgx:begin fn_1_156730 */
// Clears the indexed ranking entry's status and score markers.
void fn_1_156730(s32 index) {
    u32 *entry = &lbl_1_bss_8F428.unk_0 + index * 0x14;

    entry[0] = 0;
    entry[1] = -1;
}
/* fzgx:end fn_1_156730 */

/* fzgx:begin fn_1_156754 */
// Processes the indexed ranking entry unless its status marks it as unused.
void fn_1_156754(s32 index) {
    u32 *entry = &lbl_1_bss_8F428.unk_0 + index * 0x14;

    if (entry[1] + 0x10000 != 0xffff) {
        fn_1_1569E8(entry);
        fn_1_1568C4( (fn_1_1568C4_RankingState *)(void *)(entry));
    }
}
/* fzgx:end fn_1_156754 */

/* fzgx:begin fn_1_1567A8 */
void fn_1_1567A8(s32 index) {
    Entry *entry;
    u32 value;
    f32 field_value;

    entry = &(*((Entry *)&lbl_1_bss_8F428)) + index;
    value = entry->unk_4;
    if (entry->unk_4 + 0x10000 != 0xffff) {
        field_value = entry->unk_34;
        if (lbl_1_rodata_D8C8[0] == field_value) {
            if (entry->unk_4 + 0x10000 == 0xffff) {
                return;
            } else {
                fn_1_1569E8( (void *)(Entry *)(entry));
                fn_1_1568C4( (fn_1_1568C4_RankingState *)(Entry *)(entry));
                return;
            }
        } else if (entry->unk_4c & 0x80) {
            fn_1_156B18( (fn_1_156B18_State *)(Entry *)(entry));
            fn_1_1568C4( (fn_1_1568C4_RankingState *)(Entry *)(entry));
        } else {
            fn_1_1569A0( (fn_1_1569A0_State *)(Entry *)(entry));
            fn_1_156C08(entry);
            fn_1_156D9C(entry);
            fn_1_157070( (fn_1_157070_RankingState *)(Entry *)(entry));
            fn_1_156F54(entry);
            fn_1_157200( (fn_1_157200_RankingState *)(Entry *)(entry));
            fn_1_157358( (fn_1_157358_RankingState *)(Entry *)(entry));
        }
        fn_1_1576B4( (Obj_fn_1_1576B4 *)(Entry *)(entry));
        fn_1_157598( (fn_1_157598_RankingState *)(Entry *)(entry));
    }
}
/* fzgx:end fn_1_1567A8 */

/* fzgx:begin fn_1_156884 */
// Refreshes an entry when its ranking value is not the invalid sentinel.
void fn_1_156884(s32 index) {
    Obj_1_bss_8F428 *entry;
    u32 value;

    entry = (Obj_1_bss_8F428 *)((u8 *)&lbl_1_bss_8F428 + index * 0x50);
    value = entry->unk_4;
    if (value + 0x10000 != 0xffff) {
        fn_1_1574E0(entry, value);
    }
}
/* fzgx:end fn_1_156884 */

/* fzgx:begin fn_1_1568C4 */
#pragma opt_propagation off
void fn_1_1568C4(fn_1_1568C4_RankingState *state) {
    u32 value;
    s32 success = 0;
    fn_1_1568C4_RankingConfig config;
    u32 key;

    key = 7;
    config.field8 = key;
    config.fieldC = -1;
    config.field10 = success;
    config.field14 = success;
    config.field15 = success;
    config.field17 = 0x55;
    config.field16 = 0x55;
    config.field1A = 0x55;
    config.field18 = 0x55;

    value = state->value;
    key = state->key;
    if (((0x10000) + (key)) == 0xffff) {
        if (fn_8006B55C( (void *)(u32)(value), &state->key, (void *)(fn_1_1568C4_RankingConfig *)(&config)) >= 0) {
            success = 1;
        }
    } else {
        if (fn_8006B628(key, (u32)(fn_1_1568C4_RankingConfig *)(&config)) >= 0) {
            success = 1;
        }
    }

    if (success != 0 && (state->flags & 1) == 0 &&
        fn_8006B6F8(state->key) >= 0) {
        state->flags |= 1;
    }
}
#pragma opt_propagation reset
/* fzgx:end fn_1_1568C4 */

/* fzgx:begin fn_1_1569A0 */
void fn_1_1569A0(fn_1_1569A0_State *state) {
    if (state->flags & 1) {
        fn_8006B7B4( (u32)(void *)(state->data));
        state->flags &= ~1;
    }
}
/* fzgx:end fn_1_1569A0 */

/* fzgx:begin fn_1_1569E8 */
typedef struct {
    u32 flags;
    u8 _pad04[8];
    void *data0;
    void *data1;
    void *data2;
    s32 value;
    void *data3;
    void *data4;
    u8 _pad24[4];
    void *data5;
    void *data6;
} fn_1_1569E8_State;

/* Releases pending ranking resources and resets their status flags. */
void fn_1_1569E8(void *entry) {
    fn_1_1569E8_State *state = (fn_1_1569E8_State *)entry;

    if (state->flags & 4) {
        fn_8006B7B4( (u32)(void *)(state->data1));
        state->flags &= ~4;
    }
    if (state->flags & 2) {
        fn_8006B7B4( (u32)(void *)(state->data0));
        state->flags &= ~2;
    }
    if (state->flags & 8) {
        fn_8006B7B4( (u32)(void *)(state->data2));
        state->flags &= ~8;
    }
    if (state->flags & 0x20) {
        fn_8006B7B4( (u32)(void *)(state->data3));
        state->flags &= ~0x20;
    }
    if (state->flags & 0x40) {
        fn_8006B7B4( (u32)(void *)(state->data4));
        state->flags &= ~0x40;
    }
    if ((u32)(state->value + 0x10000) != 0xffff) {
        fn_8006B870();
        state->value = -1;
    }
    state->flags &= ~0x10;
    if (state->flags & 0x80) {
        fn_8006B7B4( (u32)(void *)(state->data5));
        state->flags &= ~0x80;
    }
    if (state->flags & 0x100) {
        fn_8006B7B4( (u32)(void *)(state->data6));
        state->flags &= ~0x100;
    }
}
/* fzgx:end fn_1_1569E8 */

/* fzgx:begin fn_1_156B18 */
void fn_1_156B18(fn_1_156B18_State *state) {
    if (state->flags & 4) {
        fn_8006B7B4( (u32)(void *)(state->data1));
        state->flags &= ~4;
    }
    if (state->flags & 2) {
        fn_8006B7B4( (u32)(void *)(state->data0));
        state->flags &= ~2;
    }
    if (state->flags & 8) {
        fn_8006B7B4( (u32)(void *)(state->data2));
        state->flags &= ~8;
    }
    if (state->flags & 32) {
        fn_8006B7B4( (u32)(void *)(state->data3));
        state->flags &= ~32;
    }
    if (state->flags & 64) {
        fn_8006B7B4( (u32)(void *)(state->data4));
        state->flags &= ~64;
    }
    if ((u32)(state->value + 0x10000) != 0xffff) {
        fn_8006B870();
        state->value = -1;
    }
    state->flags &= ~0x10;
}
/* fzgx:end fn_1_156B18 */

/* fzgx:begin fn_1_157070 noprologue */
#include "types.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = -1.899999976158142f;
    s = 25.0f;
    s = -25.0f;
    s = 30.0f;
    s = 1.5f;
    s = 170.0f;
    s = 0.5f;
    s = 248.0f;
    s = 10.0f;
    s = 60.0f;
    s = 1.0f;
    s = 1000.0f;
    s = 0.10000000149011612f;
    s = 2.0f;
    s = 2.8000001907348633f;
    s = 600.0f;
    s = 140.0f;
}
#pragma section code_type ".text"

extern const struct fn_1_157070_lbl_1_rodata_D8C8_pool {
    f32 unk_0;
    u8 pad_4[0x28];
    f32 unk_2C;
    u8 pad_30[0x8];
    f32 unk_38;
    f32 unk_3C;
    f32 unk_40;
    f32 unk_44;
} lbl_1_rodata_D8C8;

extern s32 fn_8006B55C(void *, u32 *, void *);
extern s32 fn_8006B628(u32, void *);
extern s32 fn_8006B6F8(u32);

typedef struct {
    u32 flags;
    void *owner;
    u8 _pad08[8];
    u32 value;
    u8 _pad14[0x20];
    f32 speed;
    u8 _pad38[0x10];
    f32 impulse;
    u8 state_flags;
} fn_1_157070_RankingState;

typedef struct {
    u8 type;
    u8 _pad01[3];
    u32 duration;
    u32 flags;
    u8 strength;
    u8 _pad0d;
    s16 angle;
    s16 value10;
    s16 value12;
    s16 value14;
    u32 value18;
    u32 value1c;
    u8 value20;
    u8 value21;
} fn_1_157070_RankingConfig;

#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_dead_assignments off
void fn_1_157070(fn_1_157070_RankingState *state) {
    fn_1_157070_RankingConfig config;
    s32 started;
    f32 t;

    if (!(state->state_flags & 4)) {
        return;
    }

    t = (-state->impulse) / state->speed;
    t = (t - (2.0f)) / (2.80000019f);
    if (t > (1.0f)) {
        t = (1.0f);
    } else if (t < (0.0f)) {
        t = (0.0f);
    }

    /* the zero fields share the register of the cleared result flag */
    started = 0;
    config.type = 2;
    config.duration = (s32)((600.0f) * t) + 300;
    config.flags = started;
    config.strength = (s32)((140.0f) * t) + 80;
    config.angle = 90;
    config.value10 = 100;
    config.value12 = started;
    config.value14 = started;
    config.value18 = 5;
    config.value1c = 200;
    config.value20 = started;
    config.value21 = started;

    if (!(state->flags & 4)) {
        u32 value = state->value;
        void *owner = state->owner;

        if (value + 0x10000u == 0xffffu) {
            if (fn_8006B55C(owner, &state->value, &config) >= 0) {
                started = 1;
            }
        } else {
            if (fn_8006B628(value, &config) >= 0) {
                started = 1;
            }
        }

        if (started) {
            if (!(state->flags & 4)) {
                if (fn_8006B6F8(state->value) >= 0) {
                    state->flags |= 4;
                }
            }
        }
    } else {
        fn_8006B6F8(state->value);
    }
}
#pragma opt_dead_assignments reset

#pragma opt_common_subs reset
/* fzgx:end fn_1_157070 */

/* fzgx:begin fn_1_157200 */
typedef struct {
    u8 kind;
    u8 _pad01[3];
    s32 value0c;
    s32 value10;
    u8 value14;
    u16 value16;
    u16 value18;
    u16 value1a;
    u16 value1c;
    s32 value20;
    s32 value24;
    u8 value28;
    u8 value29;
} RankingRequest;

static inline f32 fn_1_157200_array_read(f32 *array, s32 index) { return array[index]; }
#pragma opt_dead_assignments off
void fn_1_157200(fn_1_157200_RankingState *state) {
    if (state->status & 0x10) {
        s32 success = 0;
        RankingRequest request;

        request.kind = 5;
        request.value0c = 330;
        request.value10 = 0;
        request.value14 = 240;
        if (state->value > lbl_1_rodata_D910) {
            request.value16 = 90;
        } else if (state->value < fn_1_157200_array_read(lbl_1_rodata_D914, 0)) {
            request.value16 = 270;
        } else {
            request.value16 = success;
        }

        success = 0;
        request.value18 = 40;
        request.value1a = success;
        request.value1c = success;
        request.value20 = 2;
        request.value24 = 10;
        request.value28 = success;
        request.value29 = success;

        {
            u32 entry;
            void *arg04;
            if (!(state->flags & 0x20)) {
            entry = state->entry;
            arg04 = state->arg04;
            if ((entry + 0x10000) == 0xffff) {
                if (fn_8006B55C(arg04, &state->entry, &request) >= 0) {
                    success = 1;
                }
            } else if (fn_8006B628(entry, (u32)(void *)(&request)) >= 0) {
                success = 1;
            }
            if (success && !(state->flags & 0x20) &&
                fn_8006B6F8(state->entry) >= 0) {
                state->flags |= 0x20;
            }
        } else {
            fn_8006B6F8(state->entry);
        }
        }
    }
}
#pragma opt_dead_assignments reset
/* fzgx:end fn_1_157200 */

/* fzgx:begin fn_1_157358 */
typedef struct {
    u8 type;
    u8 _pad01[3];
    s32 value04;
    s32 value08;
    u8 value0c;
    u8 _pad0d;
    s16 width;
    s16 height;
    s16 x;
    s16 y;
    s32 value18;
    s32 value1c;
    u8 value20;
    u8 value21;
} Packet;

#pragma opt_propagation off
#pragma opt_common_subs off
void fn_1_157358(fn_1_157358_RankingState *state) {
    f32 *table = lbl_1_rodata_D8C8;
    f32 value;
    Packet packet;
    s32 success;
    void *data;
    void *node;

    if (state->enabled4c & 0x20) {
        value = state->value40 / table[20];
        if (value > table[11]) {
            value = table[11];
        }
        value *= table[21];

        if (state->flags & 0x40) {
            u8 converted = (u8)(s32)value;
            if (converted == state->value30) {
                return;
            }
        }
        state->value30 = (u8)(s32)value;
    } else {
        if (!(state->flags & 0x40)) {
            return;
        }
        fn_8006B7B4( (u32)(void *)(state->data));
        state->flags &= ~0x40;
        return;
    }

    success = 0;
    packet.type = 2;
    packet.value04 = -1;
    packet.value08 = success;
    packet.value0c = state->value30;
    packet.width = 0x5a;
    packet.height = 0x28;
    packet.x = success;
    packet.y = success;
    packet.value18 = success;
    packet.value1c = success;
    packet.value20 = success;
    packet.value21 = success;

    data = state->data;
    node = state->field04;
    if (data == (void *)-1) {
        if (fn_8006B55C(node, (u32 *)(void *)(&state->data), &packet) >= 0) {
            success = 1;
        }
    } else {
        if (fn_8006B628( (u32)(void *)(data), (u32)(void *)(&packet)) >= 0) {
            success = 1;
        }
    }
    if (success && !(state->flags & 0x40)) {
        if (fn_8006B6F8( (u32)(void *)(state->data)) >= 0) {
            state->flags |= 0x40;
        }
    }
}
#pragma opt_common_subs reset

#pragma opt_propagation reset
/* fzgx:end fn_1_157358 */

/* fzgx:begin fn_1_1574E0 */
typedef struct {
    u8 type;
    u8 _pad01[3];
    u32 duration;
    u32 flags;
    u8 strength;
    u8 _pad0d;
    s16 angle;
    s16 value10;
    s16 value12;
    s16 value14;
    u32 value18;
    u32 value1c;
    u8 value20;
    u8 value21;
} fn_1_1574E0_RankingConfig;

void fn_1_1574E0(fn_1_1574E0_RankingState *state) {
    u32 value = state->value;

    if (value + 0x10000u == 0xffffu) {
        fn_1_1574E0_RankingConfig config;
        void *owner;

        config.type = 2;
        config.duration = 300;
        config.flags = 0;
        config.strength = 100;
        config.angle = 90;
        config.value10 = 15;
        config.value12 = 0;
        config.value14 = 0;
        config.value18 = 0;
        config.value1c = 0;
        config.value20 = 0;
        config.value21 = 0;

        owner = state->owner;
        if (value + 0x10000u == 0xffffu) {
            fn_8006B55C(owner, (u32 *)(void *)(&state->value), &config);
        } else {
            fn_8006B628(value, (u32)(void *)(&config));
        }
    } else {
        fn_8006B7B4(value);
    }

    fn_8006B6F8(state->value);
}
/* fzgx:end fn_1_1574E0 */

/* fzgx:begin fn_1_157598 */
typedef struct {
    u8 type;
    u8 _pad01[3];
    u32 duration;
    u32 flags;
    u8 strength;
    u8 _pad0d;
    s16 angle;
    s16 value10;
    s16 value12;
    s16 value14;
    u32 value18;
    u32 value1c;
    u8 value20;
    u8 value21;
} fn_1_157598_RankingConfig;

#pragma opt_dead_assignments off
void fn_1_157598(fn_1_157598_RankingState *state) {
    s32 success;
    u32 value;
    void *owner;
    fn_1_157598_RankingConfig config;
    success = 0;

    if (!(state->state & 0x40)) {
        return;
    }

    success = 0;
    config.type = 4;
    config.duration = 700;
    config.flags = success;
    config.strength = 250;
    config.angle = 90;
    config.value10 = 100;
    config.value12 = success;
    config.value14 = success;
    config.value18 = 20;
    config.value1c = 200;
    config.value20 = success;
    config.value21 = success;

    if (!(((0x80) & (state->flags)))) {
        value = state->value;
        owner = state->owner;

        if (value + 0x10000u == 0xffffu) {
            if (fn_8006B55C(owner, (u32 *)(void *)(&state->value), &config) >= 0) {
                success = 1;
            }
        } else {
            if (fn_8006B628(value, (u32)(void *)(&config)) >= 0) {
                success = 1;
            }
        }

        if (success) {
            if (!(((0x80) & (state->flags)))) {
                if (fn_8006B6F8(state->value) >= 0) {
                    state->flags |= 0x80;
                }
            }
        }
    } else {
        fn_8006B6F8(state->value);
    }
}
#pragma opt_dead_assignments reset
/* fzgx:end fn_1_157598 */

/* fzgx:begin fn_1_1576B4 */
#pragma opt_propagation off
void fn_1_1576B4(Obj_fn_1_1576B4 *obj) {
    Param_fn_1_1576B4 param;
    s32 ok;

    if (!(obj->unk_4c & 2)) {
        return;
    }

    ok = 0;
    param.unk_0 = 4;
    param.unk_4 = 600;
    param.unk_8 = ok;
    param.unk_C = 250;
    param.unk_E = 50;
    param.unk_10 = 150;
    param.unk_12 = ok;
    param.unk_14 = ok;
    param.unk_18 = 20;
    param.unk_1C = 100;
    param.unk_20 = ok;
    param.unk_21 = ok;

    if (!(obj->flags & 0x100)) {
        u32 id = obj->unk_2c;
        u32 handle = obj->unk_4;

        if (id == 0xFFFFFFFF) {
            if (fn_8006B55C( (void *)(u32)(handle), &obj->unk_2c, (void *)(Param_fn_1_1576B4 *)(&param)) >= 0) {
                ok = 1;
            }
        } else {
            if (fn_8006B628(id, (u32)(Param_fn_1_1576B4 *)(&param)) >= 0) {
                ok = 1;
            }
        }

        if (ok && !(obj->flags & 0x100)) {
            if (fn_8006B6F8(obj->unk_2c) >= 0) {
                obj->flags |= 0x100;
            }
        }
    } else {
        fn_8006B6F8(obj->unk_2c);
    }
}
/* fzgx:end fn_1_1576B4 */

/* fzgx:begin fn_1_1577D0 noprologue */
#include "types.h"

extern f32 lbl_1_rodata_D920;
extern struct fn_1_1577D0_lbl_1_bss_8F568 lbl_1_bss_8F568;
extern u32 lbl_1_data_4C788;

struct fn_1_1577D0_lbl_1_bss_8F568 {
    u8 unk_0;
    u8 pad_1[0x3];
    f32 unk_4;
    f32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
};

f32 fn_1_1577D0(u32 arg0, u32 arg1, f32 arg2) {
    lbl_1_bss_8F568.unk_0 = arg0;
    lbl_1_bss_8F568.unk_4 = lbl_1_rodata_D920;
    lbl_1_bss_8F568.unk_8 = arg2;
    lbl_1_bss_8F568.unk_C = *(u32 *)((u8 *)&lbl_1_data_4C788 + ((s8)arg1 << 2));
    lbl_1_bss_8F568.unk_10 = 1;
    lbl_1_bss_8F568.unk_14 = 0;
    lbl_1_bss_8F568.unk_18 = 600;
    return arg2;
}
/* fzgx:end fn_1_1577D0 */

/* fzgx:begin fn_1_157820 noprologue */
#include "types.h"

typedef struct {
    u8 pad_0[0x4];
    f32 unk_4;
    f32 unk_8;
    u8 pad_C[0x4];
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
} Obj_1_bss_8F568;

typedef struct {
    u8 pad_0[0x9e];
    u8 unk_9e;
} Obj_1_bss_8B3A0;

typedef struct {
    u8 pad_0[0x8];
    u16 unk_8;
    u8 pad_A[0xa];
} Obj_1_bss_9F8;

extern Obj_1_bss_8F568 lbl_1_bss_8F568;
extern Obj_1_bss_8B3A0 lbl_1_bss_8B3A0;
extern Obj_1_bss_9F8 lbl_1_bss_9F8[];
extern s32 fn_1_157920(void);
extern void fn_1_4060(void);

void fn_1_157820(void) {
    Obj_1_bss_8F568 *p;
    u8 index;

    p = &lbl_1_bss_8F568;

    if (p->unk_14 == 0) {
        p->unk_4 += p->unk_8;
    } else {
        if (p->unk_18 > 0) {
            p->unk_18 -= 1;
        }

        index = lbl_1_bss_8B3A0.unk_9e;
        if (((lbl_1_bss_9F8[index].unk_8 >> 8) & 1) ||
            p->unk_18 == 0) {
            p->unk_10 = 0;
        }
    }

    if (fn_1_157920() == 0) {
        fn_1_4060();
    }
}
/* fzgx:end fn_1_157820 */

/* fzgx:begin fn_1_1578C4 */
void fn_1_1578C4(void) {
    s8 v0;
    u32 t2;
    v0 = (s8)(*((u8 *)&lbl_1_bss_8F568));
    switch (v0) {
    case 0:
    fn_1_157950();
    break;
    case 1:
    fn_1_157FC8();
    }
    t2 = fn_1_157920();
    if ((s32)t2 == 0) {
    fn_1_4060();
    }
}
/* fzgx:end fn_1_1578C4 */

/* fzgx:begin fn_1_157920 */
// Return the current ranking value.
u32 fn_1_157920(void) {
    return lbl_1_bss_8F578;
}
/* fzgx:end fn_1_157920 */

/* fzgx:begin fn_1_157930 */
u32 fn_1_157930(void) {
    return lbl_1_bss_8F57C[0];
}
/* fzgx:end fn_1_157930 */

/* fzgx:begin fn_1_157940 */
void fn_1_157940(void) {
    lbl_1_bss_8F578 = 0;
}
/* fzgx:end fn_1_157940 */

/* fzgx:begin fn_1_157950 */
#include "font.h"

struct fn_1_157950_Copy88 { u32 a[22]; };
struct fn_1_157950_lbl_1_rodata_D920 {
    f32 unk_0;
    f32 unk_4;
    u8 pad_8[0x28];
    f64 unk_30;
};
extern struct fn_1_157950_Copy88 lbl_1_rodata_26F8;
extern void fn_1_49410(void);
extern void fn_1_495B0(u32);
enum { FONT_DRAW_FLAGS = 3u << 30 };
extern void fn_1_5233C(void);
extern void fn_1_49738(void (*)(void));
extern void fn_1_49748(f32);
extern void fn_1_495C8(int);
extern void fn_1_49590(f32);
extern void fn_1_4955C(f32,f32);
extern void fn_1_49514(u32*);
extern void fn_1_494DC(s16);
extern void fn_1_4965C(u8);
extern void fn_1_51678(FontDrawPacket*,u32,s16,s16,s16,s16);
extern int fn_1_4F734(FontDrawPacket*);
extern void fn_1_496FC(f32,f32);
extern void fn_1_495A0(f32);
extern void fn_1_4CF3C(const char*,f32,...);
extern void fn_1_4AE0C(const char*,...);

void fn_1_157950(void) {
    Obj_1_bss_8F568 *p_lbl_1_bss_8F568;
    f32 v0;
    Obj_1_bss_8F568_AtC *v1;
    f32 v3;
    f32 v2;
    Obj_1_bss_8F568_AtC *v4;
    f32 pos;
    f32 alpha;
    p_lbl_1_bss_8F568 = (Obj_1_bss_8F568*)&lbl_1_bss_8F568;
    v0 = p_lbl_1_bss_8F568->unk_4;
    v1 = p_lbl_1_bss_8F568->unk_C;
    v4 = v1;
    v3 = 0.0f;
    v2 = (f32)(v0 - (f32)(448.0f / p_lbl_1_bss_8F568->unk_8));
    while (*(s16 *)v4 != -2) {
        v3 += (f32)*(s16*)v4 / p_lbl_1_bss_8F568->unk_8;
        if (v3 >= v2 && v3 <= p_lbl_1_bss_8F568->unk_4) {
            pos = p_lbl_1_bss_8F568->unk_8 * (v3-v2);
            alpha = 1.0f;
            fn_1_49410();
            if (pos < v4->unk_E) alpha = pos / v4->unk_E;
            else if (pos > 448.0f-v4->unk_E) alpha = (448.0f-pos) / v4->unk_E;
            if (*(s32*)((u8*)p_lbl_1_bss_8F568+0x18) < 30)
                alpha = (f32)*(s32*)((u8*)p_lbl_1_bss_8F568+0x18) / 30.0f;
            switch (v4->unk_10) {
            case 0: {
                u32 color;
                fn_1_495B0(FONT_DRAW_FLAGS);
                fn_1_49738(fn_1_5233C);
                fn_1_49748(5.0f);
                fn_1_495C8((s8)v4->unk_8);
                fn_1_49590(0.5f);
                fn_1_4955C((f32)v4->unk_C/24.0f,(f32)v4->unk_E/24.0f);
                color = v4->unk_14; fn_1_49514(&color);
                break;
            }
            case 1: {
                u32 color;
                fn_1_494DC(5);
                fn_1_495B0(FONT_DRAW_FLAGS);
                fn_1_495C8((s8)v4->unk_8);
                fn_1_49590(0.5f);
                fn_1_4955C((f32)v4->unk_C/18.0f,(f32)v4->unk_E/18.0f);
                color = v4->unk_14; fn_1_49514(&color);
                break;
            }
            case 2: {
                u32 color;
                fn_1_495B0(FONT_DRAW_FLAGS);
                fn_1_49738(fn_1_5233C);
                fn_1_49748(3.0f);
                fn_1_495C8((s8)v4->unk_8);
                fn_1_49590(0.5f);
                fn_1_4955C((f32)v4->unk_C/24.0f,(f32)v4->unk_E/24.0f);
                color = v4->unk_14; fn_1_49514(&color);
                break;
            }
            case 6: {
                u32 color;
                fn_1_495B0(FONT_DRAW_FLAGS);
                fn_1_4965C(2);
                fn_1_49738(fn_1_5233C);
                fn_1_49748(1.0f);
                fn_1_495C8((s8)v4->unk_8);
                fn_1_49590(0.5f);
                fn_1_4955C((f32)v4->unk_C/24.0f,(f32)v4->unk_E/24.0f);
                color = v4->unk_14; fn_1_49514(&color);
                break;
            }
            case 3: {
                struct fn_1_157950_Copy88 packet = lbl_1_rodata_26F8;
                *(f32*)&packet.a[1] = v4->unk_4;
                *(f32*)&packet.a[2] = pos;
                *(f32*)&packet.a[3] = 0.1f;
                packet.a[12] = 5;
                packet.a[0] = 0x100;
                *(f32*)&packet.a[11] = alpha;
                fn_1_51678((FontDrawPacket*)&packet,0x100,0,0,120,16);
                fn_1_4F734((FontDrawPacket*)&packet);
                break;
            }
            case 4: {
                struct fn_1_157950_Copy88 packet = lbl_1_rodata_26F8;
                *(f32*)&packet.a[1] = v4->unk_4;
                *(f32*)&packet.a[2] = pos;
                *(f32*)&packet.a[3] = 0.1f;
                packet.a[12] = 5;
                packet.a[0] = 0x100;
                *(f32*)&packet.a[11] = alpha;
                fn_1_51678((FontDrawPacket*)&packet,0x100,0,18,248,16);
                fn_1_4F734((FontDrawPacket*)&packet);
                break;
            }
            case 5: {
                struct fn_1_157950_Copy88 packet = lbl_1_rodata_26F8;
                *(f32*)&packet.a[1] = v4->unk_4;
                *(f32*)&packet.a[2] = pos;
                *(f32*)&packet.a[3] = 0.1f;
                packet.a[12] = 5;
                packet.a[0] = 0x8700;
                *(f32*)&packet.a[11] = alpha;
                fn_1_4F734((FontDrawPacket*)&packet);
                break;
            }
            }
            fn_1_496FC((f32)v4->unk_4,pos);
            fn_1_495A0(alpha);
            if ((s32)v4->unk_10 != 6) fn_1_4CF3C((const char*)v4->unk_18,284.0f-v4->unk_4);
            else fn_1_4AE0C((const char*)v4->unk_18);
        }
        v4 = (Obj_1_bss_8F568_AtC*)((u8*)v4+0x1c);
    }
    if ((f32)v4->unk_2 < p_lbl_1_bss_8F568->unk_4)
        *(s32*)((u8*)p_lbl_1_bss_8F568+0x14) = 1;
}
/* fzgx:end fn_1_157950 */

/* fzgx:begin fn_1_1586A8 */
// fn_1_1586A8: empty in retail (single blr).
void fn_1_1586A8(void) {
}
/* fzgx:end fn_1_1586A8 */

/* fzgx:begin fn_1_158980 */
// fn_1_158980: empty in retail (single blr).
void fn_1_158980(void) {
}
/* fzgx:end fn_1_158980 */

/* fzgx:begin fn_1_15903C */
// fn_1_15903C: empty in retail (single blr).
void fn_1_15903C(void) {
}
/* fzgx:end fn_1_15903C */

/* fzgx:begin fn_1_159040 */
void fn_1_159040(void) {
    fn_1_9AD88();
}
/* fzgx:end fn_1_159040 */

/* fzgx:begin fn_1_159060 */
// fn_1_159060: empty in retail (single blr).
void fn_1_159060(void) {
}
/* fzgx:end fn_1_159060 */

/* fzgx:begin fn_1_159064 */
// fn_1_159064: returns a constant.
int fn_1_159064(void) {
    return 0;
}
/* fzgx:end fn_1_159064 */

/* fzgx:begin fn_1_159440 */
typedef struct {
    u8 pad_0[0x30];
    u32 unk_30;
    u32 unk_34;
    u8 pad_38[0x4];
} fn_1_159440_RankingEntry;

// Preserve the current ranking entry before refreshing its state.
void fn_1_159440(int index, int flag) {
    fn_1_159440_RankingEntry *entry;

    entry = &((fn_1_159440_RankingEntry *)&lbl_1_data_4C810)[index];
    entry->unk_34 = entry->unk_30;
    fn_1_1594AC(index, flag);
}
/* fzgx:end fn_1_159440 */

/* fzgx:begin fn_1_159478 */
typedef struct {
    u8 pad[0x34];
    u32 unk_34;
    u8 tail[4];
} Entry159478;

void fn_1_159478(int index, int unused, int value) {
    ((Entry159478 *)&lbl_1_data_4C810)[index].unk_34 = value;
    fn_1_1594AC(index, unused);
}
/* fzgx:end fn_1_159478 */

/* fzgx:begin fn_1_1594AC */
void fn_1_1594AC(int index, int flag) {
    Obj_1_data_4C810 *entry;
    s16 value;
    int offset;

    // Activate the selected ranking entry and publish its referenced indices.
    entry = (Obj_1_data_4C810 *)((u8 *)&lbl_1_data_4C810 + index * 0x3c);
    if (entry->unk_2C >= 0x10) {
        OSReport((const char *)lbl_1_data_4C900);
    }

    if (flag != 0) {
        fn_1_465D0( (s32)((void *)entry->unk_0), 6);
    } else {
        fn_1_465D0( (s32)((void *)entry->unk_0), 5);
    }

    offset = 0;
    for (;;) {
        value = *(s16 *)((u8 *)entry->unk_4 + offset);
        if (value == -1) {
            break;
        }
        ((int *)lbl_1_bss_8F588)[value] = index;
        offset += 2;
    }

    fn_80008BEC((u8 *)entry + 8, 0, 0x20);
    entry->unk_28 = 1;
    entry->unk_2A = 0;
    entry->unk_38 = flag;
}
/* fzgx:end fn_1_1594AC */

/* fzgx:begin fn_1_159588 */
typedef struct {
    u8 pad_0[8];
    s16 values[16];
    s16 start;
    s16 end;
    u8 limit;
    u8 pad_2d[3];
    u32 unk_30;
    u32 value;
} RankEntryView;

int fn_1_159588(int arg) {
    s16 index;
    s16 count;
    int value;
    Obj_1_data_4C810 *entry;
    RankEntryView *view;
    s32 *table;

    index = (s16)((arg >> 8) & 0xffff);
    if (((s32 *)lbl_1_bss_8F588)[index] != 0) {
        entry = (Obj_1_data_4C810 *)((u8 *)&lbl_1_data_4C810 +
            ((s32 *)lbl_1_bss_8F588)[index] * 0x3c);
        view = (RankEntryView *)entry;
        count = view->start;
        count = view->end - count + 1;
        if (count < 0) {
            count = count + 0x10;
        }

        table = (s32 *)&lbl_1_data_FCD4;
        if (table[index * 10] != 0) {
            fn_1_159804(index, (fn_1_159804_RankingEntry *)(Obj_1_data_4C810 *)(entry));
        } else {
            if (count >= view->limit) {
                fn_1_4811C(view->values[view->start]);
                value = view->start + 1;
                view->start = value > 0xf ? 0 : (value < 0 ? 0xf : value);
            }

            value = view->end + 1;
            view->end = value > 0xf ? 0 : (value < 0 ? 0xf : value);
            view->values[view->end] = index;
            fn_1_48004(view->values[view->end], view->value);
        }
    } else {
        return 0;
    }
    return 1;
}
/* fzgx:end fn_1_159588 */

/* fzgx:begin fn_1_1596DC */
typedef struct {
    u32 unk_0;
    u32 unk_4;
    s16 unk_8[16];
    s16 unk_28;
    s16 unk_2a;
    u8 unk_2c;
    u8 pad_2d[0xb];
    s32 unk_38;
} fn_1_1596DC_RankingEntry;


void fn_1_1596DC(int index) {
    struct { int value; } offset;
    fn_1_1596DC_RankingEntry *entry;
    int i;
    int count;

    entry = &(*(fn_1_1596DC_RankingEntry (*)[4])&lbl_1_data_4C810)[index];
    i = 0;
    while (entry->unk_2a + 1 != entry->unk_28 &&
           (entry->unk_2a != 0xf || entry->unk_28 != 0)) {
        fn_1_4811C(entry->unk_8[entry->unk_28]);
        entry->unk_28 = entry->unk_28 + 1 > 0xf ? 0
                      : (entry->unk_28 + 1 < 0 ? 0xf : entry->unk_28 + 1);
        if (++i > 0x10) {
            break;
        }
    }

    if (entry->unk_38 != 0) {
        offset.value = 0;
        count = 0;
        for (;;) {
            if (*(s16 *)((u8 *)entry->unk_4 + offset.value) == -1) {
                break;
            }
            if ((s8)fn_1_46DC4( (s32)(void *)(*(void **)((*(u8 (*)[])&lbl_1_data_FCD4) +
                                      *(s16 *)((u8 *)entry->unk_4 + offset.value) * 0x28 +
                                      lbl_801A66B4 * 4 + 4))) != 0) {
                (*(int (*)[])&lbl_1_bss_8F588)[*(s16 *)((u8 *)entry->unk_4 + offset.value)] = count;
            }
            offset.value += 2;
        }
    }
}
/* fzgx:end fn_1_1596DC */

/* fzgx:begin fn_1_159804 */
s16 fn_1_159804(s16 value, fn_1_159804_RankingEntry *entry) {
    s16 head;
    s16 next;
    int i;
    int found;

    head = entry->unk_28;
    i = 0;
    found = 0;
    while (entry->unk_2a + 1 != head && (entry->unk_2a != 0xf || head != 0)) {
        next = head + 1 > 0xf ? 0 : (head + 1 < 0 ? 0xf : head + 1);
        if (value == entry->unk_8[head]) {
            found = 1;
        }
        if (found) {
            entry->unk_8[head] = entry->unk_8[next];
        }
        head = next;
        if (++i > 0x10) {
            head = -1;
            break;
        }
    }
    entry->unk_8[entry->unk_2a] = value;
    return head;
}
/* fzgx:end fn_1_159804 */

/* fzgx:begin fn_1_1598C4 */
struct fn_1_1598C4_lbl_1_bss_8F878 {
    u8 pad_0[0x34];
    u32 unk_34;
    u8 pad_38[0x1];
    u8 unk_39;
    u8 unk_3A;
    u8 unk_3B;
    u8 unk_3C;
    u8 unk_3D;
    u8 unk_3E;
};

void fn_1_1598C4(s32 arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, u8 arg6, u32 arg7, u64 arg8, u8 arg10) {
    s32 i;

    fn_80008BA8((u32)(&(*((struct fn_1_1598C4_lbl_1_bss_8F878 *)&lbl_1_bss_8F878))), arg7, 0x10U);

    for (i = 0; i < 0x10; i += 2) {
        if (*(u8 *)((u8 *)(&(*((struct fn_1_1598C4_lbl_1_bss_8F878 *)&lbl_1_bss_8F878))) + i) == 0) {
            s32 j;
            s32 t = i + 1;
            for (j = t; j < 0x10; j++) {
                *(u8 *)((u8 *)(&(*((struct fn_1_1598C4_lbl_1_bss_8F878 *)&lbl_1_bss_8F878))) + j) = 0;
            }
            break;
        }
    }

    (*((struct fn_1_1598C4_lbl_1_bss_8F878 *)&lbl_1_bss_8F878)).pad_38[0] = arg10;
    *(s32 *)((u8 *)(&(*((struct fn_1_1598C4_lbl_1_bss_8F878 *)&lbl_1_bss_8F878))) + 20) = (s32)arg8;
    *(s32 *)((u8 *)(&(*((struct fn_1_1598C4_lbl_1_bss_8F878 *)&lbl_1_bss_8F878))) + 16) = (s32)(arg8 >> 32);
    (*((struct fn_1_1598C4_lbl_1_bss_8F878 *)&lbl_1_bss_8F878)).unk_34 = arg0 & 0x3FFFF;
    (*((struct fn_1_1598C4_lbl_1_bss_8F878 *)&lbl_1_bss_8F878)).unk_39 = arg1;
    (*((struct fn_1_1598C4_lbl_1_bss_8F878 *)&lbl_1_bss_8F878)).unk_3D = arg6;
    (*((struct fn_1_1598C4_lbl_1_bss_8F878 *)&lbl_1_bss_8F878)).unk_3E = (u8)(s32)((*(f32 *)((u8 *)(&lbl_1_rodata_DAE8) + 0)) * (f32)arg5);

    if (arg1 >= 0x29U) {
        if ((s32)arg2 < fn_1_14F01C(0)) {
            (*((struct fn_1_1598C4_lbl_1_bss_8F878 *)&lbl_1_bss_8F878)).unk_3A = arg2;
        } else {
            (*((struct fn_1_1598C4_lbl_1_bss_8F878 *)&lbl_1_bss_8F878)).unk_3A = 0;
        }
        if ((s32)arg3 < fn_1_14F01C(1)) {
            (*((struct fn_1_1598C4_lbl_1_bss_8F878 *)&lbl_1_bss_8F878)).unk_3B = arg3;
        } else {
            (*((struct fn_1_1598C4_lbl_1_bss_8F878 *)&lbl_1_bss_8F878)).unk_3B = 0;
        }
        if ((s32)arg4 < fn_1_14F01C(2)) {
            (*((struct fn_1_1598C4_lbl_1_bss_8F878 *)&lbl_1_bss_8F878)).unk_3C = arg4;
            return;
        }
        (*((struct fn_1_1598C4_lbl_1_bss_8F878 *)&lbl_1_bss_8F878)).unk_3C = 0;
    }
}
/* fzgx:end fn_1_1598C4 */

/* fzgx:begin fn_1_15AC00 */
// Return the address of the ranking state byte at offset 0x3f.
u8 *fn_1_15AC00(void) {
    return &lbl_1_bss_8F878.unk_3F;
}
/* fzgx:end fn_1_15AC00 */

/* fzgx:begin fn_1_15AC10 */
extern u32 fn_1_B7FC8(void);
extern u32 fn_8003D4C0(void);
extern u8 lbl_1_bss_718E0[23016];
extern u32 lbl_801A63C0[];

static inline void set_seed(u32 value) {
    lbl_801A63C0[0] = value;
}
static inline s32 next_random(void) {
    lbl_801A63C0[0] = lbl_801A63C0[0] * 0x676A4B6B + 0x33CB;
    return (lbl_801A63C0[0] >> 16) & 0x7FFF;
}

static inline u64 make_value(void) {
    u32 t0 = fn_1_B7FC8();
    u8 v0 = lbl_1_bss_718E0[0x5523];
    u64 v1 = t0 & 0x3FFFFFFULL;
    v1 += (u64)(v0 & 0x3F) << 26;
    t0 = fn_8003D4C0();
    return (v1 << 32) + t0;
}

u64 fn_1_15AC10(void) {
    u64 v21;
    u64 v18;
    u64 v16;
    u64 v76;
    u64 v78;
    u32 v13;
    u32 v15;
    s32 v67, v69, v71;
    u8 *v82;
    u32 t0;
    u8 v0;
    v21 = make_value();
    v13 = ((u32)(((v21 >> 32) & 3) +
                      ((v21 & 0x2000ULL) >> 11) +
                      ((v21 & 0x100000ULL) >> 17)) & 0xFF) ^ 0xCAE87FB5;
    set_seed(v13);
    v16 = next_random();
    for (v18 = 0; v18 < 64; v18 += 1) {
        if (v18 != 13 && v18 != 20 && (v18 - 32) > 1) {
            u64 v29 = (v21 >> v18) & 1;
            u64 t4;
            v29 += (v16 % (v18 + 11)) & 1;
            t4 = 1ULL << v18;
            v21 &= ~t4;
            if (v29 & 1) {
                v21 |= t4;
            }
        }
    }
    lbl_1_bss_8F878.unk_18 = 0x30 + (v21 / 1ULL) % 10;
    lbl_1_bss_8F878.unk_19 = 0x30 + (v21 / 10ULL) % 10;
    lbl_1_bss_8F878.unk_1A = 0x30 + (v21 / 100ULL) % 10;
    lbl_1_bss_8F878.unk_1B = 0x30 + (v21 / 1000ULL) % 10;
    lbl_1_bss_8F878.unk_1C = 45;
    lbl_1_bss_8F878.unk_1D = 0x30 + (v21 / 10000ULL) % 10;
    lbl_1_bss_8F878.unk_1E = 0x30 + (v21 / 100000ULL) % 10;
    lbl_1_bss_8F878.unk_1F = 0x30 + (v21 / 1000000ULL) % 10;
    lbl_1_bss_8F878.unk_20 = 0x30 + (v21 / 10000000ULL) % 10;
    lbl_1_bss_8F878.unk_21 = 45;
    lbl_1_bss_8F878.unk_22 = 0x30 + (v21 / 100000000ULL) % 10;
    lbl_1_bss_8F878.unk_23 = 0x30 + (v21 / 1000000000ULL) % 10;
    lbl_1_bss_8F878.unk_24 = 0x30 + (v21 / 10000000000ULL) % 10;
    lbl_1_bss_8F878.unk_25 = 0x30 + (v21 / 100000000000ULL) % 10;
    lbl_1_bss_8F878.unk_26 = 45;
    lbl_1_bss_8F878.unk_27 = 0x30 + (v21 / 1000000000000ULL) % 10;
    lbl_1_bss_8F878.unk_28 = 0x30 + (v21 / 10000000000000ULL) % 10;
    lbl_1_bss_8F878.unk_29 = 0x30 + (v21 / 100000000000000ULL) % 10;
    lbl_1_bss_8F878.unk_2A = 0x30 + (v21 / 1000000000000000ULL) % 10;
    lbl_1_bss_8F878.unk_2B = 45;
    lbl_1_bss_8F878.unk_2C = 0x30 + (v21 / 10000000000000000ULL) % 10;
    lbl_1_bss_8F878.unk_2D = 0x30 + (v21 / 100000000000000000ULL) % 10;
    lbl_1_bss_8F878.unk_2E = 0x30 + (v21 / 1000000000000000000ULL) % 10;
    lbl_1_bss_8F878.unk_2F = 0x30 + (v21 / 10000000000000000000ULL) % 10;
    set_seed((u32)(v21 % 1000) ^ 0xCAE87FB5);
    v67 = next_random();
    v69 = next_random();
    v71 = next_random();
    v76 = (u64)v71 * ((u64)v69 * (u64)v67);
    for (v18 = 5; v18 < 24; v18 += 1) {
        v82 = &lbl_1_bss_8F878.unk_18 + v18;
        if (*v82 != 45) {
            *v82 += v76 % 10;
            if (*v82 > 57) {
                *v82 -= 10;
            }
            v76 /= 10;
        }
    }
    lbl_1_bss_8F878.unk_30 = 0;
    return v21;
}
/* fzgx:end fn_1_15AC10 */

/* fzgx:begin fn_1_15B3E8 */
// Return the current ranking state byte.
u8 fn_1_15B3E8(void) {
    return lbl_1_bss_8F878.unk_3A;
}
/* fzgx:end fn_1_15B3E8 */

/* fzgx:begin fn_1_15B3F8 */
// Return the ranking state byte at offset 0x3b.
u8 fn_1_15B3F8(void) {
    return lbl_1_bss_8F878.unk_3B;
}
/* fzgx:end fn_1_15B3F8 */

/* fzgx:begin fn_1_15B408 */
// Returns the current ranking state.
u8 fn_1_15B408(void) {
    return lbl_1_bss_8F878.unk_3C;
}
/* fzgx:end fn_1_15B408 */

/* fzgx:begin fn_1_15B418 */
u8 *fn_1_15B418(void) {
    return &lbl_1_bss_8F878.unk_18;
}
/* fzgx:end fn_1_15B418 */

/* fzgx:begin fn_1_15B428 */
// fn_1_15B428: empty in retail (single blr).
void fn_1_15B428(void) {
}
/* fzgx:end fn_1_15B428 */

/* fzgx:begin fn_1_15B42C */
typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
} Fn_1_15B42C_Chunk;

void fn_1_15B42C(void) {
    Fn_1_15B42C_Chunk *src = (Fn_1_15B42C_Chunk *)lbl_1_rodata_DAF8;
    Obj_1_data_2A7E0_At3C *obj = lbl_1_data_2A7E0.unk_3C;
    Fn_1_15B42C_Chunk *dst = (Fn_1_15B42C_Chunk *)&obj->unk_4;

    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
    dst[4] = src[4];
    obj->unk_5D = 0;
    obj->unk_5E = 0;
    obj->unk_5C = 0;
    fn_1_9A508();
    obj->unk_0 = -1;
}
/* fzgx:end fn_1_15B42C */

/* fzgx:begin fn_1_15B4F8 */
// fn_1_15B4F8: empty in retail (single blr).
void fn_1_15B4F8(void) {
}
/* fzgx:end fn_1_15B4F8 */

/* fzgx:begin fn_1_15B4FC */
void fn_1_15B4FC(void) {
    fn_1_9AD54();
}
/* fzgx:end fn_1_15B4FC */

/* fzgx:begin fn_1_15B51C */
// fn_1_15B51C: empty in retail (single blr).
void fn_1_15B51C(void) {
}
/* fzgx:end fn_1_15B51C */

/* fzgx:begin fn_1_15B520 */
void fn_1_15B520(void) {
    fn_1_9AD88();
}
/* fzgx:end fn_1_15B520 */

/* fzgx:begin fn_1_15B540 */
// fn_1_15B540: empty in retail (single blr).
void fn_1_15B540(void) {
}
/* fzgx:end fn_1_15B540 */

/* fzgx:begin fn_1_15B544 */
typedef struct {
    u32 flags;
    u8 pad_04[0x3c];
} fn_1_15B544_RankingEntry;

// Set the high flag on each ranking entry managed by the singleton.
void fn_1_15B544(void) {
    s16 i;
    fn_1_15B544_RankingEntry *entry;

    i = 0;
    entry = (fn_1_15B544_RankingEntry *)lbl_1_bss_3BE0->unk_54;
    while (i < (s32)lbl_1_bss_3BE0->unk_48) {
        entry->flags |= 0x80000000u;
        i++;
        entry = (fn_1_15B544_RankingEntry *)((u8 *)entry + 0x40);
    }
}
/* fzgx:end fn_1_15B544 */

/* fzgx:begin fn_1_15B588 */
// Clears the high bit of each ranking entry flag.
void fn_1_15B588(void) {
    u8 *entry;
    s16 i;
    Obj_1_data_2A7E0_At3C *obj;

    obj = lbl_1_data_2A7E0.unk_3C;
    entry = (u8 *)obj;
    i = 0;
    while (i < obj->unk_5E) {
        u32 *value = *(u32 **)(entry + 0xc4);

        entry += 4;
        i++;
        *value &= 0x7fffffff;
    }
}
/* fzgx:end fn_1_15B588 */

/* fzgx:begin fn_1_15B5CC */
void fn_1_15B5CC(void) {
    u8 *entry;
    s16 i;
    Obj_1_data_2A7E0_At3C *obj;

    obj = lbl_1_data_2A7E0.unk_3C;
    entry = (u8 *)obj;
    i = 0;
    while (i < obj->unk_5D) {
        u32 *value = *(u32 **)(entry + 0x74);

        entry += 4;
        i++;
        *value &= 0x7fffffff;
    }
}
/* fzgx:end fn_1_15B5CC */

/* fzgx:begin fn_1_15B610 */
void fn_1_15B610(void) {
    u8 *entry;
    s16 i;
    Obj_1_data_2A7E0_At3C *obj;

    obj = lbl_1_data_2A7E0.unk_3C;
    entry = (u8 *)obj;
    i = 0;
    while (i < *((u8 *)obj + 0x5d)) {
        u32 *value = *(u32 **)(entry + 0x74);

        entry += 4;
        i++;
        *value |= 0x80000000u;
    }
}
/* fzgx:end fn_1_15B610 */

/* fzgx:begin fn_1_15B654 */
void fn_1_15B654(void) {
    u8 *entry;
    s16 i;
    Obj_1_data_2A7E0_At3C *obj;

    obj = lbl_1_data_2A7E0.unk_3C;
    entry = (u8 *)obj;
    i = 0;
    while (i < obj->unk_5C) {
        u32 *value = *(u32 **)(entry + 0x60);

        entry += 4;
        i++;
        *value |= 0x80000000u;
    }
}
/* fzgx:end fn_1_15B654 */

/* fzgx:begin fn_1_15B698 */
u32 fn_1_15B698(s32 kind, u32 *value) {
    Obj_1_data_2A7E0_At3C *obj;

    obj = lbl_1_data_2A7E0.unk_3C;
    switch (kind) {
    case 3:
        obj->unk_114 = *value;
        break;
    case 1:
        obj->unk_120 = *value;
        break;
    case 2:
        obj->unk_124 = *value;
        break;
    case 4:
        obj->unk_118 = *value;
        break;
    case 0:
        obj->unk_11C = *value;
        break;
    default:
        break;
    }
    return 1;
}
/* fzgx:end fn_1_15B698 */
