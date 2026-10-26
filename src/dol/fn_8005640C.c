#include "types.h"

typedef struct Ent {
    u8 st0; u8 st1; u8 st2; u8 st3;
    s32 pad4;
    void *buf;
    s32 status;
    s32 blk;
    s32 limit;
    s32 pad18;
    s32 cnt;
    s32 done;
    s32 step;
    u8 cb[0x3C];
} Ent;

typedef struct G { s32 status; u8 flag; } G;

extern Ent lbl_801878CC[];
extern u32 lbl_801878B8[3];
#pragma use_lmw_stmw on
extern s32 DVDGetCommandBlockStatus(void *);
extern s32 DVDGetTransferredSize(void *);
extern void DCInvalidateRange(void *, u32);
extern void * memset(void *, int, u32);
extern void DCStoreRange(void *, u32);

static inline void UpdateTransferredState(s32 state, s32 transferred, Ent *e, G *g) {
    s32 blk;
    s32 cnt;
    s32 value;
    DCInvalidateRange(e->buf, transferred);
    blk = e->blk;
    g->flag = state;
    value = transferred / blk;
    value = blk * value;
    e->done = value;
    value = e->blk;
    cnt = e->cnt;
    value = transferred / value;
    value = cnt + value;
    e->cnt = value;
    e->st2 = state;
}

static inline void UpdateTransferred(s32 transferred, Ent *e, G *g) {
    UpdateTransferredState(0, transferred, e, g);
}

static inline void ReadComplete(Ent *e, G *g) {
    s32 d;
    char *p;
    s32 n = e->step * e->blk;
    s32 limit;
    s32 x;
    DCInvalidateRange(e->buf, n);
    e->done = n;
    e->cnt += e->step;
    x = e->cnt * e->blk;
    limit = e->limit;
    if (x > limit) {
        d = x - limit;
        p = (char *)e->buf + e->done - d;
        memset(p, 0, d);
        DCStoreRange(p, d);
    }
    e->st2 = 1;
    g->flag = 1;
}

#pragma opt_common_subs off
#pragma opt_dead_assignments off
#pragma opt_lifetimes off
void fn_8005640C(void) {
    u8 * fzgx_live_;
    G *g;
    s32 i;
    u8 * fzgx_live;
    for (i = 0; i < 40; i++) {
        Ent *e = &lbl_801878CC[i];
        g = (G *)&lbl_801878B8;
        if ((s32)e->st0 == 1 && (s32)e->st2 == 2) {
            fzgx_live_ = e->cb;
            fzgx_live = fzgx_live_;
            e->status = DVDGetCommandBlockStatus(fzgx_live);
            lbl_801878B8[0] = e->status;
            switch (e->status) {
            case -1:
                e->st2 = 3;
                g->flag = 3;
                break;
            case 0:
                ReadComplete(e, g);
                break;
            case 10: {
                fzgx_live_ = e->cb;
                fzgx_live = fzgx_live_;
                UpdateTransferred(DVDGetTransferredSize(fzgx_live), e, g);
                break;
            }
            }
        }
    }
}
#pragma opt_lifetimes reset

#pragma opt_dead_assignments reset

#pragma opt_common_subs reset
