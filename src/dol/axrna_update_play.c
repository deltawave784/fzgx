
#include "types.h"
#include "sofdec/axrna.h"

extern int lbl_80190C88;

extern int lbl_80190C8C[32];

static inline u32 axrna_get_voice_address(const AXVPB *voice) {
    return *(const u32 *)&voice->pb.addr.currentAddressHi;
}

void axrna_update_play(AXRNAHandle *handle) {
    SJCK chunk;
    AXVPB *voice;
    int current_position;
    int previous_position;
    int channel;
    int release_bytes;
    int played;
    voice = handle->voices[handle->num_channels - 1];
    previous_position = handle->play_position;
    if (voice == 0) {
        return;
    }
    current_position =
        axrna_get_voice_address(voice) - handle->aram_addresses[handle->num_channels - 1];
    lbl_80190C8C[lbl_80190C88++] = current_position;
    if (lbl_80190C88 == 32) {
        lbl_80190C88 = 0;
    }
    if (current_position < 0 || current_position > handle->buffer_size) {
        while (1) {
        }
    }
    if (previous_position == -1) {
        if (current_position == 0) {
            played = 0;
        } else {
            previous_position = 0;
            handle->play_position = 0;
        }
    }
    if (previous_position != -1) {
        if (current_position > previous_position) {
            played = current_position - previous_position;
        } else {
            played = 0x1000 - (previous_position - current_position);
        }
    }
    played = (played / 2048) * 2048;
    if (played > 0) {
        release_bytes = played * 2;
        for (channel = 0; channel < handle->num_channels; channel++) {
            handle->buffers[channel]->interface->get_chunk(handle->buffers[channel], 1,
                                                           release_bytes, &chunk);
            handle->buffers[channel]->interface->put_chunk(handle->buffers[channel], 0, &chunk);
        }
        handle->play_position += played;
        if (handle->play_position >= 0x1000) {
            handle->play_position -= 0x1000;
        }
    }
}
