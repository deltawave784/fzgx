
#include "types.h"
#include "dolphin/trk.h"

extern TRKEventQueue lbl_801A36B8;

DSError fn_8008AF48(void *);

DSError fn_8008AF40(void *);

void *fn_800035C0(void *dst, const void *src, size_t n);

static inline void TRKCopyEvent(TRKEvent *dstEvent, const TRKEvent *srcEvent) {
    fn_800035C0(dstEvent, srcEvent, sizeof(TRKEvent));
}

DSError TRKPostEvent(TRKEvent *event) {
    DSError ret = DS_NoError;
    int nextEventID;
    fn_8008AF48(&lbl_801A36B8);
    if (lbl_801A36B8.count == 2) {
        ret = DS_EventQueueFull;
    } else {
        nextEventID = (lbl_801A36B8.next + lbl_801A36B8.count) % 2;
        TRKCopyEvent(&lbl_801A36B8.events[nextEventID], event);
        lbl_801A36B8.events[nextEventID].eventID = lbl_801A36B8.eventID;
        lbl_801A36B8.eventID++;
        if (lbl_801A36B8.eventID < 0x100)
            lbl_801A36B8.eventID = 0x100;
        lbl_801A36B8.count++;
    }
    fn_8008AF40(&lbl_801A36B8);
    return ret;
}
