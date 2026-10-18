#include "common.h"

/* NEARMISS-STUB initPathTool */
#if 0 /* NEARMISS 98.82% cat=regalloc sub=- | lui/addiu register swap: gcc puts store address in v0 and -1 in v1, target has them reversed | attempts=1 */
extern u8 D_4001E428[];
extern s32 D_4002E080;
void func_40010EB8();
void createMenu(u8 *menu, s32 arg);

u8 *initPathTool(void)
{
    func_40010EB8();
    D_4002E080 = -1;
    createMenu(D_4001E428, 0);
    return D_4001E428 + 0x20;
}
#endif
INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0008_initPathTool", initPathTool);

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0008_initPathTool", chkISysPathObjForTool);
