#include "types.h"
extern void fn_80024E6C(void *);
extern void fn_80025004(void *);
#pragma peephole off
#pragma stack_alignment 8
void fn_80025504(u32 arg0, u32 arg1) {
    u8 v5;
    u32 v11;
    u32 *v12;
    u32 *v13;
    u32 *v14;
    u32 *v15;
    u32 *v16;
    u32 *v17;
    u32 v42;
    s32 v43;
    v15 = *(u32 **)(arg0 + 0);
    v16 = *(u32 **)(arg0 + 4);
    v17 = *(u32 **)(arg0 + 8);
    v5 = (*(u8 *)(arg1 + 36) + 1) % 3;
    v12 = ((u32 **)arg1)[v5];
    v13 = ((u32 **)(arg1 + 12))[v5];
    v14 = ((u32 **)(arg1 + 24))[v5];
    for (v11 = 0; v11 < 160; v11++) {
        *v12++ = *v15++;
        *v13++ = *v16++;
        *v14++ = *v17++;
    }
    *(u32 *)(arg1 + 132) = ((s32)*(u32 *)(arg1 + 96) >> 16) + 1;
    *(u32 *)(arg1 + 128) = (*(u32 *)(arg1 + 96) & 0xFFFF) << 16;
    v42 = *(u32 *)(arg1 + 100) - 1;
    *(u32 *)(arg1 + 100) = v42;
    if (v42 == 0) {
        *(u32 *)(arg1 + 100) = *(u32 *)(arg1 + 104);
        *(u32 *)(arg1 + 96) = -*(u32 *)(arg1 + 96);
    }
    for (v43 = 0; (u32)v43 < 3; v43++) {
        *(u32 *)(arg1 + 124) = *(u32 *)(arg1 + 92);
        *(u32 *)(arg1 + 120) = *(u32 *)(arg1 + 88);
        switch(v43) {
        case 0:
            *(u32 *)(arg1 + 112) = *(u32 *)(arg1 + 0);
            *(u32 *)(arg1 + 108) = *(u32 *)(arg0 + 0);
            *(u32 *)(arg1 + 116) = arg1 + 40;
            break;
        case 1:
            *(u32 *)(arg1 + 112) = *(u32 *)(arg1 + 12);
            *(u32 *)(arg1 + 108) = *(u32 *)(arg0 + 4);
            *(u32 *)(arg1 + 116) = arg1 + 56;
            break;
        case 2:
            *(u32 *)(arg1 + 112) = *(u32 *)(arg1 + 24);
            *(u32 *)(arg1 + 108) = *(u32 *)(arg0 + 8);
            *(u32 *)(arg1 + 116) = arg1 + 72;
            break;
        }
        switch(*(s32 *)(arg1 + 132)) {
        case 0: fn_80024E6C((void *)(arg1 + 108)); break;
        case 1: fn_80025004((void *)(arg1 + 108)); break;
        }
    }
    *(u32 *)(arg1 + 92) = *(u32 *)(arg1 + 124) % 480;
    *(u32 *)(arg1 + 88) = *(u32 *)(arg1 + 120);
    *(u8 *)(arg1 + 36) = v5;
}
#pragma peephole reset
