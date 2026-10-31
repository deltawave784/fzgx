#ifndef DOLPHIN_OS_OSTIME_H
#define DOLPHIN_OS_OSTIME_H

#include <dolphin/types.h>

/* OS_BUS_CLOCK / OS_TIMER_CLOCK and the __OSBusClock low-memory word are in dolphin/hw_regs.h:
   include it rather than declaring `extern u32 __OSBusClock;` (an MWCC absolute object, read as
   `lis rX, 0x8000; lwz rY, 0xF8(rX)` with no relocation). It is not included here because an
   absolute object cannot be redeclared after a first declaration. */

typedef s64 OSTime;
typedef u32 OSTick;

OSTime OSGetTime(void);
OSTick OSGetTick(void);

typedef struct OSCalendarTime {
    int sec;
    int min;
    int hour;
    int mday;
    int mon;
    int year;
    int wday;
    int yday;
    int msec;
    int usec;
} OSCalendarTime;
#endif
