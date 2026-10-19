#include "common.h"

typedef union {
    void *p;
    s32 w;
} PathSlot;
typedef struct {
    u8 pad00[0x14];
    void *p14;      /* 0x14 */
    PathSlot p18;   /* 0x18 sub points */
    u8 pad1c[4];
    s32 f20;        /* 0x20 */
    s32 f24;        /* 0x24 sub own flag */
    PathSlot p28;   /* 0x28 interest points */
    s32 f2c;        /* 0x2c */
    PathSlot p30;   /* 0x30 dead points */
    s32 f34;        /* 0x34 */
    PathSlot p38;   /* 0x38 */
    s32 f3c;        /* 0x3c */
    u8 pad40[0x90];
    s32 fd0;        /* 0xd0 */
    u8 padd4[0x10];
    void *cur;      /* 0xe4 */
    u8 padE8[0x18];
    s32 mode;       /* 0x100 */
} PathFree;
extern PathFree D_4002DF80;
typedef struct {
    s32 id;     /* 0x00 */
    s32 val;    /* 0x04 */
    s32 on8;    /* 0x08 */
    s32 onC;    /* 0x0c */
    float fl;   /* 0x10 */
} SubEdit;
typedef struct {
    s32 id;
    s32 val;
} PathEdit;
extern PathEdit D_4002F008;
typedef union {
    struct {
        u8 pad00[0x10];
        u32 flags;  /* 0x10 */
        float fl;   /* 0x14 */
        s16 val;    /* 0x18 */
    } s;
    u8 raw[0x30];
    u64 al[6];
} SubPoint;
extern SubEdit D_4002F010;
SubPoint *getSubPointData(void *h, s32 idx);
void func_40011780(s32 a);
s32 DEBUG_is_locking_debug_camera(void);
void DebugGlobalMoveWith2ndController(void *a, void *b);
extern u8 padManagerData[];
void windowCloseRequest(s32 a);
extern u8 *D_4001FA34;
extern char rootPtn[];
void *iosMallocAlign(void *, s32, s32);
void iosFree();
extern float D_4001F5E0[];
void func_4001C3F0();
void func_4001C660();
typedef struct {
    s32 id;     /* 0x00 */
    s32 val;    /* 0x04 */
    s32 area;   /* 0x08 */
} InterestEdit;
typedef union {
    struct {
        u8 pad00[0x10];
        s16 val;    /* 0x10 */
    } s;
    u8 raw[0x20];
    u64 al[4];
} InterestPoint;
extern InterestEdit D_4002F028;
InterestPoint *getInterestPointData(void *h, s32 idx);
s32 GetStageAreaNumberByPos(void *pos);
void func_4001CD00();
void func_4001CDB0();
extern float D_4001FA40[];
typedef struct {
    s32 id;     /* 0x00 */
    s32 v1;     /* 0x04 */
    s32 v2;     /* 0x08 */
    s32 v3;     /* 0x0c */
    s32 v4;     /* 0x10 */
    s32 v5;     /* 0x14 */
} DeadEdit;
typedef union {
    struct {
        u8 pad00[0x10];
        s16 h10;
        s16 h12;
        s16 h14;
        s16 h16;
        s16 h18;
    } s;
    u8 raw[0x30];
    u64 al[6];
} DeadPoint;
extern DeadEdit D_4002F038;
DeadPoint *getDeadPointData(void *h, s32 idx);
void func_4001D0A8();
void func_4001D148();
extern float D_4001FD88[];
typedef struct {
    u8 pad00[0xc];
    s32 cnt;    /* 0x0c */
    s32 v10;    /* 0x10 */
} HorseInfo;
extern HorseInfo SH_SCRInterestHORSE;
extern float D_4001FD50[];
void createParamMenu();
void cursorLockParamMenu();
void *memcpy(void *dst, const void *src, u32 n);
typedef union {
    s32 w;
    float f;
} W;

void func_40019028(void) {
    SubPoint *p;
    if (D_4002DF80.p18.p != 0) {
        p = getSubPointData(D_4002DF80.p18.p, D_4002F010.id);
        D_4002DF80.cur = p;
        D_4002F010.val = p->s.val;
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
        if (D_4002DF80.p18.p != 0) {
            u32 n = *(u32 *)D_4002DF80.p18.p;
            u32 *h;
            s32 add = 0;
            u32 i = 0;
            s32 sz = n * 0x30 + 0x40;
            h = iosMallocAlign(rootPtn, sz, 0x10);
            h[0] = n + 1;
            h[1] = sz;
            h[2] = 0;
            h[3] = 0;
            if (n != 0) {
                do {
                    SubPoint *d = getSubPointData(h, i + add);
                    SubPoint *s = getSubPointData(D_4002DF80.p18.p, i);
                    *d = *s;
                    if (D_4002F010.id == i) {
                        add = 1;
                        func_4001C3F0(h, i + 1);
                    }
                    i++;
                } while (i < n);
            }
            D_4002F010.id = D_4002F010.id + 1;
            func_4001C660(h);
            return;
        } else {
            u32 *h = iosMallocAlign(rootPtn, 0x40, 0x10);
            h[0] = 1;
            h[1] = 0x40;
            h[2] = 0;
            h[3] = 0;
            func_4001C3F0(h, 0);
            func_4001C660(h);
        }
    }
}

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0005_func_40019028", func_400192B8);

void func_400195A0(void) {
    SubPoint *p;
    SubPoint *g;
    if (D_4002DF80.p18.p != 0) {
        p = getSubPointData(D_4002DF80.p18.p, D_4002F010.id);
        D_4002DF80.cur = p;
        D_4002F010.val = p->s.val;
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
        if (D_4002DF80.p18.p != 0) {
            if (D_4002DF80.p14 != 0) {
                g = getSubPointData(D_4002DF80.p18.p, D_4002F010.id);
                if (g != 0) {
                    D_4002F008.id = g->s.val;
                    D_4002DF80.mode = 4;
                    windowCloseRequest(*(s32 *)(D_4001FA34 + 4));
                }
            }
        }
    }
}

void func_40019708(void) {
    SubPoint *p;
    SubPoint *q;
    s32 i;
    if (D_4002DF80.p18.p != 0) {
        p = getSubPointData(D_4002DF80.p18.p, D_4002F010.id);
        D_4002DF80.cur = p;
        D_4002F010.val = p->s.val;
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
        if (D_4002DF80.p18.p != 0) {
            if (D_4002DF80.p14 != 0) {
                q = getSubPointData(D_4002DF80.p18.p, D_4002F010.id);
                if (q != 0) {
                    i = D_4002F010.id + 1;
                    if ((u32)i < *(u32 *)D_4002DF80.p18.p) {
                        do {
                            if (q->s.val == getSubPointData(D_4002DF80.p18.p, i)->s.val) {
                                D_4002F010.id = i;
                                return;
                            }
                            i++;
                        } while ((u32)i < *(u32 *)D_4002DF80.p18.p);
                    }
                    i = 0;
                    if (0 < D_4002F010.id) {
                        do {
                            if (q->s.val == getSubPointData(D_4002DF80.p18.p, i)->s.val) {
                                D_4002F010.id = i;
                                return;
                            }
                            i++;
                        } while (i < D_4002F010.id);
                    }
                }
            }
        }
    }
}

void func_400198D8(void) {
    SubPoint *p;
    SubPoint *q;
    s32 i;
    if (D_4002DF80.p18.p != 0) {
        p = getSubPointData(D_4002DF80.p18.p, D_4002F010.id);
        D_4002DF80.cur = p;
        D_4002F010.val = p->s.val;
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
        if (D_4002DF80.p18.p != 0) {
            if (D_4002DF80.p14 != 0) {
                q = getSubPointData(D_4002DF80.p18.p, D_4002F010.id);
                if (q != 0) {
                    i = D_4002F010.id - 1;
                    if (i >= 0) {
                        do {
                            if (q->s.val == getSubPointData(D_4002DF80.p18.p, i)->s.val) {
                                D_4002F010.id = i;
                                return;
                            }
                            i--;
                        } while (i >= 0);
                    }
                    i = *(u32 *)D_4002DF80.p18.p - 1;
                    if (D_4002F010.id < i) {
                        do {
                            if (q->s.val == getSubPointData(D_4002DF80.p18.p, i)->s.val) {
                                D_4002F010.id = i;
                                return;
                            }
                            i--;
                        } while (D_4002F010.id < i);
                    }
                }
            }
        }
    }
}

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0005_func_40019028", func_40019AA8);

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0005_func_40019028", func_40019C00);

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0005_func_40019028", func_40019E18);

void func_4001A080(void) {
    DeadPoint *p;
    if (D_4002DF80.p30.p != 0) {
        p = getDeadPointData(D_4002DF80.p30.p, D_4002F038.id);
        D_4002DF80.cur = p;
        D_4002F038.v1 = p->s.h10;
        D_4002F038.v2 = p->s.h12;
        D_4002F038.v3 = p->s.h14;
        D_4002F038.v4 = p->s.h16;
        D_4002F038.v5 = p->s.h18;
        func_40011780(D_4002DF80.fd0);
    } else {
        D_4002DF80.cur = 0;
    }
    if (DEBUG_is_locking_debug_camera() != 0 && D_4002DF80.cur != 0) {
        DebugGlobalMoveWith2ndController(D_4002DF80.cur, D_4002DF80.cur);
    }
    if (*(s32 *)(padManagerData + 8) & 0x20) {
        if (D_4002DF80.p30.p != 0) {
            u32 n = *(u32 *)D_4002DF80.p30.p;
            u32 *h;
            s32 add = 0;
            u32 i = 0;
            s32 sz = n * 0x30 + 0x40;
            h = iosMallocAlign(rootPtn, sz, 0x10);
            h[0] = n + 1;
            h[1] = sz;
            h[2] = 0;
            h[3] = 0;
            if (n != 0) {
                do {
                    DeadPoint *d = getDeadPointData(h, i + add);
                    DeadPoint *s = getDeadPointData(D_4002DF80.p30.p, i);
                    *d = *s;
                    if (((W *)&D_4002F038)->w == i) {
                        add = 1;
                        func_4001D0A8(h, i + 1);
                    }
                    i++;
                } while (i < n);
            }
            D_4002F038.id = D_4002F038.id + 1;
            func_4001D148(h);
            return;
        } else {
            u32 *h = iosMallocAlign(rootPtn, 0x40, 0x10);
            h[0] = 1;
            h[1] = 0x40;
            h[2] = 0;
            h[3] = 0;
            func_4001D0A8(h, 0);
            func_4001D148(h);
        }
    }
}

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0005_func_40019028", func_4001A2D8);

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0005_func_40019028", func_4001A588);
