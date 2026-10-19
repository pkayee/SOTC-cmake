#include "common.h"

typedef struct { int a, b, c, d; } PtclSeg;
extern void *get_main_particle_effect_lod_from_sheet(void *);
extern void *get_sub_particle_effect_lod_from_sheet(void *);
extern void convert_to_particle_parameter_lod(void *, void *);
extern void convert_to_particle_effect_lod(void *, void *);
extern void func_400107E0(char *);

extern char *strcpy(char *, const char *);
extern char *DEBUG_get_base_name_extention_cut(char *);
extern void save_main_sub_particle_effect_lod_to_npe_file(void *, void *, char *);

extern void func_40010828();

extern unsigned int D_400193B0;
extern int D_400193B8;
extern PtclSeg g_ainParticleSegment[];
typedef struct { float f[0x17E]; } PtclBlk;

extern int D_400193C4;
extern int D_40019490;
extern char D_4002B910[];
extern char D_4002BF08[];

static inline PtclSeg *getseg(void) {
    PtclSeg *p;
    if (D_400193B0 < 0x32) {
        p = &g_ainParticleSegment[D_400193B0];
    } else {
        p = 0;
    }
    return p;
}

void batch_changing_particle_parameter(PtclSeg *seg) {
    char buf[0x600];
    int i;
    int j;
    char *item;
    void *lod;
    if (seg != 0) {
        for (i = 0; i < seg->c; i++) {
            item = (char *)seg->d + i * 0x54;
            for (j = 0; j < 2; j++) {
                lod = get_main_particle_effect_lod_from_sheet(item);
                if (j == 1) {
                    lod = get_sub_particle_effect_lod_from_sheet(item);
                }
                if (lod != 0) {
                    convert_to_particle_parameter_lod(buf, lod);
                    func_400107E0(buf);
                    convert_to_particle_effect_lod(lod, buf);
                }
            }
        }
    }
}

void batch_saving_particle_parameter(PtclSeg *seg) {
    char base[0x40];
    char tmp[0x40];
    int i;
    char *item;
    if (seg != 0) {
        for (i = 0; i < seg->c; i++) {
            item = (char *)seg->d + i * 0x54;
            strcpy(tmp, *(char **)item);
            strcpy(base, DEBUG_get_base_name_extention_cut(tmp));
            save_main_sub_particle_effect_lod_to_npe_file(get_main_particle_effect_lod_from_sheet(item), get_sub_particle_effect_lod_from_sheet(item), base);
        }
    }
}

void func_400107E0(char *p) {
    int i = 2;
    char *s = p + 0xC0;
    do {
        i--;
        func_40010828(s);
        s += 0x1BC;
    } while (i >= 0);
}

void func_40010828(void) {
}

char *func_40010830(void) {
    if (getseg() != 0 && D_400193B8 >= 0) {
        if (D_400193B8 < getseg()->c) {
            return (char *)getseg()->d + D_400193B8 * 0x54;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0000_batch_changing_particle_parameter", func_400108F8);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0000_batch_changing_particle_parameter", func_40010A80);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0000_batch_changing_particle_parameter", doit_particle_customize_mode);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0000_batch_changing_particle_parameter", func_40010E58);

void func_40011048(float f, PtclBlk *dst, PtclBlk *src) {
    char *dp;
    char *sp;
    int i;
    *dst = *src;
    ((float *)dst)[8] = f * ((float *)src)[8];
    ((float *)dst)[1] = f * ((float *)src)[1];
    ((float *)dst)[0x18] = f * ((float *)src)[0x18];
    ((float *)dst)[0x19] = f * ((float *)src)[0x19];
    sp = (char *)src + 0xC0;
    dp = (char *)dst + 0xC0;
    i = 2;
    do {
        i--;
        *(float *)(dp + 0x3C) = f * *(float *)(sp + 0x3C);
        *(float *)(dp + 0x40) = f * *(float *)(sp + 0x40);
        *(float *)(dp + 0x44) = f * *(float *)(sp + 0x44);
        *(float *)(dp + 0x198) = f * *(float *)(sp + 0x198);
        *(float *)(dp + 0x54) = f * *(float *)(sp + 0x54);
        *(float *)(dp + 0x18C) = f * *(float *)(sp + 0x18C);
        *(float *)(dp + 0x58) = f * *(float *)(sp + 0x58);
        *(float *)(dp + 0x5C) = f * *(float *)(sp + 0x5C);
        *(float *)(dp + 0x60) = f * *(float *)(sp + 0x60);
        *(float *)(dp + 0x64) = f * *(float *)(sp + 0x64);
        *(float *)(dp + 0x68) = f * *(float *)(sp + 0x68);
        *(float *)(dp + 0x1A4) = f * *(float *)(sp + 0x1A4);
        *(float *)(dp + 0x134) = f * *(float *)(sp + 0x134);
        *(float *)(dp + 0xC0) = f * *(float *)(sp + 0xC0);
        *(float *)(dp + 0x138) = f * *(float *)(sp + 0x138);
        *(float *)(dp + 0xC4) = f * *(float *)(sp + 0xC4);
        *(float *)(dp + 0x13C) = f * *(float *)(sp + 0x13C);
        *(float *)(dp + 0xC8) = f * *(float *)(sp + 0xC8);
        *(float *)(dp + 0x124) = f * *(float *)(sp + 0x124);
        sp += 0x1BC;
        dp += 0x1BC;
    } while (i >= 0);
}

void func_40011268(void) {
    char *p;
    int *q;
    int *r;
    if (D_400193C4 == 1) {
        p = func_40010830();
        if (p != 0) {
            q = (int *)(p + 0x48);
        } else {
            D_40019490 = 0;
            q = &D_40019490;
        }
        if (*q != 0) {
            p = func_40010830();
            if (p != 0) {
                r = (int *)(p + 0x48);
            } else {
                D_40019490 = 0;
                r = &D_40019490;
            }
            convert_to_particle_effect_lod((void *)*r, D_4002B910);
            return;
        }
    }
    if (D_400193C4 == 0) {
        p = func_40010830();
        if (p != 0) {
            q = (int *)(p + 0x4C);
        } else {
            D_40019490 = 0;
            q = &D_40019490;
        }
        if (*q != 0) {
            p = func_40010830();
            if (p != 0) {
                r = (int *)(p + 0x4C);
            } else {
                D_40019490 = 0;
                r = &D_40019490;
            }
            convert_to_particle_effect_lod((void *)*r, D_4002BF08);
            return;
        }
    }
}

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0000_batch_changing_particle_parameter", func_40011378);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0000_batch_changing_particle_parameter", func_400115D0);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0000_batch_changing_particle_parameter", func_400117B0);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0000_batch_changing_particle_parameter", func_40011A08);

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0000_batch_changing_particle_parameter", func_40011D18);
