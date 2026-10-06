#include "types.h"

struct Object { u8 pad_0[6]; u8 unk_6; u8 pad_7[14]; u8 unk_15; };
struct Entry {
    u8 unk_0, unk_1, unk_2, unk_3;
    u8 pad_4[0x14];
    u32 unk_18;
    struct Object *unk_1c;
    u8 pad_20[0xf8];
};
struct State {
    u8 pad_0[0x444];
    u32 unk_444;
    u8 pad_448[0x150];
    struct { u8 pad_0[2]; u8 unk_2; u8 pad_3[0x1d]; } slots[0x40];
    u8 pad_d98[0x670];
    struct Entry entries[0x40];
};
extern struct State *lbl_801A6C80;
extern void fn_8005FBDC(u32);
extern void fn_8005C9D8(u32);
extern void fn_8005FCD8(u32);
extern void fn_8005C478(u32);
extern void fn_8005C298(u32, u32);
extern void fn_8005C7C0(u32);
extern void fn_8005C5C8(u32);

void fn_80064A30(u16 arg0, u32 arg1) {
    u32 i;
    for (i = 0; i < 0x40; i++) {
        if (lbl_801A6C80->entries[i].unk_0 != 0xff &&
            lbl_801A6C80->entries[i].unk_0 != 3 &&
            lbl_801A6C80->entries[i].unk_0 != 4 &&
            (lbl_801A6C80->unk_444 & arg1) == (lbl_801A6C80->entries[i].unk_18 & arg1)) {
            switch (arg0) {
            case 0x8000:
                if (lbl_801A6C80->entries[i].unk_1 == 1 &&
                    (lbl_801A6C80->entries[i].unk_3 & 8) != 8) {
                    if (lbl_801A6C80->entries[i].unk_3 & 1)
                        lbl_801A6C80->entries[i].unk_3 |= 2;
                    else fn_8005FBDC(i);
                }
                break;
            case 0xa001: case 0xa004: case 0xa005:
            case 0xa010: case 0xa011: case 0xa034: case 0xa040:
                fn_8005C9D8(i); break;
            case 0xa002:
                if (lbl_801A6C80->entries[i].unk_0 == 1) fn_8005FCD8(i);
                break;
            case 0xa007: fn_8005C478(i); break;
            case 0xa01c:
                if (lbl_801A6C80->entries[i].unk_0 == 1) fn_8005C9D8(i);
                break;
            case 0xb001: fn_8005C298(i, 1); break;
            case 0xb002: fn_8005C298(i, 2); break;
            case 0xb007: fn_8005C9D8(i); break;
            case 0xb00a:
                if (lbl_801A6C80->entries[i].unk_1c->unk_6 & 0x80) fn_8005C7C0(i);
                break;
            case 0xb00d:
                if (lbl_801A6C80->entries[i].unk_1c->unk_15 != 0) fn_8005C5C8(i);
                break;
            case 0xb040:
                lbl_801A6C80->entries[i].unk_3 &= ~1;
                if (lbl_801A6C80->slots[lbl_801A6C80->entries[i].unk_2].unk_2 != 0)
                    lbl_801A6C80->entries[i].unk_3 |= 1;
                else if (lbl_801A6C80->entries[i].unk_3 & 2) fn_8005FBDC(i);
                break;
            case 0xb078:
                if ((lbl_801A6C80->entries[i].unk_18 & 0x0f000000) ==
                    (lbl_801A6C80->unk_444 & 0x0f000000)) fn_8005FCD8(i);
                break;
            case 0xe000: fn_8005C478(i); break;
            }
        }
    }
}
