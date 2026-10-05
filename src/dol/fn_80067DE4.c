#include "types.h"
#include "dol/globals.h"

typedef struct Fn80067DE4State {
    u8 _pad_000[0x100];
    u32 unk_100;
    u8 _pad_104[0x138];
    u32 unk_23c;
    u8 _pad_240[0x204];
    u32 unk_444;
    u8 _pad_448[0xc];
    u32 unk_454;
    u8 _pad_458[0x18];
    u8 mode0;
    u8 mode1;
} Fn80067DE4State;

typedef struct Fn80067DE4ObjA { u8 data[0x60]; } Fn80067DE4ObjA;
typedef struct Fn80067DE4ObjB { u8 data[0x9c]; } Fn80067DE4ObjB;
typedef struct Fn80067DE4ObjC { u8 data[0x1e0]; } Fn80067DE4ObjC;
typedef struct Fn80067DE4ObjD { u8 data[0x154]; } Fn80067DE4ObjD;

Fn80067DE4ObjA lbl_801932A8;
Fn80067DE4ObjA lbl_80193308;
Fn80067DE4ObjB lbl_80193368;
Fn80067DE4ObjB lbl_80193404;
Fn80067DE4ObjC lbl_801934A0;
Fn80067DE4ObjC lbl_80193680;
Fn80067DE4ObjD lbl_80193860;
Fn80067DE4ObjD lbl_801939B4;

extern u32 lbl_801A6410;
extern char lbl_80092C18[];

extern void fn_8005CBF4(u32);
extern void fn_800622B0(void);
extern void fn_80069CE4(u32, u32, u32);
extern void fn_80008E5C(u32, u32);
extern u32 fn_8001E9BC(u32 *);
extern int sprintf(char *, const char *, ...);
extern u32 fn_80024DF0(Fn80067DE4ObjD *);
extern u32 fn_80024378(Fn80067DE4ObjC *);
extern s32 fn_800253F0(Fn80067DE4ObjB *);
extern s32 fn_80025C70(Fn80067DE4ObjA *);
extern void fn_800211E0(u32, u32);
extern void fn_800211EC(u32, u32);

/* MWCC emits .bss objects in first-access order; this primer (in a section
 * the linker drops) touches them in retail layout order. */
#pragma section ".fzgxpool"
__declspec(section ".fzgxpool") void fn_80067DE4_bss_primer(void) {
    fn_80025C70(&lbl_801932A8);
    fn_80025C70(&lbl_80193308);
    fn_800253F0(&lbl_80193368);
    fn_800253F0(&lbl_80193404);
    fn_80024378(&lbl_801934A0);
    fn_80024378(&lbl_80193680);
    fn_80024DF0(&lbl_80193860);
    fn_80024DF0(&lbl_801939B4);
}

u32 fn_80067DE4(void) {
    char buf[0x400];
    u32 value;
    Fn80067DE4State *state;

    ((Fn80067DE4State *)lbl_801A6C80)->unk_444 = 0xa0000110;
    fn_8005CBF4(0xa0000100);
    fn_800622B0();
    fn_80069CE4(0x10, 0xa0000500, 0);

    state = (Fn80067DE4State *)lbl_801A6C80;
    if (state->unk_454 == 0) {
        fn_80008E5C(lbl_801A6410, state->unk_100);
        fn_8001E9BC(&value);
        state = (Fn80067DE4State *)lbl_801A6C80;
        if (state->unk_23c != value) {
            sprintf(buf, lbl_80092C18, value);
            return value;
        }
    }

    state = (Fn80067DE4State *)lbl_801A6C80;
    switch (state->mode0) {
    case 0:
        fn_80024DF0(&lbl_801939B4);
        break;
    case 1:
        fn_80024378(&lbl_80193680);
        break;
    case 2:
        fn_800253F0(&lbl_80193404);
        break;
    case 3:
        fn_80025C70(&lbl_80193308);
        break;
    }
    fn_800211E0(0, 0);

    state = (Fn80067DE4State *)lbl_801A6C80;
    switch (state->mode1) {
    case 0:
        fn_80024DF0(&lbl_80193860);
        break;
    case 1:
        fn_80024378(&lbl_801934A0);
        break;
    case 2:
        fn_800253F0(&lbl_80193368);
        break;
    case 3:
        fn_80025C70(&lbl_801932A8);
        break;
    }
    fn_800211EC(0, 0);
    return 0;
}
