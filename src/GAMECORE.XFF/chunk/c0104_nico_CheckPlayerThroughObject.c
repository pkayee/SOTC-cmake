#include "common.h"

extern s32 D_40131B4C;

u8 *GetSCRCharaAIWorkPtr();
u8 *GetLayoutClass(void *chara);
void boot_camera_lws_animation_by_script(s32 param);
extern s32 SCameraLwsAnimationParam_PLAYER_ACCUMULATE_ATTACK_CAM_VIB;

void RequestCharacterMotionShiftFunc(void *chara, void (*func)(void));
void func_4008ADA8(void);
void func_4008EFE8(void);
void func_4008AEF0(void);
void func_4008F010(void);
void func_4008F038(void);
void func_4008F070(void);
void func_4008F088(void);
void func_4008B660(void);
void func_4008B7E8(void);
void func_4008B980(void);
void func_4008F0E8(void);
void func_4008BAC0(void);
void func_4008BBF0(void);
void func_4008F148(void);
void func_4008F250(void);
void func_4008F278(void);
void func_4008F298(void);
void func_4008F358(void);
void func_4008BD20(void);
void func_4008BE38(void);
void func_4008BF50(void);
void func_4008C068(void);
void func_4008F418(void);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0104_nico_CheckPlayerThroughObject", nico_CheckPlayerThroughObject);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0104_nico_CheckPlayerThroughObject", nico_CheckThroughObject);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0104_nico_CheckPlayerThroughObject", nico_CreatePlayerGetItemObject);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0104_nico_CheckPlayerThroughObject", player_IsHorseCtrlOff);
s32 player_IsHorseCtrlOff(void)
{
    return D_40131B4C;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0104_nico_CheckPlayerThroughObject", player_GetBoundDamageLevel);
f32 player_GetBoundDamageLevel(void)
{
    u8 *work = GetSCRCharaAIWorkPtr();
    u8 *p = *(u8 **)(work + 0x130);
    return *(f32 *)(p + 0x54);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0104_nico_CheckPlayerThroughObject", isWeaponTargetMarker);
u8 isWeaponTargetMarker(void)
{
    return *(GetSCRCharaAIWorkPtr() + 0x50);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0104_nico_CheckPlayerThroughObject", isWeaponTargetReady);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0104_nico_CheckPlayerThroughObject", func_4008D978);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0104_nico_CheckPlayerThroughObject", nico_deletePlayerParachute);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0104_nico_CheckPlayerThroughObject", func_4008DAB8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0104_nico_CheckPlayerThroughObject", nico_resetPlayerHorseBridle);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0104_nico_CheckPlayerThroughObject", func_4008DBB0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0104_nico_CheckPlayerThroughObject", func_4008DC60);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0104_nico_CheckPlayerThroughObject", func_4008DCA0);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0104_nico_CheckPlayerThroughObject", SCRPlayerRotateStop);
void SCRPlayerRotateStop(void *chara)
{
    u8 *layout = GetLayoutClass(chara);
    u8 *p = *(u8 **)(layout + 0x19C);
    *(f32 *)(p + 0x50) = *(f32 *)(p + 0x50) * 0.5f;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0104_nico_CheckPlayerThroughObject", SCRPlayerPickUp);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0104_nico_CheckPlayerThroughObject", SCRPlayerCallHorse);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0104_nico_CheckPlayerThroughObject", SCRPlayerCallHorseEnd);

void SCRPlayerReset(void) {
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0104_nico_CheckPlayerThroughObject", SCRWeaponReload);
void SCRWeaponReload(void *chara)
{
    RequestCharacterMotionShiftFunc(chara, func_4008ADA8);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0104_nico_CheckPlayerThroughObject", SCRFoodTakeBegin);
void SCRFoodTakeBegin(void *chara)
{
    RequestCharacterMotionShiftFunc(chara, func_4008EFE8);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0104_nico_CheckPlayerThroughObject", SCRFoodTakeEnd);
void SCRFoodTakeEnd(void *chara)
{
    RequestCharacterMotionShiftFunc(chara, func_4008AEF0);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0104_nico_CheckPlayerThroughObject", SCRItemTakeBegin);
void SCRItemTakeBegin(void *chara)
{
    RequestCharacterMotionShiftFunc(chara, func_4008F010);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0104_nico_CheckPlayerThroughObject", SCRItemTakeEnd);
void SCRItemTakeEnd(void *chara)
{
    RequestCharacterMotionShiftFunc(chara, func_4008F038);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0104_nico_CheckPlayerThroughObject", SCRItemTakeDelete);
void SCRItemTakeDelete(void *chara)
{
    RequestCharacterMotionShiftFunc(chara, func_4008F070);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0104_nico_CheckPlayerThroughObject", SCRPlayerBeginAccumulateAttack);
void SCRPlayerBeginAccumulateAttack(void)
{
    u8 *work = GetSCRCharaAIWorkPtr();
    *(s32 *)(work + 0xD1C) = 1;
    boot_camera_lws_animation_by_script(SCameraLwsAnimationParam_PLAYER_ACCUMULATE_ATTACK_CAM_VIB);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0104_nico_CheckPlayerThroughObject", SCRArrowStart);
void SCRArrowStart(void *chara)
{
    RequestCharacterMotionShiftFunc(chara, func_4008F088);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0104_nico_CheckPlayerThroughObject", SCRArrowContinue);
void SCRArrowContinue(void *chara)
{
    RequestCharacterMotionShiftFunc(chara, func_4008B660);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0104_nico_CheckPlayerThroughObject", SCRArrowLoopStart);
void SCRArrowLoopStart(void *chara)
{
    RequestCharacterMotionShiftFunc(chara, func_4008B7E8);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0104_nico_CheckPlayerThroughObject", SCRArrowLoopEnd);
void SCRArrowLoopEnd(void *chara)
{
    RequestCharacterMotionShiftFunc(chara, func_4008B980);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0104_nico_CheckPlayerThroughObject", SCRHarpoonStart);
void SCRHarpoonStart(void *chara)
{
    RequestCharacterMotionShiftFunc(chara, func_4008F0E8);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0104_nico_CheckPlayerThroughObject", SCRHarpoonContinue);
void SCRHarpoonContinue(void *chara)
{
    RequestCharacterMotionShiftFunc(chara, func_4008BAC0);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0104_nico_CheckPlayerThroughObject", SCRHarpoonLoopStart);
void SCRHarpoonLoopStart(void *chara)
{
    RequestCharacterMotionShiftFunc(chara, func_4008BBF0);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0104_nico_CheckPlayerThroughObject", SCRHarpoonLoopEnd);
void SCRHarpoonLoopEnd(void *chara)
{
    RequestCharacterMotionShiftFunc(chara, func_4008F148);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0104_nico_CheckPlayerThroughObject", SCRPlayerSendDamageStart);
void SCRPlayerSendDamageStart(void *chara)
{
    RequestCharacterMotionShiftFunc(chara, func_4008F250);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0104_nico_CheckPlayerThroughObject", SCRPlayerSendDamageEnd);
void SCRPlayerSendDamageEnd(void *chara)
{
    RequestCharacterMotionShiftFunc(chara, func_4008F278);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0104_nico_CheckPlayerThroughObject", SCRPlayerSendDamageLater);
void SCRPlayerSendDamageLater(void *chara)
{
    RequestCharacterMotionShiftFunc(chara, func_4008F298);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0104_nico_CheckPlayerThroughObject", SCRPlayerSendDiveDamageLater);
void SCRPlayerSendDiveDamageLater(void *chara)
{
    RequestCharacterMotionShiftFunc(chara, func_4008F358);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0104_nico_CheckPlayerThroughObject", SCRPlayerSowrdHitSound);
void SCRPlayerSowrdHitSound(void *chara)
{
    RequestCharacterMotionShiftFunc(chara, func_4008BD20);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0104_nico_CheckPlayerThroughObject", SCRPlayerSowrdHitSoundMiddle);
void SCRPlayerSowrdHitSoundMiddle(void *chara)
{
    RequestCharacterMotionShiftFunc(chara, func_4008BE38);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0104_nico_CheckPlayerThroughObject", SCRPlayerSowrdHitSoundLarge);
void SCRPlayerSowrdHitSoundLarge(void *chara)
{
    RequestCharacterMotionShiftFunc(chara, func_4008BF50);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0104_nico_CheckPlayerThroughObject", SCRPlayerSowrdDiveHitSound);
void SCRPlayerSowrdDiveHitSound(void *chara)
{
    RequestCharacterMotionShiftFunc(chara, func_4008C068);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0104_nico_CheckPlayerThroughObject", SCRPlayerFullPower);
void SCRPlayerFullPower(void *chara)
{
    RequestCharacterMotionShiftFunc(chara, func_4008F418);
}

void func_4008E160(void) {
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0104_nico_CheckPlayerThroughObject", torchAttached);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0104_nico_CheckPlayerThroughObject", sendArrowPos);
void sendArrowPos(u128 *dst, void *chara)
{
    u8 *work = GetSCRCharaAIWorkPtr(chara);
    *dst = *(u128 *)(work + 0x10);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0104_nico_CheckPlayerThroughObject", sendArrowInfo);
s32 sendArrowInfo(void)
{
    return *(s32 *)(GetSCRCharaAIWorkPtr() + 0x20);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0104_nico_CheckPlayerThroughObject", nico_ResetPlayerHorseRidingControlAndContinueMotionCurrentSpeed);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0104_nico_CheckPlayerThroughObject", func_4008E288);
