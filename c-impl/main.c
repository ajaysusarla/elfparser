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
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include <errno.h>

#ifdef DEBUG
#define d(x) x
#else
#define d(x)
#endif

int main(int argc, char **argv)
{
        void *data;
        size_t siz;
        FILE *fp;
        struct stat sb;

        if (argc != 2) {
                fprintf(stderr, "USAGE: %s <path-to-file>\n", argv[0]);
                exit(EXIT_FAILURE);
        }

        /* Get file size */
        if (stat(argv[1], &sb) == -1) {
                perror("stat");
                exit(EXIT_FAILURE);
        }

        data = malloc(sizeof(unsigned char) * sb.st_size);
        if (data == NULL) {
                perror("malloc");
                exit(EXIT_FAILURE);
        }

        fp = fopen(argv[1], "r");
        if (fp == NULL) {
                perror("fopen");
                exit(EXIT_FAILURE);
        }

        siz = fread(data, sizeof(unsigned char), sb.st_size, fp);
        d(printf(">> Read %zu bytes from %s.\n", siz, argv[1]));
        fclose(fp);

        if (siz < EI_NIDENT) {
                fprintf(stderr, "fread: Couldn't read elf header.\n");
                exit(EXIT_FAILURE);
        }

        if (validate_elf_ident(data) != 0) {
                fprintf(stderr, "Not a valid ELF file!\n");
                exit(EXIT_FAILURE);
        }

        printf("=== ELF info for `%s` ===\n", argv[1]);
        printf("Class          : %s\n", get_elf_class(data));
        printf("Data           : %s\n", get_elf_data_encoding(data));
        printf("Version        : %d\n", get_elf_version_from_ident(data));
        printf("Object Type    : %s\n", get_elf_object_type(data));
        printf("Architecture   : %s\n", get_elf_architecture(data));
        printf("Version        : %d\n", get_elf_version(data));
        printf("Entry Address  : 0x%x\n", get_elf_entry_addr(data));
        printf("\n");
        printf("Program Header offset  : %d\n", get_elf_prog_hdr_off(data));
        printf("Section Header offset  : %d\n", get_elf_sect_hdr_off(data));

        printf("\n");

        exit(EXIT_SUCCESS);
}
