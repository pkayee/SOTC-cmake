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

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/mvec", iosAddMvec);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/mvec", iosClampSW_AddMvec);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/mvec", iosClampUW_AddMvec);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/mvec", iosSubMvec);

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

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/mvec", iosSwClip255Mvec);
void iosSwClip255Mvec(u_long128 *dst)
{
    register u_long128 r asm("$2");
    asm volatile(
        "pceqw $8, $0, $0;"
        "psrlw $9, $8, 23;"
        "psrlw $11, $8, 1;"
        "psubsw $9, $11, $9;"
        "paddsw $2, $2, $9;"
        "psrlw $10, $8, 31;"
        "psubsw $2, $2, $9;"
        "paddw $10, $11, $10;"
        "paddsw $2, $2, $10;"
        "psubsw $2, $2, $10"
        : "+r"(r) : : "$8", "$9", "$10", "$11");
    *dst = r;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/mvec", iosIColAddVecXYZ);

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

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/mvec", iosFvecToICol);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/mvec", iosIColToMvecSl);
void iosIColToMvecSl(u32 *dst, u32 c)
{
    dst[0] = c & 0xFF;
    dst[1] = (c >> 8) & 0xFF;
    dst[2] = (c >> 16) & 0xFF;
    dst[3] = c >> 24;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/mvec", iosIColToFvec);
