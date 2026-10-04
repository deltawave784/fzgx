
#include "types.h"
#include "sofdec/adxb.h"

void fn_80046020(AdxBasicDecoder *decoder);

int fn_8004E270(AdxXpnd *decoder);

void fn_80046020(AdxBasicDecoder *decoder) {
    AdxDecodeParams *params = &decoder->decode;
    const unsigned short *input = params->input;
    if (decoder->status == 1 && fn_8004E270(decoder->expander) == 0) {
        short *pcm;
        short *left;
        short *right;
        int i;
        int count;
        decoder->get_write_info(decoder->get_write_object, &params->write_position, &params->room,
                                &params->loop_samples);
        count = params->pcm_size - params->write_position;
        if (count > params->room)
            count = params->room;
        if (count > params->input_blocks)
            count = params->input_blocks;
        pcm = params->pcm_buffer;
        left = &pcm[params->write_position];
        if (decoder->channel_count == 2) {
            right = &pcm[params->pcm_distance + params->write_position];
            for (i = 0; i < count; i++) {
                left[i] = input[i * 2];
                right[i] = input[i * 2 + 1];
            }
        } else {
            for (i = 0; i < count; i++)
                left[i] = input[i];
        }
        decoder->decoded_samples = count;
        decoder->decoded_data_length = decoder->channel_count * (count << 1);
        decoder->status = 2;
    }
    if (decoder->status == 2) {
        decoder->add_write_info(decoder->add_write_object, decoder->decoded_data_length,
                                decoder->decoded_samples);
        decoder->status = 3;
    }
}
