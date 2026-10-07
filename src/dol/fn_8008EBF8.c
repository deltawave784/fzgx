#include "types.h"
#include "dolphin/types.h"

extern u32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(u32);
extern volatile u32 *lbl_801A6678; /* shared interrupt state is hardware-updated */
#include "sdk_addresses.h"
extern vu32 __EXIRegs[] : FZGX_ADDR___EXIRegs; /* memory-mapped hardware register block */


#pragma opt_propagation off

u32 fn_8008EBF8(u32 arg0) {
    u32 interrupts;
    volatile u32 *state; /* shared state updated by interrupt handlers */
    u32 value;
    volatile u32 *flags; /* shared interrupt state */
    volatile u32 padding; /* unused stack reserve */


    interrupts = OSDisableInterrupts();
    state = lbl_801A6678;
    value = state[3];
    flags = &state[3];
    if ((value & 4) != 0) {
        OSRestoreInterrupts(interrupts);
        return 0;
    }

    *flags |= 4;
    value = __EXIRegs[10];
    value &= 0x405;
    value |= (arg0 << 4) | 0x80;
    __EXIRegs[10] = value; /* hardware CSR write */
    OSRestoreInterrupts(interrupts);
    return 1;
}
