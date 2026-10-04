#include "types.h"

typedef struct Fn8005FCD8Entry {
    u8 state;
    u8 unk_1;
    u8 _pad2[7];
    u8 unk_9;
    u8 unk_a;
    u8 _padb[0xd];
    u32 unk_18;
    u32 _pad1c;
    u32 _pad20;
    u32 _pad24;
    u32 _pad28;
    void *object;
    u8 node[0xe8];
} Fn8005FCD8Entry;

typedef struct Fn8005FCD8Data {
    u8 _pad0[0x1408];
    Fn8005FCD8Entry entries[0x40];
} Fn8005FCD8Data;

extern Fn8005FCD8Data *lbl_801A6C80;
extern void fn_80020ABC(void *);
extern u32 fn_80026D70(void *);
extern void fn_80023168(void *, u16);
extern void fn_80028424(void *);
extern void fn_80060BDC(u32);

void fn_8005FCD8(u32 index) {
    if (lbl_801A6C80->entries[index].state != 0xff) {
        fn_80023168(lbl_801A6C80->entries[index].object, 0);
        fn_80026D70(lbl_801A6C80->entries[index].object);
        fn_80020ABC(lbl_801A6C80->entries[index].object);
        lbl_801A6C80->entries[index].object = 0;
        if (lbl_801A6C80->entries[index].state == 3) {
            fn_80060BDC(index);
        } else {
            fn_80028424(lbl_801A6C80->entries[index].node);
        }
        lbl_801A6C80->entries[index].state = 0xff;
        lbl_801A6C80->entries[index].unk_18 = 0;
        lbl_801A6C80->entries[index].unk_1 = 0;
        if (lbl_801A6C80->entries[index].unk_9 == index) {
            lbl_801A6C80->entries[index].unk_9 = 0xff;
        } else if (lbl_801A6C80->entries[index].unk_a == index) {
            lbl_801A6C80->entries[index].unk_a = 0xff;
        }
    }
}
