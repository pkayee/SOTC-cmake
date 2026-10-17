#include "common.h"

typedef struct
{
    s64 lo;
    s64 hi;
} MvecRaw;

typedef union
{
    u_long128 q;
    u32 w[4];
} MvecU;

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/mvec", iosMvecZero);
void iosMvecZero(u_long128 *dst)
{
    u_long128 r;
    asm("daddu %0, $0, $0" : "=r"(r));
    *dst = r;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/mvec", iosMvecAllOnes);
void iosMvecAllOnes(u_long128 *dst)
{
    u_long128 r;
    asm("pceqw %0, $0, $0" : "=r"(r));
    *dst = r;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/mvec", iosMvecAllOne);
void iosMvecAllOne(u_long128 *dst)
{
    u_long128 r;
    asm("pceqw %0, $0, $0" : "=r"(r));
    asm volatile("psrlw %0, %1, 31" : "=r"(r) : "r"(r));
    *dst = r;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/mvec", iosAddMvec);
void iosAddMvec(u_long128 *dst, u_long128 *a, u_long128 *b)
{
    MvecRaw x = *(MvecRaw *)a;
    MvecRaw y = *(MvecRaw *)b;
    u_long128 r;
    asm volatile("paddw %0, %1, %2" : "=r"(r) : "r"(*(u_long128 *)&x), "r"(*(u_long128 *)&y));
    *dst = r;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/mvec", iosClampSW_AddMvec);
void iosClampSW_AddMvec(u_long128 *dst, u_long128 *a, u_long128 *b)
{
    MvecRaw x = *(MvecRaw *)a;
    MvecRaw y = *(MvecRaw *)b;
    u_long128 r;
    asm volatile("paddsw %0, %1, %2" : "=r"(r) : "r"(*(u_long128 *)&x), "r"(*(u_long128 *)&y));
    *dst = r;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/mvec", iosClampUW_AddMvec);
void iosClampUW_AddMvec(u_long128 *dst, u_long128 *a, u_long128 *b)
{
    MvecRaw x = *(MvecRaw *)a;
    MvecRaw y = *(MvecRaw *)b;
    u_long128 r;
    asm volatile("padduw %0, %1, %2" : "=r"(r) : "r"(*(u_long128 *)&x), "r"(*(u_long128 *)&y));
    *dst = r;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/mvec", iosSubMvec);
void iosSubMvec(u_long128 *dst, u_long128 *a, u_long128 *b)
{
    MvecRaw x = *(MvecRaw *)a;
    MvecRaw y = *(MvecRaw *)b;
    u_long128 r;
    asm volatile("psubw %0, %1, %2" : "=r"(r) : "r"(*(u_long128 *)&x), "r"(*(u_long128 *)&y));
    *dst = r;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/mvec", iosMulMvec);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/mvec", iosApplyM_Mat);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/mvec", iosCalcIcolorToBrightness);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/mvec", iosIColScale);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/mvec", iosIColAddVec);
void iosIColAddVec(u32 *dst, u32 a, u32 b)
{
    MvecU x;
    MvecU y;
    MvecU r;
    x.w[0] = a;
    y.w[0] = b;
    asm volatile("paddub %0, %1, %2" : "=r"(r.q) : "r"(x.q), "r"(y.q));
    *dst = r.w[0];
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/mvec", iosSwClip255Mvec);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/mvec", iosIColAddVecXYZ);
void iosIColAddVecXYZ(u32 *dst, u32 a, u32 b, u32 c, u32 d, u32 e)
{
    MvecU x;
    MvecU y;
    MvecU r;
    u32 t;
    x.w[0] = a;
    t = e & 0xFFFFFF00;
    t |= b & 0xFF;
    t &= 0xFFFF00FF;
    t |= (c & 0xFF) << 8;
    t &= 0xFF00FFFF;
    t |= (d & 0xFF) << 16;
    y.w[0] = t | 0xFF000000;
    asm volatile("paddub %0, %1, %2" : "=r"(r.q) : "r"(x.q), "r"(y.q));
    *dst = r.w[0];
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/mvec", iosUcharColClampAdd);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/mvec", iosSWToMmColMvec);
void iosSWToMmColMvec(u_long128 *dst, u_long128 *src)
{
    MvecRaw x = *(MvecRaw *)src;
    u_long128 r;
    asm volatile("psllw %0, %1, 23" : "=r"(r) : "r"(*(u_long128 *)&x));
    *dst = r;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/mvec", iosMmColToSWMvec);
void iosMmColToSWMvec(u_long128 *dst, u_long128 *src)
{
    MvecRaw x = *(MvecRaw *)src;
    u_long128 r;
    asm volatile("psrlw %0, %1, 23" : "=r"(r) : "r"(*(u_long128 *)&x));
    *dst = r;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/mvec", iosITOF15ToMmColMvec);
void iosITOF15ToMmColMvec(u_long128 *dst, u_long128 *src)
{
    MvecRaw x = *(MvecRaw *)src;
    u_long128 r;
    asm volatile("psllw %0, %1, 8" : "=r"(r) : "r"(*(u_long128 *)&x));
    *dst = r;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/mvec", iosMmColToITOF15Mvec);
void iosMmColToITOF15Mvec(u_long128 *dst, u_long128 *src)
{
    MvecRaw x = *(MvecRaw *)src;
    u_long128 r;
    asm volatile("psrlw %0, %1, 8" : "=r"(r) : "r"(*(u_long128 *)&x));
    *dst = r;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/mvec", iosFvecToMmColMvec);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/mvec", iosMmColToFvecMvec);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/mvec", iosSwClipMvec);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/mvec", iosFvecToICol);
void iosFvecToICol(u8 *dst, void *src)
{
    u32 t[4];
    iosFTOI0Vector(t, src);
    dst[0] = t[0];
    dst[1] = t[1];
    dst[2] = t[2];
    dst[3] = t[3];
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/mvec", iosIColToMvecSl);
void iosIColToMvecSl(u32 *dst, u32 c)
{
    dst[0] = c & 0xFF;
    dst[1] = (c >> 8) & 0xFF;
    dst[2] = (c >> 16) & 0xFF;
    dst[3] = c >> 24;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/mvec", iosIColToFvec);
void iosIColToFvec(void *dst, u32 c)
{
    u32 t[4];
    t[0] = c & 0xFF;
    t[1] = (c >> 8) & 0xFF;
    t[2] = (c >> 16) & 0xFF;
    t[3] = c >> 24;
    iosITOF0Vector(dst, t);
}
