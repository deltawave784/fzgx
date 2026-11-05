#ifndef PSVEC_MTX_H
#define PSVEC_MTX_H

#include "types.h"

/* Matrix kernels kept out of psvec.h: an inline-asm helper in a shared header consumes MWCC's
 * anonymous `@N` numbers, so adding one to psvec.h renumbers the private literals of every includer
 * and breaks their recorded pool maps (librarian pass 23: 205 units failed). */

/* m[3,7,11] += m[0,4,8] * x, in place (a 3x4 matrix translate in the locked cache: fn_1_10976C).
 * Register-exact there: t1 before t0 gives retail's f1/f0. Retail schedules the first fmadds one slot
 * later than MWCC does here (two rows remain, insensitive to the order inside this block). */
static inline void psvec_mtx_translate_x(register f32 *m, register f32 x) {
    register f32 x0, x1, x2, t1, t0;
    asm {
        lfs x0, 0(m)
        lfs t0, 12(m)
        lfs x1, 16(m)
        lfs t1, 28(m)
        fmadds x0, x0, x, t0
        lfs x2, 32(m)
        lfs t0, 44(m)
        fmadds x1, x1, x, t1
        stfs x0, 12(m)
        fmadds x2, x2, x, t0
        stfs x1, 28(m)
        stfs x2, 44(m)
    }
}

/* m[3,7,11] += m[2,6,10] * z, in place (a 3x4 matrix translate in the locked cache: fn_1_10976C).
 * Register-exact there: t1 before t0 gives retail's f1/f0. Retail schedules the first fmadds one slot
 * later than MWCC does here (two rows remain, insensitive to the order inside this block). */
static inline void psvec_mtx_translate_z(register f32 *m, register f32 z) {
    register f32 x0, x1, x2, t1, t0;
    asm {
        lfs x0, 8(m)
        lfs t0, 12(m)
        lfs x1, 24(m)
        lfs t1, 28(m)
        fmadds x0, x0, z, t0
        lfs x2, 40(m)
        lfs t0, 44(m)
        fmadds x1, x1, z, t1
        stfs x0, 12(m)
        fmadds x2, x2, z, t0
        stfs x1, 28(m)
        stfs x2, 44(m)
    }
}

#endif
