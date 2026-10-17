#include "common.h"

/* NEARMISS-STUB __svfscanf */
#if 0 /* NEARMISS 73.97% cat=stack-frame sub=- | frame 0x2d0 vs 0x2f0, nread in t0 quad spill, float tail | attempts=1 */
int __svfscanf(FILE *fp, const char *fmt0, va_list ap)
{
    register unsigned char *fmt = (unsigned char *)fmt0;
    register int c;
    register size_t width;
    register char *p;
    register int n;
    register int flags;
    register char *p0;
    register int nread;
    int nassigned;
    register int base;
    unsigned long (*ccfn)();
    unsigned char ccltab[256];
    char buf[BUFSZ];

    nassigned = 0;
    nread = 0;
    base = 0;
    ccfn = NULL;
    for (;;)
    {
        c = *fmt++;
        if (c == 0)
        {
            return nassigned;
        }
        if (isspace(c))
        {
            while ((fp->_r > 0 || __srefill(fp) == 0) && isspace(*fp->_p))
            {
                nread++;
                fp->_r--;
                fp->_p++;
            }
            continue;
        }
        if (c != '%')
        {
            goto literal;
        }
        width = 0;
        flags = 0;
    again:
        c = *fmt++;
        switch (c)
        {
        case '%':
        literal:
            if (BufferEmpty(fp))
            {
                goto match_failure;
            }
            if (*fp->_p != c)
            {
                goto match_failure;
            }
            fp->_r--;
            fp->_p++;
            nread++;
            continue;

        case '*':
            flags |= SUPPRESS;
            goto again;
        case 'l':
            flags |= LONG;
            goto again;
        case 'L':
            flags |= LONGDBL;
            goto again;
        case 'h':
            flags |= SHORT;
            goto again;

        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            width = width * 10 + c - '0';
            goto again;

        case 'D':
            flags |= LONG;
        case 'd':
            c = CT_INT;
            ccfn = (unsigned long (*)())strtol;
            base = 10;
            break;

        case 'i':
            c = CT_INT;
            ccfn = (unsigned long (*)())strtol;
            base = 0;
            break;

        case 'O':
            flags |= LONG;
        case 'o':
            c = CT_INT;
            ccfn = (unsigned long (*)())strtoul;
            base = 8;
            break;

        case 'u':
            c = CT_INT;
            ccfn = (unsigned long (*)())strtoul;
            base = 10;
            break;

        case 'x':
        case 'X':
            flags |= PFXOK;
            c = CT_INT;
            ccfn = (unsigned long (*)())strtoul;
            base = 16;
            break;

        case 'E':
        case 'G':
        case 'e':
        case 'f':
        case 'g':
            c = CT_FLOAT;
            break;

        case 's':
            c = CT_STRING;
            break;

        case '[':
            fmt = __sccl((char *)ccltab, (char *)fmt);
            flags |= NOSKIP;
            c = CT_CCL;
            break;

        case 'c':
            flags |= NOSKIP;
            c = CT_CHAR;
            break;

        case 'p':
            flags |= POINTER | PFXOK;
            c = CT_INT;
            ccfn = (unsigned long (*)())strtoul;
            base = 16;
            break;

        case 'n':
            if (flags & SUPPRESS)
            {
                continue;
            }
            if (flags & SHORT)
            {
                *va_arg(ap, short *) = nread;
            }
            else if (flags & LONG)
            {
                *va_arg(ap, long *) = nread;
            }
            else
            {
                *va_arg(ap, int *) = nread;
            }
            continue;

        case '\0':
            return EOF;

        default:
            if (isupper(c))
            {
                flags |= LONG;
            }
            c = CT_INT;
            ccfn = (unsigned long (*)())strtol;
            base = 10;
            break;
        }

        if (BufferEmpty(fp))
        {
            goto input_failure;
        }

        if ((flags & NOSKIP) == 0)
        {
            while (isspace(*fp->_p))
            {
                nread++;
                if (--fp->_r > 0)
                {
                    fp->_p++;
                }
                else if (__srefill(fp))
                {
                    goto input_failure;
                }
            }
        }

        switch (c)
        {
        case CT_CHAR:
            if (width == 0)
            {
                width = 1;
            }
            if (flags & SUPPRESS)
            {
                size_t sum = 0;
                for (;;)
                {
                    if ((n = fp->_r) < width)
                    {
                        sum += n;
                        width -= n;
                        fp->_p += n;
                        if (__srefill(fp))
                        {
                            if (sum == 0)
                            {
                                goto input_failure;
                            }
                            break;
                        }
                    }
                    else
                    {
                        sum += width;
                        fp->_r -= width;
                        fp->_p += width;
                        break;
                    }
                }
                nread += sum;
            }
            else
            {
                size_t r = fread(va_arg(ap, char *), 1, width, fp);

                if (r == 0)
                {
                    goto input_failure;
                }
                nread += r;
            }
            nassigned++;
            break;

        case CT_CCL:
            if (width == 0)
            {
                width = (size_t)~0;
            }
            if (flags & SUPPRESS)
            {
                n = 0;
                while (ccltab[*fp->_p])
                {
                    n++;
                    fp->_r--;
                    fp->_p++;
                    if (--width == 0)
                    {
                        break;
                    }
                    if (BufferEmpty(fp))
                    {
                        break;
                    }
                }
                nread += n;
                if (n == 0)
                {
                    goto match_failure;
                }
            }
            else
            {
                p0 = p = va_arg(ap, char *);
                while (ccltab[*fp->_p])
                {
                    fp->_r--;
                    *p++ = *fp->_p++;
                    if (--width == 0)
                    {
                        break;
                    }
                    if (BufferEmpty(fp))
                    {
                        break;
                    }
                }
                nread += p - p0;
                if (p == p0)
                {
                    goto match_failure;
                }
                *p = 0;
                nassigned++;
            }
            break;

        case CT_STRING:
            if (width == 0)
            {
                width = (size_t)~0;
            }
            if (flags & SUPPRESS)
            {
                while (!isspace(*fp->_p))
                {
                    nread++;
                    if (--width == 0)
                    {
                        break;
                    }
                    if (BufferEmpty(fp))
                    {
                        break;
                    }
                }
            }
            else
            {
                p = va_arg(ap, char *);
                p0 = p;
                while (!isspace(*fp->_p))
                {
                    fp->_r--;
                    *p++ = *fp->_p++;
                    if (--width == 0)
                    {
                        break;
                    }
                    if (BufferEmpty(fp))
                    {
                        break;
                    }
                }
                nread += p - p0;
                *p = 0;
                nassigned++;
            }
            break;

        case CT_INT:
            if (--width > BUFSZ - 2)
            {
                width = BUFSZ - 2;
            }
            width++;
            flags |= SIGNOK | NDIGITS;
            for (p = buf; width; width--)
            {
                c = *fp->_p;
                switch (c)
                {
                case '0':
                    if (base == 0)
                    {
                        base = 8;
                        flags |= PFXOK;
                    }
                    flags &= ~(SIGNOK | PFXOK | NDIGITS);
                    goto ok;
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                    base = D_00139740[base];
                    flags &= ~(SIGNOK | PFXOK | NDIGITS);
                    goto ok;
                case '8':
                case '9':
                    base = D_00139740[base];
                    if (base <= 8)
                    {
                        break;
                    }
                    flags &= ~(SIGNOK | PFXOK | NDIGITS);
                    goto ok;
                case 'A':
                case 'B':
                case 'C':
                case 'D':
                case 'E':
                case 'F':
                case 'a':
                case 'b':
                case 'c':
                case 'd':
                case 'e':
                case 'f':
                    if (base <= 10)
                    {
                        break;
                    }
                    flags &= ~(SIGNOK | PFXOK | NDIGITS);
                    goto ok;
                case '+':
                case '-':
                    if (flags & SIGNOK)
                    {
                        flags &= ~SIGNOK;
                        goto ok;
                    }
                    break;
                case 'x':
                case 'X':
                    if ((flags & PFXOK) && p == buf + 1)
                    {
                        base = 16;
                        flags &= ~PFXOK;
                        goto ok;
                    }
                    break;
                }
                break;
            ok:
                *p++ = c;
                if (--fp->_r > 0)
                {
                    fp->_p++;
                }
                else if (__srefill(fp))
                {
                    break;
                }
            }
            if (flags & NDIGITS)
            {
                if (p > buf)
                {
                    ungetc(*(unsigned char *)--p, fp);
                }
                goto match_failure;
            }
            c = ((unsigned char *)p)[-1];
            if (c == 'x' || c == 'X')
            {
                --p;
                ungetc(c, fp);
            }
            if ((flags & SUPPRESS) == 0)
            {
                unsigned long res;

                *p = 0;
                res = (*ccfn)(buf, (char **)0, base);
                if (flags & POINTER)
                {
                    *va_arg(ap, void **) = (void *)res;
                }
                else if (flags & SHORT)
                {
                    *va_arg(ap, short *) = res;
                }
                else if (flags & LONG)
                {
                    *va_arg(ap, long *) = res;
                }
                else
                {
                    *va_arg(ap, int *) = res;
                }
                nassigned++;
            }
            nread += p - buf;
            break;

        case CT_FLOAT:
            if (width == 0 || width > BUFSZ - 1)
            {
                width = BUFSZ - 1;
            }
            flags |= SIGNOK | NDIGITS | DPTOK | EXPOK;
            for (p = buf; width; width--)
            {
                c = *fp->_p;
                switch (c)
                {
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    flags &= ~(SIGNOK | NDIGITS);
                    goto fok;
                case '+':
                case '-':
                    if (flags & SIGNOK)
                    {
                        flags &= ~SIGNOK;
                        goto fok;
                    }
                    break;
                case '.':
                    if (flags & DPTOK)
                    {
                        flags &= ~(SIGNOK | DPTOK);
                        goto fok;
                    }
                    break;
                case 'e':
                case 'E':
                    if ((flags & (NDIGITS | EXPOK)) == EXPOK)
                    {
                        flags = (flags & ~(EXPOK | DPTOK)) | SIGNOK | NDIGITS;
                        goto fok;
                    }
                    break;
                }
                break;
            fok:
                *p++ = c;
                if (--fp->_r > 0)
                {
                    fp->_p++;
                }
                else if (__srefill(fp))
                {
                    break;
                }
            }
            if (flags & NDIGITS)
            {
                if (p > buf)
                {
                    ungetc(*(unsigned char *)--p, fp);
                }
                goto match_failure;
            }
            c = ((unsigned char *)p)[-1];
            if (c == 'e' || c == 'E')
            {
                --p;
                ungetc(c, fp);
            }
            if ((flags & SUPPRESS) == 0)
            {
                double res;

                *p = 0;
                res = atof(buf);
                if (flags & (LONG | LONGDBL))
                {
                    *va_arg(ap, double *) = res;
                }
                else
                {
                    *va_arg(ap, float *) = res;
                }
                nassigned++;
            }
            nread += p - buf;
            break;
        }
    }
match_failure:
    return nassigned;
input_failure:
    return nassigned ? nassigned : EOF;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/vscanf", __svfscanf);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/vscanf", __sccl);
unsigned char *__sccl(char *tab, char *fmt)
{
    int c;
    int n;
    int v;
    char *p;

    c = *fmt++;
    if (c == '^')
    {
        v = 1;
        c = *fmt++;
    }
    else
    {
        v = 0;
    }

    n = 255;
    p = tab + 255;
    do
    {
        n--;
        *p-- = v;
    } while (n >= 0);

    if (c == 0)
    {
        return fmt - 1;
    }

    v = 1 - v;
    for (;;)
    {
        tab[c] = v;
    doswitch:
        n = *fmt++;
        switch (n)
        {
        case 0:
            return fmt - 1;
        case '-':
            n = *fmt;
            if (n == ']' || n < c)
            {
                c = '-';
                break;
            }
            fmt++;
            do
            {
                tab[++c] = v;
            } while (c < n);
            goto doswitch;
        case ']':
            return fmt;
        default:
            c = n;
            break;
        }
    }
}
