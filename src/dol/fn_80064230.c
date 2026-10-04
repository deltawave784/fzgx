#include "types.h"

struct fn_80064230_lbl_801A6C80_T {
    u8 data[0x444];
    u32 flags;
};

extern struct fn_80064230_lbl_801A6C80_T *lbl_801A6C80;

#define FN_80064230_FLAGS(base) (((struct fn_80064230_lbl_801A6C80_T *)(base))->flags)

/* Retail expands this body once inside the port loop and once for the single port. */
#define FN_80064230_APPLY(arg0, arg1, base, index)                                            \
    switch (arg1) {                                                                           \
    case 0xA004: {                                                                            \
        u16 cmd = arg0;                                                                       \
        u8 value = (FN_80064230_FLAGS(base) >> 8) & 0x7F;                                     \
                                                                                              \
        if ((u32)cmd == 4) {                                                                  \
            (base + ((index) << 4))[0x492] = value;                                           \
        } else if ((u32)cmd == 0xA005) {                                                      \
            (base + ((index) << 4))[0x494] = value;                                           \
        } else if ((u32)cmd == 0xA010) {                                                      \
            (base + ((index) << 4))[0x493] = value;                                           \
        } else if ((u32)cmd == 0xA011) {                                                      \
            (base + ((index) << 4))[0x495] = value;                                           \
        }                                                                                     \
        break;                                                                                \
    }                                                                                         \
    case 0xA034: {                                                                            \
        u16 cmd = arg0;                                                                       \
                                                                                              \
        if ((u32)cmd == 0xA034) {                                                             \
            *(s16 *)(base + ((index) << 1) + 0x5A34) = *(s16 *)(base + ((index) << 1) + 0x5AB4); \
        } else if ((u32)cmd == 0xA040) {                                                      \
            *(s16 *)(base + ((index) << 1) + 0x5A54) = *(s16 *)(base + ((index) << 1) + 0x5AD4); \
        }                                                                                     \
        break;                                                                                \
    }                                                                                         \
    }

void fn_80064230(u32 arg0, u16 arg1) {
    u8 *base = (u8 *)lbl_801A6C80;

    if (FN_80064230_FLAGS(base) & 0x10) {
        u8 i = 0;

        while (i < 0x10) {
            if (*(u32 *)((u8 *)lbl_801A6C80 + (i << 4)) + 0x10000 != 0xFFFF) {
                FN_80064230_APPLY(arg0, arg1, (u8 *)lbl_801A6C80, i);
            }
            i++;
        }
    } else {
        u8 index = FN_80064230_FLAGS(base) & 0xF;

        FN_80064230_APPLY(arg0, arg1, base, index);
    }
}
