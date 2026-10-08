#ifndef GAME_MAIN_REL_BG_CAS_TYPES_H
#define GAME_MAIN_REL_BG_CAS_TYPES_H

// Types (and the externs that name them) of bg_cas.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).

#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_cas.h"

typedef struct {
    f32 x, y, z;
} fn_1_FF6B8_CasVec;

typedef struct {
    s32 life;        /* 0x00 */
    fn_1_FF6B8_CasVec pos;      /* 0x04 */
    fn_1_FF6B8_CasVec prev;     /* 0x10 */
    fn_1_FF6B8_CasVec vel;      /* 0x1C */
    s16 rot;         /* 0x28 */
    s16 rotVel;      /* 0x2A */
    f32 scale;       /* 0x2C */
    f32 size;        /* 0x30 */
} CasParticle;

typedef struct {
    u8 pad_0[0x4];
    s32 active;      /* 0x04 */
    fn_1_FF6B8_CasVec pos;      /* 0x08 */
    u8 pad_14[0xC];
    fn_1_FF6B8_CasVec vel;      /* 0x20 */
    u8 pad_2C[0xC];
    f32 size;        /* 0x38 */
    CasParticle particles[20]; /* 0x3C */
} CasEmitter;

extern void fn_1_FF6B8(CasEmitter *em);

#endif  // GAME_MAIN_REL_BG_CAS_TYPES_H
