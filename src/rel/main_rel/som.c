#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/som.h"
extern u32 lbl_1_bss_3BBC;
extern int sprintf(char *s, const char *format, ...);
extern s32 fn_1_465D0(s32 arg0, s32 arg1);

/* fzgx:begin fn_1_1383C */
void fn_1_1383C(void) {
    lbl_1_bss_3BBC = 1;
}
/* fzgx:end fn_1_1383C */

/* fzgx:begin fn_1_1384C */
typedef struct { void *obj; char *name; } NEnt;
typedef struct { s32 count; u32 pad; NEnt *ents; } NTab;
typedef struct { NTab *tab; } NHold;
typedef struct { u32 flags; char *name; void *res; u32 pad; } SItem;
typedef struct { u32 pad; s32 count; SItem *items; u32 pad2; } SGrp;
typedef struct { u8 pad[0x1a]; u16 a; u16 b; u8 pad2[2]; u32 off; } Res;
extern int fn_80083BCC(const char *, const char *);

static inline Res *find_resource(NHold **arg0, char *name) {
    NHold **p;
    s32 k;
    u8 *s;
    int mv;

    for (p = arg0; *p != NULL; p++) {
        if ((*p)->tab != NULL) {
            for (k = 0; k < (*p)->tab->count; k++) {
                s = (u8 *)(*p)->tab->ents[k].name;
                mv = 0;
                if (s[0] == 'M' && s[1] == 'V' && s[2] == '_') {
                    mv = 1;
                }
                if ((mv && fn_80083BCC((char *)s + 3, name) == 0) || (!mv && fn_80083BCC((char *)s, name) == 0)) {
                    return (Res *)(*p)->tab->ents[k].obj;
                }
            }
        }
    }
    return NULL;
}

void fn_1_1384C(NHold **arg0) {
    s32 i;
    SGrp *grp;
    SItem *item;
    s32 j;
    u8 *base;
    Res *r;
    s32 n;

    grp = (SGrp *)lbl_1_bss_3BE0->unk_68;
    for (i = 0; i < (s32)lbl_1_bss_3BE0->unk_64; i++, grp++) {
        item = grp->items;
        for (j = 0; j < grp->count; j++, item++) {
            r = find_resource(arg0, item->name);
            item->res = r;
            if (r != NULL && r->a == 1 && r->b == 0) {
                u16 *ip;
                base = (u8 *)r + 0x40;
                r = (Res *)((u8 *)r + r->off);
                ip = (u16 *)((u8 *)r + 0x16);
                for (n = ((u8 *)r)[0x12]; n > 0; n--) {
                    if ((*(u32 *)(base + (*ip << 5)) & 1) != 0) {
                        item->flags |= 0x10;
                    } else {
                        item->flags |= 8;
                    }
                    ip++;
                }
            }
        }
    }
}
/* fzgx:end fn_1_1384C */

/* fzgx:begin fn_1_13A28 */
typedef struct Fn1_13A28 Fn1_13A28;

struct Fn1_13A28 {
    u8 unk_00[4];
    Fn1_13A28 *unk_04;
    Fn1_13A28 *unk_08;
    s32 unk_0c;
    Fn1_13A28 *unk_10;
    u8 unk_14[0x10];
    Fn1_13A28 *unk_24;
    Fn1_13A28 *unk_28;
    Fn1_13A28 *unk_2c;
    Fn1_13A28 *unk_30;
    Fn1_13A28 *unk_34;
    Fn1_13A28 *unk_38;
    Fn1_13A28 *unk_3c;
    Fn1_13A28 *unk_40;
    Fn1_13A28 *unk_44;
    u8 unk_48[8];
};

void fn_1_13A28(Fn1_13A28 *arg0, s32 arg1) {
    Fn1_13A28 *child;

    if (arg0->unk_04 != 0) {
        arg0->unk_04 = (Fn1_13A28 *)((u8 *)arg0->unk_04 + arg1);
    }
    if (arg0->unk_08 != 0) {
        arg0->unk_08 = (Fn1_13A28 *)((u8 *)arg0->unk_08 + arg1);
    }
    if (arg0->unk_10 != 0) {
        arg0->unk_10 = (Fn1_13A28 *)((u8 *)arg0->unk_10 + arg1);
    }

    child = arg0->unk_04;
    if (child->unk_24 != 0) {
        child->unk_24 = (Fn1_13A28 *)((u8 *)child->unk_24 + arg1);
    }
    if (child->unk_28 != 0) {
        child->unk_28 = (Fn1_13A28 *)((u8 *)child->unk_28 + arg1);
    }
    if (child->unk_2c != 0) {
        child->unk_2c = (Fn1_13A28 *)((u8 *)child->unk_2c + arg1);
    }
    if (child->unk_30 != 0) {
        child->unk_30 = (Fn1_13A28 *)((u8 *)child->unk_30 + arg1);
    }
    if (child->unk_34 != 0) {
        child->unk_34 = (Fn1_13A28 *)((u8 *)child->unk_34 + arg1);
    }
    if (child->unk_38 != 0) {
        child->unk_38 = (Fn1_13A28 *)((u8 *)child->unk_38 + arg1);
    }
    if (child->unk_3c != 0) {
        child->unk_3c = (Fn1_13A28 *)((u8 *)child->unk_3c + arg1);
    }
    if (child->unk_40 != 0) {
        child->unk_40 = (Fn1_13A28 *)((u8 *)child->unk_40 + arg1);
    }
    if (child->unk_44 != 0) {
        child->unk_44 = (Fn1_13A28 *)((u8 *)child->unk_44 + arg1);
    }

    if (arg0->unk_0c > 0) {
        s32 i;
        Fn1_13A28 *entry = arg0->unk_10;
        for (i = 0; i < arg0->unk_0c; entry += 1) {
            fn_1_13A28(entry, arg1);
            i++;
        }
    }
}
/* fzgx:end fn_1_13A28 */

/* fzgx:begin fn_1_14D5C */
void fn_1_14D5C(char *arg0, int arg1) {
    char buffer[32];

    sprintf(buffer, (const char *)lbl_1_data_5194, arg0);
    if (arg1 != 0) {
        fn_1_465D0( (s32)(char *)(buffer), 2);
    } else {
        fn_1_465D0( (s32)(char *)(buffer), 1);
    }
}
/* fzgx:end fn_1_14D5C */
