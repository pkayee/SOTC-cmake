#include "common.h"

typedef struct Sg2ModUnit {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ u8 unk4[0xC];
    /* 0x10 */ s32 unk10;
    /* 0x14 */ u8 unk14[0x9B0 - 0x14];
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
    /* 0x30 */ u8 unk30[4];
    /* 0x34 */ s32 unk34;
    /* 0x38 */ f32 unk38;
    /* 0x3C */ u8 unk3C[0x1C];
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

typedef struct Sg2ModMain {
    /* 0x000 */ u8 unk0[4];
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 unk8[0x2AC];
    /* 0x2B4 */ Sg2ModTrack trk[16];
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
void func_40032AC0(s32 arg0);
s32 Sg2CtrlEntryTickProcById(s32 id, void (*proc)(void));
void Sg2ModTickProc(void);
s32 vab_get_progchunk(s32 vab, s32 prog);
s32 vab_get_splitchunk(s32 chunk);

void Sg2SlotSetOutputMode(s32 arg0);
void Sg2SlotModKeyOff(s32 arg0, s32 arg1, s32 arg2);


INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_40032AC0);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_40032C10);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", all_keyoff);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", all_soundoff);

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

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", Sg2ModMidiout1Exclusive);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", Sg2ModMidiout);

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
    Sg2SlotModKeyOff(D_400F9050->unk4, D_400F904C[0] & 0xF, D_400F904C[1]);
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_40034838);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_40035408);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_40035A50);
void func_40035A50(void) {
    D_400F9050->trk[D_400F904C[0] & 0xF].unk0 = D_400F904C[2];
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_40035A88);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_40035B28);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_40035BC8);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_40035C68);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_40035D10);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_40035D80);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_40035F80);
void func_40035F80(void) {
    D_400F9050->trk[D_400F904C[0] & 0xF].unk10 = D_400F904C[2];
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_40035FB8);
void func_40035FB8(void) {
    D_400F9050->trk[D_400F904C[0] & 0xF].unk8 = D_400F904C[2];
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_40035FF0);
void func_40035FF0(void) {
    D_400F9050->trk[D_400F904C[0] & 0xF].unk1C = D_400F904C[2];
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
        D_400F9050->trk[t].unk2C = 0;
        Sg2SlotSetDumperOff(D_400F9050->unk4, t);
    } else {
        D_400F9050->trk[t].unk2C = 1;
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_400360C0);
void func_400360C0(void) {
    D_400F9050->trk[D_400F904C[0] & 0xF].unk34 = D_400F904C[2];
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_400360F8);
void func_400360F8(void) {
    s32 v = D_400F904C[2] * 2 - 0x80;
    if (v < 0) {
        v |= 0x100;
    }
    D_400F9050->trk[D_400F904C[0] & 0xF].unk5C = (v << 6) & 0x7FC0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_40036148);
void func_40036148(void) {
    u8 *p = D_400F904C;
    s32 t = p[0] & 0xF;
    if (p[2] >= 0x10) {
        p[2] = 0xF;
    }
    D_400F9050->trk[t].unk5A = (D_400F904C[2] << 1) & 0xF0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_400361A0);
void func_400361A0(void) {
    u8 *p = D_400F904C;
    s32 t = p[0] & 0xF;
    if (p[2] >= 0x20) {
        p[2] = 0x1F;
    }
    D_400F9050->trk[t].unk5E = (D_400F904C[2] >> 2) & 0x1F;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_400361F8);
void func_400361F8(void) {
    s8 *p = (s8 *)D_400F904C;
    s32 t = p[0] & 0xF;
    if (p[2] < 0) {
        p[2] = 0x7F;
    }
    D_400F9050->trk[t].unk58 = (D_400F904C[2] << 8) & 0x7F00;
}

void func_40036250(void) {
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_40036258);
void func_40036258(void) {
    D_400F9050->trk[D_400F904C[0] & 0xF].unk20 = D_400F904C[2];
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_40036290);

void func_40036330(void) {
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_40036338);
void func_40036338(void) {
    D_400F9050->trk[D_400F904C[0] & 0xF].unk61 = D_400F904C[2];
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_40036370);
void func_40036370(void) {
    D_400F9050->trk[D_400F904C[0] & 0xF].unk60 = D_400F904C[2];
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_400363A8);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_40036450);

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

    D_400F9050->trk[i].unk4 = p[1];
    r = vab_get_progchunk(*(s32 *)D_400F9050, p[1]);
    D_400F9050->trk[i].unk64 = r;
    D_400F9050->trk[i].unk68 = vab_get_splitchunk(r);
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
