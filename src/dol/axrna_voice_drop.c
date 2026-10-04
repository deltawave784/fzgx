
#include "types.h"
#include "sofdec/axrna.h"

void fn_80026D70(AXVPB *voice);

extern AXRNAHandle lbl_80191D4C[16];

void axrna_voice_drop(void *voice_data) {
    AXVPB *voice = (AXVPB *)voice_data;
    int handle_index;
    int channel;
    for (handle_index = 0; handle_index < 16; handle_index++) {
        for (channel = 0; channel < 2; channel++) {
            if (voice == lbl_80191D4C[handle_index].voices[channel]) {
                fn_80026D70(lbl_80191D4C[handle_index].voices[channel]);
                lbl_80191D4C[handle_index].voices[channel] = 0;
                return;
            }
        }
    }
}
