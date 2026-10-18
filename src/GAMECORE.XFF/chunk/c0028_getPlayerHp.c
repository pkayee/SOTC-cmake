#include "common.h"

f32 _gameFWorkChk(s32 idx);
f32 getPlayerHp(void);
f32 getPlayerMaxHp(void);
void _gameFWorkSet(f32 val, s32 idx);
void func_400339E0(void);
void RequestCharacterMotionShiftFunc(void *chara, void (*func)(void));

extern float D_40200F20;
extern float D_40200F24;
extern float D_40200F28;
extern float D_40130F4C;

void playerlifebar_sethp(f32 val);
void setgrip(f32 val);
void playerlifebar_effect(f32 val);
void startGaugeMaxAddEffect(f32 val);
f32 gStatGetPlayerAccessoriesDamgeRaitoToPlayer(f32 val);
//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0028_getPlayerHp", getPlayerHp);
f32 getPlayerHp(void)
{
    return D_40200F24;
}

#define CLAMP(x, lo, hi) ((x) > (hi) ? (hi) : (x) < (lo) ? (lo) : (x))

void setPlayerHp(f32 hp)
{
    hp = CLAMP(hp, 0.0f, _gameFWorkChk(11));
    D_40200F24 = hp;
    playerlifebar_sethp(getPlayerHp() / getPlayerMaxHp());
}

void addPlayerHp(f32 add)
{
    f32 v;
    f32 r;

    if (add < 0.0f)
    {
        add *= gStatGetPlayerAccessoriesDamgeRaitoToPlayer(add);
    }
    v = D_40200F24 + add;
    if (_gameFWorkChk(11) < v)
    {
        r = _gameFWorkChk(11);
    }
    else if (v < 0.0f)
    {
        r = 0.0f;
    }
    else
    {
        r = v;
    }
    D_40200F24 = r;
    playerlifebar_sethp(getPlayerHp() / getPlayerMaxHp());
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0028_getPlayerHp", _getPlayerHpRatio);
f32 _getPlayerHpRatio(void)
{
    return getPlayerHp() / getPlayerMaxHp();
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0028_getPlayerHp", getPlayerHpRatio);
f32 getPlayerHpRatio(void)
{
    return (getPlayerHp() / getPlayerMaxHp()) * 100.0f;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0028_getPlayerHp", getPlayerMaxHp);
f32 getPlayerMaxHp(void)
{
    return _gameFWorkChk(0xB);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0028_getPlayerHp", setPlayerMaxHp);
void setPlayerMaxHp(f32 val)
{
    _gameFWorkSet(val, 0xB);
}

/* NEARMISS-STUB addPlayerMaxHp */
#if 0 /* NEARMISS 68.08% cat=regalloc sub=- | see kK48 batch note | attempts=1 */
void addPlayerMaxHp(f32 val)
{
    f32 v = val + _gameFWorkChk(0xB);

    _gameFWorkSet(v, 0xB);
    playerlifebar_effect(v);
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0028_getPlayerHp", addPlayerMaxHp);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0028_getPlayerHp", getPlayerGrip);
f32 getPlayerGrip(void)
{
    return D_40200F20;
}

void setPlayerGrip(f32 g)
{
    g = CLAMP(g, 0.0f, _gameFWorkChk(12));
    D_40200F20 = g;
    setgrip(g / _gameFWorkChk(12));
}

void addPlayerGrip(f32 add)
{
    f32 v = D_40200F20 + add;

    v = _gameFWorkChk(12) < v ? _gameFWorkChk(12) : (v < 0.0f ? 0.0f : v);
    D_40200F20 = v;
    setgrip(v / _gameFWorkChk(12));
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0028_getPlayerHp", getPlayerMaxGrip);
f32 getPlayerMaxGrip(void)
{
    return _gameFWorkChk(0xC);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0028_getPlayerHp", setPlayerMaxGrip);
void setPlayerMaxGrip(f32 val)
{
    _gameFWorkSet(val, 0xC);
}

/* NEARMISS-STUB addPlayerMaxGrip */
#if 0 /* NEARMISS 68.08% cat=regalloc sub=- | see kK48 batch note | attempts=1 */
void addPlayerMaxGrip(f32 val)
{
    f32 v = val + _gameFWorkChk(0xC);

    _gameFWorkSet(v, 0xC);
    startGaugeMaxAddEffect(v);
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0028_getPlayerHp", addPlayerMaxGrip);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0028_getPlayerHp", getPlayerMaxGripRatio);
f32 getPlayerMaxGripRatio(void)
{
    return _gameFWorkChk(0xC) / 100.0f;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0028_getPlayerHp", getPlayerO2);
f32 getPlayerO2(void)
{
    return D_40130F4C;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0028_getPlayerHp", setPlayerO2);
void setPlayerO2(f32 val)
{
    f32 v = 100.0f;

    if (v < val)
    {
    }
    else
    {
        v = 0.0f;
        if (val < v)
        {
        }
        else
        {
            v = val;
        }
    }
    D_40130F4C = v;
}

void addPlayerO2(float add)
{
    float v = D_40130F4C + add;
    float r;
    if (100.0f < v)
        r = 100.0f;
    else if (v < 0.0f)
        r = 0.0f;
    else
        r = v;
    D_40130F4C = r;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0028_getPlayerHp", initPowerWork);
void initPowerWork(void)
{
    D_40200F28 = 0.0f;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0028_getPlayerHp", resetAttackPower);
void resetAttackPower(void)
{
    D_40200F28 = 0.0f;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0028_getPlayerHp", getAttackPowerRatio);
f32 getAttackPowerRatio(void)
{
    return D_40200F28 * 0.01f;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0028_getPlayerHp", getNowPower);
f32 getNowPower(void)
{
    f32 r = _gameFWorkChk(0xC) / 100.0f;

    return D_40200F28 * r;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0028_getPlayerHp", getNowPowerRatio);
f32 getNowPowerRatio(void)
{
    f32 r = _gameFWorkChk(0xC) / 100.0f;

    return D_40200F28 * r / 100.0f;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0028_getPlayerHp", setFullPower);
void setFullPower(void)
{
    D_40200F28 = 100.0f;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0028_getPlayerHp", SCRPowerReset);
void SCRPowerReset(void *chara)
{
    RequestCharacterMotionShiftFunc(chara, func_400339E0);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0028_getPlayerHp", func_400339E0);
void func_400339E0(void)
{
    D_40200F28 = 0.0f;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0028_getPlayerHp", getStageChipID);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0028_getPlayerHp", getStageAreaIndexByPos);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0028_getPlayerHp", func_40033BD0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0028_getPlayerHp", func_40033CF0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0028_getPlayerHp", func_40033EF0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0028_getPlayerHp", func_400344F8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0028_getPlayerHp", func_400347D0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0028_getPlayerHp", func_40034880);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0028_getPlayerHp", func_40034A00);
