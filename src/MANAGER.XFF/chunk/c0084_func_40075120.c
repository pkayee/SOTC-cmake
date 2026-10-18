#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0084_func_40075120", func_40075120);

extern void ParentLayoutObj(s64 a0, u8 *a1);

void motrootdyn_startchainhang(s64 a0, u8 *a1)
{
    if (*(s32 *)(a1 + 0xD14) != 0) {
        return ParentLayoutObj(a0, a1 + 0xD20);
    }
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0084_func_40075120", chainhang);

extern void charrootdyn_updateCharacterClassParentGeometry(int, void *, int);
extern void func_4006DCF0(int, int);
extern u128 ZeroPoint;

void motrootdyn_startfreefall(int arg0, int arg1)
{
    charrootdyn_updateCharacterClassParentGeometry(arg1, &ZeroPoint, arg1 + 0x6C0);
    func_4006DCF0(arg0, arg1);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0084_func_40075120", motrootdyn_startfreefall_from_pendulum);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0084_func_40075120", func_40075458);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0084_func_40075120", func_40075528);

extern int func_4006E0C0();

int freefallnostab(int a, int b, int c, int d, int e)
{
    return func_4006E0C0(a, b, c, d, e, 0);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0084_func_40075120", motrootdyn_startmotionfall);

int motionfall(int a, int b, int c, int d, int e)
{
    return func_4006E0C0(a, b, c, d, e, 1);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0084_func_40075120", func_40075680);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0084_func_40075120", motrootdyn_startcharnodeparent);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0084_func_40075120", norootdynamics_vel_xzstab);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0084_func_40075120", norootdynamics_vel);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0084_func_40075120", directplay);

extern void GetGeometryPointerSurfacePlane(char *);
extern void GetCollisionDBLastPointOnCurrentPlane(float *, char *, int);

void charrootdyn_debugDispParentGeometryStatus(char *c)
{
    float p[4] __attribute__((aligned(16)));

    GetGeometryPointerSurfacePlane(c + 0xC0);
    GetCollisionDBLastPointOnCurrentPlane(p, c + 0xC0, *(int *)(c + 0x138));
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0084_func_40075120", func_40075BC8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0084_func_40075120", func_40076370);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0084_func_40075120", func_400766A0);
