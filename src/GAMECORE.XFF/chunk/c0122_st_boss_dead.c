#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0122_st_boss_dead", st_boss_dead);

extern s32 D_40131BD8;

s32 getBossCloudObj(void)
{
    return D_40131BD8;
}

extern s32 D_40131BD4;

void bossCloudStart(void)
{
    D_40131BD4 = 1;
}

void YattsukeGetSeamlessAreaCenter(f32 *center, s32 area)
{
    s32 x = (area % 10) * 600 - 2700;

    center[0] = -x;
    center[1] = 0.0f;
    center[2] = (area / 10) * 600 - 2700;
    center[3] = 1.0f;
}

extern s32 D_40131BD0;
extern void *isysGetThisSubThread(void);
extern u8 *bossStatGetActiveBoss(void);
extern s32 bossStatBootChk(void);
extern u8 *gStatGetGObjAdrs(s32);
extern void scrRun(void);

void rootscripttest(void)
{
    u8 *b;

    isysGetThisSubThread();
    for (;;)
    {
        b = bossStatGetActiveBoss();
        if (b != NULL && D_40131BD0 != 0 && bossStatBootChk() >= 0 && *(s32 *)(gStatGetGObjAdrs(*(s32 *)(b + 0xBC)) + 8) != 0)
        {
            D_40131BD0 = 0;
        }
        scrRun();
    }
}

extern s32 D_40131BDC;

void bossDemoPlayerBreakDownAccept(void)
{
    D_40131BDC = 1;
}

void bossDemoPlayerBreakDownEnd(void)
{
    D_40131BDC = 2;
}

extern void scrInit(void *);
extern void scriptIntrAllDeleteJump(void *);
extern void scriptIntrEntryJump(s32, void *, void *);
extern s32 ScrIntrDef_DEAD_BOSS;
extern u8 D_40131BE0[];

void st_boss_status(void)
{
    void *temp_v0;

    temp_v0 = isysGetThisSubThread();
    scrInit(temp_v0);
    scriptIntrAllDeleteJump(temp_v0);
    scriptIntrEntryJump(ScrIntrDef_DEAD_BOSS, temp_v0, D_40131BE0);
    while (1)
    {
        scrRun();
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0122_st_boss_dead", func_400A6110);
