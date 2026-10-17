#include "types.h"

typedef struct Fn12_3A888_Object {
    u8 pad[0x5C];
    s32 flag;
    s32 state;
} Fn12_3A888_Object;

typedef struct Fn12_3A888_Global {
    u8 pad[0x24];
    s32 flag;
} Fn12_3A888_Global;

extern void fn_12_341C0(void);
extern Fn12_3A888_Global *fn_12_38DBC(void);
extern void fn_12_34B64(void);
extern void fn_12_341BC(void);
extern void fn_8004EC14(void);

static inline void setFlag(Fn12_3A888_Object *object, s32 flag, s32 globalFlag) {
    Fn12_3A888_Global *global = fn_12_38DBC();
    object->flag = flag;
    global->flag = globalFlag;
}

static inline void waitForState(Fn12_3A888_Object *object, s32 zero) {
    s32 i;
    if (object->state == 1) {
        for (i = zero; i < 10; i++) {
            setFlag(object, 1, 1);
            fn_8004EC14();
            setFlag(object, zero, 0);
            if (object->state == 0) {
                break;
            }
        }
    }
}

void fn_12_3A888(Fn12_3A888_Object *object) {
    fn_12_341C0();
    setFlag(object, 1, 1);
    fn_12_34B64();
    setFlag(object, 0, 0);
    fn_12_341BC();
    waitForState(object, 0);
}
