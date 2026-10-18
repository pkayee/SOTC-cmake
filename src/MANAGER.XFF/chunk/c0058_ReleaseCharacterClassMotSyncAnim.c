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

/* NEARMISS-STUB ReleaseCharacterClassMotSyncAnim */
#if 0 /* NEARMISS 96.0% cat=sched sub=- | first class select movz form vs chrClass movn; s2/s3 group register order | attempts=1 */
u8 *isysGroupForFirst();
u8 *isysGroupForNext();
void isysRequestDeleteObj();
void isysGroupForExit();
void isysDeleteGroupAllObj();

void ReleaseCharacterClassMotSyncAnim(u8 *obj)
{
    u8 *cc = chrClass(obj);
    u8 *grp = cc + 0xD02;
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

    cc = chrClass(obj);
    grp = cc + 0xD06;
    node = isysGroupForFirst(grp, 0);
    last = NULL;
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
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0058_ReleaseCharacterClassMotSyncAnim", ReleaseCharacterClassMotSyncAnim);

/* NEARMISS-STUB FlushCharacterObjImmediate */
#if 0 /* NEARMISS 96.41% cat=regalloc sub=- | cc in s2 vs s1; early obj+0x90 hoist and extra lbu reload in target | attempts=1 */
void DeleteAllTwoWayLink();
void FlushCollisionFinder();
void ChangeCharacterObjControlTarget();
void ReleaseCharacterClassMotSyncAnim();
u8 *isysGroupForFirst();
u8 *isysGroupForNext();
void isysRequestDeleteObj();
void isysGroupForExit();
void isysDeleteGroupAllObj();
void FlushLayoutObjImmediate();
void FlushJudgeVolumeObjImmediate();
void func_40059AE8();

void FlushCharacterObjImmediate(u8 *obj)
{
    u8 *cc = chrClass(obj);
    u8 *other;
    u8 *cur;
    u8 *grp;
    u8 *node;
    u8 *last;
    u32 *pos;
    s32 i;

    if (*(u8 **)(cc + 0x940) != obj)
    {
        u8 *lc = chrClass(obj);
        u8 *sc = chrClass(obj);

        other = *(u8 **)(lc + 0x940);
        *(u8 **)(chrClass(other) + 0x950) = other;
        ChangeCharacterObjControlTarget(obj, obj);
        *(u8 **)(sc + 0x950) = obj;
    }
    cur = *(u8 **)(cc + 0x950);
    if (cur != obj)
    {
        u8 *lc = chrClass(cur);
        u8 *sc = chrClass(cur);

        other = *(u8 **)(lc + 0x940);
        *(u8 **)(chrClass(other) + 0x950) = other;
        ChangeCharacterObjControlTarget(cur, cur);
        *(u8 **)(sc + 0x950) = cur;
    }
    ResetCharacterClassPositionMemoryInfo(cc);
    pos = (u32 *)(cc + 0x2C4);
    if (pos[1] != 0)
    {
        iosFree(pos[1]);
        pos[0] = 0;
        pos[1] = 0;
    }
    if (*(u8 **)(cc + 0xC70) != NULL)
    {
        DeleteTwoWayLink(cc + 0xC80);
        cc[0xD00] = 0;
        *(u8 **)(cc + 0xC70) = NULL;
        cc[0xD01] = 0;
    }
    DeleteAllTwoWayLink(cc + 0xC74, func_40059AE8);
    FlushCollisionFinder(cc + 0xD90);
    ReleaseCharacterClassMotSyncAnim(obj);

    cc = chrClass(obj);
    for (i = 0; i < *(s32 *)(cc + 0x3EC); i++)
    {
        grp = *(u8 **)(cc + 0x308) + i * 0x80;
        node = isysGroupForFirst(grp, 0);
        last = NULL;
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
    isysDeleteGroupAllObj(chrClass(obj) + 0x103C);
    FlushLayoutObjImmediate(obj);
    FlushJudgeVolumeObjImmediate(obj);
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0058_ReleaseCharacterClassMotSyncAnim", FlushCharacterObjImmediate);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0058_ReleaseCharacterClassMotSyncAnim", ExecCharaGeometry);
