#include "types.h"
#include "dolphin/trk.h"
typedef struct Sig_fn_80089EEC_TRKBuffer Sig_fn_80089EEC_TRKBuffer;
struct Sig_fn_80089EEC_TRKBuffer {
    u32 mutex;
    u32 isInUse;
    u32 length;
    u32 position;
    u8 data[0x880];
};
struct Sig_fn_80089174_fn_80089174_Arg0 {
    u8 pad_0[8]; u32 unk_8; u32 unk_C;
};
typedef enum {
    Sig_TRKTargetAccessDefault_DS_NoError = 0,
    Sig_TRKTargetAccessDefault_DS_InvalidRegister = 0x701,
    Sig_TRKTargetAccessDefault_DS_CWDSException = 0x702,
    Sig_TRKTargetAccessDefault_DS_UnsupportedError = 0x703,
    Sig_TRKTargetAccessDefault_DS_InvalidProcessID = 0x704,
    Sig_TRKTargetAccessDefault_DS_InvalidThreadID = 0x705,
    Sig_TRKTargetAccessDefault_DS_OSError = 0x706
} Sig_TRKTargetAccessDefault_DSError;
typedef struct Sig_TRKTargetAccessDefault_TRKBuffer {
    u32 mutex; BOOL isInUse; u32 length; u32 position; u8 data[0x880];
} Sig_TRKTargetAccessDefault_TRKBuffer;
struct Sig_fn_80088B00_fn_80088B00_Arg0 { u8 pad_0[8]; u32 unk_8; };
extern DSError TRKAppendBuffer_ui8(TRKBuffer *, const u8 *, int);
extern DSError fn_8008BFB4(u32, u32, TRKBuffer *, size_t *, BOOL);
extern Sig_TRKTargetAccessDefault_DSError TRKTargetAccessDefault(u32, u32, Sig_TRKTargetAccessDefault_TRKBuffer *, size_t *, BOOL);
extern s32 fn_80088B00(struct Sig_fn_80088B00_fn_80088B00_Arg0 *);
extern u32 fn_8008D398(u32, u32);
extern u32 fn_80089174(struct Sig_fn_80089174_fn_80089174_Arg0 *, u32);
extern u32 fn_8008BB7C(u32, u32, u32, void *, u32);
extern u32 fn_8008C124(u32, u32, u32, void *, u32);
struct fn_80089EEC_Strings {
    u8 pad_0[0x60];
    u8 s60[0x20];
    u8 s80[0x18];
    u8 s98[0x28];
    u8 sC0[0x38];
    u8 sF8[0x28];
    u8 s120[0x30];
    u8 s150[0x40];
};
extern u8 lbl_80095890[];
extern void *memset(void *, s32, u32);
extern u32 MWTRACE(u32, const void *, ...);

s32 fn_80089EEC(Sig_fn_80089EEC_TRKBuffer *arg0) {
    struct fn_80089EEC_Strings *p_lbl_80095890;
    s32 error;
    s32 result;
    struct { u8 a[64]; } loc_8C;
    struct { u8 a[64]; } loc_4C;
    struct { u8 a[64]; } loc_C;
    u32 loc_8;
    p_lbl_80095890 = (struct fn_80089EEC_Strings *)&lbl_80095890;
    if (*(u16 *)((u8 *)arg0 + 28) > *(u16 *)((u8 *)arg0 + 32)) {
        memset(&loc_4C, 0, 64);
        loc_4C.a[4] = 128;
        *(u32 *)&loc_4C = 64;
        loc_4C.a[8] = 20;
        fn_8008D398((u32)&loc_4C, 64);
        return 0;
    }
    loc_8C.a[4] = 128;
    *(u32 *)&loc_8C = 1128;
    fn_80089174((struct Sig_fn_80089174_fn_80089174_Arg0 *)arg0, 0);
    MWTRACE(4, &p_lbl_80095890->s98, arg0->length);
    TRKAppendBuffer_ui8((TRKBuffer *)arg0, (const u8 *)&loc_8C, 64);
    MWTRACE(4, &p_lbl_80095890->s98, arg0->length);
    error = TRKTargetAccessDefault(0, 36, (Sig_TRKTargetAccessDefault_TRKBuffer *)arg0, (size_t *)&loc_8, 1);
    MWTRACE(4, &p_lbl_80095890->sC0, error);
    MWTRACE(4, &p_lbl_80095890->s98, arg0->length);
    if (error == 0) error = fn_8008C124(0, 33, (u32)arg0, &loc_8, 1);
    MWTRACE(4, &p_lbl_80095890->sF8, error);
    MWTRACE(4, &p_lbl_80095890->s98, arg0->length);
    if (error == 0) error = fn_8008BFB4(0, 96, (TRKBuffer *)arg0, (size_t *)&loc_8, 1);
    MWTRACE(4, &p_lbl_80095890->s120, error);
    MWTRACE(4, &p_lbl_80095890->s98, arg0->length);
    if (error == 0) error = fn_8008BB7C(0, 31, (u32)arg0, &loc_8, 1);
    MWTRACE(4, &p_lbl_80095890->s150, error);
    MWTRACE(4, &p_lbl_80095890->s98, arg0->length);
    if (error != 0) {
        switch (error) {
        case 0x703: result = 18; break;
        case 0x701: result = 20; break;
        case 0x702: result = 21; break;
        case 0x704: result = 33; break;
        case 0x705: result = 34; break;
        case 0x706: result = 32; break;
        default: result = 3; break;
        }
        memset(&loc_C, 0, 64);
        loc_C.a[4] = 128;
        *(u32 *)&loc_C = 64;
        loc_C.a[8] = result;
        fn_8008D398((u32)&loc_C, 64);
        return 0;
    }
    MWTRACE(1, &p_lbl_80095890->s60);
    error = fn_80088B00((struct Sig_fn_80088B00_fn_80088B00_Arg0 *)arg0);
    MWTRACE(1, &p_lbl_80095890->s80, error);
    return error;
}
