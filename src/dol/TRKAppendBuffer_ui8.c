
#include "types.h"
#include "dolphin/trk.h"

DSError TRKAppendBuffer1_ui8(TRKBuffer *buffer, const u8 data);

static inline DSError TRKAppendBuffer1_ui8(TRKBuffer *buffer, const u8 data) {
    if (buffer->position >= (0x800 + 0x80)) {
        return DS_MessageBufferOverflow;
    }
    buffer->data[buffer->position++] = data;
    buffer->length++;
    return DS_NoError;
}

DSError TRKAppendBuffer_ui8(TRKBuffer *buffer, const u8 *data, int count) {
    DSError err;
    int i;
    for (i = 0, err = DS_NoError; err == DS_NoError && i < count; i++) {
        err = TRKAppendBuffer1_ui8(buffer, data[i]);
    }
    return err;
}
