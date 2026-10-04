#include "types.h"
#include "dolphin/os/OSThread.h"

extern void OSWakeupThread(OSThreadQueue *);

void __OSUnlockAllMutex(OSThread *thread) {
    OSMutex *mutex;
    OSMutex *next;
    OSMutex *zero = 0;

    while (thread->queueMutex.head != NULL) {
        mutex = thread->queueMutex.head;
        next = mutex->link.next;
        if (next == NULL) {
            thread->queueMutex.tail = zero;
        } else {
            next->link.prev = zero;
        }
        thread->queueMutex.head = next;
        mutex->count = 0;
        mutex->thread = (OSThread *)zero;
        OSWakeupThread(&mutex->queue);
    }
}
