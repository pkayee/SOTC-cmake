#include "common.h"

extern char D_40134288[];

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0173_mcManager", mcManager);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0173_mcManager", mcWrite);

void mcRead(u8 *m, s32 buf, s32 n)
{
    s32 v;

    v = *(s32 *)(m + 0x30) + n;
    *(s32 *)(m + 0x30) = v;
    if (*(s32 *)(m + 0x28) < v) {
        LoaderSysPrintf(D_40134288);
    }
    iosMcReadFile(*(s32 *)(m + 0x20), *(s32 *)(m + 0x24), m, buf, *(s32 *)(m + 0x2c), n);
    *(s32 *)(m + 0x2c) = *(s32 *)(m + 0x2c) + n;
}

extern int D_401B1744;

void mcReqSetWaitFunc(int arg0)
{
    D_401B1744 = arg0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0173_mcManager", mcGetInfo);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0173_mcManager", mcGetMainDataInfo);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0173_mcManager", mcSaveGameData);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0173_mcManager", mcLoadGameData);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0173_mcManager", mcDeleteGameData);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0173_mcManager", mcLoadOptionData);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0173_mcManager", mcFormat);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0173_mcManager", mcUnformat);

extern float D_4012BB38;

float mcGetProcessPer(void)
{
    return D_4012BB38;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0173_mcManager", mcDirectFileCreate);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0173_mcManager", mcDirectFileDelete);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0173_mcManager", mcDirectFileWrite);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0173_mcManager", mcDirectFileRead);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0173_mcManager", mcReqGetDir);

/* NEARMISS-STUB mcGetLastSaveGameDataIndex */
#if 0 /* NEARMISS 86.65625% cat=branch-layout sub=- | loop tail/early return layout and -1 test reg differ; arg copy/const order | attempts=1 */
extern s64 *D_4012BB3C;

s32 mcGetLastSaveGameDataIndex(u8 *arg0)
{
    s32 i;
    u8 *p;

    if (D_4012BB3C != 0) {
        i = 0;
        p = arg0 + 0xD8;
        do {
            if (*(s32 *)(p + 0xC) == 1 && *D_4012BB3C == *(s64 *)(p + 0x40)) {
                return i;
            }
            i++;
            p += 0x98;
        } while (i < 10);
    }
    if (*(s32 *)(arg0 + 0x4C) != 0) {
        return *(s32 *)(arg0 + 0x50);
    }
    return -1;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0173_mcManager", mcGetLastSaveGameDataIndex);

extern int D_4012BB40;

int mcGetGameClearFlag(void)
{
    return D_4012BB40;
}

void mcSetGameClearFlag(void)
{
    D_4012BB40 = 1;
}

extern int D_4012BB44;
extern int D_4012BB48;

void mcGetCompleteTimeAttack(int *arg0, int *arg1)
{
    *arg0 = D_4012BB44;
    *arg1 = D_4012BB48;
}

void mcSetCompleteTimeAttack(int arg0, int arg1)
{
    if (arg0 != 0) {
        D_4012BB44 = 1;
    }
    if (arg1 != 0) {
        D_4012BB48 = 1;
    }
}
