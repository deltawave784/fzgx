#include "types.h"
struct Sig_fn_800421C0_fn_800421C0_Arg0 { u8 pad_0[1]; u8 unk_1; };
struct Sig_fn_80041660_fn_80041660_Arg0 { u8 pad_0[4]; u32 unk_4; };
struct Sig_fn_80041618_fn_80041618_Arg0 { u8 pad_0[4]; u32 unk_4; };
struct Sig_fn_8004AEE4_fn_8004AEE4_Arg0 { u8 pad_0[1]; u8 unk_1; };
typedef u32 (*fn_8004D220_Fn0)(u32,u32);
typedef u32 (*fn_8004D220_Fn1)(u32,u32,u32,void *);
typedef u32 (*fn_8004D220_Fn2)(u32,u32,void *);
struct fn_8004D220_lbl_8017E5A8 { u32 unk_0,unk_4,unk_8; };
extern u32 lbl_8017E5A8[4];
extern u32 lbl_80091098[];
extern u32 lbl_80178CB8[];
extern s32 fn_800421C0(struct Sig_fn_800421C0_fn_800421C0_Arg0 *);
extern s32 fn_80041660(struct Sig_fn_80041660_fn_80041660_Arg0 *);
extern s32 fn_80041618(struct Sig_fn_80041618_fn_80041618_Arg0 *);
extern s32 fn_8004AEE4(struct Sig_fn_8004AEE4_fn_8004AEE4_Arg0 *);
extern s32 fn_8004C05C(u32);
extern s32 fn_8004C658(char *);
extern u32 fn_8004D528(u32);
extern s32 fn_80056C20(u32);
extern void fn_800474E4(u32);
extern s32 fn_8004EE84(u32);
extern s32 fn_8004EE64(u32);
extern void fn_8004EEA4(u32,u32);
extern void fn_8004EEC4(u32,u32);
extern void fn_8004216C(u32);
extern void *memset(void *,int,u32);
void fn_8004D220(u32 arg0) {
 struct fn_8004D220_lbl_8017E5A8 *p_lbl_8017E5A8;
 u32 v0; s32 v2; u32 v1; u32 v3,v4,v6,v5; s32 v7,v8;
 s32 v10; u32 v13,v12,v9; s32 v11; u32 v14,v15; s8 v16;
 struct {u32 a[4];} loc_8;
 p_lbl_8017E5A8=(struct fn_8004D220_lbl_8017E5A8 *)&lbl_8017E5A8;
 if (!arg0) { fn_800474E4((u32)&lbl_80091098); }
 else {
 if ((s8)*(u8 *)(arg0+1)==3) {
 if (fn_800421C0((void *)*(u32 *)(arg0+4))==3) {
 v3=fn_80041660((void *)*(u32 *)(arg0+4));
 p_lbl_8017E5A8->unk_8=v3;
 v1=arg0;
 for(v2=0;v2<(s32)v3;v1+=4,v2++) {
 v0=*(u32 *)(v1+24); v4=*(u32 *)v0;
 v0=((fn_8004D220_Fn0)*(u32 *)(v4+36))(v0,1);
 p_lbl_8017E5A8->unk_4=v0;
 if ((s32)v0>=64) break;
 }
 if(v2==(s32)v3) {
 fn_8004EEC4(*(u32 *)(arg0+12),0);
 *(u8 *)(arg0+1)=4;
 }
 }
 } else if ((s8)*(u8 *)(arg0+1)==1) { fn_8004D528(arg0);
 } else if ((s8)*(u8 *)(arg0+1)==2) {
 v5=*(u32 *)(arg0+12); v6=*(u32 *)(arg0+4);
 v7=fn_8004EE84(v5); v8=fn_8004EE64(v5);
 if(v7>=(s32)(*(u32 *)(arg0+72)<<1) || v8<=fn_80041618((void *)v6) || fn_800421C0((void *)*(u32 *)(arg0+4))==3) {
 if((s8)*(u8 *)(arg0+112)==0) {
 if((s8)*(u8 *)(arg0+114)==0) {
 fn_8004EEA4(v5,1);
 *(u32 *)(arg0+156)=0;
 *(u32 *)(arg0+160)=lbl_80178CB8[0];
 }
 *(u8 *)(arg0+1)=3;
 }
 *(u8 *)(arg0+113)=1;
 }
 if(fn_800421C0((void *)*(u32 *)(arg0+4))==3) {
 v11=fn_8004C05C(arg0);
 v9=arg0; v10=0;
 v12=(*(u32 *)(arg0+72)*v11)<<1;
 while(v10<v11) {
 v13=*(u32 *)(v9+24); v14=*(u32 *)v13;
 ((fn_8004D220_Fn1)*(u32 *)(v14+24))(v13,0,v12,&loc_8);
 memset((void *)loc_8.a[0],0,loc_8.a[1]);
 v15=*(u32 *)v13;
 ((fn_8004D220_Fn2)*(u32 *)(v15+32))(v13,1,&loc_8);
 v9+=4;v10++;
 }
 }
 } else if((s8)*(u8 *)(arg0+1)==4) {
 p_lbl_8017E5A8->unk_0=fn_8004EE84(*(u32 *)(arg0+12));
 if(fn_8004EE84(*(u32 *)(arg0+12))<=0) {
 fn_8004EEA4(*(u32 *)(arg0+12),0); *(u8 *)(arg0+1)=5;
 }
 }
 if(*(u32 *)(arg0+8)!=0 && fn_8004C658((char *)arg0)!=0) {
 v16=(s8)*(u8 *)(arg0+2);
 switch(v16) {
 case 3: break;
 case 0: case 1:
 if(fn_8004AEE4((void *)*(u32 *)(arg0+8))==3) fn_8004216C(*(u32 *)(arg0+4));
 break;
 case 2: fn_8004216C(*(u32 *)(arg0+4));break;
 }
 }
 if(*(u32 *)(arg0+8)!=0 && fn_8004AEE4((void *)*(u32 *)(arg0+8))==4) {
 *(s16 *)(arg0+96)=-1; *(u8 *)(arg0+1)=6;
 }
 if(*(u32 *)(arg0+148)!=0 && fn_80056C20(*(u32 *)(arg0+148))==3) {
 *(s16 *)(arg0+96)=-1; *(u8 *)(arg0+1)=6;
 }
 }
}
