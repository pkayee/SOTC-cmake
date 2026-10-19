#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0066_effectSetDamageWork", effectSetDamageWork);

/* NEARMISS-STUB effect_blood_init */
#if 0 /* NEARMISS 98.97% cat=regalloc sub=- | d2 r103: stores D8=f,D4=e,D0=d,DC=n,E0[0..2]=a,b,c (Ghidra order) give everything but f21/f23 swap (target c->f21, e->f23); ~25 other store orders and a p=(f32* | attempts=1 */
extern float D_401315D0;
extern unsigned char D_401315D4[];
extern unsigned char D_401315D8[];
extern s32 D_401315DC;
extern unsigned char D_401315E0[];
extern u8 D_40203290[];
extern u8 InitialGeometryPointer[];
extern void *iosMallocAlign(void *, s32, s32);
extern void CopyGeometryPointer(void *, void *);

void *effect_blood_init(f32 a, f32 b, f32 c, f32 d, f32 e, f32 f, void *heap, s32 n)
{
    u8 *w = iosMallocAlign(heap, n * 0x30, 0x10);
    s32 i;

    *(f32 *)D_401315D8 = f;
    *(f32 *)D_401315D4 = e;
    D_401315D0 = d;
    D_401315DC = n;
    *(f32 *)(D_401315E0 + 0) = a;
    *(f32 *)(D_401315E0 + 4) = b;
    *(f32 *)(D_401315E0 + 8) = c;
    for (i = 0; i < n; i++) {
        *(s32 *)(w + i * 0x30 + 0x24) = 0;
    }
    CopyGeometryPointer(D_40203290, InitialGeometryPointer);
    return w;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0066_effectSetDamageWork", effect_blood_init);

extern void iosFree(void *);

void effect_blood_free(void *allocation)
{
    iosFree(allocation);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0066_effectSetDamageWork", effect_blood_frame);

extern u8 D_40203290[];
extern float D_401315D0;
extern u8 *GetCharacterClass(void *chara);
extern s32 *GetDamageClass(void *obj);
extern void GetGeometryPointerPosition(float *, void *);
extern void func_4005FAF8(void *, u8 *, s32, float *, s32, s32, float, float);

void effect_blood_set(void *obj, void *target, float scale)
{
    char *c = GetCharacterClass(obj);
    float pos[4] __attribute__((aligned(16)));

    if (*GetDamageClass(obj) == 3) {
        int **m;

        GetGeometryPointerPosition(pos, D_40203290);
        m = *(int ***)(c + 0x144);
        func_4005FAF8(target, c, *(int *)((char *)m[0] + 0x20), pos, *(int *)((char *)m[3] + 0x104),
                      *(short *)(c + 0x1B4), D_401315D0, scale);
    }
}

extern int D_40131770[];
extern void createParamMenu(void *, int);

void createBossBloodParamMenu(void)
{
    if (D_40131770[12] == 0)
        createParamMenu(D_40131770, 0);
}

int getEffectBloodWorkSize(int arg0)
{
    return (arg0 * 0x30) + 0x33;
}

typedef struct
{
    float v;
    u8 pad[0x74];
} WeakPointEffect;

extern WeakPointEffect D_402032E4[];

float getWeakPointEffectIntensity(int i)
{
    return D_402032E4[i].v;
}

float getTriggerPointEffectIntensity(int index)
{
    index += 3;
    return D_402032E4[index].v;
}

/* NEARMISS-STUB boot_weakpoint_effect */
#if 0 /* NEARMISS 99.81% cat=regalloc sub=- | d2 r103: if/else arms both store 0x10/0x18 (shared tail = crossjump 90.9), arm1 store order 0x18,0x10,0x74,0x70; only f21/f22 swap: target y(f13)->f22, z(f14)-> | attempts=1 */
extern s32 D_402032D0[];
extern s32 D_401317B0;
extern u8 gcGlobalVar[];
extern u8 rootPtn[];
extern u8 D_40133588[];
extern void func_4005FFE8(void *, void *);
extern void func_40061888(void *);
extern void *gcCreateScriptObj(void *, void *, void *, s32, s32, s32, void *);

void boot_weakpoint_effect(s32 *a, f32 x, f32 y, f32 z)
{
    u8 *e = (u8 *)D_402032D0 + a[1] * 0x78;

    if (D_401317B0 == 0) {
        return;
    }
    if (*(s32 *)(e + 0xC) == 0) {
        if (x == 0.0f) {
            return;
        }
        *(s32 *)(e + 0x0) = a[0];
        *(s32 *)(e + 0xC) = 1;
        *(s32 *)(e + 0x8) = a[1];
        func_4005FFE8(e, a + 4);
        gcCreateScriptObj(func_40061888, e, rootPtn, 0x1000, 0, 8, D_40133588);
        *(f32 *)(e + 0x18) = *(f32 *)(gcGlobalVar + 0x178); *(f32 *)(e + 0x10) = x; *(f32 *)(e + 0x74) = z; *(f32 *)(e + 0x70) = y;
    } else {
        *(f32 *)(e + 0x10) = x;
        *(f32 *)(e + 0x18) = *(f32 *)(gcGlobalVar + 0x178);
    }
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0066_effectSetDamageWork", boot_weakpoint_effect);

extern s32 D_402032D0[];
extern s32 D_401317B0;
extern s32 SParticleSheetData_S_WEAKNESS_CONTACT;
extern s32 SParticleSheetData_S_TRIGGER_CONTACT;
extern s32 get_particle_effect_id_from_sheet(s32);
extern s32 boot_particle_emitter(s32, void *, void (*)(u8 *), void *);
extern s32 get_particle_emitter_from_emitter_id(s32);
extern void func_400619D8(u8 *);

void boot_weakpoint_hit_effect(s32 *a)
{
    s32 *pos = a + 4;

    if (D_401317B0 != 0) {
        s32 k = a[0];
        u8 *e = (u8 *)D_402032D0 + a[1] * 0x78;
        s32 *em = (s32 *)(e + 0x5C);

        *(s32 *)e = k;
        {
            s32 ids[2] = { SParticleSheetData_S_WEAKNESS_CONTACT, SParticleSheetData_S_TRIGGER_CONTACT };

            if (em[0] == 0) {
                em[0] = boot_particle_emitter(get_particle_effect_id_from_sheet(ids[k]), pos, func_400619D8, e);
                em[1] = get_particle_emitter_from_emitter_id(em[0]);
                em[2] = 1;
            }
        }
    }
}

extern u128 ZeroPoint;
extern u128 IdentityQuaternion;
extern void func_40060280(void *, s32);
extern void SetGeometryPointerGlobalState(void *, void *, void *);
extern s32 stop_particle_emitter_geometry_pointer_reference(s32, s32);
extern void end_particle_emitter(s32, s32, s32);
extern void func_4005FF20(void);

static inline void weakpointEffectStop(s32 *e)
{
    s32 ids[2] = { SParticleSheetData_S_WEAKNESS_CONTACT, SParticleSheetData_S_TRIGGER_CONTACT };

    if (e[0x17] != 0) {
        SetGeometryPointerGlobalState((u8 *)e[0x18] + 0xD0, &ZeroPoint, &IdentityQuaternion);
        stop_particle_emitter_geometry_pointer_reference(get_particle_effect_id_from_sheet(ids[e[0]]), e[0x17]);
        end_particle_emitter(get_particle_effect_id_from_sheet(ids[e[0]]), e[0x17], 0);
        e[0x19] = 3;
        e[0x1A] = (s32)e;
    }
}

void init_weakpoint_effect(void)
{
    s32 *e = D_402032D0;
    s32 i;

    for (i = 7; i >= 0; i--, e += 0x1E) {
        func_40060280(e, 1);
        weakpointEffectStop(e);
    }
    func_4005FF20();
    D_401317B0 = 1;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0066_effectSetDamageWork", fadeout_weakpoint_effect);
extern s32 D_402032D0[];

void fadeout_weakpoint_effect(void)
{
    s32 two = 2;
    s32 *p = D_402032D0;
    s32 i = 7;

    do {
        i--;
        p[4] = 0;
        p[1] = two;
        p += 0x1E;
    } while (i >= 0);
}

void end_weakpoint_effect(void)
{
    s32 *e = D_402032D0;
    s32 i;

    for (i = 7; i >= 0; i--, e += 0x1E) {
        func_40060280(e, 1);
        weakpointEffectStop(e);
    }
    D_401317B0 = 0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0066_effectSetDamageWork", effect_death);
extern u8 *GetLayoutClass();
extern void func_40060A68(u8 *, s32, float *, s32, s16);

void effect_death(void)
{
    float pos[4] __attribute__((aligned(16)));
    u8 *c = GetLayoutClass();
    int **m;

    GetGeometryPointerPosition(pos, D_40203290);
    m = *(int ***)(c + 0x144);
    func_40060A68(c, *(int *)((char *)m[0] + 0x20), pos, *(int *)((char *)m[3] + 0x104), *(short *)(c + 0x1B4));
    return;
}

extern int D_40203288;

void effectClearDamageWork(void)
{
    D_40203288 = 0;
}

extern unsigned char D_40202FE0[];

int effectGetDamageWork(void **arg0)
{
    *arg0 = D_40202FE0;
    return (*(int *)((char *)(D_40202FE0) + 0x2A8));
}

extern unsigned char D_401315F4[];

void *getBloodEffectEnableFlag(void)
{
    return D_401315F4;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0066_effectSetDamageWork", func_40061720);
extern unsigned char D_401315E0[];

void *func_40061720(void)
{
    return D_401315E0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0066_effectSetDamageWork", func_40061730);
extern unsigned char D_401315E4[];

void *func_40061730(void)
{
    return D_401315E4;
}

extern unsigned char D_401315E8[];

void *func_40061740(void)
{
    return D_401315E8;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0066_effectSetDamageWork", func_40061750);
void *func_40061750(void)
{
    return &D_401315D0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0066_effectSetDamageWork", func_40061760);
extern unsigned char D_401315D4[];

void *func_40061760(void)
{
    return D_401315D4;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0066_effectSetDamageWork", func_40061770);
extern unsigned char D_401315D8[];

void *func_40061770(void)
{
    return D_401315D8;
}

extern unsigned char D_401317A4[];

void *getWeakGlowSpeed(void)
{
    return D_401317A4;
}

extern unsigned char D_401317A8[];

void *getWeakGlowTime(void)
{
    return D_401317A8;
}

extern unsigned char D_401317AC[];

void *getTrigGlowTime(void)
{
    return D_401317AC;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0066_effectSetDamageWork", func_400617B0);
void func_400617B0(u8 *p)
{
    u8 *v = *(u8 **)(p + 0x50);

    *(float *)(p + 0x28) = *(float *)(p + 0x28) * *(float *)(v + 0x70);
    *(float *)(p + 0x24) = *(float *)(p + 0x24) * (*(float *)(v + 0x74) * *(float *)(v + 0x14));
}

/* NEARMISS-STUB func_400617E0 */
#if 0 /* NEARMISS 99.64% cat=sched sub=- | d2 r101: fields 4/C/10/14 are f32 0.0f (keeps the gcGlobalVar+0x178 lwc1 after them), a[0],a[1],a[2] source order gives target 8,0,4; left: target stores the s3 | attempts=1 */
extern u8 gcGlobalVar[];
extern void isysRequestDeleteObj(void *);

void func_400617E0(s32 *a)
{
    u8 *o = (u8 *)a[3];
    s32 save;
    s32 i;
    s32 *q;

    if (a[0] != 0) {
        a[0] = 0;
        a[1] = 0;
        a[2] = 0;
    }
    save = *(s32 *)(o + 8);
    if (*(void **)(o + 0x6C) != 0) {
        isysRequestDeleteObj(*(void **)(o + 0x6C));
        *(void **)(o + 0x6C) = 0;
    }
    for (i = 0, q = (s32 *)(o + 0x1C); i < 4; i++, q += 4) {
        if (*q != 0) {
            return;
        }
    }
    *(f32 *)(o + 4) = 0.0f;
    *(s32 *)(o + 8) = save;
    *(f32 *)(o + 0xC) = 0.0f;
    *(f32 *)(o + 0x10) = 0.0f;
    *(f32 *)(o + 0x14) = 0.0f;
    *(f32 *)(o + 0x18) = *(f32 *)(gcGlobalVar + 0x178);
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0066_effectSetDamageWork", func_400617E0);

/* NEARMISS-STUB func_40061888 */
#if 0 /* NEARMISS 94.33% cat=cse-hoist sub=- | d2 r103: switch 0/1/2 state loop, if (w[0]==0) A8 else AC; target addiu-forms &gcGlobalVar in v0 for the first read then loop-hoists it to s3 with consts 1,2,3  | attempts=1 */
extern unsigned char D_401317A8[];
extern unsigned char D_401317AC[];
extern u8 gcGlobalVar[];
extern s32 func_40060418(void *);
extern void scrRun(void);

void func_40061888(s32 *w)
{
    f32 limit;
    u8 *g;

    if (w[0] == 0) {
        limit = *(f32 *)D_401317A8;
    } else {
        limit = *(f32 *)D_401317AC;
    }
    w[1] = 0;
    *(f32 *)&w[6] = *(f32 *)(gcGlobalVar + 0x178);
    g = gcGlobalVar;
    while (w[3] != 0) {
        switch (w[1]) {
        case 0:
            if (func_40060418(w) != 0) {
                w[1] = 1;
                *(f32 *)&w[6] = *(f32 *)(g + 0x178);
            }
            break;
        case 1:
            func_40060418(w);
            if (limit < *(f32 *)(g + 0x178) - *(f32 *)&w[6]) {
                w[4] = 0;
                w[1] = 2;
            }
            break;
        case 2:
            if (func_40060418(w) != 0) {
                func_40060280(w, 0);
                w[1] = 3;
            }
            break;
        }
        scrRun();
    }
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0066_effectSetDamageWork", func_40061888);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0066_effectSetDamageWork", func_400619D8);
void func_400619D8(u8 *p)
{
    p += 0x5C;
    if (*(s32 *)p != 0) {
        *(s32 *)p = 0;
        *(s32 *)(p + 0x4) = 0;
        *(s32 *)(p + 0x8) = 0;
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0066_effectSetDamageWork", func_40061A00);
