#include "types.h"
typedef struct Sig_fn_12_2396C_MovieState {
    u8 unk_00; u8 unk_01; u8 pad_02[2]; u32 unk_04;
    void *unk_08; void *unk_0c;
    s32 unk_10; s32 unk_14; s32 unk_18; u32 unk_1c;
    u32 unk_20; u32 unk_24; u8 unk_28; u8 pad_29[3];
    u32 unk_2c; u8 pad_30[16];
} Sig_fn_12_2396C_MovieState;
typedef struct Sig_fn_12_6B28_MovieSlot {
    s32 state; u32 field_04; u32 field_08; u32 field_0c; u32 field_10;
    s32 ids[43];
} Sig_fn_12_6B28_MovieSlot;
typedef struct Sig_fn_12_654C_MovieValues {
    s32 value_00; s32 value_04; s32 value_08; s32 value_0c;
    s32 value_10; s32 value_14; s32 value_18; s32 value_1c;
} Sig_fn_12_654C_MovieValues;
typedef struct Sig_fn_12_654C_MovieModule {
    u8 pad00[0x10]; int field10; u8 field14[0x0c];
    Sig_fn_12_654C_MovieValues values;
    Sig_fn_12_654C_MovieValues slots[3]; u8 fielda0[0x20];
} Sig_fn_12_654C_MovieModule;
typedef struct Sig_fn_12_6A18_MovieValues {
    u32 value_14; u32 value_18; u32 value_1c;
} Sig_fn_12_6A18_MovieValues;
typedef struct Sig_fn_12_6A18_MovieModule {
    u8 pad[0x14]; Sig_fn_12_6A18_MovieValues values;
} Sig_fn_12_6A18_MovieModule;
extern Sig_fn_12_6B28_MovieSlot *fn_12_6B28(void);
extern int fn_12_654C(Sig_fn_12_654C_MovieModule *, const u8 *, int, int *, int *);
extern int fn_12_6A18(Sig_fn_12_6A18_MovieModule *, Sig_fn_12_6A18_MovieValues *);
extern int fn_12_6A90(Sig_fn_12_6B28_MovieSlot *);
extern int fn_12_24760(u8 *, s32);
extern u32 fn_12_67A4(const u8 *);
extern u8 lbl_12_rodata_B90[56];
extern u32 lbl_12_bss_69BC[549];
extern void fn_12_57F0(void *, void *, int);
extern void fn_12_24570(void *);
extern int fn_12_23700(u8 *, s32, Sig_fn_12_2396C_MovieState *);
extern int fn_12_232DC(u8 *, s32, Sig_fn_12_2396C_MovieState *);

#define find(p, n) find_size(n, p)
static inline u8 *find_size(s32 n, u8 *p) {
    while (n >= 4) {
        if (fn_12_67A4(p) == 0x10000) return p;
        p++; n--;
    }
    return 0;
}
static inline void read_rate(s32 remain, u8 *first, s32 *rate) {
    Sig_fn_12_6A18_MovieValues loc_10;
    int loc_8;
    int loc_C;
    Sig_fn_12_6B28_MovieSlot *decoder = fn_12_6B28();
    if (decoder) {
        fn_12_654C((Sig_fn_12_654C_MovieModule *)decoder, first, remain, &loc_8, &loc_C);
        if (loc_C & 0x10000) {
            fn_12_6A18((Sig_fn_12_6A18_MovieModule *)decoder, &loc_10);
            fn_12_6A90(decoder);
            *rate = loc_10.value_1c;
        }
    }
}
static inline u8 *find_count(u8 *p, s32 *n) {
    while (*n >= 4) {
        if (fn_12_67A4(p) == 0x10000) return p;
        p++; (*n)--;
    }
    return 0;
}
static inline s32 detect(u8 *arg0, s32 arg1, s32 *rate) {
    struct { s32 value; } off;
#define offset off.value
    s32 remain;
    s32 stride;
    u8 *first;
    u8 *second;
    u8 *third;
    Sig_fn_12_6A18_MovieValues loc_10;
    int loc_8;
    int loc_C;
    remain = arg1;
    first = find_count(arg0, &remain);
    if (!first) stride = 0;
    else {
        offset = first - arg0;
        remain = arg1 - offset;
        second = find(first + 1, remain - 1);
        if (!second) stride = 0;
        else {
            third = find(second + 1, arg1 - (second - arg0) - 1);
            if (!third) stride = 0;
            else {
                stride = second - first;
                if (stride != third - second) stride = -1;
                else if (offset % stride != 0) stride = -1;
                else {
                    read_rate(remain, first, rate);
                }
            }
        }
    }
    return stride;
}
#undef first
#undef offset
static inline void scan(u8 *arg0, s32 arg1, Sig_fn_12_2396C_MovieState *arg2) {
    u8 *first;
    s32 offset;
    s32 remain;
    s32 rate;
    first = (u8 *)arg1;
    offset = (s32)arg0;
    rate = 0;
    remain = arg2->unk_10;
    while (1) {
        if (fn_12_24760((u8 *)offset, (s32)first) != 0) break;
        offset += remain;
        first -= remain;
        /* Failed probes go straight to the common final parsing calls. */
        if (rate >= 3 || (s32)first <= 0) goto done;
        rate++;
    }
    {
        s32 buffer = (s32)&lbl_12_bss_69BC;
        s32 size = 0x800;
        if ((s32)first < 0x800) size = (s32)first;
        fn_12_57F0((u8 *)buffer + 0x94, (u8 *)offset, size);
        *(u32 *)(buffer + 0x90) = size;
        fn_12_24570((void *)buffer);
        if (*(s32 *)buffer != 0 && *(s32 *)(buffer + 0xc) > 0)
            arg2->unk_1c = *(s32 *)(buffer + 0xc);
    }
done:;
}
int fn_12_2396C(u8 *arg0, s32 arg1, Sig_fn_12_2396C_MovieState *arg2) {
    s32 stride;
    s32 rate = 0;
    stride = detect(arg0, arg1, &rate);
    if (stride == 0) return 0;
    arg2->unk_10 = stride;
    if (stride == -1) return 1;
    if (rate != -1 && rate > 0) arg2->unk_1c = rate * 50;
    arg2->unk_04 = (u32)lbl_12_rodata_B90;
    scan(arg0, arg1, arg2);
    fn_12_23700(arg0, arg1, arg2);
    fn_12_232DC(arg0, arg1, arg2);
    return 1;
}
