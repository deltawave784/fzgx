#include "dolphin/types.h"
#include "dolphin/gx.h"
#define wgPipe GXWGFifo

typedef struct GXKColor {
    u8 r, g, b, a;
} GXKColor;

typedef struct GXStateK {
    u16 pad;
    u16 bpSent;
} GXStateK;
extern GXStateK *gx;

void fn_800372E0(u32 reg, GXKColor color)
{
    u32 ra = 0;
    u32 bg = 0;
    ra = (ra & ~0xff) | color.r;
    ra = (ra & ~0xff000) | (color.a << 12);
    ra = (ra & ~0xf00000) | 0x800000;
    ra = (ra & ~0xff000000) | ((reg * 2 + 0xe0) << 24);
    bg = (bg & ~0xff) | color.b;
    bg = (bg & ~0xff000) | (color.g << 12);
    bg = (bg & ~0xf00000) | 0x800000;
    bg = (bg & ~0xff000000) | ((reg * 2 + 0xe1) << 24);
    wgPipe.u8 = 0x61;
    wgPipe.u32 = ra;
    wgPipe.u8 = 0x61;
    wgPipe.u32 = bg;
    gx->bpSent = 0;
}
