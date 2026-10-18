#include "common.h"

void RequestCharacterMotionShiftFunc(void *chara, void (*func)(void));
void func_40074F28(void);
void func_40074FC8(void);
void func_40075218(void);
void func_40075220(void);
void func_40075228(void);
void func_40075230(void);
void func_400751A8(void);
void func_40075068(void);
void func_40075108(void);
u8 *GetSCRCharaAIWorkPtr(void);
void *SCRGetFirstObj(void *p);
void torchObjRelease(void *obj);
extern u8 gcGlobalVar[];
void *isysGetThisSubThread(void);
void bootTexAlphaAnim(f32 a, f32 b, void *c, void *d);
extern u8 D_401317E0[];
extern u8 D_401317C8[];
extern u8 D_40131810[];
extern u8 D_401317F8[];
extern u8 *StageLayout_LEO_TORCH0;
extern u8 *StageLayout_LEO_TORCH1;
extern u8 *StageLayout_LEO_TORCH2;
extern u8 *StageLayout_LEO_TORCH3;
extern u8 *StageLayout_LEO_TORCH0_ANIM;
extern u8 *StageLayout_LEO_TORCH1_ANIM;
extern u8 *StageLayout_LEO_TORCH2_ANIM;
extern u8 *StageLayout_LEO_TORCH3_ANIM;
extern u8 ScriptCtrlDef_SCRLeoTorchFinish[];
extern s32 D_40203838;
void SetLayoutObjAccessSwitch(void *obj, s32 flag);
void CharaCtrlSetScriptCtrlStatus(void *chara, s32 status);
void CharaCtrlResetAllScriptCtrlStatus(void *chara);
void updateScriptDataSystem(void *chara);
void isysRequestDeleteObj(void *obj);
void SCRExecBossPreProcess(s32 a0);
void SCRExecBossPostProcess(s32 a0);
void scrRunM(s32 n);
void func_40074DB8(void);
void func_40074850(void);
s32 _gameFlagChk(s32 idx);
void *_SCRSetupLWSWithTargetNodeParent(void *lws, void *thread, void *node);
void _SCRStartLWS(void *a0, s32 a1, s32 a2, s32 *a3);
void SetScriptObjDeleteCallBackFunc(void *chara, void *func, void *arg);
extern u8 *ScriptAnimationObjDef_LEO_ARMER0;
extern u8 *ScriptAnimationObjDef_LEO_ARMER1;
extern u8 *ScriptAnimationObjDef_LEO_ARMER2;
extern u8 *ScriptAnimationObjDef_LEO_ARMER3;
extern u8 *SkelFocusDef_LEO_NECK_A;
extern u8 *SkelFocusDef_LEO_CHEST;
extern u8 *SkelFocusDef_LEO_WAIST;
extern u8 *SkelFocusDef_LEO_TAIL_A;
void func_40075428(s32 *a0);
extern s32 rootPtn;
extern s32 DldSysUndefSymbol;
u8 *GetLayoutClass();
void bootMemoryCardSaveScriptNoBlock(void *p);
s32 SCRGetSizeOfBossWork(void *thread);
void *iosCreatePartition(void *parent, s32 size);
u8 *GetScriptCharacterClass(void *thread);
void CharaCtrlResetCtrlStatus(void *chara);
void *_SCRMallocAlign(void *ptn, s32 size, s32 align);
void *SCRCharaInitBossWork(void *ptn, void *thread);
void SCRReleaseBossWork(void);
void SetScriptCharacterObjReleaseCallBackFunc(void *chara, void *func, void *arg);
void *GetScriptClass(void *chara);
void initScriptDataSystem(void *chara, void *data);
void isysJumpSubThread(void *func, void *arg);

/* NEARMISS-STUB nico_leoBossStart */
#if 0 /* NEARMISS 31.4% cat=branch-layout sub=- | if/else polarity on _gameFlagChk(0x125); inner glabel | attempts=1 */
void func_40074DB8(void);
void func_40074850(void);
s32 _gameFlagChk(s32 idx);
void *_SCRSetupLWSWithTargetNodeParent(void *lws, void *thread, void *node);
void _SCRStartLWS(void *a0, s32 a1, s32 a2, s32 *a3);
void SetScriptObjDeleteCallBackFunc(void *chara, void *func, void *arg);
extern u8 *ScriptAnimationObjDef_LEO_ARMER0;
extern u8 *ScriptAnimationObjDef_LEO_ARMER1;
extern u8 *ScriptAnimationObjDef_LEO_ARMER2;
extern u8 *ScriptAnimationObjDef_LEO_ARMER3;
extern u8 *SkelFocusDef_LEO_NECK_A;
extern u8 *SkelFocusDef_LEO_CHEST;
extern u8 *SkelFocusDef_LEO_WAIST;
extern u8 *SkelFocusDef_LEO_TAIL_A;

void nico_leoBossStart(void)
{
    void *thread = isysGetThisSubThread();
    s32 size = SCRGetSizeOfBossWork(thread);
    void *part = iosCreatePartition(&rootPtn, size + 0x41E3);
    u8 *cls = GetScriptCharacterClass(thread);
    u8 *mem;
    void *boss;
    void *lws;

    *(void **)(cls + 0x114C) = part;
    CharaCtrlResetCtrlStatus(thread);
    CharaCtrlResetAllScriptCtrlStatus(thread);
    cls = GetScriptCharacterClass(thread);
    mem = _SCRMallocAlign(part, 0x41B0, 0x10);
    *(void **)(cls + 0x1150) = mem;
    boss = SCRCharaInitBossWork(part, thread);
    *(void **)mem = boss;
    SetScriptCharacterObjReleaseCallBackFunc(thread, SCRReleaseBossWork, boss);
    scrRunM(1);
    CharaCtrlResetCtrlStatus(thread);
    cls = GetScriptClass(thread);
    initScriptDataSystem(thread, *(void **)(cls + 0x48));
    if (_gameFlagChk(0x125) != 0)
    {
        *(s32 *)(mem + 0x41A0) = 2;
    }
    else
    {
        lws = _SCRSetupLWSWithTargetNodeParent(ScriptAnimationObjDef_LEO_ARMER0, thread, SkelFocusDef_LEO_NECK_A);
        *(void **)(mem + 0x4190) = lws;
        _SCRStartLWS(lws, -1, 2, 0);
        lws = _SCRSetupLWSWithTargetNodeParent(ScriptAnimationObjDef_LEO_ARMER1, thread, SkelFocusDef_LEO_CHEST);
        *(void **)(mem + 0x4194) = lws;
        _SCRStartLWS(lws, -1, 2, 0);
        lws = _SCRSetupLWSWithTargetNodeParent(ScriptAnimationObjDef_LEO_ARMER2, thread, SkelFocusDef_LEO_WAIST);
        *(void **)(mem + 0x4198) = lws;
        _SCRStartLWS(lws, -1, 2, 0);
        lws = _SCRSetupLWSWithTargetNodeParent(ScriptAnimationObjDef_LEO_ARMER3, thread, SkelFocusDef_LEO_TAIL_A);
        *(void **)(mem + 0x419C) = lws;
        _SCRStartLWS(lws, -1, 2, 0);
        *(s32 *)(mem + 0x41A0) = 0;
    }
    D_40203838 = 0;
    SetLayoutObjAccessSwitch(*(void **)(StageLayout_LEO_TORCH0 + 0x48), 0);
    SetLayoutObjAccessSwitch(*(void **)(StageLayout_LEO_TORCH1 + 0x48), 0);
    SetLayoutObjAccessSwitch(*(void **)(StageLayout_LEO_TORCH2 + 0x48), 0);
    SetLayoutObjAccessSwitch(*(void **)(StageLayout_LEO_TORCH3 + 0x48), 0);
    SetScriptObjDeleteCallBackFunc(thread, func_40074DB8, 0);
    isysJumpSubThread(func_40074850, mem);
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0085_nico_leoBossStart", nico_leoBossStart);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0085_nico_leoBossStart", func_40074DB8);
void func_40074DB8(void)
{
    torchObjRelease(SCRGetFirstObj(gcGlobalVar + 0x2B0));
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0085_nico_leoBossStart", SCRLeoTorch0_Disp);
void SCRLeoTorch0_Disp(void *a0)
{
    RequestCharacterMotionShiftFunc(a0, func_40074F28);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0085_nico_leoBossStart", SCRLeoTorch1_Disp);
void SCRLeoTorch1_Disp(void *a0)
{
    RequestCharacterMotionShiftFunc(a0, func_40074FC8);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0085_nico_leoBossStart", SCRLeoTorch2_Disp);
void SCRLeoTorch2_Disp(void *a0)
{
    RequestCharacterMotionShiftFunc(a0, func_40075068);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0085_nico_leoBossStart", SCRLeoTorch3_Disp);
void SCRLeoTorch3_Disp(void *a0)
{
    RequestCharacterMotionShiftFunc(a0, func_40075108);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0085_nico_leoBossStart", SCRConditionLeoCheckArmorBroken);
s32 SCRConditionLeoCheckArmorBroken(void)
{
    return *(s32 *)(GetSCRCharaAIWorkPtr() + 0x41A0) != 0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0085_nico_leoBossStart", SCRLeoArmorBroken);
void SCRLeoArmorBroken(void *a0)
{
    RequestCharacterMotionShiftFunc(a0, func_400751A8);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0085_nico_leoBossStart", SCRLeoFall);
void SCRLeoFall(void *a0)
{
    RequestCharacterMotionShiftFunc(a0, func_40075218);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0085_nico_leoBossStart", SCRLeoDamage);
void SCRLeoDamage(void *a0)
{
    RequestCharacterMotionShiftFunc(a0, func_40075220);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0085_nico_leoBossStart", SCRLeoDashAttackEnd);
void SCRLeoDashAttackEnd(void *a0)
{
    RequestCharacterMotionShiftFunc(a0, func_40075228);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0085_nico_leoBossStart", SCRLeoDashAttack);
void SCRLeoDashAttack(void *a0)
{
    RequestCharacterMotionShiftFunc(a0, func_40075230);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0085_nico_leoBossStart", func_40074F28);
void func_40074F28(void)
{
    SetLayoutObjAccessSwitch(*(void **)(StageLayout_LEO_TORCH0 + 0x48), 1);
    D_40203838 = 1;
    torchObjRelease(SCRGetFirstObj(gcGlobalVar + 0x2B0));
    CharaCtrlSetScriptCtrlStatus(*(void **)(StageLayout_LEO_TORCH1_ANIM + 0x48), *(s32 *)(*(u8 **)ScriptCtrlDef_SCRLeoTorchFinish + 4));
    CharaCtrlSetScriptCtrlStatus(*(void **)(StageLayout_LEO_TORCH2_ANIM + 0x48), *(s32 *)(*(u8 **)ScriptCtrlDef_SCRLeoTorchFinish + 4));
    CharaCtrlSetScriptCtrlStatus(*(void **)(StageLayout_LEO_TORCH3_ANIM + 0x48), *(s32 *)(*(u8 **)ScriptCtrlDef_SCRLeoTorchFinish + 4));
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0085_nico_leoBossStart", func_40074FC8);
void func_40074FC8(void)
{
    SetLayoutObjAccessSwitch(*(void **)(StageLayout_LEO_TORCH1 + 0x48), 1);
    D_40203838 = 1;
    torchObjRelease(SCRGetFirstObj(gcGlobalVar + 0x2B0));
    CharaCtrlSetScriptCtrlStatus(*(void **)(StageLayout_LEO_TORCH0_ANIM + 0x48), *(s32 *)(*(u8 **)ScriptCtrlDef_SCRLeoTorchFinish + 4));
    CharaCtrlSetScriptCtrlStatus(*(void **)(StageLayout_LEO_TORCH2_ANIM + 0x48), *(s32 *)(*(u8 **)ScriptCtrlDef_SCRLeoTorchFinish + 4));
    CharaCtrlSetScriptCtrlStatus(*(void **)(StageLayout_LEO_TORCH3_ANIM + 0x48), *(s32 *)(*(u8 **)ScriptCtrlDef_SCRLeoTorchFinish + 4));
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0085_nico_leoBossStart", func_40075068);
void func_40075068(void)
{
    SetLayoutObjAccessSwitch(*(void **)(StageLayout_LEO_TORCH2 + 0x48), 1);
    D_40203838 = 1;
    torchObjRelease(SCRGetFirstObj(gcGlobalVar + 0x2B0));
    CharaCtrlSetScriptCtrlStatus(*(void **)(StageLayout_LEO_TORCH0_ANIM + 0x48), *(s32 *)(*(u8 **)ScriptCtrlDef_SCRLeoTorchFinish + 4));
    CharaCtrlSetScriptCtrlStatus(*(void **)(StageLayout_LEO_TORCH1_ANIM + 0x48), *(s32 *)(*(u8 **)ScriptCtrlDef_SCRLeoTorchFinish + 4));
    CharaCtrlSetScriptCtrlStatus(*(void **)(StageLayout_LEO_TORCH3_ANIM + 0x48), *(s32 *)(*(u8 **)ScriptCtrlDef_SCRLeoTorchFinish + 4));
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0085_nico_leoBossStart", func_40075108);
void func_40075108(void)
{
    SetLayoutObjAccessSwitch(*(void **)(StageLayout_LEO_TORCH3 + 0x48), 1);
    D_40203838 = 1;
    torchObjRelease(SCRGetFirstObj(gcGlobalVar + 0x2B0));
    CharaCtrlSetScriptCtrlStatus(*(void **)(StageLayout_LEO_TORCH0_ANIM + 0x48), *(s32 *)(*(u8 **)ScriptCtrlDef_SCRLeoTorchFinish + 4));
    CharaCtrlSetScriptCtrlStatus(*(void **)(StageLayout_LEO_TORCH1_ANIM + 0x48), *(s32 *)(*(u8 **)ScriptCtrlDef_SCRLeoTorchFinish + 4));
    CharaCtrlSetScriptCtrlStatus(*(void **)(StageLayout_LEO_TORCH2_ANIM + 0x48), *(s32 *)(*(u8 **)ScriptCtrlDef_SCRLeoTorchFinish + 4));
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0085_nico_leoBossStart", func_400751A8);
void func_400751A8(void)
{
    s32 v;
    u8 *work = GetSCRCharaAIWorkPtr();

    if (*(s32 *)(work + 0x41A0) == 0)
    {
        isysRequestDeleteObj(*(void **)(work + 0x4198));
        isysRequestDeleteObj(*(void **)(work + 0x419C));
        isysRequestDeleteObj(*(void **)(work + 0x4190));
        isysRequestDeleteObj(*(void **)(work + 0x4194));
        v = *(s32 *)(work + 0x41A0) + 1;
    }
    else
    {
        if (*(s32 *)(work + 0x41A0) != 1)
        {
            return;
        }
        v = 2;
    }
    *(s32 *)(work + 0x41A0) = v;
}

void func_40075218(void) {
}

void func_40075220(void) {
}

void func_40075228(void) {
}

void func_40075230(void) {
}

extern s32 D_401317C4;

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0085_nico_leoBossStart", setNowLoadingMessageDisplayFlag);
void setNowLoadingMessageDisplayFlag(s32 a0)
{
    D_401317C4 = a0;
}

/* NEARMISS-STUB nowLoadingScript */
#if 0 /* NEARMISS 83.0% cat=regalloc sub=- | s3/s4 global pointer assignment | attempts=1 */
extern const char D_40133968[];
u8 *GetSpriteMenuClass(void *thread);
void *texSearchMopByName(const char *name);
void SpriteMenuSetLayer(void *thread, s32 layer);
void SpriteMenuSetDispFlagAll(void *thread, s32 flag);
s32 SpriteMenuIsFadeCheckAllLayer(void *thread);
f32 texAnimationOne(f32 a, f32 b, void *c);
void scrRun(void);

void nowLoadingScript(void)
{
    s32 *pflag = &D_401317C4;
    u8 *g = gcGlobalVar;
    void *thread = isysGetThisSubThread();
    u8 *cls = GetSpriteMenuClass(thread);
    void *tex = texSearchMopByName(D_40133968);
    f32 f;
    s32 prev;
    s32 cur;

    *pflag = 0;
    prev = -1;
    f = *(f32 *)(g + 0x168);
    SpriteMenuSetLayer(thread, 0);
    cur = *pflag;
    for (;;)
    {
        if (prev != cur)
        {
            SpriteMenuSetDispFlagAll(thread, cur);
            cur = *pflag;
        }
        if (cur != 0 || SpriteMenuIsFadeCheckAllLayer(thread) != 0)
        {
            f = texAnimationOne(f, *(f32 *)(g + 0x170), tex);
        }
        ((void (*)(f32, void *, s32, s32, s32))(*(void **)(cls + 0x28)))(*(f32 *)(g + 0x170), thread, 0, 0, 0);
        ((void (*)(void *))(*(void **)(cls + 0x2C)))(thread);
        prev = D_401317C4;
        scrRun();
        cur = *pflag;
    }
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0085_nico_leoBossStart", nowLoadingScript);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0085_nico_leoBossStart", nico_mammosBossStart);
void nico_mammosBossStart(void)
{
    void *thread = isysGetThisSubThread();
    s32 size = SCRGetSizeOfBossWork(thread);
    void *part = iosCreatePartition(&rootPtn, size + 0x41C3);
    u8 *cls = GetScriptCharacterClass(thread);
    void *mem;
    void *boss;

    *(void **)(cls + 0x114C) = part;
    CharaCtrlResetCtrlStatus(thread);
    CharaCtrlResetAllScriptCtrlStatus(thread);
    cls = GetScriptCharacterClass(thread);
    mem = _SCRMallocAlign(part, 0x4190, 0x10);
    *(void **)(cls + 0x1150) = mem;
    boss = SCRCharaInitBossWork(part, thread);
    *(void **)mem = boss;
    SetScriptCharacterObjReleaseCallBackFunc(thread, SCRReleaseBossWork, boss);
    CharaCtrlResetCtrlStatus(thread);
    cls = GetScriptClass(thread);
    initScriptDataSystem(thread, *(void **)(cls + 0x48));
    isysJumpSubThread(func_40075428, mem);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0085_nico_leoBossStart", func_40075428);
void func_40075428(s32 *a0)
{
    void *thread;

    isysGetThisSubThread();
    for (;;)
    {
        thread = isysGetThisSubThread();
        SCRExecBossPreProcess(*a0);
        CharaCtrlResetAllScriptCtrlStatus(thread);
        updateScriptDataSystem(thread);
        isysGetThisSubThread();
        SCRExecBossPostProcess(*a0);
        scrRunM(1);
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0085_nico_leoBossStart", nico_mammothArmRightTexEnd);
void nico_mammothArmRightTexEnd(void)
{
    bootTexAlphaAnim(0.0f, -0.05f, isysGetThisSubThread(), D_401317C8);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0085_nico_leoBossStart", nico_mammothArmRightTexStart);
void nico_mammothArmRightTexStart(void)
{
    bootTexAlphaAnim(1.0f, 0.05f, isysGetThisSubThread(), D_401317C8);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0085_nico_leoBossStart", nico_mammothArmLeftTexEnd);
void nico_mammothArmLeftTexEnd(void)
{
    bootTexAlphaAnim(0.0f, -0.05f,isysGetThisSubThread(), D_401317E0);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0085_nico_leoBossStart", nico_mammothArmLeftTexStart);
void nico_mammothArmLeftTexStart(void)
{
    bootTexAlphaAnim(1.0f, 0.05f, isysGetThisSubThread(), D_401317E0);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0085_nico_leoBossStart", nico_mammothLegRightTexEnd);
void nico_mammothLegRightTexEnd(void)
{
    bootTexAlphaAnim(0.0f, -0.05f, isysGetThisSubThread(), D_401317F8);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0085_nico_leoBossStart", nico_mammothLegRightTexStart);
void nico_mammothLegRightTexStart(void)
{
    bootTexAlphaAnim(1.0f, 0.05f, isysGetThisSubThread(), D_401317F8);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0085_nico_leoBossStart", nico_mammothLegLeftTexEnd);
void nico_mammothLegLeftTexEnd(void)
{
    bootTexAlphaAnim(0.0f, -0.05f, isysGetThisSubThread(), D_40131810);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0085_nico_leoBossStart", nico_mammothLegLeftTexStart);
void nico_mammothLegLeftTexStart(void)
{
    bootTexAlphaAnim(1.0f, 0.05f, isysGetThisSubThread(), D_40131810);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0085_nico_leoBossStart", nico_mammothAllTexEnd);
void nico_mammothAllTexEnd(void)
{
    void *th = isysGetThisSubThread();

    ((void (*)(void *, void *, f32, f32))bootTexAlphaAnim)(th, D_401317C8, 0.0f, -0.05f);
    ((void (*)(void *, void *, f32, f32))bootTexAlphaAnim)(th, D_401317E0, 0.0f, -0.05f);
    ((void (*)(void *, void *, f32, f32))bootTexAlphaAnim)(th, D_401317F8, 0.0f, -0.05f);
    ((void (*)(void *, void *, f32, f32))bootTexAlphaAnim)(th, D_40131810, 0.0f, -0.05f);
}

static inline char *dldResolve(unsigned int *h)
{
    unsigned int v = *h;
    int off = v & 0x3FFFF;
    int *t = 0;

    if (off != 0)
        t = *(int **)((char *)h - off);
    return (t != 0 && t != (int *)DldSysUndefSymbol) ? (char *)t[4] + ((v >> 18) & 0xFFF) * ((int *)t[2])[3] : 0;
}

static inline char *dldResolveRe(unsigned int *h)
{
    int off = *h & 0x3FFFF;
    int *t = off != 0 ? *(int **)((char *)h - off) : 0;

    return (t != 0 && t != (int *)DldSysUndefSymbol) ? (char *)t[4] + ((*h >> 18) & 0xFFF) * ((int *)t[2])[3] : 0;
}

void mc_save_scr_begin(void *obj)
{
    char *g = obj != 0 ? *(char **)(GetLayoutClass(obj) + 0x1A4) : 0;
    char *p = 0;

    if (g != 0)
        p = dldResolveRe((unsigned int *)dldResolve((unsigned int *)(g + 0x10)));
    bootMemoryCardSaveScriptNoBlock(p);
}
