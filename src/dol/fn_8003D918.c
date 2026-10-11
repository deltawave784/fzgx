#include "types.h"

typedef struct Entry {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
} Entry;

typedef void *(*AllocFunc)(u32 size);
typedef void (*FreeFunc)(void *ptr);

extern const char *lbl_801A6580;
extern void OSRegisterVersion(const char *);
extern AllocFunc lbl_801A6C34;
extern FreeFunc lbl_801A6C38;
extern u32 lbl_801A6C58[2];
extern u32 lbl_801A6C54;
extern u32 lbl_801A6C50;
extern Entry *lbl_801A6C4C;
extern Entry *lbl_801A6C48;
extern void fn_8003E9EC(u32);
extern void fn_8003D698(void);
extern void fn_80034378(void (*func)(void));
extern void fn_80039B38(void);

u32 fn_8003D918(u32 num, u32 frames, u32 slots, AllocFunc alloc, FreeFunc free, u32 arg5) {
    u32 total;
    u32 i;

    OSRegisterVersion(lbl_801A6580);
    lbl_801A6C34 = alloc;
    lbl_801A6C38 = free;
    lbl_801A6C58[0] = frames;
    lbl_801A6C54 = slots;
    lbl_801A6C50 = num;
    total = frames * sizeof(Entry) + frames * (num * 0xb0);
    total += slots * sizeof(Entry);
    lbl_801A6C4C = alloc(frames * sizeof(Entry));
    for (i = 0; i < lbl_801A6C58[0]; i++) {
        lbl_801A6C4C[i].unk0 = (u32)lbl_801A6C34(num * 0xb0);
        lbl_801A6C4C[i].unk4 = 0;
    }
    lbl_801A6C48 = lbl_801A6C34(slots * sizeof(Entry));
    for (i = 0; i < slots; i++) {
        lbl_801A6C48[i].unk0 = 0;
        lbl_801A6C48[i].unk8 = -1;
    }
    fn_8003E9EC(arg5);
    fn_80034378(fn_8003D698);
    fn_80039B38();
    return total;
}
