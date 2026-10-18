#include "common.h"

signed char CheckClothChainExist(void *arg0)
{
    return (*(signed char *)((char *)(arg0) + 6));
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0161_CheckClothChainExist", ResetClothDynamics);

extern void CopyGeometryPointer(char *, int, int, int);

void SetClothSingleFixedChainLeafFixGeometryPointer(char *p, int a, int b, int c)
{
    char *g = p + 0x30;
    g[0x40] = 1;
    CopyGeometryPointer(g, a, b, c);
    g[0x41] = 0;
}

void SetClothSingleFixedChainLeafFixNodeOffset(void *arg0, signed char arg1)
{
    (*(signed char *)((char *)(arg0) + 0x71)) = arg1;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0161_CheckClothChainExist", getClothDynamics);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0161_CheckClothChainExist", clothmath_doubleTensionMove);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0161_CheckClothChainExist", create_particle_texture_and_get_id);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0161_CheckClothChainExist", add_particle_segment);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0161_CheckClothChainExist", func_400CBA98);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0161_CheckClothChainExist", init_particle_manager);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0161_CheckClothChainExist", doit_particle_manager);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0161_CheckClothChainExist", func_400CC058);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0161_CheckClothChainExist", func_400CC1E8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0161_CheckClothChainExist", func_400CC348);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0161_CheckClothChainExist", func_400CC510);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0161_CheckClothChainExist", func_400CC6E8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0161_CheckClothChainExist", func_400CC948);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0161_CheckClothChainExist", func_400CCC28);
