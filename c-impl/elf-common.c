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

#include "elf-common.h"

static const struct {
        ELFMachineType type;
        const char *desc;
} machine_type[] = {
        { EM_NONE, "None" },
        { EM_M32, "AT&T WE 32100" },
        { EM_SPARC, "SPARC" },
        { EM_386, "Intel 80386" },
        { EM_68K, "Motorola 68000" },
        { EM_88K, "Motorola 88000" },
        { EM_860, "Intel 80860" },
        { EM_MIPS, "MIPS RS3000 Big-Endian" },
        { EM_S370, "IBM Sys/370" },
        { EM_MIPS_RS3_LE, "MIPS RS3000 Little-Endian" },
        { EM_PARISC, "HPPA" },
        { EM_VPP500, "Fujitsu VPP500" },
        { EM_SPARC32PLUS, "Sun v8plus" },
        { EM_960, "Intel 80960" },
        { EM_PPC, "PowerPC" },
        { EM_PPC64, "PowerPC 64"  },
        { EM_S90, "IBM S390" },
        { EM_V800, "NEC V800" },
        { EM_FR20, "Fujitsu FR20" },
        { EM_RH32, "TRW RH-32" },
        { EM_RCE, "Motorola RCE" },
        { EM_ARM, "ARM" },
        { EM_FAKE_ALPHA, "DEC Alpha" },
        { EM_SH, "Hitachi SH" },
        { EM_SPARCV9, "SPARC V9 64" },
        { EM_TRICORE, "Siemens Tricore" },
        { EM_ARC, "Argonaut RISC Core" },
        { EM_H8_300, "Hitachi H8/300" },
        { EM_H8_300H, "Hitachi H8/300H" },
        { EM_H8S, "Hitachi H8S" },
        { EM_H8_500, "Hitachi H8/500" },
        { EM_IA_64, "Intel IA64 - Merced"},
        { EM_MIPS_X, "Stanford MIPS-X" },
        { EM_COLDFIRE, "Motorola Coldfire" },
        { EM_68HC12, "Motorola M68HC12" },
        { EM_MMA, "Fujitsu MMA" },
        { EM_PCP, "Siemens PCP" },
        { EM_NCPU, "Sony nCPU embeeded RISC" },
        { EM_NDR1, "Denso NDR1 microprocessor" },
        { EM_STARCORE, "Motorola Start Core" },
        { EM_ME16, "Toyota ME16 processor" },
        { EM_ST100, "STMicroelectronic ST100" },
        { EM_TINYJ, "Advanced Logic Corp. Tinyj" },
        { EM_AMD64, "AMD x86-64" },
        { EM_PDSP, "Sony DSP" },
        { EM_FX66, "Siemens FX66 microcontroller" },
        { EM_ST9PLUS, "STMicroelectronics ST9+" },
        { EM_ST7, "STmicroelectronics ST7" },
        { EM_68HC16, "Motorola MC68HC16" },
        { EM_68HC11, "Motorola MC68HC11" },
        { EM_68HC08, "Motorola MC68HC08" },
        { EM_68HC05, "Motorola MC68HC05" },
        { EM_SVX, "Silicon Graphics" },
        { EM_ST19, "STMicroelectronics ST19" },
        { EM_VAX, "Digital VAX" },
        { EM_CRIS, "Axis Communications 32-bit" },
        { EM_JAVELIN, "Infineon Technologies 32-bit" },
        { EM_FIREPATH, "Element14 64-bit" },
        { EM_ZSP,"LSI Logic 16-bit" },
        { EM_MMIX, "Donald Knuth's educational 64-bit processor" },
        { EM_HUANY, "Harvard University machine-independent object files" },
        { EM_PRISM, "SiTera Prism" },
        { EM_AVR, "Atmel AVR 8-bit" },
        { EM_FR30, "Fujitsu FR30" },
        { EM_D10V, "Mitsubishi D10V" },
        { EM_D30V, "Mitsubishi D30V" },
        { EM_V850, "NEC v850" },
        { EM_M32R, "Mitsubishi M32R" },
        { EM_MN10300, "Matsushita MN10300" },
        { EM_MN10200, "Matsushita MN10200" },
        { EM_PJ, "picoJava" },
        { EM_OPENRISC, "OpenRISC 32-bit" },
        { EM_ARC_A5, "ARC Cores Tangent-A5" },
        { EM_XTENSA, "Tensilica Xtensa Architecture" },
        { EM_AARCH64, "ARM AARCH64" },
        { EM_TILEPRO, "Tilera TILEPro" },
        { EM_MICROBLAZE, "Xilinx MicroBlaze" },
        { EM_TILEGX, "Tilera TILE-Gx" }
};

#define ARCH_COUNT (sizeof(machine_type) / sizeof(machine_type[0]))


const char * elf_common_get_architecture(uint16_t type)
{
        unsigned int i;

        for (i = 0; i < ARCH_COUNT; i++) {
                if (machine_type[i].type == type) {
                        break;
                }
        }

        if (i == ARCH_COUNT)
                return "Unknown";
        else
                return machine_type[i].desc;
}
