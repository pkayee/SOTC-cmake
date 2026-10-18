#include "common.h"

//INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_40015FF8);
extern int D_400193CC;
extern int D_400193D0;
extern int D_400198E0;

extern int D_400193C4;
extern char D_4002B910[];
extern char D_4002BF08[];

extern float D_400198C4;

extern float D_400198C8;

extern float D_400198CC;

extern float D_400198D0;

extern void func_400141C8(int);

extern float D_400198D4;

extern float D_400198D8;

extern float D_400198DC;

extern void func_40014578(int);

void func_40015FF8(void) {
    if (D_400193CC == 0) {
        D_400193D0 = D_400198E0;
    } else {
        D_400198E0 = D_400193D0;
    }
}

//INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_40016030);
extern int D_400193D4;

int *func_40016030(void) {
    return &D_400193D4;
}

//INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_40016040);
extern int D_400193D8;

int *func_40016040(void) {
    return &D_400193D8;
}

char *func_40016050(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + 0x8;
}

char *func_40016080(void) {
    char *p;
    float *q = &D_400198C4;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    *q = *(float *)(p + 0xC);
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + 0xC;
}

char *func_400160E0(void) {
    char *p;
    float *q = &D_400198C8;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    *q = *(float *)(p + 0x10);
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + 0x10;
}

char *func_40016140(void) {
    char *p;
    float *q = &D_400198CC;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    *q = *(float *)(p + 0x14);
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + 0x14;
}

char *func_400161A0(void) {
    char *p;
    float *q = &D_400198D0;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    *q = *(float *)(p + 0x18);
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + 0x18;
}

void func_40016200(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    if (D_400198C4 < *(float *)(p + 0xC)) {
        func_400141C8(1);
    } else {
        func_400141C8(0);
    }
}

void func_40016268(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    if (D_400198C8 < *(float *)(p + 0x10)) {
        func_400141C8(1);
    } else {
        func_400141C8(0);
    }
}

void func_400162D0(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    if (D_400198CC < *(float *)(p + 0x14)) {
        func_400141C8(1);
    } else {
        func_400141C8(0);
    }
}

void func_40016338(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    if (D_400198D0 < *(float *)(p + 0x18)) {
        func_400141C8(1);
    } else {
        func_400141C8(0);
    }
}

char *func_400163A0(void) {
    char *p;
    float *q = &D_400198D4;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    *q = *(float *)(p + 0x28);
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + 0x28;
}

char *func_40016400(void) {
    char *p;
    float *q = &D_400198D8;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    *q = *(float *)(p + 0x2C);
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + 0x2C;
}

char *func_40016460(void) {
    char *p;
    float *q = &D_400198DC;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    *q = *(float *)(p + 0x30);
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + 0x30;
}

void func_400164C0(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    if (D_400198D4 < *(float *)(p + 0x28)) {
        func_40014578(1);
    } else {
        func_40014578(0);
    }
}

void func_40016528(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    if (D_400198D8 < *(float *)(p + 0x2C)) {
        func_40014578(1);
    } else {
        func_40014578(0);
    }
}

void func_40016590(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    if (D_400198DC < *(float *)(p + 0x30)) {
        func_40014578(1);
    } else {
        func_40014578(0);
    }
}

char *func_400165F8(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + 0x34;
}

char *func_40016628(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + 0x50;
}

char *func_40016658(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + 0x40;
}

char *func_40016688(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + 0x44;
}

char *func_400166B8(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + 0x38;
}

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_400166E8);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_40016718);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_40016748);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_40016778);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_400167A8);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_400167D8);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_40016808);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_40016838);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_40016868);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_40016898);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_400168C8);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_400168F8);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_40016928);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_40016958);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_40016988);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_400169B8);

void func_400169C8(void) {
}

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_400169D0);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_40016A98);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_40016AC8);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_40016AF8);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_40016B28);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_40016B58);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_40016B88);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_40016BB8);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_40016BE8);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_40016C18);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_40016C48);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_40016C78);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_40016CA8);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_40016CD8);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_40016D08);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_40016D38);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_40016D68);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_40016D98);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_40016DC8);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_40016E18);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_40016E68);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_40016EB8);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_40016F08);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_40016F58);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_40016FA8);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_40016FF8);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_40017048);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_40017098);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_400170E8);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_40017138);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_40017188);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_400171D8);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_40017228);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_40017278);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_400172C8);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_40017318);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_40017368);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_400173B8);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_40017408);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_40017458);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_400174A8);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_400174F8);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_40017548);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_40017598);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_400175E8);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_40017638);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_40017688);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_400176D8);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_40017728);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_40017778);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0004_func_40015FF8", func_400177C8);
