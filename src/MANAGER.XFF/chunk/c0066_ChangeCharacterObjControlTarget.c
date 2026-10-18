#include "common.h"

typedef struct ScriptBtnCb {
    s32 w[7];
} ScriptBtnCb;
extern s32 D_4012AF04;
extern s32 D_4012AEE0;
extern s32 D_4012AF08;
extern s32 D_4012AF0C;
extern s32 D_4012AF10;
extern ScriptBtnCb D_4012AEE8;
typedef struct Blk1F0 { u64 w[0x3E]; } Blk1F0;
typedef struct Blk80 { u64 w[0x10]; } Blk80;
extern Blk1F0 D_4012ACF0;
extern Blk80 D_4012ABB0;

u8 *GetCharacterClass();
u8 *GetLayoutClass();
u8 *GetGeometryPointerObject();
void CopyGeometryPointer();
void DecreaseDamageLockTime();
void func_40061030(s32, s32, s32, s32, f32);
f32 ViewIntervalClip(s32, s32, f32);
u8 *GetScrLwsOriClass();

void ChangeCharacterObjControlTarget(s32 obj, s32 v) {
    *(s32 *)(GetCharacterClass(obj) + 0x940) = v;
}

void ChangeCharacterObjControlledTarget(s32 a, s32 b, s32 c, s32 d) {
    u8 *cc = GetCharacterClass();

    *(s32 *)(cc + 0x950) = b;
    if (a != b) {
        *(u8 *)(cc + 0x9B5) = 1;
        CopyGeometryPointer(cc + 0x960, c);
        *(s32 *)(cc + 0x9A0) = d;
    }
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0066_ChangeCharacterObjControlTarget", CharaCtrlSearchControlChange);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0066_ChangeCharacterObjControlTarget", CheckControlDef);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0066_ChangeCharacterObjControlTarget", CheckControlDefByStatus);

void CharaCtrlPlayableControl(s32 a, s32 b, s32 c, f32 dt) {
    if (dt != 0.0f) {
        func_40061030(a, b, c, 0, dt);
    }
}

void CharaCtrlPlayableControlExt(s32 a, s32 b, s32 c, f32 dt) {
    if (dt != 0.0f) {
        func_40061030(a, b, c, 1, dt);
    }
}

void CharaCtrlAIControl(s32 obj, s32 a1, f32 a, f32 dt) {
    if (dt != 0.0f) {
        u8 *cc = GetCharacterClass(obj);
        f32 r = ViewIntervalClip(obj, a1, a);

        if (*(s32 *)(cc + 0xFD0) != 1) {
            dt = r;
        }
        func_40061030(obj, 0, 0, 0, dt);
    }
}

void CharaCtrlResetCtrlStatus(s32 obj) {
    u8 *cc = GetCharacterClass(obj);

    if (cc == NULL) {
        u8 *c2 = NULL;
        u8 *lc = GetLayoutClass(obj);

        if (*(s32 *)(lc + 0x124) != 0) {
            u8 *g = GetGeometryPointerObject(lc + 0xC0);

            if (g[8] == 0x16) {
                c2 = GetCharacterClass(g);
            }
        }
        cc = c2;
        if (cc == NULL) {
            return;
        }
    }
    *(Blk1F0 *)(cc + 0x750) = D_4012ACF0;
}

void CharaCtrlResetAllScriptCtrlStatus(s32 obj) {
    u8 *cc = GetCharacterClass(obj);
    u64 *p;

    if (cc == NULL) {
        u8 *c2 = NULL;
        u8 *lc = GetLayoutClass(obj);

        if (*(s32 *)(lc + 0x124) != 0) {
            u8 *g = GetGeometryPointerObject(lc + 0xC0);

            if (g[8] == 0x16) {
                c2 = GetCharacterClass(g);
            }
        }
        cc = c2;
        if (cc == NULL) {
            return;
        }
    }
    p = (u64 *)(cc + 0x910);
    *p = 0;
}

void CharaCtrlSetScriptCtrlStatus(s32 obj, s32 n) {
    u8 *cc = GetCharacterClass(obj);
    u64 *p;

    if (cc == NULL) {
        u8 *c2 = NULL;
        u8 *lc = GetLayoutClass(obj);

        if (*(s32 *)(lc + 0x124) != 0) {
            u8 *g = GetGeometryPointerObject(lc + 0xC0);

            if (g[8] == 0x16) {
                c2 = GetCharacterClass(g);
            }
        }
        cc = c2;
        if (cc == NULL) {
            return;
        }
    }
    p = (u64 *)(cc + 0x910);
    *p |= 1L << n;
}

void CharaCtrlResetScriptCtrlStatus(s32 obj, s32 n) {
    u8 *cc = GetCharacterClass(obj);
    u64 *p;

    if (cc == NULL) {
        u8 *c2 = NULL;
        u8 *lc = GetLayoutClass(obj);

        if (*(s32 *)(lc + 0x124) != 0) {
            u8 *g = GetGeometryPointerObject(lc + 0xC0);

            if (g[8] == 0x16) {
                c2 = GetCharacterClass(g);
            }
        }
        cc = c2;
        if (cc == NULL) {
            return;
        }
    }
    p = (u64 *)(cc + 0x910);
    *p &= ~(1L << n);
}

void CharaCtrlResetPlayableCtrlStatus(s32 obj) {
    u8 *cc = GetCharacterClass(obj);

    if (cc == NULL) {
        u8 *c2 = NULL;
        u8 *lc = GetLayoutClass(obj);

        if (*(s32 *)(lc + 0x124) != 0) {
            u8 *g = GetGeometryPointerObject(lc + 0xC0);

            if (g[8] == 0x16) {
                c2 = GetCharacterClass(g);
            }
        }
        cc = c2;
        if (cc == NULL) {
            return;
        }
    }
    *(Blk80 *)(cc + 0x7D0) = D_4012ABB0;
}

void CharaCtrlSetOutsideScriptCtrlStatus(s32 obj, s32 n) {
    u8 *cc = GetCharacterClass(obj);
    u64 *p;

    if (cc == NULL) {
        u8 *c2 = NULL;
        u8 *lc = GetLayoutClass(obj);

        if (*(s32 *)(lc + 0x124) != 0) {
            u8 *g = GetGeometryPointerObject(lc + 0xC0);

            if (g[8] == 0x16) {
                c2 = GetCharacterClass(g);
            }
        }
        cc = c2;
        if (cc == NULL) {
            return;
        }
    }
    p = (u64 *)(cc + 0x918);
    *p |= 1L << n;
}

void CharaCtrlSetScriptCtrlStatusCallBack(s32 obj, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1, s32 t2, s32 t3) {
    u8 *cc = GetCharacterClass(obj);
    s32 *q;

    if (cc == NULL) {
        u8 *c2 = NULL;
        u8 *lc = GetLayoutClass(obj);

        if (*(s32 *)(lc + 0x124) != 0) {
            u8 *g = GetGeometryPointerObject(lc + 0xC0);

            if (g[8] == 0x16) {
                c2 = GetCharacterClass(g);
            }
        }
        cc = c2;
        if (cc == NULL) {
            return;
        }
    }
    q = (s32 *)(cc + 0x920);
    q[0] = a1;
    q[1] = a2;
    q[2] = a3;
    q[3] = t0;
    q[4] = t1;
    q[5] = t2;
    q[6] = t3;
}

void InitScriptControlButtonCallBack(ScriptBtnCb *dst) {
    *dst = D_4012AEE8;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0066_ChangeCharacterObjControlTarget", CheckParentCharOrLwsOrient);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0066_ChangeCharacterObjControlTarget", IsParentCharOrLwsOrient);

void ForceAcceptMotionControlChange(u8 *a, s32 v) {
    s32 old = *(s32 *)(a + 0x740);

    if (old != v) {
        *(s32 *)(a + 0x744) = old;
        *(s32 *)(a + 0x740) = v;
    }
}

s32 *getMotionPrintTarget(void) {
    return &D_4012AEE0;
}

s32 *getLocalAccelDispFlag(void) {
    return &D_4012AF04;
}

s32 *getScriptSwitchDispSw(void) {
    return &D_4012AF08;
}

void resetOutsideScriptCtrlStatus(u8 *a) {
    *(s64 *)(a + 0x918) = 0;
}

s32 GetPadControlFlag(void) {
    return D_4012AF0C != 0;
}

s32 checkScriptControlDef(s32 mask, u8 *def, s32 dflt) {
    s64 m;
    s32 kind;
    s32 r;

    if (def == NULL) {
        return dflt;
    }
    m = mask & (1L << *(s32 *)(def + 4));
    kind = *(s32 *)(def + 8);
    r = 1;
    if (kind != 1) {
        r = 0;
        if (kind == 2) {
            return m ? r : dflt;
        }
        r = 1;
    }
    return m ? r : dflt;
}

void YattsukeSetPlayerR1ON(s32 v) {
    D_4012AF10 = v;
}

void ResetCharacterClassMailRelationalTriggerFlags(u8 *a) {
    DecreaseDamageLockTime(a + 0x200);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0066_ChangeCharacterObjControlTarget", RecvCharacterObjMail);
