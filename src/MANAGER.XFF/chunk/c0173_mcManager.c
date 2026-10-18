#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0173_mcManager", mcManager);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0173_mcManager", mcWrite);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0173_mcManager", mcRead);

extern int D_401B1744;

void mcReqSetWaitFunc(int arg0)
{
    D_401B1744 = arg0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0173_mcManager", mcGetInfo);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0173_mcManager", mcGetMainDataInfo);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0173_mcManager", mcSaveGameData);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0173_mcManager", mcLoadGameData);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0173_mcManager", mcDeleteGameData);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0173_mcManager", mcLoadOptionData);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0173_mcManager", mcFormat);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0173_mcManager", mcUnformat);

extern float D_4012BB38;

float mcGetProcessPer(void)
{
    return D_4012BB38;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0173_mcManager", mcDirectFileCreate);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0173_mcManager", mcDirectFileDelete);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0173_mcManager", mcDirectFileWrite);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0173_mcManager", mcDirectFileRead);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0173_mcManager", mcReqGetDir);

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
