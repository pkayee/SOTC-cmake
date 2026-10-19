#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0101_nico_createPlayerParachute", nico_createPlayerParachute);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0101_nico_createPlayerParachute", func_4008A5B0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0101_nico_createPlayerParachute", nico_player1);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0101_nico_createPlayerParachute", SCRPlayerLandingRotateBounding);

/* NEARMISS-STUB func_4008ADA8 */
#if 0 /* NEARMISS 85.43% cat=regalloc sub=- | REA READY drop-in scored 85.43 in-TU (apply_ready) | attempts=1 */
/* c0101 func_4008ADA8: player work teardown of the two LWS slots at +0x60, then end sight-on */
void func_4008ADA8(s32 obj)
{
    u8 *w = GetSCRCharaAIWorkPtr(obj);
    s32 *p = (s32 *)(w + 0x60);
    u8 *sight;

    if (p[1] != 0) {
        if (((u8 *)p)[0x15] != 0) {
            isysRequestDeleteObj(p[1]);
        } else if (p[3] == 0) {
            isysRequestDeleteObj(p[1]);
        }
        p[1] = 0;
        p[3] = 1;
        ((u8 *)p)[0x15] = 0;
    }
    if (p[0] != 0) {
        if (((u8 *)p)[0x14] != 0) {
            isysRequestDeleteObj(p[0]);
        } else if (p[2] == 0) {
            isysRequestDeleteObj(p[0]);
        }
        p[0] = 0;
        p[2] = 1;
        ((u8 *)p)[0x14] = 0;
    }

    if (*(s32 *)(GetCharacterClass(obj) + 0x1074) != ScrParam_player_weapon_none) {
        if (p[6] == 0) {
            p[6] = SCRSetupWeaponPlayer(obj, p[4]);
        }
    }
    sight = w + 0x290;
    if (is_doing_nico_sight_on(sight) == 1) {
        end_nico_sight_on(sight);
    }
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0101_nico_createPlayerParachute", func_4008ADA8);

/* NEARMISS-STUB func_4008AEF0 */
#if 0 /* NEARMISS 94.2% cat=regalloc sub=- | REA READY drop-in scored 94.20 in-TU (apply_ready) | attempts=1 */
/* c0101 fruit pickup: apply the sheet row (max hp/grip, hp, grip) then delete the fruit obj */
void func_4008AEF0(void)
{
    u8 *w = GetSCRCharaAIWorkPtr();
    f32 *row = (f32 *)dldRef(*(u32 **)(GetScriptClass(*(s32 *)(w + 0x10C)) + 0x48), 0x10);
    f32 rem;
    u8 *node;
    u8 *cc;

    if (row != NULL) {
        if (row[0] != 0.0f) {
            sePlaySystemSound(SeList_hp_max);
        }
        if (row[1] != 0.0f) {
            sePlaySystemSound(SeList_grip_max);
        }
        addPlayerMaxHp(row[0]);
        rem = 100.0f - getPlayerMaxHp();
        if (0.0f < rem) {
            addPlayerMaxHp(rem);
        }
        addPlayerMaxGrip(row[1]);
        addPlayerHp(row[2]);
        addPlayerGrip(row[3]);
    }
    cc = GetCharacterClass(*(s32 *)(w + 0x10C));
    if (ControlMode_GEX_TAIL_DEATH != *(s32 *)(cc + 0x740)) {
        nico_setFruitsFlag(*(s32 *)(w + 0x10C));
        isysRequestDeleteObj(*(s32 *)(w + 0x10C));
        *(s32 *)(w + 0x10C) = 0;
    } else {
        node = getSObjNode(*(s32 *)(w + 0x10C));
        SetLayoutObjAccessSwitch(*(s32 *)(w + 0x10C), 0);
        if (node != NULL) {
            tailsFlagSet(*(s16 *)(node + 0x50), *(s32 *)(node + 0xC));
            setTailCutTime();
        }
        *(s32 *)(w + 0x10C) = 0;
    }
    *(s32 *)(w + 0x108) = 0;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0101_nico_createPlayerParachute", func_4008AEF0);

/* NEARMISS-STUB func_4008B070 */
#if 0 /* NEARMISS 88.66% cat=regalloc sub=- | REA READY drop-in scored 88.66 in-TU (apply_ready) | attempts=1 */
/* c0101 per-frame sight-on update: cache the old marker, read the stick, update or clear the marker */
void func_4008B070(s32 obj, u8 *w)
{
    u8 *sight = w + 0x290;
    u8 *marker = w + 0x30;
    f32 in[2];
    s32 on;

    w[0x51] = w[0x50];
    *(u128 *)(w + 0x40) = *(u128 *)(w + 0x30);
    on = is_doing_nico_sight_on(sight);
    if (on == 1) {
        GAMEUTIL_get_1p_left_analog_input_extend(&in[0], &in[1], 0, 0.3f);
        if (*(s32 *)(w + 0x12C) == 0) {
            func_4008B198(obj, w);
            doit_nico_sight_on(sight, GetWeaponRange(), in[0], in[1]);
        }
        get_predict_hit_position_nico_sight_on(marker, sight);
        w[0x50] = on;
        *(f32 *)(w + 0x3C) = 1.0f;
        sprWeaponSetMarker(marker, *(s32 *)(GetLayoutClass(obj) + 0x134), 1);
        *(s32 *)(w + 0x134) = on;
    } else {
        *(u128 *)(w + 0x30) = *(u128 *)ZeroPoint;
        w[0x50] = 0;
        sprWeaponSetMarker(0, 0, 0);
    }
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0101_nico_createPlayerParachute", func_4008B070);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0101_nico_createPlayerParachute", func_4008B198);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0101_nico_createPlayerParachute", func_4008B458);

/* NEARMISS-STUB func_4008B660 */
#if 0 /* NEARMISS 78.72% cat=regalloc sub=- | REA READY drop-in scored 78.72 in-TU (apply_ready) | attempts=1 */
/* c0101 bow start: restart the arrow and bow LWS pair */
void func_4008B660(s32 obj)
{
    u8 *w = GetSCRCharaAIWorkPtr(obj);
    s32 *p = (s32 *)(w + 0x60);
    s32 a0;

    if (p[6] != 0) {
        isysRequestDeleteObj(p[6]);
        p[6] = 0;
    }
    if (p[1] != 0) {
        if (((u8 *)p)[0x15] != 0) {
            isysRequestDeleteObj(p[1]);
        } else if (p[3] == 0) {
            isysRequestDeleteObj(p[1]);
        }
        p[1] = 0;
        p[3] = 1;
        ((u8 *)p)[0x15] = 0;
    }
    if (p[0] != 0) {
        if (((u8 *)p)[0x14] != 0) {
            isysRequestDeleteObj(p[0]);
        } else if (p[2] == 0) {
            isysRequestDeleteObj(p[0]);
        }
        p[0] = 0;
        p[2] = 1;
        ((u8 *)p)[0x14] = 0;
    }
    if (*(s32 *)(w + 0x70) == 4) {
        a0 = ScriptAnimationObjDef_ARROW_START;
    } else if (*(s32 *)(w + 0x70) == 6) {
        a0 = ScriptAnimationObjDef_ARROW_SOUND_START;
    } else {
        a0 = ScriptAnimationObjDef_ARROW_EXP_START;
    }

    *(s32 *)(w + 0x60) = _SCRSetupLWSWithTargetNodeParent(a0, obj, SkelFocusDef_PLAYER_HAND_A_R);
    *(s32 *)(w + 0x64) = _SCRSetupLWSWithTargetNodeParent(ScriptAnimationObjDef_BOW_START, obj, SkelFocusDef_PLAYER_HAND_A_L);
    _SCRStartLWS(*(s32 *)(w + 0x60), -1, 3, w + 0x68);
    _SCRStartLWS(*(s32 *)(w + 0x64), -1, 3, w + 0x6C);
    func_40088BC8(w);
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0101_nico_createPlayerParachute", func_4008B660);

/* NEARMISS-STUB func_4008B7E8 */
#if 0 /* NEARMISS 79.34% cat=regalloc sub=- | REA READY drop-in scored 79.34 in-TU (apply_ready) | attempts=1 */
/* c0101 bow loop: restart the arrow and bow LWS pair at looping level */
void func_4008B7E8(s32 obj)
{
    u8 *w = GetSCRCharaAIWorkPtr(obj);
    s32 *p = (s32 *)(w + 0x60);
    s32 a0;

    if (p[6] != 0) {
        isysRequestDeleteObj(p[6]);
        p[6] = 0;
    }
    if (p[1] != 0) {
        if (((u8 *)p)[0x15] != 0) {
            isysRequestDeleteObj(p[1]);
        } else if (p[3] == 0) {
            isysRequestDeleteObj(p[1]);
        }
        p[1] = 0;
        p[3] = 1;
        ((u8 *)p)[0x15] = 0;
    }
    if (p[0] != 0) {
        if (((u8 *)p)[0x14] != 0) {
            isysRequestDeleteObj(p[0]);
        } else if (p[2] == 0) {
            isysRequestDeleteObj(p[0]);
        }
        p[0] = 0;
        p[2] = 1;
        ((u8 *)p)[0x14] = 0;
    }
    if (*(s32 *)(w + 0x70) == 4) {
        a0 = ScriptAnimationObjDef_ARROW_LOOP;
    } else if (*(s32 *)(w + 0x70) == 6) {
        a0 = ScriptAnimationObjDef_ARROW_SOUND_LOOP;
    } else {
        a0 = ScriptAnimationObjDef_ARROW_EXP_LOOP;
    }

    *(s32 *)(w + 0x60) = _SCRSetupLWSWithTargetNodeParent(a0, obj, SkelFocusDef_PLAYER_HAND_A_R);
    *(s32 *)(w + 0x64) = _SCRSetupLWSWithTargetNodeParent(ScriptAnimationObjDef_BOW_LOOP, obj, SkelFocusDef_PLAYER_HAND_A_L);
    _SCRStartLWS(*(s32 *)(w + 0x60), -1, 5, w + 0x68);
    _SCRStartLWS(*(s32 *)(w + 0x64), -1, 5, w + 0x6C);
    *(u8 *)(w + 0x75) = 1;
    *(u8 *)(w + 0x74) = 1;
    func_40088BC8(w);
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0101_nico_createPlayerParachute", func_4008B7E8);

/* NEARMISS-STUB func_4008B980 */
#if 0 /* NEARMISS 85.06% cat=regalloc sub=- | REA READY drop-in scored 85.06 in-TU (apply_ready) | attempts=1 */
/* c0101 bow end: stop both LWS, start BOW_END on the left hand, then set up the arrow */
void func_4008B980(s32 obj)
{
    f32 buf[4];
    u8 *w = GetSCRCharaAIWorkPtr(obj);
    s32 *p;

    func_4008B458(buf, obj, w);
    p = (s32 *)(w + 0x60);
    if (p[1] != 0) {
        if (((u8 *)p)[0x15] != 0) {
            isysRequestDeleteObj(p[1]);
        } else if (p[3] == 0) {
            isysRequestDeleteObj(p[1]);
        }
        p[1] = 0;
        p[3] = 1;
        ((u8 *)p)[0x15] = 0;
    }
    if (p[0] != 0) {
        if (((u8 *)p)[0x14] != 0) {
            isysRequestDeleteObj(p[0]);
        } else if (p[2] == 0) {
            isysRequestDeleteObj(p[0]);
        }
        p[0] = 0;
        p[2] = 1;
        ((u8 *)p)[0x14] = 0;
    }

    *(s32 *)(w + 0x64) = _SCRSetupLWSWithTargetNodeParent(ScriptAnimationObjDef_BOW_END, obj, SkelFocusDef_PLAYER_HAND_A_L);
    _SCRStartLWS(*(s32 *)(w + 0x64), -1, 4, w + 0x6C);
    *(u8 *)(w + 0x75) = 1;
    func_40088BC8(w);
    SCRSetupArrow1ByPlayer2(obj, *(s32 *)(w + 0x70), buf, w + 0x150);
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0101_nico_createPlayerParachute", func_4008B980);

/* NEARMISS-STUB func_4008BAC0 */
#if 0 /* NEARMISS 84.27% cat=regalloc sub=- | REA READY drop-in scored 84.27 in-TU (apply_ready) | attempts=1 */
/* c0101 harpoon start: weapon 5, restart the right-hand LWS */
void func_4008BAC0(s32 obj)
{
    u8 *w = GetSCRCharaAIWorkPtr(obj);
    s32 *p = (s32 *)(w + 0x60);

    if (p[6] != 0) {
        isysRequestDeleteObj(p[6]);
        p[6] = 0;
    }
    if (p[1] != 0) {
        if (((u8 *)p)[0x15] != 0) {
            isysRequestDeleteObj(p[1]);
        } else if (p[3] == 0) {
            isysRequestDeleteObj(p[1]);
        }
        p[1] = 0;
        p[3] = 1;
        ((u8 *)p)[0x15] = 0;
    }
    if (p[0] != 0) {
        if (((u8 *)p)[0x14] != 0) {
            isysRequestDeleteObj(p[0]);
        } else if (p[2] == 0) {
            isysRequestDeleteObj(p[0]);
        }
        p[0] = 0;
        p[2] = 1;
        ((u8 *)p)[0x14] = 0;
    }

    *(s32 *)(w + 0x70) = 5;
    *(s32 *)(w + 0x60) = _SCRSetupLWSWithTargetNodeParent(ScriptAnimationObjDef_HARPOON_START, obj, SkelFocusDef_PLAYER_HAND_A_R);
    _SCRStartLWS(*(s32 *)(w + 0x60), -1, 3, w + 0x68);
    func_40088BC8(w);
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0101_nico_createPlayerParachute", func_4008BAC0);
