#include "common.h"

extern s32 D_40130C38;

void scrRun(void);

void CancelCaptionSubThreadAll(void)
{
    D_40130C38 = 0;
    scrRun();
    D_40130C38 = 1;
}

extern s32 D_40130C40;

void QuitCaptionSubThreadAll(void)
{
    D_40130C40 = 1;
    scrRun();
    D_40130C40 = 0;
}

void iosFree(void *p);

void func_40027ED8(s32 a0, u8 *obj)
{
    void (*fn)(s32);
    s32 *ref;
    fn = *(void (**)(s32))(obj + 0x2C);
    if (fn != 0)
    {
        fn(a0);
    }
    ref = *(s32 **)(obj + 0x30);
    (*ref)--;
    iosFree(obj);
}

/* NEARMISS-STUB func_40027F20 */
#if 0 /* NEARMISS 32.05% cat=uncategorized sub=- | list remove shared iosFree tail | attempts=1 */
extern s32 D_40130C44;
extern s32 D_40130C48;

void func_40027F20(s32 a0, s32 a1)
{
    s32 prev;
    s32 cur;
    if (a1 == 0)
    {
        return;
    }
    if (D_40130C44 == a1)
    {
        prev = D_40130C44;
        D_40130C44 = *(s32 *)(prev + 0x18);
        iosFree((void *)prev);
        D_40130C48--;
        return;
    }
    prev = D_40130C44;
    if (prev == 0)
    {
        return;
    }
    cur = *(s32 *)(prev + 0x18);
    while (cur != a1)
    {
        if (cur == 0)
        {
            return;
        }
        prev = cur;
        cur = *(s32 *)(cur + 0x18);
    }
    *(s32 *)(prev + 0x18) = *(s32 *)(cur + 0x18);
    iosFree((void *)cur);
    D_40130C48--;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0017_CancelCaptionSubThreadAll", func_40027F20);

void *GetCharacterClass(void *obj);
void ResetCharacterClassFallDownInfo(void *cls);

void nico_ResetCharacterObjFallDownInfo(void *obj)
{
    ResetCharacterClassFallDownInfo(GetCharacterClass(obj));
}

void ForceUnparentLayoutObj();

void nico_UnparentObject(void *obj)
{
    ForceUnparentLayoutObj(obj);
}

/* NEARMISS-STUB nico_SendAttackMailToVCol */
#if 0 /* NEARMISS 97.58% cat=call-abi sub=- | in-TU: SendCharaAttackMsg prototype clash (exp (void*,void*,void*,int,float) vs TU f32-first decl); 5th float arg missing | attempts=2 */
void nico_SendAttackMailToVCol(void *obj)
{
    u8 *cls = GetCharacterClass(obj);
    u8 buf[0x40];
    s32 sel;
    if (getCurWeapon(obj) == 9)
    {
        return;
    }
    if (*(s32 *)(cls + 0xDB0) == 0)
    {
        return;
    }
    ConvertGeometryPointerZNormalMode(buf, cls + 0xDD0);
    GetGeometryPointerObject(buf);
    sel = getSelectWeapon();
    SendCharaAttackMsg((f32)sel, obj, (void *)sel, buf, 0);
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0017_CancelCaptionSubThreadAll", nico_SendAttackMailToVCol);

extern s32 InitialGeometryPointer;
void SendCharaAttackMsg(f32 f, void *a, void *b, void *c, s32 d);

void nico_SendSuicideMail(void *obj)
{
    SendCharaAttackMsg(65535.0f, obj, obj, &InitialGeometryPointer, -3);
}

extern s32 InitialGeometryPointer;
void *GetCharacterClass(void *obj);
void SendCharaAttackMsg(f32 f, void *a, void *b, void *c, s32 d);

/* NEARMISS-STUB nico_SendPlayerFallDownDamageMail */
#if 0 /* NEARMISS 66.9% cat=regalloc sub=- | float load ordering, s0/s1 frame | attempts=1 */
extern s32 InitialGeometryPointer;
void *GetCharacterClass(void *obj);
void SendCharaAttackMsg(f32 f, void *a, void *b, void *c, s32 d);

void nico_SendPlayerFallDownDamageMail(void *obj)
{
    u8 *cls = GetCharacterClass(obj);
    SendCharaAttackMsg(*(f32 *)(cls + 0x50C), obj, obj, &InitialGeometryPointer, -3);
}
#endif
void nico_SendPlayerFallDownDamageMail(void *actor)
{
    void *g = &InitialGeometryPointer;
    char *c = GetCharacterClass(actor);
    SendCharaAttackMsg(*(f32 *)(c + 0x50C), actor, actor, g, -3);
}
//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0017_CancelCaptionSubThreadAll", nico_SendPlayerFallDownDamageMail);

extern s32 InitialGeometryPointer;
f32 player_GetBoundDamageLevel(void *obj);
void SendCharaAttackMsg(f32 f, void *a, void *b, void *c, s32 d);

/* NEARMISS-STUB nico_SendPlayerBoundDamageMail */
#if 0 /* NEARMISS 4.2% cat=uncategorized sub=- | obj kept in s1 across call; shape far off | attempts=1 */
extern s32 InitialGeometryPointer;
f32 player_GetBoundDamageLevel(void *obj);
void SendCharaAttackMsg(f32 f, void *a, void *b, void *c, s32 d);

void nico_SendPlayerBoundDamageMail(void *obj)
{
    f32 lvl = player_GetBoundDamageLevel(obj);
    SendCharaAttackMsg(lvl, obj, obj, &InitialGeometryPointer, -4);
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0017_CancelCaptionSubThreadAll", nico_SendPlayerBoundDamageMail);

u8 *GetDamageClass(s32 a0);

s32 nico_GetCharacterAttackedFlag(s32 a0)
{
    return *(s32 *)GetDamageClass(a0) == 3;
}

u8 *GetDamageClass(s32 a0);
u64 GetGeometryPointerCharColAttr();

u64 nico_GetCharacterAttackedGPAttr(s32 a0, u64 mask)
{
    u8 *d = GetDamageClass(a0);
    if (*(s32 *)d == 3)
    {
        return GetGeometryPointerCharColAttr(d + 0x10) & mask;
    }
    return 0;
}

void *GetCharacterClass(void *obj);

u64 nico_GetCharacterParentGPAttr(void *obj, u64 mask)
{
    u8 *cls = GetCharacterClass(obj);
    if (*(s32 *)(cls + 0x124) == 0)
    {
        return 0;
    }
    return *(u64 *)(cls + 0x680) & mask;
}

void *GetCharacterClass(void *obj);

void *nico_GetPlayerCharacterRidingHorseObject(void *obj)
{
    u8 *cls = GetCharacterClass(obj);
    void *horse;
    if (cls == 0)
    {
        return 0;
    }
    horse = *(void **)(cls + 0x940);
    if (horse == obj)
    {
        return 0;
    }
    return horse;
}

void nico_InitScriptCharObjDefaultValue(void) {
}

void *GetCharacterClass(void *obj);

/* NEARMISS-STUB nico_CheckCharacterVColPlaneAttribute */
#if 0 /* NEARMISS 86.8% cat=regalloc sub=- | sltiu vs movn | attempts=1 */
void *GetCharacterClass(void *obj);

s32 nico_CheckCharacterVColPlaneAttribute(void *obj, u64 a, u64 b)
{
    u8 *cls = GetCharacterClass(obj);
    if (*(s32 *)(cls + 0xDB0) == 0)
    {
        return 0;
    }
    return (*(u64 *)(cls + 0xDC0) & a) == b;
}
#endif
//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0017_CancelCaptionSubThreadAll", nico_CheckCharacterVColPlaneAttribute);
int nico_CheckCharacterVColPlaneAttribute(void *a, long mask, long val)
{
    char *c = GetCharacterClass(a);

    int ret = 0;

    if (*(int *)(c + 0xDB0) != 0) {
        ret = 1;
        if (((*(long *)(c + 0xDC0) & mask)) != val)
            ret = 0;
    }
    return ret;
}

void *GetCharacterClass(void *obj);

void *GetCharacterClass(void *obj);

/* NEARMISS-STUB nico_CheckCharacterGPColPlaneAttribute */
#if 0 /* NEARMISS 92.3% cat=regalloc sub=- | movn/branch layout around and/xor | attempts=1 */
void *GetCharacterClass(void *obj);

s32 nico_CheckCharacterGPColPlaneAttribute(void *obj, u64 a, u64 b)
{
    u8 *cls = GetCharacterClass(obj);
    s32 r = 1;
    if (*(s32 *)(cls + 0x124) == 0)
    {
        return 0;
    }
    if (((*(u64 *)(cls + 0x680) & a) ^ b) != 0)
    {
        r = 0;
    }
    return r;
}
#endif
//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0017_CancelCaptionSubThreadAll", nico_CheckCharacterGPColPlaneAttribute);
int nico_CheckCharacterGPColPlaneAttribute(void *a, long mask, long val)
{
    char *c = GetCharacterClass(a);

    int ret = 0;

    if (*(int *)(c + 0x124) != 0) {
        ret = 1;
        if (((*(long *)(c + 0x680) & mask)) != val)
            ret = 0;
    }
    return ret;
}

u64 GetGeometryPointerCharColAttr();

u64 GetGeometryPointerCharColAttr();

void nico_GetGeometryPointerAttr(void)
{
    GetGeometryPointerCharColAttr();
}

void *GetAnimationClass(void);
f32 GetCurrentGameAnimeTimeScaleRatio(void);
void ChangeGameAnimeTimeScaleRatio(f32 a, f32 b);

/* NEARMISS-STUB nico_timeSlow */
#if 0 /* NEARMISS 38.3% cat=float-ops sub=- | anim/ratio call order | attempts=1 */
void *GetAnimationClass(void);
f32 GetCurrentGameAnimeTimeScaleRatio(void);
void ChangeGameAnimeTimeScaleRatio(f32 a, f32 b);

void nico_timeSlow(void)
{
    u8 *anim = GetAnimationClass();
    f32 r = 0.75f;
    f32 cur = GetCurrentGameAnimeTimeScaleRatio();
    u8 *p = *(u8 **)anim;
    ChangeGameAnimeTimeScaleRatio(r, ((r - cur) * 30.0f) / (f32)p[0x44]);
}
#endif
void nico_timeSlow(void *a)
{
    u8 **anim = (u8 **)GetAnimationClass();
    f32 rate = 0.75f;
    f32 cur = GetCurrentGameAnimeTimeScaleRatio();

    ChangeGameAnimeTimeScaleRatio(rate, (rate - cur) * 30.0f / (f32)*(u8 *)(*anim + 0x44));
}
//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0017_CancelCaptionSubThreadAll", nico_timeSlow);

void *GetAnimationClass(void);
f32 GetGameAnimeTimeScaleRatio(void);
f32 GetCurrentGameAnimeTimeScaleRatio(void);
void ChangeGameAnimeTimeScaleRatio(f32 a, f32 b);

/* NEARMISS-STUB nico_timeResume */
#if 0 /* NEARMISS 91.3% cat=float-ops sub=- | float call order / f13 vs f14 | attempts=1 */
void *GetAnimationClass(void);
f32 GetGameAnimeTimeScaleRatio(void);
f32 GetCurrentGameAnimeTimeScaleRatio(void);
void ChangeGameAnimeTimeScaleRatio(f32 a, f32 b);

void nico_timeResume(void)
{
    u8 *anim = GetAnimationClass();
    f32 r;
    f32 cur;
    GetGameAnimeTimeScaleRatio();
    r = GetGameAnimeTimeScaleRatio();
    cur = GetCurrentGameAnimeTimeScaleRatio();
    ChangeGameAnimeTimeScaleRatio(r, ((r - cur) * 30.0f) / (f32)(*(u8 **)anim)[0x45]);
}
#endif
void nico_timeResume(void)
{
    u8 **anim = (u8 **)GetAnimationClass();
    f32 r = GetGameAnimeTimeScaleRatio();
    f32 cur = GetCurrentGameAnimeTimeScaleRatio();

    ChangeGameAnimeTimeScaleRatio(r, (r - cur) * 30.0f / (f32)*(u8 *)(*anim + 0x45));
}
//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0017_CancelCaptionSubThreadAll", nico_timeResume);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0017_CancelCaptionSubThreadAll", nico_StabCharacterRootRotationToXZ);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0017_CancelCaptionSubThreadAll", nico_RotCharacterRootRotationX90);

void stagemanager_unloadstage(s32 n);

void deleteSeamlessCommonLayout(u8 *layout)
{
    s32 n = *(s32 *)(layout + 0xC);
    u8 *p = *(u8 **)(layout + 0x10);
    while (--n != -1)
    {
        s32 v = *(s32 *)(p + 4);
        if (v >= 0)
        {
            stagemanager_unloadstage(v);
            *(s32 *)(p + 4) = -1;
        }
        p += 12;
    }
}

void initSeamlessCommonLayout(u8 *layout)
{
    s32 n = *(s32 *)(layout + 0xC);
    u8 *p = *(u8 **)(layout + 0x10);
    while (--n != -1)
    {
        s32 (*fn)(u8 *) = *(s32 (**)(u8 *))(p + 8);
        *(s32 *)(p + 4) = fn(p);
        p += 12;
    }
}

extern s32 D_40130C4C;

void SetDefaultStageLoad(s32 a0)
{
    D_40130C4C = a0;
}

void stagemanager_createsubthread();
void func_400285F0(void);

void st_changePlayerInspireLevel(s32 a0)
{
    stagemanager_createsubthread(func_400285F0, a0, 0);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0017_CancelCaptionSubThreadAll", func_400285F0);

s32 StartLwsDemoManager(s32 a, s32 b, s32 c);
void isysAddGroupWithLinkParam();

s32 _SCRStartLwsDemoOrient(s32 a, s32 b, s32 c, s32 d)
{
    s32 g = StartLwsDemoManager(b, c, d);
    isysAddGroupWithLinkParam(g, a, 0, 0);
    return g;
}

extern s32 padManagerData;

extern s32 padManagerData;

s32 demoscrCheckDemoFinish(void)
{
    s32 v = ((s32 *)&padManagerData)[2];
    v &= 0x800;
    return v != 0;
}
u64 demoscrCheckDemoCutSkip(void)
{
    return 0;
}

void fsEffectManagerInit();

void setDefaultFsEffect(void)
{
    fsEffectManagerInit();
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0017_CancelCaptionSubThreadAll", func_40028750);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0017_CancelCaptionSubThreadAll", st_endingflow);
