CC_BIN = ../gcc-arm-none-eabi-6-2017-q1-update/bin/
CC = $(CC_BIN)arm-none-eabi-g++ -std=c++14
CC_OBJCPY = $(CC_BIN)arm-none-eabi-objcopy

OBJECTS = ./startup_stm32f103xb.o ./system_stm32f1xx.o ./main.o

DEVICE = STM32F103xB

CMSIS_INCLUDE = ../STM32Cube_FW_F1_V1.4.0/Drivers/CMSIS/Include

DEVICE_INCLUDE = ../STM32Cube_FW_F1_V1.4.0/Drivers/CMSIS/Device/ST/STM32F1xx/Include

LINKER = ./STM32F103XB_FLASH.ld

gpio: main.hex

main.hex: main.elf
	$(CC_OBJCPY) -Oihex main.elf main.hex

main.elf : $(OBJECTS)
	$(CC) -mcpu=cortex-m3 -mthumb -Wl,--gc-sections -T$(LINKER) $(OBJECTS) -g3 -O0 -o main.elf

%.o: %.cpp
	$(CC) -mcpu=cortex-m3 -mthumb -Wall -g3 -O0 -D$(DEVICE) -I$(CMSIS_INCLUDE) -I$(DEVICE_INCLUDE) -c $< -o $@ 

%.o: %.c
	$(CC) -mcpu=cortex-m3 -mthumb -Wall -g3 -O0 -D$(DEVICE) -I$(CMSIS_INCLUDE) -I$(DEVICE_INCLUDE) -c $< -o $@ 

%.o: %.s
	$(CC) -mcpu=cortex-m3 -mthumb -Wall -g3 -O0 -I$(CMSIS_INCLUDE) -I$(DEVICE_INCLUDE) -c $< -o $@ 

.PHONY: clean
clean:
	rm *.o main.hex main.elf
