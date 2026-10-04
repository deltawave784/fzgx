#ifndef SOFDEC_ADXB_H
#define SOFDEC_ADXB_H

/* CRI ADX basic decoder (ADXB) and ADPCM expander (ADXPD) handles. */

#include "types.h"
#include "layout_check.h"

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

CHECK_SIZE(AdxXpndParams, 0x14);
CHECK_OFFSET(AdxXpnd, params, 0x14);
CHECK_OFFSET(AdxXpnd, delay, 0x28);
CHECK_SIZE(AdxXpnd, 0x3C);
CHECK_SIZE(AdxDecodeParams, 0x2C);
CHECK_OFFSET(AdxBasicDecoder, expander, 0x8);
CHECK_OFFSET(AdxBasicDecoder, max_channels, 0x38);
CHECK_OFFSET(AdxBasicDecoder, decode, 0x48);
CHECK_OFFSET(AdxBasicDecoder, get_write_info, 0x78);
CHECK_OFFSET(AdxBasicDecoder, codec_type, 0x9C);
CHECK_SIZE(AdxBasicDecoder, 0xA0);

#endif
