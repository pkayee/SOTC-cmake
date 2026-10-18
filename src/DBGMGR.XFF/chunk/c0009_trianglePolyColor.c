#include "common.h"

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0009_trianglePolyColor", trianglePolyColor);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0009_trianglePolyColor", triangleDisp);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0009_trianglePolyColor", DebugDispRadiusIndicator);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0009_trianglePolyColor", DebugDispRadiusIndicatorNoLayer);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0009_trianglePolyColor", DebugDispTriangle);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0009_trianglePolyColor", DebugDispVectorTriangle);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0009_trianglePolyColor", DebugDispWideLineHalf);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0009_trianglePolyColor", DebugDispWideLineNotBlend);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0009_trianglePolyColor", DebugDispArrowNoLayer);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0009_trianglePolyColor", DebugDispBox);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0009_trianglePolyColor", DebugDispDocileArrow);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0009_trianglePolyColor", DebugDispSelectDrawType);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0009_trianglePolyColor", DebugDispLine);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0009_trianglePolyColor", DebugDispSmoothLine);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0009_trianglePolyColor", DebugDispOctagon);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0009_trianglePolyColor", DebugDetailsDispBox);

void func_40019C18(void *arg0, void *arg1, s32 arg2);

//INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0009_trianglePolyColor", DebugDispGeometryPointer);
void DebugDispGeometryPointer(void *arg0, void *arg1)
{
    func_40019C18(arg0, arg1, 0);
}

//INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0009_trianglePolyColor", DebugDispGeometryPointerForce);
void DebugDispGeometryPointerForce(void *arg0, void *arg1)
{
    func_40019C18(arg0, arg1, 1);
}

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0009_trianglePolyColor", DebugDispArrowHalfVU1);

extern int func_40017C10();

//INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0009_trianglePolyColor", DebugDispArrowHalfNoFrameVU1);
int DebugDispArrowHalfNoFrameVU1(int a, int b, int c)
{
    return func_40017C10(a, b, c, 0, 1);
}

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0009_trianglePolyColor", DebugDispArrowNotBlendVU1);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0009_trianglePolyColor", DebugDispArrowNotBlendNoFrameVU1);

//INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0009_trianglePolyColor", DebugDispWideLineHalfVU1);

extern int func_40017F00();

int DebugDispWideLineHalfVU1(int a, int b, int c)
{
    return func_40017F00(a, b, c, 1);
}

//INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0009_trianglePolyColor", DebugDispWideLineNotBlendVU1);
int DebugDispWideLineNotBlendVU1(int a, int b, int c)
{
    return func_40017F00(a, b, c, 0);
}

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0009_trianglePolyColor", DebugSetTurnFront);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0009_trianglePolyColor", DebugDispRadiusIndicatorVU1);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0009_trianglePolyColor", DebugDispTriangularPyramidHalfVU1);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0009_trianglePolyColor", DebugDispTriangularPyramidNotBlendVU1);
