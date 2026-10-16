#include "common.h"

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/convert", iosFTOI15Vector);
void iosFTOI15Vector(void *dst, void *src)
{
    asm volatile("lqc2 $vf5, 0(%1); vftoi15.xyzw $vf6, $vf5; sqc2 $vf6, 0(%0)" : : "r"(dst), "r"(src));
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/convert", iosFTOI12Vector);
void iosFTOI12Vector(void *dst, void *src)
{
    asm volatile("lqc2 $vf5, 0(%1); vftoi12.xyzw $vf6, $vf5; sqc2 $vf6, 0(%0)" : : "r"(dst), "r"(src));
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/convert", iosFTOI4Vector);
void iosFTOI4Vector(void *dst, void *src)
{
    asm volatile("lqc2 $vf5, 0(%1); vftoi4.xyzw $vf6, $vf5; sqc2 $vf6, 0(%0)" : : "r"(dst), "r"(src));
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/convert", iosFTOI0Vector);
void iosFTOI0Vector(void *dst, void *src)
{
    asm volatile("lqc2 $vf5, 0(%1); vftoi0.xyzw $vf6, $vf5; sqc2 $vf6, 0(%0)" : : "r"(dst), "r"(src));
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/convert", iosITOF15Vector);
void iosITOF15Vector(void *dst, void *src)
{
    asm volatile("lqc2 $vf5, 0(%1); vitof15.xyzw $vf6, $vf5; sqc2 $vf6, 0(%0)" : : "r"(dst), "r"(src));
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/convert", iosITOF12Vector);
void iosITOF12Vector(void *dst, void *src)
{
    asm volatile("lqc2 $vf5, 0(%1); vitof12.xyzw $vf6, $vf5; sqc2 $vf6, 0(%0)" : : "r"(dst), "r"(src));
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/convert", iosITOF4Vector);
void iosITOF4Vector(void *dst, void *src)
{
    asm volatile("lqc2 $vf5, 0(%1); vitof4.xyzw $vf6, $vf5; sqc2 $vf6, 0(%0)" : : "r"(dst), "r"(src));
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/convert", iosITOF0Vector);
void iosITOF0Vector(void *dst, void *src)
{
    asm volatile("lqc2 $vf5, 0(%1); vitof0.xyzw $vf6, $vf5; sqc2 $vf6, 0(%0)" : : "r"(dst), "r"(src));
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/convert", iosGetStabXZVector);
void iosGetStabXZVector(void *dst, void *src)
{
    asm volatile(
        "lq $2, 0(%1);"
        "sq $2, 0(%0);"
        "sw $0, 4(%0);"
        "lqc2 $vf5, 0(%0);"
        "vmul.xyz $vf7, $vf5, $vf5;"
        "vmulax.w ACC, $vf0, $vf7x;"
        "vmadday.w ACC, $vf0, $vf7y;"
        "vmaddz.w $vf7, $vf0, $vf7z;"
        "vrsqrt Q, $vf0w, $vf7w;"
        "vwaitq;"
        "vmulq.xyz $vf5, $vf5, Q;"
        "sqc2 $vf5, 0(%0)"
        : : "r"(dst), "r"(src) : "$2", "memory");
}
