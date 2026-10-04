typedef unsigned int u32;
typedef unsigned char u8;

typedef struct GXData {
    u8 pad0[0x1ec];
    u32 cpDisp;
    u8 pad1[0xc];
    u32 cpTex;
} GXData;

/* GX's data pointer is a const pointer (lives in .sdata2), so stores through it
 * never force a reload of the base. */
extern GXData * const gx;

#define GX_BITFIELD_SET(reg, bit, val) \
    ((reg) = ((reg) & ~(1u << (bit))) | ((u32)(val) << (bit)))

void fn_80034D34(u32 clamp)
{
    GX_BITFIELD_SET(gx->cpDisp, 0, (u8)((clamp & 1) == 1));
    GX_BITFIELD_SET(gx->cpDisp, 1, (u8)((clamp & 2) == 2));
    GX_BITFIELD_SET(gx->cpTex, 0, (u8)((clamp & 1) == 1));
    GX_BITFIELD_SET(gx->cpTex, 1, (u8)((clamp & 2) == 2));
}
