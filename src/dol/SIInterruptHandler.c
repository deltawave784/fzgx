#include <dolphin/si/SIPriv.h>
#include <dolphin/os.h>
#include <dolphin/os/OSAlarm.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/os/OSTime.h>
#include <dolphin/si.h>
#include <dolphin/types.h>
#include "sdk_addresses.h"

struct SIBiosBss {
    SIPacket Packet[4];
    OSAlarm Alarm[4];
    OSTime TypeTime[4];
    OSTime XferTime[4];
    SITypeAndStatusCallback TypeCallback[4][4];
    __OSInterruptHandler RDSTHandler[4];
    BOOL InputBufferValid[4];
    u32 InputBuffer[4][2];
    vu32 InputBufferVcount[4];
};

struct SIBiosData {
    unsigned char padding_0[68];
    SIControl Si;
    u32 Type[4];
};

u32 __OSBusClock : FZGX_ADDR___OSBusClock;

vu32 __SIRegs[64] : FZGX_ADDR___SIRegs;

#pragma force_active on
static SIPacket Packet[4];
static OSAlarm Alarm[4];
static OSTime TypeTime[4];
static OSTime XferTime[4];
static SITypeAndStatusCallback TypeCallback[4][4];
static __OSInterruptHandler RDSTHandler[4];
static BOOL InputBufferValid[4];
static u32 InputBuffer[4][2];
static vu32 InputBufferVcount[4];
#pragma force_active reset

char lbl_80123B50[68] = "<< Dolphin SDK - SI\trelease build: Sep  5 2002 05:33:08 (0x2301) >>";
SIControl Si_80123B94 = { -1 };
u32 Type_80123BA8[4] = { 8, 8, 8, 8 };

extern u8 lbl_801A6810[4];

u32 CompleteTransfer(void);

void OSCancelAlarm(OSAlarm *alarm);

BOOL __SITransfer(s32 chan, void *output, u32 outputBytes, void *input, u32 inputBytes,
                  SICallback callback);

void GetTypeCallback(s32 chan, u32 error, OSContext *context);

u32 VIGetCurrentLine(void);

static inline void SITransferNext(s32 chan) {
    int i;
    SIPacket *packet;

    for (i = 0; i < 4; ++i) {
        ++chan;
        chan %= 4;
        packet = &Packet[chan];
        if (packet->chan != -1) {
            if (packet->fire <= __OSGetSystemTime()) {
                if (__SITransfer(packet->chan, packet->output, packet->outputBytes, packet->input,
                                 packet->inputBytes, packet->callback)) {
                    OSCancelAlarm(&Alarm[chan]);
                    packet->chan = -1;
                }
                break;
            }
        }
    }
}

static inline BOOL SIIsChanBusy(s32 chan) {
    BOOL rc;

    rc = TRUE;
    if (Packet[chan].chan == -1 && Si_80123B94.chan != chan) {
        rc = FALSE;
    }
    return rc;
}

static void SIInterruptHandler(__OSInterrupt interrupt, OSContext *context) {
    u32 reg;

    reg = __SIRegs[13];
    if ((reg & (3u << 30)) == (3u << 30)) {
        s32 chan;
        u32 sr;
        SICallback callback;

        chan = Si_80123B94.chan;
        sr = CompleteTransfer();
        callback = Si_80123B94.callback;
        Si_80123B94.callback = 0;

        SITransferNext(chan);

        if (callback) {
            callback(chan, sr, context);
        }

        sr = __SIRegs[14];
        sr &= 0xF000000 >> (8 * chan);
        __SIRegs[14] = sr;

        if (Type_80123BA8[chan] == 0x0080 && !SIIsChanBusy(chan)) {
            SITransfer(chan, lbl_801A6810, 1, &Type_80123BA8[chan], 3, GetTypeCallback,
                       (((65) * (((u32)__OSBusClock / 4) / 125000)) / 8));
        }
    }

    if ((reg & 0x18000000) == 0x18000000) {
        u32 half;
        s32 i;
        u32 vcount;
        u32 x;

        vcount = VIGetCurrentLine() + 1;
        x = (Si_80123B94.poll & 0x03ff0000) >> 16;
        for (i = 0; i < 4; ++i) {
            if (SIGetResponseRaw(i)) {
                InputBufferVcount[i] = vcount;
            }
        }
        half = x / 2;
        for (i = 0; i < 4; ++i) {
            if ((Si_80123B94.poll) & (0x80000000u >> (31 - 7 + i))) {
                if (InputBufferVcount[i] == 0 || InputBufferVcount[i] + half < vcount) {
                    return;
                }
            }
        }
        for (i = 0; i < 4; ++i) {
            InputBufferVcount[i] = 0;
        }
        for (i = 0; i < 4; ++i) {
            if (RDSTHandler[i]) {
                RDSTHandler[i](interrupt, context);
            }
        }
    }
}
