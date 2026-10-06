#include "types.h"
extern u8 gTRKCPUState[1072];
extern void fn_80088764(void *, s32);
extern void TRKPostEvent(void *);
extern u32 fn_8008AA04(const char *, u8, u32 *, s32 *);
extern s32 fn_8008A91C(void *, s32 *);
extern u32 fn_8008A80C(u32, u32 *, u8, s32 *);
extern u32 fn_8008AD00(u32, u32 *, u32 *, s32 *, u32, u32);
extern void fn_8008AFF0(u32, u32);
struct CPUState {
    u32 regs[32];
    u32 pc;
};
struct Event { u32 a, b, c; };
s32 TRKTargetSupportRequest(void) {
    struct CPUState *state = (struct CPUState *)gTRKCPUState;
    s32 result;
    u32 *count;
    s32 command;
    s32 status;
    u32 position;
    struct Event event;
    command = state->regs[3];
    if (command != 0xD1 && command != 0xD0 && command != 0xD2 &&
        command != 0xD3 && command != 0xD4) {
        fn_80088764(&event, 4);
        TRKPostEvent(&event);
        return 0;
    }
    if (command == 0xD2) {
        result = fn_8008AA04((const char *)((struct CPUState *)gTRKCPUState)->regs[4],
            (u8)((struct CPUState *)gTRKCPUState)->regs[5],
            (u32 *)((struct CPUState *)gTRKCPUState)->regs[6], &status);
        if (status == 0 && result != 0) status = 1;
        state->regs[3] = status;
    } else if (command == 0xD3) {
        result = fn_8008A91C((void *)((struct CPUState *)gTRKCPUState)->regs[4], &status);
        if (status == 0 && result != 0) status = 1;
        state->regs[3] = status;
    } else if (command == 0xD4) {
        position = *(u32 *)((struct CPUState *)gTRKCPUState)->regs[5];
        result = fn_8008A80C(((struct CPUState *)gTRKCPUState)->regs[4],
            &position, (u8)((struct CPUState *)gTRKCPUState)->regs[6], &status);
        if (status == 0 && result != 0) status = 1;
        state->regs[3] = status;
        *(u32 *)((struct CPUState *)gTRKCPUState)->regs[5] = position;
    } else {
        count = (u32 *)((struct CPUState *)gTRKCPUState)->regs[5];
        result = fn_8008AD00(((struct CPUState *)gTRKCPUState)->regs[4],
            (u32 *)((struct CPUState *)gTRKCPUState)->regs[6], count, &status, 1, command == 0xD1);
        if (status == 0 && result != 0) status = 1;
        state->regs[3] = status;
        if (command == 0xD1)
            fn_8008AFF0(((struct CPUState *)gTRKCPUState)->regs[6], *count);
    }
    ((struct CPUState *)gTRKCPUState)->pc += 4;
    return result;
}
