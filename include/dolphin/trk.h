#ifndef DOLPHIN_TRK_H
#define DOLPHIN_TRK_H

/* MetroTRK debugger nub shared types (names from the MetroTRK sources). */

#include "types.h"
#include "layout_check.h"

enum {
    DS_NoError = 0x0,
    DS_StepError = 0x1,
    DS_ParameterError = 0x2,
    DS_EventQueueFull = 0x100,
    DS_NoMessageBufferAvailable = 0x300,
    DS_MessageBufferOverflow = 0x301,
    DS_MessageBufferReadError = 0x302,
    DS_DispatchError = 0x500,
    DS_InvalidMemory = 0x700,
    DS_InvalidRegister = 0x701,
    DS_CWDSException = 0x702,
    DS_UnsupportedError = 0x703,
    DS_InvalidProcessID = 0x704,
    DS_InvalidThreadID = 0x705,
    DS_OSError = 0x706,
    DS_Error800 = 0x800,
};

typedef int DSError;

#define TRKMSGBUF_SIZE (0x800 + 0x80)

/* One message buffer of the nub (gTRKMsgBufs holds three). */
typedef struct TRKBuffer {
    u32 mutex;
    BOOL isInUse;
    u32 length;
    u32 position;
    u8 data[TRKMSGBUF_SIZE];
} TRKBuffer;

CHECK_OFFSET(TRKBuffer, isInUse, 0x4);
CHECK_OFFSET(TRKBuffer, length, 0x8);
CHECK_OFFSET(TRKBuffer, position, 0xC);
CHECK_OFFSET(TRKBuffer, data, 0x10);
CHECK_SIZE(TRKBuffer, 0x890);

typedef enum {
    NUBEVENT_Null = 0,
    NUBEVENT_Shutdown = 1,
    NUBEVENT_Request = 2,
    NUBEVENT_Breakpoint = 3,
    NUBEVENT_Exception = 4,
    NUBEVENT_Support = 5,
} NubEventType;

typedef int MessageBufferID;

typedef u32 NubEventID;

typedef struct TRKEvent {
    NubEventType eventType;
    NubEventID eventID;
    MessageBufferID msgBufID;
} TRKEvent;

CHECK_SIZE(TRKEvent, 0xC);

typedef struct TRKEventQueue {
    int _00;
    int count;
    int next;
    TRKEvent events[2];
    NubEventID eventID;
} TRKEventQueue;

CHECK_SIZE(TRKEventQueue, 0x28);

#endif
