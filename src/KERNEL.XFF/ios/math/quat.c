#include "common.h"

extern s32 D_400458D0;
extern f32 D_40081E80[][4];
extern f32 YUnitVector[4];
extern f32 YUnitVectorInv[4];
extern f32 XUnitVector[4];
extern f32 ZUnitVector[4];
f32 iosGetACosfExact(f32 x);

void iosTransposeMatrix(f32 *dst, f32 *src);
void InitQuaternionDrive(void);
void func_4001FCA8(f32 *dst, f32 *src);
void SetQuaternionByAxisRotateVWithNoRegularize(f32 *dst, s16 angle, f32 *axis);
void SetQuaternionByAxisRotateVWithNoRegularizeRadian(f32 *dst, f32 *axis, f32 rad);
void iosGetSinCosf(f32 *out, f32 x);
f32 iosGetTableSin(s16 angle);
f32 iosGetTableCos(s16 angle);
void GetDifferencialQuaternionWithNoRegularize(f32 *dst, f32 *a, f32 *b, f32 *c);
void GetEulerYXZFromQuaternion(f32 *dst, f32 *src);
void iosInverseMatrix(f32 *dst, f32 *src);
void iosMulCurrentMatrixR(f32 *m);

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

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", InvertCurrentQuaternion);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", SetCurrentQuaternion);
void SetCurrentQuaternion(u128 *src)
{
    *(u128 *)D_40081E80[D_400458D0] = *src;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", RotCurrentQuaternionX);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", RotCurrentQuaternionY);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", RotCurrentQuaternionZ);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", PushQuaternion);
void PushQuaternion(void)
{
    s32 n;
    if (D_400458D0 < 0)
    {
        InitQuaternionDrive();
    }
    n = D_400458D0 + 1;
    D_400458D0 = n;
    if (n >= 0x40)
    {
        D_400458D0 = 0x3F;
    }
    *(u128 *)D_40081E80[D_400458D0] = *(u128 *)D_40081E80[D_400458D0 - 1];
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", PushQuaternionWithNoCopy);
void PushQuaternionWithNoCopy(void)
{
    s32 n;
    if (D_400458D0 < 0)
    {
        InitQuaternionDrive();
    }
    n = D_400458D0 + 1;
    D_400458D0 = n;
    if (n >= 0x40)
    {
        D_400458D0 = 0x3F;
    }
}

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

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", SetQuaternionByAxisRotateV);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", SetQuaternionByAxisRotateVExact);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", SetQuaternionByAxisRotateVWithNoRegularize);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", DivQuaternion);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", GetInverseMatrixFromQuaternionPos);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", MultiMatrixByQuaternion);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", GetMirrorQuaternion);
void GetMirrorQuaternion(f32 *dst, u128 *src, s32 n)
{
    *(u128 *)dst = *src;
    switch (n)
    {
    case 0:
        dst[0] = -dst[0];
        break;
    case 1:
        dst[1] = -dst[1];
        break;
    case 2:
        dst[2] = -dst[2];
        break;
    case 3:
        dst[0] = -dst[0];
        dst[1] = -dst[1];
        break;
    case 4:
        dst[0] = -dst[0];
        dst[2] = -dst[2];
        break;
    case 5:
        dst[1] = -dst[1];
        dst[2] = -dst[2];
        break;
    case 6:
    default:
        dst[0] = -dst[0];
        dst[1] = -dst[1];
        dst[2] = -dst[2];
        break;
    }
}

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

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", SetQuaternionByCosineAxisRotateVWithNoRegularize);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", SetQuaternionByAxisRotateVWithNoRegularizeRadian);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", GetYRotQuaternionFromDir);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", GetStabYRotQuaternion);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", StabilizeToYRotQuaternion);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", GetQuaternionByEulerYXZ);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", GetQuaternionByEulerYXZExact);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", GetEulerYXZFromQuaternionZHalfPI);
void GetEulerYXZFromQuaternionZHalfPI(f32 *dst, f32 *src)
{
    GetEulerYXZFromQuaternion(dst, src);
    if (dst[2] < 0.0f ? dst[2] < -1.5707963f : 1.5707963f < dst[2])
    {
        if (dst[1] < 0.0f)
        {
            dst[1] = dst[1] + 3.1415926f;
        }
        else
        {
            dst[1] = dst[1] - 3.1415926f;
        }
        if (dst[0] > 0.0f)
        {
            dst[0] = 3.1415926f - dst[0];
        }
        else
        {
            dst[0] = -3.1415926f - dst[0];
        }
        if (dst[2] > 0.0f)
        {
            dst[2] = dst[2] - 3.1415926f;
        }
        else
        {
            dst[2] = dst[2] + 3.1415926f;
        }
    }
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", GetQuaternionByEulerZXY);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", GetQuaternionByEulerZXYExact);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", GetQuaternionByEulerXYZ);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", GetQuaternionByEulerXYZExact);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", GetLimitationQuaternion);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", GetZDirFromQuaternion);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", GetQuaternionByDegEulerYXZ);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", GetQuaternionAxisRotInfo);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/quat", SetQuaternionByCosineAxisRotateV);
