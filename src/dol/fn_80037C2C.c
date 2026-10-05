#include "types.h"

#define GX_FIFO_ADDRESS 0xCC008000 // fzgx-allow: A1 hardware FIFO register
// fzgx-allow: S2 hardware FIFO register
#define GXWGFifo8 (*(volatile u8 *)GX_FIFO_ADDRESS)
// fzgx-allow: S2 hardware FIFO register
#define GXWGFifo (*(volatile u32 *)GX_FIFO_ADDRESS)

struct fn_80037C2C_gx_T {
    u8 pad_0[0x2];
    u16 bpSentNot;
    u8 pad_4[0x1D0];
    u32 cmode1;
    u8 pad_1D8[4];
    u32 peCtrl;
    u8 pad_1E0[0x24];
    u32 genMode;
    u8 pad_208[0x2EC];
    u32 dirtyState;
};

/* The GX state pointer never changes, so the compiler keeps one load of it
 * across the field stores. */
extern struct fn_80037C2C_gx_T *const gx;
extern u32 lbl_8012B3E0[8]; /* pixel format -> PE_CTRL format field */

/* GXSetPixelFmt */
void fn_80037C2C(s32 pix_fmt, u32 z_fmt) {
    u32 oldPeCtrl = gx->peCtrl;
    u32 peCtrl;

    gx->peCtrl = (gx->peCtrl & 0xFFFFFFF8) | lbl_8012B3E0[pix_fmt];
    gx->peCtrl = (gx->peCtrl & 0xFFFFFFC7) | (z_fmt << 3);
    peCtrl = gx->peCtrl;
    if (oldPeCtrl != peCtrl) {
        u32 flag;
        GXWGFifo8 = 0x61;
        GXWGFifo = peCtrl;
        if (pix_fmt == 2) {
            flag = 1;
        } else {
            flag = 0;
        }
        gx->genMode = (gx->genMode & 0xFFFFFDFF) | ((flag & 0xFF) << 9);
        gx->dirtyState |= 4;
    }
    if (lbl_8012B3E0[pix_fmt] == 4) {
        gx->cmode1 = (gx->cmode1 & 0xFFFFF9FF) | (((pix_fmt - 4) & 3) << 9);
        gx->cmode1 = (gx->cmode1 & 0x00FFFFFF) | 0x42000000;
        GXWGFifo8 = 0x61;
        GXWGFifo = gx->cmode1;
    }
    gx->bpSentNot = 0;
}
