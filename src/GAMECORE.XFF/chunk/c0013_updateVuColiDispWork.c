#include "common.h"

/* NEARMISS-STUB updateVuColiDispWork */
#if 0 /* NEARMISS 88.07692% cat=vu0-mmi sub=- | sqc2 $vf0 store of (0,0,0,1) in else-branch has no C form (compiler emits sw x4 + lui); lq/sq copy ok; GetCollisionDB arg0 reloc is D_401FC4C8 in target vs D_40 | attempts=1 */
extern s32 D_401FC4D8;
extern s32 D_401FC4C0[];
s32 get_main_cameraman();
s32 get_cur_camera_target(s32 a0);
s32 GetLayoutClass(s32 a0);
void glColor4f(f32 r, f32 g, f32 b, f32 a);
void DebugDispRadiusIndicator(f32 r, u128 *pos, s32 n);
void GetCollisionDB(f32 r, s32 *w, s32 idx, s32 a3, u128 *p, u128 *q);

void updateVuColiDispWork(void)
{
    s32 cam;
    u8 *lc;
    s32 vec[4];

    cam = get_main_cameraman();
    if (D_401FC4D8 != 0)
    {
        if (get_cur_camera_target(cam) != 0)
        {
            lc = (u8 *)GetLayoutClass(get_cur_camera_target(cam));
            *(u128 *)vec = *(u128 *)*(u32 **)(lc + 0x134);
        }
        else
        {
            vec[0] = 0;
            vec[1] = 0;
            vec[2] = 0;
            vec[3] = 0x3f800000;
        }
        glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
        DebugDispRadiusIndicator(10.0f, (u128 *)vec, 5);
        GetCollisionDB(10.0f, D_401FC4C0 + 2, D_401FC4C0[0] + D_401FC4C0[1] * 4, 0, (u128 *)vec, (u128 *)vec);
    }
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0013_updateVuColiDispWork", updateVuColiDispWork);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0013_updateVuColiDispWork", dispVuColiDispWork);

extern s32 rootPtn;
extern s32 D_401FC4C0[];
s32 InitCollisionFinder();
s32 initVuColiDispWork(s32 a0)
{
    s32 *w = D_401FC4C0;

    w[0] = a0;
    w[1] = 2;
    w[6] = 0;
    return InitCollisionFinder(w + 2, &rootPtn, 0x400);
}

extern s32 activedemoInfo[];
void activedemoflowDemoEnd(void)
{
    activedemoInfo[0] |= 2;
}

extern s32 D_40130B3C;
s32 getActivedemoStage(void)
{
    return D_40130B3C;
}

s32 chkActiveDemoStart(void)
{
    return activedemoInfo[0] & 1;
}

void *isysGetThisSubThread(void);
void scrInit(void *thread);
void gameModeSet(u32 mode);
void gameModeCls(u32 mode);
void PauseCamFinalizer(s32 a0);
void scrRun(void);
void setDefaultFsEffect(void);
s32 get_main_cameraman();
void *get_game_camera();
void end_stream_lws_movie_playing_game_camera(void *a0);
void activeDemoCancel(s32 a0);

void st_activedemoflow(void)
{
    scrInit(isysGetThisSubThread());
    gameModeSet(1);
    PauseCamFinalizer(1);
    while ((((u32)activedemoInfo[0] >> 3) & 1) == 0)
    {
        scrRun();
    }
    activedemoInfo[0] |= 1;
    if ((((u32)activedemoInfo[0] >> 1) & 1) == 0)
    {
        do
        {
            scrRun();
        } while ((((u32)activedemoInfo[0] >> 1) & 1) == 0);
    }
    activeDemoCancel(activedemoInfo[1]);
    setDefaultFsEffect();
    end_stream_lws_movie_playing_game_camera(get_game_camera(get_main_cameraman()));
    PauseCamFinalizer(0);
    gameModeCls(1);
}

void activeDemoAbort(void)
{
    if (activedemoInfo[2] != 0) {
        activeDemoCancel(activedemoInfo[1]);
    }
}

s32 createScriptObj();
void func_400248C8();
void activeDemoStandby(s32 a0)
{
    s32 *w = activedemoInfo;

    if (w[2] == 0) {
        w[1] = a0;
        w[2] = createScriptObj(func_400248C8, 0, &rootPtn, 0x1000, 0, 1, 0, 0);
    }
    w[0] &= ~4;
}

void activeDemoCancel(s32 a0)
{
    if (activedemoInfo[2] != 0 && activedemoInfo[1] == a0) {
        activedemoInfo[0] |= 4;
    }
}

extern s32 ScrIntrDef_START_ACTIVE_DEMO;
void scriptIntrSignal();
void activeDemoStart(s32 a0)
{
    s32 *w = activedemoInfo;

    if (w[2] == 0) {
        w[1] = a0;
        w[2] = createScriptObj(func_400248C8, 0, &rootPtn, 0x1000, 0, 1, 0, 0);
    }
    w[0] &= ~4;
    scriptIntrSignal(ScrIntrDef_START_ACTIVE_DEMO);
}

/* NEARMISS-STUB func_400248C8 */
#if 0 /* NEARMISS 64.69% cat=branch-layout sub=- | loop/branch shape: target keeps w[0] in reg across for-update (daddu v1,v0) and exits bit3 via bnel to bit2 test; ours reloads w and emits beqz/bnez; constants  | attempts=1 */
s32 gcGetStageData(s32 a0);
s32 GetStageAreaNumber(void);
void stagemanager_loadstagecore(void *p, s32 a1, s32 a2, s32 a3);
void stagemanager_unloadstagecore(s32 a0);
void scrRun(void);
void *memset(void *d, s32 c, u32 n);

void *func_400248C8(void)
{
    s32 *w = activedemoInfo;
    s32 d;
    s32 area;
    s32 stage;

    do
    {
        while (1)
        {
            for (; ((u32)w[0] >> 3 & 1) == 0; w[0] |= 8)
            {
                d = w[1] - gcGetStageData(0);
                area = GetStageAreaNumber();
                stagemanager_loadstagecore(&rootPtn, (d >> 2) * -0x33333333, area, 0);
            }
            if (((u32)w[0] >> 2 & 1) != 0)
            {
                break;
            }
            scrRun();
        }
        stage = gcGetStageData(0);
        d = (w[1] - stage >> 2) * -0x33333333;
        w[0] &= 0xfffffff7;
        stagemanager_unloadstagecore(d);
    } while (((u32)w[0] >> 2 & 1) == 0);
    return memset(w, 0, 0xc);
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0013_updateVuColiDispWork", func_400248C8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0013_updateVuColiDispWork", backStageGobjSave);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0013_updateVuColiDispWork", backStageGobjSaveWithPos);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0013_updateVuColiDispWork", backStageGobjCheckEntry);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0013_updateVuColiDispWork", backStageGobjLoad);

extern int DldSysUndefSymbol;
extern int _gameFlagChk(int);

static inline char *dldResolve(unsigned int *h)
{
    unsigned int v = *h;
    int off = v & 0x3FFFF;
    char *t = off != 0 ? *(char **)((char *)h - off) : 0;

    return (t != 0 && t != (char *)DldSysUndefSymbol) ? *(char **)(t + 0x10) + ((v >> 18) & 0xFFF) * *(int *)(*(char **)(t + 8) + 0xC) : 0;
}

int backStageCheckLoadSeg(unsigned int *h)
{
    int f = *(int *)(dldResolve(h) + 0xC);

    if (f == 0)
        return 1;
    return !_gameFlagChk(f);
}

typedef struct { s32 b[0x93]; } BSBlk;
extern BSBlk D_401FC4E0;
void backStageCheckPointSave(BSBlk *a0)
{
    *a0 = D_401FC4E0;
}
