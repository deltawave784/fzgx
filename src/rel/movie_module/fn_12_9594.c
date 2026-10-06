#include "types.h"
typedef struct Sig_fn_12_9594_MPVBitReader {
    union {
        unsigned char padding_extent[16];
        struct { u32 bits; } view_bits;
        struct { unsigned char padding_next_bits[4]; u32 next_bits; } view_next_bits;
        struct { unsigned char padding_bit_offset[8]; s32 bit_offset; } view_bit_offset;
        struct { unsigned char padding_words[12]; const u32 *words; } view_words;
    } fields;
} Sig_fn_12_9594_MPVBitReader;
typedef struct Sig_fn_12_9594_MPVMotionInfo {
    union {
        unsigned char padding_extent[36];
        struct { unsigned char padding_previous_horizontal[16]; s32 previous_horizontal; } view_previous_horizontal;
        struct { unsigned char padding_previous_vertical[20]; s32 previous_vertical; } view_previous_vertical;
        struct { unsigned char padding_horizontal[24]; s32 horizontal; } view_horizontal;
        struct { unsigned char padding_vertical[28]; s32 vertical; } view_vertical;
    } fields;
} Sig_fn_12_9594_MPVMotionInfo;
extern u32 lbl_12_bss_6924;
extern u32 lbl_12_bss_6920;
#pragma opt_propagation off
s32 fn_12_9594(Sig_fn_12_9594_MPVBitReader *arg0, Sig_fn_12_9594_MPVMotionInfo *arg1, s32 *arg2, s32 *arg3) {
    s32 v0;
    u32 bits;
    u32 v1;
    const u32 *v2;
    u8 v13;
    u32 v5;
    s32 v8;
    s16 v7;
    s32 v18;
    u32 v19;
    s32 v22;
    s32 v9 = 0;
    s32 v3;
    u32 v4;
    v0 = arg0->fields.view_bit_offset.bit_offset;
    bits = arg0->fields.view_bits.bits;
    v1 = arg0->fields.view_next_bits.next_bits;
    v2 = arg0->fields.view_words.words;
    v3 = *(s32 *)((u8 *)arg1 + 4);
    v4 = *(u32 *)((u8 *)arg1 + 8);
    v5 = bits >> 21;
    if (v0 > 21) v5 |= v1 >> (53 - v0);
    if ((v5 >> 7) == 0) v7 = ((s16 *)lbl_12_bss_6924)[v5];
    else v7 = ((s16 *)lbl_12_bss_6920)[v5 >> 6];
    v8 = (s8)v7;
    if (v8 == 127) {
        v9 = -1;
    } else {
        v13 = (u16)v7 >> 8;
        v0 += v13;
        if (v0 >= 32) {
            v0 -= 32;
            bits = v1 << v0;
            v1 = *v2++;
        } else bits <<= v13;
        if (v8 == 0) *arg2 = *arg3;
        else {
            if (v3 != 0) {
                v18 = 32 - v3;
                if (v0 >= v18) {
                    v0 -= v18;
                    if (v0 != 0) {
                        bits |= v1 >> (v3 - v0);
                        v19 = bits >> v18;
                        bits = v1 << v0;
                    } else {
                        v19 = bits >> v18;
                        bits = v1;
                    }
                    v1 = *v2++;
                } else {
                    v19 = bits >> v18;
                    v0 += v3;
                    bits <<= v3;
                }
                v22 = (*(s32 *)((u8 *)arg1 + 12) - 1) - v19;
                if ((v8 <<= v3) > 0) v8 -= v22;
                else v8 += v22;
            }
            v8 += *arg3;
            *arg2 = (s32)(v8 << v4) >> v4;
            *arg3 = *arg2;
        }
        if (*(s32 *)arg1 != 0) *arg2 <<= 1;
    }
    arg0->fields.view_bits.bits = bits;
    arg0->fields.view_next_bits.next_bits = v1;
    arg0->fields.view_bit_offset.bit_offset = v0;
    arg0->fields.view_words.words = v2;
    return v9;
}
