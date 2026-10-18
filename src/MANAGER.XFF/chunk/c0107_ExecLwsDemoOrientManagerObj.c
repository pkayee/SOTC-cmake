#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0107_ExecLwsDemoOrientManagerObj", ExecLwsDemoOrientManagerObj);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0107_ExecLwsDemoOrientManagerObj", InitLwsDemoOrientManagerObj);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0107_ExecLwsDemoOrientManagerObj", CreateLwsDemoOrientManagerObj);

void SetLwoDemoOrientManagerObjCutFinishFlag(void *arg0, int arg1)
{
    (*(int *)((char *)(arg0) + 0xB0)) = arg1;
}

extern int flushScriptObj();

int FlushLwsDemoOrientManagerObj(int a, int b, int c, int d)
{
    return flushScriptObj(a, b, c, d);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0107_ExecLwsDemoOrientManagerObj", func_4008E7F0);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0107_ExecLwsDemoOrientManagerObj", func_4008E880);
void isysFlushISYSLetterObj();

void func_4008E880(s32 arg0)
{
    flushScriptObj(arg0);
    isysFlushISYSLetterObj(arg0);
}

extern int GetScriptObjWorkSize();

int GetLwsDemoOrientManagerObjWorkSize(int a, int b, int c, int d)
{
    return GetScriptObjWorkSize(a, b, c, d);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0107_ExecLwsDemoOrientManagerObj", func_4008E8C0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0107_ExecLwsDemoOrientManagerObj", func_4008EE08);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0107_ExecLwsDemoOrientManagerObj", func_4008F040);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0107_ExecLwsDemoOrientManagerObj", func_4008F4A8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0107_ExecLwsDemoOrientManagerObj", func_4008F8E0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0107_ExecLwsDemoOrientManagerObj", func_4008FC78);
