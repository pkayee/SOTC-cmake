#include "common.h"

extern s32 D_40131B4C;

u8 *GetSCRCharaAIWorkPtr();
u8 *GetLayoutClass(void *chara);
void boot_camera_lws_animation_by_script(s32 param);
extern s32 SCameraLwsAnimationParam_PLAYER_ACCUMULATE_ATTACK_CAM_VIB;
extern char gcGlobalVar[];
void *SCRGetFirstObj(void *);
int get_game_camera(int);
int get_main_cameraman();
void begin_object_interest_game_camera(int, int);
int ClipCollisionDirectCallBackOneObj(void *, void *, void *, void *, int, int, int, int);
extern char rootPtn[];
extern float IdentityQuaternion[];
extern float ZeroPoint[];
void SetGeometryPointerNodePosState(void *, void *, int, float *, float *);
void loadObj(void *, void *, void *, void *, int, int);

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

/* Inline, so gcc defers its own copy until after the caller below. */
static inline int nico_CheckThroughObject_inl(void *a, char *o)
{
    char buf[0x50];
    if (o != 0) {
        void *t = *(void **)(o + 8);
        u8 *lc;
        if (t == 0) return 0;
        lc = GetLayoutClass(a);
        if (ClipCollisionDirectCallBackOneObj(buf, *(void **)(lc + 0x138), *(void **)(lc + 0x134), t, 0, 0, 0, 0) != 0) return 1;
    }
    return 0;
}

int nico_CheckPlayerThroughObject(char *o)
{
    void *p = SCRGetFirstObj(gcGlobalVar + 0x2B0);
    if (p == 0) return 0;
    return nico_CheckThroughObject_inl(p, o);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0104_nico_CheckPlayerThroughObject", nico_CheckThroughObject);
int nico_CheckThroughObject(void *a, char *o)
{
    char buf[0x50];
    if (o != 0) {
        void *t = *(void **)(o + 8);
        u8 *lc;
        if (t == 0) return 0;
        lc = GetLayoutClass(a);
        if (ClipCollisionDirectCallBackOneObj(buf, *(void **)(lc + 0x138), *(void **)(lc + 0x134), t, 0, 0, 0, 0) != 0) return 1;
    }
    return 0;
}

typedef struct {
    int a[4];
    int b[3];
    int c;
    void *geom;
    int d[2];
    int e;
    int f[3];
} LoadReq;

/* req.e is assigned twice: gcc keeps one store, but the duplicate gives the
   original store order. */
void nico_CreatePlayerGetItemObject(void *node, void *parent)
{
    char geom[0x40];
    LoadReq req;

    SetGeometryPointerNodePosState(geom, node, 0x10000, IdentityQuaternion, ZeroPoint);
    req.e = 1;
    req.a[0] = 0;
    req.a[1] = 0;
    req.a[2] = 0;
    req.a[3] = 0;
    req.geom = geom;
    req.b[0] = 0;
    req.b[1] = 0;
    req.b[2] = 0;
    req.c = 1;
    req.d[0] = 0;
    req.d[1] = 0;
    req.e = 1;
    req.f[0] = 0;
    req.f[1] = 0;
    req.f[2] = 0;
    loadObj(parent, &req, rootPtn, gcGlobalVar + 0x280, 0, 4);
}

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

void unloadObj(void *);
void nico_ResetCharacterObjFallDownInfo(void *);

void nico_deletePlayerParachute(void *actor)
{
    void **p = (void **)(GetSCRCharaAIWorkPtr(actor) + 0x1BE0);
    if (*p != 0) {
        unloadObj(*p);
        *p = 0;
    }
    nico_ResetCharacterObjFallDownInfo(actor);
}

extern void ColCont2_Release(void *);
extern void player_resetHangPointWork(void *);
extern void player_resetAvoidDangerCliffWork(void *, void *);
extern void player_resetSlipEffect(void *, void *);

static inline void deletePlayerParachute_inl(void *actor)
{
    void **p = (void **)(GetSCRCharaAIWorkPtr(actor) + 0x1BE0);
    if (*p != 0) {
        unloadObj(*p);
        *p = 0;
    }
    nico_ResetCharacterObjFallDownInfo(actor);
}

void func_4008DAB8(void *a)
{
    u8 *w = GetSCRCharaAIWorkPtr(a);

    ColCont2_Release(w + 0xD60);
    player_resetHangPointWork(w + 0x1A40);
    player_resetAvoidDangerCliffWork(a, w + 0x1B30);
    deletePlayerParachute_inl(a);
    player_resetSlipEffect(a, w + 0x1BE8);
}

extern char *GetCharacterClass(void *);
extern void nico_resetHorseRidingStatusForHorse(void *);

static inline void *getHorse(void *a)
{
    void *h = *(void **)(GetCharacterClass(a) + 0x940);
    if (h != a && *(short *)(GetCharacterClass(h) + 0x360) == 3)
        return h;
    return 0;
}

void nico_resetPlayerHorseBridle(void *a)
{
    void *h = getHorse(a);
    if (h != 0)
        nico_resetHorseRidingStatusForHorse(h);
}

extern void *getPlayerColCont2(void *);

static inline void resetPlayerHorseBridle_inl(void *a)
{
    void *h = getHorse(a);
    if (h != 0)
        nico_resetHorseRidingStatusForHorse(h);
}

void func_4008DBB0(void *a)
{
    u8 *w = GetSCRCharaAIWorkPtr(a);

    resetPlayerHorseBridle_inl(a);
    *(s32 *)(GetSCRCharaAIWorkPtr(a) + 0xD28) = 0;
    ColCont2_Release(getPlayerColCont2(a));
    player_resetHangPointWork(w + 0x1A40);
    player_resetAvoidDangerCliffWork(a, w + 0x1B30);
    player_resetSlipEffect(a, w + 0x1BE8);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0104_nico_CheckPlayerThroughObject", func_4008DC60);
extern u32 charrootdyn_getCollisionAttribute(void);

s32 func_4008DC60(void)
{
    u32 attr = charrootdyn_getCollisionAttribute();
    s32 ret = 0;

    if (((attr & 3) == 1) || ((attr & 4) != 0)) {
        ret = 1;
    }
    return ret;
}

void *GAMEUTIL_get_motion_kind(void *chara);

void func_4008DCA0(void *chara, u8 *obj)
{
    if (*(s32 *)(obj + 0xD1C) == 1) {
        u8 *m = GAMEUTIL_get_motion_kind(chara);
        if (m == 0 || *(s32 *)(m + 0x90) != 0x31) {
            *(s32 *)(obj + 0xD1C) = 0;
        }
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0104_nico_CheckPlayerThroughObject", SCRPlayerRotateStop);
void SCRPlayerRotateStop(void *chara)
{
    u8 *layout = GetLayoutClass(chara);
    u8 *p = *(u8 **)(layout + 0x19C);
    *(f32 *)(p + 0x50) = *(f32 *)(p + 0x50) * 0.5f;
}

extern void _omakeGetFlagSet(int);
extern void _omakeSelectFlagSet(int);
extern void SCRPlayerGetWeapon(int);
extern void SetLayoutObjAccessSwitch(void *, int);
extern void isysRequestDeleteObj(void *);

void SCRPlayerPickUp(void *a)
{
    char *w = GetSCRCharaAIWorkPtr(a);
    if (*(void **)(w + 0xD20) == 0)
        return;
    *(s32 *)(w + 0x70) = 9;
    _omakeGetFlagSet(0x10);
    _omakeSelectFlagSet(0x10);
    SCRPlayerGetWeapon(9);
    SetLayoutObjAccessSwitch(*(void **)(w + 0xD20), 0);
    *(void **)(w + 0xD20) = 0;
    if (*(void **)(w + 0x110) != 0) {
        isysRequestDeleteObj(*(void **)(w + 0x110));
        *(void **)(w + 0x110) = 0;
    }
}

void SCRPlayerCallHorse(void *actor)
{
    int temp_s0;
    int temp_v0;

    (*(signed char *)((char *)(GetSCRCharaAIWorkPtr(actor)) + 0xD2C)) = 1;
    temp_s0 = get_game_camera(get_main_cameraman());
    temp_v0 = (int)SCRGetFirstObj(gcGlobalVar + 0x2B4);
    if (temp_v0 != 0) {
        begin_object_interest_game_camera(temp_s0, temp_v0);
    }
}

void end_object_interest_game_camera(int);

void SCRPlayerCallHorseEnd(void *actor)
{
    void *temp_s0;

    temp_s0 = GetSCRCharaAIWorkPtr(actor);
    end_object_interest_game_camera(get_game_camera(get_main_cameraman()));
    (*(signed char *)((char *)(temp_s0) + 0xD2C)) = 0;
}

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

void torchAttached(void *actor, float fparg0)
{
    void *temp_v0;

    temp_v0 = GetSCRCharaAIWorkPtr(actor);
    if ((*(int *)((char *)(temp_v0) + 0x70)) == 9) {
        (*(float *)((char *)(temp_v0) + 0x84)) = fparg0;
        (*(signed char *)((char *)(temp_v0) + 0x95)) = 0;
        (*(float *)((char *)(temp_v0) + 0x88)) = (float) (*(float *)((char *)(gcGlobalVar) + 0x180));
    }
}

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

void ChangeCharacterObjControlTarget(int, int);
void ChangeCharacterObjControlledTarget(int, int, int, int);
void ResetCharacterClassSyncMode(void *);
void ContinueMotionCurrentSpeed(void *);
extern unsigned char InitialGeometryPointer[];

void nico_ResetPlayerHorseRidingControlAndContinueMotionCurrentSpeed(void *arg0)
{
    void *temp_s0;
    void *temp_s2;

    temp_s0 = (*(void **)((char *)(GetCharacterClass(arg0)) + 0x950));
    temp_s2 = GetCharacterClass(temp_s0);
    ChangeCharacterObjControlTarget((int) temp_s0, (int) temp_s0);
    ChangeCharacterObjControlledTarget((int) arg0, (int) arg0, (int) InitialGeometryPointer, 0);
    ResetCharacterClassSyncMode(temp_s2);
    (*(int *)((char *)(GetSCRCharaAIWorkPtr(temp_s0)) + 0xD28)) = 0;
    nico_resetHorseRidingStatusForHorse(arg0);
    ContinueMotionCurrentSpeed(arg0);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0104_nico_CheckPlayerThroughObject", func_4008E288);
