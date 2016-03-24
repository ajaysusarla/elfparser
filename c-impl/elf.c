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

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include <errno.h>

#define IS_ELF32(elf) (((Elf32_Eheader*)elf)->e_ident[EI_CLASS] == ELFCLASS32)
#define IS_ELF64(elf) (((Elf64_Eheader*)elf)->e_ident[EI_CLASS] == ELFCLASS64)


struct _elfObject {
        unsigned char *data;
        size_t len;

        int        (*validate_elf_ident)(void *data);
        const char *(*get_elf_class)(void *data);
        const char *(*get_elf_data_encoding)(void *data);
        uint32_t   (*get_elf_version_from_ident)(void *data);
        const char *(*get_elf_object_type)(void *data);
        const char *(*get_elf_architecture)(void *data);
        uint32_t   (*get_elf_version)(void *data);
        uint32_t   (*get_elf_entry_addr)(void *data);
        uint32_t   (*get_elf_prog_hdr_off)(void *data);
        uint32_t   (*get_elf_sect_hdr_off)(void *data);
};


static ElfObject elf32ops = {
        NULL,
        0,
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

static ElfObject elf64ops = {
        NULL,
        0,
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

ElfObject *elf_object_init(const char *path)
{
        ElfObject *o = NULL;
        unsigned char *data;
        size_t siz;
        FILE *fp;
        struct stat sb;

        if (path == NULL || path[0] == '\0') {
                return NULL;
        }

        /* Get file size */
        if (stat(path, &sb) == -1) {
                perror("stat");
                return o;
        }

        data = malloc(sizeof(unsigned char) * sb.st_size);
        if (data == NULL) {
                perror("malloc");
                return NULL;
        }

        fp = fopen(path, "r");
        if (fp == NULL) {
                perror("fopen");
                free(data);
                return o;
        }

        siz = fread(data, sizeof(unsigned char), sb.st_size, fp);
        fclose(fp);

        if (siz < EI_NIDENT) {
                fprintf(stderr, "fread: Couldn't read elf header.\n");
                free(data);
                return o;
        }

        /* Validate as a 32bit ELF. */
        if (validate_elf32_ident(data) != 0) {
                fprintf(stderr, "Not a valid ELF file!\n");
                free(data);
                return NULL;
        }

        if (IS_ELF32(data)) {
                o = &elf32ops;
        } else if (IS_ELF64(data)) {
                o = &elf64ops;
        }

        o->data = data;
        o->len = siz;

        return o;
}

void elf_object_free(ElfObject **obj)
{
        if (*obj) {
                if ((*obj)->data) {
                        free((*obj)->data);
                }

                *obj = NULL;
        }
}


const char *elf_get_class(ElfObject *obj)
{
        if (obj == NULL || obj->data == NULL)
                return NULL;

        return obj->get_elf_class(obj->data);
}

const char *elf_get_data_encoding(ElfObject *obj)
{
        if (obj == NULL || obj->data == NULL)
                return NULL;

        return obj->get_elf_data_encoding(obj->data);
}

uint32_t elf_get_version_from_ident(ElfObject *obj)
{
        if (obj == NULL || obj->data == NULL)
                return -1;

        return obj->get_elf_version_from_ident(obj->data);
}

const char *elf_get_object_type(ElfObject *obj)
{
        if (obj == NULL || obj->data == NULL)
                return NULL;

        return obj->get_elf_object_type(obj->data);
}

const char *elf_get_architecture(ElfObject *obj)
{
        if (obj == NULL || obj->data == NULL)
                return NULL;

        return obj->get_elf_architecture(obj->data);
}

uint32_t elf_get_version(ElfObject *obj)
{
        if (obj == NULL || obj->data == NULL)
                return -1;

        return obj->get_elf_version(obj->data);
}

uint32_t elf_get_entry_addr(ElfObject *obj)
{
        if (obj == NULL || obj->data == NULL)
                return -1;

        return obj->get_elf_entry_addr(obj->data);
}

uint32_t elf_get_prog_hdr_off(ElfObject *obj)
{
        if (obj == NULL || obj->data == NULL)
                return -1;

        return obj->get_elf_prog_hdr_off(obj->data);
}

uint32_t elf_get_sect_hdr_off(ElfObject *obj)
{
        if (obj == NULL || obj->data == NULL)
                return -1;

        return obj->get_elf_sect_hdr_off(obj->data);
}
