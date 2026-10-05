#include "types.h"

typedef u32 file_handle;
typedef u32 file_position;

typedef struct FileMode {
    u16 open_mode : 2;
    u16 io_mode : 3;
    u16 buffer_mode : 2;
    u16 file_kind : 3;
    u16 file_orientation : 2;
    u16 binary_io : 1;
    u16 unused : 3;
    u16 pad;
} FileMode;

typedef union FileModeWord {
    u32 value;
    FileMode bits;
} FileModeWord;

typedef struct FileState {
    u8 io_state : 3;
    u8 free_buffer : 1;
    u8 eof;
    u8 error;
} FileState;

typedef void (*IdleProc)(void);
typedef int (*PositionProc)(file_handle handle, file_position *position, int mode, IdleProc idle);
typedef int (*IOProc)(file_handle handle, u8 *buffer, size_t *count, IdleProc idle);
typedef int (*CloseProc)(file_handle handle);

typedef struct FILE {
    file_handle handle;
    FileModeWord mode;
    FileState state;
    u8 is_dynamically_allocated;
    u8 char_buffer;
    u8 char_buffer_overflow;
    u8 ungetc_buffer[2];
    u32 ungetc_wide_buffer[2];
    u32 position;
    u8 *buffer;
    u32 buffer_size;
    u8 *buffer_ptr;
    u32 buffer_length;
    u32 buffer_alignment;
    u32 saved_buffer_length;
    u32 buffer_position;
    PositionProc position_proc;
    IOProc read_proc;
    IOProc write_proc;
    CloseProc close_proc;
    IdleProc idle_proc;
    struct FILE *next_file;
} FILE;

extern int setvbuf(FILE *, char *, int, size_t);
extern int fn_8008D7CC(file_handle, file_position *, int, IdleProc);
extern int fn_8008DB5C(file_handle, u8 *, size_t *, IdleProc);
extern int fn_8008DAA8(file_handle, u8 *, size_t *, IdleProc);
extern int fn_8008D8A8(file_handle);

/* MSL __init_file */
void fn_8007B1CC(FILE *file, FileModeWord mode, char *buff, size_t size) {
    file->handle = 0;
    file->mode = mode;

    file->state.io_state = 0;
    file->state.free_buffer = 0;
    file->state.eof = 0;
    file->state.error = 0;

    file->position = 0;

    if (size) {
        setvbuf(file, buff, 2, size);
    } else {
        setvbuf(file, 0, 0, 0);
    }

    file->buffer_ptr = file->buffer;
    file->buffer_length = 0;

    if (file->mode.bits.file_kind == 1) {
        file->position_proc = fn_8008D7CC;
        file->read_proc = fn_8008DB5C;
        file->write_proc = fn_8008DAA8;
        file->close_proc = fn_8008D8A8;
    }

    file->idle_proc = 0;
}
