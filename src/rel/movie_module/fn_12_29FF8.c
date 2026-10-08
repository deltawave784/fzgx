#include "types.h"
struct Sig_fn_12_21D30_fn_12_21D30_E116_u32 { u32 unk_0; u8 pad_4[0x70]; };
struct Sig_fn_12_21D30_fn_12_21D30_Arg0 { u8 pad_0[0x114C]; struct Sig_fn_12_21D30_fn_12_21D30_E116_u32 unk_114C[1]; };
typedef struct Sig_fn_12_23F00_MovieModule { u8 pad_00[0x78]; s32 unk_78; u8 pad_7c[0x58]; u8 unk_d4[1]; } Sig_fn_12_23F00_MovieModule;
typedef void (*Sig_fn_12_24A88_MovieCallback)(void *, s32);
typedef struct Sig_fn_12_24A88_MovieObject { u8 pad_0000[0x48]; s32 state; u8 pad_004c[0x940]; Sig_fn_12_24A88_MovieCallback callback; void *callback_context; s32 callback_data; } Sig_fn_12_24A88_MovieObject;
typedef s32 Sig_fn_12_CAE4_MovieCallback;
typedef struct Sig_fn_12_CAE4_MovieObject { u8 pad_0000[0x188]; s32 state; u8 pad_018c[4]; Sig_fn_12_CAE4_MovieCallback callbacks[1]; } Sig_fn_12_CAE4_MovieObject;
typedef struct MovieState { Sig_fn_12_CAE4_MovieObject *object; u8 pad_4[0xe0]; int limit; } MovieState;
typedef struct MovieModule {
 u8 pad_0[0x2c]; int total;
 u8 pad_30[0x48]; int active;
 u8 pad_7c[0x78]; int field_f4;
 u8 pad_f8[0x854]; int field_94c;
 u8 pad_950[0x10]; int field_960;
 u8 pad_964[0x98]; int limit;
 u8 pad_a00[0x3a4]; int field_da4;
 u8 pad_da8[0x1c]; u32 field_dc4;
 u8 pad_dc8[0xd68]; MovieState *state;
 int field_1b34; int previous; int current;
} MovieModule;
extern s32 fn_12_24990(u32);
extern s32 fn_12_24A88(Sig_fn_12_24A88_MovieObject *, s32);
extern s32 fn_12_21D30(struct Sig_fn_12_21D30_fn_12_21D30_Arg0 *, u32);
extern s32 fn_12_2D73C(u8 *, int);
extern void *fn_12_23F00(Sig_fn_12_23F00_MovieModule *);
extern s32 fn_12_CAE4(Sig_fn_12_CAE4_MovieObject *, s32, Sig_fn_12_CAE4_MovieCallback);
extern int fn_12_298AC(MovieModule *, int *, int *);
extern int fn_12_28CC4(MovieModule *, int, int, int *);
extern int fn_12_21D50(MovieModule *, int);
extern int fn_12_2AC8C(MovieModule *);
extern int fn_12_2ABF0(MovieModule *);
extern int fn_12_AB00(Sig_fn_12_CAE4_MovieObject *, u32 *);
extern int fn_12_21E94(MovieModule *, int);
extern int fn_12_2F1B4(MovieModule *, int);
extern int fn_12_21F38(MovieModule *, int);
extern void fn_12_21D60(MovieModule *, int, int);
extern void fn_12_21D40(MovieModule *, int, int);
extern void fn_12_2D7DC(u8 *, int, int);
static inline int ready(MovieModule *m) {
 MovieState *state = m->state;
 Sig_fn_12_CAE4_MovieObject *object = state->object;
 u32 status;
 int mode;
 int count;
 if (fn_12_21D30((struct Sig_fn_12_21D30_fn_12_21D30_Arg0 *)m,m->previous)==1) return 1;
 if (m->active != 0 && m->field_f4 == 0) return 1;
 fn_12_AB00(object,&status);
 if(status == 0x3ffff) return 1;
 if(fn_12_21E94(m,1)>=state->limit) return 1;
 mode = !fn_12_2F1B4(m,1);
 count = fn_12_21F38(m,mode);
 if(fn_12_21E94(m,mode)>=count) return 1;
 return 0;
}
static inline int complete(MovieModule *m) {
 int limit;
 int total;
 if(fn_12_2AC8C(m)) return 1;
 limit=m->limit;
 total=m->total;
 if(limit==-1) limit=total;
 if(total<limit) limit=total;
 if(fn_12_2ABF0(m)>=limit && ready(m)) return 1;
 return 0;
}
int fn_12_29FF8(MovieModule *arg0) {
 int b; int c; int a;
 MovieModule *m = arg0;
 struct { int value; } previousStorage;
 struct { int value; } ret;
#define result ret.value
 struct { int value; } currentStorage;
 int count;
 Sig_fn_12_CAE4_MovieObject *object;
 if(fn_12_2D73C((u8 *)m,5)==0) return 0;
 if(fn_12_21D30((struct Sig_fn_12_21D30_fn_12_21D30_Arg0 *)m,m->current)==1) return 0;
 if(fn_12_2D73C((u8 *)m,28)!=0 && (s32)fn_12_23F00((Sig_fn_12_23F00_MovieModule *)m)!=-1) {
  if(m==0) object=0;
  else if(fn_12_24990((u32)m)!=0) {
   fn_12_24A88(0,0xff000181);
   goto skip; /* Invalid object: skip the callback dispatch and resume processing. */
  } else object=m->state->object;
  if(fn_12_CAE4(object,5,0)!=0) fn_12_24A88((Sig_fn_12_24A88_MovieObject *)m,0xff000f12);
 }
skip:
 do {
 result=fn_12_298AC(m,&a,&b);
 if(result!=0) break;
 result=fn_12_28CC4(m,a,b,&c);
 if(result!=0) break;
 } while(c!=0);
 currentStorage.value=m->current;
 previousStorage.value=m->previous;
 if(fn_12_21D50(m,currentStorage.value)!=1 && fn_12_21D50(m,previousStorage.value)==1) {
 int done;
 if(fn_12_2AC8C(m)) done=1;
 else {
 struct { int value; } limitStorage;
 int total=m->total;
 limitStorage.value=m->limit;
 if(limitStorage.value==-1) limitStorage.value=total;
 if(total<limitStorage.value) limitStorage.value=total;
 if(fn_12_2ABF0(m)>=limitStorage.value) {
 struct { Sig_fn_12_CAE4_MovieObject *value; } objStorage;
#define obj objStorage.value
 MovieState *state=m->state;
 u32 status;
 int n;
 struct { int value; } modeStorage;
#define mode modeStorage.value
 int readyFlag;
 obj=state->object;
 if(fn_12_21D30((struct Sig_fn_12_21D30_fn_12_21D30_Arg0 *)m,m->previous)==1) readyFlag=1;
 else if(m->active!=0 && m->field_f4==0) readyFlag=1;
 else {
 fn_12_AB00(obj,&status);
 if(status==0x3ffff) readyFlag=1;
 else if(fn_12_21E94(m,1)>=state->limit) readyFlag=1;
 else {
 mode=!fn_12_2F1B4(m,1);
 n=fn_12_21F38(m,mode);
 if(fn_12_21E94(m,mode)>=n) readyFlag=1;
 else readyFlag=0;
 }
 }
 if(readyFlag) {
 done=1;
 goto done_test; /* Shared positive result of the completion tests. */
 }
 }
 done=0;
 }
done_test:
 if(done) {
 fn_12_21D60(m,currentStorage.value,1);
 if(m->field_dc4!=0x7fffffff) m->field_da4=1;
 }
 }
 count=fn_12_2ABF0(m);
 if(count==-1 || (fn_12_2AC8C(m)!=0 && count==1 && m->field_960!=0)) {
 fn_12_21D40(m,m->current,1);
 if(m->field_94c==0) fn_12_2D7DC((u8 *)m,5,0);
 }
 return result;
}
