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
#include "elfparser.h"

int validate_elf_ident(Elf32_Eheader *file)
{
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

char *get_elf_class(Elf32_Eheader *file)
{
        return class_arr[file->e_ident[EI_CLASS]];
}

/* Endianess */
static char *data_enc_arr[] = {
        "None",
        "LSB - little endian",
        "MSB - big endian"
};

char * get_elf_data_encoding(Elf32_Eheader *file)
{
        return data_enc_arr[file->e_ident[EI_CLASS]];
}

/* ELF version from identity */
int get_elf_version(Elf32_Eheader *file)
{
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

char * get_elf_object_type(Elf32_Eheader *file)
{
        return obj_type_arr[file->e_type];
}
