#include "types.h"
typedef struct Sig_fn_12_2CFEC_MovieModuleState {
    u32 field_0; u32 field_4; u32 field_8; u32 field_c; u32 field_10;
} Sig_fn_12_2CFEC_MovieModuleState;
typedef void (*Sig_fn_12_24A88_MovieCallback)(void *, s32);
typedef struct Sig_fn_12_24A88_MovieObject {
    u8 pad_0000[0x48]; s32 state; u8 pad_004c[0x940];
    Sig_fn_12_24A88_MovieCallback callback;
    void *callback_context; s32 callback_data;
} Sig_fn_12_24A88_MovieObject;
struct fn_12_22954_Arg2 {
    u8 pad_0[4]; u32 unk_4; u32 unk_8; u32 unk_C; u32 unk_10;
    u8 pad_14[0x14]; u32 unk_28;
};
extern int fn_12_24A88(void *, int);
extern u32 fn_80058498(u32, s32, u32);
extern void fn_12_24950(void *);
extern void fn_12_24970(void *);
extern void fn_12_2CFEC(Sig_fn_12_2CFEC_MovieModuleState *);

struct fn_12_22954_Copy24 { u32 a, b, c, d, e, f; };

static inline u32 fn_12_22954_alloc(u32 *desc, u32 start, s32 size, u32 reserve) {
    desc[0] = 0;
    desc[2] = start;
    desc[3] = size;
    if (size <= 0) return 0;
    desc[4] = reserve;
    desc[5] = 0;
    desc[1] = fn_80058498(start, size, reserve);
    return desc[1];
}
#define W(off) (*(u32 *)(dst.value + (off)))
#define A(off) (*(u32 *)((u8 *)arg2 + (off)))

static inline void fn_12_22954_offsets(u32 *offsets, struct fn_12_22954_Arg2 *arg2, u32 size) {
    u32 start = arg2->unk_4;
    offsets[0] = start;
    start += size; offsets[1] = start;
    start += arg2->unk_C; offsets[2] = start;
    start += arg2->unk_10; offsets[3] = start;
    start += A(20); offsets[4] = start;
    start += A(24); offsets[5] = start;
    start += A(28); offsets[6] = start;
    start += A(32); offsets[7] = start;
}

#pragma opt_propagation off
#pragma opt_strength_reduction off
#pragma opt_common_subs off
s32 fn_12_22954(s32 arg0, register u8 *arg1, struct fn_12_22954_Arg2 *arg2) {
    register u8 * arg1_local = arg1;
    u32 v27;
    s32 tmp_call20;
    void * lab_t0;
    u32 v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10;
    u32 v11; s32 v12; s32 v13;
    u32 v14, v15; s32 v16; s32 v17; u32 v18;
    u32 v19; s32 v21; u32 v20; s32 v22; s32 v23;
    u32 v24, v25, v26, v28;
    struct { u32 value[8]; } offset_storage;
#define offsets ((u32 *)&offset_storage)
    struct fn_12_22954_Copy24 desc1, desc2, desc3;
    u32 loc_10;
    u32 loc_C, loc_8;
    u32 t0, t4, t8;
    struct { u8 *value; } dst;
    s32 i;
    dst.value = (u8 *)arg1_local;

    v0 = A(8);
    v2 = A(4);
    offsets[0] = v2;
    v2 += v0; offsets[1] = v2;
    v2 += A(12); offsets[2] = v2;
    v2 += A(16); offsets[3] = v2;
    v2 += A(20); offsets[4] = v2;
    v2 += A(24); offsets[5] = v2;
    v2 += A(28); offsets[6] = v2;
    v2 += A(32); offsets[7] = v2;
    v9 = (s32)v0 % (s32)A(40);
    if ((s32)v0 == 0) {
        v11 = 0; v12 = 4;
    } else {
        v13 = v0 - v9;
        v11 = 1;
        v12 = 5;
        t0 = fn_12_22954_alloc((u32 *)&desc1, offsets[0], v13, v9);
        if (t0 == 0) {
            v12 = -1;
            goto next1; /* Keep the verified branch to next1. */
        }
        lab_t0 = &loc_10;
        fn_12_24970(lab_t0);
        W(4) = 1;
        *(struct fn_12_22954_Copy24 *)(dst.value + 16) =
            *&desc1;
        W(40) = 0; W(44) = 0; W(48) = 0; W(52) = 0;
        fn_12_2CFEC((Sig_fn_12_2CFEC_MovieModuleState *)(arg1_local + 56));
        fn_12_24950(&loc_10);
    }
    W(0) = v12; v12 = 0;
    W(4) = v11; W(8) = 0; W(12) = 0; W(76) = 9; W(80) = 9;
next1:
    v14 = A(12);
    if ((s32)v14 == 0) {
        v15 = 0; v16 = 4;
    } else {
        v17 = v14 - 2048;
        v15 = 1;
        v16 = 5;
        v18 = fn_12_22954_alloc((u32 *)&desc2, offsets[1], v17, 2048);
        if (v18 == 0) {
            v16 = -1;
            goto next2; /* Keep the verified branch to next2. */
        }
        lab_t0 = &loc_C;
        fn_12_24970(lab_t0);
        W(120) = 1;
        *(struct fn_12_22954_Copy24 *)(dst.value + 132) =
            *&desc2;
        W(156) = 0; W(160) = 0; W(164) = 0; W(168) = 0;
        fn_12_2CFEC((Sig_fn_12_2CFEC_MovieModuleState *)(arg1_local + 172));
        fn_12_24950(&loc_C);
    }
    W(116) = v16; v16 = 0;
    W(120) = v15; W(124) = 0; W(128) = 0; W(192) = 9; W(196) = 9;
next2:
    v19 = A(16);
    if ((s32)v19 == 0) {
        v20 = 0; v21 = 4;
    } else {
        v20 = 1;
        v21 = 5;
        t8 = fn_12_22954_alloc((u32 *)&desc3, offsets[2], (s32)v19, 0);
        if (t8 == 0) {
            v22 = -1;
            goto next3; /* Keep the verified branch to next3. */
        }
        lab_t0 = &loc_8;
        fn_12_24970(lab_t0);
        W(236) = 1;
        *(struct fn_12_22954_Copy24 *)(dst.value + 248) =
            *&desc3;
        W(272) = 0; W(276) = 0; W(280) = 0; W(284) = 0;
        fn_12_2CFEC((Sig_fn_12_2CFEC_MovieModuleState *)(arg1_local + 288));
        fn_12_24950(&loc_8);
    }
    W(232) = v21; v22 = 0;
    W(236) = v20; W(240) = v22; W(244) = v22; W(308) = 9; W(312) = 9;
next3:
    if (v12 != 0 || v16 != 0 || v22 != 0) {
        v23 = fn_12_24A88((void *)arg0, 0xff00040a);
    } else {
        v24 = A(20);
        v25 = -v24 | v24;
        W(348) = 1;
        W(352) = v25 >> 31;
        W(356) = 0; W(360) = 0; W(424) = 9; W(428) = 9;
        W(364) = offsets[3]; W(368) = A(20);
        W(372) = 0; W(376) = 0; W(380) = arg0 + 5344;
        for (v13 = 0; v13 < 16; v13++) {
            *(u32 *)((u8 *)W(380) + v13 * 92) = 0;
        }
        v26 = A(24);
        v25 = -v26 | v26;
        W(464) = 2; W(468) = v25 >> 31;
        W(472) = 0; W(476) = 0; W(540) = 9; W(544) = 9;
        W(480) = offsets[4]; W(484) = A(24);
        W(488) = 0; W(492) = 0; W(496) = 0; W(500) = 0;
        W(504) = 0; W(508) = 0; W(512) = 0; W(516) = 0; W(520) = 0; W(524) = 0;
        v25 = -A(28) | A(28);
        W(580) = 1; W(584) = v25 >> 31;
        W(588) = 0; W(592) = 0; W(656) = 9; W(660) = 9;
        W(596) = offsets[5]; W(600) = A(28);
        W(604) = 0; W(608) = 0; W(612) = arg0 + 5344;
        for (v17 = 0; v17 < 16; v17++) {
            *(u32 *)((u8 *)W(612) + v17 * 92) = 0;
        }
        tmp_call20 = A(32);
        v28 = tmp_call20;
        v25 = -v28 | v28;
        W(696) = 2; W(700) = v25 >> 31;
        W(704) = 0; W(708) = 0; W(772) = 9; W(776) = 9;
        W(712) = offsets[6]; W(716) = A(32);
        W(720) = 0; W(724) = 0; W(728) = 0; W(732) = 0;
        W(736) = 0; W(740) = 0; W(744) = 0; W(748) = 0; W(752) = 0; W(756) = 0;
        W(812) = 3; W(816) = 1; W(820) = 0; W(824) = 0;
        W(888) = 9; W(892) = 9;
        W(828) = 0; W(832) = 0; W(836) = 0; W(840) = 0;
        W(844) = 0; W(848) = 0; W(852) = 0; W(856) = 0; W(860) = 0;
        W(864) = 0; W(868) = 0; W(872) = 0;
        v23 = 0;
    }
    return v23;
}
#pragma opt_strength_reduction reset

#pragma opt_propagation reset

