#include "common.h"

extern u8 gcGlobalVar[];
extern u8 D_40201050[];
extern s32 DldSysUndefSymbol;
extern u8 SH_StageDataDEFAULT[];
s32 createScriptObj(void *fn, s32 a1, void *a2, s32 a3, s32 a4, s32 a5, void *a6, s32 a7);
s32 isysAddGroupWithLinkParam(s32 a0, void *a1, s32 a2, s32 a3);
void sheetMgrUnloadSegmentIndex();
void scrRun(void);
void sheetMgrLoadSegmentIndex();
void sheetMgrNopSegmentIndex();
extern u8 rootPtn[];

s32 stagemanager_createsubthread(s32 a0, s32 a1, s32 a2)
{
    s32 r = createScriptObj((void *)a0, a1, *(void **)(gcGlobalVar + 0x308), 0x1000, 0, 1, 0, 0);

    if (a2 != 0)
    {
        isysAddGroupWithLinkParam(r, D_40201050, 0, 0);
    }
    return r;
}

/* NEARMISS-STUB stagemanager_loadstage */
#if 0 /* NEARMISS 0.0% cat=call-abi sub=- | same as unloadstage: gcc emits j createScriptObj (sibcall, frame kept, ld ra early); expected jal + ld ra/jr ra and prologue scheduled after arg loads | attempts=1 */
extern u8 gcGlobalVar[];
s32 createScriptObj(void *fn, s32 a1, void *a2, s32 a3, s32 a4, s32 a5, void *a6, s32 a7);
void func_40041CC8(void);

void stagemanager_loadstage(s32 a0, s32 a1)
{
    createScriptObj((void *)func_40041CC8, (a0 << 16) | a1, *(void **)(gcGlobalVar + 0x308), 0x1000, 0, 1, 0, 0);
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0039_stagemanager_createsubthread", stagemanager_loadstage);

/* NEARMISS-STUB stagemanager_unloadstage */
#if 0 /* NEARMISS 0.0% cat=call-abi sub=- | gcc sibcalls the final createScriptObj as j (frame kept, ld ra early); expected is jal + ld ra/jr ra with prologue scheduled after arg loads; s32/void/K&R calle | attempts=1 */
extern u8 gcGlobalVar[];
s32 createScriptObj();
void func_40041DD8(void);

void stagemanager_unloadstage(s32 a0)
{
    createScriptObj((void *)func_40041DD8, a0, *(void **)(gcGlobalVar + 0x308), 0x1000, 0, 1, 0, 0);
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0039_stagemanager_createsubthread", stagemanager_unloadstage);

/* NEARMISS-STUB stagemanager_getStageNumberWithStageDataStrptr */
#if 0 /* NEARMISS 90.2% cat=branch-layout sub=- | shared zero exit block | attempts=1 */
s32 stagemanager_getStageNumberWithStageDataStrptr(u32 *a0)
{
    u32 a2;
    u32 off;
    u8 *p;
    u8 *q;
    u8 *t;
    s32 e;
    s32 v;

    a2 = *a0;
    off = a2 & 0x3FFFF;
    p = (off != 0) ? *(u8 **)((u8 *)a0 - off) : NULL;
    e = 0;
    if ((s32)p != 0 && (s32)p != DldSysUndefSymbol)
    {
        q = *(u8 **)(p + 8);
        e = *(s32 *)(p + 0x10) + ((a2 >> 18) & 0xFFF) * *(s32 *)(q + 0xC);
    }
    if (e != 0)
    {
        t = (DldSysUndefSymbol != (s32)SH_StageDataDEFAULT) ? SH_StageDataDEFAULT : NULL;
        v = 0;
        if (t != NULL)
        {
            v = *(s32 *)(t + 0x10);
        }
        return ((e - v) >> 2) * -0x33333333;
    }
    return -1;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0039_stagemanager_createsubthread", stagemanager_getStageNumberWithStageDataStrptr);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0039_stagemanager_createsubthread", stagemanager_loadstagecore);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0039_stagemanager_createsubthread", stagemanager_unloadstagecore);
void stagemanager_unloadstagecore(s32 a0)
{
    u8 *t;
    u8 *e;
    s32 r;

    t = (DldSysUndefSymbol != (s32)SH_StageDataDEFAULT) ? SH_StageDataDEFAULT : NULL;
    e = (t != NULL) ? *(u8 **)(t + 0x10) + a0 * 20 : NULL;
    if (--*(u16 *)(e + 0x10) == 0)
    {
        sheetMgrUnloadSegmentIndex(SH_StageDataDEFAULT, a0, &r);
        while ((u32)(r - 0xDEAF) >= 2)
        {
            scrRun();
        }
    }
}

extern s32 D_40131474;

s32 stagemanager_GetStageAlignParam(void)
{
    return D_40131474;
}

extern s32 D_40131478;
extern s32 GetStageContext(void *ctx);
extern s32 getstagenumber(s32 a0);

s32 GetStageNumberNumber(void)
{
    s32 ctx[16];
    s32 r;

    ctx[1] = (s32)(gcGlobalVar + 0x340);
    GetStageContext(ctx);
    r = -1;
    if (D_40131474 != 0 && D_40131478 != 0)
    {
        s32 t = getstagenumber((ctx[8] << 5) | (ctx[9] & 0x1F));
        r = getstagenumber((t << 15) | ((ctx[8] << 5) | (ctx[9] & 0x1F)));
    }
    return r;
}

/* NEARMISS-STUB stagemanager_refleshCurrentArea */
#if 0 /* NEARMISS 74.3% cat=regalloc sub=- | loop-invariant hi halves, frame 0x30 vs 0x20 | attempts=1 */
extern s32 D_40200F88[];
void func_40041BB0(s32 a0);

void stagemanager_refleshCurrentArea(void)
{
    s32 *p;
    s32 v;
    s32 r;

    p = D_40200F88;
    v = *p;
    if (v >= 0)
    {
        do
        {
            p++;
            r = createScriptObj((void *)func_40041BB0, v, *(void **)(gcGlobalVar + 0x308), 0x1000, 0, 1, 0, 0);
            isysAddGroupWithLinkParam(r, D_40201050, 0, 0);
            v = *p;
        } while (v >= 0);
    }
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0039_stagemanager_createsubthread", stagemanager_refleshCurrentArea);

extern void initstage();

void stagemanager_restartstagecore(s32 a0, s32 a1, s32 a2, s32 a3)
{
    initstage(a0, a1, a2, -1, a3, 1);
}

/* NEARMISS-STUB stagemanager_getCenterFromAreaId */
#if 0 /* NEARMISS 74.7% cat=sched sub=- | gcc hoists float const loads above div check | attempts=1 */
void stagemanager_getCenterFromAreaId(f32 *a0, s32 a1)
{
    s32 w;
    s32 h;
    f32 cw;
    f32 ch;

    w = *(s32 *)(D_40131474 + 0x34);
    cw = *(f32 *)(D_40131474 + 0x14);
    a0[1] = 0.0f;
    a0[0] = -((((f32)(a1 % w)) - ((f32)w * 0.5f)) * cw + cw * 0.5f);
    h = *(s32 *)(D_40131474 + 0x38);
    ch = *(f32 *)(D_40131474 + 0x18);
    a0[3] = 1.0f;
    a0[2] = (((f32)(a1 / w)) - ((f32)h * 0.5f)) * ch + ch * 0.5f;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0039_stagemanager_createsubthread", stagemanager_getCenterFromAreaId);

extern s32 D_40131478;

s32 stagemanager_getNbWorldLayoutDatas(void)
{
    if (D_40131474 != 0 && D_40131478 != 0)
    {
        return *(s32 *)(D_40131474 + 0x34) * *(s32 *)(D_40131474 + 0x38);
    }
    return 0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0039_stagemanager_createsubthread", stagemanager_checkstageAlreadyLoadRequested);
u16 stagemanager_checkstageAlreadyLoadRequested(s32 idx)
{
    u8 *t = (DldSysUndefSymbol != (s32)SH_StageDataDEFAULT) ? SH_StageDataDEFAULT : 0;
    u8 *e = (t != 0) ? *(u8 **)(t + 0x10) + idx * 20 : 0;
    return *(u16 *)(e + 0x10);
}

extern s32 sheetMgrChkStageIndexResolve();

void stagemanager_checkstageAlreadyLoaded(void)
{
    sheetMgrChkStageIndexResolve();
}

/* NEARMISS-STUB stagemanager_checkstageAlreadyLoadedByStrptr */
#if 0 /* NEARMISS 86.0% cat=call-abi sub=- | sibcall j vs jal | attempts=1 */
void stagemanager_checkstageAlreadyLoadedByStrptr(u32 *a0)
{
    u32 a2;
    u32 off;
    u8 *p;
    u8 *q;
    u8 *t;
    s32 e;
    s32 v;
    s32 r;

    a2 = *a0;
    off = a2 & 0x3FFFF;
    p = (off != 0) ? *(u8 **)((u8 *)a0 - off) : NULL;
    e = 0;
    if ((s32)p != 0 && (s32)p != DldSysUndefSymbol)
    {
        q = *(u8 **)(p + 8);
        e = *(s32 *)(p + 0x10) + ((a2 >> 18) & 0xFFF) * *(s32 *)(q + 0xC);
    }
    if (e != 0)
    {
        t = (DldSysUndefSymbol != (s32)SH_StageDataDEFAULT) ? SH_StageDataDEFAULT : NULL;
        v = 0;
        if (t != NULL)
        {
            v = *(s32 *)(t + 0x10);
        }
        r = ((e - v) >> 2) * -0x33333333;
    }
    else
    {
        r = -1;
    }
    sheetMgrChkStageIndexResolve(r);
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0039_stagemanager_createsubthread", stagemanager_checkstageAlreadyLoadedByStrptr);

/* NEARMISS-STUB stagemanager_checkstageAlreadyLoadedByStageData */
#if 0 /* NEARMISS 92.0% cat=call-abi sub=- | gcc emits j sheetMgrChkStageIndexResolve (sibcall, frame kept); expected jal with mult in delay slot then ld ra/jr ra; register assignment already matches | attempts=1 */
extern s32 DldSysUndefSymbol;
extern u8 SH_StageDataDEFAULT[];

void stagemanager_checkstageAlreadyLoadedByStageData(s32 a0)
{
    u8 *p;
    s32 v = 0;

    if ((s32)DldSysUndefSymbol == (s32)SH_StageDataDEFAULT)
    {
        p = NULL;
    }
    else
    {
        p = SH_StageDataDEFAULT;
    }
    if (p != NULL)
    {
        v = *(s32 *)(p + 0x10);
    }
    sheetMgrChkStageIndexResolve(((a0 - v) >> 2) * -0x33333333);
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0039_stagemanager_createsubthread", stagemanager_checkstageAlreadyLoadedByStageData);

/* NEARMISS-STUB stagemanager_unloadstageByStrptr */
#if 0 /* NEARMISS 76.59% cat=call-abi sub=- | sibcall j createScriptObj vs jal | attempts=1 */
void func_40041DD8(s32 a0);

void stagemanager_unloadstageByStrptr(u32 *a0)
{
    u32 a2;
    u32 off;
    u8 *p;
    u8 *q;
    u8 *t;
    s32 e;
    s32 v;
    s32 r;

    a2 = *a0;
    off = a2 & 0x3FFFF;
    p = (off != 0) ? *(u8 **)((u8 *)a0 - off) : NULL;
    if ((s32)p != 0 && (s32)p != DldSysUndefSymbol)
    {
        q = *(u8 **)(p + 8);
        e = *(s32 *)(p + 0x10) + ((a2 >> 18) & 0xFFF) * *(s32 *)(q + 0xC);
    }
    else
    {
        e = 0;
    }
    if (e != 0)
    {
        t = (DldSysUndefSymbol != (s32)SH_StageDataDEFAULT) ? SH_StageDataDEFAULT : NULL;
        v = 0;
        if (t != NULL)
        {
            v = *(s32 *)(t + 0x10);
        }
        r = ((e - v) >> 2) * -0x33333333;
    }
    else
    {
        r = -1;
    }
    createScriptObj((void *)func_40041DD8, r, *(void **)(gcGlobalVar + 0x308), 0x1000, 0, 1, 0, 0);
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0039_stagemanager_createsubthread", stagemanager_unloadstageByStrptr);

extern s32 D_40131488;
void func_4003C750(void);

void stagemanager_changeSegmentVariation(s32 a0)
{
    s32 r;

    if (D_40131488 != a0)
    {
        r = createScriptObj((void *)func_4003C750, a0, *(void **)(gcGlobalVar + 0x308), 0x1000, 0, 1, 0, 0);
        isysAddGroupWithLinkParam(r, D_40201050, 0, 0);
        D_40131488 = a0;
    }
}

extern s32 D_40131488;

s32 stagemanager_getSegmentVariation(void)
{
    return D_40131488;
}

void func_4003C750(void);

void FlushStageManager(s32 a0)
{
    s32 r;

    if (D_40131488 != a0)
    {
        r = createScriptObj((void *)func_4003C750, a0, *(void **)(gcGlobalVar + 0x308), 0x1000, 0, 1, 0, 0);
        isysAddGroupWithLinkParam(r, D_40201050, 0, 0);
        D_40131488 = a0;
    }
}

extern s32 D_40131478;

s32 getWorldLayoutHead(void)
{
    return D_40131478;
}

void initStageLayout(void) {
}

void deleteStageLayout(void) {
}

extern s32 D_40131490;

void initWorldLayout(s32 a0)
{
    D_40131490 = a0;
}

void deleteWorldLayout(void)
{
    D_40131490 = 0;
}

/* NEARMISS-STUB initGameObject */
#if 0 /* NEARMISS 86.7% cat=regalloc sub=- | DLD loop reg/lui hoist | attempts=1 */
void gStatSetGObjAdrs(s32 a0, u8 *a1);

void initGameObject(s32 a0)
{
    s32 n;
    u8 *e;
    u8 *f;
    u8 *p;
    u32 a2;
    u32 off;
    u8 *q;
    s32 v;

    n = *(s32 *)(a0 + 0xC);
    e = *(u8 **)(a0 + 0x10);
    if (n > 0)
    {
        do
        {
            f = e + 0x10;
            a2 = *(u32 *)f;
            off = a2 & 0x3FFFF;
            p = (off != 0) ? *(u8 **)(f - off) : NULL;
            v = 0;
            if ((s32)p != 0 && (s32)p != DldSysUndefSymbol)
            {
                q = *(u8 **)(p + 8);
                v = *(s32 *)(p + 0x10) + ((a2 >> 18) & 0xFFF) * *(s32 *)(q + 0xC);
            }
            *(s32 *)(e + 8) = 0;
            if (v != 0)
            {
                gStatSetGObjAdrs(v, e);
            }
            n--;
            e += 0x14;
        } while (n != 0);
    }
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0039_stagemanager_createsubthread", initGameObject);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0039_stagemanager_createsubthread", deleteGameObject);
void unloadObj();
void gStatSetGObjAdrs(u8 *a0, s32 a1);

void deleteGameObject(s32 a0)
{
    s32 n;
    s32 k;
    u8 *e;
    u8 *f;
    u8 *p;
    u32 a2;
    u32 off;
    u8 *q;
    s32 v;

    n = *(s32 *)(a0 + 0xC);
    e = *(u8 **)(a0 + 0x10);
    if (n > 0)
    {
        k = n;
        do
        {
            f = e + 0x10;
            a2 = *(u32 *)f;
            off = a2 & 0x3FFFF;
            p = (off != 0) ? *(u8 **)(f - off) : NULL;
            if ((s32)p != 0 && (s32)p != DldSysUndefSymbol)
            {
                q = *(u8 **)(p + 8);
                v = *(s32 *)(p + 0x10) + ((a2 >> 18) & 0xFFF) * *(s32 *)(q + 0xC);
            }
            else
            {
                v = 0;
            }
            if (*(s32 *)(e + 8) != 0)
            {
                unloadObj(*(s32 *)(e + 8));
                *(s32 *)(e + 8) = 0;
            }
            if (v != 0)
            {
                gStatSetGObjAdrs((u8 *)v, 0);
            }
            k--;
            e += 0x14;
        } while (k != 0);
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0039_stagemanager_createsubthread", func_400417E8);
void func_400417E8(s32 a0)
{
    u8 *t;
    u8 *e;
    s32 r;
    u8 *root;

    root = rootPtn;
    t = (DldSysUndefSymbol != (s32)SH_StageDataDEFAULT) ? SH_StageDataDEFAULT : NULL;
    e = (t != NULL) ? *(u8 **)(t + 0x10) + a0 * 20 : NULL;
    if (++*(u16 *)(e + 0x10) == 1)
    {
        sheetMgrLoadSegmentIndex(SH_StageDataDEFAULT, a0, &r);
        sheetMgrNopSegmentIndex(0);
        while ((u32)(r - 0xDEAF) >= 2)
        {
            scrRun();
        }
        if (r != 0xDEB0)
        {
            initstage(root, a0, -1, -1, 1, 0);
        }
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0039_stagemanager_createsubthread", func_400418F0);
void func_400418F0(s32 a0)
{
    u8 *t;
    u8 *e;
    s32 r;

    t = (DldSysUndefSymbol != (s32)SH_StageDataDEFAULT) ? SH_StageDataDEFAULT : NULL;
    e = (t != NULL) ? *(u8 **)(t + 0x10) + a0 * 20 : NULL;
    if (--*(u16 *)(e + 0x10) == 0)
    {
        sheetMgrUnloadSegmentIndex(SH_StageDataDEFAULT, a0, &r);
        while ((u32)(r - 0xDEAF) >= 2)
        {
            scrRun();
        }
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0039_stagemanager_createsubthread", func_400419B8);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0039_stagemanager_createsubthread", func_40041AE0);
void func_40041AE0(s32 a0)
{
    u8 *t;
    u8 *e;
    s32 r;
    s32 idx;

    idx = (a0 >> 15) & 0x3FFF;
    t = (DldSysUndefSymbol != (s32)SH_StageDataDEFAULT) ? SH_StageDataDEFAULT : NULL;
    e = (t != NULL) ? *(u8 **)(t + 0x10) + idx * 20 : NULL;
    if (--*(u16 *)(e + 0x10) == 0)
    {
        sheetMgrUnloadSegmentIndex(SH_StageDataDEFAULT, idx, &r);
        while ((u32)(r - 0xDEAF) >= 2)
        {
            scrRun();
        }
    }
}

extern void func_4003B908(s32 a0);
extern void func_4003B6D0(s32 a0);
extern void func_4003BB40(s32 a0);
extern void func_4003B350(void);
extern void func_4003C200(s32 a0);

void func_40041BB0(s32 a0)
{
    func_4003B908(a0);
    func_4003B6D0(a0);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0039_stagemanager_createsubthread", func_40041BD8);
void func_40041BD8(s32 a0)
{
    func_4003BB40(a0);
    isysAddGroupWithLinkParam(createScriptObj(func_4003B350, a0, *(void **)(gcGlobalVar + 0x308), 0x1000, 0, 1, 0, 0), D_40201050, 0, 0);
    func_4003B6D0(a0);
    func_4003C200(a0);
}

void func_4003C408(void);
void func_4003B540(void);
void func_4003BCB0(s32 a0);

void func_40041C50(s32 a0)
{
    s32 r;

    func_4003C408();
    func_4003B908(a0);
    r = createScriptObj((void *)func_4003B540, a0, *(void **)(gcGlobalVar + 0x308), 0x1000, 0, 1, 0, 0);
    isysAddGroupWithLinkParam(r, D_40201050, 0, 0);
    func_4003BCB0(a0);
}

/* NEARMISS-STUB func_40041CC8 */
#if 0 /* NEARMISS 81.72% cat=regalloc sub=- | movn base select order | attempts=1 */
void func_40041CC8(s32 a0)
{
    u8 *root;
    u8 *t;
    u8 *e;
    s32 r;
    s32 idx;
    s32 low;

    root = rootPtn;
    idx = a0 >> 16;
    low = a0 & 0xFFFF;
    t = (DldSysUndefSymbol != (s32)SH_StageDataDEFAULT) ? SH_StageDataDEFAULT : NULL;
    e = (t != NULL) ? *(u8 **)(t + 0x10) + idx * 20 : NULL;
    if (++*(u16 *)(e + 0x10) == 1)
    {
        sheetMgrLoadSegmentIndex(SH_StageDataDEFAULT, idx, &r);
        sheetMgrNopSegmentIndex(0);
        while ((u32)(r - 0xDEAF) >= 2)
        {
            scrRun();
        }
        if (r != 0xDEB0)
        {
            initstage(root, idx, low, -1, 1, 0);
        }
    }
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0039_stagemanager_createsubthread", func_40041CC8);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0039_stagemanager_createsubthread", func_40041DD8);
void func_40041DD8(s32 a0)
{
    u8 *t;
    u8 *e;
    s32 r;

    t = (DldSysUndefSymbol != (s32)SH_StageDataDEFAULT) ? SH_StageDataDEFAULT : NULL;
    e = (t != NULL) ? *(u8 **)(t + 0x10) + a0 * 20 : NULL;
    if (--*(u16 *)(e + 0x10) == 0)
    {
        sheetMgrUnloadSegmentIndex(SH_StageDataDEFAULT, a0, &r);
        while ((u32)(r - 0xDEAF) >= 2)
        {
            scrRun();
        }
    }
}
