CC = gcc

CWD := $(shell pwd)
# Platform
UNAME := $(shell $(CC) -dumpmachine 2>&1 | grep -E -o "linux|darwin")

ifeq ($(UNAME), linux)
OSFLAGS = -DLINUX
DEBUG = -ggdb
else ifeq ($(UNAME), darwin)
OSFLAGS = -DMACOSX
DEBUG = -g
else ifeq ($(UNAME), solaris)
OSFLAGS = -DSOLARIS
DEBUG = -g
endif

EXTRA_CFLAGS := -Wall -Wextra -pedantic
LIBS :=
CFLAGS := $(DEBUG) $(EXTRA_CFLAGS) $(OSFLAGS)
TEST_CFLAGS := $(CFLAGS) -I$(CWD)

all: elf elf32 elf64 main
	$(CC) $(CFLAGS) $(LIBS) \
		elf.o \
		elf32.o \
		elf64.o \
		main.o \
		-o elfparser

main: main.c
	$(CC) $(CFLAGS) -c main.c

elf: elf.c elf.h elf-common.h
	$(CC) $(CFLAGS) -c elf.c

elf32: elf32.h elf32.c
	$(CC) $(CFLAGS) -c elf32.c

elf64: elf64.h elf64.c
	$(CC) $(CFLAGS) -c elf64.c

clean:
	rm -rf *.o core elfparser

.PHONY: check-syntax

check-syntax:
	$(CC) $(CFLAGS) -Wextra -pedantic -fsyntax-only $(CHK_SOURCES)

