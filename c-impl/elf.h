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

#ifndef _ELF_H_
#define _ELF_H_

#include "elf-common.h"

#include <stdint.h>

int validate_elf_ident(void *data);
char *get_elf_class(void *data);
char *get_elf_data_encoding(void *data);
uint32_t get_elf_version_from_ident(void *data);
char *get_elf_object_type(void *data);
char *get_elf_architecture(void *data);
uint32_t get_elf_version(void *data);
uint32_t get_elf_entry_addr(void *data);
uint32_t get_elf_prog_hdr_off(void *data);
uint32_t get_elf_sect_hdr_off(void *data);

#endif  /* _ELF_H_ */
