#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0047_bootscelogo", bootscelogo);

extern s32 ScriptSpriteMenuObjDef_SPRITE_SCE_LOGO_LAYOUT;
void _SCRStartSpriteMenuAnim(s32 obj, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5);

void bootscelogoscript(s32 a, s32 b)
{
    _SCRStartSpriteMenuAnim(ScriptSpriteMenuObjDef_SPRITE_SCE_LOGO_LAYOUT, 0, 0, a, b, 0);
}

extern void RequestCharacterMotionShiftFunc(void *character, void (*func)(void *character));
extern void func_4004A408(void *character);
extern void func_4004A448(void *character);

void SCRBossDebugDeath(void *character)
{
    RequestCharacterMotionShiftFunc(character, &func_4004A408);
}

void SCRMammothBreaksWall(void *character)
{
    RequestCharacterMotionShiftFunc(character, func_4004A448);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0047_bootscelogo", func_4004A408);
extern s32 ScrIntrDef_DEAD_BOSS;
void *SCRGetBossWork(void *actor);
void scriptIntrSignal();

void func_4004A408(void *character)
{
    void *work;

    work = SCRGetBossWork(character);
    *(s32 *)((u8 *)work + 0x44) = 0;
    work = SCRGetBossWork(character);
    *(s32 *)((u8 *)work + 0xEC) = 1;
    scriptIntrSignal(ScrIntrDef_DEAD_BOSS);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0047_bootscelogo", func_4004A448);
extern s32 GameObject_PROTO_WALL;
extern void _SCRStartLWS(s32, s32, s32, s32);

void func_4004A448(void *character)
{
    _SCRStartLWS(*(s32 *)(GameObject_PROTO_WALL + 8), -1, 6, 0);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0047_bootscelogo", func_4004A478);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0047_bootscelogo", character_ikcolsearch);
