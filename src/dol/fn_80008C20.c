#include "types.h"
typedef struct Vec { f32 x,y,z; } Vec;
extern f32 lbl_8006D668(Vec *);
extern void lbl_8006D7DC(void *);
extern const f32 lbl_801A6F30;
extern u32 lbl_801A6D00[2];
static inline void cross(Vec *a, Vec *b, void *dest) {
 f32 *out = dest;
 f32 bx;
 f32 bz;
 f32 x, y, z;
 x = a->y * (bz = b->z);
 y = a->z * (bx = b->x);
 z = a->x * b->y;
 x = x - a->z * b->y;
 z = z - a->y * bx;
 y = y - a->x * bz;
 out[0] = x; out[1] = y; out[2] = z;
}
void fn_80008C20(Vec *position, Vec *up, Vec *direction) {
 Vec right;
 Vec vertical;
 Vec back;
 f32 *out;
 back.x = -direction->x;
 back.y = -direction->y;
 back.z = -direction->z;
 if (lbl_801A6F30 == lbl_8006D668(&back)) { lbl_8006D7DC(position); return; }
 cross(up, &back, &right);
 if (lbl_801A6F30 == lbl_8006D668(&right)) { lbl_8006D7DC(position); return; }
 cross(&back, &right, &vertical);
 if (lbl_801A6F30 == lbl_8006D668(&vertical)) { lbl_8006D7DC(position); return; }
 out = (f32 *)lbl_801A6D00[0];
 out[0]=right.x; out[1]=vertical.x; out[2]=back.x; out[3]=position->x;
 out[4]=right.y; out[5]=vertical.y; out[6]=back.y; out[7]=position->y;
 out[8]=right.z; out[9]=vertical.z; out[10]=back.z; out[11]=position->z;
}
