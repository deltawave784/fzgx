
#include "types.h"
#include "sofdec/adxb.h"

int fn_8004E270(AdxXpnd *decoder);

void fn_80043460(AdxBasicDecoder *d) {
    AdxDecodeParams *dp;
    unsigned char *input;
    unsigned short *pcm, *left, *right;
    int i, count;
    dp = &d->decode;
    input = (unsigned char *)dp->input;
    if (d->status == 1 && fn_8004E270(d->expander) == 0) {
        d->get_write_info(d->get_write_object, &dp->write_position, &dp->room, &dp->loop_samples);
        count = dp->pcm_size - dp->write_position;
        if (count > dp->room)
            count = dp->room;
        if (count > dp->input_blocks)
            count = dp->input_blocks;
        pcm = (unsigned short *)dp->pcm_buffer;
        left = &pcm[dp->write_position];
        if (d->channel_count == 2) {
            right = &pcm[dp->pcm_distance + dp->write_position];
            for (i = 0; i < count; i++) {
                left[i] = input[i * 2] * 256;
                right[i] = input[i * 2 + 1] * 256;
            }
        } else {
            for (i = 0; i < count; i++)
                left[i] = input[i] * 256;
        }
        d->decoded_samples = count;
        d->decoded_data_length = count * d->channel_count;
        d->status = 2;
    }
    if (d->status == 2) {
        d->add_write_info(d->add_write_object, d->decoded_data_length, d->decoded_samples);
        d->status = 3;
    }
}
