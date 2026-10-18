#include "common.h"

extern s32 ScriptSpriteMenuObjDef_SPRITE_CHOOSE_LANGUAGE_LAYOUT;
void _SCRStartSpriteMenuAnim(s32 obj, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0057_func_40054EC8", func_40054EC8);

void *GetSCRCharaAIWorkPtr(void *);
void *getPlayerColCont2(void *);
void *getSCRDataCtrlWork(int);

void SCRFuncCerberusSetPlayerParentObj(int arg0)
{
    void *temp_s1;

    temp_s1 = GetSCRCharaAIWorkPtr((void *)arg0);
    (*(int *)((char *)(temp_s1) + 0x41A8)) = (int) (*(int *)((char *)(getPlayerColCont2((*(void **)((char *)(getSCRDataCtrlWork(arg0)) + 0x4058)))) + 0x8));
}

void func_40054F20(void) {
}

typedef struct {
    char c[16];
} SpriteParam;

extern s32 sheetFsLanguageCode;
extern s32 D_401315A0;
void *isysGetThisSubThread(void);
char *GetSpriteMenuClass(unsigned char *thread);
void ScrSpriteParamSetup(SpriteParam *dst, SpriteParam *src);
void SpriteMenuSetDispFlagAll(unsigned char *thread, s32 flag);

void chooseLangScript(SpriteParam *parameters)
{
    SpriteParam local;
    int language;
    void *thread;

    thread = isysGetThisSubThread();
    GetSpriteMenuClass(thread);
    language = 1;
    ScrSpriteParamSetup(&local, parameters);
    SpriteMenuSetDispFlagAll(thread, 0);
    sheetFsLanguageCode = language;
    D_401315A0 = language;
}

int menuSelected(void)
{
    return D_401315A0;
}

void bootChooseLangScript(void)
{
    _SCRStartSpriteMenuAnim(ScriptSpriteMenuObjDef_SPRITE_CHOOSE_LANGUAGE_LAYOUT, 0, 0, 0, 0, 0);
}

void *isysGetThisSubThread(void);
void scrRunM(s32 n);

void nico_commonBossAI_home(void)
{
    isysGetThisSubThread();
    scrRunM(1);
}

extern u8 gcGlobalVar[];
void SCRCharaTurn(void *obj, f32 turn);
void SCRCharaAccel(void *obj, f32 accel, s32 n);
void SCRExecBossPostProcess(void *obj);

void nico_bossAIWalk(void **a)
{
    void *t = isysGetThisSubThread();
    void *o = *a;
    u8 *g = gcGlobalVar;
    for (;;) {
        SCRCharaTurn(t, 1.0f);
        SCRCharaAccel(t, *(f32 *)(g + 0x180), 10);
        SCRExecBossPostProcess(o);
        isysGetThisSubThread();
        scrRunM(1);
    }
}

extern char rootPtn[];
extern int iosCreatePartition(void *, int);
extern char *GetScriptCharacterClass(void *);
extern void CharaCtrlResetCtrlStatus(void *);
extern void CharaCtrlResetAllScriptCtrlStatus(void *);
extern int SCRGetSizeOfBossWork(void *);
extern int SCRCharaInitBossWork(int, void *);
extern void SCRReleaseBossWork(void);
extern void SetScriptCharacterObjReleaseCallBackFunc(void *, void (*)(void), int);
int _SCRMallocAlign();

void nico_CommonBossStart(void)
{
    void *th = isysGetThisSubThread();
    int part = iosCreatePartition(rootPtn, SCRGetSizeOfBossWork(th) + 0x37);
    char *c;
    int *w;
    int r;

    *(int *)(GetScriptCharacterClass(th) + 0x114C) = part;
    CharaCtrlResetCtrlStatus(th);
    CharaCtrlResetAllScriptCtrlStatus(th);
    c = GetScriptCharacterClass(th);
    w = (int *)_SCRMallocAlign(part, 4, 0x10);
    *(int **)(c + 0x1150) = w;
    r = SCRCharaInitBossWork(part, th);
    *w = r;
    SetScriptCharacterObjReleaseCallBackFunc(th, SCRReleaseBossWork, r);
    CharaCtrlResetCtrlStatus(th);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0057_func_40054EC8", _SCRPlayLWSWithTargetAttackedPoint);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0057_func_40054EC8", _SCRGetCollisionTwoBoneRay);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0057_func_40054EC8", func_40055690);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0057_func_40054EC8", func_400557D0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0057_func_40054EC8", getDebugDispType);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0057_func_40054EC8", getDebugMotionStop);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0057_func_40054EC8", getDebugScrDataPrintf);

s32 getDebugHorseRoute(void)
{
    return 0;
}

s32 getDebugHorseBikko(void)
{
    return 0;
}

s32 getDebugParentAttrReset(void)
{
    return 0;
}

s32 getDebugTrigerPrintf(void)
{
    return 0;
}

s32 getDebugHorseInsurance(void)
{
    return 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0057_func_40054EC8", getDebugViewDisp);

int GetDebugDispType(void)
{
    return 0;
}

int GetDebugMotionStop(void)
{
    return 0;
}

s32 GetDebugScrDataPrintf(void)
{
    return 0;
}

int GetDebugViewDisp(void)
{
    return 0;
}

extern int iosMallocAlign();

int _SCRMallocAlign(int a, int b, int c, int d)
{
    return iosMallocAlign(a, b, c, d);
}

extern void *GAMEUTIL_get_first_obj(void *list);

void *SCRGetFirstObj(void *list)
{
    return GAMEUTIL_get_first_obj(list);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0057_func_40054EC8", SCRGetTargetPosXZDirOnMyCtrlGeo);
