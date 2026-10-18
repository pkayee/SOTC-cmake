#include "common.h"
#include "gcc/stdarg.h"

extern int vsprintf(char *, const char *, va_list);
extern void kprintfContextCentering();

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0001_func_40018018", func_40018018);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0001_func_40018018", DebugGetGlobalDiffWith2ndController);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0001_func_40018018", DebugGlobalMoveWith1stController);

void DebugPrintf3D_Context(void *ctx, const char *fmt, ...)
{
    char buf[0x100];
    va_list ap;

    va_start(ap, fmt);
    vsprintf(buf, fmt, ap);
    kprintfContextCentering(ctx, buf);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0001_func_40018018", DebugPrintf3D);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0001_func_40018018", disphalfarc);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0001_func_40018018", disphalfarcpillar);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0001_func_40018018", func_400190B8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0001_func_40018018", func_400195E8);
