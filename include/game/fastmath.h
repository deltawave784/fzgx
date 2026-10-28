#ifndef GAME_FASTMATH_H
#define GAME_FASTMATH_H

// Hand-assembled DOL float helpers at 0x8006D044..0x8006D1xx (frsp; mcrfs; frsqrte refinement
// through .L_8006D088; no MWCC prologue). Hand-owned (librarian).

#include "types.h"

// lbl_8006D118: takes x in f1 and an output pointer in r3; stores x * rsqrt(x) (the square root)
// to *out and returns rsqrt(x) in f1 (retail 0x8006D144: fmuls f0, f1, f0; stfs f0, 0(r3)).
// Callers pass &len in r3 with len still live in f1 (fn_1_10976C, fn_1_124AD4, fn_1_10AD18,
// fn_1_D9D8C, fn_1_1192D0). The register classes make (f32 *, f32) and (f32, f32 *) the same
// call; (f32 *, f32) is the one spelling.
f32 lbl_8006D118(f32 *out, f32 x);

#endif  // GAME_FASTMATH_H
