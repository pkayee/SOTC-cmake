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

extern s32 DldSysUndefSymbol;
static inline u8 *dldElem(u32 *lp) { /* inline helper */
    u8 *slot;
    u32 w = *lp;
    u32 off = w & 0x3FFFF;

    slot = off ? *(u8 **)((u8 *)lp - off) : NULL;
    return (slot != NULL && slot != (u8 *)DldSysUndefSymbol)
               ? *(u8 **)(slot + 0x10) + ((w >> 18) & 0xFFF) * *(s32 *)(*(u8 **)(slot + 8) + 0xC)
               : NULL;
}

s32 func_4005E098();

s32 func_4005FD78();

extern u128 ZeroPoint;
extern u128 IdentityQuaternion;
s32 _isysRecvSubMsg();
s32 ForceParentLayoutObj();
void SetCharacterClassMotionNormalSyncMode();
void SetCharacterClassMotionAddSyncMode();

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

u8 *CharaCtrlSearchControlChange(u8 *target, u8 *tbl) {
    s32 i;
    s32 n;
    u8 *ent;

    if (tbl != NULL) {
        n = *(s32 *)(tbl + 0xC);
        ent = *(u8 **)(tbl + 0x10);
        for (i = 0; i < n; i++, ent += 0x10) {
            if (dldElem((u32 *)(ent + 8)) == target) {
                return dldElem((u32 *)(ent + 0xC));
            }
        }
    }
    return NULL;
}

s32 CheckControlDef(s32 a, s32 b, s32 c, u32 *lp) {
    s32 *p = (s32 *)dldElem(lp);

    while (*p != 1) {
        if (func_4005E098(a, b, c, p) == 0) {
            return 0;
        }
        p += 0xC;
    }
    return 1;
}

s32 CheckControlDefByStatus(s32 a, u32 *lp) {
    s32 *p = (s32 *)dldElem(lp);

    while (*p != 1) {
        if (func_4005FD78(a, p) == 0) {
            return 0;
        }
        p += 0xC;
    }
    return 1;
}

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

void RecvCharacterObjMail(s32 obj) {
    s32 msg[24];
    u8 *cc = GetCharacterClass(obj);

    while (_isysRecvSubMsg(cc + 0x1028, msg, 0x60) != 0) {
        switch (msg[20]) {
        case 0:
            break;
        case 1:
            ChangeCharacterObjControlTarget(obj, msg[0]);
            break;
        case 2:
            ChangeCharacterObjControlledTarget(obj, msg[16], (s32)msg, msg[17]);
            break;
        case 3:
            SetCharacterClassMotionNormalSyncMode(cc, msg[0]);
            break;
        case 5:
            SetCharacterClassMotionAddSyncMode(cc, msg[0]);
            break;
        case 4: {
            u8 *lc;

            ForceParentLayoutObj(obj, msg);
            lc = GetLayoutClass(obj);
            *(u128 *)(lc + 0x70) = ZeroPoint;
            *(u128 *)(lc + 0x60) = IdentityQuaternion;
            break;
        }
        }
    }
}
