#include "types.h"
#include "sofdec/sj.h"
typedef u32 (*fn_12_9D08_Fn0)(u32, u32, u32, u32);
struct fn_12_9D08_Arg1 { u32 unk_0; };
struct Sig_fn_800589BC_fn_800589BC_Arg2 { u32 unk_0; u32 unk_4; };
struct Sig_fn_800589BC_fn_800589BC_Arg3 { u32 unk_0; u32 unk_4; };
extern u32 fn_800589BC(u32, u32, struct Sig_fn_800589BC_fn_800589BC_Arg2 *, struct Sig_fn_800589BC_fn_800589BC_Arg3 *);
extern int MPV_GoNextDelimSj(SJ *);
extern u32 lbl_12_bss_6944;
extern u32 lbl_12_bss_6940;
#define W(o) (*(u32 *)((u8 *)arg0 + (o)))
#define S(o) (*(s32 *)((u8 *)arg0 + (o)))
typedef void (*GetFn)(struct fn_12_9D08_Arg1 *, s32, s32, void *);
typedef void (*BufFn)(struct fn_12_9D08_Arg1 *, s32, void *);
#define GET() ((GetFn)*(u32 *)((u8 *)arg1->unk_0 + 24))(arg1,1,0x7fffffff,(void *)(arg0+4808))
#define BUF(off,p) ((BufFn)*(u32 *)((u8 *)arg1->unk_0 + (off)))(arg1, ((off)==32?0:1), p)
#pragma opt_common_subs off
#pragma opt_propagation off
void fn_12_9D08(u32 arg0, struct fn_12_9D08_Arg1 *arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5, u32 arg6, u32 arg7) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v4;
    u32 v5;
    u32 v6;
    u32 v7;
    u32 v8;
    u32 v9;
    u32 v10;
    u32 v11;
    u32 v12;
    u32 v13;
    u32 v14;
    u32 v15;
    u32 v16;
    u32 v17;
    struct Sig_fn_800589BC_fn_800589BC_Arg3 tail, done;
    GET();
    v0=W(4808); v1=W(4816);
    v14=v0&~3; v13=(v0-v14)<<3;
    v10=*(u32 *)v14 << v13;
    v12=*(u32 *)(v14+4); v14+=8;
    v13+=v1;
    if ((s32)v13>=32) { v13-=32; v10=v12<<v13; v12=*(u32 *)v14; v14+=4; }
    else v10 <<= v1;
    for (;;) {
        v15=v10>>9;
        if ((s32)v13>9) v15 |= v12>>(41-v13);
        if (!v15) break;
        v11=W(776);
        for (;;) {
            v17=v10>>20;
            if ((s32)v13>20) v17 |= v12>>(52-v13);
            v4=v17>>8;
            if (v4 == 0) {
                v17=((s16 *)lbl_12_bss_6944)[v17];
            } else {
                v17=((s16 *)lbl_12_bss_6940)[v17>>6];
            }
            v4=v17&15;
            v13+=v4;
            if ((s32)v13>=32) { v13-=32; v10=v12<<v13; v12=*(u32 *)v14; v14+=4; }
            else v10<<=v4;
            v5=(s32)((v17>>2)&255)>>2;
            if ((s32)v5==34) continue;
            if ((s32)v5==35) { W(776)+=33; continue; }
            if ((s32)v5==36) { v11=-2; break; }
            W(776)+=v5;
            W(784)=v17>>10;
            if (S(776)>S(780)) v11=-2;
            else v11=W(776)-v11;
            break;
        }
        if (v11 == -2) break;
        if (W(784)&16) {
            if ((s32)v13>=27) {
                v13-=27;
                if (v13) {
                    v10 |= v12>>(5-v13);
                    v4=v10>>27;
                    v10=v12<<v13;
                } else { v4=v10>>27; v10=v12; }
                v12=*(u32 *)v14; v14+=4;
            } else { v4=v10>>27; v10<<=5; v13+=5; }
            W(700)=v4;
        }
        W(0)=v10; W(4)=v12; W(8)=v13; W(12)=v14;
        ((void (*)(u32))W(668))(arg0);
        ((void (*)(u32))W(676))(arg0);
        if (--S(4852)<=0) {
            W(4852)=W(428);
            ((void (*)(u32))W(432))(W(436));
        }
        v13=W(8); v14=W(12);
        v16=v13&7;
        v4=(((s32)(v13-v16)+7)>>3);
        v4=v14+v4;
        v4-=8;
        v4-=W(4808);
        v10=W(0); v12=W(4);
        if ((s32)(W(4812)-v4)>2048) continue;
        fn_800589BC(arg0+4808,v4,(struct Sig_fn_800589BC_fn_800589BC_Arg2 *)(arg0+4808),&tail);
        BUF(32,(void *)(arg0+4808));
        BUF(28,&tail);
        GET();
        v0=W(4808); v14=v0&~3; v13=(v0-v14)<<3;
        v10=*(u32 *)v14<<v13; v12=*(u32 *)(v14+4); v14+=8;
        v13+=v16;
        if ((s32)v13>=32) { v13-=32; v10=v12<<v13; v12=*(u32 *)v14; v14+=4; }
        else v10<<=v16;
    }
    W(4816)=v13&7;
    v0=W(4816);
    v9=W(4808);
    v4=v13-v0;
    v0=v4+7;
    v0=(s32)v0>>3;
    v4=v14+v0;
    v0=v4-8;
    v4=v0-v9;
    fn_800589BC(arg0+4808,v4,(struct Sig_fn_800589BC_fn_800589BC_Arg2 *)(arg0+4808),&done);
    BUF(32,(void *)(arg0+4808)); BUF(28,&done);
    MPV_GoNextDelimSj((SJ *)arg1);
}
