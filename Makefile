CROSS_COMPILE ?= arm-none-eabi-
CC := $(CROSS_COMPILE)gcc
CFLAGS = -fno-common -ffreestanding -O0 \
	 -gdwarf-2 -g3 -Wall -Werror \
	 -mcpu=cortex-m4 -mthumb \
	 -Wl,-Tmain.ld -nostartfiles \

hsi: main.c hsi.c startup.c
	$(CC) $(CFLAGS) $^ -o main.elf
	$(CROSS_COMPILE)objcopy -Obinary main.elf main.bin
	$(CROSS_COMPILE)objdump -S main.elf > main.list

hse: main.c hse.c startup.c
	$(CC) $(CFLAGS) $^ -o main.elf
	$(CROSS_COMPILE)objcopy -Obinary main.elf main.bin
	$(CROSS_COMPILE)objdump -S main.elf > main.list

pll_hsi: main.c pll_hsi.c startup.c
	$(CC) $(CFLAGS) $^ -o main.elf
	$(CROSS_COMPILE)objcopy -Obinary main.elf main.bin
	$(CROSS_COMPILE)objdump -S main.elf > main.list

pll_hse: main.c pll_hse.c startup.c
	$(CC) $(CFLAGS) $^ -o main.elf
	$(CROSS_COMPILE)objcopy -Obinary main.elf main.bin
	$(CROSS_COMPILE)objdump -S main.elf > main.list

FLASH_CMD := openocd \
	-f board/stm32f429discovery.cfg \
	-c "init" \
	-c "reset init" \
	-c "flash probe 0" \
	-c "flash info 0" \
	-c "stm32f2x mass_erase 0" \
	-c "flash write_bank 0 $(TARGET) 0x0" \
	-c "reset run" -c shutdown

flash: $(TARGET)
	$(shell ${FLASH_CMD})

clean:
	rm -f *.o *.bin *.elf *.list
