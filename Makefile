# ========================================================================
# $File: Makefile $
# $Date: 2017-12-04 08:00:03 $
# $Revision: $
# $Creator: Jen-Chieh Shen $
# $Notice: See LICENSE.txt for modification and distribution information
#					Copyright © 2017 by Shen, Jen-Chieh $
# ========================================================================


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
ROOT_DIR   = .
# Enter the name of the build file. could either be a dynamic
# link, executable, etc.
BUILD_NAME = libc-jcs

### Directories ###
# Build executable directory.
BIN_DIR = $(ROOT_DIR)/build/bin
# Build static library directory.
ALIB_DIR = $(ROOT_DIR)/build/alib
# Build shared library directory.
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

### Flags ###
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
ALIB  = libc-jcs.a
# dynamic link library
SOLIB = libc-jcs.so

### Source Path ###
SOURCE_PATH		= $(ROOT_DIR)/src
MAIN_PATH		= $(ROOT_DIR)/test

### Include Path ###
INCLUDE_PATH   = $(ROOT_DIR)/include
INCLUDE_PATHS  = $(wildcard $(INCLUDE_PATH)/*)

### Library path ###
STATIC_LIB_PATH	 = $(ROOT_DIR)/src
STATIC_LIB_PATHS = $(wildcard $(STATIC_LIB_PATH)/*)

SHARED_LIB_PATH	 := $(ROOT_DIR)/src
SHARED_LIB_PATHS := $(wildcard $(SHARED_LIB_PATH)/*)

### All Source ###
# main source
MAINSRC := $(wildcard $(MAIN_PATH)/*.asm $(MAIN_PATH)/*.c $(MAIN_PATH)/*.cpp)
# asm source
ASMSRC	:= $(wildcard $(SOURCE_PATH)/*.asm)
# c/c++ source
GSRC	:= $(wildcard $(SOURCE_PATH)/*.c $(SOURCE_PATH)/*.cpp)
# static link library source
ASRC	:= $(wildcard $(SOURCE_PATH)/*.c $(SOURCE_PATH)/*.cpp $(STATIC_LIB_PATH)/*.c $(STATIC_LIB_PATH)/*.cpp)
# shared link library source
SOSRC	:= $(wildcard $(SOURCE_PATH)/*.c $(SOURCE_PATH)/*.cpp $(SHARED_LIB_PATH)/*.c $(SHARED_LIB_PATH)/*.cpp)

### objs ###
# main object file
MAINOBJ := $(patsubst %.c,%.o, $(patsubst %.cpp,%.o, $(MAINSRC)))
# list of object files
OBJS	:= $(patsubst %.c,%.o, $(patsubst %.cpp,%.o, $(GSRC)))
# .a object files
AOBJS	:= $(patsubst %.c,%.o, $(patsubst %.cpp,%.o, $(ASRC)))
# .so object files
SOOBJS	:= $(patsubst %.c,%.o, $(patsubst %.cpp,%.o, $(SOSRC)))

### ASM objs ###
ASMOBJS := $(subst .asm,.o,$(ASMSRC))

### Dependencies ###
DEPDIR := $(ROOT_DIR)/mkdepGDEP	  := $(patsubst %.c,$(DEPDIR)/%.d,$(patsubst %.cpp,$(DEPDIR)/%.d, $(GSRC)))
ASMDEP := $(patsubst %.asm,$(DEPDIR)/%.d,$(ASMSRC))


.PHONY : build compile clean realclean test

test :
	echo "Test command..."

build :
	$(CC) $(GSRC) $(MAINSRC) \
	$(INCLUDE_FLAGS) $(INCLUDE_PATH) \
	$(LD_FLAGS) $(STATIC_LIB_PATH) \
	$(OUTPUT_FLAGS) $(BIN_DIR)/$(BUILD_NAME)

# compile all the source file to object file.
compile : $(MAINOBJ) $(OBJS) $(AOBJS) $(SOOBJS)

# Clean the project.
clean :
	rm -f $(MAINOBJ) $(OBJS) $(LOBJS)

realclean :
	rm -f $(MAINOBJ) $(OBJS) $(LOBJS) $(KASMOBJS) $(LASMOBJS) $(ALIB) $(SOLIB)

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
