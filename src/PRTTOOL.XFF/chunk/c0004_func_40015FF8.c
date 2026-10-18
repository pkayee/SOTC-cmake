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

extern int D_4002B9D8;

typedef struct {
    char *name;
    int unk4;
    int symIdx;
} ParticleTexEntry;
extern ParticleTexEntry g_ainParticleTextureStore[];
extern u8 padManagerData[];
extern char D_4002B8B0[];
extern int is_proper_particle_texture_id(int);
extern char *GetSymbolByIndex(int, int);
extern int strcmp(const char *, const char *);
extern void isysInitGroup(void *);
extern void isysAddGroupWithLinkParam(int, void *, int, int);
extern void texTool(char *, int, void *);

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

char *func_400166E8(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + 0x3C;
}

char *func_40016718(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + 0x24;
}

char *func_40016748(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + 0x54;
}

char *func_40016778(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + 0x5C;
}

char *func_400167A8(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + 0x58;
}

char *func_400167D8(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + 0xA0;
}

char *func_40016808(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + 0xA4;
}

char *func_40016838(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + 0xA8;
}

char *func_40016868(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + 0x68;
}

char *func_40016898(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + 0x9C;
}

char *func_400168C8(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + 0xAC;
}

char *func_400168F8(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + 0xC0;
}

char *func_40016928(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + 0x94;
}

char *func_40016958(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + 0x98;
}

char *func_40016988(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + 0xD4;
}

int *func_400169B8(void) {
    return &D_4002B9D8;
}

void func_400169C8(void) {
}

void func_400169D0(u8 *param_1) {
    ParticleTexEntry *e;
    char *b;
    if ((*(s32 *)(padManagerData + 8) & 0x20) && (b = D_4002B910, is_proper_particle_texture_id(*(int *)(b + 0xC8)) == 1)) {
        e = &g_ainParticleTextureStore[*(int *)(b + 0xC8)];
        if (strcmp(e->name, GetSymbolByIndex(e->symIdx, 0)) == 0) {
            isysInitGroup(D_4002B8B0);
            isysAddGroupWithLinkParam(e->symIdx, D_4002B8B0, 0, 0);
            texTool(e->name, *(int *)(param_1 + 0x94), D_4002B8B0);
        }
    }
    return;
}

char *func_40016A98(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + 0x6C;
}

char *func_40016AC8(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + 0x70;
}

char *func_40016AF8(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + 0x74;
}

char *func_40016B28(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + 0x78;
}

char *func_40016B58(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + 0x7C;
}

char *func_40016B88(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + 0x90;
}

char *func_40016BB8(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + 0x80;
}

char *func_40016BE8(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + 0x84;
}

char *func_40016C18(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + 0x88;
}

char *func_40016C48(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + 0x8C;
}

char *func_40016C78(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + 0x48;
}

char *func_40016CA8(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + 0x4C;
}

char *func_40016CD8(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + 0xB0;
}

char *func_40016D08(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + 0xB4;
}

char *func_40016D38(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + 0xB8;
}

char *func_40016D68(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + 0x1C;
}

char *func_40016D98(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + 0xD0;
}

char *func_40016DC8(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0xC4;
}

char *func_40016E18(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0xDC;
}

char *func_40016E68(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0xE0;
}

char *func_40016EB8(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0xCC;
}

char *func_40016F08(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0xD8;
}

char *func_40016F58(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0xE4;
}

char *func_40016FA8(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0xE8;
}

char *func_40016FF8(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x1D8;
}

char *func_40017048(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x1DC;
}

char *func_40017098(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0xEC;
}

char *func_400170E8(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0xF0;
}

char *func_40017138(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0xF4;
}

char *func_40017188(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0xF8;
}

char *func_400171D8(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0xFC;
}

char *func_40017228(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x100;
}

char *func_40017278(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x104;
}

char *func_400172C8(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x108;
}

char *func_40017318(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x254;
}

char *func_40017368(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x258;
}

char *func_400173B8(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x25C;
}

char *func_40017408(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x10C;
}

char *func_40017458(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x110;
}

char *func_400174A8(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x248;
}

char *func_400174F8(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x114;
}

char *func_40017548(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x24C;
}

char *func_40017598(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x118;
}

char *func_400175E8(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x11C;
}

char *func_40017638(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x120;
}

char *func_40017688(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x124;
}

char *func_400176D8(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x128;
}

char *func_40017728(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x12C;
}

char *func_40017778(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x260;
}

char *func_400177C8(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x264;
}
