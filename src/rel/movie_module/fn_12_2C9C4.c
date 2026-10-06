#include "types.h"
#include "sofdec/sfd.h"
typedef struct Sig_fn_12_2C9C4_MovieModuleState {
    u8 _pad_0[0x44];
    u32 field_44;
} Sig_fn_12_2C9C4_MovieModuleState;
struct Sig_fn_12_2F264_Movie;
typedef int (*Sig_fn_12_2F264_MovieHandler)(struct Sig_fn_12_2F264_Movie *, int, int, int);
struct Sig_fn_12_2F264_MovieItem {
    char pad0[0xc];
    Sig_fn_12_2F264_MovieHandler *handlers;
    char pad1[0x30];
    char pad2[4];
};
struct Sig_fn_12_2F264_Movie {
    char pad0[0x1aa0];
    struct Sig_fn_12_2F264_MovieItem items[1];
};
struct Sig_fn_12_2F1D0_fn_12_2F1D0_E68_u32 { u32 unk_0; u8 pad_4[0x40]; };
struct Sig_fn_12_2F1D0_fn_12_2F1D0_Arg0 {
    u8 pad_0[0x1AA4];
    struct Sig_fn_12_2F1D0_fn_12_2F1D0_E68_u32 unk_1AA4[1];
};
extern int fn_12_2F264(struct Sig_fn_12_2F264_Movie *, int);
extern s64 fn_12_335B8(void);
extern int fn_12_2C0F8(void *);
extern int fn_12_2C640(void *);
extern int fn_12_2D288(void *);
extern int fn_12_2D73C(void *, int);
extern u32 fn_12_2F1D0(struct Sig_fn_12_2F1D0_fn_12_2F1D0_Arg0 *, u32);
extern int fn_12_2F210(void *, int, int, int, int);
#define FIELD(p,o) (*(s32 *)((u8 *)(p)+(o)))

static inline int ready(Sig_fn_12_2C9C4_MovieModuleState *arg0) {
    int a;
    int b;
    int result;
    if (!FIELD(arg0,0x9d8)) return 1;
    if (!FIELD(arg0,0x9b4)) return 1;
    if (FIELD(arg0,0xf2c)) return 1;
    if (FIELD(arg0,0xf48) >= FIELD(arg0,0xa54)) return 1;
    if (!FIELD(arg0,0x9b8) && !FIELD(arg0,0x9b4)) {
        result = 1;
    } else {
        result = 0;
        a = fn_12_2F1D0((struct Sig_fn_12_2F1D0_fn_12_2F1D0_Arg0 *)arg0,6);
        b = fn_12_2F1D0((struct Sig_fn_12_2F1D0_fn_12_2F1D0_Arg0 *)arg0,7);
        switch (fn_12_2D73C(arg0,25)) {
        case 1: result = b; break;
        case 2: result = a; break;
        case 3: result = b | a; break;
        case 0: result = b & a; break;
        }
    }
    if (result) return 1;
    return 0;
}
static inline int update(Sig_fn_12_2C9C4_MovieModuleState *arg0) {
    int v1;
    int v5;
    v1 = FIELD(arg0,0x48);
    switch (v1) {
        case 1:
            switch(FIELD(arg0,0x4c)) {
            case 2: case 3: case 4: case 6: v1 = 2; break;
            }
            break;
        case 2: v1 = fn_12_2C640(arg0); break;
        case 3:
            v5 = v1;
            switch(FIELD(arg0,0x4c)) {
            case 2: v5 = 2; break;
            case 3: v5 = 3; break;
            case 4: case 6:
                if (ready(arg0)) {
                    fn_12_2F210(arg0,7,6,0,0);
                    v5 = 4;
                }
                break;
            }
            v1 = v5;
            break;
        case 4: v1 = fn_12_2C0F8(arg0); break;
        case 0: return v1;
        case 5: return v1;
        case 6: return v1;
    }
    return v1;
}
void fn_12_2C9C4(Sig_fn_12_2C9C4_MovieModuleState *arg0) {
    s64 v2;
    u32 v0;
    v0 = FIELD(arg0,0x48);
    if ((v0 - 1) <= 3 && (s32)arg0->field_44 != 0) {
        arg0->field_44 = 0;
        v2 = fn_12_335B8();
        if ((v0 - 2) <= 1 || (s32)v0 == 4) {
            fn_12_2F264((struct Sig_fn_12_2F264_Movie *)arg0,2);
            fn_12_2D288(arg0);
        }
        FIELD(arg0,0x48) = update(arg0);
        SFTMR_AddTsum((SfdTimerSummary *)((u8 *)arg0+0x29b8),fn_12_335B8() - v2);
    }
}
