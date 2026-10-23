#include "dolphin/types.h"
#include "dolphin/gx.h"

typedef struct GXColorLocal {
    u8 r, g, b, a;
} GXColorLocal;

typedef struct GXData {
    u16 pad;
    u16 bpSentNot;
} GXData;
extern GXData *gx;
#define GX_FIFO GXWGFifo

#define SET_REG_FIELD(reg, size, shift, val) \
    ((reg) = ((u32)(reg) & ~(((1 << (size)) - 1) << (shift))) | ((u32)(val) << (shift)))

void fn_800371F8(u32 id, GXColorLocal color)
{
    u32 regRA = 0;
    u32 regBG = 0;

    SET_REG_FIELD(regRA, 11, 0, color.r);
    SET_REG_FIELD(regRA, 11, 12, color.a);
    SET_REG_FIELD(regRA, 8, 24, 0xE0 + id * 2);
    SET_REG_FIELD(regBG, 11, 0, color.b);
    SET_REG_FIELD(regBG, 11, 12, color.g);
    SET_REG_FIELD(regBG, 8, 24, 0xE1 + id * 2);
    GX_FIFO.u8 = 0x61;
    GX_FIFO.u32 = regRA;
    GX_FIFO.u8 = 0x61;
    GX_FIFO.u32 = regBG;
    GX_FIFO.u8 = 0x61;
    GX_FIFO.u32 = regBG;
    GX_FIFO.u8 = 0x61;
    GX_FIFO.u32 = regBG;
    gx->bpSentNot = 0;
}
