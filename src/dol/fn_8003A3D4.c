#include "types.h"

struct fn_8003A3D4_Comp {
    u8 id, h, v, tq;
    u8 dc, ac;
    u8 pad6[2];
    u32 width;
    u32 height;
    u8 *data;
    u8 pad14[0x1C];
};
struct fn_8003A3D4_Dec {
    u8 pad0[0x400];
    u8 *ptr;
    u8 pad404[0x14];
    u8 tables;
    u8 pad419;
    u8 hmax;
    u8 vmax;
    u8 ncomp;
    u8 pad41D[0x2A3];
    struct fn_8003A3D4_Comp comp[3];
    u8 pad750[0x64];
    u8 *data;
};
extern s32 fn_8003A91C(struct fn_8003A3D4_Dec *);

s32 fn_8003A3D4(struct fn_8003A3D4_Dec *d) {
    u8 n;
    u8 i;
    s32 b;
    u16 width;
    u16 size;
    d->ptr += 2;
    n = *d->ptr++;
    if (n != d->ncomp) return 6;
    for (i = 0; i < n; i++) {
        d->ptr++;
        b = *d->ptr++;
        d->comp[i].dc = b >> 4;
        d->comp[i].ac = b & 15;
        if (!(d->tables & (1 << (b >> 4)))) return 9;
        if (!(d->tables & (1 << ((b & 15) + 1)))) return 9;
        width = d->comp[i].width;
        size = 16 >> (d->vmax - d->comp[i].v);
        d->comp[i].data = d->data;
        size = (u16)size;
        width = (u16)width;
        d->data += width * size;
    }
    d->ptr += 3;
    return fn_8003A91C(d);
}
