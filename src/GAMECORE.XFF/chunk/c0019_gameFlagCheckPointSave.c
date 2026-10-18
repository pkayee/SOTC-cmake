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
extern u8 D_401FC8C8[];
extern u8 D_401FCA58[];
extern u8 D_401FCD78[];
extern void *memset(void *, int, unsigned int);

void SetDamageClassDamageTableType(s32 type);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0019_gameFlagCheckPointSave", gameFlagCheckPointSave);

static inline void gameSetF(f32 f)
{
    *(f32 *)((u8 *)D_40130C78 + 0x2C) = f;
    *(f32 *)((u8 *)D_40130C78 + 0x30) = f;
}

void gameFlagInit(void)
{
    memset(D_401FC810, 0, 0x50);
    memset(D_401FC860, 0, 0x68);
    gameSetF(100.0f);
    memset(D_401FC8C8, 0, 0x190);
    memset(D_401FCA58, 0, 0x320);
    memset(D_401FCD78, 0, 0x320);
}

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

void _gameFlagSet(s32 i)
{
    D_401FC810[i / 8] |= 1 << (i & 7);
}

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

s32 _gameFlagXor(s32 i)
{
    u8 *p = &D_401FC810[i / 8];
    *p ^= 1 << (i & 7);
    return (*p >> (i & 7)) & 1;
}

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

void fruitsFlagSet(unsigned int a, int b)
{
    unsigned char *base = D_401FC8C8;
    unsigned char *p;
    int bit;

    if (a >= 100 || b >= 32 || b < 0) {
        p = 0;
    } else {
        int n = a * 32 + b;

        bit = n & 7;
        p = base + (n >> 3);
    }
    if (p != 0)
        *p |= 1 << bit;
}

int fruitsFlagChk(unsigned int a, int b)
{
    unsigned char *base = D_401FC8C8;
    unsigned char *p;
    int bit;

    if (a >= 100 || b >= 32 || b < 0) {
        p = 0;
    } else {
        int n = a * 32 + b;

        bit = n & 7;
        p = base + (n >> 3);
    }
    if (p != 0 && ((*p >> bit) & 1))
        return 1;
    return 0;
}

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

/* NEARMISS-STUB gameFlagCheckPointLoad */
#if 0 /* NEARMISS 12.7% cat=struct-layout sub=- | target copies 6 regions in unrolled u64 loops (1008 B); sibling is one struct copy | attempts=1 */
typedef struct { s32 b[0x10]; } GFCpBlk;
void gameFlagCheckPointLoad(GFCpBlk *a0)
{
    *(GFCpBlk *)D_401FC810 = *a0;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0019_gameFlagCheckPointSave", gameFlagCheckPointLoad);
