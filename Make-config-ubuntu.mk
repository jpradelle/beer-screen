include ./config/ubuntu.mk

#install: sudo apt install libsdl2-dev

SOURCE_FOLDERS = src 

# Compiler options
CFLAGS = 
CFLAGS += -O0 
CFLAGS += -g 
#CFLAGS += -I.
CFLAGS += -I ./src
#CFLAGS += -lSDL2 -I/usr/include/SDL2 -D_REENTRANT

LDFLAGS = -std=c++11 -lSDL2 # -l SDL -l SDL_gfx

CDEFINE = -DSIMULATION

START_CMD =  $(shell $(SH) -c "./$(BUILDDIRECTORY)/$(PROJECT).elf")
