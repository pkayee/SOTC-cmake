#include "common.h"

extern char D_40134288[];

typedef struct { s32 f[12]; } McReq;
extern McReq D_401B16E0[];
extern u8 D_401B16A0[];
extern char D_401342B0[];
extern float D_4012BB38;
extern int D_4012BB4C;
extern s64 *D_4012BB3C;

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0173_mcManager", mcManager);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0173_mcManager", mcWrite);

void mcRead(u8 *m, s32 buf, s32 n)
{
    s32 v;

    v = *(s32 *)(m + 0x30) + n;
    *(s32 *)(m + 0x30) = v;
    if (*(s32 *)(m + 0x28) < v) {
        LoaderSysPrintf(D_40134288);
    }
    iosMcReadFile(*(s32 *)(m + 0x20), *(s32 *)(m + 0x24), m, buf, *(s32 *)(m + 0x2c), n);
    *(s32 *)(m + 0x2c) = *(s32 *)(m + 0x2c) + n;
}

extern void (*D_401B1744)(void);

void mcReqSetWaitFunc(void (*arg0)(void))
{
    D_401B1744 = arg0;
}

s32 mcGetInfo(s32 a, s32 b)
{
    McReq *r;
    McReq *p;
    s32 i;
    void (*fn)(void);

    i = 0;
    p = D_401B16E0;
    do {
        if (p->f[0] == 0) {
            r = p;
            goto found;
        }
        p++;
        i++;
    } while (i < 2);
    r = 0;
    LoaderSysPrintf(D_401342B0);
found:
    r->f[1] = a;
    r->f[2] = b;
    D_4012BB38 = 0;
    r->f[0] = 1;
    iosSendMsg(D_401B16A0, r, 1);
    if (__builtin_expect(r->f[0], 0)) {
        fn = D_401B1744;
        do {
            fn();
            fn = D_401B1744;
        } while (r->f[0] != 0);
    }
    D_4012BB4C = 1;
    return r->f[11];
}
/* NEARMISS-STUB mcGetMainDataInfo */
#if 0 /* NEARMISS 94.62% cat=sched sub=- | family shape (EXPECT-GUARD wait loop) matches; left: after iosStartThread the target schedules li v1,cmd before lui v0,%hi(D_4012BB38) and both lui before the B | attempts=1 */
extern s32 rootPtn;
extern float D_401B1740;
void func_400DBD38(void);
void iosStartThread(void *, s32);
s32 mcGetMainDataInfo(s32 a, s32 b, s32 c)
{
    McReq *r;
    McReq *p;
    s32 i;
    void (*fn)(void);

    i = 0;
    p = D_401B16E0;
    do {
        if (p->f[0] == 0) {
            r = p;
            goto found;
        }
        p++;
        i++;
    } while (i < 2);
    r = 0;
    LoaderSysPrintf(D_401342B0);
found:
    r->f[1] = a;
    r->f[2] = b;
    r->f[10] = c;
    D_401B1740 = 0.1f;
    D_4012BB4C = 0;
    iosStartThread(iosCreateThreadS(func_400DBD38, 0, &rootPtn, 0x1000, 0x2F, 0), 0);
    D_4012BB38 = 0;
    r->f[0] = 2;
    iosSendMsg(D_401B16A0, r, 1);
    if (__builtin_expect(r->f[0], 0)) {
        fn = D_401B1744;
        do {
            fn();
            fn = D_401B1744;
        } while (r->f[0] != 0);
    }
    D_4012BB4C = 1;
    return r->f[11];
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0173_mcManager", mcGetMainDataInfo);

s32 mcSaveGameData(s32 a, s32 b, s32 c, s32 d, s32 e)
{
    McReq *r;
    McReq *p;
    s32 i;
    void (*fn)(void);

    i = 0;
    p = D_401B16E0;
    do {
        if (p->f[0] == 0) {
            r = p;
            goto found;
        }
        p++;
        i++;
    } while (i < 2);
    r = 0;
    LoaderSysPrintf(D_401342B0);
found:
    r->f[1] = a;
    r->f[2] = b;
    r->f[5] = c;
    r->f[4] = d;
    r->f[10] = e;
    D_4012BB38 = 0;
    r->f[0] = 3;
    iosSendMsg(D_401B16A0, r, 1);
    if (__builtin_expect(r->f[0], 0)) {
        fn = D_401B1744;
        do {
            fn();
            fn = D_401B1744;
        } while (r->f[0] != 0);
    }
    D_4012BB4C = 1;
    if (r->f[11] == 0) {
        *(s32 *)&D_4012BB3C = 0;
    }
    return r->f[11];
}

extern s64 D_401B16D8;
typedef union { s64 d; s32 w[2]; } McU64;
s32 mcLoadGameData(s32 a, s32 b, s32 c, u8 *d)
{
    McReq *r;
    McReq *p;
    s32 i;
    void (*fn)(void);

    i = 0;
    p = D_401B16E0;
    do {
        if (p->f[0] == 0) {
            r = p;
            goto found;
        }
        p++;
        i++;
    } while (i < 2);
    r = 0;
    LoaderSysPrintf(D_401342B0);
found:
    r->f[1] = a;
    r->f[2] = b;
    r->f[5] = c;
    D_4012BB38 = 0;
    r->f[0] = 4;
    iosSendMsg(D_401B16A0, r, 1);
    if (__builtin_expect(r->f[0], 0)) {
        fn = D_401B1744;
        do {
            fn();
            fn = D_401B1744;
        } while (r->f[0] != 0);
    }
    D_4012BB4C = 1;
    if (r->f[11] == 0) {
        s64 t = *(s64 *)(d + c * 0x98 + 0x118);
        D_4012BB3C = &D_401B16D8;
        ((McU64 *)D_4012BB3C)->d = t;
    }
    return r->f[11];
}

s32 mcDeleteGameData(s32 a, s32 b, s32 c, s32 d)
{
    McReq *r;
    McReq *p;
    s32 i;
    void (*fn)(void);

    i = 0;
    p = D_401B16E0;
    do {
        if (p->f[0] == 0) {
            r = p;
            goto found;
        }
        p++;
        i++;
    } while (i < 2);
    r = 0;
    LoaderSysPrintf(D_401342B0);
found:
    r->f[1] = a;
    r->f[2] = b;
    r->f[5] = c;
    r->f[10] = d;
    D_4012BB38 = 0;
    r->f[0] = 5;
    iosSendMsg(D_401B16A0, r, 1);
    if (__builtin_expect(r->f[0], 0)) {
        fn = D_401B1744;
        do {
            fn();
            fn = D_401B1744;
        } while (r->f[0] != 0);
    }
    D_4012BB4C = 1;
    return r->f[11];
}

s32 mcLoadOptionData(s32 a, s32 b)
{
    McReq *r;
    McReq *p;
    s32 i;
    void (*fn)(void);

    i = 0;
    p = D_401B16E0;
    do {
        if (p->f[0] == 0) {
            r = p;
            goto found;
        }
        p++;
        i++;
    } while (i < 2);
    r = 0;
    LoaderSysPrintf(D_401342B0);
found:
    r->f[1] = a;
    r->f[2] = b;
    D_4012BB38 = 0;
    r->f[0] = 6;
    iosSendMsg(D_401B16A0, r, 1);
    if (__builtin_expect(r->f[0], 0)) {
        fn = D_401B1744;
        do {
            fn();
            fn = D_401B1744;
        } while (r->f[0] != 0);
    }
    D_4012BB4C = 1;
    return r->f[11];
}

/* NEARMISS-STUB mcFormat */
#if 0 /* NEARMISS 94.26% cat=sched sub=- | family shape (EXPECT-GUARD wait loop) matches; left: after iosStartThread the target schedules li v1,cmd before lui v0,%hi(D_4012BB38) and both lui before the B | attempts=1 */
extern s32 rootPtn;
extern float D_401B1740;
void func_400DBD38(void);
void iosStartThread(void *, s32);
s32 mcFormat(s32 a, s32 b)
{
    McReq *r;
    McReq *p;
    s32 i;
    void (*fn)(void);

    i = 0;
    p = D_401B16E0;
    do {
        if (p->f[0] == 0) {
            r = p;
            goto found;
        }
        p++;
        i++;
    } while (i < 2);
    r = 0;
    LoaderSysPrintf(D_401342B0);
found:
    r->f[1] = a;
    r->f[2] = b;
    D_401B1740 = 17.0f;
    D_4012BB4C = 0;
    iosStartThread(iosCreateThreadS(func_400DBD38, 0, &rootPtn, 0x1000, 0x2F, 0), 0);
    D_4012BB38 = 0;
    r->f[0] = 7;
    iosSendMsg(D_401B16A0, r, 1);
    if (__builtin_expect(r->f[0], 0)) {
        fn = D_401B1744;
        do {
            fn();
            fn = D_401B1744;
        } while (r->f[0] != 0);
    }
    D_4012BB4C = 1;
    return r->f[11];
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0173_mcManager", mcFormat);

s32 mcUnformat(s32 a, s32 b)
{
    McReq *r;
    McReq *p;
    s32 i;
    void (*fn)(void);

    i = 0;
    p = D_401B16E0;
    do {
        if (p->f[0] == 0) {
            r = p;
            goto found;
        }
        p++;
        i++;
    } while (i < 2);
    r = 0;
    LoaderSysPrintf(D_401342B0);
found:
    r->f[1] = a;
    r->f[2] = b;
    D_4012BB38 = 0;
    r->f[0] = 8;
    iosSendMsg(D_401B16A0, r, 1);
    if (__builtin_expect(r->f[0], 0)) {
        fn = D_401B1744;
        do {
            fn();
            fn = D_401B1744;
        } while (r->f[0] != 0);
    }
    D_4012BB4C = 1;
    return r->f[11];
}

extern float D_4012BB38;

float mcGetProcessPer(void)
{
    return D_4012BB38;
}

s32 mcDirectFileCreate(s32 a, s32 b, s32 c, s32 *out)
{
    McReq *r;
    McReq *p;
    s32 i;
    void (*fn)(void);

    i = 0;
    p = D_401B16E0;
    do {
        if (p->f[0] == 0) {
            r = p;
            goto found;
        }
        p++;
        i++;
    } while (i < 2);
    r = 0;
    LoaderSysPrintf(D_401342B0);
found:
    r->f[1] = a;
    r->f[2] = b;
    r->f[3] = c;
    D_4012BB38 = 0;
    r->f[0] = 11;
    iosSendMsg(D_401B16A0, r, 1);
    if (__builtin_expect(r->f[0], 0)) {
        fn = D_401B1744;
        do {
            fn();
            fn = D_401B1744;
        } while (r->f[0] != 0);
    }
    D_4012BB4C = 1;
    *out = r->f[6];
    return r->f[11];
}

s32 mcDirectFileDelete(s32 a, s32 b, s32 c)
{
    McReq *r;
    McReq *p;
    s32 i;
    void (*fn)(void);

    i = 0;
    p = D_401B16E0;
    do {
        if (p->f[0] == 0) {
            r = p;
            goto found;
        }
        p++;
        i++;
    } while (i < 2);
    r = 0;
    LoaderSysPrintf(D_401342B0);
found:
    r->f[1] = a;
    r->f[2] = b;
    r->f[3] = c;
    D_4012BB38 = 0;
    r->f[0] = 12;
    iosSendMsg(D_401B16A0, r, 1);
    if (__builtin_expect(r->f[0], 0)) {
        fn = D_401B1744;
        do {
            fn();
            fn = D_401B1744;
        } while (r->f[0] != 0);
    }
    D_4012BB4C = 1;
    return r->f[11];
}

s32 mcDirectFileWrite(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f)
{
    McReq *r;
    McReq *p;
    s32 i;
    void (*fn)(void);

    i = 0;
    p = D_401B16E0;
    do {
        if (p->f[0] == 0) {
            r = p;
            goto found;
        }
        p++;
        i++;
    } while (i < 2);
    r = 0;
    LoaderSysPrintf(D_401342B0);
found:
    r->f[1] = a;
    r->f[2] = b;
    r->f[3] = c;
    r->f[6] = d;
    r->f[9] = e;
    r->f[7] = f;
    D_4012BB38 = 0;
    r->f[0] = 14;
    iosSendMsg(D_401B16A0, r, 1);
    if (__builtin_expect(r->f[0], 0)) {
        fn = D_401B1744;
        do {
            fn();
            fn = D_401B1744;
        } while (r->f[0] != 0);
    }
    D_4012BB4C = 1;
    return r->f[11];
}

s32 mcDirectFileRead(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f)
{
    McReq *r;
    McReq *p;
    s32 i;
    void (*fn)(void);

    i = 0;
    p = D_401B16E0;
    do {
        if (p->f[0] == 0) {
            r = p;
            goto found;
        }
        p++;
        i++;
    } while (i < 2);
    r = 0;
    LoaderSysPrintf(D_401342B0);
found:
    r->f[1] = a;
    r->f[2] = b;
    r->f[3] = c;
    r->f[6] = d;
    r->f[9] = e;
    r->f[7] = f;
    D_4012BB38 = 0;
    r->f[0] = 13;
    iosSendMsg(D_401B16A0, r, 1);
    if (__builtin_expect(r->f[0], 0)) {
        fn = D_401B1744;
        do {
            fn();
            fn = D_401B1744;
        } while (r->f[0] != 0);
    }
    D_4012BB4C = 1;
    return r->f[11];
}

s32 mcReqGetDir(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g)
{
    McReq *r;
    McReq *p;
    s32 i;
    void (*fn)(void);

    i = 0;
    p = D_401B16E0;
    do {
        if (p->f[0] == 0) {
            r = p;
            goto found;
        }
        p++;
        i++;
    } while (i < 2);
    r = 0;
    LoaderSysPrintf(D_401342B0);
found:
    r->f[1] = a;
    r->f[2] = b;
    r->f[3] = c;
    r->f[6] = d;
    r->f[7] = e;
    r->f[8] = f;
    r->f[9] = g;
    D_4012BB38 = 0;
    r->f[0] = 10;
    iosSendMsg(D_401B16A0, r, 1);
    if (__builtin_expect(r->f[0], 0)) {
        fn = D_401B1744;
        do {
            fn();
            fn = D_401B1744;
        } while (r->f[0] != 0);
    }
    D_4012BB4C = 1;
    return r->f[11];
}

/* NEARMISS-STUB mcGetLastSaveGameDataIndex */
#if 0 /* NEARMISS 86.65625% cat=branch-layout sub=- | loop tail/early return layout and -1 test reg differ; arg copy/const order | attempts=1 */
extern s64 *D_4012BB3C;

s32 mcGetLastSaveGameDataIndex(u8 *arg0)
{
    s32 i;
    u8 *p;

    if (D_4012BB3C != 0) {
        i = 0;
        p = arg0 + 0xD8;
        do {
            if (*(s32 *)(p + 0xC) == 1 && *D_4012BB3C == *(s64 *)(p + 0x40)) {
                return i;
            }
            i++;
            p += 0x98;
        } while (i < 10);
    }
    if (*(s32 *)(arg0 + 0x4C) != 0) {
        return *(s32 *)(arg0 + 0x50);
    }
    return -1;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0173_mcManager", mcGetLastSaveGameDataIndex);

extern int D_4012BB40;

int mcGetGameClearFlag(void)
{
    return D_4012BB40;
}

void mcSetGameClearFlag(void)
{
    D_4012BB40 = 1;
}

extern int D_4012BB44;
extern int D_4012BB48;

void mcGetCompleteTimeAttack(int *arg0, int *arg1)
{
    *arg0 = D_4012BB44;
    *arg1 = D_4012BB48;
}

void mcSetCompleteTimeAttack(int arg0, int arg1)
{
    if (arg0 != 0) {
        D_4012BB44 = 1;
    }
    if (arg1 != 0) {
        D_4012BB48 = 1;
    }
}
