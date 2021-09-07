/*
    Copyright (C) 2021 Westberry Technology (ChangZhou) Corp., Ltd

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#pragma once

#include <ch.h>
#include <hal.h>

// HACK ALERT. This definition may not match your processor
// To Do. Work out correct value for EEPROM_PAGE_SIZE on the WB32F3G71x9 etc
#if defined(EEPROM_EMU_WB32F3G71x9)
#    define MCU_WB32F3G71x9
#elif defined(EEPROM_EMU_WB32F3G71xB)
#    define MCU_WB32F3G71xB
#elif defined(EEPROM_EMU_WB32F3G71xC)
#    define MCU_WB32F3G71xC
#else
#    error "not implemented."
#endif

#ifndef EEPROM_PAGE_SIZE
#    if defined(MCU_WB32F3G71x9) || defined(MCU_WB32F3G71xB) || defined(MCU_WB32F3G71xC)
#        define FEE_PAGE_SIZE (uint16_t)0x100  // Page size = 256Byte
#        define FEE_DENSITY_PAGES 4            // How many pages are used
#    else
#        error "No MCU type specified. Add something like -DMCU_WB32F3G71x9 to your compiler arguments (probably in a Makefile)."
#    endif
#endif

#ifndef EEPROM_START_ADDRESS
#    if defined(MCU_WB32F3G71x9)
#        define FEE_MCU_FLASH_SIZE 96
#    elif defined(MCU_WB32F3G71xB)
#        define FEE_MCU_FLASH_SIZE 128
#    elif defined(MCU_WB32F3G71xC)
#        define FEE_MCU_FLASH_SIZE 256
#    else
#        error "No MCU type specified. Add something like -DMCU_WB32F3G71x9 to your compiler arguments (probably in a Makefile)."
#    endif
#endif

typedef enum { FLASH_BUSY = 1, FLASH_ERROR_PG, FLASH_ERROR_WRP, FLASH_ERROR_OPT, FLASH_COMPLETE, FLASH_TIMEOUT, FLASH_BAD_ADDRESS } FLASH_Status;

// DONT CHANGE
// Choose location for the first EEPROM Page address on the top of flash
#define WB32_FLASH_BASE 0x8000000
#define FEE_PAGE_BASE_ADDRESS ((uint32_t)(0x8000000 + FEE_MCU_FLASH_SIZE * 1024 - FEE_DENSITY_PAGES * FEE_PAGE_SIZE))
#define FEE_DENSITY_BYTES (FEE_PAGE_SIZE * FEE_DENSITY_PAGES - 1)

// Use this function to initialize the functionality
uint16_t EEPROM_Init(void);
void     EEPROM_Erase(void);
uint16_t EEPROM_WriteDataByte(uint16_t Address, uint8_t DataByte);
uint8_t  EEPROM_ReadDataByte(uint16_t Address);
