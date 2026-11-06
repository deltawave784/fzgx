#include "types.h"
#include "dol/globals.h"

typedef struct {
    u8 pad_0[0x8];
    u8 *data;
    u8 pad_C[0x4];
} fn_800643F4_Slot;

typedef struct {
    u8 unk_0;
    u8 flags;
    u8 pad_2[0x2];
    u8 unk_4;
    u8 unk_5;
    u8 pad_6;
    u8 unk_7;
    u8 unk_8;
    u8 pad_9[0x2];
    u8 unk_B;
    u8 unk_C;
    u8 pad_D[0x4];
    u8 unk_11;
    u8 unk_12;
    u8 unk_13;
    u8 unk_14;
    u8 pad_15[0x7];
    u8 *ptr;
} fn_800643F4_Chan;

extern void fn_8005DCEC(u16 *arg0, u32 arg1);

#pragma opt_strength_reduction off
static inline u8 *fn_800643F4_skip(u8 *base, u32 n) {
    u32 j;
    u8 *q = base;
    for (j = 0; j <= n; j++) {
        q += 2;
    }
    return base + *(u16 *)q;
}

void fn_800643F4(u16 cmd) {
    struct { s32 value; } c;
    struct { u32 value; } value2;
    u8 ch;
    u32 chOffset;
    u32 group;
    struct { u32 data; } value;
    u32 i;
    u32 slot;
    u32 flags;
    u8 lab_t1;
    s16 lab_t1_;

    c.value = cmd;
    flags = lbl_801A6C80->unk_444;
    slot = flags & 0xF;
    group = (flags >> 24) & 0xF;
    value2.value = 0;
    value.data = (flags >> 8) & 0x7F;
    value2.value = (flags >> 16) & 0x7F;
    for (i = 0; i < 4; i++) {
        ch = lbl_801A6C80->unk_D88[slot][group][i];
        if ((s32)ch == 0xFF) {
            continue;
        }
        lbl_801A6C80->pad_448[0x13] = slot;
        switch (c.value) {
        case 0x9000: {
            chOffset = ((u8)ch) << 5;
            if ((*(u8 *)((u8 *)lbl_801A6C80 + chOffset + 0x589) & 0x80) && (*(u8 **)((u8 *)lbl_801A6C80 + chOffset + 0x5A4)) != NULL) {
                lab_t1 = ch;
                lab_t1_ = lab_t1;
                fn_8005DCEC(&(*(u16 **)((u8 *)lbl_801A6C80 + chOffset + 0x5A4))[4], lab_t1 | lab_t1_);
                lab_t1 = ch;
                fn_8005DCEC(&(*(u16 **)((u8 *)lbl_801A6C80 + chOffset + 0x5A4))[5], lab_t1);
                lab_t1 = ch;
                fn_8005DCEC(&(*(u16 **)((u8 *)lbl_801A6C80 + chOffset + 0x5A4))[6], lab_t1);
                lab_t1 = ch;
                fn_8005DCEC(&(*(u16 **)((u8 *)lbl_801A6C80 + chOffset + 0x5A4))[7], lab_t1);
            }
            break;
        }
        case 0xB000: {
            Obj_801A6C80_Target *chan;
            struct { u8 *data; } hdr;

            chOffset = ((u8)ch) << 5;
            *(u8 *)((u8 *)lbl_801A6C80 + chOffset + 0x58C) = value.data;
            chan = (Obj_801A6C80_Target *)((u8 *)lbl_801A6C80 + chOffset);
            hdr.data = ((fn_800643F4_Slot *)lbl_801A6C80->unk_0)[slot].data;
            if (chan->unk_588[0][1] & 2) {
                u32 off = *(u32 *)(hdr.data + 0x28);
                if (off != 0) {
                    (*(u8 **)&chan->unk_588[0][0x1C]) = hdr.data + off;
                } else {
                    (*(u8 **)&chan->unk_588[0][0x1C]) = NULL;
                }
            } else {
                u16 *p;
                u32 j;
                u32 n;
                u8 *base;
                u32 j2;
                u16 v;

                n = chan->unk_588[0][4];
                base = hdr.data + *(u32 *)(hdr.data + 0x1C);
                hdr.data = fn_800643F4_skip(base, n);
                n = chan->unk_588[0][5];

                p = (u16 *)hdr.data;
                for (j2 = 0; j2 <= n; j2++) {
                    p++;
                }
                v = *p;
                if (v != 0) {
                    (*(u8 **)&chan->unk_588[0][0x1C]) = (u8 *)((u32)v + (u32)hdr.data);
                } else {
                    (*(u8 **)&chan->unk_588[0][0x1C]) = NULL;
                }
            }
            break;
        }
        case 0xB001:
            lbl_801A6C80->unk_588[ch][0x13] = value.data;
            break;
        case 0xB002:
            lbl_801A6C80->unk_588[ch][0x14] = value.data;
            break;
        case 0xB007:
            lbl_801A6C80->unk_588[ch][0x7] = value.data;
            break;
        case 0xB00A:
            lbl_801A6C80->unk_588[ch][0x8] = value.data;
            break;
        case 0xB00D:
            lbl_801A6C80->unk_588[ch][0xb] = value.data;
            break;
        case 0xB00E:
            lbl_801A6C80->unk_588[ch][0xc] = value.data;
            break;
        case 0xB040:
            if (value.data >= 0x40) {
                lbl_801A6C80->unk_588[ch][0x12] = value.data;
            } else {
                lbl_801A6C80->unk_588[ch][0x12] = 0;
            }
            break;
        case 0xC000:
            lbl_801A6C80->unk_588[ch][0x5] = value2.value;
            break;
        case 0xE000:
            lbl_801A6C80->unk_588[ch][0x11] = value.data;
            break;
        }
    }
}
#pragma opt_strength_reduction reset

