#include "types.h"
extern u32 fn_80057728(void);
extern void fn_800576DC(void);
extern u32 lbl_8018B2A4[4097];
extern u8 lbl_80132300[48];
extern u8 lbl_80092330[16];
extern void fn_800586E4(void);
struct Entry {
    void *table;
    s32 used;
    void *info;
    u32 unkC;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 arg0;
    u32 arg1;
    u32 arg2;
    u32 unk28;
    u32 unk2C;
    u32 unk30;
    u32 unk34;
    void (*callback)(void);
    struct Entry *self;
};
struct Entry *fn_80058498(u32 arg0, u32 arg1, u32 arg2) {
    struct Entry *entry;
    s32 i;
    fn_80057728();
    for (i = 0; i < 256; i++) {
        if (((struct Entry *)lbl_8018B2A4)[i].used == 0)
            break;
    }
    if (i == 256) {
        entry = 0;
    } else {
        entry = &((struct Entry *)lbl_8018B2A4)[i];
        entry->used = 1;
        entry->table = lbl_80132300;
        entry->arg0 = arg0;
        entry->arg1 = arg1;
        entry->arg2 = arg2;
        entry->info = lbl_80092330;
        entry->callback = fn_800586E4;
        entry->self = entry;
        fn_80057728();
        entry->unkC = 0;
        entry->unk10 = entry->arg1;
        entry->unk14 = 0;
        entry->unk18 = 0;
        entry->unk28 = 0;
        entry->unk2C = 0;
        entry->unk30 = 0;
        entry->unk34 = 0;
        fn_800576DC();
    }
    fn_800576DC();
    return entry;
}
