#include "types.h"

typedef struct Ent {
    s32 a;
    s32 b;
    s32 c;
} Ent;

extern Ent *lbl_801A6744;
extern s32 lbl_801A6740;
extern u32 lbl_801A6738;
extern s32 lbl_801A6410;
extern u32 lbl_801A673C;
extern void fn_80009468(void *);

u32 fn_80008EC8(Ent *arg0, u32 arg1, s32 arg2) {
    s32 off;
    s32 size = arg2 * sizeof(Ent);
    s32 i;
    u8 *p;
    u32 end;
    lbl_801A6744 = arg0;
    lbl_801A6740 = arg2;
    for (i = 0; i < lbl_801A6740; i++) {
        Ent *e = (Ent *)((u8 *)lbl_801A6744 + i * sizeof(Ent));
        e->a = -1;
        e->b = e->c = 0;
    }
    p = (u8 *)lbl_801A6744 + size;
    lbl_801A6738 = arg1 & ~0x1F;
    lbl_801A6410 = -1;
    end = ((u32)p + 0x1F) & ~0x1F;
    lbl_801A673C = end;
    fn_80009468(p);
    return end;
}
