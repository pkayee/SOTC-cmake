#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0091_func_4007DF08", func_4007DF08);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0091_func_4007DF08", func_4007E050);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0091_func_4007DF08", nico_nargaBossAIMain);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0091_func_4007DF08", SCRFuncNargaWallCheckMain);

extern void *GetSCRCharaAIWorkPtr(void *);

int SCRConditionNargaWallCheck(void *actor, int wall)
{
    return wall == *(int *)((char *)GetSCRCharaAIWorkPtr(actor) + 0x5A50);
}

extern void *getSCRDataCtrlWork(void *);
extern void setAttainmentPos(void *, void *);

void SCRFuncNargaSetWallAttainPos(void *a)
{
    char *l = GetSCRCharaAIWorkPtr(a);
    void *s = getSCRDataCtrlWork(a);
    setAttainmentPos(s, l + 0x5A40);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0091_func_4007DF08", SCRFuncNargaFloatMain);

void SCRFuncNargaSetPlayerDamage(int a, int b)
{
    *(int *)((char *)GetSCRCharaAIWorkPtr(a) + 0x5A54) = b;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0091_func_4007DF08", SCRFuncNargaSetPlayerAttainmentPos);

int SCRConditionNargaPlayerDamage(void *actor)
{
    return (*(int *)((char *)(GetSCRCharaAIWorkPtr(actor)) + 0x5A54)) != 0;
}

extern int DldSysUndefSymbol;
extern char *GetLayoutClass(void *);
extern void CheckCollisionInsideOfSurfaceXZ(void *, void *, void *);

void SCRFuncNargaWayVolumeMain(void *a, int b, int c, int d, int e, int *h)
{
    char *ai = GetSCRCharaAIWorkPtr(a);
    int off = *h & 0x3FFFF;
    int *t = off != 0 ? *(int **)((char *)h - off) : 0;
    int *o = (t != 0 && t != (int *)DldSysUndefSymbol) ? (int *)t[4] : 0;
    void *g;

    if (o != 0 && (g = (void *)o[2]) != 0)
        CheckCollisionInsideOfSurfaceXZ(ai + 0x5A58, g, *(void **)(GetLayoutClass(a) + 0x134));
}

int SCRConditionNargaWallNear(void *actor, int a, int b, int c, long mask, long value)
{
    return value == (*(long *)(GetSCRCharaAIWorkPtr(actor) + 0x5A58) & mask);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0091_func_4007DF08", constructor_nico_sight_on);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0091_func_4007DF08", func_4007E990);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0091_func_4007DF08", func_4007EB30);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0091_func_4007DF08", func_4007EE38);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0091_func_4007DF08", func_4007F180);
