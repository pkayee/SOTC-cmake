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

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0056_CharacterClassMalloc", CharacterClassMalloc);

/* NEARMISS-STUB GetCharacterObjWorkSize */
#if 0 /* NEARMISS 87.45% cat=regalloc sub=- | obj/idx swapped s1/s2; p84 beql shape | attempts=1 */
s32 GetLayoutObjWorkSize();
s32 GetCollisionFinderWorkSize();
s32 GetJudgeVolumeClassWorkSize();
s32 GetCollisionEdgeLinkDBWorkSize();

s32 GetCharacterObjWorkSize(u8 *obj)
{
    s32 size;
    u8 *p84;
    u8 *sub;
    s32 idx;
    s32 cnt;
    s32 arg;
    s32 layout;
    s32 n;
    s32 i;

    p84 = *(u8 **)(obj + 0x84);
    if (p84 == NULL)
    {
        idx = *(s32 *)(obj + 4);
    }
    else
    {
        idx = *(s32 *)(*(u8 **)(p84 + 0x20) + 4);
    }
    cnt = -1;
    if (p84 != NULL)
    {
        cnt = *(s32 *)(*(u8 **)(p84 + 0x20) + 0x20);
    }
    *(s32 *)(obj + 4) = idx;
    layout = GetLayoutObjWorkSize(obj);

    sub = *(u8 **)(obj + 0x118);
    arg = *(s32 *)(obj + 0x94);
    if (*(u32 *)(sub + 0x50) & 1)
    {
        arg = arg ? arg << 2 : 0;
    }

    size = idx * 0x108 + 0x33;
    n = *(s32 *)(obj + 0x98);
    if (n != 0)
    {
        size = size + n * 8 + (idx * 0x10 + 0x80) * n + 0x66;
    }
    if (cnt != 0)
    {
        size = size + cnt * 0x13B + 0x33;
    }
    size += 0x333;
    size += GetCollisionFinderWorkSize(arg);
    size += layout;
    size = size + idx * 2 + 0x33;

    sub = *(u8 **)(obj + 0x118);
    size = size + (s32)dldRef((u32 *)(sub + 0x134), 0xC) * 0x10 + 0x33;
    size = size + (s32)dldRef((u32 *)(sub + 0x130), 0xC) * 0x10 + 0x33;

    for (i = 0; i < 4; i++)
    {
        u8 *ent = dldElem((u32 *)(*(u8 **)(obj + 0x118) + 0x13C + i * 4));
        if (ent != NULL)
        {
            s32 (*fn)() = *(s32 (**)())ent;
            if (fn != NULL)
            {
                size += fn(obj);
            }
        }
    }

    sub = *(u8 **)(obj + 0x118);
    size += GetJudgeVolumeClassWorkSize(sub + 0x158);

    sub = *(u8 **)(obj + 0x118);
    size += *(s32 *)(sub + 0x154) ? *(s32 *)(sub + 0x154) * 0x10 + 0x33 : 0;
    size += *(s32 *)(sub + 0x154) ? *(s32 *)(sub + 0x154) * 0x10 + 0x33 : 0;
    if (*(u32 *)(sub + 0x50) & 2)
    {
        size += GetCollisionEdgeLinkDBWorkSize(*(s32 *)(obj + 0x94));
    }
    return size;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0056_CharacterClassMalloc", GetCharacterObjWorkSize);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0056_CharacterClassMalloc", GetCharacterClassOptionNodeGeo);

/* NEARMISS-STUB SetCharacterObjDemoMotionMode */
#if 0 /* NEARMISS 97.69% cat=sched sub=- | one addiu (lp2) scheduled before lui/ori 0x3FFFF mask | attempts=1 */
u32 *SetDemoMotionOrientInfo(u8 *info);
void ReleaseCharacterClassMotSyncAnim(u8 *obj);
void entrySyncAnim(f32 f, u8 *a, u8 *obj, u8 *elem, s32 n);
void ResetCharacterClassMotionShiftInfo(f32 f, u8 *obj, void *param);
void InitGazeAddChannelDef(u8 *gaze, u8 *elem);
void FinishCharacterObjAllAdditionMotion(u8 *obj);
void character_motchange_adjustrootrot(f32 f, u8 *obj, u8 *p, s32 a2, void *q);
void ForceAcceptMotionControlChange(u8 *a, s32 v);

s32 SetCharacterObjDemoMotionMode(u8 *obj, f32 f)
{
    u8 *s2;
    u8 *p;
    u8 *q;
    u32 *lp;
    u32 *lp2;
    u32 w1;
    u32 w2;
    u8 *elem;
    s32 n;
    u8 *e2;
    u8 *gaze;
    s32 cnt;

    s2 = chrClass(obj);
    if (s2 != NULL)
    {
        lp = SetDemoMotionOrientInfo(s2 + 0xFE0);
        ReleaseCharacterClassMotSyncAnim(obj);

        if (lp != NULL)
        {
            w1 = *lp;
            elem = dldElem(lp, w1);
            if (elem != NULL)
            {
                entrySyncAnim(0.0f, s2 + 0xD02, obj, elem, -1);
            }
            ResetCharacterClassMotionShiftInfo(f, s2, elem);

            lp2 = (u32 *)(*(u8 **)(s2 + 0x1098) + 0x134);
            w2 = *lp2;
            gaze = *(u8 **)(s2 + 0x330);
            cnt = dldCount(lp2, w2);
            if (cnt != 0)
            {
                e2 = dldElem(lp2, w2);
                n = cnt - 1;
                do
                {
                    InitGazeAddChannelDef(gaze, e2);
                    gaze += 0x10;
                    e2 += 0x14;
                    n--;
                } while (n != -1);
            }

            FinishCharacterObjAllAdditionMotion(obj);
            *(s32 *)(s2 + 0xFD0) = 1;
            s2[0x35C] = 0;
        }
        else
        {
            q = s2 + 0x1C0;
            if (*(s32 *)q != 0)
            {
                character_motchange_adjustrootrot(*(f32 *)(q + 8), s2, *(u8 **)(s2 + 0x2A8) + 0x50,
                                                  *(s32 *)q, &IdentityQuaternion);
            }

            p = chrClass(obj);
            if (p != NULL)
            {
                *(s32 *)(p + 0xFD0) = 0;
                *(u128 *)(p + 0x6C0) = ZeroPoint;
                if (*(u8 **)(p + 0x354) != NULL)
                {
                    *(f32 *)(p + 0x6C4) = *(f32 *)(*(u8 **)(p + 0x354) + 0x14);
                }
            }

            ResetCharacterClassMotionShiftInfo(f, s2, *(void **)(s2 + 0x2A8));
            ForceAcceptMotionControlChange(s2, *(s32 *)(s2 + 0x2AC));
        }
    }

    return 0;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0056_CharacterClassMalloc", SetCharacterObjDemoMotionMode);
