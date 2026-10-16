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
    /* 0x24 */ u8 unk24[0x10];
    /* 0x34 */ s32 unk34;
    /* 0x38 */ u8 unk38[0x28];
    /* 0x60 */ u8 unk60;
    /* 0x61 */ u8 unk61;
    /* 0x62 */ u8 unk62[0xE];
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

void Sg2SlotSetOutputMode(s32 arg0);
void Sg2SlotModKeyOff(s32 arg0, s32 arg1, s32 arg2);


INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_40032AC0);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_40032C10);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", all_keyoff);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", all_soundoff);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", all_soundpause);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", all_soundmute);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", Sg2ModMidiout1);

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

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", Sg2ModInit);

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

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_40036038);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_400360C0);
void func_400360C0(void) {
    D_400F9050->trk[D_400F904C[0] & 0xF].unk34 = D_400F904C[2];
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_400360F8);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_40036148);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_400361A0);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_400361F8);

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

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_400364F0);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/mod", func_40036528);

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
