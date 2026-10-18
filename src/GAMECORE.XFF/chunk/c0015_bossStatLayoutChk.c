#include "common.h"
extern s32 DldSysUndefSymbol;
extern u8 SH_BossStatusDEFAULT[];
extern u8 *D_40130B50;
void _gameFlagCls();
s32 _gameFlagChk();
extern s32 D_40130B48;
extern u8 *D_40130B4C;
s32 _gameWorkChk();
extern s32 D_40130B54;
extern s32 ScrIntrDef_SYSTEM_CONTINUE;
void scriptIntrSignal();
extern s32 D_40130BF0;
extern s32 D_40130C30;
void *get_main_cameraman();
void *get_game_camera();
void reset_game_camera_standby_flag();
extern u8 *D_40130BB4;
extern s32 ScrIntrDef_JUMP_HOKORA;
extern s32 ScrIntrDef_JUMP_SEKIBAN;
void func_40025FF8();
void setSmallManagerSystemLock();
void func_40025E30();
void windowCloseRequest();

#define DLD_ELEM(out, lpexpr) \
    do { \
        u32 *lp_ = (lpexpr); \
        u32 w_ = *lp_; \
        u32 off_ = w_ & 0x3FFFF; \
        u8 *slot_ = off_ ? *(u8 **)((u8 *)lp_ - off_) : NULL; \
        out = (slot_ != NULL && slot_ != (u8 *)DldSysUndefSymbol) \
                  ? *(u8 **)(slot_ + 0x10) + ((w_ >> 18) & 0xFFF) * *(s32 *)(*(u8 **)(slot_ + 8) + 0xC) \
                  : NULL; \
    } while (0)
s32 bossStatLayoutChk(u8 *a0)
{
    u8 *e;

    DLD_ELEM(e, (u32 *)(a0 + 0x24));
    return _gameFlagChk(*(s32 *)(e + 0xC)) == 0;
}

extern u8 *D_40130B50;
void _gameFlagCls();
void bossStatSetDeadBoss(u8 *b)
{
    D_40130B50 = b;
    _gameFlagCls(*(s32 *)(b + 0x18));
}

u8 *bossStatGetDeadBoss(void)
{
    return D_40130B50;
}

s32 _gameFlagChk();
s32 bossStatChkDeadBoss(u8 *b)
{
    return _gameFlagChk(*(s32 *)(b + 0x18)) == 0;
}

s32 bossStatGetDeadBossNum(void)
{
    u8 *t = ((s32)SH_BossStatusDEFAULT != DldSysUndefSymbol) ? SH_BossStatusDEFAULT : 0;
    s32 n = 0;
    s32 i = 0;
    u8 *e = *(u8 **)(t + 0x10);

    if (*(s32 *)(t + 0xC) > 0) {
        do {
            if (_gameFlagChk(*(s32 *)(e + 0x18)) == 0) {
                n++;
            }
            e += 0xC0;
            i++;
        } while (i < *(s32 *)(t + 0xC));
    }
    return n;
}

s32 gStatGetGObjAdrs();
u8 *bossStatGetActiveBoss(void);
s32 bossStatBootChk(void)
{
    u8 *b = bossStatGetActiveBoss();
    s32 g;

    if (b != 0) {
        g = *(s32 *)(b + 0xBC);
        if (g != 0) {
            if (gStatGetGObjAdrs(g) != 0) {
                return _gameFlagChk(*(s32 *)(b + 0x1C)) != 0;
            }
        }
    }
    return -1;
}

extern s32 D_40130B48;
extern u8 *D_40130B4C;
s32 _gameWorkChk();
u8 *bossStatGetActiveBoss(void)
{
    s32 w = _gameWorkChk(8);
    u8 *t;

    if (w == D_40130B48) {
        return D_40130B4C;
    }
    D_40130B48 = w;
    if (w == -1) {
        D_40130B4C = 0;
        return 0;
    }
    t = ((s32)SH_BossStatusDEFAULT != DldSysUndefSymbol) ? SH_BossStatusDEFAULT : 0;
    D_40130B4C = *(u8 **)(t + 0x10) + w * 0xC0;
    return D_40130B4C;
}

u8 *bossStatSrhSheetAliveBoss(void)
{
    u8 *t;
    s32 i;
    u8 *e;

    if (DldSysUndefSymbol != (s32)SH_BossStatusDEFAULT) {
        t = SH_BossStatusDEFAULT;
    } else {
        t = 0;
    }
    i = 0;
    e = *(u8 **)(t + 0x10);
    if (*(s32 *)(t + 0xC) > 0) {
        do {
            if (_gameFlagChk(*(s32 *)(e + 0x18)) != 0) {
                return e;
            }
            i++;
            e += 0xC0;
        } while (i < *(s32 *)(t + 0xC));
    }
    return 0;
}

extern s32 gstatTimeAttackMode;
void bossCloudStart();
void func_40025858();
void gStatStartTimeAttack();
void bossStatStartDemo(void)
{
    s32 w = _gameWorkChk(8);
    u8 *e;

    if (w == D_40130B48) {
        e = D_40130B4C;
    } else {
        D_40130B48 = w;
        if (w == -1) {
            D_40130B4C = 0;
            e = 0;
        } else {
            u8 *t = ((s32)SH_BossStatusDEFAULT != DldSysUndefSymbol) ? SH_BossStatusDEFAULT : 0;
            D_40130B4C = *(u8 **)(t + 0x10) + w * 0xC0;
            e = D_40130B4C;
        }
    }
    if ((*(u32 *)(e + 0x40) >> 1) & 1) {
        bossCloudStart();
    }
    func_40025858();
    if (gstatTimeAttackMode != 0) {
        gStatStartTimeAttack();
    }
}

void ExchangeLWVector();
void bossStatGetBossCloudPos(f32 *out, f32 *in)
{
    out[0] = in[1];
    out[1] = in[2];
    out[2] = in[3];
    out[3] = 1.0f;
    ExchangeLWVector(out, out);
}

extern s32 ScrIntrDef_SYSTEM_PAUSE;
extern u8 D_40130B88[];
void createSheetMenu();
void bossSelectMenu(void)
{
    u8 *t = ((s32)SH_BossStatusDEFAULT != DldSysUndefSymbol) ? SH_BossStatusDEFAULT : 0;
    u8 *m;
    u8 *q;
    s32 w;
    s32 n;

    scriptIntrSignal(ScrIntrDef_SYSTEM_PAUSE);
    m = D_40130B88;
    w = (_gameWorkChk(8) == -1) ? 0 : _gameWorkChk(8);
    *(s32 *)(m + 0x18) = w;
    q = D_40130B88;
    *(s32 *)(q + 8) = *(s32 *)(t + 0x10);
    n = *(s32 *)(t + 0xC);
    *(s32 *)(q + 0xC) = n;
    if (n != 0) {
        D_40130B54 = 1;
        createSheetMenu(q, 0);
    }
}

extern s32 D_401FC730;
void func_40025E30();
void setPlayerMaxHp(f32 v);
void setPlayerMaxGrip(f32 v);
void bossStatTimeAttackJumpSekiban(s32 a0)
{
    s32 w;
    u8 *e;

    D_401FC730 = a0;
    func_40025E30();
    w = _gameWorkChk(8);
    if (w == D_40130B48) {
        e = D_40130B4C;
    } else {
        D_40130B48 = w;
        if (w == -1) {
            D_40130B4C = 0;
            e = 0;
        } else {
            u8 *t = ((s32)SH_BossStatusDEFAULT != DldSysUndefSymbol) ? SH_BossStatusDEFAULT : 0;
            D_40130B4C = *(u8 **)(t + 0x10) + w * 0xC0;
            e = D_40130B4C;
        }
    }
    setPlayerMaxHp(*(f32 *)(e + 0x9C));
    setPlayerMaxGrip(*(f32 *)(e + 0xA0));
    scriptIntrSignal(ScrIntrDef_JUMP_SEKIBAN);
}

extern u8 *D_40130BB4;
extern s32 ScrIntrDef_JUMP_HOKORA;
extern s32 ScrIntrDef_JUMP_SEKIBAN;
void func_40025FF8();
void setSmallManagerSystemLock();
void func_40025E30();
void windowCloseRequest();
void func_40026648(void)
{
    u8 *p;

    func_40025FF8();
    setSmallManagerSystemLock(1);
    func_40025E30();
    p = D_40130BB4;
    D_40130B54 = 0;
    if (p != 0) {
        windowCloseRequest(*(s32 *)(p + 4));
    }
    scriptIntrSignal(ScrIntrDef_JUMP_HOKORA);
}

void func_40026698(void)
{
    u8 *p;

    func_40025FF8();
    setSmallManagerSystemLock(1);
    func_40025E30();
    p = D_40130BB4;
    D_40130B54 = 0;
    if (p != 0) {
        windowCloseRequest(*(s32 *)(p + 4));
    }
    scriptIntrSignal(ScrIntrDef_JUMP_SEKIBAN);
}

extern s32 D_40130B54;
extern s32 ScrIntrDef_SYSTEM_CONTINUE;
void scriptIntrSignal();
void func_400266E8(void)
{
    if (D_40130B54 != 0) {
        scriptIntrSignal(ScrIntrDef_SYSTEM_CONTINUE);
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0015_bossStatLayoutChk", func_40026720);

extern s32 D_40130BF0;
s32 CheckCamFinalizerReady(void)
{
    return D_40130BF0;
}

void SetCamFinalizerReady(s32 a0)
{
    D_40130BF0 = a0;
}

void *get_main_cameraman();
void *get_game_camera();
void reset_game_camera_standby_flag();
void ResetCamFinalizer(void)
{
    reset_game_camera_standby_flag(get_game_camera(get_main_cameraman()));
}

extern s32 D_40130C30;
void PauseCamFinalizer(s32 a0)
{
    D_40130C30 = a0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0015_bossStatLayoutChk", SetCamFinalizerGeometry);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0015_bossStatLayoutChk", st_camfinalizer);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0015_bossStatLayoutChk", func_400268E8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0015_bossStatLayoutChk", func_40026B10);
