#include "common.h"

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0023_lineObjectDelete", lineObjectDelete);

extern int isysRequestDeleteObj();

int lineObjectDelete(int a, int b, int c, int d)
{
    return isysRequestDeleteObj(a, b, c, d);
}

extern int (*D_4012A490[])(int);
extern int D_401ABD50[];
extern char D_401ABDB8[];
extern void isysInitGroup(void *);

void lineObjectInit(void)
{
    int i;

    for (i = 0; i < 26; i++) {
        if (D_4012A490[i] != 0)
            D_401ABD50[i] = D_4012A490[i](i & 1);
    }
    isysInitGroup(D_401ABDB8);
}

void func_4002F5D8(void) {
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0023_lineObjectDelete", func_4002F5E0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0023_lineObjectDelete", modelCreatePacketTransPacket);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0023_lineObjectDelete", modelGetDlLayer);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0023_lineObjectDelete", modelInitDispModelClass);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0023_lineObjectDelete", modelReInitialize);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0023_lineObjectDelete", func_40030130);
