#include "common.h"

void DebugSetHorsePositionWithTargetOfs(void *obj, void *ofs);

void *get_cur_camera_target(void *cam);

void *get_main_cameraman(void);

extern u8 D_40132A20[];

extern s32 padManagerData;

u64 *GetCollisionDBAttributeAdr(void);

void DebugDispRadiusIndicator(s32 obj, f32 radius, s32 flag);

void glColor4f(f32 r, f32 g, f32 b, f32 a);

extern const char D_40132500[];

s32 strcmp();

u8 *GetLayoutClass();

void func_4001B190();

extern s64 iosGetTCountExtension(void);

extern u8 gcGlobalVar[];

s32 iosInitKPrintfContext3D(f32 a, f32 b, f32 c, f32 d, s32 p1, s32 p2, s32 p3, s32 p4);

void ResetCharacterObj();

void CallLayoutObjDebugResetFunc();

void ForceUnparentLayoutObj();

u8 *GetCharacterClass();

extern s32 D_401304C0;

extern s32 D_401304B8;

extern s32 D_40130618;

extern s32 D_401304B4;

extern s32 D_401304C4;

extern s32 D_401304C8;

extern s32 D_40130610;

extern s32 D_401304D4;

extern s32 D_4013061C;

extern s32 D_401304CC;

extern s32 D_401304D0;

extern s32 D_401304B0;

extern s32 D_401304E8;

extern s32 D_401304E4;

extern s32 D_401304D8;

extern s32 D_401304DC;

extern s32 D_401304E0;

void CharaCtrlAIControl(s32 obj, s32 p1, f32 f0, f32 f1);
void CharaCtrlPlayableControl(s32 obj, s32 p1, s32 p2, f32 f0);

void DebugControl(s32 obj, s32 p1, s32 p2, s32 p3, f32 unused, f32 f1, f32 f2)
{
    u8 *cls;

    cls = GetCharacterClass(obj);
    if (cls == 0) {
        return;
    }
    if (*(s8 *)(cls + 0x150) != 0) {
        return;
    }
    if (p3 != 0) {
        CharaCtrlAIControl(obj, p1, f1, f2);
        return;
    }
    CharaCtrlPlayableControl(obj, p1, p2, f2);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0004_DebugControl", DebugGlobalMoveWith2ndController);

void iosSetKPrintfColorContext(s32 ctx, s32 a, f32 r, f32 g, f32 b, f32 al);
void kprintfContext(s32 ctx, const char *fmt, s32 arg);
extern const char D_401324F0[];
extern const char D_401324F8[];

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0004_DebugControl", DebugDispItem);
void DebugDispItem(s32 ctx, s32 v1, s32 v2)
{
    iosSetKPrintfColorContext(ctx, 0, 1.0f, 1.0f, 1.0f, 1.0f);
    kprintfContext(ctx, D_401324F0, v1);
    iosSetKPrintfColorContext(ctx, 0, 0.25f, 0.75f, 1.0f, 1.0f);
    kprintfContext(ctx, D_401324F8, v2);
}

void DebugDispPosition(s32 a0, f32 radius)
{
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    DebugDispRadiusIndicator(a0, radius, 1);
}

void DebugDispPositionColor(s32 a0, f32 radius, f32 *color)
{
    glColor4f(color[0], color[1], color[2], color[3]);
    DebugDispRadiusIndicator(a0, radius, 1);
}

/* NEARMISS-STUB DebugDispTargetStatusForce */
#if 0 /* NEARMISS 48.6% cat=stack-frame sub=- | expected keeps a 16-byte frame and jal GetCharacterClass (non-tail call, sd ra); gcc emits tail j GetCharacterClass; void/value return variants both tail-call | attempts=1 */
u8 *DebugDispTargetStatusForce(s32 a0, s32 a1)
{
    return GetCharacterClass(a1);
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0004_DebugControl", DebugDispTargetStatusForce);

void DebugPrintf3D_InitContext(s32 a0, s32 a1)
{
    iosInitKPrintfContext3D(0.5f, 0.75f, 1.0f, 1.0f, a0, a1, 0, 1);
}

extern u128 ZeroVector;
void UpdateCharacterClassGeometry(u8 *cls);
void charrootdyn_getRegularColFinderPosition(u8 *a, u8 *b, s32 c, s32 d);
void UpdateCharacterClassPastGeometry(u8 *cls);
void SetCharacterObjDemoCutFinishFlag(s32 obj, s32 flag);
void UpdateLayoutClassSimpleGeometry(u8 *layout, f32 f);
void GetClothDynamics(s32 obj, s32 flag, s32 zero, f32 a, f32 b);
void UpdateLayoutClassPastSimpleGeometry(u8 *layout);
void SetLayoutClassRootQuaternion(u8 *layout, s32 a1);

void DebugSetObjectGeometry(s32 a0, s32 a1, u128 *a2)
{
    u8 *layout;
    u8 *cls;
    f32 hundred;

    ForceUnparentLayoutObj(a0);
    CallLayoutObjDebugResetFunc(a0);
    ResetCharacterObj(a0);
    layout = GetLayoutClass(a0);
    if (layout != 0) {
        *(u128 *)(*(u8 **)(layout + 0x134)) = *a2;
        *(u128 *)(layout + 0x40) = *a2;
        *(u128 *)(layout + 0x30) = ZeroVector;
        cls = GetCharacterClass(a0);
        hundred = 100.0f;
        if (cls != 0) {
            UpdateCharacterClassGeometry(cls);
            charrootdyn_getRegularColFinderPosition(cls + 0x4B0, cls, *(s32 *)(layout + 0x13C), *(s32 *)(layout + 0x134));
            UpdateCharacterClassPastGeometry(cls);
            SetCharacterObjDemoCutFinishFlag(a0, 1);
        } else {
            UpdateLayoutClassSimpleGeometry(layout, hundred);
            GetClothDynamics(a0, 1, 0, 0.01f, hundred);
            UpdateLayoutClassPastSimpleGeometry(layout);
        }
        SetLayoutClassRootQuaternion(layout, a1);
    }
}

s32 DebugGetMutekiMode(void)
{
    return D_401304C8;
}

/* NEARMISS-STUB SetObjectGeo */
#if 0 /* NEARMISS 97.3% cat=sched sub=- | only difference: a1=1 for GetClothDynamics is scheduled before the 0.01f mov.s to fa1 (target sets a1 after); u128 lq/sq copies and extern calls match; shared 1 | attempts=1 */
void SetObjectGeo(s32 a0, s32 a1, u128 *a2)
{
    u8 *layout;
    u8 *cls;

    layout = GetLayoutClass();
    if (layout != 0) {
        *(u128 *)(*(u8 **)(layout + 0x134)) = *a2;
        *(u128 *)(layout + 0x40) = *a2;
        *(u128 *)(layout + 0x30) = ZeroVector;
        cls = GetCharacterClass(a0);
        if (cls != 0) {
            UpdateCharacterClassGeometry(cls);
            charrootdyn_getRegularColFinderPosition(cls + 0x4B0, cls, *(s32 *)(layout + 0x13C), *(s32 *)(layout + 0x134));
            UpdateCharacterClassPastGeometry(cls);
            SetCharacterObjDemoCutFinishFlag(a0, 1);
        } else {
            UpdateLayoutClassSimpleGeometry(layout, 100.0f);
            GetClothDynamics(a0, 1, 0, 0.01f, 100.0f);
            UpdateLayoutClassPastSimpleGeometry(layout);
        }
        SetLayoutClassRootQuaternion(layout, a1);
    }
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0004_DebugControl", SetObjectGeo);

void SetObjectGeoAndUnparent(s32 a0, s32 a1, u128 *a2)
{
    u8 *layout;
    u8 *cls;
    f32 hundred;

    ForceUnparentLayoutObj(a0);
    layout = GetLayoutClass(a0);
    if (layout != 0) {
        *(u128 *)(*(u8 **)(layout + 0x134)) = *a2;
        *(u128 *)(layout + 0x40) = *a2;
        *(u128 *)(layout + 0x30) = ZeroVector;
        cls = GetCharacterClass(a0);
        hundred = 100.0f;
        if (cls != 0) {
            UpdateCharacterClassGeometry(cls);
            charrootdyn_getRegularColFinderPosition(cls + 0x4B0, cls, *(s32 *)(layout + 0x13C), *(s32 *)(layout + 0x134));
            UpdateCharacterClassPastGeometry(cls);
            SetCharacterObjDemoCutFinishFlag(a0, 1);
        } else {
            UpdateLayoutClassSimpleGeometry(layout, hundred);
            GetClothDynamics(a0, 1, 0, 0.01f, hundred);
            UpdateLayoutClassPastSimpleGeometry(layout);
        }
        SetLayoutClassRootQuaternion(layout, a1);
    }
}

/* NEARMISS-STUB DebugIsPlayer */
#if 0 /* NEARMISS 62.5% cat=branch-layout sub=- | expected beqz/bnel on the GetLayoutClass result in v0 and emits b+li 1; gcc copies result to v1 and/or emits sltiu; explicit ret-var form gave 57.5 | attempts=1 */
s32 DebugIsPlayer(void)
{
    u8 *layout = GetLayoutClass();

    if (layout == 0) {
        return 0;
    }
    if (strcmp(*(char **)(layout + 0x130), D_40132500) != 0) {
        return 0;
    }
    return 1;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0004_DebugControl", DebugIsPlayer);

void *isysGroupForFirst(s32 group, s32 flag);
void *isysGroupForNext(void *link, s32 flag);
void isysGroupForExit(s32 obj, s32 flag);
s32 GAMEUTIL_is_player_obj(s32 chr);

s32 DebugFindPlayer(s32 group)
{
    s32 obj;
    s32 found;
    void *link;

    found = 0;
    obj = 0;
    link = isysGroupForFirst(group, 0);
    while (link != 0) {
        obj = *(s32 *)link;
        if (GAMEUTIL_is_player_obj(obj) == 1) {
            found = obj;
            break;
        }
        link = isysGroupForNext(link, 0);
    }
    if (obj != 0) {
        isysGroupForExit(obj, 0);
    }
    return found;
}

s32 *getStatusMode(void)
{
    return &D_401304B0;
}

s32 *getDispCollisionPerfFlag(void)
{
    return &D_401304B4;
}

s32 *getPrintfPerfWarning(void)
{
    return &D_401304B8;
}

void ResetObject(s32 obj)
{
    ForceUnparentLayoutObj(obj);
    CallLayoutObjDebugResetFunc(obj);
    ResetCharacterObj(obj);
}

s32 *is_disp_debug_object_info(void)
{
    return &D_401304C0;
}

s32 *getCollisionDispMode(void)
{
    return &D_401304C4;
}

s32 *getGetMutekiMode(void)
{
    return &D_401304C8;
}

s32 *getPlayerPowerDisp(void)
{
    return &D_401304CC;
}

s32 *getPlayerPowerMax(void)
{
    return &D_401304D0;
}

s32 *getGripCalcCancelMode(void)
{
    return &D_401304D4;
}

s32 func_4001D7C0(void)
{
    u64 attr;
    u64 masked;

    attr = *(u64 *)GetCollisionDBAttributeAdr();
    masked = attr & 0xF80000000;
    if (masked == 0x300000000 || masked == 0x500000000) {
        return 1;
    }
    return 0;
}

void GetGeometryPointerPosition(f32 *out, s32 geo);
void kprintfContextCentering(void *ctx, const char *fmt, s32 arg);

/* NEARMISS-STUB dispgpinfo */
#if 0 /* NEARMISS 89.8% cat=sched sub=- | target recomputes the out-buffer address (sp+0x50) after GetGeometryPointerPosition and passes it in the delay slot; ours keeps it in s0 set before the call (CS | attempts=1 */
void dispgpinfo(s32 p0, s32 p1, s32 p2, f32 f0, f32 f1, f32 f2)
{
    f32 pos[4];
    u8 ctx[64];
    f32 out[4];

    GetGeometryPointerPosition(pos, p1);
    if (iosInitKPrintfContext3D(f0, f1, f2, 1.0f, (s32)ctx, (s32)pos, 0, 1) != 0) {
        kprintfContextCentering(ctx, D_401324F8, p0);
    }
    glColor4f(f0, f1, f2, 1.0f);
    GetGeometryPointerPosition(out, p1);
    DebugDispRadiusIndicator((s32)&out[0], 0.1f, 1);
    DebugDispRadiusIndicator((s32)&out[0], 0.03f, 1);
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0004_DebugControl", dispgpinfo);

s32 *getSnapShotSize(void)
{
    return &D_401304D8;
}

s32 *getSnapShotFormat(void)
{
    return &D_401304DC;
}

s32 *getSnapShotNum(void)
{
    return &D_401304E0;
}

s32 *getSnapShotRotation(void)
{
    return &D_401304E4;
}

s32 *getSnapShotAspect(void)
{
    return &D_401304E8;
}

extern u8 D_40130510[];
extern u8 D_401304F0[];
extern s32 rootPtn;
void func_4001AD38();
void createScriptObj(void *fn, void *a1, void *a2, s32 a3, s32 a4, s32 a5, void *a6, s32 a7);

/* NEARMISS-STUB DebugDispMotionTurnRequest */
#if 0 /* NEARMISS 64.3% cat=branch-layout sub=- | range check gcc fuses into one unsigned compare (target keeps slti+bgtz with a0 bool); lui of D_401304B0 hoisted above the range test; p copied to a4 not a3; 0x | attempts=1 */
void DebugDispMotionTurnRequest(u8 *p)
{
    s32 idx;
    s32 ok;
    s32 val;
    s16 sVar;
    u8 *tbl;

    idx = *(s32 *)(p + 0xBD4);
    ok = 1;
    if (5 < idx) {
        ok = 0;
    }
    if (idx < 1) {
        ok = 0;
    }
    if (((D_401304B0 - 1U) < 2) && ok) {
        val = *(s32 *)(p + 0x134);
        sVar = *(s16 *)(p + 0x360);
        *(s32 *)(D_40130510 + idx * 0x30) = val;
        tbl = D_401304F0;
        if (sVar == 2 || sVar == 4 || sVar == 3) {
            createScriptObj(func_4001AD38, tbl + *(s32 *)(p + 0xBD4) * 0x30, &rootPtn, 0x1000, 0, 1, 0, 0);
            return;
        }
    }
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0004_DebugControl", DebugDispMotionTurnRequest);

s32 *getFreezeBossFlag(void)
{
    return &D_40130610;
}

void setFreezeBossFlag(void)
{
    s32 obj;
    void *link;
    u8 *cls;

    obj = 0;
    link = isysGroupForFirst((s32)(gcGlobalVar + 0x2B8), 0);
    while (link != 0) {
        obj = *(s32 *)link;
        cls = GetCharacterClass(obj);
        cls[0x2B0] = *(u8 *)&D_40130610;
        link = isysGroupForNext(link, 0);
    }
    if (obj != 0) {
        isysGroupForExit(obj, 0);
    }
}

void camdebug_for_new_camera(void)
{
    u8 *base = gcGlobalVar;

    *(s64 *)(base + 0xD0) = iosGetTCountExtension();
    func_4001B190();
    *(s64 *)(base + 0xD8) = iosGetTCountExtension();
}

void camdebug_for_monitortest(void)
{
    void *cameraman;
    void *target;
    s32 *pad;

    cameraman = get_main_cameraman();
    target = get_cur_camera_target(cameraman);
    pad = (s32 *)&padManagerData;
    if ((pad[0x3E6] & 0x2) != 0) {
        if ((pad[0x3E8] & 0x40) != 0) {
            DebugSetHorsePositionWithTargetOfs(target, D_40132A20);
        }
    }
}

s32 *getDispGpsMarker(void)
{
    return &D_40130618;
}

s32 *getGpsGridWidth(void)
{
    return &D_4013061C;
}
