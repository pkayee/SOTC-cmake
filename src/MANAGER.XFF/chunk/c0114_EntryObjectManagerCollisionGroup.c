#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0114_EntryObjectManagerCollisionGroup", EntryObjectManagerCollisionGroup);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0114_EntryObjectManagerCollisionGroup", EntryInterestGroup);

void deleteAmbientLightObj(void) {
}

extern unsigned char D_4012B0F0[];

void *getMemoryInfoMode(void)
{
    return D_4012B0F0;
}

extern unsigned char D_4012B0F4[];

void *getMemoryInfoLightSw(void)
{
    return D_4012B0F4;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0114_EntryObjectManagerCollisionGroup", objectmanager_mallocerrorfunc);

extern void *GetScriptLayoutClass(unsigned char *);
extern char *GetScriptCharacterClass(unsigned char *);
extern char *GetWindowClass(unsigned char *);
extern char *GetScriptAnimationClass(unsigned char *);
extern char *GetScriptSpriteClass(unsigned char *);
extern char *GetScriptSpriteMenuClass(unsigned char *);

void *GetScriptClass(unsigned char *object)
{
    switch (object[8]) {
    case 11: return GetScriptLayoutClass(object);
    case 9: return GetScriptCharacterClass(object);
    case 12: return GetWindowClass(object);
    case 13: return GetScriptAnimationClass(object);
    case 14: return GetScriptSpriteClass(object);
    case 33: return GetScriptSpriteMenuClass(object);
    case 6:
    case 22:
    case 29: return object + 0x20;
    case 32: return object + 0x1C;
    default: return 0;
    }
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0114_EntryObjectManagerCollisionGroup", initScriptObj);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0114_EntryObjectManagerCollisionGroup", func_400970C8);

extern int execScriptGroup[];
extern void isysInitGroup(int *);

void initScriptSystem(void)
{
    int i;
    int *g = execScriptGroup;
    for (i = 15; i >= 0; i--)
        isysInitGroup(g++);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0114_EntryObjectManagerCollisionGroup", createScriptObj);

extern void iosFree(void *);
extern void isysDeleteSubThread(int);

void flushScriptObj(int arg0)
{
    int temp_v0_2;
    void *temp_v0;

    temp_v0 = GetScriptClass((unsigned char *)arg0);
    temp_v0_2 = (*(int *)((char *)(temp_v0) + 0x34));
    if (temp_v0_2 != 0) {
        iosFree((void *)temp_v0_2);
    }
    if ((*(int *)((char *)(temp_v0) + 0)) != 0) {
        isysDeleteSubThread(arg0);
    }
}

extern void func_400970C8(int *);

void execScript(void)
{
    int i;
    int *g = execScriptGroup;
    for (i = 15; i >= 0; i--)
        func_400970C8(g++);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0114_EntryObjectManagerCollisionGroup", flushScriptObjImmediate);

extern int isysGetSubThreadWorkSize(int);

int GetScriptObjWorkSize(int *p)
{
    return isysGetSubThreadWorkSize(p[2]);
}

void SetScriptObjDeleteCallBackFunc(void *actor, int func, int arg)
{
    char *s = GetScriptClass(actor);
    *(int *)(s + 0x54) = func;
    *(int *)(s + 0x58) = arg;
}

void SetScriptObjDeleteCallBackFunc2(void *actor, int func, int arg)
{
    char *s = GetScriptClass(actor);
    *(int *)(s + 0x5C) = func;
    *(int *)(s + 0x60) = arg;
}

void SetScriptObjFinishCallBackFunc(void *actor, int func, int arg)
{
    char *s = GetScriptClass(actor);
    *(int *)(s + 0x4C) = func;
    *(int *)(s + 0x50) = arg;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0114_EntryObjectManagerCollisionGroup", GetScriptPriorityGroup);

void setScriptObjArgument(void *actor, int arg)
{
    char *s = GetScriptClass(actor);
    *(int *)(s + 0x24) = arg;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0114_EntryObjectManagerCollisionGroup", func_400975D0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0114_EntryObjectManagerCollisionGroup", func_40097640);

extern unsigned char D_4012B188[];

void *getStackViewFlag(void)
{
    return D_4012B188;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0114_EntryObjectManagerCollisionGroup", scriptIntrSignal);
