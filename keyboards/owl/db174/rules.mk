# MCU name
MCU = WB32FQ95

# Bootloader selection
BOOTLOADER = wb32-dfu

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
ENCODER_ENABLE = yes
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = custom
EEPROM_DRIVER = wear_leveling
WEAR_LEVELING_DRIVER = embedded_flash

RGB_MATRIX_CUSTOM_USER = yes # Enable custom RGB effect

VPATH += keyboards/owl/db174/common
SRC += rgb_driver.c
