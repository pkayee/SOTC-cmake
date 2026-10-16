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

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/font", func_4002D888);

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

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/font", iosGetFontDataWithEUC);

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
