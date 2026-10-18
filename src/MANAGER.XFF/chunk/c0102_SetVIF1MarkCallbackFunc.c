#include "common.h"

extern int iosSetSyncNoReturnFunc(void (*func)(unsigned int vif1Stat));
void func_4008A8C8(void);

void SetVIF1MarkCallbackFunc(void)
{
    iosSetSyncNoReturnFunc(&func_4008A8C8);
}

extern s32 D_4012B018;

void SetCameraResetSw(s32 resetSw)
{
    D_4012B018 = resetSw;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0102_SetVIF1MarkCallbackFunc", InitLayoutObjMatrix);

extern void *GetCharacterClass(void *);
extern void *GetLayoutClass(void *);
extern void DispCloth(s32);
extern void func_40088758(void *, void *, void *);
extern void func_40088918(void *, void *, void *);
extern void func_40088AE0(void *, void *, void *);
extern s32 D_4012B014;

void DispLayoutObjModel(void *arg0, void *arg1)
{
    void *temp_s1;
    void *temp_v0;

    temp_s1 = GetCharacterClass(arg1);
    temp_v0 = GetLayoutClass(arg1);
    if ((*(s32 *)((char *)((*(void **)((char *)((*(void **)((char *)((*(void **)((char *)(temp_v0) + 0x144))) + 0))) + 0x20))) + 0x18)) & 1) {
        func_40088918(arg0, temp_v0, temp_s1);
        if (temp_s1 != NULL) {
            if ((*(signed char *)((char *)(temp_s1) + 0x1005)) != 0 && D_4012B018 == 0) {
                func_40088AE0(GetLayoutClass(arg0), temp_s1, temp_v0);
            }
        }
    } else {
        func_40088758(arg0, temp_v0, temp_s1);
    }
    if (D_4012B014 == 0) {
        return;
    }
    if (*(s32 *)((char *)temp_v0 + 0x180) == 0) {
        return;
    }
    if (((*(s64 *)((char *)((*(void **)((char *)temp_v0 + 0x144))) + 0x280)) & 0x80) == 0) {
        return;
    }
    DispCloth(*(s32 *)((char *)temp_v0 + 0x178));
}

extern void *CreateSortList(int, int, float);
extern void *D_4012B028;
extern void *D_4012B02C;

void initSortDisplayObj(void)
{
    if (D_4012B028 == 0) {
        D_4012B028 = CreateSortList(10, 1, 200.0f);
    }
    if (D_4012B02C == 0) {
        D_4012B02C = CreateSortList(10, 1, 200.0f);
    }
}

extern void DeleteSortList(void **list);

void deleteSortLayoutObj(void)
{
    if (D_4012B028 != 0) {
        DeleteSortList(D_4012B028);
    }
    if (D_4012B02C != 0) {
        DeleteSortList(D_4012B02C);
    }
}

s32 GetResetCameraFlagForDisplay(void)
{
    return D_4012B018;
}

void *getSubObjDispSw(void)
{
    return &D_4012B014;
}

extern s32 D_4012B01C;

void *getMotionBlurSw(void)
{
    return &D_4012B01C;
}

extern s32 D_4012B024;

void *motionBlurTestType(void)
{
    return &D_4012B024;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0102_SetVIF1MarkCallbackFunc", SetLayoutDisplayFlag);
extern s32 D_4012B020;

void SetLayoutDisplayFlag(s32 flag)
{
    D_4012B020 = flag;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0102_SetVIF1MarkCallbackFunc", func_4008A7E8);

extern f32 iosCalcFColorToBrightness(f32 *);

f32 GetAmbientBrightnessOfLayoutObject(void *arg0)
{
    u8 *layout;
    u8 *temp;

    layout = GetLayoutClass(arg0);
    temp = *(u8 **)(layout + 0x144);
    if (temp != NULL && (*(u64 *)(temp + 0x280) & 2))
    {
        return iosCalcFColorToBrightness((f32 *)((u8 *)*(void **)(temp + 0xC) + 0x80));
    }
    return 0.0f;
}

void func_4008A8C8(void) {
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0102_SetVIF1MarkCallbackFunc", CreateLightColMan);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0102_SetVIF1MarkCallbackFunc", LoopExecPreLightColMan);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0102_SetVIF1MarkCallbackFunc", func_4008AC68);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0102_SetVIF1MarkCallbackFunc", InitStageLightColMan);

extern void *D_4012B030;

void *GetLightColMan(void)
{
    return D_4012B030;
}

extern char D_401AC8B0[];
extern void *memset(void *, s32, u32);
extern void isysInitGroup(void *);

void InitLightColMan(void)
{
    D_4012B030 = D_401AC8B0;
    memset(D_401AC8B0, 0, 0xBD0);
    isysInitGroup(D_401AC8B0 + 0x514);
    isysInitGroup(D_401AC8B0 + 0x518);
    isysInitGroup(D_401AC8B0 + 0x51C);
    isysInitGroup(D_401AC8B0 + 0x524);
    isysInitGroup(D_401AC8B0 + 0x528);
}
