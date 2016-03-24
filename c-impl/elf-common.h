/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef _ELF_COMMON_H_
#define _ELF_COMMON_H_

#include <stdint.h>

/* ELF identification */
#define EI_MAG0    0
#define EI_MAG1    1
#define EI_MAG2    2
#define EI_MAG3    3
#define EI_CLASS   4
#define EI_DATA    5
#define EI_VERSION 6
#define EI_PAD     7
#define EI_NIDENT   16

#define ELFMAG0 0x7F            /* Magic Number */
#define ELFMAG1 'E'
#define ELFMAG2 'L'
#define ELFMAG3 'F'

#define ELFCLASSNONE 0          /* Class 32/64 Bit */
#define ELFCLASS32   1
#define ELFCLASS64   2

#define ELFDATANONE 0           /* Data-encoding LSB/MSB */
#define ELFDATA2LSB 1
#define ELFDATA2MSB 2

#define EV_NONE    0            /* Version */
#define EV_CURRENT 1

/* ELF Object type */
enum ELFObjectType {
        ET_NONE = 0,
        ET_REL = 1,
        ET_REXEC = 2,
        ET_DYN = 3,
        ET_CORE = 4,
        ET_LOPROC = 0xFF00,
        ET_HIPROC = 0xFFFF,
        ET_NUM
};

/* ELF Machine type */
typedef enum {
        EM_NONE = 0,
        EM_M32 = 1,
        EM_SPARC = 2,
        EM_386 = 3,
        EM_68K = 4,
        EM_88K = 5,
        EM_860 = 6,
        EM_MIPS = 7,
        EM_S370 = 8,
        EM_MIPS_RS3_LE = 9,
        EM_PARISC = 15,
        EM_VPP500 = 17,
        EM_SPARC32PLUS = 18,
        EM_960 = 19,
        EM_PPC = 20,
        EM_PPC64 = 21,
        EM_S90 = 22,
        EM_V800 = 36,
        EM_FR20 = 37,
        EM_RH32 = 38,
        EM_RCE = 39,
        EM_ARM = 40,
        EM_FAKE_ALPHA = 41,
        EM_SH = 42,
        EM_SPARCV9 = 43,
        EM_TRICORE = 44,
        EM_ARC = 45,
        EM_H8_300 = 46,
        EM_H8_300H = 47,
        EM_H8S = 48,
        EM_H8_500 = 49,
        EM_IA_64 = 50,
        EM_MIPS_X = 51,
        EM_COLDFIRE = 52,
        EM_68HC12 = 53,
        EM_MMA = 54,
        EM_PCP = 55,
        EM_NCPU = 56,
        EM_NDR1 = 57,
        EM_STARCORE = 58,
        EM_ME16 = 59,
        EM_ST100 = 60,
        EM_TINYJ = 61,
        EM_AMD64 = 62,
        EM_PDSP = 63,
        EM_FX66 = 66,
        EM_ST9PLUS = 67,
        EM_ST7 = 68,
        EM_68HC16 = 69,
        EM_68HC11 = 70,
        EM_68HC08 = 71,
        EM_68HC05 = 72,
        EM_SVX = 73,
        EM_ST19 = 74,
        EM_VAX = 75,
        EM_CRIS = 76,
        EM_JAVELIN = 77,
        EM_FIREPATH = 78,
        EM_ZSP = 79,
        EM_MMIX = 80,
        EM_HUANY = 81,
        EM_PRISM = 82,
        EM_AVR = 83,
        EM_FR30 = 84,
        EM_D10V = 85,
        EM_D30V= 86,
        EM_V850 = 87,
        EM_M32R = 88,
        EM_MN10300 = 89,
        EM_MN10200 = 90,
        EM_PJ = 91,
        EM_OPENRISC = 92,
        EM_ARC_A5 = 93,
        EM_XTENSA = 94,
        EM_AARCH64 = 183,
        EM_TILEPRO = 188,
        EM_MICROBLAZE = 189,
        EM_TILEGX = 191,
} ELFMachineType;

const char *elf_common_get_architecture(uint16_t type);

#endif  /* _ELF_COMMON_H_ */
