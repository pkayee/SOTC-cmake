#include "common.h"

typedef union {
    void *p;
    s32 w;
} PathSlot;
typedef struct {
    u8 pad00[0x14];
    void *p14;      /* 0x14 */
    PathSlot p18;   /* 0x18 */
    u8 pad1c[4];
    s32 f20;        /* 0x20 */
    s32 f24;        /* 0x24 */
    PathSlot p28;   /* 0x28 */
    s32 f2c;        /* 0x2c */
    PathSlot p30;   /* 0x30 */
    s32 f34;        /* 0x34 */
    PathSlot p38;   /* 0x38 */
    s32 f3c;        /* 0x3c */
    u8 pad40[0x90];
    s32 fd0;        /* 0xd0 */
    u8 padd4[0x10];
    void *cur;      /* 0xe4 */
} PathFree;
extern PathFree D_4002DF80;
void iosFree();

void glColor4fv(float *c);

extern s32 D_4002E058;
void DebugDispWideLineNotBlendVU1();
void DebugDispWideLineHalfVU1();

void DebugDispArrowNotBlendVU1();
void DebugDispArrowHalfVU1();

extern char D_40021050[];
void iosDlPushLayer(s32 a);
void iosDlPopLayer(void);
s32 iosInitKPrintfContext3D(float r, float g, float b, float a, void *ctx, s32 x, s32 y, s32 z);
void kprintfContextCentering(void *ctx, char *fmt, s32 v);

typedef struct {
    s32 id;     /* 0x00 */
    u16 val;    /* 0x04 */
} InterestEdit;
typedef struct {
    u8 pad00[0x10];
    u16 val;    /* 0x10 */
} InterestPoint;
extern s32 D_4002DFA8;
extern InterestEdit D_4002F028;
InterestPoint *getInterestPointData(s32 h, s32 idx);

typedef struct {
    s32 id;     /* 0x00 */
    u16 v0;     /* 0x04 */
    u16 pad06;
    u16 v1;     /* 0x08 */
    u16 pad0a;
    u16 v2;     /* 0x0c */
    u16 pad0e;
    u16 v3;     /* 0x10 */
    u16 pad12;
    u16 v4;     /* 0x14 */
} DeadEdit;
typedef struct {
    u8 pad00[0x10];
    u16 v0;     /* 0x10 */
    u16 v1;     /* 0x12 */
    u16 v2;     /* 0x14 */
    u16 v3;     /* 0x16 */
    u16 v4;     /* 0x18 */
} DeadPoint;
extern s32 D_4002DFB0;
extern DeadEdit D_4002F038;
DeadPoint *getDeadPointData(s32 h, s32 idx);

void func_4001AB18(s32 a, s32 b);
void func_40011780(s32 a);

typedef struct {
    s32 id;     /* 0x00 */
    u16 val;    /* 0x04 */
    u16 pad06;
    s32 on8;    /* 0x08 */
    s32 onC;    /* 0x0c */
    float fl;   /* 0x10 */
} SubEdit;
typedef union {
    struct {
        u8 pad00[0x10];
        u32 flags;  /* 0x10 */
        float fl;   /* 0x14 */
        s16 val;    /* 0x18 */
    } s;
    u8 raw[0x20];
} SubPoint;
extern s32 D_4002DF98;
extern SubEdit D_4002F010;
SubPoint *getSubPointData(s32 h, s32 idx);
s32 DEBUG_is_locking_debug_camera(void);
void DebugGlobalMoveWith2ndController(void *a, void *b);

extern float D_4001F5E0[];

extern char rootPtn[];
extern char D_40020178[];
extern float D_4001FD88[];
void *iosMallocAlign(void *, s32, s32);
void *memcpy(void *dst, const void *src, u32 n);
void createParamMenu();
void cursorLockParamMenu();
void func_4001D148();

typedef union {
    float f[8];
    s32 w[8];
} FltTab;

typedef union {
    struct {
        u8 pad00[0x10];
        s16 val;    /* 0x10 */
    } s;
    u8 raw[0x20];
} InterestPtU;
s32 GetStageAreaNumberByPos(void *p);

extern float D_4001FA40[];

typedef union {
    struct {
        u8 pad00[0x10];
        s16 v0;     /* 0x10 */
        s16 v1;     /* 0x12 */
        s16 v2;     /* 0x14 */
        s16 v3;     /* 0x16 */
        s16 v4;     /* 0x18 */
    } s;
    u8 raw[0x20];
} DeadPtU;

typedef struct {
    s32 id;     /* 0x00 */
    float f04;  /* 0x04 */
    float f08;  /* 0x08 */
    u16 h0c;    /* 0x0c */
    u16 pad0e;
    float f10;  /* 0x10 */
    u16 h14;    /* 0x14 */
    u16 pad16;
    u16 h18;    /* 0x18 */
    u16 pad1a;
    u8 pad1c[4];
    s32 f20;    /* 0x20 */
    u16 h24;    /* 0x24 */
} LayoutEdit;
extern s32 D_4002DFB8;
extern LayoutEdit D_4002F050;
extern float D_400201B0[];

typedef union {
    struct {
        u8 pad00[0x10];
        float f10;  /* 0x10 */
        u16 h14;    /* 0x14 */
        u16 h16;    /* 0x16 */
        u16 h18;    /* 0x18 */
        u16 pad1a;
        u16 h1c;    /* 0x1c */
        u16 h1e;    /* 0x1e */
        float f20;  /* 0x20 */
        float f24;  /* 0x24 */
    } s;
    u8 raw[0x30];
} LayoutPtU;
LayoutPtU *getLayoutPointData(s32 h, s32 idx);

void func_4001C278(void) {
    if (D_4002DF80.f20 != 0) {
        iosFree(D_4002DF80.p14);
    }
    D_4002DF80.p14 = 0;
    D_4002DF80.f20 = 0;
}

extern u8 padManagerData[];
void func_40018E78();

void func_4001C2B8(void)
{
    if (*(s32 *)(padManagerData + 8) & 0x20)
    {
        func_40018E78();
    }
    return;
}

void func_4001C2E8(void) {
    SubPoint *p;
    if (D_4002DF80.p18.p != 0) {
        p = getSubPointData((s32)D_4002DF80.p18.p, D_4002F010.id);
        D_4002DF80.cur = p;
        ((s32 *)&D_4002F010)[1] = p->s.val;
        D_4002F010.fl = p->s.fl;
        if (p->s.flags & 1) {
            D_4002F010.on8 = 1;
        } else {
            D_4002F010.on8 = 0;
        }
        if (p->s.flags & 2) {
            D_4002F010.onC = 1;
        } else {
            D_4002F010.onC = 0;
        }
        func_40011780(D_4002DF80.fd0);
    } else {
        D_4002DF80.cur = 0;
    }
    if (DEBUG_is_locking_debug_camera() != 0 && D_4002DF80.cur != 0) {
        DebugGlobalMoveWith2ndController(D_4002DF80.cur, D_4002DF80.cur);
    }
}

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0007_func_4001C278", func_4001C3F0);

void func_4001C4C8(void) {
    SubPoint *p;
    if (D_4002DF98 != 0) {
        p = getSubPointData(D_4002DF98, D_4002F010.id);
        p->s.val = D_4002F010.val;
        p->s.fl = D_4002F010.fl;
        p->s.flags = 0;
        if (D_4002F010.on8 != 0) {
            p->s.flags = 1;
        }
        if (D_4002F010.onC != 0) {
            p->s.flags |= 2;
        }
    }
}

void func_4001C548(void) {
    SubPoint *p;
    if (D_4002DF80.p18.p != 0) {
        p = getSubPointData((s32)D_4002DF80.p18.p, D_4002F010.id);
        D_4002DF80.cur = p;
        ((s32 *)&D_4002F010)[1] = p->s.val;
        D_4002F010.fl = p->s.fl;
        if (p->s.flags & 1) {
            D_4002F010.on8 = 1;
        } else {
            D_4002F010.on8 = 0;
        }
        if (p->s.flags & 2) {
            D_4002F010.onC = 1;
        } else {
            D_4002F010.onC = 0;
        }
        func_40011780(D_4002DF80.fd0);
    } else {
        D_4002DF80.cur = 0;
    }
    if (DEBUG_is_locking_debug_camera() != 0 && D_4002DF80.cur != 0) {
        DebugGlobalMoveWith2ndController(D_4002DF80.cur, D_4002DF80.cur);
    }
    if (*(s32 *)(padManagerData + 8) & 0x20) {
        func_40011780(1);
    }
}

void func_4001C660(u32 *p) {
    if (D_4002DF80.f24 != 0) {
        iosFree(D_4002DF80.p18.p);
    }
    D_4002DF80.p18.p = p;
    D_4002DF80.f24 = 1;
    if (*p <= D_4002F010.id) {
        D_4002F010.id = *p - 1;
    }
    D_4001F5E0[7] = (float)*(u32 *)D_4002DF80.p18.p;
    D_4001F5E0[7] = D_4001F5E0[7] - 1.0f;
    if (D_4001F5E0[7] < 0.0f) {
        D_4001F5E0[7] = 0.0f;
    }
}

void func_4001C738(void) {
    if (D_4002DF80.f24 != 0) {
        iosFree(D_4002DF80.p18.p);
    }
    D_4002DF80.p18.p = 0;
    D_4002DF80.f24 = 0;
}

void func_4001C778(u8 *self) {
    if (*(s32 *)(padManagerData + 8) & 0x20) {
        if (D_4002DF80.p30.p != 0) {
            void *q;
            D_4001FD88[7] = (float)*(u32 *)D_4002DF80.p30.p;
            D_4001FD88[7] = D_4001FD88[7] - 1.0f;
            if (D_4001FD88[7] < 0.0f) {
                D_4001FD88[7] = 0.0f;
            }
            if (D_4002DF80.f34 == 0) {
                q = iosMallocAlign(rootPtn, ((s32 *)D_4002DF80.p30.p)[1], 0x10);
                memcpy(q, D_4002DF80.p30.p, ((s32 *)D_4002DF80.p30.p)[1]);
                func_4001D148(q);
            }
        }
        createParamMenu(D_40020178, *(s32 *)(self + 0x94));
        cursorLockParamMenu(D_40020178, 1);
    }
    return;
}

void func_4001C898(float *col) {
    float v[4];
    v[0] = 1.0f - col[0];
    v[1] = 1.0f - col[1];
    v[2] = 1.0f - col[2];
    v[3] = col[3];
    glColor4fv(v);
}

//INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0007_func_4001C278", func_4001C8F0);
void DebugDispTriangularPyramidNotBlendVU1();

void func_4001C8F0(void)
{
    DebugDispTriangularPyramidNotBlendVU1();
}

void func_4001C908(void) {
    if (D_4002E058 != 0) {
        DebugDispWideLineNotBlendVU1();
        return;
    }
    DebugDispWideLineHalfVU1();
}

void func_4001C938(void) {
    if (D_4002E058 != 0) {
        DebugDispArrowNotBlendVU1();
        return;
    }
    DebugDispArrowHalfVU1();
}

void func_4001C968(s32 a, s32 b) {
    u8 ctx[0x40];
    func_4001C8F0();
    iosDlPushLayer(0x19);
    if (iosInitKPrintfContext3D(1.0f, 1.0f, 1.0f, 1.0f, ctx, a, 0, 1)) {
        kprintfContextCentering(ctx, D_40021050, b);
    }
    iosDlPopLayer();
}

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0007_func_4001C278", func_4001C9F0);

void func_4001CBD8(FltTab *a, s32 *idx) {
    s32 pad = *(s32 *)(padManagerData + 0xFA8);
    if (pad & 8) {
        *idx = *idx + 1;
        if (a->f[7] < (float)*idx) {
            *idx = 0;
            return;
        }
    } else if (pad & 4) {
        *idx = *idx - 1;
        if (*idx < 0) {
            *idx = (s32)a->f[7];
        }
    }
}

void func_4001CC50(void) {
    InterestPtU *p;
    if (D_4002DF80.p28.p != 0) {
        p = (InterestPtU *)getInterestPointData((s32)D_4002DF80.p28.p, D_4002F028.id);
        D_4002DF80.cur = p;
        ((s32 *)&D_4002F028)[1] = p->s.val;
        ((s32 *)&D_4002F028)[2] = GetStageAreaNumberByPos(p);
        func_40011780(D_4002DF80.fd0);
    } else {
        D_4002DF80.cur = 0;
    }
    if (DEBUG_is_locking_debug_camera() != 0 && D_4002DF80.cur != 0) {
        DebugGlobalMoveWith2ndController(D_4002DF80.cur, D_4002DF80.cur);
    }
}

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0007_func_4001C278", func_4001CD00);

void func_4001CDB0(u32 *p) {
    if (D_4002DF80.f2c != 0) {
        iosFree(D_4002DF80.p28.p);
    }
    D_4002DF80.p28.p = p;
    D_4002DF80.f2c = 1;
    if (*p <= D_4002F028.id) {
        D_4002F028.id = *p - 1;
    }
    D_4001FA40[7] = (float)*(u32 *)D_4002DF80.p28.p;
    D_4001FA40[7] = D_4001FA40[7] - 1.0f;
    if (D_4001FA40[7] < 0.0f) {
        D_4001FA40[7] = 0.0f;
    }
}

void func_4001CE88(void) {
    if (D_4002DF80.f2c != 0) {
        iosFree(D_4002DF80.p28.p);
    }
    D_4002DF80.p28.p = 0;
    D_4002DF80.f2c = 0;
}

void func_4001CEC8(void) {
    InterestPoint *p;
    if (D_4002DFA8 != 0) {
        p = getInterestPointData(D_4002DFA8, D_4002F028.id);
        p->val = D_4002F028.val;
    }
}

void func_4001CF10(void) {
    InterestPtU *p;
    if (D_4002DF80.p28.p != 0) {
        p = (InterestPtU *)getInterestPointData((s32)D_4002DF80.p28.p, D_4002F028.id);
        D_4002DF80.cur = p;
        ((s32 *)&D_4002F028)[1] = p->s.val;
        ((s32 *)&D_4002F028)[2] = GetStageAreaNumberByPos(p);
        func_40011780(D_4002DF80.fd0);
    } else {
        D_4002DF80.cur = 0;
    }
    if (DEBUG_is_locking_debug_camera() != 0 && D_4002DF80.cur != 0) {
        DebugGlobalMoveWith2ndController(D_4002DF80.cur, D_4002DF80.cur);
    }
    if (*(s32 *)(padManagerData + 8) & 0x20) {
        func_40011780(1);
    }
}

void func_4001CFE0(void) {
    DeadPtU *p;
    if (D_4002DF80.p30.p != 0) {
        p = (DeadPtU *)getDeadPointData((s32)D_4002DF80.p30.p, D_4002F038.id);
        D_4002DF80.cur = p;
        ((s32 *)&D_4002F038)[1] = p->s.v0;
        ((s32 *)&D_4002F038)[2] = p->s.v1;
        ((s32 *)&D_4002F038)[3] = p->s.v2;
        ((s32 *)&D_4002F038)[4] = p->s.v3;
        ((s32 *)&D_4002F038)[5] = p->s.v4;
        func_40011780(D_4002DF80.fd0);
    } else {
        D_4002DF80.cur = 0;
    }
    if (DEBUG_is_locking_debug_camera() != 0 && D_4002DF80.cur != 0) {
        DebugGlobalMoveWith2ndController(D_4002DF80.cur, D_4002DF80.cur);
    }
}

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0007_func_4001C278", func_4001D0A8);

void func_4001D148(u32 *p) {
    if (D_4002DF80.f34 != 0) {
        iosFree(D_4002DF80.p30.p);
    }
    D_4002DF80.p30.p = p;
    D_4002DF80.f34 = 1;
    if (*p <= D_4002F038.id) {
        D_4002F038.id = *p - 1;
    }
    D_4001FD88[7] = (float)*(u32 *)D_4002DF80.p30.p;
    D_4001FD88[7] = D_4001FD88[7] - 1.0f;
    if (D_4001FD88[7] < 0.0f) {
        D_4001FD88[7] = 0.0f;
    }
}

void func_4001D220(void) {
    if (D_4002DF80.f34 != 0) {
        iosFree(D_4002DF80.p30.p);
    }
    D_4002DF80.p30.p = 0;
    D_4002DF80.f34 = 0;
}

void func_4001D260(void) {
    DeadPoint *p;
    if (D_4002DFB0 != 0) {
        p = getDeadPointData(D_4002DFB0, D_4002F038.id);
        p->v0 = D_4002F038.v0;
        p->v1 = D_4002F038.v1;
        p->v2 = D_4002F038.v2;
        p->v3 = D_4002F038.v3;
        p->v4 = D_4002F038.v4;
    }
}

void func_4001D2C8(void) {
    DeadPtU *p;
    if (D_4002DF80.p30.p != 0) {
        p = (DeadPtU *)getDeadPointData((s32)D_4002DF80.p30.p, D_4002F038.id);
        D_4002DF80.cur = p;
        ((s32 *)&D_4002F038)[1] = p->s.v0;
        ((s32 *)&D_4002F038)[2] = p->s.v1;
        ((s32 *)&D_4002F038)[3] = p->s.v2;
        ((s32 *)&D_4002F038)[4] = p->s.v3;
        ((s32 *)&D_4002F038)[5] = p->s.v4;
        func_40011780(D_4002DF80.fd0);
    } else {
        D_4002DF80.cur = 0;
    }
    if (DEBUG_is_locking_debug_camera() != 0 && D_4002DF80.cur != 0) {
        DebugGlobalMoveWith2ndController(D_4002DF80.cur, D_4002DF80.cur);
    }
    if (*(s32 *)(padManagerData + 8) & 0x20) {
        func_40011780(1);
    }
}

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0007_func_4001C278", func_4001D3B0);

void func_4001D4C0(u32 *p) {
    if (D_4002DF80.f3c != 0) {
        iosFree(D_4002DF80.p38.p);
    }
    D_4002DF80.p38.p = p;
    D_4002DF80.f3c = 1;
    if (*p <= D_4002F050.id) {
        D_4002F050.id = *p - 1;
    }
    D_400201B0[7] = (float)*(u32 *)D_4002DF80.p38.p;
    D_400201B0[7] = D_400201B0[7] - 1.0f;
    if (D_400201B0[7] < 0.0f) {
        D_400201B0[7] = 0.0f;
    }
}

void func_4001D598(void) {
    if (D_4002DF80.f3c != 0) {
        iosFree(D_4002DF80.p38.p);
    }
    D_4002DF80.p38.p = 0;
    D_4002DF80.f3c = 0;
}

void func_4001D5D8(void) {
    LayoutPtU *p;
    if (D_4002DFB8 != 0) {
        p = getLayoutPointData(D_4002DFB8, D_4002F050.id);
        p->s.f10 = D_4002F050.f04;
        p->s.f20 = D_4002F050.f08;
        p->s.h14 = D_4002F050.h0c;
        p->s.h16 = D_4002F050.h14;
        p->s.h18 = D_4002F050.h18;
        p->s.h1c = D_4002F050.h24;
        p->s.f24 = D_4002F050.f10;
        p->s.h1e = 0;
        if (D_4002F050.f20 != 0) {
            p->s.h1e = 1;
        }
    }
}

void func_4001D668(void) {
    func_4001AB18(0, 0);
    if (*(s32 *)(padManagerData + 8) & 0x20) {
        func_40011780(1);
    }
}
