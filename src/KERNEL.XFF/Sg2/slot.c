#include "common.h"

typedef struct {
    u32 flags;     /* 0x00 */
    s32 unk4;      /* 0x04 busy/refcount */
    u8 pad8[0x14];
    s32 group;     /* 0x1C */
    u8 pad20[0x14];
    s32 masTune;   /* 0x34 */
    u8 pad38[0x10];
    s32 vol;       /* 0x48 */
    u8 pad4C[8];
    s32 pan;       /* 0x54 */
    s32 bendRange; /* 0x58 */
    s32 bendValue; /* 0x5C */
    u8 pad60[0x10];
    s32 directPitch; /* 0x70 */
    s16 volPhase0; /* 0x74 */
    s16 volPhase1; /* 0x76 */
    u8 pad78[8];
    s32 lfoPitchPhase; /* 0x80 */
    s32 lfoPitchTbl;   /* 0x84 */
    s32 lfoPitchCur;   /* 0x88 */
    s32 lfoPitchEnd;   /* 0x8C */
    u8 pad90[0xC];
    s32 lfoVolTbl;   /* 0x9C */
    struct {
        s32 cur; /* 0xA0 */
        s32 end; /* 0xA4 */
        f32 b;   /* 0xA8 */
        f32 a;   /* 0xAC */
    } tv;
    struct {
        s32 x;   /* 0xB0 */
        f32 b;   /* 0xB4 */
        f32 a;   /* 0xB8 */
    } tp;
    u8 padBC[4];
    struct {
        f32 b;   /* 0xC0 */
        f32 a;   /* 0xC4 */
    } tq;
    u8 padC8[0x18];
} Sg2Slot; /* size 0xE0 */

extern Sg2Slot D_401117B0[];
typedef struct {
    s32 v;
    u8 pad[0xDC];
} Sg2SlotWord;

extern Sg2SlotWord D_401117CC[];
extern Sg2SlotWord D_401117F8[];
extern Sg2SlotWord D_40111804[];
extern Sg2SlotWord D_40111808[];
extern Sg2SlotWord D_40111810[];
extern void Sg2RemoteSend(s32, s32, s32, s32);
extern s32 D_401117A4;
extern s32 D_401117A8;
extern s32 D_401117AC;

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotGetSlotClassIdx);
s32 Sg2SlotGetSlotClassIdx(void)
{
    return D_401117A4++;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotFreeSearch);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotFreeSearchTerm);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSearchPriority);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSearchPriorityOlder);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSearchParam);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSearchParamOlder0);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSearchParamOlder1);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSearchTypeOlder);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotBlock);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotFree);
void Sg2SlotFree(s32 idx)
{
    if (D_401117B0[idx].unk4 > 0)
    {
        D_401117B0[idx].unk4 = 0;
    }
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotCheckSlotClass);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotFindLoop);
s32 Sg2SlotFindLoop(s32 *out)
{
    s32 n = 0;
    s32 i;
    for (i = 0; i < 0x30; i++)
    {
        if (D_401117B0[i].flags & 4)
        {
            *out++ = i;
            n++;
        }
    }
    return n;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotFindVab);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotFindVabCh);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotFindVabChNote);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotFindVabChSsaBaseNote);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotFindSlotClass);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotFindSlotClassCh);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotFindSlotClassChNote);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotFindSlotClassChSsaBaseNote);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetBasicParam);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetSsa);
void Sg2SlotSetSsa(s32 idx, s32 ssa)
{
    D_40111810[idx].v = ssa;
    Sg2RemoteSend(3, idx, ssa, 0);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetGroup);
void Sg2SlotSetGroup(s32 idx, s32 v)
{
    D_401117CC[idx].v = v;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetMute);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetMasVol);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetSeMasVol);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetBaseVol);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetVol);
void Sg2SlotSetVol(s32 idx, s32 v)
{
    D_401117B0[idx].vol = v;
    D_401117B0[idx].flags |= 0x1000;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetMasPan);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetBasePan);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetPan);
void Sg2SlotSetPan(s32 idx, s32 v)
{
    D_401117B0[idx].pan = v;
    D_401117B0[idx].flags |= 0x2000;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetBendRange);
void Sg2SlotSetBendRange(s32 idx, s32 v)
{
    D_40111808[idx].v = v;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetBendValue);
void Sg2SlotSetBendValue(s32 idx, s32 v)
{
    D_401117B0[idx].bendValue = v;
    D_401117B0[idx].flags |= 0x80;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetPitch);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetPause);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetDirectPitch);
void Sg2SlotSetDirectPitch(s32 idx, s32 v)
{
    D_401117B0[idx].directPitch = v;
    D_401117B0[idx].flags |= 0x80;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetMasTune);
void Sg2SlotSetMasTune(s32 idx, s32 v)
{
    D_401117B0[idx].masTune = v;
    D_401117B0[idx].flags |= 0x80;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetAdsr);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetVolPhase);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetLoop);
void Sg2SlotSetLoop(s32 idx)
{
    D_401117B0[idx].flags |= 4;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetDumperOn);
void Sg2SlotSetDumperOn(s32 idx)
{
    D_401117B0[idx].flags |= 8;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetLfoPitchTbl);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetLfoPitchSpeed);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetLfoPitchDepth);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetLfoVolTbl);
void Sg2SlotSetLfoVolTbl(s32 idx, s32 tbl)
{
    if (tbl != 0)
    {
        D_401117B0[idx].lfoVolTbl = tbl;
        D_401117B0[idx].tv.cur = tbl;
        D_401117B0[idx].tv.end = tbl + 0x3C;
    }
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetLfoVolSpeed);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetLfoVolDepth);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetTimeVolParam);
void Sg2SlotSetTimeVolParam(s32 idx, f32 a, f32 b)
{
    D_401117B0[idx].tv.a = a;
    D_401117B0[idx].tv.b = b;
    D_401117B0[idx].flags |= 0x20;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetTimePitchParam);
void Sg2SlotSetTimePitchParam(s32 idx, f32 a, f32 b)
{
    D_401117B0[idx].tq.a = a;
    D_401117B0[idx].tq.b = b;
    D_401117B0[idx].flags |= 0x10;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetTimePanParam);
void Sg2SlotSetTimePanParam(s32 idx, f32 a, f32 b)
{
    D_401117B0[idx].tp.a = a;
    D_401117B0[idx].tp.b = b;
    D_401117B0[idx].flags |= 0x40;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetPoltamentParam);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotGetVol);
s32 Sg2SlotGetVol(s32 idx)
{
    return D_401117F8[idx].v;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotGetPan);
s32 Sg2SlotGetPan(s32 idx)
{
    return D_40111804[idx].v;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetDumperOff);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotModKeyOff);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotVabKeyOff);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotVabKeyOffGroup);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetKeyOnBit);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetKeyOffBit);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetReverbOnBit);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetReverbOffBit);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetNoiseOnBit);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetNoiseOffBit);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetOutputMode);
s32 Sg2SlotSetOutputMode(s32 mode)
{
    s32 old = D_401117A8;
    D_401117A8 = mode;
    return old;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetVolShiftDownParam);
s32 Sg2SlotSetVolShiftDownParam(s32 v)
{
    s32 old = D_401117AC;
    D_401117AC = v;
    return old;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotGetVolShiftDownParam);
s32 Sg2SlotGetVolShiftDownParam(void)
{
    return D_401117AC;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotTickProc);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotInit);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotTbl);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotEnvTbl);
