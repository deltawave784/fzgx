#include "dolphin/types.h"
#include "sdk_addresses.h"

extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL);
extern BOOL fn_8008F9D8(u32 addr, const void *src, u32 size);
extern BOOL fn_8008FC3C(void *buf, s32 len, u32 mode);
extern u8 lbl_801A6688;

vu32 __EXIRegs[16] : FZGX_ADDR___EXIRegs;

#define IS_FALSE(x) (!(x))

#pragma opt_lifetimes off
static inline BOOL DBGEXISelect(u32 v) {
    u32 regs = __EXIRegs[10];
    regs &= 0x405;
    regs |= 0x80 | (v << 4);
    __EXIRegs[10] = regs;
    return TRUE;
}
#pragma opt_lifetimes reset


static inline BOOL DBGEXIDeselect(void) {
    __EXIRegs[10] &= 0x405;
    return TRUE;
}

static inline BOOL DBGEXISync(void) {
    while (__EXIRegs[13] & 1) {
    }
    return TRUE;
}

static inline BOOL DBGReadStatus(u32 *status) {
    BOOL total = FALSE;
    u32 cmd;
    DBGEXISelect(4);
    cmd = 0x40000000;
    total |= IS_FALSE(fn_8008FC3C(&cmd, 2, 1));
    total |= IS_FALSE(DBGEXISync());
    total |= IS_FALSE(fn_8008FC3C(status, 4, 0));
    total |= IS_FALSE(DBGEXISync());
    total |= IS_FALSE(DBGEXIDeselect());
    return IS_FALSE(total);
}

static inline BOOL DBGWriteMailbox(u32 value) {
    BOOL total = FALSE;
    u32 cmd;
    if (!DBGEXISelect(4)) {
        return FALSE;
    }
    cmd = (value & 0x1FFFFFFF) | (3u << 30);
    total |= IS_FALSE(fn_8008FC3C(&cmd, 4, 1));
    total |= IS_FALSE(DBGEXISync());
    total |= IS_FALSE(DBGEXIDeselect());
    return IS_FALSE(total);
}

static inline BOOL DBGReadStatusFinal(u32 *status) {
    BOOL total = FALSE;
    u32 cmd;
    if (!DBGEXISelect(4)) {
        return FALSE;
    }
    cmd = 0x40000000;
    total |= IS_FALSE(fn_8008FC3C(&cmd, 2, 1));
    total |= IS_FALSE(DBGEXISync());
    total |= IS_FALSE(fn_8008FC3C(status, 4, 0));
    total |= IS_FALSE(DBGEXISync());
    total |= IS_FALSE(DBGEXIDeselect());
    return IS_FALSE(total);
}

s32 fn_8008F45C(const void *src, u32 size) {
    u32 v;
    u32 busyFlag;
    BOOL interrupts = OSDisableInterrupts();

    do {
        DBGReadStatus(&busyFlag);
    } while (busyFlag & 2);

    lbl_801A6688++;
    v = (lbl_801A6688 & 1) ? 0x1000 : 0;
    while (!fn_8008F9D8(v | 0x1C000, src, (size + 3) & ~3)) {
    }

    do {
        DBGReadStatus(&busyFlag);
    } while (busyFlag & 2);

    v = lbl_801A6688;
    while (!DBGWriteMailbox(0x1F000000 | (v << 16) | size)) {
    }

    do {
        while (!DBGReadStatusFinal(&busyFlag)) {
        }
    } while (busyFlag & 2);

    OSRestoreInterrupts(interrupts);
    return 0;
}
