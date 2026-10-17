#include "common.h"
#include <sys/reent.h>

extern s32 D_0013A30C[];

int kill(int pid, int sig);
int getpid(void);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/signalr", _kill_r);
int _kill_r(struct _reent *ptr, int pid, int sig)
{
    int ret;

    D_0013A30C[0] = 0;
    ret = kill(pid, sig);
    if (ret == -1)
    {
        if (D_0013A30C[0] != 0)
        {
            ptr->_errno = D_0013A30C[0];
        }
    }
    return ret;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/signalr", _getpid_r);
int _getpid_r(struct _reent *ptr)
{
    return getpid();
}
