
#include "types.h"
#include "dolphin/ax.h"

void fn_8002123C(void *sbuffer, void *buffer);

extern u16 lbl_80124800[3360];

extern u32 lbl_801A6B08;

void fn_80020E4C(u32 *address);

void fn_80020E80(u32 *address);

void fn_80020EA0(u32 *address);

void fn_80020EBC(u32 *address);

void fn_80020EDC(u32 *address);

void fn_80020EFC(u32 *address);

void fn_80020F1C(u32 *address);

void fn_80020F50(u32 *address);

void fn_80020F6C(u32 *address);

void fn_80020F88(u32 *address);

u32 fn_8002201C(void);

AXPB *fn_80022E5C(void);

void DCFlushRange(void *address, unsigned long length);

extern unsigned short *lbl_801A6AFC;

extern unsigned long lbl_801A6B00;

extern unsigned long lbl_801A6B04;

extern unsigned long lbl_801A6B08;

static inline void __AXWriteToCommandList(unsigned short data) {
    *lbl_801A6AFC = data;
    lbl_801A6AFC++;
}

void fn_8002123C(void *sbuffer, void *buffer) {
    unsigned long data;
    unsigned short *command_list;
    lbl_801A6B00 = 0x1A9;
    command_list = lbl_801A6AFC;
    data = fn_8002201C();
    __AXWriteToCommandList(0);
    __AXWriteToCommandList((unsigned short)(data >> 16));
    __AXWriteToCommandList((unsigned short)data);
    lbl_801A6B00 += 0x2E44;
    switch (lbl_801A6B08) {
    case 0:
        __AXWriteToCommandList(7);
        __AXWriteToCommandList((unsigned short)((unsigned long)sbuffer >> 16));
        __AXWriteToCommandList((unsigned long)sbuffer);
        lbl_801A6B00 += 0x546;
        break;
    case 1:
        __AXWriteToCommandList(0x11);
        __AXWriteToCommandList((unsigned short)((unsigned long)sbuffer >> 16));
        __AXWriteToCommandList((unsigned long)sbuffer);
        lbl_801A6B00 += 0x5E6;
        break;
    case 2:
        break;
    }
    data = (unsigned long)fn_80022E5C();
    __AXWriteToCommandList(2);
    __AXWriteToCommandList((unsigned short)(data >> 16));
    __AXWriteToCommandList((unsigned short)data);
    __AXWriteToCommandList(3);
    if (lbl_801A6B08 == 2) {
        fn_80020E4C(&data);
        if (data != 0) {
            __AXWriteToCommandList(0x13);
            __AXWriteToCommandList(data >> 16);
            __AXWriteToCommandList((unsigned short)data);
            fn_80020E80(&data);
            __AXWriteToCommandList(data >> 16);
            __AXWriteToCommandList((unsigned short)data);
            fn_80020EA0(&data);
            __AXWriteToCommandList(data >> 16);
            __AXWriteToCommandList((unsigned short)data);
            fn_80020EBC(&data);
            __AXWriteToCommandList(data >> 16);
            __AXWriteToCommandList((unsigned short)data);
            fn_80020EDC(&data);
            __AXWriteToCommandList(data >> 16);
            __AXWriteToCommandList((unsigned short)data);
            fn_80020EFC(&data);
            __AXWriteToCommandList(data >> 16);
            __AXWriteToCommandList((unsigned short)data);
            lbl_801A6B00 += 0xDED;
        }
        __AXWriteToCommandList(0x10);
        fn_80020F6C(&data);
        __AXWriteToCommandList(data >> 16);
        __AXWriteToCommandList((unsigned short)data);
        fn_80020F88(&data);
        __AXWriteToCommandList(data >> 16);
        __AXWriteToCommandList((unsigned short)data);
        lbl_801A6B00 += 0xDED;
    } else {
        fn_80020E4C(&data);
        if (data != 0) {
            __AXWriteToCommandList(4);
            __AXWriteToCommandList((unsigned short)(data >> 16));
            __AXWriteToCommandList((unsigned short)data);
            fn_80020EA0(&data);
            __AXWriteToCommandList((unsigned short)(data >> 16));
            __AXWriteToCommandList((unsigned short)data);
            lbl_801A6B00 += 0xDED;
        }
        fn_80020F1C(&data);
        if (data != 0) {
            __AXWriteToCommandList(5);
            lbl_801A6B00 += 0xDED;
            __AXWriteToCommandList((unsigned short)(data >> 16));
            __AXWriteToCommandList((unsigned short)data);
            fn_80020F50(&data);
            __AXWriteToCommandList((unsigned short)(data >> 16));
            __AXWriteToCommandList((unsigned short)data);
        }
    }
    if (lbl_801A6B04) {
        __AXWriteToCommandList(0x12);
        __AXWriteToCommandList(0x8000);
        __AXWriteToCommandList(0xA);
        __AXWriteToCommandList((unsigned long)lbl_80124800 >> 16);
        __AXWriteToCommandList((unsigned long)lbl_80124800);
        lbl_801A6B00 += 0xBB8;
    }
    __AXWriteToCommandList(0xE);
    __AXWriteToCommandList((unsigned short)((unsigned long)sbuffer >> 16));
    __AXWriteToCommandList((unsigned long)sbuffer);
    __AXWriteToCommandList((unsigned short)((unsigned long)buffer >> 16));
    __AXWriteToCommandList((unsigned long)buffer);
    lbl_801A6B00 += 0x2710;
    __AXWriteToCommandList(0xF);
    lbl_801A6B00 += 2;
    DCFlushRange(command_list, 0x300);
}
