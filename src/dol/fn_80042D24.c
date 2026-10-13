#include "types.h"
#include "sofdec/adxb.h"

int fn_8004E270(AdxXpnd *decoder);

/* MWCC folds this byte swap into the store as sthbrx */
#define SWAP16(x) ((unsigned short)((((x) & 0xFF) << 8) | (((x) >> 8) & 0xFF)))

/* 16-bit PCM: copy samples byte-swapped into the output buffer */
void fn_80042D24(AdxBasicDecoder *decoder) {
    AdxDecodeParams *params;
    unsigned short *pcm;
    unsigned short *left;
    unsigned short *right;
    const unsigned short *input;
    int i;
    int count;
    params = &decoder->decode;
    input = (const unsigned short *)params->input;
    if (decoder->status == 1 && fn_8004E270(decoder->expander) == 0) {
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
                left[i] = SWAP16(input[i * 2]);
                right[i] = SWAP16(input[i * 2 + 1]);
            }
        } else {
            for (i = 0; i < count; i++) {
                left[i] = SWAP16(input[i]);
            }
        }
        decoder->decoded_samples = count;
        decoder->decoded_data_length = decoder->channel_count * (count * 2);
        decoder->status = 2;
    }
    if (decoder->status == 2) {
        decoder->add_write_info(decoder->add_write_object, decoder->decoded_data_length,
                                decoder->decoded_samples);
        decoder->status = 3;
    }
}
