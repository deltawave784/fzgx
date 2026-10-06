#include "types.h"
typedef unsigned long Sig_fwide___file_handle;
typedef struct Sig_fwide__file_modes {
    unsigned int open_mode : 2;
    unsigned int io_mode : 3;
    unsigned int buffer_mode : 2;
    unsigned int file_kind : 3;
    unsigned int file_orientation : 2;
    unsigned int binary_io : 1;
} Sig_fwide_file_modes;
typedef struct Sig_fwide__file_states {
    unsigned int io_state : 3;
    unsigned int free_buffer : 1;
    unsigned char eof;
    unsigned char error;
} Sig_fwide_file_states;
typedef unsigned short Sig_fwide_wchar_t;
typedef unsigned long Sig_fwide_fpos_t;
typedef void (*Sig_fwide___idle_proc)(void);
typedef int (*Sig_fwide___pos_proc)(Sig_fwide___file_handle file, Sig_fwide_fpos_t *position, int mode, Sig_fwide___idle_proc idle_proc);
typedef int (*Sig_fwide___io_proc)(Sig_fwide___file_handle file, unsigned char *buff, unsigned long *count, Sig_fwide___idle_proc idle_proc);
typedef int (*Sig_fwide___close_proc)(Sig_fwide___file_handle file);
typedef struct Sig_fwide__FILE {
    Sig_fwide___file_handle handle;
    Sig_fwide_file_modes file_mode;
    Sig_fwide_file_states file_state;
    unsigned char is_dynamically_allocated;
    char char_buffer;
    char char_buffer_overflow;
    char ungetc_buffer[2];
    Sig_fwide_wchar_t ungetc_wide_buffer[2];
    unsigned long position;
    unsigned char *buffer;
    unsigned long buffer_size;
    unsigned char *buffer_ptr;
    unsigned long buffer_length;
    unsigned long buffer_alignment;
    unsigned long save_buffer_length;
    unsigned long buffer_position;
    Sig_fwide___pos_proc position_fn;
    Sig_fwide___io_proc read_fn;
    Sig_fwide___io_proc write_fn;
    Sig_fwide___close_proc close_fn;
    Sig_fwide___idle_proc idle_fn;
    struct Sig_fwide__FILE *next_file;
} Sig_fwide_FILE;
extern int fwide(Sig_fwide_FILE *, int);
extern s32 fn_8007B028(void);
extern s32 fn_8007EC80(Sig_fwide_FILE *, unsigned long *, s32);
extern void *memcpy(void *, const void *, u32);
extern void __prep_buffer(Sig_fwide_FILE *);

u32 fn_8007F13C(void *arg0, u32 arg1, u32 arg2, Sig_fwide_FILE *arg3) {
    int t0;
    int t1;
    int buffered;
    unsigned char *dest;
    u32 remaining;
    u32 total;
    unsigned long count;
    unsigned char *saved_buffer;
    unsigned long saved_size;
    t0 = fwide(arg3, 0);
    if (t0 == 0) {
        t1 = fwide(arg3, -1);
    }
    remaining = arg1 * arg2;
    if (!remaining || arg3->file_state.error || !arg3->file_mode.file_kind)
        return 0;
    buffered = 1;
    if (arg3->file_mode.binary_io && arg3->file_mode.buffer_mode != 2)
        buffered = 0;
    if (!arg3->file_state.io_state && (arg3->file_mode.io_mode & 1)) {
        arg3->file_state.io_state = 2;
        arg3->buffer_length = 0;
    }
    if (arg3->file_state.io_state < 2) {
        arg3->file_state.error = 1;
        arg3->buffer_length = 0;
        return 0;
    }
    if ((arg3->file_mode.buffer_mode & 1) && fn_8007B028()) {
        arg3->file_state.error = 1;
        arg3->buffer_length = 0;
        return 0;
    }
    dest = arg0;
    total = 0;
    if (remaining && arg3->file_state.io_state >= 3) {
        do {
            if (fwide(arg3, 0) == 1) {
                *(unsigned short *)dest = arg3->ungetc_wide_buffer[arg3->file_state.io_state - 3];
                dest += 2;
                total += 2;
                remaining -= 2;
            } else {
                *dest++ = arg3->ungetc_buffer[arg3->file_state.io_state - 3];
                total++;
                remaining--;
            }
            arg3->file_state.io_state--;
        } while (remaining && arg3->file_state.io_state >= 3);
        if (arg3->file_state.io_state == 2)
            arg3->buffer_length = arg3->save_buffer_length;
    }
    if (remaining && (arg3->buffer_length || buffered)) {
        do {
            if (!arg3->buffer_length) {
                t0 = fn_8007EC80(arg3, 0, 0);
                if (t0) {
                    if (t0 == 1) {
                        arg3->file_state.error = 1;
                        arg3->buffer_length = 0;
                    } else {
                        arg3->file_state.io_state = 0;
                        arg3->file_state.eof = 1;
                        arg3->buffer_length = 0;
                    }
                    remaining = 0;
                    break;
                }
            }
            count = arg3->buffer_length;
            if (count > remaining)
                count = remaining;
            memcpy(dest, arg3->buffer_ptr, count);
            remaining -= count;
            dest += count;
            total += count;
            arg3->buffer_ptr += count;
            arg3->buffer_length -= count;
        } while (remaining && buffered);
    }
    if (remaining && !buffered) {
        saved_buffer = arg3->buffer;
        saved_size = arg3->buffer_size;
        arg3->buffer = dest;
        arg3->buffer_size = remaining;
        t0 = fn_8007EC80(arg3, &count, 1);
        if (t0) {
            if (t0 == 1) {
                arg3->file_state.error = 1;
                arg3->buffer_length = 0;
            } else {
                arg3->file_state.io_state = 0;
                arg3->file_state.eof = 1;
                arg3->buffer_length = 0;
            }
        }
        total += count;
        arg3->buffer = saved_buffer;
        arg3->buffer_size = saved_size;
        __prep_buffer(arg3);
        arg3->buffer_length = 0;
    }
    return total / arg1;
}
