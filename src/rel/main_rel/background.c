#include "types.h"
#include "dolphin/types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/background.h"
#include "dolphin/hw_regs.h"
#include "game/main_rel/background_types.h"

extern s32 fn_8006FC1C(const char *, const char *);
extern s32 fn_8006FC5C(const char *, const char *, s32);
extern size_t strlen(const char *str);
extern f32 lbl_1_rodata_42C0[4];
extern void fn_80038BFC(f32* out);
extern u32 __cvt_fp2unsigned(f32);
extern u32 lbl_801A6D00;
extern s32 fn_1_54E34(void *arg0, f32 arg1);
extern void fn_800724C8(void);
extern void fn_8007245C(u32 value);
extern void lbl_8006DAEC(void);
extern void lbl_8006D758(void);
extern u32 GXLoadPosMtxImm(u32, u32);
extern void lbl_8006DB30(void);
extern void fn_800736C0(u32, void *);
extern void fn_8003462C(u32 arg0, u32 arg1, u32 arg2);
extern void lbl_8006DFC4(u32);
extern void lbl_8006E1D8(u32, f32, f32, f32);
extern vu32 __DIRegs[];
extern void mathutil_mtxA_rotate_z(s32);
extern void lbl_8006E0A4(void *);
extern u32 lbl_1_bss_6EA78;
extern u32 lbl_1_bss_6EA7C;
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern const f32 lbl_1_rodata_41FC;
extern u8 fn_1_86624(void);
extern u8 *fn_1_14F04(void);
extern f32 lbl_1_rodata_4244[7];
extern void fn_1_17920(s32, s32, f32);
extern void fn_1_85C58(s32, f32);
extern void lbl_8006DB74(void *);
extern f32 fn_1_9DDA8();
extern void fn_1_9DFB8(u32, u32, u32, u32);
extern void GXPeekZ(u32, u32, void *);
extern void fn_80034200(u32 arg0);
extern void fn_8003432C(u32, u32, u32 *);
/* Pool literals, declared non-const: retail reloads them after every FIFO store. */
extern f32 lbl_1_rodata_42D0;
extern f32 lbl_1_rodata_42D4;

/* fzgx:begin fn_1_9CF78 */
typedef u32 (*FilterCallback)(u32, void *);

typedef struct {
    s32 type;
    const char *str;
} TblEntry;

typedef struct {
    s32 count;
    u32 unk4;
    TblEntry *entries;
} TblGroup;

void fn_1_9CF78(void *arg0, FilterCallback arg1) {
    s32 n;
    u32 idx;
    TblEntry *e;
    TblGroup ***p;
    s32 slen;
    TblEntry *q;
    const char *s;
    s32 ok;
    TblGroup *g;
    s32 res;

    p = (TblGroup ***)&lbl_1_data_2CC30;
    ok = 1;
    while (*p != 0) {
        g = **p;
        if (g == 0) {
            p++;
            continue;
        }
        e = g->entries;
        n = g->count;
        for (; n > 0; n--, e++) {
            s = e->str;
            slen = (s32)strlen(s);
            q = (TblEntry *)arg0;
            for (idx = 0; q->str != 0; idx++, q++) {
                switch (q->type) {
                case 0:
                    res = fn_8006FC5C(s, q->str, (s32)strlen(q->str));
                    break;
                case 1:
                    res = fn_8006FC1C(s, q->str);
                    break;
                case 2: {
                    s32 len = (s32)strlen(q->str);
                    if (len > slen) {
                        res = 0;
                    } else {
                        res = fn_8006FC5C(s + (slen - len), q->str, len);
                    }
                    break;
                }
                default:
                    res = 0;
                    break;
                }
                if (res != 0) {
                    ok = arg1(idx, e);
                }
                if (ok == 0) {
                    break;
                }
            }
            if (ok == 0) {
                break;
            }
        }
        if (ok == 0) {
            break;
        }
        p++;
    }
}
/* fzgx:end fn_1_9CF78 */

/* fzgx:begin fn_1_9D77C */
typedef struct {
    u32 flags;
    u8 _pad[0x34];
    void *link;
    u8 _tail[4];
} Fn1_9D77C_Item;

typedef struct {
    u8 _pad[4];
    u32 value;
} Fn1_9D77C_Link;

void fn_1_9D77C(Fn1_9D77C_Item *items, s32 count) {
    s32 i;
    u32 *first;
    u32 *second;

    first = (u32 *)lbl_1_bss_6EA78;
    second = (u32 *)lbl_1_bss_6EA7C;

    for (i = 0; i < 5; i++) {
        if (lbl_1_bss_6EA78 != 0 && first != 0 && *first != 0) {
            fn_1_46B4(lbl_801A6410, *first, (const char *)(void *)(lbl_1_data_2CB60), 0x922);
            *first = 0;
        }
        if (lbl_1_bss_6EA7C != 0 && second != 0 && *second != 0) {
            fn_1_46B4(lbl_801A6410, *second, (const char *)(void *)(lbl_1_data_2CB60), 0x923);
            *second = 0;
        }
        first++;
        second++;
    }

    i = 0;
    while (i < count) {
        if ((items->flags & 0x1000) != 0 &&
            items->link != 0 &&
            ((Fn1_9D77C_Link *)items->link)->value != 0) {
            fn_1_46B4(lbl_801A6410,
                       ((Fn1_9D77C_Link *)items->link)->value, (const char *)(void *)(lbl_1_data_2CB60), 0x92b);
            ((Fn1_9D77C_Link *)items->link)->value = 0;
        }
        i++;
        items++;
    }

    if (lbl_1_bss_6EA78 != 0) {
        fn_1_46B4(lbl_801A6410, lbl_1_bss_6EA78, (const char *)(void *)(lbl_1_data_2CB60), 0x92e);
        lbl_1_bss_6EA78 = 0;
    }
    if (lbl_1_bss_6EA7C != 0) {
        fn_1_46B4(lbl_801A6410, lbl_1_bss_6EA7C, (const char *)(void *)(lbl_1_data_2CB60), 0x92f);
        lbl_1_bss_6EA7C = 0;
    }
}
/* fzgx:end fn_1_9D77C */

/* fzgx:begin fn_1_9D93C */
s32 fn_1_9D93C(s32 arg0, u32 *arg1) {
    if (arg0 == 0) {
        lbl_1_data_2A7E0.unk_80 = *arg1;
    } else {
        lbl_1_data_2A7E0.unk_7C = *arg1;
    }
    {
        s32 result;
        result = 0;
        if (lbl_1_data_2A7E0.unk_80 == 0 ||
            lbl_1_data_2A7E0.unk_7C == 0) {
            result = 1;
        }
        return result;
    }
}
/* fzgx:end fn_1_9D93C */

/* fzgx:begin fn_1_9D994 noprologue */
#include "types.h"
#include "dolphin/types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/background.h"
#include "dolphin/hw_regs.h"
#include "game/main_rel/background_types.h"

extern s32 fn_1_9D93C(s32, u32 *);
typedef u32 (*Sig_fn_1_9CF78_FilterCallback)(u32, void *);
extern u8 fn_1_101348__fzgx_offset_0[];
extern u8 fn_1_1013A0__fzgx_offset_0[];
extern u8 fn_1_1013C0__fzgx_offset_0[];
extern u8 fn_1_1013C4__fzgx_offset_0[];
extern u8 fn_1_101400__fzgx_offset_0[];
extern u8 fn_1_101404__fzgx_offset_0[];
extern u8 fn_1_101424__fzgx_offset_0[];
extern u8 fn_1_101428__fzgx_offset_0[];
extern u8 fn_1_101448__fzgx_offset_0[];
extern u8 fn_1_10144C__fzgx_offset_0[];
extern u8 fn_1_101454__fzgx_offset_0[];
extern u8 fn_1_150500__fzgx_offset_0[];
extern u8 fn_1_150518__fzgx_offset_0[];
extern u8 fn_1_150570__fzgx_offset_0[];
extern u8 fn_1_150574__fzgx_offset_0[];
extern u8 fn_1_1505B4__fzgx_offset_0[];
extern u8 fn_1_150608__fzgx_offset_0[];
extern u8 fn_1_150650__fzgx_offset_0[];
extern u8 fn_1_151764__fzgx_offset_0[];
extern u8 fn_1_15176C__fzgx_offset_0[];
extern u8 fn_1_153988__fzgx_offset_0[];
extern u8 fn_1_15398C__fzgx_offset_0[];
extern u8 fn_1_1539D0__fzgx_offset_0[];
extern u8 fn_1_153A28__fzgx_offset_0[];
extern u8 fn_1_153AAC__fzgx_offset_0[];
extern u8 fn_1_153AB0__fzgx_offset_0[];
extern u8 fn_1_153AF4__fzgx_offset_0[];
extern u8 fn_1_1543E8__fzgx_offset_0[];
extern u8 fn_1_154410__fzgx_offset_0[];
extern u8 fn_1_1586A8__fzgx_offset_0[];
extern u8 fn_1_1586AC__fzgx_offset_0[];
extern u8 fn_1_158980__fzgx_offset_0[];
extern u8 fn_1_158984__fzgx_offset_0[];
extern u8 fn_1_15903C__fzgx_offset_0[];
extern u8 fn_1_159040__fzgx_offset_0[];
extern u8 fn_1_159060__fzgx_offset_0[];
extern u8 fn_1_159064__fzgx_offset_0[];
extern u8 fn_1_15906C__fzgx_offset_0[];
extern u8 fn_1_15B428__fzgx_offset_0[];
extern u8 fn_1_15B42C__fzgx_offset_0[];
extern u8 fn_1_15B4F8__fzgx_offset_0[];
extern u8 fn_1_15B4FC__fzgx_offset_0[];
extern u8 fn_1_15B51C__fzgx_offset_0[];
extern u8 fn_1_15B520__fzgx_offset_0[];
extern u8 fn_1_15B540__fzgx_offset_0[];
extern u8 fn_1_15B698__fzgx_offset_0[];
extern u8 fn_1_15B70C__fzgx_offset_0[];
extern u8 fn_1_D3C00__fzgx_offset_0[];
extern u8 fn_1_D3C04__fzgx_offset_0[];
extern u8 fn_1_D3C58__fzgx_offset_0[];
extern u8 fn_1_D3CF4__fzgx_offset_0[];
extern u8 fn_1_D3DDC__fzgx_offset_0[];
extern u8 fn_1_D3E08__fzgx_offset_0[];
extern u8 fn_1_D3E8C__fzgx_offset_0[];
extern u8 fn_1_D5C68__fzgx_offset_0[];
extern u8 fn_1_D5C70__fzgx_offset_0[];
extern u8 fn_1_D720C__fzgx_offset_0[];
extern u8 fn_1_D7274__fzgx_offset_0[];
extern u8 fn_1_D744C__fzgx_offset_0[];
extern u8 fn_1_D74C4__fzgx_offset_0[];
extern u8 fn_1_D75CC__fzgx_offset_0[];
extern u8 fn_1_D7688__fzgx_offset_0[];
extern u8 fn_1_D76EC__fzgx_offset_0[];
extern u8 fn_1_D8F4C__fzgx_offset_0[];
extern u8 fn_1_D8FC4__fzgx_offset_0[];
extern u8 fn_1_DA7B8__fzgx_offset_0[];
extern u8 fn_1_DA7E4__fzgx_offset_0[];
extern u8 fn_1_DA9F0__fzgx_offset_0[];
extern u8 fn_1_DAA34__fzgx_offset_0[];
extern u8 fn_1_DAA58__fzgx_offset_0[];
extern u8 fn_1_DAAC4__fzgx_offset_0[];
extern u8 fn_1_DAAF8__fzgx_offset_0[];
extern u8 fn_1_DAB5C__fzgx_offset_0[];
extern u8 fn_1_DABB4__fzgx_offset_0[];
extern u8 fn_1_DAD68__fzgx_offset_0[];
extern u8 fn_1_DAD6C__fzgx_offset_0[];
extern u8 fn_1_DADA8__fzgx_offset_0[];
extern u8 fn_1_DAE24__fzgx_offset_0[];
extern u8 fn_1_DAEF8__fzgx_offset_0[];
extern u8 fn_1_DAEFC__fzgx_offset_0[];
extern u8 fn_1_DAF90__fzgx_offset_0[];
extern u8 fn_1_DC1B8__fzgx_offset_0[];
extern u8 fn_1_DC1C0__fzgx_offset_0[];
extern u8 fn_1_DC204__fzgx_offset_0[];
extern u8 fn_1_DC208__fzgx_offset_0[];
extern u8 fn_1_DC264__fzgx_offset_0[];
extern u8 fn_1_DC268__fzgx_offset_0[];
extern u8 fn_1_DC2F8__fzgx_offset_0[];
extern u8 fn_1_DC33C__fzgx_offset_0[];
extern u8 fn_1_DC3A0__fzgx_offset_0[];
extern u8 fn_1_DCB9C__fzgx_offset_0[];
extern u8 fn_1_DCBF4__fzgx_offset_0[];
extern u8 fn_1_F5AAC__fzgx_offset_0[];
extern u8 fn_1_F5AB0__fzgx_offset_0[];
extern u8 fn_1_F5AEC__fzgx_offset_0[];
extern u8 fn_1_F5AF0__fzgx_offset_0[];
extern u8 fn_1_F5B38__fzgx_offset_0[];
extern u8 fn_1_F5B3C__fzgx_offset_0[];
extern u8 fn_1_F5B84__fzgx_offset_0[];
extern u8 fn_1_F70C0__fzgx_offset_0[];
extern u8 fn_1_F70C8__fzgx_offset_0[];
extern u8 fn_1_FA6C0__fzgx_offset_0[];
extern u8 fn_1_FA75C__fzgx_offset_0[];
extern u8 fn_1_FA82C__fzgx_offset_0[];
extern u8 fn_1_FA830__fzgx_offset_0[];
extern u8 fn_1_FA854__fzgx_offset_0[];
extern u8 fn_1_FA878__fzgx_offset_0[];
extern u8 fn_1_FA898__fzgx_offset_0[];
extern u8 fn_1_FB770__fzgx_offset_0[];
extern u8 fn_1_FB798__fzgx_offset_0[];
extern u8 fn_1_FE5E0__fzgx_offset_0[];
extern u8 fn_1_FE5E4__fzgx_offset_0[];
extern u8 fn_1_FE640__fzgx_offset_0[];
extern u8 fn_1_FE644__fzgx_offset_0[];
extern u8 fn_1_FE780__fzgx_offset_0[];
extern u8 fn_1_FE784__fzgx_offset_0[];
extern u8 fn_1_FE7D4__fzgx_offset_0[];
extern u8 lbl_1_bss_384B4__fzgx_offset_0[];
extern u8 lbl_1_data_1E968__fzgx_offset_0[];
extern u8 lbl_1_data_1E974__fzgx_offset_0[];
extern u8 lbl_1_data_1E980__fzgx_offset_0[];
extern u8 lbl_1_data_1E98C__fzgx_offset_0[];
extern u8 lbl_1_data_1E998__fzgx_offset_0[];
extern u8 lbl_1_data_1E9A4__fzgx_offset_0[];
extern u8 lbl_1_data_1E9B0__fzgx_offset_0[];
extern u8 lbl_1_data_1E9BC__fzgx_offset_0[];
extern u8 lbl_1_data_1E9C8__fzgx_offset_0[];
extern u8 lbl_1_data_1E9D4__fzgx_offset_0[];
extern u8 lbl_1_data_1E9E0__fzgx_offset_0[];
extern u8 lbl_1_data_1E9EC__fzgx_offset_0[];
extern u8 lbl_1_data_1E9F8__fzgx_offset_0[];
extern u8 lbl_1_data_1EA04__fzgx_offset_0[];
extern u8 lbl_1_data_1EA10__fzgx_offset_0[];
extern u8 lbl_1_data_1EA1C__fzgx_offset_0[];
extern u8 lbl_1_data_1EA34__fzgx_offset_0[];
extern u8 lbl_1_data_1EA40__fzgx_offset_0[];
extern u8 lbl_1_data_1EA4C__fzgx_offset_0[];
extern u8 lbl_1_data_1EA58__fzgx_offset_0[];
extern u8 lbl_1_data_1EA64__fzgx_offset_0[];
extern u8 lbl_1_data_1ED48__fzgx_offset_0[];
extern u8 lbl_1_data_1ED54__fzgx_offset_0[];
extern u8 lbl_1_data_1ED60__fzgx_offset_0[];
extern u8 lbl_1_data_1ED6C__fzgx_offset_0[];
extern u8 lbl_1_data_1ED78__fzgx_offset_0[];
extern u8 lbl_1_data_1ED84__fzgx_offset_0[];
extern u8 lbl_1_data_1ED90__fzgx_offset_0[];
extern u8 lbl_1_data_1ED9C__fzgx_offset_0[];
extern u8 lbl_1_data_1EDA8__fzgx_offset_0[];
extern u8 lbl_1_data_1EDB4__fzgx_offset_0[];
extern u8 lbl_1_data_1EDC0__fzgx_offset_0[];
extern u8 lbl_1_data_1EDCC__fzgx_offset_0[];
extern u8 lbl_1_data_1EDD8__fzgx_offset_0[];
extern u8 lbl_1_data_1EDE4__fzgx_offset_0[];
extern u8 lbl_1_data_1EDF0__fzgx_offset_0[];
extern u8 lbl_1_data_1EDFC__fzgx_offset_0[];
extern u8 lbl_1_data_1EE08__fzgx_offset_0[];
extern u8 lbl_1_data_1EE14__fzgx_offset_0[];
extern u8 lbl_1_data_1EE20__fzgx_offset_0[];
extern u8 lbl_1_data_1EE2C__fzgx_offset_0[];
extern u8 lbl_1_data_1EE38__fzgx_offset_0[];
extern u8 lbl_1_data_2A0C0__fzgx_offset_0[];
extern u8 lbl_1_data_2A0D0__fzgx_offset_0[];
extern u8 lbl_1_data_2A0E0__fzgx_offset_0[];
extern u8 lbl_1_data_2A0EC__fzgx_offset_0[];
extern u8 lbl_1_data_2A0F8__fzgx_offset_0[];
extern u8 lbl_1_data_2A10C__fzgx_offset_0[];
extern u8 lbl_1_data_2A13C__fzgx_offset_0[];
extern u8 lbl_1_data_2A144__fzgx_offset_0[];
extern u8 lbl_1_data_2A14C__fzgx_offset_0[];
extern u8 lbl_1_data_2A15C__fzgx_offset_0[];
extern u8 lbl_1_data_2A16C__fzgx_offset_0[];
extern u8 lbl_1_data_2A17C__fzgx_offset_0[];
extern u8 lbl_1_data_2A18C__fzgx_offset_0[];
extern u8 lbl_1_data_2A19C__fzgx_offset_0[];
extern u8 lbl_1_data_2A1AC__fzgx_offset_0[];
extern u8 lbl_1_data_2A1FC__fzgx_offset_0[];
extern u8 lbl_1_data_2A200__fzgx_offset_0[];
extern u8 lbl_1_data_2A210__fzgx_offset_0[];
extern u8 lbl_1_data_2A21C__fzgx_offset_0[];
extern u8 lbl_1_data_2A228__fzgx_offset_0[];
extern u8 lbl_1_data_2A234__fzgx_offset_0[];
extern u8 lbl_1_data_2A240__fzgx_offset_0[];
extern u8 lbl_1_data_2A250__fzgx_offset_0[];
extern u8 lbl_1_data_2A260__fzgx_offset_0[];
extern u8 lbl_1_data_2A270__fzgx_offset_0[];
extern u8 lbl_1_data_2A280__fzgx_offset_0[];
extern u8 lbl_1_data_2A290__fzgx_offset_0[];
extern u8 lbl_1_data_2A2A0__fzgx_offset_0[];
extern u8 lbl_1_data_2A2AC__fzgx_offset_0[];
extern u8 lbl_1_data_2A30C__fzgx_offset_0[];
extern u8 lbl_1_data_2A314__fzgx_offset_0[];
extern u8 lbl_1_data_2A31C__fzgx_offset_0[];
extern u8 lbl_1_data_2A32C__fzgx_offset_0[];
extern u8 lbl_1_data_2A33C__fzgx_offset_0[];
extern u8 lbl_1_data_2A34C__fzgx_offset_0[];
extern u8 lbl_1_data_2A35C__fzgx_offset_0[];
extern u8 lbl_1_data_2A37C__fzgx_offset_0[];
extern u8 lbl_1_data_2A384__fzgx_offset_0[];
extern u8 lbl_1_data_2A3B4__fzgx_offset_0[];
extern u8 lbl_1_data_2A3C4__fzgx_offset_0[];
extern u8 lbl_1_data_2A3CC__fzgx_offset_0[];
extern u8 lbl_1_data_2A3DC__fzgx_offset_0[];
extern u8 lbl_1_data_2A3EC__fzgx_offset_0[];
extern u8 lbl_1_data_2A3FC__fzgx_offset_0[];
extern u8 lbl_1_data_2A40C__fzgx_offset_0[];
extern u8 lbl_1_data_2A41C__fzgx_offset_0[];
extern u8 lbl_1_data_2A444__fzgx_offset_0[];
extern u8 lbl_1_data_2A46C__fzgx_offset_0[];
extern u8 lbl_1_data_2A474__fzgx_offset_0[];
extern u8 lbl_1_data_2A47C__fzgx_offset_0[];
extern u8 lbl_1_data_2A484__fzgx_offset_0[];
extern u8 lbl_1_data_2A494__fzgx_offset_0[];
extern u8 lbl_1_data_2A49C__fzgx_offset_0[];
extern u8 lbl_1_data_2A4B4__fzgx_offset_0[];
extern u8 lbl_1_data_2A4C0__fzgx_offset_0[];
extern u8 lbl_1_data_2A4D4__fzgx_offset_0[];
extern u8 lbl_1_data_2A4E8__fzgx_offset_0[];
extern u8 lbl_1_data_2A508__fzgx_offset_0[];
extern u8 lbl_1_data_2A518__fzgx_offset_0[];
extern u8 lbl_1_data_2A528__fzgx_offset_0[];
extern u8 lbl_1_data_2A530__fzgx_offset_0[];
extern u8 lbl_1_data_2A538__fzgx_offset_0[];
extern u8 lbl_1_data_2A544__fzgx_offset_0[];
extern u8 lbl_1_data_2A55C__fzgx_offset_0[];
extern u8 lbl_1_data_2A570__fzgx_offset_0[];
extern u8 lbl_1_data_2A580__fzgx_offset_0[];
extern u8 lbl_1_data_2A5D0__fzgx_offset_0[];
extern u8 lbl_1_data_2A5DC__fzgx_offset_0[];
extern u8 lbl_1_data_2A5EC__fzgx_offset_0[];
extern u8 lbl_1_data_2A5F8__fzgx_offset_0[];
extern u8 lbl_1_data_2A608__fzgx_offset_0[];
extern u8 lbl_1_data_2A618__fzgx_offset_0[];
extern u8 lbl_1_data_2A624__fzgx_offset_0[];
extern u8 lbl_1_data_2A62C__fzgx_offset_0[];
extern u8 lbl_1_data_2A664__fzgx_offset_0[];
extern u8 lbl_1_data_2A66C__fzgx_offset_0[];
extern u8 lbl_1_data_2A674__fzgx_offset_0[];
extern u8 lbl_1_data_2A684__fzgx_offset_0[];
extern u8 lbl_1_data_2A690__fzgx_offset_0[];
extern u8 lbl_1_data_2A69C__fzgx_offset_0[];
extern u8 lbl_1_data_2A6A8__fzgx_offset_0[];
extern u8 lbl_1_data_2A6B4__fzgx_offset_0[];
extern u8 lbl_1_data_2A6C0__fzgx_offset_0[];
extern u8 lbl_1_data_2A6F0__fzgx_offset_0[];
extern u8 lbl_1_data_2A6F8__fzgx_offset_0[];
extern u8 lbl_1_data_2A700__fzgx_offset_0[];
extern u8 lbl_1_data_2A70C__fzgx_offset_0[];
extern u8 lbl_1_data_2A718__fzgx_offset_0[];
extern u8 lbl_1_data_2A724__fzgx_offset_0[];
extern u8 lbl_1_data_2A730__fzgx_offset_0[];
extern u8 lbl_1_data_2A740__fzgx_offset_0[];
extern u8 lbl_1_data_2A74C__fzgx_offset_0[];
extern u8 lbl_1_data_2A758__fzgx_offset_0[];
extern u8 lbl_1_data_2A764__fzgx_offset_0[];
extern u8 lbl_1_data_2A774__fzgx_offset_0[];
extern u8 lbl_1_data_2A980__fzgx_offset_0[];
extern u8 lbl_1_data_2A988__fzgx_offset_0[];
extern u8 lbl_1_data_2A994__fzgx_offset_0[];
extern u8 lbl_1_data_2A9A0__fzgx_offset_0[];
extern u8 lbl_1_data_2A9AC__fzgx_offset_0[];
extern u8 lbl_1_data_2A9B8__fzgx_offset_0[];
extern u8 lbl_1_data_2A9C4__fzgx_offset_0[];
extern u8 lbl_1_data_2A9D0__fzgx_offset_0[];
extern u8 lbl_1_data_2A9DC__fzgx_offset_0[];
extern u8 lbl_1_data_2A9EC__fzgx_offset_0[];
extern u8 lbl_1_data_2A9F8__fzgx_offset_0[];
extern u8 lbl_1_data_2AA04__fzgx_offset_0[];
extern u8 lbl_1_data_2AA14__fzgx_offset_0[];
extern u8 lbl_1_data_2AA7C__fzgx_offset_0[];
extern u8 lbl_1_data_2AA8C__fzgx_offset_0[];
extern u8 lbl_1_data_2AA9C__fzgx_offset_0[];
extern u8 lbl_1_data_2AAAC__fzgx_offset_0[];
extern u8 lbl_1_data_2AABC__fzgx_offset_0[];
extern u8 lbl_1_data_2AAD0__fzgx_offset_0[];
extern u8 lbl_1_data_2AAE4__fzgx_offset_0[];
extern u8 lbl_1_data_2AAF8__fzgx_offset_0[];
extern u8 lbl_1_data_2AB08__fzgx_offset_0[];
extern u8 lbl_1_data_2AB1C__fzgx_offset_0[];
extern u8 lbl_1_data_2AB2C__fzgx_offset_0[];
extern u8 lbl_1_data_2AB40__fzgx_offset_0[];
extern u8 lbl_1_data_2AEC4__fzgx_offset_0[];
extern u8 lbl_1_data_2AECC__fzgx_offset_0[];
extern u8 lbl_1_data_2AED4__fzgx_offset_0[];
extern u8 lbl_1_data_2AEE0__fzgx_offset_0[];
extern u8 lbl_1_data_2AEE8__fzgx_offset_0[];
extern u8 lbl_1_data_2AEF4__fzgx_offset_0[];
extern u8 lbl_1_data_2AEFC__fzgx_offset_0[];
extern u8 lbl_1_data_2AF04__fzgx_offset_0[];
extern u8 lbl_1_data_2AF10__fzgx_offset_0[];
extern u8 lbl_1_data_2AF18__fzgx_offset_0[];
extern u8 lbl_1_data_2AF20__fzgx_offset_0[];
extern u8 lbl_1_data_2AF2C__fzgx_offset_0[];
extern u8 lbl_1_data_2AF34__fzgx_offset_0[];
extern u8 lbl_1_data_2AF3C__fzgx_offset_0[];
extern u8 lbl_1_data_2AF44__fzgx_offset_0[];
extern u8 lbl_1_data_2AF4C__fzgx_offset_0[];
extern u8 lbl_1_data_2AF54__fzgx_offset_0[];
extern u8 lbl_1_data_2AF60__fzgx_offset_0[];
extern u8 lbl_1_data_2AF68__fzgx_offset_0[];
extern u8 lbl_1_data_2B15C__fzgx_offset_0[];
extern u8 lbl_1_data_2B160__fzgx_offset_0[];
extern u8 lbl_1_data_2B16C__fzgx_offset_0[];
extern u8 lbl_1_data_2B178__fzgx_offset_0[];
extern u8 lbl_1_data_2B184__fzgx_offset_0[];
extern u8 lbl_1_data_2B190__fzgx_offset_0[];
extern u8 lbl_1_data_2B19C__fzgx_offset_0[];
extern u8 lbl_1_data_2B1A8__fzgx_offset_0[];
extern u8 lbl_1_data_2B1B8__fzgx_offset_0[];
extern u8 lbl_1_data_2B1C4__fzgx_offset_0[];
extern u8 lbl_1_data_2B1D0__fzgx_offset_0[];
extern u8 lbl_1_data_2B1E0__fzgx_offset_0[];
extern u8 lbl_1_data_2B1F0__fzgx_offset_0[];
extern u8 lbl_1_data_2B1FC__fzgx_offset_0[];
extern u8 lbl_1_data_2B208__fzgx_offset_0[];
extern u8 lbl_1_data_2B218__fzgx_offset_0[];
extern u8 lbl_1_data_2B220__fzgx_offset_0[];
extern u8 lbl_1_data_2B230__fzgx_offset_0[];
extern u8 lbl_1_data_2B240__fzgx_offset_0[];
extern u8 lbl_1_data_2B248__fzgx_offset_0[];
extern u8 lbl_1_data_2B258__fzgx_offset_0[];
extern u8 lbl_1_data_2B268__fzgx_offset_0[];
extern u8 lbl_1_data_2B274__fzgx_offset_0[];
extern u8 lbl_1_data_2B284__fzgx_offset_0[];
extern u8 lbl_1_data_2B294__fzgx_offset_0[];
extern u8 lbl_1_data_2B2A4__fzgx_offset_0[];
extern u8 lbl_1_data_2B2AC__fzgx_offset_0[];
extern u8 lbl_1_data_2B474__fzgx_offset_0[];
extern u8 lbl_1_data_2B47C__fzgx_offset_0[];
extern u8 lbl_1_data_2B48C__fzgx_offset_0[];
extern u8 lbl_1_data_2B49C__fzgx_offset_0[];
extern u8 lbl_1_data_2B4AC__fzgx_offset_0[];
extern u8 lbl_1_data_2B4BC__fzgx_offset_0[];
extern u8 lbl_1_data_2B4CC__fzgx_offset_0[];
extern u8 lbl_1_data_2B4DC__fzgx_offset_0[];
extern u8 lbl_1_data_2B4EC__fzgx_offset_0[];
extern u8 lbl_1_data_2B4FC__fzgx_offset_0[];
extern u8 lbl_1_data_2B50C__fzgx_offset_0[];
extern u8 lbl_1_data_2B520__fzgx_offset_0[];
extern u8 lbl_1_data_2B530__fzgx_offset_0[];
extern u8 lbl_1_data_2B540__fzgx_offset_0[];
extern u8 lbl_1_data_2B550__fzgx_offset_0[];
extern u8 lbl_1_data_2B560__fzgx_offset_0[];
extern u8 lbl_1_data_2B574__fzgx_offset_0[];
extern u8 lbl_1_data_2B584__fzgx_offset_0[];
extern u8 lbl_1_data_2B594__fzgx_offset_0[];
extern u8 lbl_1_data_2B5A4__fzgx_offset_0[];
extern u8 lbl_1_data_2B5B4__fzgx_offset_0[];
extern u8 lbl_1_data_2B5C4__fzgx_offset_0[];
extern u8 lbl_1_data_2B5D4__fzgx_offset_0[];
extern u8 lbl_1_data_2B5E4__fzgx_offset_0[];
extern u8 lbl_1_data_2B5F4__fzgx_offset_0[];
extern u8 lbl_1_data_2B604__fzgx_offset_0[];
extern u8 lbl_1_data_2B614__fzgx_offset_0[];
extern u8 lbl_1_data_2B624__fzgx_offset_0[];
extern u8 lbl_1_data_2B634__fzgx_offset_0[];
extern u8 lbl_1_data_2B644__fzgx_offset_0[];
extern u8 lbl_1_data_2B654__fzgx_offset_0[];
extern u8 lbl_1_data_2B664__fzgx_offset_0[];
extern u8 lbl_1_data_2B678__fzgx_offset_0[];
extern u8 lbl_1_data_2B68C__fzgx_offset_0[];
extern u8 lbl_1_data_2B6A0__fzgx_offset_0[];
extern u8 lbl_1_data_2B6B4__fzgx_offset_0[];
extern u8 lbl_1_data_2B6C8__fzgx_offset_0[];
extern u8 lbl_1_data_2B6D8__fzgx_offset_0[];
extern u8 lbl_1_data_2B6E8__fzgx_offset_0[];
extern u8 lbl_1_data_2B6F8__fzgx_offset_0[];
extern u8 lbl_1_data_2B708__fzgx_offset_0[];
extern u8 lbl_1_data_2B718__fzgx_offset_0[];
extern u8 lbl_1_data_2B728__fzgx_offset_0[];
extern u8 lbl_1_data_2B738__fzgx_offset_0[];
extern u8 lbl_1_data_2B748__fzgx_offset_0[];
extern u8 lbl_1_data_2B758__fzgx_offset_0[];
extern u8 lbl_1_data_2B768__fzgx_offset_0[];
extern u8 lbl_1_data_2B77C__fzgx_offset_0[];
extern u8 lbl_1_data_2B790__fzgx_offset_0[];
extern u8 lbl_1_data_2B7A4__fzgx_offset_0[];
extern u8 lbl_1_data_2B7B8__fzgx_offset_0[];
extern u8 lbl_1_data_2B7CC__fzgx_offset_0[];
extern u8 lbl_1_data_2B7E0__fzgx_offset_0[];
extern u8 lbl_1_data_2B7F4__fzgx_offset_0[];
extern u8 lbl_1_data_2B808__fzgx_offset_0[];
extern u8 lbl_1_data_2B81C__fzgx_offset_0[];
extern u8 lbl_1_data_2B830__fzgx_offset_0[];
extern u8 lbl_1_data_2B840__fzgx_offset_0[];
extern u8 lbl_1_data_2B850__fzgx_offset_0[];
extern u8 lbl_1_data_2B860__fzgx_offset_0[];
extern u8 lbl_1_data_2B870__fzgx_offset_0[];
extern u8 lbl_1_data_2B884__fzgx_offset_0[];
extern u8 lbl_1_data_2B894__fzgx_offset_0[];
extern u8 lbl_1_data_2B8A4__fzgx_offset_0[];
extern u8 lbl_1_data_2B8B4__fzgx_offset_0[];
extern u8 lbl_1_data_2B8C4__fzgx_offset_0[];
extern u8 lbl_1_data_2B8D8__fzgx_offset_0[];
extern u8 lbl_1_data_2B8EC__fzgx_offset_0[];
extern u8 lbl_1_data_2B900__fzgx_offset_0[];
extern u8 lbl_1_data_2B914__fzgx_offset_0[];
extern u8 lbl_1_data_2B928__fzgx_offset_0[];
extern u8 lbl_1_data_2B93C__fzgx_offset_0[];
extern u8 lbl_1_data_2B948__fzgx_offset_0[];
extern u8 lbl_1_data_2B954__fzgx_offset_0[];
extern u8 lbl_1_data_2B960__fzgx_offset_0[];
extern u8 lbl_1_data_2B96C__fzgx_offset_0[];
extern u8 lbl_1_data_2B97C__fzgx_offset_0[];
extern u8 lbl_1_data_2B990__fzgx_offset_0[];
extern u8 lbl_1_data_2B9A4__fzgx_offset_0[];
extern u8 lbl_1_data_2B9B8__fzgx_offset_0[];
extern u8 lbl_1_data_2B9CC__fzgx_offset_0[];
extern u8 lbl_1_data_2B9DC__fzgx_offset_0[];
extern u8 lbl_1_data_2B9F0__fzgx_offset_0[];
extern u8 lbl_1_data_2BA04__fzgx_offset_0[];
extern u8 lbl_1_data_2BA18__fzgx_offset_0[];
extern u8 lbl_1_data_2BA2C__fzgx_offset_0[];
extern u8 lbl_1_data_2BA40__fzgx_offset_0[];
extern u8 lbl_1_data_2BA4C__fzgx_offset_0[];
extern u8 lbl_1_data_2BA58__fzgx_offset_0[];
extern u8 lbl_1_data_2BA64__fzgx_offset_0[];
extern u8 lbl_1_data_2BA70__fzgx_offset_0[];
extern u8 lbl_1_data_2BA80__fzgx_offset_0[];
extern u8 lbl_1_data_2BA94__fzgx_offset_0[];
extern u8 lbl_1_data_2BAA8__fzgx_offset_0[];
extern u8 lbl_1_data_2BABC__fzgx_offset_0[];
extern u8 lbl_1_data_2BAD0__fzgx_offset_0[];
extern u8 lbl_1_data_2BAE8__fzgx_offset_0[];
extern u8 lbl_1_data_2BAFC__fzgx_offset_0[];
extern u8 lbl_1_data_2BB10__fzgx_offset_0[];
extern u8 lbl_1_data_2BB24__fzgx_offset_0[];
extern u8 lbl_1_data_2BB38__fzgx_offset_0[];
extern u8 lbl_1_data_2BB48__fzgx_offset_0[];
extern u8 lbl_1_data_2BB58__fzgx_offset_0[];
extern u8 lbl_1_data_2BB68__fzgx_offset_0[];
extern u8 lbl_1_data_2BB78__fzgx_offset_0[];
extern u8 lbl_1_data_2BB88__fzgx_offset_0[];
extern u8 lbl_1_data_2BB9C__fzgx_offset_0[];
extern u8 lbl_1_data_2BBB0__fzgx_offset_0[];
extern u8 lbl_1_data_2BBC4__fzgx_offset_0[];
extern u8 lbl_1_data_2BBD8__fzgx_offset_0[];
extern u8 lbl_1_data_2BBEC__fzgx_offset_0[];
extern u8 lbl_1_data_2BC00__fzgx_offset_0[];
extern u8 lbl_1_data_2BC14__fzgx_offset_0[];
extern u8 lbl_1_data_2BC28__fzgx_offset_0[];
extern u8 lbl_1_data_2BC3C__fzgx_offset_0[];
extern u8 lbl_1_data_2BC50__fzgx_offset_0[];
extern u8 lbl_1_data_2BC64__fzgx_offset_0[];
extern u8 lbl_1_data_2BC78__fzgx_offset_0[];
extern u8 lbl_1_data_2BC8C__fzgx_offset_0[];
extern u8 lbl_1_data_2BCA0__fzgx_offset_0[];
extern u8 lbl_1_data_2BCB4__fzgx_offset_0[];
extern u8 lbl_1_data_2BCC4__fzgx_offset_0[];
extern u8 lbl_1_data_2BCD0__fzgx_offset_0[];
extern u8 lbl_1_data_2BCDC__fzgx_offset_0[];
extern u8 lbl_1_data_2BCE8__fzgx_offset_0[];
extern u8 lbl_1_data_2BCF4__fzgx_offset_0[];
extern u8 lbl_1_data_2BD00__fzgx_offset_0[];
extern u8 lbl_1_data_2BD10__fzgx_offset_0[];
extern u8 lbl_1_data_2BD20__fzgx_offset_0[];
extern u8 lbl_1_data_2BD30__fzgx_offset_0[];
extern u8 lbl_1_data_2BD40__fzgx_offset_0[];
extern u8 lbl_1_data_2C7BC__fzgx_offset_0[];
extern u8 lbl_1_data_2C7C0__fzgx_offset_0[];
extern u8 lbl_1_data_2C7E4__fzgx_offset_0[];
extern u8 lbl_1_data_2C7E8__fzgx_offset_0[];
extern u8 lbl_1_data_2C7F0__fzgx_offset_0[];
extern u8 lbl_1_data_2C7F8__fzgx_offset_0[];
extern u8 lbl_1_data_2C804__fzgx_offset_0[];
extern u8 lbl_1_data_2C80C__fzgx_offset_0[];
extern u8 lbl_1_data_2C818__fzgx_offset_0[];
extern u8 lbl_1_data_2C824__fzgx_offset_0[];
extern u8 lbl_1_data_2C86C__fzgx_offset_0[];
extern u8 lbl_1_data_2C870__fzgx_offset_0[];
extern u8 lbl_1_data_2C890__fzgx_offset_0[];
extern u8 lbl_1_data_2C8B0__fzgx_offset_0[];
extern u8 lbl_1_data_2C8D0__fzgx_offset_0[];
extern u8 lbl_1_data_2CB8C__fzgx_offset_0[];
extern u8 lbl_1_data_2CBDC__fzgx_offset_0[];
extern u8 lbl_1_data_2CC68__fzgx_offset_0[];
extern u8 lbl_1_data_2CC70__fzgx_offset_0[];
extern u8 lbl_1_data_2CC90__fzgx_offset_0[];
extern u8 lbl_1_data_2CC9C__fzgx_offset_0[];
static u32 fzgx_pool_data_lbl_1_data_2A0C0[456] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4F43455F, 0x4C494748, 0x544D4150, 0x5F410000, 0x4F43455F, 0x57415645, 0x5F504154, 0x5F420000,
    0x4F43455F, 0x4E414D49, 0x5F000000, 0x4F434E5F, 0x504F4F4C, 0x0, 0x42494742, 0x4C55455F,
    0x52454E5A, 0x5F465245, 0x41303100, 0x1, (u32)lbl_1_data_2A0C0__fzgx_offset_0, 0x1, (u32)lbl_1_data_2A0D0__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A0E0__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A0EC__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A0F8__fzgx_offset_0, 0x3, 0x0, 0x5F6C746D,
    0x70000000, 0x5F6C746D, 0x70320000, 0x4F43455F, 0x43415343, 0x4144455F, 0x0, 0x4F43455F,
    0x4332375F, 0x43415343, 0x41444500, 0x43554245, 0x5F474154, 0x455F415F, 0x4C4F4400, 0x43554245,
    0x5F425F41, 0x5F4C4F44, 0x0, 0x43554245, 0x5F445F41, 0x5F4C4F44, 0x0, 0x42494742,
    0x4C55455F, 0x53554E30, 0x31000000, 0x2, (u32)lbl_1_data_2A13C__fzgx_offset_0, 0x2, (u32)lbl_1_data_2A144__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A14C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A15C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A0EC__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A16C__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A17C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A18C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A19C__fzgx_offset_0, 0x3, 0x0, 0x5F5F5F00,
    0x1, (u32)lbl_1_data_2A1FC__fzgx_offset_0, 0x3, 0x0, 0x5041544C, 0x414D505F, 0x41000000, 0x5041544C,
    0x414D505F, 0x42000000, 0x5041544C, 0x414D505F, 0x43000000, 0x5041544C, 0x414D505F, 0x44000000,
    0x424E535F, 0x534B595F, 0x4B554D4F, 0x5F000000, 0x4C49475F, 0x47524F55, 0x4E445F41, 0x0,
    0x4330385F, 0x5241494E, 0x524F4144, 0x0, 0x4330395F, 0x5241494E, 0x524F4144, 0x0,
    0x4332335F, 0x5241494E, 0x524F4144, 0x0, 0x4333345F, 0x5241494E, 0x524F4144, 0x0,
    0x52455041, 0x4952504F, 0x494E5400, 0x0, (u32)lbl_1_data_2A210__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A21C__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A228__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A234__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A240__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A250__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A260__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A270__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A280__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A290__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A2A0__fzgx_offset_0, 0x3, 0x0, 0x3, 0x0, 0x464C4147, 0x0, 0x0,
    (u32)lbl_1_data_2A314__fzgx_offset_0, 0x3, 0x0, 0x464F525F, 0x4546465F, 0x48413031, 0x0, 0x464F525F,
    0x52454E5A, 0x5F465245, 0x41000000, 0x464F525F, 0x4546465F, 0x47524E4C, 0x49470000, 0x1,
    (u32)lbl_1_data_2A32C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A33C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A34C__fzgx_offset_0, 0x3, 0x0, 0x464F525F,
    0x53554E00, 0x0, (u32)lbl_1_data_2A37C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A210__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A21C__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A228__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A234__fzgx_offset_0, 0x3, 0x0, 0x1, (u32)lbl_1_data_2A1FC__fzgx_offset_0, 0x3,
    0x0, 0x535F5348, 0x49500000, 0x0, (u32)lbl_1_data_2A3C4__fzgx_offset_0, 0x3, 0x0, 0x53414E5F,
    0x57415645, 0x5F504154, 0x5F4D0000, 0x53414E5F, 0x57415645, 0x5F504154, 0x5F530000, 0x474F524F,
    0x46524147, 0x5F767478, 0x0, 0x474F524F, 0x46524147, 0x325F7674, 0x78000000, 0x1,
    (u32)lbl_1_data_2A3DC__fzgx_offset_0, 0x1, (u32)lbl_1_data_2A3EC__fzgx_offset_0, 0x1, (u32)lbl_1_data_2A3FC__fzgx_offset_0, 0x1, (u32)lbl_1_data_2A40C__fzgx_offset_0, 0x3,
    0x0, 0x0, (u32)lbl_1_data_2A210__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A21C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A228__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A234__fzgx_offset_0, 0x3, 0x0, 0x3, 0x0, 0x3, 0x0, 0x44494345,
    0x0, 0x0, (u32)lbl_1_data_2A47C__fzgx_offset_0, 0x3, 0x0, 0x434F494E, 0x0, 0x0,
    (u32)lbl_1_data_2A494__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A47C__fzgx_offset_0, 0x3, 0x0, 0x4D45545F, 0x434F4D45, 0x54303200,
    0x4546465F, 0x524F434B, 0x46495245, 0x5F415F52, 0x32533100, 0x4546465F, 0x524F434B, 0x46495245,
    0x5F425F52, 0x32533100, 0x1, (u32)lbl_1_data_2A4B4__fzgx_offset_0, 0x1, (u32)lbl_1_data_2A4C0__fzgx_offset_0, 0x1, (u32)lbl_1_data_2A4D4__fzgx_offset_0,
    0x3, 0x0, 0x4D45545F, 0x42494753, 0x54415230, 0x31000000, 0x0, (u32)lbl_1_data_2A508__fzgx_offset_0,
    0x3, 0x0, 0x3, 0x0, 0x454C565F, 0x544F5000, 0x454C565F, 0x434F4C4F,
    0x4E590000, 0x454C565F, 0x544F5745, 0x52424153, 0x4530315F, 0x415F4C4F, 0x44000000, 0x454C565F,
    0x43415247, 0x4F30315F, 0x415F4C4F, 0x44000000, 0x454C565F, 0x424F5830, 0x315F415F, 0x4C4F4400,
    0x0, (u32)lbl_1_data_2A210__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A21C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A228__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A234__fzgx_offset_0,
    0x0, (u32)lbl_1_data_2A530__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A538__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A544__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A55C__fzgx_offset_0,
    0x0, (u32)lbl_1_data_2A570__fzgx_offset_0, 0x3, 0x0, 0x57494E44, 0x4F573031, 0x0, 0x0,
    (u32)lbl_1_data_2A5D0__fzgx_offset_0, 0x3, 0x0, 0x53454152, 0x43483031, 0x0, 0x53454152, 0x43485F41,
    0x524D3031, 0x0, 0x53454152, 0x43485F41, 0x524D3032, 0x0, 0x5343414D, 0x504F494E,
    0x54303100, 0x464C4153, 0x48303100, 0x0, (u32)lbl_1_data_2A5D0__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A5EC__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A5F8__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A608__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A618__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A624__fzgx_offset_0, 0x3,
    0x0, 0x3, 0x0, 0x43554245, 0x0, 0x0, (u32)lbl_1_data_2A66C__fzgx_offset_0, 0x3,
    0x0, 0x4654565F, 0x4C4F474F, 0x0, 0x4654565F, 0x52494E47, 0x0, 0x4654565F,
    0x52494E47, 0x5F460000, 0x4654565F, 0x45415254, 0x48000000, 0x4654565F, 0x52494E47, 0x5F540000,
    0x0, (u32)lbl_1_data_2A684__fzgx_offset_0, 0x1, (u32)lbl_1_data_2A690__fzgx_offset_0, 0x1, (u32)lbl_1_data_2A69C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A6A8__fzgx_offset_0,
    0x1, (u32)lbl_1_data_2A6B4__fzgx_offset_0, 0x3, 0x0, 0x43415244, 0x49535000, 0x47414C44, 0x49535000,
    0x57494E4E, 0x45523031, 0x0, 0x57494E4E, 0x45523032, 0x0, 0x57494E4E, 0x45523033,
    0x0, 0x57494E4E, 0x45523034, 0x0, 0x48594F55, 0x53594F55, 0x53504F54, 0x0,
    0x48594F55, 0x53594F55, 0x0, 0x4D55545F, 0x47524F55, 0x4E440000, 0x4D55545F, 0x53544152,
    0x53000000, 0x4D55545F, 0x43495459, 0x5F4C4947, 0x48545300, 0x0, (u32)lbl_1_data_2A6F0__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A6F8__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A700__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A70C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A718__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A724__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A730__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A740__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A74C__fzgx_offset_0, 0x0,
    (u32)lbl_1_data_2A758__fzgx_offset_0, 0x0, (u32)lbl_1_data_2A764__fzgx_offset_0, 0x3, 0x0, 0x0, 0x0, 0x0
};
static u32 fzgx_pool_data_lbl_1_data_2A7E0[62] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x8080, 0x80000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};
static u32 fzgx_pool_data_lbl_1_data_2A8D8[2280] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_1_data_1E968__fzgx_offset_0, (u32)lbl_1_data_1E974__fzgx_offset_0, (u32)lbl_1_data_1E980__fzgx_offset_0, (u32)lbl_1_data_1E98C__fzgx_offset_0, (u32)lbl_1_data_1E998__fzgx_offset_0, (u32)lbl_1_data_1E9A4__fzgx_offset_0, (u32)lbl_1_data_1E9B0__fzgx_offset_0, (u32)lbl_1_data_1E9BC__fzgx_offset_0,
    (u32)lbl_1_data_1E9C8__fzgx_offset_0, (u32)lbl_1_data_1E9D4__fzgx_offset_0, (u32)lbl_1_data_1E9E0__fzgx_offset_0, (u32)lbl_1_data_1E9EC__fzgx_offset_0, (u32)lbl_1_data_1E9F8__fzgx_offset_0, (u32)lbl_1_data_1EA04__fzgx_offset_0, (u32)lbl_1_data_1EA10__fzgx_offset_0, (u32)lbl_1_data_1EA1C__fzgx_offset_0,
    (u32)lbl_1_data_1EA34__fzgx_offset_0, (u32)lbl_1_data_1EA40__fzgx_offset_0, (u32)lbl_1_data_1EA4C__fzgx_offset_0, (u32)lbl_1_data_1EA58__fzgx_offset_0, (u32)lbl_1_data_1EA64__fzgx_offset_0, (u32)lbl_1_data_1ED48__fzgx_offset_0, (u32)lbl_1_data_1ED54__fzgx_offset_0, (u32)lbl_1_data_1ED60__fzgx_offset_0,
    (u32)lbl_1_data_1ED6C__fzgx_offset_0, (u32)lbl_1_data_1ED78__fzgx_offset_0, (u32)lbl_1_data_1ED84__fzgx_offset_0, (u32)lbl_1_data_1ED90__fzgx_offset_0, (u32)lbl_1_data_1ED9C__fzgx_offset_0, (u32)lbl_1_data_1EDA8__fzgx_offset_0, (u32)lbl_1_data_1EDB4__fzgx_offset_0, (u32)lbl_1_data_1EDC0__fzgx_offset_0,
    (u32)lbl_1_data_1EDCC__fzgx_offset_0, (u32)lbl_1_data_1EDD8__fzgx_offset_0, (u32)lbl_1_data_1EDE4__fzgx_offset_0, (u32)lbl_1_data_1EDF0__fzgx_offset_0, (u32)lbl_1_data_1EDFC__fzgx_offset_0, (u32)lbl_1_data_1EE08__fzgx_offset_0, (u32)lbl_1_data_1EE14__fzgx_offset_0, (u32)lbl_1_data_1EE20__fzgx_offset_0,
    (u32)lbl_1_data_1EE2C__fzgx_offset_0, (u32)lbl_1_data_1EE38__fzgx_offset_0, 0x4E554C4C, 0x0, 0x4D555445, 0x20434954, 0x59000000, 0x504F5254,
    0x20544F57, 0x4E000000, 0x42494720, 0x424C5545, 0x0, 0x4C494748, 0x544E494E, 0x47000000,
    0x53414E44, 0x204F4345, 0x414E0000, 0x47524545, 0x4E20504C, 0x414E5400, 0x46495245, 0x20464945,
    0x4C440000, 0x43415349, 0x4E4F2050, 0x414C4143, 0x45000000, 0x4F555445, 0x52205350, 0x41434500,
    0x4145524F, 0x504F4C49, 0x53000000, 0x434F534D, 0x4F205445, 0x524D494E, 0x414C0000, 0x5048414E,
    0x544F4D20, 0x524F4144, 0x0, (u32)lbl_1_data_2A980__fzgx_offset_0, (u32)lbl_1_data_2A988__fzgx_offset_0, (u32)lbl_1_data_2A994__fzgx_offset_0, (u32)lbl_1_data_2A994__fzgx_offset_0, (u32)lbl_1_data_2A9A0__fzgx_offset_0,
    (u32)lbl_1_data_2A9A0__fzgx_offset_0, (u32)lbl_1_data_2A9AC__fzgx_offset_0, (u32)lbl_1_data_2A9AC__fzgx_offset_0, (u32)lbl_1_data_2A9B8__fzgx_offset_0, (u32)lbl_1_data_2A9B8__fzgx_offset_0, (u32)lbl_1_data_2A9C4__fzgx_offset_0, (u32)lbl_1_data_2A9D0__fzgx_offset_0, (u32)lbl_1_data_2A9D0__fzgx_offset_0,
    (u32)lbl_1_data_2A9DC__fzgx_offset_0, (u32)lbl_1_data_2A9EC__fzgx_offset_0, (u32)lbl_1_data_2A9F8__fzgx_offset_0, (u32)lbl_1_data_2AA04__fzgx_offset_0, (u32)lbl_1_data_2A988__fzgx_offset_0, (u32)lbl_1_data_2A988__fzgx_offset_0, (u32)lbl_1_data_2AA14__fzgx_offset_0, (u32)lbl_1_data_2A988__fzgx_offset_0,
    0x0, 0x837E8385, 0x815B8367, 0x20835683, 0x65834200, 0x837C815B, 0x83672083, 0x5E834583,  /* fzgx-allow: A1 retail data bytes */
    0x93000000, 0x83728362, 0x834F2083, 0x75838B81, 0x5B000000, 0x83898343, 0x8367836A, 0x8393834F,
    0x0, 0x83548393, 0x83682083, 0x49815B83, 0x56838383, 0x93000000, 0x834F838A, 0x815B8393,  /* fzgx-allow: A1 retail data bytes */
    0x20837683, 0x89839383, 0x67000000, 0x83748340, 0x83438341, 0x20837483, 0x42815B83, 0x8B836800,
    0x834A8357, 0x836D2083, 0x70838C83, 0x58000000, 0x83418345, 0x835E815B, 0x20835883, 0x79815B83,
    0x58000000, 0x83478341, 0x838D837C, 0x838A8358, 0x0, 0x83528358, 0x83822083, 0x5E815B83,
    0x7E836983, 0x8B000000, 0x83748340, 0x83938367, 0x83802083, 0x8D815B83, 0x68000000, (u32)lbl_1_data_2A980__fzgx_offset_0,
    (u32)lbl_1_data_2AA7C__fzgx_offset_0, (u32)lbl_1_data_2AA8C__fzgx_offset_0, (u32)lbl_1_data_2AA8C__fzgx_offset_0, (u32)lbl_1_data_2AA9C__fzgx_offset_0, (u32)lbl_1_data_2AA9C__fzgx_offset_0, (u32)lbl_1_data_2AAAC__fzgx_offset_0, (u32)lbl_1_data_2AAAC__fzgx_offset_0, (u32)lbl_1_data_2AABC__fzgx_offset_0,
    (u32)lbl_1_data_2AABC__fzgx_offset_0, (u32)lbl_1_data_2AAD0__fzgx_offset_0, (u32)lbl_1_data_2AAE4__fzgx_offset_0, (u32)lbl_1_data_2AAE4__fzgx_offset_0, (u32)lbl_1_data_2AAF8__fzgx_offset_0, (u32)lbl_1_data_2AB08__fzgx_offset_0, (u32)lbl_1_data_2AB1C__fzgx_offset_0, (u32)lbl_1_data_2AB2C__fzgx_offset_0,
    (u32)lbl_1_data_2AA7C__fzgx_offset_0, (u32)lbl_1_data_2AA7C__fzgx_offset_0, (u32)lbl_1_data_2AB40__fzgx_offset_0, (u32)lbl_1_data_2AA7C__fzgx_offset_0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, (u32)fn_1_1013C0__fzgx_offset_0, (u32)fn_1_1013C4__fzgx_offset_0,
    (u32)fn_1_101400__fzgx_offset_0, (u32)fn_1_101404__fzgx_offset_0, (u32)fn_1_101424__fzgx_offset_0, (u32)fn_1_101428__fzgx_offset_0, (u32)fn_1_101448__fzgx_offset_0, (u32)fn_1_10144C__fzgx_offset_0, (u32)fn_1_101454__fzgx_offset_0, (u32)fn_1_DAD68__fzgx_offset_0,
    (u32)fn_1_DAD6C__fzgx_offset_0, (u32)fn_1_DADA8__fzgx_offset_0, (u32)fn_1_DAE24__fzgx_offset_0, (u32)fn_1_DAEF8__fzgx_offset_0, (u32)fn_1_DAEFC__fzgx_offset_0, (u32)fn_1_DAF90__fzgx_offset_0, (u32)fn_1_DC1B8__fzgx_offset_0, (u32)fn_1_DC1C0__fzgx_offset_0,
    (u32)fn_1_DAD68__fzgx_offset_0, (u32)fn_1_DAD6C__fzgx_offset_0, (u32)fn_1_DADA8__fzgx_offset_0, (u32)fn_1_DAE24__fzgx_offset_0, (u32)fn_1_DAEF8__fzgx_offset_0, (u32)fn_1_DAEFC__fzgx_offset_0, (u32)fn_1_DAF90__fzgx_offset_0, (u32)fn_1_DC1B8__fzgx_offset_0,
    (u32)fn_1_DC1C0__fzgx_offset_0, (u32)fn_1_DA7B8__fzgx_offset_0, (u32)fn_1_DA7E4__fzgx_offset_0, (u32)fn_1_DA9F0__fzgx_offset_0, (u32)fn_1_DAA34__fzgx_offset_0, (u32)fn_1_DAA58__fzgx_offset_0, (u32)fn_1_DAAC4__fzgx_offset_0, (u32)fn_1_DAAF8__fzgx_offset_0,
    (u32)fn_1_DAB5C__fzgx_offset_0, (u32)fn_1_DABB4__fzgx_offset_0, (u32)fn_1_DA7B8__fzgx_offset_0, (u32)fn_1_DA7E4__fzgx_offset_0, (u32)fn_1_DA9F0__fzgx_offset_0, (u32)fn_1_DAA34__fzgx_offset_0, (u32)fn_1_DAA58__fzgx_offset_0, (u32)fn_1_DAAC4__fzgx_offset_0,
    (u32)fn_1_DAAF8__fzgx_offset_0, (u32)fn_1_DAB5C__fzgx_offset_0, (u32)fn_1_DABB4__fzgx_offset_0, (u32)fn_1_D3C00__fzgx_offset_0, (u32)fn_1_D3C04__fzgx_offset_0, (u32)fn_1_D3C58__fzgx_offset_0, (u32)fn_1_D3CF4__fzgx_offset_0, (u32)fn_1_D3DDC__fzgx_offset_0,
    (u32)fn_1_D3E08__fzgx_offset_0, (u32)fn_1_D3E8C__fzgx_offset_0, (u32)fn_1_D5C68__fzgx_offset_0, (u32)fn_1_D5C70__fzgx_offset_0, (u32)fn_1_D3C00__fzgx_offset_0, (u32)fn_1_D3C04__fzgx_offset_0, (u32)fn_1_D3C58__fzgx_offset_0, (u32)fn_1_D3CF4__fzgx_offset_0,
    (u32)fn_1_D3DDC__fzgx_offset_0, (u32)fn_1_D3E08__fzgx_offset_0, (u32)fn_1_D3E8C__fzgx_offset_0, (u32)fn_1_D5C68__fzgx_offset_0, (u32)fn_1_D5C70__fzgx_offset_0, (u32)fn_1_D720C__fzgx_offset_0, (u32)fn_1_D7274__fzgx_offset_0, (u32)fn_1_D744C__fzgx_offset_0,
    (u32)fn_1_D74C4__fzgx_offset_0, (u32)fn_1_D75CC__fzgx_offset_0, (u32)fn_1_D7688__fzgx_offset_0, (u32)fn_1_D76EC__fzgx_offset_0, (u32)fn_1_D8F4C__fzgx_offset_0, (u32)fn_1_D8FC4__fzgx_offset_0, (u32)fn_1_D720C__fzgx_offset_0, (u32)fn_1_D7274__fzgx_offset_0,
    (u32)fn_1_D744C__fzgx_offset_0, (u32)fn_1_D74C4__fzgx_offset_0, (u32)fn_1_D75CC__fzgx_offset_0, (u32)fn_1_D7688__fzgx_offset_0, (u32)fn_1_D76EC__fzgx_offset_0, (u32)fn_1_D8F4C__fzgx_offset_0, (u32)fn_1_D8FC4__fzgx_offset_0, (u32)fn_1_DC204__fzgx_offset_0,
    (u32)fn_1_DC208__fzgx_offset_0, (u32)fn_1_DC264__fzgx_offset_0, (u32)fn_1_DC268__fzgx_offset_0, (u32)fn_1_DC2F8__fzgx_offset_0, (u32)fn_1_DC33C__fzgx_offset_0, (u32)fn_1_DC3A0__fzgx_offset_0, (u32)fn_1_DCB9C__fzgx_offset_0, (u32)fn_1_DCBF4__fzgx_offset_0,
    (u32)fn_1_F5AAC__fzgx_offset_0, (u32)fn_1_F5AB0__fzgx_offset_0, (u32)fn_1_F5AEC__fzgx_offset_0, (u32)fn_1_F5AF0__fzgx_offset_0, (u32)fn_1_F5B38__fzgx_offset_0, (u32)fn_1_F5B3C__fzgx_offset_0, (u32)fn_1_F5B84__fzgx_offset_0, (u32)fn_1_F70C0__fzgx_offset_0,
    (u32)fn_1_F70C8__fzgx_offset_0, (u32)fn_1_F5AAC__fzgx_offset_0, (u32)fn_1_F5AB0__fzgx_offset_0, (u32)fn_1_F5AEC__fzgx_offset_0, (u32)fn_1_F5AF0__fzgx_offset_0, (u32)fn_1_F5B38__fzgx_offset_0, (u32)fn_1_F5B3C__fzgx_offset_0, (u32)fn_1_F5B84__fzgx_offset_0,
    (u32)fn_1_F70C0__fzgx_offset_0, (u32)fn_1_F70C8__fzgx_offset_0, (u32)fn_1_FA6C0__fzgx_offset_0, (u32)fn_1_FA75C__fzgx_offset_0, (u32)fn_1_FA82C__fzgx_offset_0, (u32)fn_1_FA830__fzgx_offset_0, (u32)fn_1_FA854__fzgx_offset_0, (u32)fn_1_FA878__fzgx_offset_0,
    (u32)fn_1_FA898__fzgx_offset_0, (u32)fn_1_FB770__fzgx_offset_0, (u32)fn_1_FB798__fzgx_offset_0, (u32)fn_1_FE5E0__fzgx_offset_0, (u32)fn_1_FE5E4__fzgx_offset_0, (u32)fn_1_FE640__fzgx_offset_0, (u32)fn_1_FE644__fzgx_offset_0, (u32)fn_1_FE780__fzgx_offset_0,
    (u32)fn_1_FE784__fzgx_offset_0, (u32)fn_1_FE7D4__fzgx_offset_0, (u32)fn_1_101348__fzgx_offset_0, (u32)fn_1_1013A0__fzgx_offset_0, (u32)fn_1_153988__fzgx_offset_0, (u32)fn_1_15398C__fzgx_offset_0, (u32)fn_1_1539D0__fzgx_offset_0, (u32)fn_1_153A28__fzgx_offset_0,
    (u32)fn_1_153AAC__fzgx_offset_0, (u32)fn_1_153AB0__fzgx_offset_0, (u32)fn_1_153AF4__fzgx_offset_0, (u32)fn_1_1543E8__fzgx_offset_0, (u32)fn_1_154410__fzgx_offset_0, (u32)fn_1_150500__fzgx_offset_0, (u32)fn_1_150518__fzgx_offset_0, (u32)fn_1_150570__fzgx_offset_0,
    (u32)fn_1_1505B4__fzgx_offset_0, (u32)fn_1_150574__fzgx_offset_0, (u32)fn_1_150608__fzgx_offset_0, (u32)fn_1_150650__fzgx_offset_0, (u32)fn_1_151764__fzgx_offset_0, (u32)fn_1_15176C__fzgx_offset_0, (u32)fn_1_1013C0__fzgx_offset_0, (u32)fn_1_1013C4__fzgx_offset_0,
    (u32)fn_1_101400__fzgx_offset_0, (u32)fn_1_101404__fzgx_offset_0, (u32)fn_1_101424__fzgx_offset_0, (u32)fn_1_101428__fzgx_offset_0, (u32)fn_1_101448__fzgx_offset_0, (u32)fn_1_10144C__fzgx_offset_0, (u32)fn_1_101454__fzgx_offset_0, (u32)fn_1_1013C0__fzgx_offset_0,
    (u32)fn_1_1013C4__fzgx_offset_0, (u32)fn_1_101400__fzgx_offset_0, (u32)fn_1_101404__fzgx_offset_0, (u32)fn_1_101424__fzgx_offset_0, (u32)fn_1_101428__fzgx_offset_0, (u32)fn_1_101448__fzgx_offset_0, (u32)fn_1_10144C__fzgx_offset_0, (u32)fn_1_101454__fzgx_offset_0,
    (u32)fn_1_1586A8__fzgx_offset_0, (u32)fn_1_1586AC__fzgx_offset_0, (u32)fn_1_158980__fzgx_offset_0, (u32)fn_1_158984__fzgx_offset_0, (u32)fn_1_15903C__fzgx_offset_0, (u32)fn_1_159040__fzgx_offset_0, (u32)fn_1_159060__fzgx_offset_0, (u32)fn_1_159064__fzgx_offset_0,
    (u32)fn_1_15906C__fzgx_offset_0, (u32)fn_1_15B428__fzgx_offset_0, (u32)fn_1_15B42C__fzgx_offset_0, (u32)fn_1_15B4F8__fzgx_offset_0, (u32)fn_1_15B4FC__fzgx_offset_0, (u32)fn_1_15B51C__fzgx_offset_0, (u32)fn_1_15B520__fzgx_offset_0, (u32)fn_1_15B540__fzgx_offset_0,
    (u32)fn_1_15B698__fzgx_offset_0, (u32)fn_1_15B70C__fzgx_offset_0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x62675F6D, 0x75740000, 0x62675F70, 0x6F720000, 0x62675F70,
    0x6F725F73, 0x0, 0x62675F62, 0x69670000, 0x62675F62, 0x69675F73, 0x0, 0x62675F6C,
    0x69670000, 0x62675F73, 0x616E0000, 0x62675F73, 0x616E5F73, 0x0, 0x62675F66, 0x6F720000,
    0x62675F66, 0x69720000, 0x62675F66, 0x69725F73, 0x0, 0x62675F63, 0x61730000, 0x62675F6D,
    0x65740000, 0x62675F74, 0x6F770000, 0x62675F65, 0x6C650000, 0x62675F63, 0x6F6D0000, 0x62675F63,
    0x6F6D5F73, 0x0, 0x62675F72, 0x61690000, 0x62675F77, 0x696E5F67, 0x78000000, 0x0,
    (u32)lbl_1_data_2AEC4__fzgx_offset_0, (u32)lbl_1_data_2AECC__fzgx_offset_0, (u32)lbl_1_data_2AED4__fzgx_offset_0, (u32)lbl_1_data_2AEE0__fzgx_offset_0, (u32)lbl_1_data_2AEE8__fzgx_offset_0, (u32)lbl_1_data_2AEF4__fzgx_offset_0, (u32)lbl_1_data_2AEF4__fzgx_offset_0, (u32)lbl_1_data_2AEFC__fzgx_offset_0,
    (u32)lbl_1_data_2AF04__fzgx_offset_0, (u32)lbl_1_data_2AF10__fzgx_offset_0, (u32)lbl_1_data_2AF18__fzgx_offset_0, (u32)lbl_1_data_2AF20__fzgx_offset_0, (u32)lbl_1_data_2AF2C__fzgx_offset_0, (u32)lbl_1_data_2AF34__fzgx_offset_0, (u32)lbl_1_data_2AF3C__fzgx_offset_0, (u32)lbl_1_data_2AF44__fzgx_offset_0,
    (u32)lbl_1_data_2AF4C__fzgx_offset_0, (u32)lbl_1_data_2AF54__fzgx_offset_0, (u32)lbl_1_data_2AF60__fzgx_offset_0, (u32)lbl_1_data_2AF68__fzgx_offset_0, 0x0, 0x0, 0x4, 0x202C0,
    0x202C0, 0x18B0, 0x18B0, 0xFD80, 0xFD80, 0x1C60, 0x1C60, 0x226C,
    0x764, 0x764, 0x174, 0x1B1E8, 0x1704, 0x2748, 0x4, 0x4,
    0x157CC, 0x128, 0x0, 0x0, (u32)lbl_1_data_2A30C__fzgx_offset_0, (u32)lbl_1_data_2A3B4__fzgx_offset_0, (u32)lbl_1_data_2A3B4__fzgx_offset_0, (u32)lbl_1_data_2A10C__fzgx_offset_0,
    (u32)lbl_1_data_2A10C__fzgx_offset_0, (u32)lbl_1_data_2A200__fzgx_offset_0, (u32)lbl_1_data_2A200__fzgx_offset_0, (u32)lbl_1_data_2A41C__fzgx_offset_0, (u32)lbl_1_data_2A41C__fzgx_offset_0, (u32)lbl_1_data_2A35C__fzgx_offset_0, (u32)lbl_1_data_2A46C__fzgx_offset_0, (u32)lbl_1_data_2A46C__fzgx_offset_0,
    (u32)lbl_1_data_2A484__fzgx_offset_0, (u32)lbl_1_data_2A4E8__fzgx_offset_0, (u32)lbl_1_data_2A5DC__fzgx_offset_0, (u32)lbl_1_data_2A528__fzgx_offset_0, (u32)lbl_1_data_2A30C__fzgx_offset_0, (u32)lbl_1_data_2A30C__fzgx_offset_0, (u32)lbl_1_data_2A664__fzgx_offset_0, (u32)lbl_1_data_2A6C0__fzgx_offset_0,
    0x0, 0x0, (u32)lbl_1_data_2A31C__fzgx_offset_0, (u32)lbl_1_data_2A3CC__fzgx_offset_0, (u32)lbl_1_data_2A3CC__fzgx_offset_0, (u32)lbl_1_data_2A1AC__fzgx_offset_0, (u32)lbl_1_data_2A1AC__fzgx_offset_0, (u32)lbl_1_data_2A2AC__fzgx_offset_0,
    (u32)lbl_1_data_2A2AC__fzgx_offset_0, (u32)lbl_1_data_2A444__fzgx_offset_0, (u32)lbl_1_data_2A444__fzgx_offset_0, (u32)lbl_1_data_2A384__fzgx_offset_0, (u32)lbl_1_data_2A474__fzgx_offset_0, (u32)lbl_1_data_2A474__fzgx_offset_0, (u32)lbl_1_data_2A49C__fzgx_offset_0, (u32)lbl_1_data_2A518__fzgx_offset_0,
    (u32)lbl_1_data_2A62C__fzgx_offset_0, (u32)lbl_1_data_2A580__fzgx_offset_0, (u32)lbl_1_data_2A31C__fzgx_offset_0, (u32)lbl_1_data_2A31C__fzgx_offset_0, (u32)lbl_1_data_2A674__fzgx_offset_0, (u32)lbl_1_data_2A774__fzgx_offset_0, 0x0, 0x8010101,
    0x10F0202, 0x6060A0A, 0x602040B, 0xD0B0B0E, 0xE0F1006, 0x10080804, 0x130D080F, 0xE02060A,
    0x1112090D, 0x5070301, 0xC130000, 0x141400, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x10202, 0x3030404, 0x5050607, 0x708090A, 0xB0C0C0D,
    0x1000000, 0x2D2D2D00, 0x54776973, 0x7420526F, 0x61640000, 0x53657269, 0x616C2047, 0x61707300,
    0x4D756C74, 0x69706C65, 0x78000000, 0x4165726F, 0x20446976, 0x65000000, 0x4C6F6F70, 0x2043726F,
    0x73730000, 0x48616C66, 0x20506970, 0x65000000, 0x496E7465, 0x72736563, 0x74696F6E, 0x0,
    0x4D6F6269, 0x75732052, 0x696E6700, 0x4C6F6E67, 0x20506970, 0x65000000, 0x44726966, 0x74204869,
    0x67687761, 0x79000000, 0x43796C69, 0x6E646572, 0x204B6E6F, 0x74000000, 0x53706C69, 0x74204F76,
    0x616C0000, 0x556E6475, 0x6C617469, 0x6F6E0000, 0x44726167, 0x6F6E2053, 0x6C6F7065, 0x0,
    0x54726964, 0x656E7400, 0x4C617465, 0x72616C20, 0x53686966, 0x74000000, 0x53757266, 0x61636520,
    0x536C6964, 0x65000000, 0x4F726465, 0x616C0000, 0x536C696D, 0x2D6C696E, 0x6520536C, 0x69747300,
    0x446F7562, 0x6C652042, 0x72616E63, 0x68657300, 0x53637265, 0x77204472, 0x69766500, 0x4D657465,
    0x6F722053, 0x74726561, 0x6D000000, 0x43796C69, 0x6E646572, 0x20576176, 0x65000000, 0x5468756E,
    0x64657220, 0x526F6164, 0x0, 0x53706972, 0x616C0000, 0x536F6E69, 0x63204F76, 0x616C0000,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B160__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B16C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B178__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B184__fzgx_offset_0,
    (u32)lbl_1_data_2B190__fzgx_offset_0, (u32)lbl_1_data_2B19C__fzgx_offset_0, (u32)lbl_1_data_2B1A8__fzgx_offset_0, (u32)lbl_1_data_2B1B8__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B1C4__fzgx_offset_0, (u32)lbl_1_data_2B1D0__fzgx_offset_0, (u32)lbl_1_data_2B1E0__fzgx_offset_0,
    (u32)lbl_1_data_2B1F0__fzgx_offset_0, (u32)lbl_1_data_2B1FC__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B208__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B218__fzgx_offset_0, (u32)lbl_1_data_2B220__fzgx_offset_0, (u32)lbl_1_data_2B230__fzgx_offset_0, (u32)lbl_1_data_2B240__fzgx_offset_0, (u32)lbl_1_data_2B248__fzgx_offset_0, (u32)lbl_1_data_2B258__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B268__fzgx_offset_0,
    (u32)lbl_1_data_2B274__fzgx_offset_0, (u32)lbl_1_data_2B284__fzgx_offset_0, (u32)lbl_1_data_2B294__fzgx_offset_0, (u32)lbl_1_data_2B2A4__fzgx_offset_0, (u32)lbl_1_data_2B2AC__fzgx_offset_0, (u32)lbl_1_data_2B2AC__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, 0x96A292E8,
    0x0, 0x47455220, 0x54776973, 0x7420526F, 0x61640000, 0x46524520, 0x54776973, 0x7420526F,
    0x61640000, 0x53504120, 0x54776973, 0x7420526F, 0x61640000, 0x49544120, 0x54776973, 0x7420526F,
    0x61640000, 0x83638343, 0x83588367, 0x838D815B, 0x83680000, 0x47455220, 0x53657269, 0x616C2047,
    0x61707300, 0x46524520, 0x53657269, 0x616C2047, 0x61707300, 0x53504120, 0x53657269, 0x616C2047,
    0x61707300, 0x49544120, 0x53657269, 0x616C2047, 0x61707300, 0x8356838A, 0x8341838B, 0x834D8383,
    0x83628376, 0x0, 0x47455220, 0x4D756C74, 0x69706C65, 0x78000000, 0x46524520, 0x4D756C74,
    0x69706C65, 0x78000000, 0x53504120, 0x4D756C74, 0x69706C65, 0x78000000, 0x49544120, 0x4D756C74,
    0x69706C65, 0x78000000, 0x837D838B, 0x83608376, 0x838C8362, 0x834E8358, 0x0, 0x47455220,
    0x4165726F, 0x20446976, 0x65000000, 0x46524520, 0x4165726F, 0x20446976, 0x65000000, 0x53504120,
    0x4165726F, 0x20446976, 0x65000000, 0x49544120, 0x4165726F, 0x20446976, 0x65000000, 0x83478341,
    0x838D835F, 0x83438375, 0x0, 0x47455220, 0x4C6F6F70, 0x2043726F, 0x73730000, 0x46524520,
    0x4C6F6F70, 0x2043726F, 0x73730000, 0x53504120, 0x4C6F6F70, 0x2043726F, 0x73730000, 0x49544120,
    0x4C6F6F70, 0x2043726F, 0x73730000, 0x838B815B, 0x8376834E, 0x838D8358, 0x0, 0x47455220,
    0x48616C66, 0x20506970, 0x65000000, 0x46524520, 0x48616C66, 0x20506970, 0x65000000, 0x53504120,
    0x48616C66, 0x20506970, 0x65000000, 0x49544120, 0x48616C66, 0x20506970, 0x65000000, 0x836E815B,
    0x83748370, 0x83438376, 0x0, 0x47455220, 0x496E7465, 0x72736563, 0x74696F6E, 0x0,
    0x46524520, 0x496E7465, 0x72736563, 0x74696F6E, 0x0, 0x53504120, 0x496E7465, 0x72736563,
    0x74696F6E, 0x0, 0x49544120, 0x496E7465, 0x72736563, 0x74696F6E, 0x0, 0x83438393,
    0x835E815B, 0x835A834E, 0x83568387, 0x83930000, 0x47455220, 0x4D6F6269, 0x75732052, 0x696E6700,
    0x46524520, 0x4D6F6269, 0x75732052, 0x696E6700, 0x53504120, 0x4D6F6269, 0x75732052, 0x696E6700,
    0x49544120, 0x4D6F6269, 0x75732052, 0x696E6700, 0x83818372, 0x83458358, 0x838A8393, 0x834F0000,
    0x47455220, 0x4C6F6E67, 0x20506970, 0x65000000, 0x46524520, 0x4C6F6E67, 0x20506970, 0x65000000,
    0x53504120, 0x4C6F6E67, 0x20506970, 0x65000000, 0x49544120, 0x4C6F6E67, 0x20506970, 0x65000000,
    0x838D8393, 0x834F8370, 0x83438376, 0x0, 0x47455220, 0x44726966, 0x74204869, 0x67687761,
    0x79000000, 0x46524520, 0x44726966, 0x74204869, 0x67687761, 0x79000000, 0x53504120, 0x44726966,
    0x74204869, 0x67687761, 0x79000000, 0x49544120, 0x44726966, 0x74204869, 0x67687761, 0x79000000,
    0x8368838A, 0x83748367, 0x836E8343, 0x83458346, 0x83430000, 0x47455220, 0x43796C69, 0x6E646572,
    0x204B6E6F, 0x74000000, 0x46524520, 0x43796C69, 0x6E646572, 0x204B6E6F, 0x74000000, 0x53504120,
    0x43796C69, 0x6E646572, 0x204B6E6F, 0x74000000, 0x49544120, 0x43796C69, 0x6E646572, 0x204B6E6F,
    0x74000000, 0x8356838A, 0x8393835F, 0x815B836D, 0x83628367, 0x0, 0x47455220, 0x53706C69,  /* fzgx-allow: A1 retail data bytes */
    0x74204F76, 0x616C0000, 0x46524520, 0x53706C69, 0x74204F76, 0x616C0000, 0x53504120, 0x53706C69,
    0x74204F76, 0x616C0000, 0x49544120, 0x53706C69, 0x74206F76, 0x616C0000, 0x83588376, 0x838A8362,
    0x83678349, 0x815B836F, 0x838B0000, 0x47455220, 0x556E6475, 0x6C617469, 0x6F6E0000, 0x46524520,  /* fzgx-allow: A1 retail data bytes */
    0x556E6475, 0x6C617469, 0x6F6E0000, 0x53504120, 0x556E6475, 0x6C617469, 0x6F6E0000, 0x49544120,
    0x556E6475, 0x6C617469, 0x6F6E0000, 0x83418393, 0x83668385, 0x838C815B, 0x83568387, 0x83930000,
    0x47455220, 0x44726167, 0x6F6E2053, 0x6C6F7065, 0x0, 0x46524520, 0x44726167, 0x6F6E2053,
    0x6C6F7065, 0x0, 0x53504120, 0x44726167, 0x6F6E2053, 0x6C6F7065, 0x0, 0x49544120,
    0x44726167, 0x6F6E2053, 0x6C6F7065, 0x0, 0x83688389, 0x83538393, 0x8358838D, 0x815B8376,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x47455220, 0x54726964, 0x656E7400, 0x46524520, 0x54726964, 0x656E7400, 0x53504120,
    0x54726964, 0x656E7400, 0x49544120, 0x54726964, 0x656E7400, 0x83678389, 0x83438366, 0x83938367,
    0x0, 0x47455220, 0x4C617465, 0x72616C20, 0x53686966, 0x74000000, 0x46524520, 0x4C617465,
    0x72616C20, 0x53686966, 0x74000000, 0x53504120, 0x4C617465, 0x72616C20, 0x53686966, 0x74000000,
    0x49544120, 0x4C617465, 0x72616C20, 0x53686966, 0x74000000, 0x83898365, 0x8389838B, 0x83568374,
    0x83670000, 0x47455220, 0x53757266, 0x61636520, 0x536C6964, 0x65000000, 0x46524520, 0x53757266,
    0x61636520, 0x536C6964, 0x65000000, 0x53504120, 0x53757266, 0x61636520, 0x536C6964, 0x65000000,
    0x49544120, 0x53757266, 0x61636520, 0x536C6964, 0x65000000, 0x8354815B, 0x83748346, 0x83588358,
    0x83898343, 0x83680000, 0x47455220, 0x4F726465, 0x616C0000, 0x46524520, 0x4F726465, 0x616C0000,
    0x53504120, 0x4F726465, 0x616C0000, 0x49544120, 0x4F726465, 0x616C0000, 0x8349815B, 0x83668342,
    0x815B838B, 0x0, 0x47455220, 0x536C696D, 0x2D6C696E, 0x6520536C, 0x69747300, 0x46524520,  /* fzgx-allow: A1 retail data bytes */
    0x536C696D, 0x2D6C696E, 0x6520536C, 0x69747300, 0x53504120, 0x536C696D, 0x2D6C696E, 0x6520536C,
    0x69747300, 0x49544120, 0x536C696D, 0x2D6C696E, 0x6520536C, 0x69747300, 0x8358838A, 0x83808389,
    0x83438393, 0x8358838A, 0x83628367, 0x0, 0x47455220, 0x446F7562, 0x6C652042, 0x72616E63,
    0x68657300, 0x46524520, 0x446F7562, 0x6C652042, 0x72616E63, 0x68657300, 0x53504120, 0x446F7562,
    0x6C652042, 0x72616E63, 0x68657300, 0x49544120, 0x446F7562, 0x6C652042, 0x72616E63, 0x68657300,
    0x835F8375, 0x838B8375, 0x83898393, 0x83600000, 0x47455220, 0x53637265, 0x77204472, 0x69766500,
    0x46524520, 0x53637265, 0x77204472, 0x69766500, 0x53504120, 0x53637265, 0x77204472, 0x69766500,
    0x49544120, 0x53637265, 0x77204472, 0x69766500, 0x8358834E, 0x838A8385, 0x815B8368, 0x83898343,  /* fzgx-allow: A1 retail data bytes */
    0x83750000, 0x47455220, 0x4D657465, 0x6F722053, 0x74726561, 0x6D000000, 0x46524520, 0x4D657465,
    0x6F722053, 0x74726561, 0x6D000000, 0x53504120, 0x4D657465, 0x6F722053, 0x74726561, 0x6D000000,
    0x49544120, 0x4D657465, 0x6F722053, 0x74726561, 0x6D000000, 0x83818365, 0x83498358, 0x8367838A,
    0x815B8380, 0x0, 0x47455220, 0x43796C69, 0x6E646572, 0x20576176, 0x65000000, 0x46524520,  /* fzgx-allow: A1 retail data bytes */
    0x43796C69, 0x6E646572, 0x20576176, 0x65000000, 0x53504120, 0x43796C69, 0x6E646572, 0x20576176,
    0x65000000, 0x49544120, 0x43796C69, 0x6E646572, 0x20576176, 0x65000000, 0x8356838A, 0x8393835F,
    0x815B8345, 0x8346815B, 0x83750000, 0x47455220, 0x5468756E, 0x64657220, 0x526F6164, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x46524520, 0x5468756E, 0x64657220, 0x526F6164, 0x0, 0x53504120, 0x5468756E, 0x64657220,
    0x526F6164, 0x0, 0x49544120, 0x5468756E, 0x64657220, 0x526F6164, 0x0, 0x83548393,
    0x835F815B, 0x838D815B, 0x83680000, 0x47455220, 0x53706972, 0x616C0000, 0x46524520, 0x53706972,
    0x616C0000, 0x53504120, 0x53706972, 0x616C0000, 0x49544120, 0x53706972, 0x616C0000, 0x83588370,
    0x83438389, 0x838B0000, 0x47455220, 0x536F6E69, 0x63204F76, 0x616C0000, 0x46524520, 0x536F6E69,
    0x63204F76, 0x616C0000, 0x53504120, 0x536F6E69, 0x63204F76, 0x616C0000, 0x49544120, 0x536F6E69,
    0x63204F76, 0x616C0000, 0x835C836A, 0x8362834E, 0x8349815B, 0x836F838B, 0x0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B160__fzgx_offset_0, (u32)lbl_1_data_2B47C__fzgx_offset_0, (u32)lbl_1_data_2B48C__fzgx_offset_0,
    (u32)lbl_1_data_2B49C__fzgx_offset_0, (u32)lbl_1_data_2B4AC__fzgx_offset_0, (u32)lbl_1_data_2B4BC__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B16C__fzgx_offset_0, (u32)lbl_1_data_2B4CC__fzgx_offset_0, (u32)lbl_1_data_2B4DC__fzgx_offset_0, (u32)lbl_1_data_2B4EC__fzgx_offset_0, (u32)lbl_1_data_2B4FC__fzgx_offset_0, (u32)lbl_1_data_2B50C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B178__fzgx_offset_0, (u32)lbl_1_data_2B520__fzgx_offset_0, (u32)lbl_1_data_2B530__fzgx_offset_0,
    (u32)lbl_1_data_2B540__fzgx_offset_0, (u32)lbl_1_data_2B550__fzgx_offset_0, (u32)lbl_1_data_2B560__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B184__fzgx_offset_0, (u32)lbl_1_data_2B574__fzgx_offset_0, (u32)lbl_1_data_2B584__fzgx_offset_0, (u32)lbl_1_data_2B594__fzgx_offset_0, (u32)lbl_1_data_2B5A4__fzgx_offset_0, (u32)lbl_1_data_2B5B4__fzgx_offset_0, (u32)lbl_1_data_2B190__fzgx_offset_0,
    (u32)lbl_1_data_2B5C4__fzgx_offset_0, (u32)lbl_1_data_2B5D4__fzgx_offset_0, (u32)lbl_1_data_2B5E4__fzgx_offset_0, (u32)lbl_1_data_2B5F4__fzgx_offset_0, (u32)lbl_1_data_2B604__fzgx_offset_0, (u32)lbl_1_data_2B19C__fzgx_offset_0, (u32)lbl_1_data_2B614__fzgx_offset_0, (u32)lbl_1_data_2B624__fzgx_offset_0,
    (u32)lbl_1_data_2B634__fzgx_offset_0, (u32)lbl_1_data_2B644__fzgx_offset_0, (u32)lbl_1_data_2B654__fzgx_offset_0, (u32)lbl_1_data_2B1A8__fzgx_offset_0, (u32)lbl_1_data_2B664__fzgx_offset_0, (u32)lbl_1_data_2B678__fzgx_offset_0, (u32)lbl_1_data_2B68C__fzgx_offset_0, (u32)lbl_1_data_2B6A0__fzgx_offset_0,
    (u32)lbl_1_data_2B6B4__fzgx_offset_0, (u32)lbl_1_data_2B1B8__fzgx_offset_0, (u32)lbl_1_data_2B6C8__fzgx_offset_0, (u32)lbl_1_data_2B6D8__fzgx_offset_0, (u32)lbl_1_data_2B6E8__fzgx_offset_0, (u32)lbl_1_data_2B6F8__fzgx_offset_0, (u32)lbl_1_data_2B708__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B1C4__fzgx_offset_0, (u32)lbl_1_data_2B718__fzgx_offset_0, (u32)lbl_1_data_2B728__fzgx_offset_0,
    (u32)lbl_1_data_2B738__fzgx_offset_0, (u32)lbl_1_data_2B748__fzgx_offset_0, (u32)lbl_1_data_2B758__fzgx_offset_0, (u32)lbl_1_data_2B1D0__fzgx_offset_0, (u32)lbl_1_data_2B768__fzgx_offset_0, (u32)lbl_1_data_2B77C__fzgx_offset_0, (u32)lbl_1_data_2B790__fzgx_offset_0, (u32)lbl_1_data_2B7A4__fzgx_offset_0,
    (u32)lbl_1_data_2B7B8__fzgx_offset_0, (u32)lbl_1_data_2B1E0__fzgx_offset_0, (u32)lbl_1_data_2B7CC__fzgx_offset_0, (u32)lbl_1_data_2B7E0__fzgx_offset_0, (u32)lbl_1_data_2B7F4__fzgx_offset_0, (u32)lbl_1_data_2B808__fzgx_offset_0, (u32)lbl_1_data_2B81C__fzgx_offset_0, (u32)lbl_1_data_2B1F0__fzgx_offset_0,
    (u32)lbl_1_data_2B830__fzgx_offset_0, (u32)lbl_1_data_2B840__fzgx_offset_0, (u32)lbl_1_data_2B850__fzgx_offset_0, (u32)lbl_1_data_2B860__fzgx_offset_0, (u32)lbl_1_data_2B870__fzgx_offset_0, (u32)lbl_1_data_2B1FC__fzgx_offset_0, (u32)lbl_1_data_2B884__fzgx_offset_0, (u32)lbl_1_data_2B894__fzgx_offset_0,
    (u32)lbl_1_data_2B8A4__fzgx_offset_0, (u32)lbl_1_data_2B8B4__fzgx_offset_0, (u32)lbl_1_data_2B8C4__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B208__fzgx_offset_0, (u32)lbl_1_data_2B8D8__fzgx_offset_0, (u32)lbl_1_data_2B8EC__fzgx_offset_0,
    (u32)lbl_1_data_2B900__fzgx_offset_0, (u32)lbl_1_data_2B914__fzgx_offset_0, (u32)lbl_1_data_2B928__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B218__fzgx_offset_0,
    (u32)lbl_1_data_2B93C__fzgx_offset_0, (u32)lbl_1_data_2B948__fzgx_offset_0, (u32)lbl_1_data_2B954__fzgx_offset_0, (u32)lbl_1_data_2B960__fzgx_offset_0, (u32)lbl_1_data_2B96C__fzgx_offset_0, (u32)lbl_1_data_2B220__fzgx_offset_0, (u32)lbl_1_data_2B97C__fzgx_offset_0, (u32)lbl_1_data_2B990__fzgx_offset_0,
    (u32)lbl_1_data_2B9A4__fzgx_offset_0, (u32)lbl_1_data_2B9B8__fzgx_offset_0, (u32)lbl_1_data_2B9CC__fzgx_offset_0, (u32)lbl_1_data_2B230__fzgx_offset_0, (u32)lbl_1_data_2B9DC__fzgx_offset_0, (u32)lbl_1_data_2B9F0__fzgx_offset_0, (u32)lbl_1_data_2BA04__fzgx_offset_0, (u32)lbl_1_data_2BA18__fzgx_offset_0,
    (u32)lbl_1_data_2BA2C__fzgx_offset_0, (u32)lbl_1_data_2B240__fzgx_offset_0, (u32)lbl_1_data_2BA40__fzgx_offset_0, (u32)lbl_1_data_2BA4C__fzgx_offset_0, (u32)lbl_1_data_2BA58__fzgx_offset_0, (u32)lbl_1_data_2BA64__fzgx_offset_0, (u32)lbl_1_data_2BA70__fzgx_offset_0, (u32)lbl_1_data_2B248__fzgx_offset_0,
    (u32)lbl_1_data_2BA80__fzgx_offset_0, (u32)lbl_1_data_2BA94__fzgx_offset_0, (u32)lbl_1_data_2BAA8__fzgx_offset_0, (u32)lbl_1_data_2BABC__fzgx_offset_0, (u32)lbl_1_data_2BAD0__fzgx_offset_0, (u32)lbl_1_data_2B258__fzgx_offset_0, (u32)lbl_1_data_2BAE8__fzgx_offset_0, (u32)lbl_1_data_2BAFC__fzgx_offset_0,
    (u32)lbl_1_data_2BB10__fzgx_offset_0, (u32)lbl_1_data_2BB24__fzgx_offset_0, (u32)lbl_1_data_2BB38__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B268__fzgx_offset_0, (u32)lbl_1_data_2BB48__fzgx_offset_0, (u32)lbl_1_data_2BB58__fzgx_offset_0, (u32)lbl_1_data_2BB68__fzgx_offset_0, (u32)lbl_1_data_2BB78__fzgx_offset_0, (u32)lbl_1_data_2BB88__fzgx_offset_0, (u32)lbl_1_data_2B274__fzgx_offset_0,
    (u32)lbl_1_data_2BB9C__fzgx_offset_0, (u32)lbl_1_data_2BBB0__fzgx_offset_0, (u32)lbl_1_data_2BBC4__fzgx_offset_0, (u32)lbl_1_data_2BBD8__fzgx_offset_0, (u32)lbl_1_data_2BBEC__fzgx_offset_0, (u32)lbl_1_data_2B284__fzgx_offset_0, (u32)lbl_1_data_2BC00__fzgx_offset_0, (u32)lbl_1_data_2BC14__fzgx_offset_0,
    (u32)lbl_1_data_2BC28__fzgx_offset_0, (u32)lbl_1_data_2BC3C__fzgx_offset_0, (u32)lbl_1_data_2BC50__fzgx_offset_0, (u32)lbl_1_data_2B294__fzgx_offset_0, (u32)lbl_1_data_2BC64__fzgx_offset_0, (u32)lbl_1_data_2BC78__fzgx_offset_0, (u32)lbl_1_data_2BC8C__fzgx_offset_0, (u32)lbl_1_data_2BCA0__fzgx_offset_0,
    (u32)lbl_1_data_2BCB4__fzgx_offset_0, (u32)lbl_1_data_2B2A4__fzgx_offset_0, (u32)lbl_1_data_2BCC4__fzgx_offset_0, (u32)lbl_1_data_2BCD0__fzgx_offset_0, (u32)lbl_1_data_2BCDC__fzgx_offset_0, (u32)lbl_1_data_2BCE8__fzgx_offset_0, (u32)lbl_1_data_2BCF4__fzgx_offset_0, (u32)lbl_1_data_2B2AC__fzgx_offset_0,
    (u32)lbl_1_data_2BD00__fzgx_offset_0, (u32)lbl_1_data_2BD10__fzgx_offset_0, (u32)lbl_1_data_2BD20__fzgx_offset_0, (u32)lbl_1_data_2BD30__fzgx_offset_0, (u32)lbl_1_data_2BD40__fzgx_offset_0, (u32)lbl_1_data_2B2AC__fzgx_offset_0, (u32)lbl_1_data_2BD00__fzgx_offset_0, (u32)lbl_1_data_2BD10__fzgx_offset_0,
    (u32)lbl_1_data_2BD20__fzgx_offset_0, (u32)lbl_1_data_2BD30__fzgx_offset_0, (u32)lbl_1_data_2BD40__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B474__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0, (u32)lbl_1_data_2B15C__fzgx_offset_0,
    (u32)lbl_1_data_2B474__fzgx_offset_0, 0x1020304, 0x10203, 0x4050607, 0x8090A0B, 0xC0D0E0F, 0x10111213, 0x14151617,
    0x18191A1B, 0x1C1D1E1F, 0x20212223, 0x10200, 0x10203, 0x4050600, 0x10203, 0x4050607,
    0x42494746, 0x49534830, 0x31000000, 0x574F524D, 0x0, 0x4B494E47, 0x5F434F42, 0x52410000,
    0x53414E44, 0x5F464953, 0x48000000, 0x53414E44, 0x5F424952, 0x44000000, (u32)lbl_1_data_2C7F8__fzgx_offset_0, 0x3,
    (u32)lbl_1_data_2C7BC__fzgx_offset_0, (u32)lbl_1_data_2C804__fzgx_offset_0, 0x9, (u32)lbl_1_data_2C7C0__fzgx_offset_0, (u32)lbl_1_data_2C80C__fzgx_offset_0, 0x0, (u32)lbl_1_data_2C7E4__fzgx_offset_0, (u32)lbl_1_data_2C818__fzgx_offset_0,
    0x1, (u32)lbl_1_data_2C7E8__fzgx_offset_0, (u32)lbl_1_data_2C824__fzgx_offset_0, 0x1, (u32)lbl_1_data_2C7F0__fzgx_offset_0, 0x0, 0x0, (u32)lbl_1_data_2C86C__fzgx_offset_0,
    0x1, 0x44610000, 0x102, 0x1, (u32)lbl_1_data_2C870__fzgx_offset_0, 0x0, 0x0, (u32)lbl_1_data_2C86C__fzgx_offset_0,
    0x1, 0x43C80000, 0x102, 0x1, (u32)lbl_1_data_2C890__fzgx_offset_0, 0x0, 0x0, (u32)lbl_1_data_2C86C__fzgx_offset_0,
    0x1, 0x43480000, 0x102, 0x1, (u32)lbl_1_data_2C8B0__fzgx_offset_0, 0x0, 0x0, (u32)lbl_1_data_2C86C__fzgx_offset_0,
    0x1, 0x447A0000, 0x0, (u32)lbl_1_data_2C86C__fzgx_offset_0, 0x0, 0x43FA0000, 0x3, 0x2,
    (u32)lbl_1_data_2C8D0__fzgx_offset_0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x1, 0x1, 0x43480000, 0x43960000, 0x0, 0x0,
    0x0, 0x0, 0x1, 0x1, 0x43480000, 0x43C80000, 0x0, 0x0,
    0x0, 0x0, 0x1, 0x1, 0x42C80000, 0x43480000, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x1, 0x447A0000, 0x44BB8000, 0x0, 0x1,
    0x43960000, 0x44160000, 0x1, 0x1, 0x43FA0000, 0x447A0000, 0x1, 0x1,
    0x43480000, 0x43C80000, 0x1, 0x1, 0x43480000, 0x43C80000, 0x0, 0x0,
    0x0, 0x0, 0x1, 0x1, 0x43FA0000, 0x442F0000, 0x1, 0x1,
    0x43C80000, 0x44480000, 0x0, 0x1, 0x44BB8000, 0x451C4000, 0x0, 0x1,
    0x447A0000, 0x44BB8000, 0x0, 0x1, 0x447A0000, 0x44BB8000, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x1, 0x1, 0x42C80000, 0x43480000, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1,
    0x43FA0000, 0x447A0000, 0x0, 0x1, 0x43480000, 0x43C80000, 0x0, 0x1,
    0x43FA0000, 0x447A0000, 0x1, 0x1, 0x447A0000, 0x44BB8000, 0x0, 0x1,
    0x42C80000, 0x43480000, 0x1, 0x1, 0x42C80000, 0x43960000, 0x0, 0x0,
    0x0, 0x0, 0x1, 0x1, 0x43480000, 0x43FA0000, 0x1, 0x1,
    0x43FA0000, 0x447A0000, 0x0, 0x1, 0x451C4000, 0x453B8000, 0x1, 0x1,
    0x43960000, 0x44160000, 0x1, 0x1, 0x43480000, 0x43960000, 0x0, 0x1,
    0x447A0000, 0x44FA0000, 0x6261636B, 0x67726F75, 0x6E642E63, 0x0, 0x25732573, 0x2E74706C,
    0x2E6C7A00, 0x62672F00, 0x25732573, 0x2E676D61, 0x2E6C7A00, 0x0, (u32)lbl_1_data_2C86C__fzgx_offset_0, 0x0,
    0x43700000, 0x0, (u32)lbl_1_data_2C86C__fzgx_offset_0, 0x0, 0x43960000, 0x0, (u32)lbl_1_data_2C86C__fzgx_offset_0, 0x0,
    0x443B8000, 0x0, (u32)lbl_1_data_2C86C__fzgx_offset_0, 0x0, 0x447A0000, 0x41, 0x4, (u32)lbl_1_data_2CB8C__fzgx_offset_0,
    0x0, 0x0, (u32)lbl_1_data_2C86C__fzgx_offset_0, 0x0, 0x43160000, 0x0, (u32)lbl_1_data_2C86C__fzgx_offset_0, 0x0,
    0x437A0000, 0x0, (u32)lbl_1_data_2C86C__fzgx_offset_0, 0x0, 0x43FA0000, 0x0, (u32)lbl_1_data_2C86C__fzgx_offset_0, 0x0,
    0x442F0000, 0x41, 0x4, (u32)lbl_1_data_2CBDC__fzgx_offset_0, 0x0, 0xFFFFFFFF, (u32)lbl_1_bss_384B4__fzgx_offset_0, 0x0,
    0x6D6F7469, 0x6F6E0000, 0x5F534B4C, 0x30000000, 0x5F534B4C, 0x0, 0x25732E73, 0x6B6C0000,
    0x25735F74, 0x6573742E, 0x6D746100, 0x2E2E0000, 0x535F424F, 0x41524400, 0x535F4752, 0x49440000
};
static u32 fzgx_pool_data_lbl_1_data_2A0C0_2BB8[6] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x1, (u32)lbl_1_data_2CC68__fzgx_offset_0, 0x1, (u32)lbl_1_data_2CC70__fzgx_offset_0, 0x3, 0x0
};
static u32 fzgx_pool_data_lbl_1_data_2CC90[5] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x535F424F, 0x41524432, 0x0, 0x535F4752, 0x49443200
};
static u32 fzgx_pool_data_lbl_1_data_2A0C0_2BE4[6] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x1, (u32)lbl_1_data_2CC90__fzgx_offset_0, 0x1, (u32)lbl_1_data_2CC9C__fzgx_offset_0, 0x3, 0x0
};
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_1_data_2A0C0(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .data objects in retail order */
    s = *(u8 *)fzgx_pool_data_lbl_1_data_2A0C0;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_2A7E0;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_2A8D8;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_2A0C0_2BB8;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_2CC90;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_2A0C0_2BE4;
}
#pragma section code_type ".text"

extern void fn_1_9CF78(void *, Sig_fn_1_9CF78_FilterCallback);

static inline void clr(u8 *st) {
    *(u32 *)(st + 0x80) = 0;
    *(u32 *)(st + 0x7C) = 0;
}

void fn_1_9D994(s32 arg0) {
    void *data;
    
    clr(((u8 *)fzgx_pool_data_lbl_1_data_2A7E0));
    data = ((u8 *)fzgx_pool_data_lbl_1_data_2A0C0_2BB8);
    if (arg0 == 43) {
        data = ((u8 *)fzgx_pool_data_lbl_1_data_2A0C0_2BE4);
    }
    fn_1_9CF78(data, (Sig_fn_1_9CF78_FilterCallback)fn_1_9D93C);
}
/* fzgx:end fn_1_9D994 */

/* fzgx:begin fn_1_9D9E4 */
typedef struct {
    u8 pad[0x468];
    f32 value;
} Fn14F04Result;

void fn_1_9D9E4(void) {
    f32 value;
    s32 offset;
    s32 i;
    s32 count;
    Fn14F04Result *result;

    value = lbl_1_rodata_41FC;
    lbl_1_data_2A7E0.unk_74 = 1;
    if (*(s16 *)&lbl_1_bss_960 == 9) {
        lbl_1_data_2A7E0.unk_70 = fn_1_86624();
    } else {
        lbl_1_data_2A7E0.unk_70 = 0x1e;
    }

    if (lbl_1_bss_3BE0 != 0) {
        result = (Fn14F04Result *)fn_1_14F04();
        count = lbl_1_bss_3BE0->unk_8;
        if (count > 0) {
            count--;
        } else {
            count = 0;
        }
        fn_1_17920(count, 0, lbl_1_rodata_4244[0]);
        value = result->value;
    }

    i = 0;
    offset = 0;
    while (i < (s8)lbl_1_data_2A7E0.unk_70) {
        fn_1_85C58(i, value);
        lbl_8006DB74((u8 *)lbl_1_data_2A7E0.unk_78 + offset);
        offset += 0x30;
        i++;
    }
}
/* fzgx:end fn_1_9D9E4 */

/* fzgx:begin fn_1_9DB04 noprologue */
#include "types.h"
#include "psvec.h"
#include "game/main_rel/car_test_types.h"
#include "rel/main_rel/background.h"

#pragma section code_type ".fzgxpool"
static const unsigned long fzgx_pool_table1[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const unsigned long *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 6885000.0f;
}
static const unsigned long fzgx_pool_table3[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const unsigned long *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
}
static const unsigned long fzgx_pool_table5[2] = {0x000000FF, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const unsigned long *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
    s = 60.0f;
}
static const unsigned long fzgx_pool_table7[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const unsigned long *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.5;
    d = 1.0;
    s = 182.04444885253906f;
}
static const unsigned long fzgx_pool_table9[2] = {0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const unsigned long *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0f;
    s = 0.4000000059604645f;
    s = 0.01666666753590107f;
    s = -90000.0f;
    s = 100.0f;
    s = -401.0f;
    s = -0.10000000149011612f;
    s = 0.009999999776482582f;
}
static const unsigned long fzgx_pool_table11[7] = {0x00FF00FF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const unsigned long *volatile cp; cp = fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 60.0;
    d = 3.0;
    s = 400.0f;
    s = 0.05000000074505806f;
    s = 2.75f;
}
static const unsigned long fzgx_pool_table13[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const unsigned long *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

typedef struct {
    s32 type;
    f32 time;
    f32 value;
    f32 tanIn;
    f32 tanOut;
} Sig_fn_1_9DDA8_fn_1_9DDA8_CurveKey;
typedef struct {
    u8 unk_00[8];
    u32 unk_08;
    u32 unk_0C;
    u32 unk_10;
    f32 unk_14;
} Sig_fn_1_555D0_Fn1_555D0Object;

/* view of the background literal pool (lbl_1_rodata_41F0) */
typedef struct {
    u8 pad_0[0xC];
    f32 zero;
    u8 pad_10[0x38];
    f32 deg_to_s16;
    u8 pad_4C[0x8];
    f32 one;
    u8 pad_58[0xC];
    f32 hundred;
    u8 pad_68[0x28];
    f64 sixty;
    f64 three;
    f32 f400;
    f32 f005;
    f32 f275;
} BgPool41F0;

extern u8 lbl_1_rodata_41F0[12];
extern f32 fn_1_9E14C(u32, Sig_fn_1_9DDA8_fn_1_9DDA8_CurveKey *, f32);
extern s16 fn_1_3F0C8(void);
extern s32 fn_1_3FC48(void);
extern void fn_1_A2D84(u32);
extern void fn_1_55FF0(f32);
extern void fn_1_566EC(int, int);
extern void fn_1_555D0(Sig_fn_1_555D0_Fn1_555D0Object *);
extern void lbl_8006DFE8(Fn183D28Vec3 *);
extern void lbl_8006E1B0(Fn183D28Vec3 *, Fn183D28Vec3 *);
extern void lbl_8006E0B4(f32, f32, f32);
extern u32 mathutil_mtxA_rotate_x(u32);

void fn_1_9DB04(void) {
    f32 zero;
    BgPool41F0 *pool;
    Obj_1_data_2A7E0 *bg;
    Obj_1_data_2A7E0 *bg2;
    Obj_1_data_2A7E0 *bg3;
    s32 angle;
    f32 limit;
    f32 *alpha;
    s32 i;
    f32 alphas[31];
    Fn183D28Vec3 pos;

    pool = (BgPool41F0 *)lbl_1_rodata_41F0;
    bg = &lbl_1_data_2A7E0;
    if ((s32)bg->unk_74 != 0) {
        f32 t;

        t = bg->unk_1C / (60.0);
        if (t > lbl_1_data_2CCBC.unk_54) {
            bg->unk_74 = 0;
        }
        angle = (s32)((182.044449f) *
                      fn_1_9E14C(5, (Sig_fn_1_9DDA8_fn_1_9DDA8_CurveKey *)&lbl_1_data_2CCBC, t));
        if ((3.0) == t && fn_1_3F0C8() == 40 && fn_1_3FC48() == 0) {
            fn_1_A2D84(0xA9091700);
        }
    } else {
        angle = 0;
    }

    bg2 = &lbl_1_data_2A7E0;
    for (i = 0; i < (s8)bg2->unk_70; i++) {
        lbl_8006DFE8((Fn183D28Vec3 *)(bg2->unk_78 + i * 0x30));
        alpha = &alphas[i];
        if (bg2->unk_7C != 0) {
            lbl_8006E1B0((Fn183D28Vec3 *)(bg2->unk_7C + 8), &pos);
            limit = ((Sig_fn_1_555D0_Fn1_555D0Object *)bg2->unk_7C)->unk_14;
        } else {
            limit = (0.0f);
            psvec_set(&pos, *(f32 *)(0xE0000000 + 0x2C), *(f32 *)(0xE0000000 + 0x1C),
                      *(f32 *)(0xE0000000 + 0x0C));
        }
        if (pos.z > limit) {
            *alpha = (0.0f);
        } else {
            *alpha = ((400.0f) + pos.z) / (100.0f);
            if (!(*alpha <= (0.0f))) {
                if (*alpha > (1.0f)) {
                    *alpha = (1.0f);
                }
                if (bg2->unk_7C != 0) {
                    fn_1_55FF0(*alpha);
                    fn_1_566EC(1, 0x80);
                    fn_1_555D0((Sig_fn_1_555D0_Fn1_555D0Object *)bg2->unk_7C);
                    fn_1_566EC(0, 0);
                }
            }
        }
    }

    bg3 = &lbl_1_data_2A7E0;
    if (bg3->unk_80 != 0 && (s32)bg->unk_74 != 0) {
        zero = (0.0f);
        for (i = 0; i < (s8)bg2->unk_70; i++) {
            if (!(alphas[i] <= zero)) {
                lbl_8006DFE8((Fn183D28Vec3 *)(bg2->unk_78 + i * 0x30));
                lbl_8006E0B4((0.0f), (0.0500000007f), (2.75f));
                mathutil_mtxA_rotate_x(angle);
                fn_1_55FF0(alphas[i]);
                fn_1_555D0((Sig_fn_1_555D0_Fn1_555D0Object *)bg3->unk_80);
            }
        }
    }
}
/* fzgx:end fn_1_9DB04 */

/* fzgx:begin fn_1_9DDA8 noprologue */
#include "types.h"
#include "dolphin/types.h"
#include "dolphin/hw_regs.h"
#include "game/main_rel/background_types.h"

typedef struct {
    s32 type;     /* 0: constant, 1: linear, else: hermite */
    f32 time;
    f32 value;
    f32 tanIn;
    f32 tanOut;
} fn_1_9DDA8_CurveKey;

/* Evaluate a keyframe curve at time t; derivative != 0 returns the slope. */
f32 fn_1_9DDA8(s32 count, fn_1_9DDA8_CurveKey *keys, s32 derivative, f32 t) {
    fn_1_9DDA8_CurveKey *p;
    s32 i;
    f32 a, dt, d, m0, m1, u, s, u2, u3, w, b, e;
    f64 lin;

    if (count < 2 || t <= keys[0].time) {
        if (derivative) {
            return keys[0].tanOut;
        }
        return keys[0].value;
    }
    if (t >= keys[count - 1].time) {
        if (derivative) {
            return keys[count - 1].tanIn;
        }
        return keys[count - 1].value;
    }

    count--;
    keys++;
    for (i = 1; i < count; i++) {
        if (keys->time > t) {
            break;
        }
        keys++;
    }
    p = keys - 1;

    if (derivative) {
        switch (p->type) {
        case 0:
            return 0.0f;
        case 1:
            return keys->value - p->value;
        default:
            a = t - p->time;
            dt = keys->time - p->time;
            d = p->value - keys->value;
            m0 = (f32)(dt * p->tanOut);
            u = a / dt;
            s = m0 + (f32)(dt * keys->tanIn);
            return m0 + ((f32)((f32)(u * u) * (((f32)(2.0f * d) + s) / 3.0f))
                         - (f32)(u * ((m0 + ((f32)(3.0f * d) + s)) / 2.0f)));
        }
    } else {
        switch (p->type) {
        case 0:
            return p->value;
        case 1:
            dt = keys->time - p->time;
            a = t - p->time;
            u = a / dt;
            lin = p->value * (1.0 - u);
            return lin + (f32)(keys->value * u);
        default:
            a = t - p->time;
            dt = keys->time - p->time;
            u = a / dt;
            u2 = (f32)(u * u);
            u3 = (f32)(u2 * u);
            w = u3 - u2;
            e = (f32)(2.0f * w) - u2;
            b = u + (w - u2);
            return ((f32)((1.0f + e) * p->value) - (f32)(e * keys->value))
                   + (f32)(dt * ((f32)(p->tanOut * b) + (f32)(w * keys->tanIn)));
        }
    }
}
/* fzgx:end fn_1_9DDA8 */

/* fzgx:begin fn_1_9E14C */
void fn_1_9E14C(u32 arg0, u32 arg1) {
    fn_1_9DDA8(arg0, arg1, 0);
}
/* fzgx:end fn_1_9E14C */

/* fzgx:begin fn_1_9E170 */
void fn_1_9E170(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    fn_1_9DFB8(arg0, arg1, arg2, 0);
}
/* fzgx:end fn_1_9E170 */

/* fzgx:begin fn_1_9E194 */
void fn_1_9E194(u32 arg0, u32 arg1) {
    fn_1_9DDA8(arg0, arg1, 1);
}
/* fzgx:end fn_1_9E194 */

/* fzgx:begin fn_1_9E1B8 */
void fn_1_9E1B8(void) {
    lbl_1_bss_6EA80 = 0;
    lbl_1_bss_6EA84 = (u32)&lbl_1_bss_6EA80;
}
/* fzgx:end fn_1_9E1B8 */

/* fzgx:begin fn_1_9E1D0 */
typedef struct {
    s16 unk_0;
    s16 unk_2;
    u32 unk_4;
    u8 unk_8;
} Fn_1_9E1D0_Entry;

typedef struct Fn_1_9E1D0_Node {
    struct Fn_1_9E1D0_Node *unk_0;
    s32 unk_4;
    Fn_1_9E1D0_Entry *unk_8;
} Fn_1_9E1D0_Node;

void fn_1_9E1D0(void) {
    s32 count;
    Fn_1_9E1D0_Node *node;
    Fn_1_9E1D0_Entry *entry;
    u32 result;

    node = (Fn_1_9E1D0_Node *)lbl_1_bss_6EA80;
    while (node != 0) {
        entry = node->unk_8;
        count = node->unk_4;
        while (count > 0) {
            if (entry->unk_4 == 0) {
                GXPeekZ((u16)entry->unk_0, (u16)entry->unk_2, &entry->unk_4);
                fn_80034200(2);
                fn_8003432C((u16)entry->unk_0, (u16)entry->unk_2, &result);
                entry->unk_8 = (u8)(result >> 24);
            }
            count--;
            entry++;
        }
        node = node->unk_0;
    }
    lbl_1_bss_6EA80 = 0;
    lbl_1_bss_6EA84 = (u32)&lbl_1_bss_6EA80;
}
/* fzgx:end fn_1_9E1D0 */

/* fzgx:begin fn_1_9E29C noprologue */
#include "types.h"

typedef struct {
    f32 x, y, z;
} Vec3f;

typedef struct {
    s16 x;
    s16 y;
    u32 flags;
    u32 pad;
} ScreenPoint;

extern void fn_80038BFC(f32 *);
extern void fn_80038F10(f32 *);

/* Projects camera-space points to clamped screen coordinates. */
#pragma push
#pragma fp_contract off
void fn_1_9E29C(s32 count, Vec3f *src, ScreenPoint *dst) {
    Vec3f p;
    f32 proj[7];
    f32 vp[6];
    f32 halfW, halfH;
    f32 dxmax, dymax, cx, cy, xmax, ymax;
    f32 nx, ny;
    f32 inv;
    f32 t;
    s32 i;

    fn_80038BFC(proj);
    fn_80038F10(vp);
    halfW = 0.5f * vp[2];
    halfH = 0.5f * vp[3];
    cx = vp[0] + halfW;
    cy = vp[1] + halfH;
    xmax = (vp[0] + vp[2]) - 1.0f;
    ymax = (vp[1] + vp[3]) - 1.0f;
    dxmax = xmax - cx;
    dymax = ymax - cy;

    for (i = 0; i < count; i++) {
        p = src[i];
        dst[i].flags = 0x1000000;
        if (p.z < 0.0f) {
            t = 1.0f / p.z;
            ny = proj[4] + t * (p.y * proj[3]);
            nx = proj[2] + t * (p.x * proj[1]);
            nx = 0.5f * (1.0f + nx);
            p.x = vp[0] + vp[2] * (1.0f - nx);
            p.y = vp[1] + vp[3] * (0.5f * (1.0f + ny));
            if (p.x < vp[0]) {
                t = (vp[0] - cx) / (p.x - cx);
                p.x = vp[0];
                p.y = cy + t * (p.y - cy);
            } else if (p.x > xmax) {
                t = dxmax / (p.x - cx);
                p.x = xmax;
                p.y = cy + t * (p.y - cy);
            }
            if (p.y < vp[1]) {
                t = (vp[1] - cy) / (p.y - cy);
                p.y = vp[1];
                p.x = cx + t * (p.x - cx);
            } else if (p.y > ymax) {
                t = dymax / (p.y - cy);
                p.y = ymax;
                p.x = cx + t * (p.x - cx);
            }
            dst[i].x = (s16)p.x;
            dst[i].y = (s16)p.y;
            dst[i].flags = 0;
        }
    }
}
#pragma pop
/* fzgx:end fn_1_9E29C */

/* fzgx:begin fn_1_9E514 */
typedef struct {
    u8 unk_00[0x14];
    f32 unk_14;
    f32 unk_18;
} Fn_1_9E514_Data;

s32 fn_1_9E514(f32 arg0) {
    Fn_1_9E514_Data data;
    f32 *table = (f32 *)&lbl_1_rodata_42C0;
    f32 prod;
    f32 value;

    fn_80038BFC((f32 *)&data);
    prod = data.unk_14 * arg0;
    value = data.unk_18 + prod;
    value /= arg0;
    value = (table[1] - value) * table[3];
    if (value < table[2]) {
        return 0;
    }
    return __cvt_fp2unsigned(value);
}
/* fzgx:end fn_1_9E514 */

/* fzgx:begin fn_1_9E598 */
typedef struct Node Node;
struct Node {
    Node *next;
};

// Append a node to the linked-list tail and terminate the new tail.
void fn_1_9E598(Node *node) {
    Node *tail;

    tail = *(Node **)&lbl_1_bss_6EA84;
    tail->next = node;
    node->next = 0;
    lbl_1_bss_6EA84 = (u32)node;
}
/* fzgx:end fn_1_9E598 */

/* fzgx:begin fn_1_9E5B8 */
// Removes a node from the background-node chain and updates its tail link.
void fn_1_9E5B8(Obj_1_bss_6EA80_Target *node) {
    u32 *link;

    link = (u32 *)&lbl_1_bss_6EA80;
    while (*link != 0 && *link != (u32)node) {
        link = (u32 *)*link;
    }
    if (*link == 0) {
        return;
    }
    *link = node->unk_0;
    if (lbl_1_bss_6EA84 == (u32)node) {
        lbl_1_bss_6EA84 = (u32)link;
    }
}
/* fzgx:end fn_1_9E5B8 */

/* fzgx:begin fn_1_9E608 noprologue */
#include "types.h"
#include "dolphin/types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/background.h"
#include "dolphin/hw_regs.h"
#include "game/main_rel/background_types.h"

typedef struct {
    u8 r, g, b, a;
} BgColor;

typedef struct {
    u8 unk_0[0xC];
    f32 size;
    s16 rotZ;
    u16 flags;
    BgColor color;
} BgSprite;

extern u32 lbl_801A6D00;
extern s32 fn_1_54E34(void *arg0, f32 arg1);
extern void fn_800724C8(void);
extern void fn_8007245C(u32 value);
extern void lbl_8006DAEC(void);
extern void lbl_8006D758(void);
extern u32 GXLoadPosMtxImm(u32, u32);
extern void lbl_8006DB30(void);
/* The color is passed by value: MWCC copies it to the stack and passes the copy's address. */
extern void fn_800736C0(u32, BgColor);
extern void fn_8003462C(u32 arg0, u32 arg1, u32 arg2);
extern void lbl_8006E1D8(f32 *, f32, f32, f32);
extern void mathutil_mtxA_rotate_z(s32);
extern void lbl_8006E0A4(void *);
extern u32 lbl_8006D7B0(void);

/* GX write-gather FIFO: every store is a hardware write, so it must not be merged or dropped. */
#define BG_FIFO (*(volatile f32 *)GX_FIFO_BASE)

void fn_1_9E608(s32 count, BgSprite *list) {
    BgSprite *sprites;
    s32 remaining;
    f32 v[4][3];
    BgColor col;
    s32 i;
    BgSprite *start;
    BgSprite *last;
    BgSprite *s;
    s32 visible;
    s32 n;
    f32 neg;
    f32 size;

    s = list;
    visible = 0;
    for (i = count; i > 0; i--, s++) {
        if (fn_1_54E34(s, s->size) != 0) {
            visible++;
            s->flags &= ~1;
        } else {
            s->flags |= 1;
        }
    }
    if (visible == 0) {
        return;
    }

    fn_800724C8();
    fn_8007245C(0x2200);
    lbl_8006DAEC();
    lbl_8006D758();
    GXLoadPosMtxImm(lbl_801A6D00, 0);
    lbl_8006DB30();

    sprites = list;
    remaining = count;
    while (remaining > 0) {
        while (remaining > 0) {
            if (!(sprites->flags & 1)) {
                break;
            }
            remaining--;
            sprites++;
        }
        if (remaining == 0) {
            return;
        }
        col = sprites->color;
        fn_800736C0(0, col);
        fn_8003462C(0x90, 0, 8);
        start = sprites;
        remaining--;
        sprites++;
        for (i = 0; i < 8; i++) {
            BG_FIFO = 0.0f;
            BG_FIFO = 0.0f;
            BG_FIFO = 0.0f;
            BG_FIFO = 0.0f;
            BG_FIFO = 0.0f;
        }
        n = 1;
        while (remaining > 0) {
            if (!(sprites->flags & 1)) {
                if (col.r != sprites->color.r || col.g != sprites->color.g ||
                    col.b != sprites->color.b || col.a != sprites->color.a) {
                    remaining++;
                    last = sprites - 1;
                    break;
                }
                n++;
            }
            remaining--;
            sprites++;
        }
        fn_8003462C(0x80, 0, (u16)(n * 4));
        sprites = start;
        while (n > 0) {
            if (!(sprites->flags & 1)) {
                size = sprites->size;
                neg = -size;
                lbl_8006DAEC();
                lbl_8006E0A4(sprites);
                lbl_8006D7B0();
                if (sprites->rotZ != 0) {
                    mathutil_mtxA_rotate_z(sprites->rotZ);
                }
                lbl_8006E1D8(v[0], neg, neg, 0.0f);
                lbl_8006E1D8(v[1], size, neg, 0.0f);
                lbl_8006E1D8(v[2], size, size, 0.0f);
                lbl_8006E1D8(v[3], neg, size, 0.0f);
                lbl_8006DB30();
                n--;
                BG_FIFO = v[0][0];
                BG_FIFO = v[0][1];
                BG_FIFO = v[0][2];
                BG_FIFO = 0.0f;
                BG_FIFO = 0.0f;
                BG_FIFO = v[1][0];
                BG_FIFO = v[1][1];
                BG_FIFO = v[1][2];
                BG_FIFO = 1.0f;
                BG_FIFO = 0.0f;
                BG_FIFO = v[2][0];
                BG_FIFO = v[2][1];
                BG_FIFO = v[2][2];
                BG_FIFO = 1.0f;
                BG_FIFO = 1.0f;
                BG_FIFO = v[3][0];
                BG_FIFO = v[3][1];
                BG_FIFO = v[3][2];
                BG_FIFO = 0.0f;
                BG_FIFO = 1.0f;
            }
            sprites++;
        }
        remaining--;
        sprites = last + 1;
    }
}
/* fzgx:end fn_1_9E608 */

/* fzgx:begin fn_1_9EA94 noprologue */
#include "types.h"
#include "dolphin/types.h"
#include "dolphin/hw_regs.h"
#include "dolphin/gx.h"

/* FIFO writes use the canonical hardware FIFO definition. */
#define WGPIPE GXWGFifo
struct fn_1_9EA94_Arg0 { u8 pad_0[0xC]; f32 unk_C; };
/* Reload shared pool operands at each hardware FIFO write. */
extern volatile f32 lbl_1_rodata_42D0;
extern volatile f32 lbl_1_rodata_42D4; /* Reload after each hardware FIFO store. */
extern s32 fn_1_54E34(void *, f32);
extern u32 GXLoadPosMtxImm(u32, u32);
extern u32 lbl_801A6D00;
extern void fn_8003462C(u32,u32,u32);
extern void fn_8007245C(u32);
extern void fn_800724C8(void);
extern void fn_800736C0(u32,void *);
extern void lbl_8006D758(void);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern void lbl_8006E0A4(void *);
extern void lbl_8006E1D8(u32,f32,f32,f32);
extern void mathutil_mtxA_rotate_z(s32);
void fn_1_9EA94(struct fn_1_9EA94_Arg0 *arg0) {
    s32 v0;
    f32 v1;
    f32 v3;
    f32 v2;
    /* Vertex reads are sequenced with hardware FIFO writes. */
    volatile f32 loc_30[3]; /* Sequence vertex reads with hardware FIFO writes. */
    volatile f32 loc_24[3]; /* Sequence vertex reads with hardware FIFO writes. */
    volatile f32 loc_18[3]; /* Sequence vertex reads with hardware FIFO writes. */
    volatile f32 loc_C[3]; /* Sequence vertex reads with hardware FIFO writes. */
    u32 loc_8;
    if (fn_1_54E34(arg0, arg0->unk_C) == 0) {
        *(u16 *)((u8 *)arg0 + 18) |= 1;
    } else {
        *(u16 *)((u8 *)arg0 + 18) &= 0xFFFE;
        fn_800724C8();
        fn_8007245C(8704);
        lbl_8006DAEC();
        lbl_8006D758();
        GXLoadPosMtxImm(lbl_801A6D00,0);
        lbl_8006DB30();
        loc_8 = *(u32 *)((u8 *)arg0 + 20);
        fn_800736C0(0,&loc_8);
        fn_8003462C(144,0,8);
        WGPIPE.f32 = lbl_1_rodata_42D0;
        WGPIPE.f32 = lbl_1_rodata_42D0;
        WGPIPE.f32 = lbl_1_rodata_42D0;
        WGPIPE.f32 = lbl_1_rodata_42D0;
        WGPIPE.f32 = lbl_1_rodata_42D0;
        WGPIPE.f32 = lbl_1_rodata_42D0;
        WGPIPE.f32 = lbl_1_rodata_42D0;
        WGPIPE.f32 = lbl_1_rodata_42D0;
        WGPIPE.f32 = lbl_1_rodata_42D0;
        WGPIPE.f32 = lbl_1_rodata_42D0;
        WGPIPE.f32 = lbl_1_rodata_42D0;
        WGPIPE.f32 = lbl_1_rodata_42D0;
        WGPIPE.f32 = lbl_1_rodata_42D0;
        WGPIPE.f32 = lbl_1_rodata_42D0;
        WGPIPE.f32 = lbl_1_rodata_42D0;
        WGPIPE.f32 = lbl_1_rodata_42D0;
        WGPIPE.f32 = lbl_1_rodata_42D0;
        WGPIPE.f32 = lbl_1_rodata_42D0;
        WGPIPE.f32 = lbl_1_rodata_42D0;
        WGPIPE.f32 = lbl_1_rodata_42D0;
        WGPIPE.f32 = lbl_1_rodata_42D0;
        WGPIPE.f32 = lbl_1_rodata_42D0;
        WGPIPE.f32 = lbl_1_rodata_42D0;
        WGPIPE.f32 = lbl_1_rodata_42D0;
        WGPIPE.f32 = lbl_1_rodata_42D0;
        WGPIPE.f32 = lbl_1_rodata_42D0;
        WGPIPE.f32 = lbl_1_rodata_42D0;
        WGPIPE.f32 = lbl_1_rodata_42D0;
        WGPIPE.f32 = lbl_1_rodata_42D0;
        WGPIPE.f32 = lbl_1_rodata_42D0;
        WGPIPE.f32 = lbl_1_rodata_42D0;
        WGPIPE.f32 = lbl_1_rodata_42D0;
        WGPIPE.f32 = lbl_1_rodata_42D0;
        WGPIPE.f32 = lbl_1_rodata_42D0;
        WGPIPE.f32 = lbl_1_rodata_42D0;
        WGPIPE.f32 = lbl_1_rodata_42D0;
        WGPIPE.f32 = lbl_1_rodata_42D0;
        WGPIPE.f32 = lbl_1_rodata_42D0;
        WGPIPE.f32 = lbl_1_rodata_42D0;
        WGPIPE.f32 = lbl_1_rodata_42D0;
        fn_8003462C(128,0,4);
        v2 = arg0->unk_C;
        v3 = -v2;
        lbl_8006DAEC();
        lbl_8006E0A4(arg0);
        v0 = *(s16 *)((u8 *)arg0 + 16);
        if ((s16)v0 != 0) mathutil_mtxA_rotate_z(v0);
        lbl_8006E1D8((u32)loc_C,v3,v3,lbl_1_rodata_42D0);
        v1 = v2;
        v0 = (u32)loc_18;
        lbl_8006E1D8(v0,v1,v3,lbl_1_rodata_42D0);
        v1 = v2;
        v0 = (u32)loc_24;
        lbl_8006E1D8(v0,v1,v2,lbl_1_rodata_42D0);
        v1 = v3;
        v0 = (u32)loc_30;
        lbl_8006E1D8(v0,v1,v2,lbl_1_rodata_42D0);
        lbl_8006DB30();
        WGPIPE.f32 = loc_C[0];
        WGPIPE.f32 = loc_C[1];
        WGPIPE.f32 = loc_C[2];
        WGPIPE.f32 = lbl_1_rodata_42D0;
        WGPIPE.f32 = lbl_1_rodata_42D0;
        WGPIPE.f32 = loc_18[0];
        WGPIPE.f32 = loc_18[1];
        WGPIPE.f32 = loc_18[2];
        v0 = (u32)&lbl_1_rodata_42D4;
        WGPIPE.f32 = *(volatile f32 *)v0; /* Reload pool operand for the hardware FIFO write. */
        WGPIPE.f32 = lbl_1_rodata_42D0;
        WGPIPE.f32 = loc_24[0];
        WGPIPE.f32 = loc_24[1];
        WGPIPE.f32 = loc_24[2];
        WGPIPE.f32 = lbl_1_rodata_42D4;
        WGPIPE.f32 = lbl_1_rodata_42D4;
        WGPIPE.f32 = loc_30[0];
        WGPIPE.f32 = loc_30[1];
        WGPIPE.f32 = loc_30[2];
        WGPIPE.f32 = lbl_1_rodata_42D0;
        WGPIPE.f32 = lbl_1_rodata_42D4;
    }
}
/* fzgx:end fn_1_9EA94 */

/* fzgx:begin fn_1_9EDE8 */
#define lbl_1_rodata_42D0 (*(volatile const f32 *)&lbl_1_rodata_42D0) /* Reload before each ordered FIFO write. */
#define lbl_1_rodata_42D4 (*(volatile const f32 *)&lbl_1_rodata_42D4) /* Reload before each ordered FIFO write. */


typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct {
    u8 pad_00[0x14];
    f32 unk_14;
    u8 pad_18[0x0C];
    f32 unk_24;
    u8 pad_28[0x0C];
    f32 unk_34;
    u32 unk_38;
    u32 unk_3c;
} Obj_1_9EDE8;

/* fzgx-allow: A1 GX FIFO write port; retail materialises it as lis 0xcc01/stfs -0x8000 */
#define FIFO(v) (*(volatile f32 *)(GX_FIFO_BASE + 0x0) = (v)) /* Hardware access must remain ordered. */

void fn_1_9EDE8(Obj_1_9EDE8 *arg0) {
    Vec3 pos;
    u32 z;
    Vec3 vtx[4];
    struct { f32 value; } radius;
    struct { f32 value; } neg;

    pos.x = arg0->unk_14;
    pos.y = arg0->unk_24;
    pos.z = arg0->unk_34;
    if (arg0->unk_38 & 2) {
        radius.value = *(f32 *)((u8 *)arg0 + 4);
    } else {
        radius.value = *(f32 *)arg0;
    }
    if (!(arg0->unk_38 & 4) && fn_1_54E34(&pos, radius.value) == 0) {
        arg0->unk_38 |= 1;
        return;
    }
    arg0->unk_38 &= ~1;
    fn_800724C8();
    fn_8007245C(0x2200);
    lbl_8006DAEC();
    lbl_8006D758();
    GXLoadPosMtxImm(lbl_801A6D00, 0);
    lbl_8006DB30();
    z = arg0->unk_3c;
    fn_800736C0(0, &z);
    fn_8003462C(0x90, 0, 8);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    fn_8003462C(0x80, 0, 4);
    radius.value = *(f32 *)arg0;
    neg.value = -radius.value;
    lbl_8006DAEC();
    lbl_8006DFC4((u32)((u8 *)arg0 + 8));
    lbl_8006E1D8((u32)&vtx[0], neg.value, neg.value, lbl_1_rodata_42D0);
    lbl_8006E1D8((u32)&vtx[1], radius.value, neg.value, lbl_1_rodata_42D0);
    lbl_8006E1D8((u32)&vtx[2], radius.value, radius.value, lbl_1_rodata_42D0);
    lbl_8006E1D8((u32)&vtx[3], neg.value, radius.value, lbl_1_rodata_42D0);
    lbl_8006DB30();
    FIFO(vtx[0].x);
    FIFO(vtx[0].y);
    FIFO(vtx[0].z);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(vtx[1].x);
    FIFO(vtx[1].y);
    FIFO(vtx[1].z);
    FIFO(lbl_1_rodata_42D4);
    FIFO(lbl_1_rodata_42D0);
    FIFO(vtx[2].x);
    FIFO(vtx[2].y);
    FIFO(vtx[2].z);
    FIFO(lbl_1_rodata_42D4);
    FIFO(lbl_1_rodata_42D4);
    FIFO(vtx[3].x);
    FIFO(vtx[3].y);
    FIFO(vtx[3].z);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D4);
}
#undef lbl_1_rodata_42D0
#undef lbl_1_rodata_42D4
/* fzgx:end fn_1_9EDE8 */

/* fzgx:begin fn_1_9F164 noprologue */
#include "types.h"
#include "dolphin/hw_regs.h"

typedef struct fn_1_9F164_Vec {
    f32 x, y, z;
} fn_1_9F164_Vec;

struct fn_1_9F164_Arg0 {
    f32 unk_0;
    f32 unk_4;
    u8 unk_8[0xC];
    f32 unk_14;
    u8 pad_18[0xC];
    f32 unk_24;
    u8 pad_28[0xC];
    f32 unk_34;
    u32 unk_38;
    u32 unk_3C;
};

extern f32 lbl_1_rodata_42D0;
extern f32 lbl_1_rodata_42D4;
extern s32 fn_1_54E34(void *, f32);
extern void fn_8003462C(u32, u32, u32);
extern void fn_800736C0(u32, void *);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern void lbl_8006DFC4(void *);
extern void lbl_8006E1D8(void *, f32, f32, f32);

/* GX write-gather FIFO */
#define GXFIFO_F32 (*(volatile f32 *)GX_FIFO_BASE)
/* one degenerate vertex: position and texcoord all zero */
#define ZERO_VTX()                          \
    do {                                    \
        GXFIFO_F32 = lbl_1_rodata_42D0;     \
        GXFIFO_F32 = lbl_1_rodata_42D0;     \
        GXFIFO_F32 = lbl_1_rodata_42D0;     \
        GXFIFO_F32 = lbl_1_rodata_42D0;     \
        GXFIFO_F32 = lbl_1_rodata_42D0;     \
    } while (0)

void fn_1_9F164(struct fn_1_9F164_Arg0 *arg0) {
    fn_1_9F164_Vec quad[4];
    fn_1_9F164_Vec pos;
    u32 color;
    u32 flags;
    f32 neg;
    f32 size;
    f32 r;

    pos.x = arg0->unk_14;
    pos.y = arg0->unk_24;
    pos.z = arg0->unk_34;
    flags = arg0->unk_38;
    if (flags & 2) {
        r = arg0->unk_4;
    } else {
        r = arg0->unk_0;
    }
    if (!(flags & 4) && fn_1_54E34(&pos, r) == 0) {
        arg0->unk_38 |= 1;
        return;
    }
    arg0->unk_38 &= ~1;
    color = arg0->unk_3C;
    fn_800736C0(0, &color);
    fn_8003462C(0x90, 0, 8);
    ZERO_VTX(); ZERO_VTX(); ZERO_VTX(); ZERO_VTX();
    ZERO_VTX(); ZERO_VTX(); ZERO_VTX(); ZERO_VTX();
    fn_8003462C(0x80, 0, 4);
    size = arg0->unk_0;
    neg = -size;
    lbl_8006DAEC();
    lbl_8006DFC4(arg0->unk_8);
    lbl_8006E1D8(&quad[0], neg, neg, lbl_1_rodata_42D0);
    lbl_8006E1D8(&quad[1], size, neg, lbl_1_rodata_42D0);
    lbl_8006E1D8(&quad[2], size, size, lbl_1_rodata_42D0);
    lbl_8006E1D8(&quad[3], neg, size, lbl_1_rodata_42D0);
    lbl_8006DB30();
    GXFIFO_F32 = quad[0].x;
    GXFIFO_F32 = quad[0].y;
    GXFIFO_F32 = quad[0].z;
    GXFIFO_F32 = lbl_1_rodata_42D0;
    GXFIFO_F32 = lbl_1_rodata_42D0;
    GXFIFO_F32 = quad[1].x;
    GXFIFO_F32 = quad[1].y;
    GXFIFO_F32 = quad[1].z;
    GXFIFO_F32 = lbl_1_rodata_42D4;
    GXFIFO_F32 = lbl_1_rodata_42D0;
    GXFIFO_F32 = quad[2].x;
    GXFIFO_F32 = quad[2].y;
    GXFIFO_F32 = quad[2].z;
    GXFIFO_F32 = lbl_1_rodata_42D4;
    GXFIFO_F32 = lbl_1_rodata_42D4;
    GXFIFO_F32 = quad[3].x;
    GXFIFO_F32 = quad[3].y;
    GXFIFO_F32 = quad[3].z;
    GXFIFO_F32 = lbl_1_rodata_42D0;
    GXFIFO_F32 = lbl_1_rodata_42D4;
}
/* fzgx:end fn_1_9F164 */

/* fzgx:begin fn_1_9F4B4 */
struct fn_1_9F4B4_Arg0 {
    u8 pad_0[0xC];
    f32 unk_C;
    s16 unk_10;
    u16 unk_12;
    u32 unk_14;
};

/* write-gather FIFO */
#define GX_WRITE_F32(v) (*(f32 *)GX_FIFO_BASE = (v))

void fn_1_9F4B4(struct fn_1_9F4B4_Arg0 *arg0) {
    f32 neg;
    f32 half;
    s32 rot;
    f32 corner[4][3];
    u32 tex;

    if (fn_1_54E34(arg0, arg0->unk_C) == 0) {
        arg0->unk_12 |= 1;
        return;
    }
    arg0->unk_12 &= 0xFFFE;
    tex = arg0->unk_14;
    fn_800736C0(0, &tex);
    fn_8003462C(0x90, 0, 8);
    /* 8 vertices x 5 floats, all zero */
    GX_WRITE_F32(lbl_1_rodata_42D0); GX_WRITE_F32(lbl_1_rodata_42D0); GX_WRITE_F32(lbl_1_rodata_42D0); GX_WRITE_F32(lbl_1_rodata_42D0); GX_WRITE_F32(lbl_1_rodata_42D0);
    GX_WRITE_F32(lbl_1_rodata_42D0); GX_WRITE_F32(lbl_1_rodata_42D0); GX_WRITE_F32(lbl_1_rodata_42D0); GX_WRITE_F32(lbl_1_rodata_42D0); GX_WRITE_F32(lbl_1_rodata_42D0);
    GX_WRITE_F32(lbl_1_rodata_42D0); GX_WRITE_F32(lbl_1_rodata_42D0); GX_WRITE_F32(lbl_1_rodata_42D0); GX_WRITE_F32(lbl_1_rodata_42D0); GX_WRITE_F32(lbl_1_rodata_42D0);
    GX_WRITE_F32(lbl_1_rodata_42D0); GX_WRITE_F32(lbl_1_rodata_42D0); GX_WRITE_F32(lbl_1_rodata_42D0); GX_WRITE_F32(lbl_1_rodata_42D0); GX_WRITE_F32(lbl_1_rodata_42D0);
    GX_WRITE_F32(lbl_1_rodata_42D0); GX_WRITE_F32(lbl_1_rodata_42D0); GX_WRITE_F32(lbl_1_rodata_42D0); GX_WRITE_F32(lbl_1_rodata_42D0); GX_WRITE_F32(lbl_1_rodata_42D0);
    GX_WRITE_F32(lbl_1_rodata_42D0); GX_WRITE_F32(lbl_1_rodata_42D0); GX_WRITE_F32(lbl_1_rodata_42D0); GX_WRITE_F32(lbl_1_rodata_42D0); GX_WRITE_F32(lbl_1_rodata_42D0);
    GX_WRITE_F32(lbl_1_rodata_42D0); GX_WRITE_F32(lbl_1_rodata_42D0); GX_WRITE_F32(lbl_1_rodata_42D0); GX_WRITE_F32(lbl_1_rodata_42D0); GX_WRITE_F32(lbl_1_rodata_42D0);
    GX_WRITE_F32(lbl_1_rodata_42D0); GX_WRITE_F32(lbl_1_rodata_42D0); GX_WRITE_F32(lbl_1_rodata_42D0); GX_WRITE_F32(lbl_1_rodata_42D0); GX_WRITE_F32(lbl_1_rodata_42D0);
    fn_8003462C(0x80, 0, 4);
    half = arg0->unk_C;
    neg = -half;
    lbl_8006DAEC();
    lbl_8006E0A4(arg0);
    rot = arg0->unk_10;
    if ((s16)rot != 0) {
        mathutil_mtxA_rotate_z(rot);
    }
    lbl_8006E1D8( (u32)(f32 *)(corner[0]), neg, neg, lbl_1_rodata_42D0);
    lbl_8006E1D8( (u32)(f32 *)(corner[1]), half, neg, lbl_1_rodata_42D0);
    lbl_8006E1D8( (u32)(f32 *)(corner[2]), half, half, lbl_1_rodata_42D0);
    lbl_8006E1D8( (u32)(f32 *)(corner[3]), neg, half, lbl_1_rodata_42D0);
    lbl_8006DB30();
    GX_WRITE_F32(corner[0][0]);
    GX_WRITE_F32(corner[0][1]);
    GX_WRITE_F32(corner[0][2]);
    GX_WRITE_F32(lbl_1_rodata_42D0);
    GX_WRITE_F32(lbl_1_rodata_42D0);
    GX_WRITE_F32(corner[1][0]);
    GX_WRITE_F32(corner[1][1]);
    GX_WRITE_F32(corner[1][2]);
    GX_WRITE_F32(lbl_1_rodata_42D4);
    GX_WRITE_F32(lbl_1_rodata_42D0);
    GX_WRITE_F32(corner[2][0]);
    GX_WRITE_F32(corner[2][1]);
    GX_WRITE_F32(corner[2][2]);
    GX_WRITE_F32(lbl_1_rodata_42D4);
    GX_WRITE_F32(lbl_1_rodata_42D4);
    GX_WRITE_F32(corner[3][0]);
    GX_WRITE_F32(corner[3][1]);
    GX_WRITE_F32(corner[3][2]);
    GX_WRITE_F32(lbl_1_rodata_42D0);
    GX_WRITE_F32(lbl_1_rodata_42D4);
}
/* fzgx:end fn_1_9F4B4 */
