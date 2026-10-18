#include "common.h"

extern float *D_4002E064;

typedef struct {
    u32 *pts;       /* 0x00 point table (count first) */
    void *ptsBuf;   /* 0x04 */
    s32 ptsOwn;     /* 0x08 */
    s32 ptsBufOwn;  /* 0x0c */
    void *lines;    /* 0x10 */
    void *goals;    /* 0x14 */
    s32 pad18;      /* 0x18 */
    s32 linesOwn;   /* 0x1c */
    s32 f20;
    s32 f24;
    s32 f28;
    s32 f2c;
    s32 f30;
    s32 f34;
    s32 f38;
    s32 f3c;
    float *cam;     /* 0x40 */
    u8 pad44[0xE4 - 0x44];
    float *cur;     /* 0xe4 */
    s32 padE8[2];
    float ofs[3];   /* 0xf0 */
    s32 padFC;
    s32 mode;       /* 0x100 */
} PathGlob;
extern PathGlob D_4002DF80;

typedef union {
    u32 w;
    u16 h[2];
} PathIdx;
extern PathIdx D_4002E090[];
u16 *getLineData();

/* pad manager state (flags word at +8) */
extern u8 padManagerData[];
void func_400118B8(s32, s32);
void func_40011780(s32);

u8 *getPointData();

void iosFree(void *);
void func_40010618();

extern char D_4001EE48[];
void createYesNoDialog(char *, s32);

extern char D_4001EE78[];

extern void *D_4002DF90;
extern s32 D_4002F000[];
u8 *getRootPointData();

extern void *D_4002DF94;
extern s32 D_4002F008[];
u8 *getGoalPointData();

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0006_func_4001A9C0", func_4001A9C0);

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0006_func_4001A9C0", func_4001AB18);

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0006_func_4001A9C0", func_4001AC40);

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0006_func_4001A9C0", func_4001AE20);

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0006_func_4001A9C0", func_4001B040);

float *func_4001B2D0(void) {
    return D_4002E064;
}

float *func_4001B2E0(void) {
    float *p = D_4002E064;
    if (p == 0) {
        return 0;
    }
    return p + 1;
}

float *func_4001B2F8(void) {
    float *p = D_4002E064;
    if (p == 0) {
        return 0;
    }
    return p + 2;
}

float *func_4001B310(void) {
    if (D_4002DF80.cur != 0) {
        D_4002DF80.ofs[0] = D_4002DF80.cur[0] - D_4002DF80.cam[8];
        return &D_4002DF80.ofs[0];
    }
    return 0;
}

float *func_4001B348(void) {
    if (D_4002DF80.cur != 0) {
        D_4002DF80.ofs[1] = D_4002DF80.cur[1] - D_4002DF80.cam[9];
        return &D_4002DF80.ofs[1];
    }
    return 0;
}

float *func_4001B380(void) {
    if (D_4002DF80.cur != 0) {
        D_4002DF80.ofs[2] = D_4002DF80.cur[2] - D_4002DF80.cam[10];
        return &D_4002DF80.ofs[2];
    }
    return 0;
}

void func_4001B3B8(void) {
    if (D_4002DF80.cur != 0) {
        D_4002DF80.cur[0] = D_4002DF80.ofs[0] + D_4002DF80.cam[8];
    }
}

void func_4001B3E8(void) {
    if (D_4002DF80.cur != 0) {
        D_4002DF80.cur[1] = D_4002DF80.ofs[1] + D_4002DF80.cam[9];
    }
}

void func_4001B418(void) {
    if (D_4002DF80.cur != 0) {
        D_4002DF80.cur[2] = D_4002DF80.ofs[2] + D_4002DF80.cam[10];
    }
}

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0006_func_4001A9C0", func_4001B448);

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0006_func_4001A9C0", func_4001B4E0);

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0006_func_4001A9C0", func_4001B5F8);

void func_4001B690(void) {
    u16 *p = getLineData();
    p[0] = D_4002E090[0].h[0];
    p[1] = D_4002E090[0].h[0];
    *(s32 *)(p + 2) = 0x11;
    p[6] = 0x10;
    p[8] = 0xffff;
    *(s32 *)(p + 4) = 0x11;
    p[7] = 0x10;
    p[9] = 0xffff;
    *(s32 *)(p + 10) = 0;
}

void func_4001B6F0(void) {
    func_400118B8(0, 0);
    if (*(s32 *)(padManagerData + 8) & 0x20) {
        func_40011780(1);
    }
}

void func_4001B738(void) {
    u8 *p;
    if (D_4002DF80.pts != 0) {
        p = getPointData(D_4002DF80.pts, D_4002E090[0].w);
        *(u16 *)(p + 0x1c) = D_4002E090[1].h[0];
        *(u16 *)(p + 0x20) = D_4002E090[2].h[0];
        *(u16 *)(p + 0x22) = D_4002E090[3].h[0];
    }
}

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0006_func_4001A9C0", func_4001B790);

void func_4001B878(void) {
    if (D_4002DF80.ptsBufOwn != 0) {
        iosFree(D_4002DF80.ptsBuf);
    }
    D_4002DF80.ptsBuf = 0;
    D_4002DF80.ptsBufOwn = 0;
    func_40010618(0, 0);
}

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0006_func_4001A9C0", func_4001B8C0);

void func_4001B998(void) {
    if (D_4002DF80.ptsOwn != 0) {
        iosFree(D_4002DF80.pts);
    }
    D_4002DF80.pts = 0;
    D_4002DF80.ptsOwn = 0;
}

void func_4001B9D8(u8 *self) {
    if (*(s32 *)(padManagerData + 8) & 0x20) {
        createYesNoDialog(D_4001EE48, *(s32 *)(self + 0x94));
    }
}

void func_4001BA18(void) {
    u8 *g = (u8 *)&D_4002DF80;
    if (*(s64 *)(g + 8) != 0 || *(s32 *)(g + 0x1c) != 0 || *(s64 *)(g + 0x20) != 0 || *(s32 *)(g + 0x2c) != 0 || *(s32 *)(g + 0x34) != 0 || *(s32 *)(g + 0x3c) != 0) {
        createYesNoDialog(D_4001EE78, 0);
    }
}

extern u8 padManagerData[];
void func_40017728();

void func_4001BA98(void)
{
    if (*(s32 *)(padManagerData + 8) & 0x20)
    {
        func_40017728();
    }
    return;
}

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0006_func_4001A9C0", func_4001BAC8);

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0006_func_4001A9C0", func_4001BB70);

void func_4001BBF8(void) {
    u8 *p;
    if (D_4002DF90 != 0) {
        p = getRootPointData(D_4002DF90, D_4002F000[0]);
        *(s32 *)(p + 0x10) = D_4002F000[1];
    }
}

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0006_func_4001A9C0", func_4001BC40);

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0006_func_4001A9C0", func_4001BD08);

void func_4001BDE0(void) {
    if (D_4002DF80.linesOwn != 0) {
        iosFree(D_4002DF80.lines);
    }
    D_4002DF80.lines = 0;
    D_4002DF80.linesOwn = 0;
}

extern u8 padManagerData[];
void func_400180D0();

void func_4001BE20(void)
{
    if (*(s32 *)(padManagerData + 8) & 0x20)
    {
        func_400180D0();
    }
    return;
}

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0006_func_4001A9C0", func_4001BE50);

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0006_func_4001A9C0", func_4001BEF8);

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0006_func_4001A9C0", func_4001BFC8);

void func_4001C090(void) {
    u8 *p;
    if (D_4002DF94 != 0) {
        p = getGoalPointData(D_4002DF94, D_4002F008[0]);
        *(u16 *)(p + 0x10) = D_4002F008[1];
    }
}

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0006_func_4001A9C0", func_4001C0D8);

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0006_func_4001A9C0", func_4001C1A0);
