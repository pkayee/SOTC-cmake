#include "common.h"

extern u8 D_4001E428[];
extern s32 D_4002E080;
void func_40010EB8();
void createMenu(u8 *menu, s32 arg);

u8 *initPathTool(void)
{
    u8 *m = D_4001E428;
    func_40010EB8();
    D_4002E080 = -1;
    createMenu(m, 0);
    return m + 0x20;
}

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0008_initPathTool", chkISysPathObjForTool);
