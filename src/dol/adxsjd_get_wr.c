
#include "types.h"
#include "sofdec/sj.h"
#include "sofdec/adxb.h"

enum {
    ADXSJD_MAX_HANDLES = 16,
    ADXSJD_MAX_CHANNELS = 2,
    ADXSJD_MAX_HEADER_SIZE = 0xC800,
    ADXSJD_MAX_OUTPUT_CHUNK = 0x4000
};

typedef struct AhxDecoder AhxDecoder;

typedef struct AdxBasicDecoderExt {
    AdxBasicDecoder base;
    s16 default_key[3];
    s16 snapshot_key[3];
    s16 delay_left[2];
    s16 delay_right[2];
    AhxDecoder *ahx_decoder;
    s32 ahx_max_decoded_samples;
    s32 ahx_max_decoded_blocks;
    s32 ainf_length;
    u8 ainf[16];
    s16 default_out_volume;
    s16 default_pan[2];
    u8 reserved_DA[2];
    void *pl2_context;
    u8 reserved_E0[8];
    s32 last_notified_data_length;
    s32 field_EC;
    void (*notify)(void *, s32, s32);
    void *notify_object;
} AdxBasicDecoderExt;

typedef void (*AdxSjdTrapCallback)(void *object);

typedef void (*AdxSjdOutputCallback)(void *object, s32 channel, u8 *data, s32 length);

typedef struct AdxSjdHandle {
    s8 used;
    s8 status;
    s8 channel_count;
    s8 wait_for_input;
    AdxBasicDecoderExt *decoder;
    SJ *input;
    SJ *output[ADXSJD_MAX_CHANNELS];
    SJCK input_chunk;
    SJCK output_chunk[ADXSJD_MAX_CHANNELS];
    s32 decoded_samples;
    s32 decoded_data_length;
    s32 decode_position;
    s32 max_decode_samples;
    s32 trap_num_samples;
    s32 trap_count;
    s32 trap_data_length;
    AdxSjdTrapCallback trap_callback;
    void *trap_object;
    AdxSjdOutputCallback output_callback;
    void *output_object;
    u8 spsd_info[0x40];
    s32 header_length;
    s32 link_switch;
    s32 pending_leading_samples;
    s32 pending_trailing_samples;
} AdxSjdHandle;

extern s32 fn_80045588(AdxBasicDecoderExt *decoder);

extern s16 *fn_800455A4(AdxBasicDecoderExt *decoder);

extern u8 *fn_80057DB0(SJ *sj);

void adxsjd_get_wr(void *object, int *write_position, int *writable_samples, int *limit_samples) {
    AdxSjdHandle *handle = object;
    SJ *first_output = handle->output[0];
    s32 channel;
    s32 samples;
    s32 available_samples;
    for (channel = 0; channel < fn_80045588(handle->decoder); channel++) {
        handle->output[channel]->interface->get_chunk(
            handle->output[channel], 0, ADXSJD_MAX_OUTPUT_CHUNK, &handle->output_chunk[channel]);
    }
    *write_position = (handle->output_chunk[0].data - fn_80057DB0(first_output)) / 2;
    samples = handle->max_decode_samples;
    available_samples = handle->output_chunk[0].len / 2;
    if (available_samples < samples) {
        samples = available_samples;
    }
    *writable_samples = samples;
    if (handle->trap_num_samples >= 0) {
        *limit_samples = handle->trap_num_samples - handle->trap_count;
    } else {
        *limit_samples = 0x1FFFFFFF;
    }
    (void)fn_800455A4(handle->decoder);
}
