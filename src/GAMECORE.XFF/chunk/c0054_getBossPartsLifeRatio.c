#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0054_getBossPartsLifeRatio", getBossPartsLifeRatio);

extern u8 D_40202F80[];
void MotSpdCtrl_SetSpeed(void *, s32);

void SCRSetCharaMotionPlaySpeedRatio(s32 arg0)
{
    MotSpdCtrl_SetSpeed(D_40202F80, arg0);
}

void bosslifebar_sethp(f32);
void effect_blood_free(void *);
void end_weakpoint_effect();
void isysRequestDeleteObj(void *);
void BossSprStatusEnd();

void SCRReleaseBossWork(char *work)
{
    s32 i;
    s32 j;

    bosslifebar_sethp(0.0f);
    if (*(void **)(work + 0x50) != NULL)
    {
        effect_blood_free(*(void **)(work + 0x50));
        *(void **)(work + 0x50) = NULL;
    }
    end_weakpoint_effect();
    for (i = 0; i < *(s32 *)(work + 8); i++)
    {
        void *object = (void *)((s32 *)*(s32 *)(work + 0x5C))[i];
        if (object != NULL)
        {
            isysRequestDeleteObj(object);
        }
    }
    for (j = 0; j < *(s32 *)(work + 8); j++)
    {
        ((s32 *)*(s32 *)(work + 0x5C))[j] = 0;
    }
    BossSprStatusEnd();
}

void GetGeometryPointerSurfaceAttribute();
u8 *GetDamageClass();

u64 SCRGetBossCollisionAttribute(s32 a0)
{
    u64 attr[2];

    GetGeometryPointerSurfaceAttribute(attr, GetDamageClass(a0) + 0x10);
    return attr[0];
}

f32 SCRGetBossPartsDamage(void *context, s32 part_id)
{
    char *part;
    s32 count;
    s32 offset;
    s32 index;

    count = *(s32 *)((char *)context + 0x54);
    index = 0;
    if (count > 0)
    {
        part = *(char **)((char *)context + 0x10);
        offset = 0x20;
        do
        {
            s32 id = *(s32 *)part;
            part += 0x58;
            if (part_id == id)
            {
                return *(f32 *)((*(s32 *)((char *)context + 0xE8) + offset) + 4);
            }
            index++;
            offset += 8;
        } while (index < count);
    }
    return -1.0f;
}

typedef struct {
    char pad0[0x28];
    s64 key;
    char pad30[0x14];
    u32 h;
    char pad48[0x10];
} TexEnt;

typedef struct {
    char pad0[0x10];
    TexEnt *ents;
    char pad14[0x40];
    s32 n;
} BossTex;

typedef struct {
    BossTex *tex;
} AIWork;

extern u8 gcGlobalVar[];
extern s32 DldSysUndefSymbol;
void *SCRGetFirstObj(void *p);
AIWork *GetSCRCharaAIWorkPtr(void *p);

static inline s32 dldData(u32 *h)
{
    s32 off = *h & 0x3FFFF;
    s32 *t = off != 0 ? *(s32 **)((char *)h - off) : 0;

    return ((s32)t != 0 && (s32)t != DldSysUndefSymbol) ? t[4] : 0;
}

s32 chkBossWeakTexExist(s32 n)
{
    void *p;
    BossTex *w;
    s32 i;

    p = SCRGetFirstObj(gcGlobalVar + 0x2B8);
    if (p == NULL)
    {
        return 0;
    }
    w = GetSCRCharaAIWorkPtr(p)->tex;
    for (i = 0; i < w->n; i++)
    {
        if (w->ents[i].key == (s64)(n + 1) << 54)
        {
            return dldData(&w->ents[i].h) != 0;
        }
    }
    return 0;
}

s32 chkBossTrigTexExist(s32 n)
{
    void *p;
    BossTex *w;
    s32 i;
    s64 key;

    p = SCRGetFirstObj(gcGlobalVar + 0x2B8);
    key = ((s64)n + 0x1B) << 31;
    if (p == NULL)
    {
        return 0;
    }
    w = GetSCRCharaAIWorkPtr(p)->tex;
    for (i = 0; i < w->n; i++)
    {
        if (key == w->ents[i].key)
        {
            return dldData(&w->ents[i].h) != 0;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0054_getBossPartsLifeRatio", chkBossTrigTurnOff);

void *SCRGetBossWork(void *actor)
{
    return *(void **)GetSCRCharaAIWorkPtr(actor);
}

s32 SCRGetBossTypeDef(void *actor)
{
    s32 *b = *(s32 **)GetSCRCharaAIWorkPtr(actor);

    if (b == NULL)
    {
        return 0;
    }
    return *b;
}

s32 SCRGetBossPartsDamageNum(void *actor)
{
    return *(s32 *)((char *)*(void **)GetSCRCharaAIWorkPtr(actor) + 0x54);
}

void *SCRGetBossPartsDamageFromIndex(void *actor, s32 index)
{
    char *boss = *(char **)GetSCRCharaAIWorkPtr(actor);

    return *(char **)(boss + 0x10) + index * 0x58;
}

typedef struct {
    s32 attr;
    char pad04[0x54];
} BossParts;

BossParts *SCRGetBossPartsDamageFromColAttr(s32 attr, void *a)
{
    char *boss = *(char **)GetSCRCharaAIWorkPtr(a);
    s32 n = *(s32 *)(boss + 0x54);
    BossParts *ret = NULL;
    s32 i;

    attr &= 0x3F0;
    for (i = 0; i < n; i++)
    {
        if (attr == (*(BossParts **)(boss + 0x10))[i].attr)
        {
            ret = &(*(BossParts **)(boss + 0x10))[i];
            break;
        }
    }
    return ret;
}

char *SCRGetBackStageBossPartsDamageFromColAttr(s32 attr, void *a)
{
    char *boss = *(char **)GetSCRCharaAIWorkPtr(a);
    s32 n = *(s32 *)(boss + 0x54);
    char *ret = NULL;
    s32 i;

    attr &= 0x3F0;
    for (i = 0; i < n; i++)
    {
        if (attr == (*(BossParts **)(boss + 0x10))[i].attr)
        {
            ret = *(char **)(boss + 0xE8) + i * 8 + 0x24;
            break;
        }
    }
    return ret;
}

s32 SCRGetBossWeakPointIndexFromColAttr(s64 weak, void *a)
{
    char *tbl = *(char **)GetSCRCharaAIWorkPtr(a);
    s32 n = *(s32 *)(tbl + 0x54);
    s32 ret = -1;
    s32 i;

    for (i = 0; i < n; i++)
    {
        if (weak == *(s64 *)(*(char **)(tbl + 0x10) + i * 0x58 + 0x28))
        {
            ret = i;
            break;
        }
    }
    return ret;
}

f32 SCRGetBossWeakPointAngleFromIndex(void *actor, s32 index)
{
    void *boss;
    char *points;

    boss = *(void **)GetSCRCharaAIWorkPtr(actor);
    points = *(char **)((char *)boss + 0x10);
    return *(f32 *)(points + index * 0x58 + 0x30);
}

f32 getBossPartsCurDamage(void *o, s32 key)
{
    char *w = *(char **)GetSCRCharaAIWorkPtr(o);
    char *d = NULL;
    s32 i;

    key &= 0x3F0;
    for (i = 0; i < *(s32 *)(w + 0x54); i++)
    {
        if (key == (*(BossParts **)(w + 0x10))[i].attr)
        {
            d = *(char **)(w + 0xE8) + i * 8 + 0x24;
            break;
        }
    }
    if (d != NULL)
    {
        return *(f32 *)(d + 4);
    }
    return 0.0f;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0054_getBossPartsLifeRatio", IsBossDeathNextAttack);

void SCRExecBossPostProcess(void) {
}

f32 GetBossPartsDamage(void *arg0, s32 arg1)
{
    return (*(f32 *)((char *)(arg1 * 0x58 + *(s32 *)((char *)arg0 + 0x10)) + 0x1C) - *(f32 *)((char *)(arg1 * 8 + *(s32 *)((char *)arg0 + 0xE8)) + 0x24)) / *(f32 *)((char *)arg0 + 0x68);
}

f32 GetBossPartsDamagePerParts(void *arg0, s32 arg1)
{
    f32 temp_f1;

    temp_f1 = *(f32 *)((char *)(arg1 * 0x58 + *(s32 *)((char *)arg0 + 0x10)) + 0x1C);
    return (temp_f1 - *(f32 *)((char *)(arg1 * 8 + *(s32 *)((char *)arg0 + 0xE8)) + 0x24)) / temp_f1;
}

void scrRun(void);

void nico_boxtest(void)
{
    for (;;)
    {
        scrRun();
    }
}

extern s32 rootPtn;
void *isysGetThisSubThread(void);
void *iosCreatePartition(void *parent, s32 size);
u8 *GetScriptCharacterClass(void *thread);
void CharaCtrlResetCtrlStatus(void *chara);
void CharaCtrlResetAllScriptCtrlStatus(void *chara);
void *_SCRMallocAlign(void *ptn, s32 size, s32 align);
void isysJumpSubThread(void *func, void *arg);
s32 SCRGetSizeOfBossWork(void *thread);
void *SCRCharaInitBossWork(void *ptn, void *thread);
void SetScriptCharacterObjReleaseCallBackFunc(void *chara, void *func, void *arg);
void *GetScriptClass(void *chara);
void initScriptDataSystem(void *chara, void *data);
s32 getEditWorkInitData(s32 a);
void func_40052B70(void);

void nico_buddhaStart(void)
{
    void *thread = isysGetThisSubThread();
    s32 size = SCRGetSizeOfBossWork(thread);
    void *part = iosCreatePartition(&rootPtn, size + 0x41E3);
    u8 *cls = GetScriptCharacterClass(thread);
    u8 *mem;
    void *boss;

    *(void **)(cls + 0x114C) = part;
    CharaCtrlResetCtrlStatus(thread);
    CharaCtrlResetAllScriptCtrlStatus(thread);
    cls = GetScriptCharacterClass(thread);
    mem = _SCRMallocAlign(part, 0x41B0, 0x10);
    *(void **)(cls + 0x1150) = mem;
    boss = SCRCharaInitBossWork(part, thread);
    *(void **)mem = boss;
    SetScriptCharacterObjReleaseCallBackFunc(thread, SCRReleaseBossWork, boss);
    *(s32 *)(mem + 0x4190) = getEditWorkInitData(*(s32 *)((u8 *)GetScriptClass(thread) + 0x40));
    CharaCtrlResetCtrlStatus(thread);
    initScriptDataSystem(thread, *(void **)((u8 *)GetScriptClass(thread) + 0x48));
    *(s32 *)(mem + 0x4194) = 0;
    *(s32 *)(mem + 0x4198) = 0;
    *(s32 *)(mem + 0x41A4) = 2;
    *(s32 *)(mem + 0x419C) = 0;
    *(s32 *)(mem + 0x41A0) = 0;
    *(s32 *)(mem + 0x41A8) = 0;
    isysJumpSubThread(func_40052B70, mem);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0054_getBossPartsLifeRatio", func_40052B70);

void RequestCharacterMotionShiftFunc(void *character, void (*func)(void *character));
void func_40052F78(void *character);

void SCRBuddhaShoot(void *character)
{
    RequestCharacterMotionShiftFunc(character, func_40052F78);
}

extern f32 D_401333EC;

void SCRFuncBuddhaMissileInit(void *actor)
{
    *(f32 *)((char *)GetSCRCharaAIWorkPtr(actor) + 0x4194) = D_401333EC;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0054_getBossPartsLifeRatio", SCRFuncBuddhaMissileMain);
extern const f32 D_401333F0;

void SCRFuncBuddhaMissileInit2(void *actor)
{
    char *w = (char *)GetSCRCharaAIWorkPtr(actor);
    *(int *)(w + 0x419C) = 1;
    *(float *)(w + 0x4194) = D_401333F0;
    *(int *)(w + 0x4198) = 0;
    *(int *)(w + 0x41A0) = 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0054_getBossPartsLifeRatio", SCRFuncBuddhaMissileMain2);
