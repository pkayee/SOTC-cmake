#include "common.h"
extern s32 gcGlobalVar;
void *isysGetThisSubThread();
void FlushCollisionWork();
u8 *GetLayoutClass();
void UpdateAliasLayoutObjClothGeometry();
void getClothGeometry(void *o, s32 a, f32 x, f32 y);
extern s32 D_40130F14;
extern s32 D_40130F18;
extern s32 D_40130F10;
void scrRun();
void isysRequestDeleteObj();
extern u128 ZeroPoint;
extern s32 IdentityQuaternion;
s32 func_40030800();
void SetGeometryPointerNodePosState();
extern u128 D_40200EF0;
extern u128 D_40200F00;
void ForceUnparentLayoutObj();
void DebugSetObjectGeometry();
void *get_main_cameraman();
void *get_game_camera();
void reset_game_camera();
extern u8 SH_StageDataDEFAULT[];
void sheetMgrLoadSegmentIndex();
void sheetMgrUnloadSegmentIndex();

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0026_gcCheckStageLoadFinish", gcCheckStageLoadFinish);
extern s32 D_40130F14;
extern s32 D_40130F18;
extern s32 D_40130F10;
s32 gcCheckStageLoadFinish(void)
{
    return D_40130F14 == -1;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0026_gcCheckStageLoadFinish", st_collisionalias);
extern s32 gcGlobalVar;
void *isysGetThisSubThread();
void FlushCollisionWork();
u8 *GetLayoutClass();
void UpdateAliasLayoutObjClothGeometry();
void getClothGeometry(void *o, s32 a, f32 x, f32 y);
void st_collisionalias(void)
{
    void *sub = isysGetThisSubThread();
    u8 *g = (u8 *)&gcGlobalVar;
    u8 *lay;

    for (;;) {
        FlushCollisionWork(sub);
        lay = GetLayoutClass(sub);
        if (*(s32 *)(lay + 0x124) != 0) {
            UpdateAliasLayoutObjClothGeometry(sub);
            getClothGeometry(sub, *(s32 *)(lay + 0x194), *(f32 *)(g + 0x180), *(f32 *)(g + 0x184));
        }
        scrRun();
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0026_gcCheckStageLoadFinish", func_40031628);
void scrRun();
void func_40031628(void)
{
    for (;;) {
        scrRun();
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0026_gcCheckStageLoadFinish", unloadObj);
void isysRequestDeleteObj();
void unloadObj(void *a0)
{
    isysRequestDeleteObj(a0);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0026_gcCheckStageLoadFinish", getStageLayoutGeometryPointer);
extern u128 ZeroPoint;
extern s32 IdentityQuaternion;
s32 func_40030800();
void SetGeometryPointerNodePosState();
void getStageLayoutGeometryPointer(void *a0)
{
    s32 v[4];
    s32 r = func_40030800(v);

    SetGeometryPointerNodePosState(a0, r, v[0], &IdentityQuaternion, &ZeroPoint);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0026_gcCheckStageLoadFinish", checkBoot);
s32 checkBoot(void)
{
    return D_40130F10;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0026_gcCheckStageLoadFinish", reloadStage);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0026_gcCheckStageLoadFinish", reloadStageWithPlayerPos);
extern u128 D_40200EF0;
extern u128 D_40200F00;
void reloadStageWithPlayerPos(s32 a0, s32 a1, u128 *a2, u128 *a3)
{
    if (a0 != 0) {
        D_40130F14 = a0;
        D_40130F18 = a1;
        D_40200EF0 = *a2;
        D_40200F00 = *a3;
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0026_gcCheckStageLoadFinish", forceMoveObjToPos);
void ForceUnparentLayoutObj();
void DebugSetObjectGeometry();
void *get_main_cameraman();
void *get_game_camera();
void reset_game_camera();
void forceMoveObjToPos(s32 a0, s32 a1, s32 a2)
{
    ForceUnparentLayoutObj(a0);
    DebugSetObjectGeometry(a0, a1, a2);
    reset_game_camera(get_game_camera(get_main_cameraman()));
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0026_gcCheckStageLoadFinish", languageMenuLoad);
extern u8 SH_StageDataDEFAULT[];
void sheetMgrLoadSegmentIndex();
void languageMenuLoad(void)
{
    s32 st;

    sheetMgrLoadSegmentIndex(SH_StageDataDEFAULT, 0x752, &st);
    while ((u32)(st - 0xDEAF) >= 2) {
        scrRun();
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0026_gcCheckStageLoadFinish", languageMenuUnload);
void sheetMgrUnloadSegmentIndex();
void languageMenuUnload(void)
{
    sheetMgrUnloadSegmentIndex(SH_StageDataDEFAULT, 0x752, 0);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0026_gcCheckStageLoadFinish", StartLwsDemoManager);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0026_gcCheckStageLoadFinish", func_400318D8);
void func_400318D8(void)
{
    for (;;) {
        scrRun();
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0026_gcCheckStageLoadFinish", func_400318F0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0026_gcCheckStageLoadFinish", st_opflow);
