#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0239_nico_restartWormGenealogicalNodeFromDemo", nico_restartWormGenealogicalNodeFromDemo);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0239_nico_restartWormGenealogicalNodeFromDemo", nico_calcWormGenealogicalNodeNext);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0239_nico_restartWormGenealogicalNodeFromDemo", nico_calcWormGenealogicalNodeTail);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0239_nico_restartWormGenealogicalNodeFromDemo", nico_calcWormGenealogicalNodeDownTail);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0239_nico_restartWormGenealogicalNodeFromDemo", nico_calcWormGenealogicalNodeDownNextLast);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0239_nico_restartWormGenealogicalNodeFromDemo", getEventScriptClass);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0239_nico_restartWormGenealogicalNodeFromDemo", flushEventScriptObjImmediate);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0239_nico_restartWormGenealogicalNodeFromDemo", flushEventScriptObj);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0239_nico_restartWormGenealogicalNodeFromDemo", initEventScriptObj);

extern s32 D_40132460[];
s32 GetScriptObjWorkSize();

s64 getEventScriptObjWorkSize(s32 *a0)
{
    D_40132460[4] = *a0;
    return GetScriptObjWorkSize(D_40132460);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0239_nico_restartWormGenealogicalNodeFromDemo", createEventScriptObj);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0239_nico_restartWormGenealogicalNodeFromDemo", func_4012FE60);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0239_nico_restartWormGenealogicalNodeFromDemo", func_4012FE78);

void SCRFuncSoundSetDepth(void) {
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0239_nico_restartWormGenealogicalNodeFromDemo", SCRFuncActiveDemoStandby);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0239_nico_restartWormGenealogicalNodeFromDemo", SCRFuncActiveDemoCancel);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0239_nico_restartWormGenealogicalNodeFromDemo", SCRFuncActiveDemoStart);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0239_nico_restartWormGenealogicalNodeFromDemo", SCRFuncSoundPlay);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0239_nico_restartWormGenealogicalNodeFromDemo", func_40130070);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0239_nico_restartWormGenealogicalNodeFromDemo", SCRConditionSoundSignal);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0239_nico_restartWormGenealogicalNodeFromDemo", SCRSoundConditionPlayerParentColAttr);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0239_nico_restartWormGenealogicalNodeFromDemo", SCREventConditionPlayerRidingHorse);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0239_nico_restartWormGenealogicalNodeFromDemo", SCREventConditionOverDistanceToPlayerWorldXZ);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0239_nico_restartWormGenealogicalNodeFromDemo", SCREventConditionLessDistanceToPlayerWorldXZ);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0239_nico_restartWormGenealogicalNodeFromDemo", getSScriptWork);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0239_nico_restartWormGenealogicalNodeFromDemo", initSScriptSystem);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0239_nico_restartWormGenealogicalNodeFromDemo", updateSScriptSystem);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0239_nico_restartWormGenealogicalNodeFromDemo", difftime);
