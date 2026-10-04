
#include "types.h"
#include "sofdec/axrna.h"

void fn_80026EE0(AXVPB *voice, int pan);

void fn_8005A648(void);

void fn_8005A628(void);

extern int lbl_8013255C[31];

void AXRNA_SetOutPan(AXRNAHandle *handle, int channel, int pan) {
    AXVPB *voice;
    if (handle != 0) {
        if (channel < handle->allocated_channels) {
            pan = pan < 15 ? pan : 15;
            pan = pan > -15 ? pan : -15;
            if (pan != handle->output_pan[channel]) {
                handle->output_pan[channel] = pan;
                fn_8005A648();
                voice = handle->voices[channel];
                if (voice != 0) {
                    fn_80026EE0(voice, lbl_8013255C[pan + 15]);
                }
                fn_8005A628();
            }
        }
    }
}
