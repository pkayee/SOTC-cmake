#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0088_updateParentPointGPInfo", updateParentPointGPInfo);

extern s128 ZeroPoint;
extern void charrootdyn_updateCharacterClassParentGeometry(char *, s128 *, char *);
extern void *GetGeometryPointerSurfacePlane(char *);
extern void charrootdyn_getCompleteFittingYQFromYDir(void *, void *, void *);
extern void charrootdyn_parentpointxzfitstab(char *, int, int);

void motrootdyn_startparentpointxzfit_from_pendulum(void *a, char *c, int e)
{
    char *g = c + 0xC0;
    void *q = *(void **)(c + 0x13C);
    charrootdyn_updateCharacterClassParentGeometry(c, &ZeroPoint, c + 0xB90);
    charrootdyn_getCompleteFittingYQFromYDir(q, GetGeometryPointerSurfacePlane(g), q);
    charrootdyn_parentpointxzfitstab(c, *(int *)(c + 0x1C0), e);
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0088_updateParentPointGPInfo", motrootdyn_startparentpointxzfit);
extern void func_400799E8(void *, void *);

void motrootdyn_startparentpointxzfit(void *a, void *b, void *c)
{
    func_400799E8(a, c);
}

extern void motrootdyn_changehcol_from_xz(void *);
extern void func_400799E8(void *, void *);

void motrootdyn_startparentpointxzfit_from_xz(void *m, char *c, void *p)
{
    charrootdyn_updateCharacterClassParentGeometry(c, &ZeroPoint, c + 0x6C0);
    motrootdyn_changehcol_from_xz(m);
    func_400799E8(m, p);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0088_updateParentPointGPInfo", motrootdyn_startpendulum_with_VCOL);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0088_updateParentPointGPInfo", pendulum);
