#include "common.h"

extern s32 D_40131B4C;
u8 *GetSCRCharaAIWorkPtr(void);
s32 GAMEUTIL_is_swimming_now(void);

extern s64 D_40131B40;
extern s32 D_40131B48;

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0103_SCRPlayerGetWeapon", SCRPlayerGetWeapon);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0103_SCRPlayerGetWeapon", SCRPlayerLostWeapon);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0103_SCRPlayerGetWeapon", nico_playerGetSightOn);
s32 GAMEUTIL_is_player_obj(s32 chr);

u8 *nico_playerGetSightOn(s32 obj)
{
    u8 *work;

    if (GAMEUTIL_is_player_obj(obj) == 1)
    {
        u8 *GetSCRCharaAIWorkPtr();
        work = GetSCRCharaAIWorkPtr(obj);
        return work + 0x290;
    }
    return 0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0103_SCRPlayerGetWeapon", nico_playerIsActingSightOn);
s32 is_doing_nico_sight_on(u8 *p);

s32 nico_playerIsActingSightOn(s32 obj)
{
    if (GAMEUTIL_is_player_obj(obj) == 1)
    {
        u8 *work;

        u8 *GetSCRCharaAIWorkPtr();
        work = GetSCRCharaAIWorkPtr(obj);
        return is_doing_nico_sight_on(work + 0x290);
    }
    return 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0103_SCRPlayerGetWeapon", nico_playerSightOnDirection);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0103_SCRPlayerGetWeapon", nico_playerSetAttentionHeadActFlag);
void nico_playerSetAttentionHeadActFlag(s32 obj, s32 flag)
{
    if (GAMEUTIL_is_player_obj(obj) == 1)
    {
        u8 *GetSCRCharaAIWorkPtr();
        u8 *work = GetSCRCharaAIWorkPtr(obj);
        *(s32 *)(work + 0x160) = flag;
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0103_SCRPlayerGetWeapon", nico_playerIsSwimmingNow);
extern s32 ControlMode_PLAYER_SWIM;
extern s32 ControlMode_PLAYER_SWIM_MOVE;
extern s32 ControlMode_PLAYER_SWIM_DASH;
u8 *GetCharacterClass(s32 chr);

s32 nico_playerIsSwimmingNow(s32 obj)
{
    if (GAMEUTIL_is_player_obj(obj) == 1)
    {
        u8 *chara = GetCharacterClass(obj);
        s32 mode = *(s32 *)(chara + 0x740);

        if (mode == ControlMode_PLAYER_SWIM || mode == ControlMode_PLAYER_SWIM_MOVE || mode == ControlMode_PLAYER_SWIM_DASH)
        {
            return 1;
        }
    }
    return 0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0103_SCRPlayerGetWeapon", nico_playerGetExpression);
u8 *nico_playerGetExpression(void)
{
    return GetSCRCharaAIWorkPtr() + 0x570;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0103_SCRPlayerGetWeapon", nico_playerGetExpressionChange);
u8 *nico_playerGetExpressionChange(void)
{
    return GetSCRCharaAIWorkPtr() + 0xCA0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0103_SCRPlayerGetWeapon", nico_playerActForseStandReset);
extern s32 ScriptCtrlDef_SCRPlayerForceStand;
void SCRRequestMotionDirect(s32 obj, s32 motion);
void CancelSwordEffect(void);

s32 nico_playerActForseStandReset(s32 obj)
{
    if (GAMEUTIL_is_player_obj(obj) == 1)
    {
        SCRRequestMotionDirect(obj, ScriptCtrlDef_SCRPlayerForceStand);
        CancelSwordEffect();
        return 1;
    }
    return 0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0103_SCRPlayerGetWeapon", nico_playerBeginHoistSword);
extern u8 gcGlobalVar[];
void func_4008B198(s32 obj, u8 *work);
f32 GetWeaponRange(void);
void begin_nico_sight_on(u8 *p, s32 obj, u8 *x, f32 range);

void nico_playerBeginHoistSword(s32 obj)
{
    u8 *work;

    u8 *GetSCRCharaAIWorkPtr();
    work = GetSCRCharaAIWorkPtr(obj);
    func_4008B198(obj, work);
    begin_nico_sight_on(work + 0x290, obj, gcGlobalVar + 0x230, GetWeaponRange());
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0103_SCRPlayerGetWeapon", nico_playerEndHoistSword);
s32 is_doing_nico_sight_on(u8 *p);
void end_nico_sight_on(u8 *p);

void nico_playerEndHoistSword(void)
{
    u8 *p = GetSCRCharaAIWorkPtr() + 0x290;

    if (is_doing_nico_sight_on(p) == 1)
    {
        end_nico_sight_on(p);
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0103_SCRPlayerGetWeapon", torchExtinguished);
void _SCRStartLWS(s32 lws, s32 a1, s32 a2, u8 *a3);

void torchExtinguished(void)
{
    u8 *work = GetSCRCharaAIWorkPtr();

    if (*(s32 *)(work + 0x8C) != 0)
    {
        _SCRStartLWS(*(s32 *)(work + 0x8C), -1, 3, work + 0x90);
        *(u8 *)(work + 0x95) = 1;
        *(s32 *)(work + 0x88) = 0;
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0103_SCRPlayerGetWeapon", getTorchInfo);
s32 getTorchInfo(void)
{
    u8 *work = GetSCRCharaAIWorkPtr();
    s32 res = 0;

    if (*(s32 *)(work + 0x70) == 9)
    {
        res = work[0x94] != 0;
    }
    return res;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0103_SCRPlayerGetWeapon", getCurWeapon);
s32 getCurWeapon(void)
{
    u8 *work = GetSCRCharaAIWorkPtr();
    return *(s32 *)(work + 0x70);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0103_SCRPlayerGetWeapon", getPlayerMVHIST);
u8 *getPlayerMVHIST(void)
{
    return GetSCRCharaAIWorkPtr() + 0xD80;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0103_SCRPlayerGetWeapon", nico_ResetPlayerHorseRidingControl);
extern u8 InitialGeometryPointer[];
u8 *GetCharacterClass(s32 chr);
void ChangeCharacterObjControlTarget();
void ChangeCharacterObjControlledTarget(s32 a0, s32 a1, u8 *a2, s32 a3);
void ResetCharacterClassSyncMode(u8 *chara);
void nico_resetHorseRidingStatusForHorse(s32 obj);

void nico_ResetPlayerHorseRidingControl(s32 obj)
{
    u8 *GetSCRCharaAIWorkPtr();
    u8 *chara = GetCharacterClass(obj);
    s32 target = *(s32 *)(chara + 0x950);
    u8 *targetChara = GetCharacterClass(target);
    u8 *work;

    ChangeCharacterObjControlTarget(target, target);
    ChangeCharacterObjControlledTarget(obj, obj, InitialGeometryPointer, 0);
    ResetCharacterClassSyncMode(targetChara);
    work = GetSCRCharaAIWorkPtr(target);
    *(s32 *)(work + 0xD28) = 0;
    nico_resetHorseRidingStatusForHorse(obj);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0103_SCRPlayerGetWeapon", nico_returnPlayerRidingFlag);
s32 nico_returnPlayerRidingFlag(void)
{
    u8 *work = GetSCRCharaAIWorkPtr();
    return *(s32 *)(work + 0xD28);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0103_SCRPlayerGetWeapon", IsHorseCalled_withFlgOff);
s32 IsHorseCalled_withFlgOff(void)
{
    u8 *work = GetSCRCharaAIWorkPtr();
    s32 flg = work[0xD2C];

    if (flg == 1)
    {
        work[0xD2C] = 0;
    }
    return flg;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0103_SCRPlayerGetWeapon", IsHorseAutoControlled);
s32 IsHorseAutoControlled(void)
{
    u8 *work = GetSCRCharaAIWorkPtr();
    return work[0xD2D];
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0103_SCRPlayerGetWeapon", player_IsHorseHang);
extern s32 ControlMode_PLAYER_RIDING_HANG;
extern s32 ControlMode_PLAYER_RIDING_HANG_DOWN_R;
extern s32 ControlMode_PLAYER_RIDING_HANG_DOWN_L;
extern s32 ControlMode_PLAYER_DUMMY;
u8 *GetCharacterClass(s32 chr);
s32 player_IsHorseHang(s32 chr)
{
    s32 mode = *(s32 *)(GetCharacterClass(chr) + 0x740);

    if (mode == ControlMode_PLAYER_RIDING_HANG || mode == ControlMode_PLAYER_RIDING_HANG_DOWN_R || mode == ControlMode_PLAYER_RIDING_HANG_DOWN_L || mode == ControlMode_PLAYER_DUMMY)
    {
        return 1;
    }
    return 0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0103_SCRPlayerGetWeapon", player_IsSwiming);
s32 player_IsSwiming(void)
{
    return GAMEUTIL_is_swimming_now();
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0103_SCRPlayerGetWeapon", getPlayerPosAfterXSeconds);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0103_SCRPlayerGetWeapon", getArrowPos);
void getArrowPos(s32 obj, u128 *pos)
{
    if (obj != 0)
    {
        u8 *chara;
        u8 *work;

        u8 *GetScriptCharacterClass(s32 chr);
        chara = GetScriptCharacterClass(obj);
        if (*(s32 *)(chara + 0x1150) != 0)
        {
            u8 *GetSCRCharaAIWorkPtr();
            work = GetSCRCharaAIWorkPtr(obj);
            *(u128 *)(work + 0x10) = *pos;
        }
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0103_SCRPlayerGetWeapon", getArrowInfo);
void getArrowInfo(s32 obj, s32 val)
{
    if (obj != 0)
    {
        u8 *chara;
        u8 *work;

        u8 *GetScriptCharacterClass(s32 chr);
        chara = GetScriptCharacterClass(obj);
        if (*(s32 *)(chara + 0x1150) != 0)
        {
            u8 *GetSCRCharaAIWorkPtr();
            work = GetSCRCharaAIWorkPtr(obj);
            *(s32 *)(work + 0x20) = val;
        }
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0103_SCRPlayerGetWeapon", player_getWeaponType);
s32 player_getWeaponType(void)
{
    u8 *work = GetSCRCharaAIWorkPtr();
    return *(s32 *)(work + 0x70);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0103_SCRPlayerGetWeapon", player_AutoHorseCtrlOff);
void player_AutoHorseCtrlOff(s32 value)
{
    D_40131B4C = value;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0103_SCRPlayerGetWeapon", getPlayerColCont);
u8 *getPlayerColCont(void)
{
    return GetSCRCharaAIWorkPtr() + 0xD50;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0103_SCRPlayerGetWeapon", getPlayerColCont2);
u8 *getPlayerColCont2(void)
{
    return GetSCRCharaAIWorkPtr() + 0xD60;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0103_SCRPlayerGetWeapon", getPlayerLastAttrStatus);
s64 getPlayerLastAttrStatus(void)
{
    return D_40131B40;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0103_SCRPlayerGetWeapon", getPlayerLastParentObj);
s32 getPlayerLastParentObj(void)
{
    return D_40131B48;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0103_SCRPlayerGetWeapon", playerPlaneJudgeFunc);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0103_SCRPlayerGetWeapon", torchObjRelease);
void isysRequestDeleteObj(s32 obj);

void torchObjRelease(void)
{
    u8 *work = GetSCRCharaAIWorkPtr();

    if (*(s32 *)(work + 0x110) != 0)
    {
        isysRequestDeleteObj(*(s32 *)(work + 0x110));
    }
    *(s32 *)(work + 0x110) = 0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0103_SCRPlayerGetWeapon", getTorchObj);
s32 getTorchObj(void)
{
    u8 *work = GetSCRCharaAIWorkPtr();
    return *(s32 *)(work + 0x110);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0103_SCRPlayerGetWeapon", player_SetGripDamage);
void player_SetGripDamage(f32 value)
{
    u8 *work = GetSCRCharaAIWorkPtr();
    *(f32 *)(work + 0xF8) = value;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0103_SCRPlayerGetWeapon", nico_hydePlayer);
extern u8 SH_PlayerHydeObjListDEFAULT[];
void func_4008C920(s32 a0, s32 a1, s32 a2, s32 a3);

void nico_hydePlayer(s32 a0, s32 a1)
{
    u8 *list = SH_PlayerHydeObjListDEFAULT;
    s32 p = *(s32 *)(list + 0xC);

    if (p != 0)
    {
        func_4008C920(a0, *(s32 *)(list + 0x10), p, a1 == 0);
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0103_SCRPlayerGetWeapon", playerWeaponChangeIconMax);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0103_SCRPlayerGetWeapon", nico_playerCheckNippingWithHorseAndWall);
s32 nico_playerCheckNippingWithHorseAndWall(s32 obj)
{
    u8 *chara = GetCharacterClass(obj);

    if (*(s8 *)(chara + 0x525) != 0 && *(s32 *)(chara + 0xF50) != 0)
    {
        s32 target = *(s32 *)(chara + 0xF58);
        u8 *targetChara = GetCharacterClass(target);

        if (targetChara != 0 && *(s16 *)(targetChara + 0x360) == 3)
        {
            return target;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0103_SCRPlayerGetWeapon", player_setWeaponScriptSwitch);
