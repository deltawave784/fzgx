#include "types.h"

typedef void (*fn_8005A24C_Fn0)(void *, const char *, void *);
typedef struct MfCiObject {
    signed char used;
    signed char status;
    unsigned char reserved_02[2];
    int sector_length;
    int file_size;
    int sector_count;
    int sector_position;
    int transfer_length;
    int request_sectors;
    char filename[20];
    int source_offset;
    int request_length;
} MfCiObject;
struct fn_8005A24C_lbl_80190178 {
    fn_8005A24C_Fn0 unk_0;
    void *unk_4;
    char error[300];
    MfCiObject handles[40];
};
extern char *fn_80083DB0(char *, const char *);
extern int sprintf(char *, const char *, ...);
extern unsigned long strlen(const char *);
extern struct fn_8005A24C_lbl_80190178 lbl_80190178;
extern char lbl_800924F8[];
extern unsigned long strtoul(const char *, char **, int);

static inline unsigned char *get_address(const char *filename, int *file_size,
    struct fn_8005A24C_lbl_80190178 *bss, char *strings) {
    char *end;
    unsigned long address;
    if (strlen(filename) != 17) {
        sprintf(bss->error, strings + 192, filename);
        if (bss->unk_0 != 0) bss->unk_0(bss->unk_4, bss->error, 0);
    }
    if (filename[8] != '.') {
        sprintf(bss->error, strings + 256, filename);
        if (bss->unk_0 != 0) bss->unk_0(bss->unk_4, bss->error, 0);
    }
    end = (char *)filename;
    address = strtoul(filename, &end, 16);
    if (*end != 0) end++;
    if (file_size != 0) *file_size = (int)strtoul(end, &end, 16);
    return (unsigned char *)address;
}

#pragma opt_propagation off
#pragma opt_constants off
MfCiObject *fn_8005A24C(const char *arg0, u32 arg1, int arg2) {
    char *p_lbl_800924F8;
    struct fn_8005A24C_lbl_80190178 *p_lbl_80190178;
    struct { MfCiObject *ptr; } result;
#define v7 result.ptr
    struct { int index; } iteration;
#define v5 iteration.index
    int file_size;
    p_lbl_800924F8 = (char *)&lbl_800924F8;
    p_lbl_80190178 = (struct fn_8005A24C_lbl_80190178 *)&lbl_80190178;
    if (arg0 == 0) {
        if (p_lbl_80190178->unk_0 != 0)
            p_lbl_80190178->unk_0(p_lbl_80190178->unk_4, p_lbl_800924F8 + 540, 0);
        return 0;
    }
    if (arg2 != 0) {
        if (p_lbl_80190178->unk_0 != 0)
            p_lbl_80190178->unk_0(p_lbl_80190178->unk_4, p_lbl_800924F8 + 576, 0);
        return 0;
    }
    v7 = 0;
    {
        MfCiObject *handles;
        v5 = 0;
        handles = p_lbl_80190178->handles;
        for (; v5 < 40; handles++, v5++) {
            if (handles->used == 0) {
                v7 = p_lbl_80190178->handles;
                v7 += v5;
                break;
            }
        }
    }
    if (v7 == 0) {
        if (p_lbl_80190178->unk_0 != 0)
            p_lbl_80190178->unk_0(p_lbl_80190178->unk_4, p_lbl_800924F8 + 612, 0);
        return 0;
    }
    fn_80083DB0(v7->filename, arg0);
    v7->sector_length = 2048;
    get_address(v7->filename, &file_size, p_lbl_80190178, p_lbl_800924F8);
    v7->file_size = file_size;
    {
        int sector_length = v7->sector_length;
        int count = sector_length + v7->file_size;
        count--;
        v7->sector_count = count / sector_length;
    }
    v7->sector_position = 0;
    v7->request_sectors = 0;
    v7->transfer_length = 0;
    v7->status = 0;
    v7->used = 1;
    return v7;
}
