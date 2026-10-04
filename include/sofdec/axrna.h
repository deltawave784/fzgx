#ifndef SOFDEC_AXRNA_H
#define SOFDEC_AXRNA_H

/* CRI ADX renderer for AX (AXRNA): one handle per playing ADX stream. */

#include "sofdec/sj.h"
#include "dolphin/ar.h"
#include "dolphin/ax.h"
#include "layout_check.h"

typedef struct RNAResource RNAResource;

typedef struct AXRNAHandle {
    signed char used;
    unsigned char switches;
    signed char allocated_channels;
    signed char num_channels;
    int play_position;
    AXVPB *voices[2];
    RNAResource *resources[2];
    u32 aram_addresses[2];
    int buffer_size;
    int sample_rate;
    u32 request_owners[2];
    SJ *inputs[2];
    SJ *buffers[2];
    SJCK input_chunks[2];
    SJCK buffer_chunks[2];
// Hardware or OS state can change asynchronously.
    volatile int transfer_pending[2];
    int transfer_samples;
    int transfer_position;
// Hardware or OS state can change asynchronously.
    volatile int flash_pending[2];
    int flash_samples;
    int flash_position;
    int bits_per_sample;
    int output_volume;
    int output_pan[2];
    int surround_pan;
    int aux_a;
    int aux_b;
    int fader;
    short adjust_sample_rate;
    short sample_rate_state;
    int source_type;
    ARQRequest requests[2];
} AXRNAHandle;

CHECK_OFFSET(AXRNAHandle, voices, 0x8);
CHECK_OFFSET(AXRNAHandle, inputs, 0x30);
CHECK_OFFSET(AXRNAHandle, input_chunks, 0x40);
CHECK_OFFSET(AXRNAHandle, transfer_pending, 0x60);
CHECK_OFFSET(AXRNAHandle, adjust_sample_rate, 0xA0);
CHECK_OFFSET(AXRNAHandle, requests, 0xA8);
CHECK_SIZE(AXRNAHandle, 0xE8);

#endif
