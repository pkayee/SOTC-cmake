#include "common.h"

struct tm
{
    s32 tm_sec;
    s32 tm_min;
    s32 tm_hour;
    s32 tm_mday;
    s32 tm_mon;
    s32 tm_year;
    s32 tm_wday;
    s32 tm_yday;
    s32 tm_isdst;
};

typedef struct
{
    s32 quot;
    s32 rem;
} div_t;

div_t div(s32 numer, s32 denom);

#define _SEC_IN_MINUTE 60
#define _SEC_IN_HOUR 3600
#define _SEC_IN_DAY 86400

extern s32 D_400493C8[]; /* DAYS_IN_MONTH */
extern s32 D_400493F8[]; /* _DAYS_BEFORE_MONTH */
#define DAYS_IN_MONTH D_400493C8
#define _DAYS_BEFORE_MONTH D_400493F8

#define _DAYS_IN_MONTH(x) ((x == 1) ? days_in_feb : DAYS_IN_MONTH[x])
#define _ISLEAP(y) (((y) % 4) == 0 && (((y) % 100) != 0 || (((y) + 1900) % 400) == 0))
#define _DAYS_IN_YEAR(year) (_ISLEAP(year) ? 366 : 365)

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/sdk/mktime", func_40041A98);
void func_40041A98(struct tm *tim_p)
{
    div_t res;
    s32 days_in_feb = 28;

    /* calculate time & date to account for out of range values */
    if (tim_p->tm_sec < 0 || tim_p->tm_sec > 59)
    {
        res = div(tim_p->tm_sec, 60);
        tim_p->tm_min += res.quot;
        if ((tim_p->tm_sec = res.rem) < 0)
        {
            tim_p->tm_sec += 60;
            --tim_p->tm_min;
        }
    }

    if (tim_p->tm_min < 0 || tim_p->tm_min > 59)
    {
        res = div(tim_p->tm_min, 60);
        tim_p->tm_hour += res.quot;
        if ((tim_p->tm_min = res.rem) < 0)
        {
            tim_p->tm_min += 60;
            --tim_p->tm_hour;
        }
    }

    if (tim_p->tm_hour < 0 || tim_p->tm_hour > 23)
    {
        res = div(tim_p->tm_hour, 24);
        tim_p->tm_mday += res.quot;
        if ((tim_p->tm_hour = res.rem) < 0)
        {
            tim_p->tm_hour += 24;
            --tim_p->tm_mday;
        }
    }

    if (tim_p->tm_mon > 11)
    {
        res = div(tim_p->tm_mon, 12);
        tim_p->tm_year += res.quot;
        if ((tim_p->tm_mon = res.rem) < 0)
        {
            tim_p->tm_mon += 12;
            --tim_p->tm_year;
        }
    }

    if (_DAYS_IN_YEAR(tim_p->tm_year) == 366)
    {
        days_in_feb = 29;
    }

    if (tim_p->tm_mday <= 0)
    {
        while (tim_p->tm_mday <= 0)
        {
            if (--tim_p->tm_mon == -1)
            {
                tim_p->tm_year--;
                tim_p->tm_mon = 11;
                days_in_feb = ((_DAYS_IN_YEAR(tim_p->tm_year) == 366) ? 29 : 28);
            }
            tim_p->tm_mday += _DAYS_IN_MONTH(tim_p->tm_mon);
        }
    }
    else
    {
        while (tim_p->tm_mday > _DAYS_IN_MONTH(tim_p->tm_mon))
        {
            tim_p->tm_mday -= _DAYS_IN_MONTH(tim_p->tm_mon);
            if (++tim_p->tm_mon == 12)
            {
                tim_p->tm_year++;
                tim_p->tm_mon = 0;
                days_in_feb = ((_DAYS_IN_YEAR(tim_p->tm_year) == 366) ? 29 : 28);
            }
        }
    }
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/sdk/mktime", mktime);
