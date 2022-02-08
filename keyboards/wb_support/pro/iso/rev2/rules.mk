# MCU name
MCU = WB32F3G71

# Bootloader selection
BOOTLOADER = wb32-dfu

# Use SPI FLASH
EEPROM_DRIVER = custom       # Enable SPI flash memory
SRC +=  ../../../src/flash_spi.c \
        ../../../src/eeprom_flash.c \
        ../../src/wb32_spi_master.c
