typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

s32 fn_12_A2C4(u8 *p) {
    s32 code;
    s32 i;
    code = (p[0] << 8) | p[1];
    code <<= 8;
    code |= p[2];
    code <<= 8;
    code |= p[3];
    if (code == 0x100) {
        return 4;
    }
    if (code == 0x101) {
        return 3;
    }
    if (code > 0x101 && code <= 0x1AF) {
        return 1;
    }
    if (code == 0x1B2) {
        return 0x20;
    }
    if (code == 0x1B3) {
        return 0x40;
    }
    if (code == 0x1B5) {
        return 0x10;
    }
    if (code == 0x1B7) {
        return 0x80;
    }
    if (code == 0x1B8) {
        return 8;
    }
    return 0;
}
