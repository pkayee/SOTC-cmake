#include "common.h"

extern int DldSysUndefSymbol;
extern char *GetLayoutClass(void *);
extern void _gameFlagSet(int);
extern void _gameFlagCls(int);

void SCRSetMyOwnGameFlag(void *a)
{
    unsigned int *h = (unsigned int *)(*(char **)(GetLayoutClass(a) + 0x1A4) + 0x10);
    unsigned int v = *h;
    int off = v & 0x3FFFF;
    char *t = off != 0 ? *(char **)((char *)h - off) : 0;
    char *p = (t != 0 && t != (char *)DldSysUndefSymbol) ? *(char **)(t + 0x10) + ((v >> 18) & 0xFFF) * *(int *)(*(char **)(t + 8) + 0xC) : 0;
    if (p != 0)
        _gameFlagSet(*(int *)(p + 8));
}

void SCRResetMyOwnGameFlag(void *a)
{
    unsigned int *h = (unsigned int *)(*(char **)(GetLayoutClass(a) + 0x1A4) + 0x10);
    unsigned int v = *h;
    int off = v & 0x3FFFF;
    char *t = off != 0 ? *(char **)((char *)h - off) : 0;
    char *p = (t != 0 && t != (char *)DldSysUndefSymbol) ? *(char **)(t + 0x10) + ((v >> 18) & 0xFFF) * *(int *)(*(char **)(t + 8) + 0xC) : 0;
    if (p != 0)
        _gameFlagCls(*(int *)(p + 8));
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0060_SCRSetMyOwnGameFlag", nico_demoCharaScaleSync);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0060_SCRSetMyOwnGameFlag", controllerAlertScript);

s32 GAMEUTIL_get_parent_collision_attribute(u64 *attr, void *obj);

int NICO_is_quake_attack_hit(int a)
{
    u64 attr = 0;

    return GAMEUTIL_get_parent_collision_attribute(&attr, (void *)a) == 1;
}

int NICO_is_quake_attack_hit_except_boss(void *actor)
{
    u64 attr = 0;

    if (GAMEUTIL_get_parent_collision_attribute(&attr, actor) == 1 && !(attr & 1))
        return 1;
    return 0;
}

static inline int is_except_boss(void *actor)
{
    u64 attr = 0;

    if (GAMEUTIL_get_parent_collision_attribute(&attr, actor) == 1 && !(attr & 1))
        return 1;
    return 0;
}

int NICO_is_quake_attack_hit_only_boss(void *actor)
{
    return is_except_boss(actor) ^ 1;
}

extern int GAMEUTIL_is_player_obj(void *);
extern char *GetCharacterClass(void *);
extern int ControlMode_PLAYER_SWIM_DASH;

int NICO_is_hit_except_underwater(void *actor)
{
    if (GAMEUTIL_is_player_obj(actor) == 1 &&
        *(int *)(GetCharacterClass(actor) + 0x740) == ControlMode_PLAYER_SWIM_DASH)
        return 0;
    return 1;
}

int is_LwsOrientObj(void *arg0)
{
    return (*(unsigned char *)((char *)(arg0) + 8)) == 0x16;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0060_SCRSetMyOwnGameFlag", func_40057D98);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0060_SCRSetMyOwnGameFlag", func_40057ED0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0060_SCRSetMyOwnGameFlag", func_40058280);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0060_SCRSetMyOwnGameFlag", func_40058620);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0060_SCRSetMyOwnGameFlag", func_400588A0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0060_SCRSetMyOwnGameFlag", func_40058BE8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0060_SCRSetMyOwnGameFlag", func_40059108);
