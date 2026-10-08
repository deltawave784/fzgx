#include "types.h"
struct State {
    u8 pad0[8];
    s16 controller;
    u8 padA[14];
    f32 zoom;
    u8 pad1C[12];
    s16 angleY;
    s16 angleX;
    s32 toggle;
    s16 mode;
};
struct Stick { s8 x,y; u8 pad[14]; };
struct Analog { u8 pad[12]; f32 value; u8 tail[16]; };
struct Buttons { u8 pad[8]; u16 pressed; u8 padA[8]; u16 held; };
extern struct State lbl_1_bss_8B614;
extern struct Stick lbl_1_bss_A48[];
extern struct Analog lbl_1_bss_BF0[];
extern struct Buttons lbl_1_bss_9F8[];
extern const f32 lbl_16_rodata_0[18];
extern void fn_1_A2D84(u32);
static inline s32 wrap(s32 v, s32 max) {
    return v > max ? 0 : v < 0 ? max : v;
}
static inline f32 clamp(f32 v) {
    if (v < lbl_16_rodata_0[20]) return lbl_16_rodata_0[20];
    if (v > lbl_16_rodata_0[21]) return lbl_16_rodata_0[21];
    return v;
}
#pragma opt_common_subs on
#pragma opt_propagation off
s32 fn_16_20F4(void) {
    volatile u16 *pressed; /* Input flags are read again after sound calls. */
    s16 delta = 0;
    const f32 *pool = lbl_16_rodata_0;
    s32 index = lbl_1_bss_8B614.controller;
    s32 value;
    f32 factor;
    f32 current;
    f32 zoom;
    f32 bound;
    volatile u16 *held; /* Retail reloads the held flags for each test. */
    value = lbl_1_bss_8B614.angleX + lbl_1_bss_A48[index].x / 20;
    value = value > 360 ? 0 : value < 0 ? 360 : value;
    lbl_1_bss_8B614.angleX = value;
    value = lbl_1_bss_8B614.angleY + lbl_1_bss_A48[index].y / 20;
    lbl_1_bss_8B614.angleY = value > 360 ? 0 : value < 0 ? 360 : value;
    factor = pool[6];
    current = lbl_1_bss_8B614.zoom;
    bound = lbl_1_bss_BF0[index].value;
    zoom = current + (f32)(bound * factor);
    zoom = zoom < pool[20] ? pool[20] : zoom > pool[21] ? pool[21] : zoom;
    bound = zoom;
    lbl_1_bss_8B614.zoom = bound;
    pressed = (volatile u16 *)&lbl_1_bss_9F8[index]; /* Volatile: input flags are reloaded after sound calls. */
    if ((*(pressed += 4) >> 4) & 1) {
        fn_1_A2D84(0xA9010000);
        lbl_1_bss_8B614.toggle = lbl_1_bss_8B614.toggle != 1;
    }
    held = (volatile u16 *)((u8 *)lbl_1_bss_9F8 + index * 20 + 18); /* Volatile: retail reads held flags separately for each test. */
    if ((*held >> 8) & 1) delta = 1;
    if ((*held >> 9) & 1) delta--;
    if (delta != 0) {
        value = lbl_1_bss_8B614.mode + delta;
        lbl_1_bss_8B614.mode = value > 3 ? 0 : value < 0 ? 3 : value;
        fn_1_A2D84(0xA9010000);
    }
    if ((*pressed >> 9) & 1) {
        fn_1_A2D84(0xA9010200);
        return -1;
    }
    return 0;
}
#pragma opt_common_subs reset
