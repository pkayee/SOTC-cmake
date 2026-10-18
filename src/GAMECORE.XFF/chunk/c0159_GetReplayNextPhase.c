#include "common.h"

extern int D_40131E64;

int GetReplayNextPhase(void)
{
    switch (D_40131E64) {
    case 8:
        return 1;
    case 9:
        return 2;
    case 11:
        return 3;
    case 13:
        return 4;
    }
    return 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0159_GetReplayNextPhase", ReplayGameOverScriptBegin);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0159_GetReplayNextPhase", func_400D5530);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0159_GetReplayNextPhase", func_400D55A8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0159_GetReplayNextPhase", func_400D5620);

typedef struct { char pad[0xC]; int flags; } TimeAttack;
extern TimeAttack g_TimeAttack;

void CloseTimeAttackMenu(int a)
{
    if (a == 1)
        g_TimeAttack.flags |= 0xFE;
    else
        g_TimeAttack.flags |= a;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0159_GetReplayNextPhase", func_400D56D8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0159_GetReplayNextPhase", func_400D57E0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0159_GetReplayNextPhase", func_400D58F0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0159_GetReplayNextPhase", func_400D59D0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0159_GetReplayNextPhase", func_400D5AC0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0159_GetReplayNextPhase", GetNumOmakeItem);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0159_GetReplayNextPhase", CheckSelectDisp);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0159_GetReplayNextPhase", func_400D5CD0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0159_GetReplayNextPhase", func_400D5D48);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0159_GetReplayNextPhase", func_400D5DC0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0159_GetReplayNextPhase", func_400D5E40);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0159_GetReplayNextPhase", func_400D5F48);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0159_GetReplayNextPhase", func_400D6028);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0159_GetReplayNextPhase", func_400D6118);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0159_GetReplayNextPhase", func_400D61E0);
