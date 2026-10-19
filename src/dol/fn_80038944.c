#include "types.h"

struct fn_80038944_gx {
    u8 pad_0[8];
    u32 unk_8;
    u8 pad_c[0x4F0 - 0xC];
    u8 unk_4F0;
    u8 unk_4F1;
    u8 pad_4F2[2];
    u32 unk_4F4;
};
struct fn_80038944_pi {
    u8 pad_0[0x14];
    u32 unk_14;
};
struct fn_80038944_fifo {
    u8 pad_0[0x1C];
    u32 unk_1C;
    u8 pad_20[4];
    u8 unk_24[0x4F8];
};
u32 lbl_801783A0[328];
extern struct fn_80038944_gx *gx;
extern void fn_8003458C(void);
extern struct fn_80038944_pi *__piReg;
extern void __GXSaveCPUFifoAux(void *);
extern u32 lbl_801A6C28;
extern u32 GXSetCPUFifo(u32);
extern BOOL OSDisableInterrupts(void);
extern void *memcpy(void *, const void *, u32);
extern BOOL OSRestoreInterrupts(BOOL);

u32 fn_80038944(void) {
    u32 sp;
    BOOL en;
    u32 saved;

    if (gx->unk_4F4 != 0) {
        fn_8003458C();
    }
    sp = (__piReg->unk_14 >> 26) & 1;
    __GXSaveCPUFifoAux(lbl_801783A0);
    GXSetCPUFifo(lbl_801A6C28);
    if (gx->unk_4F1 != 0) {
        en = OSDisableInterrupts();
        saved = gx->unk_8;
        memcpy(gx, (u8 *)lbl_801783A0 + 0x24, 0x4F8);
        gx->unk_8 = saved;
        OSRestoreInterrupts(en);
    }
    gx->unk_4F0 = 0;
    if (sp == 0) {
        return lbl_801783A0[7];
    }
    return 0;
}
