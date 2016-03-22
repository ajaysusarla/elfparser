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

#include "elf.h"

#include "elf32.h"
#include "elf64.h"

#include <stdio.h>

#define IS_ELF32(elf) (((Elf32_Eheader*)elf)->e_ident[EI_CLASS] == ELFCLASS32)
#define IS_ELF64(elf) (((Elf64_Eheader*)elf)->e_ident[EI_CLASS] == ELFCLASS64)

struct Elf {
        int      (*validate_elf_ident)(void *data);
        char    *(*get_elf_class)(void *data);
        char    *(*get_elf_data_encoding)(void *data);
        uint32_t (*get_elf_version_from_ident)(void *data);
        char    *(*get_elf_object_type)(void *data);
        char    *(*get_elf_architecture)(void *data);
        uint32_t (*get_elf_version)(void *data);
        uint32_t (*get_elf_entry_addr)(void *data);
        uint32_t (*get_elf_prog_hdr_off)(void *data);
        uint32_t (*get_elf_sect_hdr_off)(void *data);
};

static struct Elf elf32ops = {
        validate_elf32_ident,
        get_elf32_class,
        get_elf32_data_encoding,
        get_elf32_version_from_ident,
        get_elf32_object_type,
        get_elf32_architecture,
        get_elf32_version,
        get_elf32_entry_addr,
        get_elf32_prog_hdr_off,
        get_elf32_sect_hdr_off
};

static struct Elf elf64ops = {
        validate_elf64_ident,
        get_elf64_class,
        get_elf64_data_encoding,
        get_elf64_version_from_ident,
        get_elf64_object_type,
        get_elf64_architecture,
        get_elf64_version,
        get_elf64_entry_addr,
        get_elf64_prog_hdr_off,
        get_elf64_sect_hdr_off
};

static struct Elf *elfops = NULL;

int validate_elf_ident(void *data)
{
        if (IS_ELF32(data)) {
                elfops = &elf32ops;
        } else if (IS_ELF64(data)) {
                elfops = &elf64ops;
        }

        return elfops->validate_elf_ident(data);
}

char *get_elf_class(void *data)
{
        return elfops->get_elf_class(data);
}

char *get_elf_data_encoding(void *data)
{
        return elfops->get_elf_data_encoding(data);
}

uint32_t get_elf_version_from_ident(void *data)
{
        return elfops->get_elf_version_from_ident(data);
}

char *get_elf_object_type(void *data)
{
        return elfops->get_elf_object_type(data);
}

char *get_elf_architecture(void *data)
{
        return elfops->get_elf_architecture(data);
}

uint32_t get_elf_version(void *data)
{
        return elfops->get_elf_version(data);
}

uint32_t get_elf_entry_addr(void *data)
{
        return elfops->get_elf_entry_addr(data);
}

uint32_t get_elf_prog_hdr_off(void *data)
{
        return elfops->get_elf_prog_hdr_off(data);
}

uint32_t get_elf_sect_hdr_off(void *data)
{
        return elfops->get_elf_sect_hdr_off(data);
}

