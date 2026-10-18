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

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0058_ReleaseCharacterClassMotSyncAnim", ReleaseCharacterClassMotSyncAnim);
u8 *isysGroupForFirst();
u8 *isysGroupForNext();
void isysRequestDeleteObj();
void isysGroupForExit();
void isysDeleteGroupAllObj();

void ReleaseCharacterClassMotSyncAnim(u8 *obj)
{
    u8 *grp;
    u8 *grp2;
    u8 *node;
    u8 *last;

    grp = chrClass(obj) + 0xD02;
    last = NULL;
    for (node = isysGroupForFirst(grp, 0); node != NULL; node = isysGroupForNext(node, 0))
    {
        last = *(u8 **)node;
        isysRequestDeleteObj(last);
    }
    if (last != NULL)
    {
        isysGroupForExit(last, 0);
    }
    isysDeleteGroupAllObj(grp);

    grp2 = chrClass(obj) + 0xD06;
    last = NULL;
    for (node = isysGroupForFirst(grp2, 0); node != NULL; node = isysGroupForNext(node, 0))
    {
        last = *(u8 **)node;
        isysRequestDeleteObj(last);
    }
    if (last != NULL)
    {
        isysGroupForExit(last, 0);
    }
    isysDeleteGroupAllObj(grp2);
}

/* NEARMISS-STUB FlushCharacterObjImmediate */
#if 0 /* NEARMISS 98.0% cat=regalloc sub=- | separate c2=chrClass(obj) for the loop fixes cc=s1 and the s5 hoist (96.4->98.0); left: obj s2 vs s3 and target reloads cur->type (lbu) for the 2nd chrClass(cur | attempts=2 */
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
    u8 *c2;

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

    c2 = chrClass(obj);
    for (i = 0; i < *(s32 *)(c2 + 0x3EC); i++)
    {
        grp = *(u8 **)(c2 + 0x308) + i * 0x80;
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
