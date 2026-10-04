
#include "types.h"
#include "sofdec/adxt.h"

typedef struct AdxSjeHandle AdxSjeHandle;

SJ *fn_80058498(void *buffer, int buffer_size, int extra_size);

SJ *fn_80057B9C(void *buffer, int buffer_size);

void *memcpy(void *destination, const void *source, unsigned long size);

extern void fn_800482FC(void);

extern void fn_800482B8(void);

extern AdxSjeHandle *fn_80047C94(int count, SJ **inputs, SJ *output);

extern void fn_80047C08(AdxSjeHandle *encoder);

extern void fn_80047ADC(AdxSjeHandle *encoder, int channels, int sample_rate, int sample_count);

extern void ADXSJE_Start(AdxSjeHandle *encoder);

extern void fn_80047AF8(AdxSjeHandle *encoder);

extern void ADXSJE_ExecServer(void);

extern unsigned char lbl_8017B160[0x40];

extern unsigned char lbl_8017B1A0[0x400];

void ADXT_InsertHdrSfa(ADXTHandle *decoder, int channels, int sample_rate, int sample_count) {
    SJ *inputs[2];
    SJCK header;
    SJCK destination;
    SJ *header_stream;
    SJ *destination_stream;
    AdxSjeHandle *encoder;
    fn_800482FC();
    header_stream = fn_80058498(lbl_8017B1A0, sizeof(lbl_8017B1A0), 0);
    inputs[0] = fn_80057B9C(lbl_8017B160, 0x20);
    inputs[1] = fn_80057B9C(lbl_8017B160 + 0x20, 0x20);
    destination_stream = decoder->input_sj;
    encoder = fn_80047C94(2, inputs, header_stream);
    fn_80047ADC(encoder, channels, sample_rate, sample_count);
    ADXSJE_Start(encoder);
    ADXSJE_ExecServer();
    header_stream->interface->get_chunk(header_stream, 1, sizeof(lbl_8017B1A0), &header);
    if (header.len == 0) {
        for (;;) {
        }
    }
    destination_stream->interface->get_chunk(destination_stream, 0, header.len, &destination);
    if (destination.len < header.len) {
        for (;;) {
        }
    }
    memcpy(destination.data, header.data, header.len);
    header_stream->interface->put_chunk(header_stream, 0, &header);
    destination_stream->interface->put_chunk(destination_stream, 1, &destination);
    fn_80047AF8(encoder);
    fn_80047C08(encoder);
    header_stream->interface->destroy(header_stream);
    inputs[1]->interface->destroy(inputs[1]);
    inputs[0]->interface->destroy(inputs[0]);
    fn_800482B8();
}
