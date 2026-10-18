#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0200_SendDamageLetter", SendDamageLetter);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0200_SendDamageLetter", SendDamageCylinderLetter);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0200_SendDamageLetter", SendDamageBoxLetter);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0200_SendDamageLetter", SendDirectDamageLetter);

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

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0200_SendDamageLetter", CheckDamageLetter);

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

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0200_SendDamageLetter", func_400F84C0);

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
