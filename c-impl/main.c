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

#include <stdio.h>
#include <stdlib.h>

#include <errno.h>

int main(int argc, char **argv)
{
        ElfObject *elf = NULL;

        if (argc != 2) {
                fprintf(stderr, "USAGE: %s <path-to-file>\n", argv[0]);
                exit(EXIT_FAILURE);
        }

        elf = elf_object_init(argv[1]);
        if (elf == NULL) {
                exit(EXIT_FAILURE);
        }

        printf("=== ELF info for `%s` ===\n", argv[1]);
        printf("Class          : %s\n", elf_get_class(elf));
        printf("Data           : %s\n", elf_get_data_encoding(elf));
        printf("Version        : %d\n", elf_get_version_from_ident(elf));
        printf("Object Type    : %s\n", elf_get_object_type(elf));
        printf("Architecture   : %s\n", elf_get_architecture(elf));
        printf("Version        : %d\n", elf_get_version(elf));
        printf("Entry Address  : 0x%x\n", elf_get_entry_addr(elf));
        printf("\n");
        printf("Program Header offset  : %d\n", elf_get_prog_hdr_off(elf));
        printf("Section Header offset  : %d\n", elf_get_sect_hdr_off(elf));

        printf("\n");

        elf_object_free(&elf);

        exit(EXIT_SUCCESS);
}
