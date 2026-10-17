#include "types.h"
#include "dol/globals.h"

struct Sig_fn_80064FDC_Src64FDC {
    u8 b[0x10];
};
struct Sig_fn_80064FDC_List64FDC {
    u8 count;
    u8 pad_1[7];
    struct Sig_fn_80064FDC_Src64FDC items[1];
};
extern void fn_80064FDC(u8, struct Sig_fn_80064FDC_List64FDC *);

struct fn_800657F4_Resource {
    u8 pad_0[0x18];
    u32 unk_18;
    u8 pad_1C[0x22];
    u16 unk_3E;
};

struct fn_800657F4_InitialRow {
    u8 pad_0[8];
    struct fn_800657F4_Resource *resource;
    u8 pad_C[0x484];
    u8 unk_490;
};
struct fn_800657F4_StateRow {
    struct Sig_fn_80064FDC_List64FDC *list;
    u8 unk_4;
    u8 unk_5;
    u8 unk_6;
    u8 unk_7;
    u8 pad_8[8];
};

#define INITIAL ((struct fn_800657F4_InitialRow *)lbl_801A6C80->unk_0[arg0])
#define STATE (&((struct fn_800657F4_StateRow *)lbl_801A6C80->unk_48C)[arg0])

void fn_800657F4(u8 arg0) {
    struct fn_800657F4_Resource *resource;
    u8 *base;
    u16 offset;
    u8 value;
    struct Sig_fn_80064FDC_List64FDC *list;

    resource = INITIAL->resource;
    base = (u8 *)resource + resource->unk_18;
    INITIAL->unk_490 = 0xFF;
    STATE->unk_5 = 0x7F;
    offset = resource->unk_3E;
    if (offset != 0) {
        STATE->list = (struct Sig_fn_80064FDC_List64FDC *)(base + offset);
        list = STATE->list;
        value = ((u8 *)list)[1];
        if (value != 0x80) {
            STATE->unk_7 = value;
        }
        fn_80064FDC(arg0, list);
    } else {
        STATE->list = 0;
    }
}
