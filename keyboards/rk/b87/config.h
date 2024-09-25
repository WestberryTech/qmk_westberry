// Copyright 2024 yangzheng20003 (@yangzheng20003)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define USB_POWER_EN_PIN                    B1 // USB ENABLE pin
#define LED_POWER_EN_PIN                    A5 // LED ENABLE pin
#define HS_BAT_CABLE_PIN                    A7 // USB insertion detection pin

#define BAT_FULL_PIN                        A15
#define BAT_FULL_STATE                      1

#define HS_RGB_INDICATOR_COUNT              99
#define HS_RGB_BAT_COUNT                    1

/* Status Indicator Lamp */
#define HS_RGB_INDEX_CAPS                   0
#define HS_RGB_INDEX_WIN_LOCK               1
#define HS_RGB_BLINK_INDEX_VAI              0
#define HS_RGB_BLINK_INDEX_VAD              1
#define HS_RGB_BLINK_INDEX_SPI              2

#define HS_RGB_BLINK_INDEX_WIN              55
#define HS_RGB_BLINK_INDEX_MAC              56

/* Encoder */
#define ENCODER_MAP_KEY_DELAY               1

/* SPI */
#define SPI_DRIVER                          SPIDQ
#define SPI_SCK_PIN                         B3
#define SPI_MOSI_PIN                        B5
#define SPI_MISO_PIN                        B4

/* Flash */
#define EXTERNAL_FLASH_SPI_SLAVE_SELECT_PIN C12
#define WEAR_LEVELING_LOGICAL_SIZE          (WEAR_LEVELING_BACKING_SIZE / 2)

/* RGB Matrix */
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES

/* RGB Light */
#define RGBLED_NUM         8
#define RGBLIGHT_LED_COUNT RGBLED_NUM
#define RGBLIGHT_CUSTOM_DRIVER
// #define RGBLIGHT_LED_MAP { 0,1,2,3,4,5,6,7 }

/* RGB Lighting effects*/
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_EFFECT_ALTERNATING
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_CHRISTMAS
#define RGBLIGHT_EFFECT_KNIGHT
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_RGB_TEST
#define RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_EFFECT_TWINKLE
#define RGBLIGHT_DISABLE_KEYCODES

#define CUSTOM_RGBLIGHT_EFFECT_BREATHE_TABLE
#define CUSTOM_RGBLIGHT_EFFECT_RAINBOW_MOOD
#define CUSTOM_RGBLIGHT_EFFECT_RAINBOW_SWIRL

#define RGBLIGHT_DEFAULT_VAL 60
#define breathing_val        40
#define rainbow_mood         40
#define RGBLIGHT_SLEEP
#define RGBLIGHT_DEFAULT_MODE   14
#define LED_TYPE                RGB
/* WS2812 */
#define WS2812_SPI_DRIVER       SPIDM2
#define WS2812_SPI_DIVISOR      32
#define RGB_MATRIX_DEFAULT_MODE 13

/* rgb_record */
#define ENABLE_RGB_MATRIX_RGBR_PLAY
#define RGBREC_CHANNEL_NUM         4
#define EECONFIG_CONFINFO_USE_SIZE (4 + 16)
#define EECONFIG_RGBREC_USE_SIZE   (RGBREC_CHANNEL_NUM * MATRIX_ROWS * MATRIX_COLS * 2)
#define EECONFIG_USER_DATA_SIZE    (EECONFIG_RGBREC_USE_SIZE + EECONFIG_CONFINFO_USE_SIZE)
#define RGBREC_EECONFIG_ADDR       (uint8_t *)(EECONFIG_USER_DATABLOCK)
#define CONFINFO_EECONFIG_ADDR     (uint32_t *)((uint32_t)RGBREC_EECONFIG_ADDR + (uint32_t)EECONFIG_RGBREC_USE_SIZE)
