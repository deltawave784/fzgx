#ifndef DOLPHIN_OS_OSCONTEXT_H
#define DOLPHIN_OS_OSCONTEXT_H

#include <dolphin/types.h>
#include "layout_check.h"

typedef struct OSContext {
    u32 gpr[32];
    u32 cr;
    u32 lr;
    u32 ctr;
    u32 xer;
    f64 fpr[32];
    u32 fpscr_pad;
    u32 fpscr;
    u32 srr0;
    u32 srr1;
    u16 mode;
    u16 state;
    u32 gqr[8];
    u32 psf_pad;
    f64 psf[32];
} OSContext;

CHECK_OFFSET(OSContext, cr, 0x80);
CHECK_OFFSET(OSContext, fpr, 0x90);
CHECK_OFFSET(OSContext, srr0, 0x198);
CHECK_OFFSET(OSContext, state, 0x1A2);
CHECK_OFFSET(OSContext, gqr, 0x1A4);
CHECK_OFFSET(OSContext, psf, 0x1C8);
CHECK_SIZE(OSContext, 0x2C8);

void OSSetCurrentContext(OSContext* context);

#endif
