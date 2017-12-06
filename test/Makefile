# ========================================================================
# $File: Makefile $
# $Date: 2017-12-06 14:46:52 $
# $Revision: $
# $Creator: Jen-Chieh Shen $
# $Notice: See LICENSE.txt for modification and distribution information
#					Copyright © 2017 by Shen, Jen-Chieh $
# ========================================================================


VER		   = 1.0.1
ROOT_DIR   = ..

MAIN_BIN = libc-jcs
CLIENT_BIN = libc-jcs-client
SERVER_BIN = libc-jcs-server

### Flags ##
ASM_FLAGS	  =
DASM_FLAGS	  = -D
C_FLAGS		  = -Wall
LD_FLAGS	  = -L
INCLUDE_FLAGS = -I
AR_FLAGS	  = rcs
SOR_FLAGS	  = -shared
OUTPUT_FLAGS  = -o

SOURCE_PATH		= $(ROOT_DIR)/src

### Include Path ###
INCLUDE_PATH   = $(ROOT_DIR)/include
INCLUDE_PATHS  = $(wildcard $(INCLUDE_PATH)/*)

### Library path ###
A_LIB_PATH	 = $(ROOT_DIR)/lib/alib
A_LIB_PATHS = $(wildcard $(A_LIB_PATH)/*)

SO_LIB_PATH	 := $(ROOT_DIR)/lib/solib
SO_LIB_PATHS := $(wildcard $(SO_LIB_PATH)/*)

### All Source ###
GSRC	:= $(wildcard $(SOURCE_PATH)/*.c $(SOURCE_PATH)/*.cpp)


.PHONY : build compile clean realclean test

build :
	$(CC) $(GSRC) ./main.c \
	$(INCLUDE_FLAGS) $(INCLUDE_PATH) \
	$(LD_FLAGS) $(A_LIB_PATH) \
	$(OUTPUT_FLAGS) $(ROOT_DIR)/build/bin/$(MAIN_BIN)

buildclient :
	$(CC) $(GSRC) ./client_main.c \
	$(INCLUDE_FLAGS) $(INCLUDE_PATH) \
	$(LD_FLAGS) $(A_LIB_PATH) \
	$(OUTPUT_FLAGS) $(ROOT_DIR)/build/bin/$(CLIENT_BIN)

buildserver :
	$(CC) $(GSRC) ./server_main.c \
	$(INCLUDE_FLAGS) $(INCLUDE_PATH) \
	$(LD_FLAGS) $(A_LIB_PATH) \
	$(OUTPUT_FLAGS) $(ROOT_DIR)/build/bin/$(SERVER_BIN)
