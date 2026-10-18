#include "common.h"

extern s32 DldSysUndefSymbol;
static inline u8 *dldElem(u32 *lp) {
    u8 *slot;
    u32 w = *lp;
    u32 off = w & 0x3FFFF;

    slot = off ? *(u8 **)((u8 *)lp - off) : NULL;
    return (slot != NULL && slot != (u8 *)DldSysUndefSymbol)
               ? *(u8 **)(slot + 0x10) + ((w >> 18) & 0xFFF) * *(s32 *)(*(u8 **)(slot + 8) + 0xC)
               : NULL;
}
extern u8 SH_BossStatusDEFAULT[];
extern u8 SH_GameObjectStatusDEFAULT[];
extern s32 D_401FC730;
extern u8 D_401FC528[];
typedef struct { s32 b[0x93]; } BSBlk;
extern BSBlk D_401FC4E0;
void _gameFlagCls();
void _gameFlagSet();
void _gameWorkSet();
void setBossClearCnt();
void func_40025BC0();
void SCRSetDispFlag();
s32 _gameFlagChk();
void addPlayerMaxHp(f32 v);
void addPlayerMaxGrip(f32 v);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0014_backStageCheckPointLoad", backStageCheckPointLoad);
void backStageCheckPointLoad(BSBlk *a0)
{
    D_401FC4E0 = *a0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0014_backStageCheckPointLoad", backStageGetBossSaveArea);
u8 *backStageGetBossSaveArea(void)
{
    return D_401FC528;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0014_backStageCheckPointLoad", backStageInit);
void backStageInit(void)
{
    s32 *p = (s32 *)&D_401FC4E0;

    p[0] = -1;
    p[0x24 / 4] = -1;
    p[0x48 / 4] = -1;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0014_backStageCheckPointLoad", bossStatSetActiveBoss);

/* NEARMISS-STUB bossStatGetFromIconGObj */
#if 0 /* NEARMISS 92.5% cat=branch-layout sub=- | 3 return-e sites emitted as separate trampolines (ours b epilogue per site, orig shares .L400256E0 block with sw found); 2nd dldElem uses beqzl in ours vs beqz+ | attempts=1 */
extern u8 gcGlobalVar[];
u8 *SCRGetFirstObj(void *table);
u8 *GetLayoutClass(s32 obj);
s32 GetStageAreaNumberByPos();
u8 *bossStatGetFromIconGObj(s32 flag, s32 *idx, s32 *found)
{
    u8 *t;
    u8 *e;
    s32 n;
    s32 stage;
    u8 b;

    t = ((s32)SH_BossStatusDEFAULT != DldSysUndefSymbol) ? SH_BossStatusDEFAULT : 0;
    e = *(u8 **)(t + 0x10);
    stage = GetStageAreaNumberByPos(*(s32 *)(GetLayoutClass((s32)SCRGetFirstObj(gcGlobalVar + 0x2B0)) + 0x134));
    n = *(s32 *)(t + 0xC);
    *found = 0;
    *idx = 0;
    if (n > 0) {
        do {
            if (flag == 0) {
                b = e[0x41];
            } else {
                if ((s32)dldElem((u32 *)(e + 0x28)) == flag) {
                    return e;
                }
                if ((s32)dldElem((u32 *)(e + 0x2C)) == flag) {
                    return e;
                }
                b = e[0x41];
            }
            if (stage == b) {
                *found = 1;
                return e;
            }
            e += 0xC0;
            *idx = *idx + 1;
        } while (*idx < n);
    }
    *idx = -1;
    return NULL;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0014_backStageCheckPointLoad", bossStatGetFromIconGObj);

/* NEARMISS-STUB func_40025858 */
#if 0 /* NEARMISS 52.6% cat=vu0-mmi sub=- | VU0 lqc2/vadd.xyz/sqc2 vector add (no C form) + unaligned ldl/ldr/sdl/sdr 12-byte struct copies; C emits scalar adds and frame 0x70 vs 0x90 | attempts=1 */
extern s32 DldSysUndefSymbol;
extern u8 SH_BossStatusDEFAULT[];
extern s32 D_40130B48;
extern s32 D_40130B4C;
void *memset(void *p, s32 c, u32 n);
void YattsukeGetSeamlessAreaCenter(void *out, u8 idx);
void gStatCheckPointSave(void);
void gStatChekcPointSaveHookPlayerHorsePos(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);
s32 _gameWorkChk(s32 n);
void _gameFlagSet(s32 idx);
void _gameFlagCls(s32 idx);
void func_40025858(void)
{
    s32 iVar1;
    u8 *pcVar2;
    u8 *s3;
    f32 a[4];
    f32 b[4];
    f32 c[4];
    f32 d[4];
    f32 e[4];

    iVar1 = _gameWorkChk(8);
    if (iVar1 != D_40130B48) {
        D_40130B48 = iVar1;
        if (iVar1 == -1) {
            D_40130B4C = 0;
        } else {
            pcVar2 = SH_BossStatusDEFAULT;
            if (DldSysUndefSymbol == (s32)SH_BossStatusDEFAULT) {
                pcVar2 = NULL;
            }
            D_40130B4C = *(s32 *)(pcVar2 + 0x10) + iVar1 * 0xc0;
        }
    }
    s3 = (u8 *)D_40130B4C;
    if (s3 == NULL) {
        gStatCheckPointSave();
        return;
    }
    memset(a, 0, 16);
    a[0] = -*(f32 *)(s3 + 0x44);
    a[1] = *(f32 *)(s3 + 0x48);
    a[2] = -*(f32 *)(s3 + 0x4C);
    *(u64 *)e = *(u64 *)a;
    *(u64 *)(e + 2) = *(u64 *)(a + 2);
    *(s32 *)(b) = 0;
    b[1] = *(f32 *)(s3 + 0x50);
    *(s32 *)(b + 2) = 0;
    *(u64 *)a = *(u64 *)b;
    *(s32 *)(a + 2) = *(s32 *)(b + 2);
    memset(c, 0, 16);
    c[0] = -*(f32 *)(s3 + 0x54);
    c[1] = *(f32 *)(s3 + 0x58);
    *(u64 *)d = *(u64 *)c;
    c[2] = -*(f32 *)(s3 + 0x5C);
    *(u64 *)(d + 2) = *(u64 *)(c + 2);
    *(s32 *)(c) = 0;
    c[1] = *(f32 *)(s3 + 0x60);
    YattsukeGetSeamlessAreaCenter(e, *(u8 *)(s3 + 0x41));
    _gameFlagSet(0x1D);
    gStatChekcPointSaveHookPlayerHorsePos((s32)e, (s32)a, (s32)d, (s32)b, *(u8 *)(s3 + 0x42));
    _gameFlagCls(0x1D);
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0014_backStageCheckPointLoad", func_40025858);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0014_backStageCheckPointLoad", bossStatInitCloudLayout);
void bossStatInitCloudLayout(void)
{
    u8 *t;
    u8 *e;
    s32 n;
    s32 i;

    t = ((s32)SH_BossStatusDEFAULT != DldSysUndefSymbol) ? SH_BossStatusDEFAULT : 0;
    n = *(s32 *)(t + 0xC);
    e = *(u8 **)(t + 0x10);
    if (n > 0) {
        i = n;
        do {
            u8 *a = dldElem((u32 *)(e + 0x10));

            if (a != NULL) {
                u8 *l = dldElem((u32 *)(a + 4));

                if (_gameFlagChk(*(s32 *)(e + 0x18))) {
                    SCRSetDispFlag(*(s32 *)(l + 0x8), 0);
                } else {
                    SCRSetDispFlag(*(s32 *)(l + 0x8), 1);
                }
            }
            i--;
            e += 0xC0;
        } while (i != 0);
    }
}

/* NEARMISS-STUB func_40025BC0 */
#if 0 /* NEARMISS 87.2% cat=uncategorized sub=- | one pass: stride-0x14 loop with slot/undef gate and +0xBC store; diff not inspected | attempts=1 */
static inline u8 *dldSlot(u32 *lp)
{
    u32 w = *lp;
    u32 off = w & 0x3FFFF;
    u8 *slot = off ? *(u8 **)((u8 *)lp - off) : NULL;

    return (slot != NULL && slot != (u8 *)DldSysUndefSymbol) ? slot : NULL;
}
void func_40025BC0(u8 *a0)
{
    s32 i = 0;
    u8 *e = *(u8 **)(a0 + 0x10);
    s32 n = *(s32 *)(a0 + 0xC);

    for (; i < n; i++, e += 0x14) {
        u8 *slot = dldSlot((u32 *)e);
        u8 *l;

        if ((s32)SH_BossStatusDEFAULT == DldSysUndefSymbol) {
            if (slot != NULL) {
                continue;
            }
        } else {
            if (slot != (u8 *)SH_BossStatusDEFAULT) {
                continue;
            }
        }
        l = dldElem((u32 *)e);
        if (*(s32 *)(e + 4) == 0x303) {
            *(u8 **)(l + 0xBC) = e;
            _gameFlagSet(*(s32 *)(l + 0x18));
        }
    }
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0014_backStageCheckPointLoad", func_40025BC0);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0014_backStageCheckPointLoad", bossStatInit);
void bossStatInit(void)
{
    u8 *t;
    u8 *e;
    s32 i = 0;

    func_40025BC0(((s32)SH_GameObjectStatusDEFAULT != DldSysUndefSymbol) ? SH_GameObjectStatusDEFAULT : 0);
    _gameWorkSet(8, -1);
    t = ((s32)SH_BossStatusDEFAULT != DldSysUndefSymbol) ? SH_BossStatusDEFAULT : 0;
    e = *(u8 **)(t + 0x10);
    if (*(s32 *)(t + 0xC) > 0) {
        do {
            u8 *l;
            s32 f;

            l = dldElem((u32 *)(e + 0x24));
            f = *(s32 *)(l + 0xC);
            if (0 == (s32)e) {
                _gameFlagCls(f);
            } else {
                _gameFlagSet(f);
            }
            i++;
            e += 0xC0;
        } while (i < *(s32 *)(t + 0xC));
    }
    setBossClearCnt(0);
}

/* NEARMISS-STUB func_40025E30 */
#if 0 /* NEARMISS 71.3% cat=regalloc sub=- | asm hoists lui of DldSysUndefSymbol/SH_BossStatusDEFAULT/D_401FC730 into s5-s7 and keeps base in s2, i in s1; ours re-materialises lui per use and puts base in  | attempts=1 */
extern s32 D_40130B50;
extern s32 D_401FC72C;
void bossStatSetActiveBoss(u8 *p);

void func_40025E30(void)
{
    u8 *t;
    u8 *base;
    u8 *p;
    u8 *l;
    s32 n;
    s32 i;
    s32 k;

    t = ((s32)SH_BossStatusDEFAULT != DldSysUndefSymbol) ? SH_BossStatusDEFAULT : 0;
    n = *(s32 *)(t + 0xC);
    base = *(u8 **)(t + 0x10);
    i = 0;
    if (D_401FC730 > 0) {
        p = base;
        D_40130B50 = (s32)p;
        do {
            i++;
            _gameFlagCls(*(s32 *)(p + 0x18));
            p += 0xC0;
            if (i < D_401FC730) {
                D_40130B50 = (s32)p;
            }
        } while (i < D_401FC730);
    }
    if (i < n) {
        p = base + i * 0xC0 + 0x18;
        k = n - i;
        do {
            _gameFlagSet(*(s32 *)p);
            p += 0xC0;
            k--;
        } while (k != 0);
    }
    t = ((s32)SH_BossStatusDEFAULT != DldSysUndefSymbol) ? SH_BossStatusDEFAULT : 0;
    n = *(s32 *)(t + 0xC);
    i = 0;
    if (n > 0) {
        p = *(u8 **)(t + 0x10);
        do {
            l = dldElem((u32 *)(p + 0x24));
            if (p != NULL) {
                _gameFlagSet(*(s32 *)(l + 0xC));
            } else {
                _gameFlagCls(*(s32 *)(l + 0xC));
            }
            i++;
            p += 0xC0;
        } while (i < *(s32 *)(t + 0xC));
    }
    base += D_401FC730 * 0xC0;
    D_401FC72C = (s32)base;
    bossStatSetActiveBoss(base);
    return;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0014_backStageCheckPointLoad", func_40025E30);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0014_backStageCheckPointLoad", func_40025FF8);
void func_40025FF8(void)
{
    u8 *t = ((s32)SH_BossStatusDEFAULT != DldSysUndefSymbol) ? SH_BossStatusDEFAULT : 0;
    u8 *arr = *(u8 **)(t + 0x10);
    u8 *e;
    s32 n;
    s32 i;

    if (*(s32 *)(t + 0xC) > 0) {
        n = *(s32 *)(t + 0xC);
        e = arr;
        do {
            if (_gameFlagChk(*(s32 *)(e + 0x18)) == 0) {
                addPlayerMaxHp(-*(f32 *)(e + 0x94));
                addPlayerMaxGrip(-*(f32 *)(e + 0x98));
            }
            e += 0xC0;
            n--;
        } while (n != 0);
    }
    i = 0;
    if (D_401FC730 > 0) {
        e = arr;
        do {
            addPlayerMaxHp(*(f32 *)(e + 0x94));
            addPlayerMaxGrip(*(f32 *)(e + 0x98));
            e += 0xC0;
            i++;
        } while (i < D_401FC730);
    }
}
