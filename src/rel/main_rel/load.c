#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/load.h"
extern int fn_1_45E98(void *arg0, void **result);
extern s32 fn_8000700C();
extern int fn_80006C2C(int status, void *arg0);
extern char *fn_80083DB0(char *dst, const char *src);
extern u32 fn_1_46EC8(void);
extern u32 fn_1_46ED8(void);
extern u32 lbl_1_bss_3DCE4[17];
extern void *fn_80006DFC(void *arg);
extern void fn_1_D3214(void);
extern void fn_1_3BDC(u32 arg0);
extern void fn_8000659C(void);
extern u32 lbl_1_bss_384C4;
extern u32 fn_1_46A8C(u32 value);
extern u32 lbl_1_bss_3DCD8;
extern u32 lbl_1_bss_3DD28[179];
extern void fn_1_47EE4(s32 index);
extern void fn_1_485C8(u32 arg0);
extern void fn_1_48140(int index);
extern void fn_1_4DDC0(void);
extern void fn_1_4F724(void);
extern u8 lbl_1_bss_3E024[52];
extern char lbl_1_data_1A3AC[5];
extern u32 fn_80006CE4(u32);
extern void *fn_80006DE8(void *);
extern u32 lbl_801A6410;
extern u32 fn_1_4630();
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern char *strcat(char *dest, const char *src);
extern void fn_1_48004(s32 index, s32 image);

/* fzgx:begin fn_1_45730 */
typedef struct {
    u32 flags;
    s32 unk_4;
    u32 unk_8;
    u32 unk_C;
} LoadEntry;

typedef struct {
    u32 unk_0;
    u8 pad_4[0x48];
    LoadEntry entry;
} LoadResult;

int fn_1_45730(void *arg0, LoadResult *result) {
    LoadEntry *entry;
    int status;
    int i;

    status = fn_1_45E98(arg0, (void **)&entry);
    if (status >= 0) {
        result->unk_0 = 1;
        result->entry = *entry;
        return 1;
    }

    if (status < 0) {
        status = fn_8000700C( (s32)(void *)(arg0));
    }
    if (status < 0) {
        return 0;
    }

    entry = (LoadEntry *)&lbl_1_bss_384D8;
    for (i = 0; i < 0x400; i++) {
        if ((entry->flags & 0x40000000) != 0 &&
            (entry->flags & 0x08000000) == 0 &&
            entry->unk_4 == status) {
            result->unk_0 = 1;
            result->entry = *entry;
            return 1;
        }
        entry++;
    }

    result->unk_0 = 0;
    return fn_80006C2C(status, (u8 *)result + 4);
}
/* fzgx:end fn_1_45730 */

/* fzgx:begin fn_1_45850 */
struct fn_1_45850_Arg0 {
    u32 unk_0;
};

u32 fn_1_45850(struct fn_1_45850_Arg0 *arg0) {
    u32 v0;
    u32 t0;

    v0 = (u32)arg0;
    switch ((s32)arg0->unk_0) {
    case 1:
        v0 = 1;
        break;
    case 0:
    default:
        v0 += 4;
        t0 = fn_80006CE4(v0);
        v0 = t0;
        break;
    }
    return v0;
}
/* fzgx:end fn_1_45850 */

/* fzgx:begin fn_1_45890 */
// Clear the load-state flag before starting a new load.
void fn_1_45890(void) {
    lbl_1_bss_384D0 = 0;
}
/* fzgx:end fn_1_45890 */

/* fzgx:begin fn_1_45A58 pool noprologue */
#include "types.h"

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_384C0;
u32 lbl_1_bss_384C4;
u32 fzgx_obj_lbl_1_bss_384C8;
u32 lbl_1_bss_384CC;
u32 fzgx_obj_lbl_1_bss_384D0;
u8 lbl_1_bss_384D0_fill_384D4;
u8 lbl_1_bss_384D0_5;
u16 lbl_1_bss_384D0_fill_384D6;
u32 fzgx_obj_lbl_1_bss_384D8[5632];
u32 lbl_1_bss_3DCD8;
u32 fzgx_obj_lbl_1_bss_3DCDC[2];
u8 lbl_1_bss_3DCE4;
u8 lbl_1_bss_3DCE4_fill_3DCE5;
u16 lbl_1_bss_3DCE4_fill_3DCE6;
u32 lbl_1_bss_3DCE4_fill_3DCE8[16];
u32 lbl_1_bss_3DD28[163];
u8 lbl_1_bss_3DD28_28C;
u8 lbl_1_bss_3DD28_fill_3DFB5;
u16 lbl_1_bss_3DD28_fill_3DFB6;
u32 lbl_1_bss_3DD28_fill_3DFB8[15];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_384C0;
    s = *(u8 *)&lbl_1_bss_384C4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_384C8;
    s = *(u8 *)&lbl_1_bss_384CC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_384D0;
    s = *(u8 *)&lbl_1_bss_384D0_fill_384D4;
    s = *(u8 *)&lbl_1_bss_384D0_5;
    s = *(u8 *)&lbl_1_bss_384D0_fill_384D6;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_384D8;
    s = *(u8 *)&lbl_1_bss_3DCD8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3DCDC;
    s = *(u8 *)&lbl_1_bss_3DCE4;
    s = *(u8 *)&lbl_1_bss_3DCE4_fill_3DCE5;
    s = *(u8 *)&lbl_1_bss_3DCE4_fill_3DCE6;
    s = *(u8 *)&lbl_1_bss_3DCE4_fill_3DCE8;
    s = *(u8 *)&lbl_1_bss_3DD28;
    s = *(u8 *)&lbl_1_bss_3DD28_28C;
    s = *(u8 *)&lbl_1_bss_3DD28_fill_3DFB5;
    s = *(u8 *)&lbl_1_bss_3DD28_fill_3DFB6;
    s = *(u8 *)&lbl_1_bss_3DD28_fill_3DFB8;
}
#pragma section code_type ".text"

typedef void (*LoadCallback)(u32);

/* arg0 is passed straight through to the slot's callback (r3 is untouched before bctrl). */
void fn_1_45A58(u32 arg0) {
    LoadCallback f;
    u8 v;
    ((u32 *)&lbl_1_bss_3DCE4)[lbl_1_bss_384D0_5] = 0;
    f = ((LoadCallback *)&lbl_1_bss_3DD28_28C)[lbl_1_bss_384D0_5];
    if (f != 0) {
        f(arg0);
    }
    lbl_1_bss_384D0_5++;
    v = lbl_1_bss_384D0_5;
    lbl_1_bss_384D0_5 = (v > 15) ? 0 : v;
}
/* fzgx:end fn_1_45A58 */

/* fzgx:begin fn_1_45AD4 */
// Reports whether loading is already active or any load slot is occupied.
int fn_1_45AD4(void) {
    s8 i;

    if ((s32)lbl_1_bss_384D0 != 0) {
        return 1;
    }

    for (i = 0; i < 16; i++) {
        if ((s32)lbl_1_bss_3DCE4[i] != 0) {
            return 1;
        }
    }

    return 0;
}
/* fzgx:end fn_1_45AD4 */

/* fzgx:begin fn_1_45B2C */
typedef struct Fn145B2CData {
    s32 kind;
    u8 pad[0x54];
    void *value;
} Fn145B2CData;

void *fn_1_45B2C(Fn145B2CData *data) {
    void *result;
    switch (data->kind) {
    case 1:
        result = data->value;
        break;
    default:
        result = fn_80006DE8(&data->kind + 1);
        break;
    }
    return result;
}
/* fzgx:end fn_1_45B2C */

/* fzgx:begin fn_1_45B68 */
typedef struct Fn45B68Object {
    s32 state;
    u8 _pad[0x50];
    void *value;
} Fn45B68Object;

void *fn_1_45B68(Fn45B68Object *obj) {
    switch (obj->state) {
    case 1:
        return obj->value;
    default:
        return fn_80006DFC((u8 *)obj + 4);
    }
}
/* fzgx:end fn_1_45B68 */

/* fzgx:begin fn_1_45BA4 */
void fn_1_45BA4(s32 value) {
    fn_1_D3214();
    lbl_1_bss_384C8 = value & (value >> 31);
}
/* fzgx:end fn_1_45BA4 */

/* fzgx:begin fn_1_45BE0 */
void fn_1_45BE0(void) {
    lbl_1_bss_384C8 = 0;
}
/* fzgx:end fn_1_45BE0 */

/* fzgx:begin fn_1_45CD8 */
int fn_1_45CD8(int index) {
    s32 j;

    for (j = 0; j < 0x400; j++) {
        index++;
        if ((&lbl_1_bss_384D8.unk_0)[index * 4] == 0) {
            return index;
        }
        if (index >= 0x400) {
            index = 0;
        }
    }

    return index;
}
/* fzgx:end fn_1_45CD8 */

/* fzgx:begin fn_1_45D78 */
typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
} fn_1_45D78_LoadEntry;

int fn_1_45D78(u32 start, u32 size, u32 *out_end, s32 mode) {
    u32 limit;
    fn_1_45D78_LoadEntry *entry;
    u32 i;
    u32 total;
    u32 end;

    limit = start + size;
    entry = (fn_1_45D78_LoadEntry *)&lbl_1_bss_384D8;
    total = -1;
    for (i = 0; i < 0x400; i++, entry++) {
        if (entry->unk_0 != 0) {
            if (entry->unk_8 < limit) {
                end = entry->unk_8 + entry->unk_C;
                if (end > start) {
                    if (mode == 0 && (entry->unk_0 & 0x10000000) != 0) {
                        if (out_end != 0) {
                            *out_end = end;
                        }
                        return 0;
                    }
                    entry->unk_0 = 0;
                    if (total == (u32)-1) {
                        total = 0;
                    }
                    total += entry->unk_C;
                }
            }
        }
    }
    return total;
}
/* fzgx:end fn_1_45D78 */

/* fzgx:begin fn_1_45E84 */
s32 fn_1_45E84(s32 value) {
    value += 1;
    if (value >= 0x200) {
        value = 0;
    }
    return value;
}
/* fzgx:end fn_1_45E84 */

/* fzgx:begin fn_1_46144 pool */
#include "dolphin/ar.h"

extern void fn_1_D3214(void);
extern void fn_1_45890(u32 request);
extern void DCInvalidateRange(void *addr, u32 size);

typedef struct Fn464BCEntry {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
} Fn464BCEntry;

typedef struct Fn464BCObject {
    u8 unk_00[4];
    Fn464BCEntry *unk_04;
    u8 unk_08[8];
    u8 *unk_10;
} Fn464BCObject;

typedef struct {
    void *header;
    void *data;
    void *table;
    u32 count;
    void *end;
    u32 unk_14;
    u32 unk_18;
} Fn8006A3DCResult;

extern void fn_1_464BC(void *object, u32 index, void *arg2, u32 arg3);
extern s32 fn_8006A3DC(void *header, Fn8006A3DCResult *result);
extern void OSReport(const char *, ...);
extern s32 fn_8000700C(const char *);

typedef struct {
    u32 flags;
    u32 unk_4;
    u32 addr;
    u32 size;
} LoadSlot;

typedef struct {
    u8 unk_0;
    u8 pad_1[3];
    u32 offset;
    u32 size;
} ArcEntry;

typedef struct {
    u32 unk_0;
    u32 offset;
    u32 size;
} ArcHeader;

typedef struct {
    u8 pad_0[8];
    u32 aram;
    u32 end;
} LoadArchive;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_384C0;
u8 lbl_1_bss_384C0_gap_384C4[12];
s32 fzgx_obj_lbl_1_bss_384D0;                /* +0x10 busy */
u32 fzgx_obj_lbl_1_bss_384D0_4;
LoadSlot fzgx_obj_lbl_1_bss_384D8[0x400];    /* +0x18 slot table */
u8 fzgx_obj_lbl_1_bss_384D8_fill_4000[0x5820 - 0x4018];
s32 fzgx_obj_lbl_1_bss_3DCE0;                /* +0x5820 next free slot */
s32 fzgx_obj_lbl_1_bss_3DCE4[16];            /* +0x5824 pending requests */
u32 fzgx_obj_lbl_1_bss_3DD24[2];
u8 *fzgx_obj_lbl_1_bss_3DD2C;                /* +0x586c work buffer */

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_384C0;
    s = *(u8 *)&lbl_1_bss_384C0_gap_384C4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_384D0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_384D0_4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_384D8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_384D8_fill_4000;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3DCE0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3DCE4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3DD24;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3DD2C;
}
#pragma section code_type ".text"

static inline int fn_1_46144_busy(void) {
    s8 i;
    s32 *pending;
    if (fzgx_obj_lbl_1_bss_384D0 != 0) {
        return 1;
    }
    pending = fzgx_obj_lbl_1_bss_3DCE4;
    for (i = 0; i < 16; i++) {
        if (pending[i] != 0) {
            return 1;
        }
    }
    return 0;
}

int fn_1_46144(LoadArchive *archive, s32 locked, s32 named) {
    ARQRequest request;
    u8 name[0x40];
    Fn8006A3DCResult result;
    u32 offset;
    ArcHeader *header;
    u32 aram;
    u32 size;
    s32 count;
    ArcEntry *entry;
    s32 i;
    LoadSlot *slot;
    s32 k;
    s32 next;
    u32 slotAddr;
    u32 slotSize;

    aram = archive->aram;
    while (fn_1_46144_busy()) {
        fn_1_D3214();
    }
    fzgx_obj_lbl_1_bss_384D0 = 1;
    DCInvalidateRange(fzgx_obj_lbl_1_bss_3DD2C, 0x20);
    ARQPostRequest(&request, 0, 1, 1, aram, (u32)fzgx_obj_lbl_1_bss_3DD2C, 0x20, (ARQCallback)fn_1_45890);
    while (fn_1_46144_busy()) {
        fn_1_D3214();
    }
    header = (ArcHeader *)fzgx_obj_lbl_1_bss_3DD2C;
    size = (header->size + 0x1f) & ~0x1f;
    offset = header->offset;
    archive->end = size + offset;
    fzgx_obj_lbl_1_bss_384D0 = 1;
    DCInvalidateRange(fzgx_obj_lbl_1_bss_3DD2C + offset, size);
    ARQPostRequest(&request, 0, 1, 1, aram + offset, (u32)(fzgx_obj_lbl_1_bss_3DD2C + offset), size, (ARQCallback)fn_1_45890);
    while (fn_1_46144_busy()) {
        fn_1_D3214();
    }
    if (fn_8006A3DC(header, &result) == 0) {
        OSReport((const char *)lbl_1_data_67D0);
        return 0;
    }
    entry = (ArcEntry *)(fzgx_obj_lbl_1_bss_3DD2C + offset);
    count = entry->size;
    for (i = 0; i < count; i++, entry++) {
        if (entry->unk_0 == 0) {
            slotAddr = entry->offset;
            slotSize = entry->size;
            slot = &fzgx_obj_lbl_1_bss_384D8[fzgx_obj_lbl_1_bss_3DCE0];
            slot->flags = (locked ? 0x10000000 : 0) | 0x40000000;
            slot->addr = aram + slotAddr;
            slot->size = (slotSize + 0x1f) & ~0x1f;
            if (named) {
                fn_1_464BC(&result, i, name, 0x40);
                slot->unk_4 = fn_8000700C((const char *)name);
            } else {
                slot->flags |= 0x08000000;
                slot->unk_4 = i;
            }
            next = fzgx_obj_lbl_1_bss_3DCE0;
            for (k = 0; k < 0x400; k++) {
                next++;
                if (fzgx_obj_lbl_1_bss_384D8[next].flags == 0) {
                    break;
                }
                if (next >= 0x400) {
                    next = 0;
                }
            }
            fzgx_obj_lbl_1_bss_3DCE0 = next;
        }
    }
    return 1;
}
/* fzgx:end fn_1_46144 */

/* fzgx:begin fn_1_464BC */
typedef struct Fn464BCEntry {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
} Fn464BCEntry;

typedef struct Fn464BCObject {
    u8 unk_00[4];
    Fn464BCEntry *unk_04;
    u8 unk_08[8];
    u8 *unk_10;
} Fn464BCObject;


void fn_1_464BC(Fn464BCObject *object, u32 index, void *arg2, void *arg3) {
    void *result;
    Fn464BCEntry *base;
    Fn464BCEntry *entry;
    u32 value;
    s32 flag;

    base = object->unk_04;
    entry = &base[index];
    result = (void *)fn_1_4630(lbl_801A6410, (u32)arg3, (*(u8 (*)[76])&lbl_1_data_6730), 0x3f4);
    value = entry->unk_00;
    fn_80083DB0( (char *)(void *)(arg2), (const char *)(void *)(object->unk_10 + (value & 0x00ffffff)));

    while (entry > base) {
        value = entry->unk_00;
        flag = (value & 0xff000000) != 0;
        if (flag != 0) {
            fn_80083DB0( (char *)(void *)(result), (const char *)(void *)(object->unk_10 + (value & 0x00ffffff)));
            strcat( (char *)(void *)(result), (const char *)(void *)(&lbl_1_data_67CC));
            strcat( (char *)(void *)(result), (const char *)(void *)(arg2));
            fn_80083DB0( (char *)(void *)(arg2), (const char *)(void *)(result));
            entry = &base[entry->unk_04];
        } else {
            entry--;
        }
    }

    fn_1_46B4(lbl_801A6410, (u32)(void *)(result), (const char *)(u8 *)((*(u8 (*)[76])&lbl_1_data_6730)), 0x402);
}
/* fzgx:end fn_1_464BC */

/* fzgx:begin fn_1_465D0 */
// Queues a completed load operation in the circular load queue.
s32 fn_1_465D0(s32 arg0, s32 arg1) {
    s32 *base = (s32 *)&lbl_1_bss_384C0;
    s32 result;
    s32 index;
    s32 *entry;
    s32 next;

    if (base[0x161A] != 0) {
        switch (arg1) {
        case 3:
        case 1:
        case 5:
            arg1++;
            break;
        }
    }

    result = fn_8000700C(arg0);
    if (result < 0) {
        return -1;
    }

    if (base[0] == base[1]) {
        fn_1_3BDC(2);
    }

    index = base[0];
    next = index + 1;
    if (next >= 0x200) {
        next = 0;
    }

    if (base[1] == next) {
        return -1;
    }

    entry = base + 0x1006;
    entry += index * 3;
    base[0] = next;
    entry[0] = arg1;
    entry[1] = result;
    return index;
}
/* fzgx:end fn_1_465D0 */

/* fzgx:begin fn_1_466B0 */
extern s32 fn_1_467F4(void);
extern void fn_1_469BC(void);

typedef struct Fn466B0Entry {
    u32 flags;
    u32 unk_4;
    u32 start;
    u32 size;
} Fn466B0Entry;

static inline u32 fn466B0Scan(u32 arg0, s32 arg1, u32 result, s32 i, Fn466B0Entry *tbl) {
    for (i = 0; i < 0x400; i++, tbl++) {
        Fn466B0Entry *e = tbl;
        if (e->flags != 0 && e->start < arg0 + 1 && e->start + e->size > arg0) {
            if (arg1 == 0 && (e->flags & 0x10000000)) {
                result = 0;
                break;
            }
            e->flags = 0;
            if (result == -1) {
                result = 0;
            }
            result += e->size;
        }
    }
    return result;
}

u32 fn_1_466B0(u32 arg0, s32 arg1) {
    u32 ret;
    struct { u32 value; } result;

    if (fn_1_467F4() != 0) {
        fn_1_469BC();
    }
    result.value = fn466B0Scan(arg0, arg1, -1, 0, (Fn466B0Entry *)&lbl_1_bss_384D8);
    ret = result.value;
    if (result.value == -1) {
        ret = 0;
    }
    return ret;
}
/* fzgx:end fn_1_466B0 */

/* fzgx:begin fn_1_467F4 */
s32 fn_1_467F4(void) {
    u32 value;

    fn_8000659C();
    value = lbl_1_bss_384C4;
    return lbl_1_bss_384C0[0] != value;
}
/* fzgx:end fn_1_467F4 */

/* fzgx:begin fn_1_469BC */
// Clears invalid entries in the load table and mirrors its first value.
void fn_1_469BC(void) {
    u32 *base;
    u32 *entry;
    int i;

    base = lbl_1_bss_384C0;
    entry = base + 6;
    for (i = 0; i < 0x400;) {
        if (entry[0] == ((u32)1 << 31)) {
            entry[0] = 0;
            base[0x1606] = entry[2];
        }
        i++;
        entry += 4;
    }
    base[1] = base[0];
}
/* fzgx:end fn_1_469BC */

/* fzgx:begin fn_1_46A60 */
void fn_1_46A60(void) {
    fn_1_46A8C(lbl_1_bss_3DCDC);
}
/* fzgx:end fn_1_46A60 */

/* fzgx:begin fn_1_46A8C */
typedef struct {
    u32 type;
    u32 value;
    u32 unk_8;
} fn_1_46A8C_Entry;

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u8 unk_8[0x4010];
    fn_1_46A8C_Entry entries[0x200];
} fn_1_46A8C_State;

u32 fn_1_46A8C(u32 value) {
    fn_1_46A8C_State *base;
    s32 next;
    s32 current;
    u32 initial;
    u32 arg;
    fn_1_46A8C_Entry *entry;

    base = (fn_1_46A8C_State *)&lbl_1_bss_384C0;
    arg = value;
    initial = base->unk_0;
    next = initial + 1;
    current = initial;
    if (next >= 0x200) {
        next = 0;
    }

    if ((s32)base->unk_4 == next) {
        return -1;
    }

    if (arg < fn_1_46EC8() || arg > fn_1_46ED8()) {
        arg = fn_1_46EC8();
    }

    entry = base->entries;
    entry += base->unk_0;
    base->unk_0 = next;
    entry->type = 0xb;
    entry->value = arg;

    return current;
}
/* fzgx:end fn_1_46A8C */

/* fzgx:begin fn_1_46B44 pool */
struct fn_1_46B44_Entry {
    u32 type;
    u32 value;
    u32 unk_8;
};

struct fn_1_46B44_lbl_1_bss_384C0 {
    u32 unk_0;
    u32 unk_4;
    u8 unk_8[0x4010];
    struct fn_1_46B44_Entry entries[0x200];
};

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_384C0;
u32 lbl_1_bss_384C4;
u32 fzgx_obj_lbl_1_bss_384C8;
u32 lbl_1_bss_384CC;
u32 fzgx_obj_lbl_1_bss_384D0[2];
u32 fzgx_obj_lbl_1_bss_384D8[4096];
struct fn_1_46B44_Entry lbl_1_bss_384D8_4000[0x200];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_384C0;
    s = *(u8 *)&lbl_1_bss_384C4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_384C8;
    s = *(u8 *)&lbl_1_bss_384CC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_384D0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_384D8;
    s = *(u8 *)&lbl_1_bss_384D8_4000;
}
#pragma section code_type ".text"

u32 fn_1_46B44(u32 arg0, u32 arg1) {
    s32 v1;
    struct fn_1_46B44_Entry *v2;
    u32 v0;
    s32 current;

    
    v0 = fzgx_obj_lbl_1_bss_384C0;
    v1 = v0 + 1;
    current = v0;
    if (v1 >= 512) {
        v1 = 0;
    }
    if ((s32)lbl_1_bss_384C4 == v1) {
        return -1;
    }
    v2 = lbl_1_bss_384D8_4000;
    v2 += v0;
    fzgx_obj_lbl_1_bss_384C0 = v1;
    v2->type = 13;
    v2->value = arg0;
    v2->unk_8 = arg1;
    return current;
}
/* fzgx:end fn_1_46B44 */

/* fzgx:begin fn_1_46BA0 pool */
typedef struct {
    u32 type;
    u32 value;
    u32 unk_8;
} Entry;

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u8 unk_8[0x4010];
    Entry entries[0x200];
} State;


/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_384C0;
u32 lbl_1_bss_384C4;
u32 fzgx_obj_lbl_1_bss_384C8;
u32 lbl_1_bss_384CC;
u32 fzgx_obj_lbl_1_bss_384D0[2];
u32 fzgx_obj_lbl_1_bss_384D8[4096];
Entry lbl_1_bss_384D8_4000[0x200];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_384C0;
    s = *(u8 *)&lbl_1_bss_384C4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_384C8;
    s = *(u8 *)&lbl_1_bss_384CC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_384D0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_384D8;
    s = *(u8 *)&lbl_1_bss_384D8_4000;
}
#pragma section code_type ".text"

u32 fn_1_46BA0(u32 arg0, u32 arg1) {
    s32 next;
    Entry *entry;
    s32 current;

    
    current = fzgx_obj_lbl_1_bss_384C0;
    next = current + 1;
    if (next >= 0x200) {
        next = 0;
    }

    if ((s32)lbl_1_bss_384C4 == next) {
        return -1;
    }

    entry = lbl_1_bss_384D8_4000;
    entry += fzgx_obj_lbl_1_bss_384C0;
    fzgx_obj_lbl_1_bss_384C0 = next;
    entry->type = 0xc;
    entry->value = arg0;
    entry->unk_8 = arg1;

    return current;
}
/* fzgx:end fn_1_46BA0 */

/* fzgx:begin fn_1_46C60 */
u32 fn_1_46C60(void) {
    return lbl_1_bss_3DCD8;
}
/* fzgx:end fn_1_46C60 */

/* fzgx:begin fn_1_46C70 */
s32 fn_1_46C70(void) {
    s32 value;
    s32 i;
    Obj_1_bss_384D8 *entry;

    value = fn_8000700C();
    if (value == -1) {
        return -1;
    }

    entry = &lbl_1_bss_384D8;
    for (i = 0; i < 0x400; ) {
        if (entry->unk_0 != 0 && (s32)entry->unk_4 == value) {
            return entry->unk_8;
        }
        i++;
        entry = (Obj_1_bss_384D8 *)((u8 *)entry + 0x10);
    }
    return -1;
}
/* fzgx:end fn_1_46C70 */

/* fzgx:begin fn_1_46DC4 */
s32 fn_1_46DC4(s32 value) {
    u8 *entry;
    s32 count;
    s32 i;

    count = 0;
    value = fn_8000700C(value);
    entry = (u8 *)&lbl_1_bss_384D8;
    for (i = 0; i < 1024; i++, entry += 0x10) {
        if ((((Obj_1_bss_384D8 *)entry)->unk_0 & 0x10000000) != 0 &&
            (s32)((Obj_1_bss_384D8 *)entry)->unk_4 == value) {
            ((Obj_1_bss_384D8 *)entry)->unk_0 &= ~0x10000000;
            count++;
        }
    }
    return count;
}
/* fzgx:end fn_1_46DC4 */

/* fzgx:begin fn_1_46EA8 */
void fn_1_46EA8(u32 value) {
    lbl_1_bss_3DD28[0] = value;
}
/* fzgx:end fn_1_46EA8 */

/* fzgx:begin fn_1_46EB4 */
void fn_1_46EB4(u32 value, u32 value2) {
    lbl_1_bss_3DCDC = value;
    lbl_1_bss_3DFF4.unk_0 = value2;
}
/* fzgx:end fn_1_46EB4 */

/* fzgx:begin fn_1_46EC8 */
// Returns the current load-state value.
u32 fn_1_46EC8(void) {
    return lbl_1_bss_3DCDC;
}
/* fzgx:end fn_1_46EC8 */

/* fzgx:begin fn_1_46ED8 */
u32 fn_1_46ED8(void) {
    return lbl_1_bss_3DFF4.unk_0;
}
/* fzgx:end fn_1_46ED8 */

/* fzgx:begin fn_1_4706C */
extern void fn_8000659C(void);

typedef struct E { s32 a, b, c, d; } E;
typedef struct B {
    s32 x0, x1;
    s32 pad[4];
    E e[0x400];
    s32 tail[2];
} B;

static inline E * fn_1_4706C_read_pointer(B * owner) { return owner->e; }
#pragma opt_dead_assignments off
static inline void fn_1_4706C_scan(s32 start, B *b) {
    s32 i;
    s32 z;
    struct { E *value; } p;
    i = start;
    z = i;
    p.value = b->e;
    for (; i < 0x400; i++, p.value++) {
        if (p.value->a == (s32)0x80000000) {
            p.value->a = z;
            *(s32 *)((u8 *)b + 0x5818) = p.value->c;
        }
    }
}
void fn_1_4706C(void) {
    B *b = (B *)lbl_1_bss_384C0;
    s32 z;
    s32 i;
    E *p;
    fn_8000659C();
    if (b->x0 != b->x1) {
        fn_1_4706C_scan(0, b);
        b->x1 = b->x0;
    }
    z = 0;
    p = b->e;
    for (i = 0; i < 0x400; i++, p++) {
        p->a = z;
    }
    *(s32 *)((u8 *)b + 0x5820) = 0;
}
#pragma opt_dead_assignments reset
/* fzgx:end fn_1_4706C */

/* fzgx:begin fn_1_47184 */
u32 fn_1_47184(void) {
    return lbl_1_bss_3DFF4.unk_0 - lbl_1_bss_3DCDC;
}
/* fzgx:end fn_1_47184 */

/* fzgx:begin fn_1_471A0 */
u32 fn_1_471A0(void) {
    u32 *p;
    u32 i;
    u32 total;

    total = 0;
    p = (*(u32 (*)[5632])&lbl_1_bss_384D8);
    for (i = 0; i < 0x400; i++, p += 4) {
        if ((p[0] & 0x64000000) != 0) {
            total += p[3];
        }
    }
    return total;
}
/* fzgx:end fn_1_471A0 */

/* fzgx:begin fn_1_47268 */
u32 fn_1_47268(void) {
    u32 *p;
    u32 i;
    u32 total;

    total = 0;
    p = (*(u32 (*)[])&lbl_1_bss_384D8);
    for (i = 0; i < 0x400; i++, p += 4) {
        if ((p[0] & 0x10000000) != 0) {
            total += p[3];
        }
    }
    return total;
}
/* fzgx:end fn_1_47268 */

/* fzgx:begin fn_1_479B0 */
// Reset the loading state and clear the associated resource markers.
void fn_1_479B0(void) {
    fn_1_47EE4(0);
    fn_1_485C8(0);
    lbl_1_data_6CA0.unk_0 = -1;
    *(u32 *)&lbl_1_data_6CA0.pad_C[0] = -1;
    *(u32 *)&lbl_1_data_6CA0.pad_C[0xc] = -1;
}
/* fzgx:end fn_1_479B0 */

/* fzgx:begin fn_1_479F0 */
void fn_1_479F0(s16 index) {
    s32 *entry;
    s32 i;

    entry = (s32 *)&lbl_1_data_67F0.unk_0 + index * 20;
    for (i = 0; i < 10; i++, entry += 2) {
        if (entry[0] != -1) {
            fn_1_48004(entry[0], entry[1]);
        } else {
            return;
        }
    }
}
/* fzgx:end fn_1_479F0 */

/* fzgx:begin fn_1_47A60 */
// Process the ten load entries associated with the selected index.
void fn_1_47A60(s16 index) {
    s32 *entry;
    s32 i;

    entry = (s32 *)&lbl_1_data_67F0.unk_0 + index * 20;
    for (i = 0; i < 10; i++) {
        if (entry[i * 2] != -1) {
            fn_1_48140(entry[i * 2]);
        } else {
            fn_1_4DDC0();
            fn_1_4F724();
            break;
        }
    }
}
/* fzgx:end fn_1_47A60 */

/* fzgx:begin fn_1_47AD4 */
typedef struct {
    u32 unk_0;
    u8 pad_4[0x48];
    u8 entry[0x10];
} LoadResult_47AD4;

typedef struct {
    u32 flags;
    u32 offset;
    u16 width;
    u16 height;
    u32 unk_C;
} TexEntry_47AD4;

typedef struct {
    u32 dummy[8];
} TexObj_47AD4;

typedef struct {
    u32 count;
    TexEntry_47AD4 *entries;
    u32 unk_8;
    TexObj_47AD4 *texobjs;
} TexHeader_47AD4;

typedef struct {
    u32 unk_0;
    char *names[7];
    u32 unk_20;
    u8 unk_24;
} LoadState_47AD4;

extern s32 lbl_801A66B4;
extern u32 lbl_801A6410;
extern char lbl_1_data_1A368[9];
extern u8 lbl_1_bss_3E000[32];

extern s32 fn_8006FDEC(void);
extern int fn_1_45730(char *, LoadResult_47AD4 *);
extern size_t strlen(const char *);
extern s32 strncmp(const char *, const char *, size_t);
extern s32 fn_1_458A0(LoadResult_47AD4 *, void *, u32, u32);
extern int fn_1_45850(LoadResult_47AD4 *);
extern u32 fn_1_45B2C(LoadResult_47AD4 *);
extern u32 OSGetArenaHi(void);
extern void OSSetArenaHi(u32);
extern u32 fn_8000B334(u32, u32);
extern u32 fn_8000B360(u32, u32);
extern u32 fn_1_45D0(u32, u32, const char *, int);
extern void fn_1_12860(u32, u32);
extern u32 fn_1_12F78(char *, u32);
extern void DCFlushRange(void *, u32);
extern void GXInitTexObj(TexObj_47AD4 *, void *, u16, u16, u32, u32, u32, u8);
extern void GXInvalidateTexAll(void);
extern void fn_1_4877C(void);

typedef struct {
    u32 end;
} NameEnd_47AD4;

static inline char *nameSuffix_47AD4(u32 end) {
    NameEnd_47AD4 result;
    result.end = end;
    return (char *)result.end - 3;
}

// Load the archive selected by the current index into the slot's heap and build its texture objects.
s32 fn_1_47AD4(LoadState_47AD4 *state, s32 slot, s32 useArena, s32 allocate) {
    TexHeader_47AD4 *hdr;
    u32 data;
    u32 arenaHi;
    char *name;
    u32 compSize;
    u32 fullSize;
    u32 compBuf;
    s32 len;
    u32 i;
    LoadResult_47AD4 res;
    u32 heap;

    fn_8006FDEC();
    name = state->names[lbl_801A66B4];
    if (!fn_1_45730(name, &res)) {
        return 0;
    }
    if (slot == 0) {
        (&lbl_1_data_6CA0.unk_0)[slot * 3] = lbl_801A6410;
    }
    heap = (&lbl_1_data_6CA0.unk_0)[slot * 3];
    len = strlen(name);
    if (len >= 3 && (len += (u32)name, len -= 3, strncmp((char *)len, (char *)&lbl_1_data_1A364, 3)) == 0) {
        if (fn_1_458A0(&res, lbl_1_bss_3E000, 0x20, 0) < 0) {
            return 0;
        }
        compSize = (__lwbrx(lbl_1_bss_3E000, 0) + 0x27) & ~0x1f;
        fullSize = (__lwbrx(lbl_1_bss_3E000, 4) + 0x1f) & ~0x1f;
        if (allocate != 0) {
            if (useArena != 0) {
                arenaHi = OSGetArenaHi();
                hdr = (TexHeader_47AD4 *)fn_8000B334(fullSize + 0x10, 0x20);
                compBuf = fn_8000B360(compSize, 0x20);
            } else {
                hdr = (TexHeader_47AD4 *)fn_1_45D0(heap, fullSize + 0x10, lbl_1_data_1A368, 0x12f);
            }
        } else {
            hdr = (TexHeader_47AD4 *)state->unk_20;
        }
        data = ((u32)hdr + 0x2f) & ~0x1f;
        if (useArena != 0) {
            if (fn_1_458A0(&res, (void *)compBuf, compSize, 0) < 0) {
                return 0;
            }
            if (!fn_1_45850(&res)) {
                return 0;
            }
            fn_1_12860(compBuf, data);
        } else {
            if (fn_1_12F78(name, data) == 0) {
                return 0;
            }
        }
        DCFlushRange((void *)data, fullSize);
        if (useArena != 0) {
            OSSetArenaHi(arenaHi);
        }
    } else {
        fullSize = (fn_1_45B2C(&res) + 0x1f) & ~0x1f;
        if (allocate != 0) {
            if (useArena != 0) {
                hdr = (TexHeader_47AD4 *)fn_8000B334(fullSize + 0x20, 0x20);
            } else {
                hdr = (TexHeader_47AD4 *)fn_1_45D0(heap, fullSize + 0x20, lbl_1_data_1A368, 0x156);
            }
        } else {
            hdr = (TexHeader_47AD4 *)state->unk_20;
        }
        data = ((u32)hdr + 0x2f) & ~0x1f;
        fn_1_458A0(&res, (void *)data, fullSize, 0);
        fn_1_45850(&res);
    }
    hdr->count = *(u32 *)data;
    hdr->entries = (TexEntry_47AD4 *)(data + 4);
    if (useArena != 0) {
        hdr->texobjs = (TexObj_47AD4 *)fn_8000B334(hdr->count << 5, 0x20);
    } else {
        hdr->texobjs = (TexObj_47AD4 *)fn_1_45D0(heap, hdr->count << 5, lbl_1_data_1A368, 0x168);
    }
    for (i = 0; i < hdr->count; i++) {
        TexEntry_47AD4 *entry = &hdr->entries[i];
        u32 flags = entry->flags;
        void *image = (void *)(data + entry->offset);
        if (!(flags & 0x100) && entry->width != 0 && entry->height != 0) {
            GXInitTexObj(&hdr->texobjs[i], image, entry->width, entry->height, flags & 0x1f, 0, 0, 0);
        }
    }
    GXInvalidateTexAll();
    state->unk_24 = slot;
    state->unk_0 = 1;
    state->unk_20 = (u32)hdr;
    fn_1_4877C();
    return 1;
}
/* fzgx:end fn_1_47AD4 */

/* fzgx:begin fn_1_485E8 */
// Find the resource matching value, load its data, and return the destination buffer.
void *fn_1_485E8(s32 index, s32 value) {
    s32 entry = 0;

    while (((s16 **)lbl_1_data_19FC4)[index][entry] != -1) {
        if (((s16 **)lbl_1_data_19FC4)[index][entry] == value) {
            fn_80083DB0( (char *)(void *)(lbl_1_bss_3E024), (const char *)(void *)(((void ***)lbl_1_data_19098)[index][entry]));
            return lbl_1_bss_3E024;
        }
        entry++;
    }

    fn_80083DB0( (char *)(void *)(lbl_1_bss_3E024), (const char *)(void *)(lbl_1_data_1A3AC));
    return lbl_1_bss_3E024;
}
/* fzgx:end fn_1_485E8 */
