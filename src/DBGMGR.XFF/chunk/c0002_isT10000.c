#include "common.h"

s32 LoaderSysCheckCDBootMode();

/* DBGMGR c0002: 100 in scratch; `s32 i = 0;` at decl + p=buf INSIDE the if gives the target delay-slot order (i=0 after if: 99.2) */
extern char *iosMallocAlign();

void windowCloseRequest(s32);

extern char D_4001DEC0[];
extern char D_4001E0D8[];
void windowFontColor(void *, void *);
void windowPrintf(float, float, void *, char *, char *);

extern s32 D_4001E0E0[];

extern s32 D_4001E060;
void iosDlPushLayer(s32);
void iosDlPopLayer(void);
void glLoadIdentity(void);
void glEnable(s32);
void glDisable(s32);
void glBegin(s32);
void glEnd(void);
void glBlendFunc(s32, s32);
void glColor4f(float, float, float, float);
void glVertex3f(float, float, float);

s32 isT10000(void)
{
    return LoaderSysCheckCDBootMode() == 0;
}

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0002_isT10000", func_400129D8);

/* DBGMGR c0002: debug print window scroll step. obj+0x1b8 u64 flags bit 3 selects a float step at obj+0x1e0 (cvt to int); obj+0x3e0 = DbgPrintInfo (+8 rows, +0x20 scroll pos); obj+0x1c4 flags: 0x20 reset scroll, 0x40040 close. ev_85315f23c5e6ec4e0f761112955f943aea828d9efd02b59a0cd611bb1ba00b10 */
void func_40012A48(void *a0, s32 obj)
{
    s32 step;
    s32 info;

    if ((s32)(*(long *)(obj + 0x1b8) >> 3) & 1) {
        step = (s32)*(float *)(obj + 0x1e0);
    } else {
        step = 0;
    }
    info = *(s32 *)(obj + 0x3e0);
    if (step != 0) {
        *(s32 *)(info + 0x20) += step;
    }
    if (*(s32 *)(info + 0x20) < 0) {
        *(s32 *)(info + 0x20) = 0;
    }
    if (*(s32 *)(info + 8) < *(s32 *)(info + 0x20)) {
        *(s32 *)(info + 0x20) = *(s32 *)(info + 8);
    }
    if ((*(u32 *)(obj + 0x1c4) & 0x20) != 0) {
        *(s32 *)(info + 0x20) = 0;
    }
    if ((*(u32 *)(obj + 0x1c4) & 0x40040) != 0) {
        windowCloseRequest(obj);
    }
}

/* DBGMGR c0002: draws the ring-buffer lines of a DbgPrintInfo (+8 rows, +0x1c cur, +0x20 scroll; obj+0x3e8 = line buffer, 0x100 per line) bottom-up from y=obj+0x270-16 to -16 step 16. windowPrintf(float x, float y, win, fmt, line) per sibling decl. ev_85315f23c5e6ec4e0f761112955f943aea828d9efd02b59a0cd611bb1ba00b10 */
void func_40012AF0(void *a0, s32 obj)
{
    s32 info = *(s32 *)(obj + 0x3e0);
    float y = *(float *)(obj + 0x270) - 16.0f;
    s32 i = *(s32 *)(info + 0x1c) - *(s32 *)(info + 0x20);
    s32 buf = *(s32 *)(obj + 0x3e8);

    if (i < 0) {
        do {
            i += *(s32 *)(info + 8);
        } while (i < 0);
    }
    windowFontColor((void *)obj, D_4001DEC0);
    if (-16.0f < y) {
        do {
            i--;
            if (i < 0) {
                i = *(s32 *)(info + 8) - 1;
            }
            windowPrintf(0.0f, y, (void *)obj, D_4001E0D8, (char *)(buf + (i << 8)));
            y -= 16.0f;
        } while (-16.0f < y);
    }
}

/* DBGMGR c0002: 100 in scratch; obj is s32 (a pointer-typed obj lets gcc CSE the second 0x3e0 load: 78.6) */
void func_40012C10(void *a0, s32 obj)
{
    *(s32 *)(*(s32 *)(obj + 0x3e0) + 0x24) = 0;
    *(s32 *)(*(s32 *)(obj + 0x3e0) + 0x28) = 0;
}

char *func_40012C28(void *a0, s32 obj)
{
    s32 t = *(s32 *)(obj + 0x3e0);
    char *buf = iosMallocAlign(a0, *(s32 *)(t + 0x20) << 8, 4);
    char *p;
    s32 i = 0;
    
    if (0 < *(s32 *)(t + 0x20)) {
        p = buf;
        do {
            *p = 0;
            i++;
            p += 0x100;
        } while (i < *(s32 *)(t + 0x20));
    }
    return buf;
}

/* DBGMGR c0002: debug window scroll/page update; obj+0x3e0 = DbgPrintInfo (+0xc size, +0x10 mode 0..6, +0x20, +0x28 pos). obj+0x1b8 bit 3 -> float step at obj+0x1e0. flag 0x8000 clamps, 0x20 cycles the mode (skipping 2,3,5,6) and sets obj+0x1b0 = D_4001E0E0[mode]*7+8. ev_85315f23c5e6ec4e0f761112955f943aea828d9efd02b59a0cd611bb1ba00b10 */
void func_40012C90(void *a0, s32 obj)
{
    s32 info = *(s32 *)(obj + 0x3e0);
    s32 step;
    u32 lim;
    s32 sz;
    s32 mode;

    if ((s32)(*(long *)(obj + 0x1b8) >> 3) & 1) {
        step = (s32)*(float *)(obj + 0x1e0);
    } else {
        step = 0;
    }
    if (step != 0) {
        if ((*(u32 *)(obj + 0x1c4) & 0x8000) != 0) {
            if (step > 0) {
                *(s32 *)(info + 0x28) = 0;
            }
            if (step < 0) {
                *(s32 *)(info + 0x28) = (*(u32 *)(info + 0xc) >> 4) - *(s32 *)(info + 0x20);
            }
        } else {
            *(s32 *)(info + 0x28) -= step * *(s32 *)(info + 0x20);
        }
    }
    if (*(s32 *)(info + 0x28) < 0) {
        *(s32 *)(info + 0x28) = 0;
    }
    lim = (*(u32 *)(info + 0xc) >> 4) - *(s32 *)(info + 0x20);
    if (lim < *(u32 *)(info + 0x28)) {
        *(u32 *)(info + 0x28) = lim;
    }
    if ((*(u32 *)(obj + 0x1c4) & 0x20) != 0) {
        s32 inf2 = *(s32 *)(obj + 0x3e0);
        do {
            *(s32 *)(inf2 + 0x10) += 1;
            if (*(s32 *)(inf2 + 0x10) >= 7) {
                *(s32 *)(inf2 + 0x10) = 0;
            }
        } while (*(s32 *)(inf2 + 0x10) < 0 || (*(s32 *)(inf2 + 0x10) >= 2 && *(s32 *)(inf2 + 0x10) != 4));
        *(float *)(obj + 0x1b0) = (float)(D_4001E0E0[*(s32 *)(inf2 + 0x10)] * 7 + 8);
    }
}

void func_40012DC8(void *a0, char *obj)
{
    *(s32 *)(*(char **)(obj + 0x3e0) + 0x2c) = 0;
}

//INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0002_isT10000", OffsetOverWriter);
extern void *iosDlGetCreateAdrs();
extern int func_40011960(void *, void *, void *);

int OffsetOverWriter(void *a0, void *a1)
{
    return func_40011960(iosDlGetCreateAdrs(), a0, a1);
}

//INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0002_isT10000", initdebugmanager);
extern char D_4001E7F8[];
s32 LoaderSysPrintf();

s32 initdebugmanager(void)
{
    LoaderSysPrintf(D_4001E7F8);
    return 0;
}

/* DBGMGR c0002: axis pivot gizmo, three unit-colored lines of length 2.0 from the origin (ev_85315f23c5e6ec4e0f761112955f943aea828d9efd02b59a0cd611bb1ba00b10 batch_decompile). */
void glPivotKun(void)
{
    if (D_4001E060 != 0) {
        iosDlPushLayer(3);
        glLoadIdentity();
        glEnable(1);
        glEnable(7);
        glDisable(3);
        glBegin(8);
        glBlendFunc(5, 6);
        glEnd();
        glBegin(1);
        glColor4f(1.0f, 0.5f, 0.5f, 1.0f);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(2.0f, 0.0f, 0.0f);
        glEnd();
        glBegin(1);
        glColor4f(0.5f, 1.0f, 0.5f, 1.0f);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 2.0f, 0.0f);
        glEnd();
        glBegin(1);
        glColor4f(0.5f, 0.5f, 1.0f, 1.0f);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, 2.0f);
        glEnd();
        iosDlPopLayer();
    }
}

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0002_isT10000", _gluCylinder);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0002_isT10000", gluCylinderLine);
