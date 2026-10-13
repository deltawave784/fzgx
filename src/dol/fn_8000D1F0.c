#include "dolphin/types.h"
#include "dolphin/hw_regs.h"

/* OSFontHeader (Dolphin OS font) */
typedef struct OSFontHeader {
    u16 fontType;
    u16 firstChar;
    u16 lastChar;
    u16 invalidChar;
    u16 ascent;
    u16 descent;
    u16 width;
    u16 leading;
    u16 cellWidth;
    u16 cellHeight;
    u32 sheetSize;
    u16 sheetFormat;
    u16 sheetColumn;
    u16 sheetRow;
    u16 sheetWidth;
    u16 sheetHeight;
    u16 widthTable;
    u32 sheetImage;
    u32 sheetFullSize;
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
} OSFontHeader;

extern int GetFontCode(u16 code);
extern OSFontHeader *lbl_801A6798; /* FontData */
extern u16 lbl_801A6438;           /* FontEncode */
extern u8 *lbl_801A67A0;           /* WidthTable */
extern s32 lbl_801A67A4;           /* chars per sheet */
extern vu16 __VIRegs[];

static u16 OSGetFontEncode(void)
{
    if (lbl_801A6438 <= 1) {
        return lbl_801A6438;
    }
    switch (__OSTVMode) {
    case 0:
        lbl_801A6438 = (VI_REG_LITERAL(VI_DTV_STAT) & 2) ? 1 : 0;
        break;
    case 1:
    case 2:
    default:
        lbl_801A6438 = 0;
        break;
    }
    return lbl_801A6438;
}

static BOOL IsSjisLeadByte(u8 c)
{
    return (0x81 <= c && c <= 0x9f) || (0xe0 <= c && c <= 0xfc);
}

char *fn_8000D1F0(char *string, void *image, s32 pos, s32 stride, s32 *width)
{
    u16 code;
    u8 *src;
    u8 *dst;
    int fontCode;
    int sheet;
    int numChars;
    int row;
    int column;
    int x;
    int y;
    int offsetSrc;
    int offsetDst;
    u8 *colorIndex;
    u8 *imageSrc;

    code = (u8)*string;
    if (code == 0) {
        return string;
    }
    string++;
    if (OSGetFontEncode() == 1 && IsSjisLeadByte(code) && *string != 0) {
        code = (code << 8) | (u8)*string++;
    }

    colorIndex = &lbl_801A6798->c0;
    fontCode = GetFontCode(code);

    sheet = fontCode / lbl_801A67A4;
    numChars = fontCode - sheet * lbl_801A67A4;
    row = numChars / lbl_801A6798->sheetColumn;
    column = numChars - row * lbl_801A6798->sheetColumn;
    row *= lbl_801A6798->cellHeight;
    column *= lbl_801A6798->cellWidth;
    imageSrc = (u8 *)lbl_801A6798 + lbl_801A6798->sheetImage;
    imageSrc += sheet * lbl_801A6798->sheetSize / 2;

    for (y = 0; y < lbl_801A6798->cellHeight; y++) {
        for (x = 0; x < lbl_801A6798->cellWidth; x++) {
            src = imageSrc + (((lbl_801A6798->sheetWidth / 8) << 5) / 2) * ((row + y) / 8);
            src += ((column + x) / 8) * 16;
            src += ((row + y) % 8) * 2;
            src += ((column + x) % 8) / 4;
            offsetSrc = (column + x) % 4;

            dst = (u8 *)image + ((y / 8) * (((stride * 4) / 8) << 5));
            dst += ((pos + x) / 8) << 5;
            dst += (y % 8) << 2;
            dst += ((pos + x) % 8) / 2;
            offsetDst = (pos + x) % 2;

            *dst |= colorIndex[(*src >> (6 - 2 * offsetSrc)) & 3] & (offsetDst ? 0x0f : 0xf0);
        }
    }

    if (width) {
        *width = lbl_801A67A0[fontCode];
    }
    return string;
}
