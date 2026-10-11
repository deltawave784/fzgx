#include "types.h"

struct fn_8008983C_Msg {
    u8 pad_0[0x18];
    u8 unk_18;
    u8 pad_19[3];
    u8 unk_1C;
};

struct fn_8008983C_Buffer {
    u32 unk_0;
    u8 unk_4;
    u8 pad_5[3];
    u8 unk_8;
    u8 pad_9[0x37];
};

static const u32 fzgx_pool_rodata_lbl_80095890[8] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0xA4D6574, 0x726F5452, 0x4B204F70, 0x74696F6E, 0x203A2053, 0x65726961, 0x6C494F20, 0x2D200000
};
static const u32 fzgx_pool_rodata_lbl_80095890_20[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x456E6162, 0x6C650A00
};
static const u32 fzgx_pool_rodata_lbl_80095890_28[3] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x44697361, 0x626C650A, 0x0
};
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_80095890(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .data objects in retail order */
    s = *(u8 *)fzgx_pool_rodata_lbl_80095890;
    s = *(u8 *)fzgx_pool_rodata_lbl_80095890_20;
    s = *(u8 *)fzgx_pool_rodata_lbl_80095890_28;
}
#pragma section code_type ".text"


extern s32 fn_8008963C(const char *);
extern void fn_8008D7C0(u32);
extern void *memset(void *, s32, u32);
extern s32 fn_8008D398(void *data, u32 size);

s32 fn_8008983C(struct fn_8008983C_Msg *msg) {
    struct fn_8008983C_Buffer buffer;
    u32 flag;

    
    flag = msg->unk_1C;
    if (msg->unk_18 == 1) {
        fn_8008963C(((const char *)fzgx_pool_rodata_lbl_80095890));
        if (flag != 0) {
            fn_8008963C(((const char *)fzgx_pool_rodata_lbl_80095890_20));
        } else {
            fn_8008963C(((const char *)fzgx_pool_rodata_lbl_80095890_28));
        }
        fn_8008D7C0(flag);
    }
    memset(&buffer, 0, 0x40);
    buffer.unk_4 = 0x80;
    buffer.unk_0 = 0x40;
    buffer.unk_8 = 0;
    fn_8008D398(&buffer, 0x40);
    return 0;
}
