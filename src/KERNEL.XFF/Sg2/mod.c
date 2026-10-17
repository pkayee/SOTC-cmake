#include "common.h"

typedef struct Sg2ModUnit {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ u8 unk14[0x18 - 0x14];
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 unk1C[0x34 - 0x1C];
    /* 0x34 */ s32 unk34;
    /* 0x38 */ s32 unk38;
    /* 0x3C */ u8 unk3C[0x4C - 0x3C];
    /* 0x4C */ void *unk4C;
    /* 0x50 */ s32 unk50;
    /* 0x54 */ void *unk54;
    /* 0x58 */ s32 unk58;
    /* 0x5C */ s32 unk5C;
    /* 0x60 */ u8 unk60[0x9B0 - 0x60];
} Sg2ModUnit;

typedef struct Sg2ModTrack {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ u8 unkC[4];
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ u8 unk18[4];
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ u8 unk24[8];
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ s32 unk30;
    /* 0x34 */ s32 unk34;
    /* 0x38 */ f32 unk38;
    /* 0x3C */ u8 unk3C[4];
    /* 0x40 */ s16 unk40;
    /* 0x42 */ s16 unk42;
    /* 0x44 */ u8 unk44[4];
    /* 0x48 */ s32 unk48;
    /* 0x4C */ s32 unk4C;
    /* 0x50 */ s32 unk50;
    /* 0x54 */ s32 unk54;
    /* 0x58 */ s16 unk58;
    /* 0x5A */ s16 unk5A;
    /* 0x5C */ s16 unk5C;
    /* 0x5E */ s16 unk5E;
    /* 0x60 */ u8 unk60;
    /* 0x61 */ u8 unk61;
    /* 0x62 */ u8 unk62[2];
    /* 0x64 */ s32 unk64;
    /* 0x68 */ s32 unk68;
    /* 0x6C */ u8 unk6C[4];
} Sg2ModTrack;

typedef struct Sg2ModBody {
    /* 0x000 */ s32 unk0;
    /* 0x004 */ u8 unk4[0x2B0 - 4];
    /* 0x2B0 */ Sg2ModTrack trk[16];
} Sg2ModBody;

typedef struct Sg2ModMain {
    /* 0x000 */ u8 unk0[4];
    /* 0x004 */ Sg2ModBody b;
} Sg2ModMain;

extern u8 *D_400F904C;
extern s32 D_400F9048;
extern Sg2ModMain *D_400F9050;
extern Sg2ModUnit D_400F9058[];
extern Sg2ModUnit D_400F9068[];

typedef struct Sg2ModMidiBuf {
    /* 0x000 */ u8 data[0x200];
    /* 0x200 */ s32 wp;
    /* 0x204 */ u8 pad[0x9B0 - 0x204];
} Sg2ModMidiBuf;

typedef struct Sg2ModClassRef {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ u8 pad[0x9B0 - 8];
} Sg2ModClassRef;

extern Sg2ModMidiBuf D_400F90BC[];
extern Sg2ModClassRef D_400F905C[];
extern Sg2ModClassRef D_400F9094[];
extern Sg2ModClassRef D_400F9098[];
extern s32 D_4010C658;
extern void (*control_change_ev[])(void);

s32 Sg2SlotFindSlotClass(s32 *buf, s32 cls);
void Sg2SlotSetMute(s32 slot, s32 flag);
void Sg2SlotSetPause(s32 slot, s32 flag);
void Sg2SlotSetDumperOff(s32 arg0, s32 arg1);
s64 litodp(s32 x);
s64 dpdiv(s64 a, s64 b);
f32 dptofp(s64 x);
s32 DIntr(void);
s32 EIntr(void);
void *memset(void *p, s32 c, u32 n);
void *memcpy(void *d, const void *s, u32 n);
void func_40032AC0(s32 arg0);
void func_40032C10(s32 arg0);
s32 Sg2CtrlEntryTickProcById(s32 id, void (*proc)(void));
void Sg2ModTickProc(void);
s32 vab_get_progchunk(s32 vab, s32 prog);
s32 vab_get_splitchunk(s32 chunk);

void Sg2SlotSetOutputMode(s32 arg0);
void Sg2SlotModKeyOff(s32 arg0, s32 arg1, s32 arg2);
s32 Sg2SlotFindSlotClassCh(s32 *buf, s32 cls, s32 ch);
void Sg2SlotSetLfoPitchDepth(s32 slot, s32 v);
void Sg2SlotSetLfoPitchSpeed(s32 slot, s32 v);
void Sg2SlotSetLfoVolDepth(s32 slot, s32 v);
void Sg2SlotSetLfoVolSpeed(s32 slot, s32 v);
void Sg2SlotSetBendValue(s32 slot, s32 v);
void Sg2SlotSetAdsr(s32 slot, s32 a, s32 b);
void Sg2SlotSetKeyOffBit(s32 slot, s32 bit);
s32 Sg2SlotGetSlotClassIdx(s32 slot);
s32 vab_check_alive(s32 vab);
s32 vab_get_info(s32 vab, s32 *a, s32 *b);
s32 vab_get_veltbl(s32 vab, void **p);
s32 vab_get_lfotbl_param(s32 vab, void **p, s32 *q);
extern u8 D_40045FF0[];


/* NEARMISS-STUB func_40032AC0 */
#if 0 /* NEARMISS 88.08% cat=regalloc sub=- | constants hoisted across loop in target (a1=1,0x40,0x7F), drum via xor+movz, sb 0x64 order | attempts=1 */
//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_40032AC0);
typedef struct Sg2ModBgmTrack {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ u8 unk18[8];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 drum;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ s32 unk30;
    /* 0x34 */ s32 unk34;
    /* 0x38 */ s32 unk38;
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ u8 unk40[4];
    /* 0x44 */ s16 unk44;
    /* 0x46 */ s16 unk46;
    /* 0x48 */ s32 unk48;
    /* 0x4C */ s32 unk4C;
    /* 0x50 */ s32 unk50;
    /* 0x54 */ s32 unk54;
    /* 0x58 */ s32 unk58;
    /* 0x5C */ s16 unk5C;
    /* 0x5E */ s16 unk5E;
    /* 0x60 */ s16 unk60;
    /* 0x62 */ s16 unk62;
    /* 0x64 */ u8 unk64[4];
    /* 0x68 */ s32 unk68;
    /* 0x6C */ s32 unk6C;
} Sg2ModBgmTrack;

typedef struct Sg2ModBgmHead {
    /* 0x000 */ s32 state;
    /* 0x004 */ u8 unk4[0xC];
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ u8 unk18[4];
    /* 0x01C */ s32 unk1C;
    /* 0x020 */ s32 unk20;
    /* 0x024 */ s32 unk24;
    /* 0x028 */ s32 unk28;
    /* 0x02C */ s32 unk2C;
    /* 0x030 */ s32 unk30;
    /* 0x034 */ s32 unk34;
    /* 0x038 */ s32 unk38;
    /* 0x03C */ s32 unk3C;
    /* 0x040 */ s32 unk40;
    /* 0x044 */ s32 unk44;
    /* 0x048 */ u8 unk48[0x60 - 0x48];
    /* 0x060 */ s32 unk60;
    /* 0x064 */ u8 unk64[4];
    /* 0x068 */ u8 unk68[0x2AC - 0x68];
    /* 0x2AC */ s32 unk2AC;
    /* 0x2B0 */ Sg2ModBgmTrack trk[16];
} Sg2ModBgmHead;

void func_40032AC0(s32 arg0) {
    Sg2ModBgmHead *m = (Sg2ModBgmHead *)&D_400F9058[arg0];
    Sg2ModBgmTrack *t;
    s32 i;

    m->unk38 = 0x7F;
    m->unk44 = 0x1000;
    m->unk30 = 0;
    m->unk34 = 0x7F;
    m->unk2C = 0;
    m->unk24 = 0;
    m->unk28 = 0;
    m->unk1C = 0;
    m->unk20 = 0;
    m->unk40 = 0;
    m->unk60 = 0;
    m->unk10 = 0;
    m->unk2AC = 1;
    m->unk64[0] = 0x80;
    m->unk14 = 1;
    m->unk3C = 0x40;
    m->state = -1;

    t = m->trk;
    for (i = 0; i < 16; i++) {
        s32 drum = (i == 9);

        t->unk0 = arg0;
        t->unk4 = 0;
        t->unk8 = 0xFF;
        t->unkC = 0x40;
        t->unk10 = 0;
        t->unk14 = 0x7F;
        t->unk20 = 0x7F;
        t->unk24 = 0;
        t->unk30 = 0;
        t->unk34 = 0x40;
        t->unk64[0] = 0;
        t->unk64[1] = 0;
        t->unk64[2] = 0;
        t->unk64[3] = 0;
        t->unk48 = 0x1000;
        t->unk68 = 0;
        t->unk6C = 0;
        t->unk5C = 0;
        t->unk5E = 0;
        t->unk60 = 0;
        t->unk62 = 0;
        t->unk38 = 0;
        t->unk3C = 0;
        t->unk4C = 0;
        t->unk50 = 0;
        t->unk54 = 0;
        t->unk58 = 0;
        t->unk46 = 1;
        t->unk44 = 1;
        t->drum = drum;
        t->unk2C = 1 - drum;
        t++;
    }
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_40032AC0);

/* NEARMISS-STUB func_40032C10 */
#if 0 /* NEARMISS 93.5% cat=regalloc sub=- | constant materialization regs/order (0x1000,-1,1,0x40,-0x80,2) and loop counter/ptr regs | attempts=1 */
//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_40032C10);

typedef struct Sg2ModSeTrack {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ u8 unk18[8];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ u8 unk28[8];
    /* 0x30 */ s32 unk30;
    /* 0x34 */ s32 unk34;
    /* 0x38 */ s32 unk38;
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ u8 unk40[4];
    /* 0x44 */ s16 unk44;
    /* 0x46 */ s16 unk46;
    /* 0x48 */ s32 unk48;
    /* 0x4C */ s32 unk4C;
    /* 0x50 */ s32 unk50;
    /* 0x54 */ s32 unk54;
    /* 0x58 */ s32 unk58;
    /* 0x5C */ s16 unk5C;
    /* 0x5E */ s16 unk5E;
    /* 0x60 */ s16 unk60;
    /* 0x62 */ s16 unk62;
    /* 0x64 */ u8 unk64[4];
    /* 0x68 */ s32 unk68;
    /* 0x6C */ s32 unk6C;
} Sg2ModSeTrack;

typedef struct Sg2ModSeHead {
    /* 0x000 */ s32 state;
    /* 0x004 */ u8 unk4[0xC];
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ u8 unk18[4];
    /* 0x01C */ s32 unk1C;
    /* 0x020 */ s32 unk20;
    /* 0x024 */ s32 unk24;
    /* 0x028 */ s32 unk28;
    /* 0x02C */ s32 unk2C;
    /* 0x030 */ s32 unk30;
    /* 0x034 */ s32 unk34;
    /* 0x038 */ s32 unk38;
    /* 0x03C */ s32 unk3C;
    /* 0x040 */ s32 unk40;
    /* 0x044 */ s32 unk44;
    /* 0x048 */ u8 unk48[0x60 - 0x48];
    /* 0x060 */ s32 unk60;
    /* 0x064 */ u8 unk64[4];
    /* 0x068 */ u8 unk68[0x2AC - 0x68];
    /* 0x2AC */ s32 unk2AC;
    /* 0x2B0 */ Sg2ModSeTrack trk[16];
} Sg2ModSeHead;

void func_40032C10(s32 arg0) {
    Sg2ModSeHead *m = (Sg2ModSeHead *)&D_400F9058[arg0];
    Sg2ModSeTrack *t;
    s32 i;

    m->unk38 = 0x7F;
    m->unk44 = 0x1000;
    m->unk30 = 0;
    m->unk34 = 0x7F;
    m->unk2C = 0;
    m->unk24 = 0;
    m->unk28 = 0;
    m->unk1C = 0;
    m->unk20 = 0;
    m->unk40 = 0;
    m->unk60 = 0;
    m->unk10 = 0;
    m->unk2AC = 1;
    m->unk64[0] = 0x80;
    m->unk14 = 2;
    m->unk3C = 0x40;
    m->state = -1;

    t = m->trk;
    i = 0xF;
    do {
        i--;
        t->unk0 = arg0;
        t->unk4 = 0;
        t->unk8 = 0xFF;
        t->unkC = 0x40;
        t->unk10 = 0;
        t->unk14 = 0x64;
        t->unk20 = 0x7F;
        t->unk24 = 0;
        t->unk30 = 0;
        t->unk34 = 0x40;
        t->unk64[0] = 0;
        t->unk64[1] = 0;
        t->unk64[2] = 0;
        t->unk64[3] = 0;
        t->unk48 = 0x1000;
        t->unk68 = 0;
        t->unk6C = 0;
        t->unk5C = 0;
        t->unk5E = 0;
        t->unk60 = 0;
        t->unk62 = 0;
        t->unk38 = 0;
        t->unk3C = 0;
        t->unk4C = 0;
        t->unk50 = 0;
        t->unk54 = 0;
        t->unk58 = 0;
        t->unk46 = 1;
        t->unk44 = 1;
        t++;
    } while (i >= 0);
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_40032C10);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", all_keyoff);
void all_keyoff(s32 arg0) {
    s32 buf[48];
    s32 i;

    i = Sg2SlotFindSlotClass(buf, D_400F905C[arg0].unk0) - 1;
    while (i >= 0) {
        s32 v = buf[i];

        Sg2SlotSetKeyOffBit(v >= 0x18, v < 0x18 ? 1 << v : 1 << (v - 0x18));
        i--;
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", all_soundoff);
void all_soundoff(s32 arg0) {
    s32 buf[48];
    s32 i;

    i = Sg2SlotFindSlotClass(buf, D_400F905C[arg0].unk0) - 1;
    while (i >= 0) {
        s32 v;

        Sg2SlotSetAdsr(buf[i], 0, 8);
        v = buf[i];
        Sg2SlotSetKeyOffBit(v >= 0x18, v < 0x18 ? 1 << v : 1 << (v - 0x18));
        i--;
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", all_soundpause);
void all_soundpause(s32 arg0, s32 arg1) {
    s32 buf[48];
    s32 i;

    i = Sg2SlotFindSlotClass(buf, D_400F905C[arg0].unk0) - 1;
    while (i >= 0) {
        Sg2SlotSetPause(buf[i], arg1);
        i--;
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", all_soundmute);
void all_soundmute(s32 arg0, s32 arg1) {
    s32 buf[48];
    s32 i;

    i = Sg2SlotFindSlotClass(buf, D_400F905C[arg0].unk0) - 1;
    while (i >= 0) {
        Sg2SlotSetMute(buf[i], arg1);
        i--;
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", Sg2ModMidiout1);
void Sg2ModMidiout1(s32 arg0, u8 arg1) {
    s32 intr = DIntr();
    Sg2ModMidiBuf *b = &D_400F90BC[arg0];

    b->data[b->wp] = arg1;
    b->wp = (b->wp + 1) & 0x1FF;
    if (intr) {
        EIntr();
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", Sg2ModMidiout1Exclusive);
void Sg2ModMidiout1Exclusive(s32 arg0, u8 *arg1) {
    Sg2ModMidiBuf *b;
    u8 *p = arg1;
    s32 intr;

    intr = DIntr();
    b = &D_400F90BC[arg0];
    do {
        b->data[b->wp] = *p;
        b->wp = (b->wp + 1) & 0x1FF;
    } while (*p++ != 0xF7);
    if (intr) {
        EIntr();
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", Sg2ModMidiout);
void Sg2ModMidiout(s32 mod, s32 len, u8 *data) {
    s32 intr = DIntr();
    Sg2ModMidiBuf *b = &D_400F90BC[mod];
    s32 room = 0x200 - b->wp;
    s32 diff = room - len;
    s32 rest;

    if (diff >= 0) {
        memcpy(&b->data[b->wp], data, len);
        b->wp = (b->wp + len) & 0x1FF;
    } else {
        memcpy(&b->data[b->wp], data, room);
        rest = -diff;
        memcpy(b->data, data + room, rest);
        b->wp = rest;
    }
    if (intr) {
        EIntr();
    }
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", Sg2ModTickProc);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", Sg2ModOpenBgm);
s32 Sg2ModOpenBgm(s32 vab, s32 mode) {
    s32 intr;
    s32 slot;
    s32 start;
    s32 i;
    s32 *serial;

    if (!vab_check_alive(vab)) {
        return -1;
    }
    intr = DIntr();
    i = 0;
    serial = &D_4010C658;
    start = *serial;
    slot = -1;
    for (; i < 0x20; i++) {
        s32 k = (start + i) % 0x20;

        if (D_400F9058[k].unk0 == -1) {
            slot = k;
            *serial = start + 1;
            D_400F9058[k].unk4 = Sg2SlotGetSlotClassIdx(k);
            break;
        }
    }
    if (intr != 0) {
        EIntr();
    }
    if (slot != -1) {
        func_40032AC0(slot);
        D_400F9058[slot].unk18 = mode;
        vab_get_info(vab, &D_400F9058[slot].unkC, &D_400F9058[slot].unk8);
        D_400F9058[slot].unk0 = vab;
        D_400F9058[slot].unk5C = vab_get_lfotbl_param(vab, &D_400F9058[slot].unk54, &D_400F9058[slot].unk58);
        if ((s32)D_400F9058[slot].unk54 < 0) {
            D_400F9058[slot].unk58 = (s32)D_40045FF0;
        }
        D_400F9058[slot].unk50 = vab_get_veltbl(vab, &D_400F9058[slot].unk4C);
    }
    return slot;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", Sg2ModOpenSe);
s32 Sg2ModOpenSe(s32 vab, s32 mode) {
    s32 intr;
    s32 slot;
    s32 start;
    s32 i;
    s32 *serial;

    if (!vab_check_alive(vab)) {
        return -1;
    }
    intr = DIntr();
    i = 0;
    serial = &D_4010C658;
    start = *serial;
    slot = -1;
    for (; i < 0x20; i++) {
        s32 k = (start + i) % 0x20;

        if (D_400F9058[k].unk0 == -1) {
            slot = k;
            *serial = start + 1;
            D_400F9058[k].unk4 = Sg2SlotGetSlotClassIdx(k);
            break;
        }
    }
    if (intr != 0) {
        EIntr();
    }
    if (slot != -1) {
        func_40032C10(slot);
        D_400F9058[slot].unk18 = mode;
        vab_get_info(vab, &D_400F9058[slot].unkC, &D_400F9058[slot].unk8);
        D_400F9058[slot].unk0 = vab;
        D_400F9058[slot].unk5C = vab_get_lfotbl_param(vab, &D_400F9058[slot].unk54, &D_400F9058[slot].unk58);
        if ((s32)D_400F9058[slot].unk54 < 0) {
            D_400F9058[slot].unk58 = (s32)D_40045FF0;
        }
        D_400F9058[slot].unk50 = vab_get_veltbl(vab, &D_400F9058[slot].unk4C);
    }
    return slot;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", Sg2ModCheckSndOn);
s32 Sg2ModCheckSndOn(s32 arg0) {
    if (arg0 >= 0) {
        return D_400F9058[arg0].unk0 != -1;
    }
    return 0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", Sg2ModClose);
s32 Sg2ModClose(s32 arg0) {
    if (arg0 >= 0) {
        D_400F9068[arg0].unk0 = 1;
    }
    return 0;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", Sg2ModSetParam);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", Sg2ModGetParam);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", Sg2ModSetOutputMode);
void Sg2ModSetOutputMode(s32 arg0) {
    Sg2SlotSetOutputMode(arg0);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", Sg2ModInit);
s32 Sg2ModInit(void) {
    s32 i;

    for (i = 0; i < 0x20; i++) {
        memset(&D_400F9058[i], 0, 0x9B0);
        func_40032AC0(i);
    }
    D_4010C658 = 1;
    Sg2CtrlEntryTickProcById(2, Sg2ModTickProc);
    return 0;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", debug_mod_config);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_40034800);
void func_40034800(void) {
    Sg2SlotModKeyOff(D_400F9050->b.unk0, D_400F904C[0] & 0xF, D_400F904C[1]);
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_40034838);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_40035408);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_40035A50);
void func_40035A50(void) {
    D_400F9050->b.trk[D_400F904C[0] & 0xF].unk0 = D_400F904C[2];
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_40035A88);
void func_40035A88(void) {
    u8 *p = D_400F904C;
    s32 buf[48];
    s32 t = p[0] & 0xF;
    s32 i;

    D_400F9050->b.trk[t].unk4C = p[2];
    i = Sg2SlotFindSlotClassCh(buf, D_400F9050->b.unk0, t) - 1;
    while (i >= 0) {
        Sg2SlotSetLfoPitchDepth(buf[i], D_400F904C[2]);
        i--;
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_40035B28);
void func_40035B28(void) {
    u8 *p = D_400F904C;
    s32 buf[48];
    s32 t = p[0] & 0xF;
    s32 i;

    D_400F9050->b.trk[t].unk48 = p[2];
    i = Sg2SlotFindSlotClassCh(buf, D_400F9050->b.unk0, t) - 1;
    while (i >= 0) {
        Sg2SlotSetLfoPitchSpeed(buf[i], D_400F904C[2]);
        i--;
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_40035BC8);
void func_40035BC8(void) {
    u8 *p = D_400F904C;
    s32 buf[48];
    s32 t = p[0] & 0xF;
    s32 i;

    D_400F9050->b.trk[t].unk54 = p[2];
    i = Sg2SlotFindSlotClassCh(buf, D_400F9050->b.unk0, t) - 1;
    while (i >= 0) {
        Sg2SlotSetLfoVolDepth(buf[i], D_400F904C[2]);
        i--;
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_40035C68);
void func_40035C68(void) {
    u8 *p = D_400F904C;
    s32 buf[48];
    s32 t = p[0] & 0xF;
    s32 i;

    D_400F9050->b.trk[t].unk50 = p[2];
    i = Sg2SlotFindSlotClassCh(buf, D_400F9050->b.unk0, t) - 1;
    while (i >= 0) {
        Sg2SlotSetLfoVolSpeed(buf[i], D_400F904C[2]);
        i--;
    }
}

/* NEARMISS-STUB func_40035D10 */
#if 0 /* NEARMISS 87.14% cat=sched sub=- | dpdiv delay slot: target fills it with addiu s0,0x2EC, ours with move a0 | attempts=1 */
/* best 87.14% (kR26 form reproduced; 4 new attempts in kR38 all <= 87.14: pointer local after dpdiv 85.5, inline store 85.5, in-place base += 0x2EC before call 87.14 (same diff), Sg2ModTrack* + 0x3C 84.6).
   Target: addiu s0,0x2EC sits in dpdiv's delay slot after `daddu a0,v0` (litodp result) and before jal dpdiv; move a0,v0 for dptofp follows dpdiv.
   Ours: move a0,v0 fills dpdiv's delay slot and addiu lands after the call. Still open. */
void func_40035D10(void) {
    s32 base = (D_400F904C[0] & 0xF) * 0x70 + (s32)D_400F9050;
    s64 d = litodp(D_400F904C[2]);
    f32 *p = (f32 *)(base + 0x2EC);
    *p = dptofp(dpdiv(d, 0x4028000000000000LL));
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_40035D10);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_40035D80);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_40035F80);
void func_40035F80(void) {
    D_400F9050->b.trk[D_400F904C[0] & 0xF].unk10 = D_400F904C[2];
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_40035FB8);
void func_40035FB8(void) {
    D_400F9050->b.trk[D_400F904C[0] & 0xF].unk8 = D_400F904C[2];
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_40035FF0);
void func_40035FF0(void) {
    D_400F9050->b.trk[D_400F904C[0] & 0xF].unk1C = D_400F904C[2];
}

void func_40036028(void) {
}

void func_40036030(void) {
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_40036038);
void func_40036038(void) {
    u8 *p = D_400F904C;
    s32 t = p[0] & 0xF;
    if (p[2] < 0x7E) {
        D_400F9050->b.trk[t].unk2C = 0;
        Sg2SlotSetDumperOff(D_400F9050->b.unk0, t);
    } else {
        D_400F9050->b.trk[t].unk2C = 1;
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_400360C0);
void func_400360C0(void) {
    D_400F9050->b.trk[D_400F904C[0] & 0xF].unk34 = D_400F904C[2];
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_400360F8);
void func_400360F8(void) {
    s32 v = D_400F904C[2] * 2 - 0x80;
    if (v < 0) {
        v |= 0x100;
    }
    D_400F9050->b.trk[D_400F904C[0] & 0xF].unk5C = (v << 6) & 0x7FC0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_40036148);
void func_40036148(void) {
    u8 *p = D_400F904C;
    s32 t = p[0] & 0xF;
    if (p[2] >= 0x10) {
        p[2] = 0xF;
    }
    D_400F9050->b.trk[t].unk5A = (D_400F904C[2] << 1) & 0xF0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_400361A0);
void func_400361A0(void) {
    u8 *p = D_400F904C;
    s32 t = p[0] & 0xF;
    if (p[2] >= 0x20) {
        p[2] = 0x1F;
    }
    D_400F9050->b.trk[t].unk5E = (D_400F904C[2] >> 2) & 0x1F;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_400361F8);
void func_400361F8(void) {
    s8 *p = (s8 *)D_400F904C;
    s32 t = p[0] & 0xF;
    if (p[2] < 0) {
        p[2] = 0x7F;
    }
    D_400F9050->b.trk[t].unk58 = (D_400F904C[2] << 8) & 0x7F00;
}

void func_40036250(void) {
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_40036258);
void func_40036258(void) {
    D_400F9050->b.trk[D_400F904C[0] & 0xF].unk20 = D_400F904C[2];
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_40036290);

void func_40036330(void) {
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_40036338);
void func_40036338(void) {
    D_400F9050->b.trk[D_400F904C[0] & 0xF].unk61 = D_400F904C[2];
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_40036370);
void func_40036370(void) {
    D_400F9050->b.trk[D_400F904C[0] & 0xF].unk60 = D_400F904C[2];
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_400363A8);
void func_400363A8(void) {
    u8 *p = D_400F904C;
    s32 buf[48];
    s32 t = p[0] & 0xF;
    s32 i;

    i = Sg2SlotFindSlotClassCh(buf, D_400F9050->b.unk0, t) - 1;
    while (i >= 0) {
        s32 v;

        Sg2SlotSetAdsr(buf[i], 0, 8);
        v = buf[i];
        Sg2SlotSetKeyOffBit(v >= 0x18, v < 0x18 ? 1 << v : 1 << (v - 0x18));
        i--;
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_40036450);
void func_40036450(void) {
    u8 *p = D_400F904C;
    s32 buf[48];
    s32 t = p[0] & 0xF;
    s32 i;

    i = Sg2SlotFindSlotClassCh(buf, D_400F9050->b.unk0, t) - 1;
    while (i >= 0) {
        s32 v = buf[i];

        Sg2SlotSetKeyOffBit(v >= 0x18, v < 0x18 ? 1 << v : 1 << (v - 0x18));
        i--;
    }
}

void func_400364E8(void) {
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_400364F0);
void func_400364F0(void) {
    control_change_ev[D_400F904C[1]]();
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_40036528);
void func_40036528(void) {
    u8 *p = D_400F904C;
    s32 i = p[0] & 0xF;
    s32 r;

    D_400F9050->b.trk[i].unk4 = p[1];
    r = vab_get_progchunk(*(s32 *)D_400F9050, p[1]);
    D_400F9050->b.trk[i].unk64 = r;
    D_400F9050->b.trk[i].unk68 = vab_get_splitchunk(r);
}

void func_400365B0(void) {
}

/* NEARMISS-STUB func_400365B8 */
#if 0 /* NEARMISS 93.09% cat=sched sub=- | lui order: target lui D_400F904C before lui D_400F9050 | attempts=1 */
//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_400365B8);
void func_400365B8(void) {
    u8 *p = D_400F904C;
    s32 buf[48];
    s32 t = p[0] & 0xF;
    s32 v = (p[1] + (p[2] << 7)) >> 7;
    Sg2ModBody *b;
    s32 i;

    b = &D_400F9050->b;
    b->trk[t].unk30 = v;
    i = Sg2SlotFindSlotClassCh(buf, b->unk0, t) - 1;
    while (i >= 0) {
        Sg2SlotSetBendValue(buf[i], v);
        i--;
    }
}

/* kR38 best: 93.09%. Remaining diff is lui order only: target lui v0(D_400F904C) then lui a1(D_400F9050);
   ours emits lui for D_400F9050 first. Tried: (a) local b after p (same 93.09), (b) no local b, D->b.trk direct (same 93.09),
   (c) all event reads via D_400F904C global, b = &D->b declared-init (same 93.09). Not reached 100%. */
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_400365B8);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_40036660);

void func_40036BE0(void) {
}

void func_40036BE8(void) {
}

void func_40036BF0(void) {
}

void func_40036BF8(void) {
}

/* NEARMISS-STUB func_40036C00 */
#if 0 /* NEARMISS 95.61% cat=regalloc sub=- | &D_400F9048 in s0 for 0x40/0x41 arms; target duplicates default epilogue, beql at 0x41 | attempts=1 */
/* Best attempt for KERNEL.XFF/Sg2/mod func_40036C00: 95.61% (not matched). Needs: extern s32 D_400F9048; (next to extern u8 *D_400F904C;).
 * Pointer local p=&D_400F9048 used only in cases 0x40/0x41 (95.6). Hoisting p to the top (all arms use *p) scores lower (SCORE line not kept). Remaining diff: target computes the pointer in s0 (lui s0/addiu s0) for 0x40/0x41; ours uses v0 then addiu s0,v0. Target 0x41 uses beql at the 0x41 test; default epilogue duplicated.
 */
void func_40036C00(void) {
    u8 *ev = D_400F904C;
    s32 *p;

    switch (ev[1]) {
    case 0x2F:
        all_keyoff(D_400F9048);
        return;
    case 0x3F:
        Sg2ModClose(D_400F9048);
        return;
    case 0x40:
        p = &D_400F9048;
        all_keyoff(*p);
        Sg2ModClose(*p);
        return;
    case 0x41:
        p = &D_400F9048;
        all_soundoff(*p);
        Sg2ModClose(*p);
        return;
    }
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_40036C00);

void func_40036CE0(void) {
}
