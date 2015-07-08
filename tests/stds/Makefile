####################
#
# Linux Makefile
#
####################


#
# Object Files
#

OBJS = $(patsubst %.c,%.o,$(wildcard *.c))


#
# Project Info
#

PROJ = test


#
# Compiler Info
#

# clang
CC = gcc

# libraries
CLIB_LIBS = CLib_stds.a
CLIB_PATH = ../../libs

# includes
INC_PATHS = ../../stds/include
INC_PARAMS = $(foreach d, $(INC_PATHS), -I$d)

# compiler flags
LFLAGS = -g -o $(PROJ)
CFLAGS = -g $(INC_PARAMS) -Wall -pedantic -std=gnu99 -fgnu89-inline -Wno-unknown-pragmas -Wno-variadic-macros 
CLIB_LDFLAGS = $(foreach d, $(CLIB_LIBS), $(CLIB_PATH)/$d)


#
# Compiling
#

$(PROJ): $(OBJS)
	$(CC) $(OBJS) $(LFLAGS) $(CLIB_LDFLAGS)


#
# Directory Cleanup
#

clean:
	rm *.o $(PROJ)
