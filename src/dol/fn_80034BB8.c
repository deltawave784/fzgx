typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct GXS {
    u8 pad[0x1f8];
    volatile u32 cpDst; /* GX register shadow: preserve sequential read/modify/write accesses. */
    volatile u32 cpTex; /* GX register shadow: preserve sequential read/modify/write accesses. */
    u8 cpTexZ;
} GXS;
extern GXS * const gx;
extern void __GetImageTileCount(u32, u16, u16, u32 *, u32 *, u32 *);

void fn_80034BB8(u16 wd, u16 ht, int fmt, u32 mipmap)
{
    u32 rowTiles, colTiles, cmpTiles;
    u32 peTexFmt, peTexFmtH;
    u32 *p, *q;
    volatile u32 pad; /* Reserved stack word. */

    gx->cpTexZ = 0;
    peTexFmt = fmt & 0xF;
    if (fmt == 0x13) {
        peTexFmt = 0xB;
    }
    switch (fmt) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 0x26:
        gx->cpTex = (gx->cpTex & ~0x18000) | 0x18000;
        break;
    default:
        gx->cpTex = (gx->cpTex & ~0x18000) | 0x10000;
        break;
    }
    gx->cpTexZ = (fmt & 0x10) == 0x10;
    peTexFmtH = peTexFmt >> 3;
    peTexFmt = peTexFmt & 7;
    gx->cpTex = (gx->cpTex & ~(1 << 3)) | ((peTexFmtH & 1) << 3);
    __GetImageTileCount(fmt, wd, ht, &rowTiles, &colTiles, &cmpTiles);
    p = &gx->cpDst;
    q = &gx->cpTex;
    *p = 0;
    *p = (*p & ~0x3ff) | (rowTiles * cmpTiles);
    *p = (*p & 0xffffff) | 0x4d000000;
    *q = (*q & ~0x200) | ((mipmap & 0xff) << 9);
    *q = (*q & ~0x70) | (peTexFmt << 4);
}
