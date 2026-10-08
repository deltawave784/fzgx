#ifndef GAME_MAIN_REL_REPLAY_TYPES_H
#define GAME_MAIN_REL_REPLAY_TYPES_H

// Types (and the externs that name them) of replay.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).

#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/replay.h"

typedef struct Object {
    u8 pad0[0xa0];
    u16 halfa0;
} Object;

typedef struct {
    u32 x;
    u32 y;
    u32 z;
} ReplayTriple_F3574;

typedef struct {
    u32 start0 : 15;   // 0x0 copy of start
    u32 kind : 3;
    u32 index : 5;
    u32 value : 5;
    u32 pad0 : 4;
    u32 start : 15;    // 0x4 frame the event began
    u32 count : 5;
    u32 result : 5;
    u32 stage : 5;
    u32 pad1 : 2;
    ReplayTriple_F3574 begin[4];  // 0x8
    ReplayTriple_F3574 end[4];    // 0x38
    ReplayTriple_F3574 begin1;    // 0x68
    ReplayTriple_F3574 end1;      // 0x74
} ReplayEvent_F3574;

typedef struct {
    u8 pad0[0xFEF0];
    u16 eventCount;               // 0xFEF0
    u8 pad1[0x1E];
    u16 slots[30];                // 0xFF10
    ReplayEvent_F3574 events[1];  // 0xFF4C
} ReplayBuffer_F3574;

typedef struct {
    u32 unk_0;
    u32 frame;                    // 0x4
    u8 pad0[0x10];
    u8 playerCount;               // 0x18
    u8 pad1[0x27];
    ReplayBuffer_F3574 *buffer;   // 0x40
} ReplayState_F3574;

typedef struct { u8 raw[0x84]; } ReplayOutput;
extern void fn_1_F3574(ReplayState_F3574 *state, u8 index, u8 value, u8 kind, u8 result);
extern s32 fn_1_F45CC(u32 key, ReplayOutput *out);

#endif  // GAME_MAIN_REL_REPLAY_TYPES_H
