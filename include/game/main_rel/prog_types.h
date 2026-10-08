#ifndef GAME_MAIN_REL_PROG_TYPES_H
#define GAME_MAIN_REL_PROG_TYPES_H

// Types (and the externs that name them) of prog.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).

#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/prog.h"

typedef enum {
    Sig_GXAdjustForOverscan_VI_TVMODE_NTSC_INT = ((((0)) << 2) + ((0))),
    Sig_GXAdjustForOverscan_VI_TVMODE_NTSC_DS = ((((0)) << 2) + ((1))),
    Sig_GXAdjustForOverscan_VI_TVMODE_NTSC_PROG = ((((0)) << 2) + ((2))),
    Sig_GXAdjustForOverscan_VI_TVMODE_NTSC_3D = ((((0)) << 2) + ((3))),
    Sig_GXAdjustForOverscan_VI_TVMODE_PAL_INT = ((((1)) << 2) + ((0))),
    Sig_GXAdjustForOverscan_VI_TVMODE_PAL_DS = ((((1)) << 2) + ((1))),
    Sig_GXAdjustForOverscan_VI_TVMODE_MPAL_INT = ((((2)) << 2) + ((0))),
    Sig_GXAdjustForOverscan_VI_TVMODE_MPAL_DS = ((((2)) << 2) + ((1))),
    Sig_GXAdjustForOverscan_VI_TVMODE_DEBUG_INT = ((((3)) << 2) + ((0))),
    Sig_GXAdjustForOverscan_VI_TVMODE_DEBUG_PAL_INT = ((((4)) << 2) + ((0))),
    Sig_GXAdjustForOverscan_VI_TVMODE_DEBUG_PAL_DS = ((((4)) << 2) + ((1))),
    Sig_GXAdjustForOverscan_VI_TVMODE_EURGB60_INT = ((((5)) << 2) + ((0))),
    Sig_GXAdjustForOverscan_VI_TVMODE_EURGB60_DS = ((((5)) << 2) + ((1))),
    Sig_GXAdjustForOverscan_VI_TVMODE_GCA_INT = ((((6)) << 2) + ((0))),
    Sig_GXAdjustForOverscan_VI_TVMODE_GCA_DS = ((((6)) << 2) + ((1))),
    Sig_GXAdjustForOverscan_VI_TVMODE_GCA_PROG = ((((6)) << 2) + ((2))),
} Sig_GXAdjustForOverscan_VITVMode;

typedef enum {
    Sig_GXAdjustForOverscan_VI_XFBMODE_SF = 0,
    Sig_GXAdjustForOverscan_VI_XFBMODE_DF = 1,
} Sig_GXAdjustForOverscan_VIXFBMode;

typedef struct Sig_GXAdjustForOverscan__GXRenderModeObj {
    Sig_GXAdjustForOverscan_VITVMode viTVmode;
    u16 fbWidth;
    u16 efbHeight;
    u16 xfbHeight;
    u16 viXOrigin;
    u16 viYOrigin;
    u16 viWidth;
    u16 viHeight;
    Sig_GXAdjustForOverscan_VIXFBMode xFBmode;
    u8 field_rendering;
    u8 aa;
    u8 sample_pattern[12][2];
    u8 vfilter[7];
} Sig_GXAdjustForOverscan_GXRenderModeObj;

struct fn_1_A6870_lbl_801A6D30_obj {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
};

struct fn_1_A6870_lbl_801A6D30 {
    struct fn_1_A6870_lbl_801A6D30_obj *unk_0;
};

typedef u8 Sig_fn_80035110_GXBool;
typedef u8 Sig_fn_80034ECC_GXBool;
extern Sig_GXAdjustForOverscan_GXRenderModeObj lbl_8012B030;
extern Sig_GXAdjustForOverscan_GXRenderModeObj lbl_8012AFB8;
extern Sig_GXAdjustForOverscan_GXRenderModeObj lbl_8012B0A8;
extern Sig_GXAdjustForOverscan_GXRenderModeObj lbl_8012B06C;
extern Sig_GXAdjustForOverscan_GXRenderModeObj lbl_8019E150;
extern struct fn_1_A6870_lbl_801A6D30 lbl_801A6D30;
extern void GXAdjustForOverscan(Sig_GXAdjustForOverscan_GXRenderModeObj *, Sig_GXAdjustForOverscan_GXRenderModeObj *, u16, u16);
extern void fn_80035110(void *, Sig_fn_80035110_GXBool);
extern void fn_80034ECC(Sig_fn_80034ECC_GXBool, void *, Sig_fn_80034ECC_GXBool, void *);

#endif  // GAME_MAIN_REL_PROG_TYPES_H
