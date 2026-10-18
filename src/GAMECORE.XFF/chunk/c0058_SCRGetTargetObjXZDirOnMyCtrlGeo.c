#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0058_SCRGetTargetObjXZDirOnMyCtrlGeo", SCRGetTargetObjXZDirOnMyCtrlGeo);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0058_SCRGetTargetObjXZDirOnMyCtrlGeo", SCRGetXZAngle);
f32 iosGetATan2fExact(f32 arg0, f32 arg1);
f32 SCRGetXZAngle(f32 *v)
{
    return iosGetATan2fExact(v[0], v[2]);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0058_SCRGetTargetObjXZDirOnMyCtrlGeo", SCRGetYZAngle);
f32 SCRGetYZAngle(f32 *v)
{
    return iosGetATan2fExact(v[1], v[2]);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0058_SCRGetTargetObjXZDirOnMyCtrlGeo", SCRCharaTurn);
void *GetCharacterClass();
void SCRCharaTurn(u8 *a0, f32 turn)
{
    f32 cur = *(f32 *)((u8 *)GetCharacterClass() + 0x7D8);
    f32 scaled = cur * 0.9f;
    f32 part = turn * 0.0999999940395355224609375f;
    u8 *cc = (u8 *)GetCharacterClass(a0);

    *(f32 *)(cc + 0x7D8) = scaled + part;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0058_SCRGetTargetObjXZDirOnMyCtrlGeo", SCRCharaTurnDirectInput);
void *GetCharacterClass();
void SCRCharaTurnDirectInput(f32 turn)
{
    *(f32 *)((u8 *)GetCharacterClass() + 0x7D8) = turn;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0058_SCRGetTargetObjXZDirOnMyCtrlGeo", SCRPlayableCharaTurnDirectInput);
void SCRPlayableCharaTurnDirectInput(f32 turn)
{
    u8 *cc = (u8 *)GetCharacterClass();

    *(f32 *)(cc + 0x758) = turn;
    *(u64 *)(cc + 0x7C8) |= 0x40000;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0058_SCRGetTargetObjXZDirOnMyCtrlGeo", SCRCharaAccel);
void SCRCharaAccel(s32 a0, s32 a1, f32 accel)
{
    u8 *cc = (u8 *)GetCharacterClass();

    if (*(s32 *)(cc + 0x808) != 0)
    {
        *(f32 *)(cc + 0x80C) = *(f32 *)(cc + 0x80C) + accel;
        if (*(s32 *)(cc + 0x804) != 0)
        {
            *(s32 *)(cc + 0x804) = 0;
        }
    }
    else
    {
        *(s32 *)(cc + 0x80C) = 0;
        *(s32 *)(cc + 0x808) = 1;
        *(s32 *)(cc + 0x804) = 1;
    }
    *(s32 *)(cc + 0x7DC) = a1;
    if ((f32)a1 == 0.0f)
    {
        *(f32 *)(cc + 0x7D4) = -1.0f;
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0058_SCRGetTargetObjXZDirOnMyCtrlGeo", SCRCharaDead);
void SCRCharaDead(void)
{
    *(u64 *)((u8 *)GetCharacterClass() + 0x848) |= 0x200;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0058_SCRGetTargetObjXZDirOnMyCtrlGeo", SCRCharaStand);
void SCRCharaStand(void)
{
    u8 *cc = (u8 *)GetCharacterClass();

    *(s32 *)(cc + 0x7D4) = 0;
    *(s32 *)(cc + 0x7DC) = 0;
    *(s32 *)(cc + 0x80C) = 0;
    *(s32 *)(cc + 0x808) = 0;
    *(s32 *)(cc + 0x804) = 0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0058_SCRGetTargetObjXZDirOnMyCtrlGeo", SCRGetCharNodePos);
void GetMotionNodeQuaternionPos(u8 *a0, u8 *a1, u8 *a2, s32 a3, s32 t0);
void SCRGetCharNodePos(u8 *a0, u8 *a1, u8 *a2)
{
    u8 buf[16];

    GetMotionNodeQuaternionPos(buf, a0, a1, *(s32 *)(a2 + 8), 1);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0058_SCRGetTargetObjXZDirOnMyCtrlGeo", SCRGetRoot);
u8 *GetLayoutClass(void *chara);
void SCRGetRoot(u8 *a0, u8 *a1)
{
    u8 *layout = GetLayoutClass(a1);
    u8 *src = *(u8 **)(layout + 0x134);

    *(u128 *)a0 = *(u128 *)src;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0058_SCRGetTargetObjXZDirOnMyCtrlGeo", SCRGetDir);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0058_SCRGetTargetObjXZDirOnMyCtrlGeo", SCRGetAngle);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0058_SCRGetTargetObjXZDirOnMyCtrlGeo", SCRSetCharaMotionPlaySpeedRatioDirect);
void SCRSetCharaMotionPlaySpeedRatioDirect(f32 ratio)
{
    *(f32 *)((u8 *)GetCharacterClass() + 0x514) = ratio;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0058_SCRGetTargetObjXZDirOnMyCtrlGeo", SCRGetLocalDirZ);
void GAMEUTIL_get_local_directionZ();
void SCRGetLocalDirZ(void)
{
    GAMEUTIL_get_local_directionZ();
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0058_SCRGetTargetObjXZDirOnMyCtrlGeo", SCRRequestMotionDirect);
void CharaCtrlSetScriptCtrlStatus(u8 *a0, s32 a1);
void SCRRequestMotionDirect(u8 *a0, u8 *a1)
{
    if (a1 != NULL) {
        CharaCtrlSetScriptCtrlStatus(a0, *(s32 *)(a1 + 4));
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0058_SCRGetTargetObjXZDirOnMyCtrlGeo", SCRSetRootScaleRatio);
s32 SCRSetRootScaleRatio(f32 ratio)
{
    u8 *cc = (u8 *)GetCharacterClass();

    if (cc != NULL) {
        *(f32 *)(cc + 0x560) = ratio;
        return 1;
    }
    return 0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0058_SCRGetTargetObjXZDirOnMyCtrlGeo", SCRSetCharaRootTurnScaleRatio);
s32 SCRSetCharaRootTurnScaleRatio(f32 ratio)
{
    u8 *cc = (u8 *)GetCharacterClass();

    if (cc != NULL) {
        *(f32 *)(cc + 0x564) = ratio;
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0058_SCRGetTargetObjXZDirOnMyCtrlGeo", _SCRPlayLWS);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0058_SCRGetTargetObjXZDirOnMyCtrlGeo", _SCRSetupLWSWithTargetNodeParent);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0058_SCRGetTargetObjXZDirOnMyCtrlGeo", _SCRSetupLWS);
extern s32 gcGlobalVar;
extern s32 rootPtn;
void CreateScriptAnimationSequence();
void _SCRSetupLWS(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4)
{
    s32 seq[10];
    f32 scale;

    seq[0] = a0;
    seq[1] = (s32)&rootPtn;
    seq[2] = a1;
    seq[3] = a2;
    seq[4] = a3;
    seq[5] = 0;
    scale = 1.0f;
    if (*(f32 *)((u8 *)&gcGlobalVar + 0x178) == 0.0f)
    {
        scale = 0.0f;
    }
    *(f32 *)&seq[6] = scale;
    seq[7] = a4;
    seq[8] = 0;
    seq[9] = 0;
    CreateScriptAnimationSequence(seq);
}

/* NEARMISS-STUB _SCRStartLWS */
#if 0 /* NEARMISS 99.1% cat=sched sub=- | sw s0,0x358(v0) before sw zero,0(s0) | attempts=1 */
void PlayScriptAnimationSequence();
u8 *GetScriptAnimationClass();
void *get_main_cameraman_camera_obj();
void ExecObjectAnimation(void *obj, void *cam, f32 f1, f32 f2);
void _SCRStartLWS(void *a0, s32 a1, s32 a2, s32 *a3)
{
    u8 *cls;

    if (a0 != NULL)
    {
        PlayScriptAnimationSequence(a0, 0, a1, a2);
        if (a3 != NULL)
        {
            cls = GetScriptAnimationClass(a0);
            *(s32 **)(cls + 0x358) = a3;
            *a3 = 0;
        }
        ExecObjectAnimation(a0, get_main_cameraman_camera_obj(), *(f32 *)((u8 *)&gcGlobalVar + 0x180), *(f32 *)((u8 *)&gcGlobalVar + 0x184));
    }
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0058_SCRGetTargetObjXZDirOnMyCtrlGeo", _SCRStartLWS);

/* NEARMISS-STUB SCRSetLWSGeometryWithNoParentChange */
#if 0 /* NEARMISS 89.8% cat=regalloc sub=- | value load v1 before s0 copy | attempts=1 */
void UpdateLayoutClassParentSimpleGeometry(u8 *layout);
void UpdateLayoutClassSimpleGeometry(u8 *layout, f32 f);
s32 SCRSetLWSGeometryWithNoParentChange(void *a0, u128 *a1, u128 *a2)
{
    u8 *layout = GetLayoutClass(a0);

    *(u128 *)(*(u8 **)(layout + 0x134)) = *a1;
    *(u128 *)(*(u8 **)(layout + 0x13C)) = *a2;
    if (*(s32 *)(layout + 0x124) != 0)
    {
        *(u128 *)(layout + 0x60) = *a2;
        *(u128 *)(layout + 0x70) = *a1;
        UpdateLayoutClassParentSimpleGeometry(layout);
    }
    UpdateLayoutClassSimpleGeometry(layout, 0.0f);
    return 1;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0058_SCRGetTargetObjXZDirOnMyCtrlGeo", SCRSetLWSGeometryWithNoParentChange);

/* NEARMISS-STUB SCRSetLWSGeometry */
#if 0 /* NEARMISS 91.0% cat=regalloc sub=- | a0 copy delay slot / v1 load order | attempts=1 */
void ForceParentLayoutObj();
void UpdateLayoutClassParentSimpleGeometry(u8 *layout);
void UpdateLayoutClassSimpleGeometry(u8 *layout, f32 f);
s32 SCRSetLWSGeometry(void *a0, s32 a1, u128 *a2, u128 *a3)
{
    u8 *layout;
    u8 *dst;
    u128 q;

    if (a1 != 0)
    {
        ForceParentLayoutObj();
    }
    layout = GetLayoutClass(a0);
    q = *a2;
    dst = *(u8 **)(layout + 0x134);
    *(u128 *)dst = q;
    q = *a3;
    dst = *(u8 **)(layout + 0x13C);
    *(u128 *)dst = q;
    if (*(s32 *)(layout + 0x124) != 0)
    {
        *(u128 *)(layout + 0x60) = *a3;
        *(u128 *)(layout + 0x70) = *a2;
        UpdateLayoutClassParentSimpleGeometry(layout);
    }
    UpdateLayoutClassSimpleGeometry(layout, 0.0f);
    return 1;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0058_SCRGetTargetObjXZDirOnMyCtrlGeo", SCRSetLWSGeometry);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0058_SCRGetTargetObjXZDirOnMyCtrlGeo", SCRSetLWSGeometryWithZY);

/* NEARMISS-STUB SCRGetCollision */
#if 0 /* NEARMISS 92.4% cat=stack-frame sub=- | 80B out array placed lowest vs target sp+0x30 | attempts=1 */
s32 ClipCollisionDirectCallBack();
void CopyGeometryPointer();
s32 SCRGetCollision(void *a0, u128 *a1, u128 *a2, s32 a3)
{
    u128 v1;
    u128 v2;
    u8 out[80];
    s32 r;

    v1 = *a1;
    *(f32 *)((u8 *)&v1 + 12) = 1.0f;
    v2 = *a2;
    *(f32 *)((u8 *)&v2 + 12) = 1.0f;
    r = ClipCollisionDirectCallBack(out, &v1, &v2, a3, 0, 0, 0, 0, 0);
    if (r != 0 && a0 != NULL)
    {
        CopyGeometryPointer(a0, out);
    }
    return r;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0058_SCRGetTargetObjXZDirOnMyCtrlGeo", SCRGetCollision);

/* NEARMISS-STUB SCRGetCollisionCallBack */
#if 0 /* NEARMISS 93.2% cat=sched sub=- | 1.0f store hoisted above sq; target in jal delay slot | attempts=1 */
s32 ClipCollisionDirectCallBack();
void CopyGeometryPointer();
s32 SCRGetCollisionCallBack(void *a0, u128 *a1, u128 *a2, s32 a3, s32 a4, s32 a5)
{
    struct
    {
        u128 v1;
        u128 v2;
        u8 out[80];
    } s;
    s32 r;

    s.v1 = *a1;
    *(f32 *)((u8 *)&s.v1 + 12) = 1.0f;
    s.v2 = *a2;
    *(f32 *)((u8 *)&s.v2 + 12) = 1.0f;
    r = ClipCollisionDirectCallBack(s.out, &s.v1, &s.v2, a3, 0, 0, 0, a4, a5);
    if (r != 0 && a0 != NULL)
    {
        CopyGeometryPointer(a0, s.out);
    }
    return r;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0058_SCRGetTargetObjXZDirOnMyCtrlGeo", SCRGetCollisionCallBack);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0058_SCRGetTargetObjXZDirOnMyCtrlGeo", _SCRGetCollisionTwoBoneRay3D);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0058_SCRGetTargetObjXZDirOnMyCtrlGeo", _SCRGetCharaCollision);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0058_SCRGetTargetObjXZDirOnMyCtrlGeo", _SCRRequestDamageReaction);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0058_SCRGetTargetObjXZDirOnMyCtrlGeo", SCRGetGetGeometryPointerLegalParentObj);
void *GetGeometryPointerObject();
u8 *GetLayoutClass(void *chara);
void *SCRGetGetGeometryPointerLegalParentObj(void)
{
    u8 *obj = GetGeometryPointerObject();
    u8 *layout;
    u8 *p;

    if (obj != NULL)
    {
        if (obj[8] == 10)
        {
            layout = GetLayoutClass(obj);
            if (*(s32 *)(layout + 0x124) != 0)
            {
                p = GetGeometryPointerObject(layout + 0xC0);
                if (p[8] == 13 || p[8] == 22)
                {
                    obj = p;
                }
            }
        }
    }
    return obj;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0058_SCRGetTargetObjXZDirOnMyCtrlGeo", SCRCreateScriptCharObj);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0058_SCRGetTargetObjXZDirOnMyCtrlGeo", SCRDeleteAllActiveScriptAnimationObj);
void allArrowRelease();
void DeleteAllActiveScriptAnimationObj();
u64 SCRDeleteAllActiveScriptAnimationObj(void)
{
    allArrowRelease();
    DeleteAllActiveScriptAnimationObj();
    return 0;
}
