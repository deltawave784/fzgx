#include "types.h"
#include "dol/globals.h"

typedef struct {
    u8 pad00[0x13];
    u8 unk13;
    u8 pad14[0x8];
    u32 unk1C;
} Fn8005C298Slot;

typedef struct {
    u8 pad00[0x28];
    u16 unk28;
    u16 unk2A;
} Fn8005C298Param;

typedef struct {
    u8 pad00[0xd];
    s8 unkD;
    u8 pad0E;
    s8 unkF;
} Fn8005C298Input;

typedef struct {
    u8 pad00[0x2];
    u8 slot;
    u8 pad03[0x11];
    s32 unk14;
    u8 pad18[0x4];
    Fn8005C298Param *param;
    Fn8005C298Input *input;
    u8 pad24[0x60];
    s32 unk84;
    u8 pad88[0x60];
    s32 unkE8;
    u8 padEC[0x28];
    s32 unk114;
} Fn8005C298Entry;

#define STATE lbl_801A6C80
#define ENTRY_AT(base, id) (&((Fn8005C298Entry *)(base)->unk_1408)[id])
#define SLOT_AT(base, s) (&((Fn8005C298Slot *)(base)->unk_588)[(u8)(s)])
#define ENTRY(id) ENTRY_AT(STATE, id)
#define SLOT_INDEX(s) SLOT_AT(STATE, s)
#define SLOT(id) SLOT_INDEX(ENTRY(id)->slot)

void fn_8005C298(s32 id, u8 mode) {
    Fn8005C298Param *param;
    s8 v;
    s32 t;
    u8 s;
    Fn8005C298Slot *slot;
    Obj_801A6C80_Target *state;
    struct { Fn8005C298Input *ptr; } in;

    state = STATE;
    slot = SLOT_AT(state, ENTRY_AT(state, id)->slot);
    if (slot->unk1C == 0) {
        return;
    }
    in.ptr = ENTRY_AT(state, id)->input;
    param = ENTRY_AT(state, id)->param;
    if (mode != 1) {
        return;
    }

    v = in.ptr->unkD;
    if (v > 0) {
        t = (v + 1) * 1200;
        t >>= 7;
        t *= slot->unk13;
        t >>= 7;
        t += param->unk28;
        if (t > 1200) {
            t = 1200;
        }
    } else if (v < 0) {
        t = (s32)__fabs((f64)v);
        t *= 1200;
        t >>= 7;
        t *= slot->unk13;
        t >>= 7;
        t = param->unk28 - t;
        if (t < 0) {
            t = 0;
        }
    } else {
        t = param->unk28;
    }
    ENTRY(id)->unkE8 = t << 16;

    state = STATE;
    s = ENTRY_AT(state, id)->slot;
    v = in.ptr->unkF;
    if (v > 0) {
        t = (v + 1) * 120;
        t >>= 7;
        t *= SLOT_AT(state, s)->unk13;
        t >>= 7;
        t = param->unk2A + t;
        if (t > 120) {
            t = 120;
        }
    } else if (v < 0) {
        t = (s32)__fabs((f64)v);
        t *= 120;
        t >>= 7;
        t *= SLOT_AT(state, s)->unk13;
        t >>= 7;
        t = param->unk2A - t;
        if (t < 0) {
            t = 0;
        }
    } else {
        t = param->unk2A;
    }
    ENTRY(id)->unk114 = t << 16;
    ENTRY(id)->unk84 = (ENTRY(id)->unk14 - t) << 16;
}
