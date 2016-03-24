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
#include <stdio.h>

#ifdef DEBUG
#define d(x) x
#else
#define d(x)
#endif


typedef struct _elfObject ElfObject;


ElfObject *elf_object_init(const char *path);
void elf_object_free(ElfObject **obj);

char *elf_get_class(ElfObject *obj);
char *elf_get_data_encoding(ElfObject *obj);
uint32_t elf_get_version_from_ident(ElfObject *obj);
char *elf_get_object_type(ElfObject *obj);
char *elf_get_architecture(ElfObject *obj);
uint32_t elf_get_version(ElfObject *obj);
uint32_t elf_get_entry_addr(ElfObject *obj);
uint32_t elf_get_prog_hdr_off(ElfObject *obj);
uint32_t elf_get_sect_hdr_off(ElfObject *obj);

#endif  /* _ELF_H_ */
