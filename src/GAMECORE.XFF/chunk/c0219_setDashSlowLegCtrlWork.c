#include "common.h"

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0219_setDashSlowLegCtrlWork", setDashSlowLegCtrlWork);
void setDashSlowLegCtrlWork(void *arg0, int arg1)
{
    (*(int *)((char *)(arg0) + 0x30)) = arg1;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0219_setDashSlowLegCtrlWork", setStabilizeYSlowLegCtrlWork);
void setStabilizeYSlowLegCtrlWork(void *arg0, int arg1)
{
    (*(int *)((char *)(arg0) + 0x3C)) = arg1;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0219_setDashSlowLegCtrlWork", setMoveModeSlowLegCtrlWork);
void setMoveModeSlowLegCtrlWork(void *arg0, int arg1)
{
    (*(int *)((char *)(arg0) + 0x34)) = arg1;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0219_setDashSlowLegCtrlWork", setMotScaleMaxSlowLegCtrlWork);
void setMotScaleMaxSlowLegCtrlWork(void *arg0, float fparg0)
{
    (*(float *)((char *)(arg0) + 0x38)) = fparg0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0219_setDashSlowLegCtrlWork", setAttainMotScaleSlowLegCtrlWork);
void setAttainMotScaleSlowLegCtrlWork(void *arg0, float fparg0)
{
    (*(float *)((char *)(arg0) + 0x40)) = fparg0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0219_setDashSlowLegCtrlWork", setGuardModeSlowLegCtrlWork);
void setGuardModeSlowLegCtrlWork(void *arg0, int arg1)
{
    (*(int *)((char *)(arg0) + 0x9C)) = arg1;
}

void deleteSlowLegCtrlWork(void) {
}

extern void _resetBaseMoveWork(void *, u8 *);
extern u8 *GetCharacterClass(void *);
void func_40116ED0(u8 *w);

void func_40116E60(void *obj, u8 *w)
{
    _resetBaseMoveWork(obj, w);
    *(s32 *)(w + 0x30) = 0;
    *(f32 *)(w + 0x40) = 1.0f;
    *(s32 *)(w + 0x9C) = 0;
    *(s32 *)(w + 0x34) = 0;
    *(s32 *)(w + 0x74) = 0;
    *(s32 *)(w + 0x78) = 0;
    *(s32 *)(w + 0x3C) = 0;
    func_40116ED0(w);
    *(s32 *)(w + 0x98) = *(s8 *)(GetCharacterClass(obj) + 0x35F);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0219_setDashSlowLegCtrlWork", func_40116ED0);
void func_40116ED0(u8* w)
{
    *(s32*)(w + 0x94) = 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0219_setDashSlowLegCtrlWork", func_40116ED8);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0219_setDashSlowLegCtrlWork", func_40116FB8);
float calcAngleTime(float angle, float a, float b, float c);

float func_40116FB8(char *obj, float angle)
{
    return calcAngleTime(angle, *(float *)(obj + 0xA8), *(float *)(obj + 0xA4),
                         *(float *)(**(char ***)(obj + 0x1C) + 0x78));
}

extern void PredictMotionGeometryPotentialWithScaleElem(void *, f32 *, s32, s32, f32, f32);

void func_40116FE0(f32 s, u8 *o, f32 *v)
{
    u8 *w = *(u8 **)(o + 0xCC);
    f32 d[4];
    f32 pos[4];
    f32 *m = *(f32 **)(o + 0x1C);

    PredictMotionGeometryPotentialWithScaleElem(pos, d, *(s32 *)(o + 8), *(s32 *)m, m[3], -1.0f);
    if ((d[0] >= 0.0f && *v >= 0.0f) || (d[0] <= 0.0f && *v <= 0.0f))
        *(f32 *)(o + 0x160) = *(f32 *)(o + 0x154) / s;
    else
        *(f32 *)(o + 0x160) = *(f32 *)(w + 0x58);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0219_setDashSlowLegCtrlWork", createWormCtrlWork);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0219_setDashSlowLegCtrlWork", updateWormCtrlWork);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0219_setDashSlowLegCtrlWork", func_40117B30);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0219_setDashSlowLegCtrlWork", func_40117F40);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0219_setDashSlowLegCtrlWork", func_40118290);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0219_setDashSlowLegCtrlWork", func_40118620);
