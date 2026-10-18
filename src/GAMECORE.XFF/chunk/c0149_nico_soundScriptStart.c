#include "common.h"

extern char rootPtn[];
extern int *iosMallocAlign(void *, int, int);
extern void initScriptSpriteObj(void *, int, int *, int, int, int);
extern void initScriptSpriteMenuObj(void *, int, int *, int, int, int);
extern void iosFree(void *);
extern void func_400C9BD8(void *obj, int arg);
extern void func_400C9970(void);
extern int D_40131C30, D_40131C34;
extern int D_40131C2C;
extern void *isysGetThisSubThread(void);
extern void scrInit(void *);
extern void initSScriptSystem(void *);
extern void initSmallManager(void);
extern void SetScriptObjDeleteCallBackFunc(void *, void (*func)(void *obj, int arg), int);
extern void scrRunM(int);
extern void isysJumpSubThread(void *, int);
extern void GetSpriteMenuClass(void *);
extern void scrRun(void);
extern int D_40131C38;

typedef struct
{
    char c[16];
} SpriteParam;

void nico_soundScriptStart(void)
{
    void *t = isysGetThisSubThread();
    scrInit(t);
    initSScriptSystem(t);
    initSmallManager();
    SetScriptObjDeleteCallBackFunc(t, func_400C9BD8, 0);
    scrRunM(1);
    D_40131C30 = 0;
    D_40131C34 = 0;
    isysJumpSubThread(func_400C9970, 0);
}

int getNowExecEventScriptObj(void)
{
    return D_40131C2C;
}

void setLoadingCheckFunc(int arg0, int arg1)
{
    D_40131C34 = arg0;
    D_40131C30 = arg1;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0149_nico_soundScriptStart", func_400C9BD8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0149_nico_soundScriptStart", spritedisplaytrigger);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0149_nico_soundScriptStart", spritedisplay);

void _SCRStartSpriteAnim(int def, int b, int c, int d, int e, int f)
{
    int *p = iosMallocAlign(rootPtn, 16, 16);

    p[3] = c;
    p[0] = d;
    p[1] = e;
    p[2] = f;
    initScriptSpriteObj(rootPtn, def, p, b, 9, 0);
}

void _SCRStartSpriteMenuAnim(int def, int b, int c, int d, int e, int f)
{
    int *p = iosMallocAlign(rootPtn, 16, 16);

    p[3] = c;
    p[0] = d;
    p[1] = e;
    p[2] = f;
    initScriptSpriteMenuObj(rootPtn, def, p, b, 9, 0);
}

void ScrSpriteParamSetup(SpriteParam *dst, SpriteParam *src)
{
    *dst = *src;
    iosFree(src);
}

typedef struct
{
    int *done;
    int a;
    int b;
    void (*cb)(void *);
} SpriteParamEnd;

void ScrSpriteParamEnd(SpriteParamEnd *p, void *arg)
{
    if (p->done != 0)
        *p->done = 1;
    if (p->cb != 0)
        p->cb(arg);
}

void spritemenudisplaytriggerpad_group(void)
{
    GetSpriteMenuClass(isysGetThisSubThread());
    D_40131C38++;
    for (;;)
        scrRun();
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0149_nico_soundScriptStart", func_400CA080);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0149_nico_soundScriptStart", func_400CA178);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0149_nico_soundScriptStart", setrollup);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0149_nico_soundScriptStart", func_400CA3D8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0149_nico_soundScriptStart", func_400CA9D8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0149_nico_soundScriptStart", func_400CAEB0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0149_nico_soundScriptStart", func_400CB1A8);
