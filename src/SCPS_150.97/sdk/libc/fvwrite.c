#include "common.h"

/* NEARMISS-STUB __sfvwrite */
#if 0 /* NEARMISS 26.8% cat=branch-layout sub=- | min(len,0x400) ternary if-converted to movn in target, branch in ours; loop branch layout (blezl) and arg regs differ | attempts=2 */
struct __siov
{
    char *iov_base;
    int iov_len;
};

struct __suio
{
    struct __siov *uio_iov;
    int uio_iovcnt;
    int uio_resid;
};


int __sfvwrite(FILE *fp, struct __suio *uio)
{
    struct __siov *iov;
    char *p;
    int len;
    int n;
    int m;
    int w;
    int r;
    int nldist;
    int nlknown;
    char *nl;

    if (uio->uio_resid == 0)
    {
        return 0;
    }
    if (!(fp->_flags & 0x8) || fp->_bf._base == NULL)
    {
        if (__swsetup(fp))
        {
            return -1;
        }
    }
    iov = uio->uio_iov;
    len = 0;
    if (fp->_flags & 0x2)
    {
        do
        {
            if (len == 0)
            {
                do
                {
                    len = iov->iov_len;
                    p = iov->iov_base;
                    iov++;
                } while (len == 0);
            }
            n = (len <= 0x400) ? len : 0x400;
            r = fp->_write(fp->_cookie, p, n);
            if (r <= 0)
            {
                goto err;
            }
            p += r;
            len -= r;
            uio->uio_resid -= r;
        } while (uio->uio_resid != 0);
        return 0;
    }
    if (fp->_flags & 0x1)
    {
        do
        {
            if (len == 0)
            {
                nlknown = 0;
                do
                {
                    len = iov->iov_len;
                    p = iov->iov_base;
                    iov++;
                } while (len == 0);
            }
            if (!nlknown)
            {
                nl = memchr(p, '\n', len);
                if (nl == NULL)
                {
                    nldist = len + 1;
                }
                else
                {
                    nldist = (nl - p) + 1;
                }
                nlknown = 1;
            }
            m = (len < nldist) ? len : nldist;
            w = fp->_w;
            n = w + fp->_bf._size;
            if (fp->_bf._base < fp->_p && n < m)
            {
                memmove(fp->_p, p, n);
                fp->_p += n;
                nldist -= n;
                if (fflush(fp) != 0)
                {
                    goto err;
                }
            }
            else
            {
                n = fp->_bf._size;
                if (m < n)
                {
                    n = m;
                    memmove(fp->_p, p, n);
                    fp->_w -= n;
                    fp->_p += n;
                    nldist -= n;
                }
                else
                {
                    r = fp->_write(fp->_cookie, p, n);
                    if (r <= 0)
                    {
                        goto err;
                    }
                    n = r;
                    nldist -= n;
                }
            }
            if (nldist == 0)
            {
                if (fflush(fp) != 0)
                {
                    goto err;
                }
                nlknown = 0;
            }
            p += n;
            len -= n;
            uio->uio_resid -= n;
        } while (uio->uio_resid != 0);
        return 0;
    }
    do
    {
        if (len == 0)
        {
            do
            {
                len = iov->iov_len;
                p = iov->iov_base;
                iov++;
            } while (len == 0);
        }
        w = fp->_w;
        if (fp->_flags & 0x200)
        {
            n = (len < w) ? len : w;
            memmove(fp->_p, p, n);
            fp->_w -= n;
            fp->_p += n;
            n = len;
        }
        else if (fp->_bf._base < fp->_p && w < len)
        {
            memmove(fp->_p, p, w);
            fp->_p += w;
            if (fflush(fp) != 0)
            {
                goto err;
            }
            n = w;
        }
        else if (len < fp->_bf._size)
        {
            n = len;
            memmove(fp->_p, p, n);
            fp->_w -= n;
            fp->_p += n;
        }
        else
        {
            n = fp->_write(fp->_cookie, p, fp->_bf._size);
            if (n <= 0)
            {
                goto err;
            }
        }
        p += n;
        len -= n;
        uio->uio_resid -= n;
    } while (uio->uio_resid != 0);
    return 0;

err:
    fp->_flags |= 0x40;
    return -1;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/fvwrite", __sfvwrite);
