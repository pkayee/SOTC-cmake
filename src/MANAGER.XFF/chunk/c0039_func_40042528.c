#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0039_func_40042528", func_40042528);

extern unsigned char D_4012A96C[];

void *getTexTransEnableFlag(void)
{
    return D_4012A96C;
}

extern int D_4012A970;

void texSetModelName(int arg0)
{
    D_4012A970 = arg0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0039_func_40042528", func_40042590);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0039_func_40042528", func_40042708);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0039_func_40042528", func_40042860);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0039_func_40042528", func_40042B08);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0039_func_40042528", vramAlloc);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0039_func_40042528", vramCreateBlock);

extern int iosFree();

int vramDeleteBlock(int a, int b, int c, int d)
{
    return iosFree(a, b, c, d);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0039_func_40042528", vramFree);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0039_func_40042528", vramReset);

extern int D_4012A980;

void vramEnd(void)
{
    iosFree(D_4012A980);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0039_func_40042528", vramInit);

extern void func_40042708();

void vramAllocByTBPSize(void)
{
    func_40042708();
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0039_func_40042528", zFog);
