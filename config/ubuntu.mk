include ./config/linux-tools.mk

CXX = g++
GCC = gcc
AS = as
LD = g++
OBJCOPY = objcopy
CSIZE = size

# Compiler options
CFLAGS = 
CFLAGS += -O0 
CFLAGS += -g 
#CFLAGS += -I.
CFLAGS += -I ./src

LDFLAGS = -std=c++11 

TARGET=ubuntu

CDEFINE = -DSIMULATION

#UPLOAD_CMD = $(SSH) $(SERVER) 'mkdir -p $(REMOTE_FOLDER)' && $(SCP) $(BUILDDIRECTORY)/$(PROJECT).elf $(SERVER):$(REMOTE_FOLDER) && $(SSH) $(SERVER) 'cd $(REMOTE_FOLDER);chmod +x $(PROJECT).elf;'

KILL_CMD = pkill -f $(PROJECT);

#START_CMD = $(SSH) $(SERVER) "sh -c 'cd $(REMOTE_FOLDER); ./$(PROJECT).elf > /dev/null 2>&1 &'"
