#include "common.h"

extern int DeleteTwoWayLink();
extern char MicroCode[];

int DeleteSubLinkObjLink(unsigned char *p)
{
    char *c = p[8] != 0x15 ? 0 : (char *)p + 0x1C;

    return DeleteTwoWayLink(c);
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0129_DeleteSubLinkObjLink", DeleteSubLinkObjLink);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0129_DeleteSubLinkObjLink", CreateSubLinkObjByGeometryPointer);

/* NEARMISS-STUB func_400A75E8 */
#if 0 /* NEARMISS 76.67% cat=stack-frame sub=- | frame 0x20 vs 0x30: asm keeps p and 0x15 in s1/s3 across call; xori imm used | attempts=1 */
int func_400A75E8(unsigned char *p)
{
    int t = 0x15;
    char *q = (char *)p + 0x1C;
    char *c = (p[8] ^ t) != 0 ? 0 : q;

    if (*(void (**)(void *, int))(c + 0xC) != 0)
    {
        (*(void (**)(void *, int))(c + 0xC))(p, *(int *)(c + 0x10));
        *(int *)(c + 0xC) = 0;
    }
    c = (p[8] ^ t) != 0 ? 0 : q;

    return DeleteTwoWayLink(c);
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0129_DeleteSubLinkObjLink", func_400A75E8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0129_DeleteSubLinkObjLink", InitSubLinkObj);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0129_DeleteSubLinkObjLink", ViewIntervalClip);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0129_DeleteSubLinkObjLink", InitViewIntervalClip);

void InitViewIntervalClip(char *c)
{
    *(int *)(c + 0x10B4) = 0;
    *(float *)(c + 0x10B8) = -0.0333333313465118408203125f;
    *(int *)(c + 0x10BC) = 0;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0129_DeleteSubLinkObjLink", FlushRequestViewIntervalClip);

extern void *GetCharacterClass(void *);

void FlushRequestViewIntervalClip(void *actor)
{
    (*(float *)((char *)(GetCharacterClass(actor)) + 0x10BC)) = -1.0f;
}

int getMicroCodeAddress(int i)
{
    return ((int *)MicroCode)[i];
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0129_DeleteSubLinkObjLink", transMicroCode);

extern int iosDlGetLayer();
extern void iosDlChainTailCurrent();
extern int D_401AD4E8[];

void transMicroCode(int param_1)
{
    int iVar1;

    iVar1 = iosDlGetLayer();
    if (D_401AD4E8[iVar1] != param_1)
    {
        iosDlChainTailCurrent(((int *)MicroCode)[param_1]);
        D_401AD4E8[iVar1] = param_1;
    }
    return;
}

extern int D_401AD4E8[];

void resetMicroCodeManager(void)
{
    int i;
    for (i = 0; i < 32; i++)
        D_401AD4E8[i] = 0xD;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0129_DeleteSubLinkObjLink", resetMicroCodeManager);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0129_DeleteSubLinkObjLink", func_400A7AE0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0129_DeleteSubLinkObjLink", func_400A7FC8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0129_DeleteSubLinkObjLink", func_400A8358);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0129_DeleteSubLinkObjLink", func_400A8608);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0129_DeleteSubLinkObjLink", func_400A88C0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0129_DeleteSubLinkObjLink", func_400A8B70);
