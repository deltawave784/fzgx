
#include "types.h"
#include "dolphin/trk.h"

DSError fn_8008AF50(void *);

DSError fn_8008AF48(void *);

DSError fn_8008AF40(void *);

extern TRKBuffer lbl_801A36E8[3];

static inline void TRKSetBufferUsed(TRKBuffer *msg, BOOL state) { msg->isInUse = state; }

DSError TRKInitializeMessageBuffers(void) {
    int i;
    for (i = 0; i < 3; i++) {
        fn_8008AF50(&lbl_801A36E8[i]);
        fn_8008AF48(&lbl_801A36E8[i]);
        TRKSetBufferUsed(&lbl_801A36E8[i], 0);
        fn_8008AF40(&lbl_801A36E8[i]);
    }
    return DS_NoError;
}
