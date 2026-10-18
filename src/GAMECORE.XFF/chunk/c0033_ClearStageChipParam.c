#include "common.h"

typedef struct
{
    unsigned int lo : 4;
    unsigned int hi : 28;
} ChipFlags;

typedef struct
{
    int data[2];
    ChipFlags flags[2];
    char pad10[8];
} ChipRow;

typedef struct
{
    char pad0[8];
    int chips;
} StageMap;

extern StageMap D_40130F88;
extern void iosFree(int);

void ClearStageChipParam(int x, int y, int v)
{
    StageMap *m = &D_40130F88;

    if (((ChipRow *)m->chips)[x].data[y] != 0)
        iosFree(((ChipRow *)m->chips)[x].data[y]);
    ((ChipRow *)m->chips)[x].data[y] = 0;
    ((ChipRow *)m->chips)[x].flags[y].lo = v;
    ((ChipRow *)m->chips)[x].flags[y].hi = 0;
}

struct StageCoordinateView
{
    char pad00[0x40];
    float scale_x;
    float scale_z;
    char pad48[8];
    float offset_x;
    float offset_z;
};

void getStageChipIDFloat(const float *position, float *x, float *z)
{
    struct StageCoordinateView *view = (struct StageCoordinateView *)&D_40130F88;

    *x = (-position[0] - view->offset_x) / view->scale_x;
    *z = (-position[2] - view->offset_z) / view->scale_z;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0033_ClearStageChipParam", func_40039560);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0033_ClearStageChipParam", func_400395E8);

extern char D_40130FF4[];
extern int *isysGroupForFirst(void *, int);
extern int *isysGroupForNext(int *, int);
extern void isysGroupForExit(int, int);
extern int getModuleSize(int);

void seamlessstage_mallocerrorfunc(void)
{
    int m = 0;
    int *g;

    for (g = isysGroupForFirst(D_40130FF4, 0); g != 0; g = isysGroupForNext(g, 0))
    {
        m = *g;
        getModuleSize(m);
    }
    if (m != 0)
        isysGroupForExit(m, 0);
}

int isSeamlessStage(void)
{
    return *(int *)&D_40130F88;
}

typedef struct
{
    void *name;
    int a;
    void *b;
    char pad[0x30];
    int c;
    char pad2[0x20];
    void *disp;
    int pad3;
    void *clip;
    void *light;
    char pad4[0xC];
} Desc;

extern void *memset(void *, int, unsigned int);
extern unsigned char D_401330A0[];
extern int DispLayoutObjModel();
extern int ClipLayoutObjModel();
extern int CalcLightLayoutObj();
extern void *CreateLayoutObj(void *, int, Desc *);

void *initSeamlessStageObj(void *a, void *b)
{
    Desc d;
    unsigned char *name = D_401330A0;

    memset(&d, 0, 0x7C);
    d.name = name;
    d.b = b;
    d.a = 1;
    d.c = 6;
    d.disp = DispLayoutObjModel;
    d.clip = ClipLayoutObjModel;
    d.light = CalcLightLayoutObj;
    return CreateLayoutObj(a, 0, &d);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0033_ClearStageChipParam", unloadCdSeamlessStageFile);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0033_ClearStageChipParam", WaitUnloadSeamlessStageObject);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0033_ClearStageChipParam", func_400399A0);

typedef struct
{
    int request;
    int b;
    void *buf;
} SeamlessLoad;

void RestartSeamlessStage(void)
{
    SeamlessLoad *s = (SeamlessLoad *)&D_40130F88;

    if (s->buf != 0)
    {
        s->request = 1;
    }
}

extern void InitSeamlessStageLoad();

void initStageAlignParam(void)
{
    InitSeamlessStageLoad();
}

extern int func_40033BD0(void *);
extern void func_40034A00(int, int, int);
extern int D_40130F90;
extern void *D_4013101C;

void deleteStageAlignParam(void)
{
    void *temp_s0;

    if (D_40130F90 != 0)
    {
        temp_s0 = D_4013101C;
        if (temp_s0 != NULL)
        {
            do
            {
                if (func_40033BD0(temp_s0) != 0)
                    func_40034A00(*(int *)((char *)temp_s0 + 8), *(int *)((char *)temp_s0 + 0), *(int *)((char *)temp_s0 + 4));
            } while (temp_s0 != NULL);
        }
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0033_ClearStageChipParam", func_40039AD0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0033_ClearStageChipParam", initSlowObject);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0033_ClearStageChipParam", deleteSlowObject);

extern void isysInitGroup(void *);
extern unsigned char D_40200F30[];
extern int D_40131058;

void initSlowManager(void)
{
    if (D_40131058 == 0) {
        isysInitGroup(D_40200F30);
        D_40131058 = 1;
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0033_ClearStageChipParam", createSpecialEffectObj);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0033_ClearStageChipParam", updateSpecialEffectManager);
