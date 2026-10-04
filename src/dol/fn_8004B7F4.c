
#include "types.h"
#include "sofdec/adxt.h"

s32 fn_8004B7F4(ADXTHandle *handle, s32 channels, s32 samples);

void fn_800589BC(const SJCK *source, int nbyte, SJCK *first, SJCK *remainder);

void *memset(void *destination, int value, unsigned long size);

extern void ADXSTM_EntryEosFunc(ADXStream *stream, void (*callback)(void *object), void *object);

s32 fn_8004B7F4(ADXTHandle *handle, s32 channels, s32 samples) {
    s32 requested_bytes;
    SJ *sj;
    s32 block_bytes;
    s32 usable_bytes;
    s32 written_bytes;
    SJCK chunk;
    SJCK remainder;
    sj = handle->input_sj;
    if (handle->input_sj == 0) {
        return 0;
    }
    block_bytes = channels * 18;
    requested_bytes = (samples / 32) * block_bytes;
    sj->interface->get_chunk(sj, 0, requested_bytes, &chunk);
    usable_bytes = (chunk.len / block_bytes) * block_bytes;
    memset(chunk.data, 0, usable_bytes);
    fn_800589BC(&chunk, usable_bytes, &chunk, &remainder);
    written_bytes = usable_bytes;
    sj->interface->put_chunk(sj, 1, &chunk);
    sj->interface->unget_chunk(sj, 0, &remainder);
    requested_bytes -= written_bytes;
    sj->interface->get_chunk(sj, 0, requested_bytes, &chunk);
    usable_bytes = (chunk.len / block_bytes) * block_bytes;
    memset(chunk.data, 0, usable_bytes);
    fn_800589BC(&chunk, usable_bytes, &chunk, &remainder);
    sj->interface->put_chunk(sj, 1, &chunk);
    sj->interface->unget_chunk(sj, 0, &remainder);
    return ((written_bytes + usable_bytes) / block_bytes) * 32;
}
