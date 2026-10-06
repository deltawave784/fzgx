#include "types.h"
typedef struct Obj {
    u8 unk0; u8 state; s8 mode; s8 channels;
    void *decoder; void *stream; void *out; void *aux;
    u8 pad14[0x24]; s32 unit;
    s16 x3c,x3e,volume; u8 pad42[6];
    s32 size; u8 pad4c[4]; s32 skip;
    u8 pad54[0x20]; void *extra;
    u8 pad78[0x14]; s32 block; u32 length;
    u8 pad94[0x14]; u8 pending; u8 pada9[7];
    u32 b0,b4,b8,bc;
} Obj;
extern s32 fn_8004AEE4(void *);
extern void fn_8004C980(void *,u32,u32,u32,u32);
extern s32 fn_800421C0(void *);
extern s32 fn_80041660(void *);
extern void fn_80046F88(s32,s32,void *,s32);
extern char lbl_800910C4[];
extern void fn_80047464(void *,void *);
extern void ADXT_Stop(void *);
extern s32 fn_80041684(void *);
extern s32 fn_800415D0(void *);
extern s32 fn_80041618(void *);
extern void fn_80042170(void *,u32);
extern s32 fn_80041530(void *);
extern void fn_8004AC04(void *,s32);
extern void adxt_eos_entry(void);
extern void fn_8004AC4C(void *,void (*)(void),void *);
extern u32 fn_80041554(void *);
extern u32 fn_800415AC(void *);
extern void fn_800416DC(void *,u32);
extern void fn_800416CC(void *,u32);
extern u32 fn_800416D4(void *,u32);
extern void fn_8004DFF0(void);
extern void fn_800416E4(void *,void (*)(void),void *);
extern s32 fn_800415F4(void *);
extern void fn_8004D8DC(void);
extern s32 fn_8004163C(void *);
extern void fn_8004EDA4(void *,s32);
extern void fn_8004EE04(void *,s32);
extern void fn_8004EE24(void *,s32);
extern void fn_8004ED80(void *,s32);
extern s32 fn_800414D0(void *);
extern void fn_8004EDE4(void *,s32);
extern void fn_8004BBC4(void *,s32 *,s32 *);
extern void fn_8004BBC8(void *,s32,s32);
extern void adxt_set_outpan(void *);
extern void fn_80046508(void *,s32);
extern s32 fn_800416A8(void *);
extern void *fn_80041458(void *);
extern s32 fn_8004ED5C(void *,void *);
extern void fn_8004EEC4(void *,s32);

void fn_8004D528(Obj *p) {
    void *obj;
    s32 rate, streaming, channels, length;
    s32 a,b;
    char buffer[32];
    s32 n,align;
    s32 rate2, value;
    obj=p->decoder;
    a=0; b=0;
    if ((p->mode==0 || p->mode==1) && (s32)p->pending==1) {
        if(fn_8004AEE4(p->stream)==2) return;
        if(p->aux) {
            void **vt=*(void ***)p->aux;
            ((void (*)(void *))vt[5])(p->aux);
        }
        fn_8004C980(p,p->b0,p->b4,p->b8,p->bc);
        p->pending=0;
    }
    if(fn_800421C0(obj)!=2) return;
    n=fn_80041660(obj);
    if(n>p->channels) {
        fn_80046F88(n,p->channels,buffer,16);
        fn_80047464(lbl_800910C4,buffer);
        ADXT_Stop(p);
        return;
    }
    rate=fn_80041684(obj);
    streaming=fn_800415D0(obj);
    if(streaming>0) p->size=rate/p->unit*3;
    else p->size=(rate/p->unit*3)/2;
    align=fn_80041618(obj)*2;
    p->size=(p->size+align)/align*align;
    fn_80042170(obj,p->size);
    if(streaming>0) {
        if((s32)(u8)p->mode==2) p->skip=0;
        else {
            n=fn_80041530(obj);
            p->skip=2048-n%2048;
            n=(n+2047)/2048;
            p->skip%=2048;
            p->block=n;
            fn_8004AC04(p->stream,n);
            fn_8004AC4C(p->stream,adxt_eos_entry,p);
        }
        fn_80041554(obj);
        p->length=fn_800415AC(obj);
        fn_800416DC(obj,p->length);
        fn_800416CC(obj,0);
        fn_800416D4(obj,0);
        fn_800416E4(obj,fn_8004DFF0,p);
    } else {
        if(p->stream) fn_8004AC04(p->stream,0x7fffffff);
        fn_800416DC(obj,fn_800415F4(obj));
        fn_800416CC(obj,0);
        fn_800416D4(obj,0);
        fn_800416E4(obj,fn_8004D8DC,p);
    }
    streaming=fn_80041684(obj);
    rate=fn_80041660(obj);
    length=fn_800415F4(obj);
    value=fn_8004163C(obj);
    fn_8004EDA4(p->out,value);
    fn_8004EE04(p->out,streaming);
    fn_8004EE24(p->out,rate);
    fn_8004ED80(p->out,length);
    fn_8004EDE4(p->out,p->volume+(s16)fn_800414D0(p->decoder));
    fn_8004BBC4(p,&a,&b);
    if(a!=0 || b!=0) fn_8004BBC8(p,a,b);
    adxt_set_outpan(p);
    if(p->extra) fn_80046508(p->extra,streaming);
    if(fn_800416A8(obj)==2) {
        void *data=fn_80041458(obj);
        fn_8004ED5C(p->out,data);
    }
    fn_8004EEC4(p->out,1);
    p->state=2;
}
