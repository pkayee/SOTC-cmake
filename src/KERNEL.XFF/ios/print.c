#include "common.h"
#include <stdarg.h>

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/print", iosSPrintf);
s32 iosSPrintf(char *buf, char *fmt, ...)
{
    va_list args;
    s32 ret;

    va_start(args, fmt);
    ret = vsprintf(buf, fmt, args);
    va_end(args);
    return ret;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/print", iosUsbSerialPrintf);
s32 iosUsbSerialPrintf(char *fmt, ...)
{
    char buf[0x100];
    va_list args;

    va_start(args, fmt);
    vsprintf(buf, fmt, args);
    va_end(args);
    return usbSerialSysPutString(buf);
}

void iosCreatePrintMgr(void) {
}

extern s32 D_40045810;

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/print", iosGetPrintfMode);
s32 *iosGetPrintfMode(void)
{
    return &D_40045810;
}
