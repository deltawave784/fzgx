
#include "types.h"

typedef struct AdxXpndParams {
    int channel_count;
    const signed char *input;
    int num_blocks;
    short *output_left;
    short *output_right;
} AdxXpndParams;

typedef struct AdxXpnd {
    int used;
    int index;
    int mode;
    int status;
    int num_decoded_blocks;
    AdxXpndParams params;
    short delay[2][2];
    short coefficients[2];
    short random_state;
    short random_multiplier;
    short random_increment;
    short reserved;
} AdxXpnd;

typedef struct AdxDecodeParams {
    const unsigned short *input;
    int input_blocks;
    int channel_count;
    int block_size;
    int samples_per_block;
    short *pcm_buffer;
    int pcm_size;
    int pcm_distance;
    int write_position;
    int room;
    int loop_samples;
} AdxDecodeParams;

typedef void (*AdxGetWriteInfo)(void *, int *, int *, int *);

typedef void (*AdxAddWriteInfo)(void *, int, int);

typedef struct AdxBasicDecoder {
    short used;
    short header_decoded;
    int status;
    AdxXpnd *expander;
    signed char encoding;
    signed char bits_per_sample;
    signed char channel_count;
    signed char block_length;
    int samples_per_block;
    int sample_rate;
    int total_samples;
    short coefficient;
    short field_1E;
    int loop_insert_samples;
    short loop_count;
    short loop_type;
    int loop_start_sample;
    int loop_start_offset;
    int loop_end_sample;
    int loop_end_offset;
    int max_channels;
    short *pcm_buffer;
    int pcm_size;
    int pcm_distance;
    AdxDecodeParams decode;
    short field_74;
    short field_76;
    AdxGetWriteInfo get_write_info;
    void *get_write_object;
    AdxAddWriteInfo add_write_info;
    void *add_write_object;
    int total_decoded_samples;
    int current_write_position;
    int decoded_samples;
    int decoded_data_length;
    short format_type;
    short field_9A;
    short codec_type;
} AdxBasicDecoder;

void fn_80043798(AdxBasicDecoder *decoder);

int fn_8004E270(AdxXpnd *decoder);

static inline AdxXpnd * fn_80043798_read_pointer(AdxBasicDecoder * owner) { return owner->expander; }
#pragma opt_pointer_analysis off
static inline const unsigned short * fn_80043798_read_pointer_(AdxDecodeParams * owner) { return owner->input; }
#pragma opt_loop_invariants off
#pragma opt_dead_assignments off
void fn_80043798(AdxBasicDecoder *decoder) {
    int fzgx_value;
    AdxDecodeParams *params;
    unsigned short *pcm;
    unsigned short *left;
    unsigned short *right;
    const unsigned short *input;
    unsigned short sample;
    int i;
    int count;
    params = &decoder->decode;
    input = fn_80043798_read_pointer_(params);
    if (decoder->status == 1 && fn_8004E270(fn_80043798_read_pointer(decoder)) == 0) {
        decoder->get_write_info(decoder->get_write_object, &params->write_position, &params->room,
                                &params->loop_samples);
        count = params->pcm_size - params->write_position;
        if (count > params->room) {
            count = params->room;
        }
        if (count > params->input_blocks) {
            count = params->input_blocks;
        }
        pcm = (unsigned short *)params->pcm_buffer;
        left = &pcm[params->write_position];
        if (decoder->channel_count == 2) {
            right = &pcm[params->pcm_distance + params->write_position];
            for (i = 0; i < count; i++) {
                left[i] = input[i * 2] << 8 | (sample = input[i * 2]) >> 8;
                right[i] = ((i * 2 + 1)[input]) >> 8 | ((i * 2 + 1)[input]) << 8;
            }
        } else {
            for (i = 0; i < count; i++) {
                left[i] = ((i)[input]) << 8 | ((i)[input]) >> 8;
            }
        }
        decoder->decoded_samples = count;
        decoder->decoded_data_length = count * 2 * decoder->channel_count;
        decoder->status = 2;
    }
    if (decoder->status == 2) {
        decoder->add_write_info(decoder->add_write_object, decoder->decoded_data_length,
                                decoder->decoded_samples);
        fzgx_value = 3;
        decoder->status = fzgx_value;
    }
}
#pragma opt_dead_assignments reset

#pragma opt_loop_invariants reset

#pragma opt_pointer_analysis reset

