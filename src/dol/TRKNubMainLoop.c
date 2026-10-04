
#include "types.h"
#include "dolphin/trk.h"

void TRKGetInput(void);

extern void *gTRKInputPendingPtr;

void *TRKGetBuffer(int);

void *TRKGetBuffer(int idx);

BOOL TRKDispatchMessage(TRKBuffer *buffer);

DSError TRKTargetContinue(void);

BOOL TRKGetNextEvent(TRKEvent *event);

void TRKDestructEvent(TRKEvent *);

DSError TRKTargetInterrupt(TRKEvent *);

DSError TRKTargetSupportRequest();

BOOL TRKTargetStopped(void);

static inline void TRKHandleRequestEvent(TRKEvent *event) {
    TRKBuffer *buffer = TRKGetBuffer(event->msgBufID);
    TRKDispatchMessage(buffer);
}

static inline void TRKHandleSupportEvent(TRKEvent *event) { TRKTargetSupportRequest(); }

static inline void TRKIdle() {
    if (TRKTargetStopped() == 0) {
        TRKTargetContinue();
    }
}

void TRKNubMainLoop(void) {
    TRKEvent event;
    BOOL isShutdownRequested;
    BOOL isNewInput;
    isShutdownRequested = 0;
    isNewInput = 0;
    while (isShutdownRequested == 0) {
        if (TRKGetNextEvent(&event) != 0) {
            isNewInput = 0;
            switch (event.eventType) {
            case NUBEVENT_Null:
                break;
            case NUBEVENT_Request:
                TRKHandleRequestEvent(&event);
                break;
            case NUBEVENT_Shutdown:
                isShutdownRequested = 1;
                break;
            case NUBEVENT_Breakpoint:
            case NUBEVENT_Exception:
                TRKTargetInterrupt(&event);
                break;
            case NUBEVENT_Support:
                TRKHandleSupportEvent(&event);
                break;
            }
            TRKDestructEvent(&event);
            continue;
        }
        if ((isNewInput == 0) || (*(u8 *)gTRKInputPendingPtr != '\0')) {
            isNewInput = 1;
            TRKGetInput();
            continue;
        }
        TRKIdle();
        isNewInput = 0;
    }
}
