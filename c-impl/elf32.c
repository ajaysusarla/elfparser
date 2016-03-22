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

#include "elf32.h"

int validate_elf32_ident(void *data)
{
        Elf32_Eheader *file = (Elf32_Eheader *)data;

        if (file->e_ident[EI_MAG0] != ELFMAG0 ||
            file->e_ident[EI_MAG1] != ELFMAG1 ||
            file->e_ident[EI_MAG2] != ELFMAG2 ||
            file->e_ident[EI_MAG3] != ELFMAG3) {
                return -1;
        }

        if (file->e_ident[EI_CLASS] == ELFCLASSNONE) {
                return -2;
        }

        return 0;
}

/* Class */
static char *class_arr[] = {
        "None",
        "32 bit",
        "64 bit"
};

char *get_elf32_class(void *data)
{
        Elf32_Eheader *file = (Elf32_Eheader *)data;

        return class_arr[file->e_ident[EI_CLASS]];
}

/* Endianess */
static char *data_enc_arr[] = {
        "None",
        "LSB - little endian",
        "MSB - big endian"
};

char *get_elf32_data_encoding(void *data)
{
        Elf32_Eheader *file = (Elf32_Eheader *)data;

        return data_enc_arr[file->e_ident[EI_CLASS]];
}

/* ELF version from identity */
uint32_t get_elf32_version_from_ident(void *data)
{
        Elf32_Eheader *file = (Elf32_Eheader *)data;

        return file->e_ident[EI_VERSION];
}

/* ELF Object Type */
static char *obj_type_arr[] = {
        "None",
        "Relocatable file",
        "Executable file",
        "Shared object file",
        "Core file",
        "Processor-specific",
        "Processor-specific"
};

char *get_elf32_object_type(void *data)
{
        Elf32_Eheader *file = (Elf32_Eheader *)data;

        switch(file->e_type) {
        case ET_NONE:
        case ET_REL:
        case ET_REXEC:
        case ET_DYN:
        case ET_CORE:
                return obj_type_arr[file->e_type];
        case ET_LOPROC:
                return obj_type_arr[5];
        case ET_HIPROC:
                return obj_type_arr[6];
        default:
                return "Unknown";
        }
}

/* ELF Architecture */
static char *machine_arr[] = {
        "None",
        "AT&T WE 32100",
        "SPARC",
        "Intel 80386",
        "Motorola 68000",
        "Motorola 88000",
        "Intel 80860",
        "MIPS RS3000",
};

char *get_elf32_architecture(void *data)
{
        Elf32_Eheader *file = (Elf32_Eheader *)data;

        switch(file->e_machine) {
        case EM_NONE:
        case EM_M32:
        case EM_SPARC:
        case EM_386:
        case EM_68K:
        case EM_88K:
        case EM_860:
        case EM_MIPS:
                return machine_arr[file->e_machine];
        case EM_SPARC32PLUS:
                return "Sun SPARC 32+";
        case EM_SPARCV9:
                return "SPARC V9";
        case EM_AMD64:
                return "AMD 64";
        case EM_ARM:
                return "ARM";
        default:
                return "Unknown";
        }
}

/* ELF version */
uint32_t get_elf32_version(void *data)
{
        Elf32_Eheader *file = (Elf32_Eheader *)data;

        return file->e_version;
}

/* ELF entry address */
uint32_t get_elf32_entry_addr(void *data)
{
        Elf32_Eheader *file = (Elf32_Eheader *)data;

        return file->e_entry;
}


uint32_t get_elf32_prog_hdr_off(void *data)
{
        Elf32_Eheader *file = (Elf32_Eheader *)data;

        return file->e_phoff;
}


uint32_t get_elf32_sect_hdr_off(void *data)
{
        Elf32_Eheader *file = (Elf32_Eheader *)data;

        return file->e_shoff;
}
