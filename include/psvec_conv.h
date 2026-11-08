#ifndef PSVEC_CONV_H
#define PSVEC_CONV_H

#include "types.h"

/* Float-to-integer conversion through a declared stack home.
 *
 * MWCC lowers `(s32)f` as `fctiwz; stfd; lwz` through a compiler temporary, which it always
 * places in the temporaries area above the declared locals. Retail functions whose
 * `stfd fX, off(r1)` home lies inside the declared locals (between two user objects) wrote the
 * conversion into a declared 8-byte home. Declare an FzConvHome at the retail position (stack
 * homes are laid out in reverse declaration order; the home is word-aligned, so it can sit at
 * an offset that is not a multiple of 8) and convert through FZ_FCTIWZ: the result is the low
 * word, read back by C after the asm block. Pass a named local as `value`: the asm block is a
 * CSE barrier, so an expression used both here and elsewhere is computed twice. The home's
 * address folds into the `stfd` displacement after inlining.
 * Kept in its own header so that including it cannot shift the @N literal numbering of
 * matched units (see psvec_fill.h).
 *
 * Validated byte-exact 2026-11-08: fn_1_139440 (home at 0x44, between 0x40 and 0x4C). */

typedef struct FzConvHome {
    s32 i[2];
} FzConvHome;

/* home = fctiwz(value) as a double; evaluates to the truncated s32 in home.i[1]. */
#define FZ_FCTIWZ(home, value) (fz_fctiwz_store(&(home), (value)), (home).i[1])

static inline void fz_fctiwz_store(register FzConvHome *home, register f32 value) {
    register f64 t;
    asm {
        fctiwz t, value
        stfd t, 0(home)
    }
}

#endif  // PSVEC_CONV_H
