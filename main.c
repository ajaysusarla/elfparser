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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <errno.h>

#ifdef DEBUG
#define d(x) x
#else
#define d(x)
#endif

int main(int argc, char **argv)
{
        Elf32_Eheader elf;
        void *ptr;
        size_t siz;
        FILE *fp;

        if (argc != 2) {
                fprintf(stderr, "USAGE: %s <path-to-file>\n", argv[0]);
                exit(EXIT_FAILURE);
        }

        fp = fopen(argv[1], "r");
        if (fp == NULL) {
                /* FIXME: Use strerror_l() instead? */
                fprintf(stderr, "fopen: %s\n", strerror(errno));
                exit(EXIT_FAILURE);
        }

        ptr = &elf;

        siz = fread(ptr, 1, sizeof(elf), fp);
        d(printf(">> Read %zu bytes from %s.\n", siz, argv[1]));
        fclose(fp);

        if (validate_elf_ident(&elf) != 0) {
                fprintf(stderr, "Invalid ELF file!\n");
                exit(EXIT_FAILURE);
        }

        printf("=== ELF info for `%s` ===\n", argv[1]);
        printf("Class: %s.\n", get_elf_class(&elf));
        printf("Data: %s\n", get_elf_data_encoding(&elf));
        printf("Version: %d\n", get_elf_version(&elf));
        printf("Object Type: %s\n", get_elf_object_type(&elf));

        printf("\n");

        exit(EXIT_SUCCESS);
}

