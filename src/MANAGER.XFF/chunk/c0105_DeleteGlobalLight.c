#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0105_DeleteGlobalLight", DeleteGlobalLight);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0105_DeleteGlobalLight", func_4008CD28);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0105_DeleteGlobalLight", GlobalLightConsistencyWorkGrp);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0105_DeleteGlobalLight", func_4008D000);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0105_DeleteGlobalLight", ExecGlobalLightMan);

char *GetGlobalLightClass(unsigned char *p)
{
    if (p[0x8] != 0x19)
    {
        return 0;
    }
    return (char *)p + 0x20;
}

void deleteGlobalLightObj(void) {
}

extern char *GetLightColMan(void *);
extern void isysAddGroupWithLinkParam(void *, void *, int, int);
extern void _isysDeleteGroup(void *, void *, int);

void ForceDelGlobalLighObj(unsigned char *o)
{
    char *man = GetLightColMan(o);
    unsigned char *c = o[8] == 0x19 ? o + 0x20 : 0;
    int i;

    *(int *)(c + 0x110) = 0;
    for (i = 2; i >= 0; i--)
        *(int *)(c + 0x2C + i * 0x40) = 0;
    isysAddGroupWithLinkParam(o, man + 0x514, 0, 0);
    _isysDeleteGroup(o, man + 0x51C, 0);
}
