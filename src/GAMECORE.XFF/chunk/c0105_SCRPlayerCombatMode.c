#include "common.h"

void nico_delOmakeItem(void);
void setFullPower(void);
void RequestCharacterMotionShiftFunc(void *chara, void (*func)(void));
u8 *GetSCRCharaAIWorkPtr();
void gameflowSetPauseEnable(s32 enable);
void gameflowSetCaptionPause(s32 pause);
void *GAMEUTIL_get_motion_kind(void *chara);
void player_setDangerEdgeOtherSidePlanePoint(void *chara, u8 *point);
void player_setDangerEdgePoint(void *chara, u8 *point);
void player_setHellDangerPoint(void *chara, u8 *point);
void player_setEdgeHangPointGeometry(void *chara, u8 *point);
void player_setGripHangPointGeometry(void *chara, u8 *point);
void func_4008C7C8(void);
void func_4008F430();
s32 SCRSetupWeaponPlayer(void *chara, s32 weapon);
void func_4008F478(void);
void func_4008F5B8(void);
void func_4008F5D8(void);
void func_4008F5F8(void *a0);
void func_4008F638(void *a0);
void func_4008F678(void);
void func_4008F7E0(void);
u8 *GetCharacterClass(void *chara);
void nico_setHorseBridleDoubleShort(void *actor);
void nico_setHorseBridleLeftLong(void *actor);
void nico_setHorseBridleRightLong(void *actor);
void nico_setHorseBridleDoubleLong(void *actor);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", SCRPlayerCombatMode);
/* READY 100 percent in scratch (rea-c0105). Loop-free; the camera-mode test is written as an or-condition around the horse block, and the motion-kind helper is a local static inline. */

extern s32 get_main_cameraman(void);
extern u8 *get_game_camera(s32 man);
extern s32 get_boss_interest_position_game_camera(void *out, u8 *cam);
extern s32 GAMEUTIL_get_boss_interest_position(void *out, s32 kind);
extern s32 get_game_camera_cur_mode(u8 *cam);
extern void *GAMEUTIL_get_horse_obj(void);
extern u8 *GetLayoutClass(void *o);
/* READY 100 percent in scratch (rea-c0105). Leave GetGeometryPointerObject and SendCharaNodeParentSetMsg undeclared here (implicit int): prototyping either one drops to 99.6. geo local must be declared inside the if block. */

extern s32 *SkelFocusDef_PLAYER_HAND_A_L;
extern f32 D_40134730[];
void nico_setHorseRidingStatusForHorse(void *actor, void *parent, s32 node, const f32 *point, f32 span);
void SendCharaControlChangeMsg(void *a, void *b);
void SendCharaControlledChangeMsg(void *a, void *b, void *geo);
void SendCharaAddMotionSyncStartMsg(void *a, void *b);

/* READY 100 percent in scratch (rea-c0105). Leave GetGeometryPointerObject and SendCharaNodeParentSetMsg undeclared here (implicit int): prototyping either one drops to 99.6. */

extern s32 *SkelFocusDef_PLAYER_HAND_A_L;

/* READY 100 percent in scratch (rea-c0105). Leave GetGeometryPointerObject and SendCharaNodeParentSetMsg undeclared here (implicit int). u8 geo[64] on the stack. */

extern s32 *SkelFocusDef_PLAYER_HAND_A_L;
extern u8 gcGlobalVar[];
extern u8 IdentityQuaternion[];
extern u8 ZeroPoint[];
s32 SCRGetFirstObj();
void SetGeometryPointerNodePosState(void *, void *, void *, void *, void *);

/* READY 100 percent in scratch (rea-c0105). Explicit r=0/r=1 in every arm (if/else inside if/else); r=1 default forms give 86. */

u8 *GetCharacterClass(void *chara);

/* READY 100 percent in scratch (rea-c0105). Same shape as head with kind 2, result compared to 1, offset 0x200. */

extern u8 gcGlobalVar[];
s32 func_4008F6B8(void *a0);
s32 func_4008F6E8(u128 *out, u8 *work, void *obj);
void begin_motion_ik_interest(u8 *ik);
void request_end_motion_ik_interest(u8 *ik);
void doit_motion_ik_interest(u8 *ik, void *chara, u128 *pos, f32 speed);

/* READY 100 percent in scratch (rea-c0105). Keep work + 0x170 spelled out at each use (a hoisted ik local scores 87.6). ZeroPoint must be u8 array (matches nico_ForceChange READY). Needs func_4008F6E8 from this dir. */

extern u8 gcGlobalVar[];

/* READY 100 percent in scratch (rea-c0105). Own inline helper because getHorse is defined later in the file. */

extern s32 *SkelFocusDef_PLAYER_HAND_A_L;
static inline void *getHorseB(void *a)
{
    void *h = *(void **)(GetCharacterClass(a) + 0x940);
    if (h != a && *(s16 *)(GetCharacterClass(h) + 0x360) == 3)
        return h;
    return 0;
}

static inline s32 motionLow3(void *a)
{
    u8 *motion = GAMEUTIL_get_motion_kind(a);
    if (motion != NULL)
        return *(u16 *)(motion + 0x6E) & 0x7;
    return 0;
}

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

void nico_playerIK_attention_head(void **a0)
{
    void *obj = *a0;
    s32 kind = func_4008F6B8(obj);
    u8 *work = GetSCRCharaAIWorkPtr(obj);
    u128 pos;
    if (kind == 1 && func_4008F6E8(&pos, work, obj) == kind)
    {
        begin_motion_ik_interest(work + 0x170);
    }
    else
    {
        request_end_motion_ik_interest(work + 0x170);
        pos = *(u128 *)ZeroPoint;
    }
    doit_motion_ik_interest(work + 0x170, a0, &pos, *(f32 *)(gcGlobalVar + 0x180));
}

void nico_playerIK_attention_chest(void **a0)
{
    void *obj = *a0;
    s32 kind = func_4008F6B8(obj);
    u8 *work = GetSCRCharaAIWorkPtr(obj);
    u128 pos;
    if (kind == 2 && func_4008F6E8(&pos, work, obj) == 1)
    {
        begin_motion_ik_interest(work + 0x200);
    }
    else
    {
        request_end_motion_ik_interest(work + 0x200);
        pos = *(u128 *)ZeroPoint;
    }
    doit_motion_ik_interest(work + 0x200, a0, &pos, *(f32 *)(gcGlobalVar + 0x180));
}

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

void nico_setPlayerHorseBridle(void *a)
{
    void *h = getHorseB(a);
    if (h != 0)
        nico_setHorseRidingStatusForHorse(h, a, SkelFocusDef_PLAYER_HAND_A_L[2], D_40134730, 0.035f);
}

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

void nico_ChangePlayerHorseRidingControlWithParentObj(void *o)
{
    u8 *c = GetLayoutClass(o);
    if (*(s32 *)(c + 0x124) != 0)
    {
        u8 *geo = c + 0xC0;
        u8 *work = GetSCRCharaAIWorkPtr(o);
        void *p = GetGeometryPointerObject(geo);
        SendCharaControlChangeMsg(o, p);
        SendCharaControlledChangeMsg(p, o, geo);
        SendCharaAddMotionSyncStartMsg(o, p);
        SendCharaNodeParentSetMsg(o, GetGeometryPointerObject(geo), 0x10000);
        nico_setHorseRidingStatusForHorse(p, o, SkelFocusDef_PLAYER_HAND_A_L[2], D_40134730, 0.035f);
        *(s32 *)(work + 0xD28) = 1;
    }
}

void nico_ChangePlayerHorseRidingControlWithVCol(void *o)
{
    u8 *c = GetCharacterClass(o);
    if (*(s32 *)(c + 0xDB0) != 0)
    {
        u8 *geo = c + 0xDD0;
        u8 *work = GetSCRCharaAIWorkPtr(o);
        void *p = GetGeometryPointerObject(geo);
        SendCharaControlChangeMsg(o, p);
        SendCharaControlledChangeMsg(p, o, geo);
        SendCharaAddMotionSyncStartMsg(o, p);
        SendCharaNodeParentSetMsg(o, GetGeometryPointerObject(geo), 0x10000);
        nico_setHorseRidingStatusForHorse(p, o, SkelFocusDef_PLAYER_HAND_A_L[2], D_40134730, 0.035f);
        *(s32 *)(work + 0xD28) = 1;
    }
}

void nico_ChangePlayerHorseRidingControlWithHCol(void *o)
{
    u8 *c = GetCharacterClass(o);
    if (*(s32 *)(c + 0xED0) != 0)
    {
        u8 *geo = c + 0xEE0;
        u8 *work = GetSCRCharaAIWorkPtr(o);
        void *p = GetGeometryPointerObject(geo);
        SendCharaControlChangeMsg(o, p);
        SendCharaControlledChangeMsg(p, o, geo);
        SendCharaAddMotionSyncStartMsg(o, p);
        SendCharaNodeParentSetMsg(o, GetGeometryPointerObject(geo), 0x10000);
        nico_setHorseRidingStatusForHorse(p, o, SkelFocusDef_PLAYER_HAND_A_L[2], D_40134730, 0.035f);
        *(s32 *)(work + 0xD28) = 1;
    }
}

void nico_ForceChangePlayerHorseRidingControl(void *o)
{
    u8 geo[64];
    s32 first = SCRGetFirstObj(gcGlobalVar + 0x2B4);
    if (first != 0)
    {
        u8 *work;
        void *p;
        SetGeometryPointerNodePosState(geo, (void *)first, 0, IdentityQuaternion, ZeroPoint);
        work = GetSCRCharaAIWorkPtr(o);
        p = GetGeometryPointerObject(geo);
        SendCharaControlChangeMsg(o, p);
        SendCharaControlledChangeMsg(p, o, geo);
        SendCharaAddMotionSyncStartMsg(o, p);
        SendCharaNodeParentSetMsg(o, GetGeometryPointerObject(geo), 0x10000);
        nico_setHorseRidingStatusForHorse(p, o, SkelFocusDef_PLAYER_HAND_A_L[2], D_40134730, 0.035f);
        *(s32 *)(work + 0xD28) = 1;
    }
}

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

s32 nico_playerClothOverSurfDetectFunc(void *o)
{
    u8 *c = GetCharacterClass(o);
    s32 r;
    if (*(s8 *)(c + 0x35E) != 0) {
        if (0.8f < *(f32 *)(c + 0x1020))
            r = 0;
        else
            r = 1;
    } else
        r = 1;
    return r;
}

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

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", func_4008F038);
void nico_getOmakeItem(s32 item);
void func_4008F038(void)
{
    u8 *work = GetSCRCharaAIWorkPtr();
    nico_getOmakeItem(*(s32 *)(work + 0x10C));
    *(s32 *)(work + 0x108) = 0;
    *(s32 *)(work + 0x10C) = 0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", func_4008F070);
void func_4008F070(void)
{
    nico_delOmakeItem();
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", func_4008F088);
extern u8 gcGlobalVar[];
void func_4008B198(s32 obj, u8 *work);
f32 GetWeaponRange(void);
void begin_nico_sight_on(u8 *p, s32 obj, u8 *x, f32 range);
void func_4008B660(s32 obj);

void func_4008F088(s32 obj)
{
    u8 *work;

    work = GetSCRCharaAIWorkPtr();
    func_4008B198(obj, work);
    begin_nico_sight_on(work + 0x290, obj, gcGlobalVar + 0x260, GetWeaponRange());
    func_4008B660(obj);
}

void func_4008BAC0(s32 obj);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", func_4008F0E8);
void func_4008F0E8(s32 obj)
{
    u8 *work;

    work = GetSCRCharaAIWorkPtr();
    func_4008B198(obj, work);
    begin_nico_sight_on(work + 0x290, obj, gcGlobalVar + 0x260, GetWeaponRange());
    func_4008BAC0(obj);
}

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

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", func_4008F430);
void func_4008F430(void *chara)
{
    u8 *work = GetSCRCharaAIWorkPtr() + 0x60;

    if (*(s32 *)(work + 0x18) == 0) {
        *(s32 *)(work + 0x18) = SCRSetupWeaponPlayer(chara, *(s32 *)(work + 0x10));
    }
}

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

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", func_4008F5F8);
void setSelectWeapon(int w);
void func_4008C660(void *chara, s32 arg);
void func_4008F5F8(void *a0)
{
    u8 *work = GetSCRCharaAIWorkPtr(a0);
    *(s32 *)(work + 0x70) = 1;
    *(s32 *)(work + 0x7C) = 1;
    setSelectWeapon(1);
    func_4008C660(a0, -1);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", func_4008F638);
void func_4008F638(void *a0)
{
    u8 *work = GetSCRCharaAIWorkPtr(a0);
    *(s32 *)(work + 0x70) = 8;
    *(s32 *)(work + 0x7C) = 8;
    setSelectWeapon(8);
    func_4008C660(a0, -1);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", func_4008F678);
void *nico_GetPlayerCharacterRidingHorseObject(void);
void setHorseForceScriptKey(void *actor, s32 key);
extern s32 ScriptCtrlDef_SCRHorseKicked;

void func_4008F678(void)
{
    void *obj = nico_GetPlayerCharacterRidingHorseObject();

    if (obj != NULL) {
        setHorseForceScriptKey(obj, ScriptCtrlDef_SCRHorseKicked);
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", func_4008F6B8);
s32 func_4008F6B8(void *a0)
{
    u8 *motion = GAMEUTIL_get_motion_kind(a0);
    if (motion != NULL) {
        return *(u16 *)(motion + 0x6E) & 0x7;
    }
    return 0;
}

s32 func_4008F6E8(u128 *out, u8 *work, void *obj)
{
    s32 r = 0;
    s32 w;
    u8 *cam = get_game_camera(get_main_cameraman());
    if (get_boss_interest_position_game_camera(out, cam) == 1 || ((w = *(s32 *)(work + 0x160)) == 1 && GAMEUTIL_get_boss_interest_position(out, 1) == w))
        r = 1;
    if (get_game_camera_cur_mode(cam) == 5 || motionLow3(obj) == 2)
    {
        void *horse = GAMEUTIL_get_horse_obj();
        if (horse != 0)
        {
            r = 1;
            *out = **(u128 **)(GetLayoutClass(horse) + 0x134);
        }
    }
    return r;
}

void func_4008F7E0(void) {
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0105_SCRPlayerCombatMode", func_4008F7E8);
