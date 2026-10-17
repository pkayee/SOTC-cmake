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

/* NEARMISS-STUB setPlayerHp */
#if 0 /* NEARMISS 91.29% cat=float-ops sub=- | see kK48 batch note | attempts=1 */
void setPlayerHp(f32 val)
{
    f32 hp = 0.0f;

    if (_gameFWorkChk(0xB) < val)
    {
        hp = _gameFWorkChk(0xB);
    }
    else
    {
        if (val < hp)
        {
        }
        else
        {
            hp = val;
        }
    }
    D_40200F24 = hp;
    playerlifebar_sethp(getPlayerHp() / getPlayerMaxHp());
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0028_getPlayerHp", setPlayerHp);

/* NEARMISS-STUB addPlayerHp */
#if 0 /* NEARMISS 94.64% cat=float-ops sub=- | see kK48 batch note | attempts=1 */
void addPlayerHp(f32 val)
{
    f32 hp = 0.0f;
    f32 n;

    if (val < 0.0f)
    {
        val = val * gStatGetPlayerAccessoriesDamgeRaitoToPlayer(val);
    }
    n = D_40200F24 + val;
    if (_gameFWorkChk(0xB) < n)
    {
        hp = _gameFWorkChk(0xB);
    }
    else
    {
        if (n < hp)
        {
        }
        else
        {
            hp = n;
        }
    }
    D_40200F24 = hp;
    playerlifebar_sethp(getPlayerHp() / getPlayerMaxHp());
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0028_getPlayerHp", addPlayerHp);

/* NEARMISS-STUB _getPlayerHpRatio */
#if 0 /* NEARMISS 99.62% cat=float-ops sub=- | see kK48 batch note | attempts=1 */
f32 _getPlayerHpRatio(void)
{
    return getPlayerHp() / getPlayerMaxHp();
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0028_getPlayerHp", _getPlayerHpRatio);

/* NEARMISS-STUB getPlayerHpRatio */
#if 0 /* NEARMISS 99.69% cat=float-ops sub=- | see kK48 batch note | attempts=1 */
f32 getPlayerHpRatio(void)
{
    return (getPlayerHp() / getPlayerMaxHp()) * 100.0f;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0028_getPlayerHp", getPlayerHpRatio);

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

/* NEARMISS-STUB setPlayerGrip */
#if 0 /* NEARMISS 83.74% cat=regalloc sub=- | see kK48 batch note | attempts=1 */
void setPlayerGrip(f32 val)
{
    f32 grip = 0.0f;

    if (_gameFWorkChk(0xC) < val)
    {
        grip = _gameFWorkChk(0xC);
    }
    else
    {
        if (val < grip)
        {
        }
        else
        {
            grip = val;
        }
    }
    D_40200F20 = grip;
    setgrip(grip / _gameFWorkChk(0xC));
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0028_getPlayerHp", setPlayerGrip);

/* NEARMISS-STUB addPlayerGrip */
#if 0 /* NEARMISS 86.64% cat=regalloc sub=- | see kK48 batch note | attempts=1 */
void addPlayerGrip(f32 val)
{
    f32 grip = 0.0f;
    f32 n = D_40200F20 + val;

    if (_gameFWorkChk(0xC) < n)
    {
        grip = _gameFWorkChk(0xC);
    }
    else
    {
        if (n < grip)
        {
        }
        else
        {
            grip = n;
        }
    }
    D_40200F20 = grip;
    setgrip(grip / _gameFWorkChk(0xC));
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0028_getPlayerHp", addPlayerGrip);

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

/* NEARMISS-STUB addPlayerO2 */
#if 0 /* NEARMISS 95.71% cat=regalloc sub=- | see kK48 batch note | attempts=1 */
void addPlayerO2(f32 val)
{
    f32 o2 = D_40130F4C + val;
    f32 v = 100.0f;

    if (v < o2)
    {
    }
    else
    {
        v = 0.0f;
        if (o2 < v)
        {
        }
        else
        {
            v = o2;
        }
    }
    D_40130F4C = v;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0028_getPlayerHp", addPlayerO2);

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
