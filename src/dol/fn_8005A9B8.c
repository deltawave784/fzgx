#include "types.h"
#include "sofdec/axrna.h"

void fn_800589BC(const SJCK *source, int nbyte, SJCK *first, SJCK *remainder);

void ARQPostRequest(void *request, unsigned long owner, unsigned long type, unsigned long priority,
                    unsigned long source, unsigned long destination, unsigned long length,
                    ARQCallback callback);

void DCFlushRange(void *address, unsigned long length);

void fn_8005ACF0(unsigned long request_address);

void fn_8005ADBC(unsigned long request_address);

void axrna_update_play(AXRNAHandle *handle);

extern unsigned char *lbl_80190C7C[];

static inline int axrna_get_play_switch(const AXRNAHandle *handle) {
    if (handle == 0) {
        return -1;
    }
    return (handle->switches >> 1) & 1;
}

static inline int axrna_get_transfer_switch(const AXRNAHandle *handle) {
    if (handle == 0) {
        return -1;
    }
    return handle->switches & 1;
}

static inline void axrna_transfer(AXRNAHandle *handle) {
    SJCK input_chunk;
    SJCK input_remainder;
    SJCK buffer_chunk;
    SJCK buffer_remainder;
    register int channel;
    register int transfer_size;

    for (channel = 0; channel < handle->num_channels; channel++) {
        if (handle->voices[channel] == 0 || handle->transfer_pending[channel] != 0) {
            continue;
        }
        handle->buffers[channel]->interface->get_chunk(handle->buffers[channel], 0, 0x2000,
                                                       &buffer_chunk);
        handle->inputs[channel]->interface->get_chunk(handle->inputs[channel], 1,
                                                      buffer_chunk.len, &input_chunk);
        transfer_size = input_chunk.len < buffer_chunk.len ? input_chunk.len : buffer_chunk.len;
        transfer_size = (transfer_size / 32) * 32;
        fn_800589BC(&buffer_chunk, transfer_size, &buffer_chunk, &buffer_remainder);
        handle->buffers[channel]->interface->unget_chunk(handle->buffers[channel], 0,
                                                         &buffer_remainder);
        fn_800589BC(&input_chunk, transfer_size, &input_chunk, &input_remainder);
        handle->inputs[channel]->interface->unget_chunk(handle->inputs[channel], 1,
                                                        &input_remainder);
        if (transfer_size == 0) {
            return;
        }
        if (input_chunk.len == buffer_chunk.len) {
        } else {
            for (;;) {
            }
        }
        handle->input_chunks[channel] = input_chunk;
        handle->buffer_chunks[channel] = buffer_chunk;
        handle->transfer_samples = (unsigned int)transfer_size >> 1;
        DCFlushRange(handle->input_chunks[channel].data, handle->input_chunks[channel].len);
        handle->transfer_pending[channel] = 1;
        ARQPostRequest(&handle->requests[channel], handle->request_owners[channel], 0, 1,
                       (unsigned long)input_chunk.data, (unsigned long)buffer_chunk.data,
                       transfer_size, fn_8005ADBC);
    }
}

static inline void axrna_flash(AXRNAHandle *handle) {
    SJCK flash_chunk;
    SJCK flash_remainder;
    register int channel;
    register int transfer_size;

    for (channel = 0; channel < handle->num_channels; channel++) {
        if (handle->flash_pending[channel] != 0) {
            continue;
        }
        handle->buffers[channel]->interface->get_chunk(handle->buffers[channel], 0, 0x2000,
                                                       &flash_chunk);
        transfer_size = (flash_chunk.len / 32) * 32;
        fn_800589BC(&flash_chunk, transfer_size, &flash_chunk, &flash_remainder);
        handle->buffers[channel]->interface->unget_chunk(handle->buffers[channel], 0,
                                                         &flash_remainder);
        if (transfer_size == 0) {
            return;
        }
        handle->buffer_chunks[channel] = flash_chunk;
        handle->flash_samples = (unsigned int)transfer_size >> 1;
        DCFlushRange(lbl_80190C7C[0], 0x1000);
        handle->flash_pending[channel] = 1;
        ARQPostRequest(&handle->requests[channel], handle->request_owners[channel], 0, 1,
                       (unsigned long)lbl_80190C7C[0], (unsigned long)flash_chunk.data,
                       transfer_size, fn_8005ACF0);
    }
}

#pragma opt_lifetimes off
#pragma opt_dead_assignments off
void fn_8005A9B8(AXRNAHandle *handle) {
    if (!(handle)) {
        return;
    }
    if (axrna_get_play_switch(handle) == 1) {
        axrna_update_play(handle);
    }
    if (axrna_get_transfer_switch(handle) == 1) {
        axrna_transfer(handle);
        return;
    }
    if (axrna_get_play_switch(handle) == 1 && handle->flash_position < handle->buffer_size) {
        axrna_flash(handle);
    }
}
#pragma opt_dead_assignments reset

#pragma opt_lifetimes reset

