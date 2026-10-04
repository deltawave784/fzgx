#ifndef DOLPHIN_AR_H
#define DOLPHIN_AR_H

/* ARAM DMA request queue (ARQ), Dolphin SDK names. */

#include "types.h"
#include "layout_check.h"

typedef void (*ARQCallback)(u32 pointerToARQRequest);

typedef struct ARQRequest {
    struct ARQRequest *next;
    u32 owner;
    u32 type;
    u32 priority;
    u32 source;
    u32 dest;
    u32 length;
    ARQCallback callback;
} ARQRequest;

CHECK_OFFSET(ARQRequest, dest, 0x14);
CHECK_SIZE(ARQRequest, 0x20);

#endif
