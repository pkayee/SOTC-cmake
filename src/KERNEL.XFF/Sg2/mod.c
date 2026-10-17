#include "common.h"

typedef struct Sg2ModUnit {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ u8 unk4[0xC];
    /* 0x10 */ s32 unk10;
    /* 0x14 */ u8 unk14[0x34 - 0x14];
    /* 0x34 */ s32 unk34;
    /* 0x38 */ s32 unk38;
    /* 0x3C */ u8 unk3C[0x9B0 - 0x3C];
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


INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_40032AC0);

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

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", Sg2ModOpenBgm);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", Sg2ModOpenSe);

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

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_40036C00);

void func_40036CE0(void) {
}
