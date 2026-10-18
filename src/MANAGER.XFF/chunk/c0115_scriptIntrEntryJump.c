#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0115_scriptIntrEntryJump", scriptIntrEntryJump);

void isysDeleteGroupWithLinkParam(s32 obj, void *group, s32 a2, s32 flag);

void scriptIntrDeleteJump(char *s, s32 a, s32 c)
{
    if (*(s32 *)(s + 4) & 1)
        isysDeleteGroupWithLinkParam(a, s + 8, c, 0);
}

s32 func_40097B10(s32 p);
s32 isysDeleteAllGroup(s32 obj, s32 (*func)(s32), s32 a2, s32 flag);

s32 scriptIntrAllDeleteJump(s32 a, s32 b, s32 c, s32 d)
{
    return isysDeleteAllGroup(a, func_40097B10, c, d);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0115_scriptIntrEntryJump", scriptIntrEntryChildThread);

void scriptIntrDeleteChildThread(u64 *s, s32 a, s32 c)
{
    if ((int)(*s >> 33) & 1)
        isysDeleteGroupWithLinkParam(a, (char *)s + 0x10, c, 0);
}

s32 func_40097B38(s32 p);

s32 scriptIntrAllDeleteSubThread(s32 a, s32 b, s32 c, s32 d)
{
    return isysDeleteAllGroup(a, func_40097B38, c, d);
}

void scriptIntrSegInit(void) {
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0115_scriptIntrEntryJump", scriptIntrSegDelete);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0115_scriptIntrEntryJump", func_40097B10);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0115_scriptIntrEntryJump", func_40097B38);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0115_scriptIntrEntryJump", func_40097B60);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0115_scriptIntrEntryJump", func_40097CC0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0115_scriptIntrEntryJump", SetScriptAnimationObjAccessSwitch);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0115_scriptIntrEntryJump", func_40097FC0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0115_scriptIntrEntryJump", StartAnimationSubObjInfinitePart);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0115_scriptIntrEntryJump", func_400983E0);
