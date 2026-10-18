#include "common.h"

typedef struct {
    u32 flags;     /* 0x00 */
    s32 unk4;      /* 0x04 busy/refcount */
    s32 age;       /* 0x08 */
    s32 slotClass; /* 0x0C */
    struct {
        s32 vab;   /* 0x10 */
        s32 ch;    /* 0x14 */
        s32 prio;  /* 0x18 */
        s32 group; /* 0x1C */
    } sub;
    struct {
        s32 tick;     /* 0x20 */
        s32 note;     /* 0x24 */
        s32 baseNote; /* 0x28 */
        s32 semi;     /* 0x2C */
    } pit;
    s32 fine;      /* 0x30 */
    s32 masTune;   /* 0x34 */
    s32 masVolL;   /* 0x38 */
    s32 masVolR;   /* 0x3C */
    s32 seMasVol;  /* 0x40 */
    s32 baseVol;   /* 0x44 */
    s32 vol;       /* 0x48 */
    s32 masPan;    /* 0x4C */
    s32 basePan;   /* 0x50 */
    s32 pan;       /* 0x54 */
    s32 bendRange; /* 0x58 */
    s32 bendValue; /* 0x5C */
    s32 ssa;         /* 0x60 */
    u16 adsr1;       /* 0x64 */
    u16 adsr2;       /* 0x66 */
    s32 hwVoiceL;    /* 0x68 */
    s32 hwVoiceR;    /* 0x6C */
    s32 directPitch; /* 0x70 */
    s16 volPhase[2]; /* 0x74 */
    s32 lfoPitchSpeed; /* 0x78 */
    s32 lfoPitchDepth; /* 0x7C */
    union {
        struct {
            s32 lfoPitchPhase;
            s32 lfoPitchTbl;
        } f;
        struct {
            s32 phase;
            s32 tbl;
            s32 cur;
            s32 end;
        } lp;
    } u80; /* 0x80 */
    s32 lfoVolSpeed; /* 0x90 */
    s32 lfoVolDepth; /* 0x94 */
    u8 pad98[4];
    s32 lfoVolTbl;   /* 0x9C */
    struct {
        s32 cur; /* 0xA0 */
        s32 end; /* 0xA4 */
        f32 b;   /* 0xA8 */
        f32 a;   /* 0xAC */
    } tv;
    struct {
        f32 x;   /* 0xB0 */
        f32 b;   /* 0xB4 */
        f32 a;   /* 0xB8 */
    } tp;
    f32 padBC;
    struct {
        f32 b;   /* 0xC0 */
        f32 a;   /* 0xC4 */
    } tq;
    f32 padC8;
    s32 polStart;  /* 0xCC */
    s32 polCur;    /* 0xD0 */
    s32 polTarget; /* 0xD4 */
    f32 polStep;   /* 0xD8 */
    s32 polCnt;    /* 0xDC */
} Sg2Slot; /* size 0xE0 */

extern Sg2Slot D_401117B0[];
extern s32 D_401117A0;
typedef struct {
    s32 v;
    u8 pad[0xDC];
} Sg2SlotWord;

extern Sg2SlotWord D_401117CC[];
extern Sg2SlotWord D_401117F8[];
extern Sg2SlotWord D_40111804[];
extern Sg2SlotWord D_40111808[];
extern Sg2SlotWord D_40111810[];
extern Sg2SlotWord D_401117B4[];
extern void Sg2RemoteSend(s32, s32, s32, s32);
extern s32 D_401117A4;
extern s32 D_401117A8;
extern s32 D_401117AC;
extern u32 D_40111770[];
extern u32 D_40111778[];
extern u32 D_40111780[];
extern u32 D_40111790[];
extern s32 D_40111788[];
extern s32 D_40111798[];
extern u8 D_40046398[];
s32 Sg2CtrlEntryTickProcById(s32 id, void (*proc)(void));
void Sg2SlotTickProc(void);
s32 DIntr();
s32 EIntr();

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

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotBlock);
void Sg2SlotBlock(s32 kind, s32 idx)
{
    s32 age = D_401117A0;
    D_401117B0[idx].flags = 0;
    D_401117B0[idx].unk4 = kind;
    D_401117B0[idx].slotClass = D_401117B0[idx].sub.ch = D_401117B0[idx].sub.prio = -1;
    D_401117B0[idx].age = age;
    D_401117A0 = age + 1;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotFree);
void Sg2SlotFree(s32 idx)
{
    if (D_401117B0[idx].unk4 > 0)
    {
        D_401117B0[idx].unk4 = 0;
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotCheckSlotClass);
s32 Sg2SlotCheckSlotClass(s32 slotClass)
{
    s32 found = 0;
    s32 i;
    Sg2Slot *slot = D_401117B0;
    for (i = 0; i < 0x30; i++, slot++)
    {
        if (slot->flags & 1)
        {
            if (slot->slotClass == slotClass)
            {
                found = 1;
                break;
            }
        }
    }
    return found;
}

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

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotFindVab);
s32 Sg2SlotFindVab(s32 *out, s32 vab)
{
    s32 n = 0;
    s32 i;
    for (i = 0; i < 0x30; i++)
    {
        if (D_401117B0[i].flags & 1)
        {
            if (D_401117B0[i].sub.vab == vab)
            {
                *out++ = i;
                n++;
            }
        }
    }
    return n;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotFindVabCh);
s32 Sg2SlotFindVabCh(s32 *out, s32 vab, s32 ch)
{
    s32 n = 0;
    s32 i;
    for (i = 0; i < 0x30; i++)
    {
        if (D_401117B0[i].flags & 1)
        {
            if (D_401117B0[i].sub.vab == vab && D_401117B0[i].sub.ch == ch)
            {
                *out++ = i;
                n++;
            }
        }
    }
    return n;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotFindVabChNote);
s32 Sg2SlotFindVabChNote(s32 *out, s32 vab, s32 ch, s32 note)
{
    s32 n = 0;
    s32 i;
    Sg2Slot *slot = D_401117B0;
    for (i = 0; i < 0x30; i++, slot++)
    {
        if (slot->flags & 1)
        {
            if (slot->sub.vab == vab && slot->sub.ch == ch && slot->pit.note == note)
            {
                *out++ = i;
                n++;
            }
        }
    }
    return n;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotFindVabChSsaBaseNote);
s32 Sg2SlotFindVabChSsaBaseNote(s32 *out, s32 vab, s32 ch, s32 ssa, s32 baseNote)
{
    s32 n = 0;
    s32 i;
    Sg2Slot *slot = D_401117B0;
    for (i = 0; i < 0x30; i++, slot++)
    {
        if (slot->flags & 1)
        {
            if (slot->sub.vab == vab && slot->sub.ch == ch && slot->ssa == ssa && slot->pit.baseNote == baseNote)
            {
                *out++ = i;
                n++;
            }
        }
    }
    return n;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotFindSlotClass);
s32 Sg2SlotFindSlotClass(s32 *out, s32 slotClass)
{
    s32 n = 0;
    s32 i;
    for (i = 0; i < 0x30; i++)
    {
        if (D_401117B0[i].flags & 1)
        {
            if (D_401117B0[i].slotClass == slotClass)
            {
                *out++ = i;
                n++;
            }
        }
    }
    return n;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotFindSlotClassCh);
s32 Sg2SlotFindSlotClassCh(s32 *out, s32 slotClass, s32 ch)
{
    s32 n = 0;
    s32 i;
    for (i = 0; i < 0x30; i++)
    {
        if (D_401117B0[i].flags & 1)
        {
            if (D_401117B0[i].slotClass == slotClass && D_401117B0[i].sub.ch == ch)
            {
                *out++ = i;
                n++;
            }
        }
    }
    return n;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotFindSlotClassChNote);
s32 Sg2SlotFindSlotClassChNote(s32 *out, s32 slotClass, s32 ch, s32 note)
{
    s32 n = 0;
    s32 i;
    Sg2Slot *slot = D_401117B0;
    for (i = 0; i < 0x30; i++, slot++)
    {
        if (slot->flags & 1)
        {
            if (slot->slotClass == slotClass && slot->sub.ch == ch && slot->pit.note == note)
            {
                *out++ = i;
                n++;
            }
        }
    }
    return n;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotFindSlotClassChSsaBaseNote);
s32 Sg2SlotFindSlotClassChSsaBaseNote(s32 *out, s32 slotClass, s32 ch, s32 ssa, s32 baseNote)
{
    s32 n = 0;
    s32 i;
    Sg2Slot *slot = D_401117B0;
    for (i = 0; i < 0x30; i++, slot++)
    {
        if (slot->flags & 1)
        {
            if (slot->slotClass == slotClass && slot->sub.ch == ch && slot->ssa == ssa && slot->pit.baseNote == baseNote)
            {
                *out++ = i;
                n++;
            }
        }
    }
    return n;
}

void Sg2SlotSetReverbOffBit(s32 idx, u32 mask);
void Sg2SlotSetNoiseOffBit(s32 idx, u32 mask);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetBasicParam);
void Sg2SlotSetBasicParam(s32 kind, s32 idx, s32 slotClass, s32 vab, s32 ch, s32 prio)
{
    s32 age = D_401117A0;
    D_401117B0[idx].flags = 1;
    D_401117B0[idx].unk4 = kind;
    D_401117B0[idx].slotClass = slotClass;
    D_401117B0[idx].sub.vab = vab;
    D_401117B0[idx].sub.ch = ch;
    D_401117B0[idx].sub.prio = prio;
    D_401117B0[idx].age = age;
    D_401117A0 = age + 1;
    Sg2SlotSetReverbOffBit(idx >= 0x18, idx < 0x18 ? 1 << idx : 1 << (idx - 0x18));
    Sg2SlotSetNoiseOffBit(idx >= 0x18, idx < 0x18 ? 1 << idx : 1 << (idx - 0x18));
}

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

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetMute);
void Sg2SlotSetMute(s32 idx, s32 on)
{
    if (on)
    {
        D_401117B0[idx].flags |= 0x8000;
    }
    else
    {
        D_401117B0[idx].flags &= ~0x8000;
    }
    D_401117B0[idx].flags |= 0x1000;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetMasVol);
void Sg2SlotSetMasVol(s32 i, s32 L, s32 R)
{
    D_401117B0[i].masVolL = L;
    D_401117B0[i].masVolR = R;
    if (D_401117B0[i].hwVoiceL != -1 && D_401117B0[i].hwVoiceR != -1)
    {
        D_401117B0[i].flags |= 0x1000;
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetSeMasVol);
void Sg2SlotSetSeMasVol(s32 idx, s32 v)
{
    D_401117B0[idx].seMasVol = v;
    if (D_401117B0[idx].hwVoiceL != -1 && D_401117B0[idx].hwVoiceR != -1)
    {
        D_401117B0[idx].flags |= 0x1000;
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetBaseVol);
void Sg2SlotSetBaseVol(s32 idx, s32 v)
{
    D_401117B0[idx].baseVol = v;
    if (D_401117B0[idx].hwVoiceL != -1 && D_401117B0[idx].hwVoiceR != -1)
    {
        D_401117B0[idx].flags |= 0x1000;
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetVol);
void Sg2SlotSetVol(s32 idx, s32 v)
{
    D_401117B0[idx].vol = v;
    D_401117B0[idx].flags |= 0x1000;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetMasPan);
void Sg2SlotSetMasPan(s32 idx, s32 v)
{
    D_401117B0[idx].masPan = v;
    if (D_401117B0[idx].hwVoiceL != -1 && D_401117B0[idx].hwVoiceR != -1)
    {
        D_401117B0[idx].flags |= 0x2000;
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetBasePan);
void Sg2SlotSetBasePan(s32 idx, s32 v)
{
    D_401117B0[idx].basePan = v;
    if (D_401117B0[idx].hwVoiceL != -1 && D_401117B0[idx].hwVoiceR != -1)
    {
        D_401117B0[idx].flags |= 0x2000;
    }
}

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

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetPitch);
void Sg2SlotSetPitch(s32 idx, s32 note, s32 semi, s32 baseNote, s32 fine, s32 direct)
{
    s32 a, b, c, q, r, f;
    D_401117B0[idx].pit.note = note;
    D_401117B0[idx].pit.semi = semi;
    D_401117B0[idx].pit.baseNote = baseNote;
    D_401117B0[idx].fine = fine;
    D_401117B0[idx].directPitch = direct;
    q = semi / 12;
    r = semi % 12;
    f = r * 4 / 3;
    D_401117B0[idx].flags |= 0x80;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetPause);
void Sg2SlotSetPause(s32 idx, s32 on)
{
    if (on)
    {
        D_401117B0[idx].flags |= 0x4000;
    }
    else
    {
        D_401117B0[idx].flags &= ~0x4000;
    }
    D_401117B0[idx].flags |= 0x80;
}

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

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetAdsr);
typedef struct {
    s32 hdr;
    u16 adsr1; /* 0x04 */
    u16 adsr2; /* 0x06 */
} Sg2SlotAdsrView;

void Sg2SlotSetAdsr(s32 idx, s32 adsr1, s32 adsr2)
{
    Sg2SlotAdsrView *slot = (Sg2SlotAdsrView *)&D_40111810[idx];
    u16 a1 = adsr1;
    u16 a2 = adsr2;
    slot->adsr1 = a1;
    slot->adsr2 = a2;
    Sg2RemoteSend(2, idx, a1, a2);
}

void Sg2SlotSetVolPhase(s32 s, s32 a, s32 b)
{
    D_401117B0[s].volPhase[0] = a;
    D_401117B0[s].volPhase[1] = b;
    D_401117B0[s].flags |= 0x100;
}

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

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetLfoPitchTbl);
void Sg2SlotSetLfoPitchTbl(s32 i, s32 tbl)
{
    if (tbl != 0)
    {
        (&D_401117B0[i])->u80.f.lfoPitchTbl = tbl;
        D_401117B0[i].u80.lp.cur = tbl;
        D_401117B0[i].u80.lp.end = tbl + 0x3C;
    }
}

/* NEARMISS-STUB Sg2SlotSetLfoPitchSpeed */
#if 0 /* NEARMISS 95.76% cat=regalloc sub=- | target copies v to a2 at entry, a1 as i*7 temp | attempts=1 */
// kR38 best 95.76 (not matched; repair attempt). slot.c reverted to INCLUDE_ASM.
// Tried: (v1) kR23 variant, v reused as speed -> 95.76 ; (v2) Sg2Slot *s = &D_401117B0[i] -> 64.67 (worse) ;
// (v3) s32 sp = v local, kR18-style if (sp != 0) -> 95.76 ; (v4) s32 sp; sp = v; if (sp) -> 95.76.
// Residual (all variants): target copies v into a2 at entry (daddu a2,a1,zero) and reuses a1 as i*7 temp;
// ours keeps v in a1 and allocates i*0xE0 to a6/a4 differently. Needs a source shape that makes gcc 2.96 copy the arg.
void Sg2SlotSetLfoPitchSpeed(s32 i, s32 v)
{
    if (v != 0)
    {
        v = 0xF0 / (0x3C - (v * 58) / 0x7F);
    }
    D_401117B0[i].lfoPitchSpeed = v;
    D_401117B0[i].u80.f.lfoPitchPhase = 0;
    if (v != 0 && D_401117B0[i].lfoPitchDepth != 0)
    {
        D_401117B0[i].flags |= 0x400;
    }
    else
    {
        D_401117B0[i].flags &= ~0x400;
    }
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetLfoPitchSpeed);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetLfoPitchDepth);
void Sg2SlotSetLfoPitchDepth(s32 i, s32 v)
{
    s32 d;
    if (v != 0)
    {
        d = (D_401117B0[i].unk4 == 1) ? v * 2 : v;
    }
    else
    {
        d = 0;
    }
    D_401117B0[i].lfoPitchDepth = d;
    if (v != 0 && D_401117B0[i].lfoPitchSpeed != 0)
    {
        D_401117B0[i].flags |= 0x400;
    }
    else
    {
        D_401117B0[i].flags &= ~0x400;
    }
}

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

/* NEARMISS-STUB Sg2SlotSetLfoVolSpeed */
#if 0 /* NEARMISS 94.4% cat=struct-layout sub=- | target hi(D_40111840) no addend, ours D_401117B0+0x90; needs u32 lfoVol fields | attempts=1 */
/* kR38 repair: best C 94.40% (same as kR23). Needs u32 lfoVolSpeed/u32 lfoVolDepth in Sg2Slot (0x90/0x94) - reverted, slot.c left INCLUDE_ASM.
 Residual: target stores via separate symbol D_40111840 (offset 0, no addend); ours emits D_401117B0+0x90 (addend).
 Tried (all worse): A) extern u32 D_40111840[] + D_40111840[i*56] -> 77.3; B) swap flag-test order -> 75.9; C) extern s32 D_40111840 + *(u32*)((u8*)&D_40111840 + i*0xE0) -> 77.3.
 Notes: never got the lui %hi(D_40111840) reloc with the struct-based code. */
void Sg2SlotSetLfoVolSpeed(s32 i, s32 v)
{
    f32 f;
    if (v != 0)
    {
        f = v;
        f = f / 6.35f;
    }
    else
    {
        f = 0.0f;
    }
    D_401117B0[i].lfoVolSpeed = (u32)f;
    if (f != 0.0 && (f32)D_401117B0[i].lfoVolDepth != 0.0f)
    {
        D_401117B0[i].flags |= 0x800;
    }
    else
    {
        D_401117B0[i].flags &= ~0x800;
    }
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetLfoVolSpeed);

/* NEARMISS-STUB Sg2SlotSetLfoVolDepth */
#if 0 /* NEARMISS 94.27% cat=struct-layout sub=- | target stores via separate symbol D_40111844 (no addend); needs u32 lfoVol fields | attempts=1 */
/* kR38 best C: 94.27% (identical to kR23). REQUIRES struct fields u32 lfoVolSpeed/u32 lfoVolDepth in slot.c Sg2Slot (0x90/0x94).
 Residual: target stores via separate symbol D_40111844 (offset 0, stride 0xE0). Tried: extern s32 D_40111844 + ((Sg2SlotWord*)&D_40111844)[i].v -> 76.8;
 extern Sg2SlotWord D_40111844[] + [i].v with s32 fields -> 70.3. Both worse. Left INCLUDE_ASM. */

void Sg2SlotSetLfoVolDepth(s32 i, s32 v)
{
    f32 f;
    if (v != 0)
    {
        f = v;
        f = f / 127.0f;
    }
    else
    {
        f = 0.0f;
    }
    D_401117B0[i].lfoVolDepth = (u32)f;
    if (f != 0.0 && (f32)D_401117B0[i].lfoVolSpeed != 0.0f)
    {
        D_401117B0[i].flags |= 0x800;
    }
    else
    {
        D_401117B0[i].flags &= ~0x800;
    }
}
#endif
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

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetPoltamentParam);
void Sg2SlotSetPoltamentParam(s32 idx, s32 target, f32 step)
{
    Sg2Slot *slot = &D_401117B0[idx];
    if (!(slot->flags & 0x200))
    {
        slot->flags |= 0x200;
        slot->polCnt = 0;
        slot->polStart = slot->pit.note;
        slot->polCur = slot->pit.note;
    }
    slot->polTarget = target;
    if (target < slot->polCur)
    {
        step = -step;
    }
    slot->polStep = step;
}

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

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetDumperOff);
void Sg2SlotSetDumperOff(s32 slotClass, s32 ch)
{
    s32 st;
    s32 i;
    st = DIntr();
    for (i = 0; i < 0x30; i++)
    {
        if ((D_401117B0[i].flags & 1) && (D_401117B0[i].flags & 8) && D_401117B0[i].slotClass == slotClass && D_401117B0[i].sub.ch == ch)
        {
            D_401117B0[i].flags &= ~8;
            D_40111778[i < 0x18 ? 0 : 1] |= (i < 0x18) ? (1 << i) : (1 << (i - 0x18));
        }
    }
    if (st)
    {
        EIntr();
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotModKeyOff);
void Sg2SlotModKeyOff(s32 slotClass, s32 ch, s32 note)
{
    s32 st;
    s32 i;
    st = DIntr();
    for (i = 0; i < 0x30; i++)
    {
        if (D_401117B0[i].flags & 1)
        {
            if (D_401117B0[i].slotClass == slotClass && D_401117B0[i].sub.ch == ch && D_401117B0[i].pit.note == note)
            {
                D_401117B0[i].flags &= ~8;
                D_40111778[i < 0x18 ? 0 : 1] |= (i < 0x18) ? (1 << i) : (1 << (i - 0x18));
            }
        }
    }
    if (st)
    {
        EIntr();
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotVabKeyOff);
void Sg2SlotVabKeyOff(s32 vab, s32 ch, s32 note)
{
    s32 st;
    s32 i;
    st = DIntr();
    for (i = 0; i < 0x30; i++)
    {
        if (D_401117B0[i].flags & 1)
        {
            if (D_401117B0[i].sub.vab == vab && D_401117B0[i].sub.ch == ch && D_401117B0[i].pit.note == note)
            {
                D_401117B0[i].flags &= ~8;
                D_40111778[i < 0x18 ? 0 : 1] |= (i < 0x18) ? (1 << i) : (1 << (i - 0x18));
            }
        }
    }
    if (st)
    {
        EIntr();
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotVabKeyOffGroup);
void Sg2SlotVabKeyOffGroup(s32 vab, s32 group)
{
    s32 st;
    s32 i;
    st = DIntr();
    for (i = 0; i < 0x30; i++)
    {
        if (D_401117B0[i].flags & 1)
        {
            if (D_401117B0[i].sub.vab == vab && D_401117B0[i].sub.group == group)
            {
                Sg2SlotSetAdsr(i, 0, 8);
                D_40111778[i < 0x18 ? 0 : 1] |= (i < 0x18) ? (1 << i) : (1 << (i - 0x18));
                D_401117B0[i].sub.group = -1;
            }
        }
    }
    if (st)
    {
        EIntr();
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetKeyOnBit);
void Sg2SlotSetKeyOnBit(s32 idx, u32 mask)
{
    s32 intr = DIntr();
    D_40111770[idx] |= mask;
    if (intr)
    {
        EIntr();
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetKeyOffBit);
void Sg2SlotSetKeyOffBit(s32 idx, u32 mask)
{
    s32 intr = DIntr();
    D_40111778[idx] |= mask;
    if (intr)
    {
        EIntr();
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetReverbOnBit);
void Sg2SlotSetReverbOnBit(s32 idx, u32 mask)
{
    s32 intr = DIntr();
    D_40111790[idx] |= mask;
    if (intr)
    {
        EIntr();
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetReverbOffBit);
void Sg2SlotSetReverbOffBit(s32 idx, u32 mask)
{
    s32 intr = DIntr();
    D_40111790[idx] &= ~mask;
    if (intr)
    {
        EIntr();
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetNoiseOnBit);
void Sg2SlotSetNoiseOnBit(s32 idx, u32 mask)
{
    s32 intr = DIntr();
    D_40111780[idx] |= mask;
    if (intr)
    {
        EIntr();
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotSetNoiseOffBit);
void Sg2SlotSetNoiseOffBit(s32 idx, u32 mask)
{
    s32 intr = DIntr();
    D_40111780[idx] &= ~mask;
    if (intr)
    {
        EIntr();
    }
}

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

/* NEARMISS-STUB Sg2SlotInit */
#if 0 /* NEARMISS 91.55% cat=cse-hoist sub=- | float zero stores sw zero vs mtc1/swc1, [1] globals hoisted before [0], loop bias 0x70 vs 0x94 | attempts=1 */
// kR38 repair of kR33/kR23 Sg2SlotInit. Best = kR23 body (no helper), 91.55%. Not matched; slot.c restored to INCLUDE_ASM.
// Tried: kR33 helper variant 90.76 (repro); pointer walk count-up 87.19; pointer walk count-down 86.96; shared f32 zero local 91.55 (no change).
s32 Sg2SlotInit(void)
{
    s32 i;
    s32 tbl;
    tbl = (s32)D_40046398;
    D_401117A8 = 2;
    D_401117AC = 1;
    D_40111788[0] = -1;
    D_40111778[0] = 0xFFFFFF;
    D_401117A0 = 0;
    D_401117A4 = 0;
    D_40111790[0] = 0;
    D_40111780[0] = 0;
    D_40111798[0] = -1;
    D_40111770[0] = 0;
    D_40111790[1] = 0;
    D_40111780[1] = 0;
    D_40111798[1] = -1;
    D_40111788[1] = -1;
    D_40111770[1] = 0;
    D_40111778[1] = 0xFFFFFF;
    for (i = 0; i < 0x30; i++)
    {
        D_401117B0[i].flags = 0;
        D_401117B0[i].age = 0;
        D_401117B0[i].unk4 = 0;
        D_401117B0[i].pit.tick = 0;
        D_401117B0[i].sub.group = -1;
        D_401117B0[i].sub.prio = -1;
        D_401117B0[i].masVolR = 0x7F;
        D_401117B0[i].masVolL = 0x7F;
        D_401117B0[i].baseVol = 0x7F;
        D_401117B0[i].seMasVol = 0x7F;
        D_401117B0[i].basePan = 0x40;
        D_401117B0[i].masPan = 0x40;
        D_401117B0[i].pan = -1;
        D_401117B0[i].vol = -1;
        D_401117B0[i].directPitch = 0x1000;
        D_401117B0[i].masTune = 0x1000;
        D_401117B0[i].fine = 0;
        D_401117B0[i].bendRange = 0;
        D_401117B0[i].bendValue = 0x40;
        D_401117B0[i].volPhase1 = 1;
        D_401117B0[i].volPhase0 = 1;
        D_401117B0[i].u80.lp.cur = tbl;
        D_401117B0[i].u80.lp.tbl = tbl;
        D_401117B0[i].u80.lp.end = tbl + 0x3C;
        D_401117B0[i].lfoPitchSpeed = 0;
        D_401117B0[i].lfoVolDepth = 0;
        D_401117B0[i].lfoVolSpeed = 0;
        D_401117B0[i].lfoVolTbl = tbl;
        D_401117B0[i].tv.cur = tbl;
        D_401117B0[i].tv.end = tbl + 0x3C;
        D_401117B0[i].hwVoiceL = -1;
        D_401117B0[i].hwVoiceR = -1;
        D_401117B0[i].polTarget = -1;
        D_401117B0[i].polCur = -1;
        D_401117B0[i].polStart = -1;
        D_401117B0[i].tp.x = 0.0f;
        D_401117B0[i].padBC = 0.0f;
        D_401117B0[i].padC8 = 0.0f;
        D_401117B0[i].polStep = 0.0f;
        *(f32 *)&D_401117B0[i].polCnt = 0.0f;
    }
    Sg2CtrlEntryTickProcById(3, Sg2SlotTickProc);
    return 0;
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotInit);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotTbl);
void Sg2SlotTbl(s32 idx, char *out)
{
    s32 n = 0;
    s32 k;
    s8 c;

    for (k = idx * 24; k < idx * 24 + 24; k++) {
        c = '-';
        if (D_401117B4[k].v != 0) {
            c = *(u8 *)&D_401117B4[k].v + 0x30;
        }
        out[n++] = c;
        if (k != 0 && k != 24 && k % 4 == 3) {
            out[n++] = ' ';
        }
    }
    out[n] = 0;
}

extern u8 D_40049260;
extern char D_40049268[];
extern char D_40049270[];
extern s32 Sg2RemoteGetSlotReleaseLv(s32);
s32 sprintf(char *, const char *, ...);
char *strcat(char *, const char *);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/slot", Sg2SlotEnvTbl);
void Sg2SlotEnvTbl(char *out)
{
    char buf[16];
    s32 i = 0;
    s32 rel;

    out[0] = D_40049260;
    for (i = 0; i < 48; i++) {
        rel = Sg2RemoteGetSlotReleaseLv(i);
        sprintf(buf, D_40049268, rel);
        if ((i + 1) % 12 == 0) {
            strcat(buf, D_40049270);
        }
        strcat(out, buf);
    }
}
