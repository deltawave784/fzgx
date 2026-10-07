#include "types.h"
#include "sofdec/sj.h"

extern int fn_12_CAB4(void *movie);
extern int fn_12_A660(void *movie, u32 error);
extern int MPV_GoNextDelimSj(SJ *);
extern int MPV_MoveChunk(SJ *, int, int);

#pragma opt_propagation off
int fn_12_A7B0(void *movie, SJ *sj) {
    void *state = movie;
    u32 error;
    if (fn_12_CAB4(movie)) {
        return fn_12_A660(0, 0xff03020a);
    }
    error = 0xff030305;
    for (;;) {
        int flags = MPV_GoNextDelimSj(sj);
        if (flags == 0) break;
        if (flags & 0xcc) {
            error = 0;
            break;
        }
        if (MPV_MoveChunk(sj, 1, 4) != 4) break;
    }
    return fn_12_A660(state, error);
}
