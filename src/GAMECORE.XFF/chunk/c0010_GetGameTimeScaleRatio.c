#include "common.h"

extern s32 rootPtn;
extern u8 gcGlobalVar[];
extern const char D_40132CC0[];
extern const char D_40132CD0[];
extern const char D_40132CE0[];
extern const char D_40132CF0[];
extern const char D_40132D08[];
extern f32 D_40130A60;
extern f32 D_40130A64;
extern s32 D_40130A68;
extern s64 D_40130A70;
extern s32 D_40130AE8;
extern f32 D_40130AC8;
extern s32 D_40130ACC;
extern f32 D_40130AE0;
extern s32 D_40130AB8;
extern s32 D_40130AD0;

void createScriptObj(void *fn, s32 a1, void *a2, s32 a3, s32 a4, s32 a5, void *a6, s32 a7);
s32 checkFadeParam(void *param);
void setFadeParam(void *param, s32 value);

void gcCreateScriptObj(void *fn, s32 a1, void *a2, s32 a3, s32 a4, s32 a5, const char *a6);
void func_400222E8(void);
void func_40022168(void);
void func_40022220(void);
void func_400221B8(void);
void func_40022270(void);

/* NEARMISS-STUB GetGameTimeScaleRatio */
#if 0 /* NEARMISS 98.33% cat=rodata-const sub=- | lui %hi(gcGlobalVar+off) folded by gcc vs expected lui %hi(gcGlobalVar)+lo addend | attempts=1 */
f32 GetGameTimeScaleRatio(void) {
    return *(f32*)(gcGlobalVar + 0x19C);
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", GetGameTimeScaleRatio);

/* NEARMISS-STUB PauseAI */
#if 0 /* NEARMISS 98.75% cat=rodata-const sub=- | lui %hi(gcGlobalVar+off) folded by gcc vs expected lui %hi(gcGlobalVar)+lo addend | attempts=1 */
void PauseAI(void) {
    *(s32*)(gcGlobalVar + 0x310) = 1;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", PauseAI);

/* NEARMISS-STUB ReleaseAI */
#if 0 /* NEARMISS 98.33% cat=rodata-const sub=- | lui %hi(gcGlobalVar+off) folded by gcc vs expected lui %hi(gcGlobalVar)+lo addend | attempts=1 */
void ReleaseAI(void) {
    *(s32*)(gcGlobalVar + 0x310) = 0;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", ReleaseAI);

void SwitchPadAct(void) {
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", gcCreateScriptObj);
void gcCreateScriptObj(void *fn, s32 a1, void *a2, s32 a3, s32 a4, s32 a5, const char *a6)
{
    createScriptObj(fn, a1, a2, a3, a4, a5, 0, 0);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", _gcCreateChildScriptObj);
void _gcCreateChildScriptObj(void *fn, s32 a1, void *a2, s32 a3, s32 a4, s32 a5, void *a6, void *a7)
{
    createScriptObj(fn, a1, a2, a3, a4, a5, a7, 0);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", ChangeGameAnimeTimeScaleRatio);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", GetCurrentGameAnimeTimeScaleRatio);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", GetGameAnimeTimeScaleRatio);
f32 GetGameAnimeTimeScaleRatio(void)
{
    return D_40130A64;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", GetPlayerControlButtonContext);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", getGameAnimeTimeScaleRatio);
void *getGameAnimeTimeScaleRatio(void)
{
    return &D_40130A60;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", RestoreDefaultGameAnimeTimeScaleRatio);
void RestoreDefaultGameAnimeTimeScaleRatio(void)
{
    D_40130A64 = 0.9f;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", SetDefaultGameAnimeTimeScaleRatio);
void SetDefaultGameAnimeTimeScaleRatio(f32 ratio)
{
    D_40130A64 = ratio;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", setGameAnimeTimeScaleRatio);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", getDummyCount);
s64 getDummyCount(void)
{
    return D_40130A70;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", getFrameRateMode);
void *getFrameRateMode(void)
{
    return &D_40130A68;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", setFrameRateMode);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", func_40021D78);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", func_40021DB8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", func_40021E08);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", func_40021E58);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", setDefaultPlayerControlButton);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", func_40021EF0);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", initgcmaingp);
void initgcmaingp(void)
{
    gcCreateScriptObj(func_40022168, 0, &rootPtn, 0x1000, 0, 1, D_40132CD0);
    gcCreateScriptObj(func_40022220, 0, &rootPtn, 0x2000, 0, 10, D_40132CE0);
    gcCreateScriptObj(func_400221B8, 0, &rootPtn, 0x1000, 0, 11, D_40132CF0);
    gcCreateScriptObj(func_40022270, 0, &rootPtn, 0x1000, 0, 2, D_40132D08);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", setLayerFade);
void setLayerFade(s32 value)
{
    D_40130ACC = value;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", setFade);
void setFade(void)
{
    setFadeParam(&D_40130AB8, 0x1C);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", getFade);
s32 getFade(void)
{
    return checkFadeParam(&D_40130AB8);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", getFadeValue);
f32 getFadeValue(void)
{
    return D_40130AC8;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", getDemoBarSw);
void *getDemoBarSw(void)
{
    return &D_40130AE8;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", setDemoBar);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", getDemoBar);
s32 getDemoBar(void)
{
    return checkFadeParam(&D_40130AD0);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", getDemoBarFade);
f32 getDemoBarFade(void)
{
    return 1.0f - D_40130AE0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", func_40022168);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", func_400221B8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", func_40022220);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", func_40022270);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", initgcmain);
void initgcmain(void)
{
    gcCreateScriptObj(func_400222E8, 0, &rootPtn, 0x1000, 0, 1, D_40132CC0);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", func_400222E8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", constructor_nico_yaw_pitch_cntrl);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", func_400224A0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", func_40022668);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0010_GetGameTimeScaleRatio", func_40022820);
