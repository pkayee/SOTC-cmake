#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0016_glRotatef", glRotatef);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0016_glRotatef", glReset);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0016_glRotatef", glEnable);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0016_glRotatef", glDisable);

void glMatrixMode(void) {
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0016_glRotatef", glBegin);
s32 iosDlGetLayer(s32 mode);
void glBeginWithDlLayerNo(s32 mode, s32 layer);

void glBegin(s32 mode)
{
    glBeginWithDlLayerNo(mode, iosDlGetLayer(mode));
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0016_glRotatef", glNormal3f);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0016_glRotatef", glNormal3fv);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0016_glRotatef", glNormal4f);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0016_glRotatef", glNormal4fv);

/* NEARMISS-STUB glColor3f */
#if 0 /* NEARMISS 90.0% cat=regalloc sub=- | loop counter a0 vs v0, f-reg swap of 255/0 consts, addiu v1 placement | attempts=1 */
extern u8 D_401248C0[];

void glColor3f(f32 r, f32 g, f32 b)
{
    u8 *p = D_401248C0;
    s32 i;
    f32 *c;

    *(f32 *)(p + 0x9C) = 128.0f;
    *(f32 *)(p + 0x90) = r * 255.0f;
    *(f32 *)(p + 0x94) = g * 255.0f;
    *(f32 *)(p + 0x98) = b * 255.0f;
    c = (f32 *)(p + 0x90);
    for (i = 3; i >= 0; i--)
    {
        f32 v = *c;

        if (255.0f < v)
        {
            *c = 255.0f;
            v = 255.0f;
        }
        if (v < 0.0f)
        {
            *c = 0.0f;
        }
        c++;
    }
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0016_glRotatef", glColor3f);

extern u8 D_401248C0[];

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0016_glRotatef", glColor3fv);
void glColor3fv(f32 *v)
{
    u8 *p = D_401248C0;
    s32 i;
    f32 *c;
    f32 b;

    *(f32 *)(p + 0x90) = v[0] * 255.0f;
    *(f32 *)(p + 0x94) = v[1] * 255.0f;
    b = v[2];
    *(f32 *)(p + 0x9C) = 128.0f;
    *(f32 *)(p + 0x98) = b * 255.0f;
    c = (f32 *)(p + 0x90);
    for (i = 3; i >= 0; i--)
    {
        f32 x = *c;

        if (255.0f < x)
        {
            *c = 255.0f;
            x = 255.0f;
        }
        if (x < 0.0f)
        {
            *c = 0.0f;
        }
        c++;
    }
}

/* NEARMISS-STUB glColor4f */
#if 0 /* NEARMISS 86.0% cat=sched sub=- | addiu v1 scheduled between mul.s; store order 0x9C | attempts=1 */
extern u8 D_401248C0[];

void glColor4f(f32 r, f32 g, f32 b, f32 a)
{
    u8 *p = D_401248C0;
    s32 i;
    f32 *c;

    *(f32 *)(p + 0x90) = r * 255.0f;
    *(f32 *)(p + 0x9C) = a * 128.0f;
    *(f32 *)(p + 0x94) = g * 255.0f;
    *(f32 *)(p + 0x98) = b * 255.0f;
    c = (f32 *)(p + 0x90);
    for (i = 3; i >= 0; i--)
    {
        f32 v = *c;

        if (255.0f < v)
        {
            *c = 255.0f;
            v = 255.0f;
        }
        if (v < 0.0f)
        {
            *c = 0.0f;
        }
        c++;
    }
}
#endif
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

/* NEARMISS-STUB glVertex3fv */
#if 0 /* NEARMISS 92.0% cat=regalloc sub=- | lq a0 then lw v0 index; mine lq a1 then lw a0 | attempts=1 */
void func_40026360(s32 mode);
void func_40026738(s32 mode);

void glVertex3fv(f32 *v)
{
    u128 tmp;
    u8 *p;
    s32 n;

    func_40026360(1);
    p = D_401248C0;
    tmp = *(u128 *)v;
    n = *(s32 *)(p + 0x41F0);
    *(u128 *)(p + 0x200 + (n << 6)) = tmp;
    func_40026738(*(s32 *)(p + 0x41F0));
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0016_glRotatef", glVertex3fv);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0016_glRotatef", glVertex4f);

/* NEARMISS-STUB glVertex4fv */
#if 0 /* NEARMISS 92.0% cat=regalloc sub=- | same as glVertex3fv: lq/index register swap | attempts=1 */
void func_40026360(s32 mode);
void func_40026738(s32 mode);

void glVertex4fv(f32 *v)
{
    u128 tmp;
    u8 *p;
    s32 n;

    func_40026360(1);
    p = D_401248C0;
    tmp = *(u128 *)v;
    n = *(s32 *)(p + 0x41F0);
    *(u128 *)(p + 0x200 + (n << 6)) = tmp;
    func_40026738(*(s32 *)(p + 0x41F0));
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0016_glRotatef", glVertex4fv);

/* NEARMISS-STUB glGetColor */
#if 0 /* NEARMISS 6.0% cat=sched sub=- | gcc hoists dst loads/scalar stores above the u128 sq copy; float literal 0.0039215685f gives 0x3B808080 | attempts=1 */
extern u8 D_40124950[];

void glGetColor(f32 *dst)
{
    u128 c;

    c = *(u128 *)D_40124950;
    *(u128 *)dst = c;
    dst[0] = dst[0] * 0.0039215685f;
    dst[1] = dst[1] * 0.0039215685f;
    dst[2] = dst[2] * 0.0039215685f;
    dst[3] = dst[3] * 0.0078125f;
}
#endif
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

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0016_glRotatef", glLoadMatrixf);
void iosCopyMatrix(void *dst, void *src);

void glLoadMatrixf(void *m)
{
    iosCopyMatrix(D_401AB0C0 + (D_401AB8C0 << 6), m);
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0016_glRotatef", glGetMatrixf);
void glGetMatrixf(void *dst)
{
    iosCopyMatrix(dst, D_401AB0C0 + (D_401AB8C0 << 6));
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0016_glRotatef", glPushMatrix);
void glPushMatrix(void)
{
    s32 n;

    n = D_401AB8C0 + 1;
    D_401AB8C0 = n;
    if (n >= 0x20)
    {
        D_401AB8C0 = 0x20;
        return;
    }
    iosCopyMatrix(D_401AB0C0 + (n << 6), D_401AB0C0 - 0x40 + (n << 6));
}

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

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0016_glRotatef", glSetReg);
void glSetReg(s64 a, s64 b)
{
    u8 *base = D_401248C0;
    u8 **slot = (u8 **)(base + 4);
    u8 *p;
    u8 *q;

    p = *slot;
    *(s64 *)p = b;
    p += 8;
    q = p + 8;
    *(u8 * volatile *)slot = p;
    *(s64 *)p = a;
    *slot = q;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0016_glRotatef", glGetCurrentMatrix);
void glGetCurrentMatrix(void *dst)
{
    iosCopyMatrix(dst, D_401AB0C0 + (D_401AB8C0 << 6));
}

/* NEARMISS-STUB glLightVector */
#if 0 /* NEARMISS 63.0% cat=regalloc sub=- | f-reg swap: target loads f1,f0,f1 / base v0,v3; mine f0,f1,f0 / at | attempts=1 */
void glLightVector(f32 *dst, s32 idx)
{
    u8 *p = D_401248C0;
    f32 *src = (f32 *)(p + (idx << 2));

    dst[0] = src[76];
    dst[1] = src[80];
    dst[2] = src[84];
}
#endif
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
