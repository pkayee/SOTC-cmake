#include "common.h"
#include "gcc/math.h"

extern f32 D_40082280[];
extern s32 D_400458E4;
extern s32 D_400458E8;
extern s32 D_400458EC;
extern s32 D_400458F0;

void iosGetSinCosf(f32 *out, f32 x);
f32 iosGetSinf(f32 x);
f32 iosGetCosf(f32 x);
void iosGetSinCos(f32 *out, s32 a);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/trig", iosGetAlignSinCosf);
void iosGetAlignSinCosf(f32 *arg0, f32 arg1)
{
    f32 sp[2];

    iosGetSinCosf(sp, arg1);
    arg0[0] = sp[1];
    arg0[1] = sp[0];
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/trig", iosGetSinCosf);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/trig", func_40023498);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/trig", iosGetSinf);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/trig", func_400235DC);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/trig", iosGetCosf);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/trig", func_40023700);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/trig", iosGetTanf);
f32 iosGetTanf(f32 arg0)
{
    f32 sp[2];

    iosGetSinCosf(sp, arg0);
    return sp[1] / sp[0];
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/trig", iosGetSinCos);
void iosGetSinCos(f32 *arg0, s32 arg1)
{
    iosGetSinCosf(arg0, (f32)arg1 * 4.6566099e-10f * 3.14159265f);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/trig", iosGetSin);
f32 iosGetSin(s32 arg0)
{
    return iosGetSinf((f32)arg0 * 4.6566099e-10f * 3.14159265f);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/trig", iosGetCos);
f32 iosGetCos(s32 arg0)
{
    return iosGetCosf((f32)arg0 * 4.6566099e-10f * 3.14159265f);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/trig", iosGetTan);
f32 iosGetTan(s32 arg0)
{
    f32 sp[2];

    iosGetSinCos(sp, arg0);
    return sp[1] / sp[0];
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/trig", iosGetACosf);
f32 iosGetACosf(f32 arg0)
{
    f32 x2 = arg0 * arg0;
    f32 x3 = x2 * arg0;
    f32 x4 = x3 * arg0;
    f32 x5 = x4 * arg0;
    f32 x6 = x5 * arg0;
    f32 x7 = x6 * arg0;
    f32 x8 = x7 * arg0;
    f32 x9 = x8 * arg0;

    return 1.5707963f - arg0 - x3 * 0.16666666f - x5 * 0.075f - x7 * 0.044642858f - x9 * 0.030381944f;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/trig", iosGetACos);
f32 iosGetACos(s32 arg0)
{
    f32 arg = (f32)arg0 * 4.6566099e-10f;
    f32 x2 = arg * arg;
    f32 x3 = x2 * arg;
    f32 x4 = x3 * arg;
    f32 x5 = x4 * arg;
    f32 x6 = x5 * arg;
    f32 x7 = x6 * arg;
    f32 x8 = x7 * arg;
    f32 x9 = x8 * arg;

    return 1.5707963f - arg - x3 * 0.16666666f - x5 * 0.075f - x7 * 0.044642858f - x9 * 0.030381944f;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/trig", iosGetACosfExact);
f32 iosGetACosfExact(f32 arg0)
{
    if (arg0 >= 1.0f)
    {
        return 0.0f;
    }
    if (arg0 <= -1.0f)
    {
        return 3.14159265f;
    }
    return acosf(arg0);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/trig", iosGetASinfExact);
f32 iosGetASinfExact(f32 arg0)
{
    if (arg0 >= 1.0f)
    {
        return 3.14159265f / 2.0f;
    }
    if (arg0 <= -1.0f)
    {
        return -3.14159265f / 2.0f;
    }
    return asinf(arg0);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/trig", iosGetATanfExact);
f32 iosGetATanfExact(f32 arg0)
{
    return atanf(arg0);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/trig", iosGetATan2fExact);
f32 iosGetATan2fExact(f32 arg0, f32 arg1)
{
    if (arg0 > 1.0f)
    {
        arg0 = 1.0f;
    }
    else if (arg0 < -1.0f)
    {
        arg0 = -1.0f;
    }
    if (arg1 > 1.0f)
    {
        arg1 = 1.0f;
    }
    else if (arg1 < -1.0f)
    {
        arg1 = -1.0f;
    }
    return atan2f(arg0, arg1);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/trig", iosGetASin);
f32 iosGetASin(void)
{
    return 0.0f;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/trig", iosGetATan2);
f32 iosGetATan2(void)
{
    return 0.0f;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/trig", resetArcFuncCall);
void resetArcFuncCall(void)
{
    D_400458E4 = D_400458E8 = D_400458EC = D_400458F0 = 0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/trig", iosGetTableSin);
f32 iosGetTableSin(s16 arg0)
{
    s32 neg = 0;
    s32 idx = (((s32)arg0 << 16) - 0x40000000) >> 16;

    idx = idx < 0 ? -idx : idx;
    if (idx > 0x3FFF)
    {
        idx = 0x8000 - idx;
        neg = 1;
    }
    return neg ? -D_40082280[idx] : D_40082280[idx];
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/trig", iosGetTableCos);
f32 iosGetTableCos(s16 arg0)
{
    s32 neg = 0;
    s32 idx = arg0 < 0 ? -arg0 : arg0;

    if (idx > 0x3FFF)
    {
        idx = 0x8000 - idx;
        neg = 1;
    }
    return neg ? -D_40082280[idx] : D_40082280[idx];
}

/* NEARMISS-STUB InitTableSinCos */
#if 0 /* NEARMISS 93.93% cat=regalloc sub=flag-in-s3 | regalloc: flag addr kept in extra saved s3 (frame 0x50 vs target); sqrt result held in f1 on NaN-check path; table/sinTable copy placement (kN2 re-diff) | attempts=1 */
// SCORE 93.93% (angle scale 1.0f/16384.0f, pi/2 1.5707963f; arm pointer names swapped: sqrt arm writes table[0], cos arm writes sinTable[0]) (INCLUDE_ASM in tree). needs extern s32 D_400458F4. Diff: target frame 0x50, extra saved s3 (flag addr), sqrt result kept in f1 (NaN-check path).
void InitTableSinCos(void)
{
    s32 i; f32 *table; f32 *sinTable; f32 angle; f32 v;
    if (D_400458F4 == 0)
    {
        table = D_40082280;
        sinTable = D_40082280;
        for (i = 0; i <= 0x4000; i++)
        {
            angle = (f32)i * (1.0f / 16384.0f);
            if (angle > 0.5f) { v = sinf(angle * 1.5707963f); table[0] = sqrtf(1.0f - v * v); }
            else { sinTable[0] = cosf(angle * 1.5707963f); }
            table++; sinTable++;
        }
        D_400458F4 = 1;
    }
}
// remaining: target does addiu v0,lo; daddu s1,v0,zero (table = copy of address temp); sinTable=s1 copy placed after i=0 init
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/trig", InitTableSinCos);
