#include "types.h"
#include "game/main_rel/effect_types.h"
#include "dolphin/types.h"
#include "game/main_rel/car_test_types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/effect.h"
#include "psvec.h"

struct P {
    u8 pad_0[0xC];
    f32 unk_C;
    u8 pad_10[0x18];
    f32 unk_28;
    u8 pad_2C[0xC];
    f64 unk_38;
    u8 pad_40[0x20];
    f32 unk_60;
    f32 unk_64;
    u8 pad_68[0xC];
    f32 unk_74;
    u8 pad_78[0x54];
    f32 unk_CC;
    f32 unk_D0;
    f32 unk_D4;
    f32 unk_D8;
    f32 unk_DC;
};

typedef struct Fn620C8Viewport {
    f32 x;
    f32 y;
    f32 w;
    f32 h;
    f32 near;
    f32 far;
} Fn620C8Viewport;

typedef struct Obj {
    u8 b0;
    u8 pad1[0xF];
    s32 n10;
    u8 pad14[4];
    s16 id18;
    u8 pad1a[0x0E];
    f32 f28;
    f32 f2c;
    u8 pad30[0x0C];
    f32 m3c[3];
    f32 f48;
    f32 f4c;
    f32 f50;
    s16 s54;
    u8 pad56[4];
    s16 s5a;
    u8 pad5c[0x38];
    f32 p94[3];
    u8 pada0[0x14];
    f32 fb4;
} Obj;

typedef struct Fn620C8Model {
    u8 pad_0[0x8];
    u8 data[0xC];
    f32 scale;
} Fn620C8Model;

typedef struct Fn620C8TexObj {
    u32 dummy[8];
    void *image;
} Fn620C8TexObj;

typedef struct Fn620C8Obj {
    u8 pad_0[0x28];
    f32 time;
    u8 pad_2C[0x8];
    Fn620C8Model *model;
    Fn620C8TexObj *tex;
    u8 rot[0x78];
    f32 brightness;
    Fn183D28Vec3 pos;
} Fn620C8Obj;
extern u32 fn_1_3FC58(void);
extern void *memset(void *, int, u32);
extern void *memcpy(void *, const void *, u32);
extern const f32 lbl_1_rodata_2950;
extern u32 fn_1_86514(int index);
extern void fn_1_867CC(s16 value, void *out);
extern u8 fn_1_86634(int index);
extern u32 fn_1_6EC0(u8 index);
extern s16 camera_get_entry_field_0xa4(u32 index);
extern void lbl_8006D9D8(void *);
extern void lbl_8006D7B0(void);
extern f32 lbl_8006D0B4(f32 value);
extern void lbl_8006DB74(void *);
extern void lbl_8006D848(f32);
extern void lbl_8006DFC4(void *);
extern int fn_1_9F914(const void *src0, const void *src1);
extern void lbl_8006DCA4();
extern s32 fn_1_54E34(void *arg0, f32 arg1);
extern void *fn_1_5448C(void *);
extern void fn_1_5489C(void **arg0, void **arg1);
extern void fn_1_862D4(s16 value, void *result);
extern void *fn_1_548AC(u32 size);
extern void *lbl_801A6410;
extern s32 fn_1_45D0();
extern u32 lbl_1_bss_6C864;
extern void fn_1_8636C();
extern void *lbl_8006DC6C(void *);
extern void lbl_8006DBAC(void *);
extern u32 lbl_8006DA50(void);
extern void lbl_8006DF44(void);
extern void fn_1_56000(u8 value0, u8 value1, u8 value2);
extern void fn_1_5621C(f32 value0, f32 value1, f32 value2, f32 value3);
extern void fn_1_556B8(void *value);
extern void fn_80038F10(f32* out);
extern u32 fn_80038EEC();
extern u32 fn_80074188(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
extern void lbl_8006E0A4(void *);
extern void lbl_8006E14C(f32);
extern void mathutil_mtxA_rotate_x(s16 value);
extern void fn_80072558(void);
extern void fn_80074918(u8 arg0, s32 arg1, u8 arg2);
extern void fn_80074300();
extern void fn_80074438(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
extern void fn_8003526C(void *, u8);
extern void GXInitTexObj(void *, void *, u16, u16, s32, s32, s32, u8);
extern s32 fn_1_66B8(void *, f32);
extern void *lbl_801A6D00;
extern void fn_1_8645C(int index, void *arg);
extern void fn_8006FA24(void *, void *, void *, f32);
extern void mathutil_mtxA_rotate_z(int);
extern void mathutil_mtxA_rotate_y(s16 value);
extern const f32 lbl_1_rodata_2AA0[21];
extern f32 lbl_1_rodata_29AC[5];
extern void fn_1_55FC4(f32 value);
extern void fn_1_55FF0(f32 value);
extern void fn_1_5557C(void *object);
extern void fn_1_555D0(void *object);
extern u32 GXGetTexBufferSize(u16, u16, u32, u32, u8);
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern void fn_1_4730(u32 value, u32 count, u32 size, const char *file, int line);
extern void lbl_8006D7DC(void *obj);
extern void *fn_1_868C0(s8 index);
extern void *fn_1_86254(int index);
extern void lbl_8006D95C(s32);
extern void fn_1_3BDC(u32 arg0);
extern u32 fn_1_3C18(s32 arg0);
extern void fn_80008BEC(void *dest, int value, u32 size);
extern void fn_80008BA8(void *, void *, int);
extern void fn_1_680F8(void);
extern void fn_1_68284(void);
extern void fn_1_68B68(void);
extern void fn_1_68248(void);
extern void fn_1_69BBC(void);
extern void fn_1_69BCC(void);
extern f32 lbl_1_rodata_2978[4];
extern f32 lbl_1_rodata_2AF4[14];
extern void fn_1_5EB98(void);
extern f32 lbl_1_rodata_2A5C[5];
extern int fn_1_61D08();
extern int fn_1_61EF4();
extern void fn_1_620C4(void);
extern f32 lbl_1_rodata_2B2C[145];
extern void fn_1_638E8(void);
extern const f32 lbl_1_rodata_2A70[12];
extern void fn_1_64388(void);
extern void fn_1_65748(void);
extern int fn_1_61E60();
extern u32 fn_1_3FC8C(void);
extern const f32 lbl_1_rodata_29A4;
extern f64 lbl_1_rodata_2988;
extern void fn_1_620C8(Fn620C8Obj *obj);
extern f32 fn_1_8652C(int index);
extern void fn_1_557C4(void *value);
extern const f32 lbl_1_rodata_29C0;
extern const f32 lbl_1_rodata_29F0;
extern s32 fn_1_58C4(void);
extern const f64 lbl_1_rodata_2954;

/* fzgx:begin fn_1_584D4 noprologue */
#include "types.h"

typedef struct AvlineEntry {
    s8 unk_00;
    u8 _pad01;
    s16 unk_02;
    s16 unk_04;
    u8 _pad06[0xe2];
} AvlineEntry;

typedef struct AvlineState {
    AvlineEntry *unk_00;
    AvlineEntry *unk_04;
    s16 unk_08;
    u8 _pad0a[2];
    s32 unk_0c;
    s32 unk_10;
} AvlineState;

extern u32 lbl_801A6410[];
extern u8 lbl_1_bss_6C848[];
extern u8 lbl_1_data_1D62C[148];
extern AvlineEntry *fn_1_4630(u32, u32, u8 *, u32);
extern void fn_1_9F7DC(void);
extern void fn_1_58114(void);

static inline AvlineEntry * fn_1_584D4_read_pointer(AvlineState * owner) { return owner->unk_00; }
void fn_1_584D4(void) {
    AvlineState *state = (AvlineState *)&lbl_1_bss_6C848;
    s32 id;
    s32 count;
    AvlineEntry *entry;

    state->unk_00 = fn_1_4630(lbl_801A6410[0], sizeof(AvlineEntry) * 0xbe, lbl_1_data_1D62C, 0xc1);
    state->unk_04 = fn_1_4630(lbl_801A6410[0], sizeof(AvlineEntry) * 0xc8, lbl_1_data_1D62C, 0xc2);
    entry = fn_1_584D4_read_pointer(state);
    state->unk_08 = 0;
    id = 0;
    for (count = 0xbe; count > 0; count--) {
        entry->unk_02 = id++;
        entry->unk_04 = -1;
        entry++;
    }
    entry = state->unk_04;
    id = 0;
    for (count = 0xc8; count > 0; count--) {
        entry->unk_02 = id++;
        entry->unk_04 = -1;
        entry++;
    }

    fn_1_9F7DC();
    fn_1_58114();
    state->unk_0c = 0;
    state->unk_10 = 0;
}
/* fzgx:end fn_1_584D4 */

/* fzgx:begin fn_1_58994 noprologue */
#include "types.h"

typedef struct EffectVec3 {
    u32 x;
    u32 y;
    u32 z;
} EffectVec3;

typedef struct EffectEntry {
    s8 unk_00;
    u8 _pad01[0x07];
    u32 unk_08;
    s16 unk_0c;
    u8 _pad0e[0x0c];
    u16 unk_1a;
    u8 _pad1c[0x20];
    EffectVec3 unk_3c;
    u8 _pad48[0x18];
    EffectVec3 unk_60;
    u8 _pad6c[0x7c];
} EffectEntry;

typedef struct EffectState {
    EffectEntry *unk_00;
    EffectEntry *unk_04;
    u8 _pad08[0x04];
    u32 unk_0c;
} EffectState;

typedef void (*EffectHandler)(EffectEntry *);

typedef struct EffectData {
    u8 _pad000[0xd68];
    EffectHandler update[0x45];
    EffectHandler destroy[0x45];
    u32 unk_f90;
} EffectData;

extern EffectData lbl_1_data_1C698;
extern EffectState lbl_1_bss_6C848;

extern void fn_1_3BDC(s32);
extern s32 fn_1_3F164(void);
extern void fn_1_9F8FC(void);
extern void fn_1_5819C(void);
extern u32 fn_1_58C4(void);
extern u32 camera_forward_status(void);
extern void fn_1_63518(EffectEntry *);
extern u32 fn_1_3C18(s32);

extern u8 fn_1_5942C__fzgx_offset_0[];
extern u8 fn_1_5944C__fzgx_offset_0[];
extern u8 fn_1_5946C__fzgx_offset_0[];
extern u8 fn_1_5948C__fzgx_offset_0[];
extern u8 fn_1_594AC__fzgx_offset_0[];
extern u8 fn_1_594CC__fzgx_offset_0[];
extern u8 fn_1_594EC__fzgx_offset_0[];
extern u8 fn_1_594F0__fzgx_offset_0[];
extern u8 fn_1_594F4__fzgx_offset_0[];
extern u8 fn_1_594F8__fzgx_offset_0[];
extern u8 fn_1_594FC__fzgx_offset_0[];
extern u8 fn_1_59500__fzgx_offset_0[];
extern u8 fn_1_59504__fzgx_offset_0[];
extern u8 fn_1_59508__fzgx_offset_0[];
extern u8 fn_1_5950C__fzgx_offset_0[];
extern u8 fn_1_59510__fzgx_offset_0[];
extern u8 fn_1_59514__fzgx_offset_0[];
extern u8 fn_1_5962C__fzgx_offset_0[];
extern u8 fn_1_59770__fzgx_offset_0[];
extern u8 fn_1_59A70__fzgx_offset_0[];
extern u8 fn_1_59A74__fzgx_offset_0[];
extern u8 fn_1_59B00__fzgx_offset_0[];
extern u8 fn_1_59B90__fzgx_offset_0[];
extern u8 fn_1_59CC4__fzgx_offset_0[];
extern u8 fn_1_59CC8__fzgx_offset_0[];
extern u8 fn_1_59D54__fzgx_offset_0[];
extern u8 fn_1_59EE4__fzgx_offset_0[];
extern u8 fn_1_5A8CC__fzgx_offset_0[];
extern u8 fn_1_5A8D0__fzgx_offset_0[];
extern u8 fn_1_5A8DC__fzgx_offset_0[];
extern u8 fn_1_5ABC4__fzgx_offset_0[];
extern u8 fn_1_5ABC8__fzgx_offset_0[];
extern u8 fn_1_5ABCC__fzgx_offset_0[];
extern u8 fn_1_5AC48__fzgx_offset_0[];
extern u8 fn_1_5AF28__fzgx_offset_0[];
extern u8 fn_1_5B074__fzgx_offset_0[];
extern u8 fn_1_5B078__fzgx_offset_0[];
extern u8 fn_1_5B188__fzgx_offset_0[];
extern u8 fn_1_5B30C__fzgx_offset_0[];
extern u8 fn_1_5B3CC__fzgx_offset_0[];
extern u8 fn_1_5B3D0__fzgx_offset_0[];
extern u8 fn_1_5B450__fzgx_offset_0[];
extern u8 fn_1_5B578__fzgx_offset_0[];
extern u8 fn_1_5B6F0__fzgx_offset_0[];
extern u8 fn_1_5B6F4__fzgx_offset_0[];
extern u8 fn_1_5B780__fzgx_offset_0[];
extern u8 fn_1_5B7F8__fzgx_offset_0[];
extern u8 fn_1_5BF6C__fzgx_offset_0[];
extern u8 fn_1_5BF70__fzgx_offset_0[];
extern u8 fn_1_5BFF0__fzgx_offset_0[];
extern u8 fn_1_5C058__fzgx_offset_0[];
extern u8 fn_1_5C780__fzgx_offset_0[];
extern u8 fn_1_5C784__fzgx_offset_0[];
extern u8 fn_1_5C83C__fzgx_offset_0[];
extern u8 fn_1_5CA00__fzgx_offset_0[];
extern u8 fn_1_5D010__fzgx_offset_0[];
extern u8 fn_1_5D014__fzgx_offset_0[];
extern u8 fn_1_5D020__fzgx_offset_0[];
extern u8 fn_1_5D1B8__fzgx_offset_0[];
extern u8 fn_1_5D374__fzgx_offset_0[];
extern u8 fn_1_5D378__fzgx_offset_0[];
extern u8 fn_1_5D4FC__fzgx_offset_0[];
extern u8 fn_1_5D500__fzgx_offset_0[];
extern u8 fn_1_5D718__fzgx_offset_0[];
extern u8 fn_1_5D88C__fzgx_offset_0[];
extern u8 fn_1_5D918__fzgx_offset_0[];
extern u8 fn_1_5D91C__fzgx_offset_0[];
extern u8 fn_1_5DFA4__fzgx_offset_0[];
extern u8 fn_1_5E3C4__fzgx_offset_0[];
extern u8 fn_1_5E4D8__fzgx_offset_0[];
extern u8 fn_1_5EB08__fzgx_offset_0[];
extern u8 fn_1_5F5C4__fzgx_offset_0[];
extern u8 fn_1_5F5C8__fzgx_offset_0[];
extern u8 fn_1_5F654__fzgx_offset_0[];
extern u8 fn_1_5F9B8__fzgx_offset_0[];
extern u8 fn_1_5FE24__fzgx_offset_0[];
extern u8 fn_1_5FE28__fzgx_offset_0[];
extern u8 fn_1_5FE2C__fzgx_offset_0[];
extern u8 fn_1_5FE30__fzgx_offset_0[];
extern u8 fn_1_5FFAC__fzgx_offset_0[];
extern u8 fn_1_5FFB0__fzgx_offset_0[];
extern u8 fn_1_60170__fzgx_offset_0[];
extern u8 fn_1_601B4__fzgx_offset_0[];
extern u8 fn_1_6028C__fzgx_offset_0[];
extern u8 fn_1_60734__fzgx_offset_0[];
extern u8 fn_1_60880__fzgx_offset_0[];
extern u8 fn_1_60B80__fzgx_offset_0[];
extern u8 fn_1_60C70__fzgx_offset_0[];
extern u8 fn_1_60C74__fzgx_offset_0[];
extern u8 fn_1_60C84__fzgx_offset_0[];
extern u8 fn_1_60C88__fzgx_offset_0[];
extern u8 fn_1_60D54__fzgx_offset_0[];
extern u8 fn_1_60F7C__fzgx_offset_0[];
extern u8 fn_1_60F80__fzgx_offset_0[];
extern u8 fn_1_60F84__fzgx_offset_0[];
extern u8 fn_1_61070__fzgx_offset_0[];
extern u8 fn_1_611EC__fzgx_offset_0[];
extern u8 fn_1_61370__fzgx_offset_0[];
extern u8 fn_1_61640__fzgx_offset_0[];
extern u8 fn_1_61760__fzgx_offset_0[];
extern u8 fn_1_617A4__fzgx_offset_0[];
extern u8 fn_1_618B8__fzgx_offset_0[];
extern u8 fn_1_619E4__fzgx_offset_0[];
extern u8 fn_1_61C84__fzgx_offset_0[];
extern u8 fn_1_61C88__fzgx_offset_0[];
extern u8 fn_1_61CA8__fzgx_offset_0[];
extern u8 fn_1_61CC8__fzgx_offset_0[];
extern u8 fn_1_61CE8__fzgx_offset_0[];
extern u8 fn_1_62AF8__fzgx_offset_0[];
extern u8 fn_1_62C84__fzgx_offset_0[];
extern u8 fn_1_62E9C__fzgx_offset_0[];
extern u8 fn_1_6312C__fzgx_offset_0[];
extern u8 fn_1_63130__fzgx_offset_0[];
extern u8 fn_1_6313C__fzgx_offset_0[];
extern u8 fn_1_632D4__fzgx_offset_0[];
extern u8 fn_1_633BC__fzgx_offset_0[];
extern u8 fn_1_633C0__fzgx_offset_0[];
extern u8 fn_1_63514__fzgx_offset_0[];
extern u8 fn_1_635BC__fzgx_offset_0[];
extern u8 fn_1_63858__fzgx_offset_0[];
extern u8 fn_1_64098__fzgx_offset_0[];
extern u8 fn_1_640A4__fzgx_offset_0[];
extern u8 fn_1_642E8__fzgx_offset_0[];
extern u8 fn_1_645C8__fzgx_offset_0[];
extern u8 fn_1_645CC__fzgx_offset_0[];
extern u8 fn_1_645D0__fzgx_offset_0[];
extern u8 fn_1_645D4__fzgx_offset_0[];
extern u8 fn_1_64760__fzgx_offset_0[];
extern u8 fn_1_648D4__fzgx_offset_0[];
extern u8 fn_1_648D8__fzgx_offset_0[];
extern u8 fn_1_648DC__fzgx_offset_0[];
extern u8 fn_1_64E1C__fzgx_offset_0[];
extern u8 fn_1_64F2C__fzgx_offset_0[];
extern u8 fn_1_64FB8__fzgx_offset_0[];
extern u8 fn_1_65268__fzgx_offset_0[];
extern u8 fn_1_65420__fzgx_offset_0[];
extern u8 fn_1_65424__fzgx_offset_0[];
extern u8 fn_1_654B0__fzgx_offset_0[];
extern u8 fn_1_656C8__fzgx_offset_0[];
extern u8 fn_1_65AAC__fzgx_offset_0[];
extern u8 fn_1_65AB0__fzgx_offset_0[];
extern u8 fn_1_65B58__fzgx_offset_0[];
extern u8 fn_1_65B5C__fzgx_offset_0[];
extern u8 fn_1_65CDC__fzgx_offset_0[];
extern u8 fn_1_65E58__fzgx_offset_0[];
extern u8 fn_1_65E88__fzgx_offset_0[];
extern u8 fn_1_65E8C__fzgx_offset_0[];
extern u8 fn_1_660EC__fzgx_offset_0[];
extern u8 fn_1_66254__fzgx_offset_0[];
extern u8 fn_1_662D4__fzgx_offset_0[];
extern u8 fn_1_662D8__fzgx_offset_0[];
extern u8 fn_1_67294__fzgx_offset_0[];
extern u8 fn_1_67414__fzgx_offset_0[];
extern u8 fn_1_6742C__fzgx_offset_0[];
extern u8 fn_1_67430__fzgx_offset_0[];
extern u8 fn_1_6755C__fzgx_offset_0[];
extern u8 fn_1_6766C__fzgx_offset_0[];
extern u8 fn_1_6767C__fzgx_offset_0[];
extern u8 fn_1_67680__fzgx_offset_0[];
extern u8 fn_1_67D0C__fzgx_offset_0[];
extern u8 fn_1_67E94__fzgx_offset_0[];
extern u8 fn_1_67F20__fzgx_offset_0[];
extern u8 fn_1_68054__fzgx_offset_0[];
extern u8 fn_1_680F4__fzgx_offset_0[];
extern u8 lbl_1_data_1CC68__fzgx_offset_0[];
extern u8 lbl_1_data_1CC78__fzgx_offset_0[];
extern u8 lbl_1_data_1CC8C__fzgx_offset_0[];
extern u8 lbl_1_data_1CC9C__fzgx_offset_0[];
extern u8 lbl_1_data_1CCAC__fzgx_offset_0[];
extern u8 lbl_1_data_1CCC0__fzgx_offset_0[];
extern u8 lbl_1_data_1CCD0__fzgx_offset_0[];
extern u8 lbl_1_data_1CCE4__fzgx_offset_0[];
extern u8 lbl_1_data_1CCFC__fzgx_offset_0[];
extern u8 lbl_1_data_1CD14__fzgx_offset_0[];
extern u8 lbl_1_data_1CD30__fzgx_offset_0[];
extern u8 lbl_1_data_1CD48__fzgx_offset_0[];
extern u8 lbl_1_data_1CD60__fzgx_offset_0[];
extern u8 lbl_1_data_1CD7C__fzgx_offset_0[];
extern u8 lbl_1_data_1CD88__fzgx_offset_0[];
extern u8 lbl_1_data_1CD98__fzgx_offset_0[];
extern u8 lbl_1_data_1CDA8__fzgx_offset_0[];
extern u8 lbl_1_data_1CDB8__fzgx_offset_0[];
extern u8 lbl_1_data_1CDCC__fzgx_offset_0[];
extern u8 lbl_1_data_1CDE0__fzgx_offset_0[];
extern u8 lbl_1_data_1CDF4__fzgx_offset_0[];
extern u8 lbl_1_data_1CE04__fzgx_offset_0[];
extern u8 lbl_1_data_1CE10__fzgx_offset_0[];
extern u8 lbl_1_data_1CE20__fzgx_offset_0[];
extern u8 lbl_1_data_1CE30__fzgx_offset_0[];
extern u8 lbl_1_data_1CE44__fzgx_offset_0[];
extern u8 lbl_1_data_1CE58__fzgx_offset_0[];
extern u8 lbl_1_data_1CE68__fzgx_offset_0[];
extern u8 lbl_1_data_1CE78__fzgx_offset_0[];
extern u8 lbl_1_data_1CE8C__fzgx_offset_0[];
extern u8 lbl_1_data_1CE9C__fzgx_offset_0[];
extern u8 lbl_1_data_1CEB0__fzgx_offset_0[];
extern u8 lbl_1_data_1CEC8__fzgx_offset_0[];
extern u8 lbl_1_data_1CEDC__fzgx_offset_0[];
extern u8 lbl_1_data_1CEF0__fzgx_offset_0[];
extern u8 lbl_1_data_1CF08__fzgx_offset_0[];
extern u8 lbl_1_data_1CF1C__fzgx_offset_0[];
extern u8 lbl_1_data_1CF30__fzgx_offset_0[];
extern u8 lbl_1_data_1CF4C__fzgx_offset_0[];
extern u8 lbl_1_data_1CF58__fzgx_offset_0[];
extern u8 lbl_1_data_1CF6C__fzgx_offset_0[];
extern u8 lbl_1_data_1CF78__fzgx_offset_0[];
extern u8 lbl_1_data_1CF84__fzgx_offset_0[];
extern u8 lbl_1_data_1CF90__fzgx_offset_0[];
extern u8 lbl_1_data_1CF9C__fzgx_offset_0[];
extern u8 lbl_1_data_1CFA8__fzgx_offset_0[];
extern u8 lbl_1_data_1CFB4__fzgx_offset_0[];
extern u8 lbl_1_data_1CFC0__fzgx_offset_0[];
extern u8 lbl_1_data_1CFCC__fzgx_offset_0[];
extern u8 lbl_1_data_1CFD8__fzgx_offset_0[];
extern u8 lbl_1_data_1CFE4__fzgx_offset_0[];
extern u8 lbl_1_data_1CFF0__fzgx_offset_0[];
extern u8 lbl_1_data_1CFFC__fzgx_offset_0[];
extern u8 lbl_1_data_1D008__fzgx_offset_0[];
extern u8 lbl_1_data_1D014__fzgx_offset_0[];
extern u8 lbl_1_data_1D020__fzgx_offset_0[];
extern u8 lbl_1_data_1D02C__fzgx_offset_0[];
extern u8 lbl_1_data_1D038__fzgx_offset_0[];
extern u8 lbl_1_data_1D044__fzgx_offset_0[];
extern u8 lbl_1_data_1D050__fzgx_offset_0[];
extern u8 lbl_1_data_1D05C__fzgx_offset_0[];
extern u8 lbl_1_data_1D068__fzgx_offset_0[];
extern u8 lbl_1_data_1D074__fzgx_offset_0[];
extern u8 lbl_1_data_1D080__fzgx_offset_0[];
extern u8 lbl_1_data_1D08C__fzgx_offset_0[];
extern u8 lbl_1_data_1D098__fzgx_offset_0[];
extern u8 lbl_1_data_1D0A4__fzgx_offset_0[];
extern u8 lbl_1_data_1D0B0__fzgx_offset_0[];
extern u8 lbl_1_data_1D0BC__fzgx_offset_0[];
static u32 fzgx_pool_native_lbl_1_data_1C698_gap_0[858] = {0x00000000, 0x00000001, 0x00000002, 0x00000003, 0x00000004, 0x00000005, 0x00000006, 0x00000007, 0x00000008, 0x00000009, 0x0000000A, 0x0000000B, 0x0000000C, 0x0000000D, 0x0000000E, 0x0000000F, 0x00000010, 0x00000011, 0x00000012, 0x00000013, 0x00000014, 0x00000015, 0x00000016, 0x00000017, 0x00000018, 0x00000019, 0x0000001A, 0x0000001B, 0x0000001C, 0x0000001D, 0x0000001E, 0x0000001F, 0x00000020, 0x00000021, 0x00000022, 0x00000023, 0x00000024, 0x00000025, 0x00000026, 0x00000027, 0x00000028, 0x00000029, 0x0000002A, 0x0000002B, 0x0000002C, 0x0000002D, 0x0000002E, 0x0000002F, 0x00000030, 0x00000031, 0x00000032, 0x00000033, 0x00000034, 0x00000035, 0x00000036, 0x00000037, 0x00000038, 0x00000039, 0x0000003A, 0x0000003B, 0x0000003C, 0x0000003D, 0x0000003E, 0x0000003F, 0x00000040, 0x00000041, 0x00000042, 0x00000043, 0x00000044, 0x00000045, 0x00000046, 0x00000047, 0x00000048, 0x00000049, 0x0000004A, 0x0000004B, 0x0000004C, 0x0000004D, 0x0000004E, 0x0000004F, 0x00000050, 0x00000051, 0x00000052, 0x00000053, 0x00000054, 0x00000055, 0x00000056, 0x00000057, 0x00000058, 0x00000059, 0x0000005A, 0x0000005B, 0x0000005C, 0x0000005D, 0x0000005E, 0x0000005F, 0x00000060, 0x00000061, 0x00000062, 0x00000063, 0x00000064, 0x00000065, 0x00000066, 0x00000067, 0x00000068, 0x00000069, 0x0000006A, 0x0000006B, 0x0000006C, 0x0000006D, 0x0000006E, 0x0000006F, 0x00000070, 0x00000071, 0x00000072, 0x00000073, 0x00000074, 0x00000075, 0x00000076, 0x00000077, 0x00000078, 0x00000079, 0x0000007A, 0x0000007B, 0x0000007C, 0x0000007D, 0x0000007E, 0x0000007F, 0x00000080, 0x00000081, 0x00000082, 0x00000083, 0x00000084, 0x00000085, 0x00000086, 0x00000087, 0x00000088, 0x00000089, 0x0000008A, 0x0000008B, 0x0000008C, 0x0000008D, 0x0000008E, 0x0000008F, 0x00000090, 0x00000091, 0x00000092, 0x00000093, 0x00000094, 0x00000095, 0x00000096, 0x00000097, 0x00000098, 0x00000099, 0x0000009A, 0x0000009B, 0x0000009C, 0x0000009D, 0x0000009E, 0x0000009F, 0x000000A0, 0x000000A1, 0x000000A2, 0x000000A3, 0x000000A4, 0x000000A5, 0x000000A6, 0x000000A7, 0x000000A8, 0x000000A9, 0x000000AA, 0x000000AB, 0x000000AC, 0x000000AD, 0x000000AE, 0x000000AF, 0x000000B0, 0x000000B1, 0x000000B2, 0x000000B3, 0x000000B4, 0x000000B5, 0x000000B6, 0x000000B7, 0x000000B8, 0x000000B9, 0x000000BA, 0x000000BB, 0x000000BC, 0x000000BD, 0x000000BE, 0x000000BF, 0x000000C0, 0x000000C1, 0x000000C2, 0x000000C3, 0x000000C4, 0x000000C5, 0x000000C6, 0x000000C7, 0x000000C8, 0x000000C9, 0x000000CA, 0x000000CB, 0x000000CC, 0x000000CD, 0x000000CE, 0x000000CF, 0x000000D0, 0x000000D1, 0x000000D2, 0x000000D3, 0x000000D4, 0x000000D5, 0x000000D6, 0x000000D7, 0x000000D8, 0x000000D9, 0x000000DA, 0x000000DB, 0x000000DC, 0x000000DD, 0x000000DE, 0x000000DF, 0x000000E0, 0x000000E1, 0x000000E2, 0x000000E3, 0x000000E4, 0x000000E5, 0x000000E6, 0x000000E7, 0x000000E8, 0x000000E9, 0x00000000, 0x00000001, 0x00000002, 0x00000003, 0x00000004, 0x00000005, 0x00000006, 0x00000007, 0x00000008, 0x00000009, 0x0000000A, 0x0000000B, 0x0000000C, 0x0000000D, 0x0000000E, 0x0000000F, 0x00000010, 0x00000011, 0x00000012, 0x00000013, 0x00000014, 0x00000015, 0x00000016, 0x00000000, 0x00000017, 0x0000001A, 0x0000001B, 0x0000001C, 0x0000001D, 0x0000001E, 0x0000001F, 0x00000020, 0x00000021, 0x00000022, 0x00000018, 0x00000019, 0x00000023, 0x00000024, 0x00000025, 0x00000026, 0x00000027, 0x00000028, 0x00000029, 0x0000002A, 0x0000002B, 0x0000002C, 0x0000002D, 0x0000002E, 0x0000002F, 0x00000030, 0x00000031, 0x00000032, 0x00000033, 0x00000034, 0x00000035, 0x00000036, 0x00000037, 0x00000038, 0x00000039, 0x0000003A, 0x0000003B, 0x0000003C, 0x0000003D, 0x0000003E, 0x0000003F, 0x00000040, 0x00000041, 0x00000042, 0x00000043, 0x00000044, 0x00000045, 0x00000046, 0x00000047, 0x00000048, 0x00000049, 0x0000004A, 0x0000004B, 0x0000004C, 0x0000004D, 0x0000004E, 0x0000004F, 0x00000050, 0x00000051, 0x00000052, 0x00000053, 0x00000054, 0x00000055, 0x00000056, 0x00000057, 0x00000058, 0x00000059, 0x0000005A, 0x0000005B, 0x0000005C, 0x0000005D, 0x0000005E, 0x0000005F, 0x00000060, 0x00000061, 0x00000062, 0x00000063, 0x00000064, 0x00000065, 0x00000066, 0x00000067, 0x00000068, 0x00000069, 0x0000006A, 0x0000006B, 0x0000006C, 0x0000006D, 0x0000006E, 0x0000006F, 0x00000070, 0x00000071, 0x00000072, 0x00000073, 0x00000074, 0x00000075, 0x00000076, 0x00000077, 0x00000078, 0x00000079, 0x0000007A, 0x0000007B, 0x0000007C, 0x0000007D, 0x0000007E, 0x0000007F, 0x00000080, 0x00000081, 0x00000082, 0x00000083, 0x00000084, 0x00000085, 0x00000086, 0x00000087, 0x00000088, 0x00000000, 0xBF800000, 0x00000000, (u32)lbl_1_data_1CC68__fzgx_offset_0, 0x45545F43, 0x4F4C495F, 0x50415254, 0x49434C45, 0x00000000, 0x45545F43, 0x41525F45, 0x46464543, 0x54000000, 0x45545F44, 0x52494654, 0x5F505443, 0x4C000000, 0x45545F43, 0x41525354, 0x41425F53, 0x52495030, 0x31000000, 0x45545F43, 0x41525F43, 0x4F4C4950, 0x00000000, 0x45545F43, 0x41525F54, 0x48554E44, 0x45523031, 0x00000000, 0x45545F52, 0x4F434B45, 0x545F5354, 0x4152545F, 0x45335343, 0x4E000000, 0x45545F52, 0x53544152, 0x545F4533, 0x53434E5F, 0x5054434C, 0x00000000, 0x45545F52, 0x53544152, 0x545F4533, 0x53434E5F, 0x5054434C, 0x46524147, 0x00000000, 0x45545F52, 0x53544152, 0x545F4533, 0x53434E5F, 0x52494E47, 0x00000000, 0x45545F43, 0x41525F46, 0x524F4E54, 0x5F544855, 0x4E444552, 0x00000000, 0x45545F43, 0x41525F46, 0x524F4E54, 0x5F544855, 0x4E444552, 0x5F4F5554, 0x00000000, 0x45545F43, 0x41525F42, 0x454C5400, 0x45545F43, 0x41525F53, 0x4D4F4B45, 0x00000000, 0x45545F43, 0x41525F52, 0x45504149, 0x52000000, 0x45545F43, 0x41525F53, 0x5041524B, 0x00000000, 0x45545F43, 0x41525F54, 0x48554E44, 0x45523032, 0x00000000, 0x45545F43, 0x41525F54, 0x48554E44, 0x45523033, 0x00000000, 0x45545F43, 0x41525F45, 0x4D455247, 0x454E4359, 0x00000000, 0x45545F42, 0x475F5448, 0x554E4445, 0x52303100, 0x45545F43, 0x41525F4C, 0x45414600, 0x45545F43, 0x41525F48, 0x49544D41, 0x524B0000, 0x45545F43, 0x41525F48, 0x49544D41, 0x524B3200, 0x45545F43, 0x41525F54, 0x5552424F, 0x5F454E44, 0x00000000, 0x45545F43, 0x41525F4A, 0x554D505F, 0x5054434C, 0x00000000, 0x45545F48, 0x424F4152, 0x445F504C, 0x414E4500, 0x45545F43, 0x41525F57, 0x41544552, 0x00000000, 0x45545F43, 0x41525F57, 0x41544552, 0x5F534D4F, 0x4B450000, 0x45545F43, 0x41525F53, 0x50494E5F, 0x41544B00, 0x45545F43, 0x41525F42, 0x5245414B, 0x5F534D4F, 0x4B450000, 0x45545F43, 0x41525F42, 0x5245414B, 0x5F535441, 0x52545F50, 0x54434C00, 0x45545F43, 0x41525F42, 0x5245414B, 0x5F505443, 0x4C000000, 0x45545F43, 0x41525F42, 0x5245414B, 0x5F42414C, 0x4C000000, 0x45545F43, 0x41525F42, 0x5245414B, 0x5F42414C, 0x4C5F424F, 0x4D420000, 0x45545F43, 0x41525F42, 0x4F4D425F, 0x46495245, 0x00000000, 0x45545F43, 0x41525F42, 0x4F4D425F, 0x4D495353, 0x494C4500, 0x45545F43, 0x41525F42, 0x4F4D425F, 0x4D495353, 0x494C455F, 0x534D4F4B, 0x45000000, 0x45545F43, 0x41525F55, 0x464F0000, 0x45545F43, 0x41525F42, 0x4F4D425F, 0x4354524C, 0x00000000, 0x45545F43, 0x41525F44, 0x49525400, 0x45545F44, 0x4D593030, 0x31000000, 0x45545F44, 0x4D593030, 0x32000000, 0x45545F44, 0x4D593030, 0x33000000, 0x45545F44, 0x4D593030, 0x34000000, 0x45545F54, 0x4D503030, 0x31000000, 0x45545F54, 0x4D503030, 0x32000000, 0x45545F54, 0x4D503030, 0x33000000, 0x45545F54, 0x4D503030, 0x34000000, 0x45545F54, 0x4D503030, 0x35000000, 0x45545F54, 0x4D503030, 0x36000000, 0x45545F54, 0x4D503030, 0x37000000, 0x45545F54, 0x4D503030, 0x38000000, 0x45545F54, 0x4D503030, 0x39000000, 0x45545F54, 0x4D503031, 0x30000000, 0x45545F54, 0x4D503031, 0x31000000, 0x45545F54, 0x4D503031, 0x32000000, 0x45545F54, 0x4D503031, 0x33000000, 0x45545F54, 0x4D503031, 0x34000000, 0x45545F54, 0x4D503031, 0x35000000, 0x45545F54, 0x4D503031, 0x36000000, 0x45545F54, 0x4D503031, 0x37000000, 0x45545F54, 0x4D503031, 0x38000000, 0x45545F54, 0x4D503031, 0x39000000, 0x45545F54, 0x4D503032, 0x30000000, 0x45545F54, 0x4D503032, 0x31000000, 0x45545F54, 0x4D503032, 0x32000000, 0x45545F54, 0x4D503032, 0x33000000, 0x45545F54, 0x4D503032, 0x34000000, (u32)lbl_1_data_1CC78__fzgx_offset_0, (u32)lbl_1_data_1CC8C__fzgx_offset_0, (u32)lbl_1_data_1CC9C__fzgx_offset_0, (u32)lbl_1_data_1CCAC__fzgx_offset_0, (u32)lbl_1_data_1CCC0__fzgx_offset_0, (u32)lbl_1_data_1CCD0__fzgx_offset_0, (u32)lbl_1_data_1CCE4__fzgx_offset_0, (u32)lbl_1_data_1CCFC__fzgx_offset_0, (u32)lbl_1_data_1CD14__fzgx_offset_0, (u32)lbl_1_data_1CD30__fzgx_offset_0, (u32)lbl_1_data_1CD48__fzgx_offset_0, (u32)lbl_1_data_1CD60__fzgx_offset_0, (u32)lbl_1_data_1CD7C__fzgx_offset_0, (u32)lbl_1_data_1CD88__fzgx_offset_0, (u32)lbl_1_data_1CD98__fzgx_offset_0, (u32)lbl_1_data_1CDA8__fzgx_offset_0, (u32)lbl_1_data_1CDB8__fzgx_offset_0, (u32)lbl_1_data_1CDCC__fzgx_offset_0, (u32)lbl_1_data_1CDE0__fzgx_offset_0, (u32)lbl_1_data_1CDF4__fzgx_offset_0, (u32)lbl_1_data_1CE04__fzgx_offset_0, (u32)lbl_1_data_1CE10__fzgx_offset_0, (u32)lbl_1_data_1CE20__fzgx_offset_0, (u32)lbl_1_data_1CE30__fzgx_offset_0, (u32)lbl_1_data_1CE44__fzgx_offset_0, (u32)lbl_1_data_1CE58__fzgx_offset_0, (u32)lbl_1_data_1CE68__fzgx_offset_0, (u32)lbl_1_data_1CE78__fzgx_offset_0, (u32)lbl_1_data_1CE8C__fzgx_offset_0, (u32)lbl_1_data_1CE9C__fzgx_offset_0, (u32)lbl_1_data_1CEB0__fzgx_offset_0, (u32)lbl_1_data_1CEC8__fzgx_offset_0, (u32)lbl_1_data_1CEDC__fzgx_offset_0, (u32)lbl_1_data_1CEF0__fzgx_offset_0, (u32)lbl_1_data_1CF08__fzgx_offset_0, (u32)lbl_1_data_1CF1C__fzgx_offset_0, (u32)lbl_1_data_1CF30__fzgx_offset_0, (u32)lbl_1_data_1CF4C__fzgx_offset_0, (u32)lbl_1_data_1CF58__fzgx_offset_0, (u32)lbl_1_data_1CF6C__fzgx_offset_0, (u32)lbl_1_data_1CF78__fzgx_offset_0, (u32)lbl_1_data_1CF84__fzgx_offset_0, (u32)lbl_1_data_1CF90__fzgx_offset_0, (u32)lbl_1_data_1CF9C__fzgx_offset_0, (u32)lbl_1_data_1CFA8__fzgx_offset_0, (u32)lbl_1_data_1CFB4__fzgx_offset_0, (u32)lbl_1_data_1CFC0__fzgx_offset_0, (u32)lbl_1_data_1CFCC__fzgx_offset_0, (u32)lbl_1_data_1CFD8__fzgx_offset_0, (u32)lbl_1_data_1CFE4__fzgx_offset_0, (u32)lbl_1_data_1CFF0__fzgx_offset_0, (u32)lbl_1_data_1CFFC__fzgx_offset_0, (u32)lbl_1_data_1D008__fzgx_offset_0, (u32)lbl_1_data_1D014__fzgx_offset_0, (u32)lbl_1_data_1D020__fzgx_offset_0, (u32)lbl_1_data_1D02C__fzgx_offset_0, (u32)lbl_1_data_1D038__fzgx_offset_0, (u32)lbl_1_data_1D044__fzgx_offset_0, (u32)lbl_1_data_1D050__fzgx_offset_0, (u32)lbl_1_data_1D05C__fzgx_offset_0, (u32)lbl_1_data_1D068__fzgx_offset_0, (u32)lbl_1_data_1D074__fzgx_offset_0, (u32)lbl_1_data_1D080__fzgx_offset_0, (u32)lbl_1_data_1D08C__fzgx_offset_0, (u32)lbl_1_data_1D098__fzgx_offset_0, (u32)lbl_1_data_1D0A4__fzgx_offset_0, (u32)lbl_1_data_1D0B0__fzgx_offset_0, (u32)lbl_1_data_1D0BC__fzgx_offset_0, (u32)fn_1_59504__fzgx_offset_0, (u32)fn_1_5942C__fzgx_offset_0, (u32)fn_1_59514__fzgx_offset_0, (u32)fn_1_59A74__fzgx_offset_0, (u32)fn_1_594AC__fzgx_offset_0, (u32)fn_1_59CC8__fzgx_offset_0, (u32)fn_1_5A8D0__fzgx_offset_0, (u32)fn_1_5ABCC__fzgx_offset_0, (u32)fn_1_5B078__fzgx_offset_0, (u32)fn_1_5B3D0__fzgx_offset_0, (u32)fn_1_5B6F4__fzgx_offset_0, (u32)fn_1_5BF70__fzgx_offset_0, (u32)fn_1_5C784__fzgx_offset_0, (u32)fn_1_5D014__fzgx_offset_0, (u32)fn_1_5D378__fzgx_offset_0, (u32)fn_1_5D88C__fzgx_offset_0, (u32)fn_1_5E3C4__fzgx_offset_0, (u32)fn_1_5F5C8__fzgx_offset_0, (u32)fn_1_5FE28__fzgx_offset_0, (u32)fn_1_5FFB0__fzgx_offset_0, (u32)fn_1_60734__fzgx_offset_0, (u32)fn_1_60C74__fzgx_offset_0, (u32)fn_1_60F7C__fzgx_offset_0, (u32)fn_1_611EC__fzgx_offset_0, (u32)fn_1_617A4__fzgx_offset_0, (u32)fn_1_61C88__fzgx_offset_0, (u32)fn_1_62AF8__fzgx_offset_0, (u32)fn_1_63130__fzgx_offset_0, (u32)fn_1_633C0__fzgx_offset_0, (u32)fn_1_64098__fzgx_offset_0, (u32)fn_1_645CC__fzgx_offset_0, (u32)fn_1_648D4__fzgx_offset_0, (u32)fn_1_64F2C__fzgx_offset_0, (u32)fn_1_65424__fzgx_offset_0, (u32)fn_1_65AB0__fzgx_offset_0, (u32)fn_1_6766C__fzgx_offset_0, (u32)fn_1_67E94__fzgx_offset_0, (u32)fn_1_65E58__fzgx_offset_0, (u32)fn_1_66254__fzgx_offset_0, (u32)fn_1_67414__fzgx_offset_0, (u32)fn_1_594F4__fzgx_offset_0, (u32)fn_1_594F4__fzgx_offset_0, (u32)fn_1_594F4__fzgx_offset_0, (u32)fn_1_594F4__fzgx_offset_0, (u32)fn_1_594F4__fzgx_offset_0, (u32)fn_1_594F4__fzgx_offset_0, (u32)fn_1_594F4__fzgx_offset_0, (u32)fn_1_594F4__fzgx_offset_0, (u32)fn_1_594F4__fzgx_offset_0, (u32)fn_1_594F4__fzgx_offset_0, (u32)fn_1_594F4__fzgx_offset_0, (u32)fn_1_594F4__fzgx_offset_0, (u32)fn_1_594F4__fzgx_offset_0, (u32)fn_1_594F4__fzgx_offset_0, (u32)fn_1_594F4__fzgx_offset_0, (u32)fn_1_594F4__fzgx_offset_0, (u32)fn_1_594F4__fzgx_offset_0, (u32)fn_1_594F4__fzgx_offset_0, (u32)fn_1_594F4__fzgx_offset_0, (u32)fn_1_594F4__fzgx_offset_0, (u32)fn_1_594F4__fzgx_offset_0, (u32)fn_1_594F4__fzgx_offset_0, (u32)fn_1_594F4__fzgx_offset_0, (u32)fn_1_594F4__fzgx_offset_0, (u32)fn_1_594F4__fzgx_offset_0, (u32)fn_1_594F4__fzgx_offset_0, (u32)fn_1_594F4__fzgx_offset_0, (u32)fn_1_594F4__fzgx_offset_0, 0x00000000, (u32)fn_1_59508__fzgx_offset_0, (u32)fn_1_5944C__fzgx_offset_0, (u32)fn_1_5962C__fzgx_offset_0, (u32)fn_1_59B00__fzgx_offset_0, (u32)fn_1_594CC__fzgx_offset_0, (u32)fn_1_59D54__fzgx_offset_0, (u32)fn_1_5A8DC__fzgx_offset_0, (u32)fn_1_5AC48__fzgx_offset_0, (u32)fn_1_5B188__fzgx_offset_0, (u32)fn_1_5B450__fzgx_offset_0, (u32)fn_1_5B780__fzgx_offset_0, (u32)fn_1_5BFF0__fzgx_offset_0, (u32)fn_1_5C83C__fzgx_offset_0, (u32)fn_1_5D020__fzgx_offset_0, (u32)fn_1_5D500__fzgx_offset_0, (u32)fn_1_5D91C__fzgx_offset_0, (u32)fn_1_5E4D8__fzgx_offset_0, (u32)fn_1_5F654__fzgx_offset_0, (u32)fn_1_5FE2C__fzgx_offset_0, (u32)fn_1_601B4__fzgx_offset_0, (u32)fn_1_60880__fzgx_offset_0, (u32)fn_1_60C88__fzgx_offset_0, (u32)fn_1_60F84__fzgx_offset_0, (u32)fn_1_61370__fzgx_offset_0, (u32)fn_1_618B8__fzgx_offset_0, (u32)fn_1_61CA8__fzgx_offset_0, (u32)fn_1_62C84__fzgx_offset_0, (u32)fn_1_6313C__fzgx_offset_0, (u32)fn_1_635BC__fzgx_offset_0, (u32)fn_1_640A4__fzgx_offset_0, (u32)fn_1_645D4__fzgx_offset_0, (u32)fn_1_648DC__fzgx_offset_0, (u32)fn_1_64FB8__fzgx_offset_0, (u32)fn_1_654B0__fzgx_offset_0, (u32)fn_1_65B5C__fzgx_offset_0, (u32)fn_1_67680__fzgx_offset_0, (u32)fn_1_67F20__fzgx_offset_0, (u32)fn_1_65E8C__fzgx_offset_0, (u32)fn_1_662D8__fzgx_offset_0, (u32)fn_1_67430__fzgx_offset_0, (u32)fn_1_594F8__fzgx_offset_0, (u32)fn_1_594F8__fzgx_offset_0, (u32)fn_1_594F8__fzgx_offset_0, (u32)fn_1_594F8__fzgx_offset_0, (u32)fn_1_594F8__fzgx_offset_0, (u32)fn_1_594F8__fzgx_offset_0, (u32)fn_1_594F8__fzgx_offset_0, (u32)fn_1_594F8__fzgx_offset_0, (u32)fn_1_594F8__fzgx_offset_0, (u32)fn_1_594F8__fzgx_offset_0, (u32)fn_1_594F8__fzgx_offset_0, (u32)fn_1_594F8__fzgx_offset_0, (u32)fn_1_594F8__fzgx_offset_0, (u32)fn_1_594F8__fzgx_offset_0, (u32)fn_1_594F8__fzgx_offset_0, (u32)fn_1_594F8__fzgx_offset_0, (u32)fn_1_594F8__fzgx_offset_0, (u32)fn_1_594F8__fzgx_offset_0, (u32)fn_1_594F8__fzgx_offset_0, (u32)fn_1_594F8__fzgx_offset_0, (u32)fn_1_594F8__fzgx_offset_0, (u32)fn_1_594F8__fzgx_offset_0, (u32)fn_1_594F8__fzgx_offset_0, (u32)fn_1_594F8__fzgx_offset_0, (u32)fn_1_594F8__fzgx_offset_0, (u32)fn_1_594F8__fzgx_offset_0, (u32)fn_1_594F8__fzgx_offset_0, (u32)fn_1_594F8__fzgx_offset_0, 0x00000000}; /* fzgx-allow: A1 measured pool bytes and bindings */
static EffectHandler fzgx_pool_native_lbl_1_data_1C698_update[0x45] = {(EffectHandler)(u32)fn_1_5950C__fzgx_offset_0, (EffectHandler)(u32)fn_1_5946C__fzgx_offset_0, (EffectHandler)(u32)fn_1_59770__fzgx_offset_0, (EffectHandler)(u32)fn_1_59B90__fzgx_offset_0, (EffectHandler)(u32)fn_1_594EC__fzgx_offset_0, (EffectHandler)(u32)fn_1_59EE4__fzgx_offset_0, (EffectHandler)(u32)fn_1_5ABC4__fzgx_offset_0, (EffectHandler)(u32)fn_1_5AF28__fzgx_offset_0, (EffectHandler)(u32)fn_1_5B30C__fzgx_offset_0, (EffectHandler)(u32)fn_1_5B578__fzgx_offset_0, (EffectHandler)(u32)fn_1_5B7F8__fzgx_offset_0, (EffectHandler)(u32)fn_1_5C058__fzgx_offset_0, (EffectHandler)(u32)fn_1_5CA00__fzgx_offset_0, (EffectHandler)(u32)fn_1_5D1B8__fzgx_offset_0, (EffectHandler)(u32)fn_1_5D718__fzgx_offset_0, (EffectHandler)(u32)fn_1_5DFA4__fzgx_offset_0, (EffectHandler)(u32)fn_1_5EB08__fzgx_offset_0, (EffectHandler)(u32)fn_1_5F9B8__fzgx_offset_0, (EffectHandler)(u32)fn_1_5FE30__fzgx_offset_0, (EffectHandler)(u32)fn_1_6028C__fzgx_offset_0, (EffectHandler)(u32)fn_1_60B80__fzgx_offset_0, (EffectHandler)(u32)fn_1_60D54__fzgx_offset_0, (EffectHandler)(u32)fn_1_61070__fzgx_offset_0, (EffectHandler)(u32)fn_1_61640__fzgx_offset_0, (EffectHandler)(u32)fn_1_619E4__fzgx_offset_0, (EffectHandler)(u32)fn_1_61CC8__fzgx_offset_0, (EffectHandler)(u32)fn_1_62E9C__fzgx_offset_0, (EffectHandler)(u32)fn_1_632D4__fzgx_offset_0, (EffectHandler)(u32)fn_1_63858__fzgx_offset_0, (EffectHandler)(u32)fn_1_642E8__fzgx_offset_0, (EffectHandler)(u32)fn_1_64760__fzgx_offset_0, (EffectHandler)(u32)fn_1_64E1C__fzgx_offset_0, (EffectHandler)(u32)fn_1_65268__fzgx_offset_0, (EffectHandler)(u32)fn_1_656C8__fzgx_offset_0, (EffectHandler)(u32)fn_1_65CDC__fzgx_offset_0, (EffectHandler)(u32)fn_1_67D0C__fzgx_offset_0, (EffectHandler)(u32)fn_1_68054__fzgx_offset_0, (EffectHandler)(u32)fn_1_660EC__fzgx_offset_0, (EffectHandler)(u32)fn_1_67294__fzgx_offset_0, (EffectHandler)(u32)fn_1_6755C__fzgx_offset_0, (EffectHandler)(u32)fn_1_594FC__fzgx_offset_0, (EffectHandler)(u32)fn_1_594FC__fzgx_offset_0, (EffectHandler)(u32)fn_1_594FC__fzgx_offset_0, (EffectHandler)(u32)fn_1_594FC__fzgx_offset_0, (EffectHandler)(u32)fn_1_594FC__fzgx_offset_0, (EffectHandler)(u32)fn_1_594FC__fzgx_offset_0, (EffectHandler)(u32)fn_1_594FC__fzgx_offset_0, (EffectHandler)(u32)fn_1_594FC__fzgx_offset_0, (EffectHandler)(u32)fn_1_594FC__fzgx_offset_0, (EffectHandler)(u32)fn_1_594FC__fzgx_offset_0, (EffectHandler)(u32)fn_1_594FC__fzgx_offset_0, (EffectHandler)(u32)fn_1_594FC__fzgx_offset_0, (EffectHandler)(u32)fn_1_594FC__fzgx_offset_0, (EffectHandler)(u32)fn_1_594FC__fzgx_offset_0, (EffectHandler)(u32)fn_1_594FC__fzgx_offset_0, (EffectHandler)(u32)fn_1_594FC__fzgx_offset_0, (EffectHandler)(u32)fn_1_594FC__fzgx_offset_0, (EffectHandler)(u32)fn_1_594FC__fzgx_offset_0, (EffectHandler)(u32)fn_1_594FC__fzgx_offset_0, (EffectHandler)(u32)fn_1_594FC__fzgx_offset_0, (EffectHandler)(u32)fn_1_594FC__fzgx_offset_0, (EffectHandler)(u32)fn_1_594FC__fzgx_offset_0, (EffectHandler)(u32)fn_1_594FC__fzgx_offset_0, (EffectHandler)(u32)fn_1_594FC__fzgx_offset_0, (EffectHandler)(u32)fn_1_594FC__fzgx_offset_0, (EffectHandler)(u32)fn_1_594FC__fzgx_offset_0, (EffectHandler)(u32)fn_1_594FC__fzgx_offset_0, (EffectHandler)(u32)fn_1_594FC__fzgx_offset_0, (EffectHandler)0x00000000}; /* fzgx-allow: A1 measured pool bytes and bindings */
static EffectHandler fzgx_pool_native_lbl_1_data_1C698_destroy[0x45] = {(EffectHandler)(u32)fn_1_59510__fzgx_offset_0, (EffectHandler)(u32)fn_1_5948C__fzgx_offset_0, (EffectHandler)(u32)fn_1_59A70__fzgx_offset_0, (EffectHandler)(u32)fn_1_59CC4__fzgx_offset_0, (EffectHandler)(u32)fn_1_594F0__fzgx_offset_0, (EffectHandler)(u32)fn_1_5A8CC__fzgx_offset_0, (EffectHandler)(u32)fn_1_5ABC8__fzgx_offset_0, (EffectHandler)(u32)fn_1_5B074__fzgx_offset_0, (EffectHandler)(u32)fn_1_5B3CC__fzgx_offset_0, (EffectHandler)(u32)fn_1_5B6F0__fzgx_offset_0, (EffectHandler)(u32)fn_1_5BF6C__fzgx_offset_0, (EffectHandler)(u32)fn_1_5C780__fzgx_offset_0, (EffectHandler)(u32)fn_1_5D010__fzgx_offset_0, (EffectHandler)(u32)fn_1_5D374__fzgx_offset_0, (EffectHandler)(u32)fn_1_5D4FC__fzgx_offset_0, (EffectHandler)(u32)fn_1_5D918__fzgx_offset_0, (EffectHandler)(u32)fn_1_5F5C4__fzgx_offset_0, (EffectHandler)(u32)fn_1_5FE24__fzgx_offset_0, (EffectHandler)(u32)fn_1_5FFAC__fzgx_offset_0, (EffectHandler)(u32)fn_1_60170__fzgx_offset_0, (EffectHandler)(u32)fn_1_60C70__fzgx_offset_0, (EffectHandler)(u32)fn_1_60C84__fzgx_offset_0, (EffectHandler)(u32)fn_1_60F80__fzgx_offset_0, (EffectHandler)(u32)fn_1_61760__fzgx_offset_0, (EffectHandler)(u32)fn_1_61C84__fzgx_offset_0, (EffectHandler)(u32)fn_1_61CE8__fzgx_offset_0, (EffectHandler)(u32)fn_1_6312C__fzgx_offset_0, (EffectHandler)(u32)fn_1_633BC__fzgx_offset_0, (EffectHandler)(u32)fn_1_63514__fzgx_offset_0, (EffectHandler)(u32)fn_1_645C8__fzgx_offset_0, (EffectHandler)(u32)fn_1_645D0__fzgx_offset_0, (EffectHandler)(u32)fn_1_648D8__fzgx_offset_0, (EffectHandler)(u32)fn_1_65420__fzgx_offset_0, (EffectHandler)(u32)fn_1_65AAC__fzgx_offset_0, (EffectHandler)(u32)fn_1_65B58__fzgx_offset_0, (EffectHandler)(u32)fn_1_6767C__fzgx_offset_0, (EffectHandler)(u32)fn_1_680F4__fzgx_offset_0, (EffectHandler)(u32)fn_1_65E88__fzgx_offset_0, (EffectHandler)(u32)fn_1_662D4__fzgx_offset_0, (EffectHandler)(u32)fn_1_6742C__fzgx_offset_0, (EffectHandler)(u32)fn_1_59500__fzgx_offset_0, (EffectHandler)(u32)fn_1_59500__fzgx_offset_0, (EffectHandler)(u32)fn_1_59500__fzgx_offset_0, (EffectHandler)(u32)fn_1_59500__fzgx_offset_0, (EffectHandler)(u32)fn_1_59500__fzgx_offset_0, (EffectHandler)(u32)fn_1_59500__fzgx_offset_0, (EffectHandler)(u32)fn_1_59500__fzgx_offset_0, (EffectHandler)(u32)fn_1_59500__fzgx_offset_0, (EffectHandler)(u32)fn_1_59500__fzgx_offset_0, (EffectHandler)(u32)fn_1_59500__fzgx_offset_0, (EffectHandler)(u32)fn_1_59500__fzgx_offset_0, (EffectHandler)(u32)fn_1_59500__fzgx_offset_0, (EffectHandler)(u32)fn_1_59500__fzgx_offset_0, (EffectHandler)(u32)fn_1_59500__fzgx_offset_0, (EffectHandler)(u32)fn_1_59500__fzgx_offset_0, (EffectHandler)(u32)fn_1_59500__fzgx_offset_0, (EffectHandler)(u32)fn_1_59500__fzgx_offset_0, (EffectHandler)(u32)fn_1_59500__fzgx_offset_0, (EffectHandler)(u32)fn_1_59500__fzgx_offset_0, (EffectHandler)(u32)fn_1_59500__fzgx_offset_0, (EffectHandler)(u32)fn_1_59500__fzgx_offset_0, (EffectHandler)(u32)fn_1_59500__fzgx_offset_0, (EffectHandler)(u32)fn_1_59500__fzgx_offset_0, (EffectHandler)(u32)fn_1_59500__fzgx_offset_0, (EffectHandler)(u32)fn_1_59500__fzgx_offset_0, (EffectHandler)(u32)fn_1_59500__fzgx_offset_0, (EffectHandler)(u32)fn_1_59500__fzgx_offset_0, (EffectHandler)(u32)fn_1_59500__fzgx_offset_0, (EffectHandler)0x00000000}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u32 fzgx_pool_native_lbl_1_data_1C698_unk_f90 = 0x00000001; /* fzgx-allow: A1 measured pool bytes and bindings */

void fn_1_58994(void) {
    
    EffectHandler *update;
    EffectState *state = &lbl_1_bss_6C848;
    EffectEntry *entry;
    s32 count;
    u16 mask;
    EffectHandler *destroy;
    u32 flags;
    u32 time;
    u32 level;

    fn_1_3BDC(9);
    if (fn_1_3F164() != 0) {
        fzgx_pool_native_lbl_1_data_1C698_unk_f90 = 1;
    }
    fn_1_9F8FC();
    fn_1_5819C();

    level = fn_1_58C4();
    if (level >= 1 && level <= 4) {
        mask = 1 << (level - 1);
    } else {
        mask = 0xffff;
    }

    entry = state->unk_00;
    if (!(camera_forward_status() & 0x80000000)) {
        mask = (u16)mask;
        update = fzgx_pool_native_lbl_1_data_1C698_update;
        for (count = 0xbe; count > 0; count--) {
            if (entry->unk_00 != 0 && (entry->unk_1a & mask) && !(entry->unk_08 & 0x80000000)) {
                update[entry->unk_0c](entry);
            }
            entry++;
        }
        entry = state->unk_04;
        update = fzgx_pool_native_lbl_1_data_1C698_update;
        for (count = 0xc8; count > 0; count--) {
            if (entry->unk_00 != 0 && (entry->unk_1a & mask) && !(entry->unk_08 & 0x80000000)) {
                update[entry->unk_0c](entry);
            }
            entry++;
        }
    } else {
        for (count = 0xbe; count > 0; count--) {
            if (entry->unk_00 != 0 && (entry->unk_1a & mask)) {
                flags = entry->unk_08;
                if (!(flags & 0x80000000)) {
                    if (flags & 0x08000000) {
                        destroy = fzgx_pool_native_lbl_1_data_1C698_destroy;
                        destroy[entry->unk_0c](entry);
                        entry->unk_00 = 0;
                    } else {
                        if (flags & 0x70000000) {
                            entry->unk_60 = entry->unk_3c;
                        }
                        if (entry->unk_0c == 0x1c) {
                            fn_1_63518(entry);
                        }
                        update = fzgx_pool_native_lbl_1_data_1C698_update;
                        update[entry->unk_0c](entry);
                    }
                }
            }
            entry++;
        }
        entry = state->unk_04;
        for (count = 0xc8; count > 0; count--) {
            if (entry->unk_00 != 0 && (entry->unk_1a & mask)) {
                flags = entry->unk_08;
                if (!(flags & 0x80000000)) {
                    if (flags & 0x08000000) {
                        destroy = fzgx_pool_native_lbl_1_data_1C698_destroy;
                        destroy[entry->unk_0c](entry);
                        entry->unk_00 = 0;
                    } else {
                        if (flags & 0x70000000) {
                            entry->unk_60 = entry->unk_3c;
                        }
                        if (entry->unk_0c == 0x1c) {
                            fn_1_63518(entry);
                        }
                        update = fzgx_pool_native_lbl_1_data_1C698_update;
                        update[entry->unk_0c](entry);
                    }
                }
            }
            entry++;
        }
    }

    time = fn_1_3C18(9);
    flags = state->unk_0c;
    if (time > flags) {
        flags = time;
    }
    state->unk_0c = flags;
}
/* fzgx:end fn_1_58994 */

/* fzgx:begin fn_1_58C6C */
struct fn_1_58C6C_lbl_1_bss_6C848_T {
    u8 unk_0;
    u8 pad_1[0x7];
    u32 unk_8;
    s16 unk_C;
    u8 pad_E[0xC];
    u16 unk_1A;
};
struct fn_1_58C6C_lbl_1_bss_6C84C_T {
    u8 unk_0;
    u8 pad_1[0x7];
    u32 unk_8;
    s16 unk_C;
    u8 pad_E[0xC];
    u16 unk_1A;
};

void fn_1_58C6C(void) {
    struct fn_1_58C6C_lbl_1_bss_6C848_T *var_r31;
    s32 var_r30;
    s32 var_r30_2;
    struct fn_1_58C6C_lbl_1_bss_6C84C_T *var_r31_2;

    var_r30 = 0xBE;
    var_r31 = (struct fn_1_58C6C_lbl_1_bss_6C848_T *)(*(struct fn_1_58C6C_lbl_1_bss_6C848_T **)((u8 *)(&(*(struct fn_1_58C6C_lbl_1_bss_6C848_T * *)&lbl_1_bss_6C848)) + 0));
    do {
        if (((s16) var_r31->unk_C == 0x19) && ((s8) var_r31->unk_0 != 0) && ((s32) var_r31->unk_1A != 0) && !(var_r31->unk_8 & 0x80000000)) {
            fn_1_620C8( (Fn620C8Obj *)((void *)(var_r31)));
        }
        var_r30 -= 1;
        var_r31 = (struct fn_1_58C6C_lbl_1_bss_6C848_T *)((u8 *)(var_r31) + 0xE8);
    } while (var_r30 > 0);
    var_r30_2 = 0xC8;
    var_r31_2 = (struct fn_1_58C6C_lbl_1_bss_6C84C_T *)(*(struct fn_1_58C6C_lbl_1_bss_6C84C_T **)((u8 *)(&(*(struct fn_1_58C6C_lbl_1_bss_6C84C_T * *)&lbl_1_bss_6C84C)) + 0));
    do {
        if (((s16) var_r31_2->unk_C == 0x19) && ((s8) var_r31_2->unk_0 != 0) && ((s32) var_r31_2->unk_1A != 0) && !(var_r31_2->unk_8 & 0x80000000)) {
            fn_1_620C8( (Fn620C8Obj *)((void *)(var_r31_2)));
        }
        var_r30_2 -= 1;
        var_r31_2 = (struct fn_1_58C6C_lbl_1_bss_6C84C_T *)((u8 *)(var_r31_2) + 0xE8);
    } while (var_r30_2 > 0);
}
/* fzgx:end fn_1_58C6C */

/* fzgx:begin fn_1_58D38 */
typedef struct fn_1_58D38_EffectState {
    fn_1_58D38_EffectEntry *unk_00;
    fn_1_58D38_EffectEntry *unk_04;
    u8 pad_08[8];
    u32 unk_10;
} fn_1_58D38_EffectState;


void fn_1_58D38(void) {
    fn_1_58D38_EffectState *state;
    s32 count;
    fn_1_58D38_EffectEntry *entry;
    u32 max_count;

    state = (fn_1_58D38_EffectState *)&lbl_1_bss_6C848;
    if (state->unk_00 != 0) {
        fn_1_3BDC(9);

        entry = state->unk_00;
        count = 190;
        do {
            if (entry->unk_0C == 25 &&
                (s32)entry->unk_00 != 0 &&
                entry->unk_1A != (s16)0 &&
                (entry->unk_08 & ~0x7fffffff) == 0) {
                fn_1_62360(entry);
            }
            count--;
            entry++;
        } while (count > 0);

        entry = state->unk_04;
        count = 200;
        do {
            if (entry->unk_0C == 25 &&
                (s32)entry->unk_00 != 0 &&
                entry->unk_1A != (s16)0 &&
                (entry->unk_08 & ~0x7fffffff) == 0) {
                fn_1_62360(entry);
            }
            count--;
            entry++;
        } while (count > 0);

        count = fn_1_3C18(9);
        max_count = state->unk_10;
        if (count > max_count) {
            max_count = count;
        }
        state->unk_10 = max_count;
    }
}
/* fzgx:end fn_1_58D38 */

/* fzgx:begin fn_1_58E3C */
typedef struct {
    s8 unk_0;
    u8 pad_1;
    s16 unk_2;
    s16 unk_4;
    u8 pad_6[6];
    s16 unk_C;
    u8 pad_E[0xDA];
} EffectEntry;

s16 fn_1_58E3C(void *source) {
    s32 i;

    if ((s32)fn_1_3FC58() != 0) {
        return -1;
    }

    {
        EffectEntry *scan;
        scan = *(EffectEntry **)&lbl_1_bss_6C848;
        i = 0;
        for (; i < 0xbe; i++, scan++) {
            if (!scan->unk_0) {
                scan->unk_0 = 1;
                /* The shared exit preserves the counted search result. */
                goto slot_found;
            }
        }
        i = -1;
    }
slot_found:
    if (i < 0) {
        return -1;
    }
    {
        EffectEntry *entry;
        entry = *(EffectEntry **)&lbl_1_bss_6C848 + i;
    memcpy(entry, source, 0xe8);
    entry->unk_0 = 1;
    entry->unk_2 = i;
    ((void (**)(void *))lbl_1_data_1D1D8)[entry->unk_C](entry);
    entry->unk_4 = lbl_1_bss_6C850.unk_0;
    lbl_1_bss_6C850.unk_0++;
    if (lbl_1_bss_6C850.unk_0 < 0) {
        lbl_1_bss_6C850.unk_0 = 0;
    }
        return entry->unk_4;
    }
}
/* fzgx:end fn_1_58E3C */

/* fzgx:begin fn_1_58F50 */
typedef struct {
    u8 unk_0;
    u8 pad_1[1];
    s16 unk_2;
    s16 unk_4;
    u8 pad_6[6];
    s16 unk_C;
    u8 pad_E[0xDA];
} fn_1_58F50_EffectEntry;

/* Allocate an effect entry, initialize it, and return its sequence number. */
s16 fn_1_58F50(const void *source) {
    fn_1_58F50_EffectEntry *entry;
    s32 index;
    u8 *cursor;

    if ((int)fn_1_3FC8C() != 0) {
        return -1;
    }
    if ((int)fn_1_3FC58() != 0) {
        return -1;
    }

    cursor = *(u8 **)&lbl_1_bss_6C848;
    index = 0;
    for (; index < 0xbe;) {
        if (*(s8 *)cursor == 0) {
            *cursor = 1;
            goto found; /* irreducible split between allocation and failure */
        }
        index++;
        cursor += 0xe8;
    }
    index = -1;
found:
    if (index < 0) {
        return -1;
    }

    entry = (fn_1_58F50_EffectEntry *)(*(u8 **)&lbl_1_bss_6C848) + index;
    memcpy(entry, source, 0xe8);
    entry->unk_0 = 1;
    entry->unk_2 = index;
    ((void (*)(void *))(*(u32 *)((*(u8 (*)[276])&lbl_1_data_1D1D8) + (entry->unk_C << 2))))(entry);

    entry->unk_4 = lbl_1_bss_6C850.unk_0;
    lbl_1_bss_6C850.unk_0++;
    if (lbl_1_bss_6C850.unk_0 < 0) {
        lbl_1_bss_6C850.unk_0 = 0;
    }
    return entry->unk_4;
}
/* fzgx:end fn_1_58F50 */

/* fzgx:begin fn_1_59078 */
s16 fn_1_59078(Obj_1_bss_6C84C_Target *arg0) {
    Obj_1_bss_6C84C_Target *obj;
    s32 i;

    if ((int)fn_1_3FC8C() != 0) {
        return -1;
    }
    if ((int)fn_1_3FC58() != 0) {
        return -1;
    }

    obj = lbl_1_bss_6C84C;
    for (i = 0; i < 0xbe; i++, obj++) {
        if ((s8)obj->unk_0 == 0) {
            obj->unk_0 = 1;
            // Skip the exhaustion path when a free slot is found.
            goto slot_found;
        }
    }
    i = -1;
slot_found:
    if (i < 0) {
        return -1;
    }

    obj = lbl_1_bss_6C84C + i;
    memcpy(obj, arg0, 0xe8);
    obj->unk_0 = 1;
    obj->unk_2 = i;
    ((void (**)(Obj_1_bss_6C84C_Target *))lbl_1_data_1D1D8)[obj->unk_C](obj);
    obj->unk_4 = lbl_1_bss_6C850.unk_0;
    lbl_1_bss_6C850.unk_0++;
    if (lbl_1_bss_6C850.unk_0 < 0) {
        lbl_1_bss_6C850.unk_0 = 0;
    }
    return obj->unk_4;
}
/* fzgx:end fn_1_59078 */

/* fzgx:begin fn_1_59290 */
void fn_1_59290(void) {
    u8 buffer1[0xe8];
    u8 buffer2[0xe8];
    int count;
    Obj_1_bss_6C84C_Target *effect;
    Obj_1_bss_6C84C_Target *effects;

    effects = *(Obj_1_bss_6C84C_Target **)(void *)&lbl_1_bss_6C848;
    effect = effects;
    count = 0xbe;
    for (; count > 0; count--, effect++) {
        if ((s8)effect->unk_0 != 0) {
            if (effect->unk_C == 1) {
                fn_80008BEC(buffer1, 0, 0xe8);
                *(s16 *)(buffer1 + 0x4) = effect->unk_4;
                buffer1[0] = effect->unk_0;
                *(s16 *)(buffer1 + 0xc) = effect->unk_C;
                *(u32 *)(buffer1 + 0x38) = effect->unk_38;
                *(u32 *)(buffer1 + 0x34) = effect->unk_34;
                *(u16 *)(buffer1 + 0x1a) = effect->unk_1A;
                *(s16 *)(buffer1 + 0x18) = effect->unk_18;
                fn_80008BEC(effect, 0, 0xe8);
                fn_80008BA8(effect, buffer1, 0xe8);
            } else if (effect->unk_C != 4) {
                effect->unk_0 = 3;
                effect->unk_8 |= (u32)1 << 31;
            }
        }
    }

    effects = lbl_1_bss_6C84C;
    effect = effects;
    count = 0xc8;
    for (; count > 0; count--, effect++) {
        if ((s8)effect->unk_0 != 0) {
            if (effect->unk_C == 1) {
                fn_80008BEC(buffer2, 0, 0xe8);
                *(s16 *)(buffer2 + 0x4) = effect->unk_4;
                buffer2[0] = effect->unk_0;
                *(s16 *)(buffer2 + 0xc) = effect->unk_C;
                *(u32 *)(buffer2 + 0x38) = effect->unk_38;
                *(u32 *)(buffer2 + 0x34) = effect->unk_34;
                *(u16 *)(buffer2 + 0x1a) = effect->unk_1A;
                *(s16 *)(buffer2 + 0x18) = effect->unk_18;
                fn_80008BEC(effect, 0, 0xe8);
                fn_80008BA8(effect, buffer2, 0xe8);
            } else if (effect->unk_C != 4) {
                effect->unk_0 = 3;
                effect->unk_8 |= (u32)1 << 31;
            }
        }
    }
}
/* fzgx:end fn_1_59290 */

/* fzgx:begin fn_1_5942C */
// fn_1_5942C: wrapper that calls fn_1_680F8
void fn_1_5942C(void) {
    fn_1_680F8();
}
/* fzgx:end fn_1_5942C */

/* fzgx:begin fn_1_5944C */
void fn_1_5944C(void) {
    fn_1_68284();
}
/* fzgx:end fn_1_5944C */

/* fzgx:begin fn_1_5946C */
void fn_1_5946C(void) {
    fn_1_68B68();
}
/* fzgx:end fn_1_5946C */

/* fzgx:begin fn_1_5948C */
void fn_1_5948C(void) {
    fn_1_68248();
}
/* fzgx:end fn_1_5948C */

/* fzgx:begin fn_1_594AC */
void fn_1_594AC(void) {
    fn_1_69BBC();
}
/* fzgx:end fn_1_594AC */

/* fzgx:begin fn_1_594CC */
void fn_1_594CC(void) {
    fn_1_69BCC();
}
/* fzgx:end fn_1_594CC */

/* fzgx:begin fn_1_594EC */
// fn_1_594EC: empty in retail (single blr).
void fn_1_594EC(void) {
}
/* fzgx:end fn_1_594EC */

/* fzgx:begin fn_1_594F0 */
// fn_1_594F0: empty in retail (single blr).
void fn_1_594F0(void) {
}
/* fzgx:end fn_1_594F0 */

/* fzgx:begin fn_1_594F4 */
// fn_1_594F4: empty in retail (single blr).
void fn_1_594F4(void) {
}
/* fzgx:end fn_1_594F4 */

/* fzgx:begin fn_1_594F8 */
// fn_1_594F8: empty in retail (single blr).
void fn_1_594F8(void) {
}
/* fzgx:end fn_1_594F8 */

/* fzgx:begin fn_1_594FC */
// fn_1_594FC: empty in retail (single blr).
void fn_1_594FC(void) {
}
/* fzgx:end fn_1_594FC */

/* fzgx:begin fn_1_59500 */
// fn_1_59500: empty in retail (single blr).
void fn_1_59500(void) {
}
/* fzgx:end fn_1_59500 */

/* fzgx:begin fn_1_59504 */
// fn_1_59504: empty in retail (single blr).
void fn_1_59504(void) {
}
/* fzgx:end fn_1_59504 */

/* fzgx:begin fn_1_59508 */
// fn_1_59508: empty in retail (single blr).
void fn_1_59508(void) {
}
/* fzgx:end fn_1_59508 */

/* fzgx:begin fn_1_5950C */
// fn_1_5950C: empty in retail (single blr).
void fn_1_5950C(void) {
}
/* fzgx:end fn_1_5950C */

/* fzgx:begin fn_1_59510 */
// fn_1_59510: empty in retail (single blr).
void fn_1_59510(void) {
}
/* fzgx:end fn_1_59510 */

/* fzgx:begin fn_1_59514 */
void fn_1_59514(void *obj) {
    if (*(s32 *)((u8 *)obj + 0x10) == 0) {
        u32 s = lbl_1_data_1D628 * 0x41c64e6d + 0x3039;
        u32 r;
        lbl_1_data_1D628 = s;
        r = (s >> 16) & 0x7fff;
        *(s32 *)((u8 *)obj + 0x10) = (s32)(60.0f * (0.1f + (f32)r / 32767.0f));
    }

    {
        f32 t = fn_1_8652C(*(s16 *)((u8 *)obj + 0x18));
        u32 s = lbl_1_data_1D628 * 0x41c64e6d + 0x3039;
        u32 r;
        lbl_1_data_1D628 = s;
        r = (s >> 16) & 0x7fff;
        *(f32 *)((u8 *)obj + 0x94) = 0.05f * ((f32)r / 32767.0f);
        *(f32 *)((u8 *)obj + 0x98) = (f32)(0.07 + t / 20000.0f);
    }
}
/* fzgx:end fn_1_59514 */

/* fzgx:begin fn_1_5962C noprologue */
#include "dolphin/types.h"

typedef struct Vec5962C {
    f32 x, y, z;
} Vec5962C;

typedef struct Obj5962C {
    u8 pad0[0x10];
    s32 age;
    u8 pad14[8];
    Vec5962C scale;
    f32 size;
    f32 targetSize;
    u8 pad30[0xC];
    Vec5962C position;
    Vec5962C velocity;
    u8 pad54[0xC];
    Vec5962C previousPosition;
    u8 pad6C[0x28];
    f32 drag;
    f32 targetDrag;
} Obj5962C;

extern void fn_1_5962C_prime_f32(f32);
extern void fn_1_5962C_prime_f64(f64);
#pragma section code_type ".fzgxpool"
void fzgx_pool_prime_5962C(void)
{
    fn_1_5962C_prime_f32(60.0f);
    fn_1_5962C_prime_f32(0.1f);
    fn_1_5962C_prime_f32(32767.0f);
    fn_1_5962C_prime_f32(0.05f);
    fn_1_5962C_prime_f64(0.07);
    fn_1_5962C_prime_f32(20000.0f);
    fn_1_5962C_prime_f64(4503599627370496.0);
    fn_1_5962C_prime_f32(1.0f);
    fn_1_5962C_prime_f32(-0.03f);
    fn_1_5962C_prime_f64(15.0);
    fn_1_5962C_prime_f64(4503601774854144.0);
}
#pragma section code_type ".text"

void fn_1_5962C(Obj5962C *obj)
{
    f32 factor;
    obj->previousPosition = obj->position;
    factor = 1.0f - obj->drag;
    obj->velocity.y += -0.03f;
    obj->velocity.x *= factor;
    obj->velocity.y *= factor;
    obj->velocity.z *= factor;
    obj->position.x += obj->velocity.x;
    obj->position.y += obj->velocity.y;
    obj->position.z += obj->velocity.z;
    obj->drag += (f32)(0.05f * (obj->targetDrag - obj->drag));
    obj->size += (f32)(0.1f * (obj->targetSize - obj->size));
    if ((f64)obj->age < 15.0) {
        f32 scaleX;
        f32 scaleFactor;
        /* Preserve the scale load before the age conversion. */
        scaleX = *(volatile f32 *)&obj->scale.x;
        scaleFactor = 1.0f - 1.0f / (f32)(obj->age + 1);
        obj->scale.x = scaleX * scaleFactor;
        obj->scale.y *= scaleFactor;
        obj->scale.z *= scaleFactor;
    }
}
/* fzgx:end fn_1_5962C */

/* fzgx:begin fn_1_59A70 */
// fn_1_59A70: empty in retail (single blr).
void fn_1_59A70(void) {
}
/* fzgx:end fn_1_59A70 */

/* fzgx:begin fn_1_59A74 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
}
#pragma section code_type ".text"


struct fn_1_59A74_Arg0 {
    u8 pad_0[0x10];
    u32 unk_10;
    u8 pad_14[0x6];
    u16 unk_1A;
};

void fn_1_59A74(struct fn_1_59A74_Arg0 *arg0) {
    u32 v0;
    f32 v1;
    f32 v2;
    f32 v3;
    f32 v4;

    arg0->unk_1A = (0x10000 - 1);
    v0 = ((lbl_1_data_1D628 * (0x41C60000 + 20077)) + 12345);
    lbl_1_data_1D628 = v0;
    v1 = (f32)(u32)((v0 >> 16) & 0x7FFF);
    v2 = v1 / 32767.0f;
    v3 = 0.5f * v2;
    v4 = 0.1f + v3;
    arg0->unk_10 = (s32)(60.0f * v4);
}
/* fzgx:end fn_1_59A74 */

/* fzgx:begin fn_1_59B00 */
typedef struct fn_1_59B00_Effect {
    u8 pad_00[0x10];
    s32 frame;
    u8 pad_14[0x14];
    f32 value;
    f32 target;
} fn_1_59B00_Effect;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
}
#pragma section code_type ".text"
void fn_1_59B00(fn_1_59B00_Effect *effect) {
    if ((f32)effect->frame < 15.0f) {
        effect->value = effect->value * (1.0f - 1.0f / (f32)(effect->frame + 1));
    } else {
        f32 delta = (effect->target - effect->value) * 0.2f;

        effect->value += delta;
    }
}
/* fzgx:end fn_1_59B00 */

/* fzgx:begin fn_1_59B90 noprologue */
#include "dolphin/types.h"
#include "game/main_rel/camera_types.h"
#include "rel/main_rel/effect.h"
#include "psvec.h"

typedef struct Fn59B90Arg {
    u8 pad_0[0x28];
    f32 unk_28;
    u8 pad_2C[0x10];
    u8 unk_3C[0x18];
    s16 unk_54;
    s16 unk_56;
} Fn59B90Arg;

typedef struct Fn59B90Model {
    u8 pad_0[8];
    u8 unk_8[0xC];
    f32 unk_14;
} Fn59B90Model;

typedef struct Fn59B90State {
    u8 pad_0[0x90];
    Fn59B90Model *unk_90;
} Fn59B90State;

extern s32 fn_1_54E34(void *, f32);
extern f32 lbl_1_rodata_2954[2];
extern void fn_1_56000(u8, u8, u8);
extern void fn_1_556B8(void *);
extern void lbl_8006D9D8(CamEntry *);
extern u32 mathutil_mtxA_rotate_y(u32);
extern u32 mathutil_mtxA_rotate_x(u32);
extern void lbl_8006E14C(f32);
extern void lbl_8006DB74(void *);
extern f32 lbl_8006D0B4(f32);
extern void lbl_8006D848(f32);
extern void lbl_8006DFC4(void *);
extern u32 u_gxutil_upload_some_mtx(u32, u32);

#pragma fp_contract on
void fn_1_59B90(Fn59B90Arg *arg) {
    Fn59B90Model *model;
    f32 matrix[3][4];
    struct { f32 x, y, z; } vec;
    f32 length;

    model = ((Fn59B90State *)lbl_1_bss_38458->unk_8)->unk_90;
    lbl_8006D9D8((CamEntry *)arg->unk_3C);
    mathutil_mtxA_rotate_y(arg->unk_56);
    mathutil_mtxA_rotate_x(arg->unk_54);
    lbl_8006E14C(arg->unk_28 / model->unk_14);
    if (fn_1_54E34(model->unk_8, arg->unk_28)) {
        psvec_set(&vec, *(f32 *)(0xE0000000 + 0x2C), *(f32 *)(0xE0000000 + 0x1C), *(f32 *)(0xE0000000 + 0x0C));
        lbl_8006DB74(matrix);
        {
            f32 y = vec.y;
            length = vec.x * vec.x;
            length = __fmadds(y, y, length);
            length = __fmadds(vec.z, vec.z, length);
            length = lbl_8006D0B4(length);
        }
        lbl_8006D848((length - lbl_1_rodata_2954[0]) / length);
        lbl_8006DFC4(matrix);
        fn_1_56000(1, 3, 0);
        u_gxutil_upload_some_mtx((u32)lbl_801A6D00, 0);
        fn_1_556B8(model);
        fn_1_56000(1, 3, 1);
    }
}
/* fzgx:end fn_1_59B90 */

/* fzgx:begin fn_1_59CC4 */
// fn_1_59CC4: empty in retail (single blr).
void fn_1_59CC4(void) {
}
/* fzgx:end fn_1_59CC4 */

/* fzgx:begin fn_1_59CC8 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
}
#pragma section code_type ".text"

extern const f32 lbl_1_rodata_2950;  /* +0x0 = 60.0f */
extern const f64 lbl_1_rodata_2950_20; /* placeholder, replaced below */

struct Fn159CC8Object {
    u8 pad[0x10];
    s32 unk_10;
};

#pragma opt_lifetimes off
void fn_1_59CC8(struct Fn159CC8Object *arg0) {
    if (arg0->unk_10 == 0) {
        u32 seed = (0x41C64E6D * lbl_1_data_1D628) + 0x3039;

        f32 value;
        f32 scaled;

        lbl_1_data_1D628 = seed;
        value = (f32)((seed >> 16) & 0x7FFF);
        scaled = 0.25f * (value / 32767.0f);
        arg0->unk_10 = (s32)(60.0f * (0.08f + scaled));
    }
}
#pragma opt_lifetimes reset
/* fzgx:end fn_1_59CC8 */

/* fzgx:begin fn_1_59D54 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
}
#pragma section code_type ".text"


typedef struct fn_1_59D54_Effect {
    u8 state;
    u8 pad0[0xf];
    s32 frame;
    u8 pad1[0x4];
    s16 effect_id;
    u8 pad2[0x22];
    f32 position_x;
    f32 position_y;
    f32 position_z;
    f32 velocity_x;
    f32 velocity_y;
    f32 velocity_z;
    u8 pad3[0x40];
    f32 accumulator_x;
    f32 accumulator_y;
    f32 accumulator_z;
    f32 scale_x;
    f32 scale_y;
    f32 scale_z;
    u8 pad4[0x8];
    f32 intensity;
} fn_1_59D54_Effect;

void fn_1_59D54(fn_1_59D54_Effect *effect) {
    f32 coords[3];
    f32 dz, dy, dx, dist;

    effect->velocity_x *= 0.98f;
    effect->velocity_y *= 0.98f;
    effect->velocity_z *= 0.98f;
    effect->position_x += effect->velocity_x;
    effect->position_y += effect->velocity_y;
    effect->position_z += effect->velocity_z;

    effect->scale_x *= 0.99f;
    effect->scale_y *= 0.99f;
    effect->scale_z *= 0.99f;
    effect->accumulator_x += effect->scale_x;
    effect->accumulator_y += effect->scale_y;
    effect->accumulator_z += effect->scale_z;

    effect->intensity = 0.5f * (f32)effect->frame;

    fn_1_862D4(effect->effect_id, coords);

    dx = coords[0] - effect->position_x;
    dist = dx * dx;
    dy = coords[1];
    dy = dy - effect->position_y;
    dist += dy * dy;
    dz = coords[2];
    dz = dz - effect->position_z;
    dist += dz * dz;
    dist = lbl_8006D0B4(dist);

    if (dist > 40.0f) {
        effect->state = 3;
    } else if (dist > 20.0f) {
        effect->intensity *= 0.05f * (dist - 20.0f);
    }
}
/* fzgx:end fn_1_59D54 */

/* fzgx:begin fn_1_5A8CC */
// fn_1_5A8CC: empty in retail (single blr).
void fn_1_5A8CC(void) {
}
/* fzgx:end fn_1_5A8CC */

/* fzgx:begin fn_1_5A8D0 */
typedef struct {
    u8 pad[0x10];
    s32 field_10;
} Fn1_5A8D0Data;

void fn_1_5A8D0(Fn1_5A8D0Data *data) {
    data->field_10 = 2;
}
/* fzgx:end fn_1_5A8D0 */

/* fzgx:begin fn_1_5A8DC noprologue */
#include "rel/main_rel/effect.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
}
static const u32 fzgx_pool_table1[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
    s = 0.0f;
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
}
#pragma section code_type ".text"

extern void *lbl_801A6D00;
extern void fn_1_8645C(int index, void *arg);
extern void lbl_8006E1B0(void *src, void *dst);
extern u32 fn_1_3FC58(void);
extern void *memcpy(void *, const void *, u32);
extern void *memset(void *, int, u32);
extern void lbl_8006E1F0(void *dst, f32 x, f32 y, f32 z);
extern void fn_8006EF10(void *dir, s16 *yaw, s16 *pitch);

typedef struct {
    f32 x, y, z;
} Fn15A8DCVec3;

/* Address-of view of the manager pointer: retail materialises its address before the load. */
typedef struct {
    Obj_1_bss_38458_Target *ptr;
} Fn15A8DCPtrHolder;

typedef struct {
    s8 state;            /* 0x00 */
    u8 pad_1;
    s16 index;           /* 0x02 */
    s16 serial;          /* 0x04 */
    u8 pad_6[6];
    s16 type;            /* 0x0C */
    u8 pad_e[0xA];
    s16 id;              /* 0x18 */
    u16 unk_1a;          /* 0x1A */
    Fn15A8DCVec3 unk_1c; /* 0x1C */
    f32 unk_28;          /* 0x28 */
    f32 unk_2c;          /* 0x2C */
    u8 pad_30[4];
    u32 unk_34;          /* 0x34 */
    u8 pad_38[4];
    Fn15A8DCVec3 pos;    /* 0x3C */
    Fn15A8DCVec3 vel;    /* 0x48 */
    s16 yaw;             /* 0x54 */
    s16 pitch;           /* 0x56 */
    u8 pad_58[0x3C];
    Fn15A8DCVec3 unk_94; /* 0x94 */
    u8 pad_a0[0x48];
} Fn15A8DCEffect;        /* 0xE8 */

typedef struct {
    u8 pad_0[0x18];
    s16 id;              /* 0x18 */
    u8 pad_1a[2];
    Fn15A8DCVec3 unk_1c; /* 0x1C */
    u8 pad_28[0x14];
    Fn15A8DCVec3 pos;    /* 0x3C */
    u8 pad_48[0x4C];
    Fn15A8DCVec3 unk_94; /* 0x94 */
} Fn15A8DCObject;

/* Linear congruential random number, 15 bits (ANSI rand). */
static inline u32 effect_rand_5A8DC(void) {
    lbl_1_data_1D628 = lbl_1_data_1D628 * 0x41C64E6D + 0x3039;
    return (lbl_1_data_1D628 >> 16) & 0x7FFF;
}

/* Same-TU copy of fn_1_58E3C, inlined by retail. */
static inline s16 effect_spawn_5A8DC(void *source) {
    s32 i;

    if ((s32)fn_1_3FC58() != 0) {
        return -1;
    }

    {
        Fn15A8DCEffect *scan;
        scan = *(Fn15A8DCEffect **)&lbl_1_bss_6C848;
        i = 0;
        for (; i < 0xbe; i++, scan++) {
            if (!scan->state) {
                scan->state = 1;
                goto slot_found; /* fzgx-allow: S1 exits the slot search with its index intact */
            }
        }
        i = -1;
    }
slot_found:
    if (i < 0) {
        return -1;
    }
    {
        Fn15A8DCEffect *entry;
        entry = *(Fn15A8DCEffect **)&lbl_1_bss_6C848 + i;
        memcpy(entry, source, 0xe8);
        entry->state = 1;
        entry->index = i;
        ((void (**)(void *))lbl_1_data_1D1D8)[entry->type](entry);
        entry->serial = lbl_1_bss_6C850.unk_0;
        lbl_1_bss_6C850.unk_0++;
        if (lbl_1_bss_6C850.unk_0 < 0) {
            lbl_1_bss_6C850.unk_0 = 0;
        }
        return entry->serial;
    }
}

void fn_1_5A8DC(Fn15A8DCObject *obj) {
    Fn15A8DCEffect buf;
    Fn15A8DCVec3 pos;
    Fn15A8DCVec3 oldPos;
    Fn15A8DCVec3 dir;
    f32 dx, dy, dz;
    f32 scaled;

    oldPos = obj->pos;
    fn_1_8645C(obj->id, lbl_801A6D00);
    lbl_8006E1B0(&obj->unk_94, &pos);
    lbl_8006E1F0(&dir, 0.0f, 0.0f, 1.0f);
    dx = pos.x - oldPos.x;
    dy = pos.y - oldPos.y;
    dz = pos.z - oldPos.z;
    obj->pos = pos;

    memset(&buf, 0, sizeof(buf));
    buf.id = obj->id;
    buf.type = 9;
    buf.unk_1a = 0xffff;
    buf.unk_34 = *(u32 *)((u8 *)lbl_1_bss_38458->unk_8 + 0x120);
    buf.pos = pos;
    buf.unk_94 = obj->unk_94;
    buf.vel.x = dx;
    buf.vel.y = dy;
    buf.vel.z = dz;
    buf.pos.x -= dx;
    buf.pos.y -= dy;
    buf.pos.z -= dz;
    fn_8006EF10(&dir, &buf.yaw, &buf.pitch);
    buf.unk_28 = 0.3f;
    scaled = 0.2f * ((f32)effect_rand_5A8DC() / 32767.0f);
    buf.unk_2c = 0.3f + scaled;
    buf.unk_1c = obj->unk_1c;
    effect_spawn_5A8DC(&buf);
}
/* fzgx:end fn_1_5A8DC */

/* fzgx:begin fn_1_5ABC4 */
// fn_1_5ABC4: empty in retail (single blr).
void fn_1_5ABC4(void) {
}
/* fzgx:end fn_1_5ABC4 */

/* fzgx:begin fn_1_5ABC8 */
// fn_1_5ABC8: empty in retail (single blr).
void fn_1_5ABC8(void) {
}
/* fzgx:end fn_1_5ABC8 */

/* fzgx:begin fn_1_5ABCC */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
}
#pragma section code_type ".text"

extern const struct fn_1_5ABCC_lbl_1_rodata_2950_pool {
    f32 unk_0;
    u8 pad_4[0x4];
    f32 unk_8;
    u8 pad_C[0x60];
    f32 unk_6C;
} fn_1_5ABCC_lbl_1_rodata_2950;

typedef struct {
    u8 pad_00[0x10];
    s32 unk_10;
} Fn1_5ABCCOutput;



#pragma opt_loop_invariants off
#pragma opt_common_subs off
#pragma opt_pointer_analysis off
void fn_1_5ABCC(Fn1_5ABCCOutput *out) {
    f32 t;
    f32 scaled;

{
    u32 value;
    value = lbl_1_data_1D628 * 0x41c64e6d + 0x3039;
    lbl_1_data_1D628 = value;
    t = (f32)((value >> 16) & 0x7fff);
}
    scaled = (0.25f) * (t / (32767.0f));
    out->unk_10 = (s32)((60.0f) * ((0.25f) + scaled));
}
#pragma opt_pointer_analysis reset

#pragma opt_common_subs reset

#pragma opt_loop_invariants reset
/* fzgx:end fn_1_5ABCC */

/* fzgx:begin fn_1_5AC48 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
}
#pragma section code_type ".text"


typedef struct {
    f32 x, y, z;
} fn_1_5AC48_Vec;

typedef struct {
    s8 unk_0;
    u8 pad_1;
    s16 unk_2;
    s16 unk_4;
    u8 pad_6[6];
    s16 unk_C;
    u8 pad_E[2];
    s32 unk_10;
    u8 pad_14[4];
    s16 unk_18;
    u16 unk_1A;
    fn_1_5AC48_Vec unk_1C;
    f32 unk_28;
    f32 unk_2C;
    u8 pad_30[4];
    u32 unk_34;
    u8 pad_38[4];
    fn_1_5AC48_Vec pos;
    fn_1_5AC48_Vec vel;
    u8 pad_54[0xE8 - 0x54];
} fn_1_5AC48_Effect;

typedef struct {
    u8 pad_0[0x70];
    u32 unk_70;
} fn_1_5AC48_Inner;

typedef struct {
    u8 pad_0[0x8];
    fn_1_5AC48_Inner *unk_8;
} fn_1_5AC48_Owner;

static inline s16 fn_1_5AC48_spawn(void *source) {
    s32 i;

    if ((s32)fn_1_3FC58() != 0) {
        return -1;
    }

    {
        fn_1_5AC48_Effect *scan;
        scan = *(fn_1_5AC48_Effect **)&lbl_1_bss_6C848;
        i = 0;
        for (; i < 0xbe; i++, scan++) {
            if (!scan->unk_0) {
                scan->unk_0 = 1;
                /* Skip the exhaustion path when a free slot is found. */
                goto slot_found;
            }
        }
        i = -1;
    }
slot_found:
    if (i < 0) {
        return -1;
    }
    {
        fn_1_5AC48_Effect *entry;
        entry = *(fn_1_5AC48_Effect **)&lbl_1_bss_6C848 + i;
        memcpy(entry, source, 0xe8);
        entry->unk_0 = 1;
        entry->unk_2 = i;
        ((void (**)(void *))lbl_1_data_1D1D8)[entry->unk_C](entry);
        entry->unk_4 = lbl_1_bss_6C850.unk_0;
        lbl_1_bss_6C850.unk_0++;
        if (lbl_1_bss_6C850.unk_0 < 0) {
            lbl_1_bss_6C850.unk_0 = 0;
        }
        return entry->unk_4;
    }
}

/* Linear congruential random value in [0, 1]. */
static inline f32 fn_1_5AC48_rand(void) {
    lbl_1_data_1D628 = lbl_1_data_1D628 * 0x41c64e6d + 0x3039;
    return (f32)((lbl_1_data_1D628 >> 16) & 0x7fff) / 32767.0f;
}

void fn_1_5AC48(fn_1_5AC48_Effect *effect) {
    fn_1_5AC48_Effect spawn;

    effect->vel.y += -0.004f;
    effect->vel.x *= 0.98f;
    effect->vel.y *= 0.98f;
    effect->vel.z *= 0.98f;
    effect->pos.x += effect->vel.x;
    effect->pos.y += effect->vel.y;
    effect->pos.z += effect->vel.z;

    memset(&spawn, 0, 0xe8);
    spawn.unk_18 = effect->unk_18;
    spawn.unk_C = 8;
    spawn.unk_1A = 0xffff;
    spawn.unk_34 = ((fn_1_5AC48_Owner *)lbl_1_bss_38458)->unk_8->unk_70;
    spawn.pos = effect->pos;
    spawn.vel.x = 0.5f * effect->vel.x;
    spawn.vel.y = 0.5f * effect->vel.y;
    spawn.vel.z = 0.5f * effect->vel.z;
    spawn.unk_28 = 0.25f * effect->unk_28;
    spawn.unk_2C = effect->unk_2C * (0.016666668f * fn_1_5AC48_rand());
    spawn.unk_1C = effect->unk_1C;
    fn_1_5AC48_spawn(&spawn);

    if ((f32)effect->unk_10 < 15.0f) {
        effect->unk_28 *= 1.0f - 1.0f / (f32)(effect->unk_10 + 1);
    }
}
/* fzgx:end fn_1_5AC48 */

/* fzgx:begin fn_1_5AF28 noprologue */
#include "dolphin/types.h"
#include "game/main_rel/camera_types.h"
#include "psvec.h"

#pragma fp_contract on

typedef struct DrawModel {
    u8 pad0[0x14];
    f32 scale;
} DrawModel;
typedef struct DrawObject {
    u8 pad0[0x1C];
    f32 x, y, z;
    f32 radius;
    u8 pad2C[8];
    DrawModel *model;
} DrawObject;
typedef struct DrawVector { f32 x, y, z; } DrawVector;
typedef struct DrawMatrix { f32 m[3][4]; } DrawMatrix;

extern s32 fn_1_54E34(void *, f32);
extern f32 lbl_1_rodata_2954[2];
extern f32 lbl_1_rodata_2978[4];
extern void fn_1_5621C(f32, f32, f32, f32);
extern void fn_1_56000(u8, u8, u8);
extern void fn_1_557C4(void *);
extern void lbl_8006D9D8(CamEntry *);
extern void lbl_8006D7B0(void);
extern void lbl_8006E14C(f32);
extern f32 lbl_8006D0B4(f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006D848(f32);
extern void lbl_8006DFC4(void *);

void fn_1_5AF28(DrawObject *object) {
    DrawModel *model = object->model;
    DrawVector position;
    DrawMatrix matrix;
    f32 distance;
    f32 one;
    lbl_8006D9D8((CamEntry *)((u8 *)object + 0x3C));
    lbl_8006D7B0();
    lbl_8006E14C(object->radius / model->scale);
    if (fn_1_54E34((u8 *)model + 8, object->radius)) {
        psvec_set(&position, *(f32 *)(0xE0000000 + 0x2C), *(f32 *)(0xE0000000 + 0x1C), *(f32 *)(0xE0000000 + 0x0C));
        distance = position.x * position.x;
        distance = __fmadds(position.y, position.y, distance);
        distance = __fmadds(position.z, position.z, distance);
        distance = lbl_8006D0B4(distance);
        if (distance > lbl_1_rodata_2954[0] + object->radius) {
            lbl_8006DB74(&matrix);
            lbl_8006D848((distance - object->radius) / distance);
            lbl_8006DFC4(&matrix);
        }
        fn_1_5621C(object->x, object->y, object->z, lbl_1_rodata_2978[0]);
        fn_1_56000(1, 3, 0);
        fn_1_557C4(model);
        one = lbl_1_rodata_2978[0];
        fn_1_5621C(one, one, one, one);
        fn_1_56000(1, 3, 1);
    }
}
/* fzgx:end fn_1_5AF28 */

/* fzgx:begin fn_1_5B074 */
// fn_1_5B074: empty in retail (single blr).
void fn_1_5B074(void) {
}
/* fzgx:end fn_1_5B074 */

/* fzgx:begin fn_1_5B078 noprologue */
#include "rel/main_rel/effect.h"

#pragma push
#pragma force_active on
#pragma section code_type ".fzgxpool"
static void fn_1_5B078_pool_primer(void) {
    /* Volatile stores retain the shared retail literal-pool order. */
    volatile f32 f;
    volatile f64 d; /* Retain double entries and alignment in the shared literal pool. */
    f = 60.0f;
    f = 0.1f;
    f = 32767.0f;
    f = 0.05f;
    d = 0.07;
    f = 20000.0f;
    d = 4503599627370496.0;
    f = 1.0f;
    f = -0.03f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
    f = 0.0f;
    f = 0.5f;
    f = 8.0f;
    f = 255.0f;
    f = 15.0f;
    f = 0.2f;
    f = 0.08f;
    f = 0.25f;
    f = 0.98f;
    f = 0.99f;
    f = 40.0f;
    f = 20.0f;
    f = 1.5f;
    f = 0.45f;
    f = -2.0f;
    f = 0.0833333358168602f;
    f = 0.15f;
    f = 0.125f;
    f = -0.4f;
    f = -0.3f;
    f = 2.0f;
    f = 250.0f;
    d = 0.6;
    d = 0.4;
    f = 0.3f;
    f = -0.004f;
    f = 0.01666666753590107f;
    f = 65536.0f;
    f = 4096.0f;
}
#pragma pop

typedef struct Fn1_5B078Object {
    u8 pad_00[0x10];
    s32 unk_10;
    u8 pad_14[0x44];
    s16 unk_58;
    u8 pad_5A[4];
    s16 unk_5E;
    u8 pad_60[0x54];
    f32 unk_B4;
} Fn1_5B078Object;

static inline f32 random_float(void) {
    lbl_1_data_1D628 = lbl_1_data_1D628 * 0x41C64E6D + 12345;
    return (f32)((lbl_1_data_1D628 >> 16) & 0x7FFF) / 32767.0f;
}

void fn_1_5B078(Fn1_5B078Object* arg0) {
    arg0->unk_10 = (s32)(60.0f * (0.125f + (f32)(0.1f * random_float())));
    arg0->unk_58 = (s16)(65536.0f * (random_float() - 0.5f));
    arg0->unk_5E = (s16)(4096.0f * (random_float() - 0.5f));
    arg0->unk_B4 = 0.5f;
}
/* fzgx:end fn_1_5B078 */

/* fzgx:begin fn_1_5B188 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const unsigned long fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
}
#pragma section code_type ".text"

struct A {
    u8 pad_0[0x10];
    s32 unk_10;
    u8 pad_14[0x8];
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    u8 pad_28[0x4];
    f32 unk_2C;
    u8 pad_30[0xC];
    f32 unk_3C;
    f32 unk_40;
    f32 unk_44;
    f32 unk_48;
    f32 unk_4C;
    f32 unk_50;
    u8 pad_54[0x4];
    s16 unk_58;
    u8 pad_5A[0x4];
    s16 unk_5E;
    u8 pad_60[0x54];
    f32 unk_B4;
};


#pragma opt_common_subs off
static inline f32 fn_1_5B188_operand(f32 left, f32 right) { return left * right; }
void fn_1_5B188(struct A *a) {
    f32 f = (1.0f);
    f32 d = f / (f32)(a->unk_10 + 1);
    a->unk_48 = fn_1_5B188_operand((a->unk_48), ((0.959999979f)));
    a->unk_4C = fn_1_5B188_operand((a->unk_4C), ((0.959999979f)));
    a->unk_50 = fn_1_5B188_operand((a->unk_50), ((0.959999979f)));
    a->unk_3C = a->unk_3C + a->unk_48;
    a->unk_40 = a->unk_40 + a->unk_4C;
    a->unk_44 = a->unk_44 + a->unk_50;
    a->unk_5E = (s16)(fn_1_5B188_operand(((0.99000001f)), ((f32)a->unk_5E)));
    a->unk_58 = a->unk_58 + a->unk_5E;
    a->unk_1C = a->unk_1C + (f32)(fn_1_5B188_operand(((0.0500000007f)), ((f32)((0.400000006f) - a->unk_1C))));
    a->unk_20 = a->unk_20 + (f32)(fn_1_5B188_operand(((0.0505000018f)), ((f32)((0.400000006f) - a->unk_20))));
    a->unk_24 = a->unk_24 + (f32)(fn_1_5B188_operand(((0.050999999f)), ((f32)((0.400000006f) - a->unk_24))));
    if ((f32)a->unk_10 < (15.0f)) {
        a->unk_B4 = fn_1_5B188_operand((a->unk_B4), ((f32)(f - d)));
        a->unk_2C = fn_1_5B188_operand((a->unk_2C), ((0.949999988f)));
    } else {
        a->unk_B4 = a->unk_B4 + (f32)(fn_1_5B188_operand(((0.200000003f)), ((f32)(f - a->unk_B4))));
    }
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_5B188 */

/* fzgx:begin fn_1_5B30C */
struct fn_1_5B30C_Arg0 {
    u8 pad_0[0x34];
    u32 unk_34;
};


void fn_1_5B30C(struct fn_1_5B30C_Arg0 *arg0) {
    u32 v0;
    u32 v1;
    f32 v2;
    u32 t3;
    v0 = arg0->unk_34;
    lbl_8006D9D8((void *)((u32)arg0 + 60));
    lbl_8006D7B0();
    lbl_8006E14C((*(f32 *)((u8 *)(u32)arg0 + 40) / *(f32 *)((u8 *)v0 + 20)));
    t3 = fn_1_54E34((void *)(v0 + 8), *(f32 *)((u8 *)(u32)arg0 + 40));
    v1 = t3;
    if ((s32)t3 != 0) {
    v1 = *(s16 *)((u8 *)(u32)arg0 + 88);
    mathutil_mtxA_rotate_z(v1);
    v2 = *(f32 *)((u8 *)(u32)arg0 + 28);
    fn_1_5621C(v2, *(f32 *)((u8 *)(u32)arg0 + 32), *(f32 *)((u8 *)(u32)arg0 + 36), *(f32 *)((u8 *)(u32)arg0 + 180));
    v1 = 1;
    fn_1_56000(v1, 3, 0);
    v1 = v0;
    fn_1_557C4((void *)v1);
    v2 = (*(f32 *)&lbl_1_rodata_2978);
    fn_1_5621C(v2, v2, v2, v2);
    v1 = 1;
    fn_1_56000(v1, 3, 1);
    }
}
/* fzgx:end fn_1_5B30C */

/* fzgx:begin fn_1_5B3CC */
// fn_1_5B3CC: empty in retail (single blr).
void fn_1_5B3CC(void) {
}
/* fzgx:end fn_1_5B3CC */

/* fzgx:begin fn_1_5B3D0 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
}
#pragma section code_type ".text"

extern const struct fn_1_5B3D0_lbl_1_rodata_2950_pool {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
    u8 pad_C[0x88];
    f32 unk_94;
} fn_1_5B3D0_lbl_1_rodata_2950;

struct fn_1_5B3D0_Arg0 {
    u8 pad_0[0x10];
    u32 unk_10;
};

struct fn_1_5B3D0_State {
    u32 unk_0;
};



#pragma opt_common_subs off
#pragma opt_lifetimes on
#pragma opt_strength_reduction off
void fn_1_5B3D0(struct fn_1_5B3D0_Arg0 *arg0) {
    u32 next;
    struct fn_1_5B3D0_State *state;
    struct { u32 value; } random;
    struct { f32 value; } r;

    state = &(*(struct fn_1_5B3D0_State *)&lbl_1_data_1D628);
    next = ((1103515245) * (state->unk_0)) + 12345;
    { u32 __reg_value_random = (next >> 16) & 0x7FFF; random.value = __reg_value_random; }
    { f32 __reg_value_r = (f32)random.value; r.value = __reg_value_r; }
    { f32 __reg_value_r = r.value / (32767.0f); r.value = __reg_value_r; }
    { f32 __reg_value_r = (0.100000001f) * r.value; r.value = __reg_value_r; }
    state->unk_0 = next;
    arg0->unk_10 = (s32)((60.0f) * ((0.125f) + r.value));
}
#pragma opt_strength_reduction reset

#pragma opt_lifetimes reset

#pragma opt_common_subs reset
/* fzgx:end fn_1_5B3D0 */

/* fzgx:begin fn_1_5B450 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
}
#pragma section code_type ".text"

typedef struct {
    u8 pad_0[0x10];
    s32 unk_10;
    u8 pad_14[0x4];
    s16 unk_18;
    u8 pad_1A[0x2];
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2C;
    u8 pad_30[0xC];
    u8 unk_3C[0x1C];
    s16 unk_58;
    u8 pad_5A[0x3A];
    u8 unk_94[0x4];
} Effect_5B450;


/* Linear congruential random number, 15 bits (ANSI rand). */
static inline s32 effect_rand(void) {
    lbl_1_data_1D628 = lbl_1_data_1D628 * 0x41C64E6D + 0x3039;
    return (lbl_1_data_1D628 >> 16) & 0x7FFF;
}

#pragma opt_propagation off
void fn_1_5B450(Effect_5B450 *e) {
    u8 * fzgx_live;
    f32 t;

    fn_1_8645C(e->unk_18, lbl_801A6D00);
    fzgx_live = e->unk_94;
    lbl_8006E1B0( (Fn183D28Vec3 *)(void *)(fzgx_live), (Fn183D28Vec3 *)(void *)(e->unk_3C));
    e->unk_58 += effect_rand();
    e->unk_2C *= 0.95f;
    e->unk_28 += e->unk_2C;
    if ((f32)e->unk_10 < 60.0f) {
        t = 1.0f - 1.0f / (f32)(e->unk_10 + 1);
        e->unk_1C *= t;
        e->unk_20 *= 0.99f * t;
        e->unk_24 *= 0.95f * t;
    }
}
#pragma opt_propagation reset
/* fzgx:end fn_1_5B450 */

/* fzgx:begin fn_1_5B578 noprologue */
#include "rel/main_rel/effect.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const unsigned long fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const unsigned long fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

extern s32 lbl_801A66A0;
extern s32 fn_1_54E34(void *, f32);
extern void fn_1_56000(u8, u8, u8);
extern void fn_1_5621C(f32, f32, f32, f32);
extern void fn_1_557C4(void *);
extern void lbl_8006D9D8(void *);
extern void lbl_8006D7B0(void);
extern void lbl_8006E14C(f32);
extern f32 lbl_8006D0B4(f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006D848(f32);
extern void lbl_8006DFC4(void *);

typedef struct {
    u8 pad0[2];
    s16 s2;
    u8 pad4[0x18];
    f32 f1c;
    f32 f20;
    f32 f24;
    f32 f28;
    u8 pad2c[8];
    u8 *p34;
    u8 pad38[4];
    u8 v3c[1];
} EffObj;

static inline f32 sqmag(f32 *p)
{
    return (f32)(p[0] * p[0]) + p[1] * p[1] + p[2] * p[2];
}

#pragma opt_common_subs off
#pragma opt_propagation off
void fn_1_5B578(EffObj *a)
{
    struct { f32 v[3]; f32 w[3]; f32 pad[9]; } L;
    u8 *p = a->p34;
    f32 s;
    u8 *q;

    if ((lbl_801A66A0 + a->s2) & 1) {
        s = 1.0f;
    } else {
        s = 0.9f;
    }
    lbl_8006D9D8(a->v3c);
    if (fn_1_54E34(p + 8, a->f28)) {
        q = *(u8 **)(*(u8 **)((u8 *)lbl_1_bss_38458 + 8) + 0x70);
        lbl_8006D7B0();
        {
            f32 factor = a->f28 / *(f32 *)(q + 0x14);
            lbl_8006E14C(factor * s);
        }
        {
            f32 mag = L.v[0] * L.v[0];
            mag += L.v[1] * L.v[1];
            mag += L.v[2] * L.v[2];
            s = lbl_8006D0B4(mag);
        }
        if (s > 0.1f + (f32)(2.0f * a->f28)) {
            lbl_8006DB74(L.w);
            lbl_8006D848((s - (f32)(2.0f * a->f28)) / s);
            lbl_8006DFC4(L.w);
        }
        fn_1_56000(1, 3, 0);
        fn_1_5621C(a->f1c, a->f20, a->f24, 0.2f);
        fn_1_557C4(q);
        fn_1_5621C(1.0f, 1.0f, 1.0f, 1.0f);
        fn_1_56000(1, 3, 1);
    }
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_5B578 */

/* fzgx:begin fn_1_5B6F0 */
// fn_1_5B6F0: empty in retail (single blr).
void fn_1_5B6F0(void) {
}
/* fzgx:end fn_1_5B6F0 */

/* fzgx:begin fn_1_5B6F4 */
typedef struct Fn15B6F4 {
    u8 _pad00[0x10];
    s32 unk_10;
    s32 unk_14;
} Fn15B6F4;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 150.0;
    d = 10.0;
    d = 3.0;
}
#pragma section code_type ".text"
void fn_1_5B6F4(Fn15B6F4 *obj) {
    u32 seed = lbl_1_data_1D628 * 1103515245 + 12345;
    f32 r = (f32)((seed >> 16) & 0x7FFF) / 32767.0f;
    f64 d = 10.0 * ((f64)r - 3.0);

    lbl_1_data_1D628 = seed;
    obj->unk_10 = (s32)(150.0 + d);
    obj->unk_14 = obj->unk_10 - 20;
}
/* fzgx:end fn_1_5B6F4 */

/* fzgx:begin fn_1_5B780 */
typedef struct Fn15B780 {
    u8 state;
    u8 _pad01[0x0f];
    int current;
    int maximum;
    u8 _pad18[0x94];
    s16 step;
    u8 _padAE[0x04];
    f32 result;
} Fn15B780;

void fn_1_5B780(Fn15B780 *effect) {
    effect->state = 2;
    if (effect->current <= effect->maximum) {
        effect->step += 2;
        if (effect->step >= 14) {
            effect->step = 14;
        }
    }
    effect->result = lbl_1_rodata_29A4 * (f32)effect->current;
}
/* fzgx:end fn_1_5B780 */

/* fzgx:begin fn_1_5BF6C */
// fn_1_5BF6C: empty in retail (single blr).
void fn_1_5BF6C(void) {
}
/* fzgx:end fn_1_5BF6C */

/* fzgx:begin fn_1_5BF70 */
struct fn_1_5BF70_Arg0 {
    u8 pad_0[0x10];
    s32 unk_10;
};
struct fn_1_5BF70_lbl_1_data_1D628 {
    u32 unk_0;
};


#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 150.0;
    d = 10.0;
    d = 3.0;
}
static const u32 fzgx_pool_table6[2] = {0x00000000, 0x3DCCCCCD};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -2.4000000953674316f;
    s = 5.0f;
    d = 1.2;
    d = 0.1;
    s = 10.0f;
    s = 18.0f;
    d = 0.7;
    d = 50.0;
}
#pragma section code_type ".text"
void fn_1_5BF70(struct fn_1_5BF70_Arg0 *arg0) {
    u32 seed;
    f32 normalized;
    f64 value;

    seed = lbl_1_data_1D628 * 0x41c64e6d + 0x3039;
    lbl_1_data_1D628 = seed;
    normalized = (f32)((seed >> 16) & 0x7fff) / 32767.0f;
    value = 10.0 * ((f64)normalized - 3.0);
    arg0->unk_10 = (s32)(value + 50.0);
}
/* fzgx:end fn_1_5BF70 */

/* fzgx:begin fn_1_5BFF0 */
struct fn_1_5BFF0_Arg0 {
    u8 unk_0;
    u8 pad_1[0xF];
    u32 unk_10;
    u8 pad_14[0x98];
    s16 unk_AC;
    u8 pad_AE[0x6];
    f32 unk_B4;
};

void fn_1_5BFF0(struct fn_1_5BFF0_Arg0 *arg0) {
    arg0->unk_0 = 2;
    arg0->unk_AC += 2;
    if (arg0->unk_AC >= 15) {
    arg0->unk_AC = 15;
    }
    arg0->unk_B4 = (lbl_1_rodata_29A4 * (f32)(s32)arg0->unk_10);
}
/* fzgx:end fn_1_5BFF0 */

/* fzgx:begin fn_1_5C780 */
// fn_1_5C780: empty in retail (single blr).
void fn_1_5C780(void) {
}
/* fzgx:end fn_1_5C780 */

/* fzgx:begin fn_1_5C784 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
}
#pragma section code_type ".text"

typedef struct EffectVec3 {
    u32 x;
    u32 y;
    u32 z;
} EffectVec3;

typedef struct EffectWork {
    u8 pad_00[0x10];
    s32 unk_10;
    u8 pad_14[0x4];
    s16 unk_18;
    u8 pad_1a[0x22];
    EffectVec3 unk_3c;
    u8 pad_48[0x4c];
    EffectVec3 unk_94;
    u8 pad_a0[0x18];
    u8 unk_b8;
} EffectWork;

#pragma opt_loop_invariants off
// Rolls a random lifetime if unset, then copies the saved position and updates the transform.
void fn_1_5C784(EffectWork *self) {
    if (self->unk_10 == 0) {
        u32 value = lbl_1_data_1D628 * 0x41C64E6D + 0x3039;
        lbl_1_data_1D628 = value;
        value = (value >> 16) & 0x7FFF;
        self->unk_10 = (s32)(60.0f * (0.1f + (f32)value / 32767.0f));
    }
    self->unk_3c = self->unk_94;
    fn_1_8636C(self->unk_18, &self->unk_b8);
}
#pragma opt_loop_invariants reset
/* fzgx:end fn_1_5C784 */

/* fzgx:begin fn_1_5C83C */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 150.0;
    d = 10.0;
    d = 3.0;
}
static const u32 fzgx_pool_table6[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 5.0f;
    d = 1.2;
    d = 0.1;
    s = 10.0f;
    s = 18.0f;
    d = 0.7;
    d = 50.0;
}
static const u32 fzgx_pool_table8[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 19.0f;
    d = 24.0;
}
#pragma section code_type ".text"

struct Fn1_5C83CObject {
    u8 state;
    u8 _pad01[0xf];
    s32 age;
    u8 _pad14[0x4];
    s16 owner;
    u8 _pad1a[0x2];
    f32 color_1c;
    f32 color_20;
    f32 color_24;
    f32 size;
    f32 target_size;
    u8 _pad30[0xc];
    f32 pos_3c;
    f32 pos_40;
    f32 pos_44;
    f32 vel_48;
    f32 vel_4c;
    f32 vel_50;
    u8 _pad54[0x34];
    f32 blend;
    f32 target_blend;
    u8 _pad90[0x4];
    f32 acc_94;
    f32 acc_98;
    f32 acc_9c;
    u8 _pada0[0x12];
    u16 flag_b2;
    u8 _padb4[0x4];
    u8 matrix_b8[1];
};


void fn_1_5C83C(struct Fn1_5C83CObject *self) {
    f32 mtx[12];
    f32 pos[3];
    f32 t;
    s32 age;

    self->state = 2;
    fn_1_862D4(self->owner, pos);
    fn_1_8636C(self->owner, mtx);

    t = 1.0f - self->blend;
    self->vel_48 *= t;
    self->vel_4c *= t;
    self->vel_50 *= t;
    self->pos_3c += self->vel_48;
    self->pos_40 += self->vel_4c;
    self->pos_44 += self->vel_50;

    if (self->flag_b2 != 0) {
        self->acc_94 += (f32)(0.2f * self->vel_48);
        self->acc_98 += (f32)(0.2f * self->vel_4c);
        self->acc_9c += (f32)(0.2f * self->vel_50);
    }

    fn_8006FA24(self->matrix_b8, mtx, self->matrix_b8, 0.05f);

    self->blend += (f32)(0.05f * (self->target_blend - self->blend));
    self->size += (f32)(0.2f * (self->target_size - self->size));

    age = self->age;
    if (age < 24.0) {
        /* the common factor is CSE'd by the compiler; writing it out per
           component keeps the color load ahead of the literal */
        self->color_1c = self->color_1c * (1.0f - 1.0f / (f32)(age + 1));
        self->color_20 = self->color_20 * (1.0f - 1.0f / (f32)(age + 1));
        self->color_24 = self->color_24 * (1.0f - 1.0f / (f32)(age + 1));
    }
}
/* fzgx:end fn_1_5C83C */

/* fzgx:begin fn_1_5D010 */
// fn_1_5D010: empty in retail (single blr).
void fn_1_5D010(void) {
}
/* fzgx:end fn_1_5D010 */

/* fzgx:begin fn_1_5D014 */
typedef struct Fn1_5D014Object {
    u8 pad[0xae];
    s16 field_ae;
} Fn1_5D014Object;

void fn_1_5D014(Fn1_5D014Object *obj) {
    obj->field_ae = 0;
}
/* fzgx:end fn_1_5D014 */

/* fzgx:begin fn_1_5D1B8 noprologue */
typedef float f32;
typedef unsigned char u8;
typedef unsigned int u32;
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const unsigned long fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const unsigned long fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 150.0;
    d = 10.0;
    d = 3.0;
}
static const unsigned long fzgx_pool_table6[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 5.0f;
    d = 1.2;
    d = 0.1;
    s = 10.0f;
    s = 18.0f;
    d = 0.7;
    d = 50.0;
}
static const unsigned long fzgx_pool_table8[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const unsigned long *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 19.0f;
    d = 24.0;
    s = 0.7071067690849304f;
}
static const unsigned long fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const unsigned long *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 255.0;
    d = 0.9;
    s = 0.004000000189989805f;
    s = 0.0010000000474974513f;
    s = 0.009999999776482582f;
    s = -1.1920928955078125e-07f;
    s = 240.0f;
    s = 100.0f;
    s = 300.0f;
    s = 200.0f;
    s = 10000.0f;
    s = 5000.0f;
}
#pragma section code_type ".text"

typedef short s16;
typedef struct { f32 x, y, z; } V3;
typedef struct { f32 a, b; u8 pad[0x34]; u8 c[4]; } Part;
typedef struct { u8 p0[0x14]; f32 f14; } Sub;
typedef struct {
    u8 p0[0x1c]; f32 f1c; f32 f20; f32 f24; f32 f28; u8 p2c[8];
    Sub *sub; u8 p38[4]; V3 pos; u8 p48[0x66]; s16 rot;
} Obj;

extern f32 fn_1_A71AC(void);
extern int fn_1_9F914(const void *, const void *);
extern void lbl_8006DCA4(void);
extern void lbl_8006E1B0(void *, void *);
extern void lbl_8006D7DC(void *);
extern void mathutil_mtxA_rotate_z(int);
extern void *memset(void *, int, u32);
extern void lbl_8006DB74(void *);

#pragma opt_propagation off
void fn_1_5D1B8(Obj *o)
{
    f32 fzgx_live;
    Sub *s = o->sub;
    f32 sc = o->f28;
    V3 v;
    Part p;
    f32 r, k, a;

    lbl_8006DCA4();
    lbl_8006E1B0(&o->pos, &v);
    if (!(v.z > -1.1920929e-07f)) {
        r = fn_1_A71AC();
        fzgx_live = v.z;
        fzgx_live = -fzgx_live;
        r = fzgx_live * r;
        k = (240.0f * ((2.0f * s->f14) * sc)) / r;
        a = 1.0f;
        if (k < 100.0f) return;
        if (k < 300.0f) a *= (k - 100.0f) / 200.0f;
        if (k > 10000.0f) return;
        if (k > 5000.0f) a *= 1.0f - (k - 5000.0f) / 5000.0f;
        lbl_8006D7DC(&v);
        mathutil_mtxA_rotate_z(o->rot);
        memset(&p, 0, 0x40);
        lbl_8006DB74((u8 *)&p + 8);
        p.a = 0.70710677f * sc;
        p.c[0] = (u8)(255.0f * o->f1c * a);
        p.c[1] = (u8)(255.0f * o->f20 * a);
        p.c[2] = (u8)(255.0f * o->f24 * a);
        p.c[3] = (u8)(255.0f * a);
        p.b = p.a;
        fn_1_9F914(&p, s);
    }
}
#pragma opt_propagation reset
/* fzgx:end fn_1_5D1B8 */

/* fzgx:begin fn_1_5D374 */
// fn_1_5D374: empty in retail (single blr).
void fn_1_5D374(void) {
}
/* fzgx:end fn_1_5D374 */

/* fzgx:begin fn_1_5D378 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
}
static const unsigned long fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
    s = 0.0f;
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const unsigned long fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 150.0;
    d = 10.0;
    d = 3.0;
}
static const unsigned long fzgx_pool_table6[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 5.0f;
    d = 1.2;
    d = 0.1;
    s = 10.0f;
    s = 18.0f;
    d = 0.7;
    d = 50.0;
}
static const unsigned long fzgx_pool_table8[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const unsigned long *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 19.0f;
    d = 24.0;
    s = 0.7071067690849304f;
}
static const unsigned long fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const unsigned long *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 255.0;
    d = 0.9;
    s = 0.004000000189989805f;
    s = 0.0010000000474974513f;
    s = 0.009999999776482582f;
    s = -1.1920928955078125e-07f;
    s = 240.0f;
    s = 100.0f;
    s = 300.0f;
    s = 200.0f;
    s = 10000.0f;
    s = 5000.0f;
    s = 204.0f;
    s = 85.0f;
}
#pragma section code_type ".text"

typedef struct FxObj {
    u8 pad0[0x10];
    s32 unk_10;
    u8 pad14[4];
    s16 unk_18;
    u8 pad1A[2];
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
} FxObj;

void fn_1_5D378(FxObj *obj)
{
    s32 cam;
    f32 r;

    if (obj->unk_10 == 0) {
        lbl_1_data_1D628 = lbl_1_data_1D628 * 0x41C64E6D + 0x3039;
        r = (f32)((lbl_1_data_1D628 >> 16) & 0x7FFF) / 32767.0f;
        obj->unk_10 = (s32)(60.0f * (0.4f + (f32)(0.1f * r)));
    }
    cam = (s8)fn_1_86634(obj->unk_18);
    if ((s32)fn_1_6EC0(cam) != 0 && camera_get_entry_field_0xa4((u8)cam) == 0) {
        obj->unk_1C = 0.0f;
        obj->unk_20 = 0.0f;
        obj->unk_24 = 0.0f;
    } else {
        f32 t;
        lbl_1_data_1D628 = lbl_1_data_1D628 * 0x41C64E6D + 0x3039;
        t = 0.5f + (f32)(0.2f * ((f32)((lbl_1_data_1D628 >> 16) & 0x7FFF) / 32767.0f));
        obj->unk_1C = (204.0f * (0.5f * (1.0f + t))) / 255.0f;
        obj->unk_20 = (85.0f * t) / 255.0f;
        obj->unk_24 = 0.0f;
    }
}
/* fzgx:end fn_1_5D378 */

/* fzgx:begin fn_1_5D4FC */
// fn_1_5D4FC: empty in retail (single blr).
void fn_1_5D4FC(void) {
}
/* fzgx:end fn_1_5D4FC */

/* fzgx:begin fn_1_5D500 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
}
static const unsigned long fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
    s = 0.0f;
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const unsigned long fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 150.0;
    d = 10.0;
    d = 3.0;
}
static const unsigned long fzgx_pool_table6[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 5.0f;
    d = 1.2;
    d = 0.1;
    s = 10.0f;
    s = 18.0f;
    d = 0.7;
    d = 50.0;
}
static const unsigned long fzgx_pool_table8[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const unsigned long *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 19.0f;
    d = 24.0;
    s = 0.7071067690849304f;
}
static const unsigned long fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const unsigned long *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 255.0;
    d = 0.9;
    s = 0.004000000189989805f;
    s = 0.0010000000474974513f;
    s = 0.009999999776482582f;
    s = -1.1920928955078125e-07f;
    s = 240.0f;
    s = 100.0f;
    s = 300.0f;
    s = 200.0f;
    s = 10000.0f;
    s = 5000.0f;
    s = 204.0f;
    s = 85.0f;
    s = -0.05000000074505806f;
}
#pragma section code_type ".text"

typedef struct EffectGlow {
    u8 pad_0[0x8];
    u32 flags;
    u8 pad_C[0x4];
    s32 counter;
    u8 pad_14[0x4];
    s16 id;
    u8 pad_1A[0x2];
    f32 r;
    f32 g;
    f32 b;
    u8 pad_28[0x14];
    u8 unk_3C[0xC];
} EffectGlow;

void fn_1_5D500(EffectGlow *e) {
    s32 cam;
    f32 t;
    f32 s;

    if (((fn_1_86514(e->id) >> 27) & 1) && ((e->flags >> 18) & 1)) {
        e->counter++;
    } else {
        e->flags &= ~0x40000;
    }
    fn_1_867CC(e->id, e->unk_3C);
    cam = (s8)fn_1_86634(e->id);
    if ((s32)fn_1_6EC0(cam) != 0 && camera_get_entry_field_0xa4((u8)cam) == 0) {
        e->r += (f32)(0.05f * -e->r);
        e->g += (f32)(0.05f * -e->g);
        e->b += (f32)(0.05f * -e->b);
    } else {
        lbl_1_data_1D628 = lbl_1_data_1D628 * 0x41C64E6D + 0x3039;
        t = 0.5f + (f32)(0.1f * ((f32)((lbl_1_data_1D628 >> 16) & 0x7FFF) / 32767.0f));
        e->r = (204.0f * (0.5f * (1.0f + t))) / 255.0f;
        e->g = (85.0f * t) / 255.0f;
        e->b = 0.0f;
    }
    if (lbl_1_data_2A7E0.unk_0 == 6) {
        e->r *= 0.2f;
        e->g *= 0.2f;
        e->b *= 0.2f;
    }
    if (e->counter < 20) {
        t = 1.0f + (f32)(-0.05f * (f32)e->counter);
        e->r *= 1.0f - t;
        e->g *= 1.0f - t;
        e->b *= 1.0f - t;
    }
}
/* fzgx:end fn_1_5D500 */

/* fzgx:begin fn_1_5D718 noprologue */
#include "psvec.h"

extern const f32 lbl_1_rodata_2950[];
extern void lbl_8006D9D8(void *);
extern void lbl_8006D7B0(void);
extern f32 lbl_8006D0B4(f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006D848(f32);
extern void lbl_8006DFC4(void *);
extern void fn_1_9F914(void *, u32);
extern void *memset(void *, int, u32);

struct Fn15D718 {
    u8 _pad00[0x1c];
    f32 value1c;
    f32 value20;
    f32 value24;
    f32 value28;
    u8 _pad2c[0x08];
    u32 object34;
    u8 _pad38[0x04];
    f32 value3c;
};
struct Fn15D718Tmp {
    u8 data[0x30];
};
struct Fn15D718Sub {
    u8 data[0x34];
};
struct Fn15D718Work {
    f32 alpha;
    f32 alpha2;
    struct Fn15D718Sub sub;
    u8 red;
    u8 green;
    u8 blue;
    u8 alphaByte;
};

#pragma opt_propagation off
#pragma opt_common_subs on
static inline f32 *fn_1_5D718_array_read(f32 *array) { return array; }
static inline f32 fn_1_5D718_array_read_(s32 index, f32 *array) { return array[index]; }
#pragma opt_strength_reduction off
void fn_1_5D718(struct Fn15D718 *self) {
    struct Fn15D718Work work;
    struct Fn15D718Tmp tmp;
    u32 object;
    f32 radius;
    f32 distance;
    f32 alpha;
    const f32 *pool;
    f32 v[3];
    f32 x;
    f32 y;
    f32 z;
    f32 sq;
    f32 vy;

    object = self->object34;
    pool = lbl_1_rodata_2950;
    radius = self->value28;
    lbl_8006D9D8(&self->value3c);
    lbl_8006D7B0();
    /* translation column of the current matrix in the locked cache */
    x = (*(f32 *)(0xE0000000 + 0xC));
    y = (*(f32 *)(0xE0000000 + 0x1C));
    (void) y;  /* fzgx: keeps the web at its definition */
    psvec_set(v, (z = (*(f32 *)(0xE0000000 + 0x2C))), y, x);
    sq = (f32)(fn_1_5D718_array_read_(0, v) * (*((0) + (v))));
    sq += fn_1_5D718_array_read_(1, v) * fn_1_5D718_array_read_(1, v);
    sq += fn_1_5D718_array_read_(2, v) * fn_1_5D718_array_read_(2, v);
    distance = lbl_8006D0B4(sq);
    if (distance > pool[1] + radius) {
        lbl_8006DB74(&tmp);
        lbl_8006D848((distance - radius) / distance);
        lbl_8006DFC4(&tmp);
    }
    memset(&work, 0, 0x40);
    lbl_8006DB74(&work.sub);
    alpha = pool[0x150 / 4] * self->value28;
    work.alpha = alpha;
    work.red = (u8)(pool[0x5c / 4] * self->value1c);
    work.green = (u8)(pool[0x5c / 4] * self->value20);
    work.blue = (u8)(pool[0x5c / 4] * self->value24);
    work.alphaByte = 0xff;
    work.alpha2 = alpha;
    fn_1_9F914(&work, object);
}
#pragma opt_strength_reduction reset

#pragma opt_common_subs reset
#pragma opt_propagation reset
/* fzgx:end fn_1_5D718 */

/* fzgx:begin fn_1_5D88C */
struct Fn15D88C {
    u8 _pad08[0x08];
    u32 flags;
    u8 _pad0c[0x1c];
    f32 value28;
    u8 _pad2c[0x08];
    u32 enabled;
    u8 _pad38[0x1c];
    u16 value54;
    u16 value56;
    u16 value58;
    u8 _pad5a[0x5a];
    f32 value_b4;
};

void fn_1_5D88C(struct Fn15D88C *self) {
    self->value_b4 = lbl_1_rodata_29AC[0];
    if (self->enabled != 0) {
        f32 value28;
        lbl_1_data_1D628 = lbl_1_data_1D628 * 1103515245 + 12345;
        value28 = lbl_1_rodata_2978[0];
        self->value54 = (u16)((lbl_1_data_1D628 >> 16) & 0x7fff);
        lbl_1_data_1D628 = lbl_1_data_1D628 * 1103515245 + 12345;
        self->value56 = (u16)((lbl_1_data_1D628 >> 16) & 0x7fff);
        lbl_1_data_1D628 = lbl_1_data_1D628 * 1103515245 + 12345;
        self->value58 = (u16)((lbl_1_data_1D628 >> 16) & 0x7fff);
        self->value28 = value28;
    }
    self->flags |= 0x40000000;
}
/* fzgx:end fn_1_5D88C */

/* fzgx:begin fn_1_5D918 */
// fn_1_5D918: empty in retail (single blr).
void fn_1_5D918(void) {
}
/* fzgx:end fn_1_5D918 */

/* fzgx:begin fn_1_5E3C4 noprologue */
#include "rel/main_rel/effect.h"

typedef struct Fn1_5E3C4Data {
    u8 pad_00[0x10];
    s32 unk_10;
    u8 pad_14[0x9E];
    u16 unk_B2;
} Fn1_5E3C4Data;

#pragma section code_type ".fzgxpool"
/* volatile: preserve literal pool order by retaining each primer store. */
void fzgx_pool_primer(volatile f32 *f, volatile f64 *d) {
    *f = 60.0f;
    *f = 0.1f;
    *f = 32767.0f;
    *f = 0.05f;
    *d = 0.07;
    *f = 20000.0f;
    *d = 4503599627370496.0;
    *f = 1.0f;
    *f = -0.03f;
    *d = 15.0;
    *d = 4503601774854144.0;
    *d = 1.5;
    *d = 0.5;
    *f = 0.0f;
    *f = 0.5f;
    *f = 8.0f;
    *f = 255.0f;
    *f = 15.0f;
    *f = 0.2f;
    *f = 0.08f;
    *f = 0.25f;
    *f = 0.98f;
    *f = 0.99f;
    *f = 40.0f;
    *f = 20.0f;
    *f = 1.5f;
    *f = 0.45f;
    *f = -2.0f;
    *f = 0.0833333358168602f;
    *f = 0.15f;
    *f = 0.125f;
    *f = -0.4f;
    *f = -0.3f;
    *f = 2.0f;
    *f = 250.0f;
    *d = 0.6;
    *d = 0.4;
    *f = 0.3f;
    *f = -0.004f;
    *f = 0.01666666753590107f;
    *f = 65536.0f;
    *f = 4096.0f;
    *f = 0.96f;
    *f = 0.4f;
}
#pragma section code_type ".text"

void fn_1_5E3C4(Fn1_5E3C4Data *arg0) {
    if (arg0->unk_B2 == 1) {
        if (arg0->unk_10 == 0) {
            lbl_1_data_1D628 = lbl_1_data_1D628 * 0x41C64E6D + 0x3039;
            arg0->unk_10 = (s32)(60.0f * (0.4f + (f32)(0.25f * ((f32)((lbl_1_data_1D628 >> 16) & 0x7FFF) / 32767.0f))));
        }
    } else {
        if (arg0->unk_10 == 0) {
            lbl_1_data_1D628 = lbl_1_data_1D628 * 0x41C64E6D + 0x3039;
            arg0->unk_10 = (s32)(60.0f * (0.08f + (f32)(0.25f * ((f32)((lbl_1_data_1D628 >> 16) & 0x7FFF) / 32767.0f))));
        }
    }
}
/* fzgx:end fn_1_5E3C4 */

/* fzgx:begin fn_1_5EB08 */
typedef struct FnObj {
    u8 pad18[0x18];
    s16 value;
    u8 pad3c[0x22];
    f32 field3c;
} FnObj;

typedef struct FnLocal {
    u8 data[0x10];
} FnLocal;

typedef struct FnNode {
    u8 pad4[4];
    void (*callback)(void);
    FnObj *object;
} FnNode;

void fn_1_5EB08(FnObj *object) {
    FnLocal local;
    FnNode *node;
    FnNode *allocated;

    fn_1_862D4(object->value, &local);
    lbl_8006DCA4();
    if (fn_1_54E34(&object->field3c, lbl_1_rodata_2AF4[0])) {
        node = fn_1_5448C(&local);
        allocated = fn_1_548AC(0xc);
        if (allocated != 0) {
            allocated->callback = fn_1_5EB98;
            allocated->object = object;
            fn_1_5489C( (void **)(void *)(node), (void **)(void *)(allocated));
        }
    }
}
/* fzgx:end fn_1_5EB08 */

/* fzgx:begin fn_1_5F5C4 */
// fn_1_5F5C4: empty in retail (single blr).
void fn_1_5F5C4(void) {
}
/* fzgx:end fn_1_5F5C4 */

/* fzgx:begin fn_1_5F5C8 */
typedef signed long s32;

typedef unsigned char u8;

typedef unsigned long u32;

typedef float f32;
typedef double f64;

/* lbl_1_data_1D628: .data size 0x4, referenced by 41 functions, shape {'object': 185} */

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
volatile f32 s; volatile f64 d; /* fzgx-allow: S2 pool primer sinks */
s = 60.0f;
s = 0.10000000149011612f;
s = 32767.0f;
s = 0.05000000074505806f;
d = 0.07;
s = 20000.0f;
s = 0.0f;
d = 4503599627370496.0;
s = 1.0f;
s = -0.029999999329447746f;
d = 15.0;
d = 4503601774854144.0;
d = 1.5;
d = 0.5;
}
static const u32 fzgx_pool_table2[1] = {0x00000000}; /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; } /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
volatile f32 s; volatile f64 d; /* fzgx-allow: S2 pool primer sinks */
s = 0.5f;
s = 8.0f;
s = 255.0f;
s = 15.0f;
s = 0.20000000298023224f;
s = 0.07999999821186066f;
s = 0.25f;
s = 0.9800000190734863f;
s = 0.9900000095367432f;
s = 40.0f;
s = 20.0f;
s = 1.5f;
s = 0.44999998807907104f;
s = -2.0f;
s = 0.0833333358168602f;
s = 0.15000000596046448f;
s = 0.125f;
s = -0.4000000059604645f;
s = -0.30000001192092896f;
s = 2.0f;
s = 250.0f;
d = 0.6;
d = 0.4;
s = 0.30000001192092896f;
s = -0.004000000189989805f;
}
#pragma section code_type ".text"
typedef struct {
u8 pad_00[0x10];
s32 unk_10;
} fn_1_5F5C8_Fn_1_64F2C_Object;
void fn_1_5F5C8(fn_1_5F5C8_Fn_1_64F2C_Object *obj) {
f32 random;
f32 scaled;
f32 offset;
if (obj->unk_10 == 0) {
{
u32 value;
value = lbl_1_data_1D628 * 0x41c64e6d + 0x3039;
lbl_1_data_1D628 = value;
random = (f32)((value >> 16) & 0x7fff) / 32767.0f;
}
scaled = 0.25f * random;
offset = 0.3f + scaled;
obj->unk_10 = (s32)(60.0f * offset);
}
}
/* fzgx:end fn_1_5F5C8 */

/* fzgx:begin fn_1_5F654 noprologue */
#include "types.h"
#include "game/main_rel/car_test_types.h"
#include "rel/main_rel/effect.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
}
static const u32 fzgx_pool_table1[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime1b(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
    s = 0.0f;
}
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 150.0;
    d = 10.0;
    d = 3.0;
}
static const u32 fzgx_pool_table6[2] = {0x00000000, 0x3DCCCCCD};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -2.4000000953674316f;
    s = 5.0f;
    d = 1.2;
    d = 0.1;
    s = 10.0f;
    s = 18.0f;
    d = 0.7;
    d = 50.0;
}
static const u32 fzgx_pool_table8[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 19.0f;
    d = 24.0;
    s = 0.7071067690849304f;
}
static const u32 fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 255.0;
    d = 0.9;
    s = 0.004000000189989805f;
    s = 0.0010000000474974513f;
    s = 0.009999999776482582f;
}
static const u32 fzgx_pool_table12[1] = {0xB4000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 240.0f;
    s = 100.0f;
    s = 300.0f;
    s = 200.0f;
    s = 10000.0f;
    s = 5000.0f;
    s = 204.0f;
    s = 85.0f;
    s = -0.05000000074505806f;
    s = 4.0f;
    s = -0.05999999865889549f;
    s = -0.5f;
    s = -1.0f;
}
static const u32 fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.2;
    s = 512.0f;
    s = 0.029999999329447746f;
    s = 51.0f;
    s = 88.0f;
    d = -3.0;
    s = 4.5f;
    s = 6.0f;
    s = 1.100000023841858f;
}
static const u32 fzgx_pool_table16[2] = {0x00000000, 0x3F666666};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -1.100000023841858f;
}
static const u32 fzgx_pool_table18[4] = {0x00000000, 0x3F666666, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.699999988079071f;
}
static const u32 fzgx_pool_table20[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.2000000476837158f;
    s = 50.0f;
    s = 0.02500000037252903f;
    s = 0.800000011920929f;
    s = 0.0625f;
    s = 2.5f;
}
#pragma section code_type ".text"

typedef struct fn_1_5F654_Effect {
    u8 pad_00[0x8];
    u32 flags;
    u8 pad_0C[0x4];
    s32 frame;
    u8 pad_14[0x4];
    s16 id;
    u8 pad_1A[0x2];
    f32 color[3];
    f32 speed;
    u8 pad_2C[0x10];
    Fn183D28Vec3 pos;
    u8 pad_48[0xC];
    s16 rot_x;
    s16 rot_y;
    u8 pad_58[0x2];
    s16 rot_vel_x;
    s16 rot_vel_y;
    u8 pad_5E[0x56];
    f32 alpha;
} fn_1_5F654_Effect;

typedef struct {
    u8 pad_000[0x475];
    u8 camera;
} fn_1_5F654_Owner;

extern u32 fn_1_86514(int);
extern void *fn_1_86254(int);
extern void fn_1_862D4(int, Fn183D28Vec3 *);
extern void fn_1_8636C(int, void *);
extern u32 fn_1_6EC0(u8);
extern s16 camera_get_entry_field_0xa4(u32);
extern void *lbl_8006DC6C(void *);
extern void mathutil_mtxA_rotate_y(s32);
extern void mathutil_mtxA_rotate_x(s32);

/* Sets the translation column of the locked-cache matrix A. */
static inline void fn_1_5F654_set_translate(f32 x, f32 y, f32 z) {

    *(f32 *)(0xE0000000 + 0x0C) = x;
    *(f32 *)(0xE0000000 + 0x1C) = y;
    *(f32 *)(0xE0000000 + 0x2C) = z;
}

#pragma opt_propagation on
void fn_1_5F654(fn_1_5F654_Effect *effect) {
    f32 mtx[12];
    Fn183D28Vec3 pos;
    Fn183D28Vec3 tail;
    Fn183D28Vec3 eye;
    fn_1_5F654_Owner *owner;
    f32 t;

    if (((fn_1_86514(effect->id) >> 27) & 1) && ((effect->flags >> 18) & 1)) {
        effect->frame++;
    } else {
        effect->rot_vel_x *= 0.98f;
        effect->rot_vel_y *= 0.98f;
        effect->flags &= ~0x40000;
    }

    owner = fn_1_86254(effect->id);
    fn_1_862D4(effect->id, &pos);
    fn_1_8636C(effect->id, mtx);
    lbl_8006DC6C(mtx);
    {
        {
            f32 fzgx_lc0_z;
            f32 fzgx_lc0_y;
            f32 fzgx_lc0_x;
            fzgx_lc0_x = *(volatile f32 *)&pos.x;  /* fzgx-allow: S2 volatile view keeps the verified load order */
            fzgx_lc0_y = (pos.y);
            fzgx_lc0_z = (pos.z);
            *(f32 *)(0xE0000000 + 0x0C) = fzgx_lc0_x;
            *(f32 *)(0xE0000000 + 0x1C) = fzgx_lc0_y;
            *(f32 *)(0xE0000000 + 0x2C) = fzgx_lc0_z;
        }
    }

    if ((s8)owner->camera != -1 && (s32)fn_1_6EC0(owner->camera) != 0 &&
        camera_get_entry_field_0xa4(owner->camera) == 0) {
        Fn183D28Vec3 offset = {0.0f, 0.0f, 0.0f};

        offset.z = -3.0f;
        eye = offset;
        lbl_8006E1B0(&eye, &eye);
        {
            {
                f32 fzgx_lc1_z;
                f32 fzgx_lc1_y;
                f32 fzgx_lc1_x;
                fzgx_lc1_x = *(volatile f32 *)&eye.x;  /* fzgx-allow: S2 volatile view keeps the verified load order */
                fzgx_lc1_y = (eye.y);
                fzgx_lc1_z = (eye.z);
                *(f32 *)(0xE0000000 + 0x0C) = fzgx_lc1_x;
                *(f32 *)(0xE0000000 + 0x1C) = fzgx_lc1_y;
                *(f32 *)(0xE0000000 + 0x2C) = fzgx_lc1_z;
            }
        }
    }

    effect->rot_x += effect->rot_vel_x;
    effect->rot_y += effect->rot_vel_y;
    mathutil_mtxA_rotate_y(effect->rot_y);
    mathutil_mtxA_rotate_x(effect->rot_x);
    {
        Fn183D28Vec3 offset = {0.0f, 0.0f, 0.0f};

        offset.z = 0.5 * -effect->speed;
        tail = offset;
        lbl_8006E1B0(&tail, &effect->pos);
    }

    effect->alpha = 0.5f * (f32)effect->frame;
    {
        u32 seed = lbl_1_data_1D628 * 0x41C64E6D + 0x3039;

        lbl_1_data_1D628 = seed;
        t = 0.8f + (f32)(0.2f * ((f32)((seed >> 16) & 0x7FFF) / 32767.0f));
    }
    effect->color[0] = (255.0f * (0.5f * (1.0f + t))) / 255.0f;
    effect->color[1] = (85.0f * t) / 255.0f;
    effect->color[2] = 0.0f;
    if (lbl_1_data_2A7E0.unk_0 == 6) {
        effect->color[0] *= 0.2f;
        effect->color[1] *= 0.2f;
        effect->color[2] *= 0.2f;
    }
    if (effect->frame < 20) {
        f32 fade;
        effect->color[0] *= (fade = 1.0f - (1.0f + (f32)(-0.05f * (f32)effect->frame)));
        effect->color[1] *= fade;
        effect->color[2] *= fade;
    }
}
#pragma opt_propagation reset
/* fzgx:end fn_1_5F654 */

/* fzgx:begin fn_1_5F9B8 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/effect.h"
#include "dolphin/os/OSFastCast.h"
#include "dolphin/hw_regs.h"
#include "psvec.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} fn_1_5F9B8_Vec;

typedef struct {
    u8 pad_0[0x18];
    s16 id;
    u8 pad_1A[0x2];
    f32 red;
    f32 green;
    f32 blue;
    f32 size;
    u8 pad_2C[0x10];
    fn_1_5F9B8_Vec pos;
    u8 pad_48[0xC];
    s16 rot_x;
    s16 rot_y;
    u8 pad_58[0x5C];
    f32 scale;
} fn_1_5F9B8_Effect;

typedef struct {
    fn_1_5F9B8_Vec pos;
    f32 radius;
    s16 flags;
    u8 pad_12[0x2];
    u8 color[4];
} fn_1_5F9B8_Light;

typedef struct {
    u8 pad_0[0x8];
    fn_1_5F9B8_Vec pos;
    u8 pad_14[0x10];
    void *tex;
} fn_1_5F9B8_Model;

typedef struct {
    u8 pad_0[0xA0];
    fn_1_5F9B8_Model *glow;
    u8 pad_A4[0x7C];
    void *model;
} fn_1_5F9B8_Assets;

extern void fn_1_867CC(s16 value, void *out);
extern void *fn_1_868C0(s8 index);
extern void *fn_1_86254(int index);
extern int fn_1_9F914(const void *src0, const void *src1);
extern s32 fn_1_54E34(void *arg0, f32 arg1);
extern void fn_1_9EA94(void *light);
extern void lbl_8006D9D8(void *);
extern void lbl_8006D95C(s32);
extern void mathutil_mtxA_rotate_x(s16 value);
extern void *memset(void *, int, u32);
extern void lbl_8006DB74(void *);
extern void lbl_8006D7B0(void);
extern f32 lbl_8006D0B4(f32 value);
extern void lbl_8006D848(f32);
extern void lbl_8006DFC4(void *);
extern void fn_80074788(u32);
extern void fn_80072864(u32);
extern void fn_800745A4(u32, s32, s32, u32, u32, u32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_800735C8(s32, s32);
extern void fn_80073620(s32, s32);
extern void fn_80073C6C(s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072D64(s32, s32, s32, s32, u8, s32);
extern void fn_80072CC4(s32, s32, s32, s32, s32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_80073678(u32);
extern void fn_80074660(u32);
extern void fn_80074918(u8 arg0, s32 arg1, u8 arg2);
extern void fn_800720B0(u32);
extern void fn_800728A8(s32, s32, s32, s32);
extern void fn_80073778(void *, s32);

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
    s = 0.0f;
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 150.0;
    d = 10.0;
    d = 3.0;
}
static const u32 fzgx_pool_table6[2] = {0x00000000, 0x3DCCCCCD};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -2.4000000953674316f;
    s = 5.0f;
    d = 1.2;
    d = 0.1;
    s = 10.0f;
    s = 18.0f;
    d = 0.7;
    d = 50.0;
}
static const u32 fzgx_pool_table8[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 19.0f;
    d = 24.0;
    s = 0.7071067690849304f;
}
#pragma section code_type ".text"
#pragma fp_contract on

void fn_1_5F9B8(fn_1_5F9B8_Effect *effect) {
    u8 camera[12];
    fn_1_5F9B8_Vec pos;
    u8 data[64];
    u8 mtx[0x30];
    fn_1_5F9B8_Light light;
    fn_1_5F9B8_Vec axis;
    fn_1_5F9B8_Model *glow;
    void *model;
    s32 players;
    void *player;
    u32 seed;
    f32 red;
    f32 green;
    f32 blue;
    f32 radius;
    f32 brightness;
    f32 size;
    f32 color_scale;
    f32 base;
    f32 half;
    f32 dist;

    fn_1_867CC(effect->id, camera);
    players = *(s16 *)((u8 *)fn_1_868C0((s8)effect->id) + 0x3ba);
    player = fn_1_86254(effect->id);
    if (players >= 3 && *(s8 *)((u8 *)player + 0x475) == -1) {
        return;
    }

    pos = effect->pos;
    model = ((fn_1_5F9B8_Assets *)lbl_1_bss_38458->unk_8)->model;
    lbl_8006D9D8(camera);
    lbl_8006D95C(effect->rot_y);
    mathutil_mtxA_rotate_x(effect->rot_x);
    memset(data, 0, 64);
    lbl_8006DB74(data + 8);
    size = 0.70710677f * effect->size;
    *(f32 *)(data + 0) = size;
    color_scale = 255.0f;
    data[60] = (u8)(s32)(color_scale * effect->red);
    data[61] = (u8)(s32)(color_scale * effect->green);
    data[62] = (u8)(s32)(color_scale * effect->blue);
    data[63] = 0xff;
    *(f32 *)(data + 4) = size;
    fn_1_9F914(data, model);

    glow = ((fn_1_5F9B8_Assets *)lbl_1_bss_38458->unk_8)->glow;
    base = 0.1f * effect->scale;
    radius = 1.0f + base;
    half = 0.5f * base;
    brightness = 255.0f * ((0.125f + half) * (1.0f + (f32)(((lbl_1_data_1D628 = lbl_1_data_1D628 * 0x41c64e6d + 0x3039) >> 16) & 0x7fff) / 32767.0f));

    fn_80074788(0);
    fn_80072864(0);
    fn_800745A4(0, 1, 4, 60, 0, 125);
    fn_800734A8(0, 0, 0, 255);
    fn_80072AB0(0, 0, 0);
    fn_800735C8(0, 12);
    fn_80073620(0, 28);
    fn_80073C6C(0);
    fn_80072C24(0, 15, 15, 15, 14);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 6, 4, 7);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_80073678(1);
    fn_80074660(1);
    fn_80074918(1, 3, 0);
    fn_800720B0(0);
    fn_800728A8(1, 4, 1, 0);
    fn_80073778(glow->tex, 0);

    memset(&light, 0, sizeof(light));
    red = brightness * effect->red;
    green = brightness * effect->green;
    blue = brightness * effect->blue;
    light.color[0] = __OSf32tou8(red);
    light.color[1] = __OSf32tou8(green);
    light.color[2] = __OSf32tou8(blue);
    light.color[3] = 0xff;
    lbl_8006D9D8(&pos);
    lbl_8006D7B0();
    if (fn_1_54E34(&glow->pos, radius) != 0) {
        /* translation column of the locked-cache matrix */
        psvec_set(&axis, *(f32 *)(LC_BASE + 0x2C), *(f32 *)(LC_BASE + 0x1C), *(f32 *)(LC_BASE + 0x0C));
        /* squared length; the asm block above blocks fp contraction, so fuse explicitly */
        dist = axis.x * axis.x;
        dist = __fmadds(axis.y, axis.y, dist);
        dist = lbl_8006D0B4(__fmadds(axis.z, axis.z, dist));
        if (dist > 0.1f + radius) {
            lbl_8006DB74(mtx);
            lbl_8006D848((dist - radius) / dist);
            lbl_8006DFC4(mtx);
        }
        light.pos = glow->pos;
        light.radius = 0.70710677f * radius;
        light.flags = 0;
        fn_1_9EA94(&light);
    }
}
/* fzgx:end fn_1_5F9B8 */

/* fzgx:begin fn_1_5FE24 */
// fn_1_5FE24: empty in retail (single blr).
void fn_1_5FE24(void) {
}
/* fzgx:end fn_1_5FE24 */

/* fzgx:begin fn_1_5FE28 */
// fn_1_5FE28: empty in retail (single blr).
void fn_1_5FE28(void) {
}
/* fzgx:end fn_1_5FE28 */

/* fzgx:begin fn_1_5FE2C */
// fn_1_5FE2C: empty in retail (single blr).
void fn_1_5FE2C(void) {
}
/* fzgx:end fn_1_5FE2C */

/* fzgx:begin fn_1_5FE30 */
typedef struct {
    u8 unk[0x18];
    s16 value;
    u8 unk1A[0x0E];
    f32 rate;
    u8 unk2C[0x10];
    u8 field3C[1];
} fn_1_5FE30_FZeroObject;

typedef struct {
    u8 unk0[4];
    void (*callback)();
    fn_1_5FE30_FZeroObject *owner;
} FZeroEvent;

// Queue an effect update when the object passes its activation test.
void fn_1_5FE30(fn_1_5FE30_FZeroObject *object) {
    u8 result[8];
    void **callback;
    FZeroEvent *event;

    fn_1_862D4(object->value, result);
    lbl_8006DCA4();
    if (fn_1_54E34(object->field3C, object->rate) != 0) {
        callback = fn_1_5448C(result);
        event = fn_1_548AC(sizeof(FZeroEvent));
        if (event != 0) {
            event->callback = fn_1_5FEBC;
            event->owner = object;
            fn_1_5489C(callback, (void **)event);
        }
    }
}
/* fzgx:end fn_1_5FE30 */

/* fzgx:begin fn_1_5FEBC */
void fn_1_5FEBC(fn_1_5FEBC_EffectObject *object) {
    u8 result[12];
    u8 data[64];
    fn_1_5FEBC_EffectData *effect;
    void *owner;
    f32 color_scale;
    f32 size;

    effect = object->data;
    fn_1_867CC(effect->value18, result);
    owner = effect->field34;
    lbl_8006D9D8(result);
    lbl_8006D7B0();
    mathutil_mtxA_rotate_y(effect->value56);
    mathutil_mtxA_rotate_x(effect->value54);
    memset(data, 0, 64);
    lbl_8006DB74(data + 8);
    size = lbl_1_rodata_2AA0[0];
    size = size * effect->value28;
    *(f32 *)(data + 0) = size;
    color_scale = (((const f32 *)&lbl_1_rodata_29AC))[0];
    data[60] = (u8)(s32)(color_scale * effect->value1C);
    data[61] = (u8)(s32)(color_scale * effect->value20);
    data[62] = (u8)(s32)(color_scale * effect->value24);
    data[63] = 0xff;
    *(f32 *)(data + 4) = size;
    fn_1_9F914(data, owner);
}
/* fzgx:end fn_1_5FEBC */

/* fzgx:begin fn_1_5FFAC */
// fn_1_5FFAC: empty in retail (single blr).
void fn_1_5FFAC(void) {
}
/* fzgx:end fn_1_5FFAC */

/* fzgx:begin fn_1_60170 */
typedef struct {
    u8 unk[0x38];
    void *field38;
} fn_1_60170_FZeroObject;

// Submit the effect data when this object has an associated field.
void fn_1_60170(fn_1_60170_FZeroObject *object) {
    if (object->field38 != 0) {
        fn_1_46B4((u32)lbl_801A6410, (u32)(void *)(object->field38), (const char *)(u8 *)(lbl_1_data_1D62C), 0x1261);
    }
}
/* fzgx:end fn_1_60170 */

/* fzgx:begin fn_1_601B4 */
typedef struct {
    u8 unk_0[0x10];
    s32 unk_10;
    s32 unk_14;
    u8 unk_18[0x24];
    f32 unk_3c;
    f32 unk_40;
    f32 unk_44;
    f32 unk_48;
    f32 unk_4c;
    f32 unk_50;
    u8 unk_54[0x60];
    f32 unk_b4;
} EffectState;


void fn_1_601B4(EffectState *effect) {
    f32 factor;

    effect->unk_14--;
    if (effect->unk_14 > 0) {
        factor = lbl_1_rodata_29C0;
        effect->unk_48 *= factor;
        effect->unk_4c *= factor;
        effect->unk_50 *= factor;
        effect->unk_3c += effect->unk_48;
        effect->unk_40 += effect->unk_4c;
        effect->unk_44 += effect->unk_50;
        effect->unk_b4 = lbl_1_rodata_29F0;
    } else {
        s32 numerator = effect->unk_10;
        s32 denominator = lbl_1_bss_6C86C;

        effect->unk_b4 = (f32)numerator / (f32)denominator;
    }
}
/* fzgx:end fn_1_601B4 */

/* fzgx:begin fn_1_60734 */
typedef struct Fn60734 {
    u8 pad_00[0x0e];
    s16 unk_0e;
    s32 unk_10;
    u8 pad_14[0x14];
    f32 unk_28;
    u8 pad_2c[0x28];
    s16 unk_54;
    s16 unk_56;
    s16 unk_58;
} Fn60734;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
    s = 0.0f;
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 150.0;
    d = 10.0;
    d = 3.0;
}
static const u32 fzgx_pool_table6[2] = {0x00000000, 0x3DCCCCCD};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -2.4000000953674316f;
    s = 5.0f;
    d = 1.2;
    d = 0.1;
    s = 10.0f;
    s = 18.0f;
    d = 0.7;
    d = 50.0;
}
static const u32 fzgx_pool_table8[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 19.0f;
    d = 24.0;
    s = 0.7071067690849304f;
}
static const u32 fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 255.0;
    d = 0.9;
    s = 0.004000000189989805f;
    s = 0.0010000000474974513f;
    s = 0.009999999776482582f;
}
static const u32 fzgx_pool_table12[1] = {0xB4000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 240.0f;
    s = 100.0f;
    s = 300.0f;
    s = 200.0f;
    s = 10000.0f;
    s = 5000.0f;
    s = 204.0f;
    s = 85.0f;
    s = -0.05000000074505806f;
    s = 4.0f;
    s = -0.05999999865889549f;
    s = -0.5f;
    s = -1.0f;
}
static const u32 fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.2;
    s = 512.0f;
    s = 0.029999999329447746f;
    s = 51.0f;
    s = 88.0f;
    d = -3.0;
    s = 4.5f;
    s = 6.0f;
    s = 1.100000023841858f;
}
static const u32 fzgx_pool_table16[2] = {0x00000000, 0x3F666666};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -1.100000023841858f;
}
static const u32 fzgx_pool_table18[4] = {0x00000000, 0x3F666666, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.699999988079071f;
}
static const u32 fzgx_pool_table20[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.2000000476837158f;
    s = 50.0f;
    s = 0.02500000037252903f;
    s = 0.800000011920929f;
    s = 0.0625f;
    s = 2.5f;
}
static const u32 fzgx_pool_table22[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -3.0f;
}
static const u32 fzgx_pool_table24[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const u32 *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.01;
    s = 1.8600000143051147f;
}
static const u32 fzgx_pool_table26[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep26(void) { const u32 *volatile cp; cp = fzgx_pool_table26; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime27(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 210.0;
    d = 0.02;
}
#pragma section code_type ".text"
void fn_1_60734(Fn60734 *effect) {
    u32 value;

    if (effect->unk_10 == 0) {
        value = lbl_1_data_1D628 * 1103515245 + 12345;
        lbl_1_data_1D628 = value;
        effect->unk_10 = (s32)(210.0 + 60.0f * ((f32)((value >> 16) & 0x7fff) / 32767.0f));
    }

    effect->unk_0e = 0;
    if (0.0f == effect->unk_28) {
        f64 prod;
        value = lbl_1_data_1D628 * 1103515245 + 12345;
        lbl_1_data_1D628 = value;
        prod = 0.02 * ((f32)((value >> 16) & 0x7fff) / 32767.0f);
        effect->unk_28 = (f32)(prod + 0.02);
    }

    value = lbl_1_data_1D628 * 1103515245 + 12345;
    lbl_1_data_1D628 = value;
    effect->unk_54 = (value >> 16) & 0x7fff;

    value = lbl_1_data_1D628 * 1103515245 + 12345;
    lbl_1_data_1D628 = value;
    effect->unk_56 = (value >> 16) & 0x7fff;

    value = lbl_1_data_1D628 * 1103515245 + 12345;
    lbl_1_data_1D628 = value;
    effect->unk_58 = (value >> 16) & 0x7fff;
}
/* fzgx:end fn_1_60734 */

/* fzgx:begin fn_1_60C70 */
// fn_1_60C70: empty in retail (single blr).
void fn_1_60C70(void) {
}
/* fzgx:end fn_1_60C70 */

/* fzgx:begin fn_1_60C74 */
struct fn_1_60C74_Effect {
    u8 _pad[0x28];
    f32 field_28;
};

void fn_1_60C74(struct fn_1_60C74_Effect *effect) {
    effect->field_28 = lbl_1_rodata_2A5C[0];
}
/* fzgx:end fn_1_60C74 */

/* fzgx:begin fn_1_60C84 */
// fn_1_60C84: empty in retail (single blr).
void fn_1_60C84(void) {
}
/* fzgx:end fn_1_60C84 */

/* fzgx:begin fn_1_60C88 noprologue */
#include "types.h"
#include "dolphin/hw_regs.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
}
static const unsigned long fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
    s = 0.0f;
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const unsigned long fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 150.0;
    d = 10.0;
    d = 3.0;
}
static const unsigned long fzgx_pool_table6[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 5.0f;
    d = 1.2;
    d = 0.1;
    s = 10.0f;
    s = 18.0f;
    d = 0.7;
    d = 50.0;
}
static const unsigned long fzgx_pool_table8[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const unsigned long *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 19.0f;
    d = 24.0;
    s = 0.7071067690849304f;
}
static const unsigned long fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const unsigned long *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 255.0;
    d = 0.9;
    s = 0.004000000189989805f;
    s = 0.0010000000474974513f;
    s = 0.009999999776482582f;
    s = -1.1920928955078125e-07f;
    s = 240.0f;
    s = 100.0f;
    s = 300.0f;
    s = 200.0f;
    s = 10000.0f;
    s = 5000.0f;
    s = 204.0f;
    s = 85.0f;
    s = -0.05000000074505806f;
    s = 4.0f;
    s = -0.05999999865889549f;
    s = -0.5f;
    s = -1.0f;
}
static const unsigned long fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const unsigned long *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.2;
    s = 512.0f;
    s = 0.029999999329447746f;
    s = 51.0f;
    s = 88.0f;
    d = -3.0;
    s = 4.5f;
    s = 6.0f;
}
static const unsigned long fzgx_pool_table14[12] = {0x3F8CCCCD, 0x00000000, 0x3F666666, 0xBF8CCCCD, 0x00000000, 0x3F666666, 0x00000000, 0x00000000, 0xBF333333, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const unsigned long *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.2000000476837158f;
    s = 50.0f;
    s = 0.02500000037252903f;
    s = 0.800000011920929f;
    s = 0.0625f;
    s = 2.5f;
}
static const unsigned long fzgx_pool_table16[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const unsigned long *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = -3.0f;
}
static const unsigned long fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const unsigned long *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.01;
    s = 1.8600000143051147f;
}
static const unsigned long fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const unsigned long *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 210.0;
    d = 0.02;
    d = 0.003;
    d = -0.699999988079071;
    d = -0.029999999329447746;
    d = 0.141;
    d = 0.699999988079071;
    d = 1.0;
    d = 0.3;
}
#pragma section code_type ".text"

typedef struct {
    u8 pad_00[0x10];
    s32 unk_10;
    u8 pad_14[0x4];
    s16 unk_18;
    u8 pad_1a[0xE];
    f32 unk_28;
    u8 pad_2c[0x10];
    u8 unk_3c[0x58];
    u8 unk_94[0x20];
    f32 unk_b4;
} fn_1_60C88_EffectObject;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} fn_1_60C88_Vec;

extern void fn_1_862D4(s16 value, void *result);
extern void fn_1_8636C(s16 value, void *arg);
extern void *lbl_801A6D00;
extern void lbl_8006E1B0(void *src, void *dst);

/* Write the translation column of the locked-cache matrix. */
static inline void fn_1_60C88_set_translation(f32 x, f32 y, f32 z) {
    *(f32 *)(0xE0000000 + 0x0C) = x;
    *(f32 *)(0xE0000000 + 0x1C) = y;
    *(f32 *)(0xE0000000 + 0x2C) = z;
}

#pragma opt_propagation off
void fn_1_60C88(fn_1_60C88_EffectObject *obj) {
    fn_1_60C88_Vec pos;

    fn_1_862D4(obj->unk_18, &pos);
    fn_1_8636C(obj->unk_18, lbl_801A6D00);
    {
        {
            f32 fzgx_lc0_z;
            f32 fzgx_lc0_y;
            f32 fzgx_lc0_x;
            fzgx_lc0_x = (pos.x);
            fzgx_lc0_y = (pos.y);
            fzgx_lc0_z = (pos.z);
            *(f32 *)(0xE0000000 + 0x0C) = fzgx_lc0_x;
            *(f32 *)(0xE0000000 + 0x1C) = fzgx_lc0_y;
            *(f32 *)(0xE0000000 + 0x2C) = fzgx_lc0_z;
        }
    }
    lbl_8006E1B0(obj->unk_94, obj->unk_3c);
    obj->unk_b4 = 0.5f * (f32)obj->unk_10;
    if (obj->unk_28 > 0.0f) {
        obj->unk_28 -= 0.3;
    }
}
#pragma opt_propagation reset
/* fzgx:end fn_1_60C88 */

/* fzgx:begin fn_1_60F7C */
// fn_1_60F7C: empty in retail (single blr).
void fn_1_60F7C(void) {
}
/* fzgx:end fn_1_60F7C */

/* fzgx:begin fn_1_60F80 */
// fn_1_60F80: empty in retail (single blr).
void fn_1_60F80(void) {
}
/* fzgx:end fn_1_60F80 */

/* fzgx:begin fn_1_60F84 */
/* Shared literal pool primer: lays out lbl_1_rodata_2950 in retail order so the
   function's own literals dedupe onto retail's offsets (0xcc, 0x118, 0x38, 0x28, 0x1a0). */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 150.0;
    d = 10.0;
    d = 3.0;
}
static const u32 fzgx_pool_table6[2] = {0x00000000, 0x3DCCCCCD};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -2.4000000953674316f;
    s = 5.0f;
    d = 1.2;
    d = 0.1;
    s = 10.0f;
    s = 18.0f;
    d = 0.7;
    d = 50.0;
}
static const u32 fzgx_pool_table8[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 19.0f;
    d = 24.0;
    s = 0.7071067690849304f;
}
static const u32 fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 255.0;
    d = 0.9;
    s = 0.004000000189989805f;
    s = 0.0010000000474974513f;
    s = 0.009999999776482582f;
}
static const u32 fzgx_pool_table12[1] = {0xB4000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 240.0f;
    s = 100.0f;
    s = 300.0f;
    s = 200.0f;
    s = 10000.0f;
    s = 5000.0f;
    s = 204.0f;
    s = 85.0f;
    s = -0.05000000074505806f;
}
#pragma section code_type ".text"

typedef struct fn_1_60F84_Effect {
    u8 pad0[0x10];
    s32 age;
    u8 pad14[8];
    f32 color_1c;
    f32 color_20;
    f32 color_24;
    f32 size;
    f32 target_size;
    u8 pad30[0xC];
    f32 pos_x;
    f32 pos_y;
    f32 pos_z;
    f32 vel_x;
    f32 vel_y;
    f32 vel_z;
} fn_1_60F84_Effect;

void fn_1_60F84(fn_1_60F84_Effect *obj)
{
    f32 t;
    f64 d;
    f32 k = 0.96f;

    obj->vel_x = obj->vel_x * k;
    obj->vel_y = obj->vel_y * k;
    obj->vel_z = obj->vel_z * k;
    obj->pos_x = obj->pos_x + obj->vel_x;
    obj->pos_y = obj->pos_y + obj->vel_y;
    obj->pos_z = obj->pos_z + obj->vel_z;
    /* held in a double so the product and sum stay separate (fmul; fadd; frsp) */
    d = 0.1 * (obj->target_size - obj->size);
    obj->size = obj->size + d;

    if (obj->age < 20) {
        t = 1.0f + (f32)(-0.05f * (f32)obj->age);
        /* the common factor is CSE'd by the compiler; a named local would
           coalesce it with the chain and move the color load's register */
        obj->color_1c = obj->color_1c * (1.0f - t);
        obj->color_20 = obj->color_20 * (1.0f - t);
        obj->color_24 = obj->color_24 * (1.0f - t);
    }
}
/* fzgx:end fn_1_60F84 */

/* fzgx:begin fn_1_61070 noprologue */
#include "types.h"
#include "psvec.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/effect.h"

/* Current matrix window in the Gekko locked cache. */
#define LC_BASE 0xE0000000

typedef struct Fn161070 {
    u8 pad00[0x1c];
    f32 field1c;
    f32 field20;
    f32 field24;
    f32 field28;
    u8 pad2c[0x8];
    int field34;
    u8 pad38[0x4];
    u8 field3c[0x1c];
    s16 field58;
} Fn161070;

typedef struct Vec {
    f32 x;
    f32 y;
    f32 z;
} Vec;

typedef struct Mat44 {
    f32 m[3][4];
} Mat44;

typedef struct EfxData {
    f32 field0;
    f32 field4;
    u8 mtx[0x34];
    u8 color[4];
} EfxData;

extern const f32 lbl_1_rodata_2950[200];
extern void lbl_8006D9D8(void *);
extern void lbl_8006D7B0(void);
extern void mathutil_mtxA_rotate_z(s16);
extern f32 lbl_8006D0B4(f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006D848(f32);
extern void lbl_8006DFC4(void *);
extern void fn_1_9F914(void *, int);
extern u8 *memset(u8 *, int, u32);

#pragma opt_loop_invariants off
#pragma opt_propagation off
static inline f32 fn_1_61070_read_pointer(Vec * owner) { return owner->y; }
static inline f32 fn_1_61070_read_pointer_(Vec * owner) { return owner->z; }
#pragma opt_lifetimes off
void fn_1_61070(Fn161070 *self) {
    EfxData data;
    Mat44 matrix;
    Vec vector;
    const f32 *pool = lbl_1_rodata_2950;
    int id = self->field34;
    f32 radius = self->field28;
    f32 distance;
    f32 scale;
    f32 x;
    void * lab_t0;
    void * lab_t0__2;
    void * lab_t0_;
    const Mat44 * src;
    void * lab_t0__;

    lbl_8006D9D8((u8 *)self + 0x3c);
    lbl_8006D7B0();
    mathutil_mtxA_rotate_z(self->field58);

    {
        src = (const Mat44 *)LC_BASE;
        psvec_set(&vector.x, src->m[2][3], src->m[1][3], src->m[0][3]);
    }
    x = vector.x * vector.x;
    x += fn_1_61070_read_pointer(&vector) * fn_1_61070_read_pointer(&vector);
    x += fn_1_61070_read_pointer_(&vector) * vector.z;
    distance = lbl_8006D0B4(x);

    if (distance > pool[1] + radius) {
        lab_t0 = &matrix;
        lab_t0_ = lab_t0;
        lab_t0__ = lab_t0_;
        lbl_8006DB74(lab_t0__);
        lbl_8006D848((distance - radius) / distance);
        lbl_8006DFC4(&matrix);
    }

{
    u32 lab_t2;
    lab_t2 = 0x40;
    memset((u8 *)&data, 0, lab_t2);
}
    lab_t0 = data.mtx;
    lab_t0__2 = lab_t0;
    lab_t0__ = lab_t0__2;
    lbl_8006DB74(lab_t0__);
    scale = pool[0x54] * self->field28;
    data.field0 = scale;
    data.color[0] = (u8)(pool[0x17] * self->field1c);
    data.color[1] = (u8)(pool[0x17] * self->field20);
    data.color[2] = (u8)(pool[0x17] * self->field24);
    data.color[3] = 0xff;
    data.field4 = scale;
    fn_1_9F914(&data, id);
}
#pragma opt_lifetimes reset

#pragma opt_propagation reset

#pragma opt_loop_invariants reset
/* fzgx:end fn_1_61070 */

/* fzgx:begin fn_1_611EC */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
}
static const unsigned long fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
    s = 0.0f;
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const unsigned long fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 150.0;
    d = 10.0;
    d = 3.0;
}
static const unsigned long fzgx_pool_table6[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 5.0f;
    d = 1.2;
    d = 0.1;
    s = 10.0f;
    s = 18.0f;
    d = 0.7;
    d = 50.0;
}
static const unsigned long fzgx_pool_table8[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const unsigned long *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 19.0f;
    d = 24.0;
    s = 0.7071067690849304f;
}
static const unsigned long fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const unsigned long *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 255.0;
    d = 0.9;
    s = 0.004000000189989805f;
    s = 0.0010000000474974513f;
    s = 0.009999999776482582f;
    s = -1.1920928955078125e-07f;
    s = 240.0f;
    s = 100.0f;
    s = 300.0f;
    s = 200.0f;
    s = 10000.0f;
    s = 5000.0f;
    s = 204.0f;
    s = 85.0f;
    s = -0.05000000074505806f;
    s = 4.0f;
    s = -0.05999999865889549f;
    s = -0.5f;
    s = -1.0f;
}
static const unsigned long fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const unsigned long *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.2;
    s = 512.0f;
    s = 0.029999999329447746f;
    s = 51.0f;
    s = 88.0f;
    d = -3.0;
    s = 4.5f;
    s = 6.0f;
}
static const unsigned long fzgx_pool_table14[12] = {0x3F8CCCCD, 0x00000000, 0x3F666666, 0xBF8CCCCD, 0x00000000, 0x3F666666, 0x00000000, 0x00000000, 0xBF333333, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const unsigned long *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.2000000476837158f;
    s = 50.0f;
    s = 0.02500000037252903f;
    s = 0.800000011920929f;
    s = 0.0625f;
    s = 2.5f;
}
static const unsigned long fzgx_pool_table16[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const unsigned long *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = -3.0f;
}
static const unsigned long fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const unsigned long *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.01;
    s = 1.8600000143051147f;
}
static const unsigned long fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const unsigned long *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 210.0;
    d = 0.02;
    d = 0.003;
    d = -0.699999988079071;
    d = -0.029999999329447746;
    d = 0.141;
    d = 0.699999988079071;
    d = 1.0;
    d = 0.3;
    d = 0.800000011920929;
    d = 12.0;
}
#pragma section code_type ".text"
typedef struct {
    u8 pad0[0xe];
    s16 unk_0E;
    s32 unk_10;
    u8 pad14[0x14];
    f32 unk_28;
    u8 pad2C[0xC];
    s32 unk_38;
    u8 pad3C[0x18];
    s16 unk_54;
    s16 unk_56;
    s16 unk_58;
} EffObj611EC;


#define RND() (lbl_1_data_1D628 = lbl_1_data_1D628 * 0x41C64E6D + 0x3039, (lbl_1_data_1D628 >> 16) & 0x7FFF)

void fn_1_611EC(EffObj611EC *p)
{
    if (p->unk_10 == 0) {
        p->unk_10 = (s32)(12.0 + (f64)(12.0 * ((f32)RND() / 32767.0f)));
    }
    p->unk_0E = 0;
    if (p->unk_28 == 0.0f) {
        p->unk_28 = (f32)(1.0 + (f32)RND() / 32767.0f);
    }
    p->unk_54 = RND();
    p->unk_56 = RND();
    p->unk_58 = RND();
    p->unk_38 = fn_1_45D0((*((u32 *)&lbl_801A6410)), 0xF0, lbl_1_data_1D62C, 0x1573);
}
/* fzgx:end fn_1_611EC */

/* fzgx:begin fn_1_61640 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 150.0;
    d = 10.0;
    d = 3.0;
}
static const u32 fzgx_pool_table6[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 5.0f;
    d = 1.2;
    d = 0.1;
    s = 10.0f;
    s = 18.0f;
    d = 0.7;
    d = 50.0;
}
static const u32 fzgx_pool_table8[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 19.0f;
    d = 24.0;
    s = 0.7071067690849304f;
}
static const u32 fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 255.0;
    d = 0.9;
    s = 0.004000000189989805f;
    s = 0.0010000000474974513f;
    s = 0.009999999776482582f;
    s = -1.1920928955078125e-07f;
    s = 240.0f;
    s = 100.0f;
    s = 300.0f;
    s = 200.0f;
    s = 10000.0f;
    s = 5000.0f;
    s = 204.0f;
    s = 85.0f;
    s = -0.05000000074505806f;
    s = 4.0f;
    s = -0.05999999865889549f;
    s = -0.5f;
    s = -1.0f;
}
static const u32 fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.2;
    s = 512.0f;
    s = 0.029999999329447746f;
    s = 51.0f;
    s = 88.0f;
    d = -3.0;
    s = 4.5f;
    s = 6.0f;
}
static const u32 fzgx_pool_table14[12] = {0x3F8CCCCD, 0x00000000, 0x3F666666, 0xBF8CCCCD, 0x00000000, 0x3F666666, 0x00000000, 0x00000000, 0xBF333333, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.2000000476837158f;
    s = 50.0f;
    s = 0.02500000037252903f;
    s = 0.800000011920929f;
    s = 0.0625f;
    s = 2.5f;
}
static const u32 fzgx_pool_table16[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -3.0f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.01;
    s = 1.8600000143051147f;
}
static const u32 fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 210.0;
    d = 0.02;
    d = 0.003;
    d = -0.699999988079071;
    d = -0.029999999329447746;
    d = 0.141;
    d = 0.699999988079071;
    d = 1.0;
}
#pragma section code_type ".text"


struct Fn1_61640Pool {
    u8 _pad00[0x28];
    f32 initial;
    u8 _pad2c[0xc];
    f64 int_bias;
    u8 _pad40[0x4c];
    f32 scale;
    u8 _pad90[0x200];
    f64 threshold;
};

struct Fn1_61640Object {
    u8 _pad10[0x10];
    s32 field_10;
    u8 _pad14[0x4];
    s16 field_18;
    u8 _pad1a[0xe];
    f32 field_28;
    u8 _pad2c[0x8];
    void *field_34;
    u8 _pad38[0x4];
    f32 field_3c[3];
    u8 _pad48[0xc];
    s16 field_54;
    s16 field_56;
    s16 field_58;
};

#pragma opt_propagation off
void fn_1_61640(struct Fn1_61640Object *object) {
    const struct Fn1_61640Pool *pool = (const struct Fn1_61640Pool *)&lbl_1_rodata_2950;
    f32 value = (1.0f);
    f32 output[3];
    f32 temp[3];
    f32 pz, py, px;

    fn_1_862D4(object->field_18, output);
    fn_1_8636C(object->field_18, lbl_801A6D00);

    px = ((0)[output]);
    py = ((1)[output]);
    pz = ((2)[output]);

    *(f32 *)(0xE0000000 + 0x0c) = px;
    *(f32 *)(0xE0000000 + 0x1c) = py;
    *(f32 *)(0xE0000000 + 0x2c) = pz;

    lbl_8006E1B0( (Fn183D28Vec3 *)(void *)(object->field_3c), (Fn183D28Vec3 *)(void *)(temp));
    lbl_8006D9D8(temp);
    mathutil_mtxA_rotate_y(object->field_56);
    mathutil_mtxA_rotate_x(object->field_54);
    mathutil_mtxA_rotate_z(object->field_58);
    lbl_8006E14C(object->field_28);
    fn_1_55FC4(object->field_28);

    if (object->field_10 < 12) {
        value *= (0.0833333358f) * (f32)object->field_10;
    }
    if (value < (1.0)) {
        fn_1_55FF0(value);
        fn_1_5557C(object->field_34);
    } else {
        fn_1_555D0(object->field_34);
    }
}
#pragma opt_propagation reset
/* fzgx:end fn_1_61640 */

/* fzgx:begin fn_1_61760 */
struct Fn1_61760Object {
    u8 _pad38[0x38];
    void *effect_resource;
};

// Dispatches the object's effect resource when one is available.
void fn_1_61760(struct Fn1_61760Object *object) {
    if (object->effect_resource != 0) {
        fn_1_46B4((u32)lbl_801A6410, (u32)(void *)(object->effect_resource), (const char *)(u8 *)(lbl_1_data_1D62C), 0x16c1);
    }
}
/* fzgx:end fn_1_61760 */

/* fzgx:begin fn_1_617A4 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 150.0;
    d = 10.0;
    d = 3.0;
}
static const u32 fzgx_pool_table6[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 5.0f;
    d = 1.2;
    d = 0.1;
    s = 10.0f;
    s = 18.0f;
    d = 0.7;
    d = 50.0;
}
static const u32 fzgx_pool_table8[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 19.0f;
    d = 24.0;
    s = 0.7071067690849304f;
}
static const u32 fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 255.0;
    d = 0.9;
    s = 0.004000000189989805f;
    s = 0.0010000000474974513f;
    s = 0.009999999776482582f;
    s = -1.1920928955078125e-07f;
    s = 240.0f;
    s = 100.0f;
    s = 300.0f;
    s = 200.0f;
    s = 10000.0f;
    s = 5000.0f;
    s = 204.0f;
    s = 85.0f;
    s = -0.05000000074505806f;
    s = 4.0f;
    s = -0.05999999865889549f;
    s = -0.5f;
    s = -1.0f;
}
static const u32 fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.2;
    s = 512.0f;
    s = 0.029999999329447746f;
    s = 51.0f;
    s = 88.0f;
    d = -3.0;
    s = 4.5f;
    s = 6.0f;
}
static const u32 fzgx_pool_table14[12] = {0x3F8CCCCD, 0x00000000, 0x3F666666, 0xBF8CCCCD, 0x00000000, 0x3F666666, 0x00000000, 0x00000000, 0xBF333333, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.2000000476837158f;
    s = 50.0f;
    s = 0.02500000037252903f;
    s = 0.800000011920929f;
    s = 0.0625f;
    s = 2.5f;
}
static const u32 fzgx_pool_table16[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -3.0f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.01;
    s = 1.8600000143051147f;
}
static const u32 fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 210.0;
    d = 0.02;
    d = 0.003;
    d = -0.699999988079071;
    d = -0.029999999329447746;
    d = 0.141;
    d = 0.699999988079071;
    d = 1.0;
    d = 0.3;
    d = 0.800000011920929;
    d = 12.0;
    s = -0.8999999761581421f;
    s = 0.07000000029802322f;
}
#pragma section code_type ".text"


struct Fn1_617A4Object {
    u8 _pad10[0x10];
    s32 unk_10;
    u8 _pad14[0x80];
    f32 unk_94;
    f32 unk_98;
};

void fn_1_617A4(struct Fn1_617A4Object *object) {
    const f32 *pool;
    f32 t;

    pool = (((const f32 *)&lbl_1_rodata_2950));

    if (object->unk_10 == 0) {
        lbl_1_data_1D628 = lbl_1_data_1D628 * 0x41c64e6d + 0x3039;
        object->unk_10 = (s32)((60.0f) *
            ((0.100000001f) + (f32)(u32)((lbl_1_data_1D628 >> 16) & 0x7fff) / (32767.0f)));
    }

    lbl_1_data_1D628 = lbl_1_data_1D628 * 0x41c64e6d + 0x3039;
    t = (0.0299999993f) * ((f32)(u32)((lbl_1_data_1D628 >> 16) & 0x7fff) / (32767.0f));
    object->unk_94 = (0.0700000003f) + t;

    lbl_1_data_1D628 = lbl_1_data_1D628 * 0x41c64e6d + 0x3039;
    t = (0.100000001f) * ((f32)(u32)((lbl_1_data_1D628 >> 16) & 0x7fff) / (32767.0f));
    object->unk_98 = (0.0700000003f) + t;
}
/* fzgx:end fn_1_617A4 */

/* fzgx:begin fn_1_618B8 noprologue */
#include "dolphin/types.h"

/* Volatile sink preserves literal first-use order in the discarded pool primer. */
extern volatile f32 __fzgx_pool_f;
/* Volatile sink preserves double literal first-use order in the pool primer. */
extern volatile f64 __fzgx_pool_d;

#pragma section code_type ".fzgxpool"
void fzgx_pool_primer(void)
{
    __fzgx_pool_f = 60.0f;
    __fzgx_pool_f = 0.1f;
    __fzgx_pool_f = 32767.0f;
    __fzgx_pool_f = 0.05f;
    __fzgx_pool_d = 0.07;
    __fzgx_pool_f = 20000.0f;
    __fzgx_pool_d = 4503599627370496.0;
    __fzgx_pool_f = 1.0f;
    __fzgx_pool_f = -0.03f;
    __fzgx_pool_d = 15.0;
    __fzgx_pool_d = 4503601774854144.0;
    __fzgx_pool_d = 1.5;
    __fzgx_pool_d = 0.5;
    __fzgx_pool_f = 0.0f;
    __fzgx_pool_f = 0.5f;
    __fzgx_pool_f = 8.0f;
    __fzgx_pool_f = 255.0f;
    __fzgx_pool_f = 15.0f;
    __fzgx_pool_f = 0.2f;
    __fzgx_pool_f = 0.08f;
    __fzgx_pool_f = 0.25f;
    __fzgx_pool_f = 0.98f;
    __fzgx_pool_f = 0.99f;
    __fzgx_pool_f = 40.0f;
    __fzgx_pool_f = 20.0f;
    __fzgx_pool_f = 1.5f;
    __fzgx_pool_f = 0.45f;
    __fzgx_pool_f = -2.0f;
    __fzgx_pool_f = 0.083333336f;
    __fzgx_pool_f = 0.15f;
    __fzgx_pool_f = 0.125f;
    __fzgx_pool_f = -0.4f;
    __fzgx_pool_f = -0.3f;
    __fzgx_pool_f = 2.0f;
    __fzgx_pool_f = 250.0f;
    __fzgx_pool_d = 0.6;
    __fzgx_pool_d = 0.4;
    __fzgx_pool_f = 0.3f;
    __fzgx_pool_f = -0.004f;
}
#pragma section code_type ".text"

typedef struct {
    u8 pad00[0x10];
    s32 age;
    u8 pad14[8];
    f32 xScale;
    f32 yScale;
    f32 zScale;
    f32 value;
    f32 targetValue;
    u8 pad30[0xC];
    f32 x;
    f32 y;
    f32 z;
    f32 vx;
    f32 vy;
    f32 vz;
    u8 pad54[0x40];
    f32 damping;
    f32 targetDamping;
} Particle;

void fn_1_618B8(Particle *p)
{
    f32 drag;
    register f32 factor;
    drag = 1.0f - p->damping;
    p->vy += -0.004f;
    p->vx *= drag;
    p->vy *= drag;
    p->vz *= drag;
    p->x += p->vx;
    p->y += p->vy;
    p->z += p->vz;
    p->damping += (f32)(0.05f * (p->targetDamping - p->damping));
    p->value += (f32)(0.2f * (p->targetValue - p->value));
    if (p->age < 15.0) {
        /* Keep the first scale load independent of the conversion. */
        f32 scale = *(volatile f32 *)&p->xScale;
        factor = 1.0f - 1.0f / (p->age + 1);
        p->xScale = scale * factor;
        p->yScale *= factor;
        p->zScale *= factor;
    }
}
/* fzgx:end fn_1_618B8 */

/* fzgx:begin fn_1_619E4 noprologue */
#include "types.h"
#include "game/vec3.h"

struct fn_1_619E4_pool {
    u8 pad_0[0x28];
    f32 one;        /* 0x28 */
    u8 pad_2C[0x24];
    f32 zero;       /* 0x50 */
    f32 half;       /* 0x54 */
    u8 pad_58[0x4];
    f32 c255;       /* 0x5C */
    u8 pad_60[0x40];
    f32 two;        /* 0xA0 */
    u8 pad_A4[0x214];
    f32 widthScale; /* 0x2B8 */
};

typedef struct fn_1_619E4_Obj {
    u8 pad_0[0x1C];
    f32 red;     /* 0x1C */
    f32 green;   /* 0x20 */
    f32 blue;    /* 0x24 */
    f32 radius;  /* 0x28 */
    u8 pad_2C[0x8];
    void *model; /* 0x34 */
    u8 pad_38[0x4];
    Vec3 end;    /* 0x3C */
    u8 pad_48[0x18];
    Vec3 start;  /* 0x60 */
} fn_1_619E4_Obj;

typedef struct fn_1_619E4_DrawParam {
    f32 scale;
    f32 unk4;
    f32 mtx[3][4];
    f32 unk38;
    u8 r, g, b, a;
} fn_1_619E4_DrawParam;

extern struct fn_1_619E4_pool lbl_1_rodata_2950;
extern void *lbl_801A66CC;
extern s32 fn_1_54E34(void *, f32);
extern int fn_1_9F914(const void *, const void *);
extern void *memset(void *, int, u32);
extern void lbl_8006DBAC(void *);
extern void lbl_8006E1B0(Vec3 *, Vec3 *);
extern void lbl_8006DCA4(void);
extern void lbl_8006E0A4(Vec3 *);
extern void lbl_8006D7B0(void);
extern void lbl_8006D668(Vec3 *);
extern f32 lbl_8006D0B4(f32);
extern void fn_8006EDBC(Vec3 *, Vec3 *, s16 *, s16 *);
extern void lbl_8006D7DC(Vec3 *);
extern void mathutil_mtxA_rotate_y(s32);
extern void mathutil_mtxA_rotate_x(s32);
extern void lbl_8006E15C(f32, f32, f32);
extern void fn_8006E294(Vec3 *);
extern s32 lbl_8006D24C(f32, f32);
extern void lbl_8006DB74(void *);

#pragma opt_common_subs off
void fn_1_619E4(fn_1_619E4_Obj *obj) {
    struct fn_1_619E4_pool *pool;
    void *model;
    f32 size;
    f32 radius;
    f32 len;
    f32 s;
    f32 dx, dz, dy;
    f32 ox, oy;
    fn_1_619E4_DrawParam param;
    Vec3 end;
    Vec3 start;
    Vec3 mid;
    Vec3 dir;
    s16 rotX;
    s16 rotY;

    model = obj->model;
    pool = &lbl_1_rodata_2950;
    memset(&param, 0, sizeof(param));
    radius = obj->radius;
    lbl_8006DBAC(lbl_801A66CC);
    lbl_8006E1B0(&obj->start, &start);
    lbl_8006DCA4();
    if (fn_1_54E34(&obj->end, obj->radius)) {
        lbl_8006E1B0(&obj->end, &end);
        if (end.z < pool->zero && start.z < pool->zero) {
            dx = end.x - start.x;
            dy = end.y - start.y;
            size = obj->radius;
            dir.x = dx;
            dir.y = dy;
            if (pool->zero == dx && pool->zero == dy) {
                lbl_8006E0A4(&obj->end);
                lbl_8006D7B0();
            } else {
                dir.z = pool->zero;
                lbl_8006D668(&dir);
                s = radius * pool->widthScale;
                ox = dir.x * s;
                oy = dir.y * s;
                end.x = end.x + ox;
                end.y = end.y + oy;
                start.x = start.x - ox;
                start.y = start.y - oy;
                mid.x = pool->half * (end.x + start.x);
                mid.y = pool->half * (end.y + start.y);
                mid.z = pool->half * (end.z + start.z);
                dx = end.x - start.x;
                oy = end.y - start.y;
                ox = end.z - start.z;
                len = dx * dx;
                len = oy * oy + len;
                len = ox * ox + len;
                len = lbl_8006D0B4(len);
                fn_8006EDBC(&end, &start, &rotX, &rotY);
                lbl_8006D7DC(&mid);
                mathutil_mtxA_rotate_y(rotY);
                mathutil_mtxA_rotate_x(rotX);
                lbl_8006E15C(pool->one, pool->one, len / radius);
                mathutil_mtxA_rotate_x(0x4000);
                fn_8006E294(&dir);
                mathutil_mtxA_rotate_y(lbl_8006D24C(dir.x, dir.z));
            }
            lbl_8006DB74(param.mtx);
            param.scale = pool->two * size;
            param.r = pool->c255 * obj->red;
            param.g = pool->c255 * obj->green;
            param.b = pool->c255 * obj->blue;
            param.a = 0xFF;
            fn_1_9F914(&param, model);
        }
    }
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_619E4 */

/* fzgx:begin fn_1_61C84 */
// fn_1_61C84: empty in retail (single blr).
void fn_1_61C84(void) {
}
/* fzgx:end fn_1_61C84 */

/* fzgx:begin fn_1_61C88 */
void fn_1_61C88(void) {
    fn_1_61D08();
}
/* fzgx:end fn_1_61C88 */

/* fzgx:begin fn_1_61CA8 */
void fn_1_61CA8(void) {
    fn_1_61EF4();
}
/* fzgx:end fn_1_61CA8 */

/* fzgx:begin fn_1_61CC8 */
void fn_1_61CC8(void) {
    fn_1_620C4();
}
/* fzgx:end fn_1_61CC8 */

/* fzgx:begin fn_1_61CE8 */
void fn_1_61CE8(void) {
    fn_1_61E60();
}
/* fzgx:end fn_1_61CE8 */

/* fzgx:begin fn_1_61D08 */
typedef struct {
    u8 pad_0[0x20];
    void *unk_20;
} EffectChild;

typedef struct {
    u8 pad_0[0x130];
    u32 unk_130;
} EffectInner;

#pragma opt_common_subs off
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 150.0;
    d = 10.0;
    d = 3.0;
}
static const u32 fzgx_pool_table6[2] = {0x00000000, 0x3DCCCCCD};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -2.4000000953674316f;
    s = 5.0f;
    d = 1.2;
    d = 0.1;
    s = 10.0f;
    s = 18.0f;
    d = 0.7;
    d = 50.0;
}
static const u32 fzgx_pool_table8[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 19.0f;
    d = 24.0;
    s = 0.7071067690849304f;
}
static const u32 fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 255.0;
    d = 0.9;
    s = 0.004000000189989805f;
    s = 0.0010000000474974513f;
    s = 0.009999999776482582f;
}
static const u32 fzgx_pool_table12[1] = {0xB4000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 240.0f;
    s = 100.0f;
    s = 300.0f;
    s = 200.0f;
    s = 10000.0f;
    s = 5000.0f;
    s = 204.0f;
    s = 85.0f;
    s = -0.05000000074505806f;
    s = 4.0f;
    s = -0.05999999865889549f;
    s = -0.5f;
    s = -1.0f;
}
static const u32 fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.2;
    s = 512.0f;
    s = 0.029999999329447746f;
    s = 51.0f;
    s = 88.0f;
    d = -3.0;
    s = 4.5f;
    s = 6.0f;
    s = 1.100000023841858f;
}
static const u32 fzgx_pool_table16[2] = {0x00000000, 0x3F666666};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -1.100000023841858f;
}
static const u32 fzgx_pool_table18[4] = {0x00000000, 0x3F666666, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.699999988079071f;
}
static const u32 fzgx_pool_table20[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.2000000476837158f;
    s = 50.0f;
    s = 0.02500000037252903f;
    s = 0.800000011920929f;
    s = 0.0625f;
    s = 2.5f;
}
static const u32 fzgx_pool_table22[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -3.0f;
}
static const u32 fzgx_pool_table24[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const u32 *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.01;
    s = 1.8600000143051147f;
}
static const u32 fzgx_pool_table26[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep26(void) { const u32 *volatile cp; cp = fzgx_pool_table26; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime27(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 210.0;
    d = 0.02;
    d = 0.003;
    d = -0.699999988079071;
    d = -0.029999999329447746;
    d = 0.141;
    d = 0.699999988079071;
    d = 1.0;
    d = 0.3;
    d = 0.800000011920929;
    d = 12.0;
    s = -0.8999999761581421f;
    s = 0.07000000029802322f;
    s = 0.6000000238418579f;
    s = 30.0f;
}
#pragma section code_type ".text"
int fn_1_61D08(obj)
fn_1_61D08_EffectObject *obj;
{
    u8 *data;
    EffectChild *child;
    u32 size;
    u32 random;
    f32 initial;
    f32 value;

    data = (u8 *)(((u8 *)&lbl_1_data_1C698));
    obj->unk_38 = (void *)fn_1_45D0(lbl_801A6410, 0x24, data + 0xf94, 0x17a6);
    child = (EffectChild *)obj->unk_38;
    size = GXGetTexBufferSize(0x14, 0xe, 0, 0, 0);
    child->unk_20 = (void *)fn_1_45D0(lbl_801A6410, size, data + 0xf94, 0x17ab);

    initial = 30.0f;
    *(f32 *)(data + 0x120c) = initial;
    obj->unk_10 = (s32)initial;
    obj->unk_b4 = 0.3f;

    random = ((0x41c64e6d) * (*(u32 *)(data + 0xf90))) + 0x3039;
    *(u32 *)(data + 0xf90) = random;
    obj->unk_54 = (u16)((random >> 16) & 0x7fff);

    random = ((0x41c64e6d) * (*(u32 *)(data + 0xf90))) + 0x3039;
    *(u32 *)(data + 0xf90) = random;
    value = (f32)((random >> 16) & 0x7fff);
    obj->unk_5a = (s16)(4096.0f * (value / 32767.0f - 0.5f));

    obj->unk_34 = ((EffectInner *)(u8 *)lbl_1_bss_38458->unk_8)->unk_130;
    return 1;
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_61D08 */

/* fzgx:begin fn_1_61E60 */
// Releases the effect resources and clears the active effect references.
int fn_1_61E60(object)
Fn1_61E60Object *object;
{
    Fn1_61E60Node *node = object->unk_38;

    if (node != 0) {
        fn_1_4730( (u32)(void *)(lbl_801A6410), (u32)(void *)(node->unk_20), 1, (const char *)(u8 *)(lbl_1_data_1D62C), 0x17D5);
        node->unk_20 = 0;
        fn_1_46B4((u32)lbl_801A6410, (u32)(void *)(object->unk_38), (const char *)(u8 *)(lbl_1_data_1D62C), 0x17D8);
        object->unk_38 = 0;
    }

    return 1;
}
/* fzgx:end fn_1_61E60 */

/* fzgx:begin fn_1_61EF4 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const unsigned long fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const unsigned long fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 150.0;
    d = 10.0;
    d = 3.0;
}
static const unsigned long fzgx_pool_table6[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 5.0f;
    d = 1.2;
    d = 0.1;
    s = 10.0f;
    s = 18.0f;
    d = 0.7;
    d = 50.0;
}
static const unsigned long fzgx_pool_table8[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const unsigned long *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 19.0f;
    d = 24.0;
    s = 0.7071067690849304f;
}
static const unsigned long fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const unsigned long *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 255.0;
    d = 0.9;
    s = 0.004000000189989805f;
    s = 0.0010000000474974513f;
    s = 0.009999999776482582f;
    s = -1.1920928955078125e-07f;
    s = 240.0f;
    s = 100.0f;
    s = 300.0f;
    s = 200.0f;
    s = 10000.0f;
    s = 5000.0f;
    s = 204.0f;
    s = 85.0f;
    s = -0.05000000074505806f;
    s = 4.0f;
    s = -0.05999999865889549f;
    s = -0.5f;
    s = -1.0f;
}
static const unsigned long fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const unsigned long *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.2;
    s = 512.0f;
    s = 0.029999999329447746f;
    s = 51.0f;
    s = 88.0f;
    d = -3.0;
    s = 4.5f;
    s = 6.0f;
}
static const unsigned long fzgx_pool_table14[12] = {0x3F8CCCCD, 0x00000000, 0x3F666666, 0xBF8CCCCD, 0x00000000, 0x3F666666, 0x00000000, 0x00000000, 0xBF333333, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const unsigned long *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.2000000476837158f;
    s = 50.0f;
    s = 0.02500000037252903f;
    s = 0.800000011920929f;
    s = 0.0625f;
    s = 2.5f;
}
static const unsigned long fzgx_pool_table16[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const unsigned long *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = -3.0f;
}
static const unsigned long fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const unsigned long *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.01;
    s = 1.8600000143051147f;
}
static const unsigned long fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const unsigned long *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 210.0;
    d = 0.02;
    d = 0.003;
    d = -0.699999988079071;
    d = -0.029999999329447746;
    d = 0.141;
    d = 0.699999988079071;
    d = 1.0;
    d = 0.3;
    d = 0.800000011920929;
    d = 12.0;
    s = -0.8999999761581421f;
    s = 0.07000000029802322f;
    s = 0.6000000238418579f;
    s = 30.0f;
    s = 1.059999942779541f;
    s = 28.0f;
}
#pragma section code_type ".text"


#pragma opt_propagation off
int fn_1_61EF4(self)
Obj *self;
{
    f32 b[13];
    f32 a[3];
    s32 c;

    c = ++lbl_1_bss_6C864;
    if (c > 1) {
        self->b0 = 3;
    }
    fn_1_862D4(self->id18, a);
    fn_1_8636C(self->id18, b);
    lbl_8006DC6C(b);
    {
        f32 fzgx_lc0_z;
        f32 fzgx_lc0_y;
        f32 fzgx_lc0_x;
        fzgx_lc0_x = a[0];
        fzgx_lc0_y = a[1];
        fzgx_lc0_z = a[2];
        *(f32 *)(0xE0000000 + 0x0C) = fzgx_lc0_x;
        *(f32 *)(0xE0000000 + 0x1C) = fzgx_lc0_y;
        *(f32 *)(0xE0000000 + 0x2C) = fzgx_lc0_z;
    }
    self->f48 *= 0.98f;
    self->f4c *= 0.98f;
    self->p94[0] += self->f48;
    self->p94[1] += self->f4c;
    self->p94[2] += self->f50;
    lbl_8006E1B0( (Fn183D28Vec3 *)(void *)(self->p94), (Fn183D28Vec3 *)(void *)(self->m3c));
    lbl_8006DBAC((u8 *)self + 0xb8);
    lbl_8006DA50();
    lbl_8006DF44();
    lbl_8006E1B0( (Fn183D28Vec3 *)(void *)(self->m3c), (Fn183D28Vec3 *)(void *)(self->m3c));
    self->s5a = 0.98f * (f32)self->s5a;
    self->s54 += self->s5a;
    self->f2c *= 1.06f;
    self->f28 += self->f2c;
    if (self->n10 > 15) {
        self->fb4 = self->fb4 + (f32)(0.1f * (1.0f - self->fb4));
    } else {
        self->fb4 = self->fb4 * (1.0f - 1.0f / (f32)(self->n10 + 1));
    }
    return 1;
}
#pragma opt_propagation reset
/* fzgx:end fn_1_61EF4 */

/* fzgx:begin fn_1_620C4 */
// fn_1_620C4: empty in retail (single blr).
void fn_1_620C4(void) {
}
/* fzgx:end fn_1_620C4 */

/* fzgx:begin fn_1_620C8 noprologue */
#include "types.h"
#include "game/main_rel/car_test_types.h"

/* Shared literal pool primer: lays out lbl_1_rodata_2950 in retail order. */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
    s = 0.0f;
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 150.0;
    d = 10.0;
    d = 3.0;
}
static const u32 fzgx_pool_table6[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 5.0f;
    d = 1.2;
    d = 0.1;
    s = 10.0f;
    s = 18.0f;
    d = 0.7;
    d = 50.0;
}
static const u32 fzgx_pool_table8[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 19.0f;
    d = 24.0;
    s = 0.7071067690849304f;
}
static const u32 fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 255.0;
    d = 0.9;
    s = 0.004000000189989805f;
    s = 0.0010000000474974513f;
    s = 0.009999999776482582f;
    s = -1.1920928955078125e-07f;
    s = 240.0f;
    s = 100.0f;
    s = 300.0f;
    s = 200.0f;
    s = 10000.0f;
    s = 5000.0f;
    s = 204.0f;
    s = 85.0f;
    s = -0.05000000074505806f;
    s = 4.0f;
    s = -0.05999999865889549f;
    s = -0.5f;
    s = -1.0f;
}
static const u32 fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.2;
    s = 512.0f;
    s = 0.029999999329447746f;
    s = 51.0f;
    s = 88.0f;
    d = -3.0;
    s = 4.5f;
    s = 6.0f;
}
static const u32 fzgx_pool_table14[12] = {0x3F8CCCCD, 0x00000000, 0x3F666666, 0xBF8CCCCD, 0x00000000, 0x3F666666, 0x00000000, 0x00000000, 0xBF333333, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.2000000476837158f;
    s = 50.0f;
    s = 0.02500000037252903f;
    s = 0.800000011920929f;
    s = 0.0625f;
    s = 2.5f;
}
static const u32 fzgx_pool_table16[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -3.0f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.01;
    s = 1.8600000143051147f;
}
static const u32 fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 210.0;
    d = 0.02;
    d = 0.003;
    d = -0.699999988079071;
    d = -0.029999999329447746;
    d = 0.141;
    d = 0.699999988079071;
    d = 1.0;
    d = 0.3;
    d = 0.800000011920929;
    d = 12.0;
}
static const u32 fzgx_pool_table22[5] = {0xBF666666, 0x3D8F5C29, 0x3F19999A, 0x41F00000, 0x3F87AE14};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 28.0f;
}
#pragma section code_type ".text"

typedef struct Fn620C8TexObj {
    u32 dummy[8];
    void *image;
} Fn620C8TexObj;

typedef struct Fn620C8Model {
    u8 pad_0[0x8];
    u8 data[0xC];
    f32 scale;
} Fn620C8Model;

typedef struct Fn620C8Obj {
    u8 pad_0[0x28];
    f32 time;
    u8 pad_2C[0x8];
    Fn620C8Model *model;
    Fn620C8TexObj *tex;
    u8 rot[0x78];
    f32 brightness;
    Fn183D28Vec3 pos;
} Fn620C8Obj;

typedef struct Fn620C8Viewport {
    f32 x;
    f32 y;
    f32 w;
    f32 h;
    f32 near;
    f32 far;
} Fn620C8Viewport;

extern s32 fn_1_54E34(void *, f32);
extern void fn_1_56000(u8, u8, u8);
extern void fn_1_5621C(f32, f32, f32, f32);
extern void fn_1_556B8(void *);
extern void fn_80038F10(Fn620C8Viewport *);
extern void fn_80038EEC(f32, f32, f32, f32, f32, f32);
extern void fn_80074188(s32, s32, s32, s32);
extern void lbl_8006DFE8(Fn183D28Vec3 *);
extern void lbl_8006DA50(void);
extern void lbl_8006E0A4(void *);
extern void lbl_8006E14C(f32);
extern void mathutil_mtxA_rotate_x(s16);
extern void fn_80072558(void);
extern void fn_80074918(u8, s32, u8);
extern void fn_80074300(u16, u16, u16, u16);
extern void fn_80074438(u16, u16, u32, u32);
extern void fn_8003526C(void *, u8);
extern void GXInitTexObj(void *, void *, u16, u16, s32, s32, s32, u8);

void fn_1_620C8(Fn620C8Obj *obj) {
    s32 width;
    s32 height;
    s32 halfW;
    s32 halfH;
    Fn620C8TexObj *tex;
    Fn620C8Model *model;
    f32 brightness;
    Fn620C8Viewport vp;

    tex = obj->tex;
    fn_80038F10(&vp);
    width = (s32)(vp.w < 40.0f ? vp.w : 40.0f);
    height = (s32)(vp.h < 28.0f ? vp.h : 28.0f);
    halfW = width >> 1;
    halfH = height >> 1;
    fn_80038EEC(vp.x, vp.y, (f32)width, (f32)height, 0.0f, 1.0f);
    fn_80074188((s32)vp.x, (s32)vp.y, width, height);

    brightness = obj->brightness;
    model = obj->model;
    lbl_8006DFE8(&obj->pos);
    lbl_8006DA50();
    lbl_8006E0A4(obj->rot);
    lbl_8006E14C(obj->time / model->scale);
    mathutil_mtxA_rotate_x(-0x8000);
    if (fn_1_54E34(model->data, obj->time) != 0) {
        fn_1_56000(1, 3, 0);
        fn_1_5621C(brightness, brightness, brightness, 1.0f);
        fn_80072558();
        fn_1_556B8(model);
        fn_1_56000(1, 3, 1);
        fn_1_5621C(1.0f, 1.0f, 1.0f, 1.0f);
    }
    fn_80074918(1, 3, 1);
    fn_80074300((s32)vp.x, (s32)vp.y, width, height);
    fn_80074438(halfW, halfH, 0, 1);
    fn_8003526C(tex->image, 1);
    GXInitTexObj(tex, tex->image, halfW, halfH, 0, 0, 0, 0);
    fn_80038EEC(vp.x, vp.y, vp.w, vp.h, vp.near, vp.far);
    fn_80074188((s32)vp.x, (s32)vp.y, (s32)vp.w, (s32)vp.h);
}
/* fzgx:end fn_1_620C8 */

/* fzgx:begin fn_1_62794 noprologue */
#include "types.h"

typedef struct GXTexObj {
    u32 dummy[8];
} GXTexObj;

/* Shared literal pool primer: lays out lbl_1_rodata_2950 in retail order so the
   function's own literals dedupe onto retail's offsets (0x50, 0x54, 0x1ac). */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
    s = 0.0f;
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 150.0;
    d = 10.0;
    d = 3.0;
}
static const u32 fzgx_pool_table6[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 5.0f;
    d = 1.2;
    d = 0.1;
    s = 10.0f;
    s = 18.0f;
    d = 0.7;
    d = 50.0;
}
static const u32 fzgx_pool_table8[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 19.0f;
    d = 24.0;
    s = 0.7071067690849304f;
}
static const u32 fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 255.0;
    d = 0.9;
    s = 0.004000000189989805f;
    s = 0.0010000000474974513f;
    s = 0.009999999776482582f;
    s = -1.1920928955078125e-07f;
    s = 240.0f;
    s = 100.0f;
    s = 300.0f;
    s = 200.0f;
    s = 10000.0f;
    s = 5000.0f;
    s = 204.0f;
    s = 85.0f;
    s = -0.05000000074505806f;
    s = 4.0f;
    s = -0.05999999865889549f;
    s = -0.5f;
}
#pragma section code_type ".text"

extern void *lbl_801A63D0;
extern f32 *lbl_801A6D00;

extern void fn_80038F10(f32 *);
extern void fn_80074300(u16, u16, u16, u16);
extern void fn_80074438(u16, u16, u32, u32);
extern void fn_8003526C(void *, u8);
extern void GXInitTexObj(GXTexObj *, void *, u16, u16, s32, s32, s32, u8);
extern void fn_80072864(u32);
extern void fn_80038BFC(f32 *);
extern void lbl_8006DAEC(void);
extern void lbl_8006D758(void);
extern void lbl_8006DB74(void *);
extern void lbl_8006DB30(void);
extern void lbl_8006DFD8(void *);
extern void GXLoadTexMtxImm(f32 *, u32, u32);
extern void fn_80073A58(int, void *, s8);
extern void fn_80074788(u32);
extern void fn_800747D0(u32, u32, s32, s32, u32, s32, s32);
extern void fn_80073778(void *, s32);
extern void fn_800745A4(u32, s32, s32, u32, u32, u32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072D64(s32, s32, s32, s32, u8, s32);
extern void fn_80072CC4(s32, s32, s32, s32, s32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_80074918(u8, s32, u8);
extern void fn_800720B0(u32);
extern void fn_800728A8(s32, s32, s32, s32);
extern void fn_800738E0(s32, s32, s32);
extern void fn_80073B50(u32, s32, s32, s32, s32, s32, s32, u8, u8, s32);
extern void fn_80073678(u32);
extern void fn_80074660(u32);
extern void fn_80073898(u32);

void fn_1_62794(void *tex) {
    s32 halfW;
    s32 halfH;
    void *image;
    s32 w;
    s32 h;
    u8 mtx[0x34];
    GXTexObj texObj;
    f32 viewport[6];
    f32 proj[7];
    f32 ind[6];

    image = lbl_801A63D0;
    fn_80038F10(viewport);
    w = (s32)viewport[2];
    halfW = w >> 1;
    h = (s32)viewport[3];
    halfH = h >> 1;
    fn_80074300((s32)viewport[0], (s32)viewport[1], w, h);
    fn_80074438(halfW, halfH, 4, 1);
    fn_8003526C(image, 0);
    GXInitTexObj(&texObj, image, halfW, halfH, 4, 0, 0, 0);
    fn_80072864(0);
    fn_80038BFC(proj);
    lbl_8006DAEC();
    lbl_8006DAEC();
    lbl_8006D758();
    lbl_801A6D00[0] = -0.5f * proj[1];
    lbl_801A6D00[2] = 0.5f + (f32)(0.5f * proj[2]);
    lbl_801A6D00[5] = 0.5f * proj[3];
    lbl_801A6D00[6] = 0.5f + (f32)(0.5f * proj[4]);
    lbl_8006DB74(mtx);
    lbl_8006DB30();
    lbl_8006DFD8(mtx);
    GXLoadTexMtxImm(lbl_801A6D00, 30, 0);
    lbl_8006DB30();
    ind[0] = 0.0f;
    ind[1] = 0.5f;
    ind[2] = 0.0f;
    ind[3] = 0.5f;
    ind[4] = 0.0f;
    ind[5] = 0.0f;
    fn_80073A58(1, ind, 0);
    fn_80074788(1);
    fn_800747D0(0, 0, 0, 0, 0, 0, 2);
    fn_800747D0(2, 0, 0, 1, 0, 0, 2);
    fn_80073778(&texObj, 0);
    fn_80073778(tex, 1);
    fn_800745A4(0, 0, 0, 30, 0, 125);
    fn_800734A8(0, 0, 0, 4);
    fn_80072AB0(0, 0, 0);
    fn_80072C24(0, 15, 15, 15, 8);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 7, 7, 5);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_80074918(1, 7, 0);
    fn_800720B0(0);
    fn_800728A8(1, 4, 1, 0);
    fn_800745A4(1, 0, 0, 30, 0, 125);
    fn_800738E0(0, 1, 1);
    fn_80073B50(0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
    fn_80073678(1);
    fn_80074660(2);
    fn_80073898(1);
}
/* fzgx:end fn_1_62794 */

/* fzgx:begin fn_1_62AF8 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
    s = 0.0f;
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 150.0;
    d = 10.0;
    d = 3.0;
}
static const u32 fzgx_pool_table6[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 5.0f;
    d = 1.2;
    d = 0.1;
    s = 10.0f;
    s = 18.0f;
    d = 0.7;
    d = 50.0;
}
static const u32 fzgx_pool_table8[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 19.0f;
    d = 24.0;
    s = 0.7071067690849304f;
}
static const u32 fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 255.0;
    d = 0.9;
    s = 0.004000000189989805f;
    s = 0.0010000000474974513f;
    s = 0.009999999776482582f;
    s = -1.1920928955078125e-07f;
    s = 240.0f;
    s = 100.0f;
    s = 300.0f;
    s = 200.0f;
    s = 10000.0f;
    s = 5000.0f;
    s = 204.0f;
    s = 85.0f;
    s = -0.05000000074505806f;
    s = 4.0f;
    s = -0.05999999865889549f;
    s = -0.5f;
    s = -1.0f;
}
static const u32 fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.2;
    s = 512.0f;
    s = 0.029999999329447746f;
    s = 51.0f;
    s = 88.0f;
    d = -3.0;
    s = 4.5f;
    s = 6.0f;
}
static const u32 fzgx_pool_table14[12] = {0x3F8CCCCD, 0x00000000, 0x3F666666, 0xBF8CCCCD, 0x00000000, 0x3F666666, 0x00000000, 0x00000000, 0xBF333333, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.2000000476837158f;
    s = 50.0f;
    s = 0.02500000037252903f;
    s = 0.800000011920929f;
    s = 0.0625f;
    s = 2.5f;
}
static const u32 fzgx_pool_table16[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -3.0f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.01;
    s = 1.8600000143051147f;
}
static const u32 fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 210.0;
    d = 0.02;
    d = 0.003;
    d = -0.699999988079071;
    d = -0.029999999329447746;
    d = 0.141;
    d = 0.699999988079071;
    d = 1.0;
    d = 0.3;
    d = 0.800000011920929;
    d = 12.0;
    s = -0.8999999761581421f;
    s = 0.07000000029802322f;
    s = 0.6000000238418579f;
    s = 30.0f;
    s = 1.059999942779541f;
    s = 28.0f;
    d = 5.0;
    s = 3.5f;
    s = 180.0f;
}
static const u32 fzgx_pool_table22[2] = {0xFFFFFFFF, 0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 30.0;
}
#pragma section code_type ".text"

typedef struct {
    u8 pad_0[0xE];
    u16 unk_E;
    s32 unk_10;
    u8 pad_14[0x14];
    f32 unk_28;
    u8 pad_2C[0x28];
    u16 unk_54;
    u16 unk_56;
    u16 unk_58;
} EffectParticle_62AF8;

/* Linear congruential random: 15-bit result. */
static inline u16 effect_rand_62AF8(void) {
    lbl_1_data_1D628 = lbl_1_data_1D628 * 0x41C64E6D + 0x3039;
    return (lbl_1_data_1D628 >> 16) & 0x7FFF;
}

/* Random in [0, 1]. */
#define EFFECT_RANDF() ((f32)effect_rand_62AF8() / 32767.0f)

void fn_1_62AF8(EffectParticle_62AF8 *p) {
    if (p->unk_10 == 0) {
        p->unk_10 = (s32)(30.0 + 60.0f * EFFECT_RANDF());
    }
    p->unk_E = 0;
    if (p->unk_28 == 0.0f) {
        f64 a = 0.02 * EFFECT_RANDF();
        f64 b = 0.5 * EFFECT_RANDF();
        p->unk_28 = (5.0f * (f32)(0.02 + a)) * (0.5 + b);
    }
    p->unk_54 = effect_rand_62AF8();
    p->unk_56 = effect_rand_62AF8();
    p->unk_58 = effect_rand_62AF8();
}
/* fzgx:end fn_1_62AF8 */

/* fzgx:begin fn_1_6312C */
// fn_1_6312C: empty in retail (single blr).
void fn_1_6312C(void) {
}
/* fzgx:end fn_1_6312C */

/* fzgx:begin fn_1_63130 */
struct fn_1_63130_obj {
    u8 unk_00[0xAE];
    s16 unk_AE;
};

void fn_1_63130(struct fn_1_63130_obj *obj) {
    obj->unk_AE = 0;
}
/* fzgx:end fn_1_63130 */

/* fzgx:begin fn_1_6313C noprologue */
typedef unsigned char u8;
typedef signed short s16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const unsigned long fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const unsigned long fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 150.0;
    d = 10.0;
    d = 3.0;
}
static const unsigned long fzgx_pool_table6[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 5.0f;
    d = 1.2;
    d = 0.1;
    s = 10.0f;
    s = 18.0f;
    d = 0.7;
    d = 50.0;
}
static const unsigned long fzgx_pool_table8[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const unsigned long *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 19.0f;
    d = 24.0;
    s = 0.7071067690849304f;
}
static const unsigned long fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const unsigned long *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 255.0;
    d = 0.9;
    s = 0.004000000189989805f;
    s = 0.0010000000474974513f;
    s = 0.009999999776482582f;
    s = -1.1920928955078125e-07f;
    s = 240.0f;
    s = 100.0f;
    s = 300.0f;
    s = 200.0f;
    s = 10000.0f;
    s = 5000.0f;
    s = 204.0f;
    s = 85.0f;
    s = -0.05000000074505806f;
    s = 4.0f;
    s = -0.05999999865889549f;
    s = -0.5f;
    s = -1.0f;
}
static const unsigned long fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const unsigned long *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.2;
    s = 512.0f;
    s = 0.029999999329447746f;
    s = 51.0f;
    s = 88.0f;
    d = -3.0;
    s = 4.5f;
    s = 6.0f;
}
static const unsigned long fzgx_pool_table14[12] = {0x3F8CCCCD, 0x00000000, 0x3F666666, 0xBF8CCCCD, 0x00000000, 0x3F666666, 0x00000000, 0x00000000, 0xBF333333, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const unsigned long *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.2000000476837158f;
    s = 50.0f;
    s = 0.02500000037252903f;
    s = 0.800000011920929f;
    s = 0.0625f;
    s = 2.5f;
}
static const unsigned long fzgx_pool_table16[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const unsigned long *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = -3.0f;
}
static const unsigned long fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const unsigned long *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.01;
    s = 1.8600000143051147f;
}
static const unsigned long fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const unsigned long *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 210.0;
    d = 0.02;
    d = 0.003;
    d = -0.699999988079071;
    d = -0.029999999329447746;
    d = 0.141;
    d = 0.699999988079071;
    d = 1.0;
    d = 0.3;
    d = 0.800000011920929;
    d = 12.0;
    s = -0.8999999761581421f;
    s = 0.07000000029802322f;
    s = 0.6000000238418579f;
    s = 30.0f;
    s = 1.059999942779541f;
    s = 28.0f;
    d = 5.0;
    s = 3.5f;
    s = 180.0f;
}
static const unsigned long fzgx_pool_table22[2] = {0xFFFFFFFF, 0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const unsigned long *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 30.0;
    d = 0.03;
    s = 0.9399999976158142f;
    s = -0.07999999821186066f;
}
#pragma section code_type ".text"


typedef struct Fx {
    u8 state;
    u8 pad1[0xF];
    s32 unk10;
    u8 pad14[8];
    f32 unk1c, unk20, unk24, unk28, unk2c;
    u8 pad30[0xC];
    f32 unk3c, unk40, unk44, unk48, unk4c, unk50;
    u8 pad54[0x34];
    f32 unk88, unk8c;
    u8 pad90[0x1C];
    s16 unkac, unkae;
} Fx;

extern s32 lbl_1_bss_6C860;
extern s32 fn_1_66B8(void *, f32);

#pragma opt_propagation off
#pragma opt_common_subs off
void fn_1_6313C(Fx *p) {
    f32 v;
    f32 w;
    f32 t;
    f32 g;
    p->state = 2;
    lbl_1_bss_6C860 = lbl_1_bss_6C860 + 1;
    if (lbl_1_bss_6C860 > 150) {
        p->state = 3;
    }
    if (fn_1_66B8(&p->unk3c, p->unk28) == 0) {
        p->state = 3;
    }
    t = 1.0f - p->unk88;
    p->unk48 *= t;
    v = p->unk4c;
    p->unk4c = v * t;
    p->unk50 *= t;
    p->unk4c += -0.08f;
    p->unk48 += 0.001f;
    p->unk3c += p->unk48;
    p->unk40 += p->unk4c;
    p->unk44 += p->unk50;
    p->unk88 = p->unk88 + (f32)(0.05f * (p->unk8c - p->unk88));
    p->unk28 = p->unk28 + (f32)(0.01f * (p->unk2c - p->unk28));
    p->unkae += p->unkac;
    g = 1.0f - 1.0f / (f32)(p->unk10 + 1);
    w = p->unk1c;
    p->unk1c = w * g;
    p->unk20 *= g;
    p->unk24 *= g;
}
#pragma opt_common_subs reset
#pragma opt_propagation reset
/* fzgx:end fn_1_6313C */

/* fzgx:begin fn_1_632D4 */
struct fn_1_632D4_obj {
    u8 unk_00[0x1C];
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    u8 unk_2C[0x8];
    int unk_34;
    u8 unk_38[0x4];
    void *unk_3C;
    u8 unk_40[0x6E];
    s16 unk_AE;
};

struct fn_1_632D4_data {
    f32 unk_00;
    f32 unk_04;
    u8 unk_08[0x34];
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;
};

void fn_1_632D4(struct fn_1_632D4_obj *obj) {
    struct fn_1_632D4_value { s32 a, b, c; } value;
    struct fn_1_632D4_data data;
    int id;
    s32 red;
    s32 green;
    s32 blue;
    f32 color_scale;
    f32 size;

    id = obj->unk_34;
    lbl_8006DCA4(obj);
    lbl_8006E1B0( (Fn183D28Vec3 *)(void *)(&obj->unk_3C), (Fn183D28Vec3 *)(void *)(&value));
    lbl_8006D7DC(&value);
    mathutil_mtxA_rotate_z(obj->unk_AE);
    memset(&data, 0, 0x40);
    lbl_8006DB74(&data.unk_08);

    size = (((f32 *)&lbl_1_rodata_2AA0))[0];
    size = size * obj->unk_28;
    data.unk_00 = size;
    color_scale = lbl_1_rodata_29AC[0];
    red = color_scale * obj->unk_1C;
    data.red = red;
    green = color_scale * obj->unk_20;
    data.green = green;
    blue = color_scale * obj->unk_24;
    data.alpha = 0xff;
    data.unk_04 = size;
    data.blue = blue;

    fn_1_9F914(&data, (const void *)(int)(id));
}
/* fzgx:end fn_1_632D4 */

/* fzgx:begin fn_1_633BC */
// fn_1_633BC: empty in retail (single blr).
void fn_1_633BC(void) {
}
/* fzgx:end fn_1_633BC */

/* fzgx:begin fn_1_633C0 noprologue */
#include "rel/main_rel/effect.h"

typedef struct { f32 x, y, z; } FxVec;
typedef struct {
    u8 pad0[0x10];
    s32 unk10;
    u8 pad14[4];
    s16 unk18;
    u8 pad1A[0x3c - 0x1a];
    FxVec unk3c;
    u8 pad48[0x60 - 0x48];
    FxVec unk60;
    u8 pad6c[0x94 - 0x6c];
    FxVec unk94;
} FxObj633C0;

extern void fn_1_862D4(int, void *);
extern void fn_1_8645C(int, void *);
extern void *lbl_8006DC6C(void *);
extern void lbl_8006E1B0(void *, void *);


/* Establish the native shared literal pool in retail order. */
#pragma section code_type ".fzgxpool"
/* Volatile output preserves the native shared literal-pool priming stores. */
void fzgx_pool_primer_fn_1_633C0(volatile f32 *f, volatile f64 *d) {
    f[0] = 60.0f;
    f[1] = 0.1f;
    f[2] = 32767.0f;
    f[3] = 0.05f;
    d[0] = 0.07;
    f[4] = 20000.0f;
    d[1] = 4503599627370496.0;
    f[5] = 1.0f;
    f[6] = -0.03f;
    d[2] = 15.0;
    d[3] = 4503601774854144.0;
    d[4] = 1.5;
    d[5] = 0.5;
    f[7] = 0.0f;
    f[8] = 0.5f;
    f[9] = 8.0f;
    f[10] = 255.0f;
    f[11] = 15.0f;
    f[12] = 0.2f;
}
#pragma section code_type ".text"

#pragma section code_type ".fzgxpool"
void fzgx_pool_tail_fn_1_633C0(void (*use)(void *)) {
    /* Raw IEEE-754 pool words, including padding, not pointer addresses. */
    u32 words[] = {
        1034147594U, 1048576000U, 1065017672U, 1065185444U,
        1109393408U, 1101004800U, 1069547520U, 1055286886U,
        3221225472U, 1034594987U, 1041865114U, 1040187392U,
        3201092813U, 3197737370U, 1073741824U, 1132068864U,
        1071854387U, 858993459U, 1071225241U, 2576980378U,
        1050253722U, 3145929327U, 1015580809U, 1199570944U,
        1166016512U, 1064682127U, 1053609165U, 1028577559U,
        1028711776U, 1064514355U, 1063675494U, 0U,
        1080213504U, 0U, 1076101120U, 0U,
        1074266112U, 0U, 0U, 1036831949U,
        3222903194U, 1084227584U, 1072902963U, 858993459U,
        1069128089U, 2576980378U, 1092616192U, 1099956224U,
        1072064102U, 1717986918U, 1078525952U, 0U,
        0U, 1036831949U, 3222903194U, 1100480512U,
        1077411840U, 0U, 1060439283U, 0U,
        0U, 0U, 1081073664U, 0U,
        1072483532U, 3435973837U, 998445679U, 981668463U,
        1008981770U, 3019898880U, 1131413504U, 1120403456U,
        1133903872U, 1128792064U, 1176256512U, 1167867904U,
        1129054208U, 1118437376U, 3175926989U, 1082130432U,
        3178611343U, 3204448256U, 3212836864U, 0U,
        1070176665U, 2576980378U, 1140850688U, 1022739087U,
        1112276992U, 1118830592U, 3221749760U, 0U,
        1083179008U, 1086324736U, 1066192077U, 0U,
        1063675494U, 3213675725U, 0U, 1063675494U,
        0U, 0U, 3207803699U, 0U,
        0U, 0U, 1067030938U, 1112014848U,
        1020054733U, 1061997773U, 1031798784U, 1075838976U,
        0U, 0U, 0U, 0U,
        0U, 0U, 3225419776U, 0U,
        1065646817U, 1202590843U, 1072567419U, 0U,
        1080705024U, 0U, 1066695393U, 1202590843U,
        1063818100U, 3161095930U, 3219547750U, 1610612736U,
        3214850129U, 3758096384U, 1069681737U, 3126736191U,
        1072064102U, 1610612736U, 1072693248U, 0U,
        1070805811U, 858993459U, 1072273817U, 2684354560U,
        1076363264U, 0U, 3211159142U, 1032805417U,
        1058642330U, 1106247680U, 1065856532U, 1105199104U,
        1075052544U, 0U, 1080033280U, 1127481344U,
        4294967295U, 4294967295U, 1077805056U, 0U,
        1067366481U, 3951369912U, 1064346583U, 3181631242U,
    };
    use(words);
}
#pragma section code_type ".text"

#pragma opt_propagation off
void fn_1_633C0(FxObj633C0 *obj) {
    FxVec b[4];
    FxVec a;
    FxVec d;

    if (obj->unk10 == 0) {
        u32 r;
        r = lbl_1_data_1D628 * 0x41C64E6D + 0x3039;
        lbl_1_data_1D628 = r;
        obj->unk10 = (s32)(60.0f * (0.2f + (f32)((0.2f * ((f32)((r >> 16) & 0x7FFF) / 32767.0f)))));
    }
    fn_1_862D4(obj->unk18, &a);
    fn_1_8645C(obj->unk18, &b);
    lbl_8006DC6C(&b);
    {
        f32 fzgx_lc0_z;
        f32 fzgx_lc0_y;
        f32 fzgx_lc0_x;
        fzgx_lc0_x = a.x;
        fzgx_lc0_y = a.y;
        fzgx_lc0_z = a.z;
        *(f32 *)(0xE0000000 + 0x0C) = fzgx_lc0_x;
        *(f32 *)(0xE0000000 + 0x1C) = fzgx_lc0_y;
        *(f32 *)(0xE0000000 + 0x2C) = fzgx_lc0_z;
    }
    {
    FxVec c = {0.0f, 0.0f, 0.0f};
    c.x = obj->unk94.x;
    c.y = obj->unk94.y;
    c.z = obj->unk94.z;
    d = c;
    }
    lbl_8006E1B0(&d, &obj->unk3c);
    obj->unk60 = obj->unk3c;
}
#pragma opt_propagation reset
/* fzgx:end fn_1_633C0 */

/* fzgx:begin fn_1_63514 */
// fn_1_63514: empty in retail (single blr).
void fn_1_63514(void) {
}
/* fzgx:end fn_1_63514 */

/* fzgx:begin fn_1_63518 */
typedef struct Effect_63518_vec {
    u32 x;
    u32 y;
    u32 z;
} Effect_63518_vec;

typedef struct Effect_63518 {
    u8 unk00[0x14];
    u32 unk14;
    u8 unk18[0x20];
    Effect_63518_vec *unk38;
    Effect_63518_vec unk3c;
    u8 unk48[0x10];
    u16 unk58;
    u8 unk5a[0x06];
    Effect_63518_vec unk60;
    u8 unk6c[0x40];
    u16 unkac;
    u16 unkae;
    u16 unkb0;
} Effect_63518;

void fn_1_63518(Effect_63518 *effect) {
    Effect_63518_vec *dst;
    u32 i;

    effect->unk14 = 0;
    effect->unkac = 0;
    effect->unkae = 0;
    effect->unkb0 = 0;
    effect->unk58 = 0;

    effect->unk60 = effect->unk3c;
    dst = effect->unk38;

    for (i = 0; i < fn_1_58C4() * 8; i++) {
        *dst++ = effect->unk3c;
    }
}
/* fzgx:end fn_1_63518 */

/* fzgx:begin fn_1_635BC noprologue */
#include "types.h"
#include "game/main_rel/car_types.h"
#include "game/main_rel/car_test_types.h"
#include "rel/main_rel/effect.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const unsigned long fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const unsigned long fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 150.0;
    d = 10.0;
    d = 3.0;
}
static const unsigned long fzgx_pool_table6[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 5.0f;
    d = 1.2;
    d = 0.1;
    s = 10.0f;
    s = 18.0f;
    d = 0.7;
    d = 50.0;
}
static const unsigned long fzgx_pool_table8[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const unsigned long *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 19.0f;
    d = 24.0;
    s = 0.7071067690849304f;
}
static const unsigned long fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const unsigned long *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 255.0;
    d = 0.9;
    s = 0.004000000189989805f;
    s = 0.0010000000474974513f;
    s = 0.009999999776482582f;
    s = -1.1920928955078125e-07f;
    s = 240.0f;
    s = 100.0f;
    s = 300.0f;
    s = 200.0f;
    s = 10000.0f;
    s = 5000.0f;
    s = 204.0f;
    s = 85.0f;
    s = -0.05000000074505806f;
    s = 4.0f;
    s = -0.05999999865889549f;
    s = -0.5f;
    s = -1.0f;
}
static const unsigned long fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const unsigned long *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.2;
    s = 512.0f;
    s = 0.029999999329447746f;
    s = 51.0f;
    s = 88.0f;
    d = -3.0;
    s = 4.5f;
    s = 6.0f;
}
static const unsigned long fzgx_pool_table14[12] = {0x3F8CCCCD, 0x00000000, 0x3F666666, 0xBF8CCCCD, 0x00000000, 0x3F666666, 0x00000000, 0x00000000, 0xBF333333, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const unsigned long *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.2000000476837158f;
    s = 50.0f;
    s = 0.02500000037252903f;
    s = 0.800000011920929f;
    s = 0.0625f;
    s = 2.5f;
}
static const unsigned long fzgx_pool_table16[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const unsigned long *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = -3.0f;
}
static const unsigned long fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const unsigned long *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.01;
    s = 1.8600000143051147f;
}
static const unsigned long fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const unsigned long *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 210.0;
    d = 0.02;
    d = 0.003;
    d = -0.699999988079071;
    d = -0.029999999329447746;
    d = 0.141;
    d = 0.699999988079071;
    d = 1.0;
    d = 0.3;
    d = 0.800000011920929;
    d = 12.0;
    s = -0.8999999761581421f;
    s = 0.07000000029802322f;
    s = 0.6000000238418579f;
    s = 30.0f;
    s = 1.059999942779541f;
    s = 28.0f;
    d = 5.0;
    s = 3.5f;
    s = 180.0f;
}
static const unsigned long fzgx_pool_table22[2] = {0xFFFFFFFF, 0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const unsigned long *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 30.0;
    d = 0.03;
    s = 0.9399999976158142f;
    s = -0.07999999821186066f;
}
static const unsigned long fzgx_pool_table24[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const unsigned long *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

typedef struct {
    u8 pad_0[0x8];
    u32 flags;
    u8 pad_C[0x4];
    s32 timer;
    u8 pad_14[0x4];
    s16 id;
    u8 pad_1A[0x2];
    f32 r;
    f32 g;
    f32 b;
    u8 pad_28[0x14];
    Fn183D28Vec3 pos;
    u8 pad_48[0xC];
    s16 rot_x;
    s16 rot_y;
    u8 pad_58[0x2];
    s16 vel_x;
    s16 vel_y;
    u8 pad_5E[0x36];
    Fn183D28Vec3 offset;
    u8 pad_A0[0x14];
    f32 unk_B4;
} Fn1635BCEffect;

extern u32 fn_1_864E8(int);
extern void fn_1_862D4(int, Fn183D28Vec3 *);
extern void fn_1_8645C(int, void *);
extern void *lbl_8006DC6C(void *);
extern void mathutil_mtxA_rotate_y(s16);
extern void mathutil_mtxA_rotate_x(s16);

/* Translation column of the current matrix in the locked cache. */
static inline void mtxA_set_translate(Fn183D28Vec3 *v) {
    f32 z;
    f32 y;
    f32 x;

    z = v->z;
    y = v->y;
    x = v->x;

    *(f32 *)(0xE0000000 + 0x0C) = x;
    *(f32 *)(0xE0000000 + 0x1C) = y;
    *(f32 *)(0xE0000000 + 0x2C) = z;
}

void fn_1_635BC(Fn1635BCEffect *e) {
    Fn183D28Vec3 pos;
    Fn183D28Vec3 offset;
    Fn183D28Vec3 tmp;
    u32 flags;
    f32 rnd;
    f32 scale;

    flags = fn_1_864E8(e->id);
    if (((flags & 0x8) || (flags & 0x20000)) && __rlwnm(e->flags, 19, 31, 31)) {
        e->timer++;
    } else {
        e->vel_x *= 0.98f;
        e->vel_y *= 0.98f;
        e->flags &= ~0x2000;
    }

    fn_1_862D4(e->id, &pos);
{
    f32 mtx[3][4];
    fn_1_8645C(e->id, mtx);
    lbl_8006DC6C(mtx);
}
    {
        f32 fzgx_lc0_z;
        f32 fzgx_lc0_y;
        f32 fzgx_lc0_x;
        fzgx_lc0_x = *(volatile f32 *)&((&pos)->x);  /* volatile: keeps the first-stored locked-cache value loaded in source order (retail x/y/z FPR order) */
        fzgx_lc0_y = (&pos)->y;
        fzgx_lc0_z = (&pos)->z;
        *(f32 *)(0xE0000000 + 0x0C) = fzgx_lc0_x;
        *(f32 *)(0xE0000000 + 0x1C) = fzgx_lc0_y;
        *(f32 *)(0xE0000000 + 0x2C) = fzgx_lc0_z;
    }
    e->rot_y += e->vel_y;
    e->rot_x += e->vel_x;
    mathutil_mtxA_rotate_y(e->rot_y);
    mathutil_mtxA_rotate_x(e->rot_x);
    {
        Fn183D28Vec3 init = { 0.0f, 0.0f, 0.0f };
        tmp = init;
    }
    tmp.x = e->offset.x;
    tmp.y = e->offset.y;
    tmp.z = e->offset.z;
    offset = tmp;
    lbl_8006E1B0(&offset, &e->pos);

    e->unk_B4 = 0.5f * (f32)e->timer;
    lbl_1_data_1D628 = lbl_1_data_1D628 * 0x41C64E6D + 12345;
    rnd = 0.8f + (f32)(0.2f * ((f32)((lbl_1_data_1D628 >> 16) & 0x7FFF) / 32767.0f));
    e->r = 255.0f * (0.5f * (1.0f + rnd)) / 255.0f;
    scale = 136.0f * rnd / 255.0f;
    e->g = scale;
    e->b = scale;
    if (e->timer < 30) {
        e->r *= scale = 1.0f - (1.0f + (f32)(-0.03f * (f32)e->timer));
        e->g *= scale;
        e->b *= scale;
    }
}
/* fzgx:end fn_1_635BC */

/* fzgx:begin fn_1_63858 */
struct LocalData {
    u8 data[0x10];
};

struct fn_1_63858_Event {
    u8 data[4];
    void (*callback)(void);
    void *owner;
};

struct fn_1_63858_Object {
    u8 data[0x18];
    s16 value;
};

void fn_1_63858(struct fn_1_63858_Object *object) {
    struct LocalData local;
    struct fn_1_63858_Event *event;
    void *target;

    fn_1_862D4(object->value, &local);
    lbl_8006DCA4();
    if (fn_1_54E34(&local, lbl_1_rodata_2B2C[0]) != 0) {
        target = fn_1_5448C(&local);
        event = (struct fn_1_63858_Event *)fn_1_548AC(0xc);
        if (event != 0) {
            event->callback = fn_1_638E8;
            event->owner = object;
            fn_1_5489C( (void **)(void *)(target), (void **)(void *)(event));
        }
    }
}
/* fzgx:end fn_1_63858 */

/* fzgx:begin fn_1_64098 */
typedef struct Fn164098Object {
    u8 pad[0xae];
    u16 value;
} Fn164098Object;

void fn_1_64098(Fn164098Object *object) {
    object->value = 0;
}
/* fzgx:end fn_1_64098 */

/* fzgx:begin fn_1_640A4 pool */
typedef struct {
    u8 state;
    u8 pad_1[0x7];
    u32 flags;
    u8 pad_C[0x4];
    s32 timer;
    u8 pad_14[0x8];
    f32 scale[3];
    f32 alpha;
    f32 alphaTarget;
    u8 pad_30[0xC];
    f32 pos[3];
    f32 vel[3];
    u8 pad_54[0x34];
    f32 drag;
    f32 dragTarget;
    u8 pad_90[0x1C];
    s16 spin;
    s16 angle;
} SmokeParticle;


/* Shared literal pool primer (retail lbl_1_rodata_2950 layout); dropped at integration. */
#pragma section RX ".fzgxpool"
static const f32 pool_a[3] = { 60.0f, 0.1f, 32767.0f };
__declspec(section ".fzgxpool") void fzgx_pool_p0(const void **o, f32 *f) { *o = pool_a; *f = 0.05f; }
static const f32 pool_b[6] = { 1.39f, 1.951564e-20f, 20000.0f, 0.0f, 176.0f, 0.0f };
__declspec(section ".fzgxpool") void fzgx_pool_p1(const void **o, f32 *f) { *o = pool_b; *f = 1.0f; }
static const f32 pool_c[3] = { -0.03f, 2.71875f, 0.0f };
__declspec(section ".fzgxpool") void fzgx_pool_p2(const void **o, f32 *f, s32 x) { *o = pool_c; *f = (f32)x; }
static const u32 pool_d0[5] = { 0x3FF80000, 0, 0x3FE00000, 0, 0 };
static const f32 pool_d1[71] = {
    0.5f, 8.0f, 255.0f, 15.0f, 0.2f, 0.08f, 0.25f,
    0.98f, 0.99f, 40.0f, 20.0f, 1.5f, 0.45f, -2.0f, 0.083333336f, 0.15f, 0.125f, -0.4f, -0.3f,
    2.0f, 250.0f, 1.775f, 4.172325e-8f, 1.6999999f, -1.5881868e-23f, 0.3f, -0.004f, 0.016666668f,
    65536.0f, 4096.0f, 0.96f, 0.4f, 0.0505f, 0.051f, 0.95f, 0.9f, 0.0f, 3.5429688f, 0.0f, 2.5625f,
    0.0f, 2.125f, 0.0f, 0.0f, 0.1f, -2.4f,
    5.0f, 1.9f, 4.172325e-8f, 1.4499999f, -1.5881868e-23f,
    10.0f, 18.0f, 1.8f, 2.720083e23f, 3.140625f, 0.0f, 0.0f, 0.1f, -2.4f, 19.0f, 2.875f, 0.0f,
    0.70710677f, 0.0f, 0.0f, 0.0f, 3.7480469f, 0.0f, 1.8499999f, -107374184.0f
};
__declspec(section ".fzgxpool") void fzgx_pool_p3(const void **o, f32 *f) {
    o[0] = pool_d0; o[1] = pool_d1; f[0] = 0.004f; f[1] = 0.001f; f[2] = 0.01f;
}
static const f32 pool_e[38] = {
    -1.1920929e-07f, 240.0f, 100.0f, 300.0f, 200.0f, 10000.0f, 5000.0f, 204.0f, 85.0f, -0.05f,
    4.0f, -0.06f, -0.5f, -1.0f, 0.0f, 1.5749999f, -1.5881868e-23f, 512.0f, 0.03f, 51.0f, 88.0f,
    -2.125f, 0.0f, 4.5f,
    6.0f, 1.1f, 0.0f, 0.9f, -1.1f, 0.0f, 0.9f, 0.0f, 0.0f, -0.7f, 0.0f, 0.0f, 0.0f, 1.2f
};
__declspec(section ".fzgxpool") void fzgx_pool_p4(const void **o, f32 *f) { *o = pool_e; *f = 50.0f; }
static const f32 pool_f1[48] = {
    0.025f, 0.8f, 0.0625f, 2.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, -3.0f, 0.0f,
    1.035f, 89128.96f, 1.86f, 0.0f, 3.6601563f, 0.0f, 1.16f, 89128.96f,
    0.90849996f, -0.0143125f, -1.8f, 3.689349e19f, -1.2399999f, -3.689349e19f, 1.5159999f,
    -0.0008476562f, 1.8f, 3.689349e19f, 1.875f, 0.0f,
    1.65f, 4.172325e-8f, 1.8249999f, -1.0842022e-19f, 2.625f, 0.0f,
    -0.9f, 0.07f, 0.6f, 30.0f, 1.06f, 28.0f, 2.3125f, 0.0f, 3.5f, 180.0f
};
static const u32 pool_nan[2] = { 0xFFFFFFFF, 0xFFFFFFFF };
static const f32 pool_f2[13] = {
    2.96875f, 0.0f, 1.2399999f, -3.218644e26f, 0.94f, -0.08f,
    0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 136.0f
};
__declspec(section ".fzgxpool") void fzgx_pool_p5(const void **o, f32 *f) {
    o[0] = pool_f1; o[1] = pool_nan; o[2] = pool_f2;
    f[0] = 0.008f; f[1] = 0.0045454544f; f[2] = 0.014285714f;
}

void fn_1_640A4(SmokeParticle *p)
{
    f32 keep;
    f32 fade;

    p->state = 2;
    if ((s32)++lbl_1_bss_6C860 > 150) {
        p->state = 3;
    }
    if (fn_1_66B8(p->pos, p->alpha) == 0) {
        p->state = 3;
    }

    keep = 1.0f - p->drag;
    p->vel[0] *= keep;
    p->vel[1] *= keep;
    p->vel[2] *= keep;
    p->spin = (f32)p->spin * keep;

    if (!((p->flags >> 17) & 1)) {
        p->vel[1] += 0.008f;
    } else {
        p->vel[1] += 0.004f;
    }
    p->vel[0] += 0.001f;

    p->pos[0] += p->vel[0];
    p->pos[1] += p->vel[1];
    p->pos[2] += p->vel[2];
    p->angle += p->spin;

    p->drag = p->drag + (f32)(0.05f * (p->dragTarget - p->drag));
    p->alpha = p->alpha + (f32)(0.01f * (p->alphaTarget - p->alpha));

    if (p->alphaTarget > 50.0f) {
        if (p->timer < 220) {
            fade = 0.0045454544f * (f32)p->timer;
        } else {
            fade = 1.0f;
        }
    } else {
        if (p->timer < 70) {
            fade = 0.014285714f * (f32)p->timer;
        } else {
            fade = 1.0f;
        }
    }
    p->scale[0] *= fade;
    p->scale[1] *= fade;
    p->scale[2] *= fade;
}
/* fzgx:end fn_1_640A4 */

/* fzgx:begin fn_1_642E8 */
typedef struct fn_1_642E8_EffectState {
    char bytes[0x14];
} fn_1_642E8_EffectState;

typedef struct fn_1_642E8_EffectObject {
    char pad0[0x28];
    f32 value;
    char pad2c[0x10];
    fn_1_642E8_EffectState state;
} fn_1_642E8_EffectObject;

typedef struct EffectNode {
    char pad0[4];
    void (*callback)(void);
    void *owner;
} EffectNode;

void fn_1_642E8(fn_1_642E8_EffectObject *self) {
    f32 value;
    void *state;
    EffectNode *node;

    value = self->value / lbl_1_rodata_2A70[0];
    lbl_8006DCA4();
    if (fn_1_54E34(&self->state, value)) {
        state = fn_1_5448C(&self->state);
        node = fn_1_548AC(0xc);
        if (node != 0) {
            node->callback = fn_1_64388;
            node->owner = self;
            fn_1_5489C( (void **)(void *)(state), (void **)(void *)(node));
        }
    }
}
/* fzgx:end fn_1_642E8 */

/* fzgx:begin fn_1_64388 noprologue */
#include "game/main_rel/car_test_types.h"
#include "psvec.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const unsigned long fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const unsigned long fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 150.0;
    d = 10.0;
    d = 3.0;
}
static const unsigned long fzgx_pool_table6[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 5.0f;
    d = 1.2;
    d = 0.1;
    s = 10.0f;
    s = 18.0f;
    d = 0.7;
    d = 50.0;
}
static const unsigned long fzgx_pool_table8[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const unsigned long *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 19.0f;
    d = 24.0;
    s = 0.7071067690849304f;
}
static const unsigned long fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const unsigned long *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 255.0;
    d = 0.9;
    s = 0.004000000189989805f;
    s = 0.0010000000474974513f;
    s = 0.009999999776482582f;
    s = -1.1920928955078125e-07f;
    s = 240.0f;
    s = 100.0f;
    s = 300.0f;
    s = 200.0f;
    s = 10000.0f;
    s = 5000.0f;
    s = 204.0f;
    s = 85.0f;
    s = -0.05000000074505806f;
    s = 4.0f;
    s = -0.05999999865889549f;
    s = -0.5f;
    s = -1.0f;
}
static const unsigned long fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const unsigned long *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.2;
    s = 512.0f;
    s = 0.029999999329447746f;
    s = 51.0f;
    s = 88.0f;
    d = -3.0;
    s = 4.5f;
    s = 6.0f;
}
static const unsigned long fzgx_pool_table14[12] = {0x3F8CCCCD, 0x00000000, 0x3F666666, 0xBF8CCCCD, 0x00000000, 0x3F666666, 0x00000000, 0x00000000, 0xBF333333, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const unsigned long *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.2000000476837158f;
    s = 50.0f;
    s = 0.02500000037252903f;
    s = 0.800000011920929f;
    s = 0.0625f;
    s = 2.5f;
}
static const unsigned long fzgx_pool_table16[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const unsigned long *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = -3.0f;
}
static const unsigned long fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const unsigned long *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.01;
    s = 1.8600000143051147f;
}
static const unsigned long fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const unsigned long *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 210.0;
    d = 0.02;
    d = 0.003;
    d = -0.699999988079071;
    d = -0.029999999329447746;
    d = 0.141;
    d = 0.699999988079071;
    d = 1.0;
    d = 0.3;
    d = 0.800000011920929;
    d = 12.0;
    s = -0.8999999761581421f;
    s = 0.07000000029802322f;
    s = 0.6000000238418579f;
    s = 30.0f;
    s = 1.059999942779541f;
    s = 28.0f;
    d = 5.0;
    s = 3.5f;
    s = 180.0f;
}
static const unsigned long fzgx_pool_table22[2] = {0xFFFFFFFF, 0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const unsigned long *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 30.0;
    d = 0.03;
    s = 0.9399999976158142f;
    s = -0.07999999821186066f;
}
static const unsigned long fzgx_pool_table24[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const unsigned long *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 136.0f;
    s = 0.00800000037997961f;
    s = 0.004545454401522875f;
    s = 0.014285714365541935f;
    s = 2000.0f;
    s = 1000.0f;
    s = 2.0999999046325684f;
}
static const unsigned long fzgx_pool_table26[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep26(void) { const unsigned long *volatile cp; cp = fzgx_pool_table26; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

extern f32 fn_1_A71AC(void);
extern void fn_1_55FC4(f32);
extern void fn_1_56000(u8, u8, u8);
extern void fn_1_5621C(f32, f32, f32, f32);
extern void fn_1_556B8(void *);
extern void lbl_8006DCA4(void);
extern void lbl_8006D7DC(Fn183D28Vec3 *);
extern f32 lbl_8006D0B4(f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006D848(f32);
extern void lbl_8006DFC4(void *);
extern void mathutil_mtxA_rotate_z(s16);
extern void lbl_8006E14C(f32);
extern void fn_80072558(void);

typedef struct {
    u8 pad_0[0x14];
    f32 size;
} Fn1_64388Model;

typedef struct {
    u8 pad_0[0x10];
    s32 timer;
    u8 pad_14[0x8];
    f32 r;
    f32 g;
    f32 b;
    f32 scale;
    u8 pad_2C[0x8];
    Fn1_64388Model *model;
    u8 pad_38[0x4];
    Fn183D28Vec3 pos;
    u8 pad_48[0xae - 0x48];
    s16 rotZ;
} Fn1_64388Effect;

typedef struct {
    u8 pad_0[0x8];
    Fn1_64388Effect *effect;
} Fn1_64388Work;

static inline f32 sqlen(f32 z, f32 y, f32 x)
{
    f32 len;
    len = x * x;
    len = y * y + len;
    return z * z + len;
}

void fn_1_64388(Fn1_64388Work *work)
{
    Fn183D28Vec3 viewPos;
    Fn183D28Vec3 dist;
    f32 mtx[3][4];
    Fn1_64388Effect *effect;
    Fn1_64388Model *model;
    f32 scale;
    f32 alpha;
    f32 z;
    f32 len;
    f32 size;

    effect = work->effect;
    lbl_8006DCA4();
    lbl_8006E1B0(&effect->pos, &viewPos);
    scale = effect->scale / 10.0f;
    model = effect->model;
    if (viewPos.z > -1.1920929e-07f) {
        return;
    }
    z = fn_1_A71AC();
    size = 240.0f * (2.0f * model->size * scale) / (-viewPos.z * z);
    alpha = 1.0f;
    if (size < 10.0f) {
        return;
    }
    if (size < 20.0f) {
        alpha *= (size - 10.0f) / 10.0f;
    }
    if (size > 2000.0f) {
        return;
    }
    if (size > 1000.0f) {
        alpha *= 1.0f - (size - 1000.0f) / 1000.0f;
    }
    lbl_8006D7DC(&viewPos);
    psvec_set(&dist, *(f32 *)(0xE0000000 + 0x2C), *(f32 *)(0xE0000000 + 0x1C), *(f32 *)(0xE0000000 + 0x0C));
    len = lbl_8006D0B4(sqlen(dist.z, dist.y, dist.x));
    if (len > 2.1f) {
        lbl_8006DB74(mtx);
        lbl_8006D848((len - 2.0f) / len);
        lbl_8006DFC4(mtx);
    }
    mathutil_mtxA_rotate_z(effect->rotZ);
    lbl_8006E14C(scale);
    fn_1_55FC4(scale);
    fn_1_56000(1, 3, 0);
    fn_80072558();
    fn_1_5621C(effect->r, effect->g, effect->b,
               effect->timer < 60 ? 0.016666668f * (f32)effect->timer * alpha : alpha);
    fn_1_556B8(model);
    fn_1_56000(1, 3, 1);
    fn_1_5621C(1.0f, 1.0f, 1.0f, 1.0f);
}
/* fzgx:end fn_1_64388 */

/* fzgx:begin fn_1_645C8 */
// fn_1_645C8: empty in retail (single blr).
void fn_1_645C8(void) {
}
/* fzgx:end fn_1_645C8 */

/* fzgx:begin fn_1_645CC */
// fn_1_645CC: empty in retail (single blr).
void fn_1_645CC(void) {
}
/* fzgx:end fn_1_645CC */

/* fzgx:begin fn_1_645D0 */
// fn_1_645D0: empty in retail (single blr).
void fn_1_645D0(void) {
}
/* fzgx:end fn_1_645D0 */

/* fzgx:begin fn_1_645D4 noprologue */
#include "types.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const unsigned long fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const unsigned long fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 150.0;
    d = 10.0;
    d = 3.0;
}
static const unsigned long fzgx_pool_table6[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 5.0f;
    d = 1.2;
    d = 0.1;
    s = 10.0f;
    s = 18.0f;
    d = 0.7;
    d = 50.0;
}
static const unsigned long fzgx_pool_table8[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const unsigned long *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 19.0f;
    d = 24.0;
    s = 0.7071067690849304f;
}
static const unsigned long fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const unsigned long *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 255.0;
    d = 0.9;
    s = 0.004000000189989805f;
    s = 0.0010000000474974513f;
    s = 0.009999999776482582f;
    s = -1.1920928955078125e-07f;
    s = 240.0f;
    s = 100.0f;
    s = 300.0f;
    s = 200.0f;
    s = 10000.0f;
    s = 5000.0f;
    s = 204.0f;
    s = 85.0f;
    s = -0.05000000074505806f;
    s = 4.0f;
    s = -0.05999999865889549f;
    s = -0.5f;
    s = -1.0f;
}
static const unsigned long fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const unsigned long *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.2;
    s = 512.0f;
    s = 0.029999999329447746f;
    s = 51.0f;
    s = 88.0f;
    d = -3.0;
    s = 4.5f;
    s = 6.0f;
}
static const unsigned long fzgx_pool_table14[12] = {0x3F8CCCCD, 0x00000000, 0x3F666666, 0xBF8CCCCD, 0x00000000, 0x3F666666, 0x00000000, 0x00000000, 0xBF333333, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const unsigned long *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.2000000476837158f;
    s = 50.0f;
    s = 0.02500000037252903f;
    s = 0.800000011920929f;
    s = 0.0625f;
    s = 2.5f;
}
static const unsigned long fzgx_pool_table16[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const unsigned long *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = -3.0f;
}
static const unsigned long fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const unsigned long *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.01;
    s = 1.8600000143051147f;
}
static const unsigned long fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const unsigned long *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 210.0;
    d = 0.02;
    d = 0.003;
    d = -0.699999988079071;
    d = -0.029999999329447746;
    d = 0.141;
    d = 0.699999988079071;
    d = 1.0;
    d = 0.3;
    d = 0.800000011920929;
    d = 12.0;
    s = -0.8999999761581421f;
    s = 0.07000000029802322f;
    s = 0.6000000238418579f;
    s = 30.0f;
    s = 1.059999942779541f;
    s = 28.0f;
    d = 5.0;
    s = 3.5f;
    s = 180.0f;
}
static const unsigned long fzgx_pool_table22[2] = {0xFFFFFFFF, 0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const unsigned long *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 30.0;
    d = 0.03;
    s = 0.9399999976158142f;
    s = -0.07999999821186066f;
}
static const unsigned long fzgx_pool_table24[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const unsigned long *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 136.0f;
    s = 0.00800000037997961f;
    s = 0.004545454401522875f;
    s = 0.014285714365541935f;
    s = 2000.0f;
    s = 1000.0f;
    s = 2.0999999046325684f;
}
#pragma section code_type ".text"

typedef struct { f32 x, y, z; } V3;
struct A { u8 pad_0[0x18]; s16 unk_18; };
extern u32 lbl_801A63C0;
extern void fn_1_862D4(int, V3 *);
extern void fn_1_8636C(int, void *);
extern void lbl_8006D5A4(void *, void *, void *, f32);
extern void lbl_8006DC6C(void *);
extern void lbl_8006E1B0(void *, void *);

#pragma opt_common_subs off
#pragma opt_propagation off
void fn_1_645D4(struct A *arg0) {
    V3 pos;
    V3 rnd2;
    u8 mtx[0x30];
    fn_1_862D4(arg0->unk_18, &pos);
    fn_1_8636C(arg0->unk_18, mtx);
{
    V3 rnd = {0.0f, 0.0f, 0.0f};
    lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
    rnd.x = 0.2 * ((f32)(s32)((lbl_801A63C0 >> 16) & 0x7FFF) / 32767.0f);
    lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
    rnd.y = 0.2 * ((f32)(s32)((lbl_801A63C0 >> 16) & 0x7FFF) / 32767.0f);
    lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
    rnd.z = 0.2 * ((f32)(s32)((lbl_801A63C0 >> 16) & 0x7FFF) / 32767.0f);
    rnd2 = rnd;
}
    lbl_8006D5A4((u8 *)arg0 + 0x94, &rnd2, (u8 *)arg0 + 0x94, 0.05f);
    lbl_8006DC6C(mtx);
    {
        f32 fzgx_lc0_z;
        f32 fzgx_lc0_y;
        f32 fzgx_lc0_x;
        fzgx_lc0_x = pos.x;
        fzgx_lc0_y = pos.y;
        fzgx_lc0_z = pos.z;
        *(f32 *)(0xE0000000 + 0x0C) = fzgx_lc0_x;
        *(f32 *)(0xE0000000 + 0x1C) = fzgx_lc0_y;
        *(f32 *)(0xE0000000 + 0x2C) = fzgx_lc0_z;
    }
    lbl_8006E1B0((u8 *)arg0 + 0x94, (u8 *)arg0 + 0x3c);
}
#pragma opt_propagation reset
#pragma opt_common_subs reset
/* fzgx:end fn_1_645D4 */

/* fzgx:begin fn_1_648D4 */
// fn_1_648D4: empty in retail (single blr).
void fn_1_648D4(void) {
}
/* fzgx:end fn_1_648D4 */

/* fzgx:begin fn_1_648D8 */
// fn_1_648D8: empty in retail (single blr).
void fn_1_648D8(void) {
}
/* fzgx:end fn_1_648D8 */

/* fzgx:begin fn_1_64E1C noprologue */
#include "dolphin/types.h"
#include "game/main_rel/camera_types.h"

typedef struct {
    u8 pad_00[0x1a];
    u16 count_b;
    u16 count_c;
} Sig_fn_1_55210_Fn55210Arg;
extern void fn_1_55FC4(f32);
extern void fn_1_55FF0(f32);
extern void fn_1_55210(Sig_fn_1_55210_Fn55210Arg *);
extern void lbl_8006D9D8(CamEntry *);
extern u32 mathutil_mtxA_rotate_y(u32);
extern u32 mathutil_mtxA_rotate_x(u32);
extern u32 mathutil_mtxA_rotate_z(u32);
extern void lbl_8006E14C(f32);
extern void fn_80072558(void);
extern const f32 lbl_1_rodata_295C;
extern const f32 lbl_1_rodata_2978;

typedef struct {
    u8 pad_00[0x10];
    s32 timer;
    u8 pad_14[0x14];
    f32 scale;
    f32 offset;
    u8 pad_30[4];
    Sig_fn_1_55210_Fn55210Arg *model;
    u8 pad_38[4];
    f32 x, y, z;
    u8 pad_48[0xc];
    s16 rx, ry, rz;
    u8 pad_5a[0x46];
    f32 dx, dy, dz;
} Fn64E1CArg;

void fn_1_64E1C(Fn64E1CArg *arg)
{
    struct { f32 x, y, z; } pos;
    f32 scale;
    Sig_fn_1_55210_Fn55210Arg *model;
    model = arg->model;
    pos.x = arg->x + (f32)(arg->offset * arg->dx);
    pos.y = arg->y + (f32)(arg->offset * arg->dy);
    pos.z = arg->z + (f32)(arg->offset * arg->dz);
    scale = arg->scale;
    lbl_8006D9D8((CamEntry *)&pos);
    mathutil_mtxA_rotate_y(arg->ry);
    mathutil_mtxA_rotate_x(arg->rx);
    mathutil_mtxA_rotate_z(arg->rz);
    lbl_8006E14C(scale);
    fn_1_55FC4(scale);
    fn_80072558();
    {
        f32 alpha;
        if (arg->timer < 20) {
            alpha = lbl_1_rodata_295C * (f32)arg->timer;
        } else {
            alpha = lbl_1_rodata_2978;
        }
        fn_1_55FF0(alpha);
    }
    fn_1_55210(model);
}
/* fzgx:end fn_1_64E1C */

/* fzgx:begin fn_1_64F2C */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
}
#pragma section code_type ".text"

typedef struct {
    u8 pad_00[0x10];
    s32 unk_10;
} fn_1_64F2C_Fn_1_64F2C_Object;


void fn_1_64F2C(fn_1_64F2C_Fn_1_64F2C_Object *obj) {
    f32 random;
    f32 scaled;
    f32 offset;

    if (obj->unk_10 == 0) {
{
    u32 value;
        value = lbl_1_data_1D628 * 0x41c64e6d + 0x3039;
        lbl_1_data_1D628 = value;
        random = (f32)((value >> 16) & 0x7fff) / 32767.0f;
}
        scaled = 0.25f * random;
        offset = 0.3f + scaled;
        obj->unk_10 = (s32)(60.0f * offset);
    }
}
/* fzgx:end fn_1_64F2C */

/* fzgx:begin fn_1_64FB8 noprologue */
#include "types.h"
#include "game/main_rel/car_test_types.h"
#include "game/main_rel/car_types.h"
#include "rel/main_rel/effect.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const unsigned long fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const unsigned long fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 150.0;
    d = 10.0;
    d = 3.0;
}
static const unsigned long fzgx_pool_table6[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 5.0f;
    d = 1.2;
    d = 0.1;
    s = 10.0f;
    s = 18.0f;
    d = 0.7;
    d = 50.0;
}
static const unsigned long fzgx_pool_table8[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const unsigned long *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 19.0f;
    d = 24.0;
    s = 0.7071067690849304f;
}
static const unsigned long fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const unsigned long *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 255.0;
    d = 0.9;
    s = 0.004000000189989805f;
    s = 0.0010000000474974513f;
    s = 0.009999999776482582f;
    s = -1.1920928955078125e-07f;
    s = 240.0f;
    s = 100.0f;
    s = 300.0f;
    s = 200.0f;
    s = 10000.0f;
    s = 5000.0f;
    s = 204.0f;
    s = 85.0f;
    s = -0.05000000074505806f;
    s = 4.0f;
    s = -0.05999999865889549f;
    s = -0.5f;
    s = -1.0f;
}
static const unsigned long fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const unsigned long *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.2;
    s = 512.0f;
    s = 0.029999999329447746f;
    s = 51.0f;
    s = 88.0f;
    d = -3.0;
    s = 4.5f;
    s = 6.0f;
}
static const unsigned long fzgx_pool_table14[12] = {0x3F8CCCCD, 0x00000000, 0x3F666666, 0xBF8CCCCD, 0x00000000, 0x3F666666, 0x00000000, 0x00000000, 0xBF333333, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const unsigned long *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.2000000476837158f;
    s = 50.0f;
    s = 0.02500000037252903f;
    s = 0.800000011920929f;
    s = 0.0625f;
    s = 2.5f;
}
static const unsigned long fzgx_pool_table16[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const unsigned long *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = -3.0f;
}
static const unsigned long fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const unsigned long *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.01;
    s = 1.8600000143051147f;
}
static const unsigned long fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const unsigned long *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 210.0;
    d = 0.02;
    d = 0.003;
    d = -0.699999988079071;
    d = -0.029999999329447746;
    d = 0.141;
    d = 0.699999988079071;
    d = 1.0;
    d = 0.3;
    d = 0.800000011920929;
    d = 12.0;
    s = -0.8999999761581421f;
    s = 0.07000000029802322f;
    s = 0.6000000238418579f;
    s = 30.0f;
    s = 1.059999942779541f;
    s = 28.0f;
    d = 5.0;
    s = 3.5f;
    s = 180.0f;
}
static const unsigned long fzgx_pool_table22[2] = {0xFFFFFFFF, 0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const unsigned long *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 30.0;
    d = 0.03;
    s = 0.9399999976158142f;
    s = -0.07999999821186066f;
}
static const unsigned long fzgx_pool_table24[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const unsigned long *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 136.0f;
    s = 0.00800000037997961f;
    s = 0.004545454401522875f;
    s = 0.014285714365541935f;
    s = 2000.0f;
    s = 1000.0f;
    s = 2.0999999046325684f;
}
static const unsigned long fzgx_pool_table26[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep26(void) { const unsigned long *volatile cp; cp = fzgx_pool_table26; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime27(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.04;
    d = 0.98;
    d = 0.96;
    d = 0.025;
    d = -1.0;
    d = 0.8;
}

#pragma section code_type ".text"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} EffVec;

typedef struct {
    u8 pad_0[0x10];
    s32 unk_10;
    u8 pad_14[0x4];
    s16 unk_18;
    u8 pad_1A[0x2];
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2C;
    u8 pad_30[0xC];
    EffVec unk_3C;
    u8 pad_48[0xC];
    s16 unk_54;
    s16 unk_56;
    u8 pad_58[0x2];
    s16 unk_5A;
    s16 unk_5C;
    u8 pad_5E[0x56];
    f32 unk_B4;
} fn_1_64FB8_Effect;

extern void *fn_1_86254(int);
extern void fn_1_862D4(int, Triple *);
extern void fn_1_8636C(int, void *);
extern u32 fn_1_6EC0(u8);
extern s16 camera_get_entry_field_0xa4(u32);
extern void *lbl_8006DC6C(void *);
extern void lbl_8006E1B0(Fn183D28Vec3 *, Fn183D28Vec3 *);
extern void mathutil_mtxA_rotate_y(s16);
extern void mathutil_mtxA_rotate_x(s16);

/* Store a translation into the locked-cache current matrix. */
static inline void fn_1_64FB8_set_translate(EffVec *v) {
    f32 x;
    f32 y;
    f32 z;

    x = v->x;
    y = v->y;
    z = v->z;
    *(f32 *)(0xE0000000 + 0x0C) = x;
    *(f32 *)(0xE0000000 + 0x1C) = y;
    *(f32 *)(0xE0000000 + 0x2C) = z;
}

/* A vector along the z axis, built from a zero template. */
static inline EffVec fn_1_64FB8_offset_z(f32 z) {
    EffVec v = {0.0f, 0.0f, 0.0f};

    v.z = z;
    return v;
}

static inline EffVec fn_1_64FB8_offset_z2(f32 z) {
    EffVec v = {0.0f, 0.0f, 0.0f};
    v.z = z;
    return v;
}

#pragma opt_propagation off
void fn_1_64FB8(fn_1_64FB8_Effect *effect) {
    u8 *car;
    EffVec pos;
    EffVec ofs;
    EffVec cam_ofs;
    f32 mtx[3][4];
    f32 t;
    f32 b;

    effect->unk_5A *= 0.98f;
    effect->unk_5C *= 0.98f;

    car = fn_1_86254(effect->unk_18);
    fn_1_862D4(effect->unk_18, (Triple *)&pos);
    fn_1_8636C(effect->unk_18, mtx);
    lbl_8006DC6C(mtx);
    fn_1_64FB8_set_translate(&pos);

    if ((s8)car[0x475] != -1 && (s32)fn_1_6EC0(car[0x475]) != 0 &&
        camera_get_entry_field_0xa4(car[0x475]) == 0) {
        cam_ofs = fn_1_64FB8_offset_z(-3.0f);
        lbl_8006E1B0((Fn183D28Vec3 *)&cam_ofs, (Fn183D28Vec3 *)&cam_ofs);
        fn_1_64FB8_set_translate(&cam_ofs);
    }

    effect->unk_54 += effect->unk_5A;
    effect->unk_56 += effect->unk_5C;
    mathutil_mtxA_rotate_y(effect->unk_56);
    mathutil_mtxA_rotate_x(effect->unk_54);
    ofs = fn_1_64FB8_offset_z2(0.5 * -effect->unk_28);
    lbl_8006E1B0((Fn183D28Vec3 *)&ofs, (Fn183D28Vec3 *)&effect->unk_3C);

    effect->unk_28 += (f32)(0.01f * (effect->unk_2C - effect->unk_28));
    effect->unk_B4 = 0.5f * effect->unk_10;
    lbl_1_data_1D628 = lbl_1_data_1D628 * 1103515245 + 12345;
    t = 0.8f + (f32)(0.2f * ((f32)((lbl_1_data_1D628 >> 16) & 0x7FFF) / 32767.0f));
    effect->unk_1C = 255.0f * (0.5f * (1.0f + t)) / 255.0f;
    b = 136.0f * t / 255.0f;
    effect->unk_20 = b;
    effect->unk_24 = b;
}
#pragma opt_propagation reset
/* fzgx:end fn_1_64FB8 */

/* fzgx:begin fn_1_65268 noprologue */
#include "types.h"

extern void lbl_8006DCA4(void);
extern s32 fn_1_54E34(void *object, f32 value);
extern void fn_1_652F4(void);

extern void lbl_8006DCA4(void);
extern s32 fn_1_54E34(void *object, f32 value);
extern void *fn_1_5448C(void *);
extern void fn_1_5489C(void *, void *);
extern void fn_1_862D4(s16 value, void *result);
extern void *fn_1_548AC(u32 size);

typedef struct {
    u32 pad_00;
    void (*vtable)(void);
    void *owner;
} Event;

typedef struct {
    u8 pad_00[0x18];
    s16 value;
    u8 pad_1a[0xe];
    f32 amount;
    u8 pad_2c[0x10];
    u8 embedded[1];
} Object;

void fn_1_65268(Object *object) {
    u8 local[4];
    void *result;
    Event *event;

    fn_1_862D4(object->value, local);
    lbl_8006DCA4();
    if (fn_1_54E34(&object->embedded[0], object->amount) != 0) {
        result = fn_1_5448C(local);
        event = (Event *)fn_1_548AC(0xc);
        if (event != 0) {
            event->vtable = fn_1_652F4;
            event->owner = object;
            fn_1_5489C(result, event);
        }
    }
}
/* fzgx:end fn_1_65268 */

/* fzgx:begin fn_1_652F4 */
typedef struct {
    u8 pad_00[0x18];
    s16 unk_18;
    u8 pad_1a[2];
    f32 unk_1c;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    u8 pad_2c[0x28];
    s16 unk_54;
    s16 unk_56;
} fn_1_652F4_EffectData;
typedef struct {
    u8 pad_00[0x120];
    void *unk_120;
} EffectRoot;
typedef struct {
    f32 value;
    f32 value2;
    u8 pad_08[0x34];
    u8 color[4];
} ParticleData;

#pragma opt_common_subs off
void fn_1_652F4(fn_1_652F4_Effect *effect) {
    u8 temp[0xc];
    ParticleData data;
    fn_1_652F4_EffectData *object;
    void *owner;
    register f32 color_scale;
    register f32 scale;
    void *manager;
    s16 level;

    object = effect->unk_08;
    fn_1_867CC(object->unk_18, temp);
    level = *(s16 *)((u8 *)fn_1_868C0((s8)object->unk_18) + 0x3ba);
    owner = fn_1_86254(object->unk_18);
    if (level >= 3 && *(s8 *)((u8 *)owner + 0x475) == -1) {
        return;
    }
    manager = ((EffectRoot *)lbl_1_bss_38458->unk_8)->unk_120;
    lbl_8006D9D8(temp);
    lbl_8006D95C(object->unk_56);
    mathutil_mtxA_rotate_x(object->unk_54);
    memset(&data, 0, 0x40);
    lbl_8006DB74((u8 *)&data + 8);

        scale = (((f32 *)&lbl_1_rodata_2AA0))[0];
        data.value = scale * object->unk_28;
    color_scale = lbl_1_rodata_29AC[0];
    data.color[0] = (u8)(s32)(color_scale * object->unk_1c);
    data.color[1] = (u8)(s32)(color_scale * object->unk_20);
    data.color[2] = (u8)(s32)(color_scale * object->unk_24);
    data.color[3] = 0xff;
    data.value2 = data.value;
    fn_1_9F914(&data, manager);
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_652F4 */

/* fzgx:begin fn_1_65420 */
// fn_1_65420: empty in retail (single blr).
void fn_1_65420(void) {
}
/* fzgx:end fn_1_65420 */

/* fzgx:begin fn_1_65424 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
}
#pragma section code_type ".text"


typedef struct {
    u8 pad_00[0x10];
    s32 unk_10;
} fn_1_65424_EffectObject;

#pragma fp_contract off
void fn_1_65424(fn_1_65424_EffectObject *object) {
    u32 next;

    if (object->unk_10 == 0) {
        next = lbl_1_data_1D628 * 0x41C64E6D + 0x3039;
        lbl_1_data_1D628 = next;
        object->unk_10 = (s32)(60.0f * (0.3f + 0.25f * ((f32)(((0x7FFF) & ((next >> 16)))) / 32767.0f)));
    }
}
#pragma fp_contract reset
/* fzgx:end fn_1_65424 */

/* fzgx:begin fn_1_656C8 */
typedef struct {
    u32 unk_00;
    void (*unk_04)(void);
    void *unk_08;
} EffectEvent;

typedef struct {
    u8 unk_00[0x28];
    f32 unk_28;
    u8 unk_2c[0x10];
    u8 unk_3c[1];
} fn_1_656C8_EffectObject;

// Initializes the effect and queues an event when its embedded state is ready.
void fn_1_656C8(fn_1_656C8_EffectObject *object) {
    void *result;
    EffectEvent *event;

    lbl_8006DCA4();
    if (fn_1_54E34(&object->unk_3c, object->unk_28) != 0) {
        result = fn_1_5448C(&object->unk_3c);
        event = (EffectEvent *)fn_1_548AC(0xc);
        if (event != 0) {
            event->unk_04 = fn_1_65748;
            event->unk_08 = object;
            fn_1_5489C( (void **)(void *)(result), (void **)(void *)(event));
        }
    }
}
/* fzgx:end fn_1_656C8 */

/* fzgx:begin fn_1_65AAC */
// fn_1_65AAC: empty in retail (single blr).
void fn_1_65AAC(void) {
}
/* fzgx:end fn_1_65AAC */

/* fzgx:begin fn_1_65AB0 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
    s = 0.0f;
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 150.0;
    d = 10.0;
    d = 3.0;
}
static const u32 fzgx_pool_table6[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 5.0f;
    d = 1.2;
    d = 0.1;
    s = 10.0f;
    s = 18.0f;
    d = 0.7;
    d = 50.0;
}
static const u32 fzgx_pool_table8[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 19.0f;
    d = 24.0;
    s = 0.7071067690849304f;
}
static const u32 fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 255.0;
    d = 0.9;
    s = 0.004000000189989805f;
    s = 0.0010000000474974513f;
    s = 0.009999999776482582f;
    s = -1.1920928955078125e-07f;
    s = 240.0f;
    s = 100.0f;
    s = 300.0f;
    s = 200.0f;
    s = 10000.0f;
    s = 5000.0f;
    s = 204.0f;
    s = 85.0f;
    s = -0.05000000074505806f;
    s = 4.0f;
    s = -0.05999999865889549f;
    s = -0.5f;
    s = -1.0f;
}
static const u32 fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.2;
    s = 512.0f;
    s = 0.029999999329447746f;
    s = 51.0f;
    s = 88.0f;
    d = -3.0;
    s = 4.5f;
    s = 6.0f;
}
static const u32 fzgx_pool_table14[12] = {0x3F8CCCCD, 0x00000000, 0x3F666666, 0xBF8CCCCD, 0x00000000, 0x3F666666, 0x00000000, 0x00000000, 0xBF333333, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.2000000476837158f;
    s = 50.0f;
    s = 0.02500000037252903f;
    s = 0.800000011920929f;
    s = 0.0625f;
    s = 2.5f;
}
static const u32 fzgx_pool_table16[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -3.0f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.01;
    s = 1.8600000143051147f;
}
static const u32 fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 210.0;
    d = 0.02;
    d = 0.003;
    d = -0.699999988079071;
    d = -0.029999999329447746;
    d = 0.141;
    d = 0.699999988079071;
    d = 1.0;
    d = 0.3;
    d = 0.800000011920929;
    d = 12.0;
    s = -0.8999999761581421f;
    s = 0.07000000029802322f;
    s = 0.6000000238418579f;
    s = 30.0f;
    s = 1.059999942779541f;
    s = 28.0f;
    d = 5.0;
    s = 3.5f;
    s = 180.0f;
}
static const u32 fzgx_pool_table22[2] = {0xFFFFFFFF, 0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 30.0;
    d = 0.03;
    s = 0.9399999976158142f;
    s = -0.07999999821186066f;
}
static const u32 fzgx_pool_table24[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const u32 *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 136.0f;
    s = 0.00800000037997961f;
    s = 0.004545454401522875f;
    s = 0.014285714365541935f;
    s = 2000.0f;
    s = 1000.0f;
    s = 2.0999999046325684f;
}
static const u32 fzgx_pool_table26[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep26(void) { const u32 *volatile cp; cp = fzgx_pool_table26; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime27(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.04;
    d = 0.98;
    d = 0.96;
    d = 0.025;
    d = -1.0;
    d = 0.8;
}
static const u32 fzgx_pool_table28[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep28(void) { const u32 *volatile cp; cp = fzgx_pool_table28; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime29(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.03999999910593033f;
}
static const u32 fzgx_pool_table30[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep30(void) { const u32 *volatile cp; cp = fzgx_pool_table30; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime31(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 2.0;
    s = 7.0f;
}
static const u32 fzgx_pool_table32[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep32(void) { const u32 *volatile cp; cp = fzgx_pool_table32; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

typedef struct {
    u8 pad_00[0x10];
    s32 value_10;
    u8 pad_14[0x18];
    f32 value_2c;
    u8 pad_30[0x84];
    f32 value_b4;
} Fn165AB0Object;

void fn_1_65AB0(Fn165AB0Object *obj) {
    f32 fn_1_65AB0_zero;
    f32 factor;
    struct { f32 value; } result;

    if ((fn_1_65AB0_zero = 0.0f, obj->value_b4 == fn_1_65AB0_zero)) {
        obj->value_b4 = 1.0f;
    }
    if (obj->value_b4 > 1.0f) {
        obj->value_2c = obj->value_2c * obj->value_b4;
        factor = obj->value_b4 / 7.0f;
        if (factor < 1.0f) {
            result.value = 1.0f;
        } else if (factor > 1.2f) {
            result.value = 1.2f;
        } else {
            result.value = factor;
        }
        obj->value_10 = (s32)((f32)obj->value_10 * result.value);
    }
}
/* fzgx:end fn_1_65AB0 */

/* fzgx:begin fn_1_65B58 */
// fn_1_65B58: empty in retail (single blr).
void fn_1_65B58(void) {
}
/* fzgx:end fn_1_65B58 */

/* fzgx:begin fn_1_65B5C noprologue */
typedef int s32;
typedef unsigned char u8;
typedef float f32;
typedef double f64;
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const unsigned long fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const unsigned long fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 150.0;
    d = 10.0;
    d = 3.0;
}
static const unsigned long fzgx_pool_table6[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 5.0f;
    d = 1.2;
    d = 0.1;
    s = 10.0f;
    s = 18.0f;
    d = 0.7;
    d = 50.0;
}
static const unsigned long fzgx_pool_table8[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const unsigned long *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 19.0f;
    d = 24.0;
    s = 0.7071067690849304f;
}
static const unsigned long fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const unsigned long *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 255.0;
    d = 0.9;
    s = 0.004000000189989805f;
    s = 0.0010000000474974513f;
    s = 0.009999999776482582f;
    s = -1.1920928955078125e-07f;
    s = 240.0f;
    s = 100.0f;
    s = 300.0f;
    s = 200.0f;
    s = 10000.0f;
    s = 5000.0f;
    s = 204.0f;
    s = 85.0f;
    s = -0.05000000074505806f;
    s = 4.0f;
    s = -0.05999999865889549f;
    s = -0.5f;
    s = -1.0f;
}
static const unsigned long fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const unsigned long *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.2;
    s = 512.0f;
    s = 0.029999999329447746f;
    s = 51.0f;
    s = 88.0f;
    d = -3.0;
    s = 4.5f;
    s = 6.0f;
}
static const unsigned long fzgx_pool_table14[12] = {0x3F8CCCCD, 0x00000000, 0x3F666666, 0xBF8CCCCD, 0x00000000, 0x3F666666, 0x00000000, 0x00000000, 0xBF333333, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const unsigned long *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.2000000476837158f;
    s = 50.0f;
    s = 0.02500000037252903f;
    s = 0.800000011920929f;
    s = 0.0625f;
    s = 2.5f;
}
static const unsigned long fzgx_pool_table16[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const unsigned long *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = -3.0f;
}
static const unsigned long fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const unsigned long *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.01;
    s = 1.8600000143051147f;
}
static const unsigned long fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const unsigned long *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 210.0;
    d = 0.02;
    d = 0.003;
    d = -0.699999988079071;
    d = -0.029999999329447746;
    d = 0.141;
    d = 0.699999988079071;
    d = 1.0;
    d = 0.3;
    d = 0.800000011920929;
    d = 12.0;
    s = -0.8999999761581421f;
    s = 0.07000000029802322f;
    s = 0.6000000238418579f;
    s = 30.0f;
    s = 1.059999942779541f;
    s = 28.0f;
    d = 5.0;
    s = 3.5f;
    s = 180.0f;
}
static const unsigned long fzgx_pool_table22[2] = {0xFFFFFFFF, 0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const unsigned long *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 30.0;
    d = 0.03;
    s = 0.9399999976158142f;
    s = -0.07999999821186066f;
}
static const unsigned long fzgx_pool_table24[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const unsigned long *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 136.0f;
    s = 0.00800000037997961f;
    s = 0.004545454401522875f;
    s = 0.014285714365541935f;
    s = 2000.0f;
    s = 1000.0f;
    s = 2.0999999046325684f;
}
static const unsigned long fzgx_pool_table26[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep26(void) { const unsigned long *volatile cp; cp = fzgx_pool_table26; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime27(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.04;
    d = 0.98;
    d = 0.96;
    d = 0.025;
    d = -1.0;
    d = 0.8;
}
static const unsigned long fzgx_pool_table28[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep28(void) { const unsigned long *volatile cp; cp = fzgx_pool_table28; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime29(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.03999999910593033f;
}
static const unsigned long fzgx_pool_table30[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep30(void) { const unsigned long *volatile cp; cp = fzgx_pool_table30; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime31(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 2.0;
    s = 7.0f;
}
static const unsigned long fzgx_pool_table32[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep32(void) { const unsigned long *volatile cp; cp = fzgx_pool_table32; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime33(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.9200000137090683;
    d = -0.02;
    s = -0.02500000037252903f;
}
static const unsigned long fzgx_pool_table34[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep34(void) { const unsigned long *volatile cp; cp = fzgx_pool_table34; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

typedef struct EffP {
    s32 pad0[4];
    s32 i10;
    s32 pad14[2];
    f32 f1c, f20, f24, f28, f2c;
    s32 pad30[3];
    f32 f3c, f40, f44, f48, f4c, f50;
    u8 pad54[0xb4 - 0x54];
    f32 fb4;
} EffP;

#pragma opt_dead_assignments off
static inline f64 fn_1_65B5C_operand(f64 right, f64 left) { return left * right; }
void fn_1_65B5C(EffP *p) {
    f32 fzgx_live_;
    f32 fzgx_live;
    f32 one;
    f32 s;
    f32 t;
    p->f48 *= 0.98f;
    p->f4c *= 0.98f;
    p->f50 *= 0.98f;
    p->f3c = p->f3c + p->f48;
    p->f40 = p->f40 + p->f4c;
    p->f44 = p->f44 + p->f50;
    if (p->f28 > 50.0f * (((p->fb4) / 2.0f))) {
        fzgx_live_ = p->f2c;
        p->f2c = fn_1_65B5C_operand((0.9200000137090683), (fzgx_live_));
    }
    p->f28 = p->f28 + p->f2c;
    one = 1.0f;
    if (p->fb4 > one) {
        if (p->i10 < 50) {
            s = one - (one + (f32)(-0.02 * (f64)p->i10));
            fzgx_live = p->f1c;
            p->f1c = fzgx_live * s;
            p->f20 = p->f20 * s;
            p->f24 = p->f24 * s;
        }
    } else if (p->i10 < 40) {
        t = -0.025f * (f32)p->i10;
        s = one - (one + t);
        fzgx_live = p->f1c;
        p->f1c = fzgx_live * s;
        p->f20 = p->f20 * s;
        p->f24 = p->f24 * s;
    }
}
#pragma opt_dead_assignments reset
/* fzgx:end fn_1_65B5C */

/* fzgx:begin fn_1_65E58 */
typedef struct fn_1_65E58_Effect {
    u8 _pad_00[0x10];
    int field_10;
    u8 _pad_14[0x4];
    s16 field_18;
    u8 _pad_1a[0x9e];
} fn_1_65E58_Effect;

void fn_1_65E58(fn_1_65E58_Effect *effect) {
    effect->field_10 = 10;
    fn_1_8636C(effect->field_18, (u8 *)effect + 0xb8);
}
/* fzgx:end fn_1_65E58 */

/* fzgx:begin fn_1_65E88 */
// fn_1_65E88: empty in retail (single blr).
void fn_1_65E88(void) {
}
/* fzgx:end fn_1_65E88 */

/* fzgx:begin fn_1_65E8C noprologue */
#include "types.h"
#include "game/main_rel/car_test_types.h"
#include "game/main_rel/car_types.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
    s = 0.0f;
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 150.0;
    d = 10.0;
    d = 3.0;
}
static const u32 fzgx_pool_table6[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 5.0f;
    d = 1.2;
    d = 0.1;
    s = 10.0f;
    s = 18.0f;
    d = 0.7;
    d = 50.0;
}
static const u32 fzgx_pool_table8[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 19.0f;
    d = 24.0;
    s = 0.7071067690849304f;
}
static const u32 fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 255.0;
    d = 0.9;
    s = 0.004000000189989805f;
    s = 0.0010000000474974513f;
    s = 0.009999999776482582f;
    s = -1.1920928955078125e-07f;
    s = 240.0f;
    s = 100.0f;
    s = 300.0f;
    s = 200.0f;
    s = 10000.0f;
    s = 5000.0f;
    s = 204.0f;
    s = 85.0f;
    s = -0.05000000074505806f;
    s = 4.0f;
    s = -0.05999999865889549f;
    s = -0.5f;
    s = -1.0f;
}
static const u32 fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.2;
    s = 512.0f;
    s = 0.029999999329447746f;
    s = 51.0f;
    s = 88.0f;
    d = -3.0;
    s = 4.5f;
    s = 6.0f;
}
static const u32 fzgx_pool_table14[12] = {0x3F8CCCCD, 0x00000000, 0x3F666666, 0xBF8CCCCD, 0x00000000, 0x3F666666, 0x00000000, 0x00000000, 0xBF333333, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.2000000476837158f;
    s = 50.0f;
    s = 0.02500000037252903f;
    s = 0.800000011920929f;
    s = 0.0625f;
    s = 2.5f;
}
static const u32 fzgx_pool_table16[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -3.0f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.01;
    s = 1.8600000143051147f;
}
static const u32 fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 210.0;
    d = 0.02;
    d = 0.003;
    d = -0.699999988079071;
    d = -0.029999999329447746;
    d = 0.141;
    d = 0.699999988079071;
    d = 1.0;
    d = 0.3;
    d = 0.800000011920929;
    d = 12.0;
    s = -0.8999999761581421f;
    s = 0.07000000029802322f;
    s = 0.6000000238418579f;
    s = 30.0f;
    s = 1.059999942779541f;
    s = 28.0f;
    d = 5.0;
    s = 3.5f;
    s = 180.0f;
}
static const u32 fzgx_pool_table22[2] = {0xFFFFFFFF, 0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 30.0;
    d = 0.03;
    s = 0.9399999976158142f;
    s = -0.07999999821186066f;
}
static const u32 fzgx_pool_table24[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const u32 *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 136.0f;
    s = 0.00800000037997961f;
    s = 0.004545454401522875f;
    s = 0.014285714365541935f;
    s = 2000.0f;
    s = 1000.0f;
    s = 2.0999999046325684f;
}
static const u32 fzgx_pool_table26[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep26(void) { const u32 *volatile cp; cp = fzgx_pool_table26; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime27(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.04;
    d = 0.98;
    d = 0.96;
    d = 0.025;
    d = -1.0;
    d = 0.8;
}
static const u32 fzgx_pool_table28[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep28(void) { const u32 *volatile cp; cp = fzgx_pool_table28; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime29(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.03999999910593033f;
}
static const u32 fzgx_pool_table30[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep30(void) { const u32 *volatile cp; cp = fzgx_pool_table30; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime31(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 2.0;
    s = 7.0f;
}
static const u32 fzgx_pool_table32[6] = {0x00000000, 0x3FED70A3, 0xDE666666, 0xBF947AE1, 0x47AE147B, 0xBCCCCCCD};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep32(void) { const u32 *volatile cp; cp = fzgx_pool_table32; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

typedef struct Effect65E8C_Owner {
    u8 pad_0[0x214];
    u16 active;
} Effect65E8C_Owner;

typedef struct Effect65E8C {
    u8 pad_0[0x10];
    s32 timer;
    u8 pad_14[0x4];
    s16 mtxId;
    u8 pad_1A[0x1E];
    Effect65E8C_Owner *owner;
    Fn183D28Vec3 pos;
    u8 pad_48[0xC];
    s16 spinScale;
    s16 rotY;
    s16 rotZ;
    s16 velX;
    s16 velY;
    s16 velZ;
    u8 pad_60[0x58];
    u8 unk_B8[1];
} Effect65E8C;

extern u32 lbl_801A66A0;
extern f32 lbl_8006D188(s32);
extern void lbl_8006DC6C(void *);
extern void fn_1_862D4(int, Triple *);
extern void fn_1_8636C(int, void *);
extern void lbl_8006E1B0(Fn183D28Vec3 *, Fn183D28Vec3 *);
extern void lbl_8006DB74(void *);

void fn_1_65E8C(Effect65E8C *eff) {
    s32 moving;
    s32 t;
    f32 bob;
    u8 mtx[0x30];
    Fn183D28Vec3 pos;
    Fn183D28Vec3 arg;
    Fn183D28Vec3 v;

    moving = 0;
    if (eff->owner->active != 0) {
        t = eff->timer;
        moving = 1;
        if (t < 20) {
            eff->timer = t + 2;
        } else {
            eff->timer = t + 1;
        }
    }
    fn_1_862D4(eff->mtxId, (Triple *)&pos);
    fn_1_8636C(eff->mtxId, mtx);
    if (moving != 0) {
        bob = 0.3 * lbl_8006D188((s32)(182.04444885253906f * (f32)lbl_801A66A0));
        lbl_8006DC6C(mtx);
        /* set the current matrix's translation */
        {
            f32 fzgx_lc0_z;
            f32 fzgx_lc0_y;
            f32 fzgx_lc0_x;
            fzgx_lc0_x = *(volatile f32 *)&(pos.x);  /* volatile: keeps the first-stored locked-cache value loaded in source order (retail x/y/z FPR order) */
            fzgx_lc0_y = pos.y;
            fzgx_lc0_z = pos.z;
            *(f32 *)(0xE0000000 + 0x0C) = fzgx_lc0_x;
            *(f32 *)(0xE0000000 + 0x1C) = fzgx_lc0_y;
            *(f32 *)(0xE0000000 + 0x2C) = fzgx_lc0_z;
        }
        {
            Fn183D28Vec3 init = {0.0f, 0.0f, 0.0f};
            v = init;
        }
        v.y = 5.0 + bob;
        arg = v;
        (void) arg;  /* fzgx: keeps the web at its definition */
        lbl_8006E1B0(&arg, &eff->pos);
    } else {
        eff->velX *= 0.98;
        eff->velY *= 0.98;
        eff->velZ *= 0.98;
    }
    eff->spinScale = 768.0f * lbl_8006D188((s32)(182.04444885253906f * (f32)lbl_801A66A0));
    eff->rotY += eff->velY;
    eff->rotZ += eff->velZ;
    lbl_8006DB74(eff->unk_B8);
}
/* fzgx:end fn_1_65E8C */

/* fzgx:begin fn_1_660EC noprologue */
#include "dolphin/types.h"
#include "game/main_rel/camera_types.h"
#include "rel/main_rel/effect.h"

typedef struct {
    u8 pad_0[0xec];
    f32 matrix[3][4];
} Fn660ECModel;
typedef struct {
    u8 pad_0[0x10];
    s32 timer;
    u8 pad_14[0x24];
    Fn660ECModel *model;
    CamEntry position;
} Fn660ECObject;
typedef struct {
    u8 pad_0[0x1f0];
    void *model;
} Fn660ECManager;
typedef struct { f32 m[3][4]; } Fn660ECMatrix;

extern u32 lbl_801A66A0;
extern void lbl_8006D7F4(f32, f32, f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006D9D8(CamEntry *);
extern void lbl_8006DFC4(void *);
extern void mathutil_mtxA_rotate_y(s32);
extern void mathutil_mtxA_rotate_x(s32);
extern void mathutil_mtxA_rotate_z(s32);
extern void lbl_8006E14C(f32);
extern void fn_1_55FC4(f32);
extern void fn_80072558(void);
extern void fn_1_55FF0(f32);
extern u32 fn_1_56018(s32);
extern void fn_1_560F0(s32, void *);
extern void fn_1_55210(void *);

extern void fzgx_pool_f32(f32);
extern void fzgx_pool_f64(f64);
#pragma section code_type ".fzgxpool"
void fzgx_pool_primer(void)
{
    fzgx_pool_f32(60.0f);
    fzgx_pool_f32(0.1f);
    fzgx_pool_f32(32767.0f);
    fzgx_pool_f32(0.05f);
    fzgx_pool_f64(0.07);
    fzgx_pool_f32(20000.0f);
    fzgx_pool_f64(4503599627370496.0);
    fzgx_pool_f32(1.0f);
    fzgx_pool_f32(-0.03f);
    fzgx_pool_f64(15.0);
    fzgx_pool_f64(4503601774854144.0);
    fzgx_pool_f64(1.5);
    fzgx_pool_f64(0.5);
    fzgx_pool_f32(0.0f);
    fzgx_pool_f32(0.5f);
}
#pragma section code_type ".text"

const u32 fzgx_pool_table_58[218] = {
0x41000000, 0x437F0000, 0x41700000, 0x3E4CCCCD, 0x3DA3D70A, 0x3E800000, 0x3F7AE148, 0x3F7D70A4, 0x42200000, 0x41A00000, 0x3FC00000, 0x3EE66666, 3221225472U /* -2.0f */, 0x3DAAAAAB, 0x3E19999A, 0x3E000000, 0xBECCCCCD, 0xBE99999A, 0x40000000, 0x437A0000, 0x3FE33333, 0x33333333, 0x3FD99999, 0x9999999A, 0x3E99999A, 0xBB83126F, 0x3C888889, 0x47800000, 0x45800000, 0x3F75C28F, 0x3ECCCCCD, 0x3D4ED917, 0x3D50E560, 0x3F733333, 0x3F666666, 0x00000000, 0x4062C000, 0x00000000, 0x40240000, 0x00000000, 0x40080000, 0x00000000, 0x00000000, 0x3DCCCCCD, 3222903194U /* -2.4f */, 0x40A00000, 0x3FF33333, 0x33333333, 0x3FB99999, 0x9999999A, 0x41200000, 0x41900000, 0x3FE66666, 0x66666666, 0x40490000, 0x00000000, 0x00000000, 0x3DCCCCCD, 3222903194U /* -2.4f */, 0x41980000, 0x40380000, 0x00000000, 0x3F3504F3, 0x00000000, 0x00000000, 0x00000000, 0x406FE000, 0x00000000, 0x3FECCCCC, 0xCCCCCCCD, 0x3B83126F, 0x3A83126F, 0x3C23D70A, 0xB4000000, 0x43700000, 0x42C80000, 0x43960000, 0x43480000, 0x461C4000, 0x459C4000, 0x434C0000, 0x42AA0000, 0xBD4CCCCD, 0x40800000, 0xBD75C28F, 0xBF000000, 0xBF800000, 0x00000000, 0x3FC99999, 0x9999999A, 0x44000000, 0x3CF5C28F, 0x424C0000, 0x42B00000, 3221749760U /* -3.0 double, high word */, 0x00000000, 0x40900000, 0x40C00000, 0x3F8CCCCD, 0x00000000, 0x3F666666, 0xBF8CCCCD, 0x00000000, 0x3F666666, 0x00000000, 0x00000000, 0xBF333333, 0x00000000, 0x00000000, 0x00000000, 0x3F99999A, 0x42480000, 0x3CCCCCCD, 0x3F4CCCCD, 0x3D800000, 0x40200000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 3225419776U /* -3.0f */, 0x00000000, 0x3F847AE1, 0x47AE147B, 0x3FEE147B, 0x00000000, 0x406A4000, 0x00000000, 0x3F947AE1, 0x47AE147B, 0x3F689374, 0xBC6A7EFA, 0xBFE66666, 0x60000000, 0xBF9EB851, 0xE0000000, 0x3FC20C49, 0xBA5E353F, 0x3FE66666, 0x60000000, 0x3FF00000, 0x00000000, 0x3FD33333, 0x33333333, 0x3FE99999, 0xA0000000, 0x40280000, 0x00000000, 0xBF666666, 0x3D8F5C29, 0x3F19999A, 0x41F00000, 0x3F87AE14, 0x41E00000, 0x40140000, 0x00000000, 0x40600000, 0x43340000, 0xFFFFFFFF, 0xFFFFFFFF, 0x403E0000, 0x00000000, 0x3F9EB851, 0xEB851EB8, 0x3F70A3D7, 0xBDA3D70A, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x43080000, 0x3C03126F, 0x3B94F209, 0x3C6A0EA1, 0x44FA0000, 0x447A0000, 0x40066666, 0x00000000, 0x00000000, 0x00000000, 0x3FA47AE1, 0x47AE147B, 0x3FEF5C28, 0xF5C28F5C, 0x3FEEB851, 0xEB851EB8, 0x3F999999, 0x9999999A, 0xBFF00000, 0x00000000, 0x3FE99999, 0x9999999A, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xBD23D70A, 0x00000000, 0x40000000, 0x00000000, 0x40E00000, 0x00000000, 0x3FED70A3, 0xDE666666, 0xBF947AE1, 0x47AE147B, 0xBCCCCCCD, 0x00000000, 0x00000000, 0x00000000, 0x43360B61, 0x44400000
};

void fn_1_660EC(Fn660ECObject *obj)
{
    Fn660ECMatrix mtx;
    f32 alpha;
    Fn660ECModel *model = obj->model;
    void *drawModel;

    if (obj->timer < 20) {
        alpha = 0.05f * (f32)obj->timer;
    } else {
        alpha = 1.0f;
    }
    lbl_8006D7F4((f32)(lbl_801A66A0 % 30) / 29.0f, 0.0f, 0.0f);
    lbl_8006DB74(&mtx);
    drawModel = ((Fn660ECManager *)lbl_1_bss_38458->unk_8)->model;
    lbl_8006D9D8(&obj->position);
    lbl_8006DFC4(&model->matrix);
    mathutil_mtxA_rotate_y(*(s16 *)((u8 *)obj + 0x56));
    mathutil_mtxA_rotate_x(*(s16 *)((u8 *)obj + 0x54));
    mathutil_mtxA_rotate_z(*(s16 *)((u8 *)obj + 0x58));
    lbl_8006E14C(0.5f);
    fn_1_55FC4(0.5f);
    fn_80072558();
    fn_1_55FF0(alpha);
    fn_1_56018(1);
    fn_1_560F0(0, &mtx);
    fn_1_55210(drawModel);
    fn_1_56018(0);
}
/* fzgx:end fn_1_660EC */

/* fzgx:begin fn_1_66254 */
typedef struct {
    u8 pad[0x28];
    f32 field_28;
    f32 field_2c;
} fn_1_66254_output;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 150.0;
    d = 10.0;
    d = 3.0;
}
static const u32 fzgx_pool_table6[2] = {0x00000000, 0x3DCCCCCD};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -2.4000000953674316f;
    s = 5.0f;
    d = 1.2;
    d = 0.1;
    s = 10.0f;
    s = 18.0f;
    d = 0.7;
    d = 50.0;
}
static const u32 fzgx_pool_table8[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 19.0f;
    d = 24.0;
    s = 0.7071067690849304f;
}
static const u32 fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 255.0;
    d = 0.9;
    s = 0.004000000189989805f;
    s = 0.0010000000474974513f;
    s = 0.009999999776482582f;
}
static const u32 fzgx_pool_table12[1] = {0xB4000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 240.0f;
    s = 100.0f;
    s = 300.0f;
    s = 200.0f;
    s = 10000.0f;
    s = 5000.0f;
    s = 204.0f;
    s = 85.0f;
    s = -0.05000000074505806f;
    s = 4.0f;
    s = -0.05999999865889549f;
    s = -0.5f;
    s = -1.0f;
}
static const u32 fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.2;
    s = 512.0f;
    s = 0.029999999329447746f;
    s = 51.0f;
    s = 88.0f;
    d = -3.0;
    s = 4.5f;
    s = 6.0f;
    s = 1.100000023841858f;
}
static const u32 fzgx_pool_table16[2] = {0x00000000, 0x3F666666};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -1.100000023841858f;
}
static const u32 fzgx_pool_table18[4] = {0x00000000, 0x3F666666, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.699999988079071f;
}
static const u32 fzgx_pool_table20[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.2000000476837158f;
    s = 50.0f;
    s = 0.02500000037252903f;
    s = 0.800000011920929f;
    s = 0.0625f;
    s = 2.5f;
}
static const u32 fzgx_pool_table22[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -3.0f;
}
static const u32 fzgx_pool_table24[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const u32 *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.01;
    s = 1.8600000143051147f;
}
static const u32 fzgx_pool_table26[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep26(void) { const u32 *volatile cp; cp = fzgx_pool_table26; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime27(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 210.0;
    d = 0.02;
    d = 0.003;
    d = -0.699999988079071;
    d = -0.029999999329447746;
    d = 0.141;
    d = 0.699999988079071;
    d = 1.0;
    d = 0.3;
    d = 0.800000011920929;
    d = 12.0;
    s = -0.8999999761581421f;
    s = 0.07000000029802322f;
    s = 0.6000000238418579f;
    s = 30.0f;
    s = 1.059999942779541f;
    s = 28.0f;
    d = 5.0;
    s = 3.5f;
    s = 180.0f;
}
#pragma section code_type ".text"
void fn_1_66254(fn_1_66254_output *output) {
    u32 *state;
    u32 seed;
    u32 value;
    f32 coordinate;
    f32 field_2c;
    f32 field_28;

    state = &lbl_1_data_1D628;
    seed = *state;
    value = seed * 0x41c64e6d;
    value += 0x3039;
    coordinate = 0.8f + (f32)(0.2f * ((f32)((value >> 16) & 0x7fff) / 32767.0f));
    *state = value;
    field_2c = 3.5f * coordinate;
    field_28 = 0.5f * coordinate;
    output->field_2c = field_2c;
    output->field_28 = field_28;
}
/* fzgx:end fn_1_66254 */

/* fzgx:begin fn_1_662D4 */
// fn_1_662D4: empty in retail (single blr).
void fn_1_662D4(void) {
}
/* fzgx:end fn_1_662D4 */

/* fzgx:begin fn_1_67414 */
struct fn_1_67414_Arg0 {
    u8 pad_0[0x10];
    u32 unk_10;
    u8 pad_14[0xa0];
    f32 unk_b4;
};

void fn_1_67414(struct fn_1_67414_Arg0 *arg0) {
    // Volatile preserves the retail load-after-store ordering for the pooled value.
    volatile const f32 *value = (volatile const f32 *)&lbl_1_rodata_2954;
    arg0->unk_10 = 30;
    arg0->unk_b4 = *value;
}
/* fzgx:end fn_1_67414 */

/* fzgx:begin fn_1_6742C */
// fn_1_6742C: empty in retail (single blr).
void fn_1_6742C(void) {
}
/* fzgx:end fn_1_6742C */

/* fzgx:begin fn_1_67430 noprologue */
#include "dolphin/types.h"
#include "game/main_rel/car_types.h"
#include "game/main_rel/car_test_types.h"
#include "psvec.h"

extern const f64 lbl_1_rodata_2950[];
extern u32 fn_1_86514(int);
extern void fn_1_862D4(int, Triple *);
extern void fn_1_8636C(int, void *);
extern void *lbl_8006DC6C(void *);
extern void lbl_8006E1B0(Fn183D28Vec3 *, Fn183D28Vec3 *);

typedef struct Fn167430 {
    u8 pad00[0x10];
    s32 state;
    u8 pad14[4];
    s16 id;
    u8 pad1A[0xE];
    f32 value;
    f32 target;
    u8 pad30[0xC];
    Fn183D28Vec3 position;
    Fn183D28Vec3 velocity;
    u8 pad54[0x40];
    Fn183D28Vec3 offset;
    u8 padA0[0x14];
    f32 alpha;
} Fn167430;

void fn_1_67430(Fn167430 *arg0) {
    const f64 *pool = (const f64 *)&lbl_1_rodata_2950;
    f32 matrix[3][4];
    Fn183D28Vec3 position;
    f32 z, y, x;
    f64 one, rate;
    f64 delta, damping;
    f32 value;

    if (!((fn_1_86514(arg0->id) >> 29) & 1)) {
        arg0->state = 1;
    }
    fn_1_862D4(arg0->id, (Triple *)&position);
    fn_1_8636C(arg0->id, matrix);
    z = arg0->velocity.x;
    damping = pool[0x340 / 8];
    arg0->velocity.x = z * damping;
    arg0->velocity.y *= damping;
    arg0->velocity.z *= damping;
    psvec_add(&arg0->offset, &arg0->velocity, &arg0->offset);
    lbl_8006DC6C(matrix);
    /* Volatile preserves the locked-cache translation-column load order. */
    x = *(volatile f32 *)&position.x;
    y = position.y;
    z = position.z;
    /* The current matrix occupies the hardware locked cache at 0xE0000000. */
    *(f32 *)(0xE0000000 + 0x0C) = x;
    *(f32 *)(0xE0000000 + 0x1C) = y;
    *(f32 *)(0xE0000000 + 0x2C) = z;
    lbl_8006E1B0(&arg0->offset, &arg0->position);
    value = arg0->value;
    delta = pool[0x260 / 8] * (arg0->target - value);
    arg0->value = value + delta;
    value = arg0->alpha;
    delta = pool[0x408 / 8] * (pool[0x290 / 8] - value);
    arg0->alpha = value + delta;
}
/* fzgx:end fn_1_67430 */

/* fzgx:begin fn_1_6755C */
typedef struct {
    u8 pad_0[0x18];
    s16 unk_18;
    u8 pad_1a[2];
    f32 unk_1c;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    u8 pad_2c[0x88];
    f32 unk_b4;
} FnObj_6755C;

typedef struct {
    u8 pad_0[0x120];
    u32 unk_120;
} Root_6755C;

void fn_1_6755C(FnObj_6755C *obj) {
    u8 temp[0x30];
    u8 data[0x40];
    f32 f1;
    f32 f0;
    f32 f3;
    f32 f2;
    Root_6755C *root;
    u32 manager;

    root = (Root_6755C *)(u32)lbl_1_bss_38458->unk_8;
    manager = root->unk_120;
    fn_1_8636C(obj->unk_18, temp, (u32)root);
    lbl_8006D9D8((u8 *)obj + 0x3c);
    lbl_8006DFC4(temp);
    lbl_8006D95C(0);
    mathutil_mtxA_rotate_x(0x4000);
    memset(data, 0, 0x40);
    lbl_8006DB74(data + 8);

    f3 = (((f32 *)&lbl_1_rodata_2AA0))[0] * obj->unk_28;
    *(f32 *)(data + 0) = f3;
    f2 = lbl_1_rodata_29AC[0];
    f1 = obj->unk_b4;
    f0 = obj->unk_1c;
    f0 = f2 * f0;
    f0 = f0 * f1;
    data[0x3c] = (u8)f0;
    f0 = obj->unk_20;
    f0 = f2 * f0;
    f0 = f0 * f1;
    data[0x3d] = (u8)f0;
    f0 = obj->unk_24;
    f0 = f2 * f0;
    data[0x3f] = 0xff;
    *(f32 *)(data + 4) = f3;
    f0 = f0 * f1;
    data[0x3e] = (u8)f0;
    fn_1_9F914(data, (const void *)(u32)(manager));
}
/* fzgx:end fn_1_6755C */

/* fzgx:begin fn_1_6766C */
typedef struct {
    u8 padding[0xb4];
    f32 value;
} Fn6766CObject;

void fn_1_6766C(Fn6766CObject *object) {
    object->value = lbl_1_rodata_2978[0];
}
/* fzgx:end fn_1_6766C */

/* fzgx:begin fn_1_6767C */
// fn_1_6767C: empty in retail (single blr).
void fn_1_6767C(void) {
}
/* fzgx:end fn_1_6767C */

/* fzgx:begin fn_1_67E94 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
}
#pragma section code_type ".text"


static inline f32 pool_pad(u32 sel) {
    switch (sel) {
    case 0: return 1.0f;
    case 1: return 2.0f;
    case 2: return 3.0f;
    case 3: return 4.0f;
    }
    return 0.0f;
}

void fn_1_67E94(u8 *object) {
    u32 value;

    if (*(s32 *)(object + 0x10) == 0) {
        value = lbl_1_data_1D628 * 0x41c64e6d + 0x3039;
        lbl_1_data_1D628 = value;
        *(s32 *)(object + 0x10) = (s32)(60.0f *
            (0.2f + (f32)((value & 0x7fff8000) >> 16) / 32767.0f));
    } else {
        pool_pad(value);
    }
    *(u16 *)(object + 0xae) = 0;
}
/* fzgx:end fn_1_67E94 */

/* fzgx:begin fn_1_67F20 pool noprologue */
#include "dolphin/types.h"

/* Shared literal-pool primer. Volatile stores preserve literal emission order;
 * hexadecimal initializers below are IEEE-754 data words, not addresses. */
#pragma section code_type ".fzgxpool"
const u32 fzgx_fn_1_67F20_pool_prefix[] = {
    0x42700000, 0x3DCCCCCD, 0x46FFFE00
};
/* Volatile writes preserve shared literal-pool emission order. */
void fzgx_fn_1_67F20_pool_prime0(volatile f32 *p) { *p = 0.05f; }
const u32 fzgx_fn_1_67F20_pool_gap0[] = {
    0x3FB1EB85, 0x1EB851EC, 0x469C4000, 0x00000000,
    0x43300000, 0x00000000, 0x3F800000, 0xBCF5C28F,
    0x402E0000, 0x00000000
};
/* Volatile writes preserve shared literal-pool emission order. */
void fzgx_fn_1_67F20_pool_prime1(volatile f64 *p) { *p = 4503601774854144.0; }
const u32 fzgx_fn_1_67F20_pool_gap1[] = {
    0x3FF80000, 0x00000000, 0x3FE00000, 0x00000000,
    0x00000000, 0x3F000000, 0x41000000, 0x437F0000,
    0x41700000, 0x3E4CCCCD, 0x3DA3D70A, 0x3E800000,
    0x3F7AE148, 0x3F7D70A4, 0x42200000, 0x41A00000,
    0x3FC00000, 0x3EE66666, 3221225472U, 0x3DAAAAAB,
    0x3E19999A, 0x3E000000, 0xBECCCCCD, 0xBE99999A,
    0x40000000, 0x437A0000, 0x3FE33333, 0x33333333,
    0x3FD99999, 0x9999999A, 0x3E99999A, 0xBB83126F,
    0x3C888889, 0x47800000, 0x45800000, 0x3F75C28F,
    0x3ECCCCCD, 0x3D4ED917, 0x3D50E560, 0x3F733333
};
/* Volatile writes preserve shared literal-pool emission order. */
void fzgx_fn_1_67F20_pool_prime2(volatile f32 *p) { *p = 0.9f; }
const u32 fzgx_fn_1_67F20_pool_gap2[] = {
    0x00000000, 0x4062C000, 0x00000000,
    0x40240000, 0x00000000, 0x40080000, 0x00000000,
    0x00000000, 0x3DCCCCCD, 3222903194U, 0x40A00000,
    0x3FF33333, 0x33333333, 0x3FB99999, 0x9999999A,
    0x41200000, 0x41900000, 0x3FE66666, 0x66666666,
    0x40490000, 0x00000000, 0x00000000, 0x3DCCCCCD,
    3222903194U, 0x41980000, 0x40380000, 0x00000000,
    0x3F3504F3, 0x00000000, 0x00000000, 0x00000000,
    0x406FE000, 0x00000000, 0x3FECCCCC, 0xCCCCCCCD,
    0x3B83126F
};
/* Volatile writes preserve shared literal-pool emission order. */
void fzgx_fn_1_67F20_pool_prime3(volatile f32 *p)
{
    *p = 0.001f;
    *p = 0.01f;
}

#pragma section code_type ".text"

typedef struct Fn167F20State {
    u8 pad00[0x10];
    s32 age;
    u8 pad14[0x8];
    f32 scaleX;
    f32 scaleY;
    f32 scaleZ;
    f32 value;
    f32 targetValue;
    u8 pad30[0xC];
    f32 x;
    f32 y;
    f32 z;
    f32 vx;
    f32 vy;
    f32 vz;
    u8 pad54[0x34];
    f32 blend;
    f32 targetBlend;
    u8 pad90[0x1C];
    s16 angularVelocity;
    s16 angle;
} Fn167F20State;

static inline f32 fn_1_67F20_scale(f32 x, f32 factor)
{
    return x * factor;
}

void fn_1_67F20(Fn167F20State *p)
{
    p->vx *= 0.9f;
    p->vy *= 0.9f;
    p->vz *= 0.9f;
    p->angularVelocity *= 0.9f;
    p->vx += 0.001f;
    p->x += p->vx;
    p->y += p->vy;
    p->z += p->vz;
    p->angle += p->angularVelocity;
    p->blend += (f32)(0.05f * (p->targetBlend - p->blend));
    p->value += (f32)(0.01f * (p->targetValue - p->value));
    if (p->age < 30) {
        p->scaleX = fn_1_67F20_scale(-p->scaleX, 0.01f);
        p->scaleY = fn_1_67F20_scale(-p->scaleY, 0.01f);
        p->scaleZ = fn_1_67F20_scale(-p->scaleZ, 0.01f);
    }
}
/* fzgx:end fn_1_67F20 */

/* fzgx:begin fn_1_68054 */
typedef struct fn_1_68054_EffectObject {
    u8 pad0[0x28];
    f32 value;
    u8 pad1[0x10];
    u8 subobject;
} fn_1_68054_EffectObject;

typedef struct fn_1_68054_EffectEntry {
    u8 pad0[4];
    void (*callback)(void);
    fn_1_68054_EffectObject *owner;
} fn_1_68054_EffectEntry;

// Advances the effect and queues its completion callback when it finishes.
void fn_1_68054(fn_1_68054_EffectObject *effect) {
    f32 progress;
    void *source;
    fn_1_68054_EffectEntry *completion;

    progress = effect->value / lbl_1_rodata_2A70[0];
    lbl_8006DCA4();

    if (fn_1_54E34(&effect->subobject, progress) == 0) {
        return;
    }

    source = fn_1_5448C(&effect->subobject);
    completion = (fn_1_68054_EffectEntry *)fn_1_548AC(0xc);
    if (completion == 0) {
        return;
    }

    completion->callback = fn_1_64388;
    completion->owner = effect;
    fn_1_5489C( (void **)(void *)(source), (void **)(void *)(completion));
}
/* fzgx:end fn_1_68054 */

/* fzgx:begin fn_1_680F4 */
// fn_1_680F4: empty in retail (single blr).
void fn_1_680F4(void) {
}
/* fzgx:end fn_1_680F4 */
