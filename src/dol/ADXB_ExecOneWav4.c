
#include "types.h"
#include "sofdec/adxb.h"

int fn_8004E270(AdxXpnd *decoder);

void ADXB_ExecOneWav4(AdxBasicDecoder *decoder) {
    AdxDecodeParams *params;
    unsigned short *pcm;
    unsigned short *left;
    unsigned short *right;
    const unsigned char *input;
    int i;
    int count;
    params = &decoder->decode;
    input = (const unsigned char *)params->input;
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
                left[i] = input[i * 4] | input[i * 4 + 2] * 256;
                right[i] = input[i * 4 + 1] | input[i * 4 + 3] * 256;
            }
        } else {
            for (i = 0; i < count; i++) {
                left[i] = input[i * 2] | input[i * 2 + 1] * 256;
            }
        }
        decoder->decoded_samples = count;
        decoder->decoded_data_length = count * 2 * decoder->channel_count;
        decoder->status = 2;
    }
    if (decoder->status == 2) {
        decoder->add_write_info(decoder->add_write_object, decoder->decoded_data_length,
                                decoder->decoded_samples);
        decoder->status = 3;
    }
}
