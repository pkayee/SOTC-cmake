#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0106_player_HellDangerDetect", player_HellDangerDetect);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0106_player_HellDangerDetect", func_40090138);

extern void CharaCtrlResetScriptCtrlStatus(int, int);
extern void CopyGeometryPointer(void *, void *);
extern void *GetLayoutClass(int);
extern unsigned char InitialGeometryPointer[];
extern void *ScriptCtrlDef_SCRPlayerFallDanger;
extern void *ScriptCtrlDef_SCRPlayerHellDanger;
extern void *GetCharacterClass(void *);
extern void CharaCtrlSetScriptCtrlStatus(void *, int);
extern int func_40090138(int, void *, int, int);
extern void charrootdyn_setVColFindFlag(void *, void *, float);
extern void charrootdyn_resetVColEdgeFindFlag(void *);
extern void *GetGeometryPointerObject(void *);
extern int AddTwoWayLinkNext(void *, void *);

void player_initAvoidDangerCliffWork(int arg0, void *arg1)
{
    (*(int *)((char *)(arg1) + 0)) = 0;
    CopyGeometryPointer(arg1 + 0x10, InitialGeometryPointer);
    CopyGeometryPointer(arg1 + 0x70, InitialGeometryPointer);
    (*(s128 *)((char *)(arg1) + 0x50)) = (s128) *(*(s128 **)((char *)(GetLayoutClass(arg0)) + 0x134));
    CharaCtrlResetScriptCtrlStatus(arg0, (*(int *)((char *)(ScriptCtrlDef_SCRPlayerFallDanger) + 4)));
    CharaCtrlResetScriptCtrlStatus(arg0, (*(int *)((char *)(ScriptCtrlDef_SCRPlayerHellDanger) + 4)));
}

void player_resetAvoidDangerCliffWork(int arg0, void *arg1)
{
    (*(int *)((char *)(arg1) + 0)) = 0;
    CopyGeometryPointer(arg1 + 0x10, InitialGeometryPointer);
    CopyGeometryPointer(arg1 + 0x70, InitialGeometryPointer);
    (*(s128 *)((char *)(arg1) + 0x50)) = (s128) *(*(s128 **)((char *)(GetLayoutClass(arg0)) + 0x134));
    CharaCtrlResetScriptCtrlStatus(arg0, (*(int *)((char *)(ScriptCtrlDef_SCRPlayerFallDanger) + 4)));
    CharaCtrlResetScriptCtrlStatus(arg0, (*(int *)((char *)(ScriptCtrlDef_SCRPlayerHellDanger) + 4)));
}

void player_CliffDetect(void *arg0, int arg1)
{
    void *temp_s0;

    temp_s0 = GetCharacterClass(arg0);
    CharaCtrlResetScriptCtrlStatus(arg0, (*(int *)((char *)(ScriptCtrlDef_SCRPlayerFallDanger) + 4)));
    if (func_40090138(arg1 + 0x10, temp_s0 + 0xD90, (*(int *)((char *)(temp_s0) + 0x138)), (*(int *)((char *)(temp_s0) + 0x134))) != 0)
    {
        CharaCtrlSetScriptCtrlStatus(arg0, (*(int *)((char *)(ScriptCtrlDef_SCRPlayerFallDanger) + 4)));
    }
}

void player_setDangerEdgePoint(void *a, char *b)
{
    char *g = b + 0x10;
    char *c = GetCharacterClass(a);
    charrootdyn_setVColFindFlag(c, g, 0.0f);
    charrootdyn_resetVColEdgeFindFlag(c);
    AddTwoWayLinkNext(GetLayoutClass(GetGeometryPointerObject(g)) + 0x118, c + 0xEC0);
    *(int *)(c + 0xE30) = 1;
    CopyGeometryPointer(c + 0xE50, g);
    CopyGeometryPointer(c + 0xDD0, g);
}

extern int ExchangeGeometryPointerCollisionEdgeOtherSideInfo(void *, void *);
extern void iosJumpRecoverPoint(void *);
extern char D_40134750[];

void player_setDangerEdgeOtherSidePlanePoint(void *a, char *b)
{
    char *g = b + 0x10;
    char *c;
    if (ExchangeGeometryPointerCollisionEdgeOtherSideInfo(g, g) == 0) {
        iosJumpRecoverPoint(D_40134750);
    }
    c = GetCharacterClass(a);
    charrootdyn_setVColFindFlag(c, g, 0.0f);
    charrootdyn_resetVColEdgeFindFlag(c);
    AddTwoWayLinkNext(GetLayoutClass(GetGeometryPointerObject(g)) + 0x118, c + 0xEC0);
    *(int *)(c + 0xE30) = 1;
    CopyGeometryPointer(c + 0xE50, g);
    CopyGeometryPointer(c + 0xDD0, g);
}

extern int ParentLayoutObj();

int player_setHellDangerPoint(int a, int b, int c, int d)
{
    return ParentLayoutObj(a, b + 112, c, d);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0106_player_HellDangerDetect", player_AvoidDangerCliff);
