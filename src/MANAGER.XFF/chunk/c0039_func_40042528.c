#include "common.h"

extern int D_4012A6A4;

void func_40042528(void)
{
    int iVar1;
    int iVar2;

    iVar2 = D_4012A6A4;
    if (iVar2 != 0)
    {
        iVar1 = *(int *)(iVar2 + 4);
        while (1)
        {
            if (*(int *)(iVar1 + 0x24) == 0)
            {
                iVar2 = *(int *)(iVar2 + 0xc);
            }
            else
            {
                *(int *)(iVar1 + 0x14) = 0;
                *(int *)(iVar1 + 0x10) = 0;
                *(int *)(iVar1 + 0x1c) = 0;
                *(int *)(iVar1 + 0x18) = 0;
                iVar2 = *(int *)(iVar2 + 0xc);
            }
            if (iVar2 == 0)
            {
                break;
            }
            iVar1 = *(int *)(iVar2 + 4);
        }
    }
    return;
}

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

/* NEARMISS-STUB vramFree */
#if 0 /* NEARMISS 88.75% cat=branch-layout sub=- | gcc picks bnel/bnezl branch-likely with ld ra in delay slot; target uses plain bne and nop delay | attempts=1 */
extern void func_40042860();

void vramFree(void *param_1)
{
    if (*(s32 *)((u8 *)param_1 + 8) == 2 && (*(u32 *)((u8 *)param_1 + 0xc) & 1) == 0)
    {
        func_40042860(param_1);
    }
    return;
}
#endif
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
