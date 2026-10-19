#include "common.h"

/* MANAGER c0115 scriptIntrEntryChildThread(sig, obj, link, v): bit 33 of the u64 flags at +0 = child-thread group (at +0x10) initialised. Stores v/obj into the link record (+8, +0x10) and adds obj to the group (tail call). */
void isysInitGroup(void *);
void isysAddGroupWithLinkParam(s32, void *, s32, s32);

/* MANAGER c0115 scriptIntrEntryJump(sig, obj, link): sig is the script interrupt signal record (u64 flags at +0, bit 32 = jump group initialised, group at +8). Lazily inits the group then adds obj with the link param (tail call). The flag test must be a s32 temp of the high word (lwu+dsll32+dsra32) and the group pointer a local. */
void isysInitGroup(void *);

/* MANAGER c0115 scriptIntrSegDelete(seg): seg+0xC = count, seg+0x10 = array of 0x18-byte signal records (u64 flags at +0, jump group at +8, child-thread group at +0x10). Deletes all objs of each initialised group (bit 32 / bit 33). */
void isysDeleteGroupAllObj(void *);

void scriptIntrEntryJump(u64 *s, s32 a, s32 c)
{
    char *g = (char *)s + 8;
    s32 hi = (*s >> 32);
    if ((hi & 1) == 0) {
        isysInitGroup(g);
        *s |= 0x100000000LL;
    }
    isysAddGroupWithLinkParam(a, g, 0, c);
}

void isysDeleteGroupWithLinkParam(s32 obj, void *group, s32 a2, s32 flag);

void scriptIntrDeleteJump(char *s, s32 a, s32 c)
{
    if (*(s32 *)(s + 4) & 1)
        isysDeleteGroupWithLinkParam(a, s + 8, c, 0);
}

s32 func_40097B10(s32 p);
s32 isysDeleteAllGroup(s32 obj, s32 (*func)(s32), s32 a2, s32 flag);

s32 scriptIntrAllDeleteJump(s32 a, s32 b, s32 c, s32 d)
{
    return isysDeleteAllGroup(a, func_40097B10, c, d);
}

void scriptIntrEntryChildThread(u64 *s, s32 a, s32 c, s32 d)
{
    char *g = (char *)s + 0x10;
    if (((*s >> 33) & 1) == 0) {
        isysInitGroup(g);
        *s |= 0x200000000LL;
    }
    ((s32 *)c)[2] = d;
    ((s32 *)c)[4] = a;
    isysAddGroupWithLinkParam(a, g, 0, c);
}

void scriptIntrDeleteChildThread(u64 *s, s32 a, s32 c)
{
    if ((int)(*s >> 33) & 1)
        isysDeleteGroupWithLinkParam(a, (char *)s + 0x10, c, 0);
}

s32 func_40097B38(s32 p);

s32 scriptIntrAllDeleteSubThread(s32 a, s32 b, s32 c, s32 d)
{
    return isysDeleteAllGroup(a, func_40097B38, c, d);
}

void scriptIntrSegInit(void) {
}

void scriptIntrSegDelete(char *seg)
{
    s32 i = 0;
    u64 *p = *(u64 **)(seg + 0x10);
    if (*(s32 *)(seg + 0xC) > 0) {
        u64 *r = p;
        do {
            u64 f = *r;
            u64 *g1 = r + 1;
            u64 *g2 = r + 2;
            if ((int)(f >> 32) & 1) {
                isysDeleteGroupAllObj(g1);
                f = *r;
            }
            if ((int)(f >> 33) & 1) {
                isysDeleteGroupAllObj(g2);
            }
            i++;
            r += 3;
        } while (i < *(s32 *)(seg + 0xC));
    }
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0115_scriptIntrEntryJump", func_40097B10);
s32 func_40097B10(s32 p)
{
    if (p != 0 && *(s32 *)p == -0x5A5A5A5B) {
        return 1;
    }
    return 0;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0115_scriptIntrEntryJump", func_40097B38);
s32 func_40097B38(s32 p)
{
    if (p != 0 && *(s32 *)p == -0x5A5A5A5C) {
        return 1;
    }
    return 0;
}

/* NEARMISS-STUB func_40097B60 */
#if 0 /* NEARMISS 86.67% cat=regalloc sub=- | REA READY drop-in scored 86.67 in-TU (apply_ready) | attempts=1 */
void func_40097B60(u8 *o)
{
    char *c;
    s32 *res;
    s32 *slot;
    s32 n;
    s32 *row;
    char *c2;
    s32 *res2;
    s32 cnt;
    s32 i;

    c = (char *)o + 0x20;
    if (o[8] != 0xD) c = 0;
    res = *(s32 **)(c + 0x328);
    slot = *(s32 **)(c + 0x338);
    n = res[0] - 1;
    row = (s32 *)res[6];
    if (n != -1) {
        do {
            if (IsNonISysObjTypeRes(row[0]) == 0 && (signed char)row[2] != 0) {
                if (row[0] < 0x2b) {
                    if (row[0] >= 0x27) {
                        delete_object_animation_camera_region((void *)slot[0]);
                    }
                }
                if (slot[1] != 0) {
                    isysRequestDeleteObj(slot[1]);
                    slot[1] = 0;
                }
            }
            n--;
            row += 3;
            slot += 2;
        } while (n != -1);
    }
    c2 = sc(o);
    res2 = *(s32 **)(c2 + 0x328);
    cnt = res2[0];
    i = 0;
    if (cnt > 0) {
        do {
            s32 off = i * 8;
            s32 t;
            i++;
            t = *(s32 *)(off + *(s32 *)(c2 + 0x338));
            if (t != 0) {
                isysRequestDeleteObj(t);
                FlushLayoutObj(*(s32 *)(off + *(s32 *)(c2 + 0x338)));
                cnt = res2[0];
            }
        } while (i < cnt);
    }
    if (*(s32 *)(c2 + 0x368) != 0) {
        iosFree();
        *(s32 *)(c2 + 0x368) = 0;
        *(s32 *)(c2 + 0x35C) = 0;
    }
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0115_scriptIntrEntryJump", func_40097B60);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0115_scriptIntrEntryJump", func_40097CC0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0115_scriptIntrEntryJump", SetScriptAnimationObjAccessSwitch);

/* NEARMISS-STUB func_40097FC0 */
#if 0 /* NEARMISS 93.58% cat=regalloc sub=- | REA READY drop-in scored 93.58 in-TU (apply_ready) | attempts=1 */
void func_40097FC0(u8 *o)
{
    char *c = sc(o);
    char *c2;
    u8 *r;
    s32 *w;
    s32 *cur;
    s32 i;
    s32 off;

    *(s32 *)(c + 0x344) = 1;
    *(s32 *)(c + 0x348) = -1;
    r = SetLayoutObjAccessSwitchThisObjOnly(o, 0);
    if (r != 0) {
        i = 0;
        c2 = sc(o);
        w = *(s32 **)(c2 + 0x328);
        if (*w > 0) {
            cur = w;
            off = 0;
            do {
                s32 *e = (s32 *)(*(s32 *)(c2 + 0x338) + i * 8);
                i++;
                if (e[0] != 0) {
                    SetLayoutObjAccessSwitchThisObjOnly((u8 *)e[0], 0);
                    cur = *(s32 **)(c2 + 0x328);
                } else if (*(s32 *)(w[6] + off) == 0x11) {
                    if (e[1] != 0) {
                        SetFogColAvailableFlag((void *)e[1], 0);
                        cur = *(s32 **)(c2 + 0x328);
                    }
                }
                off += 0xC;
            } while (i < *cur);
        }
    }
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0115_scriptIntrEntryJump", func_40097FC0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0115_scriptIntrEntryJump", StartAnimationSubObjInfinitePart);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0115_scriptIntrEntryJump", func_400983E0);
