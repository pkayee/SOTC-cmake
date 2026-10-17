#include "common.h"

extern s32 D_40131B28;
extern s32 D_40131ABC;
extern u8 D_40131AB0[];
extern u8 D_40131AC0[];
extern u8 D_40131AC4[];
extern u8 D_40131AC8[];
extern u8 D_40131ACC[];
extern u8 D_40203FE0[];

s32 _optionWorkChk(s32 idx);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0099_OptionMenuStart", OptionMenuStart);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0099_OptionMenuStart", PauseMenuStart);

s32 func_40087520(void)
{
    return _optionWorkChk(1);
}

s32 func_40087538(void)
{
    return _optionWorkChk(4);
}

s32 func_40087550(void)
{
    return _optionWorkChk(5);
}

s32 func_40087568(void)
{
    return _optionWorkChk(2);
}

s32 func_40087580(void)
{
    return _optionWorkChk(6);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0099_OptionMenuStart", func_40087598);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0099_OptionMenuStart", func_400875B0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0099_OptionMenuStart", func_400875C8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0099_OptionMenuStart", func_400875E0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0099_OptionMenuStart", func_400875F8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0099_OptionMenuStart", func_40087610);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0099_OptionMenuStart", func_40087628);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0099_OptionMenuStart", func_40087660);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0099_OptionMenuStart", func_40087698);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0099_OptionMenuStart", func_400876D0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0099_OptionMenuStart", func_40087700);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0099_OptionMenuStart", func_40087730);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0099_OptionMenuStart", func_40087750);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0099_OptionMenuStart", func_40087788);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0099_OptionMenuStart", func_400877C0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0099_OptionMenuStart", func_400877F8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0099_OptionMenuStart", func_40087830);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0099_OptionMenuStart", func_40087868);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0099_OptionMenuStart", func_40087880);

void initSavePoint(void) {
}

void deleteSavePoint(void) {
}

void SetMapLogDispMode(s32 mode)
{
    D_40131ABC = mode;
}

s32 getSprLogWorkSize(void)
{
    return 0x2D00;
}

u8* getSprLogWorkAddress(void)
{
    return D_40203FE0;
}

s32 getSprLogStatusSize(void)
{
    return 0xC;
}

u8* getSprLogStatusAddress(void)
{
    return D_40131AB0;
}

u8* getLogLineColorR(void)
{
    return D_40131AC0;
}

u8* getLogLineColorG(void)
{
    return D_40131AC4;
}

u8* getLogLineColorB(void)
{
    return D_40131AC8;
}

u8* getLogLineColorA(void)
{
    return D_40131ACC;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0099_OptionMenuStart", mapLogReset);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0099_OptionMenuStart", createPauseMenuMap);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0099_OptionMenuStart", initPauseMenuMap);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0099_OptionMenuStart", st_pausemenu_load_omake_chara);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0099_OptionMenuStart", setLoadMapOffset);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0099_OptionMenuStart", loadMapSetCloud);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0099_OptionMenuStart", mapScript);

void LoadWaitCancel(void)
{
    D_40131B28 = 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0099_OptionMenuStart", LoadWaitScript);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0099_OptionMenuStart", LoadWaitScriptDemoStart);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0099_OptionMenuStart", execPause);

f32 GetMenuFade(void)
{
    return 0.0f;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0099_OptionMenuStart", func_40087D50);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0099_OptionMenuStart", physicalOp);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0099_OptionMenuStart", func_400882C8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0099_OptionMenuStart", func_400884B0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0099_OptionMenuStart", func_40088740);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0099_OptionMenuStart", func_400888C0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0099_OptionMenuStart", func_40088A38);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0099_OptionMenuStart", func_40088BC8);
