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

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/vprintf", vfprintf);
#define CHECK_INIT(fp) \
    do \
    { \
        if ((fp)->_data == 0) \
            (fp)->_data = D_00135D60[0]; \
        if (!(fp)->_data->__sdidinit) \
            __sinit((fp)->_data); \
    } while (0)

int vfprintf(FILE *fp, const char *fmt0, va_list ap)
{
    CHECK_INIT(fp);
    return _vfprintf_r(fp->_data, fp, fmt0, ap);
}

/* NEARMISS-STUB _vfprintf_r */
#if 0 /* NEARMISS 99.58% cat=rodata-const sub=jtbl-in-rodatabin | verbatim newlib vfprintf 57->99.58; switch jtbl sits in the SDK rodatabin (needs kS .rodata split); plus one e-format _double word-test the compiler drops in ou | attempts=2 */
/* newlib (1999) vfprintf.c _VFPRINTF_R verbatim: PRINT/PAD/FLUSH macros, SARG/UARG without quad (but the l/ll QUADINT flag parse kept), _uquad u_long, (u_long)va_arg(ap, void *). Strings/blanks/zeroes are the D_001395xx symbols. 99.58: (1) the switch jump table lives in the SDK rodatabin (0x1395C8..) -> needs a kS .rodata split for vprintf like frame.c; (2) in the e-format tail the target tests the two words of _double (lw 476/480(sp), bnezl/beqz) where ours drops the `_double || flags & ALT == 0` test. */
#define MAXFRACT 39
#define BUF (MAXEXP + MAXFRACT + 1) /* + decimal point */
#define DEFPREC 6
#define PADSIZE 16 /* pad chunk size */
#define NIOV 8

#define ALT 0x001       /* alternate form */
#define HEXPREFIX 0x002 /* add 0x or 0X prefix */
#define LADJUST 0x004   /* left adjustment */
#define LONGDBL 0x008   /* long double; unimplemented */
#define LONGINT 0x010   /* long integer */
#define QUADINT 0x020   /* quad integer */
#define SHORTINT 0x040  /* short integer */
#define ZEROPAD 0x080   /* zero (as opposed to blank) pad */
#define FPT 0x100       /* Floating point number */

#define quad_t long long
typedef unsigned long u_long;
typedef unsigned short u_short;
typedef unsigned int u_int;
#define u_quad_t unsigned long long

#define to_digit(c) ((c) - '0')
#define is_digit(c) ((unsigned)to_digit(c) <= 9)
#define to_char(n) ((n) + '0')

#define cantwrite(fp) \
    ((((fp)->_flags & __SWR) == 0 || (fp)->_bf._base == NULL) && __swsetup(fp))

/* static const char blanks[PADSIZE] / zeroes[PADSIZE] and the string
   literals live in the SDK rodata (-G0 build): reached through their symbols */
extern const char D_00139530[]; /* blanks */
extern const char D_00139540[]; /* zeroes */
#define blanks D_00139530
#define zeroes D_00139540
extern char D_00139550[]; /* "Inf" */
extern char D_00139558[]; /* "NaN" */
extern char D_00139560[]; /* "0123456789abcdef" */
extern char D_00139578[]; /* "(null)" */
extern char D_00139580[]; /* "0123456789ABCDEF" */
extern char D_00139598[]; /* "bug in vfprintf: bad base" */
extern char D_001395B8[]; /* "0" */
extern char D_001395C0[]; /* "." */
extern int D_001361C8[];  /* __mb_cur_max */
#define MB_CUR_MAX (*D_001361C8)
#define _REENT (*D_00135D60)

struct lconv_ { char *decimal_point; };
extern struct lconv_ *localeconv(void);
extern int _mbtowc_r(struct _reent *ptr, int *pwc, const char *s, int n, int *state);
extern int __swsetup(FILE *fp);
extern int isinf(double d);
extern int isnan(double d);
extern void *memchr(const void *s, int c, unsigned int n);
extern unsigned int strlen(const char *s);
char *cvf(struct _reent *ptr, double value, int ndigits, int flags, char *sign, int *decpt, int ch, int *length);
#define cvt cvf
int exponent(char *p0, int exp, int fmtch);

#define PRINT(ptr, len) \
    { \
        iovp->iov_base = (ptr); \
        iovp->iov_len = (len); \
        uio.uio_resid += (len); \
        iovp++; \
        if (++uio.uio_iovcnt >= NIOV) \
        { \
            if (__sprint(fp, &uio)) \
                goto error; \
            iovp = iov; \
        } \
    }
#define PAD(howmany, with) \
    { \
        if ((n = (howmany)) > 0) \
        { \
            while (n > PADSIZE) \
            { \
                PRINT(with, PADSIZE); \
                n -= PADSIZE; \
            } \
            PRINT(with, n); \
        } \
    }
#define FLUSH() \
    { \
        if (uio.uio_resid && __sprint(fp, &uio)) \
            goto error; \
        uio.uio_iovcnt = 0; \
        iovp = iov; \
    }

/*
 * To extend shorts properly, we need both signed and unsigned
 * argument extraction methods.
 */
#define SARG() \
    (flags & LONGINT ? va_arg(ap, long) : flags & SHORTINT ? (long)(short)va_arg(ap, int) : \
     (long)va_arg(ap, int))
#define UARG() \
    (flags & LONGINT ? va_arg(ap, u_long) : flags & SHORTINT ? (u_long)(u_short)va_arg(ap, int) : \
     (u_long)va_arg(ap, u_int))

int _vfprintf_r(struct _reent *data, FILE *fp, const char *fmt0, va_list ap)
{
    register char *fmt;          /* format string */
    register int ch;             /* character from fmt */
    register int n, m;           /* handy integers (short term usage) */
    register char *cp;           /* handy char pointer (short term usage) */
    register struct __siov *iovp; /* for PRINT macro */
    register int flags;          /* flags as above */
    int ret;                     /* return value accumulator */
    int width;                   /* width from format (%8d), or 0 */
    int prec;                    /* precision from format (%.3d), or -1 */
    char sign;                   /* sign prefix (' ', '+', '-', or \0) */
    int wc;
    char *decimal_point = localeconv()->decimal_point;
    char softsign; /* temporary negative sign for floats */
    double _double; /* double precision arguments %[eEfgG] */
    int expt;      /* integer value of exponent */
    int expsize;   /* character count for expstr */
    int ndig;      /* actual number of digits returned by cvt */
    char expstr[7]; /* buffer for exponent string */
    u_long _uquad; /* integer arguments %[diouxX] */
    enum { OCT, DEC, HEX } base; /* base for [diouxX] conversion */
    int dprec;       /* a copy of prec if [diouxX], 0 otherwise */
    int realsz;      /* field size expanded by dprec */
    int size;        /* size of converted field or string */
    char *xdigs;     /* digits for [xX] conversion */
    struct __suio uio;       /* output information: summary */
    struct __siov iov[NIOV]; /* ... and individual io vectors */
    char buf[BUF];   /* space for %c, %[diouxX], %[eEfgG] */
    char ox[2];      /* space for 0x hex-prefix */
    int state = 0;   /* mbtowc calls from library must not change state */

    /* sorry, fprintf(read_only_file, "") returns EOF, not 0 */
    if (cantwrite(fp))
        return (EOF);

    /* optimise fprintf(stderr) (and other unbuffered Unix files) */
    if ((fp->_flags & (__SNBF | __SWR | __SRW)) == (__SNBF | __SWR) && fp->_file >= 0)
        return (__sbprintf(fp, fmt0, ap));

    fmt = (char *)fmt0;
    uio.uio_iov = iovp = iov;
    uio.uio_resid = 0;
    uio.uio_iovcnt = 0;
    ret = 0;

    /*
     * Scan the format for conversions (`%' character).
     */
    for (;;)
    {
        cp = fmt;
        while ((n = _mbtowc_r(_REENT, &wc, fmt, MB_CUR_MAX, &state)) > 0)
        {
            fmt += n;
            if (wc == '%')
            {
                fmt--;
                break;
            }
        }
        if ((m = fmt - cp) != 0)
        {
            PRINT(cp, m);
            ret += m;
        }
        if (n <= 0)
            goto done;
        fmt++; /* skip over '%' */

        flags = 0;
        dprec = 0;
        width = 0;
        prec = -1;
        sign = '\0';

    rflag:
        ch = *fmt++;
    reswitch:
        switch (ch)
        {
        case ' ':
            /*
             * ``If the space and + flags both appear, the space
             * flag will be ignored.''
             *	-- ANSI X3J11
             */
            if (!sign)
                sign = ' ';
            goto rflag;
        case '#':
            flags |= ALT;
            goto rflag;
        case '*':
            /*
             * ``A negative field width argument is taken as a
             * - flag followed by a positive field width.''
             *	-- ANSI X3J11
             * They don't exclude field widths read from args.
             */
            if ((width = va_arg(ap, int)) >= 0)
                goto rflag;
            width = -width;
            /* FALLTHROUGH */
        case '-':
            flags |= LADJUST;
            goto rflag;
        case '+':
            sign = '+';
            goto rflag;
        case '.':
            if ((ch = *fmt++) == '*')
            {
                n = va_arg(ap, int);
                prec = n < 0 ? -1 : n;
                goto rflag;
            }
            n = 0;
            while (is_digit(ch))
            {
                n = 10 * n + to_digit(ch);
                ch = *fmt++;
            }
            prec = n < 0 ? -1 : n;
            goto reswitch;
        case '0':
            /*
             * ``Note that 0 is taken as a flag, not as the
             * beginning of a field width.''
             *	-- ANSI X3J11
             */
            flags |= ZEROPAD;
            goto rflag;
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
                n = 10 * n + to_digit(ch);
                ch = *fmt++;
            } while (is_digit(ch));
            width = n;
            goto reswitch;
        case 'L':
            flags |= LONGDBL;
            goto rflag;
        case 'h':
            flags |= SHORTINT;
            goto rflag;
        case 'l':
            if (*fmt == 'l')
            {
                fmt++;
                flags |= QUADINT;
            }
            else
            {
                flags |= LONGINT;
            }
            goto rflag;
        case 'q':
            flags |= QUADINT;
            goto rflag;
        case 'c':
            *(cp = buf) = va_arg(ap, int);
            size = 1;
            sign = '\0';
            break;
        case 'D':
            flags |= LONGINT;
            /*FALLTHROUGH*/
        case 'd':
        case 'i':
            _uquad = SARG();
            if ((long)_uquad < 0)
            {

                _uquad = -_uquad;
                sign = '-';
            }
            base = DEC;
            goto number;
        case 'e':
        case 'E':
        case 'f':
        case 'g':
        case 'G':
            if (prec == -1)
            {
                prec = DEFPREC;
            }
            else if ((ch == 'g' || ch == 'G') && prec == 0)
            {
                prec = 1;
            }

            if (flags & LONGDBL)
            {
                _double = (double)va_arg(ap, long double);
            }
            else
            {
                _double = va_arg(ap, double);
            }

            /* do this before tricky precision changes */
            if (isinf(_double))
            {
                if (_double < 0)
                    sign = '-';
                cp = D_00139550;
                size = 3;
                break;
            }
            if (isnan(_double))
            {
                cp = D_00139558;
                size = 3;
                break;
            }

            flags |= FPT;
            cp = cvt(data, _double, prec, flags, &softsign, &expt, ch, &ndig);
            if (ch == 'g' || ch == 'G')
            {
                if (expt <= -4 || expt > prec)
                    ch = (ch == 'g') ? 'e' : 'E';
                else
                    ch = 'g';
            }
            if (ch <= 'e')
            { /* 'e' or 'E' fmt */
                --expt;
                expsize = exponent(expstr, expt, ch);
                size = expsize + ndig;
                if (ndig > 1 || flags & ALT)
                    ++size;
            }
            else if (ch == 'f')
            { /* f fmt */
                if (expt > 0)
                {
                    size = expt;
                    if (prec || flags & ALT)
                        size += prec + 1;
                }
                else /* "0.X" */
                    size = prec + 2;
            }
            else if (expt >= ndig)
            { /* fixed g fmt */
                size = expt;
                if (flags & ALT)
                    ++size;
            }
            else
                size = ndig + (expt > 0 ? 1 : 2 - expt);

            if (softsign)
                sign = '-';
            break;
        case 'n':
            if (flags & LONGINT)
                *va_arg(ap, long *) = ret;
            else if (flags & SHORTINT)
                *va_arg(ap, short *) = ret;
            else
                *va_arg(ap, int *) = ret;
            continue; /* no output */
        case 'O':
            flags |= LONGINT;
            /*FALLTHROUGH*/
        case 'o':
            _uquad = UARG();
            base = OCT;
            goto nosign;
        case 'p':
            /*
             * ``The argument shall be a pointer to void.  The
             * value of the pointer is converted to a sequence
             * of printable characters, in an implementation-
             * defined manner.''
             *	-- ANSI X3J11
             */
            /* NOSTRICT */
            _uquad = (u_long)va_arg(ap, void *);
            base = HEX;
            xdigs = D_00139560;
            flags |= HEXPREFIX;
            ch = 'x';
            goto nosign;
        case 's':
            if ((cp = va_arg(ap, char *)) == NULL)
                cp = D_00139578;
            if (prec >= 0)
            {
                /*
                 * can't use strlen; can only look for the
                 * NUL in the first `prec' characters, and
                 * strlen() will go further.
                 */
                char *p = memchr(cp, 0, prec);

                if (p != NULL)
                {
                    size = p - cp;
                    if (size > prec)
                        size = prec;
                }
                else
                    size = prec;
            }
            else
                size = strlen(cp);
            sign = '\0';
            break;
        case 'U':
            flags |= LONGINT;
            /*FALLTHROUGH*/
        case 'u':
            _uquad = UARG();
            base = DEC;
            goto nosign;
        case 'X':
            xdigs = D_00139580;
            goto hex;
        case 'x':
            xdigs = D_00139560;
        hex:
            _uquad = UARG();
            base = HEX;
            /* leading 0x/X only if non-zero */
            if (flags & ALT && _uquad != 0)
                flags |= HEXPREFIX;

            /* unsigned conversions */
        nosign:
            sign = '\0';
            /*
             * ``... diouXx conversions ... if a precision is
             * specified, the 0 flag will be ignored.''
             *	-- ANSI X3J11
             */
        number:
            if ((dprec = prec) >= 0)
                flags &= ~ZEROPAD;

            /*
             * ``The result of converting a zero value with an
             * explicit precision of zero is no characters.''
             *	-- ANSI X3J11
             */
            cp = buf + BUF;
            if (_uquad != 0 || prec != 0)
            {
                /*
                 * Unsigned mod is hard, and unsigned mod
                 * by a constant is easier than that by
                 * a variable; hence this switch.
                 */
                switch (base)
                {
                case OCT:
                    do
                    {
                        *--cp = to_char(_uquad & 7);
                        _uquad >>= 3;
                    } while (_uquad);
                    /* handle octal leading 0 */
                    if (flags & ALT && *cp != '0')
                        *--cp = '0';
                    break;

                case DEC:
                    /* many numbers are 1 digit */
                    while (_uquad >= 10)
                    {
                        *--cp = to_char(_uquad % 10);
                        _uquad /= 10;
                    }
                    *--cp = to_char(_uquad);
                    break;

                case HEX:
                    do
                    {
                        *--cp = xdigs[_uquad & 15];
                        _uquad >>= 4;
                    } while (_uquad);
                    break;

                default:
                    cp = D_00139598;
                    size = strlen(cp);
                    goto skipsize;
                }
            }
            size = buf + BUF - cp;
        skipsize:
            break;
        default: /* "%?" prints ?, unless ? is NUL */
            if (ch == '\0')
                goto done;
            /* pretend it was %c with argument ch */
            cp = buf;
            *cp = ch;
            size = 1;
            sign = '\0';
            break;
        }

        /*
         * All reasonable formats wind up here.  At this point, `cp'
         * points to a string which (if not flags&LADJUST) should be
         * padded out to `width' places.  If flags&ZEROPAD, it should
         * first be prefixed by any sign or other prefix; otherwise,
         * it should be blank padded before the prefix is emitted.
         * After any left-hand padding and prefixing, emit zeroes
         * required by a decimal [diouxX] precision, then print the
         * string proper, then emit zeroes required by any leftover
         * floating precision; finally, if LADJUST, pad with blanks.
         *
         * Compute actual size, so we know how much to pad.
         * size excludes decimal prec; realsz includes it.
         */
        realsz = dprec > size ? dprec : size;
        if (sign)
            realsz++;
        else if (flags & HEXPREFIX)
            realsz += 2;

        /* right-adjusting blank padding */
        if ((flags & (LADJUST | ZEROPAD)) == 0)
            PAD(width - realsz, blanks);

        /* prefix */
        if (sign)
        {
            PRINT(&sign, 1);
        }
        else if (flags & HEXPREFIX)
        {
            ox[0] = '0';
            ox[1] = ch;
            PRINT(ox, 2);
        }

        /* right-adjusting zero padding */
        if ((flags & (LADJUST | ZEROPAD)) == ZEROPAD)
            PAD(width - realsz, zeroes);

        /* leading zeroes from decimal precision */
        PAD(dprec - size, zeroes);

        /* the string or number proper */
        if ((flags & FPT) == 0)
        {
            PRINT(cp, size);
        }
        else
        { /* glue together f_p fragments */
            if (ch >= 'f')
            { /* 'f' or 'g' */
                if (_double == 0)
                {
                    /* kludge for __dtoa irregularity */
                    PRINT(D_001395B8, 1);
                    if (expt < ndig || (flags & ALT) != 0)
                    {
                        PRINT(decimal_point, 1);
                        PAD(ndig - 1, zeroes);
                    }
                }
                else if (expt <= 0)
                {
                    PRINT(D_001395B8, 1);
                    PRINT(decimal_point, 1);
                    PAD(-expt, zeroes);
                    PRINT(cp, ndig);
                }
                else if (expt >= ndig)
                {
                    PRINT(cp, ndig);
                    PAD(expt - ndig, zeroes);
                    if (flags & ALT)
                        PRINT(D_001395C0, 1);
                }
                else
                {
                    PRINT(cp, expt);
                    cp += expt;
                    PRINT(D_001395C0, 1);
                    PRINT(cp, ndig - expt);
                }
            }
            else
            { /* 'e' or 'E' */
                if (ndig > 1 || flags & ALT)
                {
                    ox[0] = *cp++;
                    ox[1] = '.';
                    PRINT(ox, 2);
                    if (_double || flags & ALT == 0)
                    {
                        PRINT(cp, ndig - 1);
                    }
                    else /* 0.[0..] */
                        /* __dtoa irregularity */
                        PAD(ndig - 1, zeroes);
                }
                else /* XeYYY */
                    PRINT(cp, 1);
                PRINT(expstr, expsize);
            }
        }
        /* left-adjusting padding (always blank) */
        if (flags & LADJUST)
            PAD(width - realsz, blanks);

        /* finally, adjust ret */
        ret += width > realsz ? width : realsz;

        FLUSH(); /* copy out the I/O vectors */
    }
done:
    FLUSH();
error:
    return (__sferror(fp) ? EOF : ret);
    /* NOTREACHED */
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
