#include "types.h"

typedef struct MovieState {
    u8 unk_00;
    u8 unk_01;
    u8 pad_02[2];
    u32 unk_04;
    void *unk_08;
    void *unk_0c;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    u32 unk_1c;
    u32 unk_20;
    u32 unk_24;
    u8 unk_28;
    u8 pad_29[3];
    u32 unk_2c;
    u8 pad_30[16];
} MovieState;
typedef struct AudioHeader {
    u8 layer, protection, bitrate, frequency, padding, private_bit;
    u8 mode, mode_extension, copyright, original, emphasis;
} AudioHeader;
extern s32 fn_12_2396C(u8 *, s32, MovieState *);
extern s32 fn_12_232DC(u8 *, s32, MovieState *);
extern s32 fn_12_23410(u8 *, s32, MovieState *);
extern const u32 lbl_12_rodata_ADC[4];
extern const u32 lbl_12_rodata_AEC[5];
extern u8 lbl_12_bss_69B0[12];
extern void *memset(void *, int, u32);

static inline u8 *find_header(u8 *data, s32 size, AudioHeader *header) {
    s32 i;
    for (i = 4; i <= size; i++, data++) {
        if (data[0] == 255 && (data[1] & 0xf8) == 0xf8) {
            header->layer = (data[1] >> 1) & 3;
            header->protection = data[1] & 1;
            header->bitrate = (data[2] >> 4) & 15;
            header->frequency = (data[2] >> 2) & 3;
            header->padding = (data[2] >> 1) & 1;
            header->private_bit = data[2] & 1;
            header->mode = (data[3] >> 6) & 3;
            header->mode_extension = (data[3] >> 4) & 3;
            header->copyright = (data[3] >> 3) & 1;
            header->original = (data[3] >> 2) & 1;
            header->emphasis = data[3] & 3;
            if (header->layer != 0 && header->bitrate != 15 && header->frequency != 3)
                return data;
        }
    }
    return 0;
}
static inline s32 parse_audio(u8 *data, s32 size, MovieState *movie) {
    AudioHeader header;
    data = find_header(data, size, &header);
    if (data != 0) {
        if (header.layer == 2 && header.bitrate != 0 && header.frequency == 0) {
            movie->unk_28 = ((const u32 *)lbl_12_rodata_ADC)[header.mode];
            movie->unk_2c = ((const u32 *)lbl_12_rodata_AEC)[header.frequency];
        }
        *(AudioHeader *)lbl_12_bss_69B0 = header;
        return 1;
    }
    return 0;
}
void fn_12_23BFC(u8 *data, s32 size, MovieState *movie) {
    memset(movie, 0, 0x40);
    movie->unk_00 = 0;
    movie->unk_01 = 0;
    movie->unk_04 = 0;
    movie->unk_08 = 0;
    movie->unk_0c = 0;
    movie->unk_10 = 0;
    movie->unk_14 = 0;
    movie->unk_18 = 0;
    movie->unk_1c = 0;
    movie->unk_20 = 0;
    movie->unk_24 = 0;
    movie->unk_28 = 0;
    movie->unk_2c = 0;
    if (fn_12_2396C(data, size, movie)) return;
    if (fn_12_232DC(data, size, movie)) return;
    if (fn_12_23410(data, size, movie)) return;
    if (parse_audio(data, size, movie)) return;
}
