#include "types.h"

typedef struct Fn12_A5C_Player {
    u8 unk0[8];
    s32 width;      /* 0x08 */
    s32 height;     /* 0x0C */
    u8 unk10[0x10];
    u32 unk20;      /* 0x20 */
    u8 unk24[0x10];
    s32 state;      /* 0x34 */
    u32 unk38;      /* 0x38 */
} Fn12_A5C_Player;

typedef struct Fn12_A5C_Info {
    u8 unk0[4];
    u32 unk4;       /* 0x04 */
    s32 width;      /* 0x08 */
    s32 height;     /* 0x0C */
    u8 unk10[4];
    u32 unk14;      /* 0x14 */
    u32 unk18;      /* 0x18 */
    u8 unk1C[8];
    u32 unk24;      /* 0x24 */
    u32 unk28;      /* 0x28 */
    u8 unk2C[0x20];
    u32 unk4c;      /* 0x4C */
} Fn12_A5C_Info;

typedef struct Fn12_A5C_Src {
    u32 y;
    u32 u;
    u32 v;
    s32 width;
    u32 uvPitch0;
    u32 uvPitch1;
    u32 unk18;
} Fn12_A5C_Src;

typedef struct Fn12_A5C_Dst {
    s32 format;
    void *buffer;
    s32 width;
    s32 height;
    s32 srcWidth;
    s32 srcHeight;
} Fn12_A5C_Dst;

extern u8 lbl_12_rodata_194[248];
extern void fn_12_309C(u32, u32, void *);
extern void fn_12_3710(u32, u32, u32);
extern void fn_12_3A64(u32, u32, u32);
extern void fn_12_3DCEC(Fn12_A5C_Src *, Fn12_A5C_Dst *, u32);
extern void fn_12_3DBE0(Fn12_A5C_Src *, Fn12_A5C_Dst *, u32);

void fn_12_A5C(Fn12_A5C_Player *player, Fn12_A5C_Info *info, s32 type, void *buffer) {
    Fn12_A5C_Src src;
    s32 width;
    s32 height;
    s32 format;
    s32 changed;
    s32 ysize;
    s32 csize;

    ysize = (info->width * info->height) / 2;
    src.y = info->unk4 + ysize;
    csize = ysize / 2;
    src.u = info->unk14 + csize;
    src.v = info->unk24 + csize;
    src.width = info->width;
    src.uvPitch0 = info->unk18;
    src.uvPitch1 = info->unk28;
    src.unk18 = 0;

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
        Fn12_A5C_Dst dst;

        dst.format = format;
        dst.buffer = buffer;
        dst.width = width;
        dst.height = height;
        dst.srcWidth = info->width;
        dst.srcHeight = info->height / 2;

        switch (type) {
        case 0x10:
            changed = player->state != 100;
            if (changed == 1) {
                player->state = 11;
                fn_12_3A64(player->unk20, info->unk4c, player->unk38);
            }
            fn_12_3DCEC(&src, &dst, player->unk38);
            break;
        case 0x20:
            changed = player->state != 100;
            if (changed == 1) {
                player->state = 13;
                fn_12_3710(player->unk20, info->unk4c, player->unk38);
            }
            fn_12_3DBE0(&src, &dst, player->unk38);
            break;
        }
    }
}
