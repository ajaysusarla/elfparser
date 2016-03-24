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

#include "elf64.h"

int validate_elf64_ident(void *data)
{
        Elf64_Eheader *file = (Elf64_Eheader *)data;

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

const char *get_elf64_class(void *data)
{
        Elf64_Eheader *file = (Elf64_Eheader *)data;

        return class_arr[file->e_ident[EI_CLASS]];
}

/* Endianess */
static char *data_enc_arr[] = {
        "None",
        "LSB - little endian",
        "MSB - big endian"
};

const char *get_elf64_data_encoding(void *data)
{
        Elf64_Eheader *file = (Elf64_Eheader *)data;

        return data_enc_arr[file->e_ident[EI_CLASS]];
}

/* ELF version from identity */
uint32_t get_elf64_version_from_ident(void *data)
{
        Elf64_Eheader *file = (Elf64_Eheader *)data;

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

const char *get_elf64_object_type(void *data)
{
        Elf64_Eheader *file = (Elf64_Eheader *)data;

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
const char *get_elf64_architecture(void *data)
{
        Elf64_Eheader *file = (Elf64_Eheader *)data;

        return elf_common_get_architecture(file->e_machine);

}

/* ELF version */
uint32_t get_elf64_version(void *data)
{
        Elf64_Eheader *file = (Elf64_Eheader *)data;

        return file->e_version;
}

/* ELF entry address */
uint32_t get_elf64_entry_addr(void *data)
{
        Elf64_Eheader *file = (Elf64_Eheader *)data;

        return file->e_entry;
}


uint32_t get_elf64_prog_hdr_off(void *data)
{
        Elf64_Eheader *file = (Elf64_Eheader *)data;

        return file->e_phoff;
}


uint32_t get_elf64_sect_hdr_off(void *data)
{
        Elf64_Eheader *file = (Elf64_Eheader *)data;

        return file->e_shoff;
}
