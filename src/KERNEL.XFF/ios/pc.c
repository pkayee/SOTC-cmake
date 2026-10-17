#include "common.h"

void iosInitDebPc(void) {
}

void iosStopPc(void) {
}

void iosDebPcVsyncCounterCheck(void) {
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/pc", iosGetCnt0Pc);
u64 iosGetCnt0Pc(void)
{
    return 0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/pc", iosGetCnt1Pc);
u64 iosGetCnt1Pc(void)
{
    return 0;
}

void InitDebPc(void) {
}
