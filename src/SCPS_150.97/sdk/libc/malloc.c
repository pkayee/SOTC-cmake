#include "common.h"

extern struct _reent *D_00135D60[];
void __malloc_lock();
void __malloc_unlock();
void *_malloc_r(struct _reent *ptr, u32 nbytes);
void _free_r(struct _reent *ptr, void *p);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/malloc", malloc);
void *malloc(u32 nbytes)
{
    void *ret;

    __malloc_lock(D_00135D60[0]);
    ret = _malloc_r(D_00135D60[0], nbytes);
    __malloc_unlock(D_00135D60[0]);
    return ret;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/malloc", free);
void free(void *p)
{
    __malloc_lock(D_00135D60[0]);
    _free_r(D_00135D60[0], p);
    __malloc_unlock(D_00135D60[0]);
}

/* NEARMISS-STUB func_00127908 */
#if 0 /* NEARMISS 82.0% cat=regalloc sub=- | temp register assignment (s3/s6/a2/a3) and %hi/%lo folding of D_00136180/D_00136178 differ; best re-score 75.1% with decl preamble (db 82) | attempts=1 */
void func_00127908(struct _reent *ptr, u32 nbytes)
{
    s32 *av;
    s32 *top;
    s32 oldSize;
    s32 *oldEnd;
    s32 size;
    s32 *brk;
    s32 *brk2;
    s32 front;
    s32 corr;
    s32 newSize;

    av = D_00135D68;
    top = (s32 *)av[2];
    oldSize = top[1] & ~3;
    oldEnd = (s32 *)((u8 *)top + oldSize);
    size = (s32)(nbytes + D_00136178[0] + 16);
    if (D_00136180[0] != -1)
    {
        size = (s32)(((u32)size + 0xFFF) & ~0xFFF);
    }
    brk = (s32 *)_sbrk_r(ptr, size);
    if (brk == (s32 *)-1)
    {
        return;
    }
    if ((u32)brk < (u32)oldEnd)
    {
        if (top != av)
        {
            return;
        }
    }
    D_00136198[0] += size;
    if (brk == oldEnd)
    {
        ((s32 *)av[2])[1] = (size + oldSize) | 1;
    }
    else
    {
        if (D_00136180[0] == -1)
        {
            D_00136180[0] = (s32)brk;
        }
        else
        {
            D_00136198[0] += (s32)((u8 *)brk - (u8 *)oldEnd);
        }
        front = ((s32)brk + 8) & 0xF;
        if (front != 0)
        {
            front = 16 - front;
            brk = (s32 *)((u8 *)brk + front);
        }
        else
        {
            front = 0;
        }
        corr = 0x1000 - (((s32)brk + size) & 0xFFF);
        front += corr;
        brk2 = (s32 *)_sbrk_r(ptr, front);
        if (brk2 == (s32 *)-1)
        {
            return;
        }
        newSize = ((s32)brk2 - (s32)brk + front) | 1;
        D_00136198[0] += front;
        av[2] = (s32)brk;
        brk[1] = newSize;
        if (top == av)
        {
            goto L00127AFC;
        }
        if (oldSize < 16)
        {
            brk[1] = 1;
            return;
        }
        newSize = (oldSize - 12) & -16;
        top[1] = (top[1] & 1) | newSize;
        ((s32 *)((u8 *)top + newSize))[2] = 5;
        ((s32 *)((u8 *)top + newSize))[1] = 5;
        if (newSize >= 16)
        {
            _free_r(ptr, (u8 *)top + 8);
        }
    }
L00127AFC:
    if (D_00136188[0] < (u64)D_00136198[0])
    {
        D_00136188[0] = (u64)D_00136198[0];
    }
    if (D_00136190[0] < (u64)D_00136198[0])
    {
        D_00136190[0] = (u64)D_00136198[0];
    }
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/malloc", func_00127908);
