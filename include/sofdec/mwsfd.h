#ifndef SOFDEC_MWSFD_H
#define SOFDEC_MWSFD_H

#include "sofdec/mwsst.h"
#include "layout_check.h"

/* GX layout: name only fields used by recovered player routines. */
typedef struct SfdHandle SfdHandle;

typedef struct MwsPlayer {
    u8 unknown_000[0x0c];
    int playback_mode;
    u8 unknown_010[0x30];
    SfdHandle *sfd;          /* 0x40 */
    u8 unknown_044[0x08];
    void *lsc;               /* 0x4C: linked stream controller (LSC_Start) */
    u8 unknown_050[0x04];
    void *field_54;
    u8 unknown_058[0x18];
    s8 field_70;
    s8 field_71;
    s8 paused;               /* 0x72 */
    u8 unknown_073[0x179];
    MwsStHandle sound;       /* 0x1EC */
} MwsPlayer;

CHECK_OFFSET(MwsPlayer, playback_mode, 0x0C);
CHECK_OFFSET(MwsPlayer, sfd, 0x40);
CHECK_OFFSET(MwsPlayer, lsc, 0x4C);
CHECK_OFFSET(MwsPlayer, field_54, 0x54);
CHECK_OFFSET(MwsPlayer, field_70, 0x70);
CHECK_OFFSET(MwsPlayer, paused, 0x72);
CHECK_OFFSET(MwsPlayer, sound, 0x1EC);
CHECK_SIZE(MwsPlayer, 0x204);

void mwSfdPause(MwsPlayer* player, int paused);

#endif
