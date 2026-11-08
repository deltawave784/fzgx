#include "types.h"
#include "font.h"

struct ProfileMenuState {
    u8 pad0[0xA];
    s16 language;
    u8 padC[0x40];
    u32 flags;
    u8 pad50[2];
    s16 timer;
    s16 duration;
};
extern struct ProfileMenuState lbl_1_bss_8B614;

typedef struct {
    const char *name;
    f32 unk_4;
    u8 fields_8[0xAC];
} MachineParameterRecord;
extern MachineParameterRecord lbl_1_data_28060[];
extern s32 lbl_1_data_416B8[][3];

typedef struct {
    char unk_0[6][0x40];
    char unk_180[6][0x40];
} fn_16_3BCC_lbl_16_bss_A8_entry;
extern fn_16_3BCC_lbl_16_bss_A8_entry *lbl_16_bss_A8[];

extern const FontDrawPacket lbl_1_rodata_26F8;

extern void fn_1_49410(void);
extern void fn_1_495B0(u32);
extern void fn_1_4965C(u8);
extern void fn_1_4955C(f32, f32);
extern f32 fn_1_4B068(const char *);
extern s32 fn_1_A5DC4(void);
extern void fn_1_50164(FontDrawPacket *, f32, f32, f32, f32);
extern void fn_1_495A0(f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_49514(u32 *);
extern int fn_1_14EE00(s16, void *, s16);

/* the retail TU's .data objects this function uses, at their retail offsets, so MWCC addresses them off one
 * section base; the table's contents do not matter here (nonzero so it stays in .data), and the string
 * literals below land after the last gap, at 0x688, 0x690 and 0x694 */
extern u8 lbl_16_data_82DB0__fzgx_offset_0[];
extern u8 lbl_16_data_82DB4__fzgx_offset_0[];
extern u8 lbl_16_data_82DB8__fzgx_offset_0[];
extern u8 lbl_16_data_82DC0__fzgx_offset_0[];
extern u8 lbl_16_data_82DD0__fzgx_offset_0[];
extern u8 lbl_16_data_82DEC__fzgx_offset_0[];
extern u8 lbl_16_data_82E10__fzgx_offset_0[];
extern u8 lbl_16_data_82E1C__fzgx_offset_0[];
extern u8 lbl_16_data_82E24__fzgx_offset_0[];
extern u8 lbl_16_data_82E3C__fzgx_offset_0[];
extern u8 lbl_16_data_82E48__fzgx_offset_0[];
extern u8 lbl_16_data_82E54__fzgx_offset_0[];
extern u8 lbl_16_data_82E64__fzgx_offset_0[];
extern u8 lbl_16_data_82E70__fzgx_offset_0[];
extern u8 lbl_16_data_82E78__fzgx_offset_0[];
extern u8 lbl_16_data_82E80__fzgx_offset_0[];
extern u8 lbl_16_data_82E88__fzgx_offset_0[];
extern u8 lbl_16_data_82E90__fzgx_offset_0[];
extern u8 lbl_16_data_82E98__fzgx_offset_0[];
extern u8 lbl_16_data_82EA0__fzgx_offset_0[];
extern u8 lbl_16_data_82EA8__fzgx_offset_0[];
extern u8 lbl_16_data_82EB0__fzgx_offset_0[];
extern u8 lbl_16_data_82EBC__fzgx_offset_0[];
extern u8 lbl_16_data_82EC4__fzgx_offset_0[];
extern u8 lbl_16_data_82ECC__fzgx_offset_0[];
extern u8 lbl_16_data_82EDC__fzgx_offset_0[];
extern u8 lbl_16_data_82EE8__fzgx_offset_0[];
extern u8 lbl_16_data_82EF8__fzgx_offset_0[];
extern u8 lbl_16_data_82F08__fzgx_offset_0[];
extern u8 lbl_16_data_82F18__fzgx_offset_0[];
static union { u32 w[1]; char v[4]; } fzgx_pool_init_fzgx_obj_lbl_16_data_82DB0 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4E4F2E00
}};
static union { u32 w[93]; u8 v[0x174]; } fzgx_pool_init_fzgx_pool_gap_82DB4 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0x4E414D45, 0x0, 0x43484152, 0x41435445, 0x52204C49, 0x53540000, 0x53656C65,
    0x63742061, 0x2050696C, 0x6F742074, 0x6F205669, 0x65772E20, 0x0, 0x8CA982BD, 0x82A28370,
    0x8343838D, 0x83628367, 0x82F09149, 0x82F182C5, 0x82AD82BE, 0x82B382A2, 0x81420000, 0x50494C4F,  /* fzgx-allow: A1 retail data bytes */
    0x54204441, 0x54410000, 0x4D414348, 0x494E4500, 0x4D616368, 0x696E6520, 0x496E7472, 0x6F647563,
    0x74696F6E, 0x73000000, 0x837D8356, 0x83938FD0, 0x89EE0000, 0x56696577, 0x204D6F76, 0x69650000,
    0x8380815B, 0x8372815B, 0x82F08CA9, 0x82E90000, 0x526F7461, 0x74696F6E, 0x0, 0x89F1935D,
    0x0, 0x5A6F6F6D, 0x0, 0x8359815B, 0x83800000, 0x4261636B, 0x0, 0x96DF82E9,
    0x0, 0x4D616465, 0x20427900, 0x90BB8DEC, 0x0, 0x456E6769, 0x6E650000, 0x83478393,
    0x83578393, 0x0, 0x57656967, 0x68740000, 0x918D8F64, 0x97CA0000, 0x426F6479, 0x20537472,
    0x656E6774, 0x68000000, 0x837B8366, 0x834290AB, 0x945C0000, 0x426F6F73, 0x74205374, 0x72656E67,
    0x74680000, 0x8375815B, 0x83588367, 0x90AB945C, 0x0, 0x47726970, 0x20537472, 0x656E6774,
    0x68000000, 0x834F838A, 0x83628376, 0x90AB945C, 0x0
}};
static union { u32 w[102]; char *v[17][6]; } fzgx_pool_init_fzgx_obj_lbl_16_data_82F28 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_16_data_82DB0__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB0__fzgx_offset_0, (u32)lbl_16_data_82DB8__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0,
    (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB8__fzgx_offset_0, (u32)lbl_16_data_82DC0__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0,
    (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DC0__fzgx_offset_0, (u32)lbl_16_data_82DD0__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DEC__fzgx_offset_0,
    (u32)lbl_16_data_82E10__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82E10__fzgx_offset_0, (u32)lbl_16_data_82E1C__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0,
    (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82E1C__fzgx_offset_0, (u32)lbl_16_data_82E24__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0,
    (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82E3C__fzgx_offset_0, (u32)lbl_16_data_82E48__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82E54__fzgx_offset_0,
    (u32)lbl_16_data_82E64__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82E70__fzgx_offset_0, (u32)lbl_16_data_82E78__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0,
    (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82E80__fzgx_offset_0, (u32)lbl_16_data_82E88__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0,
    (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82E90__fzgx_offset_0, (u32)lbl_16_data_82E98__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82EA0__fzgx_offset_0,
    (u32)lbl_16_data_82EA8__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82EB0__fzgx_offset_0, (u32)lbl_16_data_82EBC__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0,
    (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82EC4__fzgx_offset_0, (u32)lbl_16_data_82ECC__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0,
    (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82EDC__fzgx_offset_0, (u32)lbl_16_data_82EE8__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82EF8__fzgx_offset_0,
    (u32)lbl_16_data_82F08__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82F18__fzgx_offset_0
}};
static union { u32 w[222]; u8 v[0x378]; } fzgx_pool_init_fzgx_pool_gap_830C0 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x6500, 0x6501, 0x6502, 0x6503, 0x6D00, 0x6D01, 0x6D02, 0x6D03,
    0x8000, 0x8001, 0x8002, 0x8003, 0x5800, 0x5801, 0x5802, 0x5803,
    0x6900, 0x6901, 0x6902, 0x6903, 0x7500, 0x7501, 0x7502, 0x7503,
    0x6400, 0x6401, 0x6402, 0x6403, 0x7400, 0x7401, 0x7402, 0x7403,
    0x6300, 0x6301, 0x6302, 0x6303, 0x6C00, 0x6C01, 0x6C02, 0x6C03,
    0x5A00, 0x5A01, 0x5A02, 0x5A03, 0x6E00, 0x6E01, 0x6E02, 0x6E03,
    0x8200, 0x8201, 0x8202, 0x8203, 0x6B00, 0x6B01, 0x6B02, 0x6B03,
    0x7900, 0x7901, 0x7902, 0x7903, 0x6800, 0x6801, 0x6802, 0x6803,
    0x6A00, 0x6A01, 0x6A02, 0x6A03, 0x5900, 0x5901, 0x5902, 0x5903,
    0x6F00, 0x6F01, 0x6F02, 0x6F03, 0x5700, 0x5701, 0x5702, 0x5703,
    0x7200, 0x7201, 0x7202, 0x7203, 0x7E00, 0x7E01, 0x7E02, 0x7E03,
    0x7300, 0x7301, 0x7302, 0x7303, 0x7100, 0x7101, 0x7102, 0x7103,
    0x5B00, 0x5B01, 0x5B02, 0x5B03, 0x8100, 0x8101, 0x8102, 0x8103,
    0x6200, 0x6201, 0x6202, 0x6203, 0x7A00, 0x7A01, 0x7A02, 0x7A03,
    0x5D00, 0x5D01, 0x5D02, 0x5D03, 0x7C00, 0x7C01, 0x7C02, 0x7C03,
    0x5C00, 0x5C01, 0x5C02, 0x5C03, 0x6100, 0x6101, 0x6102, 0x6103,
    0x6000, 0x6001, 0x6002, 0x6003, 0x5E00, 0x5E01, 0x5E02, 0x5E03,
    0x7F00, 0x7F01, 0x7F02, 0x7F03, 0x5F00, 0x5F01, 0x5F02, 0x5F03,
    0x7700, 0x7701, 0x7702, 0x7703, 0x7000, 0x7001, 0x7002, 0x7003,
    0x7600, 0x7601, 0x7602, 0x7603, 0x7800, 0x7801, 0x7802, 0x7803,
    0x7D00, 0x7D01, 0x7D02, 0x7D03, 0x6700, 0x6701, 0x6702, 0x6703,
    0x7B00, 0x7B01, 0x7B02, 0x7B03, 0x6600, 0x6601, 0x6602, 0x6603,
    0x4A00, 0x5400, 0x3800, 0x3E00, 0x3700, 0x5500, 0x3000, 0x3500,
    0x3A00, 0x4000, 0x4400, 0x5000, 0x3300, 0x2E00, 0x3100, 0x4F00,
    0x3900, 0x3D00, 0x4C00, 0x3F00, 0x4800, 0x5200, 0x4500, 0x5300,
    0x3C00, 0x5600, 0x4300, 0x4200, 0x3200, 0x2F00, 0x3400, 0x3600,
    0x4D00, 0x4600, 0x4100, 0x5100, 0x4E00, 0x4700, 0x3B00, 0x4B00,
    0x4900, 0x25732530, 0x32640000, 0x81F40000, 0x25303264, 0x0
}};

#pragma push
#pragma force_active on
#pragma section code_type ".fzgxpool"
static const union { u32 w[2]; const u32 v[2]; } fzgx_pool_init_fzgx_pool_rodata_58 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0xFFFF0000, 0x41A00000
}};
static void fzgx_pool_primer_a(void) {
    volatile f32 f; /* fzgx-allow: S2 pool primer sink */
    f = 10.0f;
}
static const union { u32 w[5]; const u32 v[5]; } fzgx_pool_init_fzgx_pool_rodata_64 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3F19999A, 0x43E40000, 0x3E000000, 0x40A00000, 0x3FB8E38E
}};
static void fzgx_pool_primer_b(void) {
    volatile f32 f; /* fzgx-allow: S2 pool primer sink */
    f = 1.0f;
}
static const union { u32 w[2]; const u32 v[2]; } fzgx_pool_init_fzgx_pool_rodata_7C = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x42380000, 0x42500000
}};
static void fzgx_pool_primer_c(void) {
    volatile f32 f; /* fzgx-allow: S2 pool primer sink */
    f = 0.5f;
}
static const union { u32 w[6]; const u32 v[6]; } fzgx_pool_init_fzgx_pool_rodata_88 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x428E0000, 0x41B00000, 0x42C40000, 0x42BAC6C7, 0x3F44C4C5, 0x0
}};
static void fzgx_pool_primer_d(void) {
    volatile f64 d; /* fzgx-allow: S2 pool primer sink */
    d = 4503601774854144.0;
}
static const union { u32 w[1]; const u32 v[1]; } fzgx_pool_init_fzgx_pool_rodata_A8 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0xFFFF0000
}};
static void fzgx_pool_primer_e(void) {
    volatile f32 f; /* fzgx-allow: S2 pool primer sink */
    f = 0.0f;
}
static const union { u32 w[6]; const u32 v[6]; } fzgx_pool_init_fzgx_pool_rodata_B0 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x42000000, 0x41E00000, 0x428A0000, 0x43A90000, 0x43FC0000, 0x41C00000
}};
static void fzgx_pool_primer_f(void) {
    volatile f32 f; /* fzgx-allow: S2 pool primer sink */
    f = 8.0f;
}
static const union { u32 w[27]; const u32 v[27]; } fzgx_pool_init_fzgx_pool_rodata_CC = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3F471C72, 0x429E0000, 0x43AB8000, 0x431B0000, 0x43B68000, 0xFFFF0000, 0x42300000, 0x43780000,
    0x40C00000, 0xFFFF0000, 0x43F00000, 0x430E0000, 0x436C0000, 0x42CC0000, 0x42D60000, 0x3F200000,
    0x430D0000, 0x40E00000, 0x43360B61, 0x43340000, 0x43060000, 0x3DCCCCCD, 0x3F40C0C1, 0x3E99999A,
    0x43B40000, 0x43300000, 0x0
}};
#pragma pop

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define clamp01(v) ((v) < 0.0f ? 0.0f : ((v) > 1.0f ? 1.0f : (v)))

static inline char *fn_16_3BCC_array_read(char **array, s32 index) {
    return array[index];
}

/* row `row` of the .data 0x82F28 text table, in the current language */
#define LABEL(row) fn_16_3BCC_array_read(fzgx_pool_init_fzgx_obj_lbl_16_data_82F28.v[row], lbl_1_bss_8B614.language)

/* a part letter of .data 0x416B8 (1 A to 5 E) as the odd grade fn_1_14EE00 prints; any other value keeps the
 * previous grade */
#define SET_GRADE(letter)  \
    switch (letter) {      \
    case 0:                \
        grade = 1;         \
        break;             \
    case 1:                \
        grade = 1;         \
        break;             \
    case 2:                \
        grade = 3;         \
        break;             \
    case 3:                \
        grade = 5;         \
        break;             \
    case 4:                \
        grade = 7;         \
        break;             \
    case 5:                \
        grade = 9;         \
        break;             \
    }

void fn_16_3BCC(s16 arg0, s16 x, s16 y) {
    f32 top;
    FontDrawPacket packet;
    f32 labelWidth;
    f32 valueWidth;
    f32 width;
    f32 alpha;
    f32 left;
    char buffer[32];
    f32 innerLeft;
    f32 innerTop;
    f32 t;
    f32 half;
    f32 height;
    s16 grade;
    s16 shift;
    s32 h;

    shift = 0;
    fn_1_49410();
    fn_1_495B0(0x80000000);
    fn_1_4965C(2);
    fn_1_4955C(0.5f, 0.5f);
    labelWidth = MAX(fn_1_4B068(LABEL(11)), fn_1_4B068(LABEL(12)));
    labelWidth = MAX(labelWidth, fn_1_4B068(LABEL(13)));
    labelWidth = MAX(labelWidth, fn_1_4B068(LABEL(14)));
    labelWidth = MAX(labelWidth, fn_1_4B068(LABEL(15)));
    labelWidth = MAX(labelWidth, fn_1_4B068(LABEL(16)));
    valueWidth = MAX(fn_1_4B068(lbl_16_bss_A8[arg0]->unk_180[lbl_1_bss_8B614.language]),
                     fn_1_4B068(lbl_16_bss_A8[arg0]->unk_0[lbl_1_bss_8B614.language]));
    valueWidth = MAX(valueWidth, fn_1_4B068("1000kg"));
    if ((s8)fn_1_A5DC4()) {
        shift = 94;
    }
    width = 10.0f + (10.0f + (19.0f + (labelWidth + valueWidth)));
    height = 92.0f;
    if (lbl_1_bss_8B614.flags & 0x80000000) {
        if (lbl_1_bss_8B614.flags & 0x10000000) {
            t = clamp01((f32)lbl_1_bss_8B614.timer / ((f32)lbl_1_bss_8B614.duration / 2.0f));
            half = (f32)lbl_1_bss_8B614.duration / 2.0f;
            h = (s32)(17.0f + (f32)(75.0f * t));
            alpha = clamp01(((f32)lbl_1_bss_8B614.timer - half) / half);
        } else if (lbl_1_bss_8B614.flags & 0x08000000) {
            half = (f32)lbl_1_bss_8B614.duration / 2.0f;
            t = clamp01(((f32)lbl_1_bss_8B614.timer - half) / half);
            h = (s32)(17.0f + (f32)(75.0f * (1.0f - t)));
            alpha = 1.0f - clamp01((f32)lbl_1_bss_8B614.timer / half);
        } else {
            h = (s32)height;
            alpha = 1.0f;
        }
    } else {
        h = (s32)height;
        alpha = 1.0f;
    }
    packet = lbl_1_rodata_26F8;
    packet.image = 12;
    packet.x = (f32)shift + (left = (f32)x - width);
    packet.y = top = (f32)y - height;
    packet.z = 10.0f;
    fn_1_50164(&packet, width, (f32)(s16)h, 8.0f, 8.0f);
    fn_1_495A0(alpha);
    innerTop = 10.0f + top;
    innerLeft = 10.0f + left;
    fn_1_496FC((f32)shift + innerLeft, innerTop);
    fn_1_4AE0C("%s\n", LABEL(11));
    fn_1_4AE0C("%s\n", LABEL(12));
    fn_1_4AE0C("%s\n", LABEL(13));
    fn_1_4AE0C("%s\n", LABEL(14));
    fn_1_4AE0C("%s\n", LABEL(15));
    fn_1_4AE0C("%s\n", LABEL(16));
    fn_1_496FC((f32)shift + (19.0f + (labelWidth + innerLeft)), innerTop);
    fn_1_4AE0C("%s\n", lbl_16_bss_A8[arg0]->unk_180[lbl_1_bss_8B614.language]);
    fn_1_4AE0C("%s\n", lbl_16_bss_A8[arg0]->unk_0[lbl_1_bss_8B614.language]);
    fn_1_4AE0C("%4dkg\n", (s16)lbl_1_data_28060[arg0].unk_4);
    {
        u8 color[4] = {0xFF, 0xFF, 0x00, 0x00};
        fn_1_49514((u32 *)color);
    }
    SET_GRADE(lbl_1_data_416B8[arg0][0]);
    fn_1_4AE0C("%s\n", (const char *)fn_1_14EE00(grade, buffer, lbl_1_bss_8B614.language));
    SET_GRADE(lbl_1_data_416B8[arg0][1]);
    fn_1_4AE0C("%s\n", (const char *)fn_1_14EE00(grade, buffer, lbl_1_bss_8B614.language));
    SET_GRADE(lbl_1_data_416B8[arg0][2]);
    fn_1_4AE0C("%s\n", (const char *)fn_1_14EE00(grade, buffer, lbl_1_bss_8B614.language));
}
