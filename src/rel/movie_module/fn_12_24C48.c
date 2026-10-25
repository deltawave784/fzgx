#include "types.h"
extern u8 lbl_12_rodata_B00[88];
extern u32 lbl_12_rodata_C78[102];
extern void fn_80058680(void);
extern void fn_12_33428(u32 *, u32, u32);
extern void *fn_12_57F0(void *, const void *, u32);
extern void fn_12_2F1A0(void *, u32);
extern void fn_12_22FB8(void *);
extern int fn_12_2F7AC(void *, u32);
extern void fn_12_2CD8C(void);
extern void fn_12_24924(void);
typedef struct Params { u32 a, b; } Params;
typedef struct Body {
u32 data[100];
Params params;
u32 zero[6];
u32 sub[3];
u32 sub2;
u32 table[15];
u32 tail[10];
} Body;
typedef struct State { u32 size, unused; void *name; Body body; } State;
static inline int init(Body *p, Params *args) {
int result;
int rv;
fn_12_33428((u32 *)p, 0, 0x89);
fn_12_57F0(p, lbl_12_rodata_C78, 0x190);
{
u32 a;
u32 b;
b = args->b;
a = args->a;
p->params.a = a;
p->params.b = b;
p->zero[0]=0;
p->zero[1]=0;
p->zero[2]=0;
p->zero[3]=0;
p->zero[4]=0;
p->zero[5]=0;
fn_12_2F1A0(p->sub, b);
}
fn_12_22FB8(&p->sub2);
p->tail[0]=0;
p->tail[1]=0;
p->tail[2]=0;
p->tail[3]=0;
p->tail[4]=0;
p->tail[5]=0;
p->tail[6]=0;
p->tail[7]=0;
p->tail[8]=0;
p->tail[9]=0;
result=fn_12_2F7AC(p->table,args->a);
rv=0;
if(result!=0) rv=result;
return rv;
}
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 lbl_12_bss_7C58;
u32 lbl_12_bss_7C5C;
void *lbl_12_bss_7C5C_4;
Body lbl_12_bss_7C64;
u32 lbl_12_bss_7E88;
u32 lbl_12_bss_7E8C[1541];
u32 lbl_12_bss_96A0[28];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&lbl_12_bss_7C58;
    s = *(u8 *)&lbl_12_bss_7C5C;
    s = *(u8 *)&lbl_12_bss_7C5C_4;
    s = *(u8 *)&lbl_12_bss_7C64;
    s = *(u8 *)&lbl_12_bss_7E88;
    s = *(u8 *)&lbl_12_bss_7E8C;
    s = *(u8 *)&lbl_12_bss_96A0;
}
#pragma section code_type ".text"

int fn_12_24C48(Params *args) {

int result;
lbl_12_bss_7C58=0x29d8;
lbl_12_bss_7C5C_4=lbl_12_rodata_B00;
fn_80058680();
result=init(&lbl_12_bss_7C64,args);
if(result!=0) return result;
fn_12_2CD8C();
fn_12_24924();
return 0;
}
