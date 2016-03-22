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
enum ELFMachineType {
        EM_NONE = 0,
        EM_M32 = 1,
        EM_SPARC = 2,
        EM_386 = 3,
        EM_68K = 4,
        EM_88K = 5,
        EM_860 = 6,
        EM_MIPS = 7,
        EM_SPARC32PLUS = 18,
        EM_ARM = 40,
        EM_SPARCV9 = 43,
        EM_AMD64 = 62,
        EM_NUM
};

#endif  /* _ELF_COMMON_H_ */
