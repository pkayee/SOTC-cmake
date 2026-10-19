#include "common.h"

typedef union {
    s32 w;
    float f;
} W;
typedef struct {
    u32 *pts;
    u32 *lines;
    s32 f08;
    s32 f0c;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1c;
    s32 f20;
    s32 f24;
    s32 f28;
    s32 f2c;
    s32 f30;
    s32 f34;
    s32 f38;
    s32 f3c;
    W *cam;
    s32 f44;
} PathGlob;
extern PathGlob D_4002DF80;
extern u8 *D_4002DF84;
typedef struct {
    u32 idx;
    u16 v04;
    u16 pad06;
    u16 v08;
    u16 pad0a;
    s32 f0c;
    s32 f10;
    s32 f14;
    s32 mode;
    u16 v1c;
    u16 pad1e;
    u16 v20;
    u16 pad22;
    u16 v24;
    u16 pad26;
    s32 f28;
    float v2c;
} PathEdit;
extern PathEdit D_4002E0A8;
typedef struct {
    u64 d[6];
} LineRec6;
typedef union {
    struct {
        u16 a;
        u16 b;
        u32 flags;
        s32 pad08;
        u16 c;
        u16 pad0e;
        u16 d;
        u16 e;
        float f;
    } s;
    u8 raw[0x18];
} LineRec;
typedef struct {
    u8 pad[0x20];
    char *name;
    u8 pad2[0x24];
} NameEnt;
extern NameEnt D_4001DFF8[];
extern u8 padManagerData[];
extern u8 gcGlobalVar[];
extern char rootPtn[];
extern char *D_4001DB84;
extern char D_4002E100[];
extern u8 D_4001EE78[];
extern float D_4001E828[];
extern char D_4001EC88[];
extern char D_4001DFB8[];
extern char D_40020FD0[];
s32 strcmp();
char *strcpy();
void *memcpy();
void *iosMallocAlign();
u8 *getLineData();
u8 *isysGroupForFirst();
u8 *isysGroupForNext();
void isysGroupForExit();
void iosJumpRecoverPoint();
void createParamMenu();
void cursorLockParamMenu();
void func_4001B998();
void func_4001B878();
void func_4001BDE0();
void func_4001C278();
void func_4001C738();
void func_4001CE88();
void func_4001D220();
void func_4001B690();
void func_4001B790();
void func_40010618();
void func_40010A20();

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0000_func_40010618", func_40010618);

void func_400108A8(void) {
    LineRec *r;
    if (D_4002DF84 != 0) {
        r = (LineRec *)getLineData(D_4002DF84, D_4002E0A8.idx);
        r->s.a = D_4002E0A8.v04;
        r->s.b = D_4002E0A8.v08;
        r->s.flags = 0;
        if (D_4002E0A8.f0c != 0) {
            r->s.flags = 1;
        } else {
            r->s.flags = 0;
        }
        if (D_4002E0A8.f10 != 0) {
            r->s.flags = r->s.flags | 2;
        } else {
            r->s.flags = r->s.flags & ~2;
        }
        if (D_4002E0A8.f14 != 0) {
            r->s.flags = r->s.flags | 4;
        } else {
            r->s.flags = r->s.flags & ~4;
        }
        if (D_4002E0A8.f28 != 0) {
            r->s.flags = r->s.flags | 8;
        } else {
            r->s.flags = r->s.flags & ~8;
        }
        if (D_4002E0A8.mode == 0) {
            r->s.flags = r->s.flags | 0x10;
        } else if (D_4002E0A8.mode == 1) {
            r->s.flags = r->s.flags | 0x20;
        } else if (D_4002E0A8.mode == 2) {
            r->s.flags = r->s.flags | 0x40;
        }
        r->s.c = D_4002E0A8.v1c;
        r->s.d = D_4002E0A8.v20;
        r->s.e = D_4002E0A8.v24;
        r->s.f = D_4002E0A8.v2c;
        func_40010A20(0, 0);
    }
}

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0000_func_40010618", func_40010A20);

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0000_func_40010618", func_40010CC8);

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0000_func_40010618", func_40010EB8);

s32 func_40010FD0(u8 *a0, s32 a1, s32 *a2) {
    if (strcmp((char *)a2[2], D_4001DB84) != 0) {
        s32 idx;
        s32 i;
        W *c;
        func_4001B998();
        idx = 0;
        func_4001B878();
        func_4001BDE0();
        func_4001C278();
        func_4001C738();
        func_4001CE88();
        func_4001D220();
        D_4002DF80.cam = 0;
        for (i = 0; i < 4; i++) {
            u8 *node = isysGroupForFirst(gcGlobalVar + 0x2EC + i * 4, 0);
            u8 *last = 0;
            for (; node != 0; node = isysGroupForNext(node, 0), idx++) {
                last = *(u8 **)node;
                if (a2[1] == idx) {
                    D_4002DF80.cam = (W *)last;
                    idx++;
                    break;
                }
            }
            if (last != 0) {
                isysGroupForExit(last, 0);
            }
        }
        c = D_4002DF80.cam;
        D_4002DF80.f44 = *(s32 *)(c[14].w + 0x1C);
        D_4002DF80.pts = (u32 *)c[15].w;
        D_4002DF80.lines = (u32 *)c[16].w;
        D_4002DF80.f10 = c[17].w;
        D_4002DF80.f14 = c[18].w;
        D_4002DF80.f18 = c[19].w;
        D_4002DF80.f28 = c[20].w;
        D_4002DF80.f30 = c[21].w;
        D_4002DF80.f38 = c[22].w;
        if (*(s32 *)c[14].w != 0x68746171) {
            iosJumpRecoverPoint(D_40020FD0);
        }
        createParamMenu(D_4001DFB8, *(s32 *)(a0 + 0x94));
        cursorLockParamMenu(D_4001DFB8, 1);
    }
}

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0000_func_40010618", func_40011190);

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0000_func_40010618", func_40011410);

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0000_func_40010618", func_40011780);

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0000_func_40010618", func_400118B8);

s32 func_40011A10(u8 *a0) {
    if (*(u32 *)(padManagerData + 8) & 0x20) {
        if (D_4002DF80.pts != 0) {
            if (D_4002DF80.lines != 0) {
                D_4001E828[7] = (float)*D_4002DF80.lines;
                D_4001E828[7] = D_4001E828[7] - 1.0f;
                if (D_4001E828[7] < 0.0f) {
                    D_4001E828[7] = 0.0f;
                }
                if (D_4002DF80.f0c == 0) {
                    void *p = iosMallocAlign(rootPtn, D_4002DF80.lines[1], 0x10);
                    memcpy(p, D_4002DF80.lines, D_4002DF80.lines[1]);
                    func_4001B790(p);
                }
            }
            D_4001E828[0x31] = (float)*D_4002DF80.pts;
            D_4001E828[0x31] = D_4001E828[0x31] - 1.0f;
            if (D_4001E828[0x31] < 0.0f) {
                D_4001E828[0x31] = 0.0f;
            }
            D_4001E828[0x3F] = D_4001E828[0x31];
            createParamMenu(D_4001EC88, ((W *)a0)[0x25].w);
            cursorLockParamMenu(D_4001EC88, 1);
        }
    }
}

s32 func_40011BC0(void) {
    if (*(u32 *)(padManagerData + 8) & 0x20) {
        if (D_4002DF80.pts == 0) {
            goto out;
        }
        if (D_4002DF80.lines != 0) {
            u32 n = *D_4002DF80.lines;
            s32 skip = 0;
            u32 i = 0;
            s32 size = n * 0x30 + 0x40;
            s32 *buf = iosMallocAlign(rootPtn, size, 0x10);
            LineRec6 *dst;
            LineRec6 *src;
            buf[0] = n + 1;
            buf[1] = size;
            buf[2] = 0;
            buf[3] = 0;
            if (n != 0) {
                do {
                    dst = (LineRec6 *)getLineData(buf, i + skip);
                    src = (LineRec6 *)getLineData(D_4002DF80.lines, i);
                    *dst = *src;
                    if (((W *)&D_4002E0A8)->w == i) {
                        skip = 1;
                        func_4001B690(buf, i + 1);
                    }
                    i++;
                } while (i < n);
            }
            D_4002E0A8.idx = D_4002E0A8.idx + 1;
            func_4001B790(buf);
        } else {
            s32 *buf = iosMallocAlign(rootPtn, 0x40, 0x10);
            buf[0] = 1;
            buf[1] = 0x40;
            buf[2] = 0;
            buf[3] = 0;
            func_4001B690(buf, 0);
            func_4001B790(buf);
        }
    }
    func_40010618(0, 0);
out:
    ;

}

s32 func_40011D98(void) {
    if (*(u32 *)(padManagerData + 8) & 0x20) {
        if (D_4002DF80.lines != 0) {
            u32 n = *D_4002DF80.lines;
            if (n != 0) {
                if (n >= 2) {
                    s32 skip = 0;
                    s32 cnt = n - 1;
                    s32 size = cnt * 0x30 + 0x10;
                    u32 i = 0;
                    s32 *buf = iosMallocAlign(rootPtn, size, 0x10);
                    LineRec6 *dst;
                    LineRec6 *src;
                    buf[0] = cnt;
                    buf[1] = size;
                    buf[2] = 0;
                    buf[3] = 0;
                    for (; i < n; i++) {
                        if (D_4002E0A8.idx != i) {
                            dst = (LineRec6 *)getLineData(buf, i - skip);
                            src = (LineRec6 *)getLineData(D_4002DF80.lines, i);
                            *dst = *src;
                        } else {
                            skip = 1;
                        }
                    }
                    func_4001B790(buf);
                } else {
                    func_4001B878();
                }
            }
        }
    }
    func_40010618(0, 0);
}
