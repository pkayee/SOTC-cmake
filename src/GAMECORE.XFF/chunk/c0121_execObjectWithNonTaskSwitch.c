#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0121_execObjectWithNonTaskSwitch", execObjectWithNonTaskSwitch);

extern int isysGetThisSubThread();
extern int func_400A4778();

int scrRun(void)
{
    return func_400A4778(isysGetThisSubThread());
}

void scrRunM(int n)
{
    void *t = isysGetThisSubThread();
    int i;
    for (i = 0; i < n; i++)
        func_400A4778(t);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0121_execObjectWithNonTaskSwitch", SCRSetDispFlag);

extern void *GetScriptCharacterClass(void *);

void *GetSCRCharaAIWorkPtr(void *actor)
{
    void *script;

    script = GetScriptCharacterClass(actor);
    return *(void **)((char *)script + 0x1150);
}

int CheckSCRCharaAIWorkPtr(int arg0)
{
    int var_v0;

    var_v0 = 0;
    if (arg0 != 0) {
        var_v0 = (*(int *)((char *)(GetScriptCharacterClass((void *)arg0)) + 0x1150));
    }
    return var_v0;
}

extern void func_400A5440();
extern int D_40131BB4;

void SCRSimpleExecCharaGeometry(int arg0)
{
    D_40131BB4 = arg0;
    func_400A5440();
    D_40131BB4 = 0;
}

void scrInit(void) {
}

extern void ExecScriptLwsOrientClass(void *, void *, void *, float, float);
extern float ViewIntervalClip(void *, void *, float);
extern void *get_main_cameraman_camera_obj(void);
struct OrientationGlobalsView {
    char pad00[0x188];
    float interval;
    char pad18C[0x1E4];
    char context[0];
};
extern struct OrientationGlobalsView gcGlobalVar;

void __execScrLwsOri(void *actor)
{
    float interval;

    interval = ViewIntervalClip(actor, get_main_cameraman_camera_obj(),
                                gcGlobalVar.interval);
    ExecScriptLwsOrientClass(actor, get_main_cameraman_camera_obj(),
                            gcGlobalVar.context, interval, 1.0f / interval);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0121_execObjectWithNonTaskSwitch", func_400A5088);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0121_execObjectWithNonTaskSwitch", func_400A5148);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0121_execObjectWithNonTaskSwitch", func_400A5228);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0121_execObjectWithNonTaskSwitch", func_400A52E8);

extern void func_400A5398();
extern void isysSleepSubThread();

void st_motionsyncanimation(void)
{
    for (;;) {
        func_400A5398();
        isysSleepSubThread();
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0121_execObjectWithNonTaskSwitch", func_400A5398);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0121_execObjectWithNonTaskSwitch", func_400A5440);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0121_execObjectWithNonTaskSwitch", simpleExecCharaGeometry);

extern char D_40216E08[];
extern int isysAddGroupWithLinkParam();

int AddDefaultAIGroup(int a, int b, int c, int d)
{
    return isysAddGroupWithLinkParam(a, (int)D_40216E08, 0, 0);
}

extern char D_40135D48[];
extern char rootPtn[];
extern void isysInitGroup();
extern s32 gcCreateScriptObj();
void func_400A58C0();

s32 initdefaultaitask(void)
{
    isysInitGroup(D_40216E08);
    return gcCreateScriptObj(func_400A58C0, 0, rootPtn, 0x1000, 0, 4, D_40135D48);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0121_execObjectWithNonTaskSwitch", _initstage);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0121_execObjectWithNonTaskSwitch", initstage);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0121_execObjectWithNonTaskSwitch", func_400A58C0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0121_execObjectWithNonTaskSwitch", func_400A58E8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0121_execObjectWithNonTaskSwitch", func_400A5960);
