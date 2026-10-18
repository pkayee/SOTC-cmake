#include "common.h"

extern char gcGlobalVar[];
extern int SCRGetFirstObj();
extern void *GetCharacterClass(void *);
extern int GetSCRCharaAIWorkPtr();
extern int initInterestWork();
extern int updateInterestWork(void *, void *, int);

int SCRConditionHorseRiddenOn(int arg0)
{
    return arg0 != (*(int *)((char *)(GetCharacterClass((void *)arg0)) + 0x950));
}

int SCRFuncHorseInterestInit(int a)
{
    return initInterestWork(a, GetSCRCharaAIWorkPtr(a) + 16784);
}

int SCRFuncHorseInterestMain(void *actor, int a, int b, int c, int d, int e)
{
    return updateInterestWork(actor, GetSCRCharaAIWorkPtr(actor) + 0x4190, e);
}

extern int getInterestExec();

int SCRConditionHorseInterestExec(void *actor)
{
    return getInterestExec(((char *)GetSCRCharaAIWorkPtr(actor)) + 0x4190);
}

extern void *getSCRDataCtrlWork(void *);
extern int IsHorseCalled_withFlgOff(void *);

int SCRConditionHorseCalled(void *actor)
{
    return IsHorseCalled_withFlgOff(*(void **)(((char *)getSCRDataCtrlWork(actor)) + 0x4058));
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0077_SCRConditionHorseRiddenOn", SCRFuncHorseBossCircumferenceMain);

float getHorseInterpSpeed(void *actor)
{
    return (*(float *)((char *)(GetSCRCharaAIWorkPtr(actor)) + 0x3DD0));
}

extern void setWallStopHorseCtrlWork(void *, int);

void setHorseSemiAutomaticCtrl(void *actor, int on)
{
    char *w = (char *)GetSCRCharaAIWorkPtr(actor);
    *(int *)(w + 0x41D4) = on;
    if (on != 0)
        setWallStopHorseCtrlWork(w + 0x3D00, 0);
    else
        setWallStopHorseCtrlWork(w + 0x3D00, 1);
}

extern int DldSysUndefSymbol;

void SCRFuncHorseForceScriptKey(void *a, int b, int c, int d, int e, int f, int g, int i, unsigned int *h)
{
    char *ai = (char *)GetSCRCharaAIWorkPtr(a);
    unsigned int v = *h;
    int off = v & 0x3FFFF;
    char *t = off != 0 ? *(char **)((char *)h - off) : 0;
    char *p = (t != 0 && t != (char *)DldSysUndefSymbol) ? *(char **)(t + 0x10) + ((v >> 18) & 0xFFF) * *(int *)(*(char **)(t + 8) + 0xC) : 0;
    if (p != 0)
        *(long *)(ai + 0x41e8) |= 1L << *(int *)(p + 4);
}

void SCRFuncHorseAdvertisFlag(int a, int b)
{
    *(int *)(GetSCRCharaAIWorkPtr(a) + 0x41e4) = b;
}

int SCRConditionOverHorseLife(void *actor, float fparg0)
{
    int var_v0;

    var_v0 = 1;
    if (!(fparg0 <= (*(float *)((char *)(GetSCRCharaAIWorkPtr(actor)) + 0x4200)))) {
        var_v0 = 0;
    }
    return var_v0;
}

extern int nico_playerCheckNippingWithHorseAndWall(int);

int SCRConditionPlayerNippingHorseAndWall(void *actor)
{
    return nico_playerCheckNippingWithHorseAndWall((*(int *)((char *)(getSCRDataCtrlWork(actor)) + 0x4058))) != 0;
}

void SCRFuncHorseEscapeCounterInit(void *actor, float fparg0)
{
    (*(float *)((char *)(GetSCRCharaAIWorkPtr(actor)) + 0x4208)) = fparg0;
}

void SCRFuncHorseEscapeCounterMain(void *actor)
{
    float temp_f1;
    void *temp_v0;

    temp_v0 = (void *)GetSCRCharaAIWorkPtr(actor);
    temp_f1 = (*(float *)((char *)(temp_v0) + 0x4208));
    if (temp_f1 > 0.0f) {
        (*(float *)((char *)(temp_v0) + 0x4208)) = (float) (temp_f1 - (*(float *)((char *)(gcGlobalVar) + 0x180)));
    }
}

int SCRConditionHorseEscapeCounterChack(void *actor)
{
    char *w = GetSCRCharaAIWorkPtr(actor);
    int r = 1;
    if (!(0.0f < *(float *)(w + 0x4208)))
        r = 0;
    return r;
}

int SCRConditionHorseNeighPermission(void *arg0, float fparg0)
{
    return ((int) ((*(float *)((char *)(getSCRDataCtrlWork(arg0)) + 0x4084)) * 10.0f) % (int) (fparg0 * 10.0f)) == 0;
}

int SRCConditionHorseBossChackAll(void)
{
    return SCRGetFirstObj(gcGlobalVar + 0x2B8) != 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0077_SCRConditionHorseRiddenOn", SRCFuncHorseAngleFromPlayerToHorse);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0077_SCRConditionHorseRiddenOn", SRCConditionHorseAngleFromPlayerToHorse);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0077_SCRConditionHorseRiddenOn", SRCFuncHorseRayHitColAttr);

int SRCConditionHorseHitColAttrChack(void *actor, int a, int b, int c, long mask, long value)
{
    return value == (*(long *)(GetSCRCharaAIWorkPtr(actor) + 0x4218) & mask);
}

int SRCConditionHorseHitColChack(void *actor)
{
    return (*(long *)((char *)(GetSCRCharaAIWorkPtr(actor)) + 0x4218)) != 0;
}

void setHorseForceScriptKey(void *actor, int *key)
{
    char *w = (char *)GetSCRCharaAIWorkPtr(actor);
    if (key != 0)
        *(long *)(w + 0x41E8) |= 1L << key[1];
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0077_SCRConditionHorseRiddenOn", SCRFuncFromHorceToPlayerSendKey);
