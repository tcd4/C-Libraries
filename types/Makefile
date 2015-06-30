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

PROJECT = C_Types
VERSION_MAJOR = 1
VERSION_MINOR = 0.1


#
# Documentation
#

DOXYGEN = doxygen


#
# Compiler Info
#

# clang
CC = gcc

# library
LIBRARY_PATH = ../libs

# includes
INCLUDE_PATHS = ../includes
INCLUDE_PARAMS = $(foreach d, $(INCLUDE_PATHS), -I$d)

# compiler flags
LFLAGS = -g -shared -Wl,-soname,CLib_$(PROJECT).so.$(VERSION_MAJOR) -o $(LIBRARY_PATH)/CLib_$(PROJECT).so.$(VERSION_MAJOR).$(VERSION_MINOR)
CFLAGS = -g -c -fPIC -Wall -pedantic -Wno-unknown-pragmas -Wno-variadic-macros $(INCLUDE_PARAMS)


#
# Compiling
#

$(PROJECT): $(OBJECTS)
	$(CC) $(OBJECTS) $(LFLAGS)


#
# Directory Cleanup
#

clean:
	rm *.o $(LIBRARY_PATH)/clib_$(PROJECT).*


#
# Library Creation
#

static:
	ar rcs $(LIBRARY_PATH)/CLib_$(PROJECT).a $(OBJECTS)


#
# Documentation Creation
#

docs:
	$(DOXYGEN) doxgen.cfg

