#include "types.h"
#include "dol/globals.h"

struct Sig_fn_80020CB0_fn_80020CB0_object {
    struct Sig_fn_80020CB0_fn_80020CB0_object *next;
    struct Sig_fn_80020CB0_fn_80020CB0_object *prev;
    u8 pad_8[4];
    u32 index;
};
extern void fn_80020CB0(struct Sig_fn_80020CB0_fn_80020CB0_object *, u32);

typedef struct Fn8005FBDCRecord {
    u8 pad_0[0x12];
    s16 unk_12;
} Fn8005FBDCRecord;

typedef struct Fn8005FBDCEntry {
    u8 state;
    u8 active;
    u8 pad_2[6];
    u8 count;
    u8 pad_9[5];
    u16 duration;
    s32 step;
    u8 pad_14[8];
    Fn8005FBDCRecord *record;
    u8 pad_20[0xc];
    struct Sig_fn_80020CB0_fn_80020CB0_object *object;
    u8 pad_30[0x84];
    s32 velocity;
    s32 target;
    u8 pad_bc[0x5c];
} Fn8005FBDCEntry;

#define ENTRY(i) (((Fn8005FBDCEntry *)lbl_801A6C80->unk_1408)[i])

void fn_8005FBDC(u32 index) {
    if (ENTRY(index).state != 0xff) {
        ENTRY(index).active = 2;
        if (ENTRY(index).state == 3) {
            ENTRY(index).step = -960 / ENTRY(index).duration;
            if (ENTRY(index).step == 0) {
                ENTRY(index).step = -1;
            }
        } else {
            s16 value = ENTRY(index).record->unk_12;
            if (value != 0) {
                ENTRY(index).velocity = value << 16;
            } else {
                ENTRY(index).velocity = -960 << 16;
            }
            ENTRY(index).target = -960 << 16;
            ENTRY(index).duration = 2;
        }
        {
            Fn8005FBDCEntry *entry = &ENTRY(index);
            struct { u32 value; } count;
            count.value = entry->count;
            if (count.value >= 2 && !(count.value & 0x80)) {
                entry->count = count.value - 1;
                fn_80020CB0(ENTRY(index).object, ENTRY(index).count);
            }
        }
    }
}
