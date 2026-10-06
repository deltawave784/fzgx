#include "types.h"
#pragma use_lmw_stmw on
typedef struct MovieModule {
 u8 pad_0[0x48];
 int unk_48;
 int unk_4C;
 u8 pad_50[0x964];
 int field_9b4;
 int field_9b8;
 u8 pad_9bc[0x1c];
 int field_9d8;
 int field_9dc;
 u8 pad_9e0[0x74];
 int field_a54;
 u8 pad_a58[0x4d4];
 int field_f2c;
 u8 pad_f30[0x18];
 int field_f48;
} MovieModule;
extern int fn_12_2D73C(MovieModule *, int);
extern int fn_12_2F1F0(MovieModule *, int);
extern int fn_12_2F1D0(MovieModule *, int);
extern int fn_12_21E94(MovieModule *, int);
extern int fn_12_21F28(MovieModule *, int);
extern void fn_12_2D420(MovieModule *, int, int);
extern void fn_12_2D7DC(MovieModule *, int, int);
extern int fn_12_2F210(MovieModule *, int, int, int, int);

static inline int completed(MovieModule *arg0) {
 int v6;
 int v7;
 int v2;
 if (arg0->field_9d8 == 0) return 1;
 if (arg0->field_9b4 == 0) return 1;
 if (arg0->field_f2c != 0) return 1;
 if (arg0->field_f48 >= arg0->field_a54) return 1;
 if (arg0->field_9b8 == 0 && arg0->field_9b4 == 0) v2 = 1;
 else {
 v2 = 0;
 v6 = fn_12_2F1D0(arg0,6);
 v7 = fn_12_2F1D0(arg0,7);
 switch (fn_12_2D73C(arg0,25)) {
 case 1: v2 = v7; break;
 case 2: v2 = v6; break;
 case 3: v2 = v7 | v6; break;
 case 0: v2 = v7 & v6; break;
 }
 }
 if (v2 != 0) return 1;
 return 0;
}
static inline int active(MovieModule *arg0) {
 int v2;
 int v3;
 int t1;
 if (fn_12_2D73C(arg0, 5) == 0) v2 = 1;
 else {
 t1 = fn_12_2F1F0(arg0, 6);
 v2 = t1 | fn_12_2F1D0(arg0, 6);
 }
 if (fn_12_2D73C(arg0, 6) == 0) v3 = 1;
 else {
 t1 = fn_12_2F1F0(arg0, 7);
 v3 = t1 | fn_12_2F1D0(arg0, 7);
 }
 if (v2 == 0 || v3 == 0) return 0;
 return 1;
}
int fn_12_2C640(MovieModule *input) {
 int v1;
 int v0;
 MovieModule *arg0 = input;
 int t1;
 int v2;
 int v3;
 int v4;
 int ready;
 v0 = arg0->unk_48;
 v1 = arg0->unk_4C;
 if (!active(arg0)) return v0;
 if (arg0->field_9b4 == 1 && fn_12_21E94(arg0,1) == 0 && fn_12_21F28(arg0,1) == 0)
 arg0->field_9b4 = 0;
 if (arg0->field_9b8 == 1 && fn_12_21E94(arg0,2) == 0 && fn_12_21F28(arg0,2) == 0)
 arg0->field_9b8 = 0;
 fn_12_2D420(arg0,arg0->field_9b4,arg0->field_9b8);
 if (arg0->field_9b8 == 0 && arg0->field_9dc == 2) fn_12_2D7DC(arg0,15,1);
 if (arg0->field_9b4 == 0 && arg0->field_9dc == 1) fn_12_2D7DC(arg0,15,2);
 v3 = 0;
 if (arg0->field_9b8 == 1) v3 |= 1;
 if (arg0->field_9b4 == 1) v3 |= 2;
 switch (v3) {
 case 1: v4 = 1; break;
 case 2: v4 = 2; break;
 case 3: v4 = fn_12_2D73C(arg0,25); break;
 default: v4 = 3; break;
 }
 fn_12_2D7DC(arg0,25,v4);
 switch (v1) {
 case 2: v0 = 2; break;
 case 3: v0 = 3; break;
 case 4:
 case 6:
 if (completed(arg0)) {
 fn_12_2F210(arg0,7,6,0,0);
 v0 = 4;
 } else v0 = 3;
 break;
 }
 return v0;
}
