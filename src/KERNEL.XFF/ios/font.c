#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    u8 *data;
    s32 unkC;
    s32 w;
    s32 h;
    s32 unk18;
    s32 unk1C;
} FontInfo;

extern FontInfo D_400F5BF8[];
extern s32 D_40045C90[];

s32 func_4002D888(s32);
int strlen(const char *);

static inline s32 JisToId(s32 jis) {
    return (jis >> 8) * 94 + (jis & 0xFF) - 0xC3F;
}

static inline s32 SjisToJis(s32 sjis) {
    u64 c1 = (sjis >> 8) & 0xFF;
    u64 c2 = sjis & 0xFF;

    if (c1 - 0x81 < 0x1F) {
        c1 -= 0x81;
    } else if (c1 - 0xE0 < 0x10) {
        c1 -= 0xC1;
    }
    c1 <<= 1;
    if (c2 - 0x40 < 0x3F) {
        c2 -= 0x40;
    } else if (c2 - 0x80 < 0x1F) {
        c2 -= 0x41;
    } else if (c2 - 0x9F < 0x5E) {
        c2 -= 0x9F;
        c1++;
    }
    return ((c1 + 1) << 8) + c2 + 0x2021;
}

/* NEARMISS-STUB func_4002D888 */
#if 0 /* NEARMISS 61.0% cat=cse-hoist sub=- | D_400F5BEC held in a4 vs t3, BF0 hoisting differs | attempts=1 */
extern s32 D_400F5BE8;
extern s32 D_400F5BEC;
extern s32 D_400F5BF0;
s32 func_4002D888(s32 arg)
{
    s32 c;
    s32 n;
    s32 t;
    s32 orig;
    s32 count;

    D_400F5BEC = 0;
    D_400F5BE8 = arg >> 8;
    c = arg & 0xFF;
    count = 0;
    do
    {
        if (c < 0x80)
        {
            D_400F5BEC = (D_400F5BEC << 8) | c;
        }
        else if ((u32)(c - 0xA1) < 0x5E)
        {
            orig = D_400F5BE8;
            n = orig & 0xFF;
            D_400F5BE8 = orig >> 8;
            if (n == 0)
            {
                D_400F5BEC = (D_400F5BEC << 8) | c;
                return D_400F5BEC;
            }
            if ((u32)(n - 0xA1) < 0x5E)
            {
                c &= 0x7F;
                t = n & 0x7F;
                if (c & 1)
                {
                    t += 0x1F;
                    c = (c >> 1) + 0x71;
                    if (t >= 0x7F)
                    {
                        t = (t + 1) & 0xFF;
                    }
                }
                else
                {
                    t = (t + 0x7E) & 0xFF;
                    c = (c >> 1) + 0x70;
                }
                if (c >= 0xA0)
                {
                    c = (c + 0x40) & 0xFF;
                }
                c &= 0xFF;
                D_400F5BF0 = t;
                D_400F5BEC = (((D_400F5BEC << 8) | c) << 8) | t;
            }
            else
            {
                D_400F5BEC = (((D_400F5BEC << 8) | c) << 8) | n;
            }
        }
        else if (c == 0x8E)
        {
            orig = D_400F5BE8;
            n = orig & 0xFF;
            D_400F5BE8 = orig >> 8;
            if (n == 0)
            {
                return D_400F5BEC;
            }
            D_400F5BEC = (D_400F5BEC << 8) | n;
        }
        else if (c == 0x8F)
        {
            orig = D_400F5BE8;
            n = orig & 0xFF;
            D_400F5BE8 = orig >> 8;
            if (n == 0)
            {
                return D_400F5BEC;
            }
            D_400F5BE8 = orig >> 16;
            D_400F5BEC = (D_400F5BEC << 8) | n;
            n = (orig >> 8) & 0xFF;
            if (n == 0)
            {
                return D_400F5BEC;
            }
            D_400F5BEC = (D_400F5BEC << 8) | n;
        }
        else
        {
            D_400F5BEC = (D_400F5BEC << 8) | c;
        }
        c = D_400F5BE8 & 0xFF;
        D_400F5BE8 >>= 8;
        count++;
    } while (c != 0 && count < 2);
    return D_400F5BEC;
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/font", func_4002D888);

/* NEARMISS-STUB iosConvertStringSJIStoEUC */
#if 0 /* NEARMISS 56.0% cat=regalloc sub=- | store-motion preload lbu, c2/lo share reg, c1<<1 sched | attempts=1 */
s32 iosConvertStringSJIStoEUC(u8 *dst, u8 *src)
{
    s32 len = strlen(src);
    s32 i = 0;
    u8 buf[2];
    s32 c;
    s32 c1;
    s32 c2;
    s32 hi;
    s32 lo;

    buf[1] = 0;
    if (len > 0)
    {
        do
        {
            c = *(s8 *)src++;
            i++;
            c1 = c & 0xFF;
            if ((c1 << 24) >= 0)
            {
                *dst = c1;
            }
            else if ((u8)(c1 + 0x5F) < 0x3F)
            {
                *dst++ = 0x8E;
                *dst = c1;
            }
            else
            {
                c2 = *(s8 *)src++;
                i++;
                if ((u8)c2 < 0x9F)
                {
                    hi = ((u8)(c1 << 1) < 0x3F) ? (c1 << 1) - 0x61 : (c1 << 1) + 0x1F;
                    lo = ((u8)c2 < 0x7F) ? c2 + 0x61 : c2 + 0x60;
                }
                else
                {
                    hi = ((u8)(c1 << 1) < 0x3F) ? (c1 << 1) - 0x60 : (c1 << 1) + 0x20;
                    lo = c2 + 2;
                }
                buf[0] = hi;
                buf[1] = lo;
                *dst++ = hi;
                *dst = lo;
            }
            dst++;
        } while (i < len);
    }
    *dst = 0;
    return len >> 1;
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/font", iosConvertStringSJIStoEUC);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/font", iosConvertStringEUCtoSJIS);
s32 iosConvertStringEUCtoSJIS(u8 *dst, u8 *src) {
    s32 i = 0;
    s32 len = strlen(src);

    if (len > 0) {
        u8 *p = dst;
        do {
            u8 *s = src + i;
            if ((u8)(s[0] + 0x5F) < 0x5E) {
                u16 sjis;
                i++;
                sjis = func_4002D888(s[0] | (s[1] << 8));
                p[1] = sjis;
                p[0] = sjis >> 8;
                p++;
            } else {
                *p = s[0];
            }
            i++;
            p++;
        } while (i < len);
    }
    dst[len] = 0;
    return len / 2;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/font", iosConvertStringEUCtoID);
s32 iosConvertStringEUCtoID(u8 *dst, u8 *src) {
    s32 i = 0;
    s32 len = strlen(src);

    for (; i < len; i += 2) {
        *(u16 *)(dst + i) = JisToId(SjisToJis(func_4002D888(*(u16 *)(src + i))));
    }
    dst[len] = 0;
    return len / 2;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/font", iosGetDataSizeOfFont);
s32 iosGetDataSizeOfFont(s32 id) {
    return D_40045C90[id];
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/font", iosGetFontDataWithID);
u8 *iosGetFontDataWithID(FontInfo *out, s32 idx, s32 font) {
    FontInfo *f = &D_400F5BF8[font];
    u8 *ret = f->data + idx * (f->w * f->h);
    if (out != NULL) {
        *out = *f;
    }
    return ret;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/font", iosGetFontDataWithJIS);
u8 *iosGetFontDataWithJIS(FontInfo *out, s32 jis, s32 font) {
    FontInfo *f = &D_400F5BF8[font];
    u8 *ret = f->data + JisToId(jis) * (f->w * f->h);
    if (out != NULL) {
        *out = *f;
    }
    return ret;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/font", iosGetFontDataWithSJIS);
u8 *iosGetFontDataWithSJIS(FontInfo *out, s32 sjis, s32 font) {
    s32 jis = SjisToJis(sjis);
    FontInfo *f = &D_400F5BF8[font];
    u8 *ret = f->data + JisToId(jis) * (f->w * f->h);
    if (out != NULL) {
        *out = *f;
    }
    return ret;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/font", iosGetFontDataWithEUC);
u8 *iosGetFontDataWithEUC(FontInfo *out, s32 euc, s32 font) {
    s32 jis = SjisToJis(func_4002D888(euc));
    FontInfo *f = &D_400F5BF8[font];
    u8 *ret = f->data + JisToId(jis) * (f->w * f->h);
    if (out != NULL) {
        *out = *f;
    }
    return ret;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/font", iosGetFontIDWithJIS);
s32 iosGetFontIDWithJIS(s32 jis) {
    return (jis >> 8) * 94 + (jis & 0xFF) - 0xC3F;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/font", iosGetFontIDWithSJIS);
s32 iosGetFontIDWithSJIS(s32 sjis) {
    return JisToId(SjisToJis(sjis));
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/font", iosGetFontIDWithEUC);
s32 iosGetFontIDWithEUC(s32 euc) {
    return JisToId(SjisToJis(func_4002D888(euc)));
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/font", iosEntryLocaleFontNoLoad);
s32 iosEntryLocaleFontNoLoad(s32 data, FontInfo *info) {
    D_400F5BF8[0] = *info;
    D_400F5BF8[0].data = (u8 *)data;
    return data;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/font", iosGetFontInfo);
void iosGetFontInfo(FontInfo *out, s32 font) {
    *out = D_400F5BF8[font];
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/font", iosGet2ByteCharCode);
s32 iosGet2ByteCharCode(u8 *p) {
    return (p[1] << 8) | p[0];
}
