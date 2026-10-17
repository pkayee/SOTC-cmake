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

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/trig", func_40023498);
void func_40023498(f32 *arg0)
{
    asm volatile(
        "mfc1 $8,$f5\n"
        "qmtc2.ni $8,$vf16\n"
        "lqc2 $vf15,0($2)\n"
        "vmr32.w $vf16,$vf16\n"
        "vaddx.x $vf18,$vf0,$vf16x\n"
        "vmul.x $vf16,$vf16,$vf16\n"
        "vmulx.yzw $vf18,$vf18,$vf0x\n"
        "vmulw.xyzw $vf19,$vf15,$vf16w\n"
        "vmulx.xyzw $vf19,$vf19,$vf16x\n"
        "vmulx.xyz $vf19,$vf19,$vf16x\n"
        "vaddw.x $vf18,$vf18,$vf19w\n"
        "vmulx.xy $vf19,$vf19,$vf16x\n"
        "vaddz.x $vf18,$vf18,$vf19z\n"
        "vmulx.x $vf19,$vf19,$vf16x\n"
        "vaddy.x $vf18,$vf18,$vf19y\n"
        "vaddx.x $vf18,$vf18,$vf19x\n"
        "vaddx.xy $vf18,$vf0,$vf18x\n"
        "vmul.x $vf17,$vf18,$vf18\n"
        "vsubx.w $vf17,$vf0,$vf17x\n"
        "vsqrt Q,$vf17w\n"
        "bnez $7,1f\n"
        "vwaitq\n"
        "vaddq.y $vf18,$vf0,Q\n"
        "b 2f\n"
        "1:\n"
        "vwaitq\n"
        "vsubq.y $vf18,$vf0,Q\n"
        "2:\n"
        "sqc2 $vf18,0($4)\n"
        :
        :
        : "$2", "$4", "$7", "$8");
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/trig", iosGetSinf);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/trig", func_400235DC);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/trig", iosGetCosf);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/trig", func_40023700);
f32 func_40023700(void)
{
    register f32 ret asm("$f12");

    asm volatile(
        "mfc1 $8,$f5\n"
        "qmtc2 $8,$vf16\n"
        "lqc2 $vf15,0($2)\n"
        "vmr32.w $vf16w,$vf16w\n"
        "vaddx.x $vf18x,$vf0x,$vf16x\n"
        "vmul.x $vf16x,$vf16x,$vf16x\n"
        "vmulx.yzw $vf18yzw,$vf18yzw,$vf0x\n"
        "vmulw.xyzw $vf19xyzw,$vf15xyzw,$vf16w\n"
        "vmulx.xyzw $vf19xyzw,$vf19xyzw,$vf16x\n"
        "vmulx.xyz $vf19xyz,$vf19xyz,$vf16x\n"
        "vaddw.x $vf18x,$vf18x,$vf19w\n"
        "vmulx.xy $vf19xy,$vf19xy,$vf16x\n"
        "vaddz.x $vf18x,$vf18x,$vf19z\n"
        "vmulx.x $vf19x,$vf19x,$vf16x\n"
        "vaddy.x $vf18x,$vf18x,$vf19y\n"
        "vaddx.x $vf18x,$vf18x,$vf19x\n"
        "qmfc2 $7,$vf18\n"
        "mtc1 $7,$f12\n"
        : "=f"(ret)
        :
        : "$7", "$8");
    return ret;
}

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

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/trig", iosGetACosf);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/trig", iosGetACos);

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

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/trig", InitTableSinCos);
