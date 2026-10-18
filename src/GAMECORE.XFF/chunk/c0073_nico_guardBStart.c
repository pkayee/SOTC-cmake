#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0073_nico_guardBStart", nico_guardBStart);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0073_nico_guardBStart", nico_guardDStart);

extern void RequestCharacterMotionShiftFunc(void *character, void (*func)(void *character));

extern void func_40068A50(void *character);

void SCRGuardArrowShoot(void *character)
{
    RequestCharacterMotionShiftFunc(character, func_40068A50);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0073_nico_guardBStart", func_40068940);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0073_nico_guardBStart", func_40068A50);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0073_nico_guardBStart", r1_alert);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0073_nico_guardBStart", checkpoint_alert);

extern void *isysGetThisSubThread(void);

extern void scrRun(void);

extern void scrInit(void *thread);

void home_test_anim(void)
{
    scrInit(isysGetThisSubThread());
    for (;;) {
        scrRun();
    }
}

extern void scrRunM(int);

extern void iosDebugPrintHashTable(void *);

extern char rootPtn[];

void st_malloc_test(void)
{
    scrInit(isysGetThisSubThread());
    for (;;) {
        scrRunM(0xB4);
        iosDebugPrintHashTable(rootPtn);
    }
}

extern int SeList_st03_air_0;

extern int SeList_st03_wind1_0;

extern int sePlayStageEnv(int, int, int);

void home_sound(void)
{
    scrInit(isysGetThisSubThread());
    sePlayStageEnv(SeList_st03_air_0, 0, 0);
    sePlayStageEnv(SeList_st03_wind1_0, 0, 0);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0073_nico_guardBStart", func_40068E50);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0073_nico_guardBStart", nico_horseRStart);
