#include "common.h"
extern u8 gcGlobalVar[];
extern s32 D_40130EF0;
extern s32 D_40130EF8;
extern u8 D_40200E70[];
extern s32 gstatTimeAttackMode;
extern u8 D_401FD1D0[];
extern u8 D_40200DF0[];
extern s32 *D_40130EE4;
extern s32 *D_40130EE8;
typedef struct { s32 pad0; s32 pad4; s32 gflag; s32 adrs; u32 on:1; u32 inv:1; } GObj;
typedef struct { s32 id; s32 flag; s32 idx; u8 pad[4]; s32 omake; } HorseEnt;
extern struct { u8 pad[0xC]; s32 num; HorseEnt *ent; } SH_HorseTypeDEFAULT;
typedef struct { u8 b0; s8 placeId; u8 pad[0x42]; } SavePointEnt;
extern struct { u8 pad[0xC]; s32 num; SavePointEnt *ent; } SH_SavePointDEFAULT;
extern s32 D_40130EF4;
extern s32 D_40130EEC;
extern s32 rootPtn;
extern s32 vschedGameTime;
typedef struct { u8 b[0x70]; } __attribute__((aligned(8))) OmakeStat;
void *func_unused;
s32 getGameClearCnt(void);
void iosGetClock(void *p);
s32 getSavedPlaceId(void);
s32 mcWrite(s32 slot, void *buf, s32 size);
s32 mcRead(s32 slot, void *buf, s32 size);
void setSavedClock(void *p);
void setSavedGameTime(s32 t);
void stagemanager_unloadstagecore(s32 n);
void stagemanager_restartstagecore(void *root, s32 a, s32 b, s32 c);
void func_4002E650(s32 flag);
extern s32 D_40130ED8;
extern s32 D_40130EDC;
extern s32 D_40130EE0;
extern u8 D_40130E98[];
void stagemanager_loadstagecore(void *root, s32 a, s32 b, s32 c);
void gStatLoadPlayerAccessories(void);
void _omakeSelectFlagSet(s32 idx);
void _omakeSelectFlagCls(s32 idx);
static inline HorseEnt *findHorseEnt(void)
{
    HorseEnt *q = SH_HorseTypeDEFAULT.ent;
    HorseEnt *base = q;
    s32 n = SH_HorseTypeDEFAULT.num;
    s32 i = 0;
    n--;
    q++;
    for (; i < n; i++, q++) {
        if (_omakeSelectFlagChk(q->flag) != 0) {
            return q;
        }
    }
    return base;
}
void omakeStatInit(s32 a, void *b, s32 c);
void gameFlowInit_unused(void);
void gameFlagInit(void);
void bossStatInit(void);
void backStageInit(void);
void time_attack_init_gstat_adrs(void);
s32 _gameFlagCls(s32 idx);
void _gameFlagSet(s32 idx);
s32 _gameFlagChk(s32 idx);
s32 _omakeSelectFlagChk(s32 idx);
void gameFlagCheckPointSave(void *a, void *b, void *c, void *d, void *e, void *f);
void backStageCheckPointSave(void *a);
void *getSprLogWorkAddress(void);
s32 getSprLogWorkSize(void);
void *getSprLogStatusAddress(void);
s32 getSprLogStatusSize(void);
void *memcpy(void *d, const void *s, unsigned n);
void SetTimeAttackTimeFlag(s32 a);

void func_4002E650(s32 flag)
{
    if (flag != 0) {
        s32 a = D_40130EF8;
        u8 *b = (D_40130EF0 != 0) ? D_40200E70 : 0;
        omakeStatInit(a, b, 0);
    }
    gameFlagInit();
    bossStatInit();
    backStageInit();
    time_attack_init_gstat_adrs();
    if (gstatTimeAttackMode == 0) {
        _gameFlagCls(0x1C);
        gameFlagCheckPointSave(D_401FD1D0, D_401FD1D0 + 0x64, D_401FD1D0 + 0x1F4, D_401FD1D0 + 0x384, D_401FD1D0 + 0x6A4, D_401FD1D0 + 0x3C20);
        backStageCheckPointSave(D_401FD1D0 + 0x9C4);
        memcpy(D_401FD1D0 + 0xC10, getSprLogWorkAddress(), getSprLogWorkSize());
        memcpy(D_401FD1D0 + 0x3C10, getSprLogStatusAddress(), getSprLogStatusSize());
        D_401FD1D0[0x3C1C] = 0;
    }
}

/* NEARMISS-STUB gStatChekcPointSaveHookPlayerHorsePos */
#if 0 /* NEARMISS 99.78% cat=regalloc sub=- | gstatTimeAttackMode addr lui in v0 vs expected v1 (hoisted lui in beqz delay slot) | attempts=1 */
void *SCRGetFirstObj(void *p);
void *GetLayoutClass(void *o);
void SaveLayoutObjGroupAllGeo(void);
void backStageGobjSaveWithPos(s32 a, s32 b, s32 c);

void *gStatChekcPointSaveHookPlayerHorsePos(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4)
{
    void *first = SCRGetFirstObj(gcGlobalVar + 0x2B0);
    void *second = SCRGetFirstObj(gcGlobalVar + 0x2B4);
    void *pvVar2;
    s32 has;
    SaveLayoutObjGroupAllGeo();
    backStageGobjSaveWithPos(*(s32 *)((u8 *)GetLayoutClass(first) + 0x1A4), a0, a1);
    if (second != 0 && a2 != 0) {
        backStageGobjSaveWithPos(*(s32 *)((u8 *)GetLayoutClass(second) + 0x1A4), a2, a3);
    }
    has = second != 0;
    pvVar2 = (void *)gstatTimeAttackMode;
    if (gstatTimeAttackMode == 0) {
        if (has == 0) {
            _gameFlagSet(0x1C);
        } else {
            _gameFlagCls(0x1C);
        }
        gameFlagCheckPointSave(D_401FD1D0, D_401FD1D0 + 0x64, D_401FD1D0 + 0x1F4, D_401FD1D0 + 0x384, D_401FD1D0 + 0x6A4, D_401FD1D0 + 0x3C20);
        backStageCheckPointSave(D_401FD1D0 + 0x9C4);
        memcpy(D_401FD1D0 + 0xC10, getSprLogWorkAddress(), getSprLogWorkSize());
        pvVar2 = memcpy(D_401FD1D0 + 0x3C10, getSprLogStatusAddress(), getSprLogStatusSize());
        D_401FD1D0[0x3C1C] = a4;
    }
    return pvVar2;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0023_func_4002E650", gStatChekcPointSaveHookPlayerHorsePos);

SavePointEnt *gStatPlaceIdToSavePoint(s32 id)
{
    s32 i;
    s32 n = SH_SavePointDEFAULT.num;
    SavePointEnt *p = SH_SavePointDEFAULT.ent;
    for (i = 0; i < n; i++, p++) {
        if (p->placeId == id) {
            return p;
        }
    }
    return 0;
}

s32 gStatMcSave(s32 slot)
{
    s32 t = vschedGameTime;
    u64 clock;
    s32 r;
    iosGetClock(&clock);
    D_401FD1D0[0x3C20] = getSavedPlaceId();
    *(u64 *)(D_401FD1D0 + 0x3C48) = clock;
    *(s32 *)(D_401FD1D0 + 0x3C34) = t;
    r = mcWrite(slot, D_401FD1D0, 0x3C90);
    if (r == 0) {
        setSavedClock(&clock);
        setSavedGameTime(t);
    }
    return r;
}

s32 gStatMcLoad(s32 slot)
{
    s32 r = mcRead(slot, D_401FD1D0, 0x3C90);
    if (r == 0) {
        vschedGameTime = *(s32 *)(D_401FD1D0 + 0x3C34);
        setSavedClock(D_401FD1D0 + 0x3C48);
    }
    return r;
}

u8 *gStatGetOmakeStatAdrs(void)
{
    return D_40200DF0;
}

s32 gStatSaveDataGameFlagChk(s32 idx)
{
    return (D_401FD1D0[idx / 8] >> (idx & 7)) & 1;
}

void gStatGObjDispOn(u8 *obj)
{
    *(u32 *)(obj + 0x10) |= 1;
}

void gStatGObjDispOff(u8 *obj)
{
    *(u32 *)(obj + 0x10) &= ~1;
}

s32 gStatGObjDispChk(u8 *obj)
{
    return *(u32 *)(obj + 0x10) & 1;
}

s32 gStatGobjDispGflagChk(u8 *obj)
{
    if (*(s32 *)(obj + 8) == 0) {
        return 0;
    }
    if (((*(u32 *)(obj + 0x10) >> 1) & 1) == 0) {
        return _gameFlagChk(*(s32 *)(obj + 8));
    }
    return _gameFlagChk(*(s32 *)(obj + 8)) == 0;
}

void gStatGobjDispGflagSet(u8 *obj)
{
    if (*(s32 *)(obj + 8) != 0) {
        if (((*(u32 *)(obj + 0x10) >> 1) & 1) == 0) {
            _gameFlagSet(*(s32 *)(obj + 8));
        } else {
            _gameFlagCls(*(s32 *)(obj + 8));
        }
    }
}

void gStatGobjDispGflagCls(GObj *obj)
{
    if (obj->gflag != 0) {
        if (obj->inv == 1) {
            _gameFlagSet(obj->gflag);
        } else {
            _gameFlagCls(obj->gflag);
        }
    }
}

void gStatSetGObjAdrs(u8 *obj, s32 v)
{
    *(s32 *)(obj + 0xC) = v;
}

s32 gStatGetGObjAdrs(u8 *obj)
{
    return *(s32 *)(obj + 0xC);
}

void gStatStartTimeAttack(void)
{
    gstatTimeAttackMode = 2;
    SetTimeAttackTimeFlag(1);
}

void gStatStopTimeAttack(void)
{
    gstatTimeAttackMode = 3;
    SetTimeAttackTimeFlag(0);
}

f32 gStatGetPlayerAccessoriesDamgeRaitoToPlayer(void)
{
    f32 a = 1.0f;
    f32 r;
    if (D_40130EE4 != 0) {
        a = *(f32 *)((u8 *)D_40130EE4 + 8);
    }
    r = a;
    if (D_40130EE8 != 0) {
        r = r * *(f32 *)((u8 *)D_40130EE8 + 8);
    }
    return r;
}

f32 gStatGetPlayerAccessoriesDamgeRaitoToBoss(void)
{
    f32 a = 1.0f;
    f32 r;
    if (D_40130EE4 != 0) {
        a = *(f32 *)((u8 *)D_40130EE4 + 0xC);
    }
    r = a;
    if (D_40130EE8 != 0) {
        r = r * *(f32 *)((u8 *)D_40130EE8 + 0xC);
    }
    return r;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0023_func_4002E650", gStatLoadPlayerChara);

void gStatUnloadPlayerChara(void)
{
    if (D_40130EE4[1] != 0) {
        stagemanager_unloadstagecore(D_40130EE4[1]);
    }
    D_40130EE4 = (s32 *)D_40130E98;
    if (D_40130EE8[1] != 0) {
        stagemanager_unloadstagecore(D_40130EE8[1]);
    }
    D_40130EE8 = 0;
    if (D_40130EDC != 0) {
        stagemanager_unloadstagecore(D_40130EDC);
        D_40130EDC = 0;
    }
    if (D_40130EE0 != 0) {
        stagemanager_unloadstagecore(D_40130EE0);
        D_40130EE0 = 0;
    }
    if (D_40130ED8 != 0) {
        stagemanager_unloadstagecore(D_40130ED8);
    }
    D_40130ED8 = 0;
}

s32 gStatGetHorseDemoStageIndex(void)
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
    return p->idx;
}

extern s32 DldSysUndefSymbol;

s32 gStatGetHorseDemoISYSObj(void)
{
    u8 *lp = (u8 *)findHorseEnt() + 0xC;
    u32 link = *(u32 *)lp;
    s32 off = link & 0x3FFFF;
    u8 *slot;
    u8 *elem;
    if (off != 0) {
        slot = *(u8 **)(lp - off);
    } else {
        slot = 0;
    }
    if (slot != 0 && slot != (u8 *)DldSysUndefSymbol) {
        elem = *(u8 **)(slot + 0x10) + ((link >> 18) & 0xFFF) * *(s32 *)(*(u8 **)(slot + 8) + 0xC);
    } else {
        elem = 0;
    }
    return elem != 0 ? *(s32 *)(elem + 8) : 0;
}

void gStatLoadHorseChara(s32 a)
{
    s32 id = findHorseEnt()->id;
    if (D_40130EEC != 0) {
        if (id == D_40130EEC) {
            goto reload;
        }
        stagemanager_unloadstagecore(D_40130EEC);
    }
    if (id != 0) {
        stagemanager_loadstagecore(&rootPtn, id, a, 0);
    }
reload:
    D_40130EEC = findHorseEnt()->id;
}

void gStatUnloadHorseChara(void)
{
    s32 *p = &D_40130EEC;
    if (*p != 0) {
        stagemanager_unloadstagecore(*p);
    }
    *p = 0;
}

void gStatRestartHorseChara(void)
{
    if (D_40130EEC != 0) {
        stagemanager_restartstagecore(&rootPtn, D_40130EEC, -1, 0);
    }
}

void gStatLoadAdvertiseHorseChara(void)
{
    _omakeSelectFlagSet(findHorseEnt()->omake);
}

void gStatUnloadAdvertiseHorseChara(void)
{
    HorseEnt *p = findHorseEnt();
    if (p->omake != 0) {
        _omakeSelectFlagSet(p->omake);
    } else {
        _omakeSelectFlagCls(p->flag);
    }
}

void gStatInit(void)
{
    func_4002E650(1);
}

void gStatInitNotOmakeInit(void)
{
    func_4002E650(0);
}

s32 gstatBootMcChkExistNicoData(s32 *p)
{
    if (*p != 0) {
        *p = D_40130EF4;
    }
    return D_40130EF0;
}

void gstatBootMcSetExistNicoData(s32 a, s32 b)
{
    D_40130EF0 = a;
    D_40130EF4 = b;
}

void gstatBootMcSetLastSaveOmakeStat(OmakeStat *src)
{
    *(OmakeStat *)D_40200E70 = *src;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0023_func_4002E650", gstatBootMcCurSetLastSaveOmakeStat);

void gstatBootMcSetExistIcoData(s32 v)
{
    D_40130EF8 = v;
}

s32 gstatBootMcChkExistIcoData(void)
{
    return D_40130EF8;
}

