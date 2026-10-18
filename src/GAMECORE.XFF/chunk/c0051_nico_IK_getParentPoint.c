#include "common.h"

extern void GetGeometryPointerPosition(void *, int);
extern int GetLayoutClass(int);
extern u8 D_40202E00[];
extern s128 D_40202E10;
extern u128 ZeroPoint;

void nico_IK_getParentPoint(int *arg0)
{
    GetGeometryPointerPosition(D_40202E00, GetLayoutClass(*arg0) + 0xC0);
    D_40202E10 = ZeroPoint;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0051_nico_IK_getParentPoint", nico_IK_getAddSubPosition);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0051_nico_IK_getParentPoint", nico_IK_legAddSubPosition);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0051_nico_IK_getParentPoint", nico_IK_legGetUpper);

void nico_IK_leafSetWithMotion(void) {
}

extern void GetMotionMatrix(int, int, int, int, int, int);

void nico_IK_recomputeAll(int *p)
{
    GetMotionMatrix(p[2], p[3], p[4], p[1], p[45], p[46]);
}

extern int D_40202E80;

void nico_IK_idDetect(void *arg0)
{
    D_40202E80 = (*(int *)((char *)(arg0) + 0x14)) & 0xFFFEFFFF;
}

extern int GetMotionMatrixOfTargetFromRoot();

int nico_IK_TargetFromRoot(int *p)
{
    return GetMotionMatrixOfTargetFromRoot(p[2], p[3], p[4], p[1], p[0x2D], p[0x2E], p[5]);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0051_nico_IK_getParentPoint", nico_neckFitToParentInvDirIKBankReverse);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0051_nico_IK_getParentPoint", nico_IK_targetAiming);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0051_nico_IK_getParentPoint", func_4004F9A0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0051_nico_IK_getParentPoint", nico_IK_setTargetQFromSkeletonRestWithLimit);
