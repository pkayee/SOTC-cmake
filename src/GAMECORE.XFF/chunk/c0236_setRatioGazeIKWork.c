#include "common.h"

void setRatioGazeIKWork(void *actor, float x, float y, float z)
{
    void *work = *(void **)((char *)actor + 0x1064);

    if (work != 0)
    {
        if (*(float *)((char *)work + 0x34) != x ||
            *(float *)((char *)work + 0x38) != y ||
            *(float *)((char *)work + 0x3C) != z)
        {
            *(float *)((char *)work + 0x70) = 1.0f;
        }
        *(float *)((char *)work + 0x34) = x;
        *(float *)((char *)work + 0x38) = y;
        *(float *)((char *)work + 0x3C) = z;
    }
}

void setGoingAngleGazeIKWork(char *p, float a)
{
    char *w = *(char **)(p + 0x1064);

    if (w != 0)
    {
        *(float *)(w + 0x40) = a;
    }
}

void setGazeDirGazeIKWork(char *p, s128 *v)
{
    char *w = *(char **)(p + 0x1064);

    if (w != 0)
    {
        *(s128 *)(w + 0x50) = *v;
    }
}

void setSubParamGazeIKWork(char *p, int a)
{
    char *w = *(char **)(p + 0x1064);

    if (w != 0)
    {
        *(int *)(w + 0xBC) = a;
    }
}

void setGazeModeGazeIKWork(char *p, int a)
{
    char *w = *(char **)(p + 0x1064);

    if (w != 0)
    {
        *(int *)(w + 0x60) = a;
    }
}

void setExecRootQuatGazeIKWork(char *p, int a)
{
    char *w = *(char **)(p + 0x1064);

    if (w != 0) {
        *(int *)(w + 0xB0) = a;
    }
}

void setExecGazeIKWork(char *p, int a)
{
    char *w = *(char **)(p + 0x1064);

    if (w != 0)
    {
        *(int *)(w + 0x30) = a;
    }
}

void updateGazeIKWork(char *w, s128 *target)
{
    s128 *gaze = *(s128 **)(w + 0x1064);

    if (gaze) {
        *gaze = *target;
        ((float *)gaze)[3] = 1.0f;
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0236_setRatioGazeIKWork", func_4012CC60);
u32 func_4012CC60(s32 n, u8 *p)
{
    s32 i;
    u32 v = *(u32 *)(p + 0x14);

    for (i = 0; i != n; i++)
    {
        if ((s32)v < 0)
        {
            return 0xFFFFFFFE;
        }
        if ((s32)v > 0 && (v & 0x10000))
        {
            v = *(u32 *)((v & 0xFFFEFFFF) * 0x40 + *(u32 *)(*(u32 *)(p + 0x10) + 0x24) + 0x30);
        }
        else
        {
            v = *(u32 *)(v * 0x40 + *(u32 *)(*(u32 *)(p + 0x10) + 8) + 0x38);
        }
    }
    return v;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0236_setRatioGazeIKWork", func_4012CCE0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0236_setRatioGazeIKWork", nico_calcTailGenealogicalNodeHead);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0236_setRatioGazeIKWork", nico_calcTailGenealogicalNodeNext);

int getSizeTailIKWork(void)
{
    return 0x3D0;
}

void initTailIKWork(int a, int b, char *p)
{
    *(int *)(p + 0x3C0) = 0;
    *(int *)(p + 0x3C8) = 0;
    *(int *)(p + 0x3C4) = 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0236_setRatioGazeIKWork", nico_calcTailGenealogicalNodeTail);

typedef union { u128 q; f32 f[4]; } RIKVec;
extern RIKVec ZeroVector;

void ReflectIK_initWormDynamics(void *dst, RIKVec *a, RIKVec *b, RIKVec *c, float f)
{
    RIKVec *d = (RIKVec *)dst;

    d[1].q = a->q;
    d[2].q = ZeroVector.q;
    d[0].q = b->q;
    d[3].q = c->q;
    *(float *)((u8 *)dst + 0x40) = f;
}
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0236_setRatioGazeIKWork", func_4012D738);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0236_setRatioGazeIKWork", func_4012DA20);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0236_setRatioGazeIKWork", func_4012DBE0);
