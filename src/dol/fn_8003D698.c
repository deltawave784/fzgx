#include "types.h"

typedef struct Record {
    u8 pad0[0xC];
    u32 unkC;
    u32 unk10;
    u8 pad14[0x8];
    u32 unk1C;
    u32 unk20;
    u32 unk24;
    u8 pad28[0x8];
    u32 unk30;
    u32 unk34;
    u8 pad38[0x78];
} Record;

typedef struct Entry {
    Record *unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
} Entry;

extern u8 lbl_801A6C30;
extern s32 lbl_801A6C40;
extern u32 lbl_801A6C3C;
/* current record id; reread on every access in retail */
extern volatile u32 lbl_801A6588[2];
extern u32 lbl_801A6C44;
extern Entry *lbl_801A6C4C;
extern s32 lbl_801A6584;

extern void fn_8003E284(void);
extern void fn_8003E13C(void);
extern u32 fn_8000A050(void);
extern u32 fn_8000A040(void);
extern u32 fn_8000A020(void);
extern void fn_8003D588(u32 *, u32);

void fn_8003D698(u32 arg0) {
    u32 id;
    s32 slot;
    u32 t;

    id = arg0 & 0xFFFF;
    if (id < 0xE000 || (s32)((id >> 8) & 0xF) != lbl_801A6C30 || lbl_801A6C40 == 0) {
        if (lbl_801A6C3C != 0) {
            ((void (*)(u32))lbl_801A6C3C)(arg0);
        }
        return;
    }
    if (id >= 0xF000) {
        if (lbl_801A6588[0] == 0xFFFF) {
            fn_8003E284();
            fn_8003E13C();
            return;
        }
        slot = (u8)id;
        if ((u8)lbl_801A6588[0] != slot) {
            slot = (u8)lbl_801A6588[0];
        }
        lbl_801A6C4C[lbl_801A6C44].unk0[slot].unk10 = fn_8000A050();
        lbl_801A6C4C[lbl_801A6C44].unk0[slot].unk24 = fn_8000A040();
        lbl_801A6C4C[lbl_801A6C44].unk0[slot].unk34 = fn_8000A020();
        fn_8003D588((u32 *)&lbl_801A6C4C[lbl_801A6C44].unk0[slot], 1);
        if (lbl_801A6584 >= 0) {
            fn_8003E284();
        }
        lbl_801A6588[0] = 0xFFFF;
        fn_8003E13C();
        return;
    }
    if (lbl_801A6588[0] < 0xFFFF) {
        slot = (u8)lbl_801A6588[0];
        lbl_801A6C4C[lbl_801A6C44].unk0[slot].unk10 = fn_8000A050();
        lbl_801A6C4C[lbl_801A6C44].unk0[slot].unk24 = fn_8000A040();
        lbl_801A6C4C[lbl_801A6C44].unk0[slot].unk34 = fn_8000A020();
        fn_8003D588((u32 *)&lbl_801A6C4C[lbl_801A6C44].unk0[slot], 1);
    } else {
        fn_8003E284();
    }
    lbl_801A6C4C[lbl_801A6C44].unk0[(u8)id].unk20 = fn_8000A040();
    lbl_801A6C4C[lbl_801A6C44].unk0[(u8)id].unk30 = fn_8000A020();
    t = fn_8000A050();
    lbl_801A6C4C[lbl_801A6C44].unk0[(u8)id].unk1C = t;
    lbl_801A6C4C[lbl_801A6C44].unk0[(u8)id].unkC = t;
    fn_8003D588((u32 *)&lbl_801A6C4C[lbl_801A6C44].unk0[(u8)id], 0);
    lbl_801A6588[0] = (u16)arg0;
}
