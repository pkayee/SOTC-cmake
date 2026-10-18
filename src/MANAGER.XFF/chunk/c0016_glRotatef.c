#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0016_glRotatef", glRotatef);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0016_glRotatef", glReset);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0016_glRotatef", glEnable);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0016_glRotatef", glDisable);

void glMatrixMode(void) {
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0016_glRotatef", glBegin);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0016_glRotatef", glNormal3f);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0016_glRotatef", glNormal3fv);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0016_glRotatef", glNormal4f);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0016_glRotatef", glNormal4fv);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0016_glRotatef", glColor3f);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0016_glRotatef", glColor3fv);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0016_glRotatef", glColor4f);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0016_glRotatef", glColor4fv);

extern u8 D_401248C0[];

void glTexCoord2f(f32 s, f32 t)
{
    u8 *p = D_401248C0;

    *(f32 *)(p + 0xA0) = s;
    *(f32 *)(p + 0xA4) = t;
    *(f32 *)(p + 0xA8) = 1.0f;
    *(s32 *)(p + 0xAC) = 0;
}

/* NEARMISS-STUB glTexCoord2fv */
#if 0 /* NEARMISS 79.0% cat=float-ops sub=- | gcc loads v[0] after v[1] / mtc1 of 1.0 ordering differs; sched of lwc1 pair | attempts=1 */
void glTexCoord2fv(f32 *v)
{
    u8 *p = D_401248C0;
    f32 s = v[0];
    f32 t = v[1];

    *(f32 *)(p + 0xA0) = s;
    *(f32 *)(p + 0xA4) = t;
    *(f32 *)(p + 0xA8) = 1.0f;
    *(s32 *)(p + 0xAC) = 0;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0016_glRotatef", glTexCoord2fv);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0016_glRotatef", glVertex2f);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0016_glRotatef", glVertex2fv);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0016_glRotatef", glVertex3f);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0016_glRotatef", glVertex3fv);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0016_glRotatef", glVertex4f);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0016_glRotatef", glVertex4fv);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0016_glRotatef", glGetColor);

extern s32 D_401248F4;

s32 glGetZTest(void)
{
    return D_401248F4;
}

void iosUnitMatrix(void *m);

extern s32 D_401AB8C0;
extern u8 D_401AB0C0[];

void glLoadIdentity(void)
{
    D_401AB8C0 = 0;
    iosUnitMatrix(D_401AB0C0);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0016_glRotatef", glLoadMatrixf);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0016_glRotatef", glGetMatrixf);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0016_glRotatef", glPushMatrix);

extern s32 D_401AB8C0;

void glPopMatrix(void)
{
    s32 n;

    n = D_401AB8C0 - 1;
    if (n < 0)
    {
        n = 0;
    }
    D_401AB8C0 = n;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0016_glRotatef", glTranslatef);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0016_glRotatef", glScalef);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0016_glRotatef", glRotatex);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0016_glRotatef", glRotatey);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0016_glRotatef", glRotatez);

extern f32 D_40128AB4;

void glZOffset(f32 z)
{
    D_40128AB4 = z;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0016_glRotatef", glSetReg);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0016_glRotatef", glGetCurrentMatrix);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0016_glRotatef", glLightVector);

void iosCopyMatrix(void *dst, void *src);

extern u8 D_401249F0[];

void glSetLightVector(void *m)
{
    iosCopyMatrix(D_401249F0, m);
}

extern u8 D_40124A30[];

void iosCopyMatrix(void *dst, void *src);

void glSetLightColor(void *m)
{
    iosCopyMatrix(D_40124A30, m);
}
