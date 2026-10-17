#include "common.h"

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/vector", iosGetRandomVector);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/vector", iosGetDRandomVector);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/vector", iosGetRandomVector0);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/vector", iosAbsVector);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/vector", iosGetReflectVector);

void iosDumpFVector(void) {
}

void iosDumpIVector(void) {
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/vector", iosGetArbitraryUpVectorElement);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/vector", iosGetScaleInverseVector);
void iosGetScaleInverseVector(void *dst, void *src)
{
    f32 *d = dst;
    f32 *s = src;

    d[0] = 1.0f / s[0];
    d[1] = 1.0f / s[1];
    d[2] = 1.0f / s[2];
    d[3] = 1.0f / s[3];
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/vector", iosGetStabXYVector);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/vector", iosGetStabYZVector);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/vector", iosGetLengthPointToLine);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/vector", iosGetInverseVectorXYZ);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/vector", iosGetExceptAxisVector);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/vector", iosCalcFColorToBrightness);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/vector", iosITOF15VectorXYZ);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/vector", iosScaleColorTo255);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/vector", iosScaleColorToONE);
