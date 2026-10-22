#include "dolphin/types.h"
#include "dolphin/gx.h"
#define __wgPipe GXWGFifo

typedef struct GXColorS10 {
    s16 r, g, b, a;
} GXColorS10;

typedef struct GXData {
    u16 pad;
    u16 bpSentNot;
} GXData;
extern GXData *gx;

void fn_8003726C(u32 id, GXColorS10 color)
{
    u32 regRA = 0;
    u32 regBG = 0;
    regRA = (regRA & ~0x7FF) | (color.r & 0x7FF);
    regRA = (regRA & ~0x7FF000) | ((color.a & 0x7FF) << 12);
    regRA = (regRA & ~0xFF000000) | ((0xE0 + id * 2) << 24);
    regBG = (regBG & ~0x7FF) | (color.b & 0x7FF);
    regBG = (regBG & ~0x7FF000) | ((color.g & 0x7FF) << 12);
    regBG = (regBG & ~0xFF000000) | ((0xE1 + id * 2) << 24);
    __wgPipe.u8 = 0x61;
    __wgPipe.u32 = regRA;
    __wgPipe.u8 = 0x61;
    __wgPipe.u32 = regBG;
    __wgPipe.u8 = 0x61;
    __wgPipe.u32 = regBG;
    __wgPipe.u8 = 0x61;
    __wgPipe.u32 = regBG;
    gx->bpSentNot = 0;
}
