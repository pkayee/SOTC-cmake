#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0229_SCRConditionUnderWaterByBoneForHorse", SCRConditionUnderWaterByBoneForHorse);

extern int getConnectPPointIdx(void *, int, int);
extern void *getSCRDataCtrlWork(void *);

int SCRConditionPPCheck(void *actor)
{
    void *temp_v0;

    temp_v0 = getSCRDataCtrlWork(actor);
    return getConnectPPointIdx(temp_v0, (*(int *)((char *)(temp_v0) + 0x3C70)), (*(int *)((char *)(temp_v0) + 0x3C6C))) >= 2;
}

extern int stagemanager_checkstageAlreadyLoadedByStrptr();

int SCRConditionSegmentLoad(int a, int b, int c, int d, int e, int f, int g, int h, int i)
{
    return stagemanager_checkstageAlreadyLoadedByStrptr(i);
}

extern int get_main_cameraman();
extern int is_playing_lws_movie_now_game_camera();

int SCRConditionLWSCameraPlay(void)
{
    return is_playing_lws_movie_now_game_camera(get_main_cameraman());
}

int SCRConditionEyeModeLapsedTime(void *actor, float fparg0)
{
    int var_v0;

    var_v0 = 1;
    if (!(fparg0 <= (*(float *)((char *)(getSCRDataCtrlWork(actor)) + 0x40E8)))) {
        var_v0 = 0;
    }
    return var_v0;
}

extern int *DldSysUndefSymbol;

static inline int *dldData(unsigned int *h)
{
    int off = *h & 0x3FFFF;
    int *t = off != 0 ? *(int **)((char *)h - off) : 0;

    return (t != 0 && t != DldSysUndefSymbol) ? (int *)t[4] : 0;
}

static inline char *dldResolve(unsigned int *h)
{
    unsigned int v = *h;
    int off = v & 0x3FFFF;
    int *t = off != 0 ? *(int **)((char *)h - off) : 0;

    return (t != 0 && t != DldSysUndefSymbol) ? (char *)t[4] + ((v >> 18) & 0xFFF) * ((int *)t[2])[3] : 0;
}

extern int CheckSCRCharaAIWorkPtr(void *);

int SCRConditionModeStatusByGameObj(void *a, int b, int c, int d, int e, int f, int g, int *h1, unsigned int *h2)
{
    int none;
    int *o = dldData((unsigned int *)h1);
    char *w;

    if (o == 0 || o[2] == 0)
        return 0;
    none = CheckSCRCharaAIWorkPtr((void *)o[2]) == 0;
    if (none)
        return 0;
    w = (char *)getSCRDataCtrlWork((void *)o[2]);
    return dldResolve(h2) == *(char **)(w + 0x407C);
}

extern int existSoundBow();

int SCRConditionExistSoundBow(int a, int b, int c, int d)
{
    return existSoundBow(a, b, c, d);
}

int SCRConditionModeStatusByMySelf(void *a, int b, int c, int d, int e, int f, int g, int i, unsigned int *h)
{
    char *w = getSCRDataCtrlWork(a);
    unsigned int v = *h;
    int off = v & 0x3FFFF;
    char *t = off != 0 ? *(char **)((char *)h - off) : 0;
    char *p = (t != 0 && t != (char *)DldSysUndefSymbol) ? *(char **)(t + 0x10) + ((v >> 18) & 0xFFF) * *(int *)(*(char **)(t + 8) + 0xC) : 0;
    return p == *(char **)(w + 0x407C);
}

int SCRConditionSpecifiedModeByMySelf(void *a, int b, int c, int d, int e, int f, int g, int i, unsigned int *h)
{
    char *w = getSCRDataCtrlWork(a);
    unsigned int v;
    int off;
    char *t;
    char *p;

    if (*(int *)(w + 0x4074) != 0) {
        v = *h;
        off = v & 0x3FFFF;
        t = off != 0 ? *(char **)((char *)h - off) : 0;
        p = (t != 0 && t != (char *)DldSysUndefSymbol) ? *(char **)(t + 0x10) + ((v >> 18) & 0xFFF) * *(int *)(*(char **)(t + 8) + 0xC) : 0;
        if (p == *(char **)(w + 0x4078))
            return 1;
    }
    return 0;
}

int SCRConditionModeShiftByMySelf(void *a, int b, int c, int d, int e, int f, int g, int i, unsigned int *h)
{
    char *w = getSCRDataCtrlWork(a);
    unsigned int v;
    int off;
    char *t;
    char *p;

    if (*(int *)(w + 0x4074) != 0) {
        v = *h;
        off = v & 0x3FFFF;
        t = off != 0 ? *(char **)((char *)h - off) : 0;
        p = (t != 0 && t != (char *)DldSysUndefSymbol) ? *(char **)(t + 0x10) + ((v >> 18) & 0xFFF) * *(int *)(*(char **)(t + 8) + 0xC) : 0;
        if (p == *(char **)(w + 0x407C))
            return 1;
    }
    return 0;
}

extern int _omakeSelectFlagChk();

int SCRConditionInvisibilityCloak(int a, int b, int c, int d)
{
    return _omakeSelectFlagChk(7, b, c, d);
}

extern int _omakeGetFlagChk();

int SCRConditionGetOmakeFlag(int a, int b, int c, int d)
{
    return _omakeGetFlagChk(b, b, c, d);
}

int SCRConditionTargetAttrOfInside(void *actor, int a, int b, int c, long mask, long value)
{
    return value == (*(long *)(getSCRDataCtrlWork(actor) + 0x4170) & mask);
}

extern int getGameClearCnt(void);

int SCRConditionCheckGameClearCnt(int a, int n)
{
    return getGameClearCnt() >= n;
}

extern int getGameHardMode();

int SCRConditionHardMode(int a, int b, int c, int d)
{
    return getGameHardMode(a, b, c, d);
}

extern s32 _gameWorkChk(s32 n);

s32 SCRConditionOverGameWork(void *actor, s32 index, s32 value)
{
    return _gameWorkChk(index) >= value;
}

extern int getArrowObjParent();

int SCRConditionArrowParentOverNum(int a, int n)
{
    return getArrowObjParent() >= n;
}

extern int *DldSysUndefSymbol;
extern void GetMotionNodeQuaternionPos(void *, void *, void *, int, int);
extern int CheckPositionInsideOfJudgeVolumeObject(void *, void *, void *, void *);

int SCRConditionVolumeCheckForBoneByGameObj(void *actor, int a1, int a2, int a3, int a4, int a5, int a6,
                                            unsigned int *h, unsigned int *vh, unsigned int *bone)
{
    char work[0x60];
    float q[4] __attribute__((aligned(16)));
    float pos[4] __attribute__((aligned(16)));
    int *o = dldData(h);
    void *vol;

    GetMotionNodeQuaternionPos(q, pos, actor, *(int *)(dldResolve(bone) + 8), 1);
    if (o != 0) {
        vol = (void *)o[2];
        if (vol != 0)
            return CheckPositionInsideOfJudgeVolumeObject(work, vol, vh, pos);
    }
    return 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0229_SCRConditionUnderWaterByBoneForHorse", SCRConditionAtkChackThreeRaySector);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0229_SCRConditionUnderWaterByBoneForHorse", SCRConditionAtkChackThreeRayParallel);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0229_SCRConditionUnderWaterByBoneForHorse", func_40125880);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0229_SCRConditionUnderWaterByBoneForHorse", func_401258C0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0229_SCRConditionUnderWaterByBoneForHorse", func_40125B18);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0229_SCRConditionUnderWaterByBoneForHorse", func_40125C48);
