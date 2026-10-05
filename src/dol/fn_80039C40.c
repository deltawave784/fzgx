#include "types.h"

/* JPEG frame header (SOF) component descriptor. */
struct fn_80039C40_Comp {
    u8 id;
    u8 h;
    u8 v;
    u8 tq;
    u8 pad_4[0x4];
    u32 unk_8;
    u32 unk_C;
    u8 pad_10[0x20];
};

struct fn_80039C40_Dec {
    u8 pad_0[0x400];
    u8 *ptr;
    u8 pad_404[0x4];
    u16 width;
    u16 height;
    u8 pad_40C[0xE];
    u8 hmax;
    u8 vmax;
    u8 ncomp;
    u8 pad_41D[0x2A3];
    struct fn_80039C40_Comp comp[3];
    u8 pad_750[0x58];
    u16 unk_7A8;
};

s32 fn_80039C40(struct fn_80039C40_Dec *d, u8 n) {
    u8 i;
    s32 b;
    s32 rows;
    s32 t;
    s32 mcu;
    s32 h;

    d->ptr += 2;
    if (*d->ptr++ != 8) {
        return 4;
    }
    d->height = (d->ptr[0] << 8) | d->ptr[1];
    d->ptr += 2;
    d->width = (d->ptr[0] << 8) | d->ptr[1];
    d->ptr += 2;
    d->ncomp = *d->ptr++;
    if (d->ncomp != 3 && d->ncomp != 1) {
        return 6;
    }
    for (i = 0; i < d->ncomp; i++) {
        d->comp[i].id = *d->ptr++;
        b = *d->ptr++;
        d->comp[i].h = b >> 4;
        d->comp[i].v = b & 0xF;
        d->comp[i].tq = *d->ptr++;
    }
    d->hmax = 1;
    d->vmax = 1;
    for (i = 0; i < d->ncomp; i++) {
        struct fn_80039C40_Comp *c = &d->comp[i];
        d->hmax = (d->hmax > c->h) ? d->hmax : c->h;
        d->vmax = (d->vmax > c->v) ? d->vmax : c->v;
    }
    h = d->height;
    mcu = d->vmax * 8;
    /* ceil(a / b) spelled as (b + a - 1) / b with the sum held first */
    t = mcu + h;
    rows = (t - 1) / mcu;
    t = rows + h;
    t = (t - 1) / rows;
    d->unk_7A8 = t;
    for (n = 0; n < d->ncomp; n++) {
        t = d->hmax + d->width * d->comp[n].h;
        t = (t - 1) / d->hmax;
        d->comp[n].unk_8 = t;
        t = d->vmax + d->height * d->comp[n].v;
        t = (t - 1) / d->vmax;
        d->comp[n].unk_C = t;
    }
    return 0;
}
