#include "common.h"

extern s32 D_40131B28;
extern s32 D_40131ABC;
extern u8 D_40131AB0[];
extern u8 D_40131AC0[];
extern u8 D_40131AC4[];
extern u8 D_40131AC8[];
extern u8 D_40131ACC[];
extern u8 D_40203FE0[];
extern u8 gcGlobalVar[];
u8 *SCRGetFirstObj(void *table);
u8 *GetLayoutClass(void *chara);
void func_40084AA0(s32 a, s32 b);
void scrRun(void);
extern f32 D_40131AD8;
extern f32 D_40131ADC;
extern s32 D_40131AE0;
extern s32 D_40131AE4;
extern s32 D_40131AD4;
extern s32 rootPtn;
extern u8 D_40134530[];
s32 gcCreateScriptObj(void *fn, s32 a1, void *a2, s32 a3, s32 a4, s32 a5, const char *a6);
void func_40087D50(void);

s32 _optionWorkChk(s32 idx);
void _optionWorkSet(s32 idx, s32 val);
void setAspect(s32 aspect);
void setSoundMode(s32 mode);
void gStatLoadPlayerAccessories(void);
void _SCRStartSpriteMenuAnim(s32 obj, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5);
extern s32 ScriptSpriteMenuObjDef_SPRITE_OPTION;
extern s32 ScriptSpriteMenuObjDef_SPRITE_MAP_SMOKE_REND_LAYOUT;
extern s32 D_40131990;
s32 *getBrightness(void);
s32 *getScreenOffsetX(void);
s32 *getScreenOffsetY(void);
s32 *getSightOnRevCntrlLR(void);
s32 *getSightOnRevCntrlUD(void);
s32 *getFreeModeRevControlLR(void);
s32 *getFreeModeRevControlUD(void);
s32 *getFreeModeRevAngleVelRatio(void);
extern s32 D_40131B3C;

void OptionMenuStart(s32 a)
{
    D_40131990 = 0;
    _SCRStartSpriteMenuAnim(ScriptSpriteMenuObjDef_SPRITE_OPTION, 0, 0, a, 0, 0);
}

void PauseMenuStart(s32 a)
{
    D_40131990 = 0;
    _SCRStartSpriteMenuAnim(ScriptSpriteMenuObjDef_SPRITE_MAP_SMOKE_REND_LAYOUT, 0, 0, a, 0, 0);
}

s32 func_40087520(void)
{
    return _optionWorkChk(1);
}

s32 func_40087538(void)
{
    return _optionWorkChk(4);
}

s32 func_40087550(void)
{
    return _optionWorkChk(5);
}

s32 func_40087568(void)
{
    return _optionWorkChk(2);
}

s32 func_40087580(void)
{
    return _optionWorkChk(6);
}

s32 func_40087598(void)
{
    return _optionWorkChk(0x11);
}

s32 func_400875B0(void)
{
    return _optionWorkChk(0x16);
}

s32 func_400875C8(void)
{
    return _optionWorkChk(0x15);
}

s32 func_400875E0(void)
{
    return _optionWorkChk(0x13);
}

s32 func_400875F8(void)
{
    return _optionWorkChk(0x12);
}

s32 func_40087610(void)
{
    return _optionWorkChk(0x14);
}

void func_40087628(s32 a)
{
    s32 *p;

    _optionWorkSet(1, a);
    p = getBrightness();
    *p = a;
}

void func_40087660(s32 a)
{
    s32 *p;

    _optionWorkSet(4, a);
    p = getScreenOffsetX();
    *p = a;
}

void func_40087698(s32 a)
{
    s32 *p;

    _optionWorkSet(5, a);
    p = getScreenOffsetY();
    *p = a;
}

void func_400876D0(s32 a)
{
    _optionWorkSet(2, a);
    setAspect(a);
}

void func_40087700(s32 a)
{
    _optionWorkSet(6, a);
    setAspect(a);
}

void func_40087730(s32 a)
{
    _optionWorkSet(0x11, a);
}

void func_40087750(s32 a)
{
    s32 *p;

    _optionWorkSet(0x16, a);
    p = getSightOnRevCntrlLR();
    *p = a;
}

void func_40087788(s32 a)
{
    s32 *p;

    _optionWorkSet(0x15, a);
    p = getSightOnRevCntrlUD();
    *p = a;
}

void func_400877C0(s32 a)
{
    s32 *p;

    _optionWorkSet(0x13, a);
    p = getFreeModeRevControlLR();
    *p = a;
}

void func_400877F8(s32 a)
{
    s32 *p;

    _optionWorkSet(0x12, a);
    p = getFreeModeRevControlUD();
    *p = a;
}

void func_40087830(s32 a)
{
    s32 *p;

    _optionWorkSet(0x14, a);
    p = getFreeModeRevAngleVelRatio();
    *p = a;
}

s32 func_40087868(void)
{
    return _optionWorkChk(3);
}

void func_40087880(s32 a)
{
    _optionWorkSet(3, a);
    setSoundMode(a);
}

void initSavePoint(void) {
}

void deleteSavePoint(void) {
}

void SetMapLogDispMode(s32 mode)
{
    D_40131ABC = mode;
}

s32 getSprLogWorkSize(void)
{
    return 0x2D00;
}

u8* getSprLogWorkAddress(void)
{
    return D_40203FE0;
}

s32 getSprLogStatusSize(void)
{
    return 0xC;
}

u8* getSprLogStatusAddress(void)
{
    return D_40131AB0;
}

u8* getLogLineColorR(void)
{
    return D_40131AC0;
}

u8* getLogLineColorG(void)
{
    return D_40131AC4;
}

u8* getLogLineColorB(void)
{
    return D_40131AC8;
}

u8* getLogLineColorA(void)
{
    return D_40131ACC;
}

void mapLogReset(void)
{
    u8 *obj;
    u8 *layout;

    obj = SCRGetFirstObj(gcGlobalVar + 0x2B0);
    if (obj != NULL) {
        layout = GetLayoutClass(obj);
        if (layout != NULL) {
            func_40084AA0(*(s32 *)(layout + 0x134), 1);
        }
    }
}

void createPauseMenuMap(void)
{
    s32 *p = (s32 *)D_40131AB0;

    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    if (D_40131AD4 == 0) {
        D_40131AD4 = gcCreateScriptObj(func_40087D50, 0, &rootPtn, 0x1000, 0, 8, D_40134530);
    }
}

void initPauseMenuMap(void)
{
    s32 *p = (s32 *)D_40131AB0;

    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
}

void st_pausemenu_load_omake_chara(s32 *p)
{
    gStatLoadPlayerAccessories();
    *p = 1;
}

void setLoadMapOffset(f32 a, f32 b, s32 c, s32 d)
{
    D_40131AD8 = a;
    D_40131ADC = b;
    D_40131AE0 = c;
    D_40131AE4 = d;
}

extern const char *D_40131AE8[];
u32 MakeStrHashValue(const char *str);
void SpriteMenuSetDispFlagByHash(u8 *menu, u32 hash, s32 flag);

void loadMapSetCloud(u8 *menu)
{
    s32 i;
    const char **p;

    i = 0;
    p = D_40131AE8;
    do {
        s32 c = i < D_40131AE4;
        i++;
        if (c) {
            SpriteMenuSetDispFlagByHash(menu, MakeStrHashValue(*p), 0);
        } else {
            SpriteMenuSetDispFlagByHash(menu, MakeStrHashValue(*p), 1);
        }
        p++;
    } while ((u32)i < 0x10);
}

void *isysGetThisSubThread(void);
void ScrSpriteParamSetup(void *sp, void *param);
void ScrSpriteParamEnd(void *sp, s32 flag);
void PauseSeamlessStageManager(s32 flag);
void func_400865F0(void *thread);
void func_40086F78(void *thread, void *sp);
void func_400872A0(void *thread, void *sp);

void mapScript(void *param)
{
    void *thread;
    struct {
        s32 pad[2];
        s32 *mode;
    } sp;

    thread = isysGetThisSubThread();
    ScrSpriteParamSetup(&sp, param);
    if (sp.mode == NULL) {
        PauseSeamlessStageManager(1);
        func_400865F0(thread);
        PauseSeamlessStageManager(0);
    } else {
        switch (*sp.mode) {
        case 0:
            func_40086F78(thread, &sp);
            break;
        case 1:
            func_400872A0(thread, &sp);
            break;
        }
    }
    ScrSpriteParamEnd(&sp, 1);
}

void LoadWaitCancel(void)
{
    D_40131B28 = 0;
}

extern s32 D_40131B2C;
extern s32 D_40131B30;

void LoadWaitScript(void)
{
    D_40131B28 = 1;
    D_40131990 = 0;
    D_40131B2C = 0;
    _SCRStartSpriteMenuAnim(ScriptSpriteMenuObjDef_SPRITE_MAP_SMOKE_REND_LAYOUT, 0, 0, (s32)&D_40131B2C, (s32)&D_40131B28, (s32)&D_40131B30);
    while (D_40131B2C == 0) {
        scrRun();
    }
}

extern s32 D_40131B34;
extern s32 D_40131B38;

void LoadWaitScriptDemoStart(void)
{
    D_40131B28 = 1;
    D_40131990 = 0;
    D_40131B34 = 0;
    _SCRStartSpriteMenuAnim(ScriptSpriteMenuObjDef_SPRITE_MAP_SMOKE_REND_LAYOUT, 0, 0, (s32)&D_40131B34, (s32)&D_40131B28, (s32)&D_40131B38);
    while (D_40131B34 == 0) {
        scrRun();
    }
}

void execPause(void)
{
    D_40131990 = 0;
    _SCRStartSpriteMenuAnim(ScriptSpriteMenuObjDef_SPRITE_MAP_SMOKE_REND_LAYOUT, 0, 0, (s32)&D_40131B3C, 0, 0);
}

f32 GetMenuFade(void)
{
    return 0.0f;
}

void func_40087D50(void)
{
    u8 *obj;
    u8 *layout;

    while (1) {
        obj = SCRGetFirstObj(gcGlobalVar + 0x2B0);
        if (obj != NULL) {
            layout = GetLayoutClass(obj);
            if (layout != NULL) {
                func_40084AA0(*(s32 *)(layout + 0x134), 0);
            }
        }
        scrRun();
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0099_OptionMenuStart", physicalOp);

extern s32 ControlMode_PLAYER_FAINT;
extern s32 ScriptCtrlDef_SCRPlayerFaintLoop;
extern u8 padManagerData[];
void GAMEUTIL_get_1p_left_analog_input(f32 *a, f32 *b);
f32 fabsf(f32 x);
u8 *GetCharacterClass(void *chara);
void CharaCtrlSetScriptCtrlStatus(void *chara, s32 status);

void func_400882C8(u8 *p)
{
    s32 *mode;
    void *thread;
    u8 *cls;
    u8 *q;
    u8 *pm;
    f32 lx;
    f32 ly;
    f32 acc;
    f32 limit;

    mode = &ControlMode_PLAYER_FAINT;
    thread = isysGetThisSubThread();
    GAMEUTIL_get_1p_left_analog_input(&lx, &ly);
    cls = GetCharacterClass(thread);
    if (*mode == *(s32 *)(cls + 0x740)) {
        if (*(f32 *)(p + 0x11C) * lx <= 0.0f) {
            if (0.7f < fabsf(lx)) {
                *(s32 *)(p + 0x114) += 1;
                *(f32 *)(p + 0x11C) = lx;
                *(f32 *)(p + 0x120) = ly;
            }
        }
        if (*(f32 *)(p + 0x120) * ly <= 0.0f) {
            if (0.7f < fabsf(ly)) {
                *(s32 *)(p + 0x114) += 1;
                *(f32 *)(p + 0x11C) = lx;
                *(f32 *)(p + 0x120) = ly;
            }
        }
        pm = padManagerData;
        if ((*(s32 *)(pm + 0x8) & 0x40) != 0) {
            *(s32 *)(p + 0x114) += 1;
        }
        if ((*(s32 *)(pm + 0x8) & 0x10) != 0) {
            *(s32 *)(p + 0x114) += 1;
        }
        if ((*(s32 *)(pm + 0x8) & 0x80) != 0) {
            *(s32 *)(p + 0x114) += 1;
        }
        if ((*(s32 *)(pm + 0x8) & 0x20) != 0) {
            *(s32 *)(p + 0x114) += 1;
        }
        acc = *(f32 *)(p + 0x118) + *(f32 *)(gcGlobalVar + 0x180);
        *(f32 *)(p + 0x118) = acc;
        q = *(u8 **)(p + 0x130);
        acc = acc + (f32)*(s32 *)(p + 0x114) * *(f32 *)(q + 0x40);
        limit = *(f32 *)(q + 0x44);
        if (!(limit < acc)) {
            CharaCtrlSetScriptCtrlStatus(thread, *(s32 *)(ScriptCtrlDef_SCRPlayerFaintLoop + 4));
        }
    } else {
        *(f32 *)(p + 0x11C) = lx;
        *(f32 *)(p + 0x120) = ly;
        *(s32 *)(p + 0x118) = 0;
        *(s32 *)(p + 0x114) = 0;
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0099_OptionMenuStart", func_400884B0);

extern u8 SH_WeaponChangeMotList2DEFAULT[];
extern u8 padManagerData[];
extern s32 SeList_cursor;
extern s32 ScriptCtrlDef_SCRPlayerWeaponChangeExec;
s32 *GetAnimationClass(void *chara);
s32 chkMotionList(s32 motList, u8 *list);
s32 selectWeaponNext(s32 weapon);
s32 selectWeaponBefore(s32 weapon);
u8 *GetCharacterClass(void *chara);
void CharaCtrlSetScriptCtrlStatus(void *chara, s32 status);
void sePlaySystemSound(s32 se);
void func_4008C660(void *chara, s32 arg);

void func_40088740(u8 *p)
{
    void *thread;
    s32 *anim;
    u8 *cls;
    u8 *g;
    s32 pad;
    s32 one;
    s32 changed;
    s32 old;

    thread = isysGetThisSubThread();
    anim = GetAnimationClass(thread);
    if (chkMotionList(anim[0], SH_WeaponChangeMotList2DEFAULT) != 0) {
        if (*(s32 *)(p + 0x80) != 0) {
            return;
        }
        changed = 0;
        one = 1;
        g = gcGlobalVar;
        pad = *(s32 *)(padManagerData + 0x8);
        if ((pad & (one << *(s32 *)(g + 0x318))) != 0) {
            *(s32 *)(p + 0x7C) = selectWeaponNext(*(s32 *)(p + 0x7C));
            changed = 1;
        } else if ((pad & (one << *(s32 *)(g + 0x314))) != 0) {
            *(s32 *)(p + 0x7C) = selectWeaponBefore(*(s32 *)(p + 0x7C));
            changed = 1;
        }
        CharaCtrlSetScriptCtrlStatus(thread, *(s32 *)(ScriptCtrlDef_SCRPlayerWeaponChangeExec + 4));
        if (changed == 0) {
            return;
        }
        sePlaySystemSound(SeList_cursor);
        return;
    } else {
        *(s32 *)(p + 0x80) = 0;
        cls = GetCharacterClass(thread);
        if (*(s8 *)(cls + 0x35C) == 0) {
            return;
        }
        if (chkMotionList(anim[1], SH_WeaponChangeMotList2DEFAULT) == 0) {
            return;
        }
        if (chkMotionList(anim[0], SH_WeaponChangeMotList2DEFAULT) != 0) {
            return;
        }
        old = *(s32 *)(p + 0x70);
        *(s32 *)(p + 0x70) = *(s32 *)(p + 0x7C);
        func_4008C660(thread, old);
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0099_OptionMenuStart", func_400888C0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0099_OptionMenuStart", func_40088A38);

s32 _omakeSelectFlagChk(s32 idx);
void SetScriptAnimationObjAccessSwitch(s32 obj, s32 flag);

void func_40088BC8(u8 *p)
{
    s32 v;

    isysGetThisSubThread();
    if (_omakeSelectFlagChk(7) != 0) {
        v = *(s32 *)(p + 0x60);
        if (v == 0) {
            v = *(s32 *)(p + 0x64);
        } else if (*(p + 0x74) == 0) {
            if (*(s32 *)(p + 0x68) == 0) {
                SetScriptAnimationObjAccessSwitch(v, 0);
            }
            v = *(s32 *)(p + 0x64);
        } else {
            SetScriptAnimationObjAccessSwitch(v, 0);
            v = *(s32 *)(p + 0x64);
        }
        if (v != 0) {
            if (*(p + 0x75) == 0) {
                if (*(s32 *)(p + 0x6C) == 0) {
                    SetScriptAnimationObjAccessSwitch(v, 0);
                }
            } else {
                SetScriptAnimationObjAccessSwitch(v, 0);
            }
        }
    } else {
        v = *(s32 *)(p + 0x60);
        if (v == 0) {
            v = *(s32 *)(p + 0x64);
        } else if (*(p + 0x74) == 0) {
            if (*(s32 *)(p + 0x68) == 0) {
                SetScriptAnimationObjAccessSwitch(v, 1);
            }
            v = *(s32 *)(p + 0x64);
        } else {
            SetScriptAnimationObjAccessSwitch(v, 1);
            v = *(s32 *)(p + 0x64);
        }
        if (v != 0) {
            if (*(p + 0x75) == 0) {
                if (*(s32 *)(p + 0x6C) == 0) {
                    SetScriptAnimationObjAccessSwitch(v, 1);
                }
            } else {
                SetScriptAnimationObjAccessSwitch(v, 1);
            }
        }
    }
}
