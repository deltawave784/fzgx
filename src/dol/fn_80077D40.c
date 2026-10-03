#include "types.h"

typedef u8 Sig_GXGetTexBufferSize_GXBool;

struct fn_80077D40_Entry {
    u32 flags;
    u32 unk_4;
    u16 w;
    u16 h;
    u16 lod;
};

struct fn_80077D40_Arg0 {
    u32 count;
    u8 *entries;
};

extern u32 fn_800717BC(u32, u32);
extern u32 GXGetTexBufferSize(u16, u16, u32, Sig_GXGetTexBufferSize_GXBool, u8);

u32 fn_80077D40(struct fn_80077D40_Arg0 *arg0) {
    u32 off;
    u32 i;
    u32 total;
    u32 lod;
    struct fn_80077D40_Entry *e;
    u32 l;

    total = 0;
    i = 0;
    off = 0;
    while (i < arg0->count) {
        e = (struct fn_80077D40_Entry *)(arg0->entries + off);
        if ((e->flags & 0x100) == 0) {
            lod = fn_800717BC(e->w, e->h);
            if ((lod + 0x10000) == 0xFFFF) {
                lod = 0;
            }
            l = e->lod;
            if ((s32)l != -1 && l < lod) {
                lod = l;
            }
            total += GXGetTexBufferSize(e->w, e->h, e->flags & 0x1F, lod != 0, lod);
        }
        off += 0x10;
        i++;
    }
    return total;
}
