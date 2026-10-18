#include "common.h"

s32 _gameIWorkChk(s32 idx);
void _gameIWorkSet(s32 idx, s32 val);
extern s32 DldSysUndefSymbol;
extern char *getSCRDataCtrlWork(void *);

s32 startHintWork(void)
{
    if (_gameIWorkChk(14) == -1)
    {
        _gameIWorkSet(14, 0);
    }
}

s32 SCRConditionHintPlayFunc(void *a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 i, u32 *h)
{
    s32 *hint = (s32 *)(getSCRDataCtrlWork(a) + 0x40C0);
    u32 v = *h;
    s32 voff = v & 0x3FFFF;
    char *t = voff != 0 ? *(char **)((char *)h - voff) : 0;
    char *p = (t != 0 && t != (char *)DldSysUndefSymbol) ? *(char **)(t + 0x10) + ((v >> 18) & 0xFFF) * *(s32 *)(*(char **)(t + 8) + 0xC) : 0;

    if (hint[0] != 0 && _gameIWorkChk(14) != -1 && _gameIWorkChk(14) < hint[1] && p == (char *)hint[0] + _gameIWorkChk(14) * 28 && hint[4] != 0)
        return 1;
    return 0;
}

s32 SCRConditionHintOverPlayCount(void *a, s32 b)
{
    return !(*(s32 *)(getSCRDataCtrlWork(a) + 0x40C8) < b);
}

s32 SCRConditionHintEqualPlayCount(void *a, s32 b)
{
    return b == *(s32 *)(getSCRDataCtrlWork(a) + 0x40C8);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0231_startHintWork", updateInterestWork);

void initInterestWork(s32 xa0, char *pa1)
{
    *(s32 *)(pa1 + 0x8) = -1;
    *(s32 *)(pa1 + 0x0) = 0;
    *(s32 *)(pa1 + 0x4) = 0;
    *(s32 *)(pa1 + 0xC) = 0;
}

s32 getInterestExec(s32 *xa0)
{
    return *xa0 != 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0231_startHintWork", updatePerceptionWork);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0231_startHintWork", perceptionExec);
