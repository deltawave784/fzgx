#include "types.h"

extern u16 *__memReg;
extern void GXReadXfRasMetric(u32 *, u32 *, u32 *, u32 *);

#pragma opt_common_subs off
void fn_8003D588(u32 *arg0, u32 arg1) {
    u32 high;
    u32 *p = arg0 + arg1;
    GXReadXfRasMetric(p + 0x24, p + 0x26, p + 0x28, p + 0x2A);
    high = ((0x19)[__memReg]);
    p[0x10] = (high << 16) | ((0x1A)[__memReg]);
    high = ((0x1B)[__memReg]);
    p[0x12] = (high << 16) | ((0x1C)[__memReg]);
    high = ((0x1D)[__memReg]);
    p[0x14] = (high << 16) | ((0x1E)[__memReg]);
    high = ((0x1F)[__memReg]);
    p[0x16] = (high << 16) | ((0x20)[__memReg]);
    high = ((0x21)[__memReg]);
    p[0x18] = (high << 16) | ((0x22)[__memReg]);
    high = ((0x23)[__memReg]);
    p[0x1A] = (high << 16) | ((0x24)[__memReg]);
    high = ((0x25)[__memReg]);
    p[0x1C] = (high << 16) | ((0x26)[__memReg]);
    high = ((0x27)[__memReg]);
    p[0x1E] = (high << 16) | ((0x28)[__memReg]);
    high = ((0x29)[__memReg]);
    p[0x20] = ((((0x2A)[__memReg])) | ((high << 16)));
    high = ((0x2B)[__memReg]);
    p[0x22] = (high << 16) | ((0x2C)[__memReg]);
}
#pragma opt_common_subs reset

