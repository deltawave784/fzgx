#include "types.h"

typedef struct { u32 value; } Word;

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    Word unkC;
} Entry;

extern Entry *lbl_801A6C48;
extern Word lbl_801A71B8;

void fn_8003DB54(u32 idx, u32 val4, u32 val5)
{
    Word initial = lbl_801A71B8;

    lbl_801A6C48[(u8)idx].unk0 = val4;
    lbl_801A6C48[(u8)idx].unk4 = val5;
    lbl_801A6C48[(u8)idx].unk8 = 0xffffffffu;
    lbl_801A6C48[(u8)idx].unkC = initial;
}
