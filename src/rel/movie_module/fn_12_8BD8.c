#include "types.h"
#include "sofdec/sj.h"
struct fn_12_8BD8_Arg1 { u32 unk_0; };
typedef u32 (*fn_12_8BD8_Fn0)(struct fn_12_8BD8_Arg1 *, u32, u32, u32);
typedef u32 (*fn_12_8BD8_Fn1)(struct fn_12_8BD8_Arg1 *, u32, void *);
extern u32 lbl_12_bss_6944;
extern u32 lbl_12_bss_6940;
struct Sig_fn_800589BC_fn_800589BC_Arg2 { u32 unk_0; u32 unk_4; };
struct Sig_fn_800589BC_fn_800589BC_Arg3 { u32 unk_0; u32 unk_4; };
extern u32 fn_800589BC(u32, u32, struct Sig_fn_800589BC_fn_800589BC_Arg2 *, struct Sig_fn_800589BC_fn_800589BC_Arg3 *);
extern int MPV_GoNextDelimSj(SJ *);
#define F(off) (*(u32 *)((u8 *)arg0 + (off)))
void fn_12_8BD8(u32 arg0, struct fn_12_8BD8_Arg1 *arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5, u32 arg6, u32 arg7) {
 u32 v9; u32 v0; u32 v1; u32 v2; u32 v3; u32 v5; u32 v6; u32 v7; u32 v8; u32 v10; u32 v17; u32 v12; s32 v13; u32 v14; u32 v15; s32 v16; u32 v11; u32 v4;
 struct Sig_fn_800589BC_fn_800589BC_Arg3 chunk;
 struct Sig_fn_800589BC_fn_800589BC_Arg3 end;
 ((fn_12_8BD8_Fn0)*(u32 *)((u8 *)arg1->unk_0+24))(arg1,1,0x7fffffff,arg0+4808);
 v0=F(4808); v1=F(4816); v14=v0&~3;
 v13=(v0-v14)<<3;
 v10=*(u32 *)v14<<v13; v12=*(u32 *)(v14+4); v14+=8;
 v13+=v1;
 if ((s32)v13>=32) { v13-=32; v10=v12<<v13; v12=*(u32 *)v14; v14+=4; }
 else v10<<=v1;
 for (;;) {
 v15=v10>>9;
 if ((s32)v13>9) v15|=v12>>(41-v13);
 if (!v15) break;
 v11=F(776);
 for (;;) {
 v17=v10>>20;
 if ((s32)v13>20) v17|=v12>>(52-v13);
 if ((v17>>8)==0) v17=((s16 *)lbl_12_bss_6944)[v17];
 else v17=((s16 *)lbl_12_bss_6940)[v17>>6];
 v4=v17&15; v13+=v4;
 if ((s32)v13>=32) { v13-=32; v10=v12<<v13; v12=*(u32 *)v14; v14+=4; }
 else v10<<=v4;
 v16=(s32)((v17>>2)&255)>>2;
 if (v16==34) continue;
 if (v16==35) { F(776)+=33; continue; }
 if (v16==36) { v11=-2; break; }
 F(776)+=v16; F(784)=v17>>10;
 if ((s32)F(776)>(s32)F(780)) v11=-2;
 else v11=F(776)-v11;
 break;
 }
 if (v11==-2) break;
 F(0)=v10; F(4)=v12; F(8)=v13; F(12)=v14;
 ((void (*)(u32))F(668))(arg0);
 ((void (*)(u32))F(676))(arg0);
 v11=F(4852)-1;
 F(4852)=v11;
 if ((s32)v11<=0) {
 F(4852)=F(428);
 ((void (*)(u32))F(432))(F(436));
 }
 v13=F(8); v10=F(0); v12=F(4); v14=F(12);
 v11=v10>>31;
 if (v13==31) { v10=v12; v12=*(u32 *)v14; v13=0; v14+=4; }
 else { v10<<=1; v13++; }
 if (v11!=1) break;
 v1=v13&7;
 v4=v14+(((s32)(v13-v1)+7)>>3);
 v4-=8;
 v4-=F(4808);
 if ((s32)(F(4812)-v4)>2048) continue;
 fn_800589BC(arg0+4808,v4,(struct Sig_fn_800589BC_fn_800589BC_Arg2 *)(arg0+4808),&chunk);
 ((fn_12_8BD8_Fn1)*(u32 *)((u8 *)arg1->unk_0+32))(arg1,0,(void *)(arg0+4808));
 ((fn_12_8BD8_Fn1)*(u32 *)((u8 *)arg1->unk_0+28))(arg1,1,&chunk);
 ((fn_12_8BD8_Fn0)*(u32 *)((u8 *)arg1->unk_0+24))(arg1,1,0x7fffffff,arg0+4808);
 v0=F(4808); v14=v0&~3; v13=(v0-v14)<<3;
 v10=*(u32 *)v14<<v13; v12=*(u32 *)(v14+4); v14+=8;
 v13+=v1;
 if ((s32)v13>=32) { v13-=32; v10=v12<<v13; v12=*(u32 *)v14; v14+=4; }
 else v10<<=v1;
 }
 F(4816)=v13&7;
 {
 /* Volatile: sample the externally managed SJ chunk address when committing consumed bytes. */
 u8 *base=(u8 *)*(volatile u32 *)((u8 *)arg0+4808);
 v4=v13-F(4816);
 v0=((s32)v4+7)>>3;
 v4=v14+v0;
 v0=v4-8;
 v4=(u8 *)v0-base;
 }
 fn_800589BC(arg0+4808,v4,(struct Sig_fn_800589BC_fn_800589BC_Arg2 *)(arg0+4808),&end);
 ((fn_12_8BD8_Fn1)*(u32 *)((u8 *)arg1->unk_0+32))(arg1,0,(void *)(arg0+4808));
 ((fn_12_8BD8_Fn1)*(u32 *)((u8 *)arg1->unk_0+28))(arg1,1,&end);
 MPV_GoNextDelimSj((SJ *)arg1);
}
