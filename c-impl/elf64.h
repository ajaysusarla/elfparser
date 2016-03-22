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

#ifndef _ELF64_H_
#define _ELF64_H_

#include <stdint.h>

#include "elf-common.h"

typedef struct {
        unsigned char e_ident[EI_NIDENT];
        uint16_t      e_type;
        uint16_t      e_machine;
        uint32_t      e_version;
        uint64_t      e_entry;
        uint64_t      e_phoff;
        uint64_t      e_shoff;
        uint32_t      e_flags;
        uint16_t      e_ehsize;
        uint16_t      e_phentsize;
        uint16_t      e_phnum;
        uint16_t      e_shentsize;
        uint16_t      e_shnum;
        uint16_t      e_shstrndx;
} Elf64_Eheader;

int validate_elf64_ident(void *data);
char *get_elf64_class(void *data);
char *get_elf64_data_encoding(void *data);
uint32_t get_elf64_version_from_ident(void *data);
char *get_elf64_object_type(void *data);
char *get_elf64_architecture(void *data);
uint32_t get_elf64_version(void *data);
uint32_t get_elf64_entry_addr(void *data);
uint32_t get_elf64_prog_hdr_off(void *data);
uint32_t get_elf64_sect_hdr_off(void *data);


#endif  /* _ELF64_H_ */
