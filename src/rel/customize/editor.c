#include "types.h"
#include "rel/customize/globals.h"
#include "rel/customize/editor.h"


extern struct Obj *fn_3_14074(void);
extern u8 lbl_3_bss_A2408[8];
extern void *fn_1_45D0(void *, u32, char *, u32);
extern void fn_80008BEC(void *, u32, u32);
extern void fn_3_17100(void);
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32, u32, char *, int);
extern const f32 lbl_3_rodata_5FC[3];

/* fzgx:begin fn_3_1552C */
struct Obj {
    u8 pad[0x10];
    u16 width;
    u16 height;
};

void fn_3_1552C(void) {
    struct Obj *ptr;

    ptr = fn_3_14074();
    ptr->width = 0x20;
    ptr->height = 0x20;
    *(u32 *)((*(u8 (*)[28])&lbl_3_bss_A23EC) + 0xC) = 0x20000000;
    *(u8 *)((*(u8 (*)[28])&lbl_3_bss_A23EC) + 0x11) = 1;
    *(u8 *)((*(u8 (*)[28])&lbl_3_bss_A23EC) + 0x16) = 0;
    *(u8 *)((*(u8 (*)[28])&lbl_3_bss_A23EC) + 0x0) = 0;
    *(u32 *)((*(u8 (*)[28])&lbl_3_bss_A23EC) + 0x4) =
        (u32)fn_1_45D0((*(void * *)&lbl_801A6410), 0x2000, (*(char (*)[9])&lbl_3_data_35B0), 0x4A);
    *(u32 *)((*(u8 (*)[28])&lbl_3_bss_A23EC) + 0x8) =
        (u32)fn_1_45D0((*(void * *)&lbl_801A6410), 0x2000, (*(char (*)[9])&lbl_3_data_35B0), 0x4B);
    fn_80008BEC(*(void **)((*(u8 (*)[28])&lbl_3_bss_A23EC) + 0x4), 0, 0x2000);
    fn_80008BEC(*(void **)((*(u8 (*)[28])&lbl_3_bss_A23EC) + 0x8), 0, 0x2000);
    *lbl_3_bss_A2408 = 0;
}
/* fzgx:end fn_3_1552C */

/* fzgx:begin fn_3_1560C */
void fn_3_1560C(void) {
    *(u32 *)((*(u8 (*)[28])&lbl_3_bss_A23EC) + 0xC) = (u32)1 << 31;
}
/* fzgx:end fn_3_1560C */

/* fzgx:begin fn_3_15620 */
void fn_3_15620(void) {
    *(u8 *)((*(u8 (*)[28])&lbl_3_bss_A23EC) + 0x10) = 0;
    *(u32 *)((*(u8 (*)[28])&lbl_3_bss_A23EC) + 0xc) = 0x40000000;
}
/* fzgx:end fn_3_15620 */

/* fzgx:begin fn_3_1563C */
void fn_3_1563C(void) {
    fn_1_46B4(lbl_801A6410, *(u32 *)((*(u8 (*)[28])&lbl_3_bss_A23EC) + 0x4),
              (*(char (*)[9])&lbl_3_data_35B0), 0x71);
    fn_1_46B4(lbl_801A6410, *(u32 *)((*(u8 (*)[28])&lbl_3_bss_A23EC) + 0x8),
              (*(char (*)[9])&lbl_3_data_35B0), 0x72);
}
/* fzgx:end fn_3_1563C */

/* fzgx:begin fn_3_156A8 */
void fn_3_156A8(void) {
    u8 value = ((*(u8 (*)[28])&lbl_3_bss_A23EC)[0x11] & 0x7f) << 1;
    (*(u8 (*)[28])&lbl_3_bss_A23EC)[0x11] = value;
    if (value > 6) {
        (*(u8 (*)[28])&lbl_3_bss_A23EC)[0x11] = 1;
    }
}
/* fzgx:end fn_3_156A8 */

/* fzgx:begin fn_3_156D0 */
struct Obj {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    s16 unk_C;
    s16 unk_E;
    s16 unk_10;
    s16 unk_12;
    u8 pad_14[8];
    u8 unk_1C;
    u8 pad_1D[3];
    void *unk_20;
};
extern struct Obj *fn_3_14074(void);
extern u8 fn_3_19C94(void);
extern void fn_3_169B8(void);
extern u32 fn_3_17820(void);
extern void fn_3_1445C(void);
extern u8 fn_3_14600(void);
extern u32 fn_3_19F7C(void *, s32, s32);
extern void fn_3_17830(void);
extern void fn_3_177AC(void *);
extern void fn_3_16FD0(void *);
extern void fn_3_19CA4(void);
extern void fn_3_19CCC(void);
extern void fn_80008BEC(void *, u32, u32);
extern void DCInvalidateRange(void *, u32);
extern void DCStoreRange(void *, u32);
extern void fn_1_A2D84(u32);
extern u8 lbl_1_bss_9F8[];
struct Input { u16 unk_0; u8 pad_2[18]; };

typedef void (*EditorFunc)(struct Obj *);
#define BUF ((void **)&lbl_3_bss_A23EC.unk_4)[(lbl_3_bss_A23EC.unk_0 + 1) % 2]
#define CALL(n) (((EditorFunc *)&lbl_3_data_3738)[n])(obj)
#define INPUT(off) (((u16 *)(lbl_1_bss_9F8 + (off)))[state.ptr->unk_12 * 10])
#define BIT(off, n) ((INPUT(off) >> (n)) & 1)

void fn_3_156D0(void) {
    struct Obj *obj;
    struct { Obj_3_bss_A23EC *ptr; } state;
    void *saved;
    u32 color;
    u32 copy;
    obj = fn_3_14074();
    fn_80008BEC(BUF, 0, 0x2000);
    if (!(lbl_3_bss_A23EC.unk_C & 0x20000000)) {
        if (fn_3_19C94() != 9 && fn_3_19C94() != 10)
            fn_3_169B8();
        else
            obj->unk_1C = fn_3_19C94();
        if ((((u16 *)(lbl_1_bss_9F8 + 8))[(state.ptr = &lbl_3_bss_A23EC)->unk_12 * 10] >> 8 & 1) && (lbl_3_bss_A23EC.unk_C & 0x40000000)) {
            obj = fn_3_14074();
            saved = obj->unk_20;
            obj->unk_20 = BUF;
            obj->unk_8 = fn_3_17820();
            CALL(0);
            obj->unk_20 = saved;
            lbl_3_bss_A23EC.unk_C = 0x80000000;
            return;
        }
        /* Sample the controller index again for the held-button state. */
        if (((((struct Input *)lbl_1_bss_9F8)[((volatile Obj_3_bss_A23EC *)state.ptr)->unk_12].unk_0 >> 8) & 1) && (lbl_3_bss_A23EC.unk_C & 0x80000000)) {
            switch (obj->unk_1C) {
            case 1:
                obj->unk_8 = fn_3_17820();
                CALL(obj->unk_1C);
                if (lbl_3_bss_A23EC.unk_16 > 39) {
                    obj->unk_0 |= 0x04000000;
                    fn_3_1445C();
                    lbl_3_bss_A23EC.unk_16 = 0;
                } else if (!fn_3_14600()) {
                    lbl_3_bss_A23EC.unk_16++;
                }
                break;
            case 0:
                obj->unk_8 = fn_3_17820();
                CALL(obj->unk_1C);
                if (lbl_3_bss_A23EC.unk_16 > 39) {
                    obj->unk_0 |= 0x04000000;
                    fn_3_1445C();
                    lbl_3_bss_A23EC.unk_16 = 0;
                } else if (!fn_3_14600()) {
                    lbl_3_bss_A23EC.unk_16++;
                }
                return;
            }
        }
        if (BIT(8, 8) && (lbl_3_bss_A23EC.unk_C & 0x80000000)) {
            obj->unk_8 = fn_3_17820();
            switch (obj->unk_1C) {
            case 2:
                CALL(obj->unk_1C);
                fn_3_1445C();
                break;
            case 3: case 4: case 5: case 7: case 8:
                if (!lbl_3_bss_A23EC.unk_10) {
                    obj->unk_C = obj->unk_10;
                    obj->unk_E = obj->unk_12;
                    lbl_3_bss_A23EC.unk_10 = 1;
                } else {
                    lbl_3_bss_A23EC.unk_10 = 0;
                    DCInvalidateRange(BUF, 0x2000);
                    CALL(obj->unk_1C);
                    DCStoreRange(BUF, 0x2000);
                    fn_3_1445C();
                }
                break;
            }
        }
        if (obj->unk_1C == 9) {
            if ((INPUT(8) & 1) || (INPUT(10) & 1)) obj->unk_4 |= 0x20000000;
            if (BIT(8, 1) || BIT(10, 1)) obj->unk_4 |= 0x10000000;
            CALL(fn_3_19C94());
        }
        if (obj->unk_1C == 10) {
            if ((INPUT(8) & 1) || (INPUT(10) & 1)) obj->unk_4 |= 0x20000000;
            if (BIT(8, 1) || BIT(10, 1)) obj->unk_4 |= 0x10000000;
            if (BIT(8, 3) || BIT(10, 3)) obj->unk_4 |= 0x80000000;
            if (BIT(8, 2) || BIT(10, 2)) obj->unk_4 |= 0x40000000;
            CALL(fn_3_19C94());
        }
    }
    if ((((u16 *)(lbl_1_bss_9F8 + 8))[(state.ptr = &lbl_3_bss_A23EC)->unk_12 * 10] >> 10 & 1)) {
        color = fn_3_19F7C(obj->unk_20, obj->unk_10, obj->unk_12);
        obj->unk_8 = color;
        if (((u8 *)&color)[3]) {
            fn_3_17830();
            copy = color;
            fn_3_177AC(&copy);
        }
    }
    switch (obj->unk_1C) {
    case 3: case 4: case 5: case 7: case 8:
        if (lbl_3_bss_A23EC.unk_10) {
            saved = obj->unk_20;
            obj->unk_20 = BUF;
            obj->unk_8 = fn_3_17820();
            DCInvalidateRange(BUF, 0x2000);
            if (obj->unk_1C == 7) CALL(4);
            else if (obj->unk_1C == 8) CALL(5);
            else CALL(obj->unk_1C);
            fn_3_16FD0(BUF);
            DCStoreRange(BUF, 0x2000);
            obj->unk_20 = saved;
        } else {
            obj->unk_8 = fn_3_17820();
            saved = obj->unk_20;
            obj->unk_20 = BUF;
            CALL(0);
            obj->unk_20 = saved;
        }
        break;
    default:
        saved = obj->unk_20;
        obj->unk_8 = fn_3_17820();
        obj->unk_20 = BUF;
        CALL(0);
        obj->unk_20 = saved;
        break;
    }
    if (BIT(8, 9)) {
        fn_1_A2D84(0xA9150500);
        switch (obj->unk_1C) {
        case 3: case 4: case 5: case 7: case 8:
            if (!lbl_3_bss_A23EC.unk_10) {
                lbl_3_bss_A23EC.unk_10 = 0;
                lbl_3_bss_A23EC.unk_C = 0x20000000;
                fn_3_19CA4();
            } else {
                lbl_3_bss_A23EC.unk_10 = 0;
            }
            break;
        case 0: case 1: case 9: case 10:
            fn_3_1445C();
        default:
            lbl_3_bss_A23EC.unk_10 = 0;
            lbl_3_bss_A23EC.unk_C = 0x20000000;
            fn_3_19CCC();
            break;
        }
    }
    obj->unk_4 = 0;
}
/* fzgx:end fn_3_156D0 */

/* fzgx:begin fn_3_1683C */
typedef struct { u32 c; } Col4;
struct Arg0 {
    u8 pad_0[4];
    f32 unk_4;
    f32 unk_8;
};

extern const Col4 lbl_3_rodata_5B8;
extern const Col4 lbl_3_rodata_5BC;
extern s8 fn_1_A5DC4(void);
extern void fn_1_A9868(void);
extern u32 fn_1_A9FFC(s16, s16, s16, s16, void *);
extern void fn_1_AA538(void);
extern void fn_1_4E0F4(void);

void fn_3_1683C(struct Arg0 *arg0, s16 off, s16 size) {
    s16 x;
    s16 y;
    u8 i;
    u8 j;
    Col4 colA;
    Col4 colB;
    Obj_3_bss_A23EC *p = &lbl_3_bss_A23EC;
    x = arg0->unk_4;
    y = arg0->unk_8;
    off = 0;
    size = p->unk_11 << 3;
    colA = lbl_3_rodata_5B8;
    colB = lbl_3_rodata_5BC;
    if (fn_1_A5DC4()) {
        off = 4 / p->unk_11;
    }
    fn_1_A9868();
    for (i = 0; i < 256 / size; i++) {
        for (j = off; j < 256 / size - off; j++) {
            if (((i % 2) ^ (j % 2)) != 0) {
                Col4 t = colA;
                fn_1_A9FFC(x + size * j, y + size * i, size, size, &t);
            } else {
                Col4 t = colB;
                fn_1_A9FFC(x + size * j, y + size * i, size, size, &t);
            }
        }
    }
    fn_1_AA538();
    fn_1_4E0F4();
}
/* fzgx:end fn_3_1683C */

/* fzgx:begin fn_3_16E14 */
#include "font.h"

#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 192.0f;
    s = 105.0f;
    s = 90.0f;
    s = 32.0f;
    s = 0.0f;
    s = 184.0f;
    s = 86.0f;
    s = 100.0f;
    s = 175.0f;
    s = 88.0f;
    s = 0.5f;
    s = 10.0f;
    s = 420.0f;
    s = 334.0f;
    s = 29.0f;
    s = 320.0f;
    s = 232.0f;
    s = 50.0f;
    s = 4.0f;
    s = 480.0f;
    s = 92.0f;
    s = 1.0f;
    s = 1.0714285373687744f;
    s = 64.0f;
    s = 65535.0f;
    s = 119.0f;
    s = 30.0f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
}
static const u32 fzgx_pool_table3[1] = {0x00000064};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0920546628767624e-05f;
    s = -0.25f;
    s = -0.6000000238418579f;
    s = -0.949999988079071f;
    s = 0.25f;
    s = 0.6000000238418579f;
    s = 0.949999988079071f;
}
static const u32 fzgx_pool_table5[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 28.0f;
    s = 0.05999999865889549f;
    s = 10.680000305175781f;
    s = 0.03999999910593033f;
}
static const u32 fzgx_pool_table7[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

typedef struct {
    u32 type;
    f32 x;
    f32 y;
    f32 z;
    f32 a;
    f32 b;
    u8 pad18[0x18];
    u32 mode;
    u8 pad34[8];
    u32 color;
    u8 pad40[0x18];
} Packet16E14;
extern const Packet16E14 lbl_1_rodata_26F8;
extern u8 lbl_3_rodata_538[];
extern int fn_1_4F734(FontDrawPacket *);

void fn_3_16E14(void) {
    u16 v2;
    u8 *p_lbl_3_rodata_538;
    u8 v3;
    s32 end;
    s32 middle;
    s32 pos;
    s32 index;
    u8 i;
    Packet16E14 packet;
    v2 = 64 / lbl_3_bss_A23EC.unk_11;
    p_lbl_3_rodata_538 = lbl_3_rodata_538;
    v3 = 256 / v2 - 1;
    packet = lbl_1_rodata_26F8;
    packet.type = 12;
    packet.mode = 5;
    packet.z = 28.0f;
    packet.color = fzgx_pool_table5[0];
    middle = v3 / 2;
    end = middle + 5;
    for (i = 0; i < v3; i++) {
        index = i;
        pos = (index + 1) * v2;
        packet.x = (f32)(pos + 191);
        packet.y = 105.0f;
        packet.a = 0.06f;
        packet.b = 10.68f;
        fn_1_4F734((FontDrawPacket *)&packet);
        packet.x = 192.0f;
        packet.y = (f32)(pos + 104);
        packet.a = 10.68f;
        if (index >= middle && index < end)
            packet.b = 0.04f;
        else
            packet.b = 0.06f;
        fn_1_4F734((FontDrawPacket *)&packet);
    }
}
/* fzgx:end fn_3_16E14 */

/* fzgx:begin fn_3_16FD0 */
typedef struct { u32 c; } Col4;
extern Col4 lbl_3_rodata_5EC;
extern u32 fn_3_14794(u32, s16, s16, void *);

void fn_3_16FD0(u32 arg0) {
    u32 i = 0;
    Col4 col = lbl_3_rodata_5EC;
    for (; i < 64; i++) {
        {
            Col4 t = col;
            fn_3_14794(arg0, i, 0, &t);
        }
        {
            Col4 t = col;
            fn_3_14794(arg0, i, 63, &t);
        }
    }
    for (i = 0; i < 64; i++) {
        {
            Col4 t = col;
            fn_3_14794(arg0, 0, i, &t);
        }
        {
            Col4 t = col;
            fn_3_14794(arg0, 63, i, &t);
        }
    }
}
/* fzgx:end fn_3_16FD0 */

/* fzgx:begin fn_3_170E0 */
void fn_3_170E0(void) {
    fn_3_17100();
}
/* fzgx:end fn_3_170E0 */

/* fzgx:begin fn_3_17820 */
u32 fn_3_17820(void) {
    return *(u32 *)&(*(u16 (*)[20])&lbl_3_bss_A2410)[2];
}
/* fzgx:end fn_3_17820 */

/* fzgx:begin fn_3_17830 */
typedef struct CustomizeState {
    u8 _pad0[8];
    u32 flags;
    u8 _pad1[16];
    f32 field_1c;
} CustomizeState;

void fn_3_17830(void) {
    (*(CustomizeState *)&lbl_3_bss_A2410).field_1c = lbl_3_rodata_5FC[0];
    (*(CustomizeState *)&lbl_3_bss_A2410).flags |= 0x20000000u;
}
/* fzgx:end fn_3_17830 */
