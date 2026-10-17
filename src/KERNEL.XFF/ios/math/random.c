#include "common.h"

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/random", iosInitRandom);
void iosInitRandom(f32 seed)
{
    asm volatile(
        "mfc1 $6, $f12\n"
        "qmtc2.ni $6, $vf5\n"
        "vaddw.x $vf6, $vf5, $vf0w\n"
        "vadd.x $vf5, $vf5, $vf5\n"
        "vrinit R, $vf5x\n"
        "vrxor R, $vf6x\n"
        :
        :
        : "$6");
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/random", iosGetRandom);
f32 iosGetRandom(void)
{
    register f32 ret asm("$f0");

    asm volatile(
        "vrnext.x $vf5, R\n"
        "vrnext.x $vf5, R\n"
        "vrnext.x $vf5, R\n"
        "vrnext.x $vf5, R\n"
        "vrnext.x $vf5, R\n"
        "vrnext.x $vf5, R\n"
        "vrnext.x $vf5, R\n"
        "vrinit R, $vf5x\n"
        "vrnext.x $vf5, R\n"
        "vrnext.x $vf5, R\n"
        "vrnext.x $vf5, R\n"
        "vrnext.x $vf5, R\n"
        "vrnext.x $vf5, R\n"
        "vrnext.x $vf5, R\n"
        "vrnext.x $vf5, R\n"
        "vsubw.x $vf5, $vf5, $vf0w\n"
        "qmfc2.ni $7, $vf5\n"
        "mtc1 $7, $f0\n"
        : "=f"(ret)
        :
        : "$7");
    return ret;
}
