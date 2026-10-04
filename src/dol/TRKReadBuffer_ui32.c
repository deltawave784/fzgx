
#include "types.h"
#include "dolphin/trk.h"

DSError TRKReadBuffer1_ui32(TRKBuffer *buffer, u32 *data);

DSError TRKReadBuffer(TRKBuffer *msg, void *data, size_t length);

extern BOOL gTRKBigEndian;

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

static inline DSError TRKReadBuffer1_ui32(TRKBuffer *buffer, u32 *data) {
    DSError err;
    u8 *bigEndianData;
    u8 *byteData;
    u8 swapBuffer[sizeof(data)];
    if (gTRKBigEndian) {
        bigEndianData = (u8 *)data;
    } else {
        bigEndianData = swapBuffer;
    }
    err = TRKReadBuffer(buffer, (void *)bigEndianData, sizeof(*data));
    if (!gTRKBigEndian && err == DS_NoError) {
        byteData = (u8 *)data;
        byteData[0] = bigEndianData[3];
        byteData[1] = bigEndianData[2];
        byteData[2] = bigEndianData[1];
        byteData[3] = bigEndianData[0];
    }
    return err;
}

DSError TRKReadBuffer_ui32(TRKBuffer *buffer, u32 *data, int count) {
    DSError err;
    s32 i;
    for (i = 0, err = DS_NoError; err == DS_NoError && i < count; i++) {
        err = TRKReadBuffer1_ui32(buffer, &(data[i]));
    }
    return err;
}
