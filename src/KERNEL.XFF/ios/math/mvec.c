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

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/mvec", iosMvecZero);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/mvec", iosMvecAllOnes);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/mvec", iosMvecAllOne);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/mvec", iosAddMvec);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/mvec", iosClampSW_AddMvec);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/mvec", iosClampUW_AddMvec);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/mvec", iosSubMvec);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/mvec", iosMulMvec);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/mvec", iosApplyM_Mat);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/mvec", iosCalcIcolorToBrightness);
extern const MvecRaw D_40047550;
void iosMulMvec(u_long128 *, u_long128 *, u_long128 *);

u32 iosCalcIcolorToBrightness(u32 c)
{
    MvecU x;
    MvecRaw y;
    s32 sum;
    x.w[0] = c & 0xFF;
    x.w[1] = (c >> 8) & 0xFF;
    x.w[2] = (c >> 16) & 0xFF;
    x.w[3] = c >> 24;
    y = D_40047550;
    iosMulMvec(&x.q, &x.q, (u_long128 *)&y);
    sum = x.w[0] + x.w[1] + x.w[2];
    return (sum >> 23) & 0xFF;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/mvec", iosIColScale);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/mvec", iosIColAddVec);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/mvec", iosSwClip255Mvec);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/mvec", iosIColAddVecXYZ);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/mvec", iosUcharColClampAdd);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/mvec", iosSWToMmColMvec);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/mvec", iosMmColToSWMvec);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/mvec", iosITOF15ToMmColMvec);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/mvec", iosMmColToITOF15Mvec);

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
