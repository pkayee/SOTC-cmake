#include "common.h"
extern u8 gcGlobalVar[];
extern u8 padManagerData[];
extern s32 D_401FD194;
extern s32 D_40130CC4;
extern s32 D_40130CC8;
extern s32 D_40130CC0;
extern s32 D_40130CCC;
extern s32 D_401FD190;
extern s32 vschedGameTimeExec;
extern s32 gstatTimeAttackMode;
extern s32 gameflowStartMenuKaisou;
extern s32 SeList_pause;
extern s32 ScriptSpriteMenuObjDef_SPRITE_GAME_OVER_LAYOUT;
extern u8 D_40130CD0[];
extern s32 SeList_hp_alert;
extern s32 SeList_grip_alert;
extern s32 SeList_grip_alert_vo;
extern s32 D_40130CB8;
extern s32 D_40130CA4;
extern s32 D_40130CAC;
extern s32 D_40130CB0;
extern s32 controller_alert_script_pause;
extern u8 D_401FD110[];
extern f32 IdentityQuaternion[];
extern f32 ZeroPoint[];
extern s32 D_401FD198[];
extern s32 __gameMode;
extern s8 D_401FD1B0[];
void *memset(void *p, int c, unsigned n);
extern s32 rootPtn;
extern u8 D_401FD1D0[];
extern s32 D_40130ED8;
extern s32 D_40130EDC;
extern s32 D_40130EE0;
extern s32 *D_40130EE4;
extern s32 *D_40130EE8;
extern s32 D_40130EEC;
extern s32 D_40130E58[];
extern s32 D_40130EA8[];
typedef struct { s32 v[4]; } Acc16;
extern Acc16 D_40200E60;
typedef struct { s32 id; s32 flag; u8 pad[0xC]; } HorseEnt;
extern struct { u8 pad[0xC]; s32 num; HorseEnt *ent; } SH_HorseTypeDEFAULT;
s32 stagemanager_getSegmentVariation(void);
void SaveLayoutObjGroupAllGeo();
void _gameFlagSet(s32 idx);
s32 _gameFlagCls(s32 idx);
s32 _gameFlagChk(s32 idx);
void gameFlagCheckPointSave(void *a, void *b, void *c, void *d, void *e, void *f);
void gameFlagCheckPointLoad(void *a, void *b, void *c, void *d, void *e, void *f);
void backStageCheckPointSave(void *a);
void backStageCheckPointLoad(void *a);
void *getSprLogWorkAddress(void);
s32 getSprLogWorkSize(void);
void *getSprLogStatusAddress(void);
s32 getSprLogStatusSize(void);
void *memcpy(void *d, const void *s, unsigned n);
void gStatUnloadHorseChara(void);
void gStatRestartHorseChara(void);
void stagemanager_restartstagecore(void *root, s32 a, s32 b, s32 c);
void stagemanager_loadstagecore(void *root, s32 a, s32 b, s32 c);
void nico_hydePlayer(void *obj, s32 f);
s32 bossStatGetActiveBoss(void);
void scrRun(void);
void scrInit(void *thread);
void *isysGetThisSubThread(void);
void sheetMgrAllReqWait(s32 *res);
void sheetMgrSpecialFsStart(s32 a, s32 b, s32 *res);
void sheetMgrSpecialFsEnd(s32 a, s32 *res);
void GetQuaternionByDegEulerYXZ(f32 *out, f32 x, f32 y, f32 z);
void DebugSetObjectGeometry(void *obj, f32 *quat, f32 *pos);
void *SCRGetFirstObj(void *p);
void PauseGame(s32 a);
void ReleaseGame(s32 a);
void adpcmGamePause(s32 a);
void sndSepPauseAll(s32 a);
s32 sePlaySystemSound(s32 a);
s32 sePlay3D(s32 a, void *pos, s32 b, s32 c);
void SetGeometryPointerNodePosState(void *a, void *obj, s32 b, f32 *quat, f32 *pos);
void execPause(void);
void timeAttackPauseScriptBegin(void);
void timeAttackInScriptBegin(void);
void ReplayPauseScriptBegin(void);
void ReplayInScriptBegin(void);
void fadeOut(s32 a, f32 t, s32 b);
void fadeIn(s32 a, f32 t, s32 b);
void setLayerFade(s32 v);
void gameModeSet(u32 mode);
void SetCaptionPauseFlag(s32 a);
void bgmStop(s32 h, f32 t, s32 b);
s32 _omakeSelectFlagChk(s32 a);
void begin_check_and_boot_boss_subjective_camera_lws_animation(void);
void end_check_and_boot_boss_subjective_camera_lws_animation(void);
void _SCRStartSpriteMenuAnim(s32 layout, void *thread, s32 a, s32 *flag, s32 b, void *c);
void bootmccheckscript();
s32 _optionWorkChk(s32 idx);
void bootprogressivecheck();
void scrRunM(s32 n);
void bootscelogoscript();
s32 gcCheckStageLoadFinish(void);
void stagemanager_unloadstagecore(s32 n);

static inline void gameflowSetPosInl(void *obj, f32 x, f32 y, f32 z, f32 rx, f32 ry, f32 rz)
{
    f32 pos[4];
    f32 quat[4];
    pos[0] = -x;
    pos[1] = y;
    pos[2] = -z;
    pos[3] = 1.0f;
    GetQuaternionByDegEulerYXZ(quat, rx, -ry, rz);
    DebugSetObjectGeometry(obj, quat, pos);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0022_gameflowMpegCancelChk", gameflowMpegCancelChk);
s32 gameflowMpegCancelChk(void)
{
    return (*(s32 *)(padManagerData + 8) >> 11) & 1;
}


//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0022_gameflowMpegCancelChk", gameflowSheetMgrAllReqWait);
void gameflowSheetMgrAllReqWait(void)
{
    s32 res;
    scrRun();
    sheetMgrAllReqWait(&res);
    while (res != 0xDEAF && res != 0xDEB0) {
        scrRun();
    }
}


//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0022_gameflowMpegCancelChk", gameflowSheetMgrSplFsStart);
void gameflowSheetMgrSplFsStart(s32 a)
{
    s32 res;
    scrRun();
    sheetMgrSpecialFsStart(a, 1, &res);
    while (res != 0xDEAF && res != 0xDEB0) {
        scrRun();
    }
}


//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0022_gameflowMpegCancelChk", gameflowSheetMgrSplFsEnd);
void gameflowSheetMgrSplFsEnd(s32 a)
{
    s32 res;
    scrRun();
    sheetMgrSpecialFsEnd(a, &res);
    while (res != 0xDEAF && res != 0xDEB0) {
        scrRun();
    }
}


//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0022_gameflowMpegCancelChk", gameflowSelectGameoverMenu);
void gameflowSelectGameoverMenu(s32 v)
{
    D_401FD194 = v;
}


//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0022_gameflowMpegCancelChk", gameflowSetPos);
void gameflowSetPos(void *obj, f32 x, f32 y, f32 z, f32 rx, f32 ry, f32 rz)
{
    f32 pos[4];
    f32 quat[4];
    pos[0] = -x;
    pos[1] = y;
    pos[2] = -z;
    pos[3] = 1.0f;
    GetQuaternionByDegEulerYXZ(quat, rx, -ry, rz);
    DebugSetObjectGeometry(obj, quat, pos);
}


//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0022_gameflowMpegCancelChk", gameflowJumpOp2DemoSkip);
void gameflowJumpOp2DemoSkip(void)
{
    void *a = SCRGetFirstObj(gcGlobalVar + 0x2B0);
    void *b = SCRGetFirstObj(gcGlobalVar + 0x2B4);
    gameflowSetPosInl(a, 300.0f, 11.0f, 278.0f, 0.0f, 0.0f, 0.0f);
    gameflowSetPosInl(b, 292.0f, 10.0f, 290.0f, 0.0f, 0.0f, 0.0f);
}


//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0022_gameflowMpegCancelChk", gameflowSetPauseEnable);
void gameflowSetPauseEnable(s32 enable)
{
    s32 *p = &D_40130CC4;
    s32 v;
    if (enable == 0) {
        v = *p + 1;
    } else {
        v = *p - 1;
    }
    *p = v;
}


void gameflowSetCaptionPause(s32 arg0)
{
    s32 old;
    s32 val;

    old = D_40130CC8;
    val = old + 1;
    if (arg0 ^ 1)
    {
        val = old - 1;
    }
    D_40130CC8 = val;
    if (old > 0 && val == 0)
    {
        SetCaptionPauseFlag(0);
        return;
    }
    if (old == 0 && D_40130CC8 > 0)
    {
        SetCaptionPauseFlag(1);
        return;
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0022_gameflowMpegCancelChk", gameflowGetJumpSekiban);
s32 gameflowGetJumpSekiban(void)
{
    return D_40130CC0;
}


//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0022_gameflowMpegCancelChk", gameflowSetJumpSekiban);
void gameflowSetJumpSekiban(s32 v)
{
    D_40130CC0 = v;
}


//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0022_gameflowMpegCancelChk", func_4002D838);
void func_4002D838(void)
{
    scrInit(isysGetThisSubThread());
    PauseGame(1);
}


//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0022_gameflowMpegCancelChk", func_4002D860);
void func_4002D860(void)
{
    scrInit(isysGetThisSubThread());
    ReleaseGame(1);
}


//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0022_gameflowMpegCancelChk", func_4002D888);
void func_4002D888(void)
{
    scrInit(isysGetThisSubThread());
    PauseGame(1);
}


//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0022_gameflowMpegCancelChk", func_4002D8B0);
void func_4002D8B0(void)
{
    scrInit(isysGetThisSubThread());
    ReleaseGame(1);
}


//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0022_gameflowMpegCancelChk", func_4002D8D8);
void func_4002D8D8(void)
{
    scrInit(isysGetThisSubThread());
    gameModeSet(1);
    D_40130CCC = 1;
    adpcmGamePause(1);
    sndSepPauseAll(1);
    sePlaySystemSound(SeList_pause);
    if (gameflowStartMenuKaisou == 0) {
        timeAttackInScriptBegin();
    } else {
        ReplayInScriptBegin();
    }
}


//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0022_gameflowMpegCancelChk", func_4002D940);
void func_4002D940(void)
{
    scrInit(isysGetThisSubThread());
    adpcmGamePause(0);
    sndSepPauseAll(0);
    D_40130CCC = 0;
    D_401FD190 = 9;
}


//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0022_gameflowMpegCancelChk", st_menupause);
void st_menupause(void)
{
    scrInit(isysGetThisSubThread());
    PauseGame(1);
    vschedGameTimeExec = 0;
    if (gstatTimeAttackMode == 0) {
        execPause();
    } else {
        D_40130CCC = 2;
        if (gameflowStartMenuKaisou == 0) {
            timeAttackPauseScriptBegin();
        } else {
            fadeOut(1, 0.4f, 0);
            setLayerFade(0x19);
            ReplayPauseScriptBegin();
        }
    }
    adpcmGamePause(1);
    sndSepPauseAll(1);
    sePlaySystemSound(SeList_pause);
}


//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0022_gameflowMpegCancelChk", func_4002DA48);
void func_4002DA48(void)
{
    s32 one = 1;
    scrInit(isysGetThisSubThread());
    ReleaseGame(1);
    vschedGameTimeExec = one;
    adpcmGamePause(0);
    sndSepPauseAll(0);
    D_40130CCC = 0;
    if (_omakeSelectFlagChk(0x19) != 0) {
        D_40130CB8 = one;
        begin_check_and_boot_boss_subjective_camera_lws_animation();
    } else {
        end_check_and_boot_boss_subjective_camera_lws_animation();
        D_40130CB8 = 0;
    }
    if (gameflowStartMenuKaisou != 0) {
        fadeIn(0, 0.4f, 0);
    }
}


//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0022_gameflowMpegCancelChk", func_4002DB00);
void func_4002DB00(void)
{
    D_401FD190 = 1;
}


//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0022_gameflowMpegCancelChk", func_4002DB10);
void func_4002DB10(s32 *flag)
{
    void *th = isysGetThisSubThread();
    scrInit(th);
    _SCRStartSpriteMenuAnim(ScriptSpriteMenuObjDef_SPRITE_GAME_OVER_LAYOUT, th, 0, flag, 0, D_40130CD0);
    while (*flag == 0) {
        scrRun();
    }
}


//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0022_gameflowMpegCancelChk", func_4002DB90);
void func_4002DB90(void)
{
    D_401FD190 = 4;
}


//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0022_gameflowMpegCancelChk", func_4002DBA0);
void func_4002DBA0(void)
{
    D_401FD190 = 5;
}


//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0022_gameflowMpegCancelChk", func_4002DBB0);
void func_4002DBB0(void)
{
    D_401FD190 = 6;
}


//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0022_gameflowMpegCancelChk", func_4002DBC0);
void func_4002DBC0(void)
{
    D_401FD190 = 7;
}


//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0022_gameflowMpegCancelChk", func_4002DBD0);
void func_4002DBD0(void)
{
    scrInit(isysGetThisSubThread());
    adpcmGamePause(0);
    sndSepPauseAll(0);
    D_40130CCC = 0;
    D_401FD190 = 3;
}


//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0022_gameflowMpegCancelChk", func_4002DC18);
void func_4002DC18(s32 h)
{
    bgmStop(h, 20.0f, 0);
}


//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0022_gameflowMpegCancelChk", gameflowJumpOp2DemoNoSkip);
void gameflowJumpOp2DemoNoSkip(void)
{
    gameflowSetPosInl(SCRGetFirstObj(gcGlobalVar + 0x2B4), 292.0f, 10.0f, 290.0f, 0.0f, 0.0f, 0.0f);
}


//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0022_gameflowMpegCancelChk", func_4002DCB8);
void func_4002DCB8(void)
{
    D_401FD190 = 8;
}


//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0022_gameflowMpegCancelChk", func_4002DCC8);
void func_4002DCC8(void)
{
    D_40130CA4 = sePlaySystemSound(SeList_hp_alert);
}


//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0022_gameflowMpegCancelChk", func_4002DCF8);
void func_4002DCF8(void)
{
    D_40130CAC = sePlaySystemSound(SeList_grip_alert);
    SetGeometryPointerNodePosState(D_401FD110, SCRGetFirstObj(gcGlobalVar + 0x2B0), 0, IdentityQuaternion, ZeroPoint);
    D_40130CB0 = sePlay3D(SeList_grip_alert_vo, D_401FD110, 0, 0);
}


//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0022_gameflowMpegCancelChk", func_4002DD80);
void func_4002DD80(s32 *p)
{
    bootmccheckscript(p, p + 1);
    while (p[0] == 0) {
        scrRun();
    }
    if (_optionWorkChk(6) != 0) {
        bootprogressivecheck(p + 2);
        while (p[2] == 0) {
            scrRun();
        }
    }
    controller_alert_script_pause = 1;
    scrRunM(0x3C);
    bootscelogoscript(p + 4, p + 3);
    while (p[3] == 0) {
        scrRun();
    }
}


//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0022_gameflowMpegCancelChk", func_4002DE50);
void func_4002DE50(void)
{
    while (gcCheckStageLoadFinish() == 0) {
        scrRun();
    }
    D_401FD198[3] = 0;
    while (D_401FD198[4] == 0) {
        scrRun();
    }
    controller_alert_script_pause = 0;
    stagemanager_unloadstagecore(0x8D);
}


//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0022_gameflowMpegCancelChk", gameModeSet);
void gameModeSet(u32 mode)
{
    s32 i;
    __gameMode |= mode;
    for (i = 0; mode != 0; i++, mode >>= 1) {
        if (mode & 1) {
            D_401FD1B0[i]++;
        }
    }
}


//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0022_gameflowMpegCancelChk", gameModeCls);
void gameModeCls(u32 mode)
{
    s32 i;
    for (i = 0; mode != 0; i++, mode >>= 1) {
        if (mode & 1) {
            D_401FD1B0[i]--;
            if (D_401FD1B0[i] == 0) {
                __gameMode &= ~(1 << i);
            } else if (D_401FD1B0[i] < 0) {
                D_401FD1B0[i] = 0;
            }
        }
    }
}


//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0022_gameflowMpegCancelChk", gameModeInit);
void gameModeInit(void)
{
    __gameMode = 0;
    memset(D_401FD1B0, 0, 0x20);
}


//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0022_gameflowMpegCancelChk", gStatCheckPointSave);
void gStatCheckPointSave(void)
{
    s32 var = 0;
    s32 seg = stagemanager_getSegmentVariation();
    void *horse = SCRGetFirstObj(gcGlobalVar + 0x2B4);
    s32 has;
    SaveLayoutObjGroupAllGeo();
    has = horse != 0;
    if (seg != -1) {
        var = seg;
    }
    if (gstatTimeAttackMode == 0) {
        if (has == 0) {
            _gameFlagSet(0x1C);
        } else {
            _gameFlagCls(0x1C);
        }
        gameFlagCheckPointSave(D_401FD1D0, D_401FD1D0 + 0x64, D_401FD1D0 + 0x1F4, D_401FD1D0 + 0x384, D_401FD1D0 + 0x6A4, D_401FD1D0 + 0x3C20);
        backStageCheckPointSave(D_401FD1D0 + 0x9C4);
        memcpy(D_401FD1D0 + 0xC10, getSprLogWorkAddress(), getSprLogWorkSize());
        memcpy(D_401FD1D0 + 0x3C10, getSprLogStatusAddress(), getSprLogStatusSize());
        D_401FD1D0[0x3C1C] = var;
    }
}


//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0022_gameflowMpegCancelChk", gStatCheckPointLoad);
u8 gStatCheckPointLoad(void)
{
    gameFlagCheckPointLoad(D_401FD1D0, D_401FD1D0 + 0x64, D_401FD1D0 + 0x1F4, D_401FD1D0 + 0x384, D_401FD1D0 + 0x6A4, D_401FD1D0 + 0x3C20);
    backStageCheckPointLoad(D_401FD1D0 + 0x9C4);
    memcpy(getSprLogWorkAddress(), D_401FD1D0 + 0xC10, getSprLogWorkSize());
    memcpy(getSprLogStatusAddress(), D_401FD1D0 + 0x3C10, getSprLogStatusSize());
    if (_gameFlagChk(0x1C) != 0) {
        if (SCRGetFirstObj(gcGlobalVar + 0x2B4) != 0) {
            gStatUnloadHorseChara();
        }
    }
    return D_401FD1D0[0x3C1C];
}


//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0022_gameflowMpegCancelChk", gStatLoadPlayerAccessories);
void gStatLoadPlayerAccessories(void)
{
    u8 *boss = (u8 *)bossStatGetActiveBoss();
    s32 *e = D_40130E58;
    s32 *q;
    s32 *sel;
    s32 *cur;
    s32 new;
    while (e[0] != 0) {
        if (_omakeSelectFlagChk(e[0]) != 0) {
            break;
        }
        e += 4;
    }
    q = D_40130EA8;
    while (q[0] != 0) {
        if (_omakeSelectFlagChk(q[0]) != 0) {
            sel = q;
            goto found;
        }
        q += 4;
    }
    if (boss != 0) {
        q[1] = *(s32 *)(boss + 0x90);
    } else {
        q[1] = 0xB4;
    }
    sel = q;
found:
    new = e[1];
    if (D_40130EE4[1] != 0) {
        if (new == D_40130EE4[1]) {
            goto skip1;
        }
        stagemanager_unloadstagecore(D_40130EE4[1]);
    }
    if (new != 0) {
        stagemanager_loadstagecore(&rootPtn, new, -1, 0);
    }
skip1:
    D_40130EE4 = e;
    {
        s32 c = (D_40130EE8 != 0) ? D_40130EE8[1] : 0;
        new = q[1];
        if (c != 0) {
            if (new == c) {
                goto skip2;
            }
            stagemanager_unloadstagecore(c);
        }
        if (new != 0) {
            stagemanager_loadstagecore(&rootPtn, new, -1, 0);
        }
    }
skip2:
    D_40200E60 = *(Acc16 *)sel;
    D_40130EE8 = (s32 *)&D_40200E60;
    new = (boss == 0) ? 0xB3 : *(s32 *)(boss + 0x88);
    if (new != D_40130EDC) {
        if (D_40130EDC != 0) {
            stagemanager_unloadstagecore(D_40130EDC);
        }
        if (new != 0) {
            stagemanager_loadstagecore(&rootPtn, new, -1, 0);
        }
        D_40130EDC = new;
    }
    new = (boss == 0) ? 0xB2 : *(s32 *)(boss + 0x8C);
    if (new != D_40130EE0) {
        if (D_40130EE0 != 0) {
            stagemanager_unloadstagecore(D_40130EE0);
        }
        if (new != 0) {
            stagemanager_loadstagecore(&rootPtn, new, -1, 0);
        }
        D_40130EE0 = new;
    }
    nico_hydePlayer(SCRGetFirstObj(gcGlobalVar + 0x2B0), _omakeSelectFlagChk(7) != 0);
}


//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0022_gameflowMpegCancelChk", gStatRestartPlayerChara);
void gStatRestartPlayerChara(void)
{
    void *obj;
    if (D_40130ED8 != 0) {
        stagemanager_restartstagecore(&rootPtn, D_40130ED8, -1, 0);
    }
    if (D_40130EDC != 0) {
        stagemanager_restartstagecore(&rootPtn, D_40130EDC, -1, 0);
    }
    if (D_40130EE0 != 0) {
        stagemanager_restartstagecore(&rootPtn, D_40130EE0, -1, 0);
    }
    if (D_40130EE4[1] != 0) {
        stagemanager_restartstagecore(&rootPtn, D_40130EE4[1], -1, 0);
    }
    if (D_40130EE8[1] != 0) {
        stagemanager_restartstagecore(&rootPtn, D_40130EE8[1], -1, 0);
    }
    if (D_40130ED8 != 0) {
        obj = SCRGetFirstObj(gcGlobalVar + 0x2B0);
        nico_hydePlayer(obj, _omakeSelectFlagChk(7) != 0);
    }
}


//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0022_gameflowMpegCancelChk", gStatReloadHorseChara);
static inline s32 getHorseStageId(void)
{
    s32 n = SH_HorseTypeDEFAULT.num;
    HorseEnt *ent = SH_HorseTypeDEFAULT.ent;
    HorseEnt *p;
    HorseEnt *q;
    s32 i = 0;
    n--;
    for (q = ent + 1; i < n; i++, q++) {
        if (_omakeSelectFlagChk(q->flag) != 0) {
            p = q;
            goto out;
        }
    }
    p = ent;
out:
    return p->id;
}
void gStatReloadHorseChara(void)
{
    s32 new;
    gStatRestartHorseChara();
    if (getHorseStageId() != D_40130EEC) {
        new = getHorseStageId();
        if (D_40130EEC != 0) {
            if (new == D_40130EEC) {
                goto skip;
            }
            stagemanager_unloadstagecore(D_40130EEC);
        }
        if (new != 0) {
            stagemanager_loadstagecore(&rootPtn, new, -1, 0);
        }
skip:
        {
            s32 *d = &D_40130EEC;
            *d = getHorseStageId();
        }
    }
}

