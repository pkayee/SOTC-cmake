#include "common.h"

extern s32 D_401FC788[];
extern u8 D_401FC810[];
extern s32 D_401FC860[];
extern f32 *D_40130C78;
extern s32 *D_40130C7C;
extern s32 D_401FD0AC;
extern s32 D_401FD0B0;
extern s32 D_401FD0B4;
extern s32 D_401FD0B8;
extern f32 D_401FD0C8[];
extern s32 D_401FD0BC;
extern s64 D_401FD0C0;
extern s8 D_401FD098;

void SetDamageClassDamageTableType(s32 type);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0019_gameFlagCheckPointSave", gameFlagCheckPointSave);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0019_gameFlagCheckPointSave", gameFlagInit);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0019_gameFlagCheckPointSave", _optionWorkSet);
void _optionWorkSet(s32 idx, s32 val)
{
    D_401FC788[idx] = val;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0019_gameFlagCheckPointSave", _optionWorkCls);
void _optionWorkCls(s32 idx)
{
    D_401FC788[idx] = 0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0019_gameFlagCheckPointSave", _optionWorkChk);
s32 _optionWorkChk(s32 idx)
{
    return D_401FC788[idx];
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0019_gameFlagCheckPointSave", _optionWorkPtr);
s32 *_optionWorkPtr(s32 idx)
{
    return &D_401FC788[idx];
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0019_gameFlagCheckPointSave", _gameFlagSet);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0019_gameFlagCheckPointSave", _gameFlagCls);
s32 _gameFlagCls(s32 idx)
{
    u8 *p = &D_401FC810[idx / 8];
    u8 v = *p & ~(1 << (idx & 7));
    *p = v;
    return v;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0019_gameFlagCheckPointSave", _gameFlagChk);
s32 _gameFlagChk(s32 idx)
{
    return (D_401FC810[idx / 8] >> (idx & 7)) & 1;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0019_gameFlagCheckPointSave", _gameFlagXor);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0019_gameFlagCheckPointSave", _gameWorkSet);
void _gameWorkSet(s32 idx, s32 val)
{
    D_401FC860[idx] = val;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0019_gameFlagCheckPointSave", _gameFWorkSet);
void _gameFWorkSet(f32 val, s32 idx)
{
    D_40130C78[idx] = val;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0019_gameFlagCheckPointSave", _gameIWorkSet);
void _gameIWorkSet(s32 idx, s32 val)
{
    D_40130C7C[idx] = val;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0019_gameFlagCheckPointSave", _gameWorkCls);
void _gameWorkCls(s32 idx)
{
    D_401FC860[idx] = 0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0019_gameFlagCheckPointSave", _gameWorkChk);
s32 _gameWorkChk(s32 idx)
{
    return D_401FC860[idx];
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0019_gameFlagCheckPointSave", _gameFWorkChk);
f32 _gameFWorkChk(s32 idx)
{
    return D_40130C78[idx];
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0019_gameFlagCheckPointSave", _gameIWorkChk);
s32 _gameIWorkChk(s32 idx)
{
    return D_40130C7C[idx];
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0019_gameFlagCheckPointSave", fruitsFlagSet);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0019_gameFlagCheckPointSave", fruitsFlagChk);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0019_gameFlagCheckPointSave", getGameDataExistIcoData);
s32 getGameDataExistIcoData(void)
{
    return D_401FD0B8;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0019_gameFlagCheckPointSave", getGameDataExistIcoDataAdrs);
s32 *getGameDataExistIcoDataAdrs(void)
{
    return &D_401FD0B8;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0019_gameFlagCheckPointSave", setBossClearCnt);
void setBossClearCnt(s32 val)
{
    D_401FD0B0 = val;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0019_gameFlagCheckPointSave", getBossIndexTimeAttackBestTime);
f32 getBossIndexTimeAttackBestTime(s32 idx)
{
    return D_401FD0C8[idx];
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0019_gameFlagCheckPointSave", setBossIndexTimeAttackBestTime);
void setBossIndexTimeAttackBestTime(f32 val, s32 idx)
{
    D_401FD0C8[idx] = val;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0019_gameFlagCheckPointSave", getGameClearCnt);
s32 getGameClearCnt(void)
{
    return D_401FD0B4;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0019_gameFlagCheckPointSave", getGameClearCntAdrs);
s32 *getGameClearCntAdrs(void)
{
    return &D_401FD0B4;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0019_gameFlagCheckPointSave", setGmaeClearCnt);
void setGmaeClearCnt(s32 val)
{
    D_401FD0B4 = val;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0019_gameFlagCheckPointSave", getGameHardMode);
s32 getGameHardMode(void)
{
    return D_401FD0BC != 0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0019_gameFlagCheckPointSave", getGameHardModeAdrs);
s32 *getGameHardModeAdrs(void)
{
    return &D_401FD0BC;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0019_gameFlagCheckPointSave", setGameHardMode);
void setGameHardMode(s32 v)
{
    D_401FD0BC = v;
    SetDamageClassDamageTableType(v != 0);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0019_gameFlagCheckPointSave", getSavedGameTime);
s32 getSavedGameTime(void)
{
    return D_401FD0AC;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0019_gameFlagCheckPointSave", setSavedGameTime);
void setSavedGameTime(s32 val)
{
    D_401FD0AC = val;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0019_gameFlagCheckPointSave", getSavedClock);
void getSavedClock(s64 *out)
{
    *out = D_401FD0C0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0019_gameFlagCheckPointSave", setSavedClock);
void setSavedClock(s64 *in)
{
    D_401FD0C0 = *in;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0019_gameFlagCheckPointSave", getSavedPlaceId);
s8 getSavedPlaceId(void)
{
    return D_401FD098;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0019_gameFlagCheckPointSave", setSavedPlaceId);
void setSavedPlaceId(s8 val)
{
    D_401FD098 = val;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0019_gameFlagCheckPointSave", gameFlagCheckPointLoad);
