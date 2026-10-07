#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_common.h"

typedef void (*Fn103FCC)(void);

typedef struct Fn1_103F58_Object {
    u8 pad0[4];
    Fn103FCC callback;
    void *context;
} Fn1_103F58_Object;
extern s32 fn_1_5910(void);
extern f32 lbl_1_rodata_7960[43];
extern f32 lbl_1_rodata_7A40[2];
extern s32 fn_1_58C4(void);
extern void lbl_8006DCA4(void);
extern void fn_1_57714(s32 arg0);
extern void fn_1_57720(u32 value_1, u32 value_2, u32 value_3, u32 value_4);
extern void fn_1_57CD0(u32 value, void *arg);
extern void * fn_1_548AC(u32 amount);
extern void fn_1_5489C(void **arg0, void **arg1);
extern u8 *fn_80083970(u8 *str, const u8 *needle);
extern void fn_1_10846C(void *);
extern void fn_1_128884(void *arg0, void *arg1, s32 type);
extern f32 fn_1_128AAC(s32 exponent, f32 value);
extern f32 lbl_1_rodata_78E8[19];
extern void fn_1_103B00(void);
extern f32 lbl_1_rodata_7934[11];
extern void fn_1_9E5B8(void *);
extern void **fn_1_54448(s32 arg0);
extern void fn_1_103FCC(void);
extern void fn_1_10688C(void);
extern void fn_1_106B68(void);
extern u8 lbl_1_bss_86EC4;
extern void fn_80008BEC(void *dest, int value, u32 size);
extern void fn_1_1088B8(void *arg);
extern void lbl_8006DBAC(void *arg);
extern void lbl_8006E1B0(void *arg0, void *arg1);
extern void fn_1_107F74(void *arg0, int arg1);
extern u32 lbl_801A6410;
extern u32 lbl_1_data_3F284[2];
extern s32 OSIsThreadTerminated(void *arg0);
extern void OSCancelThread(void *arg0);
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern void fn_1_469BC(void);
extern void fn_1_466B0(s32 arg0, s32 arg1);
extern u32 lbl_1_bss_85288[2];

/* fzgx:begin fn_1_103AA8 */
// Initializes the background-common state and its update callback.
void fn_1_103AA8(void) {
    lbl_1_bss_85290 = lbl_1_rodata_78E8[0];
    lbl_1_data_2A7E0.unk_34 = (u32)fn_1_103B00;
}
/* fzgx:end fn_1_103AA8 */

/* fzgx:begin fn_1_103AD4 */
void fn_1_103AD4(void) {
    f32 current = lbl_1_bss_85290;

    if (current > lbl_1_rodata_78E8[0]) {
        lbl_1_bss_85290 = current - lbl_1_rodata_7934[0];
    }
}
/* fzgx:end fn_1_103AD4 */

/* fzgx:begin fn_1_103F10 */
void fn_1_103F10(void *arg) {
    int count;
    u8 *entry;

    entry = (u8 *)arg + 0x8e4;
    count = 4;
    do {
        fn_1_9E5B8(entry);
        count--;
        entry += 0xfc;
    } while (count > 0);
}
/* fzgx:end fn_1_103F10 */

/* fzgx:begin fn_1_103F58 */
void fn_1_103F58(void *arg0) {
    void *value;
    Fn1_103F58_Object *object;

    if (*(u32 *)arg0 != 0) {
        value = (void *)fn_1_54448(0);
        object = (Fn1_103F58_Object *)fn_1_548AC(12);
        if (object != 0) {
            object->callback = fn_1_103FCC;
            object->context = arg0;
            fn_1_5489C( (void **)(void *)(value), (void **)(Fn1_103F58_Object *)(object));
        }
    }
}
/* fzgx:end fn_1_103F58 */

/* fzgx:begin fn_1_104710 */
void fn_1_104710(void) {
    fn_1_10688C();
}
/* fzgx:end fn_1_104710 */

/* fzgx:begin fn_1_105724 */
// fn_1_105724: simple wrapper function calling fn_1_106B68
void fn_1_105724(void) {
    fn_1_106B68();
}
/* fzgx:end fn_1_105724 */

/* fzgx:begin fn_1_105744 */
// Reset the shared background state to its initial sentinel and zero values.
void fn_1_105744(void) {
    lbl_1_bss_854B8.unk_C = -1;
    lbl_1_bss_854B8.unk_0 = 0;
    lbl_1_bss_854B8.unk_4 = 0;
    lbl_1_bss_854B8.unk_8 = 0;
}
/* fzgx:end fn_1_105744 */

/* fzgx:begin fn_1_105768 */
// fn_1_105768: empty in retail (single blr).
void fn_1_105768(void) {
}
/* fzgx:end fn_1_105768 */

/* fzgx:begin fn_1_1067A8 */

void fn_1_1067A8(void *arg0, f32 arg1, f32 arg2) {
    s32 result;
    s32 value;
    s32 count;
    s32 stride;
    u8 *base;
    f32 scale;
    f32 offset;

    scale = arg1;
    offset = arg2;
    result = fn_1_5910();

    value = (s32)(lbl_1_rodata_7960[0] * scale / offset + lbl_1_rodata_7A40[0]);
    count = fn_1_58C4();
    if (count <= 2) {
        lbl_8006DCA4();
        fn_1_57714(value);
        fn_1_57720(1, 4, 5, 0);
        base = (u8 *)arg0;
        stride = *(s32 *)(base + 0xC000);
        fn_1_57CD0((stride & 0x7FFF) << 1, base + (result * stride << 5) + 0x4000);
        fn_1_57714(6);
    }
}
/* fzgx:end fn_1_1067A8 */

/* fzgx:begin fn_1_106B68 */
void fn_1_106B68(void) {
    u32 *data;
    Obj_1_bss_85280 *base;
    s32 i;

    base = &lbl_1_bss_85280;
    *(s32 *)((u8 *)base + 0x248) = 2;
    if (OSIsThreadTerminated((u8 *)base + 0x918) == 0) {
        OSCancelThread((u8 *)base + 0x918);
    }

    data = lbl_1_data_3F284;
    fn_1_46B4(lbl_801A6410, data[1], (const char *)(u8 *)((*(u8 (*)[12])&lbl_1_data_3F34C)), 0x8a5);
    fn_1_46B4(lbl_801A6410, data[0], (const char *)(u8 *)((*(u8 (*)[12])&lbl_1_data_3F34C)), 0x8a6);

    data[1] = 0;
    data[0] = 0;
    fn_1_46B4(lbl_801A6410, base->unk_0, (const char *)(u8 *)((*(u8 (*)[12])&lbl_1_data_3F34C)), 0x8a9);

    base->unk_0 = 0;
    fn_1_46B4(lbl_801A6410, base->unk_4, (const char *)(u8 *)((*(u8 (*)[12])&lbl_1_data_3F34C)), 0x8ab);
    base->unk_4 = 0;
    fn_1_469BC();

    i = 0;
    data = (u32 *)((u8 *)base + 0x5b4);
    for (; i < 0xd2; i++) {
        fn_1_466B0(*data, 1);
        data++;
    }
    fn_1_466B0(*(s32 *)((u8 *)base + 0x8fc), 1);
}
/* fzgx:end fn_1_106B68 */

/* fzgx:begin fn_1_106DB4 */
s32 fn_1_106DB4(u32 arg0, u32 arg1) {
    volatile u32 *counter;  /* fzgx: count is re-read after each store in the retail loop */
    u8 *entry;

    switch (arg0) {
    case 0:
        *(u32 *)arg1 |= 0x08000000;
        break;
    case 1:
        lbl_1_bss_854B8.unk_0 = arg1;
        break;
    case 2:
        lbl_1_bss_854B8.unk_4 = (Obj_1_bss_854B8_At4 *)arg1;
        break;
    case 3:
        lbl_1_bss_854B8.unk_8 = (Obj_1_bss_854B8_At8 *)arg1;
        ((Obj_1_bss_3BE0_Target *)arg1)->unk_3C = 0;
        *(u32 *)arg1 &= 0x7FFFFFFF;
        break;
    case 4:
        counter = &lbl_1_bss_85288[0];
        entry = (u8 *)lbl_1_bss_3BE0->unk_54;
        *counter = 0;
        while ((u32)entry != arg1) {
            entry += 0x40;
            *counter = *counter + 1;
        }
        break;
    case 5:
        counter = &lbl_1_bss_85288[1];
        entry = (u8 *)lbl_1_bss_3BE0->unk_54;
        *counter = 0;
        while ((u32)entry != arg1) {
            entry += 0x40;
            *counter = *counter + 1;
        }
        break;
    case 6:
        break;
    }
    return 1;
}
/* fzgx:end fn_1_106DB4 */

/* fzgx:begin fn_1_106EA4 */
void fn_1_106EA4(f32 arg0) {
    lbl_1_bss_85290 = arg0;
}
/* fzgx:end fn_1_106EA4 */

/* fzgx:begin fn_1_1071C0 */
void fn_1_1071C0(void) {
    if (lbl_1_bss_86EC4 != 0) {
        lbl_1_bss_86EC4 = 0;
        lbl_1_bss_86EC0 = 0;
    }
}
/* fzgx:end fn_1_1071C0 */

/* fzgx:begin fn_1_107900 */
void fn_1_107900(void) {
    fn_80008BEC(&lbl_1_bss_86ED0, 0, 0x1c70);
}
/* fzgx:end fn_1_107900 */

/* fzgx:begin fn_1_107C4C */
void fn_1_107C4C(void *arg) {
    if (arg != 0) {
        fn_1_1088B8(arg);
    }
}
/* fzgx:end fn_1_107C4C */

/* fzgx:begin fn_1_107E90 */
typedef struct {
    u8 unk_00[0x8];
    u32 unk_08;
    u8 *unk_0C;
    u8 unk_10[0x8];
    u32 unk_18;
    u8 unk_1C[0x8];
    u8 *unk_24;
} Fn107E90Context;

// Initialize each background entry selected by the context.
void fn_1_107E90(Fn107E90Context *context) {
    u32 i;
    u8 *entries;
    u8 *background;
    u8 *entry;
    u32 *background_indices;

    i = 0;
    entries = context->unk_24;
    background_indices = (u32 *)&lbl_1_data_3FFBC;
    background = *(u8 **)(*(u8 **)(context->unk_0C + 0x150) + 0x8);
    entry = background + background_indices[context->unk_08] * 0x18c;
    for (; i < context->unk_18; i++, entries += 0x44) {
        lbl_8006DBAC(entry + 0x88);
        lbl_8006E1B0(entries + 0x28, entries + 0x10);
    }
}
/* fzgx:end fn_1_107E90 */

/* fzgx:begin fn_1_107F2C */
void fn_1_107F2C(void *arg0) {
    fn_1_107F74(arg0, 0);
}
/* fzgx:end fn_1_107F2C */

/* fzgx:begin fn_1_107F50 */
void fn_1_107F50(void *arg0) {
    fn_1_107F74(arg0, 1);
}
/* fzgx:end fn_1_107F50 */

/* fzgx:begin fn_1_1185B4 */
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.1920928955078125e-07;
    s = 0.009999999776482582f;
}
static const u32 fzgx_pool_table3[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1e-07;
}
static const u32 fzgx_pool_table5[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 0.25f;
}
static const u32 fzgx_pool_table7[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    d = 0.0013611111376020642;
    s = 0.0027222223579883575f;
    s = -1.0f;
    s = 0.0f;
    s = -2.0f;
    s = 2.0f;
    s = 1.1920928955078125e-07f;
    s = -1.0000001192092896f;
}
static const u32 fzgx_pool_table9[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const u32 *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.0013611111789941788f;
    s = -0.0027222223579883575f;
    s = 9.999999747378752e-05f;
    s = 1.0f;
    s = 0.00039999998989515007f;
    s = 0.02500000037252903f;
    s = 0.004224999807775021f;
    d = 0.0749999976158142;
    d = 0.3;
    s = -0.01899999938905239f;
    s = 0.05700000002980232f;
    s = 0.0009609999833628535f;
}
static const u32 fzgx_pool_table11[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const u32 *volatile cp; cp = fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.04099999949336052;
    d = -1.0;
    s = 0.75f;
    s = -0.25f;
}
#pragma section code_type ".text"

typedef struct Sig_fn_1_10846C_Node10C4E4 {
    u8 flag;
    u8 pad[0x13];
    f32 keyA;
    f32 keyB;
    u8 pad2[0x24];
    f32 value;
} Sig_fn_1_10846C_Node10C4E4;
typedef struct Sig_fn_1_10846C_Edge10C4E4 {
    Sig_fn_1_10846C_Node10C4E4 *a;
    Sig_fn_1_10846C_Node10C4E4 *b;
    u32 pad;
} Sig_fn_1_10846C_Edge10C4E4;
typedef struct Sig_fn_1_10846C_Graph10C4E4 {
    u8 pad[0x8];
    u32 nameIndex;
    u8 pad1[0xC];
    u32 nodeCount;
    u32 edgeCount;
    u32 pad2;
    Sig_fn_1_10846C_Node10C4E4 *nodes;
    Sig_fn_1_10846C_Edge10C4E4 *edges;
} Sig_fn_1_10846C_Graph10C4E4;



void fn_1_1185B4(Sig_fn_1_10846C_Graph10C4E4 *g) {
    s32 flag;
    u32 j;
    u32 quarter;
    Sig_fn_1_10846C_Node10C4E4 *a;
    u32 i;
    Sig_fn_1_10846C_Node10C4E4 *b;
    Sig_fn_1_10846C_Node10C4E4 *p;

    if (g == NULL) {
        return;
    }

    flag = fn_80083970((((u8 * *)&lbl_1_data_3FCAC))[g->nameIndex], (((u8 *)&lbl_1_data_3F9E0))) != NULL;
    fn_1_10846C(g);

    p = g->nodes;
    for (i = 0; i < g->nodeCount; i++, p++) {
        if (p->flag & 1) {
            p->value = -1.0f;
            p->flag = 0;
        } else {
            p->value = 0.0f;
            p->flag = 1;
        }
    }

    a = g->nodes;
    for (i = 0; i < g->nodeCount; i++, a++) {
        b = &g->nodes[i] + 1;
        for (j = i + 1; j < g->nodeCount; j++, b++) {
            if (!(a->flag & 1) && (b->flag & 1)) {
                fn_1_128884(a, b, sizeof(Sig_fn_1_10846C_Node10C4E4));
            }
        }
    }

    a = g->nodes;
    for (i = 0; i < g->nodeCount; i++, a++) {
        if (flag) {
            b = &g->nodes[i] + 1;
            for (j = i + 1; j < g->nodeCount; j++, b++) {
                if (a->flag == b->flag && a->keyA < b->keyA) {
                    fn_1_128884(a, b, sizeof(Sig_fn_1_10846C_Node10C4E4));
                }
            }
        } else {
            b = &g->nodes[i] + 1;
            for (j = i + 1; j < g->nodeCount; j++, b++) {
                if (a->flag == b->flag && a->keyA > b->keyA) {
                    fn_1_128884(a, b, sizeof(Sig_fn_1_10846C_Node10C4E4));
                }
            }
        }
    }

    quarter = (g->nodeCount - 1) >> 2;
    for (i = 0; i < quarter; i++) {
        for (j = 0; j < 4; j++) {
            if (1.1920928955078125e-07f + g->nodes[i * 4 + j].value < 0.0f) {
                g->nodes[i * 4 + j].value = -fn_1_128AAC(i, 2.0f);
                g->nodes[i * 4 + j].value /= fn_1_128AAC(quarter, 2.0f);
                g->nodes[i * 4 + j].value *= 0.75f;
                g->nodes[i * 4 + j].value -= 0.25f;
            }
        }
    }
    g->nodes[quarter * 4].value = -1.0f;
}
/* fzgx:end fn_1_1185B4 */
