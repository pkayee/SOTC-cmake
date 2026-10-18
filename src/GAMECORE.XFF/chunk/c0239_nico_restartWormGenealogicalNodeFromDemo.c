#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0239_nico_restartWormGenealogicalNodeFromDemo", nico_restartWormGenealogicalNodeFromDemo);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0239_nico_restartWormGenealogicalNodeFromDemo", nico_calcWormGenealogicalNodeNext);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0239_nico_restartWormGenealogicalNodeFromDemo", nico_calcWormGenealogicalNodeTail);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0239_nico_restartWormGenealogicalNodeFromDemo", nico_calcWormGenealogicalNodeDownTail);

extern void nico_calcWormGenealogicalNodeDownNext();

void nico_calcWormGenealogicalNodeDownNextLast(void)
{
    nico_calcWormGenealogicalNodeDownNext();
}

char *getEventScriptClass(unsigned char *p)
{
    if (p[0x8] != 0x20) {
        return 0;
    }
    return (char *)p + 0x20;
}

extern int flushScriptObjImmediate();

int flushEventScriptObjImmediate(int a, int b, int c, int d)
{
    return flushScriptObjImmediate(a, b, c, d);
}

extern int flushScriptObj();

int flushEventScriptObj(int a, int b, int c, int d)
{
    return flushScriptObj(a, b, c, d);
}

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

extern int DldSysUndefSymbol;
extern void activeDemoStandby(char *);

void SCRFuncActiveDemoStandby(void *a, int b, int c, int d, int e, int g, unsigned int *h)
{
    unsigned int v = *h;
    int off = v & 0x3FFFF;
    char *t = off != 0 ? *(char **)((char *)h - off) : 0;
    activeDemoStandby((t != 0 && t != (char *)DldSysUndefSymbol) ? *(char **)(t + 0x10) + ((v >> 18) & 0xFFF) * *(int *)(*(char **)(t + 8) + 0xC) : 0);
}

extern void activeDemoCancel(char *);

void SCRFuncActiveDemoCancel(void *a, int b, int c, int d, int e, int g, unsigned int *h)
{
    unsigned int v = *h;
    int off = v & 0x3FFFF;
    char *t = off != 0 ? *(char **)((char *)h - off) : 0;
    activeDemoCancel((t != 0 && t != (char *)DldSysUndefSymbol) ? *(char **)(t + 0x10) + ((v >> 18) & 0xFFF) * *(int *)(*(char **)(t + 8) + 0xC) : 0);
}

extern int DldSysUndefSymbol;
extern void activeDemoStart(char *);

void SCRFuncActiveDemoStart(void *a, int b, int c, int d, int e, int g, unsigned int *h)
{
    unsigned int v = *h;
    int off = v & 0x3FFFF;
    char *t = off != 0 ? *(char **)((char *)h - off) : 0;
    activeDemoStart((t != 0 && t != (char *)DldSysUndefSymbol) ? *(char **)(t + 0x10) + ((v >> 18) & 0xFFF) * *(int *)(*(char **)(t + 8) + 0xC) : 0);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0239_nico_restartWormGenealogicalNodeFromDemo", SCRFuncSoundPlay);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0239_nico_restartWormGenealogicalNodeFromDemo", func_40130070);

extern int bgmScriptRecvSoundSignal();

int SCRConditionSoundSignal(int a, int b, int c, int d)
{
    return bgmScriptRecvSoundSignal(b, b, c, d);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0239_nico_restartWormGenealogicalNodeFromDemo", SCRSoundConditionPlayerParentColAttr);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0239_nico_restartWormGenealogicalNodeFromDemo", SCREventConditionPlayerRidingHorse);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0239_nico_restartWormGenealogicalNodeFromDemo", SCREventConditionOverDistanceToPlayerWorldXZ);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0239_nico_restartWormGenealogicalNodeFromDemo", SCREventConditionLessDistanceToPlayerWorldXZ);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0239_nico_restartWormGenealogicalNodeFromDemo", getSScriptWork);

extern int scrRunM();

int initSScriptSystem(int a, int b, int c, int d)
{
    return scrRunM(1, b, c, d);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0239_nico_restartWormGenealogicalNodeFromDemo", updateSScriptSystem);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0239_nico_restartWormGenealogicalNodeFromDemo", difftime);
