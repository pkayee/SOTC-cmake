#include "common.h"

struct _reent;

struct Bigint
{
    struct Bigint *next;
    int k;
    int maxwds;
    int sign;
    int wds;
    u32 x[1];
};

#define REENT_FREELIST(p) (*(struct Bigint ***)((u8 *)(p) + 0x4C))
#define REENT_P5S(p) (*(struct Bigint **)((u8 *)(p) + 0x48))

union mp_double
{
    double d;
    u32 L[2];
};

#define word0(x) ((x).L[1])
#define word1(x) ((x).L[0])

extern void *_calloc_r(struct _reent *ptr, u32 n, u32 size);
extern void *memcpy(void *d, const void *s, u32 n);
extern int fflush(void *fp);
extern int __mcmp(struct Bigint *a, struct Bigint *b);
extern struct Bigint *_Balloc(struct _reent *ptr, int k);
extern void _Bfree(struct _reent *ptr, struct Bigint *v);
extern struct Bigint *_i2b(struct _reent *ptr, int i);
extern struct Bigint *_multadd(struct _reent *ptr, struct Bigint *b, int m, int a);
extern struct Bigint *_multiply(struct _reent *ptr, struct Bigint *a, struct Bigint *b);
extern double _b2d(struct Bigint *a, int *e);
extern double dpdiv(double a, double b);
extern double dpmul(double a, double b);
extern double D_00139C60[];
extern int D_00139C4C[];

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/mprec", _Balloc);
struct Bigint *_Balloc(struct _reent *ptr, int k)
{
    int x;
    struct Bigint *rv;
    struct Bigint **fl;

    if (REENT_FREELIST(ptr) == NULL)
    {
        fl = _calloc_r(ptr, 4, 16);
        REENT_FREELIST(ptr) = fl;
        if (fl == NULL)
        {
            return NULL;
        }
    }
    if ((rv = REENT_FREELIST(ptr)[k]) != NULL)
    {
        REENT_FREELIST(ptr)[k] = rv->next;
    }
    else
    {
        x = 1 << k;
        rv = _calloc_r(ptr, 1, sizeof(struct Bigint) + (x - 1) * sizeof(u32));
        if (rv == NULL)
        {
            return NULL;
        }
        rv->k = k;
        rv->maxwds = x;
    }
    rv->wds = 0;
    rv->sign = 0;
    return rv;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/mprec", _Bfree);
void _Bfree(struct _reent *ptr, struct Bigint *v)
{
    if (v)
    {
        v->next = REENT_FREELIST(ptr)[v->k];
        REENT_FREELIST(ptr)[v->k] = v;
    }
}


//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/mprec", _multadd);
struct Bigint *_multadd(struct _reent *ptr, struct Bigint *b, int m, int a)
{
    int i;
    int wds;
    u32 *x;
    u32 xi;
    u32 y;
    u32 z;
    struct Bigint *b1;

    wds = b->wds;
    x = b->x;
    i = 0;
    do
    {
        xi = *x;
        y = (xi & 0xffff) * m + a;
        z = (xi >> 16) * m + (y >> 16);
        a = (int)(z >> 16);
        *x++ = (z << 16) + (y & 0xffff);
    } while (++i < wds);
    if (a)
    {
        if (wds >= b->maxwds)
        {
            b1 = _Balloc(ptr, b->k + 1);
            memcpy(&b1->sign, &b->sign, b->wds * 4 + 8);
            _Bfree(ptr, b);
            b = b1;
        }
        b->x[wds++] = a;
        b->wds = wds;
    }
    return b;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/mprec", _s2b);
struct Bigint *_s2b(struct _reent *ptr, const char *s, int nd0, int nd, u32 y9)
{
    struct Bigint *b;
    int i;
    int k;
    s32 x;
    s32 y;

    x = (nd + 8) / 9;
    for (k = 0, y = 1; x > y; y <<= 1, k++)
        ;
    b = _Balloc(ptr, k);
    b->x[0] = y9;
    b->wds = 1;

    i = 9;
    if (9 < nd0)
    {
        s += 9;
        do
        {
            b = _multadd(ptr, b, 10, *s++ - '0');
        } while (++i < nd0);
        s++;
    }
    else
    {
        s += 10;
    }
    for (; i < nd; i++)
    {
        b = _multadd(ptr, b, 10, *s++ - '0');
    }
    return b;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/mprec", _hi0bits);
int _hi0bits(u32 x)
{
    int k = 0;

    if (!(x & 0xffff0000))
    {
        k = 16;
        x <<= 16;
    }
    if (!(x & 0xff000000))
    {
        k += 8;
        x <<= 8;
    }
    if (!(x & 0xf0000000))
    {
        k += 4;
        x <<= 4;
    }
    if (!(x & 0xc0000000))
    {
        k += 2;
        x <<= 2;
    }
    if (!(x & 0x80000000))
    {
        k++;
        if (!(x & 0x40000000))
        {
            return 32;
        }
    }
    return k;
}


//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/mprec", _lo0bits);
int _lo0bits(u32 *y)
{
    u32 x;
    int k;

    x = *y;
    if (x & 7)
    {
        if (x & 1)
        {
            return 0;
        }
        if (x & 2)
        {
            *y = x >> 1;
            return 1;
        }
        *y = x >> 2;
        return 2;
    }
    k = 0;
    if (!(x & 0xffff))
    {
        k = 16;
        x >>= 16;
    }
    if (!(x & 0xff))
    {
        k += 8;
        x >>= 8;
    }
    if (!(x & 0xf))
    {
        k += 4;
        x >>= 4;
    }
    if (!(x & 3))
    {
        k += 2;
        x >>= 2;
    }
    if (!(x & 1))
    {
        k++;
        x >>= 1;
        if (!x & 1)
        {
            return 32;
        }
    }
    *y = x;
    return k;
}


//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/mprec", _i2b);
struct Bigint *_i2b(struct _reent *ptr, int i)
{
    struct Bigint *b;

    b = _Balloc(ptr, 1);
    b->x[0] = i;
    b->wds = 1;
    return b;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/mprec", _multiply);
struct Bigint *_multiply(struct _reent *ptr, struct Bigint *a, struct Bigint *b)
{
    struct Bigint *c;
    int k;
    int wa;
    int wb;
    int wc;
    u32 carry;
    u32 y;
    u32 z;
    u32 z2;
    u32 *x;
    u32 *xa;
    u32 *xae;
    u32 *xb;
    u32 *xbe;
    u32 *xc;
    u32 *xc0;
    u32 *xcb;

    if (a->wds < b->wds)
    {
        c = a;
        a = b;
        b = c;
    }
    wa = a->wds;
    wb = b->wds;
    wc = wa + wb;
    k = a->k;
    if (wc > a->maxwds)
    {
        k++;
    }
    c = _Balloc(ptr, k);
    xc0 = c->x;
    for (x = xc0, xa = xc0 + wc; x < xa; x++)
    {
        *x = 0;
    }
    xa = a->x;
    xae = xa + wa;
    xb = b->x;
    xbe = xb + wb;
    for (xcb = xc0; xb < xbe; xb++, xcb++)
    {
        if ((y = *xb & 0xffff))
        {
            x = xa;
            xc = xcb;
            carry = 0;
            do
            {
                z = (*x & 0xffff) * y + (*xc & 0xffff) + carry;
                carry = z >> 16;
                z2 = (*x++ >> 16) * y + (*xc >> 16) + carry;
                carry = z2 >> 16;
                ((u16 *)xc)[0] = z;
                ((u16 *)xc)[1] = z2;
                xc++;
            } while (x < xae);
            *xc = carry;
        }
        if ((y = *xb >> 16))
        {
            x = xa;
            xc = xcb;
            carry = 0;
            z2 = *xc;
            do
            {
                z = (*x & 0xffff) * y + (*xc >> 16) + carry;
                carry = z >> 16;
                ((u16 *)xc)[0] = z2;
                ((u16 *)xc)[1] = z;
                xc++;
                z2 = (*x++ >> 16) * y + (*xc & 0xffff) + carry;
                carry = z2 >> 16;
            } while (x < xae);
            *xc = z2;
        }
    }
    for (xc = xc0 + wc; wc > 0 && !*--xc; --wc)
        ;
    c->wds = wc;
    return c;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/mprec", _pow5mult);
struct Bigint *_pow5mult(struct _reent *ptr, struct Bigint *b, int k)
{
    int i;
    struct Bigint *p5;
    struct Bigint *p5n;
    struct Bigint *b1;

    if ((i = k & 3))
    {
        b = _multadd(ptr, b, D_00139C4C[i], 0);
    }
    if (!(k >>= 2))
    {
        return b;
    }
    if (!(p5 = REENT_P5S(ptr)))
    {
        p5 = REENT_P5S(ptr) = _i2b(ptr, 625);
        p5->next = NULL;
    }
    for (;;)
    {
        if (k & 1)
        {
            b1 = _multiply(ptr, b, p5);
            _Bfree(ptr, b);
            b = b1;
        }
        if (!(k >>= 1))
        {
            break;
        }
        if (!(p5n = p5->next))
        {
            p5n = p5->next = _multiply(ptr, p5, p5);
            p5n->next = NULL;
        }
        p5 = p5n;
    }
    return b;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/mprec", _lshift);
struct Bigint *_lshift(struct _reent *ptr, struct Bigint *b, int k)
{
    int i;
    int k1;
    int n;
    int n1;
    struct Bigint *b1;
    u32 *x;
    u32 *x1;
    u32 *xe;
    u32 z;

    n = k >> 5;
    k1 = b->k;
    n1 = n + b->wds + 1;
    for (i = b->maxwds; n1 > i; i <<= 1)
    {
        k1++;
    }
    b1 = _Balloc(ptr, k1);
    x1 = b1->x;
    for (i = 0; i < n; i++)
    {
        *x1++ = 0;
    }
    x = b->x;
    xe = x + b->wds;
    if (k &= 0x1f)
    {
        k1 = 32 - k;
        z = 0;
        do
        {
            *x1++ = (*x << k) | z;
            z = *x++ >> k1;
        } while (x < xe);
        if ((*x1 = z) != 0)
        {
            ++n1;
        }
    }
    else
    {
        do
        {
            *x1++ = *x++;
        } while (x < xe);
    }
    b1->wds = n1 - 1;
    _Bfree(ptr, b);
    return b1;
}

/* NEARMISS-STUB __mcmp */
#if 0 /* NEARMISS 97.88% cat=regalloc sub=- | sll v1 in place, b->x in v0 vs ours j in v1/xb in a4 | attempts=1 */
//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/mprec", __mcmp);
int __mcmp(struct Bigint *a, struct Bigint *b)
{
    u32 *xa;
    u32 *xa0;
    u32 *xb;
    int i;
    int j;

    i = a->wds - b->wds;
    if (i)
    {
        return i;
    }
    j = b->wds;
    xa0 = a->x;
    xa = a->x;
    xb = b->x;
    xa += j;
    xb += j;
    for (;;)
    {
        if (*--xa != *--xb)
        {
            return *xa < *xb ? -1 : 1;
        }
        if (xa <= xa0)
        {
            break;
        }
    }
    return 0;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/mprec", __mcmp);


//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/mprec", __mdiff);
struct Bigint *__mdiff(struct _reent *ptr, struct Bigint *a, struct Bigint *b)
{
    struct Bigint *c;
    int i;
    int wa;
    int wb;
    s32 borrow;
    s32 y;
    s32 z;
    u32 *xa;
    u32 *xae;
    u32 *xb;
    u32 *xbe;
    u32 *xc;

    i = __mcmp(a, b);
    if (i == 0)
    {
        c = _Balloc(ptr, 0);
        c->wds = 1;
        c->x[0] = 0;
        return c;
    }
    if (i < 0)
    {
        c = a;
        a = b;
        b = c;
        i = 1;
    }
    else
    {
        i = 0;
    }
    c = _Balloc(ptr, a->k);
    xa = a->x;
    xb = b->x;
    c->sign = i;
    xc = c->x;
    borrow = 0;
    wa = a->wds;
    wb = b->wds;
    xae = xa + wa;
    xbe = xb + wb;
    do
    {
        y = (*xa & 0xffff) - (*xb & 0xffff) + borrow;
        borrow = y >> 16;
        z = (*xa++ >> 16) - (*xb++ >> 16) + borrow;
        borrow = z >> 16;
        ((u16 *)xc)[0] = y;
        ((u16 *)xc)[1] = z;
        xc++;
    } while (xb < xbe);
    if (xa < xae)
    {
        do
        {
            y = (*xa & 0xffff) + borrow;
            borrow = y >> 16;
            z = (*xa++ >> 16) + borrow;
            borrow = z >> 16;
            ((u16 *)xc)[0] = y;
            ((u16 *)xc)[1] = z;
            xc++;
        } while (xa < xae);
    }
    while (!*--xc)
    {
        wa--;
    }
    c->wds = wa;
    return c;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/mprec", _ulp);
double _ulp(double x)
{
    union mp_double xu;
    union mp_double a;
    int L;

    xu.d = x;
    L = (word0(xu) & 0x7ff00000) - 0x3400000;
    if (L > 0)
    {
        word0(a) = L;
        word1(a) = 0;
    }
    else
    {
        L = -L >> 20;
        if (L < 20)
        {
            word0(a) = 0x80000 >> L;
            word1(a) = 0;
        }
        else
        {
            word0(a) = 0;
            L -= 20;
            word1(a) = L >= 31 ? 1 : 1 << (31 - L);
        }
    }
    return a.d;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/mprec", _b2d);
double _b2d(struct Bigint *a, int *e)
{
    u32 *xa;
    u32 *xa0;
    u32 w;
    u32 y;
    u32 z;
    int k;
    union mp_double d;

    xa0 = a->x;
    xa = xa0 + a->wds;
    y = *--xa;
    k = _hi0bits(y);
    *e = 32 - k;
    if (k < 11)
    {
        word0(d) = 0x3FF00000 | (y >> (11 - k));
        w = xa > xa0 ? *--xa : 0;
        word1(d) = (y << (21 + k)) | (w >> (11 - k));
        goto ret_d;
    }
    z = xa > xa0 ? *--xa : 0;
    k -= 11;
    if (k)
    {
        word0(d) = 0x3FF00000 | (y << k) | (z >> (32 - k));
        y = xa > xa0 ? *--xa : 0;
        word1(d) = (z << k) | (y >> (32 - k));
    }
    else
    {
        word0(d) = 0x3FF00000 | y;
        word1(d) = z;
    }
ret_d:
    return d.d;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/mprec", _d2b);
struct Bigint *_d2b(struct _reent *ptr, double _d, int *e, int *bits)
{
    struct Bigint *b;
    int de;
    int k;
    u32 *x;
    u32 y;
    u32 z;
    int i;
    union mp_double d;

    d.d = _d;
    b = _Balloc(ptr, 1);
    x = b->x;

    z = word0(d) & 0xFFFFF;
    word0(d) &= 0x7fffffff;
    de = (int)(word0(d) >> 20);
    if (de)
    {
        z |= 0x100000;
    }

    if (word1(d))
    {
        y = word1(d);
        if ((k = _lo0bits(&y)))
        {
            x[0] = y | (z << (32 - k));
            z >>= k;
        }
        else
        {
            x[0] = y;
        }
        i = b->wds = (x[1] = z) ? 2 : 1;
    }
    else
    {
        k = _lo0bits(&z);
        x[0] = z;
        i = b->wds = 1;
        k += 32;
    }
    if (de)
    {
        *e = de - 1023 - 52 + k;
        *bits = 53 - k;
    }
    else
    {
        *e = de - 1023 - 52 + 1 + k;
        *bits = 32 * i - _hi0bits(x[i - 1]);
    }
    return b;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/mprec", _ratio);
double _ratio(struct Bigint *a, struct Bigint *b)
{
    union mp_double da;
    union mp_double db;
    int k;
    int ka;
    int kb;

    da.d = _b2d(a, &ka);
    db.d = _b2d(b, &kb);
    k = ka - kb + 32 * (a->wds - b->wds);
    if (k > 0)
    {
        word0(da) += k * 0x100000;
    }
    else
    {
        k = -k;
        word0(db) += k * 0x100000;
    }
    return dpdiv(da.d, db.d);
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/mprec", _mprec_log10);
double _mprec_log10(int dig)
{
    double v = 1.0;

    if (dig < 24)
    {
        return D_00139C60[dig];
    }
    if (dig > 0)
    {
        do
        {
            dig--;
            v = dpmul(v, 10.0);
        } while (dig > 0);
    }
    return v;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/mprec", func_0012F900);
int func_0012F900(void *fp)
{
    if ((*(u16 *)((u8 *)fp + 0xC) & 9) == 9)
    {
        return fflush(fp);
    }
    return 0;
}
