#include "common.h"

void Sg2ExPcmOutputSetVol(s32 arg0, s32 arg1);
void Sg2ExPcmOutputCtrl(s32 arg0);
void createYesNoDialog(u8* arg0, s32 arg1);
void iosFree(void* arg0);
void changeVolume(s32 arg0);
extern u8 D_4012EAA0[];
extern u8* D_4012E3C8;

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0205_setStartEditWorkTool", setStartEditWorkTool);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0205_setStartEditWorkTool", unsetEndEditWorkTool);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0205_setStartEditWorkTool", openEditWorkTool);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0205_setStartEditWorkTool", func_400FC6C8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0205_setStartEditWorkTool", func_400FC750);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0205_setStartEditWorkTool", func_400FC7A8);

void func_400FC830(u8* arg0)
{
    createYesNoDialog(D_4012EAA0, *(s32*)(arg0 + 0x94));
}

void func_400FC850(u8* arg0)
{
    u8* temp = D_4012E3C8;
    void (*fn)(void*, void*, void*) = *(void (**)(void*, void*, void*))(temp + 0x218);

    if (fn != NULL)
    {
        fn(*(void**)temp, *(void**)(temp + 0x20C), *(void**)(*(u8**)(arg0 + 0x3E8) + 4));
    }
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0205_setStartEditWorkTool", func_400FC890);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0205_setStartEditWorkTool", initEtiInfoWork);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0205_setStartEditWorkTool", loadPathData);

void delPathData(void *arg0, void *arg1, void *arg2)
{
    iosFree(arg2);
    return;
}

u8* getPointDataHeader(u8* arg0)
{
    s32 temp = *(s32*)(arg0 + 0x8);

    if (temp == 0)
    {
        return NULL;
    }
    return arg0 + temp;
}

u8* getLineDataHeader(u8* arg0)
{
    s32 temp = *(s32*)(arg0 + 0xC);

    if (temp == 0)
    {
        return NULL;
    }
    return arg0 + temp;
}

u8* getPointData(u8* arg0, s32 arg1)
{
    u8* temp = NULL;

    if (arg0 != NULL && arg1 >= 0)
    {
        temp = arg0 + arg1 * 48 + 0x10;
        if ((u32)arg1 < *(u32*)arg0)
        {
            return temp;
        }
        temp = NULL;
    }
    return temp;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0205_setStartEditWorkTool", getConnectLineArray);

u8* getLineData(u8* arg0, s32 arg1)
{
    u8* temp = NULL;

    if (arg0 != NULL && arg1 >= 0)
    {
        temp = arg0 + arg1 * 48 + 0x10;
        if ((u32)arg1 < *(u32*)arg0)
        {
            return temp;
        }
        temp = NULL;
    }
    return temp;
}

u8* getRootDataHeader(u8* arg0)
{
    s32 temp = *(s32*)(arg0 + 0x10);

    if (temp == 0)
    {
        return NULL;
    }
    return arg0 + temp;
}

u8* getGoalDataHeader(u8* arg0)
{
    s32 temp = *(s32*)(arg0 + 0x14);

    if (temp == 0)
    {
        return NULL;
    }
    return arg0 + temp;
}

u8* getSubDataHeader(u8* arg0)
{
    s32 temp = *(s32*)(arg0 + 0x18);

    if (temp == 0)
    {
        return NULL;
    }
    return arg0 + temp;
}

u8* getRootPointData(u8* arg0, s32 arg1)
{
    u8* temp = NULL;

    if (arg0 != NULL && arg1 >= 0)
    {
        temp = arg0 + arg1 * 48 + 0x10;
        if ((u32)arg1 < *(u32*)arg0)
        {
            return temp;
        }
        temp = NULL;
    }
    return temp;
}

u8* getGoalPointData(u8* arg0, s32 arg1)
{
    u8* temp = NULL;

    if (arg0 != NULL && arg1 >= 0)
    {
        temp = arg0 + arg1 * 48 + 0x10;
        if ((u32)arg1 < *(u32*)arg0)
        {
            return temp;
        }
        temp = NULL;
    }
    return temp;
}

u8* getSubPointData(u8* arg0, s32 arg1)
{
    u8* temp = NULL;

    if (arg0 != NULL && arg1 >= 0)
    {
        temp = arg0 + arg1 * 48 + 0x10;
        if ((u32)arg1 < *(u32*)arg0)
        {
            return temp;
        }
        temp = NULL;
    }
    return temp;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0205_setStartEditWorkTool", getChildGoalPointIdxArray);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0205_setStartEditWorkTool", getChildSubPointIdxArray);

u8* getInterestDataHeader(u8* arg0)
{
    s32 temp = *(s32*)(arg0 + 0x20);

    if (temp == 0)
    {
        return NULL;
    }
    return arg0 + temp;
}

u8* getInterestPointData(u8* arg0, s32 arg1)
{
    u8* temp = NULL;

    if (arg0 != NULL && arg1 >= 0)
    {
        temp = arg0 + arg1 * 32 + 0x10;
        if ((u32)arg1 < *(u32*)arg0)
        {
            return temp;
        }
        temp = NULL;
    }
    return temp;
}

u8* getDeadDataHeader(u8* arg0)
{
    s32 temp = *(s32*)(arg0 + 0x24);

    if (temp == 0)
    {
        return NULL;
    }
    return arg0 + temp;
}

u8* getDeadPointData(u8* arg0, s32 arg1)
{
    u8* temp = NULL;

    if (arg0 != NULL && arg1 >= 0)
    {
        temp = arg0 + arg1 * 48 + 0x10;
        if ((u32)arg1 < *(u32*)arg0)
        {
            return temp;
        }
        temp = NULL;
    }
    return temp;
}

u8* getLayoutDataHeader(u8* arg0)
{
    s32 temp = *(s32*)(arg0 + 0x28);

    if (temp == 0)
    {
        return NULL;
    }
    return arg0 + temp;
}

u8* getLayoutPointData(u8* arg0, s32 arg1)
{
    u8* temp = NULL;

    if (arg0 != NULL && arg1 >= 0)
    {
        temp = arg0 + arg1 * 48 + 0x10;
        if ((u32)arg1 < *(u32*)arg0)
        {
            return temp;
        }
        temp = NULL;
    }
    return temp;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0205_setStartEditWorkTool", audioDecCreate);

s32 audioDecIsPreset(u8* arg0)
{
    if (*(s32*)(arg0 + 0x10) > 0x3FFFF)
    {
        Sg2ExPcmOutputCtrl(5);
        changeVolume(0x7F);
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0205_setStartEditWorkTool", audioDecReset);

void changeVolume(s32 arg0)
{
    s32 temp = arg0 * 129;

    Sg2ExPcmOutputSetVol(temp, temp);
}

void changeVolumeDirect(s32 arg0)
{
    Sg2ExPcmOutputSetVol(arg0, arg0);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0205_setStartEditWorkTool", spriteMovieImage);
