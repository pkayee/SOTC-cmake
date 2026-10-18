#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0211_updateGazeCtrlWork", updateGazeCtrlWork);

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    f32 scale;
    s32 unk14;
    u8 pad18[0x18];
    s32 unk30;
    u8 link[0xC];
    s32 linked;
} GazeCtrlWork;

void InitTwoWayLink();
void DeleteTwoWayLink();

void initGazeCtrlWork(GazeCtrlWork *w)
{
    InitTwoWayLink(w->link, &w->linked);
    w->linked = 0;
    w->unk4 = 1;
    w->unk0 = 0;
    w->unk8 = 0;
    w->unk14 = 0;
    if (w->linked != 0) {
        w->linked = 0;
        DeleteTwoWayLink(w->link);
    }
    w->unk30 = 0;
    w->unkC = 0;
    w->scale = 1.0f;
}

void deleteGazeCtrlWork(char *p)
{
    if (*(int *)(p + 0x40) != 0) {
        *(int *)(p + 0x40) = 0;
        DeleteTwoWayLink(p + 0x34);
    }
}

void setExecGazeCtrlWork(int *arg0, int arg1)
{
    *arg0 = arg1;
}

void setViewJudgeGazeCtrlWork(void *arg0, int arg1)
{
    (*(int *)((char *)(arg0) + 4)) = arg1;
}

void setNextDistGazeCtrlWork(void *arg0, float fparg0)
{
    (*(float *)((char *)(arg0) + 8)) = fparg0;
}

void setValidPosGazeCtrlWork(void *arg0, int arg1)
{
    (*(int *)((char *)(arg0) + 0x14)) = arg1;
}

typedef int s128 __attribute__((mode(TI)));

void setPosGazeCtrlWork(char *p, s128 *v)
{
    *(s128 *)(p + 0x20) = *v;
    *(int *)(p + 0x30) = 0;
}

int AddTwoWayLinkNext();
void *GetLayoutClass();

void setObjGazeCtrlWork(void *arg0, void *arg1)
{
    if ((*(int *)((char *)(arg0) + 0x40)) != 0) {
        (*(int *)((char *)(arg0) + 0x40)) = 0;
        DeleteTwoWayLink(arg0 + 0x34);
    }
    (*(void **)((char *)(arg0) + 0x30)) = arg1;
    if (arg1 != NULL) {
        AddTwoWayLinkNext(GetLayoutClass(arg1) + 0x118, arg0 + 0x34);
        (*(int *)((char *)(arg0) + 0x40)) = 1;
    }
}

void setBirdModeGazeCtrlWork(void *arg0, int arg1)
{
    (*(int *)((char *)(arg0) + 0xC)) = arg1;
}

void setGazeCoffGazeCtrlWork(void *arg0, float fparg0)
{
    (*(float *)((char *)(arg0) + 0x10)) = fparg0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0211_updateGazeCtrlWork", initGazeTool);

extern s32 D_40132400;
extern char D_4021E1C0[];
void glColor4f(f32 r, f32 g, f32 b, f32 a);
void DebugDispRadiusIndicator(void *obj, f32 radius, s32 flag);

void drawGazeTool(void)
{
    if (D_40132400 != 0) {
        glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
        DebugDispRadiusIndicator(D_4021E1C0, 0.5f, 5);
    }
}

s32 chkGazeTool(void)
{
    return D_40132400;
}

void getGazeToolPos(s128 *out)
{
    *out = *(s128 *)D_4021E1C0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0211_updateGazeCtrlWork", func_4010F360);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0211_updateGazeCtrlWork", func_4010F3A0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0211_updateGazeCtrlWork", createHorseCtrlWork);
