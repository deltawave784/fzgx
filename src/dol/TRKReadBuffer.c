
#include "types.h"
#include "dolphin/trk.h"

void *fn_800035C0(void *dst, const void *src, size_t n);

DSError TRKReadBuffer(TRKBuffer *msg, void *data, size_t length) {
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
