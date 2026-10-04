
#include "types.h"
#include "sofdec/axrna.h"

void fn_80020ABC(AXVPB *voice);

void fn_80026D70(AXVPB *voice);

void *memset(void *destination, int value, unsigned long size);

void fn_8005A648(void);

void fn_8005A628(void);

void fn_8005BE98(RNAResource *resource);

void fn_8005BFB4(void);

void fn_8005B0C4(AXRNAHandle *handle, int enabled);

void fn_8005B264(AXRNAHandle *handle, int enabled);

void AXRNA_Destroy(AXRNAHandle *handle);

extern u32 lbl_80190C78;

extern AXRNAHandle lbl_80191D4C[16];

static inline void AXRNA_Destroy(AXRNAHandle *handle) {
    int channel;
    if (handle == 0) {
        return;
    }
    fn_8005B0C4(handle, 0);
    fn_8005B264(handle, 0);
    for (channel = 0; channel < handle->allocated_channels; channel++) {
        if (handle->buffers[channel] != 0) {
            handle->buffers[channel]->interface->destroy(handle->buffers[channel]);
        }
        if (handle->resources[channel] != 0) {
            fn_8005BE98(handle->resources[channel]);
        }
        fn_8005A648();
        if (handle->voices[channel] != 0) {
            fn_80026D70(handle->voices[channel]);
            fn_80020ABC(handle->voices[channel]);
        }
        fn_8005A628();
    }
    memset(handle, 0, sizeof(AXRNAHandle));
}

void AXRNA_Finish(void) {
    int i;
    lbl_80190C78--;
    if (lbl_80190C78 == 0) {
        for (i = 0; i < 16; i++) {
            if (lbl_80191D4C[i].used == 1) {
                AXRNA_Destroy(&lbl_80191D4C[i]);
            }
        }
        memset(lbl_80191D4C, 0, sizeof(lbl_80191D4C));
        fn_8005BFB4();
    }
}
