###############################################################################
# Makefile for the project LCCDATMEGA8
###############################################################################

## General Flags
PROJECT = LCCDATMEGA8
MCU = atmega8
TARGET = LCCDATMEGA8.elf
CC = avr-gcc

## Options common to compile, link and assembly rules
COMMON = -mmcu=$(MCU)

## Compile options common for all C compilation units.
CFLAGS = $(COMMON)
CFLAGS += -Wall -gdwarf-2 -std=gnu99 -DF_CPU=8000000UL -Os -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums
CFLAGS += -MD -MP -MT $(*F).o -MF dep/$(@F).d 

## Assembly specific flags
ASMFLAGS = $(COMMON)
ASMFLAGS += $(CFLAGS)
ASMFLAGS += -x assembler-with-cpp -Wa,-gdwarf2

## Linker flags
LDFLAGS = $(COMMON)
LDFLAGS +=  -Wl,-Map=LCCDATMEGA8.map


## Intel Hex file production flags
HEX_FLASH_FLAGS = -R .eeprom -R .fuse -R .lock -R .signature

HEX_EEPROM_FLAGS = -j .eeprom
HEX_EEPROM_FLAGS += --set-section-flags=.eeprom="alloc,load"
HEX_EEPROM_FLAGS += --change-section-lma .eeprom=0 --no-change-warnings


## Objects that must be built in order to link
OBJECTS = LCCDATMEGA8.o com_def.o LCD.o 

## Objects explicitly added by the user
LINKONLYOBJECTS = 

## Build
all: $(TARGET) LCCDATMEGA8.hex LCCDATMEGA8.eep LCCDATMEGA8.lss size

## Compile
LCCDATMEGA8.o: ../LCCDATMEGA8.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

com_def.o: ../com_def.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

LCD.o: ../LCD.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

##Link
$(TARGET): $(OBJECTS)
	 $(CC) $(LDFLAGS) $(OBJECTS) $(LINKONLYOBJECTS) $(LIBDIRS) $(LIBS) -o $(TARGET)

%.hex: $(TARGET)
	avr-objcopy -O ihex $(HEX_FLASH_FLAGS)  $< $@

%.eep: $(TARGET)
	-avr-objcopy $(HEX_EEPROM_FLAGS) -O ihex $< $@ || exit 0

%.lss: $(TARGET)
	avr-objdump -h -S $< > $@

size: ${TARGET}
	@echo
	@avr-size -C --mcu=${MCU} ${TARGET}

## Clean target
.PHONY: clean
clean:
	-rm -rf $(OBJECTS) LCCDATMEGA8.elf dep/* LCCDATMEGA8.hex LCCDATMEGA8.eep LCCDATMEGA8.lss LCCDATMEGA8.map


## Other dependencies
-include $(shell mkdir dep 2>/dev/null) $(wildcard dep/*)

