#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0049_GetMotionNodeParentBaseQuaternion", GetMotionNodeParentBaseQuaternion);

extern void *GetCharacterClass(void *);

extern int GetCharacterClassMotionPhysicalNodeID(void *, int);

unsigned int GetMotionNodeExistNodeAnimationData(void *arg0, int arg1) {
    if ((arg1 > 0) && (arg1 & 0x10000)) {
        return (unsigned int) ~GetCharacterClassMotionPhysicalNodeID(GetCharacterClass(arg0), arg1 & 0xFFFEFFFF) >> 0x1F;
    }
    return 1U;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0049_GetMotionNodeParentBaseQuaternion", getAnimObjResource);

extern void GetMotionFloatFrameNoCaribration(void *, void *, int, float);

extern void func_4004EAC8(void *, void *, int, int);

void getMotionFloatFrameWithLimitCaribration(void *output, void *motion, int selector, float frame)
{
    short limit = *(short *)((char *)motion + 4);
    if ((float)limit <= frame) {
        func_4004EAC8(output, motion, limit, selector);
        return;
    }
    GetMotionFloatFrameNoCaribration(output, motion, selector, frame);
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0049_GetMotionNodeParentBaseQuaternion", getMotionFloatFrame);
void getMotionFloatFrame(void *output, void *motion, int selector, float frame)
{
    int idx = *(short *)((char *)motion + 4) - 1;
    float fidx = (float)idx;
    float orig = frame;
    frame = frame - (float)(idx * (int)(frame / fidx));
    if ((frame == 0.0f) && (0.0f < orig)) {
        frame = fidx;
    }
    GetMotionFloatFrameNoCaribration(output, motion, selector, frame);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0049_GetMotionNodeParentBaseQuaternion", GetMotionNS_RootInfo);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0049_GetMotionNodeParentBaseQuaternion", GetMotionNS_RootShiftInfo);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0049_GetMotionNodeParentBaseQuaternion", GetMotionNS_RootDirInfo);
extern void func_4004B970(float, void *, int, int, int);

void GetMotionNS_RootDirInfo(float frame, void *arg1, u8 *arg2, int arg3)
{
    int off = arg3 * 12;
    int idx = *(short *)(arg2 + 4) - 1;
    int i;
    frame = frame - (float)(idx * (int)(frame / (float)idx));
    i = (int)frame;
    func_4004B970(frame - (float)i, arg1, *(int *)(*(u8 **)(arg2 + 0x10) + off + 8), i, i + 1);
}

void DebugDumpMotion(void) {
}

int IsFullFixFormat(int arg0)
{
    return (arg0 & 0xFFFFFF) == 0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0049_GetMotionNodeParentBaseQuaternion", getPosPQSAnimIntFrame);

void func_40043588();

void getQuatPQSAnimIntFrame(void *a, unsigned char *b, void *c)
{
    int v = *(int *)(b + 8);
    int k = b[1];
    if (v != 0)
        func_40043588(a, k, v, c);
}

typedef struct { s8 b[3]; } MotionBoolInfo;
extern MotionBoolInfo D_4012A9F0;

void InitMotionBoolInfo(MotionBoolInfo *arg0)
{
    *arg0 = D_4012A9F0;
}

void SetMotionDynamicCallFunc(char *p, int a1, int a2)
{
    *(int *)(p + 0xE0) = a1;
    *(int *)(p + 0xE4) = a2;
}

int GetMotionResourceRotAngle(int kind)
{
    int angle = 0;

    switch (kind) {
    case 0:
        break;
    case 1:
    case 3:
        angle = 0x4000;
        break;
    case 2:
        angle = -0x4000;
        break;
    }
    return angle;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0049_GetMotionNodeParentBaseQuaternion", MultiGlobalQuaternionToRootSkeleton);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0049_GetMotionNodeParentBaseQuaternion", GetDissolveAnimation);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0049_GetMotionNodeParentBaseQuaternion", GetMotionMatrixOfTargetFromRoot);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0049_GetMotionNodeParentBaseQuaternion", GetMotionMatrixOfTargetFromParent);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0049_GetMotionNodeParentBaseQuaternion", GetMotionMatrixOfChildsFromTarget);
