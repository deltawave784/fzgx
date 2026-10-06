#include "types.h"
struct fn_80076238_Mtx {
 f32 unk_0, unk_4, unk_8, unk_C, unk_10, unk_14, unk_18, unk_1C, unk_20, unk_24, unk_28, unk_2C;
};
struct fn_80076238_State { s32 unk_0, unk_4, unk_8, unk_C; };
struct fn_80076238_Color { u8 r,g,b,a; };
extern struct fn_80076238_Mtx *lbl_801A6D00;
extern u8 lbl_801A3220[];
extern u8 lbl_8015AD1C[];
extern const f32 lbl_801A7480, lbl_801A7488, lbl_801A748C, lbl_801A749C;
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern void lbl_8006E14C(f32);
extern void GXLoadTexMtxImm(void *,u32,u32);
extern void fn_8006F120(void *,void *);
extern void fn_80073C6C(s32);
extern void fn_80072AB0(s32,s32,s32);
extern void fn_800734A8(u32,s32,s32,s32);
extern void fn_800736C0(s32,struct fn_80076238_Color);
extern void fn_800735C8(s32,s32);
extern void fn_800745A4(u32,s32,s32,u32,u32,u32);
extern void fn_80072C24(s32,s32,s32,s32,s32);
extern void fn_80072D64(s32,s32,s32,s32,u8,s32);
extern void fn_80072CC4(s32,s32,s32,s32,s32);
extern void fn_80072E20(s32,s32,s32,s32,u8,s32);
void fn_80076238(struct fn_80076238_State *arg0, struct fn_80076238_State *arg1, s32 arg2, s32 arg3) {
 struct fn_80076238_Color color;
 fn_80073C6C(arg0->unk_0);
 fn_80072AB0(arg0->unk_0,0,0);
 if (*(s32 *)(lbl_801A3220+0x3C) == 0) {
 lbl_8006DAEC();
 lbl_801A6D00->unk_C = lbl_801A7480;
 lbl_801A6D00->unk_1C = lbl_801A7480;
 lbl_801A6D00->unk_2C = lbl_801A7480;
 GXLoadTexMtxImm(lbl_801A6D00,30,0);
 lbl_8006DB30();
 *(s32 *)(lbl_801A3220+0x3C)=1;
 }
 if (*(s32 *)(lbl_801A3220+0x40) == 0) {
 lbl_8006DAEC();
 fn_8006F120(lbl_8015AD1C,lbl_801A3220+0x50);
 lbl_801A6D00->unk_C = lbl_801A748C;
 lbl_801A6D00->unk_10 = lbl_801A6D00->unk_10 * lbl_801A749C;
 lbl_801A6D00->unk_14 = lbl_801A6D00->unk_14 * lbl_801A749C;
 lbl_801A6D00->unk_18 = lbl_801A6D00->unk_18 * lbl_801A749C;
 lbl_801A6D00->unk_1C = lbl_801A748C;
 lbl_801A6D00->unk_20 = lbl_801A7480;
 lbl_801A6D00->unk_24 = lbl_801A7480;
 lbl_801A6D00->unk_28 = lbl_801A7480;
 lbl_801A6D00->unk_2C = lbl_801A7488;
 lbl_8006E14C(lbl_801A748C);
 GXLoadTexMtxImm(lbl_801A6D00,64,0);
 lbl_8006DB30();
 *(s32 *)(lbl_801A3220+0x40)=1;
 }
 color.r=arg2; color.g=arg2; color.b=arg2; color.a=arg2;
 fn_800734A8(arg0->unk_0,arg0->unk_4,arg0->unk_C,4);
 fn_800736C0(0,color);
 fn_800735C8(arg0->unk_0,12);
 fn_800745A4(arg0->unk_4,0,1,30,1,64);
 if(arg3) fn_80072C24(arg0->unk_0,15,8,arg1->unk_8,15);
 else fn_80072C24(arg0->unk_0,15,8,14,arg1->unk_8);
 fn_80072D64(arg0->unk_0,0,0,0,1,0);
 fn_80072CC4(arg0->unk_0,7,7,7,arg1->unk_C);
 fn_80072E20(arg0->unk_0,0,0,0,1,0);
 arg0->unk_0++; arg0->unk_4++;
}
