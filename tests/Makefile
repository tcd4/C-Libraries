####################
#
# Linux Makefile
#
####################


#
# Object Files
#

OBJECTS = $(patsubst %.c,%.o,$(wildcard *.c))


#
# Project Info
#

PROJECT = test


#
# Compiler Info
#

# clang
CC = gcc

# libraries
CLIB_LIBRARIES = CLib_C_Types.a
CLIB_PATH = ../libs

# includes
INCLUDE_PATHS = ../includes
INCLUDE_PARAMS = $(foreach d, $(INCLUDE_PATHS), -I$d)

# compiler flags
LFLAGS = -g -o $(PROJECT)
CFLAGS = -g $(INCLUDE_PARAMS) -Wall -pedantic -std=gnu99 -fgnu89-inline -Wno-unknown-pragmas -Wno-variadic-macros 
CLIB_LDFLAGS = $(foreach d, $(CLIB_LIBRARIES), $(CLIB_PATH)/$d)


#
# Compiling
#

$(PROJECT): $(OBJECTS)
	$(CC) $(OBJECTS) $(LFLAGS) $(CLIB_LDFLAGS)


#
# Directory Cleanup
#

clean:
	rm *.o $(PROJECT)
