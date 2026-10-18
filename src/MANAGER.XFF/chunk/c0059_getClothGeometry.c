#include "common.h"

static inline u8 *chrClass(u8 *obj)
{
    switch (obj[8])
    {
        case 9:
            return obj + 0x90;
        case 0x16:
            return obj + 0x90;
        default:
            return NULL;
    }
}

/* NEARMISS-STUB getClothGeometry */
#if 0 /* NEARMISS 87.81% cat=regalloc sub=- | reg alloc shifted s1-s6, loop prologue N-1 kept in reg, sq zero via addiu vs por | attempts=1 */
u8 *GetLayoutClass();
u8 *GetGeometryPointerObject();
void GetLayoutClassWindGeometry();
void ResetClothDynamics();
void GetClothDynamics(u8 *obj, f32 x, f32 y, s32 flag, u8 *p);

void getClothGeometry(u8 *obj, u8 *obj2, f32 x, f32 y)
{
    u8 *cc;
    u8 *fl;
    u8 *lc;
    u8 *p;
    u8 *q;
    u8 *cs;
    u128 *dst;
    s32 (*cb)();
    s32 i;
    s32 flag;

    lc = GetLayoutClass(obj);
    if (*(u32 *)(lc + 0x180) == 0)
    {
        return;
    }
    cc = chrClass(obj2);
    if (*(s8 *)(cc + 0x52C) != 0)
    {
        return;
    }
    fl = cc + 0x51A;
    if (obj == obj2 && *(u32 *)(lc + 0x124) != 0)
    {
        p = GetGeometryPointerObject(lc + 0xC0);
        if (p != NULL)
        {
            q = chrClass(p);
            if (q != NULL)
            {
                flag = q[0x51A] & 0x7F;
                if (flag != 0)
                {
                    *fl = flag;
                }
            }
        }
    }
    if (*(s8 *)fl != 0)
    {
        dst = (u128 *)(lc + 0x30);
        *dst = 0;
        GetLayoutClassWindGeometry(lc, &ZeroVector);
        GetClothDynamics(obj, x, y, 1, 0);
        ResetClothDynamics(obj);
        for (i = (*fl & 0x7F) - 1; i != -1; i--)
        {
            GetClothDynamics(obj, x, y, 1, 0);
        }
        *fl |= 0x80;
    }
    cs = *(u8 **)(lc + 0x178);
    p = (u8 *)(*(u32 **)(cc + 0xDA4) + *(s16 *)(cc + 0x360));
    flag = 2;
    if (*(u32 *)(cs + 0xC) == 0)
    {
        cb = *(s32 (**)())(cs + 8);
        if (cb != NULL)
        {
            flag = cb(obj2, p) != 0;
        }
        else
        {
            flag = *(s8 *)(cc + 0x35E) == 0;
        }
    }
    GetClothDynamics(obj, x, y, flag, p);
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0059_getClothGeometry", getClothGeometry);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0059_getClothGeometry", GetCharacterClass);

u8 *GetCharacterClass(u8 *obj)
{
    switch (obj[8])
    {
        case 9:
            return obj + 0x90;
        case 0x16:
            return obj + 0x90;
        default:
            return NULL;
    }
}

void charrootdyn_resetHColFindFlag();
void charrootdyn_resetVColFindFlag();
void charrootdyn_resetVColEdgeFindFlag();
void charrootdyn_resetChainFindStatus();
void charrootdyn_resetkeepcolhitstatus();
void ReleaseCollisionFinder();
void ReleaseCollisionEdgeLinkDB();
void FlushLayoutObj();
void FlushJudgeVolumeObj();

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0059_getClothGeometry", FlushCharacterObj);
void FlushCharacterObj(u8 *obj)
{
    u8 *cc = chrClass(obj);

    charrootdyn_resetHColFindFlag(cc);
    charrootdyn_resetVColFindFlag(cc);
    charrootdyn_resetVColEdgeFindFlag(cc);
    charrootdyn_resetChainFindStatus(cc);
    charrootdyn_resetkeepcolhitstatus(cc);
    ReleaseCollisionFinder(cc + 0xD90);
    ReleaseCollisionEdgeLinkDB(cc + 0xDAC);
    FlushLayoutObj(obj);
    FlushJudgeVolumeObj(obj);
}

/* NEARMISS-STUB ExecCharaGeometryPreprocess */
#if 0 /* NEARMISS 78.45% cat=branch-layout sub=- | gcc dup return-0 blocks and bnezl; original shares one return-0 and returns callee result on failed path | attempts=1 */
extern s32 func_40053270(f32 a, f32 b);

s32 ExecCharaGeometryPreprocess(u8 *obj, f32 x, f32 y, f32 z)
{
    u8 *cc = chrClass(obj);

    if (y == 0.0f)
    {
        return 0;
    }
    if (*(s32 *)(cc + 0x1E4) != 0)
    {
        return 0;
    }
    if (func_40053270(y, z) == 0)
    {
        return 0;
    }
    *(f32 *)(cc + 0xC60) = z;
    *(u8 *)(cc + 0xC68) = 1;
    *(f32 *)(cc + 0xC64) = x;
    *(f32 *)(cc + 0xC5C) = y;
    return 1;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0059_getClothGeometry", ExecCharaGeometryPreprocess);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0059_getClothGeometry", ExecCharaGeometryPostprocess);
void SetCharacterObjDemoCutFinishFlag();

void ExecCharaGeometryPostprocess(u8 *obj)
{
    u8 *cc = chrClass(obj);
    u8 *p;

    if (*(u8 **)(cc + 0x19C) != NULL)
    {
        (*(u8 **)(cc + 0x19C))[0x8C] = 0;
    }
    if (*(s8 *)(cc + 0x1000) != 0)
    {
        SetCharacterObjDemoCutFinishFlag(obj, 0);
        p = *(u8 **)(cc + 0x19C);
        if (p != NULL)
        {
            p[0x8C] = 1;
        }
    }
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0059_getClothGeometry", GetCharacterClassInitParamNbNodes);
s32 GetCharacterClassInitParamNbNodes(u8 *obj)
{
    u8 *p = *(u8 **)(obj + 0x84);
    s32 n;

    if (p != NULL)
    {
        n = *(s32 *)(*(u8 **)(p + 0x20) + 4);
    }
    else
    {
        n = *(s32 *)(obj + 4);
    }
    return n;
}

s32 GetCharacterClassInitParamNbOptionNodes(u8 *obj)
{
    s32 n = -1;
    u8 *p = *(u8 **)(obj + 0x84);

    if (p != NULL)
    {
        n = *(s32 *)(*(u8 **)(p + 0x20) + 0x20);
    }
    return n;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0059_getClothGeometry", GetCharacterClassBaseQ);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0059_getClothGeometry", GetCharacterClassMotionTopDirection);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0059_getClothGeometry", GetCharacterClassControlFrontDirection);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0059_getClothGeometry", GetCharacterClassMotionFrontDirection);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0059_getClothGeometry", GetCharacterClassControlDirection);

/* NEARMISS-STUB GetCharacterClassIKNodeBooleanInfo */
#if 0 /* NEARMISS 88.98% cat=branch-layout sub=- | a2 kept in s3 across calls; -1 early-return shape | attempts=1 */
s32 GetMotionVersion();
s32 GetMotionOptionNodePhysicalId();
void GetMotionOptionNodeBooleanInfoFloatFrame(f32 a, f32 b, u8 *obj, u8 *node, s32 id);

s32 GetCharacterClassIKNodeBooleanInfo(u8 *obj, u8 *cc, s32 a2)
{
    u8 *ik;
    s32 base;
    s32 *ver;
    u8 *node;
    s32 id;

    ik = cc + 0x1C0;
    base = *(s32 *)ik;
    ver = *(s32 **)(cc + 0x354);
    obj[2] = 0;
    obj[1] = 0;
    obj[0] = 0;
    node = NULL;
    if (base != 0)
    {
        node = (u8 *)base + 0x50;
    }
    if (node == NULL)
    {
        return -1;
    }
    if (*ver < 1)
    {
        return -1;
    }
    if (GetMotionVersion(node) < 5)
    {
        return -1;
    }
    id = GetMotionOptionNodePhysicalId(node, a2);
    if (id < 0)
    {
        return -1;
    }
    GetMotionOptionNodeBooleanInfoFloatFrame(*(f32 *)(ik + 8), *(f32 *)(ik + 0xC), obj, node, id);
    return 0;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0059_getClothGeometry", GetCharacterClassIKNodeBooleanInfo);

typedef union
{
    u128 q;
    f32 f[4];
    s32 i[4];
} Vec4;

typedef struct
{
    char pad[0x30];
    s32 value30;
    char pad34[0xC];
} OptionNode;

typedef struct
{
    char pad[0x24];
    OptionNode *nodes;
} OptionContext;

typedef struct
{
    char pad[0x2E8];
    Vec4 *quaternions;
    Vec4 *positions;
    char pad2F0[0x64];
    OptionContext *options;
} CharacterClass;

s32 GetCharacterClassOptionNodeLocalQuaternionPos(Vec4 *quaternion, Vec4 *position, CharacterClass *character, s32 index)
{
    OptionNode *node = &character->options->nodes[index];
    u128 p = character->positions[index].q;
    s32 value = node->value30;
    position->q = p;
    quaternion->q = character->quaternions[index].q;
    return value;
}

void isysDeleteGroupAllObj();

void ResetCharacterClassCtrlRelationInfos(u8 *a)
{
    isysDeleteGroupAllObj(a + 0x103C);
}

/* NEARMISS-STUB ResetCharacterClassFallDownInfo */
#if 0 /* NEARMISS 75.0% cat=sched sub=- | target loads 0x134 pointer before sw 0x50C | attempts=1 */

void ResetCharacterClassFallDownInfo(u8 *a)
{
    a[0x359] = 0;
    a[0x358] = 0;
    a[0x1007] = 0;
    *(u128 *)(a + 0x1010) = *(u128 *)*(u8 **)(a + 0x134);
    *(u32 *)(a + 0x50C) = 0;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0059_getClothGeometry", ResetCharacterClassFallDownInfo);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0059_getClothGeometry", ResetCharacterClassIKInfo);
void ResetCharacterClassIKInfo(u8 *a)
{
    s32 n;
    u8 *p;

    if (*(u8 **)(a + 0x354) != NULL)
    {
        n = *(s32 *)(*(u8 **)(a + 0x354) + 0x20);
        p = *(u8 **)(a + 0x318);
        while (--n != -1)
        {
            p[0xC4] = 0;
            *(u32 *)(p + 0xB0) = 0;
            *(f32 *)(p + 0xB8) = 1.0f;
            *(u32 *)(p + 0xB4) = 0;
            p[0xC5] = 0;
            *(f32 *)(p + 0xBC) = 100.0f;
            *(u32 *)(p + 0xC0) = 0;
            p += 0xD0;
        }
    }
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0059_getClothGeometry", ResetCharacterClassWaterStatus);

void ResetCharacterClassWaterStatus(u8 *a)
{
    a[0x35D] = 0;
    a[0x35E] = 0;
    *(u32 *)(a + 0x1024) = 0;
    *(u32 *)(a + 0x1020) = 0;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0059_getClothGeometry", ReleaseCharacterClassMotSyncAnimForceDeleteGroupWithMotChange);
u8 *isysGroupForFirst();
u8 *isysGroupForNext();
void isysRequestDeleteObj();
void isysGroupForExit();
void isysDeleteGroupAllObj();

void ReleaseCharacterClassMotSyncAnimForceDeleteGroupWithMotChange(u8 *obj)
{
    u8 *cc = chrClass(obj);
    u8 *grp = cc + 0xD06;
    u8 *node;
    u8 *last = NULL;

    node = isysGroupForFirst(grp, 0);
    if (node != NULL)
    {
        last = *(u8 **)node;
        for (;;)
        {
            isysRequestDeleteObj(last);
            node = isysGroupForNext(node, 0);
            if (node == NULL)
            {
                break;
            }
            last = *(u8 **)node;
        }
    }
    if (last != NULL)
    {
        isysGroupForExit(last, 0);
    }
    isysDeleteGroupAllObj(grp);
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0059_getClothGeometry", ReleaseCharacterClassAddMotSyncAnim);
void ReleaseCharacterClassAddMotSyncAnim(u8 *grp)
{
    u8 *node;
    u8 *last = NULL;

    node = isysGroupForFirst(grp, 0);
    if (node != NULL)
    {
        do
        {
            last = *(u8 **)node;
            isysRequestDeleteObj(last);
            node = isysGroupForNext(node, 0);
        } while (node != NULL);
    }
    if (last != NULL)
    {
        isysGroupForExit(last, 0);
    }
    isysDeleteGroupAllObj(grp);
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0059_getClothGeometry", DebugResetCharacterObjControlTarget);
void ChangeCharacterObjControlTarget();
void CopyGeometryPointer();

void DebugResetCharacterObjControlTarget(u8 *obj1, u8 *obj2)
{
    u8 *cc1 = chrClass(obj1);
    u8 *cc2 = chrClass(obj2);
    u8 *ctl = *(u8 **)(cc1 + 0x940);

    *(u8 **)(chrClass(ctl) + 0x950) = ctl;
    ChangeCharacterObjControlTarget(obj1, obj2);
    *(u8 **)(cc2 + 0x950) = obj1;
    if (obj1 == obj2)
    {
        return;
    }
    cc2[0x9B5] = 1;
    CopyGeometryPointer(cc2 + 0x960, cc1 + 0xC0);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0059_getClothGeometry", UpdateCharacterClassGeometry);

void UpdateLayoutClassPastGeometry();

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0059_getClothGeometry", UpdateCharacterClassPastGeometry);
void UpdateCharacterClassPastGeometry(u8 *a)
{
    *(u128 *)(a + 0x4F0) = *(u128 *)*(u8 **)(a + 0x138);
    UpdateLayoutClassPastGeometry();
    *(u128 *)(a + 0x4C0) = *(u128 *)(a + 0x4B0);
}
