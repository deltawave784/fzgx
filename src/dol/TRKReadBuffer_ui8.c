
#include "types.h"
#include "dolphin/trk.h"

DSError TRKReadBuffer1_ui8(TRKBuffer *buffer, u8 *data);

DSError TRKReadBuffer(TRKBuffer *msg, void *data, size_t length);

void *fn_800035C0(void *dst, const void *src, size_t n);

static inline DSError TRKReadBuffer(TRKBuffer *msg, void *data, size_t length) {
    DSError error = DS_NoError;
    unsigned int bytesLeft;
    if (length == 0) {
        return DS_NoError;
    }
    bytesLeft = msg->length - msg->position;
    if (length > bytesLeft) {
        error = DS_MessageBufferReadError;
        length = bytesLeft;
    }
    fn_800035C0(data, msg->data + msg->position, length);
    msg->position += length;
    return error;
}

static inline DSError TRKReadBuffer1_ui8(TRKBuffer *buffer, u8 *data) {
    return TRKReadBuffer(buffer, (void *)data, 1);
}

DSError TRKReadBuffer_ui8(TRKBuffer *buffer, u8 *data, int count) {
    DSError err;
    int i;
    for (i = 0, err = DS_NoError; err == DS_NoError && i < count; i++) {
        err = TRKReadBuffer1_ui8(buffer, &(data[i]));
    }
    return err;
}
