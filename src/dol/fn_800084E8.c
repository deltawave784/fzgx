#include "types.h"
extern f32 lbl_801A6F14;
extern f32 lbl_801A6F30;
extern f32 lbl_801A6F38;
extern u32 lbl_8006DAEC(void);
extern void fn_800087F4(void *, void *);
extern void fn_8003462C(u32, u32, u32);
extern void fn_80038BFC(f32 *);
extern void fn_80072558(void);
extern void lbl_8006D758(void);
extern void lbl_8006DB30(void);
extern void fn_80008A4C(void *);
#include "dolphin/gx.h"
#pragma opt_common_subs off
#define FIFO GXWGFifo.f32
static inline void fifo_pos(f32 x, f32 y, f32 z) { FIFO=x; FIFO=y; FIFO=z; }
void fn_800084E8(u32 arg0, u32 arg1, u32 arg2) {
 f32 v14,v1,v0,v2,v3,v4,v5,v6,v8,v7,v9,v10,v11,v12,v13;
 f32 v16,v17,v18,v19,v20,v21,v22,v23,v24,v25;
 struct { f32 a[6]; } loc_8;
 fn_800087F4((void *)arg0,(void *)arg1);
 lbl_8006DAEC(); lbl_8006D758(); fn_80072558(); lbl_8006DB30();
 fn_80038BFC((f32 *)&loc_8);
 v0=lbl_801A6F38/loc_8.a[1];
 v4=lbl_801A6F14/loc_8.a[3];
 v2=*(f32 *)((u8 *)arg1+4)*(v1=*(f32 *)((u8 *)arg1+0));
 v3=*(f32 *)((u8 *)arg1+12)*v1;
 v5=*(f32 *)((u8 *)arg1+8)*v1;
 v6=v0*v2; v7=v0*v3; v8=v4*v5;
 v9=v4*(f32)(*(f32 *)((u8 *)arg1+16)*v1);
 fn_8003462C(128,0,4);
v10=*(f32 *)((u8 *)arg1+0); FIFO=v6; FIFO=v8; FIFO=v10; FIFO=lbl_801A6F30; FIFO=lbl_801A6F30;
v11=*(f32 *)((u8 *)arg1+0); FIFO=v7; FIFO=v8; FIFO=v11; FIFO=lbl_801A6F14; FIFO=lbl_801A6F30;
v12=*(f32 *)((u8 *)arg1+0); FIFO=v7; FIFO=v9; FIFO=v12; FIFO=lbl_801A6F14; FIFO=lbl_801A6F14;
v13=*(f32 *)((u8 *)arg1+0); FIFO=v6; FIFO=v9; FIFO=v13; FIFO=lbl_801A6F30; FIFO=lbl_801A6F14;
fn_80008A4C((void *)arg1);
v14=*(f32 *)((u8 *)arg1+0);
fn_8003462C(176,0,5);
FIFO=v6; FIFO=v8; FIFO=v14;
FIFO=v7; FIFO=v8; FIFO=v14;
FIFO=v7; FIFO=v9; FIFO=v14;
FIFO=v6; FIFO=v9; FIFO=v14;
FIFO=v6; FIFO=v8; FIFO=v14;
if ((s32)*(u32 *)((u8 *)arg1+28)!=0) {
fn_8003462C(176,0,5);
fifo_pos(*(f32 *)((u8 *)arg1+32), *(f32 *)((u8 *)arg1+36), *(f32 *)((u8 *)arg1+40));
fifo_pos(*(f32 *)((u8 *)arg1+44), *(f32 *)((u8 *)arg1+48), *(f32 *)((u8 *)arg1+52));
fifo_pos(*(f32 *)((u8 *)arg1+56), *(f32 *)((u8 *)arg1+60), *(f32 *)((u8 *)arg1+64));
fifo_pos(*(f32 *)((u8 *)arg1+68), *(f32 *)((u8 *)arg1+72), *(f32 *)((u8 *)arg1+76));
fifo_pos(*(f32 *)((u8 *)arg1+32), *(f32 *)((u8 *)arg1+36), *(f32 *)((u8 *)arg1+40));
fn_8003462C(168,0,8);
fifo_pos(*(f32 *)((u8 *)arg1+32), *(f32 *)((u8 *)arg1+36), *(f32 *)((u8 *)arg1+40)); FIFO=v6; FIFO=v8; FIFO=v14;
fifo_pos(*(f32 *)((u8 *)arg1+44), *(f32 *)((u8 *)arg1+48), *(f32 *)((u8 *)arg1+52)); FIFO=v7; FIFO=v8; FIFO=v14;
fifo_pos(*(f32 *)((u8 *)arg1+56), *(f32 *)((u8 *)arg1+60), *(f32 *)((u8 *)arg1+64)); FIFO=v7; FIFO=v9; FIFO=v14;
fifo_pos(*(f32 *)((u8 *)arg1+68), *(f32 *)((u8 *)arg1+72), *(f32 *)((u8 *)arg1+76)); FIFO=v6; FIFO=v9; FIFO=v14;
}
}
