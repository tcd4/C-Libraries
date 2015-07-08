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

PROJ_LIB = CLib_
PROJ = types
MAJ = 1
MIN = 0.1


#
# Documentation
#

DOXYGEN = doxygen


#
# Compiler Info
#

# CLang
CC = gcc

# Project Library
PROJ_LIB_PATH = ../../libs

# Used Libraries
CLIB_LIBS = CLib_stds.a
CLIB_PATH = ../../libs

# Includes
INC_PATHS = ../include ../../stds/include
INC_PARAMS = $(foreach d, $(INC_PATHS), -I$d)

# Compiler Flags
LFLAGS = -g -shared -Wl,-soname,$(PROJ_LIB)$(PROJ).so.$(MAJ) -o $(PROJ_LIB_PATH)/$(PROJ_LIB)$(PROJ).so.$(MAJ).$(MIN)
CFLAGS = -g -c -fPIC -Wall -pedantic -Wno-unknown-pragmas -Wno-variadic-macros $(INC_PARAMS)
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
	rm *.o $(PROJ_LIB_PATH)/$(PROJ_LIB)$(PROJ).*


#
# Static Library Creation
#

static:
	ar rcs $(PROJ_LIB_PATH)/$(PROJ_LIB)$(PROJ).a $(OBJS)


#
# Documentation Creation
#

docs:
	$(DOXYGEN) doxygen.cfg

