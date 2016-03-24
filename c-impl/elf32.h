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
#ifndef _ELF32_H_
#define _ELF32_H_

#include <stdint.h>

#include "elf-common.h"

typedef struct {
        unsigned char e_ident[EI_NIDENT];
        uint16_t      e_type;
        uint16_t      e_machine;
        uint32_t      e_version;
        uint32_t      e_entry;
        uint32_t      e_phoff;
        uint32_t      e_shoff;
        uint32_t      e_flags;
        uint16_t      e_ehsize;
        uint16_t      e_phentsize;
        uint16_t      e_phnum;
        uint16_t      e_shentsize;
        uint16_t      e_shnum;
        uint16_t      e_shstrndx;
} Elf32_Eheader;

int validate_elf32_ident(void *data);
const char *get_elf32_class(void *data);
const char *get_elf32_data_encoding(void *data);
uint32_t get_elf32_version_from_ident(void *data);
const char *get_elf32_object_type(void *data);
const char *get_elf32_architecture(void *data);
uint32_t get_elf32_version(void *data);
uint32_t get_elf32_entry_addr(void *data);
uint32_t get_elf32_prog_hdr_off(void *data);
uint32_t get_elf32_sect_hdr_off(void *data);

#endif  /* _ELF32_H_ */
