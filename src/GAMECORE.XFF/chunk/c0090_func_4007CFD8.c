#include "common.h"

extern s32 D_40131960;
extern s32 D_40131964;

extern void scrRunM(s32);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0090_func_4007CFD8", func_4007CFD8);

typedef struct { s32 a, b, c, d, e, f, g, h, i, j, k, l, m, n, o; } MParam;
extern s32 ScriptLayoutObjDef_MISSILE_TYPE1;
extern u8 gcGlobalVar[];
extern u8 rootPtn[];
extern void *initScriptLayoutObj(void *, s32, MParam *, s32, s32, void *, s32);
extern void isysAddGroupWithLinkParam(void *, void *, s32, s32);
extern void *isysGetThisSubThread(void);
extern int iosCreatePartition(void *, int);
extern char *GetScriptLayoutClass(void *);
extern void SetScriptLayoutObjLetterProcMode(void *, int);
extern char *_SCRMallocAlign(int, int, int);
extern void isysJumpSubThread(void (*)(void), void *);
extern void func_4007CFD8(void);

void SCRSetupMissile1(void *a, s32 b, s32 c, s32 d)
{
    MParam s;
    void *o;
    s.a = 0;
    s.b = b;
    s.c = c;
    s.d = 0;
    s.i = 0;
    s.e = 0;
    s.f = 0;
    s.g = 0;
    s.h = 1;
    s.j = 0;
    s.k = 0;
    s.l = 1;
    s.m = 0;
    s.n = 0;
    s.o = 0;
    o = initScriptLayoutObj(rootPtn, ScriptLayoutObjDef_MISSILE_TYPE1, &s, d, 4, a, 0);
    if (o != 0)
    {
        isysAddGroupWithLinkParam(o, gcGlobalVar + 0x280, 0, 0);
    }
}

s32 func_4007D210(s32 a) {
    if (D_40131960 == a || D_40131964 == a) {
        return 0;
    }
    return 1;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0090_func_4007CFD8", func_4007D240);
u64 *GetCollisionDBAttributeAdr(void *surface);

s32 func_4007D240(void *surface)
{
    u64 attribute = *GetCollisionDBAttributeAdr(surface);
    u64 flags = attribute & (0xF800UL << 20);
    u64 material = attribute & 0x7C000000UL;
    u64 mode = attribute & (0xF000UL << 30);

    if (material == 0x04000000UL || material == 0x64000000UL || material == 0x68000000UL ||
        material == 0x6C000000UL)
    {
        return 0;
    }
    if (material == 0x24000000UL || flags == (0x8000UL << 18) || flags == (0xB800UL << 20) ||
        flags == (0xC000UL << 18) || flags == (0xA000UL << 19) || flags == (0xE000UL << 18) ||
        flags == (0xA000UL << 18) || flags == (0x8000UL << 17) || mode == (0x8000UL << 28))
    {
        return 0;
    }
    return 1;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0090_func_4007CFD8", func_4007D330);
s32 arrowFilter(void *surface);

s32 func_4007D330(void *surface)
{
    if (arrowFilter(surface) != 0)
    {
        if ((s32)(*GetCollisionDBAttributeAdr(surface) & 1) == 0)
        {
            return 1;
        }
        return 0;
    }
    return 0;
}

void func_4007D378(void) {
    u8 *g;
    float t;
    isysGetThisSubThread();
    g = gcGlobalVar;
    t = 0.0f;
    do {
        t += *(float *)(g + 0x180);
        scrRunM(1);
    } while (t < 5.0f);
}

void nico_missile1start(int arg)
{
    void *th = isysGetThisSubThread();
    int part = iosCreatePartition(rootPtn, 0x53);
    char *c;
    char *w;

    *(int *)(GetScriptLayoutClass(th) + 0x2D4) = part;
    SetScriptLayoutObjLetterProcMode(th, 1);
    c = GetScriptLayoutClass(th);
    w = _SCRMallocAlign(part, 0x20, 0x10);
    *(char **)(c + 0x2D8) = w;
    *(int *)(w + 0x10) = arg;
    isysJumpSubThread(func_4007CFD8, w);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0090_func_4007CFD8", CalcFootVec);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0090_func_4007CFD8", CalcFootPos);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0090_func_4007CFD8", CalcDistancePointAnd2Point);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0090_func_4007CFD8", CalcDistancePointAndLine);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0090_func_4007CFD8", MVHIST_Init);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0090_func_4007CFD8", MVHIST_Update);

void DirectTurn_Reset(char *p)
{
    *(char *)(p + 0x14) = 0;
    *(int *)(p + 0x10) = 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0090_func_4007CFD8", IsTouchableObj);

extern s32 SCRGetSizeOfBossWork(void *thread);
extern u8 *GetScriptCharacterClass(void *thread);
extern void CharaCtrlResetCtrlStatus(void *chara);
extern void CharaCtrlResetAllScriptCtrlStatus(void *chara);
extern void *SCRCharaInitBossWork(void *ptn, void *thread);
extern void SCRReleaseBossWork(void);
extern void SetScriptCharacterObjReleaseCallBackFunc(void *chara, void *func, void *arg);
extern void *GetScriptClass(void *chara);
extern void initScriptDataSystem(void *chara, void *data);
extern void setRealColJudgeFunc(void *obj, void (*func)(void));
extern void setRotColCheckWormCtrlWork(void *obj, s32 flag);
extern void *getWormIKWork(void *thread);
extern void func_4007E050(void);
extern void nico_nargaBossAIMain(void);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0090_func_4007CFD8", nico_nargaBossStart);
void nico_nargaBossStart(void)
{
    void *thread = isysGetThisSubThread();
    s32 size = SCRGetSizeOfBossWork(thread);
    void *part = iosCreatePartition(&rootPtn, size + 0x5A93);
    u8 *cls = GetScriptCharacterClass(thread);
    void *mem;
    void *boss;

    *(void **)(cls + 0x114C) = part;
    CharaCtrlResetCtrlStatus(thread);
    CharaCtrlResetAllScriptCtrlStatus(thread);
    cls = GetScriptCharacterClass(thread);
    mem = _SCRMallocAlign(part, 0x5A60, 0x10);
    *(void **)(cls + 0x1150) = mem;
    boss = SCRCharaInitBossWork(part, thread);
    *(void **)mem = boss;
    SetScriptCharacterObjReleaseCallBackFunc(thread, SCRReleaseBossWork, boss);
    CharaCtrlResetCtrlStatus(thread);
    *(u64 *)((u8 *)mem + 0x5A58) = 0;
    cls = GetScriptClass(thread);
    initScriptDataSystem(thread, *(void **)(cls + 0x48));
    setRealColJudgeFunc((u8 *)mem + 0x10, func_4007E050);
    setRotColCheckWormCtrlWork((u8 *)mem + 0x3D00, 1);
    getWormIKWork(thread);
    isysJumpSubThread(nico_nargaBossAIMain, mem);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0090_func_4007CFD8", SCRConditionNaragaBodyRot);
