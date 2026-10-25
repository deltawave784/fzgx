#include "types.h"
#include "rel/customize/globals.h"
#include "rel/customize/emb_memcard.h"

struct GXLightObj {
    u32 dummy[16];
};
extern u32 lbl_3_bss_7ED58[18];
extern u32 lbl_801A6410;
extern u32 lbl_3_data_1A18;
extern u8 fn_1_B7C00(void);
extern void fn_1_C1394(u32 *arg0);
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern u32 lbl_3_rodata_288[60];
extern void lbl_8006DCA4(void);
extern void fn_80035680(struct GXLightObj *, f32, f32, f32);
extern void fn_80035690(struct GXLightObj *, f32, f32, f32);
extern void fn_80035420(struct GXLightObj *, f32, int);
extern void fn_800356AC(struct GXLightObj *, u32 *);
extern void GXInitLightDistAttn(struct GXLightObj *, f32, f32, int);
extern void fn_1_7BB80(struct GXLightObj *, int);
extern void fn_1_7BD6C(int);
extern void fn_80074CF4(f32 arg0, f32 arg1, f32 arg2);

/* fzgx:begin fn_3_C328 */
void fn_3_C328(void) {
    u32 *state;

    if (!fn_1_B7C00()) {
        state = lbl_3_bss_7ED58;
        fn_1_C1394(state);
        if (state[2] != 0) {
            fn_1_46B4(lbl_801A6410, state[2], (((char *)&lbl_3_data_1A30)), 0x154);
            state[2] = 0;
            state[3] = 0;
        }
        lbl_3_data_1A18 = 0;
    }
}
/* fzgx:end fn_3_C328 */

/* fzgx:begin fn_3_E5D4 pool noprologue */
#include "types.h"
#include "rel/customize/emb_memcard.h"
#include "rel/customize/emb_paste_editor.h"
#include "game/main_rel/car_types.h"
#include "game/main_rel/shadowmap_types.h"

typedef struct Sig_fn_3_F948_MemCardSlot { u32 unk0; u32 flags; u8 pad[0x2058]; } Sig_fn_3_F948_MemCardSlot;
struct Sig_fn_1_87238_CarSlot { struct Model **model_ptr; char pad[8]; };
struct Sig_fn_1_87238_fn_1_87238_Car { char pad[0x328]; s8 field_0x328; char pad1[0xb]; struct Sig_fn_1_87238_CarSlot slots[1]; char pad2[0x50]; u32 flags; };
extern f32 lbl_3_rodata_378[84];
extern s16 fn_3_F948(Sig_fn_3_F948_MemCardSlot *);
extern void fn_1_870BC(fn_1_568F8_Data *, s8, fn_1_568F8_Data *, s32, u8, f32);
extern void fn_1_87238(struct Sig_fn_1_87238_fn_1_87238_Car *, s8, f32);
extern void fn_80008BEC(void *, int, u32);
extern void fn_1_151BDC(u32);
extern void fn_1_14E2DC(u32, u32, f32);
struct E5D4_Record { u8 pad[5]; u8 kind; u8 end[0x81ba]; };
struct E5D4_State { u8 pad[0x1c]; s16 state; u8 pad1e[0x28]; u8 index; };
struct E5D4_Buffer { u8 pad[0x390]; u32 flags; u8 pad394[0xc]; u32 model; u32 other; u8 pad3a8[0x12]; s16 value; u8 end[0x84]; };
#pragma opt_pointer_analysis off
#pragma opt_propagation off
static inline struct E5D4_Record *record_ptr(void *p) { return p; }
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
Obj_3_bss_7EDC0_At0 *fzgx_obj_lbl_3_bss_7EDC0;
u32 lbl_3_bss_7EDC0_fill_7EDC4;
u32 lbl_3_bss_7EDC0_8;
u8 lbl_3_bss_7EDCC;
u8 lbl_3_bss_7EDCC_fill_7EDCD;
u16 lbl_3_bss_7EDCC_fill_7EDCE;
u8 lbl_3_bss_7EDCC_4;
u8 lbl_3_bss_7EDCC_fill_7EDD1;
u16 lbl_3_bss_7EDCC_fill_7EDD2;
u32 lbl_3_bss_7EDCC_fill_7EDD4;
u8 fzgx_obj_lbl_3_bss_7EDD8;
u8 lbl_3_bss_7EDD8_fill_7EDD9;
u16 lbl_3_bss_7EDD8_fill_7EDDA;
u32 lbl_3_bss_7EDD8_fill_7EDDC[25];
u32 fzgx_obj_lbl_3_bss_7EE40[8304];
u32 fzgx_obj_lbl_3_bss_87000[16];
u32 fzgx_obj_lbl_3_bss_87040[8304];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_3_bss_7EDC0;
    s = *(u8 *)&lbl_3_bss_7EDC0_fill_7EDC4;
    s = *(u8 *)&lbl_3_bss_7EDC0_8;
    s = *(u8 *)&lbl_3_bss_7EDCC;
    s = *(u8 *)&lbl_3_bss_7EDCC_fill_7EDCD;
    s = *(u8 *)&lbl_3_bss_7EDCC_fill_7EDCE;
    s = *(u8 *)&lbl_3_bss_7EDCC_4;
    s = *(u8 *)&lbl_3_bss_7EDCC_fill_7EDD1;
    s = *(u8 *)&lbl_3_bss_7EDCC_fill_7EDD2;
    s = *(u8 *)&lbl_3_bss_7EDCC_fill_7EDD4;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_7EDD8;
    s = *(u8 *)&lbl_3_bss_7EDD8_fill_7EDD9;
    s = *(u8 *)&lbl_3_bss_7EDD8_fill_7EDDA;
    s = *(u8 *)&lbl_3_bss_7EDD8_fill_7EDDC;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_7EE40;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_87000;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_87040;
}
#pragma section code_type ".text"

void fn_3_E5D4(void) {
 
 struct E5D4_Buffer buffer __attribute__((aligned(32)));
 Obj_3_bss_7EDD8 *state;
 state = (Obj_3_bss_7EDD8 *)((u8 *)&fzgx_obj_lbl_3_bss_7EDD8);
 if (record_ptr((u8 *)fzgx_obj_lbl_3_bss_7EDC0 + (state->unk_46) * 0x81c0)->kind < 41) {
  fn_1_870BC(*(fn_1_568F8_Data **)((u8 *)&lbl_3_bss_7EDCC), 0, *(fn_1_568F8_Data **)((u8 *)&lbl_3_bss_7EDCC), 0, 1, lbl_3_rodata_378[0]);
  if (fn_3_F948((Sig_fn_3_F948_MemCardSlot *)((u8 *)&fzgx_obj_lbl_3_bss_7EE40 + 0x20)) != 0) {
   state = (Obj_3_bss_7EDD8 *)((u8 *)&fzgx_obj_lbl_3_bss_7EDD8);
   if (state->unk_1C == 0) {
    fn_1_87238(*(struct Sig_fn_1_87238_fn_1_87238_Car **)((u8 *)&lbl_3_bss_7EDCC), 0, lbl_3_rodata_378[0]);
   }
  }
 } else {
  fn_80008BEC(&buffer, 0, 0x440);
  { u32 other;
  u32 model;
  u32 flags;
  flags = buffer.flags;
  model = lbl_3_bss_7EDC0_8;
  other = *(u32 *)((u8 *)&lbl_3_bss_7EDCC_4);
  flags |= 0x4000000;
  buffer.flags = flags;
  buffer.model = model;
  buffer.other = other; }
  buffer.value = 0;
  fn_1_151BDC((u32)&fzgx_obj_lbl_3_bss_7EE40);
  fn_1_14E2DC(lbl_3_bss_7EDC0_8, 0, lbl_3_rodata_378[0]);
 }
}
/* fzgx:end fn_3_E5D4 */

/* fzgx:begin fn_3_F044 */
#include "font.h"

struct fn_3_F044_Copy88 { u32 a[22]; };
struct fn_3_F044_Packet {
    u32 id;
    f32 x, y, z;
    f32 sx, sy;
    u8 pad_18[0x18];
    u32 flags;
    u8 pad_34[0x24];
};
extern u32 lbl_1_rodata_26F8;
extern u32 lbl_3_rodata_288[60];
extern u8 lbl_3_bss_87040[33216];
extern s32 lbl_801A66B4;
extern u32 fn_1_50A90(void *, u32, u32, u32, u32);
extern int fn_1_4F734(FontDrawPacket *);
extern s32 fn_1_4FC50(void *, u32, u16, u16, void *);
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);
extern u32 fn_1_4AEC0(u32);
extern void fn_1_4954C(f32);
extern void fn_1_495C8(u8);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4A0D8(const char *);
#define F(off) ((off) == 0x14 ? 20.0f : (off) == 0x3c ? 0.5f : (off) == 0xf8 ? 360.0f : (off) == 0xfc ? 30.0f : (off) == 0x108 ? 0.90625f : (off) == 0x110 ? 0.9375f : (off) == 0x188 ? 354.0f : (off) == 0x18c ? 310.0f : (off) == 0x190 ? 365.0f : (off) == 0x194 ? 143.0f : (off) == 0x198 ? 19.2999f : (off) == 0x19c ? 0.01f : (off) == 0x1a0 ? 0.75f : (off) == 0x1a4 ? 351.0f : (off) == 0x1a8 ? 387.0f : (off) == 0x1ac ? 0.6f : (off) == 0x1b0 ? 0.7f : (off) == 0x1b4 ? 348.0f : 384.0f)
#define COPY() (*(struct fn_3_F044_Copy88 *)&packet = *(struct fn_3_F044_Copy88 *)&lbl_1_rodata_26F8)
struct fn_3_F044_TextEntry {
    const char *t0;
    u8 pad4[20]; const char *t0x18;
    u8 pad1c[20]; const char *t0x30;
    u8 pad34[20]; const char *t0x48;
    u8 pad4c[20]; const char *t0x60;
    u8 pad64[20]; const char *t0x78;
    u8 pad7c[20]; const char *t0x90;
};
#define TEXT(off) ((const char *)(&lbl_3_data_318C.unk_0)[lbl_801A66B4 + (off) / 4])
static inline Obj_3_bss_7EE40 *fn_3_F044_slot(u32 index) {
    u32 slot;
    slot = (u32)&lbl_3_bss_7EE40;
    slot += index * 0x2060;
    return (Obj_3_bss_7EE40 *)slot;
}
#define SLOT() fn_3_F044_slot(lbl_3_bss_7EDD8.unk_15)

#pragma section code_type ".fzgxpool"
void fzgx_fn_3_F044_pool0(volatile f32 *f, volatile f64 *d) { /* volatile: sinks keep the retail literal-pool order */
    f[0] = 50.0f; f[1] = 500.0f; f[2] = 31.2f; f[3] = 312.0f;
    f[4] = 68.0f; f[5] = 20.0f; f[6] = 96.0f; f[7] = 1.36f;
    f[8] = 161.0f; f[9] = 1.015625f; f[10] = 129.0f; f[11] = 15.0f;
    f[12] = 10.0f; f[13] = 0.0f; f[14] = 86.0f; f[15] = 0.5f;
    f[16] = 139.0f; f[17] = 75.0f; d[0] = 4503601774854144.0;
}
#pragma section code_type ".text"
const u32 fzgx_pool_table_50[3] = {0xffff0000, 0xffff0000, 0xffffff00};
/* Volatile sinks preserve the shared retail literal-pool order. */
#pragma section code_type ".fzgxpool"
void fzgx_pool_primer_1(volatile f32 *f, volatile f64 *d) { /* volatile: sinks keep the retail literal-pool order */
    f[0] = 185.000000f;
    f[1] = 180.000000f;
    f[2] = 276.000000f;
    f[3] = 116.000000f;
    f[4] = 7.00000000f;
    f[5] = 205.000000f;
    f[6] = 11.3999996f;
    f[7] = 40.0000000f;
    f[8] = 65536.0000f;
    f[9] = 60.0000000f;
    f[10] = 80.0000000f;
    f[11] = 274.000000f;
    f[12] = 0.583333313f;
    f[13] = 0.541666687f;
    f[14] = 0.458333343f;
}
#pragma section code_type ".text"
/* Volatile sinks preserve the shared retail literal-pool order. */
#pragma section code_type ".fzgxpool"
void fzgx_pool_primer_2(volatile f32 *f, volatile f64 *d) { /* volatile: sinks keep the retail literal-pool order */
    d[0] = 4503599627370496.0;
    f[2] = 320.000000f;
    f[3] = 240.000000f;
    f[4] = 5.00000000f;
    f[5] = 6.09999990f;
    f[6] = 0.800000012f;
    f[7] = 228.000000f;
    f[8] = 252.000000f;
    f[9] = 0.100000001f;
    f[10] = -30.0000000f;
    f[11] = 750.000000f;
    f[12] = 48.0000000f;
    f[13] = 660.000000f;
    f[14] = 44.0000000f;
    f[15] = 24.0000000f;
    f[16] = 302.000000f;
    f[17] = 70.0000000f;
    f[18] = 330.000000f;
    f[19] = 1.26999998f;
    f[20] = 390.000000f;
    f[21] = 308.000000f;
    f[22] = 1.00000000f;
    f[23] = 368.000000f;
    f[24] = 360.000000f;
    f[25] = 30.0000000f;
    f[26] = 0.400000006f;
    f[27] = 32768.0000f;
    f[28] = 0.906250000f;
    f[29] = 0.921875000f;
    f[30] = 0.937500000f;
}
#pragma section code_type ".text"
const u32 fzgx_pool_table_114[25] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x40a00000, 0xc1700000, 0x0, 0x40200000, 0xc1700000, 0x0, 0x40a00000, 0xc1700000, 0x0, 0x40200000, 0xc1700000, 0x0, 0x0, 0x0, 0x40a00000, 0xc1700000, 0x0, 0x40200000, 0xc1700000};
/* Volatile sinks preserve the shared retail literal-pool order. */
#pragma section code_type ".fzgxpool"
void fzgx_pool_primer_3(volatile f32 *f, volatile f64 *d) { /* volatile: sinks keep the retail literal-pool order */
    f[0] = 55.0000000f;
    f[1] = 90000.0000f;
    f[2] = 95.0000000f;
    f[3] = 17.0000000f;
    f[4] = 354.000000f;
    f[5] = 310.000000f;
    f[6] = 365.000000f;
    f[7] = 143.000000f;
    f[8] = 19.2999001f;
    f[9] = 0.00999999978f;
    f[10] = 0.750000000f;
    f[11] = 351.000000f;
    f[12] = 387.000000f;
    f[13] = 0.600000024f;
    f[14] = 0.699999988f;
    f[15] = 348.000000f;
    f[16] = 384.000000f;
}
#pragma section code_type ".text"
#pragma opt_pointer_analysis on
void fn_3_F044(void) {
    u8 *p_lbl_3_rodata_288;
    s16 v0;
    s32 v1;
    s32 v3;
    s16 v2;
    u32 v4;
    struct fn_3_F044_Packet packet;
    p_lbl_3_rodata_288 = (u8 *)&lbl_3_rodata_288;
    v0 = lbl_3_bss_7EDD8.unk_24;
    if (v0 < -15) {
        v1 = -15;
    } else {
        v1 = v0 > 0 ? 0 : v0;
    }
    v2 = (s16)(-(v1 * 62 + 930));
    COPY();
    v3 = v2 + 82;
    packet.id = 0x8927;
    packet.x = v3;
    packet.y = F(0x188);
    packet.z = F(0xfc);
    packet.flags = 10;
    fn_1_50A90(&packet, 7, 0, 104, 104);
    v4 = lbl_3_bss_7EDD8.unk_3C;
    if (v4 < 3) {
        COPY();
        if (v4 == 0) packet.id = 0x891c;
        else if (v4 == 1) packet.id = 0x891d;
        else if (v4 == 2) packet.id = 0x891b;
        packet.x = v2 + 38;
        packet.y = F(0x18c);
        packet.z = F(0x14);
        packet.flags = 5;
        fn_1_4F734((FontDrawPacket *)&packet);
    }
    if (lbl_3_bss_7EDD8.unk_C & 0x03000000) {
        COPY();
        packet.x = v3;
        packet.y = F(0xf8);
        packet.z = F(0x14);
        packet.flags = 10;
        packet.sx = F(0x108);
        packet.sy = F(0x110);
        fn_1_4FC50(&packet, 5, 64, 64, lbl_3_bss_87040 + lbl_3_bss_7EDD8.unk_15 * 0x2060 + 0x80);
    }
    COPY();
    packet.id = 12;
    packet.x = v2 + 375;
    packet.y = F(0x190);
    packet.z = F(0xfc);
    packet.flags = 10;
    fn_1_50A90(&packet, 7, 7, 468, 74);
    COPY();
    packet.id = 12;
    packet.x = F(0x194) + (f32)v2;
    packet.y = F(0x190);
    packet.z = F(0x14);
    fn_1_51678((FontDrawPacket *)&packet, 12, 7, 22, 2, 2);
    packet.sx = F(0x198);
    packet.flags = 5;
    fn_1_4F734((FontDrawPacket *)&packet);
    if (lbl_801A66B4 == 5) {
        fn_1_4AEC0(1);
        fn_1_4954C(F(0x19c));
        fn_1_495C8(8);
        fn_1_495B0(0x80000000);
        fn_1_49590(F(0x3c));
        fn_1_4955C(F(0x1a0), F(0x1a0));
        fn_1_496FC(v2 + 178, F(0x1a4));
        fn_1_4A0D8(TEXT(0));
        fn_1_496FC(v2 + 312, F(0x1a4));
        fn_1_4A0D8(TEXT(0x18));
        fn_1_496FC(v2 + 492, F(0x1a8));
        fn_1_4A0D8(TEXT(0x30));
        fn_1_496FC(v2 + 362, F(0x1a8));
        fn_1_4A0D8(TEXT(0x48));
        fn_1_496FC(v2 + 158, F(0x1a8));
        fn_1_4955C(F(0x1ac), F(0x1b0));
        fn_1_4A0D8(TEXT(0x60));
        fn_1_496FC(v2 + 481, F(0x1a4));
        fn_1_4955C(F(0x1a0), F(0x1a0));
        if (SLOT()->unk_24 & 0x80000000)
            fn_1_4A0D8(TEXT(0x90));
        else
            fn_1_4A0D8(TEXT(0x78));
        fn_1_4AEC0(0);
    } else {
        fn_1_4954C(F(0x19c));
        fn_1_495C8(8);
        fn_1_495B0(0x80000000);
        fn_1_49590(F(0x3c));
        fn_1_4955C(F(0x1ac), F(0x1ac));
        fn_1_496FC(v2 + 163, F(0x1b4));
        fn_1_4A0D8(TEXT(0));
        fn_1_496FC(v2 + 340, F(0x1b4));
        fn_1_4A0D8(TEXT(0x18));
        fn_1_496FC(v2 + 521, F(0x1b8));
        fn_1_4A0D8(TEXT(0x30));
        fn_1_496FC(v2 + 432, F(0x1b8));
        fn_1_4A0D8(TEXT(0x48));
        fn_1_496FC(v2 + 150, F(0x1b8));
        fn_1_4A0D8(TEXT(0x60));
        fn_1_496FC(v2 + 500, F(0x1b4));
        if (SLOT()->unk_24 & 0x80000000)
            fn_1_4A0D8(TEXT(0x90));
        else
            fn_1_4A0D8(TEXT(0x78));
    }
}
/* fzgx:end fn_3_F044 */

/* fzgx:begin fn_3_F878 */
struct fn_3_F878_Vec3 {
    f32 x;
    f32 y;
    f32 z;
};


struct CustomizeData {
    u8 pad34[0x34];
    f32 value34;
    u8 pad1ac[0x174];
    f32 value1ac;
    u8 pad1bc[0xc];
    u32 value1bc;
    f32 value1c0;
};

void fn_3_F878(void) {
    struct GXLightObj second;
    struct fn_3_F878_Vec3 first;
    u32 value;
    f32 scale;
    struct CustomizeData *data;

    data = (struct CustomizeData *)lbl_3_rodata_288;
    lbl_8006DCA4();
    scale = data->value1c0;
    lbl_8006E1D8(&first, scale, scale, scale);
    fn_1_7BCCC(&first);
    fn_80035680(&second, first.x, first.y, first.z);
    fn_80035690(&second, first.x, first.y, first.z);
    fn_80035420(&second, data->value34, 0);
    value = data->value1bc;
    fn_800356AC(&second, &value);
    GXInitLightDistAttn(&second, data->value34, data->value34, 0);
    fn_1_7BB80(&second, 1);
    fn_1_7BD6C(1);
    scale = data->value1ac;
    fn_80074CF4(scale, scale, scale);
}
/* fzgx:end fn_3_F878 */

/* fzgx:begin fn_3_F948 */
typedef struct MemCardSlot {
    u32 unk0;
    u32 flags;
    u8 pad[0x2058];
} MemCardSlot;

s16 fn_3_F948(MemCardSlot *slot) {
    s16 i;
    s16 count = 0;
    i = 0;

    while (i < 4) {
        if (slot->flags & (1u << 31)) {
            count++;
        }
        slot++;
        i++;
    }
    return count;
}
/* fzgx:end fn_3_F948 */

/* fzgx:begin fn_3_11FD0 */
u32 fn_3_11FD0(u32 index, u32 value) {
    return ((u32 *)(lbl_3_data_2F78 + (__cntlzw(value) * 24)))[index];
}
/* fzgx:end fn_3_11FD0 */

/* fzgx:begin fn_3_12910 */
struct fn_3_12910_tbl_ent {
    u8 pad_0[0x8];
    u32 unk_8;
};
struct fn_3_12910_glb {
    u8 pad_0[0xC];
    u32 unk_C;
    u32 unk_10;
    u8 pad_14[0xE];
    s16 unk_22;
    s16 unk_24;
};


#pragma opt_dead_assignments off
void fn_3_12910(void) {
    struct fn_3_12910_glb *p;
    struct fn_3_12910_tbl_ent *t;
    u32 f;
    u32 idx;

    t = (struct fn_3_12910_tbl_ent *)(((u8 *)&lbl_3_data_3234));
    p = (struct fn_3_12910_glb *)(((u8 *)&lbl_3_bss_7EDD8));
    idx = __cntlzw(p->unk_C);
    ((void (*)(void))(*(u32 *)((u8 *)(((u8 *)&lbl_3_data_3234)) + idx * 12 + 8)))();

    f = p->unk_C;
    if (!(f & 0x80000000)) {
        if (f & 0x2000000) {
            s32 v = ((struct fn_3_12910_glb *)(((u8 *)&lbl_3_bss_7EDD8)))->unk_24 - 1;

            ((struct fn_3_12910_glb *)(((u8 *)&lbl_3_bss_7EDD8)))->unk_24 = (v < -15) ? -15 : ((v > 30) ? 30 : v);
        } else if (f & 0x1000000) {
            if (((struct fn_3_12910_glb *)(((u8 *)&lbl_3_bss_7EDD8)))->unk_10 & 0x2000000) {
                s32 v = ((struct fn_3_12910_glb *)(((u8 *)&lbl_3_bss_7EDD8)))->unk_24 + 1;

                ((struct fn_3_12910_glb *)(((u8 *)&lbl_3_bss_7EDD8)))->unk_24 = (v < -15) ? -15 : ((v > 0) ? 0 : v);
            } else {
                s32 v = ((struct fn_3_12910_glb *)(((u8 *)&lbl_3_bss_7EDD8)))->unk_24 - 1;

                ((struct fn_3_12910_glb *)(((u8 *)&lbl_3_bss_7EDD8)))->unk_24 = (v < 0) ? 0 : ((v > 30) ? 30 : v);
            }
        } else if (f & 0x400000) {
            s32 v = ((struct fn_3_12910_glb *)(((u8 *)&lbl_3_bss_7EDD8)))->unk_24 - 1;

            ((struct fn_3_12910_glb *)(((u8 *)&lbl_3_bss_7EDD8)))->unk_24 = (v < 0) ? 0 : ((v > 30) ? 30 : v);
        } else if (!(f & 0x800000)) {
            s32 v = ((struct fn_3_12910_glb *)(((u8 *)&lbl_3_bss_7EDD8)))->unk_24 + 1;

            ((struct fn_3_12910_glb *)(((u8 *)&lbl_3_bss_7EDD8)))->unk_24 = (v < -15) ? -15 : ((v > 30) ? 30 : v);
        }

        f = p->unk_C;
        if (f & 0x40000000) {
            s32 v = ((struct fn_3_12910_glb *)(((u8 *)&lbl_3_bss_7EDD8)))->unk_22 - 1;

            ((struct fn_3_12910_glb *)(((u8 *)&lbl_3_bss_7EDD8)))->unk_22 = (v < 0) ? 0 : ((v > 10) ? 10 : v);
        } else if (f & 0x20000000) {
            s32 v = ((struct fn_3_12910_glb *)(((u8 *)&lbl_3_bss_7EDD8)))->unk_22 + 1;

            ((struct fn_3_12910_glb *)(((u8 *)&lbl_3_bss_7EDD8)))->unk_22 = (v < 0) ? 0 : ((v > 10) ? 10 : v);
        }
    }
}
#pragma opt_dead_assignments reset
/* fzgx:end fn_3_12910 */

/* fzgx:begin fn_3_12E4C */
typedef struct { u32 x; u32 y; u32 z; } fn_3_12E4C_Vec3;
typedef struct { u32 unused0; u32 unused1; fn_3_12E4C_Vec3 first; fn_3_12E4C_Vec3 second; } Data;
typedef struct { u8 pad_000[0x508]; fn_3_12E4C_Vec3 first; fn_3_12E4C_Vec3 second; } SpecialData;
typedef struct {
    u8 pad_000[0x328];
    s8 state;
    u8 pad_329[0x67];
    u32 flags;
    u8 pad_394[0xc];
    s16 *indices;
} Customize;

#pragma opt_strength_reduction off
#pragma opt_common_subs off
void fn_3_12E4C(Customize *self, u8 index, fn_3_12E4C_Vec3 *first, fn_3_12E4C_Vec3 *second) {
    Data *data;
    SpecialData *special;
    u8 state;

    if (self->flags & 0x04000000) {
        data = (Data *)(*(u8 (*)[2400])&lbl_3_data_246C);
        data = (Data *)((u8 *)data +
                        ((u8)((self->indices)[(u32)index * 0x1b0]) << 5));
        *first = data->first;
        *second = data->second;
        return;
    }

    state = self->state;
    if (state == 4) {
        if (index != 0) {
            data = (Data *)((u8 *)(*(u32 (*)[352])&lbl_3_data_1EEC) + 0x560);
            *first = data->first;
            *second = data->second;
            return;
        }
        data = (Data *)((u8 *)(*(u32 (*)[352])&lbl_3_data_1EEC) + ((u8)state << 5));
        *first = data->first;
        *second = data->second;
        return;
    }

    if ((u8)state == 0x28) {
        special = (SpecialData *)((u8 *)(*(u32 (*)[352])&lbl_3_data_1EEC) + ((u8)index << 5));
        *first = special->first;
        *second = special->second;
        return;
    }

    data = (Data *)((u8 *)(*(u32 (*)[352])&lbl_3_data_1EEC) + ((u8)state << 5));
    *first = data->first;
    *second = data->second;
}
#pragma opt_common_subs reset

#pragma opt_strength_reduction reset
/* fzgx:end fn_3_12E4C */

/* fzgx:begin fn_3_12FD4 noprologue */
#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    u8 pad[24];
} Ent;

extern Ent lbl_3_data_1EEC[];
extern Ent lbl_3_data_246C[];

void fn_3_12FD4(u32 arg0, u32 arg1, u32 arg2, f32 *arg3, f32 *arg4) {
    u32 v;
    if (__rlwnm(arg0, 6, 31, 31) != 0) {
        *arg3 = lbl_3_data_246C[(u8)arg2].x;
        *arg4 = lbl_3_data_246C[(u8)arg2].y;
        return;
    }
    v = arg2 & 0xFF;
    if (v == 4) {
        arg2 = 43;
    } else if (v == 40) {
        arg2 = (arg1 + 40) & 0xFF;
    }
    *arg3 = lbl_3_data_1EEC[(u8)arg2].x;
    *arg4 = lbl_3_data_1EEC[(u8)arg2].y;
}
/* fzgx:end fn_3_12FD4 */
