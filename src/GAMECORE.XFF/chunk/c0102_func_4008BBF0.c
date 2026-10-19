#include "common.h"

extern s32 SkelFocusDef_PLAYER_HAND_A_R;
extern s32 ScriptAnimationObjDef_HARPOON_LOOP;
extern u8 *GetSCRCharaAIWorkPtr();
extern void isysRequestDeleteObj();
extern s32 _SCRSetupLWSWithTargetNodeParent(s32 def, s32 obj, s32 node);
extern void _SCRStartLWS(s32 lws, s32 a, s32 b, void *c);
extern void func_40088BC8(void *w);

extern s32 DldSysUndefSymbol;
extern s32 SH_ScriptRequestEffectDefPOSEIDON_HIT;
extern s32 ScriptRequestEffectDef_COM_TORCHHIT;
extern s32 ScriptRequestEffectDef_POSE_ICOSWORDHIT;
extern s32 ScriptRequestEffectDef_ICOSWORDHIT;
extern s32 ScriptRequestEffectDef_POSE_SWORDHIT;
extern s32 ScriptRequestEffectDef_SWORDHIT;
extern void ExecEff(s32 def, s32 a, s32 obj, s32 b, void *pos);

extern s32 ScriptRequestEffectDef_POSE_ICOSWORDHIT_M;
extern s32 ScriptRequestEffectDef_ICOSWORDHIT_M;
extern s32 ScriptRequestEffectDef_POSE_SWORDHIT_M;
extern s32 ScriptRequestEffectDef_SWORDHIT_M;

extern s32 ScriptRequestEffectDef_POSE_ICOSWORDHIT_L;
extern s32 ScriptRequestEffectDef_ICOSWORDHIT_L;
extern s32 ScriptRequestEffectDef_POSE_SWORDHIT_L;
extern s32 ScriptRequestEffectDef_SWORDHIT_L;

extern s32 ScriptRequestEffectDef_POSE_ICOSWORDHIT_DIVE;
extern s32 ScriptRequestEffectDef_ICOSWORDHIT_DIVE;
extern s32 ScriptRequestEffectDef_POSE_SWORDHIT_DIVE;
extern s32 ScriptRequestEffectDef_SWORDHIT_DIVE;

extern void fadeout_weakpoint_effect(void);
extern s32 SCRSetupWeaponPlayer(s32 obj, s32 kind);
extern void SCRPlayerLostWeapon(s32 kind);
extern void _omakeGetFlagCls(s32 bit);
extern void _omakeSelectFlagCls(s32 bit);
extern void func_4008C3E0(s32 obj);

extern u8 *WeaponList_HAND;
extern u8 *GetCharacterClass();

extern u8 rootPtn[];
extern u8 *WeaponList_SWORD;
extern u8 YUnitVector[];
extern void *isysGetThisSubThread();
extern s32 iosCreatePartition();
extern u8 *GetScriptCharacterClass();
extern void CharaCtrlResetCtrlStatus();
extern void CharaCtrlResetAllScriptCtrlStatus();
extern u8 *_SCRMallocAlign();
extern void SetLayoutObjDebugResetFunc();
extern void SetLayoutObjSubDispFunc();
extern void MVHIST_Init();
extern void player_initHangPointWork();
extern void player_initAvoidDangerCliffWork();
extern void player_initSlipEffect();
extern void SetCollisionEdgeLinkDBFinderCollectStatus(s32 a, s32 b, s32 c, void *d, void *e, float f);
extern void isysJumpSubThread();
extern void func_4008DBB0();
extern void func_4008E160();
extern void func_4008E288();
extern void nico_player1();

void func_4008BBF0(s32 obj)
{
    u8 *w = GetSCRCharaAIWorkPtr();
    s32 *p = (s32 *)(w + 0x60);
    s32 lws;

    if (p[6] != 0) {
        isysRequestDeleteObj(p[6]);
        p[6] = 0;
    }
    if (p[1] != 0) {
        if (((u8 *)p)[0x15] == 0) {
            if (p[3] == 0) {
                isysRequestDeleteObj(p[1]);
            }
        } else {
            isysRequestDeleteObj(p[1]);
        }
        p[1] = 0;
        p[3] = 1;
        ((u8 *)p)[0x15] = 0;
    }
    if (p[0] != 0) {
        if (((u8 *)p)[0x14] == 0) {
            if (p[2] == 0) {
                isysRequestDeleteObj(p[0]);
            }
        } else {
            isysRequestDeleteObj(p[0]);
        }
        p[0] = 0;
        p[2] = 1;
        ((u8 *)p)[0x14] = 0;
    }
    lws = _SCRSetupLWSWithTargetNodeParent(ScriptAnimationObjDef_HARPOON_LOOP, obj, SkelFocusDef_PLAYER_HAND_A_R);
    *(s32 *)(w + 0x60) = lws;
    _SCRStartLWS(lws, -1, 5, w + 0x68);
    ((u8 *)w)[0x74] = 1;
    func_40088BC8(w);
}

void func_4008BD20(s32 obj)
{
    u8 *w = GetSCRCharaAIWorkPtr();
    if (*(s32 *)(w + 0x70) == 9) {
        ExecEff(ScriptRequestEffectDef_COM_TORCHHIT, 0, obj, 0, w + 0xA0);
        return;
    }
    if (*(s32 *)(w + 0x70) == 3) {
        if (DldSysUndefSymbol != (s32)&SH_ScriptRequestEffectDefPOSEIDON_HIT) {
            ExecEff(ScriptRequestEffectDef_POSE_ICOSWORDHIT, 0, obj, 0, w + 0xA0);
            return;
        }
        ExecEff(ScriptRequestEffectDef_ICOSWORDHIT, 0, obj, 0, w + 0xA0);
        return;
    }
    if (DldSysUndefSymbol != (s32)&SH_ScriptRequestEffectDefPOSEIDON_HIT) {
        ExecEff(ScriptRequestEffectDef_POSE_SWORDHIT, 0, obj, 0, w + 0xA0);
        return;
    }
    ExecEff(ScriptRequestEffectDef_SWORDHIT, 0, obj, 0, w + 0xA0);
}

void func_4008BE38(s32 obj)
{
    u8 *w = GetSCRCharaAIWorkPtr();
    if (*(s32 *)(w + 0x70) == 9) {
        ExecEff(ScriptRequestEffectDef_COM_TORCHHIT, 0, obj, 0, w + 0xA0);
        return;
    }
    if (*(s32 *)(w + 0x70) == 3) {
        if (DldSysUndefSymbol != (s32)&SH_ScriptRequestEffectDefPOSEIDON_HIT) {
            ExecEff(ScriptRequestEffectDef_POSE_ICOSWORDHIT_M, 0, obj, 0, w + 0xA0);
            return;
        }
        ExecEff(ScriptRequestEffectDef_ICOSWORDHIT_M, 0, obj, 0, w + 0xA0);
        return;
    }
    if (DldSysUndefSymbol != (s32)&SH_ScriptRequestEffectDefPOSEIDON_HIT) {
        ExecEff(ScriptRequestEffectDef_POSE_SWORDHIT_M, 0, obj, 0, w + 0xA0);
        return;
    }
    ExecEff(ScriptRequestEffectDef_SWORDHIT_M, 0, obj, 0, w + 0xA0);
}

void func_4008BF50(s32 obj)
{
    u8 *w = GetSCRCharaAIWorkPtr();
    if (*(s32 *)(w + 0x70) == 9) {
        ExecEff(ScriptRequestEffectDef_COM_TORCHHIT, 0, obj, 0, w + 0xA0);
        return;
    }
    if (*(s32 *)(w + 0x70) == 3) {
        if (DldSysUndefSymbol != (s32)&SH_ScriptRequestEffectDefPOSEIDON_HIT) {
            ExecEff(ScriptRequestEffectDef_POSE_ICOSWORDHIT_L, 0, obj, 0, w + 0xA0);
            return;
        }
        ExecEff(ScriptRequestEffectDef_ICOSWORDHIT_L, 0, obj, 0, w + 0xA0);
        return;
    }
    if (DldSysUndefSymbol != (s32)&SH_ScriptRequestEffectDefPOSEIDON_HIT) {
        ExecEff(ScriptRequestEffectDef_POSE_SWORDHIT_L, 0, obj, 0, w + 0xA0);
        return;
    }
    ExecEff(ScriptRequestEffectDef_SWORDHIT_L, 0, obj, 0, w + 0xA0);
}

void func_4008C068(s32 obj)
{
    u8 *w = GetSCRCharaAIWorkPtr();
    if (*(s32 *)(w + 0x70) == 3) {
        if (DldSysUndefSymbol != (s32)&SH_ScriptRequestEffectDefPOSEIDON_HIT) {
            ExecEff(ScriptRequestEffectDef_POSE_ICOSWORDHIT_DIVE, 0, obj, 0, w + 0xA0);
            return;
        }
        ExecEff(ScriptRequestEffectDef_ICOSWORDHIT_DIVE, 0, obj, 0, w + 0xA0);
        return;
    }
    if (DldSysUndefSymbol != (s32)&SH_ScriptRequestEffectDefPOSEIDON_HIT) {
        ExecEff(ScriptRequestEffectDef_POSE_SWORDHIT_DIVE, 0, obj, 0, w + 0xA0);
        return;
    }
    ExecEff(ScriptRequestEffectDef_SWORDHIT_DIVE, 0, obj, 0, w + 0xA0);
}

void nico_playerstart(void)
{
    void *th = isysGetThisSubThread();
    s32 part = iosCreatePartition(rootPtn, 0x1C33);
    u8 *sc;
    u8 *c1;
    u8 *chara;
    u8 *pw;
    u8 *arg;
    u8 *q;
    u8 *q2;
    u8 *q3;
    s32 word;
    s32 *p;
    s32 r;

    *(s32 *)(GetScriptCharacterClass(th) + 0x114C) = part;
    CharaCtrlResetCtrlStatus(th);
    CharaCtrlResetAllScriptCtrlStatus(th);
    sc = GetScriptCharacterClass(th);
    pw = _SCRMallocAlign(part, 0x1C00, 0x10);
    *(u8 **)(sc + 0x1150) = pw;

    arg = WeaponList_SWORD;
    c1 = GetCharacterClass(th);
    q = arg + 0x14;
    word = *(s32 *)q;
    if ((word & 0x3FFFF) != 0) {
        p = *(s32 **)(q - (word & 0x3FFFF));
    } else {
        p = 0;
    }
    if (p != 0 && (s32)p != DldSysUndefSymbol) {
        r = p[4] + (((u32)word >> 18) & 0xFFF) * ((s32 *)p[2])[3];
    } else {
        r = 0;
    }
    *(s32 *)(c1 + 0x1074) = r;

    c1 = GetCharacterClass(th);
    q2 = arg + 0x18;
    word = *(s32 *)q2;
    if ((word & 0x3FFFF) != 0) {
        p = *(s32 **)(q2 - (word & 0x3FFFF));
    } else {
        p = 0;
    }
    if (p != 0 && (s32)p != DldSysUndefSymbol) {
        r = p[4] + (((u32)word >> 18) & 0xFFF) * ((s32 *)p[2])[3];
    } else {
        r = 0;
    }
    *(s32 *)(c1 + 0x1078) = r;

    SetLayoutObjDebugResetFunc(th, func_4008DBB0);
    SetLayoutObjSubDispFunc(th, func_4008E160, 0);
    *(s32 *)(pw + 0xD28) = 0;
    MVHIST_Init(pw + 0xD80);

    q3 = *(u8 **)(GetCharacterClass(th) + 0x3E4);
    word = *(s32 *)q3;
    if ((word & 0x3FFFF) != 0) {
        p = *(s32 **)(q3 - (word & 0x3FFFF));
    } else {
        p = 0;
    }
    if (p != 0 && (s32)p != DldSysUndefSymbol) {
        r = p[4] + (((u32)word >> 18) & 0xFFF) * ((s32 *)p[2])[3];
    } else {
        r = 0;
    }
    *(s32 *)pw = r;

    player_initHangPointWork(pw + 0x1A40);
    player_initAvoidDangerCliffWork(th, pw + 0x1B30);
    player_initSlipEffect(th, pw + 0x1BE8);
    chara = GetCharacterClass(th);
    SetCollisionEdgeLinkDBFinderCollectStatus(*(s32 *)(chara + 0xDAC), 0, 1, YUnitVector, func_4008E288, 1.0f);
    chara[0xAB0] = 1;
    chara[0xAB1] = 1;
    *(s32 *)(pw + 0x1BE0) = 0;
    isysJumpSubThread(nico_player1, pw);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0102_func_4008BBF0", func_4008C3E0);

void func_4008C660(s32 obj, s32 kind)
{
    u8 *w = GetSCRCharaAIWorkPtr();
    s32 *p = (s32 *)(w + 0x60);

    if (p[1] != 0) {
        if (((u8 *)p)[0x15] == 0) {
            if (p[3] == 0) {
                isysRequestDeleteObj(p[1]);
            }
        } else {
            isysRequestDeleteObj(p[1]);
        }
        p[1] = 0;
        p[3] = 1;
        ((u8 *)p)[0x15] = 0;
    }
    if (p[0] != 0) {
        if (((u8 *)p)[0x14] == 0) {
            if (p[2] == 0) {
                isysRequestDeleteObj(p[0]);
            }
        } else {
            isysRequestDeleteObj(p[0]);
        }
        p[0] = 0;
        p[2] = 1;
        ((u8 *)p)[0x14] = 0;
    }
    if (p[6] != 0) {
        isysRequestDeleteObj(p[6]);
        p[6] = 0;
    }
    fadeout_weakpoint_effect();
    if (p[6] == 0) {
        p[6] = SCRSetupWeaponPlayer(obj, p[4]);
    }
    if (kind == 9) {
        SCRPlayerLostWeapon(9);
        _omakeGetFlagCls(0x10);
        _omakeSelectFlagCls(0x10);
        if (*(s32 *)(w + 0x110) == 0) {
            func_4008C3E0(obj);
        }
    }
}

void func_4008C7C8(s32 obj)
{
    u8 *w = GetSCRCharaAIWorkPtr();
    s32 *pp;
    u8 *chara;
    u8 *arg;
    u8 *q;
    s32 word;
    s32 *p;
    s32 r;

    if (*(s32 *)(w + 0x70) == 9) {
        func_4008C3E0(obj);
        if (*(s32 *)(w + 0x78) != 0) {
            pp = (s32 *)(w + 0x60);
            if (pp[6] != 0) {
                isysRequestDeleteObj(pp[6]);
                pp[6] = 0;
            }
            arg = WeaponList_HAND;
            chara = GetCharacterClass(obj);
            q = arg + 0x14;
            word = *(s32 *)q;
            if ((word & 0x3FFFF) != 0) {
                p = *(s32 **)(q - (word & 0x3FFFF));
            } else {
                p = 0;
            }
            if (p != 0 && (s32)p != DldSysUndefSymbol) {
                r = p[4] + (((u32)word >> 18) & 0xFFF) * ((s32 *)p[2])[3];
            } else {
                r = 0;
            }
            *(s32 *)(chara + 0x1074) = r;

            chara = GetCharacterClass(obj);
            q = arg + 0x18;
            word = *(s32 *)q;
            if ((word & 0x3FFFF) != 0) {
                p = *(s32 **)(q - (word & 0x3FFFF));
            } else {
                p = 0;
            }
            if (p != 0 && (s32)p != DldSysUndefSymbol) {
                r = p[4] + (((u32)word >> 18) & 0xFFF) * ((s32 *)p[2])[3];
            } else {
                r = 0;
            }
            *(s32 *)(chara + 0x1078) = r;
        }
    }
}

/* NEARMISS-STUB func_4008C920 */
#if 0 /* NEARMISS 69.14% cat=regalloc sub=- | REA READY drop-in scored 69.14 in-TU (apply_ready) | attempts=2 */
void func_4008C920(s32 obj, u32 *tbl, s32 cnt, u64 flag)
{
    u8 *lay = GetLayoutClass(obj);
    s32 found;
    s32 *p;
    u8 *link;
    s32 q;
    u32 word;
    u32 *e;
    s32 i;

    if (lay != 0) {
        found = 0;
        if (cnt != 0) {
            i = cnt - 1;
            e = tbl;
            do {
                word = *e;
                p = (s32 *)((u8 *)e - (word & 0x3FFFF));
                e += 2;
                if ((word & 0x3FFFF) == 0) {
                    p = 0;
                } else {
                    p = (s32 *)*p;
                }
                q = 0;
                if (p != 0) {
                    if ((s32)p == DldSysUndefSymbol) {
                        q = 0;
                    } else {
                        q = p[4] + ((word >> 18) & 0xFFF) * ((s32 *)p[2])[3];
                    }
                }
                if (q != 0 && ((s32 *)q)[2] == obj) {
                    found = 1;
                    break;
                }
                i--;
            } while (i != -1);
        }
        if (found) {
            u8 *x = *(u8 **)(lay + 0x144);
            if (x != 0) {
                *(u64 *)(x + 0x280) = (*(u64 *)(x + 0x280) & ~0x20ULL) | ((flag & 1) << 5);
                *(u64 *)(*(u8 **)(lay + 0x144) + 0x280) = (*(u64 *)(*(u8 **)(lay + 0x144) + 0x280) & ~0x80ULL) | ((flag & 1) << 7);
            }
            if (*(s32 *)(lay + 0x180) != 0) {
                SetClothAccessSwitch(*(s32 *)(lay + 0x178), flag);
            }
        }
        link = lay + 0x10C;
        while ((link = GetTwoWayLinkNext(link)) != 0) {
            func_4008C920(GetTwoWayLinkData(link), tbl, cnt, flag);
        }
    }
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0102_func_4008BBF0", func_4008C920);
