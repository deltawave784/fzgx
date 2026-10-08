#include "types.h"
extern const u32 gx;
extern volatile union { u8 u8val; u32 u32val; } __GXWGFifo : 0xCC008000; /* fzgx-allow: A1 memory-mapped write-gather FIFO symbol */
extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL);
extern void fn_8003458C(void);
extern u32 fn_80009FF4(void);

void fn_8003401C(u32 token) {
    u32 context;
    u32 reg;
    BOOL enabled;
    enabled = OSDisableInterrupts();
    reg = (token & 0xFFFF) | 0x48000000;
    __GXWGFifo.u8val = 0x61;
    __GXWGFifo.u32val = reg;
    reg = (reg & 0xFFFF0000) | (token & 0xFFFF);
    reg = (reg & 0x00FFFFFF) | 0x47000000;
    __GXWGFifo.u8val = 0x61;
    __GXWGFifo.u32val = reg;
    if (*(u32 *)((u8 *)gx + 0x4F4)) fn_8003458C();
    __GXWGFifo.u32val = 0;
    __GXWGFifo.u32val = 0;
    __GXWGFifo.u32val = 0;
    __GXWGFifo.u32val = 0;
    __GXWGFifo.u32val = 0;
    __GXWGFifo.u32val = 0;
    __GXWGFifo.u32val = 0;
    __GXWGFifo.u32val = 0;
    fn_80009FF4();
    OSRestoreInterrupts(enabled);
    *(u16 *)((u8 *)gx + 2) = 0;
}
