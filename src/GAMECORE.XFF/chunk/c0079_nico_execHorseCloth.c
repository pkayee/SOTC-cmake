#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0079_nico_execHorseCloth", nico_execHorseCloth);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0079_nico_execHorseCloth", nico_setHorseBridleType);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0079_nico_execHorseCloth", nico_setHorseBridleTerminalParentPoint);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0079_nico_execHorseCloth", nico_setHorseBridleTerminalParentPointIndep);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0079_nico_execHorseCloth", nico_execHorseBriddle);

extern void nico_resetHorseBridleTerminalParentPoint();

void nico_initHorseBriddle(void)
{
    nico_resetHorseBridleTerminalParentPoint();
}

extern void *GetLayoutClass(int);
extern int isysGetThisSubThread();
extern void isysJumpSubThread(void (*entry)(int arg), int arg);
extern void nico_setHorseBridleObjToHorseWork(int, int);
extern void st_collisionalias(int arg);

void st_nico_horseBridle(int arg0)
{
    int temp_v0;

    temp_v0 = isysGetThisSubThread();
    nico_setHorseBridleObjToHorseWork((*(int *)((char *)(GetLayoutClass(temp_v0)) + 0x194)), temp_v0);
    isysJumpSubThread(st_collisionalias, arg0);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0079_nico_execHorseCloth", drawbar);
