#include "types.h"

typedef struct Fn12_8E4_Player {
    u8 unk0[8];
    s32 width;      /* 0x08 */
    s32 height;     /* 0x0C */
    u8 unk10[0x10];
    u32 unk20;      /* 0x20 */
    u8 unk24[0x10];
    s32 state;      /* 0x34 */
    u32 unk38;      /* 0x38 */
} Fn12_8E4_Player;

typedef struct Fn12_8E4_Info {
    u8 unk0[4];
    u32 unk4;       /* 0x04 */
    s32 width;      /* 0x08 */
    s32 height;     /* 0x0C */
    u8 unk10[0x3C];
    u32 unk4c;      /* 0x4C */
} Fn12_8E4_Info;

typedef struct Fn12_8E4_Src {
    u32 unk0;
    s32 width;
    s32 height;
    u32 unk0c;
    u32 unk10;
    u32 unk14;
} Fn12_8E4_Src;

typedef struct Fn12_8E4_Dst {
    s32 format;
    void *buffer;
    s32 width;
    s32 height;
    s32 srcWidth;
    s32 srcHeight;
} Fn12_8E4_Dst;

extern u8 lbl_12_rodata_194[248];
extern void fn_12_309C(u32, u32, void *);
extern void fn_12_3710(u32, u32, u32);
extern void fn_12_3DBDC(Fn12_8E4_Src *, Fn12_8E4_Dst *, u32);

void fn_12_8E4(Fn12_8E4_Player *player, Fn12_8E4_Info *info, s32 type, void *buffer) {
    Fn12_8E4_Src src;
    s32 width;
    s32 height;
    s32 format;
    s32 changed;

    src.unk0 = info->unk4;
    src.width = info->width;
    src.height = info->height;
    src.unk0c = 0x40;

    if (player->width == 0) {
        width = info->width;
    } else {
        width = player->width;
    }
    if (player->height == 0) {
        height = info->height / 2;
    } else {
        height = player->height;
    }

    switch (type) {
    case 0x10:
        format = 1;
        break;
    case 0x18:
        format = 2;
        break;
    case 0x20:
        format = 3;
        break;
    case 0:
    default:
        fn_12_309C(0, 0, lbl_12_rodata_194);
        format = 0;
        break;
    }

    {
        Fn12_8E4_Dst dst;

        dst.format = format;
        dst.buffer = buffer;
        dst.width = width;
        dst.height = height;
        dst.srcWidth = info->width;
        dst.srcHeight = info->height / 2;

        switch (type) {
        case 0x20:
            changed = player->state != 100;
            if (changed == 1) {
                player->state = 13;
                fn_12_3710(player->unk20, info->unk4c, player->unk38);
            }
            fn_12_3DBDC(&src, &dst, player->unk38);
            break;
        case 0x10:
            break;
        }
    }
}
