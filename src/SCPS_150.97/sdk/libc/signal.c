#include "common.h"
#include <sys/reent.h>

typedef void (*SigFunc)(int);

extern struct _reent *D_00135D60[];

void *_malloc_r(struct _reent *ptr, u32 size);
int _getpid_r(struct _reent *ptr);
int _kill_r(struct _reent *ptr, int pid, int sig);
int _init_signal_r(struct _reent *ptr);
int _raise_r(struct _reent *ptr, int sig);
int __sigtramp_r(struct _reent *ptr, int sig);
SigFunc _signal_r(struct _reent *ptr, int sig, SigFunc func);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/signal", _init_signal_r);
int _init_signal_r(struct _reent *ptr)
{
    SigFunc *sig;
    SigFunc *p;
    int i;

    if (ptr->_sig_func == 0)
    {
        sig = _malloc_r(ptr, 0x80);
        ptr->_sig_func = sig;
        if (sig == 0)
        {
            return -1;
        }
        p = sig + 31;
        for (i = 31; i >= 0; i--)
        {
            *p = 0;
            p--;
        }
    }
    return 0;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/signal", _signal_r);
SigFunc _signal_r(struct _reent *ptr, int sig, SigFunc func)
{
    SigFunc old;

    if ((u32)sig >= 32)
    {
        ptr->_errno = 22;
        return (SigFunc)-1;
    }
    if (ptr->_sig_func == 0)
    {
        if (_init_signal_r(ptr) != 0)
        {
            return (SigFunc)-1;
        }
    }
    old = ptr->_sig_func[sig];
    ptr->_sig_func[sig] = func;
    return old;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/signal", _raise_r);
int _raise_r(struct _reent *ptr, int sig)
{
    SigFunc *slot;
    SigFunc func;

    if ((u32)sig >= 32)
    {
        ptr->_errno = 22;
        return -1;
    }
    if (ptr->_sig_func == 0)
    {
        if (_init_signal_r(ptr) != 0)
        {
            return -1;
        }
    }
    slot = (SigFunc *)(sig * 4 + (u32)ptr->_sig_func);
    func = *slot;
    if (func == 0)
    {
        return _kill_r(ptr, _getpid_r(ptr), sig);
    }
    if (func == (SigFunc)1)
    {
        return 0;
    }
    if (func == (SigFunc)-1)
    {
        ptr->_errno = 22;
        return 1;
    }
    *slot = 0;
    func(sig);
    return 0;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/signal", __sigtramp_r);
int __sigtramp_r(struct _reent *ptr, int sig)
{
    SigFunc *slot;
    SigFunc func;

    if ((u32)sig >= 32)
    {
        return -1;
    }
    if (ptr->_sig_func == 0)
    {
        if (_init_signal_r(ptr) != 0)
        {
            return -1;
        }
    }
    slot = (SigFunc *)(sig * 4 + (u32)ptr->_sig_func);
    func = *slot;
    if (func == 0)
    {
        return 1;
    }
    if (func == (SigFunc)-1)
    {
        return 2;
    }
    if (func == (SigFunc)1)
    {
        return 3;
    }
    *slot = 0;
    func(sig);
    return 0;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/signal", raise);
int raise(int sig)
{
    return _raise_r(D_00135D60[0], sig);
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/signal", signal);
SigFunc signal(int sig, SigFunc func)
{
    return _signal_r(D_00135D60[0], sig, func);
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/signal", _init_signal);
int _init_signal(void)
{
    return _init_signal_r(D_00135D60[0]);
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/signal", __sigtramp);
int __sigtramp(int sig)
{
    return __sigtramp_r(D_00135D60[0], sig);
}
