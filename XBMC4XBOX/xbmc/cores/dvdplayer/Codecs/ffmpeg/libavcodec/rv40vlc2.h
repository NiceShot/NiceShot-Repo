/*
 * RealVideo 4 decoder
 * copyright (c) 2007 Konstantin Shishkov
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

/**
 * @file
 * RV40 VLC tables used for macroblock information decoding
 */

#ifndef AVCODEC_RV40VLC2_H
#define AVCODEC_RV40VLC2_H

#include <stdint.h>

/**
 * codes used for the first four block types
 */
//@{
#define AIC_TOP_BITS  8
#define AIC_TOP_SIZE 16
static const uint8_t rv40_aic_top_vlc_codes[AIC_TOP_SIZE] = {
 0x01, 0x05, 0x01, 0x00, 0x03, 0x3D, 0x1D, 0x02,
 0x04, 0x3C, 0x3F, 0x1C, 0x0D, 0x3E, 0x0C, 0x01
};

static const uint8_t rv40_aic_top_vlc_bits[AIC_TOP_SIZE] = {
 1, 4, 5, 5, 5, 7, 6, 5, 4, 7, 7, 6, 5, 7, 5, 3
};
//@}

/**
 * codes used for determining a pair of block types
 */
//@{
#define AIC_MODE2_NUM  20
#define AIC_MODE2_SIZE 81
#define AIC_MODE2_BITS  9

static const uint16_t aic_mode2_vlc_codes[AIC_MODE2_NUM][AIC_MODE2_SIZE] = {
{ 0x0001, 0x0001, 0x0005, 0x01F5, 0x0011, 0x0049, 0x0000, 0x0048, 0x004B,
  0x0035, 0x0003, 0x0034, 0x03C9, 0x01F4, 0x00C9, 0x004A, 0x0FD9, 0x03C8,
  0x0010, 0x0037, 0x0001, 0x00C8, 0x0075, 0x01F7, 0x00CB, 0x0074, 0x0002,
  0x01F6, 0x00CA, 0x01F1, 0x01F0, 0x1F81, 0x07F9, 0x1F80, 0x1F83, 0x07F8,
  0x0077, 0x00F5, 0x0036, 0x07FB, 0x0076, 0x1F82, 0x00F4, 0x00F7, 0x07FA,
  0x0071, 0x00F6, 0x03CB, 0x03CA, 0x0FD8, 0x00F1, 0x03F5, 0x1F8D, 0x07E5,
  0x0013, 0x0031, 0x00F0, 0x0FDB, 0x00F3, 0x07E4, 0x0030, 0x01F3, 0x07E7,
  0x03F4, 0x07E6, 0x0070, 0x3F19, 0x01F2, 0x3F18, 0x0FDA, 0x0033, 0x07E1,
  0x01FD, 0x01FC, 0x0073, 0x01FF, 0x0FC5, 0x0FC4, 0x0FC7, 0x03F7, 0x0072, },
{ 0x0005, 0x0005, 0x0005, 0x0079, 0x0005, 0x000D, 0x001D, 0x0078, 0x0069,
  0x0004, 0x0001, 0x0007, 0x0068, 0x001C, 0x001F, 0x0004, 0x006B, 0x000C,
  0x0004, 0x001E, 0x0006, 0x006A, 0x0015, 0x000F, 0x0014, 0x0017, 0x0007,
  0x0016, 0x000E, 0x0011, 0x0009, 0x00D1, 0x00D0, 0x0181, 0x00D3, 0x007B,
  0x0010, 0x0013, 0x0004, 0x00D2, 0x0007, 0x0319, 0x0008, 0x007A, 0x00DD,
  0x0019, 0x0006, 0x000B, 0x0065, 0x00DC, 0x0012, 0x0064, 0x0180, 0x00DF,
  0x0006, 0x0018, 0x0001, 0x00DE, 0x001D, 0x00D9, 0x001B, 0x0067, 0x000A,
  0x00D8, 0x00DB, 0x001C, 0x0318, 0x00DA, 0x0635, 0x0183, 0x0000, 0x00C5,
  0x0066, 0x0061, 0x0035, 0x00C4, 0x0182, 0x0634, 0x031B, 0x00C7, 0x001F, },
{ 0x0005, 0x0001, 0x001D, 0x01C1, 0x0035, 0x00F1, 0x006D, 0x00F0, 0x0049,
  0x0000, 0x0004, 0x0003, 0x00F3, 0x0048, 0x0034, 0x006C, 0x01C0, 0x01C3,
  0x0007, 0x0006, 0x0001, 0x006F, 0x0002, 0x004B, 0x006E, 0x001C, 0x0005,
  0x0069, 0x0068, 0x006B, 0x0037, 0x01C2, 0x00F2, 0x0395, 0x01CD, 0x00FD,
  0x006A, 0x0036, 0x0015, 0x01CC, 0x0014, 0x0394, 0x004A, 0x00FC, 0x00FF,
  0x0017, 0x0031, 0x00FE, 0x01CF, 0x0397, 0x00F9, 0x01CE, 0x0725, 0x0396,
  0x0016, 0x0030, 0x0075, 0x0724, 0x00F8, 0x0727, 0x0033, 0x0391, 0x0390,
  0x0011, 0x0032, 0x001F, 0x00FB, 0x0074, 0x0726, 0x00FA, 0x001E, 0x0077,
  0x0019, 0x0018, 0x0004, 0x0010, 0x003D, 0x0076, 0x0071, 0x0013, 0x0001, },
{ 0x000D, 0x0019, 0x0011, 0x0015, 0x0061, 0x0019, 0x0014, 0x01AD, 0x0060,
  0x0018, 0x0001, 0x0005, 0x001B, 0x0010, 0x0019, 0x0005, 0x0017, 0x0018,
  0x0016, 0x0004, 0x0004, 0x0013, 0x000C, 0x0012, 0x001A, 0x0018, 0x0005,
  0x000F, 0x001B, 0x0004, 0x001D, 0x0011, 0x001C, 0x0010, 0x000E, 0x001B,
  0x0013, 0x001F, 0x001A, 0x0029, 0x0005, 0x0063, 0x001E, 0x0009, 0x0062,
  0x0008, 0x0007, 0x0007, 0x0019, 0x0004, 0x001A, 0x0018, 0x006D, 0x0007,
  0x001B, 0x0007, 0x001A, 0x006C, 0x0006, 0x0012, 0x0005, 0x006F, 0x000B,
  0x006E, 0x0069, 0x001D, 0x0359, 0x0028, 0x002B, 0x002A, 0x001C, 0x00D5,
  0x0358, 0x001F, 0x0001, 0x001E, 0x0068, 0x00D4, 0x00D7, 0x0019, 0x0000, },
{ 0x00B9, 0x0061, 0x0060, 0x00B8, 0x02B5, 0x01AD, 0x00BB, 0x0AF5, 0x0151,
  0x0001, 0x0001, 0x0005, 0x0000, 0x0003, 0x0005, 0x0004, 0x0063, 0x0025,
  0x00BA, 0x0004, 0x0007, 0x0062, 0x00A5, 0x0024, 0x006D, 0x0002, 0x006C,
  0x02B4, 0x000D, 0x006F, 0x0027, 0x00A4, 0x0026, 0x01AC, 0x0150, 0x01AF,
  0x01AE, 0x0021, 0x006E, 0x02B7, 0x0020, 0x0153, 0x0023, 0x00A7, 0x0152,
  0x00A6, 0x0006, 0x000C, 0x0022, 0x01A9, 0x0019, 0x002D, 0x02B6, 0x01A8,
  0x000F, 0x0007, 0x000E, 0x00A1, 0x0069, 0x002C, 0x0001, 0x01AB, 0x00A0,
  0x02B1, 0x00A3, 0x002F, 0x0AF4, 0x02B0, 0x0AF7, 0x02B3, 0x0068, 0x015D,
  0x0AF6, 0x01AA, 0x0055, 0x015C, 0x02B2, 0x0579, 0x0578, 0x015F, 0x00A2, },
{ 0x0905, 0x013D, 0x013C, 0x0904, 0x121D, 0x049D, 0x049C, 0x243D, 0x0907,
  0x00ED, 0x0001, 0x0015, 0x0041, 0x013F, 0x0031, 0x0014, 0x025D, 0x025C,
  0x013E, 0x000D, 0x0000, 0x0040, 0x0139, 0x0043, 0x0030, 0x0017, 0x0033,
  0x0906, 0x0032, 0x0042, 0x00EC, 0x025F, 0x00EF, 0x025E, 0x049F, 0x0138,
  0x0901, 0x013B, 0x0259, 0x121C, 0x049E, 0x0900, 0x0258, 0x243C, 0x121F,
  0x0903, 0x003D, 0x00EE, 0x025B, 0x025A, 0x004D, 0x013A, 0x0902, 0x0245,
  0x00E9, 0x0016, 0x00E8, 0x0499, 0x0125, 0x0244, 0x004C, 0x0498, 0x090D,
  0x00EB, 0x003C, 0x0011, 0x049B, 0x049A, 0x0485, 0x00EA, 0x003F, 0x0124,
  0x090C, 0x003E, 0x0039, 0x0095, 0x0247, 0x0246, 0x0484, 0x0094, 0x0038, },
{ 0x0F09, 0x00CD, 0x01FD, 0x0791, 0x1E6D, 0x0790, 0x03D9, 0x3CD1, 0x3CD0,
  0x0075, 0x0001, 0x0001, 0x0035, 0x00CC, 0x0011, 0x0000, 0x03D8, 0x01FC,
  0x03DB, 0x0010, 0x0003, 0x00CF, 0x03DA, 0x00CE, 0x0074, 0x0034, 0x0077,
  0x0793, 0x0013, 0x0076, 0x0071, 0x03C5, 0x0070, 0x01FF, 0x0792, 0x01FE,
  0x01F9, 0x0037, 0x00C9, 0x0F08, 0x01F8, 0x03C4, 0x00C8, 0x0F0B, 0x079D,
  0x03C7, 0x0001, 0x0012, 0x0073, 0x00CB, 0x0005, 0x0036, 0x03C6, 0x0072,
  0x007D, 0x0002, 0x00CA, 0x079C, 0x01FB, 0x00F5, 0x0031, 0x079F, 0x0F0A,
  0x0F35, 0x079E, 0x01FA, 0x1E6C, 0x1E6F, 0x3CD3, 0x0799, 0x03C1, 0x1E6E,
  0x3CD2, 0x0030, 0x00F4, 0x007C, 0x03C0, 0x03C3, 0x0798, 0x01E5, 0x00F7, },
{ 0x01A5, 0x0001, 0x001D, 0x0021, 0x00A1, 0x000D, 0x0061, 0x06B9, 0x00A0,
  0x0060, 0x0001, 0x0005, 0x000C, 0x0020, 0x001C, 0x0004, 0x01A4, 0x01A7,
  0x00A3, 0x001F, 0x001E, 0x0023, 0x0022, 0x002D, 0x002C, 0x0063, 0x0062,
  0x1A81, 0x01A6, 0x01A1, 0x06B8, 0x06BB, 0x00A2, 0x06BA, 0x0D59, 0x06A5,
  0x01A0, 0x000F, 0x006D, 0x06A4, 0x002F, 0x00AD, 0x006C, 0x06A7, 0x00AC,
  0x0D58, 0x000E, 0x01A3, 0x00AF, 0x00AE, 0x006F, 0x01A2, 0x0D5B, 0x00A9,
  0x0019, 0x0001, 0x0009, 0x00A8, 0x006E, 0x002E, 0x0000, 0x01AD, 0x00AB,
  0x00AA, 0x0355, 0x0029, 0x1A80, 0x1A83, 0x1A82, 0x0354, 0x01AC, 0x0D5A,
  0x1A8D, 0x01AF, 0x0357, 0x0D45, 0x0D44, 0x0D47, 0x1A8C, 0x06A6, 0x06A1, },
{ 0x0001, 0x0011, 0x0005, 0x0775, 0x00F9, 0x00F8, 0x0031, 0x0030, 0x0049,
  0x00FB, 0x0010, 0x0033, 0x0EC9, 0x038D, 0x038C, 0x00FA, 0x038F, 0x0774,
  0x0048, 0x0032, 0x0000, 0x01D5, 0x00E5, 0x038E, 0x00E4, 0x0013, 0x000D,
  0x0389, 0x0777, 0x0388, 0x038B, 0x1DF9, 0x0EC8, 0x3BC9, 0x1DF8, 0x038A,
  0x03B5, 0x0776, 0x00E7, 0x3BC8, 0x01D4, 0x3BCB, 0x0ECB, 0x0771, 0x0ECA,
  0x01D7, 0x03B4, 0x01D6, 0x1DFB, 0x0EF5, 0x0770, 0x0EF4, 0x3BCA, 0x0773,
  0x00E6, 0x03B7, 0x004B, 0x1DFA, 0x03B6, 0x0EF7, 0x00E1, 0x0EF6, 0x0EF1,
  0x03B1, 0x01D1, 0x003D, 0x0EF0, 0x0772, 0x077D, 0x077C, 0x003C, 0x01D0,
  0x03B0, 0x01D3, 0x003F, 0x03B3, 0x01D2, 0x0EF3, 0x077F, 0x00E0, 0x004A, },
{ 0x0015, 0x0049, 0x0014, 0x07D1, 0x03FD, 0x03FC, 0x01C1, 0x01C0, 0x00F1,
  0x0017, 0x0001, 0x0001, 0x01C3, 0x0048, 0x004B, 0x0016, 0x0031, 0x01C2,
  0x004A, 0x0011, 0x0000, 0x01CD, 0x00F0, 0x01CC, 0x0075, 0x0010, 0x000D,
  0x03FF, 0x01CF, 0x01CE, 0x07D0, 0x0F81, 0x07D3, 0x1F1D, 0x0F80, 0x07D2,
  0x01C9, 0x03FE, 0x0074, 0x07DD, 0x00F3, 0x1F1C, 0x07DC, 0x03F9, 0x07DF,
  0x00F2, 0x00FD, 0x0077, 0x07DE, 0x07D9, 0x01C8, 0x07D8, 0x0F83, 0x03F8,
  0x0030, 0x0076, 0x0013, 0x0F82, 0x00FC, 0x03FB, 0x0033, 0x03FA, 0x03E5,
  0x03E4, 0x01CB, 0x0032, 0x1F1F, 0x03E7, 0x07DB, 0x07DA, 0x003D, 0x01CA,
  0x07C5, 0x03E6, 0x0071, 0x0F8D, 0x07C4, 0x1F1E, 0x0F8C, 0x03E1, 0x01F5, },
{ 0x0019, 0x0065, 0x0018, 0x0351, 0x0350, 0x0353, 0x0021, 0x0020, 0x0064,
  0x001D, 0x0005, 0x0005, 0x01A5, 0x0023, 0x0067, 0x0005, 0x0066, 0x0022,
  0x001B, 0x0004, 0x0001, 0x0004, 0x001C, 0x0061, 0x001A, 0x0005, 0x0004,
  0x0007, 0x002D, 0x0006, 0x002C, 0x01A4, 0x002F, 0x0352, 0x035D, 0x0060,
  0x0001, 0x002E, 0x001F, 0x035C, 0x0000, 0x06B1, 0x01A7, 0x0029, 0x01A6,
  0x0028, 0x0063, 0x0062, 0x035F, 0x01A1, 0x002B, 0x06B0, 0x06B3, 0x01A0,
  0x0003, 0x006D, 0x001E, 0x035E, 0x006C, 0x06B2, 0x0002, 0x01A3, 0x01A2,
  0x000D, 0x0005, 0x0007, 0x01AD, 0x006F, 0x002A, 0x006E, 0x0004, 0x0004,
  0x000C, 0x0007, 0x0006, 0x000F, 0x000E, 0x00D5, 0x0009, 0x0006, 0x0007, },
{ 0x0065, 0x0181, 0x0064, 0x36C9, 0x06D5, 0x0DB5, 0x0379, 0x0180, 0x0183,
  0x00D5, 0x001D, 0x001C, 0x0DB4, 0x0182, 0x0378, 0x00D4, 0x00D7, 0x06D4,
  0x0067, 0x001F, 0x0001, 0x00D6, 0x00D1, 0x018D, 0x0066, 0x0001, 0x0000,
  0x037B, 0x06D7, 0x037A, 0x0DB7, 0x36C8, 0x06D6, 0x0DB6, 0x1B79, 0x0DB1,
  0x018C, 0x0365, 0x00D0, 0x1B78, 0x00D3, 0x1B7B, 0x0364, 0x06D1, 0x06D0,
  0x018F, 0x018E, 0x00D2, 0x36CB, 0x0367, 0x0366, 0x06D3, 0x0DB0, 0x06D2,
  0x0361, 0x06DD, 0x0189, 0x36CA, 0x0360, 0x36F5, 0x0188, 0x0DB3, 0x36F4,
  0x0009, 0x0008, 0x0005, 0x06DC, 0x00DD, 0x018B, 0x00DC, 0x0004, 0x000B,
  0x018A, 0x0061, 0x0003, 0x0363, 0x00DF, 0x06DF, 0x0362, 0x000A, 0x001E, },
{ 0x001D, 0x0061, 0x000D, 0x0D55, 0x06B9, 0x06B8, 0x01A5, 0x0021, 0x0020,
  0x0023, 0x000C, 0x0060, 0x0D54, 0x00AD, 0x00AC, 0x0022, 0x00AF, 0x06BB,
  0x000F, 0x001C, 0x0001, 0x002D, 0x0063, 0x01A4, 0x000E, 0x0001, 0x0005,
  0x01A7, 0x06BA, 0x01A6, 0x06A5, 0x0D57, 0x0D56, 0x1ABD, 0x0D51, 0x00AE,
  0x002C, 0x00A9, 0x002F, 0x0D50, 0x01A1, 0x1ABC, 0x06A4, 0x06A7, 0x06A6,
  0x00A8, 0x06A1, 0x01A0, 0x1ABF, 0x0D53, 0x06A0, 0x0D52, 0x1ABE, 0x06A3,
  0x0062, 0x002E, 0x0009, 0x0D5D, 0x01A3, 0x0D5C, 0x006D, 0x00AB, 0x06A2,
  0x006C, 0x001F, 0x0001, 0x06AD, 0x0029, 0x01A2, 0x0028, 0x0004, 0x001E,
  0x01AD, 0x006F, 0x0000, 0x01AC, 0x01AF, 0x06AC, 0x00AA, 0x006E, 0x0019, },
{ 0x0019, 0x007D, 0x0018, 0x01B5, 0x000D, 0x01B4, 0x007C, 0x007F, 0x01B7,
  0x000C, 0x001B, 0x001A, 0x01B6, 0x000F, 0x00D5, 0x0019, 0x007E, 0x00D4,
  0x0018, 0x001B, 0x0001, 0x000E, 0x0011, 0x0009, 0x0005, 0x0005, 0x0005,
  0x00D7, 0x01B1, 0x0008, 0x01B0, 0x0079, 0x06FD, 0x0371, 0x0370, 0x00D6,
  0x0078, 0x01B3, 0x0010, 0x0373, 0x0013, 0x06FC, 0x007B, 0x007A, 0x00D1,
  0x00D0, 0x00D3, 0x0065, 0x0372, 0x06FF, 0x0064, 0x06FE, 0x037D, 0x00D2,
  0x00DD, 0x0067, 0x0004, 0x037C, 0x0012, 0x01B2, 0x0007, 0x0066, 0x01BD,
  0x0006, 0x0061, 0x0004, 0x01BC, 0x001A, 0x0060, 0x001D, 0x0004, 0x001C,
  0x0063, 0x0001, 0x0007, 0x000B, 0x0000, 0x0062, 0x000A, 0x0005, 0x0007, },
{ 0x0069, 0x0045, 0x0068, 0x04BD, 0x0255, 0x04BC, 0x00E5, 0x00E4, 0x0031,
  0x0030, 0x0019, 0x0001, 0x0121, 0x00E7, 0x00E6, 0x0033, 0x00E1, 0x00E0,
  0x006B, 0x0018, 0x0001, 0x0044, 0x0032, 0x0047, 0x006A, 0x001B, 0x0005,
  0x003D, 0x0046, 0x0015, 0x0041, 0x0120, 0x0123, 0x04BF, 0x0122, 0x0040,
  0x003C, 0x00E3, 0x0014, 0x0254, 0x0043, 0x0975, 0x012D, 0x00E2, 0x00ED,
  0x0042, 0x00EC, 0x004D, 0x0257, 0x0256, 0x0251, 0x04BE, 0x0974, 0x0250,
  0x00EF, 0x00EE, 0x004C, 0x04B9, 0x012C, 0x04B8, 0x004F, 0x04BB, 0x0253,
  0x003F, 0x0017, 0x0001, 0x0252, 0x00E9, 0x00E8, 0x00EB, 0x0000, 0x0003,
  0x0016, 0x0002, 0x0004, 0x004E, 0x003E, 0x00EA, 0x0049, 0x000D, 0x0007, },
{ 0x000D, 0x01BD, 0x000C, 0x0D31, 0x0D30, 0x0D33, 0x0359, 0x0358, 0x002D,
  0x0065, 0x001D, 0x001C, 0x0D32, 0x035B, 0x035A, 0x002C, 0x01BC, 0x0345,
  0x000F, 0x001F, 0x0001, 0x002F, 0x0064, 0x01BF, 0x0067, 0x0001, 0x0005,
  0x0066, 0x002E, 0x0061, 0x0029, 0x0695, 0x0694, 0x0697, 0x0696, 0x0060,
  0x01BE, 0x0D3D, 0x0028, 0x1A49, 0x0344, 0x1A48, 0x1A4B, 0x0D3C, 0x0691,
  0x002B, 0x01B9, 0x002A, 0x0D3F, 0x0690, 0x0347, 0x0D3E, 0x1A4A, 0x0346,
  0x00D5, 0x0341, 0x0063, 0x0D39, 0x0340, 0x0D38, 0x01B8, 0x0D3B, 0x0D3A,
  0x00D4, 0x0062, 0x0000, 0x0693, 0x01BB, 0x0343, 0x0342, 0x001E, 0x000E,
  0x006D, 0x0009, 0x0001, 0x006C, 0x00D7, 0x034D, 0x01BA, 0x0008, 0x0004, },
{ 0x0075, 0x00CD, 0x0035, 0x03C1, 0x03C0, 0x07F9, 0x03C3, 0x1F8D, 0x00CC,
  0x0074, 0x0011, 0x0010, 0x03C2, 0x0FD9, 0x01F1, 0x00CF, 0x03CD, 0x00CE,
  0x0034, 0x0001, 0x0001, 0x0037, 0x00C9, 0x00C8, 0x0036, 0x0000, 0x0001,
  0x0FD8, 0x03CC, 0x00CB, 0x01F0, 0x07F8, 0x03CF, 0x07FB, 0x07FA, 0x00CA,
  0x01F3, 0x03CE, 0x00F5, 0x0FDB, 0x00F4, 0x07E5, 0x07E4, 0x07E7, 0x01F2,
  0x07E6, 0x03C9, 0x01FD, 0x0FDA, 0x1F8C, 0x07E1, 0x1F8F, 0x1F8E, 0x03C8,
  0x03CB, 0x0077, 0x0076, 0x0FC5, 0x03CA, 0x07E0, 0x00F7, 0x0FC4, 0x03F5,
  0x00F6, 0x01FC, 0x0003, 0x03F4, 0x0071, 0x03F7, 0x00F1, 0x0013, 0x0031,
  0x0030, 0x0070, 0x0005, 0x0012, 0x0073, 0x01FF, 0x0072, 0x007D, 0x0002, },
{ 0x0061, 0x0055, 0x0060, 0x02C9, 0x02C8, 0x02CB, 0x0171, 0x00B5, 0x0054,
  0x0001, 0x0001, 0x0001, 0x0057, 0x0001, 0x0063, 0x001D, 0x0062, 0x0039,
  0x006D, 0x0000, 0x0005, 0x0038, 0x0056, 0x00B4, 0x006C, 0x0003, 0x001C,
  0x006F, 0x003B, 0x0002, 0x003A, 0x0170, 0x00B7, 0x0173, 0x0051, 0x006E,
  0x0025, 0x0050, 0x0069, 0x02CA, 0x0024, 0x0027, 0x0172, 0x00B6, 0x00B1,
  0x000D, 0x000C, 0x001F, 0x017D, 0x0026, 0x0068, 0x0053, 0x017C, 0x006B,
  0x001E, 0x000F, 0x0004, 0x017F, 0x006A, 0x02F5, 0x0019, 0x0021, 0x0052,
  0x02F4, 0x02F7, 0x0020, 0x0BCD, 0x05E5, 0x05E4, 0x0BCC, 0x0023, 0x00B0,
  0x02F6, 0x00B3, 0x0022, 0x02F1, 0x02F0, 0x0BCF, 0x0BCE, 0x017E, 0x005D, },
{ 0x00BD, 0x0025, 0x01A1, 0x0159, 0x0299, 0x00BC, 0x0024, 0x0505, 0x0504,
  0x01A0, 0x0001, 0x001D, 0x006D, 0x001C, 0x0001, 0x0005, 0x0027, 0x01A3,
  0x0158, 0x001F, 0x001E, 0x01A2, 0x0026, 0x0021, 0x000D, 0x0020, 0x0023,
  0x0298, 0x006C, 0x0022, 0x00BF, 0x00BE, 0x01AD, 0x002D, 0x029B, 0x00B9,
  0x01AC, 0x00B8, 0x01AF, 0x029A, 0x006F, 0x015B, 0x006E, 0x0285, 0x0284,
  0x01AE, 0x0019, 0x002C, 0x01A9, 0x01A8, 0x000C, 0x000F, 0x015A, 0x00BB,
  0x000E, 0x0000, 0x0069, 0x01AB, 0x0018, 0x01AA, 0x0004, 0x0055, 0x00BA,
  0x0507, 0x0145, 0x0054, 0x0506, 0x00A5, 0x0501, 0x00A4, 0x0057, 0x0500,
  0x0A05, 0x0144, 0x00A7, 0x0287, 0x0286, 0x0503, 0x0147, 0x0A04, 0x0146, },
{ 0x0759, 0x0041, 0x00E5, 0x03BD, 0x0E9D, 0x012D, 0x012C, 0x3A1D, 0x03BC,
  0x012F, 0x000D, 0x0040, 0x00E4, 0x03BF, 0x0043, 0x0042, 0x0758, 0x03BE,
  0x00E7, 0x0001, 0x0000, 0x003D, 0x00E6, 0x0015, 0x0014, 0x0017, 0x003C,
  0x743D, 0x012E, 0x03B9, 0x03B8, 0x0E9C, 0x03BB, 0x075B, 0x3A1C, 0x0E9F,
  0x0129, 0x00E1, 0x0128, 0x0E9E, 0x012B, 0x075A, 0x00E0, 0x0E99, 0x0745,
  0x3A1F, 0x03BA, 0x0744, 0x0E98, 0x1D0D, 0x03A5, 0x0E9B, 0x743C, 0x0E9A,
  0x012A, 0x004D, 0x00E3, 0x0E85, 0x01D5, 0x0E84, 0x004C, 0x0747, 0x1D0C,
  0x01D4, 0x003F, 0x0016, 0x0746, 0x03A4, 0x0741, 0x004F, 0x003E, 0x01D7,
  0x0740, 0x000C, 0x0011, 0x004E, 0x00E2, 0x00ED, 0x00EC, 0x0049, 0x0048, },
};

static const uint8_t aic_mode2_vlc_bits[AIC_MODE2_NUM][AIC_MODE2_SIZE] = {
{  1,  5,  4, 10,  6,  8,  5,  8,  8,
   7,  5,  7, 11, 10,  9,  8, 13, 11,
   6,  7,  3,  9,  8, 10,  9,  8,  5,
  10,  9, 10, 10, 14, 12, 14, 14, 12,
   8,  9,  7, 12,  8, 14,  9,  9, 12,
   8,  9, 11, 11, 13,  9, 11, 14, 12,
   6,  7,  9, 13,  9, 12,  7, 10, 12,
  11, 12,  8, 15, 10, 15, 13,  7, 12,
  10, 10,  8, 10, 13, 13, 13, 11,  8, },
{  4,  6,  5, 11,  8, 10,  7, 11,  9,
   4,  1,  4,  9,  7,  7,  5,  9, 10,
   6,  7,  4,  9,  9, 10,  9,  9,  6,
   9, 10,  9, 10, 12, 12, 13, 12, 11,
   9,  9,  8, 12,  8, 14, 10, 11, 12,
   7,  8, 10, 11, 12,  9, 11, 13, 12,
   6,  7,  8, 12,  9, 12,  7, 11, 10,
  12, 12,  9, 14, 12, 15, 13,  8, 12,
  11, 11, 10, 12, 13, 15, 14, 12,  9, },
{  5,  7,  6, 12,  9, 11,  8, 11, 10,
   7,  5,  7, 11, 10,  9,  8, 12, 12,
   5,  5,  1,  8,  7, 10,  8,  6,  4,
   8,  8,  8,  9, 12, 11, 13, 12, 11,
   8,  9,  8, 12,  8, 13, 10, 11, 11,
   8,  9, 11, 12, 13, 11, 12, 14, 13,
   8,  9, 10, 14, 11, 14,  9, 13, 13,
   8,  9,  6, 11, 10, 14, 11,  6, 10,
   6,  6,  4,  8,  9, 10, 10,  8,  5, },
{ 11,  7,  8, 10, 12,  9, 10, 14, 12,
   7,  1,  5,  7,  8,  6,  4, 10,  9,
  10,  5,  4,  8, 11,  8,  7,  6,  7,
  11,  6,  7,  8, 10,  8, 10, 11,  9,
  10,  8,  9, 13,  9, 12,  8, 11, 12,
  11,  4,  7,  8,  9,  6,  8, 12,  9,
   8,  5,  8, 12,  9, 10,  6, 12, 11,
  12, 12, 10, 15, 13, 13, 13, 10, 13,
  15, 10,  9, 10, 12, 13, 13, 10,  9, },
{ 11,  8,  8, 11, 13, 10, 11, 15, 12,
   7,  1,  4,  7,  7,  5,  4,  8,  9,
  11,  5,  5,  8, 11,  9,  8,  7,  8,
  13,  7,  8,  9, 11,  9, 10, 12, 10,
  10,  9,  8, 13,  9, 12,  9, 11, 12,
  11,  5,  7,  9, 10,  6,  9, 13, 10,
   7,  4,  7, 11,  8,  9,  5, 10, 11,
  13, 11,  9, 15, 13, 15, 13,  8, 12,
  15, 10, 10, 12, 13, 14, 14, 12, 11, },
{ 12,  9,  9, 12, 13, 11, 11, 14, 12,
   8,  2,  5,  7,  9,  6,  5, 10, 10,
   9,  4,  2,  7,  9,  7,  6,  5,  6,
  12,  6,  7,  8, 10,  8, 10, 11,  9,
  12,  9, 10, 13, 11, 12, 10, 14, 13,
  12,  6,  8, 10, 10,  7,  9, 12, 10,
   8,  5,  8, 11,  9, 10,  7, 11, 12,
   8,  6,  5, 11, 11, 11,  8,  6,  9,
  12,  6,  6,  8, 10, 10, 11,  8,  6, },
{ 13,  9, 10, 12, 14, 12, 11, 15, 15,
   8,  1,  5,  7,  9,  6,  5, 11, 10,
  11,  6,  5,  9, 11,  9,  8,  7,  8,
  12,  6,  8,  8, 11,  8, 10, 12, 10,
  10,  7,  9, 13, 10, 11,  9, 13, 12,
  11,  3,  6,  8,  9,  4,  7, 11,  8,
   8,  5,  9, 12, 10,  9,  7, 12, 13,
  13, 12, 10, 14, 14, 15, 12, 11, 14,
  15,  7,  9,  8, 11, 11, 12, 10,  9, },
{ 10,  5,  6,  9, 11,  7,  8, 12, 11,
   8,  1,  4,  7,  9,  6,  4, 10, 10,
  11,  6,  6,  9,  9,  9,  9,  8,  8,
  14, 10, 10, 12, 12, 11, 12, 13, 12,
  10,  7,  8, 12,  9, 11,  8, 12, 11,
  13,  7, 10, 11, 11,  8, 10, 13, 11,
   6,  3,  7, 11,  8,  9,  5, 10, 11,
  11, 11,  9, 14, 14, 14, 11, 10, 13,
  14, 10, 11, 13, 13, 13, 14, 12, 12, },
{  2,  5,  3, 11,  8,  8,  6,  6,  7,
   8,  5,  6, 12, 10, 10,  8, 10, 11,
   7,  6,  2,  9,  8, 10,  8,  5,  4,
  10, 11, 10, 10, 13, 12, 14, 13, 10,
  10, 11,  8, 14,  9, 14, 12, 11, 12,
   9, 10,  9, 13, 12, 11, 12, 14, 11,
   8, 10,  7, 13, 10, 12,  8, 12, 12,
  10,  9,  6, 12, 11, 11, 11,  6,  9,
  10,  9,  6, 10,  9, 12, 11,  8,  7, },
{  6,  8,  6, 12, 11, 11, 10, 10,  9,
   6,  1,  3, 10,  8,  8,  6,  7, 10,
   8,  6,  3, 10,  9, 10,  8,  6,  5,
  11, 10, 10, 12, 13, 12, 14, 13, 12,
  10, 11,  8, 12,  9, 14, 12, 11, 12,
   9,  9,  8, 12, 12, 10, 12, 13, 11,
   7,  8,  6, 13,  9, 11,  7, 11, 11,
  11, 10,  7, 14, 11, 12, 12,  7, 10,
  12, 11,  8, 13, 12, 14, 13, 11, 10, },
{  7, 10,  7, 13, 13, 13, 11, 11, 10,
   8,  5,  6, 12, 11, 10,  9, 10, 11,
   7,  5,  1,  9,  8, 10,  7,  4,  4,
   9, 11,  9, 11, 12, 11, 13, 13, 10,
   9, 11,  8, 13,  9, 14, 12, 11, 12,
  11, 10, 10, 13, 12, 11, 14, 14, 12,
   9, 10,  8, 13, 10, 14,  9, 12, 12,
   9,  7,  4, 12, 10, 11, 10,  6,  7,
   9,  7,  4,  9,  9, 11,  9,  7,  5, },
{  7,  9,  7, 14, 11, 12, 10,  9,  9,
   8,  5,  5, 12,  9, 10,  8,  8, 11,
   7,  5,  2,  8,  8,  9,  7,  4,  4,
  10, 11, 10, 12, 14, 11, 12, 13, 12,
   9, 10,  8, 13,  8, 13, 10, 11, 11,
   9,  9,  8, 14, 10, 10, 11, 12, 11,
  10, 11,  9, 14, 10, 14,  9, 12, 14,
   6,  6,  3, 11,  8,  9,  8,  3,  6,
   9,  7,  4, 10,  8, 11, 10,  6,  5, },
{  6,  8,  7, 13, 12, 12, 10,  9,  9,
   9,  7,  8, 13, 11, 11,  9, 11, 12,
   7,  6,  1,  9,  8, 10,  7,  5,  4,
  10, 12, 10, 12, 13, 13, 14, 13, 11,
   9, 11,  9, 13, 10, 14, 12, 12, 12,
  11, 12, 10, 14, 13, 12, 13, 14, 12,
   8,  9,  7, 13, 10, 13,  8, 11, 12,
   8,  6,  3, 12,  9, 10,  9,  4,  6,
  10,  8,  5, 10, 10, 12, 11,  8,  6, },
{  7, 10,  7, 12,  9, 12, 10, 10, 12,
   9,  7,  7, 12,  9, 11,  6, 10, 11,
   6,  6,  1,  9,  8,  9,  7,  4,  5,
  11, 12,  9, 12, 10, 14, 13, 13, 11,
  10, 12,  8, 13,  8, 14, 10, 10, 11,
  11, 11, 10, 13, 14, 10, 14, 13, 11,
  11, 10,  7, 13,  8, 12,  7, 10, 12,
   7, 10,  4, 12,  6, 10,  8,  5,  8,
  10,  7,  4,  9,  7, 10,  9,  6,  5, },
{  7,  9,  7, 13, 12, 13, 10, 10,  8,
   8,  5,  6, 11, 10, 10,  8, 10, 10,
   7,  5,  2,  9,  8,  9,  7,  5,  3,
   8,  9,  7,  9, 11, 11, 13, 11,  9,
   8, 10,  7, 12,  9, 14, 11, 10, 10,
   9, 10,  9, 12, 12, 12, 13, 14, 12,
  10, 10,  9, 13, 11, 13,  9, 13, 12,
   8,  7,  4, 12, 10, 10, 10,  6,  6,
   7,  6,  3,  9,  8, 10,  9,  6,  3, },
{  7, 10,  7, 13, 13, 13, 11, 11,  9,
   8,  6,  6, 13, 11, 11,  9, 10, 11,
   7,  6,  1,  9,  8, 10,  8,  5,  4,
   8,  9,  8,  9, 12, 12, 12, 12,  8,
  10, 13,  9, 14, 11, 14, 14, 13, 12,
   9, 10,  9, 13, 12, 11, 13, 14, 11,
   9, 11,  8, 13, 11, 13, 10, 13, 13,
   9,  8,  5, 12, 10, 11, 11,  6,  7,
   8,  7,  3,  8,  9, 11, 10,  7,  4, },
{  8,  9,  7, 11, 11, 12, 11, 14,  9,
   8,  6,  6, 11, 13, 10,  9, 11,  9,
   7,  5,  1,  7,  9,  9,  7,  5,  3,
  13, 11,  9, 10, 12, 11, 12, 12,  9,
  10, 11,  9, 13,  9, 12, 12, 12, 10,
  12, 11, 10, 13, 14, 12, 14, 14, 11,
  11,  8,  8, 13, 11, 12,  9, 13, 11,
   9, 10,  5, 11,  8, 11,  9,  6,  7,
   7,  8,  4,  6,  8, 10,  8,  8,  5, },
{  8, 10,  8, 13, 13, 13, 12, 11, 10,
   5,  1,  3, 10,  7,  8,  6,  8,  9,
   8,  7,  4,  9, 10, 11,  8,  7,  6,
   8,  9,  7,  9, 12, 11, 12, 10,  8,
   9, 10,  8, 13,  9,  9, 12, 11, 11,
   7,  7,  6, 12,  9,  8, 10, 12,  8,
   6,  7,  4, 12,  8, 13,  6,  9, 10,
  13, 13,  9, 15, 14, 14, 15,  9, 11,
  13, 11,  9, 13, 13, 15, 15, 12, 10, },
{ 10,  8,  9, 11, 12, 10,  8, 13, 13,
   9,  2,  5,  7,  5,  4,  3,  8,  9,
  11,  5,  5,  9,  8,  8,  6,  8,  8,
  12,  7,  8, 10, 10,  9,  8, 12, 10,
   9, 10,  9, 12,  7, 11,  7, 12, 12,
   9,  5,  8,  9,  9,  6,  6, 11, 10,
   6,  4,  7,  9,  5,  9,  3,  9, 10,
  13, 11,  9, 13, 10, 13, 10,  9, 13,
  14, 11, 10, 12, 12, 13, 11, 14, 11, },
{ 11,  7,  8, 10, 12,  9,  9, 14, 10,
   9,  4,  7,  8, 10,  7,  7, 11, 10,
   8,  2,  2,  6,  8,  5,  5,  5,  6,
  15,  9, 10, 10, 12, 10, 11, 14, 12,
   9,  8,  9, 12,  9, 11,  8, 12, 11,
  14, 10, 11, 12, 13, 10, 12, 15, 12,
   9,  7,  8, 12,  9, 12,  7, 11, 13,
   9,  6,  5, 11, 10, 11,  7,  6,  9,
  11,  4,  5,  7,  8,  8,  8,  7,  7, },
};
//@}

/**
 * Codes used for determining block type
 */
//@{
#define AIC_MODE1_NUM  90
#define AIC_MODE1_SIZE  9
#define AIC_MODE1_BITS  7

static const uint8_t aic_mode1_vlc_codes[AIC_MODE1_NUM][AIC_MODE1_SIZE] = {
 { 0x01, 0x01, 0x01, 0x11, 0x00, 0x09, 0x03, 0x10, 0x05,},
 { 0x09, 0x01, 0x01, 0x05, 0x11, 0x00, 0x03, 0x21, 0x20,},
 { 0x01, 0x01, 0x01, 0x11, 0x09, 0x10, 0x05, 0x00, 0x03,},
 { 0x01, 0x01, 0x00, 0x03, 0x21, 0x05, 0x09, 0x20, 0x11,},
 { 0x01, 0x09, 0x00, 0x29, 0x08, 0x15, 0x03, 0x0B, 0x28,},
 { 0x01, 0x01, 0x01, 0x01, 0x00, 0x01, 0x01, 0x03, 0x02,},
 { 0x01, 0x01, 0x01, 0x05, 0x00, 0x03, 0x01, 0x09, 0x08,},
 { 0x01, 0x01, 0x01, 0x09, 0x01, 0x08, 0x00, 0x03, 0x05,},
 { 0x01, 0x01, 0x01, 0x00, 0x05, 0x11, 0x09, 0x10, 0x03,},
 { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},

 { 0x01, 0x01, 0x01, 0x05, 0x01, 0x00, 0x03, 0x09, 0x08,},
 { 0x09, 0x01, 0x01, 0x05, 0x11, 0x00, 0x03, 0x21, 0x20,},
 { 0x01, 0x01, 0x01, 0x0D, 0x05, 0x04, 0x00, 0x07, 0x0C,},
 { 0x01, 0x01, 0x00, 0x05, 0x11, 0x03, 0x09, 0x21, 0x20,},
 { 0x05, 0x01, 0x01, 0x11, 0x00, 0x09, 0x03, 0x21, 0x20,},
 { 0x09, 0x01, 0x01, 0x00, 0x05, 0x01, 0x03, 0x11, 0x10,},
 { 0x01, 0x01, 0x01, 0x00, 0x01, 0x01, 0x01, 0x03, 0x02,},
 { 0x01, 0x01, 0x01, 0x09, 0x00, 0x05, 0x01, 0x03, 0x08,},
 { 0x01, 0x01, 0x01, 0x09, 0x11, 0x05, 0x00, 0x10, 0x03,},
 { 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},

 { 0x01, 0x00, 0x01, 0x09, 0x08, 0x15, 0x14, 0x0B, 0x03,},
 { 0x0D, 0x01, 0x01, 0x05, 0x0C, 0x04, 0x01, 0x00, 0x07,},
 { 0x01, 0x01, 0x01, 0x05, 0x00, 0x04, 0x03, 0x01, 0x01,},
 { 0x05, 0x01, 0x01, 0x04, 0x19, 0x07, 0x18, 0x0D, 0x00,},
 { 0x11, 0x09, 0x01, 0x21, 0x05, 0x20, 0x01, 0x00, 0x03,},
 { 0x41, 0x01, 0x00, 0x05, 0x40, 0x03, 0x09, 0x21, 0x11,},
 { 0x29, 0x01, 0x00, 0x28, 0x09, 0x15, 0x03, 0x08, 0x0B,},
 { 0x01, 0x00, 0x01, 0x11, 0x09, 0x10, 0x05, 0x01, 0x03,},
 { 0x05, 0x01, 0x01, 0x04, 0x0D, 0x0C, 0x07, 0x00, 0x01,},
 { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},

 { 0x01, 0x00, 0x03, 0x05, 0x11, 0x10, 0x25, 0x24, 0x13,},
 { 0x21, 0x01, 0x01, 0x00, 0x11, 0x03, 0x05, 0x20, 0x09,},
 { 0x01, 0x01, 0x01, 0x00, 0x09, 0x11, 0x10, 0x05, 0x03,},
 { 0x21, 0x05, 0x01, 0x01, 0x09, 0x00, 0x11, 0x20, 0x03,},
 { 0x05, 0x01, 0x00, 0x04, 0x01, 0x19, 0x07, 0x18, 0x0D,},
 { 0x11, 0x01, 0x00, 0x01, 0x09, 0x01, 0x03, 0x10, 0x05,},
 { 0x1D, 0x01, 0x05, 0x0D, 0x0C, 0x04, 0x00, 0x1C, 0x0F,},
 { 0x05, 0x19, 0x01, 0x04, 0x00, 0x18, 0x1B, 0x1A, 0x07,},
 { 0x09, 0x01, 0x00, 0x01, 0x05, 0x03, 0x11, 0x10, 0x01,},
 { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},

 { 0x01, 0x00, 0x03, 0x41, 0x05, 0x40, 0x09, 0x11, 0x21,},
 { 0x05, 0x01, 0x01, 0x19, 0x04, 0x07, 0x00, 0x18, 0x0D,},
 { 0x01, 0x01, 0x01, 0x05, 0x01, 0x04, 0x01, 0x00, 0x03,},
 { 0x01, 0x05, 0x00, 0x0D, 0x01, 0x04, 0x07, 0x19, 0x18,},
 { 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x01, 0x03, 0x02,},
 { 0x31, 0x01, 0x05, 0x19, 0x04, 0x07, 0x00, 0x30, 0x0D,},
 { 0x01, 0x00, 0x03, 0x11, 0x01, 0x05, 0x01, 0x09, 0x10,},
 { 0x01, 0x05, 0x01, 0x11, 0x01, 0x10, 0x00, 0x03, 0x09,},
 { 0x01, 0x09, 0x00, 0x29, 0x03, 0x08, 0x28, 0x15, 0x0B,},
 { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},

 { 0x01, 0x01, 0x00, 0x09, 0x15, 0x03, 0x08, 0x14, 0x0B,},
 { 0x11, 0x01, 0x01, 0x00, 0x09, 0x01, 0x03, 0x10, 0x05,},
 { 0x01, 0x00, 0x03, 0x25, 0x11, 0x05, 0x10, 0x24, 0x13,},
 { 0x11, 0x01, 0x00, 0x01, 0x09, 0x01, 0x05, 0x10, 0x03,},
 { 0x05, 0x01, 0x00, 0x0D, 0x0C, 0x04, 0x0F, 0x1D, 0x1C,},
 { 0x01, 0x01, 0x01, 0x01, 0x00, 0x01, 0x01, 0x03, 0x02,},
 { 0x21, 0x01, 0x05, 0x09, 0x11, 0x00, 0x03, 0x41, 0x40,},
 { 0x05, 0x01, 0x00, 0x1D, 0x1C, 0x0D, 0x0C, 0x0F, 0x04,},
 { 0x05, 0x01, 0x00, 0x0D, 0x31, 0x04, 0x19, 0x30, 0x07,},
 { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},

 { 0x01, 0x01, 0x00, 0x21, 0x05, 0x11, 0x03, 0x09, 0x20,},
 { 0x01, 0x01, 0x00, 0x11, 0x03, 0x05, 0x01, 0x09, 0x10,},
 { 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x01, 0x03, 0x02,},
 { 0x05, 0x01, 0x04, 0x19, 0x07, 0x0D, 0x00, 0x31, 0x30,},
 { 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x01, 0x03, 0x02,},
 { 0x05, 0x01, 0x01, 0x11, 0x09, 0x00, 0x03, 0x21, 0x20,},
 { 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x01, 0x03, 0x02,},
 { 0x01, 0x01, 0x01, 0x00, 0x01, 0x03, 0x01, 0x01, 0x02,},
 { 0x09, 0x01, 0x00, 0x29, 0x08, 0x15, 0x03, 0x28, 0x0B,},
 { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},

 { 0x01, 0x01, 0x01, 0x05, 0x01, 0x04, 0x00, 0x01, 0x03,},
 { 0x09, 0x01, 0x00, 0x29, 0x28, 0x15, 0x08, 0x03, 0x0B,},
 { 0x01, 0x00, 0x01, 0x11, 0x05, 0x10, 0x09, 0x01, 0x03,},
 { 0x05, 0x04, 0x01, 0x1D, 0x0D, 0x0C, 0x1C, 0x00, 0x0F,},
 { 0x09, 0x11, 0x01, 0x41, 0x00, 0x40, 0x05, 0x03, 0x21,},
 { 0x0D, 0x05, 0x01, 0x1D, 0x1C, 0x0C, 0x04, 0x00, 0x0F,},
 { 0x41, 0x09, 0x01, 0x40, 0x00, 0x11, 0x05, 0x03, 0x21,},
 { 0x01, 0x01, 0x01, 0x05, 0x01, 0x04, 0x00, 0x01, 0x03,},
 { 0x05, 0x04, 0x01, 0x0D, 0x01, 0x0C, 0x07, 0x01, 0x00,},
 { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},

 { 0x05, 0x04, 0x01, 0x07, 0x19, 0x31, 0x30, 0x0D, 0x00,},
 { 0x21, 0x01, 0x01, 0x00, 0x11, 0x09, 0x20, 0x05, 0x03,},
 { 0x05, 0x01, 0x01, 0x04, 0x07, 0x0D, 0x0C, 0x00, 0x01,},
 { 0x21, 0x09, 0x01, 0x00, 0x20, 0x05, 0x23, 0x22, 0x03,},
 { 0x31, 0x0D, 0x01, 0x19, 0x05, 0x30, 0x04, 0x07, 0x00,},
 { 0x31, 0x05, 0x01, 0x04, 0x19, 0x00, 0x0D, 0x30, 0x07,},
 { 0x31, 0x01, 0x00, 0x0D, 0x05, 0x19, 0x04, 0x30, 0x07,},
 { 0x01, 0x01, 0x01, 0x00, 0x01, 0x03, 0x02, 0x01, 0x01,},
 { 0x01, 0x00, 0x01, 0x01, 0x05, 0x09, 0x08, 0x03, 0x01,},
 { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},
};

static const uint8_t aic_mode1_vlc_bits[AIC_MODE1_NUM][AIC_MODE1_SIZE] = {
 {  1,  4,  2,  7,  4,  6,  4,  7,  5,},
 {  5,  1,  3,  4,  6,  3,  3,  7,  7,},
 {  1,  4,  2,  7,  6,  7,  5,  4,  4,},
 {  1,  3,  3,  3,  7,  4,  5,  7,  6,},
 {  2,  4,  2,  6,  4,  5,  2,  4,  6,},
 {  7,  2,  3,  4,  7,  1,  5,  7,  7,},
 {  5,  1,  3,  6,  5,  5,  2,  7,  7,},
 {  2,  5,  1,  7,  3,  7,  5,  5,  6,},
 {  2,  4,  1,  4,  5,  7,  6,  7,  4,},
 {  0,  0,  0,  0,  0,  0,  0,  0,  0,},

 {  2,  1,  3,  6,  5,  5,  5,  7,  7,},
 {  5,  1,  3,  4,  6,  3,  3,  7,  7,},
 {  4,  1,  2,  6,  5,  5,  4,  5,  6,},
 {  3,  1,  3,  4,  6,  3,  5,  7,  7,},
 {  4,  1,  3,  6,  3,  5,  3,  7,  7,},
 {  6,  1,  4,  4,  5,  2,  4,  7,  7,},
 {  7,  1,  5,  7,  4,  3,  2,  7,  7,},
 {  5,  3,  2,  7,  5,  6,  1,  5,  7,},
 {  4,  1,  2,  6,  7,  5,  4,  7,  4,},
 {  1,  0,  1,  0,  0,  0,  0,  0,  0,},

 {  3,  3,  1,  5,  5,  6,  6,  5,  3,},
 {  6,  2,  1,  5,  6,  5,  4,  4,  5,},
 {  6,  4,  1,  7,  6,  7,  6,  3,  2,},
 {  4,  3,  1,  4,  6,  4,  6,  5,  3,},
 {  6,  5,  1,  7,  4,  7,  3,  3,  3,},
 {  7,  2,  2,  3,  7,  2,  4,  6,  5,},
 {  6,  2,  2,  6,  4,  5,  2,  4,  4,},
 {  4,  4,  1,  7,  6,  7,  5,  2,  4,},
 {  5,  4,  1,  5,  6,  6,  5,  4,  2,},
 {  0,  0,  0,  0,  0,  0,  0,  0,  0,},

 {  2,  2,  2,  3,  5,  5,  6,  6,  5,},
 {  7,  1,  3,  3,  6,  3,  4,  7,  5,},
 {  2,  4,  1,  4,  6,  7,  7,  5,  4,},
 {  7,  4,  3,  1,  5,  3,  6,  7,  3,},
 {  4,  3,  3,  4,  1,  6,  4,  6,  5,},
 {  7,  4,  4,  2,  6,  1,  4,  7,  5,},
 {  5,  2,  3,  4,  4,  3,  2,  5,  4,},
 {  3,  5,  2,  3,  2,  5,  5,  5,  3,},
 {  6,  4,  4,  2,  5,  4,  7,  7,  1,},
 {  0,  0,  0,  0,  0,  0,  0,  0,  0,},

 {  2,  2,  2,  7,  3,  7,  4,  5,  6,},
 {  4,  1,  3,  6,  4,  4,  3,  6,  5,},
 {  2,  4,  1,  7,  3,  7,  6,  6,  6,},
 {  3,  4,  3,  5,  1,  4,  4,  6,  6,},
 {  4,  5,  2,  7,  1,  7,  3,  7,  7,},
 {  6,  2,  3,  5,  3,  3,  2,  6,  4,},
 {  4,  4,  4,  7,  2,  5,  1,  6,  7,},
 {  4,  5,  2,  7,  1,  7,  4,  4,  6,},
 {  2,  4,  2,  6,  2,  4,  6,  5,  4,},
 {  0,  0,  0,  0,  0,  0,  0,  0,  0,},

 {  1,  3,  3,  5,  6,  3,  5,  6,  5,},
 {  7,  1,  4,  4,  6,  2,  4,  7,  5,},
 {  2,  2,  2,  6,  5,  3,  5,  6,  5,},
 {  7,  4,  4,  2,  6,  1,  5,  7,  4,},
 {  3,  2,  2,  4,  4,  3,  4,  5,  5,},
 {  7,  2,  5,  3,  7,  1,  4,  7,  7,},
 {  6,  2,  3,  4,  5,  2,  2,  7,  7,},
 {  3,  2,  2,  5,  5,  4,  4,  4,  3,},
 {  3,  2,  2,  4,  6,  3,  5,  6,  3,},
 {  0,  0,  0,  0,  0,  0,  0,  0,  0,},

 {  1,  3,  3,  7,  4,  6,  3,  5,  7,},
 {  4,  1,  4,  7,  4,  5,  2,  6,  7,},
 {  2,  4,  1,  7,  5,  7,  3,  7,  7,},
 {  3,  2,  3,  5,  3,  4,  2,  6,  6,},
 {  3,  5,  4,  7,  2,  7,  1,  7,  7,},
 {  4,  1,  3,  6,  5,  3,  3,  7,  7,},
 {  4,  2,  5,  7,  3,  7,  1,  7,  7,},
 {  7,  4,  1,  7,  3,  7,  2,  5,  7,},
 {  4,  2,  2,  6,  4,  5,  2,  6,  4,},
 {  0,  0,  0,  0,  0,  0,  0,  0,  0,},

 {  3,  4,  1,  7,  6,  7,  6,  2,  6,},
 {  4,  2,  2,  6,  6,  5,  4,  2,  4,},
 {  4,  4,  1,  7,  5,  7,  6,  2,  4,},
 {  3,  3,  2,  5,  4,  4,  5,  2,  4,},
 {  4,  5,  2,  7,  2,  7,  3,  2,  6,},
 {  4,  3,  2,  5,  5,  4,  3,  2,  4,},
 {  7,  4,  2,  7,  2,  5,  3,  2,  6,},
 {  4,  6,  2,  7,  3,  7,  6,  1,  6,},
 {  5,  5,  1,  6,  4,  6,  5,  2,  4,},
 {  0,  0,  0,  0,  0,  0,  0,  0,  0,},

 {  3,  3,  2,  3,  5,  6,  6,  4,  2,},
 {  7,  1,  3,  3,  6,  5,  7,  4,  3,},
 {  5,  4,  1,  5,  5,  6,  6,  4,  2,},
 {  6,  4,  2,  2,  6,  3,  6,  6,  2,},
 {  6,  4,  2,  5,  3,  6,  3,  3,  2,},
 {  6,  3,  2,  3,  5,  2,  4,  6,  3,},
 {  6,  2,  2,  4,  3,  5,  3,  6,  3,},
 {  7,  5,  1,  7,  4,  7,  7,  3,  2,},
 {  5,  5,  2,  3,  6,  7,  7,  5,  1,},
 {  0,  0,  0,  0,  0,  0,  0,  0,  0,},
};

//@}

#define PBTYPE_ESCAPE 0xFF

/** tables used for P-frame macroblock type decoding */
//@{
#define NUM_PTYPE_VLCS 7
#define PTYPE_VLC_SIZE 8
#define PTYPE_VLC_BITS 7

static const uint8_t ptype_vlc_codes[NUM_PTYPE_VLCS][PTYPE_VLC_SIZE] = {
 { 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00 },
 { 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00 },
 { 0x0D, 0x05, 0x01, 0x04, 0x01, 0x00, 0x07, 0x0C },
 { 0x09, 0x11, 0x01, 0x00, 0x05, 0x03, 0x21, 0x20 },
 { 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00 },
 { 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00 },
 { 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00 }
};

static const uint8_t ptype_vlc_bits[NUM_PTYPE_VLCS][PTYPE_VLC_SIZE] = {
 { 1, 2, 3, 6, 5, 4, 7, 7 },
 { 3, 1, 2, 7, 6, 5, 4, 7 },
 { 5, 4, 1, 4, 3, 3, 4, 5 },
 { 4, 5, 2, 2, 3, 2, 6, 6 },
 { 5, 6, 1, 4, 2, 3, 7, 7 },
 { 5, 6, 1, 4, 3, 2, 7, 7 },
 { 6, 3, 2, 7, 5, 4, 1, 7 }
};

static const uint8_t ptype_vlc_syms[PTYPE_VLC_SIZE] = {
 0, 1, 2, 3, 8, 9, 11, PBTYPE_ESCAPE
};

/** reverse of ptype_vlc_syms */
static const uint8_t block_num_to_ptype_vlc_num[12] = {
 0, 1, 2, 3, 0, 0, 2, 0, 4, 5, 0, 6
};
//@}

/** tables used for P-frame macroblock type decoding */
//@{
#define NUM_BTYPE_VLCS 6
#define BTYPE_VLC_SIZE 7
#define BTYPE_VLC_BITS 6

static const uint8_t btype_vlc_codes[NUM_BTYPE_VLCS][BTYPE_VLC_SIZE] = {
 { 0x01, 0x05, 0x00, 0x03, 0x11, 0x09, 0x10 },
 { 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00 },
 { 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00 },
 { 0x09, 0x01, 0x00, 0x01, 0x05, 0x03, 0x08 },
 { 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00 },
 { 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00 }
};

static const uint8_t btype_vlc_bits[NUM_BTYPE_VLCS][PTYPE_VLC_SIZE] = {
 { 2, 3, 2, 2, 5, 4, 5 },
 { 4, 1, 3, 2, 6, 5, 6 },
 { 6, 4, 1, 2, 5, 3, 6 },
 { 5, 3, 3, 1, 4, 3, 5 },
 { 6, 5, 3, 2, 4, 1, 6 },
 { 6, 5, 3, 1, 4, 2, 6 }
};

static const uint8_t btype_vlc_syms[BTYPE_VLC_SIZE] = {
 0, 1, 4, 5, 10, 7, PBTYPE_ESCAPE
};

/** reverse of btype_vlc_syms */
static const uint8_t block_num_to_btype_vlc_num[12] = {
 0, 1, 0, 0, 2, 3, 0, 5, 0, 0, 4, 0
};
//@}
#endif /* AVCODEC_RV40VLC2_H */
