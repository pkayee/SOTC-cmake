#include "common.h"

extern s32 D_400458D0;
extern f32 D_40081E80[][4];

void iosTransposeMatrix(f32 *dst, f32 *src);
void func_4001FCA8(f32 *dst, f32 *src);
void SetQuaternionByAxisRotateVWithNoRegularize(f32 *dst, s16 angle, f32 *axis);
void SetQuaternionByAxisRotateVWithNoRegularizeRadian(f32 *dst, f32 *axis, f32 rad);

static inline void NormalizeXYZ(f32 *dst, f32 *src)
{
    asm volatile(
        "lqc2 $vf5, 0(%1);"
        "vmul.xyz $vf7, $vf5, $vf5;"
        "vmulax.w ACC, $vf0, $vf7x;"
        "vmadday.w ACC, $vf0, $vf7y;"
        "vmaddz.w $vf7, $vf0, $vf7z;"
        "vrsqrt Q, $vf0w, $vf7w;"
        "vwaitq;"
        "vmulq.xyz $vf5, $vf5, Q;"
        "sqc2 $vf5, 0(%0)"
        : : "r"(dst), "r"(src) : "memory");
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", GetDifferencialQuaternionWithNoRegularize);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", func_4001FCA8);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", GetEulerYXZFromQuaternion);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", GetEulerZXYFromQuaternion);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", GetEulerXYZFromQuaternion);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", GetRotLimitationQuaternion);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", GetLimitationQuaternionWithBaseAxis);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", GetCurrentQuaternion);
f32 *GetCurrentQuaternion(void)
{
    return D_40081E80[D_400458D0];
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", GetLastQuaternion);
f32 *GetLastQuaternion(void)
{
    return D_40081E80[D_400458D0 - 1];
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", MultiCurrentQuaternion);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", MultiCurrentQuaternionL);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", InvertCurrentQuaternion);
void InvertCurrentQuaternion(void)
{
    f32 *q = D_40081E80[D_400458D0];
    asm volatile(
        "lqc2 $vf11, 0(%0);"
        "vsubw.x $vf5, $vf0, $vf0w;"
        "vmulx.xyz $vf11, $vf11, $vf5x;"
        "sqc2 $vf11, 0(%0)"
        : : "r"(q) : "memory");
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", SetCurrentQuaternion);
void SetCurrentQuaternion(u128 *src)
{
    *(u128 *)D_40081E80[D_400458D0] = *src;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", RotCurrentQuaternionX);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", RotCurrentQuaternionY);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", RotCurrentQuaternionZ);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", PushQuaternion);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", PushQuaternionWithNoCopy);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", PopQuaternion);
void PopQuaternion(void)
{
    s32 n = D_400458D0 - 1;
    if (n < 0)
    {
        n = 0;
    }
    D_400458D0 = n;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", InitQuaternionDrive);
void InitQuaternionDrive(void)
{
    D_400458D0 = 0;
    asm volatile("sqc2 $vf0, 0(%0)" : : "r"(D_40081E80) : "memory");
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", SetQuaternionByAxisRotate);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", SetQuaternionByAxisRotateWithNoRegularize);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", SetQuaternionByAxisRotateV);
void SetQuaternionByAxisRotateV(f32 *dst, s16 angle, f32 *axis)
{
    f32 tmp[4] __attribute__((aligned(16)));
    NormalizeXYZ(tmp, axis);
    SetQuaternionByAxisRotateVWithNoRegularize(dst, angle, tmp);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", SetQuaternionByAxisRotateVExact);
void SetQuaternionByAxisRotateVExact(f32 *dst, f32 *axis, f32 rad)
{
    f32 tmp[4] __attribute__((aligned(16)));
    NormalizeXYZ(tmp, axis);
    SetQuaternionByAxisRotateVWithNoRegularizeRadian(dst, tmp, rad);
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", SetQuaternionByAxisRotateVWithNoRegularize);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", DivQuaternion);
void DivQuaternion(f32 *dst, f32 *a, f32 *b)
{
    f32 tmp[4] __attribute__((aligned(16)));
    asm volatile(
        "lqc2 $vf11, 0(%2);"
        "vsubw.x $vf5, $vf0, $vf0w;"
        "vmulx.xyz $vf11, $vf11, $vf5x;"
        "sqc2 $vf11, 0(%3);"
        "lqc2 $vf11, 0(%3);"
        "lqc2 $vf12, 0(%1);"
        "vmul.xyzw $vf13, $vf11, $vf12;"
        "vaddy.x $vf13, $vf13, $vf13y;"
        "vaddz.x $vf13, $vf13, $vf13z;"
        "vsubx.w $vf13, $vf13, $vf13x;"
        "vmulw.xyz $vf14, $vf12, $vf11w;"
        "vmulw.xyz $vf15, $vf11, $vf12w;"
        "vopmula.xyz ACC, $vf12, $vf11;"
        "vopmsub.xyz $vf16, $vf11, $vf12;"
        "vadd.xyz $vf13, $vf14, $vf15;"
        "vadd.xyz $vf13, $vf13, $vf16;"
        "sqc2 $vf13, 0(%0)"
        : : "r"(dst), "r"(a), "r"(b), "r"(tmp) : "memory");
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", GetInverseMatrixFromQuaternionPos);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", MultiMatrixByQuaternion);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", GetMirrorQuaternion);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", RotQuaternionXExact);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", RotQuaternionYExact);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", RotQuaternionZExact);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", GetQuaternionFromMatrix);
void GetQuaternionFromMatrix(f32 *dst, f32 *mat)
{
    f32 tmp[16];
    iosTransposeMatrix(tmp, mat);
    func_4001FCA8(dst, tmp);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", CopyMultiQuaternion);
void CopyMultiQuaternion(u128 *dst, u128 *src, s32 n)
{
    s32 i;
    for (i = 0; i < n; i++)
    {
        dst[i] = src[i];
    }
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", GetQuaternionByAxisDirZY);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", GetQuaternionByAxisDirZYExact);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", GetQuaternionByAxisDirZX);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", SetQuaternionByCosineAxisRotateVWithNoRegularize);
void SetQuaternionByCosineAxisRotateVWithNoRegularize(f32 *dst, f32 *axis, f32 c)
{
    f32 w, s;
    asm volatile("sqrt.s %0,%1" : "=f"(w) : "f"((1.0f + c) * 0.5f));
    asm volatile("sqrt.s %0,%1" : "=f"(s) : "f"((1.0f - c) * 0.5f));
    asm volatile(
        "lqc2 $vf5, 0(%1);"
        "qmtc2.ni %2, $vf6;"
        "vmulx.xyzw $vf5, $vf5, $vf6x;"
        "sqc2 $vf5, 0(%0)"
        : : "r"(dst), "r"(axis), "r"(s) : "memory");
    dst[3] = w;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", SetQuaternionByAxisRotateVWithNoRegularizeRadian);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", GetYRotQuaternionFromDir);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", GetStabYRotQuaternion);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", StabilizeToYRotQuaternion);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", GetQuaternionByEulerYXZ);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", GetQuaternionByEulerYXZExact);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", GetEulerYXZFromQuaternionZHalfPI);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", GetQuaternionByEulerZXY);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", GetQuaternionByEulerZXYExact);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", GetQuaternionByEulerXYZ);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", GetQuaternionByEulerXYZExact);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", GetLimitationQuaternion);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", GetZDirFromQuaternion);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", GetQuaternionByDegEulerYXZ);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", GetQuaternionAxisRotInfo);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", SetQuaternionByCosineAxisRotateV);
