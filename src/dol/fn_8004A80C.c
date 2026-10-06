#include "types.h"
#include "sofdec/sj.h"
typedef struct Sig_fn_8004A80C_CvFsObject Sig_fn_8004A80C_CvFsObject;
typedef struct Sig_fn_8004A80C_ADXStream Sig_fn_8004A80C_ADXStream;
struct Sig_fn_8004A80C_ADXStream {
    s8 used;
    s8 status;
    s8 read_active;
    s8 retry_count;
    SJ *sj;
    Sig_fn_8004A80C_CvFsObject *file;
    s32 file_offset;
    s32 file_size;
    s32 file_sectors;
    s32 minimum_buffer_size;
    s32 request_sectors;
    SJCK request_chunk;
    s32 maximum_request_sectors;
    s32 eos_sector;
    s32 transferred_bytes;
    void (*eos_callback)(void *);
    void *eos_object;
    s32 sj_buffer_size;
    s8 stop_requested;
    s8 bind_requested;
    s8 release_requested;
    s8 start_requested;
    s8 stop_pending;
    s8 file_open;
    s8 realtime;
    u8 reserved_47[5];
    const char *filename;
    void *directory;
    s32 position;
    s32 transfer_limit;
};
struct Sig_fn_800546A0_fn_800546A0_Object { u32 vtable; u32 value; };
struct Sig_fn_800589BC_fn_800589BC_Arg2 { u32 unk_0; u32 unk_4; };
struct Sig_fn_800589BC_fn_800589BC_Arg3 { u32 unk_0; u32 unk_4; };
typedef struct Sig_fn_80054930_CvFsObject Sig_fn_80054930_CvFsObject;
typedef struct Sig_fn_80054870_CvFsObject Sig_fn_80054870_CvFsObject;
extern int fn_80054870(Sig_fn_80054870_CvFsObject *, int, int);
extern int fn_80054930(Sig_fn_80054930_CvFsObject *, int, int);
extern s32 fn_800546A0(struct Sig_fn_800546A0_fn_800546A0_Object *);
extern u32 fn_800589BC(u32, u32, struct Sig_fn_800589BC_fn_800589BC_Arg2 *, struct Sig_fn_800589BC_fn_800589BC_Arg3 *);
extern s32 fn_80059AB4(void);
extern s32 fn_80059B44(void);
extern u32 lbl_8017D700[];
extern u32 lbl_8017D704[];
#define FIELD(s, off) (*(s32 *)((u8 *)(s) + (off)))
#define CHUNK(s) (&(s)->request_chunk)
void fn_8004A80C(Sig_fn_8004A80C_ADXStream *arg0) {
    SJ *v0;
    s32 state;
    s32 bytes;
    s32 sectors;
    s32 available;
    struct Sig_fn_800589BC_fn_800589BC_Arg2 loc_18;
    struct Sig_fn_800589BC_fn_800589BC_Arg3 loc_10;
    SJCK loc_8;
    v0 = arg0->sj;
    state = fn_800546A0((struct Sig_fn_800546A0_fn_800546A0_Object *)arg0->file);
    fn_80059B44();
    if (arg0->read_active == 1) {
        if (state == 1) {
            arg0->read_active = 0;
            fn_80059AB4();
            bytes = arg0->request_sectors << 11;
            fn_800589BC((u32)CHUNK(arg0), bytes, &loc_18, &loc_10);
            v0->interface->put_chunk(v0, 1, (SJCK *)&loc_18);
            v0->interface->unget_chunk(v0, 0, (SJCK *)&loc_10);
            arg0->position += arg0->request_sectors;
            arg0->transferred_bytes += bytes;
            ((s32 *)&arg0->request_chunk)[0] = 0;
            ((s32 *)&arg0->request_chunk)[1] = 0;
            sectors = arg0->file_size / 2048 + (arg0->file_size % 2048 > 0);
            if (arg0->position == arg0->eos_sector) {
                if (*(void (**)(void *))((u8 *)arg0 + 0x34) != 0) {
                    (*(void (**)(void *))((u8 *)arg0 + 0x34))(*(void **)((u8 *)arg0 + 0x38));
                }
            }
            if (arg0->position >= sectors) {
                arg0->status = 3;
            } else if (((u32)arg0->transferred_bytes >> 11) >= (u32)arg0->transfer_limit &&
                       (u32)arg0->transfer_limit < 0xfffff) {
                arg0->status = 3;
            }
            arg0->retry_count = 0;
        } else if (state == 3) {
            arg0->read_active = 0;
            fn_80059AB4();
            v0->interface->unget_chunk(v0, 0, CHUNK(arg0));
            ((s32 *)&arg0->request_chunk)[0] = 0;
            ((s32 *)&arg0->request_chunk)[1] = 0;
            if ((s32)lbl_8017D700[0] >= 0) {
                if (arg0->retry_count >= (s32)lbl_8017D700[0]) arg0->status = 4;
                else arg0->retry_count++;
            }
        } else {
            fn_80059AB4();
        }
    } else {
        arg0->read_active = 1;
        ((s32 *)&arg0->request_chunk)[0] = 0;
        ((s32 *)&arg0->request_chunk)[1] = 0;
        fn_80059AB4();
        if (arg0->stop_requested == 1 || arg0->stop_pending == 1) {
            arg0->read_active = 0;
        } else if (arg0->file_size == 0) {
            arg0->read_active = 0;
            arg0->request_sectors = 0;
            arg0->status = 3;
        } else if (v0 == 0 || v0->interface == 0) {
            arg0->read_active = 0;
            lbl_8017D704[0]++;
        } else if (arg0->sj_buffer_size - v0->interface->get_num_data(v0, 0) >= arg0->minimum_buffer_size) {
            arg0->read_active = 0;
        } else {
            v0->interface->get_chunk(v0, 0, arg0->file_sectors, &loc_8);
            bytes = arg0->position;
            available = ((s32 *) &loc_8)[1] / 2048;
            sectors = available < arg0->eos_sector - bytes ? available : arg0->eos_sector - bytes;
            available = arg0->file_size / 2048 - arg0->position;
            if (sectors < available) available = sectors;
            sectors = arg0->maximum_request_sectors;
            if (available < sectors) sectors = available;
            fn_80054930((Sig_fn_80054930_CvFsObject *)arg0->file, arg0->file_offset + arg0->position, 0);
            arg0->request_sectors = fn_80054870((Sig_fn_80054870_CvFsObject *)arg0->file, sectors, ((s32 *)&loc_8)[0]);
            ((s32 *)&arg0->request_chunk)[0] = ((s32 *)&loc_8)[0];
            ((s32 *)&arg0->request_chunk)[1] = ((s32 *)&loc_8)[1];
            if (arg0->request_sectors <= 0) {
                v0->interface->unget_chunk(v0, 0, CHUNK(arg0));
                ((s32 *)&arg0->request_chunk)[0] = 0;
                ((s32 *)&arg0->request_chunk)[1] = 0;
                arg0->read_active = 0;
                if (fn_800546A0((struct Sig_fn_800546A0_fn_800546A0_Object *)arg0->file) == 3) {
                    if ((s32)lbl_8017D700[0] >= 0) {
                        if (arg0->retry_count >= (s32)lbl_8017D700[0]) arg0->status = 4;
                        else arg0->retry_count++;
                    }
                }
            }
        }
    }
}
