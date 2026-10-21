#include "types.h"
#include "dol/globals.h"
#pragma use_lmw_stmw on

extern void fn_8005FBDC(u8 value);
extern void fn_80060C54(u8 level, u8 *script, u8 slot, u32 index);

struct fn_80062360_Entry {
    u8 state;
    u8 active;
    u8 id;
    u8 pad_3[8];
    u8 level;
    u8 count;
    u8 unk_d;
    u8 unk_e;
    u8 unk_f;
    u8 *record;
    u8 data[16][4];
};

extern struct fn_80062360_Entry lbl_80192D68[16];

/* Release the voices held by every step of the slot's current record. */
static void fn_80062360_release(u32 slot) {
    u32 j;
    volatile u8 *script = lbl_80192D68[slot].record; /* retail keeps the record walk (lbz/add) although nothing reads it */

    for (j = 0; (u8)j <= lbl_80192D68[slot].count; j++) {
        if (lbl_80192D68[(u8)slot].data[(u8)j][0] == 1) {
            if (lbl_80192D68[(u8)slot].data[(u8)j][2] != 0xff) {
                fn_8005FBDC(lbl_80192D68[(u8)slot].data[(u8)j][2]);
            }
            if (lbl_80192D68[(u8)slot].data[(u8)j][3] != 0xff) {
                fn_8005FBDC(lbl_80192D68[(u8)slot].data[(u8)j][3]);
            }
            lbl_80192D68[(u8)slot].data[(u8)j][0] = 0;
        }
        script += *script;
    }
}

#pragma opt_propagation off
static u8 *fn_80062360_table(Obj_801A6C80_Target *obj, s32 found) {
    u8 *row = obj->unk_0[found];
    return *(u8 **)(row + 8);
}
#pragma opt_propagation off

/* Step past the first sel+1 record offsets of the table. */
static inline u32 *fn_80062360_skip(u32 *p, u32 sel) {
    s8 k;
    for (k = 0; k <= sel; k++) {
        p++;
    }
    return p;
}

static inline void fn_80062360_apply(u32 slot, u32 level) {
    u32 j;
    u8 *script;
                script = lbl_80192D68[slot].record;
                for (j = 0; (u8)j <= lbl_80192D68[slot].count; j++) {
                    if (script[4] <= level && script[5] >= level && level != 0) {
                        fn_80060C54(level, script, slot, j);
                    } else if (lbl_80192D68[(u8)slot].data[(u8)j][0] == 1) {
                        if (lbl_80192D68[(u8)slot].data[(u8)j][2] != 0xff) {
                            fn_8005FBDC(lbl_80192D68[(u8)slot].data[(u8)j][2]);
                        }
                        if (lbl_80192D68[(u8)slot].data[(u8)j][3] != 0xff) {
                            fn_8005FBDC(lbl_80192D68[(u8)slot].data[(u8)j][3]);
                        }
                        lbl_80192D68[(u8)slot].data[(u8)j][0] = 0;
                    }
                    script += *script;
                }
}

void fn_80062360(u32 slot, u32 sel) {
    u8 *script;
    u32 j;
    s8 found = -1;
    u8 level;
    struct { u8 key; u8 (*value)[16]; } row_cursor;
#define rows row_cursor.value
    s8 i;
    struct { u32 *value; } pointer;
#define p pointer.value
    struct { s8 value; } counter;
#define k counter.value
    u8 *base;
    u8 *table;
    u8 *rec;
    Obj_801A6C80_Target *obj;

    row_cursor.key = 0;
    rows = lbl_801A6C80->unk_0;
    for (i = 0; i < 16; rows++, i++) {
        row_cursor.key = lbl_80192D68[slot].id;
        if (row_cursor.key == (*rows)[0xd]) {
            found = i;
            break;
        }
    }
    if (found != -1) {
        level = lbl_80192D68[slot].level;
        if (level != 0) {
            if (lbl_80192D68[slot].active) {
                fn_80062360_release(slot);
                lbl_80192D68[slot].level = 0;
            } else {
                void (*callback)(s32, u32) = (void (*)(s32, u32))lbl_801A6C80->unk_5B1C;
                if (callback) {
                    callback(-5, lbl_801A6C80->unk_444);
                }
            }
        }

#pragma opt_propagation off
        obj = lbl_801A6C80;
        lbl_80192D68[slot].active = 1;
        base = fn_80062360_table(obj, found);
        table = base + *(s32 *)(base + 0x2c);
        rec = table + *fn_80062360_skip((u32 *)table, sel);
        lbl_80192D68[slot].count = rec[0];
        lbl_80192D68[slot].unk_d = rec[1];
        lbl_80192D68[slot].unk_e = rec[2];
        lbl_80192D68[slot].unk_f = rec[3] + 0x15;
        lbl_80192D68[slot].record = rec + 8;
        lbl_80192D68[slot].state = found;

        if (level != 0) {
            if (lbl_80192D68[slot].active) {
                fn_80062360_apply(slot, level);
                lbl_80192D68[slot].level = level;
            } else {
                void (*callback)(s32, u32) = (void (*)(s32, u32))obj->unk_5B1C;
                if (callback) {
                    callback(-5, obj->unk_444);
                }
            }
        }
    } else {
        void (*callback)(s32, u32) = (void (*)(s32, u32))lbl_801A6C80->unk_5B1C;
        if (callback) {
            callback(-4, lbl_801A6C80->unk_444);
        }
    }
}
