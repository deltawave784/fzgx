
#include "types.h"
#include "dolphin/trk.h"

void *fn_800035C0(void *dst, const void *src, size_t n);

DSError TRKAppendBuffer(TRKBuffer *msg, const void *data, size_t length) {
    DSError error = DS_NoError;
    u32 bytesLeft;
    if (length == 0) {
        return DS_NoError;
    }
    bytesLeft = 0x880 - msg->position;
    if (bytesLeft < length) {
        error = DS_MessageBufferOverflow;
        length = bytesLeft;
    }
    if (length == 1) {
        msg->data[msg->position] = ((u8 *)data)[0];
    } else {
        fn_800035C0(msg->data + msg->position, data, length);
    }
    msg->position += length;
    msg->length = msg->position;
    return error;
}
