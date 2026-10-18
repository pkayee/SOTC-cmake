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
extern s32 opFlag;
extern s32 ScrIntrDef_GAME_NEWSTART;
extern s32 ScrIntrDef_GAME_LOADSTART;
extern s32 D_40130F30;
extern s32 D_40130F38;
void *isysGetThisSubThread();
void scrInit();
void scriptIntrEntryJump();
void scrRun();
extern s32 opFlag;
extern f32 D_40200F18;
extern s32 D_40200F10;
extern s32 opflowMcBootLoadedOptionData;
extern s32 D_40200F1C;
s32 getOptionDataAdrsAndSize();
s32 memcmp(const void *a, const void *b, u32 n);
extern s32 D_40200F14;
void *isysGetThisSubThread();
void scrInit();
s32 spriteMenuObjPadChangeHorse();
extern s32 checkPointChangeHorse;

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0027_opflowOp1End", opflowOp1End);
extern s32 opFlag;
void opflowOp1End(void)
{
    opFlag |= 0x11;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0027_opflowOp1End", opflowOp2Start);
void opflowOp2Start(void)
{
    opFlag |= 2;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0027_opflowOp1End", opflowOp2End);
void opflowOp2End(s32 a0)
{
    opFlag = ((opFlag | 4) & ~8) | ((a0 & 1) << 3);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0027_opflowOp1End", opflowChkTitleDemoStart);
extern s32 opFlag;
s32 opflowChkTitleDemoStart(void)
{
    return ((u32)opFlag >> 4) & 1;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0027_opflowOp1End", opflowTitleDmoeEnd);
void opflowTitleDmoeEnd(void)
{
    opFlag |= 0x20;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0027_opflowOp1End", opflowSetDemoFrame);
extern f32 D_40200F18;
void opflowSetDemoFrame(f32 f)
{
    D_40200F18 = f / 30.0f;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0027_opflowOp1End", opflowChkAbort);
extern s32 D_40200F10;
s32 opflowChkAbort(void)
{
    return D_40200F10 != 0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0027_opflowOp1End", opflowChkLoadStart);
s32 opflowChkLoadStart(void)
{
    return D_40200F10 == 2;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0027_opflowOp1End", opflowCompareOptionData);
extern s32 opflowMcBootLoadedOptionData;
extern s32 D_40200F1C;
s32 getOptionDataAdrsAndSize();
s32 memcmp(const void *a, const void *b, u32 n);
s32 opflowCompareOptionData(void)
{
    s32 size[4];
    s32 p = getOptionDataAdrsAndSize(size);

    if (opflowMcBootLoadedOptionData == 0) {
        return memcmp((void *)D_40200F1C, (void *)p, size[0]);
    }
    return 1;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0027_opflowOp1End", func_40032988);
extern s32 D_40200F14;
void *isysGetThisSubThread();
void scrInit();
s32 spriteMenuObjPadChangeHorse();
void func_40032988(void)
{
    scrInit(isysGetThisSubThread());
    D_40200F10 = 1;
    D_40200F14 = spriteMenuObjPadChangeHorse();
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0027_opflowOp1End", func_400329C8);
extern s32 checkPointChangeHorse;
void func_400329C8(void)
{
    scrInit(isysGetThisSubThread());
    D_40200F10 = 2;
    checkPointChangeHorse = spriteMenuObjPadChangeHorse();
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0027_opflowOp1End", func_40032A08);
extern s32 ScrIntrDef_GAME_NEWSTART;
extern s32 ScrIntrDef_GAME_LOADSTART;
extern s32 D_40130F30;
extern s32 D_40130F38;
void *isysGetThisSubThread();
void scrInit();
void scriptIntrEntryJump();
void scrRun();
void func_40032A08(void)
{
    void *s = isysGetThisSubThread();

    scrInit(s);
    scriptIntrEntryJump(ScrIntrDef_GAME_NEWSTART, s, &D_40130F30);
    scriptIntrEntryJump(ScrIntrDef_GAME_LOADSTART, s, &D_40130F38);
    for (;;) {
        scrRun();
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0027_opflowOp1End", func_40032A68);
void func_40032A68(s32 a0, s32 a1, s32 a2, s32 *a3, s32 *t0)
{
    *t0 = 1;
    *a3 = -2;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0027_opflowOp1End", updatePowerWork);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0027_opflowOp1End", chkMotionList);
s32 chkMotionList(u8 *obj, u8 *list)
{
    s32 n = *(s32 *)(list + 0xC);
    u32 *p = *(u32 **)(list + 0x10);
    s32 i;

    for (i = 0; i < n; i++, p++) {
        if (obj == dldElem(p)) {
            return 1;
        }
    }
    return 0;
}
