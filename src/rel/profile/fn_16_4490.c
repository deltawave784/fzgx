typedef signed short s16;
typedef signed long s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef float f32;

typedef struct FontDrawPacket FontDrawPacket;
typedef struct FontVertex {
    f32 x, y, z;
} FontVertex;
struct FontDrawPacket {
    u32 image;
    f32 x, y, z;
    f32 scale_x, scale_y;
    f32 u0, v0, u1, v1;
    s16 rotation_z, rotation_y;
    f32 alpha;
    u32 flags;
    f32 depth;
    u8 color[4], color_add[4];
    u32 format;
    u16 width, height;
    void *pixels;
    FontDrawPacket *secondary;
    void (*vertex_callback)(FontDrawPacket *packet, FontVertex *vertices);
    u32 unk_54;
};
int fn_1_4F734(FontDrawPacket *packet);
void fn_1_4AE0C(const char *format, ...);

extern FontDrawPacket lbl_1_rodata_26F8;
extern u8 lbl_16_data_830C0[704];
extern u8 lbl_16_data_83440[28];
extern u8 lbl_1_bss_8B614[];
extern u8 *lbl_1_data_212A8[];
extern void fn_16_2528(FontDrawPacket *packet, FontVertex *vertices);
extern s16 fn_1_12C930(s16);
extern void fn_1_51564(u16, u16, u16, u16, u16, u16);
extern void fn_1_5158C(FontDrawPacket *, u32, s16, s16);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_495C8(u8);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_4962C(void);
extern void fn_1_495A0(f32);
extern void fn_1_49514(u32 *);
extern void fn_1_49738(void (*)(FontDrawPacket *, FontVertex *));
extern u32 strlen(const u8 *);
extern f32 fn_1_4B040(const u8 *);
extern void fn_1_4955C(f32, f32);

/* The TU's shared literal pool (lbl_16_rodata_58), primed in retail order: raw table words
 * between the primer functions, and the function's own literals (1.0f at +0x20, the
 * 2^52+2^31 int-to-float constant at +0x48, 70.0f at +0x124) emitted by the primers. */
static const union { u32 w[8]; const u32 v[8]; } fzgx_pool_init_fzgx_pool_rodata_lbl_16_rodata_58 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0xFFFF0000, 0x41A00000, 0x41200000, 0x3F19999A, 0x43E40000, 0x3E000000, 0x40A00000, 0x3FB8E38E
}};
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_16_rodata_58_a(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .rodata objects in retail order */
    volatile f32 f;  /* fzgx-allow: S2 layout primer sink for the native literal */
    s = *(u8 *)fzgx_pool_init_fzgx_pool_rodata_lbl_16_rodata_58.v;
    f = 1.0f;
}
#pragma section code_type ".text"
static const union { u32 w[9]; const u32 v[9]; } fzgx_pool_init_fzgx_pool_rodata_lbl_16_rodata_58_24 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x42380000, 0x42500000, 0x3F000000, 0x428E0000, 0x41B00000, 0x42C40000, 0x42BAC6C7,
    0x3F44C4C5, 0x0
}};
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_16_rodata_58_b(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .rodata objects in retail order */
    volatile s32 n;  /* fzgx-allow: S2 layout primer source for the int-to-float constant */
    volatile f32 f;  /* fzgx-allow: S2 layout primer sink for the int-to-float constant */
    s = *(u8 *)fzgx_pool_init_fzgx_pool_rodata_lbl_16_rodata_58_24.v;
    f = (f32)n;
}
#pragma section code_type ".text"
static const union { u32 w[1]; const u32 v[1]; } fzgx_pool_init_fzgx_pool_rodata_lbl_16_rodata_58_50 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0xFFFF0000
}};
static const union { u32 w[40]; const u32 v[40]; } fzgx_pool_init_fzgx_pool_rodata_lbl_16_rodata_AC = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0x42000000, 0x41E00000, 0x428A0000, 0x43A90000, 0x43FC0000, 0x41C00000, 0x41000000,
    0x3F471C72, 0x429E0000, 0x43AB8000, 0x431B0000, 0x43B68000, 0xFFFF0000, 0x42300000, 0x43780000,
    0x40C00000, 0xFFFF0000, 0x43F00000, 0x430E0000, 0x436C0000, 0x42CC0000, 0x42D60000, 0x3F200000,
    0x430D0000, 0x40E00000, 0x43360B61, 0x43340000, 0x43060000, 0x3DCCCCCD, 0x3F40C0C1, 0x3E99999A,
    0x43B40000, 0x43300000, 0x0, 0xFFFF0000, 0x41980000, 0x41880000, 0x42960000, 0x42B80000
}};
static const union { u32 w[1]; const u32 v[1]; } fzgx_pool_init_fzgx_pool_rodata_lbl_16_rodata_58_F4 = {{ 0xFFFF00 }};  /* fzgx-allow: A1 retail data bytes and bindings */
static const union { u32 w[1]; const u32 v[1]; } fzgx_pool_init_fzgx_pool_rodata_lbl_16_rodata_58_F8 = {{ 0xFFFF00 }};  /* fzgx-allow: A1 retail data bytes and bindings */
static const union { u32 w[1]; const u32 v[1]; } fzgx_pool_init_fzgx_pool_rodata_lbl_16_rodata_58_FC = {{ 0xFFFF00 }};  /* fzgx-allow: A1 retail data bytes and bindings */
static const union { u32 w[1]; const u32 v[1]; } fzgx_pool_init_fzgx_pool_rodata_lbl_16_rodata_58_100 = {{ 0xFFFF00 }};  /* fzgx-allow: A1 retail data bytes and bindings */
static const union { u32 w[1]; const u32 v[1]; } fzgx_pool_init_fzgx_pool_rodata_lbl_16_rodata_58_104 = {{ 0xFFFF00 }};  /* fzgx-allow: A1 retail data bytes and bindings */
static const union { u32 w[1]; const u32 v[1]; } fzgx_pool_init_fzgx_pool_rodata_lbl_16_rodata_58_108 = {{ 0xFFFF00 }};  /* fzgx-allow: A1 retail data bytes and bindings */
static const union { u32 w[1]; const u32 v[1]; } fzgx_pool_init_fzgx_pool_rodata_lbl_16_rodata_58_10C = {{ 0xFFFF00 }};  /* fzgx-allow: A1 retail data bytes and bindings */
static const union { u32 w[1]; const u32 v[1]; } fzgx_pool_init_fzgx_pool_rodata_lbl_16_rodata_58_110 = {{ 0x3F400000 }};  /* fzgx-allow: A1 retail data bytes and bindings */
static const union { u32 w[1]; const u32 v[1]; } fzgx_pool_init_fzgx_pool_rodata_lbl_16_rodata_58_114 = {{ 0x42140000 }};  /* fzgx-allow: A1 retail data bytes and bindings */
static const union { u32 w[1]; const u32 v[1]; } fzgx_pool_init_fzgx_pool_rodata_lbl_16_rodata_58_118 = {{ 0x42940000 }};  /* fzgx-allow: A1 retail data bytes and bindings */
static const union { u32 w[1]; const u32 v[1]; } fzgx_pool_init_fzgx_pool_rodata_lbl_16_rodata_58_11C = {{ 0x41D00000 }};  /* fzgx-allow: A1 retail data bytes and bindings */
static const union { u32 w[1]; const u32 v[1]; } fzgx_pool_init_fzgx_pool_rodata_lbl_16_rodata_58_120 = {{ 0x427C0000 }};  /* fzgx-allow: A1 retail data bytes and bindings */
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_16_rodata_58_c(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .rodata objects in retail order */
    volatile f32 f;  /* fzgx-allow: S2 layout primer sink for the native literal */
    s = *(u8 *)fzgx_pool_init_fzgx_pool_rodata_lbl_16_rodata_58_50.v;
    s = *(u8 *)fzgx_pool_init_fzgx_pool_rodata_lbl_16_rodata_AC.v;
    s = *(u8 *)fzgx_pool_init_fzgx_pool_rodata_lbl_16_rodata_58_F4.v;
    s = *(u8 *)fzgx_pool_init_fzgx_pool_rodata_lbl_16_rodata_58_F8.v;
    s = *(u8 *)fzgx_pool_init_fzgx_pool_rodata_lbl_16_rodata_58_FC.v;
    s = *(u8 *)fzgx_pool_init_fzgx_pool_rodata_lbl_16_rodata_58_100.v;
    s = *(u8 *)fzgx_pool_init_fzgx_pool_rodata_lbl_16_rodata_58_104.v;
    s = *(u8 *)fzgx_pool_init_fzgx_pool_rodata_lbl_16_rodata_58_108.v;
    s = *(u8 *)fzgx_pool_init_fzgx_pool_rodata_lbl_16_rodata_58_10C.v;
    s = *(u8 *)fzgx_pool_init_fzgx_pool_rodata_lbl_16_rodata_58_110.v;
    s = *(u8 *)fzgx_pool_init_fzgx_pool_rodata_lbl_16_rodata_58_114.v;
    s = *(u8 *)fzgx_pool_init_fzgx_pool_rodata_lbl_16_rodata_58_118.v;
    s = *(u8 *)fzgx_pool_init_fzgx_pool_rodata_lbl_16_rodata_58_11C.v;
    s = *(u8 *)fzgx_pool_init_fzgx_pool_rodata_lbl_16_rodata_58_120.v;
    f = 70.0f;
}
#pragma section code_type ".text"
static const union { u32 w[23]; const u32 v[23]; } fzgx_pool_init_fzgx_pool_rodata_lbl_16_rodata_58_128 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0xFFFF00, 0xFFFF00, 0xFFFF00, 0xFFFF00, 0xFFFF00, 0xFFFF00, 0x43A00000,
    0x43580000, 0x42F40000, 0x43480000, 0x43980000, 0x42200000, 0x44160000, 0x3DCCCCD0, 0x3EAE147A,
    0xC2CC0000, 0x3F666666, 0x3F28F5C3, 0x3F638E39, 0x42BE0000, 0x40000000, 0x423C0000, 0x41800000
}};
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_16_rodata_58_d(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .rodata objects in retail order */
    s = *(u8 *)fzgx_pool_init_fzgx_pool_rodata_lbl_16_rodata_58_128.v;
}
#pragma section code_type ".text"

#define POOL_U32(name) (*(const u32 *)fzgx_pool_init_fzgx_pool_rodata_lbl_16_rodata_58_##name.v)
#define POOL_F32(name) (*(const f32 *)fzgx_pool_init_fzgx_pool_rodata_lbl_16_rodata_58_##name.v)
#define PACKET_COLOR(p) (*(u32 *)(p).color)
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

/* lap counter: 30 means "none"; above 30 is already 1-based */
#define LAP_NUMBER(x) (((x) == 30) ? 0 : (((x) > 30) ? (x) : (x) + 1))

void fn_16_4490(f32 alpha, f32 scale, f32 scale2, s16 index, s16 x, s16 y, s16 z) {
    f32 digit_y;
    s32 number;
    s16 digit;
    s16 i;
    u32 color;
    u8 name[64];
    FontDrawPacket packet;

    packet = lbl_1_rodata_26F8;
    packet.image = 0x8919;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.alpha = alpha;
    packet.flags = 0x0400000f;
    packet.vertex_callback = fn_16_2528;
    PACKET_COLOR(packet) = POOL_U32(F4);
    packet.scale_x *= scale;
    packet.scale_y *= scale;
    fn_1_4F734(&packet);

    packet = lbl_1_rodata_26F8;
    packet.image = 0x8919;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.alpha = alpha;
    packet.flags = 0x0408000d;
    packet.vertex_callback = fn_16_2528;
    PACKET_COLOR(packet) = POOL_U32(F8);
    packet.scale_x *= scale;
    packet.scale_y *= scale;
    fn_1_4F734(&packet);

    packet = lbl_1_rodata_26F8;
    packet.image = 0x8919;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.alpha = alpha;
    packet.flags = 0x04100007;
    packet.vertex_callback = fn_16_2528;
    PACKET_COLOR(packet) = POOL_U32(FC);
    packet.scale_x *= scale;
    packet.scale_y *= scale;
    fn_1_4F734(&packet);

    packet = lbl_1_rodata_26F8;
    packet.image = 0x8919;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.alpha = alpha;
    packet.flags = 0x04180005;
    packet.vertex_callback = fn_16_2528;
    PACKET_COLOR(packet) = POOL_U32(100);
    packet.scale_x *= scale;
    packet.scale_y *= scale;
    fn_1_4F734(&packet);

    packet = lbl_1_rodata_26F8;
    packet.image = ((u32 (*)[4])lbl_16_data_830C0)[fn_1_12C930(index)][*(s16 *)(lbl_1_bss_8B614 + 0x30)];
    packet.x = x;
    packet.y = y;
    packet.z = z - 1;
    packet.alpha = alpha;
    packet.flags = 0x0400000a;
    packet.vertex_callback = fn_16_2528;
    packet.scale_x *= POOL_F32(110);
    packet.scale_y *= POOL_F32(110);
    packet.scale_x *= scale2;
    packet.scale_y *= scale2;
    fn_1_4F734(&packet);

    number = LAP_NUMBER(index);
    packet = lbl_1_rodata_26F8;
    packet.image = 0x891a;
    packet.x = x - (f32)(POOL_F32(114) * scale);
    digit_y = y - (f32)(POOL_F32(118) * scale);
    packet.y = digit_y;
    packet.z = z;
    packet.alpha = alpha;
    packet.flags = 0x04000005;
    packet.vertex_callback = fn_16_2528;
    PACKET_COLOR(packet) = POOL_U32(104);
    packet.scale_x *= scale;
    packet.scale_y *= scale;
    fn_1_51564(0, 0, 12, 16, 10, 1);
    digit = number / 10;
    fn_1_5158C(&packet, packet.image, (s16)(digit % 10), (s16)(digit / 10));
    fn_1_4F734(&packet);

    number = LAP_NUMBER(index);
    packet = lbl_1_rodata_26F8;
    packet.image = 0x891a;
    packet.x = x - (f32)(POOL_F32(11C) * scale);
    packet.y = digit_y;
    packet.z = z;
    packet.alpha = alpha;
    packet.flags = 0x04000005;
    packet.vertex_callback = fn_16_2528;
    PACKET_COLOR(packet) = POOL_U32(108);
    packet.scale_x *= scale;
    packet.scale_y *= scale;
    fn_1_51564(0, 0, 12, 16, 10, 1);
    digit = number % 10;
    fn_1_5158C(&packet, packet.image, (s16)(digit % 10), (s16)(digit / 10));
    fn_1_4F734(&packet);

    fn_1_49410();
    fn_1_494DC(9);
    fn_1_495C8(1);
    fn_1_496FC(x, y + (f32)(POOL_F32(120) * scale));
    fn_1_4954C(z);
    fn_1_4962C();
    fn_1_495A0(alpha);
    color = POOL_U32(10C);
    fn_1_49514(&color);
    fn_1_49738(fn_16_2528);
    for (i = 0; i < strlen(lbl_1_data_212A8[fn_1_12C930(index)]); i++) {
        if (lbl_1_data_212A8[fn_1_12C930(index)][i] == 0x26) name[i] = 0x5f;
        else if (lbl_1_data_212A8[fn_1_12C930(index)][i] == 0x8145u) name[i] = 0x5e;
        else if (lbl_1_data_212A8[fn_1_12C930(index)][i] == 0x2d) name[i] = 0x5c;
        else if (lbl_1_data_212A8[fn_1_12C930(index)][i] == 0x2e) name[i] = 0x5b;
        else name[i] = lbl_1_data_212A8[fn_1_12C930(index)][i];
    }
    name[i] = 0;
    fn_1_4955C(MIN(70.0f / fn_1_4B040(name), 1.0f), 1.0f);
    fn_1_4AE0C((const char *)lbl_16_data_83440, name);
}
