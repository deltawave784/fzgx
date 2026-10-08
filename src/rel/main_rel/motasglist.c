#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/motasglist.h"
#include "dolphin/hw_regs.h"
#include "game/main_rel/motasglist_types.h"

extern void * fn_1_41BDC();
extern void fn_1_41328(void *arg0);
extern void lbl_8006DBAC(void *value);
extern void fn_8006E5FC(f32 *arg0);
extern void fn_1_43264(void *arg0, f32 arg1);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern void lbl_8006D668(void *vector);
extern void fn_1_449A8(void *vector);
extern void lbl_8006DB74(void *value);
extern u32 lbl_1_bss_384CC;
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern const f64 lbl_1_rodata_F40;
extern const f32 lbl_1_rodata_F34;
extern const f32 lbl_1_rodata_F30;
extern const f64 lbl_1_rodata_F48;
extern const f32 lbl_1_rodata_F38;
extern const f32 lbl_1_rodata_F50;
extern const f32 lbl_1_rodata_F54;
extern const f32 lbl_1_rodata_F68;
extern const f32 lbl_1_rodata_F6C;
extern f32 lbl_8006D188(s32);
extern void lbl_8006D758(void);
extern void lbl_8006DD7C(void);
extern void lbl_8006DFC4(void *);
extern void lbl_8006E1B0(void *, void *);
extern void mathutil_mtxA_from_quat(void *);
extern void lbl_8006E15C(f32, f32, f32);

/* fzgx:begin fn_1_41850 */
struct fn_1_41850_Arg0 {
    u8 pad_0[0x2];
    u16 unk_2;
};
struct fn_1_41850_Node {
    u8 pad_0[0x28];
    void *unk_28;
    u8 pad_2c[0x4];
    void *next;
};

void fn_1_41850(void *arg0, s32 arg_sp0) {
    void *temp_r4;
    void *temp_r4_2;
    void *temp_r4_3;
    void *temp_r4_4;
    void *temp_r4_5;
    void *temp_r4_6;
    void *temp_r4_7;
    void *temp_r4_8;
    void *temp_r4_9;
    void *temp_r4_10;
    void *temp_r4_11;
    u16 temp_r3;
    s32 var_r28;
    void *temp_r28;
    s32 var_r27;
    void *var_r27_2;

    temp_r3 = *(u16 *)((u8 *)(arg0) + 2);
    if (temp_r3 & 1) {
        if (!(temp_r3 & 4)) {
            var_r27 = 0;
            var_r28 = 0;
            while (var_r27 < (s32) (*(u16 *)((u8 *)(arg0) + 16))) {
                temp_r4 = (void *)(((struct fn_1_41850_Node *)(*(void **)((u8 *)(arg0) + 12)))[var_r27].unk_28);
                if (temp_r4 != NULL) {
                    fn_1_46B4((u32)(lbl_801A6410.unk_0), (u32)((void *)(temp_r4)), (const char *)((s8 *) (*(u8 (*)[])&lbl_1_data_6720)), (s32)(0x123));
                }
                var_r28 += 0x34;
                var_r27 += 1;
                            }
            temp_r4_2 = (void *)(*(void **)((u8 *)(arg0) + 20));
            if (temp_r4_2 != NULL) {
                fn_1_46B4((u32)(lbl_801A6410.unk_0), (u32)((void *)(temp_r4_2)), (const char *)((s8 *) (*(u8 (*)[])&lbl_1_data_6720)), (s32)(0x125));
            }
            temp_r4_3 = (void *)(*(void **)((u8 *)(arg0) + 32));
            if (temp_r4_3 != NULL) {
                fn_1_46B4((u32)(lbl_801A6410.unk_0), (u32)((void *)(temp_r4_3)), (const char *)((s8 *) (*(u8 (*)[])&lbl_1_data_6720)), (s32)(0x126));
            }
        }
        fn_1_46B4((u32)(lbl_801A6410.unk_0), (u32)((void *)(*(void **)((u8 *)(arg0) + 12))), (const char *)((s8 *) (*(u8 (*)[])&lbl_1_data_6720)), (s32)(0x128));
    } else {
        var_r27_2 = (void *)(*(void **)((u8 *)(arg0) + 12));
        while (var_r27_2 != NULL) {
            temp_r4_4 = (void *)(*(void **)((u8 *)(var_r27_2) + 40));
            temp_r28 = (void *)(*(void **)((u8 *)(var_r27_2) + 48));
            if (temp_r4_4 != NULL) {
                fn_1_46B4((u32)(lbl_801A6410.unk_0), (u32)((void *)(temp_r4_4)), (const char *)((s8 *) (*(u8 (*)[])&lbl_1_data_6720)), (s32)(0x12E));
            }
            fn_1_46B4((u32)(lbl_801A6410.unk_0), (u32)((void *)(var_r27_2)), (const char *)((s8 *) (*(u8 (*)[])&lbl_1_data_6720)), (s32)(0x12F));
            var_r27_2 = (void *)(temp_r28);
                    }
        temp_r4_5 = (void *)(*(void **)((u8 *)(arg0) + 32));
        if (temp_r4_5 != NULL) {
            fn_1_46B4((u32)(lbl_801A6410.unk_0), (u32)((void *)(temp_r4_5)), (const char *)((s8 *) (*(u8 (*)[])&lbl_1_data_6720)), (s32)(0x131));
        }
    }
    temp_r4_6 = (void *)(*(void **)((u8 *)(arg0) + 40));
    if (temp_r4_6 != NULL) {
        fn_1_46B4((u32)(lbl_801A6410.unk_0), (u32)((void *)(temp_r4_6)), (const char *)((s8 *) (*(u8 (*)[])&lbl_1_data_6720)), (s32)(0x133));
    }
    temp_r4_7 = (void *)(*(void **)((u8 *)(arg0) + 52));
    if (temp_r4_7 != NULL) {
        fn_1_46B4((u32)(lbl_801A6410.unk_0), (u32)((void *)(temp_r4_7)), (const char *)((s8 *) (*(u8 (*)[])&lbl_1_data_6720)), (s32)(0x10B));
    }
    temp_r4_8 = (void *)(*(void **)((u8 *)(arg0) + 56));
    if (temp_r4_8 != NULL) {
        fn_1_46B4((u32)(lbl_801A6410.unk_0), (u32)((void *)(temp_r4_8)), (const char *)((s8 *) (*(u8 (*)[])&lbl_1_data_6720)), (s32)(0x10C));
    }
    temp_r4_9 = (void *)(*(void **)((u8 *)(arg0) + 44));
    if (temp_r4_9 != NULL) {
        fn_1_46B4((u32)(lbl_801A6410.unk_0), (u32)((void *)(temp_r4_9)), (const char *)((s8 *) (*(u8 (*)[])&lbl_1_data_6720)), (s32)(0x10D));
    }
    temp_r4_10 = (void *)(*(void **)((u8 *)(arg0) + 48));
    if (temp_r4_10 != NULL) {
        fn_1_46B4((u32)(lbl_801A6410.unk_0), (u32)((void *)(temp_r4_10)), (const char *)((s8 *) (*(u8 (*)[])&lbl_1_data_6720)), (s32)(0x10E));
    }
    (*(void **)((u8 *)(arg0) + 52)) = (void *)(NULL);
    (*(s8 *)((u8 *)(arg0) + 39)) = 0;
    (*(void **)((u8 *)(arg0) + 56)) = (void *)(NULL);
    (*(s32 *)((u8 *)(arg0) + 60)) = 0;
    (*(s32 *)((u8 *)(arg0) + 64)) = 0;
    (*(s16 *)((u8 *)(arg0) + 72)) = 0;
    (*(s8 *)((u8 *)(arg0) + 76)) = 0;
    temp_r4_11 = (void *)(*(void **)((u8 *)(arg0) + 8));
    if ((temp_r4_11 != NULL) && !((*(u16 *)((u8 *)(arg0) + 2)) & 2)) {
        fn_1_46B4((u32)(lbl_801A6410.unk_0), (u32)((void *)(temp_r4_11)), (const char *)((s8 *) (*(u8 (*)[])&lbl_1_data_6720)), (s32)(0x137));
    }
    fn_1_46B4((u32)(lbl_801A6410.unk_0), (u32)((void *)(arg0)), (const char *)((s8 *) (*(u8 (*)[])&lbl_1_data_6720)), (s32)(0x138));
}
/* fzgx:end fn_1_41850 */

/* fzgx:begin fn_1_41B18 */
typedef struct Node Node;
struct Node {
    u8 pad[0x30];
    Node *next;
};

typedef struct Object {
    u8 pad[2];
    u16 flags;
    Node *data;
} Object;


#pragma opt_propagation off
void *fn_1_41B18(Object *obj, s32 unused, s32 index) {
    Object *result;
    Node *node;
    s32 i;

    result = (Object *)fn_1_41BDC(obj);
    if ((obj->flags & 1) != 0) {
        return (char *)result->data + index * 0x34;
    }

    node = result->data;
    i = 0;
    while (i < index) {
        node = node->next;
        i++;
    }
    return node;
}
#pragma opt_propagation reset
/* fzgx:end fn_1_41B18 */

/* fzgx:begin fn_1_41BDC */
void *fn_1_41BDC(data, index)
fn_1_41BDC_MotasglistData *data;
s32 index;
{
    if (index < data->count) {
        return (u8 *)data->entries + index * 0xc;
    }

    if (data->fallback == 0) {
        return data;
    }

    return (u8 *)data->fallback + (index - data->fallback_base) * 0xc;
}
/* fzgx:end fn_1_41BDC */

/* fzgx:begin fn_1_41C18 */
typedef struct Sig_fn_1_41C18_Fn1967A8Resource Sig_fn_1_41C18_Fn1967A8Resource;
struct Sig_fn_1_41C18_Fn1967A8Resource {
    u8 unk_00;
    u8 unk_01[0x07];
    u32 unk_08;
    u8 unk_0C[0x10];
    u32 unk_1C;
};

struct fn_1_41C18_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
};


void fn_1_41C18(struct fn_1_41C18_Arg0 *arg0, u32 arg1) {
    struct { u32 value; } v0;
    s32 v1;
    u32 v2;
    u32 v3;
    u32 v4;
    int t1;
    arg0->unk_4 = arg1;
    fn_1_41328( (void *)((Sig_fn_1_41328_RelocData *)arg1));
    if ((*(u16 *)((u8 *)(u32)arg0 + 2) & 0x4) != 0) {
    v0.value = 0;
    v1 = 0;
    v2 = v0.value;
    while (v1 < (s32)*(u16 *)((u8 *)(u32)arg0 + 16)) {
    v3 = arg1;
    v4 = (*(u32 *)((u8 *)(u32)arg0 + 12) + v0.value);
    t1 = fn_1_41488((Sig_fn_1_41488_Fn41488Data *)v3, (const char *)(*(u32 *)((u8 *)(u32)arg0 + 20) + *(u32 *)((u8 *)v4 + 28)));
    v3 = t1;
    *(u16 *)((u8 *)v4 + 2) = v3;
    if (*(u16 *)((u8 *)v4 + 2) == 65535) {
    *(u16 *)((u8 *)v4 + 2) = v2;
    }
    v0.value += 52;
    v1++;
    }
    }
}
/* fzgx:end fn_1_41C18 */

/* fzgx:begin fn_1_41E34 */
typedef struct MotasglistEntry {
    u16 value;
    u16 frame;
    s16 offset;
    u8 pad6[2];
    u32 id;
    u8 padC[4];
} MotasglistEntry;

typedef struct MotasglistObject {
    u8 pad0[0x4c];
    f32 value;
} MotasglistObject;

typedef struct fn_1_41E34_MotasglistData {
    u8 pad0[8];
    MotasglistObject *object;
    u8 padC[0x20];
    MotasglistEntry *entries_a;
    MotasglistEntry *entries_b;
} fn_1_41E34_MotasglistData;

typedef struct MotasglistResult {
    u16 first;
    u16 second;
    f32 value;
    u16 third;
} MotasglistResult;

void fn_1_41E34(fn_1_41E34_MotasglistData *data, u32 index, MotasglistResult *result) {
    MotasglistEntry *entry_a = &data->entries_a[index];
    MotasglistEntry *entry_b = &data->entries_b[index];
    f32 delta;
    f32 start;
    f32 end;
    f32 value;

    result->first = entry_a->id;
    result->second = entry_b->id;
    delta = (f32)(entry_b->frame - entry_a->frame);
    if (lbl_1_rodata_F34 == delta) {
        delta = lbl_1_rodata_F30;
    }
    result->value = (data->object->value - (f32)entry_a->frame) / delta;
    if (result->first == result->second) {
        start = (f32)entry_a->offset;
        end = (f32)entry_b->offset;
        value = result->value * (end - start);
        result->value = start + value;
        result->value = result->value / lbl_1_rodata_F38;
    }
    result->third = entry_b->value;
}
/* fzgx:end fn_1_41E34 */

/* fzgx:begin fn_1_41F58 */
typedef u16 (*Fn41F58Callback)(void *arg, void *entry);

typedef struct Fn41F58Entry {
    u8 pad0[6];
    u8 type;
    u8 pad7;
    u32 value;
} Fn41F58Entry;

typedef struct Fn41F58Data {
    u8 pad0[0x14];
    u32 first_base;
    u8 pad18[8];
    u32 first_data;
    u16 first_count;
    u8 pad26[0x16];
    u32 second_data;
    u32 second_base;
    u8 pad44[6];
    u16 second_count;
} Fn41F58Data;

void fn_1_41F58(Fn41F58Data *data, int type, Fn41F58Callback callback, void *arg) {
    Fn41F58Entry *entry;
    int i;

    for (i = 0; i < data->first_count; i++) {
        entry = (Fn41F58Entry *)(data->first_data + i * 0x10);
        if (entry->type == type) {
            entry->value = callback(arg, (void *)(data->first_base + entry->value));
        }
    }

    for (i = 0; i < data->second_count; i++) {
        entry = (Fn41F58Entry *)(data->second_data + i * 0x10);
        if (entry->type == type) {
            entry->value = callback(arg, (void *)(data->second_base + entry->value));
        }
    }
}
/* fzgx:end fn_1_41F58 */

/* fzgx:begin fn_1_42458 */
typedef struct Fn142458Data {
    u16 value0;
    u16 value2;
    s16 value4;
    u16 pad6;
    u32 value8;
} Fn142458Data;

void fn_1_42458(Fn142458Data *dst, const Fn142458Data *src) {
    dst->value0 = src->value0;
    dst->value8 = src->value8;
    dst->value2 = src->value2;
    dst->value4 = src->value4;
}
/* fzgx:end fn_1_42458 */

/* fzgx:begin fn_1_426AC */
typedef struct Fn1426ACObject {
    u16 count;
    u8 pad2[6];
    u8 *entries;
    u8 padC[0x30];
    void *value;
} Fn1426ACObject;

void fn_1_426AC(Fn1426ACObject *object, void *value) {
    u32 offset;
    s32 i;

    object->value = value;
    i = 0;
    offset = 0;
    for (; i < object->count; i++) {
        *(void **)(object->entries + 0xd0 + offset) = value;
        offset += 0x18c;
        value = (u8 *)value + 8;
    }
}
/* fzgx:end fn_1_426AC */

/* fzgx:begin fn_1_426E4 */
typedef struct Fn1426E4Object {
    u8 pad0[0x24];
    void *value;
} Fn1426E4Object;

void fn_1_426E4(Fn1426E4Object *object, void *value) {
    object->value = value;
    fn_1_41328(value);
}
/* fzgx:end fn_1_426E4 */

/* fzgx:begin fn_1_4270C */
extern const f32 lbl_1_rodata_F54;
extern const f64 lbl_1_rodata_F58;
typedef struct Sig_fn_1_431B8_Fn1431B8Object {
    u8 pad0[4];
    u16 flags;
    u16 index;
    u8 pad8[0xD8];
    u16 value0;
    u16 value1;
    u16 value2;
} Sig_fn_1_431B8_Fn1431B8Object;
extern s32 fn_1_431B8(Sig_fn_1_431B8_Fn1431B8Object *, Sig_fn_1_431B8_Fn1431B8Object *);

typedef struct Fn14270CEntry {
    u8 pad0[0xD4];
    u16 countsD4[6];
    u16 countsE0[6];
    u16 countsEC[6];
    u16 valuesF8[6];
    u16 values104[6];
    u16 values110[6];
    u16 *ptrs11C[6];
    u16 *ptrs134[6];
    u16 *ptrs14C[6];
    u8 pad164[0x28];
} Fn14270CEntry;
typedef struct Fn14270CData {
    u8 pad0[8];
    u16 *streams[1];
} Fn14270CData;
typedef struct Fn14270CObject {
    u16 count;
    u16 flags;
    u8 pad4[4];
    Fn14270CEntry *entries;
    u8 padC[0x18];
    Fn14270CData *data;
    f32 value28, value2C, value30, value34, value38;
    u8 pad3C[4];
    u16 value40, value42, value44, value46;
    u8 pad48[4];
    f32 value4C, value50;
    u16 value54;
} Fn14270CObject;
typedef struct Fn14270CParams {
    u16 value0, value2, value4, value6;
} Fn14270CParams;

void fn_1_4270C(struct Fn142AD0Object *arg0, void *arg1, u32 index) {
    Fn14270CObject *object = (Fn14270CObject *)arg0;
    Fn14270CParams *params = (Fn14270CParams *)arg1;
    u16 *data;
    u32 count;
    u32 i;
    u32 offset;
    u32 j;
    u16 flags;
    Sig_fn_1_431B8_Fn1431B8Object *entry;

    data = object->data->streams[(u16)index];
    object->value28 = lbl_1_rodata_F54;
    object->value2C = lbl_1_rodata_F54;
    object->flags &= 0x30A;
    object->value30 = lbl_1_rodata_F54;
    object->value34 = lbl_1_rodata_F54;
    object->value38 = lbl_1_rodata_F54;
    if (params != 0) {
        if (object->value44 >= params->value4)
            object->value44 = params->value4;
        else
            object->value44 = data[0];
        object->value42 = params->value2;
        object->value46 = params->value6;
        object->value54 = 0;
    } else {
        object->value44 = data[0];
        object->value42 = 0;
        object->value46 = 0;
        object->value54 = 0;
    }
    object->value40 = 0;
    object->value50 = (f32)(u32)data[0];
    object->value4C = (f32)(u32)object->value42;
    count = data[1];
    if (object->count < count)
        count = object->count;
    offset = 0;
    data += 2;
    for (i = 0; i < count; i++) {
        flags = data[0];
        data += 2;
        for (j = 0; j < 3; j++) {
            if (flags & 1) {
                object->entries[i].countsD4[j] = *data++;
                object->entries[i].ptrs11C[j] = data + 1;
                data += object->entries[i].countsD4[j] * 8;
                data++;
            } else {
                object->entries[i].countsD4[j] = 0;
                object->entries[i].ptrs11C[j] = 0;
            }
            object->entries[i].valuesF8[j] = 0;
            flags >>= 1;
        }
        for (j = 0; j < 3; j++) {
            if (flags & 1) {
                object->entries[i].countsE0[j] = *data++;
                object->entries[i].ptrs134[j] = data + 1;
                data += object->entries[i].countsE0[j] * 8;
                data++;
            } else {
                object->entries[i].countsE0[j] = 0;
                object->entries[i].ptrs134[j] = 0;
            }
            object->entries[i].values104[j] = 0;
            flags >>= 1;
        }
        for (j = 0; j < 3; j++) {
            if (flags & 1) {
                object->entries[i].countsEC[j] = *data++;
                object->entries[i].ptrs14C[j] = data + 1;
                data += object->entries[i].countsEC[j] * 8;
                data++;
            } else {
                object->entries[i].countsEC[j] = 0;
                object->entries[i].ptrs14C[j] = 0;
            }
            object->entries[i].values110[j] = 0;
            flags >>= 1;
        }
        offset += 0x18C;
    }
    i = 0;
    offset = 0;
    for (; i < object->count; i++) {
        entry = (Sig_fn_1_431B8_Fn1431B8Object *)((u8 *)object->entries + offset);
        if ((entry->flags & 1) && *(u16 *)((u8 *)entry + 0xEC) == 0
            && *(u16 *)((u8 *)entry + 0xEE) == 0 && *(u16 *)((u8 *)entry + 0xF0) == 0) {
            if (fn_1_431B8((Sig_fn_1_431B8_Fn1431B8Object *)object->entries, entry))
                entry->flags |= 0x100;
        }
        offset += 0x18C;
    }
}
/* fzgx:end fn_1_4270C */

/* fzgx:begin fn_1_42AD0 */
static inline void fn_1_42AD0_save_keys(Fn142AD0Entry *entry, s32 k) {
    entry->keys[0][1][k] = entry->keys[0][0][k];
    entry->keys[1][1][k] = entry->keys[1][0][k];
    entry->keys[2][1][k] = entry->keys[2][0][k];
    entry->keysF[0][1][k] = entry->keysF[0][0][k];
    entry->keysF[1][1][k] = entry->keysF[1][0][k];
    entry->keysF[2][1][k] = entry->keysF[2][0][k];
    entry->keys[3][1][k] = entry->keys[3][0][k];
    entry->keys[4][1][k] = entry->keys[4][0][k];
    entry->keys[5][1][k] = entry->keys[5][0][k];
}

static inline void fn_1_42AD0_reset_entry(Fn142AD0Entry *entry) {
    lbl_8006DBAC(entry->value88);
    fn_8006E5FC( (f32 *)(void *)(entry->quat));
    entry->value174 = entry->sourceB8;
    entry->value17C = entry->sourceC0;
    entry->value180 = entry->sourceC4;
    entry->value188 = entry->sourceCC;
}

void fn_1_42AD0(Fn142AD0Object *object, void *arg1, u32 arg2, u16 arg3, u16 arg4) {
    f32 ratio;
    f32 span;
    s32 i;
    u32 offset;
    s32 j;
    Fn142AD0Entry *entry;
    f32 start;
    f32 newSpan;

    if (arg3 == 0 || (object->flags & 0x100)) {
        fn_1_4270C(object, arg1, arg2);
        return;
    }

    start = (f32)object->cur.value1;
    span = (f32)object->cur.value2 - start;
    ratio = (object->cur.value5 - start) / span;
    fn_1_433A4( (Fn1433A4Object *)(Fn142AD0Key *)(&object->prev), (Fn1433A4Object *)(Fn142AD0Key *)(&object->cur));

    if (arg4 & 2) {
        for (i = 0; i < object->count; i++) {
            entry = (Fn142AD0Entry *)((u8 *)object->entries + i * 0x18c);
            fn_1_42AD0_save_keys(entry, 0);
            fn_1_42AD0_save_keys(entry, 1);
            fn_1_42AD0_save_keys(entry, 2);
        }
    } else {
        for (i = 0; i < object->count; i++) {
            entry = &object->entries[i];
            fn_1_42AD0_reset_entry(entry);
        }
    }

    fn_1_4270C(object, arg1, arg2);
    newSpan = (f32)(object->cur.value2 - object->cur.value1);
    if (arg4 & 2) {
        object->flags |= 1;
        object->prev.value4 = object->prev.value4 * (span / newSpan);
    }
    if (arg4 & 0x20) {
        object->flags |= 0x400;
    }
    if (arg4 & 0x80) {
        object->flags |= 0x800;
    }
    if (arg4 & 0x40) {
        object->flags |= 0x200;
    }
    if (arg4 & 1) {
        object->cur.value5 = (f32)object->cur.value1 + (f32)(newSpan * ratio);
    }
    if (arg4 & 4) {
        object->flags |= 0x20;
    }
    if (arg4 & 8) {
        object->flags |= 0x40;
    }
    if (arg4 & 0x10) {
        object->flags |= 0x80;
    }
    object->value2C = (f32)arg3;
    object->value30 = object->entries->x;
    object->value34 = object->entries->y;
    object->value38 = object->entries->z;
}
/* fzgx:end fn_1_42AD0 */

/* fzgx:begin fn_1_42E74 */
void fn_1_42E74(Fn142E74Object *object) {
    s32 i;
    Fn142E74Entry *entry;

    lbl_8006DAEC();
    if (object->flags & 1) {
        for (i = 0; i < object->count; i++) {
            fn_1_438AC(object, (Fn142E74Entry *)((u8 *)object->entries + i * 0x18c), 1);
        }

        for (i = 0; i < object->count; i++) {
            entry = (Fn142E74Entry *)((u8 *)object->entries + i * 0x18c);
            lbl_8006DBAC((u8 *)entry + 0x88);
            fn_8006E5FC( (f32 *)(void *)((u8 *)entry + 0x164));
            entry->value174 = entry->sourceB8;
            entry->value17C = entry->sourceC0;
            entry->value180 = entry->sourceC4;
            entry->value188 = entry->sourceCC;
        }
    }

    for (i = 0; i < object->count; i++) {
        fn_1_438AC(object, (Fn142E74Entry *)((u8 *)object->entries + i * 0x18c), 0);
    }
    object->value0 = *(f32 *)((u8 *)object->entries + 0x94);
    object->value1 = *(f32 *)((u8 *)object->entries + 0xa4);
    object->value2 = *(f32 *)((u8 *)object->entries + 0xb4);
    fn_1_433E0( (Fn1433E0Object *)(Fn142E74Object *)(object));
    lbl_8006DB30();
    if (!(object->flags & 0x10)) {
        fn_1_4300C( (Fn14300CObject *)(Fn142E74Object *)(object));
    }
    if (object->flags40 & 2) {
        object->flags |= 4;
    } else {
        object->flags &= ~4;
    }
    object->flags &= ~0x100;
}
/* fzgx:end fn_1_42E74 */

/* fzgx:begin fn_1_4300C */
void fn_1_4300C(Fn14300CObject *object) {
    fn_1_43264((u8 *)object + 0x40, object->value);
    if (object->flags & 1) {
        fn_1_43264((u8 *)object + 0x58, object->value);
    }
}
/* fzgx:end fn_1_4300C */

/* fzgx:begin fn_1_43058 */
typedef struct Fn143058Entry {
    u8 pad0[0x94];
    f32 value0;
    u8 pad98[0x0C];
    f32 value1;
    u8 padA8[0x0C];
    f32 value2;
} Fn143058Entry;



void fn_1_43058(Fn143058Object *object, void *arg2, void *arg3, f32 value) {
    u32 offset;
    s32 i;

    lbl_8006DAEC();
    i = 0;
    offset = 0;
    for (; i < object->count; i++) {
        fn_1_43E08(object, object->entries + offset, arg2, arg3, value);
        offset += 0x18c;
    }
    object->value0 = ((Fn143058Entry *)object->entries)->value0;
    object->value1 = ((Fn143058Entry *)object->entries)->value1;
    object->value2 = ((Fn143058Entry *)object->entries)->value2;
    fn_1_433E0( (Fn1433E0Object *)(Fn143058Object *)(object));
    lbl_8006DB30();
    object->flags &= ~0x100;
}
/* fzgx:end fn_1_43058 */

/* fzgx:begin fn_1_43120 */
typedef struct Fn143120Entry {
    u8 pad0[0x88];
    u8 value0[8];
    f32 x;
    u8 pad94[0x0c];
    f32 y;
    u8 padA4[0x0c];
    f32 z;
} Fn143120Entry;

typedef struct Fn143120Object {
    u8 pad0[8];
    Fn143120Entry *entries;
} Fn143120Object;

void fn_1_43120(Fn143120Object *object, u32 index, f32 *vector) {
    Fn143120Entry *entry;
    f32 delta[3];

    entry = (Fn143120Entry *)((u8 *)object->entries + (index & 0xffff) * 0x18c);
    lbl_8006DAEC();
    delta[0] = vector[0] - entry->x;
    delta[1] = vector[1] - entry->y;
    delta[2] = vector[2] - entry->z;
    lbl_8006D668(delta);
    lbl_8006DBAC(entry->value0);
    fn_1_449A8(delta);
    lbl_8006DB74(entry->value0);
    lbl_8006DB30();
}
/* fzgx:end fn_1_43120 */

/* fzgx:begin fn_1_431B8 */
typedef enum Fn1431B8Index {
    FN1431B8_INVALID = -1
} Fn1431B8Index;

typedef struct Fn1431B8Object {
    u8 pad0[4];
    u16 flags;
    u16 index;
    u8 pad8[0xD8];
    u16 value0;
    u16 value1;
    u16 value2;
} Fn1431B8Object;

s32 fn_1_431B8(Fn1431B8Object *base, Fn1431B8Object *object) {
    Fn1431B8Object *entry;
    s32 count;

    entry = (Fn1431B8Object *)((u8 *)base + object->index * 0x18c);
    count = 0;
    while (!(entry->flags & 2)) {
        if (count == 2) {
            // The retail loop shares one exit for both termination checks.
            goto done;
        }
        if (entry->index == FN1431B8_INVALID) {
            // The retail loop shares one exit for both termination checks.
            goto done;
        }
        count++;
        if (entry->value0 != 0 || entry->value1 != 0 || entry->value2 != 0) {
            return 1;
        }
        entry = (Fn1431B8Object *)((u8 *)base + entry->index * 0x18c);
    }
done:
    return 0;
}
/* fzgx:end fn_1_431B8 */

/* fzgx:begin fn_1_4322C */
struct fn_1_4322C_Arg0 {
    u16 unk_0;
    u16 unk_2;
    u16 unk_4;
    u16 unk_6;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
};

void fn_1_4322C(struct fn_1_4322C_Arg0 *arg0) {
    const f32 *value;
    f32 v0;
    u16 zero;

    value = &lbl_1_rodata_F50;
    zero = 0;
    arg0->unk_0 = zero;
    v0 = *value;
    arg0->unk_8 = v0;
    arg0->unk_C = lbl_1_rodata_F54;
    arg0->unk_10 = lbl_1_rodata_F54;
    arg0->unk_2 = zero;
    arg0->unk_4 = zero;
    arg0->unk_6 = zero;
}
/* fzgx:end fn_1_4322C */

/* fzgx:begin fn_1_433A4 */
void fn_1_433A4(Fn1433A4Object *dst, Fn1433A4Object *src) {
    dst->value0 = src->value0;
    dst->value5 = src->value5;
    dst->value6 = src->value6;
    dst->value4 = src->value4;
    dst->value1 = src->value1;
    dst->value3 = src->value3;
    dst->value2 = src->value2;
}
/* fzgx:end fn_1_433A4 */

/* fzgx:begin fn_1_433E0 */
// Matrix A lives at the start of the locked-cache window.
#define MTXA ((f32 *)(LC_BASE + 0x0))

static inline void mtxA_clear_translation(void) {
    f32 *m = MTXA;
    m[3] = lbl_1_rodata_F54;
    m[7] = lbl_1_rodata_F54;
    m[11] = lbl_1_rodata_F54;
}

#pragma opt_propagation off
void fn_1_433E0(Fn1433E0Object *object) {
    f32 *mtxA;
    Fn1433E0Entry *entry;
    Fn1433E0Entry *entries;
    s32 i;
    Fn1433E0Entry *parent;
    f32 t;
    Fn1433E0Vec tmp;
    u8 mtx[0x30];
    Fn1433E0Vec vec;
    Fn1433E0Quat q1;
    Fn1433E0Quat q0;
    f32 base;
    f32 z;
    f32 y;
    f32 x;

    if (object->frame < object->duration) {
        t = object->frame / object->duration;
        if (object->flags & 0xC00) {
            t = lbl_8006D188((s32)(lbl_1_rodata_F68 * (lbl_1_rodata_F6C * t)));
            if (object->flags & 0x800) {
                t = t * t;
            }
        }
        object->frame = object->frame + lbl_1_rodata_F50;
    } else {
        t = lbl_1_rodata_F50;
        object->frame = lbl_1_rodata_F54;
        object->duration = lbl_1_rodata_F54;
        object->flags &= ~1;
    }

    entries = object->entries;
    entry = entries;
    for (i = 0; i < object->count; i++) {
        parent = NULL;
        if (i == 0) {
            vec.x = object->offset.x * object->scale.x;
            vec.y = object->offset.y * object->scale.y;
            vec.z = object->offset.z * object->scale.z;
            if (!(object->flags & 0x20)) {
                base = object->prev.x;
                vec.x = base + (f32)(t * (vec.x - base));
            }
            if (!(object->flags & 0x40)) {
                base = object->prev.y;
                vec.y = base + (f32)(t * (vec.y - base));
            }
            if (!(object->flags & 0x80)) {
                base = object->prev.z;
                vec.z = base + (f32)(t * (vec.z - base));
            }
        } else {
            if (entry->parent == 0xFFFF) {
                lbl_8006D758();
            } else {
                parent = (Fn1433E0Entry *)((u8 *)entries + entry->parent * 0x18c);
                lbl_8006DBAC(parent->mtx);
            }
            if (entry->flags & 0x11) {
                base = entry->value14 * object->scale.x;
                vec.y = lbl_1_rodata_F54;
                vec.x = base;
                vec.z = lbl_1_rodata_F54;
                if (object->flags & 8) {
                    vec.x = base * entry->value24;
                }
            } else {
                if (object->flags & 8) {
                    tmp = entry->offset18;
                } else {
                    tmp = entry->offsetC4;
                }
                vec = tmp;
                if (t < lbl_1_rodata_F50 && (entry->flags & 0x40)) {
                    base = entry->value180.x * (entry->value174.x / entry->scale.x);
                    vec.x = base + (f32)(t * (vec.x - base));
                    base = entry->value180.y * (entry->value174.y / entry->scale.y);
                    vec.y = base + (f32)(t * (vec.y - base));
                    base = entry->value180.z * (entry->value174.z / entry->scale.z);
                    vec.z = base + (f32)(t * (vec.z - base));
                }
            }
            lbl_8006E1B0(&vec, &vec);
        }

        entry->scale.x = entry->scale.x * object->scale.x;
        entry->scale.y = entry->scale.y * object->scale.y;
        entry->scale.z = entry->scale.z * object->scale.z;

        if (t < lbl_1_rodata_F50) {
            if ((object->flags & 0x200) && parent != NULL && entry->parent != 0) {
                mathutil_mtxA_from_quat(&entry->quat);
                lbl_8006DB74(mtx);
                mathutil_mtxA_from_quat(&parent->quat);
                lbl_8006DD7C();
                lbl_8006DFC4(mtx);
                fn_8006E5FC( (f32 *)(void *)(&q0));
                lbl_8006DBAC(parent->mtx);
                mtxA_clear_translation();
                lbl_8006DD7C();
                lbl_8006DFC4(entry->mtx);
                mtxA_clear_translation();
                fn_8006E5FC( (f32 *)(void *)(&q1));
                fn_8006E8DC(&q1);
                fn_8006E8DC(&q0);
                fn_8006EB4C(&q1, &q0, &q1, t);
                fn_8006E8DC(&q1);
                mathutil_mtxA_from_quat(&q1);
                lbl_8006DB74(mtx);
                lbl_8006DBAC(parent->mtx);
                mtxA_clear_translation();
                lbl_8006DFC4(mtx);
            } else {
                lbl_8006DBAC(entry->mtx);
                fn_8006E5FC( (f32 *)(void *)(&q1));
                fn_8006EB4C(&q1, &entry->quat, &q1, t);
                mathutil_mtxA_from_quat(&q1);
            }
        } else {
            lbl_8006DBAC(entry->mtx);
        }

        x = vec.x;
        y = vec.y;
        z = vec.z;
        mtxA = MTXA;
        mtxA[3] = x;
        mtxA[7] = y;
        mtxA[11] = z;
        lbl_8006E15C(entry->scale.x, entry->scale.y, entry->scale.z);
        lbl_8006DB74(entry->mtx);
        entry++;
    }
}
#pragma opt_propagation reset
/* fzgx:end fn_1_433E0 */

/* fzgx:begin fn_1_451D4 */
void fn_1_451D4(void) {
    lbl_1_bss_384CC = 0;
}
/* fzgx:end fn_1_451D4 */
