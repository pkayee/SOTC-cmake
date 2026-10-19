#include "common.h"

typedef union {
    s32 i;
    float f;
} DmgW;
extern void func_400F7880(char *, void *);
extern void CopyGeometryPointer(void *, void *);

/* READY MANAGER c0200 SendDamageLetter: 100.0 in scratch (rea-mgr-c0200, 2026-10-19). Local DECLARATION ORDER u, w, d fixes the frame (u at 0, w at 0x20, d at 0x40); w is a union of the 24 byte pos struct and one s128 so the later lq/sq reuses its slot; memcpy extern void memcpy(); not prototyped. */
extern s32 D_4012E37C;
extern void *memset(void *, s32, u32);
extern s32 create_letter(void *, void *, s32, s32, s32);
extern void init_letter(s32, void *, void *);
extern void send_letter(void *);
extern void memcpy();
extern void func_400F6900();
extern u8 IdentityQuaternion[];
extern void SetGeometryPointerGlobalState(void *, void *, void *);
typedef struct {
    s32 kind;
    s32 pad[3];
    s32 a;
    s32 c;
    s32 pad2[2];
    u8 geom[0x40];
} DmgBody;
typedef struct {
    s32 a;
    float v[4];
    s32 c;
} DmgPos;

extern s32 D_4012E378;
extern void func_400F86C0();
typedef struct {
    s32 kind;
    s32 pad[3];
    s32 a;
    float f;
    float g;
    s32 pad2;
    u8 geom[0x40];
} DmgData;

extern u64 *GetCollisionDBAttributeAdr(void);

void SendDamageLetter(s32 a, s32 b, s32 c, float *p)
{
    DmgPos u;
    union {
        DmgPos t;
        s128 q;
        float f[4];
    } w;
    DmgBody d;
    void **post = 0;
    void *data = 0;
    void **pp;
    s32 letter;
    letter = create_letter(&post, &data, D_4012E37C, 0, b);
    w.t.a = a;
    w.t.v[0] = p[0];
    w.t.v[1] = p[1];
    w.t.v[2] = p[2];
    w.t.v[3] = p[3];
    w.t.c = c;
    u = w.t;
    d.kind = 0;
    memset(&d.a, 0, 0x50);
    w.q = *(s128 *)p;
    w.f[3] = 1.0f;
    d.a = a;
    d.c = c;
    SetGeometryPointerGlobalState(d.geom, IdentityQuaternion, &w);
    pp = post;
    *pp = func_400F6900;
    memcpy(pp + 4, &u, 0x18);
    memcpy(data, &d, 0x60);
    init_letter(letter, &post, &data);
    send_letter(&letter);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0200_SendDamageLetter", SendDamageCylinderLetter);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0200_SendDamageLetter", SendDamageBoxLetter);

/* READY MANAGER c0200 SendDirectDamageLetter: 100.0 in scratch (rea-mgr-c0200, 2026-10-19). memcpy MUST be declared K and R style extern void memcpy(); (the prototyped form is expanded inline by gcc, 27 percent); post pointer copied to a local pp (a second load of post after the store gives 91 percent). */
void SendDirectDamageLetter(s32 a, s32 b, void *geom, s32 n, float f)
{
    DmgData d;
    void **post = 0;
    void *data = 0;
    void **pp;
    s32 letter;
    letter = create_letter(&post, &data, D_4012E378, b, 0);
    d.kind = 1;
    memset(&d.a, 0, 0x50);
    d.a = a;
    d.f = f;
    d.g = (float)n;
    CopyGeometryPointer(d.geom, geom);
    pp = post;
    *pp = func_400F86C0;
    memcpy(pp + 4, 0, 0);
    memcpy(data, &d, 0x60);
    init_letter(letter, &post, &data);
    send_letter(&letter);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0200_SendDamageLetter", SendVolumeShapeDamageLetter);

extern void open_letter_post(void *);
extern void *get_next_letter_in_post(void *);
extern void *get_letter_contents_data(void *);
extern void close_letter_post(void *);

void CheckLetter(char *o, void (*cb)(char *, void *))
{
    void *post = *(void **)(o + 0x1C);
    void *l;
    open_letter_post(post);
    while ((l = get_next_letter_in_post(post)) != 0)
        cb(o, get_letter_contents_data(l));
    close_letter_post(post);
}

extern char *GetCharacterClass(void *);
extern char *GetScriptLayoutClass(void *);
extern char *GetScriptAnimationClass(void *);

char *GetDamageClass(char *o)
{
    switch (((unsigned char *)o)[8]) {
    case 9:
        return GetCharacterClass(o) + 0x200;
    case 0xB:
        return GetScriptLayoutClass(o) + 0x230;
    case 0xD:
        return GetScriptAnimationClass(o) + 0x230;
    case 0x16:
        return o + 0x290;
    }
    return 0;
}

/* READY MANAGER c0200 CheckDamageLetter: 100.0 in scratch (rea-mgr-c0200, 2026-10-19). Letter kind 1 handler with the GetDamageClass switch inlined by hand; case 1 listed BEFORE case 0 (T37), float field stored as int through a union (T38). */
s32 CheckDamageLetter(char *o, s32 *l)
{
    char *c;
    DmgW *p;
    switch (l[0]) {
    case 1:
        p = (DmgW *)(l + 4);
        switch (((unsigned char *)o)[8]) {
        case 9:
            c = GetCharacterClass(o) + 0x200;
            break;
        case 0xB:
            c = GetScriptLayoutClass(o) + 0x230;
            break;
        case 0xD:
            c = GetScriptAnimationClass(o) + 0x230;
            break;
        case 0x16:
            c = o + 0x290;
            break;
        default:
            c = 0;
            break;
        }
        *(s32 *)(c + 0x50) = 0;
        *(float *)(c + 0x5C) = p[1].f;
        ((DmgW *)(c + 0x60))->i = (s32)p[2].f;
        if (p[0].i == (s32)o) {
            *(s32 *)c = 2;
        } else {
            *(s32 *)c = 3;
            CopyGeometryPointer(c + 0x10, p + 4);
        }
        break;
    case 0:
        func_400F7880(o, l + 4);
        break;
    }
    return 0;
}

extern s128 ZeroPoint;

void InitDamageClass(char *p)
{
    *(s32 *)(p + 0x54) = -1;
    *(s32 *)(p + 0x58) = 0;
    *(s32 *)p = 0;
    *(s32 *)(p + 0x5C) = 0;
    *(s32 *)(p + 0x60) = -1;
    *(s32 *)(p + 0x6C) = -1;
    *(s32 *)(p + 0x64) = 0;
    *(s32 *)(p + 0x68) = 0;
    *(s128 *)(p + 0x80) = ZeroPoint;
    *(s32 *)(p + 0x90) = 0;
    *(s32 *)(p + 0x70) = 0;
    *(s32 *)(p + 0x94) = 0;
}

void ResetDamageClass(char *d)
{
    *(s32 *)(d + 0x54) = -1;
    *(s32 *)(d + 0x58) = 0;
    *(s32 *)d = 0;
    *(s32 *)(d + 0x5C) = 0;
    *(s32 *)(d + 0x64) = 0;
    *(s32 *)(d + 0x60) = -1;
    *(s32 *)(d + 0x68) = 0;
}

s32 SetDamageOffsetStatus(char *d, s32 type, s128 *ofs, f32 scale)
{
    *(s32 *)(d + 0x6C) = type;
    if (ofs != 0) {
        *(s128 *)(d + 0x80) = *ofs;
        *(s32 *)(d + 0x70) = 1;
    } else {
        *(s32 *)(d + 0x70) = 0;
    }
    *(f32 *)(d + 0x90) = scale;
    return 0;
}

s32 SetDamageClassJudgeExternalFunc(void *arg0, s32 arg1)
{
    (*(s32 *)((char *)(arg0) + 0x94)) = arg1;
    return 1;
}

typedef struct {
    int flag;
    char pad4[0x50];
    int state;
    float time;
    float time_prev;
    int count;
    float zero;
    float rate;
} DamageLock;

void DecreaseDamageLockTime(DamageLock *lock, float dt)
{
    lock->zero = 0.0f;
    lock->flag = 0;
    if (lock->state >= 0) {
        lock->time -= dt;
        if (lock->time < lock->zero) {
            lock->time = lock->zero;
            lock->time_prev = lock->zero;
            lock->state = -1;
            lock->count = -1;
            lock->rate = lock->zero;
        }
    }
}

extern s32 D_4012E380;

s32 GetDamagerClassDamageSheetType(void *arg0)
{
    return *(s32 *)((char *)((D_4012E380 * 8) + *(s32 *)((char *)arg0 + 0x50)) + 0x10);
}

s32 SetDamageClassDamageTableType(s32 a)
{
    return D_4012E380 = a;
}

extern s32 entry_new_letter_type(void *);
extern s32 D_40135440[];
extern s32 D_40135458[];
extern s32 D_4012E378;
extern s32 D_4012E37C;

void InitDamageLetter(void)
{
    D_4012E378 = entry_new_letter_type(D_40135440);
    D_4012E37C = entry_new_letter_type(D_40135458);
}

/* READY MANAGER c0200 func_400F84C0: 100.0 in scratch (rea-mgr-c0200, 2026-10-19). u64 collision attribute; masks 0xF80000000 and 0x7C000000, any listed value returns 0 else 1. */
s32 func_400F84C0(void)
{
    u64 v = *GetCollisionDBAttributeAdr();
    u64 a = v & 0xF80000000;
    u64 b = v & 0x7C000000;
    if (a == 0x300000000 || a == 0x500000000 || a == 0x280000000 || a == 0x200000000 ||
        a == 0xB80000000 || a == 0x380000000 || a == 0x800000000 || a == 0x100000000 ||
        b == 0x30000000 || b == 0x34000000 || b == 0x6C000000 || b == 0x24000000 ||
        b == 0x64000000 || b == 0x68000000)
        return 0;
    return 1;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0200_SendDamageLetter", func_400F85A8);
typedef void (*DamageCallback)(void *, void *);

void func_400F85A8(void *arg0, void **arg1)
{
    ((DamageCallback)arg1[0])(arg0, arg1 + 4);
    return;
}

extern void *memset(void *, s32, u32);

void *func_400F85C8(s32 *arg0)
{
    *arg0 = 0;
    return memset(arg0 + 4, 0x7E, 0x40);
}
