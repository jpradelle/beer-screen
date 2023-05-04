ifneq ($(filter $(MAKECMDGOALS),stm32f3),)
include Make-config-stm32f3.mk
else
	ifneq ($(filter $(MAKECMDGOALS),beaglebone),)
		include Make-config-beaglebone.mk
	else
		ifneq ($(filter $(MAKECMDGOALS),ubuntu),)
			include Make-config-ubuntu.mk
	    endif
	endif
endif

# the project is nameOfCurrentDirectory_target
PROJECT=$(shell $(BASENAME) $(CURDIR))_$(TARGET)

BUILDDIRECTORY = build/$(PROJECT)

DIRS=$(shell $(SH) -c "$(FIND) $(SOURCE_FOLDERS) -type d | $(SED) 's/$(SOURCE_FOLDERS) /./g'")

SRCS = $(shell $(FIND) $(SOURCE_FOLDERS) -name '*.cpp')
C_SRCS = $(shell $(FIND) $(SOURCE_FOLDERS) -name '*.c')
#AS_SRCS = $(shell $(FIND) $(SOURCE_FOLDERS) -name '*.S')
#AS_SRCS =

OBJS = $(patsubst %.cpp,$(BUILDDIRECTORY)/%.cpp.o,$(SRCS))
C_OBJS = $(patsubst %.c,$(BUILDDIRECTORY)/%.c.o,$(C_SRCS))
AS_OBJS = $(patsubst %.S,$(BUILDDIRECTORY)/%.S.o,$(AS_SRCS))
DEP_FILES := $(OBJS:.o=.d) $(C_OBJS:.o=.d)

# add defines into flags
CFLAGS += $(CDEFINE)

# for a better output
MSG_EMPTYLINE = .
MSG_COMPILING = ---COMPILE---
MSG_ASSEMBLING = ---ASSEMBLING---
MSG_LINKING = ---LINK---
MSG_SUCCESS = ---SUCCESS---
MSG_PREBUILD = ---PRE-BUILD---
MSG_POSTBUILD = ---POST-BUILD---
MSG_GENERATEOBJFILE = ---GENERATE-OBJFILE---

# Just a single newline! Note 2 blank lines are needed.
define NL


endef

# Our favourite
all:
	@echo the new build command is "make target build"
	@echo with target \= beaglebone or stm32f3 or ubuntu

build: pre-build $(PROJECT) post-build

beaglebone:
	@echo TARGET is beaglebone

stm32f3:
	@echo TARGET is stm32f3

ubuntu:
	@echo TARGET is ubuntu

# Linker call
$(PROJECT): $(BUILDDIRECTORY)/objects.list $(OBJS) $(C_OBJS) $(AS_OBJS)
	@echo $(MSG_EMPTYLINE)
	@echo $(MSG_LINKING)
	$(LD) -Wl,-Map=$(BUILDDIRECTORY)/$(PROJECT).map -o $(BUILDDIRECTORY)/$(PROJECT).elf  @"$(BUILDDIRECTORY)/objects.list" $(LDFLAGS)
	@echo $(MSG_EMPTYLINE)
	@echo $(MSG_SUCCESS) $(BUILDDIRECTORY)/$(PROJECT)

# Compiler call
$(BUILDDIRECTORY)/%.cpp.o: %.cpp
	@echo $(MSG_EMPTYLINE)
	@echo $(MSG_COMPILING)
	@echo $<
	$(CXX) -MMD -MP $(OPTS) -c -o $@ $< $(CFLAGS)

# Compiler call
$(BUILDDIRECTORY)/%.c.o: %.c
	@echo $(MSG_EMPTYLINE)
	@echo $(MSG_COMPILING)
	@echo $<
	$(GCC) -MMD -MP -c -o $@ $< $(CFLAGS)

# Assembler call
$(BUILDDIRECTORY)/%.S.o: %.S
	@echo $(MSG_EMPTYLINE)
	@echo $(MSG_ASSEMBLING)
	@echo $<
	$(AS) -c -o $@ $< $(ASFLAGS)

$(BUILDDIRECTORY)/objects.list: pre-build
	@echo $(MSG_EMPTYLINE)
	@echo $(MSG_GENERATEOBJFILE)
	$(SH) -c '$(REMOVE) -f $(BUILDDIRECTORY)/objects.list'
	$(foreach f, $(OBJS) $(C_OBJS) $(AS_OBJS) ,$(ECHO) $(f) >> $(BUILDDIRECTORY)/objects.list$(NL))
	@echo $(MSG_GENERATEOBJFILE_END)

removeObjList:
	$(REMOVE) -f $(BUILDDIRECTORY)/objects.list

pre-build:
	@echo $(MSG_EMPTYLINE)
	@echo $(MSG_PREBUILD)
	$(PREBUILDSCRIPT)
	$(SH) -c 'for i in $(DIRS); do $(MKDIR) -p $(BUILDDIRECTORY)/$$i; done;'

clean:
	$(REMOVE) -rf $(BUILDDIRECTORY)

post-build: $(PROJECT)
	@echo $(MSG_EMPTYLINE)
	@echo $(MSG_POSTBUILD)
	$(OBJCOPY) -O binary $(BUILDDIRECTORY)/$(PROJECT).elf $(BUILDDIRECTORY)/$(PROJECT).bin
	$(CSIZE) -B $(BUILDDIRECTORY)/$(PROJECT).elf

upload:
	$(UPLOAD_CMD)
kill:
	$(KILL_CMD)
start:
	$(START_CMD)

ifneq ($(filter $(MAKECMDGOALS),build),)
-include $(DEP_FILES)
endif
