#include "types.h"
#include "sofdec/axrna.h"

void fn_8005A648(void);
void fn_8005A628(void);
void fn_8005A5BC(const char *message);
void fn_80023284(AXVPB *voice, AXPBADDR *addr);
void fn_80023168(AXVPB *voice, u16 state);

extern char lbl_800927D0[];

static inline int AXRNA_GetPlaySwitch(AXRNAHandle *handle) {
    if (handle == 0) {
        return -1;
    }
    return (handle->switches >> 1) & 1;
}

static inline void AXRNA_SetVoiceAddr(AXVPB *voice, s32 loop, s32 endOffset) {
    AXPBADDR addr;
    addr.loopFlag = 1;
    addr.format = 10;
    addr.loopAddressHi = loop >> 16;
    addr.loopAddressLo = loop;
    endOffset = loop + endOffset;
    addr.endAddressHi = endOffset >> 16;
    addr.endAddressLo = endOffset;
    addr.currentAddressHi = loop >> 16;
    addr.currentAddressLo = loop;
    fn_80023284(voice, &addr);
}

#pragma opt_common_subs off
void fn_8005B0C4(AXRNAHandle *handle, int enabled) {
    int i;
    s32 start;
    s32 end;

    if (handle == 0) {
        return;
    }
    if (enabled == AXRNA_GetPlaySwitch(handle)) {
        return;
    }
    fn_8005A648();
    if (enabled == 1) {
        handle->play_position = -1;
        for (i = 0; i < handle->num_channels; i++) {
            if (handle->voices[i] != 0) {
                AXRNA_SetVoiceAddr(handle->voices[i], handle->aram_addresses[i],
                    handle->buffer_size - 1);
                fn_80023168(handle->voices[i], 1);
            }
        }
        handle->switches |= 2;
    } else if (enabled == 0) {
        for (i = 0; i < handle->num_channels; i++) {
            if (handle->voices[i] != 0) {
                fn_80023168(handle->voices[i], 0);
            }
        }
        for (i = 0; i < handle->allocated_channels; i++) {
            handle->buffers[i]->interface->reset(handle->buffers[i]);
        }
        handle->switches &= 1;
    } else {
        fn_8005A5BC(lbl_800927D0);
    }
    fn_8005A628();
}
#pragma opt_common_subs reset

