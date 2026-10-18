#include "common.h"

int modelNameByObj(void *arg0)
{
    return (*(int *)((char *)((*(void **)((char *)(arg0) + 0x20))) + 0x70));
}

int modelNameByHeader(void *arg0)
{
    return (*(int *)((char *)(arg0) + 0x70));
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0026_modelNameByObj", modelSetMatrixTransTag);

int modelGetTextureObjByIndex(void *arg0, int arg1)
{
    return (*(int *)((char *)(((arg1 << 5) + (*(int *)((char *)(arg0) + 0x40)))) + 0x10));
}

int modelGetTextureResourceByIndex(void *arg0, int arg1)
{
    return (*(int *)((char *)((*(void **)((char *)(((arg1 << 5) + (*(int *)((char *)(arg0) + 0x40)))) + 0x10))) + 0x20));
}

typedef struct
{
    unsigned long a : 9;
    unsigned int cnt : 15;
    unsigned long b : 40;
} LF;

void modelDeleteDispModelClass(char **p)
{
    ((LF *)(*(char **)(*p + 0x20) + 0x18))->cnt--;
}

int modelGetLinkCount(char *p)
{
    return ((LF *)(p + 0x18))->cnt;
}

void modelIncLinkCount(char *p)
{
    ((LF *)(p + 0x18))->cnt++;
}

void modelDecLinkCount(char *p)
{
    ((LF *)(p + 0x18))->cnt--;
}

int modelGetWorkSize(void *arg0)
{
    return ((*(int *)((char *)(arg0) + 0x64)) * 0x30) + ((*(int *)((char *)(arg0) + 0x54)) << 6) + 0xA1;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0026_modelNameByObj", modelInitialize);

int modelGetName(void *arg0)
{
    return (*(int *)((char *)(arg0) + 0x70));
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0026_modelNameByObj", modelSetSurface);

extern void *modelGetDlLayer(void *model, void *layer);

void *modelGetDlLayerIndex(char *model, int index)
{
    return modelGetDlLayer(model, *(char **)(model + 0x50) + index * 0x120);
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0026_modelNameByObj", modelSetEnviroment);

extern s32 D_4012A4FC;
extern s32 D_4012A4F8;
extern void func_40031988(void);
extern void *getSpecularity(void);
extern void func_40031AE8(float);

void modelSetEnviroment(void)
{
    s32 i;

    if (D_4012A4F8 != 0)
    {
        for (i = 0; i < D_4012A4FC; i++)
        {
            *(s32 *)(D_4012A4F8 + i * 4) = 0;
        }
    }
    func_40031988();
    func_40031AE8(*(float *)getSpecularity());
}

extern s32 rootPtn;
extern s32 D_4012A4FC;
extern s32 D_4012A4F8;
void *iosMallocAlign(void *, s32, s32);

void modelInit(s32 arg0)
{
    D_4012A4FC = arg0;
    D_4012A4F8 = (s32)iosMallocAlign(&rootPtn, arg0 << 2, 0x10);
}

int ModelDispGetWorkSize(void)
{
    return 0x2E3;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0026_modelNameByObj", func_40032540);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0026_modelNameByObj", func_40032788);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0026_modelNameByObj", ptclmanBuildMatPacket);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0026_modelNameByObj", ptclmanBuildVtxPacket);
