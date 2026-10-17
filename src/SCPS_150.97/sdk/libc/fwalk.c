#include "common.h"
#include <sys/reent.h>
#include <stdio.h>

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/fwalk", _fwalk);
int _fwalk(struct _reent *ptr, int (*function)(FILE *))
{
    FILE *fp;
    int n;
    int ret;
    struct _glue *g;

    ret = 0;
    for (g = &ptr->__sglue; g != NULL; g = g->_next)
    {
        fp = g->_iobs;
        for (n = g->_niobs; --n >= 0; fp++)
        {
            if (fp->_flags == 0)
            {
                continue;
            }
            ret |= (*function)(fp);
        }
    }
    return ret;
}
