#include "common.h"
#include <stdio.h>
#include <stdarg.h>
#include <sys/reent.h>

extern struct _reent *D_00135D60[];

struct __siov
{
    void *iov_base;
    int iov_len;
};

struct __suio
{
    struct __siov *uio_iov;
    int uio_iovcnt;
    int uio_resid;
};

int __sfvwrite(FILE *fp, struct __suio *uio);
void __sinit(struct _reent *s);
int fflush(FILE *fp);
int _vfprintf_r(struct _reent *ptr, FILE *fp, const char *fmt, va_list ap);
int vfprintf(FILE *fp, const char *fmt, va_list ap);
double dpsub(double a, double b);
s32 dpcmp(double a, double b);
char *_dtoa_r(struct _reent *ptr, double d, int mode, int ndigits, int *decpt, int *sign, char **rve);

#define MAXEXP 0x134

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/vprintf", __sprint);
int __sprint(FILE *fp, struct __suio *uio)
{
    int err;

    if (uio->uio_resid == 0)
    {
        uio->uio_iovcnt = 0;
        return 0;
    }
    err = __sfvwrite(fp, uio);
    uio->uio_resid = 0;
    uio->uio_iovcnt = 0;
    return err;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/vprintf", __sbprintf);
int __sbprintf(FILE *fp, const char *fmt, va_list ap)
{
    FILE fake;
    unsigned char buf[1024];
    int ret;

    fake._p = buf;
    fake._data = fp->_data;
    fake._flags = fp->_flags & ~__SNBF;
    fake._file = fp->_file;
    fake._cookie = fp->_cookie;
    fake._write = fp->_write;
    fake._w = 1024;
    fake._bf._base = buf;
    fake._bf._size = 1024;
    fake._lbfsize = 0;
    ret = vfprintf(&fake, fmt, ap);
    if (ret >= 0)
    {
        if (fflush(&fake))
        {
            ret = -1;
        }
    }
    if (fake._flags & __SERR)
    {
        fp->_flags |= __SERR;
    }
    return ret;
}

/* NEARMISS-STUB vfprintf */
#if 0 /* NEARMISS 86.14% cat=regalloc sub=- | fmt/ap s1/s2 swapped, NULL _data path load into a0 | attempts=1 */
//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/vprintf", vfprintf);
int vfprintf(FILE *fp, const char *fmt, va_list ap)
{
    struct _reent *ptr;

    ptr = fp->_data;
    if (!ptr)
    {
        ptr = D_00135D60[0];
        fp->_data = ptr;
    }
    if (!ptr->__sdidinit)
    {
        __sinit(ptr);
        ptr = fp->_data;
    }
    return _vfprintf_r(ptr, fp, fmt, ap);
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/vprintf", vfprintf);

/* NEARMISS-STUB _vfprintf_r */
#if 0 /* NEARMISS 57.19% cat=branch-layout sub=- | goto-threaded shared PRINT tails, frame 0x290, s-reg allocation | attempts=1 */
#define BUF 348
#define MAXFRACT 39
#define PADSIZE 16
#define NIOV 8

#define ALT 0x001
#define HEXPREFIX 0x002
#define LADJUST 0x004
#define LONGDBL 0x008
#define LONGINT 0x010
#define QUADINT 0x020
#define SHORTINT 0x040
#define ZEROPAD 0x080
#define FPT 0x100

extern char D_00139530[];
extern char D_00139540[];
extern char D_00139550[];
extern char D_00139558[];
extern char D_00139560[];
extern char D_00139578[];
extern char D_00139580[];
extern char D_00139598[];
extern char D_001395B8[];
extern char D_001395C0[];
extern char D_001361C8[];
extern void *localeconv(void);
extern int _mbtowc_r(struct _reent *ptr, int *pwc, const char *s, int n, void *state);
extern int __swsetup(FILE *fp);
extern int isinf(double d);
extern int isnan(double d);
extern void *memchr(const void *s, int c, unsigned int n);
extern unsigned int strlen(const char *s);
extern u64 __umoddi3(u64 a, u64 b);
extern u64 __udivdi3(u64 a, u64 b);
char *cvf(struct _reent *ptr, double value, int ndigits, int flags, char *sign, int *decpt, int ch, int *length);
int exponent(char *p0, int exp, int fmtch);

int _vfprintf_r(struct _reent *data, FILE *fp, const char *fmt0, va_list ap)
{
    char *fmt;
    int ch;
    int n;
    int m;
    char *cp;
    struct __siov *iovp;
    int flags;
    int ret;
    int width;
    int prec;
    char sign;
    int wc;
    void *state;
    int dprec;
    int fieldsz;
    int realsz;
    char *xdigs;
    struct __suio uio;
    struct __siov iov[NIOV];
    char buf[BUF];
    char ox[2];
    char softsign;
    int expt;
    int ndig;
    int expsize;
    char expstr[7];
    double _double;
    u64 _uquad;
    char *decimal_point;
    int size;
    int base;

    state = 0;
    fmt = (char *)fmt0;
    ret = 0;
    decimal_point = *(char **)localeconv();
    if (((fp->_flags & __SWR) == 0 || fp->_bf._base == NULL) && __swsetup(fp))
    {
        return -1;
    }
    if ((fp->_flags & (__SNBF | __SWR | __SRW)) == (__SNBF | __SWR) && fp->_file >= 0)
    {
        return __sbprintf(fp, fmt0, ap);
    }
    iovp = iov;
    uio.uio_iov = iovp;
    uio.uio_resid = 0;
    uio.uio_iovcnt = 0;
    ret = 0;

    for (;;)
    {
        cp = fmt;
        for (;;)
        {
            n = _mbtowc_r(D_00135D60[0], &wc, fmt, *(int *)D_001361C8, &state);
            if (n <= 0)
            {
                break;
            }
            fmt += n;
            if (wc == '%')
            {
                fmt--;
                break;
            }
        }
        m = fmt - cp;
        if (m != 0)
        {
            iovp->iov_base = cp;
            iovp->iov_len = m;
            uio.uio_resid += m;
            iovp++;
            if (++uio.uio_iovcnt >= NIOV)
            {
                if (__sprint(fp, &uio))
                {
                    goto error;
                }
                iovp = iov;
            }
            ret += m;
        }
        if (n <= 0)
        {
            goto done;
        }
        fmt++;
        sign = 0;
        dprec = 0;
        flags = 0;
        width = 0;
        prec = -1;
        ch = *fmt++;

    reswitch:
        switch (ch)
        {
        case ' ':
            if (!sign)
            {
                sign = ' ';
            }
            ch = *fmt++;
            goto reswitch;
        case '#':
            flags |= ALT;
            ch = *fmt++;
            goto reswitch;
        case '*':
            width = va_arg(ap, int);
            if (width < 0)
            {
                width = -width;
                flags |= LADJUST;
            }
            ch = *fmt++;
            goto reswitch;
        case '-':
            flags |= LADJUST;
            ch = *fmt++;
            goto reswitch;
        case '+':
            sign = '+';
            ch = *fmt++;
            goto reswitch;
        case '.':
            if ((ch = *fmt++) == '*')
            {
                n = va_arg(ap, int);
                prec = n < 0 ? -1 : n;
                ch = *fmt++;
                goto reswitch;
            }
            n = 0;
            while (ch >= '0' && ch <= '9')
            {
                n = 10 * n + (ch - '0');
                ch = *fmt++;
            }
            prec = n < 0 ? -1 : n;
            goto reswitch;
        case '0':
            flags |= ZEROPAD;
            ch = *fmt++;
            goto reswitch;
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            n = 0;
            do
            {
                n = 10 * n + (ch - '0');
                ch = *fmt++;
            } while (ch >= '0' && ch <= '9');
            width = n;
            goto reswitch;
        case 'L':
            flags |= LONGDBL;
            ch = *fmt++;
            goto reswitch;
        case 'h':
            flags |= SHORTINT;
            ch = *fmt++;
            goto reswitch;
        case 'l':
            ch = *fmt++;
            if (ch == 'l')
            {
                flags |= QUADINT;
                ch = *fmt++;
            }
            else
            {
                flags |= LONGINT;
            }
            goto reswitch;
        case 'q':
            flags |= QUADINT;
            ch = *fmt++;
            goto reswitch;
        case 'c':
            cp = buf;
            *cp = va_arg(ap, int);
            size = 1;
            sign = 0;
            break;
        case 'D':
            flags |= LONGINT;
        case 'd':
        case 'i':
            _uquad = va_arg(ap, int);
            if ((long long)_uquad < 0)
            {
                _uquad = -_uquad;
                sign = '-';
            }
            base = 1;
            goto number;
        case 'e':
        case 'E':
        case 'f':
        case 'g':
        case 'G':
            if (prec == -1)
            {
                prec = 6;
            }
            else if ((ch == 'g' || ch == 'G') && prec == 0)
            {
                prec = 1;
            }
            _double = va_arg(ap, double);
            if (isinf(_double))
            {
                if (dpcmp(_double, 0.0) < 0)
                {
                    sign = '-';
                }
                cp = D_00139550;
                size = 3;
                fieldsz = 3;
                break;
            }
            if (isnan(_double))
            {
                cp = D_00139558;
                size = 3;
                break;
            }
            flags |= FPT;
            cp = cvf(data, _double, prec, flags, &softsign, &expt, ch, &ndig);
            if (ch == 'g' || ch == 'G')
            {
                if (expt <= -4 || expt > prec)
                {
                    ch = (ch == 'g') ? 'e' : 'E';
                }
                else
                {
                    ch = 'g';
                }
            }
            if (ch <= 'e')
            {
                --expt;
                expsize = exponent(expstr, expt, ch);
                size = expsize + ndig;
                if (ndig > 1 || (flags & ALT))
                {
                    ++size;
                }
            }
            else if (ch == 'f')
            {
                if (expt <= 0)
                {
                    size = prec + 2;
                }
                else if (prec != 0)
                {
                    size = expt + prec + 1;
                }
                else
                {
                    size = expt;
                    if (flags & ALT)
                    {
                        size++;
                    }
                }
            }
            else
            {
                if (expt >= ndig)
                {
                    size = expt;
                    if (flags & ALT)
                    {
                        ++size;
                    }
                }
                else if (expt > 0)
                {
                    size = ndig + 1;
                }
                else
                {
                    size = ndig - expt + 2;
                }
            }
            if (softsign)
            {
                sign = '-';
            }
            break;
        case 'n':
            if (flags & QUADINT)
            {
                *va_arg(ap, long long *) = ret;
            }
            else if (flags & LONGINT)
            {
                *va_arg(ap, long *) = ret;
            }
            else if (flags & SHORTINT)
            {
                *va_arg(ap, short *) = ret;
            }
            else
            {
                *va_arg(ap, int *) = ret;
            }
            goto rflag_next;
        case 'O':
            flags |= LONGINT;
        case 'o':
            _uquad = va_arg(ap, unsigned int);
            base = 0;
            goto nosign;
        case 'p':
            _uquad = (u32)va_arg(ap, void *);
            base = 2;
            xdigs = D_00139560;
            flags |= HEXPREFIX;
            ch = 'x';
            goto nosign;
        case 's':
            cp = va_arg(ap, char *);
            if (cp == NULL)
            {
                cp = D_00139578;
            }
            if (prec >= 0)
            {
                char *p = memchr(cp, 0, prec);
                if (p != NULL)
                {
                    size = p - cp;
                    if (size > prec)
                    {
                        size = prec;
                    }
                }
                else
                {
                    size = prec;
                }
            }
            else
            {
                size = strlen(cp);
            }
            sign = 0;
            break;
        case 'U':
            flags |= LONGINT;
        case 'u':
            _uquad = va_arg(ap, unsigned int);
            base = 1;
            goto nosign;
        case 'X':
            xdigs = D_00139580;
            _uquad = va_arg(ap, unsigned int);
            base = 2;
            if ((flags & ALT) && _uquad != 0)
            {
                flags |= HEXPREFIX;
            }
            goto nosign;
        case 'x':
            xdigs = D_00139560;
            _uquad = va_arg(ap, unsigned int);
            base = 2;
            if ((flags & ALT) && _uquad != 0)
            {
                flags |= HEXPREFIX;
            }
        nosign:
            sign = 0;
        number:
            if ((dprec = prec) >= 0)
            {
                flags &= ~ZEROPAD;
            }
            cp = buf + BUF;
            if (_uquad != 0 || prec != 0)
            {
                switch (base)
                {
                case 0:
                    do
                    {
                        *--cp = (_uquad & 7) + '0';
                        _uquad >>= 3;
                    } while (_uquad);
                    if ((flags & ALT) && *cp != '0')
                    {
                        *--cp = '0';
                    }
                    break;
                case 1:
                    while (_uquad >= 10)
                    {
                        *--cp = (_uquad % 10) + '0';
                        _uquad /= 10;
                    }
                    *--cp = _uquad + '0';
                    break;
                case 2:
                    do
                    {
                        *--cp = xdigs[_uquad & 15];
                        _uquad >>= 4;
                    } while (_uquad);
                    break;
                }
            }
            size = buf + BUF - cp;
            break;
        default:
            if (ch == '\0')
            {
                goto done;
            }
            cp = buf;
            *cp = ch;
            size = 1;
            sign = 0;
            break;
        }

        fieldsz = size;
        realsz = dprec > size ? dprec : size;
        if (sign)
        {
            realsz++;
        }
        else if (flags & HEXPREFIX)
        {
            realsz += 2;
        }
        if ((flags & (LADJUST | ZEROPAD)) == 0)
        {
            if ((n = width - realsz) > 0)
            {
                while (n > PADSIZE)
                {
                    iovp->iov_base = D_00139530;
                    iovp->iov_len = PADSIZE;
                    uio.uio_resid += PADSIZE;
                    iovp++;
                    if (++uio.uio_iovcnt >= NIOV)
                    {
                        if (__sprint(fp, &uio))
                        {
                            goto error;
                        }
                        iovp = iov;
                    }
                    n -= PADSIZE;
                }
                iovp->iov_base = D_00139530;
                iovp->iov_len = n;
                uio.uio_resid += n;
                iovp++;
                if (++uio.uio_iovcnt >= NIOV)
                {
                    if (__sprint(fp, &uio))
                    {
                        goto error;
                    }
                    iovp = iov;
                }
            }
        }
        if (sign)
        {
            iovp->iov_base = &sign;
            iovp->iov_len = 1;
            uio.uio_resid += 1;
            iovp++;
            if (++uio.uio_iovcnt >= NIOV)
            {
                if (__sprint(fp, &uio))
                {
                    goto error;
                }
                iovp = iov;
            }
        }
        if (flags & HEXPREFIX)
        {
            ox[0] = '0';
            ox[1] = ch;
            iovp->iov_base = ox;
            iovp->iov_len = 2;
            uio.uio_resid += 2;
            iovp++;
            if (++uio.uio_iovcnt >= NIOV)
            {
                if (__sprint(fp, &uio))
                {
                    goto error;
                }
                iovp = iov;
            }
        }
        if ((flags & (LADJUST | ZEROPAD)) == ZEROPAD)
        {
            if ((n = width - realsz) > 0)
            {
                while (n > PADSIZE)
                {
                    iovp->iov_base = D_00139540;
                    iovp->iov_len = PADSIZE;
                    uio.uio_resid += PADSIZE;
                    iovp++;
                    if (++uio.uio_iovcnt >= NIOV)
                    {
                        if (__sprint(fp, &uio))
                        {
                            goto error;
                        }
                        iovp = iov;
                    }
                    n -= PADSIZE;
                }
                iovp->iov_base = D_00139540;
                iovp->iov_len = n;
                uio.uio_resid += n;
                iovp++;
                if (++uio.uio_iovcnt >= NIOV)
                {
                    if (__sprint(fp, &uio))
                    {
                        goto error;
                    }
                    iovp = iov;
                }
            }
        }
        if ((n = dprec - fieldsz) > 0)
        {
            while (n > PADSIZE)
            {
                iovp->iov_base = D_00139540;
                iovp->iov_len = PADSIZE;
                uio.uio_resid += PADSIZE;
                iovp++;
                if (++uio.uio_iovcnt >= NIOV)
                {
                    if (__sprint(fp, &uio))
                    {
                        goto error;
                    }
                    iovp = iov;
                }
                n -= PADSIZE;
            }
            iovp->iov_base = D_00139540;
            iovp->iov_len = n;
            uio.uio_resid += n;
            iovp++;
            if (++uio.uio_iovcnt >= NIOV)
            {
                if (__sprint(fp, &uio))
                {
                    goto error;
                }
                iovp = iov;
            }
        }
        if (!(flags & FPT))
        {
            iovp->iov_base = cp;
            iovp->iov_len = fieldsz;
            uio.uio_resid += fieldsz;
            iovp++;
            if (++uio.uio_iovcnt >= NIOV)
            {
                if (__sprint(fp, &uio))
                {
                    goto error;
                }
                iovp = iov;
            }
        }
        else
        {
            if (ch < 'f')
            {
                if (ndig < 2 && !(flags & ALT))
                {
                    iovp->iov_base = cp;
                    iovp->iov_len = 1;
                    uio.uio_resid += 1;
                    iovp++;
                    if (++uio.uio_iovcnt >= NIOV)
                    {
                        if (__sprint(fp, &uio))
                        {
                            goto error;
                        }
                        iovp = iov;
                    }
                }
                else
                {
                    ox[0] = *cp++;
                    ox[1] = '.';
                    iovp->iov_base = ox;
                    iovp->iov_len = 2;
                    uio.uio_resid += 2;
                    iovp++;
                    if (++uio.uio_iovcnt >= NIOV)
                    {
                        if (__sprint(fp, &uio))
                        {
                            goto error;
                        }
                        iovp = iov;
                    }
                    iovp->iov_base = cp;
                    iovp->iov_len = ndig - 1;
                    uio.uio_resid += ndig - 1;
                    iovp++;
                    if (++uio.uio_iovcnt >= NIOV)
                    {
                        if (__sprint(fp, &uio))
                        {
                            goto error;
                        }
                        iovp = iov;
                    }
                }
                iovp->iov_base = expstr;
                iovp->iov_len = expsize;
                uio.uio_resid += expsize;
                iovp++;
                if (++uio.uio_iovcnt >= NIOV)
                {
                    if (__sprint(fp, &uio))
                    {
                        goto error;
                    }
                    iovp = iov;
                }
            }
            else
            {
                if (ch == 'f')
                {
                    if (expt > 0)
                    {
                        iovp->iov_base = cp;
                        iovp->iov_len = expt;
                        uio.uio_resid += expt;
                        iovp++;
                        if (++uio.uio_iovcnt >= NIOV)
                        {
                            if (__sprint(fp, &uio))
                            {
                                goto error;
                            }
                            iovp = iov;
                        }
                        cp += expt;
                        expt = 0;
                    }
                    else
                    {
                        iovp->iov_base = D_001395B8;
                        iovp->iov_len = 1;
                        uio.uio_resid += 1;
                        iovp++;
                        if (++uio.uio_iovcnt >= NIOV)
                        {
                            if (__sprint(fp, &uio))
                            {
                                goto error;
                            }
                            iovp = iov;
                        }
                    }
                    if (prec || (flags & ALT))
                    {
                        iovp->iov_base = decimal_point;
                        iovp->iov_len = 1;
                        uio.uio_resid += 1;
                        iovp++;
                        if (++uio.uio_iovcnt >= NIOV)
                        {
                            if (__sprint(fp, &uio))
                            {
                                goto error;
                            }
                            iovp = iov;
                        }
                    }
                    if (ndig - expt > 0)
                    {
                        iovp->iov_base = cp;
                        iovp->iov_len = ndig - expt;
                        uio.uio_resid += ndig - expt;
                        iovp++;
                        if (++uio.uio_iovcnt >= NIOV)
                        {
                            if (__sprint(fp, &uio))
                            {
                                goto error;
                            }
                            iovp = iov;
                        }
                    }
                }
                else
                {
                    iovp->iov_base = cp;
                    iovp->iov_len = ndig;
                    uio.uio_resid += ndig;
                    iovp++;
                    if (++uio.uio_iovcnt >= NIOV)
                    {
                        if (__sprint(fp, &uio))
                        {
                            goto error;
                        }
                        iovp = iov;
                    }
                }
            }
        }
        if ((n = fieldsz) > 0)
        {
            if (flags & FPT)
            {
                n = size;
            }
        }
        if ((flags & (LADJUST | ZEROPAD)) == LADJUST)
        {
            if ((n = width - realsz) > 0)
            {
                while (n > PADSIZE)
                {
                    iovp->iov_base = D_00139530;
                    iovp->iov_len = PADSIZE;
                    uio.uio_resid += PADSIZE;
                    iovp++;
                    if (++uio.uio_iovcnt >= NIOV)
                    {
                        if (__sprint(fp, &uio))
                        {
                            goto error;
                        }
                        iovp = iov;
                    }
                    n -= PADSIZE;
                }
                iovp->iov_base = D_00139530;
                iovp->iov_len = n;
                uio.uio_resid += n;
                iovp++;
                if (++uio.uio_iovcnt >= NIOV)
                {
                    if (__sprint(fp, &uio))
                    {
                        goto error;
                    }
                    iovp = iov;
                }
            }
        }
    }
done:
    if (uio.uio_resid != 0)
    {
        if (__sprint(fp, &uio))
        {
            goto error;
        }
    }
    uio.uio_iovcnt = 0;
    iovp = iov;
    goto out;
error:
    ret = -1;
out:
    if (fp->_flags & __SERR)
    {
        return -1;
    }
    return ret;
rflag_next:
    ch = *fmt++;
    goto reswitch;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/vprintf", _vfprintf_r);

/* NEARMISS-STUB cvf */
#if 0 /* NEARMISS 72.86% cat=regalloc sub=- | callee-save allocation (9 s-regs), length arg spilled vs kept in fp | attempts=1 */
char *cvf(struct _reent *ptr, double value, int ndigits, int flags, char *sign, int *decpt, int ch, int *length)
{
    int mode;
    int dsign;
    char *digits;
    char *bp;
    char *rve;

    if (ch == 'f')
    {
        mode = 3;
    }
    else
    {
        if (ch == 'e' || ch == 'E')
        {
            ndigits++;
        }
        mode = 2;
    }
    if (value < 0)
    {
        value = dpsub(0.0, value);
        *sign = '-';
    }
    else
    {
        *sign = 0;
    }
    digits = _dtoa_r(ptr, value, mode, ndigits, decpt, &dsign, &rve);
    bp = digits + ndigits;
    if (ch == 'g' || ch == 'G')
    {
        if ((flags & 1) == 0)
        {
            *length = rve - digits;
            return digits;
        }
    }
    else if (ch == 'f')
    {
        if (*digits == '0' && dpcmp(value, 0.0) != 0)
        {
            *decpt = 1 - ndigits;
        }
        bp += *decpt;
    }
    if (dpcmp(value, 0.0) == 0)
    {
        rve = bp;
    }
    if (rve < bp)
    {
        do
        {
            *rve++ = '0';
        } while (rve < bp);
    }
    *length = rve - digits;
    return digits;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/vprintf", cvf);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/vprintf", exponent);


int exponent(char *p0, int exp, int fmtch)
{
    char *p;
    char *t;
    char expbuf[MAXEXP];

    p = p0 + 1;
    *p0 = fmtch;
    if (exp < 0)
    {
        exp = -exp;
        *p++ = '-';
    }
    else
    {
        *p++ = '+';
    }
    t = expbuf + MAXEXP;
    if (exp > 9)
    {
        do
        {
            *--t = (exp % 10) + '0';
        } while ((exp /= 10) > 9);
        *--t = exp + '0';
        for (; t < expbuf + MAXEXP; t++)
        {
            *p++ = *t;
        }
    }
    else
    {
        *p++ = '0';
        *p++ = exp + '0';
    }
    return p - p0;
}
