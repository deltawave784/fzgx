#include "dolphin/types.h"

extern u32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(u32);
struct St {
    u32 pad[3];
    u32 flags;
    s32 len;
    u8 *buf;
};
extern struct St *lbl_801A6678;
extern vu32 __EXIRegs[];

void fn_8008E9B4(vu32 *regs) {
    struct St *st = lbl_801A6678;
    /* volatile: flags are updated by interrupt handlers */
    while (regs = __EXIRegs, ((volatile struct St *)st)->flags & 4) {
        if (!(regs[13] & 1)) {
            u32 en = OSDisableInterrupts();
            struct St *s = lbl_801A6678;
            vu32 *flags = &s->flags;
            if (s->flags & 3) {
                if ((*flags & 2) && s->len != 0) {
                    s32 n = s->len;
                    s32 i;
                    u32 v;
                    u8 *p = s->buf;
                    v = *(vu32 *)0xCC006838; /* fzgx-allow: A1,A2 */
                    for (i = 0; i < n; i++) {
                        *p++ = v >> ((3 - i) * 8);
                    }
                }
                lbl_801A6678->flags &= ~3;
            }
            OSRestoreInterrupts(en);
            return;
        }
    }
}
