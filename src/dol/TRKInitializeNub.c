#include "types.h"
#include "dolphin/trk.h"

extern u32 gTRKBigEndian[];
extern u32 gTRKInputPendingPtr[];
extern DSError TRKInitializeMessageBuffers(void);
extern int TRKInitializeDispatcher(void);
extern s32 TRKInitializeEventQueue(void);
extern s32 TRKInitializeIntDrivenUART(u32, u32, u32, u32);
extern s32 TRKInitializeSerialHandler(void);
extern s32 TRKInitializeTarget(void);
extern void InitializeProgramEndTrap(void);
extern void MWTRACE(u32, ...);
extern void TRKTargetSetInputPendingPtr(void *);
extern void usr_put_initialize(void);

static inline s32 TRKInitializeEndian(void) {
    s32 v0;
    u32 one = 1;
    u32 word;
    gTRKBigEndian[0] = one;
    ((u8 *)&word)[0] = 18;
    ((u8 *)&word)[1] = 52;
    ((u8 *)&word)[2] = 86;
    ((u8 *)&word)[3] = 120;
    v0 = 0;
    if (word == 0x12345678) {
        gTRKBigEndian[0] = one;
    } else if (word == 0x78563412) {
        gTRKBigEndian[0] = v0;
    } else {
        v0 = one;
    }
    return v0;
}

s32 TRKInitializeNub(u32 arg0, u32 arg1, u32 arg2) {
    s32 v0;
    s32 t8;
    v0 = TRKInitializeEndian();
    {
        const char *message = "Initialize NUB\n";
        MWTRACE(1, message);
    }
    if (v0 == 0) usr_put_initialize();
    if (v0 == 0) v0 = TRKInitializeEventQueue();
    if (v0 == 0) v0 = TRKInitializeMessageBuffers();
    if (v0 == 0) v0 = TRKInitializeDispatcher();
    InitializeProgramEndTrap();
    if (v0 == 0) v0 = TRKInitializeSerialHandler();
    if (v0 == 0) v0 = TRKInitializeTarget();
    if (v0 == 0) {
        t8 = TRKInitializeIntDrivenUART(0xE100, 1, 0, (u32)&gTRKInputPendingPtr);
        TRKTargetSetInputPendingPtr((void *)gTRKInputPendingPtr[0]);
        if (t8 != 0) v0 = t8;
    }
    return v0;
}
