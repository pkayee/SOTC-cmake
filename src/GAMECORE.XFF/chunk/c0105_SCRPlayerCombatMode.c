#include "common.h"

void nico_delOmakeItem(void);
void setFullPower(void);
void RequestCharacterMotionShiftFunc(void *chara, void (*func)(void));
u8 *GetSCRCharaAIWorkPtr(void);
void gameflowSetPauseEnable(s32 enable);
void gameflowSetCaptionPause(s32 pause);
void *GAMEUTIL_get_motion_kind(void *chara);
void player_setDangerEdgeOtherSidePlanePoint(void *chara, u8 *point);
void player_setDangerEdgePoint(void *chara, u8 *point);
void player_setHellDangerPoint(void *chara, u8 *point);
void player_setEdgeHangPointGeometry(void *chara, u8 *point);
void player_setGripHangPointGeometry(void *chara, u8 *point);
void func_4008C7C8(void);
void func_4008F430(void);
void func_4008F478(void);
void func_4008F5B8(void);
void func_4008F5D8(void);
void func_4008F5F8(void);
void func_4008F638(void);
void func_4008F678(void);
void func_4008F7E0(void);
u8 *GetCharacterClass(void *chara);
void nico_setHorseBridleDoubleShort(void *actor);
void nico_setHorseBridleLeftLong(void *actor);
void nico_setHorseBridleRightLong(void *actor);
void nico_setHorseBridleDoubleLong(void *actor);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", SCRPlayerCombatMode);
void SCRPlayerCombatMode(void *a0)
{
    RequestCharacterMotionShiftFunc(a0, func_4008F430);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", SCRPlayerNonCombatMode);
void SCRPlayerNonCombatMode(void *a0)
{
    RequestCharacterMotionShiftFunc(a0, func_4008F478);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", SCRPlayerPauseDisable);
void SCRPlayerPauseDisable(void *a0)
{
    RequestCharacterMotionShiftFunc(a0, func_4008F5B8);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", SCRPlayerPauseEnable);
void SCRPlayerPauseEnable(void *a0)
{
    RequestCharacterMotionShiftFunc(a0, func_4008F5D8);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", SCRPlayerTorchThrow);
void SCRPlayerTorchThrow(void *a0)
{
    RequestCharacterMotionShiftFunc(a0, func_4008C7C8);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", SCRWeaponSword);
void SCRWeaponSword(void *a0)
{
    RequestCharacterMotionShiftFunc(a0, func_4008F5F8);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", SCRWeaponHand);
void SCRWeaponHand(void *a0)
{
    RequestCharacterMotionShiftFunc(a0, func_4008F638);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", SCRHorseKick);
void SCRHorseKick(void *a0)
{
    RequestCharacterMotionShiftFunc(a0, func_4008F678);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", nico_playerIK_attention_head);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", nico_playerIK_attention_chest);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", nico_playeGripDamage);
void nico_playeGripDamage(void *a0)
{
    RequestCharacterMotionShiftFunc(a0, func_4008F7E0);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", nico_playeGripholdOn);
void nico_playeGripholdOn(void)
{
    u8 *work = GetSCRCharaAIWorkPtr();
    *(s32 *)(work + 0xF0) = 1;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", nico_playeGripholdOff);
void nico_playeGripholdOff(void)
{
    u8 *work = GetSCRCharaAIWorkPtr();
    *(s32 *)(work + 0xF0) = 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", nico_setPlayerHorseBridle);

static inline void *getHorse(void *a)
{
    void *h = *(void **)(GetCharacterClass(a) + 0x940);
    if (h != a && *(s16 *)(GetCharacterClass(h) + 0x360) == 3)
        return h;
    return 0;
}

void nico_setPlayerHorseBridleDoubleShort(void *a)
{
    void *h = getHorse(a);
    if (h != 0)
        nico_setHorseBridleDoubleShort(h);
}

void nico_setPlayerHorseBridleLeftLong(void *a)
{
    void *h = getHorse(a);
    if (h != 0)
        nico_setHorseBridleLeftLong(h);
}

void nico_setPlayerHorseBridleRightLong(void *a)
{
    void *h = getHorse(a);
    if (h != 0)
        nico_setHorseBridleRightLong(h);
}

void nico_setPlayerHorseBridleDoubleLong(void *a)
{
    void *h = getHorse(a);
    if (h != 0)
        nico_setHorseBridleDoubleLong(h);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", nico_ChangePlayerHorseRidingControlWithParentObj);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", nico_ChangePlayerHorseRidingControlWithVCol);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", nico_ChangePlayerHorseRidingControlWithHCol);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", nico_ForceChangePlayerHorseRidingControl);

void *GetGeometryPointerObject(void *chara);
void SendCharaNodeParentSetMsg(void *chara, void *parent, s32 flag);

void nico_ChangePlayerHorseRidingParentWithVCol(void *o)
{
    u8 *c = GetCharacterClass(o);
    if (*(s32 *)(c + 0xDB0) != 0)
    {
        SendCharaNodeParentSetMsg(o, GetGeometryPointerObject(c + 0xDD0), 0x10000);
        c = 0;
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", nico_setPlayerEdgePoint);
void nico_setPlayerEdgePoint(void *a0)
{
    player_setEdgeHangPointGeometry(a0, GetSCRCharaAIWorkPtr() + 0x1A40);
}

void nico_setPlayerGripPoint(void *a0)
{
    player_setGripHangPointGeometry(a0, GetSCRCharaAIWorkPtr() + 0x1A40);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", SetPlayerDangerEdgePoint);
void SetPlayerDangerEdgePoint(void *a0)
{
    player_setDangerEdgePoint(a0, GetSCRCharaAIWorkPtr() + 0x1B30);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", SetPlayerDangerEdgeOtherSidePlanePoint);
void SetPlayerDangerEdgeOtherSidePlanePoint(void *a0)
{
    player_setDangerEdgeOtherSidePlanePoint(a0, GetSCRCharaAIWorkPtr() + 0x1B30);
}

s32 SetInertiaRotInterpMode(void *obj);

s32 SetPlayerDangerEdgeOtherSidePlanePointWithInertiaRot(void *a0)
{
    player_setDangerEdgeOtherSidePlanePoint(a0, GetSCRCharaAIWorkPtr() + 0x1B30);
    return SetInertiaRotInterpMode(a0);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", SetPlayerHellDangerPoint);
void SetPlayerHellDangerPoint(void *a0)
{
    player_setHellDangerPoint(a0, GetSCRCharaAIWorkPtr() + 0x1B30);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", nico_playerClothOverSurfDetectFunc);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", nico_playerRootReverseByZRot);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", func_4008EFE8);
void func_4008EFE8(void)
{
    u8 *work = GetSCRCharaAIWorkPtr();
    s32 tmp = *(s32 *)(work + 0x108);
    *(s32 *)(work + 0x108) = 0;
    *(s32 *)(work + 0x10C) = tmp;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", func_4008F010);
void func_4008F010(void)
{
    u8 *work = GetSCRCharaAIWorkPtr();
    s32 tmp = *(s32 *)(work + 0x108);
    *(s32 *)(work + 0x108) = 0;
    *(s32 *)(work + 0x10C) = tmp;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", func_4008F038);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", func_4008F070);
void func_4008F070(void)
{
    nico_delOmakeItem();
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", func_4008F088);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", func_4008F0E8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", func_4008F148);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", func_4008F250);
void func_4008F250(void)
{
    u8 *work = GetSCRCharaAIWorkPtr();
    *(s32 *)(work + 0xE0) = 1;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", func_4008F278);
void func_4008F278(void)
{
    u8 *work = GetSCRCharaAIWorkPtr();
    *(s32 *)(work + 0xE0) = 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", func_4008F298);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", func_4008F358);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", func_4008F418);
void func_4008F418(void)
{
    setFullPower();
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", func_4008F430);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", func_4008F478);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", func_4008F5B8);
void func_4008F5B8(void)
{
    gameflowSetPauseEnable(0);
    gameflowSetCaptionPause(1);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", func_4008F5D8);
void func_4008F5D8(void)
{
    gameflowSetPauseEnable(1);
    gameflowSetCaptionPause(0);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", func_4008F5F8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", func_4008F638);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", func_4008F678);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", func_4008F6B8);
s32 func_4008F6B8(void *a0)
{
    u8 *motion = GAMEUTIL_get_motion_kind(a0);
    if (motion != NULL) {
        return *(u16 *)(motion + 0x6E) & 0x7;
    }
    return 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", func_4008F6E8);

void func_4008F7E0(void) {
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", func_4008F7E8);
