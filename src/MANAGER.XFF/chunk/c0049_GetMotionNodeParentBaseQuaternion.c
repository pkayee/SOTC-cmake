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

extern s32 DldSysUndefSymbol;
extern u8 D_40131D40[];
void iosJumpRecoverPoint();

static inline u8 *dldElem(u32 *lp)
{
    u32 v = *lp;
    u32 off = v & 0x3FFFF;
    u8 *slot = off ? *(u8 **)((u8 *)lp - off) : NULL;

    if (slot != NULL && slot != (u8 *)DldSysUndefSymbol)
    {
        return *(u8 **)(slot + 0x10) + ((v >> 18) & 0xFFF) * *(s32 *)(*(u8 **)(slot + 8) + 0xC);
    }
    return NULL;
}

u8 *getAnimObjResource(u32 *lp)
{
    u8 *e = dldElem(lp);

    if (*(s32 *)(e + 0xC) == 0)
    {
        iosJumpRecoverPoint(D_40131D40, *(s32 *)e);
    }
    return *(u8 **)(*(u8 **)(e + 0xC) + 0x20);
}

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

/* NEARMISS-STUB getPosPQSAnimIntFrame */
#if 0 /* NEARMISS 75.53% cat=sched sub=- | branch layout solved (early returns, type!=0 / type!=2 nesting); left: the s16-dequant arm, target loads q[1]/q[2] and p[3]/p[5] after each out[] store (no hois | attempts=1 */
void getPosPQSAnimIntFrame(f32 *out, u8 *a, s32 idx)
{
    f32 *p = *(f32 **)(a + 4);
    u8 type = a[2];
    s16 *q;
    f32 *e;

    if (p == NULL)
    {
        return;
    }
    out[3] = 1.0f;
    if (type != 0)
    {
        if (type != 2)
        {
            e = p + idx * 3;
            out[0] = e[0];
            out[1] = e[1];
            out[2] = e[2];
            return;
        }
        q = *(s16 **)(p + 6) + idx * 3;
        out[0] = q[0] * p[1] * 3.051851e-05f + p[0];
        out[1] = q[1] * p[3] * 3.051851e-05f + p[2];
        out[2] = q[2] * p[5] * 3.051851e-05f + p[4];
        return;
    }
    out[0] = p[0];
    out[1] = p[1];
    out[2] = p[2];
}
#endif
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

s16 *GetAnimObjResource();

f32 GetDissolveAnimation(s32 obj, s32 frame)
{
    s16 *r = GetAnimObjResource(obj);
    f32 v = 0.0f;
    s32 n;

    if (r[0] >= 10 && *(u8 **)(r + 0x20) != NULL)
    {
        n = r[2] - 1;
        frame = frame - n * (frame / n);
        v = (*(u8 **)(r + 0x20))[frame] * 0.0039215684f;
    }
    return v;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0049_GetMotionNodeParentBaseQuaternion", GetMotionMatrixOfTargetFromRoot);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0049_GetMotionNodeParentBaseQuaternion", GetMotionMatrixOfTargetFromParent);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0049_GetMotionNodeParentBaseQuaternion", GetMotionMatrixOfChildsFromTarget);
