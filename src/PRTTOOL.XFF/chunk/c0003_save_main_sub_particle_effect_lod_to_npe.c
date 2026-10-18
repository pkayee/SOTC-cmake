#include "common.h"

extern int D_400193CC;
extern int D_400193C4;
extern char D_4002B910[];
extern char D_4002BF08[];

extern int D_400193D0;
extern int D_400198E0;

extern float D_40019488;

extern float D_40019370;
extern float D_40019390[4];
extern float YUnitVector[4];
extern void func_40010A80(void);
extern void func_40014968(void);
extern void func_400149C8(void);
extern void gluGetLookAtPosition(float *, float);

extern void GAMEUTIL_get_direction_by_yaw_pitch(void *, float, float);

extern void convert_to_particle_parameter_lod(void *, int);
extern void constructor_particle_parameter_lod(char *, int);

extern char *D_40019364;
extern char *D_40019368;
extern void convert_to_particle_effect_lod(char *, char *);

extern int D_400196E0;

extern unsigned int D_400193B0;

extern int D_400193B8;
extern void func_40013FF0(void);

extern float D_4001936C;

extern char D_40019438[];
extern char *strcpy(char *, const char *);

extern char D_400196E8[];
extern void createStringInputDialog(char *, int);

extern void func_40011268(void);

extern int D_400193DC;

extern int D_4001942C;

extern int D_40019484;

extern int D_40019430;

extern int D_40019434;

extern int D_40019478;

extern int D_4001947C;

typedef struct { int a, b, c, d; } PtclSeg;
extern void batch_changing_particle_parameter(PtclSeg *);
extern PtclSeg g_ainParticleSegment[];

extern void batch_saving_particle_parameter(PtclSeg *);

extern int D_400194D8;

extern int D_40019424;

extern int D_40019428;

extern float D_400193AC;

extern float D_40019374;

extern float D_40019378;

extern int D_400193A4;

extern int D_400193A8;

extern int D_400193A0;

extern int D_40019360;
extern void func_400115D0(void);
extern void func_40012468(void);
extern void func_40019328(float);
extern float iosGetCpuRapCountPar1Int();
extern void iosResetCpuRapCounter(u32);

extern char D_400193E0[];
extern int D_40019420;
extern char D_4002B8B8[];
extern void check_free_particle_geodisp(int *);
extern int create_and_boot_particle_geodisp(char *, char *, int, int, int);

typedef union { s128 q; float f[4]; } Q4;
extern Q4 D_40019380;
extern float UnitMatrix[16];
extern void glDrawLineStrip(void *, int, float *, float *, int);

extern char D_4001C968[];
extern int iosSPrintf(char *, char *, ...);

typedef union { s128 q; float f[8]; } Q8;
extern Q8 D_40019718;
extern void createYesNoDialog(void *, int);
extern int getDrawScreenHeight(void);
extern int getDrawScreenWidth(void);

extern Q8 D_40019748;

extern Q8 D_40019778;

extern Q8 D_400197A8;

extern Q8 D_400197D8;

extern Q8 D_40019808;

extern Q8 D_40019838;

extern Q8 D_40019868;

extern Q8 D_40019898;

extern void func_40015488();

void save_main_sub_particle_effect_lod_to_npe_file(char *m, char *s, char *name) {
    char buf[128];
    if (m != 0) {
        func_40015488(m, name);
    }
    if (s != 0) {
        iosSPrintf(buf, D_4001C968, name);
        ((void (*)(char *, char *))func_40015488)(s, buf);
    }
}

float func_40014858(float a) {
    return a / 180.0f;
}

float func_40014878(float a) {
    return a * 180.0f;
}

void func_40014888(float a) {
    D_40019488 = a;
}

void func_40014898(void) {
    gluGetLookAtPosition(&D_40019370, 9.0f);
    *(s128 *)D_40019390 = *(s128 *)YUnitVector;
    func_40010A80();
    func_40014968();
    func_400149C8();
}

void func_400148E8(void) {
    int saved = *(int *)(D_40019364 + 0x1c);
    *(int *)(D_40019364 + 0x1c) = 100;
    check_free_particle_geodisp(&D_40019420);
    D_40019420 = create_and_boot_particle_geodisp(D_4002B8B8, D_400193E0, 0, 0, 0);
    *(int *)(D_40019364 + 0x1c) = saved;
}

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0003_save_main_sub_particle_effect_lod_to_npe", func_40014968);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0003_save_main_sub_particle_effect_lod_to_npe", func_400149C8);

void func_40014A60(float alpha, Q4 *pos, int extra) {
    Q4 pts[2];
    float col[4] = {0.4f, 0.9f, 1.0f, alpha};
    pts[0].q = pos->q;
    pts[1].q = D_40019380.q;
    pts[1].f[3] = 1.0f;
    glDrawLineStrip(pts, 2, UnitMatrix, col, extra);
}

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0003_save_main_sub_particle_effect_lod_to_npe", func_40014AE0);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0003_save_main_sub_particle_effect_lod_to_npe", func_40014C98);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0003_save_main_sub_particle_effect_lod_to_npe", func_40014E40);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0003_save_main_sub_particle_effect_lod_to_npe", func_40014F10);

void func_40014FA8(char *a, char *b) {
    GAMEUTIL_get_direction_by_yaw_pitch(a + 0x40, *(float *)(b + 0x38) * 3.1415927f / 180.0f, *(float *)(b + 0x3c) * 3.1415927f / 180.0f);
}

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0003_save_main_sub_particle_effect_lod_to_npe", func_40015000);

float func_40015088(float a, float b) {
    return a - b * 0.5f;
}

float func_400150A0(float a, float b) {
    if (a - b * 0.5f < 0.0f) {
        return 0.0f;
    }
    return a - b * 0.5f;
}

float func_400150C8(float a, float b) {
    return a + b * 0.5f;
}

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0003_save_main_sub_particle_effect_lod_to_npe", func_400150E0);

void func_400151B8(void *a, int b, int c) {
    if (b != 0) {
        convert_to_particle_parameter_lod(a, b);
    } else {
        constructor_particle_parameter_lod(a, c);
    }
}

void func_400151E0(int *a) {
    int i = 1;
    while (i < a[0x34]) {
        int *s = (int *)a[0x35];
        int *t = (int *)((char *)s + i * 0x1bc);
        t[0] = s[0];
        t[0x4f] = s[0x4f];
        t[5] = s[5];
        t[4] = s[4];
        i++;
    }
}

void func_40015248(char *b) {
    int *s = (int *)(b + 0xc0);
    int *d = (int *)(b + 0x27c);
    int i = 1;
    do {
        i--;
        d[0] = s[0];
        d[0x50] = s[0x50];
        d[5] = s[5];
        d[4] = s[4];
        d += 0x6f;
    } while (i >= 0);
}

void func_40015290(void) {
    if (D_400193C4 == 1) {
        convert_to_particle_effect_lod(D_40019364, D_4002B910);
    } else {
        convert_to_particle_effect_lod(D_40019368, D_4002BF08);
    }
}

void disp_particle_customize_mode(void) {
    if (D_40019360 != 0) {
        iosResetCpuRapCounter(2);
        func_40019328(iosGetCpuRapCountPar1Int() * 100.0f);
        if (D_4001942C == 1) {
            func_400115D0();
        }
        func_40012468();
    }
}

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0003_save_main_sub_particle_effect_lod_to_npe", func_40015358);

float func_40015430(float a) {
    if (a > 0.0f) {
        return a / 30.0f;
    }
    return a;
}

float func_40015460(float a) {
    if (a > 0.0f) {
        return a * 30.0f;
    }
    return a;
}

void func_40015488(void) {
}

void func_40015490(void) {
}

void func_40015498(void) {
}

int *func_400154A0(void) {
    D_400196E0 = 0;
    return &D_400196E0;
}

unsigned int *func_400154B0(void) {
    return &D_400193B0;
}

void func_400154C0(void) {
    D_400193B8 = 0;
    func_40013FF0();
}

int *func_400154E0(void) {
    return &D_400193B8;
}

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0003_save_main_sub_particle_effect_lod_to_npe", func_400154F0);

int *func_40015598(void) {
    return &D_400193C4;
}

void func_400155A8(void) {
    if (D_400193C4 == 1) {
        D_4001936C = 0.0f;
    } else {
        D_4001936C = 1.0f;
    }
}

float *func_400155D8(void) {
    return &D_4001936C;
}

char *func_400155E8(char *s) {
    return strcpy(D_40019438, s);
}

void func_40015608(char *a) {
    createStringInputDialog(D_400196E8, *(int *)(a + 0x94));
}

void func_40015628(void) {
    char buf[128];
    char *s = D_40019368;
    char *name = D_40019438;
    if (D_40019364 != 0) {
        ((void (*)(char *, char *))func_40015488)(D_40019364, name);
    }
    if (s != 0) {
        iosSPrintf(buf, D_4001C968, name);
        ((void (*)(char *, char *))func_40015488)(s, buf);
    }
}

void func_400156A0(char *a) {
    D_40019718.f[6] = (float)(getDrawScreenWidth() / 2 - 0x80);
    D_40019718.f[7] = (float)(getDrawScreenHeight() / 2 - 0x46);
    createYesNoDialog(&D_40019718, *(int *)(a + 0x94));
}

void func_40015718(char *a) {
    D_40019748.f[6] = (float)(getDrawScreenWidth() / 2 - 0x80);
    D_40019748.f[7] = (float)(getDrawScreenHeight() / 2 - 0x46);
    createYesNoDialog(&D_40019748, *(int *)(a + 0x94));
}

void func_40015790(void) {
    func_40011268();
}

void func_400157A8(char *a) {
    D_40019778.f[6] = (float)(getDrawScreenWidth() / 2 - 0x80);
    D_40019778.f[7] = (float)(getDrawScreenHeight() / 2 - 0x46);
    createYesNoDialog(&D_40019778, *(int *)(a + 0x94));
}

int *func_40015820(void) {
    return &D_400193DC;
}

void func_40015830(void) {
    constructor_particle_parameter_lod(D_4002B910, 1);
    constructor_particle_parameter_lod(D_4002BF08, 0);
}

void func_40015860(char *a) {
    D_400197A8.f[6] = (float)(getDrawScreenWidth() / 2 - 0x80);
    D_400197A8.f[7] = (float)(getDrawScreenHeight() / 2 - 0x46);
    createYesNoDialog(&D_400197A8, *(int *)(a + 0x94));
}

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0003_save_main_sub_particle_effect_lod_to_npe", func_400158D8);

void func_40015A08(char *a) {
    D_400197D8.f[6] = (float)(getDrawScreenWidth() / 2 - 0x80);
    D_400197D8.f[7] = (float)(getDrawScreenHeight() / 2 - 0x46);
    createYesNoDialog(&D_400197D8, *(int *)(a + 0x94));
}

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0003_save_main_sub_particle_effect_lod_to_npe", func_40015A80);

void func_40015B88(char *a) {
    D_40019808.f[6] = (float)(getDrawScreenWidth() / 2 - 0x80);
    D_40019808.f[7] = (float)(getDrawScreenHeight() / 2 - 0x46);
    createYesNoDialog(&D_40019808, *(int *)(a + 0x94));
}

int *func_40015C00(void) {
    return &D_4001942C;
}

int *func_40015C10(void) {
    return &D_40019484;
}

int *func_40015C20(void) {
    return &D_40019430;
}

int *func_40015C30(void) {
    return &D_40019434;
}

int *func_40015C40(void) {
    return &D_40019478;
}

int *func_40015C50(void) {
    return &D_4001947C;
}

void func_40015C60(void) {
    PtclSeg *p;
    if (D_400193B0 < 0x32) {
        p = &g_ainParticleSegment[D_400193B0];
    } else {
        p = 0;
    }
    batch_changing_particle_parameter(p);
    func_40013FF0();
}

void func_40015CA0(char *a) {
    D_40019838.f[6] = (float)(getDrawScreenWidth() / 2 - 0x80);
    D_40019838.f[7] = (float)(getDrawScreenHeight() / 2 - 0x46);
    createYesNoDialog(&D_40019838, *(int *)(a + 0x94));
}

void func_40015D18(void) {
    PtclSeg *p;
    if (D_400193B0 < 0x32) {
        p = &g_ainParticleSegment[D_400193B0];
    } else {
        p = 0;
    }
    batch_saving_particle_parameter(p);
}

void func_40015D50(char *a) {
    D_40019868.f[6] = (float)(getDrawScreenWidth() / 2 - 0x80);
    D_40019868.f[7] = (float)(getDrawScreenHeight() / 2 - 0x46);
    createYesNoDialog(&D_40019868, *(int *)(a + 0x94));
}

void func_40015DC8(char *a) {
    D_40019898.f[6] = (float)(getDrawScreenWidth() / 2 - 0x80);
    D_40019898.f[7] = (float)(getDrawScreenHeight() / 2 - 0x46);
    createYesNoDialog(&D_40019898, *(int *)(a + 0x94));
}

int *func_40015E40(void) {
    return &D_400194D8;
}

int *func_40015E50(void) {
    return &D_40019424;
}

int *func_40015E60(void) {
    return &D_40019428;
}

float *func_40015E70(void) {
    return &D_400193AC;
}

float *func_40015E80(void) {
    return &D_40019370;
}

float *func_40015E90(void) {
    return &D_40019374;
}

float *func_40015EA0(void) {
    return &D_40019378;
}

int *func_40015EB0(void) {
    return &D_400193A4;
}

int *func_40015EC0(void) {
    return &D_400193A8;
}

void func_40015ED0(void) {
    D_400193A0 = 1;
}

//INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0003_save_main_sub_particle_effect_lod_to_npe", func_40015EE0);

char *func_40015EE0(void) {
    if (D_400193C4 == 1) {
        return D_4002B910;
    }
    return D_4002BF08;
}

//INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0003_save_main_sub_particle_effect_lod_to_npe", func_40015F08);

char *func_40015F08(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + 0x20;
}

//INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0003_save_main_sub_particle_effect_lod_to_npe", func_40015F38);

char *func_40015F38(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + 0x4;
}

//INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0003_save_main_sub_particle_effect_lod_to_npe", func_40015F68);

char *func_40015F68(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + 0x60;
}

char *func_40015F98(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + 0x64;
}

//INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0003_save_main_sub_particle_effect_lod_to_npe", func_40015FC8);

int *func_40015FC8(void) {
    return &D_400193CC;
}

int *func_40015FD8(void) {
    D_400198E0 = D_400193D0;
    return &D_400198E0;
}
