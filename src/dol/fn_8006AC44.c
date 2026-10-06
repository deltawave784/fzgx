#include "types.h"
struct fn_8006AC44_Arg0 { u8 pad_0[7]; u8 unk_7; u8 unk_8; };
struct fn_8006AC44_Arg1 { u16 unk_0; u8 pad_2[4]; u8 unk_6; u8 unk_7; };
struct fn_8006AC44_Arg2 {
 u8 pad_0[7]; u8 unk_7; u8 unk_8; u8 pad_9[8]; u8 unk_11; u8 unk_12;
 u8 pad_13[8]; u8 unk_1B; u8 unk_1C; u8 pad_1D[1]; u16 unk_1E;
};
#pragma opt_common_subs off
u32 fn_8006AC44(struct fn_8006AC44_Arg0 *arg0, struct fn_8006AC44_Arg1 *arg1, struct fn_8006AC44_Arg2 *arg2) {
 s32 v7; s32 v5; s32 v0; s32 v2; s32 v1; s32 v3; u32 v4; s32 v6; s32 unk_1;
 s32 v9; s32 v10; s32 v11; s32 unk_2;
 s32 v20; s32 v18; s32 v13; s32 v15; s32 v14; s32 v16; u32 v17; s32 v19; s32 unk_3;
 s32 v22; s32 v23; s32 v24; s32 unk_4;
 v0=arg2->unk_1B; v1=arg2->unk_11; v2=arg1->unk_6;
 if(v2 > v1-(v0&255)*2) {
  if(((arg1->unk_0 ^ arg2->unk_1E)&0x40)!=0) {
   v3=v2-v0; v4=v3 & ~(v3>>31); arg2->unk_11=v4; arg0->unk_7=255;
  } else if((arg1->unk_0 & 0x40)!=0) { arg0->unk_7=255; }
  else {
   v5=arg2->unk_7;
   if(v2<v5) {arg2->unk_7=v2; v5=v2;}
   if(v2>v1) {arg2->unk_11=v2; v1=v2;}
   v7=v1-v5-((v0&255)<<1); if(v7==0) v7=1;
   unk_1=(v2-(v5+v0))*255/v7;
   if(unk_1<0) unk_1=0; if(unk_1>255) unk_1=255;
   arg0->unk_7=unk_1;
  }
 } else {
  v9=arg2->unk_7;
  if(v2<v9) {arg2->unk_7=v2; v9=v2;}
  if(v2>v1) {arg2->unk_11=v2; v1=v2;}
  v11=v1-v9-((v0&255)<<1); if(v11==0) v11=1;
  unk_2=(v2-(v9+v0))*255/v11;
  if(unk_2<0) unk_2=0; if(unk_2>255) unk_2=255;
  arg0->unk_7=unk_2;
 }
 v13=arg2->unk_1C; v14=arg2->unk_12; v15=arg1->unk_7;
 if(v15>v14-(v13&255)*2) {
  if(((arg1->unk_0^arg2->unk_1E)&0x20)!=0) {
   v16=v15-v13; v17=v16 & ~(v16>>31); arg2->unk_12=v17; arg0->unk_8=255; return (u32)arg0;
  }
  if((arg1->unk_0&0x20)!=0) {arg0->unk_8=255; return (u32)arg0;}
  v18=arg2->unk_8;
  if(v15<v18) {arg2->unk_8=v15; v18=v15;}
  if(v15>v14) {arg2->unk_12=v15; v14=v15;}
  v20=v14-v18-((v13&255)<<1); if(v20==0) v20=1;
  unk_3=(v15-(v18+v13))*255/v20;
  if(unk_3<0) unk_3=0; if(unk_3>255) unk_3=255;
  arg0->unk_8=unk_3; return (u32)arg0;
 }
 v22=arg2->unk_8;
 if(v15<v22) {arg2->unk_8=v15; v22=v15;}
 if(v15>v14) {arg2->unk_12=v15; v14=v15;}
 v24=v14-v22-((v13&255)<<1); if(v24==0) v24=1;
 unk_4=(v15-(v22+v13))*255/v24;
 if(unk_4<0) unk_4=0; if(unk_4>255) unk_4=255;
 arg0->unk_8=unk_4;
 return (u32)arg0;
}
