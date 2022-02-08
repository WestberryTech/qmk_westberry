#pragma once

#include_next <mcuconf.h>

#if defined(WB32_SPI_USE_QSPI)
#    undef WB32_SPI_USE_QSPI
#    define WB32_SPI_USE_QSPI TRUE
#endif

#if defined STM32_SPI_USE_SPI1
#    undef STM32_SPI_USE_SPI1
#    define STM32_SPI_USE_SPI1 TRUE
#endif
