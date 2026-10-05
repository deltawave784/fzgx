#include "types.h"
#include "sofdec/mwsst.h"

extern MwsStManager lbl_12_data_E90;

void fn_12_3B15C(MwsStHandle *handle);

static inline int mwsst_IsValid(const MwsStHandle *handle) {
    if (lbl_12_data_E90.interface == 0) {
        return 0;
    }
    if (handle->active != 1) {
        return 0;
    }
    if (handle->backend == 0) {
        return 0;
    }
    return 1;
}

void fn_12_3B15C(MwsStHandle *handle) {
    if (mwsst_IsValid(handle) == 1) {
        MwsStHandle *backend = handle->backend;
        SJ *stream = handle->stream;
        MwsStManagerInterface *interface;

        if (backend == 0) {
            return;
        }
        if (mwsst_IsValid(backend) == 1) {
            void *playback = backend->backend;
            if (lbl_12_data_E90.interface != 0 && lbl_12_data_E90.interface->stop != 0) {
                lbl_12_data_E90.interface->stop(playback);
            }
        }
        handle->active = 0;
        interface = lbl_12_data_E90.interface;
        if (backend != 0 && interface != 0 && interface->destroy != 0) {
            interface->destroy(backend);
        }
        stream->interface->destroy(stream);
        handle->backend = 0;
        interface = lbl_12_data_E90.interface;
        if (interface != 0 && lbl_12_data_E90.active_count != 0) {
            if (--lbl_12_data_E90.active_count == 0) {
                if (interface->finish != 0) {
                    interface->finish();
                }
            }
        }
    }
}
