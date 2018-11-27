# ========================================================================
# $File: Makefile $
# $Date: 2017-12-05 15:05:49 $
# $Revision: $
# $Creator: Jen-Chieh Shen $
# $Notice: See LICENSE.txt for modification and distribution information
#					Copyright © 2017 by Shen, Jen-Chieh $
# ========================================================================


### Library Makefile Template ###

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

# ----------------------------------------------- #
#					  Functions
# ----------------------------------------------- #
rwildcard = $(foreach d,$(wildcard $(addsuffix *,$(1))),$(call rwildcard,$(d)/,$(2)) $(filter $(subst *,%,$(2)),$(d)))

# ----------------------------------------------- #
#					   General
# ----------------------------------------------- #
# version number
VER		   = 1.0.1
ROOT_DIR   = .
# Enter the name of the build file. could either be a dynamic
# link, executable, etc.
BIN_NAME = libc-jcs

# ----------------------------------------------- #
#					 Directories
# ----------------------------------------------- #
# Build executable directory.
BIN_DIR = $(ROOT_DIR)/build/bin
# Build library directory.
ALIB_DIR = $(ROOT_DIR)/build/alib
# Build library directory.
SOLIB_DIR = $(ROOT_DIR)/build/solib

# ----------------------------------------------- #
#					   Commands
# ----------------------------------------------- #
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

# ----------------------------------------------- #
#					   Flags
# ----------------------------------------------- #
# assemble flags
ASM_FLAGS	  =
# disassemble flags
DASM_FLAGS	  = -D
# compile flags
C_FLAGS		  = -lcurl -fPIC
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

# ----------------------------------------------- #
#				   Source Path
# ----------------------------------------------- #
MAIN_PATH		= $(ROOT_DIR)/test
SOURCE_PATH		= $(ROOT_DIR)/src

# ----------------------------------------------- #
#				   Include Path
# ----------------------------------------------- #
INCLUDE_PATH   = $(ROOT_DIR)/include
INCLUDE_PATHS  = $(wildcard $(INCLUDE_PATH)/*)

# ----------------------------------------------- #
#				   Library path
# ----------------------------------------------- #
A_LIB_PATH	 = $(ROOT_DIR)/lib/alib
A_LIB_PATHS = $(wildcard $(A_LIB_PATH)/*)

SO_LIB_PATH	 := $(ROOT_DIR)/lib/solib
SO_LIB_PATHS := $(wildcard $(SO_LIB_PATH)/*)

# ----------------------------------------------- #
#					All Source
# ----------------------------------------------- #
# main source
MAINSRC := $(sort $(call rwildcard, $(MAIN_PATH)/, *.asm *.c *.cpp))
# asm source
ASMSRC	:= $(sort $(call rwildcard, $(SOURCE_PATH)/, *.asm *.inc))
# c/c++ source
GSRC	:= $(sort $(call rwildcard, $(SOURCE_PATH)/, *.c *.cpp))
# static link library source
ASRC	:= $(sort $(call rwildcard, $(SOURCE_PATH)/, *.c *.cpp)) \
		   $(sort $(call rwildcard, $(A_LIB_PATH)/, *.c *.cpp))
# shared link library source
SOSRC	:= $(sort $(call rwildcard, $(SOURCE_PATH), *.c *.cpp)) \
		   $(sort $(call rwildcard, $(SO_LIB_PATH)/, *.c *.cpp))

# ----------------------------------------------- #
#					   objs
# ----------------------------------------------- #
# main object file
MAINOBJ := $(patsubst %.c,%.o, $(patsubst %.cpp,%.o, $(MAINSRC)))
# asm object files
ASMOBJS := $(sort $(patsubst %.asm,%.o, $(patsubst %.inc,%.o, $(ASMSRC))))
# list of object files
OBJS	:= $(patsubst %.c,%.o, $(patsubst %.cpp,%.o, $(GSRC)))
# .a object files
AOBJS	:= $(patsubst %.c,%.o, $(patsubst %.cpp,%.o, $(ASRC)))
# .so object files
SOOBJS	:= $(patsubst %.c,%.o, $(patsubst %.cpp,%.o, $(SOSRC)))

# ----------------------------------------------- #
#					Dependencies
# ----------------------------------------------- #
DEPDIR := $(ROOT_DIR)/mkdepGDEP	  := $(patsubst %.c,$(DEPDIR)/%.d,$(patsubst %.cpp,$(DEPDIR)/%.d, $(GSRC)))
ASMDEP := $(patsubst %.asm,$(DEPDIR)/%.d,$(ASMSRC))


.PHONY : build compile clean realclean test

test :
	@echo "Test command..."

build :
	$(CC) $(GSRC) $(MAINSRC) \
	$(INCLUDE_FLAGS) $(INCLUDE_PATH) \
	$(LD_FLAGS) $(A_LIB_PATH) \
	$(OUTPUT_FLAGS) $(BIN_DIR)/$(BIN_NAME)


# compile all the source file to object file.
compile : $(MAINOBJ) $(OBJS) $(AOBJS) $(SOOBJS)

# Clean the project.
clean :
	rm -f $(MAINOBJ) $(OBJS) $(LOBJS)

realclean :
	rm -f $(MAINOBJ) $(OBJS) $(LOBJS) $(KASMOBJS) $(LASMOBJS) $(ALIB_DIR)/$(ALIB) $(SOLIB_DIR)/$(SOLIB)

# include dependencies.
-include $(GDEP)
-include $(ASMDEP)

program_main.o : program_main.c
	$(CC) $(C_FLAGS) $(OUTPUT_FLAGS) $@ $<

# compile assembly file to object file.
$(ASMOBJS) : $(ASMSRC)
	$(ASM) $< $(ASM_FLAGS) $(OUTPUT_FLAGS) $@

# generate static link library.
$(ALIB) : $(AOBJS)
	$(AR) $(AR_FLAGS) $(ALIB_DIR)/$@ $^

# generate shared link library.
$(SOLIB) : $(SOOBJS)
	$(CC) $(SOR_FLAGS) \
	$(OUTPUT_FLAGS) $(SOLIB_DIR)/$@ $^ $(C_FLAGS)
