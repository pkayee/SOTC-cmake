#include "common.h"

extern u8 D_40130F88[];

float getAreaSize(void)
{
    u8 *env = D_40130F88;

    return *(float *)(env + 0x40) * (float)*(s32 *)(env + 0x38);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0032_getAreaSize", getStageAreaID);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0032_getAreaSize", getStageAreaName);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0032_getAreaSize", getStageAreaNameUV);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0032_getAreaSize", SetSeamlessZFogDist);

extern s32 D_40130F5C;

s32 *getSeamlessStageHighModelDispDist(void)
{
    return &D_40130F5C;
}

extern s32 D_40130F60;

s32 *getSeamlessStageMiddleModelDispDist(void)
{
    return &D_40130F60;
}

extern s32 D_40130F6C;

s32 *getSeamlessStageHighModelDispDistDefault(void)
{
    return &D_40130F6C;
}

extern s32 D_40130F70;

s32 *getSeamlessStageMiddleModelDispDistDefault(void)
{
    return &D_40130F70;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0032_getAreaSize", getStageChipIDReal);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0032_getAreaSize", getStageChipIDWithOffset);

void getStageNormalizePosition(float *pos, float *outX, float *outZ)
{
    u8 *env = D_40130F88;

    *outX = (-pos[0] - *(float *)(env + 0x50)) / *(float *)(env + 0x40);
    *outZ = (-pos[2] - *(float *)(env + 0x54)) / *(float *)(env + 0x44);
}

extern u8 gcGlobalVar[];

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0032_getAreaSize", getCameraPosOnMap);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0032_getAreaSize", getSeamlessStageCenter);

u8 *getSeamlessStageEnv(void)
{
    return D_40130F88;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0032_getAreaSize", getStageLayout);

extern u8 *D_40130F90;

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0032_getAreaSize", getStageStat);

extern s32 D_40130F58;

s32 GetLoadAreaGroupData(void)
{
    return D_40130F58;
}

extern s32 rootPtn;
void *iosMallocAlign(void *, s32, s32);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0032_getAreaSize", CreateLoadAreaGroupData);

void iosFree(void *p);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0032_getAreaSize", DeleteLoadAreaGroupData);

extern s32 D_40130F74;

void forceLoadSeamlessStage(void)
{
    D_40130F74 = 1;
}

extern s32 D_40130FAC;

void SetSeamlessStageControlObject(s32 param_1)
{
    D_40130FAC = param_1;
}

void UpdateSeamlessStageLoad(void)
{
    u8 *env = D_40130F88;

    if (*(s32 *)(env + 0x8))
    {
        *(s32 *)env = 1;
    }
}

s32 func_40033BD0(void *node);
void func_40034A00(s32 a, s32 b, s32 c);
extern s32 D_4013101C;
extern u8 *D_40130F90;

void DeleteAllSeamlessStageObject(void)
{
    s32 *cur;

    if (D_40130F90 != NULL)
    {
        cur = (s32 *)D_4013101C;
        if (cur != NULL)
        {
            do
            {
                if (func_40033BD0(cur))
                {
                    func_40034A00(cur[2], cur[0], cur[1]);
                }
            } while (cur != NULL);
        }
    }
}

void iosFree(void *p);

void DeleteSeamlessStageLoad(void)
{
    u8 *env = D_40130F88;

    if (*(s32 *)(env + 0x8))
    {
        iosFree(*(void **)(env + 0x8));
        *(s32 *)(env + 0x8) = 0;
    }
}

s32 GetStageChipNum(void)
{
    u8 *env = D_40130F88;

    if (*(s32 *)(env + 0x8))
    {
        return *(s32 *)(env + 0x58);
    }
    return 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0032_getAreaSize", DeleteSeamlessStageObject);

extern u8 D_40130FF4[];

u8 *GetSeamlessStageObjectGroup(void)
{
    return D_40130FF4;
}

extern s32 D_40130F8C;

void PauseSeamlessStageManager(s32 param_1)
{
    D_40130F8C = param_1;
    if (param_1 == 0)
    {
        D_40130F74 = 1;
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0032_getAreaSize", UnloadAllSeamlessStageObject);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0032_getAreaSize", getChipNo);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0032_getAreaSize", getPosOnMap);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0032_getAreaSize", getStageIDWithOffset);

extern u8 *D_40130F90;

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0032_getAreaSize", getStageStatByChipNo);
