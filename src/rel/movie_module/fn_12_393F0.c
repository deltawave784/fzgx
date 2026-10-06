#include "types.h"
#include "sofdec/mwsfd.h"
#include "sofdec/mwsst.h"

typedef struct MovieEntry MovieEntry;
typedef struct MovieEntryVTable {
    u8 pad[0xc];
    void (*destroy)(MovieEntry *);
} MovieEntryVTable;
struct MovieEntry { MovieEntryVTable *vtable; };
typedef struct MovieModule {
    u32 unk0, unk4;
    int status;
    int playback_mode;
    u8 pad10[0x30];
    SfdHandle *sfd;
    void *stream;
    u8 pad48[0x29];
    s8 concat_stopped;
    s8 paused;
    u8 pad73[9];
    int field7c, field80, field84;
    u8 pad88[0xa0];
    MovieEntry *movie;
    u8 pad12c[0x20];
    MovieEntry *movie_data;
    void *movie_data_1;
    void *movie_data_2;
    u8 pad158[0x94];
    MwsStHandle sound;
} MovieModule;

extern u8 lbl_12_rodata_2480[];
extern int fn_12_3A36C(MovieModule *);
extern void fn_12_3A888(MovieModule *);
extern int fn_12_2B358(SfdHandle *);
extern int fn_12_38A0C(int);
extern void MWSFSVM_Error(const char *, ...);
extern void fn_12_3B540(MwsStHandle *);
extern void fn_12_34EB0(void *);
extern MovieEntry *fn_80057B9C(void *, void *);
extern u32 *fn_12_38DBC(void);
extern int MWSFCRE_ResetSfdHn(MovieModule *);
extern void fn_12_3B2EC(MovieModule *);
extern void fn_12_33A14(MovieModule *);
extern void fn_12_353C4(MovieModule *);
extern int fn_12_35418(MovieModule *);
extern void fn_12_353FC(MovieModule *);
extern int fn_12_2AD88(SfdHandle *);
extern int fn_12_38AD0(void);
extern int fn_12_2D74C(SfdHandle *, int, int *);
extern int fn_12_2AF5C(SfdHandle *, int);
extern void fn_12_3858C(MovieModule *);

void fn_12_393F0(MovieModule *module, void *arg1, void *arg2) {
    u8 *messages = lbl_12_rodata_2480;
    SfdHandle *movie;
    int paused;
    int pause_status;
    if (fn_12_3A36C(module) == 0) {
        MWSFSVM_Error((char *)messages + 0x1c4);
        return;
    }
    movie = module->sfd;
    if (movie != 0) {
        fn_12_3A888(module);
        module->status = 0;
        if (fn_12_2B358(movie) != 0) {
            fn_12_38A0C(-0x134);
            MWSFSVM_Error((char *)messages + 0x100);
        }
        fn_12_3B540(&module->sound);
        if (module->stream != 0) fn_12_34EB0(module->stream);
    }
    module->movie_data->vtable->destroy(module->movie_data);
    module->movie_data = fn_80057B9C(arg1, arg2);
    module->movie = module->movie_data;
    module->movie_data_1 = arg1;
    module->movie_data_2 = arg2;
    fn_12_38DBC();
    if (module->sfd != 0) {
        if (MWSFCRE_ResetSfdHn(module) != 0) {
            MWSFSVM_Error((char *)messages + 0x14c);
            goto done; /* Reset failure shares the final cleanup path. */
        }
        fn_12_3B2EC(module);
        fn_12_33A14(module);
        fn_12_353C4(module);
        if (fn_12_35418(module) != 0) {
            MWSFSVM_Error((char *)messages + 0x178);
            goto done; /* Preparation failure shares the final cleanup path. */
        }
        fn_12_353FC(module);
    }
    module->field7c = 0;
    module->field80 = 0;
    if (fn_12_2AD88(module->sfd) != 0) {
        fn_12_38A0C(-0x137);
        MWSFSVM_Error((char *)messages + 0x1a4);
    }
    paused = module->paused;
    if (fn_12_3A36C(module) == 0) {
        MWSFSVM_Error((char *)messages + 0x84);
        goto start; /* Skip pause handling but retain shared sound startup. */
    }
    movie = module->sfd;
    if (module->paused == 0 && paused == 0) goto start; /* No pause change: join sound startup. */
    if (fn_12_38AD0() == 1 && module->playback_mode == 1) {
        if (fn_12_2D74C(movie, 6, &pause_status) == 0) {
            if (pause_status == 1) fn_12_3A888(module);
        } else {
            fn_12_3A888(module);
        }
    }
    if (fn_12_2AF5C(movie, paused) != 0) {
        const char *format;
        const char *state;
        fn_12_38A0C(-0x136);
        format = (char *)messages + 0xac;
        state = (char *)messages + 0xd4;
        if (paused == 1) state = (char *)messages + 0xd0;
        MWSFSVM_Error(format, state);
    }
    MWSST_Pause(&module->sound, paused);
    module->paused = paused;
start:
    MWSST_Pause(&module->sound, 1);
    MWSST_StartSj(&module->sound);
    module->field84 = 0;
    module->concat_stopped = 0;
    module->status = 1;
done:
    fn_12_3858C(module);
}
