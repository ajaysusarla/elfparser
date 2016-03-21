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

all: elfparser main.c
	$(CC) $(CFLAGS) -c main.c
	$(CC) $(CFLAGS) $(LIBS) elfparser.o main.o -o elfparser

elfparser: elfparser.c elfparser.h
	$(CC) $(CFLAGS) -c elfparser.c

clean:
	rm -rf *.o core elfparser

.PHONY: check-syntax

check-syntax:
	$(CC) $(CFLAGS) -Wextra -pedantic -fsyntax-only $(CHK_SOURCES)

