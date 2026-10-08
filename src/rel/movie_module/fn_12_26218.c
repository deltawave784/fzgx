#include "types.h"
typedef struct Sig_fn_12_654C_MovieValues {
    s32 value_00, value_04, value_08, value_0c, value_10, value_14, value_18, value_1c;
} Sig_fn_12_654C_MovieValues;
typedef struct Sig_fn_12_654C_MovieModule {
    u8 pad00[0x10];
    int field10;
    u8 field14[0x0c];
    Sig_fn_12_654C_MovieValues values;
    Sig_fn_12_654C_MovieValues slots[3];
    u8 fielda0[0x20];
} Sig_fn_12_654C_MovieModule;
typedef void (*Sig_fn_12_24A88_MovieCallback)(void *, s32);
typedef struct Sig_fn_12_24A88_MovieObject {
    u8 pad_0000[0x48];
    s32 state;
    u8 pad_004c[0x940];
    Sig_fn_12_24A88_MovieCallback callback;
    void *callback_context;
    s32 callback_data;
} Sig_fn_12_24A88_MovieObject;
typedef struct Sig_fn_12_68D4_MovieValues {
    u32 value_00, value_04, value_08, value_0c, value_10, value_14, value_18, value_1c;
} Sig_fn_12_68D4_MovieValues;
typedef struct Sig_fn_12_68D4_MovieModule {
    u8 _pad00[0x20];
    Sig_fn_12_68D4_MovieValues values;
} Sig_fn_12_68D4_MovieModule;
struct fn_12_26218_Arg0 {
    u8 pad_0[0x1AEC];
    u32 unk_1AEC;
};
struct fn_12_26218_Arg3 { u32 unk_0; };
extern int fn_12_654C(Sig_fn_12_654C_MovieModule *, const u8 *, int, int *, int *);
extern int fn_12_68D4(Sig_fn_12_68D4_MovieModule *, Sig_fn_12_68D4_MovieValues *);
extern s32 fn_12_231F8(u32);
extern s32 fn_12_24A88(Sig_fn_12_24A88_MovieObject *, s32);
extern s32 fn_12_23250(u32);
extern s32 fn_12_2559C(struct fn_12_26218_Arg0 *, u32, u32, u32);
extern u32 fn_12_25FA8(u32, u32, u32, void *, void *);
extern u32 fn_12_67A4(const u8 *);
extern void *fn_12_57F0(void *, const void *, u32);

static inline int all_zero(u32 p, s32 n) {
    s32 i;
    for (i=0;i<n;i++) {
        if (*(s8 *)p++ != 0) return 0;
    }
    return 1;
}
#pragma opt_propagation on
static inline s32 scan(struct fn_12_26218_Arg0 *arg0, u32 arg1, s32 arg2) {
    register s32 v2;
    s32 v13;
    u32 v18;
    int valid;
    v2=*(s32 *)((u8 *)arg0+0x28);
    if (arg2>=v2+3 && all_zero(arg1,v2)) return v2;
    v13=0;
    while (arg2>=4) {
        if (fn_12_67A4((const u8 *)arg1)&0xd0000) return v13;
        v13++;
        arg1++;
        arg2--;
    }
    if (arg2>0 && arg2<4) {
        v18=(u32)arg0+*(s32 *)((u8 *)arg0+0x1af4)*0x74;
        if (*(s32 *)(v18+0x1150)==0 && (*(s32 *)(v18+0x1160)!=0 || *(s32 *)(v18+0x1164)!=0)) valid=0;
        else if (arg1+arg2==*(u32 *)(v18+0x1158)+*(u32 *)(v18+0x115c)) valid=1;
        else valid=0;
        if (valid) v13+=arg2;
    }
    return v13;
}

#pragma opt_propagation off
u32 fn_12_26218(struct fn_12_26218_Arg0 *arg0, u32 arg1, s32 size, struct fn_12_26218_Arg3 *arg3, u32 arg4) {
    u32 v1;
    s32 arg2 = size;
    s32 v3 = 0;
    u32 v4;
    u32 v7;
    s32 v6;
    s32 v13;
    u32 v18;
    s32 v2;
    u32 v11;
    s32 i;
    int valid;
    Sig_fn_12_68D4_MovieValues loc_18;
    s32 loc_14;
    u32 loc_10;
    u32 loc_C;
    s32 loc_8;
    arg3->unk_0 = 0;
    v1 = *(u32 *)arg0->unk_1AEC;
    if (fn_12_2559C(arg0,arg1,arg2,arg4) == 0) return 0;
    if (fn_12_654C((Sig_fn_12_654C_MovieModule *)v1,(const u8 *)arg1,arg2,(int *)&loc_10,(int *)&loc_14) != 0)
        v3 = fn_12_24A88((Sig_fn_12_24A88_MovieObject *)arg0,0xff000d03);
    if (loc_14 & 0x20000) {
        v4 = *(u32 *)((u8 *)arg0 + 0x2908);
        if (v4 == 0) v4 = 0;
        else if (*(s32 *)((u8 *)arg0->unk_1AEC+0x14)>0) v4=0;
        else v4 += 0x8a0;
        if (v4 != 0 && *(s32 *)v4 == 0) {
            v7=v4+0x24;
            fn_12_68D4((Sig_fn_12_68D4_MovieModule *)v1,&loc_18);
            v6=0xb0;
            if (arg2<0xb0) v6=arg2;
            if ((s32)loc_18.value_0c>0) *(s32 *)(v7+0x160)=v6;
            else if ((s32)loc_18.value_08>0) {
                *(s32 *)(v7+0x164)=v6;
                v7+=0xb0;
            } else {
                /* No available data: join the status dispatch without copying. */
                goto copied;
            }
            fn_12_57F0((void *)v7,(const void *)arg1,v6);
        }
    }
copied:
    if (loc_14==0x80000 && fn_12_23250((u32)arg0)!=0) {
        ++*(s32 *)(arg0->unk_1AEC+0x14);
        arg3->unk_0=4;
    } else if (loc_14==0x80000 && fn_12_231F8((u32)arg0)!=0) {
        arg3->unk_0=4;
    } else if (loc_14==0) {
        v2=*(s32 *)((u8 *)arg0+0x28);
        if (arg2>=v2+3) {
            u32 p = arg1;
            for (i=0;i<v2;i++) {
                /* A nonzero byte ends the zero-prefix test at its common join. */
                if (*(s8 *)p++ != 0) { valid=0; goto zero_done; }
            }
            valid=1;
zero_done:
            /* The zero prefix supplies the result directly at the shared store. */
            if (valid) { v18=v2; goto scanned; }
        }
        v13=0;
        while (arg2>=4) {
            /* A recognized header ends scanning and joins the shared result store. */
            if (fn_12_67A4((const u8 *)arg1)&0xd0000) { v18=v13; goto scanned; }
            v13++;
            arg1++;
            arg2--;
        }
        if (arg2>0 && arg2<4) {
            v11=(u32)arg0+*(s32 *)((u8 *)arg0+0x1af4)*0x74;
            if (*(s32 *)(v11+0x1150)==0 && (*(s32 *)(v11+0x1160)!=0 || *(s32 *)(v11+0x1164)!=0)) valid=0;
            else if (arg1+arg2==*(u32 *)(v11+0x1158)+*(u32 *)(v11+0x115c)) valid=1;
            else valid=0;
            if (valid) v13+=arg2;
        }
        v18=v13;
scanned:
        arg3->unk_0=v18;
    } else if (!(loc_14&0x40000)) {
        v3=fn_12_24A88((Sig_fn_12_24A88_MovieObject *)arg0,0xff000d05);
    } else {
        arg1+=loc_10;
        arg2-=loc_10;
        v3=fn_12_25FA8((u32)arg0,arg1,arg2,&loc_C,&loc_8);
        if (loc_8==1) arg3->unk_0=loc_10+loc_C;
    }
    return v3;
}
