#include "types.h"

struct InitMetroTRKCommTable_gDBCommTable {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
};

extern int AMC_IsStub(void);
extern int Hu_IsStub(void);
extern int ddh_cc_close(void);
extern int ddh_cc_shutdown(void);
extern int gdev_cc_close(void);
extern int gdev_cc_shutdown(void);
extern int udp_cc_close(void);
extern int udp_cc_initialize(void);
extern int udp_cc_open(void);
extern int udp_cc_peek(void);
extern int udp_cc_post_stop(void);
extern int udp_cc_pre_continue(void);
extern int udp_cc_read(void);
extern int udp_cc_shutdown(void);
extern int udp_cc_write(void);
extern s32 ddh_cc_initialize(u32, u32);
extern s32 ddh_cc_initinterrupts(void);
extern s32 ddh_cc_open(u32);
extern s32 ddh_cc_peek(void);
extern s32 ddh_cc_post_stop(void);
extern s32 ddh_cc_pre_continue(void);
extern s32 ddh_cc_read(u32, s32);
extern s32 ddh_cc_write(u8 *, s32);
extern s32 gdev_cc_initialize(u32, u32);
extern s32 gdev_cc_initinterrupts(void);
extern s32 gdev_cc_open(u32);
extern s32 gdev_cc_peek(void);
extern s32 gdev_cc_post_stop(void);
extern s32 gdev_cc_pre_continue(void);
extern u8 TRK_Use_BBA[];
extern struct InitMetroTRKCommTable_gDBCommTable gDBCommTable[];
extern u32 gdev_cc_read();
extern u32 gdev_cc_write(void *, s32);
extern u8 EndofProgramInstruction_80095BC8[];
extern void OSReport(const char *, ...);

s32 InitMetroTRKCommTable(u32 arg0) {
    u8 *p_EndofProgramInstruction_80095BC8;
    s32 v1 = 1;
    p_EndofProgramInstruction_80095BC8 = EndofProgramInstruction_80095BC8;
    OSReport((const char *)(p_EndofProgramInstruction_80095BC8 + 8), arg0);
    TRK_Use_BBA[0] = 0;
    if ((s32)arg0 == 2) {
        OSReport((const char *)(p_EndofProgramInstruction_80095BC8 + 32));
        TRK_Use_BBA[0] = 1;
        gDBCommTable[0].unk_0 = (u32)udp_cc_initialize;
        gDBCommTable[0].unk_18 = (u32)udp_cc_open;
        gDBCommTable[0].unk_1C = (u32)udp_cc_close;
        gDBCommTable[0].unk_10 = (u32)udp_cc_read;
        gDBCommTable[0].unk_14 = (u32)udp_cc_write;
        gDBCommTable[0].unk_8 = (u32)udp_cc_shutdown;
        gDBCommTable[0].unk_C = (u32)udp_cc_peek;
        gDBCommTable[0].unk_20 = (u32)udp_cc_pre_continue;
        gDBCommTable[0].unk_24 = (u32)udp_cc_post_stop;
        gDBCommTable[0].unk_4 = 0;
        return 0;
    } else {
        if ((s32)arg0 == 1) {
            OSReport((const char *)(p_EndofProgramInstruction_80095BC8 + 56));
            v1 = Hu_IsStub();
            gDBCommTable[0].unk_0 = (u32)gdev_cc_initialize;
            gDBCommTable[0].unk_18 = (u32)gdev_cc_open;
            gDBCommTable[0].unk_1C = (u32)gdev_cc_close;
            gDBCommTable[0].unk_10 = (u32)gdev_cc_read;
            gDBCommTable[0].unk_14 = (u32)gdev_cc_write;
            gDBCommTable[0].unk_8 = (u32)gdev_cc_shutdown;
            gDBCommTable[0].unk_C = (u32)gdev_cc_peek;
            gDBCommTable[0].unk_20 = (u32)gdev_cc_pre_continue;
            gDBCommTable[0].unk_24 = (u32)gdev_cc_post_stop;
            gDBCommTable[0].unk_4 = (u32)gdev_cc_initinterrupts;
        } else {
            if ((s32)arg0 == 0) {
                OSReport((const char *)(p_EndofProgramInstruction_80095BC8 + 92));
                v1 = AMC_IsStub();
                gDBCommTable[0].unk_0 = (u32)ddh_cc_initialize;
                gDBCommTable[0].unk_18 = (u32)ddh_cc_open;
                gDBCommTable[0].unk_1C = (u32)ddh_cc_close;
                gDBCommTable[0].unk_10 = (u32)ddh_cc_read;
                gDBCommTable[0].unk_14 = (u32)ddh_cc_write;
                gDBCommTable[0].unk_8 = (u32)ddh_cc_shutdown;
                gDBCommTable[0].unk_C = (u32)ddh_cc_peek;
                gDBCommTable[0].unk_20 = (u32)ddh_cc_pre_continue;
                gDBCommTable[0].unk_24 = (u32)ddh_cc_post_stop;
                gDBCommTable[0].unk_4 = (u32)ddh_cc_initinterrupts;
            } else {
                OSReport((const char *)(p_EndofProgramInstruction_80095BC8 + 128), arg0);
                OSReport((const char *)(p_EndofProgramInstruction_80095BC8 + 172));
                OSReport((const char *)(p_EndofProgramInstruction_80095BC8 + 220));
            }
        }
    }
    return v1;
}
