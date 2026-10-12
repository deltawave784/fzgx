#include "types.h"

typedef struct {
    u8 pad00[4];
    s32 unk04;
    s32 unk08;
    u32 unk0C;
} Slot48;

typedef struct {
    u8 unk00;
    u8 pad01[3];
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u8 pad1C[4];
    u32 unk20;
    u8 pad24[4];
    u32 unk28;
    u8 pad2C[4];
    u32 unk30;
    u8 pad34[4];
    u32 unk38;
    u8 pad3C[0x74];
} Entry;

typedef struct {
    Entry *entries;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
} Slot;

extern u32 OSDisableInterrupts(void);
extern void OSReport(const char *fmt, ...);
extern void OSRestoreInterrupts(u32 level);
extern s32 fn_8003401C(u32 arg);
extern u32 fn_8000A050(void);
extern u32 fn_8000A040(void);
extern u32 fn_8000A020(void);

extern u8 lbl_801A6C30;
extern volatile u32 lbl_801A6C40;  /* shared with the handler */
extern u32 lbl_801A6C44;
extern Slot48 *lbl_801A6C48;
extern Slot *lbl_801A6C4C;
extern u32 lbl_801A6C50;
extern char lbl_8012B590[];
extern char lbl_8012B5D0[];

/* current frame's entry at byte offset `off` */
#define ENTRY(off) (lbl_801A6C4C[lbl_801A6C44].entries[id])
/* hands out the next sample id, saturating at the last slot */
static inline u32 next_id(void) {
    u32 last = lbl_801A6C50 - 1;
    u32 id;

    if (lbl_801A6C40 >= last) {
        lbl_801A6C40 = last;
        return lbl_801A6C40;
    }
    id = lbl_801A6C40;
    lbl_801A6C40 = id + 1;
    return id;
}

void fn_8003DD48(u8 arg0) {
    u32 id;
    u32 level;
    u32 v;

    level = OSDisableInterrupts();
    if (lbl_801A6C48[arg0].unk08 < 0) {
        id = next_id();
        lbl_801A6C48[arg0].unk08 = id;
        ENTRY(off).unk00 = arg0;
        ENTRY(off).unk14 = 0;
        switch (lbl_801A6C48[arg0].unk04) {
        case 2:
            ENTRY(off).unk20 = 0;
            ENTRY(off).unk30 = 0;
            ENTRY(off).unk0C = 0;
            ENTRY(off).unk10 = 0;
            fn_8003401C((u16)id + 0x10000 + ((lbl_801A6C30 << 8) & 0xFF00) - 0x2000);
            break;
        case 1:
            ENTRY(off).unk0C = 0;
            ENTRY(off).unk10 = 0;
            ENTRY(off).unk20 = fn_8000A040();
            ENTRY(off).unk30 = fn_8000A020();
            fn_8003401C((u16)id + 0x10000 + ((lbl_801A6C30 << 8) & 0xFF00) - 0x2000);
            /* fallthrough */
        case 0:
            ENTRY(off).unk28 = fn_8000A040();
            ENTRY(off).unk38 = fn_8000A020();
            v = fn_8000A050();
            ENTRY(off).unk04 = v;
            ENTRY(off).unk18 = v;
            ENTRY(off).unk08 = 0;
            break;
        default:
            OSReport(lbl_8012B590, arg0);
            break;
        }
    } else {
        OSReport(lbl_8012B5D0);
    }
    OSRestoreInterrupts(level);
}
