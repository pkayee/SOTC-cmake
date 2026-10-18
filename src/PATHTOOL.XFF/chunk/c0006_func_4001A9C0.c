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

extern char rootPtn[];
extern char D_40020680[];
extern float D_400201B0[];
extern s32 SH_SmallAnimalTypeDEFAULT[];
void *iosMallocAlign(void *, s32, s32);
void *memcpy(void *dst, const void *src, u32 n);
void createParamMenu();
void cursorLockParamMenu();
void func_4001D4C0();

void func_400180D0();
void func_40017728();
void func_40018E78();

extern char D_4001E7D8[];
extern float D_4001E458[];
void func_4001B8C0();

extern u32 D_4002E0A8;
extern float D_4001E828[];

s32 DEBUG_is_locking_debug_camera();
void DebugGlobalMoveWith2ndController();

extern float D_4001EEA8[];

void func_40018550();

extern float D_4001F1F0[];

void func_4001A9C0(u8 *self) {
    if (*(s32 *)(padManagerData + 8) & 0x20) {
        u32 *t = (u32 *)D_4002DF80.f38;
        if (t != 0) {
            void *q;
            D_400201B0[7] = (float)*t;
            D_400201B0[7] = D_400201B0[7] - 1.0f;
            if (D_400201B0[7] < 0.0f) {
                D_400201B0[7] = 0.0f;
            }
            if (D_4002DF80.f3c == 0) {
                q = iosMallocAlign(rootPtn, ((u32 *)D_4002DF80.f38)[1], 0x10);
                memcpy(q, (void *)D_4002DF80.f38, ((u32 *)D_4002DF80.f38)[1]);
                func_4001D4C0(q);
            }
        }
        D_400201B0[63] = (float)(SH_SmallAnimalTypeDEFAULT[3] - 1);
        *(s32 *)&D_400201B0[67] = SH_SmallAnimalTypeDEFAULT[4];
        {
            union { s32 w; float f; } *u = (void *)(self + 0x94);
            createParamMenu(D_40020680, u->w);
        }
        cursorLockParamMenu(D_40020680, 1);
    }
    return;
}

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

void func_4001B448(s32 a) {
    switch (D_4002DF80.mode) {
    case 3:
        func_40017728(a);
        break;
    case 4:
        func_400180D0(a);
        break;
    case 5:
        func_40018E78(a);
        break;
    }
    D_4002DF80.mode = -1;
}

void func_4001B4E0(u8 *self) {
    if (*(s32 *)(padManagerData + 8) & 0x20) {
        if (D_4002DF80.pts != 0) {
            void *q;
            D_4001E458[7] = (float)*D_4002DF80.pts;
            D_4001E458[7] = D_4001E458[7] - 1.0f;
            if (D_4001E458[7] < 0.0f) {
                D_4001E458[7] = 0.0f;
            }
            if (D_4002DF80.ptsOwn == 0) {
                q = iosMallocAlign(rootPtn, D_4002DF80.pts[1], 0x10);
                memcpy(q, D_4002DF80.pts, D_4002DF80.pts[1]);
                func_4001B8C0(q);
            }
        }
        createParamMenu(D_4001E7D8, *(s32 *)(self + 0x94));
        cursorLockParamMenu(D_4001E7D8, 1);
    }
    return;
}

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

void func_4001B790(u32 *p) {
    u32 *g = (u32 *)&D_4002DF80;
    if (D_4002DF80.ptsBufOwn != 0) {
        iosFree((void *)g[1]);
    }
    g[1] = (u32)p;
    D_4002DF80.ptsBufOwn = 1;
    if (*p <= D_4002E0A8) {
        D_4002E0A8 = *p - 1;
    }
    func_40010618(0, 0);
    D_4001E828[7] = (float)*(u32 *)g[1];
    D_4001E828[7] = D_4001E828[7] - 1.0f;
    if (D_4001E828[7] < 0.0f) {
        D_4001E828[7] = 0.0f;
    }
}

void func_4001B878(void) {
    if (D_4002DF80.ptsBufOwn != 0) {
        iosFree(D_4002DF80.ptsBuf);
    }
    D_4002DF80.ptsBuf = 0;
    D_4002DF80.ptsBufOwn = 0;
    func_40010618(0, 0);
}

void func_4001B8C0(u32 *p) {
    if (D_4002DF80.ptsOwn != 0) {
        iosFree(D_4002DF80.pts);
    }
    *(u32 *)&D_4002DF80.pts = (u32)p;
    D_4002DF80.ptsOwn = 1;
    if (*p <= D_4002E090[0].w) {
        D_4002E090[0].w = *p - 1;
    }
    D_4001E458[7] = (float)*D_4002DF80.pts;
    D_4001E458[7] = D_4001E458[7] - 1.0f;
    if (D_4001E458[7] < 0.0f) {
        D_4001E458[7] = 0.0f;
    }
}

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

void func_4001BAC8(void) {
    u8 *p;
    if (D_4002DF80.lines != 0) {
        p = getRootPointData(D_4002DF80.lines, D_4002F000[0]);
        *(s32 *)&D_4002DF80.cur = (s32)p;
        D_4002F000[1] = *(s32 *)(p + 0x10);
        func_40011780(*(s32 *)((u8 *)&D_4002DF80 + 0xD0));
    } else {
        D_4002DF80.cur = 0;
    }
    if (DEBUG_is_locking_debug_camera() != 0 && D_4002DF80.cur != 0) {
        DebugGlobalMoveWith2ndController(D_4002DF80.cur, D_4002DF80.cur);
    }
}

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0006_func_4001A9C0", func_4001BB70);

void func_4001BBF8(void) {
    u8 *p;
    if (D_4002DF90 != 0) {
        p = getRootPointData(D_4002DF90, D_4002F000[0]);
        *(s32 *)(p + 0x10) = D_4002F000[1];
    }
}

void func_4001BC40(void) {
    u8 *p;
    if (D_4002DF80.lines != 0) {
        p = getRootPointData(D_4002DF80.lines, D_4002F000[0]);
        *(s32 *)&D_4002DF80.cur = (s32)p;
        D_4002F000[1] = *(s32 *)(p + 0x10);
        func_40011780(*(s32 *)((u8 *)&D_4002DF80 + 0xD0));
    } else {
        D_4002DF80.cur = 0;
    }
    if (DEBUG_is_locking_debug_camera() != 0 && D_4002DF80.cur != 0) {
        DebugGlobalMoveWith2ndController(D_4002DF80.cur, D_4002DF80.cur);
    }
    if (*(s32 *)(padManagerData + 8) & 0x20) {
        func_40011780(1);
    }
}

void func_4001BD08(u32 *p) {
    u32 *g = (u32 *)&D_4002DF80;
    if (D_4002DF80.linesOwn != 0) {
        iosFree((void *)g[4]);
    }
    g[4] = (u32)p;
    D_4002DF80.linesOwn = 1;
    if (*p <= D_4002F000[0]) {
        D_4002F000[0] = *p - 1;
    }
    D_4001EEA8[7] = (float)*(u32 *)g[4];
    D_4001EEA8[7] = D_4001EEA8[7] - 1.0f;
    if (D_4001EEA8[7] < 0.0f) {
        D_4001EEA8[7] = 0.0f;
    }
}

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

void func_4001BE50(void) {
    u8 *p;
    if (D_4002DF80.goals != 0) {
        union { s32 w; s16 h; } *u;
        p = getGoalPointData(D_4002DF80.goals, D_4002F008[0]);
        *(s32 *)&D_4002DF80.cur = (s32)p;
        u = (void *)(p + 0x10);
        D_4002F008[1] = u->h;
        func_40011780(*(s32 *)((u8 *)&D_4002DF80 + 0xD0));
    } else {
        D_4002DF80.cur = 0;
    }
    if (DEBUG_is_locking_debug_camera() != 0 && D_4002DF80.cur != 0) {
        DebugGlobalMoveWith2ndController(D_4002DF80.cur, D_4002DF80.cur);
    }
}

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0006_func_4001A9C0", func_4001BEF8);

void func_4001BFC8(void) {
    u8 *p;
    if (D_4002DF80.goals != 0) {
        union { s32 w; s16 h; } *u;
        p = getGoalPointData(D_4002DF80.goals, D_4002F008[0]);
        *(s32 *)&D_4002DF80.cur = (s32)p;
        u = (void *)(p + 0x10);
        D_4002F008[1] = u->h;
        func_40011780(*(s32 *)((u8 *)&D_4002DF80 + 0xD0));
    } else {
        D_4002DF80.cur = 0;
    }
    if (DEBUG_is_locking_debug_camera() != 0 && D_4002DF80.cur != 0) {
        DebugGlobalMoveWith2ndController(D_4002DF80.cur, D_4002DF80.cur);
    }
    if (*(s32 *)(padManagerData + 8) & 0x20) {
        func_40018550(D_4002F008[0]);
    }
}

void func_4001C090(void) {
    u8 *p;
    if (D_4002DF94 != 0) {
        p = getGoalPointData(D_4002DF94, D_4002F008[0]);
        *(u16 *)(p + 0x10) = D_4002F008[1];
    }
}

void func_4001C0D8(void) {
    u8 *p;
    if (D_4002DF80.goals != 0) {
        union { s32 w; s16 h; } *u;
        p = getGoalPointData(D_4002DF80.goals, D_4002F008[0]);
        *(s32 *)&D_4002DF80.cur = (s32)p;
        u = (void *)(p + 0x10);
        D_4002F008[1] = u->h;
        func_40011780(*(s32 *)((u8 *)&D_4002DF80 + 0xD0));
    } else {
        D_4002DF80.cur = 0;
    }
    if (DEBUG_is_locking_debug_camera() != 0 && D_4002DF80.cur != 0) {
        DebugGlobalMoveWith2ndController(D_4002DF80.cur, D_4002DF80.cur);
    }
    if (*(s32 *)(padManagerData + 8) & 0x20) {
        func_40011780(1);
    }
}

void func_4001C1A0(u32 *p) {
    u32 *g = (u32 *)&D_4002DF80;
    if (D_4002DF80.f20 != 0) {
        iosFree((void *)g[5]);
    }
    g[5] = (u32)p;
    D_4002DF80.f20 = 1;
    if (*p <= D_4002F008[0]) {
        D_4002F008[0] = *p - 1;
    }
    D_4001F1F0[7] = (float)*(u32 *)g[5];
    D_4001F1F0[7] = D_4001F1F0[7] - 1.0f;
    if (D_4001F1F0[7] < 0.0f) {
        D_4001F1F0[7] = 0.0f;
    }
}
