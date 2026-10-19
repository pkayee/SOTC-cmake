#include "common.h"

typedef union {
    void *p;
    s32 w;
} PathSlot;
typedef struct {
    u8 pad00[0x10];
    u32 *p10;       /* 0x10 root points */
    u32 *p14;       /* 0x14 goal points */
    u32 *p18;       /* 0x18 sub points */
    s32 f1c;        /* 0x1c */
    u8 pad20[0xb0];
    s32 fd0;        /* 0xd0 */
    u8 padd4[0x10];
    void *cur;      /* 0xe4 */
    u8 padE8[0x18];
    s32 mode;       /* 0x100 */
} PathFree;
extern PathFree D_4002DF80;
typedef struct {
    s32 id;
    s32 val;
} PathEdit;
extern PathEdit D_4002F000;
extern PathEdit D_4002F008;
extern PathEdit D_4002F010;
typedef union {
    struct {
        u8 pad00[0x10];
        s16 h10;
    } s;
    u8 raw[0x20];
} GoalPt;
typedef union {
    struct {
        u8 pad00[0x10];
        s32 w10;
    } s;
    u8 raw[0x20];
} RootPt;
typedef union {
    struct {
        u8 pad00[0x18];
        s16 h18;
    } s;
    u8 raw[0x20];
} SubPt;
RootPt *getRootPointData(u32 *h, s32 idx);
GoalPt *getGoalPointData(u32 *h, s32 idx);
SubPt *getSubPointData(u32 *h, s32 idx);
void func_40011780(s32 a);
s32 DEBUG_is_locking_debug_camera(void);
void DebugGlobalMoveWith2ndController(void *a, void *b);
extern u8 padManagerData[];
void windowCloseRequest(s32 a);
extern u8 *D_4001F5D4;
extern u8 *D_4001F1E4;
extern float D_4001EEA8[];
extern float D_4001EEC4;
extern char rootPtn[];
extern char D_4001F1B8[];
void *iosMallocAlign(void *, s32, s32);
void *memcpy(void *dst, const void *src, u32 n);
void func_4001BD08();
void createParamMenu();
void cursorLockParamMenu();

void func_40017728(u8 *self) {
    void *q;
    if (D_4002DF80.p10 != 0) {
        D_4001EEA8[7] = (float)*D_4002DF80.p10;
        D_4001EEA8[7] = D_4001EEA8[7] - 1.0f;
        if (D_4001EEA8[7] < 0.0f) {
            D_4001EEA8[7] = 0.0f;
        }
        if (D_4002DF80.f1c == 0) {
            q = iosMallocAlign(rootPtn, D_4002DF80.p10[1], 0x10);
            memcpy(q, D_4002DF80.p10, D_4002DF80.p10[1]);
            func_4001BD08(q);
        }
    } else {
        D_4001EEC4 = 0.0f;
    }
    createParamMenu(D_4001F1B8, *(s32 *)(self + 0x94));
    cursorLockParamMenu(D_4001F1B8, 1);
    return;
}

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0004_func_40017728", func_40017848);

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0004_func_40017728", func_40017B18);

void func_40017F98(void) {
    RootPt *r;
    GoalPt *g;
    u32 i;
    if (D_4002DF80.p10 != 0) {
        D_4002DF80.cur = getRootPointData(D_4002DF80.p10, D_4002F000.id);
        D_4002F000.val = ((RootPt *)D_4002DF80.cur)->s.w10;
        func_40011780(D_4002DF80.fd0);
    } else {
        D_4002DF80.cur = 0;
    }
    if (DEBUG_is_locking_debug_camera() != 0 && D_4002DF80.cur != 0) {
        DebugGlobalMoveWith2ndController(D_4002DF80.cur, D_4002DF80.cur);
    }
    if (*(s32 *)(padManagerData + 8) & 0x20) {
        if (D_4002DF80.p10 != 0) {
            if (D_4002DF80.p14 != 0) {
                i = 0;
                if (*D_4002DF80.p14 != 0) {
                    do {
                        g = getGoalPointData(D_4002DF80.p14, i);
                        if (g != 0 && D_4002F000.id == g->s.h10) {
                            D_4002DF80.mode = 4;
                            D_4002F008.id = i;
                            windowCloseRequest(*(s32 *)(D_4001F1E4 + 4));
                            return;
                        }
                        i++;
                    } while (i < *D_4002DF80.p14);
                }
            }
        }
    }
}

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0004_func_40017728", func_400180D0);

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0004_func_40017728", func_40018280);

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0004_func_40017728", func_40018550);

void func_40018948(void) {
    GoalPt *g;
    if (D_4002DF80.p14 != 0) {
        D_4002DF80.cur = getGoalPointData(D_4002DF80.p14, D_4002F008.id);
        D_4002F008.val = ((GoalPt *)D_4002DF80.cur)->s.h10;
        func_40011780(D_4002DF80.fd0);
    } else {
        D_4002DF80.cur = 0;
    }
    if (DEBUG_is_locking_debug_camera() != 0 && D_4002DF80.cur != 0) {
        DebugGlobalMoveWith2ndController(D_4002DF80.cur, D_4002DF80.cur);
    }
    if (*(s32 *)(padManagerData + 8) & 0x20) {
        if (D_4002DF80.p14 != 0) {
            if (D_4002DF80.p10 != 0) {
                g = getGoalPointData(D_4002DF80.p14, D_4002F008.id);
                if (g != 0) {
                    D_4002F000.id = g->s.h10;
                    D_4002DF80.mode = 3;
                    windowCloseRequest(*(s32 *)(D_4001F5D4 + 4));
                }
            }
        }
    }
}

void func_40018A48(void) {
    GoalPt *g;
    SubPt *s;
    u32 i;
    if (D_4002DF80.p14 != 0) {
        D_4002DF80.cur = getGoalPointData(D_4002DF80.p14, D_4002F008.id);
        D_4002F008.val = ((GoalPt *)D_4002DF80.cur)->s.h10;
        func_40011780(D_4002DF80.fd0);
    } else {
        D_4002DF80.cur = 0;
    }
    if (DEBUG_is_locking_debug_camera() != 0 && D_4002DF80.cur != 0) {
        DebugGlobalMoveWith2ndController(D_4002DF80.cur, D_4002DF80.cur);
    }
    if (*(s32 *)(padManagerData + 8) & 0x20) {
        if (D_4002DF80.p14 != 0) {
            if (D_4002DF80.p18 != 0) {
                i = 0;
                if (*D_4002DF80.p18 != 0) {
                    do {
                        s = getSubPointData(D_4002DF80.p18, i);
                        if (s != 0 && D_4002F008.id == s->s.h18) {
                            D_4002DF80.mode = 5;
                            D_4002F010.id = i;
                            windowCloseRequest(*(s32 *)(D_4001F5D4 + 4));
                            return;
                        }
                        i++;
                    } while (i < *D_4002DF80.p18);
                }
            }
        }
    }
}

void func_40018B80(void) {
    GoalPt *g;
    GoalPt *t;
    u32 i;
    s32 j;
    if (D_4002DF80.p14 != 0) {
        D_4002DF80.cur = getGoalPointData(D_4002DF80.p14, D_4002F008.id);
        D_4002F008.val = ((GoalPt *)D_4002DF80.cur)->s.h10;
        func_40011780(D_4002DF80.fd0);
    } else {
        D_4002DF80.cur = 0;
    }
    if (DEBUG_is_locking_debug_camera() != 0 && D_4002DF80.cur != 0) {
        DebugGlobalMoveWith2ndController(D_4002DF80.cur, D_4002DF80.cur);
    }
    if (*(s32 *)(padManagerData + 8) & 0x20) {
        if (D_4002DF80.p14 != 0) {
            if (D_4002DF80.p10 != 0) {
                g = getGoalPointData(D_4002DF80.p14, D_4002F008.id);
                if (g != 0) {
                    i = D_4002F008.id + 1;
                    if (i < *D_4002DF80.p14) {
                        do {
                            t = getGoalPointData(D_4002DF80.p14, i);
                            if (g->s.h10 == t->s.h10) {
                                D_4002F008.id = i;
                                return;
                            }
                            i++;
                        } while (i < *D_4002DF80.p14);
                    }
                    j = 0;
                    if (D_4002F008.id > 0) {
                        do {
                            t = getGoalPointData(D_4002DF80.p14, j);
                            if (g->s.h10 == t->s.h10) {
                                D_4002F008.id = j;
                                return;
                            }
                            j++;
                        } while (j < D_4002F008.id);
                    }
                }
            }
        }
    }
}

void func_40018D00(void) {
    GoalPt *g;
    GoalPt *t;
    s32 i;
    if (D_4002DF80.p14 != 0) {
        D_4002DF80.cur = getGoalPointData(D_4002DF80.p14, D_4002F008.id);
        D_4002F008.val = ((GoalPt *)D_4002DF80.cur)->s.h10;
        func_40011780(D_4002DF80.fd0);
    } else {
        D_4002DF80.cur = 0;
    }
    if (DEBUG_is_locking_debug_camera() != 0 && D_4002DF80.cur != 0) {
        DebugGlobalMoveWith2ndController(D_4002DF80.cur, D_4002DF80.cur);
    }
    if (*(s32 *)(padManagerData + 8) & 0x20) {
        if (D_4002DF80.p14 != 0) {
            if (D_4002DF80.p10 != 0) {
                g = getGoalPointData(D_4002DF80.p14, D_4002F008.id);
                if (g != 0) {
                    for (i = D_4002F008.id - 1; i >= 0; i--) {
                        t = getGoalPointData(D_4002DF80.p14, i);
                        if (g->s.h10 == t->s.h10) {
                            D_4002F008.id = i;
                            return;
                        }
                    }
                    for (i = *D_4002DF80.p14 - 1; D_4002F008.id < i; i--) {
                        t = getGoalPointData(D_4002DF80.p14, i);
                        if (g->s.h10 == t->s.h10) {
                            D_4002F008.id = i;
                            return;
                        }
                    }
                }
            }
        }
    }
}

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0004_func_40017728", func_40018E78);
