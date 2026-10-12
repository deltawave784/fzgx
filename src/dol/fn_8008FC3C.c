#include "dolphin/types.h"

#include "sdk_addresses.h"

/* The debugger stub addresses the EXI block as an absolute object. */
vu32 __EXIRegs[16] : FZGX_ADDR___EXIRegs;

// DBGEXIImm: immediate EXI channel 2 transfer of up to four bytes.
BOOL fn_8008FC3C(void *buffer, s32 bytecounter, u32 write) {
    u8 *tempPointer;
    u32 writeOutValue;
    int i;

    if (write) {
        writeOutValue = 0;
        for (i = 0; i < bytecounter; i++) {
            u8 *temp = (u8 *)buffer + i;
            writeOutValue |= *temp << ((3 - i) << 3);
        }
        __EXIRegs[14] = writeOutValue;
    }

    __EXIRegs[13] = 1 | write << 2 | (bytecounter - 1) << 4;
    while (__EXIRegs[13] & 1) {
    }

    if (!write) {
        writeOutValue = __EXIRegs[14];
        tempPointer = buffer;
        for (i = 0; i < bytecounter; i++) {
            *tempPointer++ = writeOutValue >> ((3 - i) << 3);
        }
    }
    return TRUE;
}
