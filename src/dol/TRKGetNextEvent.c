
#include "types.h"
#include "dolphin/trk.h"

extern TRKEventQueue lbl_801A36B8;

DSError fn_8008AF48(void *);

DSError fn_8008AF40(void *);

void *fn_800035C0(void *dst, const void *src, size_t n);

static inline void TRKCopyEvent(TRKEvent *dstEvent, const TRKEvent *srcEvent) {
    fn_800035C0(dstEvent, srcEvent, sizeof(TRKEvent));
}

BOOL TRKGetNextEvent(TRKEvent *event) {
    BOOL status = 0;
    fn_8008AF48(&lbl_801A36B8);
    if (0 < lbl_801A36B8.count) {
        TRKCopyEvent(event, &lbl_801A36B8.events[lbl_801A36B8.next]);
        lbl_801A36B8.count--;
        lbl_801A36B8.next++;
        if (lbl_801A36B8.next == 2)
            lbl_801A36B8.next = 0;
        status = 1;
    }
    fn_8008AF40(&lbl_801A36B8);
    return status;
}
