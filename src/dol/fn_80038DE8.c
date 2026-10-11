#include "types.h"
#include "dolphin/gx.h"

#define WGPIPE GXWGFifo

typedef struct GXContext {
    u8 pad_0[0x2];
    u16 bpSentNot;
    u8 pad_4[0x43c - 0x4];
    f32 vpLeft;
    f32 vpTop;
    f32 vpWd;
    f32 vpHt;
    f32 vpNearz;
    f32 vpFarz;
    u8 fgRange;
    u8 pad_455[0x3];
    f32 fgSideX;
} GXContext;

extern GXContext* const gx;
extern void fn_80038878(f32 nearz, f32 sideX); /* __GXSetRange */

/* GXSetViewportJitter */
void fn_80038DE8(f32 left, f32 top, f32 wd, f32 ht, f32 nearz, f32 farz, u32 field) {
    f32 sx, sy, sz;
    f32 ox, oy, oz;
    f32 zmin, zmax;

    if (field == 0) {
        top -= 0.5f;
    }

    sx = wd / 2.0f;
    sy = -ht / 2.0f;
    ox = 342.0f + (left + sx);
    oy = 342.0f + (top + (f32)(ht / 2.0f));

    zmin = nearz * 16777215.0f;
    zmax = farz * 16777215.0f;
    sz = zmax - zmin;
    oz = zmax;

    gx->vpLeft = left;
    gx->vpTop = top;
    gx->vpWd = wd;
    gx->vpHt = ht;
    gx->vpNearz = nearz;
    gx->vpFarz = farz;

    if (gx->fgRange) {
        fn_80038878(nearz, gx->fgSideX);
    }

    WGPIPE.u8 = 0x10;
    WGPIPE.u32 = (5 << 16) | 0x101a;
    WGPIPE.f32 = sx;
    WGPIPE.f32 = sy;
    WGPIPE.f32 = sz;
    WGPIPE.f32 = ox;
    WGPIPE.f32 = oy;
    WGPIPE.f32 = oz;

    gx->bpSentNot = 1;
}
