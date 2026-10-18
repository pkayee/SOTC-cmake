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

void glColor4f(f32 r, f32 g, f32 b, f32 a)
{
    u8 *p = D_401248C0;
    f32 *color;
    f32 value;
    s32 remaining = 3;
    f32 maximum;

    *(f32 *)(p + 0x90) = r * 255.0f;
    *(f32 *)(p + 0x94) = g * 255.0f;
    *(f32 *)(p + 0x98) = b * 255.0f;
    maximum = 255.0f;
    *(f32 *)(p + 0x9C) = a * 128.0f;
    color = (f32 *)(p + 0x90);
    do {
        value = *color;
        if (value > maximum) {
            *color = maximum;
            value = maximum;
        }
        if (value < 0.0f) {
            *color = 0.0f;
        }
        remaining--;
        color++;
    } while (remaining >= 0);
}

typedef struct {
    char pad0[0x90];
    f32 color[4];
} GlState;

void glColor4fv(f32 *c)
{
    GlState *gl = (GlState *)D_401248C0;
    f32 *p;
    s32 i;

    gl->color[0] = c[0] * 255.0f;
    gl->color[1] = c[1] * 255.0f;
    gl->color[2] = c[2] * 255.0f;
    gl->color[3] = c[3] * 128.0f;
    p = gl->color;
    for (i = 0; i < 4; i++, p++) {
        if (*p > 255.0f) {
            *p = 255.0f;
        }
        if (*p < 0.0f) {
            *p = 0.0f;
        }
    }
}

extern u8 D_401248C0[];

void glTexCoord2f(f32 s, f32 t)
{
    u8 *p = D_401248C0;

    *(f32 *)(p + 0xA0) = s;
    *(f32 *)(p + 0xA4) = t;
    *(f32 *)(p + 0xA8) = 1.0f;
    *(s32 *)(p + 0xAC) = 0;
}

void glTexCoord2fv(f32 *v)
{
    u8 *p = D_401248C0;

    *(f32 *)(p + 0xA0) = v[0];
    *(f32 *)(p + 0xA4) = v[1];
    *(f32 *)(p + 0xA8) = 1.0f;
    *(f32 *)(p + 0xAC) = 0.0f;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0016_glRotatef", glVertex2f);

typedef struct
{
    f32 x;
    f32 y;
    f32 z;
    char pad[0x34];
} GlVert;

typedef union
{
    struct
    {
        char pad[0x200];
        GlVert v[1];
    } a;
    struct
    {
        char pad[0x41F0];
        s32 n;
    } b;
} GlVertState;

void func_40026360(s32 mode);
void func_40026738(s32 mode);
extern const f32 D_40130318;

void glVertex2fv(f32 *p)
{
    func_40026360(0);
    ((GlVertState *)D_401248C0)->a.v[((GlVertState *)D_401248C0)->b.n].x = p[0];
    ((GlVertState *)D_401248C0)->a.v[((GlVertState *)D_401248C0)->b.n].y = p[1];
    ((GlVertState *)D_401248C0)->a.v[((GlVertState *)D_401248C0)->b.n].z = D_40130318;
    func_40026738(((GlVertState *)D_401248C0)->b.n);
}

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

typedef union { s128 q; float f[4]; } Vec4;
extern Vec4 D_40124950;

void glGetColor(Vec4 *c)
{
    c->q = D_40124950.q;
    c->f[0] *= 0.0039215688f;
    c->f[1] *= 0.0039215688f;
    c->f[2] *= 0.0039215688f;
    c->f[3] *= 0.0078125f;
}

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

typedef struct {
    char pad0[0x130];
    f32 x[4];
    f32 y[4];
    f32 z[4];
} GlLightState;

void glLightVector(f32 *v, s32 light)
{
    GlLightState *gl = (GlLightState *)D_401248C0;

    v[0] = gl->x[light];
    v[1] = gl->y[light];
    v[2] = gl->z[light];
}

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
