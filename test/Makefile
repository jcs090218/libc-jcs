# ========================================================================
# $File: Makefile $
# $Date: 2017-12-04 15:02:51 $
# $Revision: $
# $Creator: Jen-Chieh Shen $
# $Notice: See LICENSE.txt for modification and distribution information
#					Copyright © 2017 by Shen, Jen-Chieh $
# ========================================================================


### Application Makefile Template ###

#----------------------------------------------
# JayCeS project directories preference.
#----------------------------------------------
# .
# ├── build
# │   ├── alib
# │   └── bin
# │   └── solib
# ├── data
# ├── doc
# ├── lib
# │   ├── alib
# │   └── solib
# ├── misc
# ├── src
# └── test
#----------------------------------------------

### General ###
# version number
VER		   = 1.0.1
ROOT_DIR   = ..
# Enter the name of the build file. could either be a dynamic
# link, executable, etc.
BIN_NAME = libc-jcs-test

### Directories ###
# Build executable directory.
BIN_DIR = $(ROOT_DIR)/build/bin
# Build library directory.
ALIB_DIR = $(ROOT_DIR)/build/alib
# Build library directory.
SOLIB_DIR = $(ROOT_DIR)/build/solib

### Commands ###
# assembler type
ASM	 = nasm
# disassembler commands
DAMS = objdump
# compiler type
CC	 = gcc
# linker commands
LD	 = ld
# compile lib file commands
AR	 = ar

### Flags ##
# assemble flags
ASM_FLAGS	  =
# disassemble flags
DASM_FLAGS	  = -D
# compile flags
C_FLAGS		  = -Wall
# linker flags
LD_FLAGS	  = -L
# include flags
INCLUDE_FLAGS = -I
# static link flags
AR_FLAGS	  = rcs
# dynamic link flags
SOR_FLAGS	  = -shared
# output flags
OUTPUT_FLAGS  = -o

### Library File ###
# static link library
ALIB  = default_static_lib_name.a
# dynamic link library
SOLIB = default_shared_lib_name.so

### Source Path ###
SOURCE_PATH		= $(ROOT_DIR)/test

### Include Path ###
INCLUDE_PATH   = $(ROOT_DIR)/include
INCLUDE_PATHS  = $(wildcard $(INCLUDE_PATH)/*)

### Library path ###
STATIC_LIB_PATH	 = $(ROOT_DIR)/lib/alib
STATIC_LIB_PATHS = $(wildcard $(STATIC_LIB_PATH)/*)

SHARED_LIB_PATH	 := $(ROOT_DIR)/lib/solib
SHARED_LIB_PATHS := $(wildcard $(SHARED_LIB_PATH)/*)

### All Source ###
# asm source
ASMSRC := $(wildcard $(SOURCE_PATH)/*.asm)
# c/c++ source
GSRC   := $(wildcard $(SOURCE_PATH)/*.c $(SOURCE_PATH)/*.cpp)
# static link library
ASRC   := $(wildcard $(SOURCE_PATH)/*.c $(SOURCE_PATH)/*.cpp $(STATIC_LIB_PATH)/*.c $(STATIC_LIB_PATH)/*.cpp)
# shared link library
SOSRC  := $(wildcard $(SOURCE_PATH)/*.c $(SOURCE_PATH)/*.cpp $(SHARED_LIB_PATH)/*.c $(SHARED_LIB_PATH)/*.cpp)

### objs ###
# list of object files
OBJS   := $(patsubst %.c,%.o, $(patsubst %.cpp,%.o, $(GSRC)))
# .a object files
AOBJS  := $(patsubst %.c,%.o, $(patsubst %.cpp,%.o, $(ASRC)))
# .so object files
SOOBJS := $(patsubst %.c,%.o, $(patsubst %.cpp,%.o, $(SOSRC)))

### ASM objs ###
ASMOBJS := $(subst .asm,.o,$(ASMSRC))

### Dependencies ###
DEPDIR := $(ROOT_DIR)/mkdepGDEP	  := $(patsubst %.c,$(DEPDIR)/%.d,$(patsubst %.cpp,$(DEPDIR)/%.d, $(GSRC)))
ASMDEP := $(patsubst %.asm,$(DEPDIR)/%.d,$(ASMSRC))


.PHONY : build compile clean realclean

build :
	$(CC) $(GSRC) \
	$(INCLUDE_FLAGS) $(INCLUDE_PATH) \
	$(LD_FLAGS) $(STATIC_LIB_PATH) \
	$(OUTPUT_FLAGS) $(BIN_DIR)/$(BIN_NAME)


# compile all the source file to object file.
compile : $(OBJS) $(AOBJS) $(SOOBJS)

# Clean the project.
clean :
	rm -f $(OBJS) $(LOBJS)

realclean :
	rm -f $(OBJS) $(LOBJS) $(KASMOBJS) $(LASMOBJS) $(ALIB) $(SOLIB)

# include dependencies.
-include $(GDEP)
-include $(ASMDEP)

# example of compile the program main file.
program_main.o : program_main.c
	$(CC) $(C_FLAGS) $(OUTPUT_FLAGS) $@ $<

# generate static link library.
$(ALIB) : $(AOBJS)
	$(AR) $(AR_FLAGS) $(ALIB_DIR)/$@ $<

# generate shared link library.
$(SOLIB) : $(SOOBJS)
	$(CC) $(SOR_FLAGS) \
	$(OUTPUT_FLAGS) $(SOLIB_DIR)/$@ $<
