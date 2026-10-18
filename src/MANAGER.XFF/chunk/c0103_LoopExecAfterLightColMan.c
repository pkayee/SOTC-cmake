#include "common.h"

extern char D_401AC8B0[];
extern void *D_4012B030;
extern int D_4012B034;

void iosSprToMemDmaAdrCopy(void *, int, void *);

void LoopExecAfterLightColMan(void)
{
    iosSprToMemDmaAdrCopy(D_401AC8B0, 0xBD, (void *)0x70000000);
    D_4012B030 = D_401AC8B0;
}

void TaskExecLightColMan(void)
{
    D_4012B030 = D_401AC8B0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0103_LoopExecAfterLightColMan", SetCameraReverbFlag);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0103_LoopExecAfterLightColMan", SetGeoDispClassLightColMan);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0103_LoopExecAfterLightColMan", getColLightDebugSts);

int *getColLightDebugSts(void)
{
    return &D_4012B034;
}

int GetColLightDebugSts(void)
{
    return D_4012B034;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0103_LoopExecAfterLightColMan", func_4008B298);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0103_LoopExecAfterLightColMan", DeleteGameLight);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0103_LoopExecAfterLightColMan", UpdateClipGameLight);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0103_LoopExecAfterLightColMan", func_4008B868);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0103_LoopExecAfterLightColMan", ExecGameLight);
