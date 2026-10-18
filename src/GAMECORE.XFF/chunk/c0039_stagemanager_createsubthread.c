#include "common.h"

extern u8 gcGlobalVar[];
extern u8 D_40201050[];
s32 createScriptObj(void *fn, s32 a1, void *a2, s32 a3, s32 a4, s32 a5, void *a6, s32 a7);
void isysAddGroupWithLinkParam(s32 a0, void *a1, s32 a2, s32 a3);

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

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0039_stagemanager_createsubthread", stagemanager_getStageNumberWithStageDataStrptr);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0039_stagemanager_createsubthread", stagemanager_loadstagecore);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0039_stagemanager_createsubthread", stagemanager_unloadstagecore);

extern s32 D_40131474;

s32 stagemanager_GetStageAlignParam(void)
{
    return D_40131474;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0039_stagemanager_createsubthread", GetStageNumberNumber);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0039_stagemanager_createsubthread", stagemanager_refleshCurrentArea);

extern void initstage();

void stagemanager_restartstagecore(s32 a0, s32 a1, s32 a2, s32 a3)
{
    initstage(a0, a1, a2, -1, a3, 1);
}

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

/* NEARMISS-STUB stagemanager_checkstageAlreadyLoadRequested */
#if 0 /* NEARMISS 96.2% cat=regalloc sub=- | p and DLD value swapped between v1/a1 (expected p in v1, DLD in a1); scaled index kept in v1 not a0; branch layout matches | attempts=1 */
extern s32 DldSysUndefSymbol;
extern u8 SH_StageDataDEFAULT[];

u16 stagemanager_checkstageAlreadyLoadRequested(s32 a0)
{
    u8 *p = SH_StageDataDEFAULT;
    s32 v;

    if ((s32)SH_StageDataDEFAULT == DldSysUndefSymbol)
    {
        p = NULL;
    }
    if (p != NULL)
    {
        v = *(s32 *)(p + 0x10) + a0 * 0x14;
    }
    else
    {
        v = 0;
    }
    return *(u16 *)(v + 0x10);
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0039_stagemanager_createsubthread", stagemanager_checkstageAlreadyLoadRequested);

extern s32 sheetMgrChkStageIndexResolve();

void stagemanager_checkstageAlreadyLoaded(void)
{
    sheetMgrChkStageIndexResolve();
}

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

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0039_stagemanager_createsubthread", stagemanager_unloadstageByStrptr);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0039_stagemanager_createsubthread", stagemanager_changeSegmentVariation);

extern s32 D_40131488;

s32 stagemanager_getSegmentVariation(void)
{
    return D_40131488;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0039_stagemanager_createsubthread", FlushStageManager);

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

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0039_stagemanager_createsubthread", initGameObject);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0039_stagemanager_createsubthread", deleteGameObject);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0039_stagemanager_createsubthread", func_400417E8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0039_stagemanager_createsubthread", func_400418F0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0039_stagemanager_createsubthread", func_400419B8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0039_stagemanager_createsubthread", func_40041AE0);

extern void func_4003B908(s32 a0);
extern void func_4003B6D0(s32 a0);

void func_40041BB0(s32 a0)
{
    func_4003B908(a0);
    func_4003B6D0(a0);
}

/* NEARMISS-STUB func_40041BD8 */
#if 0 /* NEARMISS 92.6% cat=sched sub=- | return value move into a0 scheduled before the a1/a2/a3 arg loads; expected puts 'daddu a0,v0' in the isysAddGroupWithLinkParam jal delay slot (K&R decl did not | attempts=1 */
void func_4003BB40(void);
void func_4003B350(void);
void func_4003C200(s32 a0);

void func_40041BD8(s32 a0)
{
    s32 r;

    func_4003BB40();
    r = createScriptObj((void *)func_4003B350, a0, *(void **)(gcGlobalVar + 0x308), 0x1000, 0, 1, 0, 0);
    isysAddGroupWithLinkParam(r, D_40201050, 0, 0);
    func_4003B6D0(a0);
    func_4003C200(a0);
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0039_stagemanager_createsubthread", func_40041BD8);

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

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0039_stagemanager_createsubthread", func_40041CC8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0039_stagemanager_createsubthread", func_40041DD8);
