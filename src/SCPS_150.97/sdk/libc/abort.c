#include "common.h"

void _exit(int status) __attribute__((noreturn));
int raise(int sig);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/abort", abort);
void abort(void)
{
    raise(6);
    _exit(1);
    for (;;);
}

struct _atexit_local
{
    struct _atexit_local *_next;
    int _ind;
    void (*_fns[32])(void);
};

struct _reent_local
{
    char pad[0x148];
    struct _atexit_local *_atexit;
    struct _atexit_local _atexit0;
};

extern struct _reent_local *D_00135D60[];
void *malloc(unsigned int size);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/abort", atexit);
int atexit(void (*fn)(void))
{
    struct _reent_local **rp;
    struct _atexit_local *p;

    rp = D_00135D60;
    p = (*rp)->_atexit;
    if (p == NULL)
    {
        p = &(*rp)->_atexit0;
        (*rp)->_atexit = p;
    }

    if (p->_ind >= 32)
    {
        p = malloc(0x88);
        if (p == NULL)
        {
            return -1;
        }
        p->_ind = 0;
        p->_next = (*rp)->_atexit;
        (*rp)->_atexit = p;
    }

    p->_fns[p->_ind++] = fn;
    return 0;
}
