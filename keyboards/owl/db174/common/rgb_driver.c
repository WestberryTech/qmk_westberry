#include QMK_KEYBOARD_H
#include <string.h>
#include "util.h"
#include "matrix.h"
#include "debounce.h"
#include "quantum.h"
#include "rgb_matrix.h"
#include "rgb_driver.h"

#define SCAN_PWM_FREQ 65536 // 31250

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} __attribute__((packed)) rgb_t;

static volatile uint32_t sw_scan_index = 0;
static volatile uint32_t sw_line_active = 0;
static matrix_row_t rt_matrix[MATRIX_ROWS] = {0};
static pin_t row_pins[MATRIX_ROWS] = MATRIX_ROW_PINS;
static pin_t col_pins[MATRIX_COLS] = MATRIX_COL_PINS;

__IO rgb_t g_pwm_buffer[MATRIX_ROWS][5] = {0};

static void gpt1cb(void);
static bool select_row(uint8_t row);
static void unselect_row(uint8_t row);
static void rt_matrix_read_cols_on_row(matrix_row_t current_matrix[], uint8_t current_row);

static void gpt1cb(void) {

  if (sw_line_active == 0) {
    rgb_t color;

    TIM1->ARR = 255;
    select_row(sw_scan_index);
    sw_line_active = 1;

    color      = g_pwm_buffer[sw_scan_index][0];
    TIM1->CCR1 = 256 - color.r;
    TIM1->CCR2 = 256 - color.g;
    TIM1->CCR3 = 256 - color.b;
    color      = g_pwm_buffer[sw_scan_index][1];
    TIM2->CCR1 = 256 - color.r;
    TIM2->CCR2 = 256 - color.g;
    TIM2->CCR3 = 256 - color.b;
    color      = g_pwm_buffer[sw_scan_index][2];
    TIM2->CCR4 = 256 - color.r;
    TIM3->CCR1 = 256 - color.g;
    TIM3->CCR2 = 256 - color.b;
    color      = g_pwm_buffer[sw_scan_index][3];
    TIM3->CCR3 = 256 - color.r;
    TIM3->CCR4 = 256 - color.g;
    TIM4->CCR1 = 256 - color.b;
    color      = g_pwm_buffer[sw_scan_index][4];
    TIM4->CCR2 = 256 - color.r;
    TIM4->CCR3 = 256 - color.g;
    TIM4->CCR4 = 256 - color.b;

    TIM1->CCER |= TIM_CCER_CC1E | TIM_CCER_CC2E | TIM_CCER_CC3E;
    TIM4->CR1 |= TIM_CR1_CEN;
    TIM3->CR1 |= TIM_CR1_CEN;
    TIM2->CR1 |= TIM_CR1_CEN;
  } else {
    rt_matrix_read_cols_on_row(rt_matrix, sw_scan_index);
    unselect_row(sw_scan_index);
    sw_line_active = 0;
    sw_scan_index  = (sw_scan_index + 1) % MATRIX_ROWS;
    TIM1->CCER &= ~(TIM_CCER_CC1E | TIM_CCER_CC2E | TIM_CCER_CC3E);
    TIM1->ARR = 100;
  }

  TIM1->CR1 |= TIM_CR1_CEN;
}

static void wb32_tim_base_init(TIM_TypeDef *TIMx) {
  uint16_t tmpcr1 = 0;

  TIMx->CR1 |= TIM_CR1_URS;

  tmpcr1 = TIMx->CR1;
  tmpcr1 &= (uint16_t)(~((uint16_t)(TIM_CR1_DIR | TIM_CR1_CMS)));
  tmpcr1 |= ((uint16_t)0x0000); // TIM_CounterMode_Up
  tmpcr1 &= (uint16_t)(~((uint16_t)TIM_CR1_CKD));
  tmpcr1 |= ((uint16_t)0x0000); // TIM_CKD_DIV1
  TIMx->CR1 = tmpcr1;

  TIMx->ARR = 255;

  TIMx->PSC = ((WB32_TIMCLK1 / SCAN_PWM_FREQ) / 256) - 1;
  ;

  TIMx->EGR = 0x01;

  TIMx->CR1 |= TIM_CR1_OPM;

  if (TIMx == TIM1) {
    TIMx->RCR = 0;
    TIMx->SR = ~((uint16_t)0x0001);
    TIMx->DIER |= ((uint16_t)0x0001);
    nvicEnableVector(WB32_TIM1_UP_NUMBER, WB32_GPT_TIM1_IRQ_PRIORITY);
  }
}

static void wb32_tim_pwm_ch1_init(TIM_TypeDef *TIMx) {
  uint16_t tmpccmrx = 0, tmpccer = 0, tmpcr2 = 0;

  TIMx->CCER &= (uint16_t)(~(uint16_t)TIM_CCER_CC1E);

  tmpccer  = TIMx->CCER;
  tmpcr2   = TIMx->CR2;
  tmpccmrx = TIMx->CCMR1;

  tmpccmrx &= (uint16_t)(~((uint16_t)TIM_CCMR1_OC1M));
  tmpccmrx &= (uint16_t)(~((uint16_t)TIM_CCMR1_CC1S));

  tmpccmrx |= 0x70; // TIM_OCMode_PWM2
  tmpccer &= (uint16_t)(~((uint16_t)TIM_CCER_CC1P));
  tmpccer |= 0x00; // TIM_OCPolarity_High
  tmpccer |= 0x01; // TIM_OutputState_Enable

  if (TIMx == TIM1) {
    tmpccer &= (uint16_t)(~0x01); // TIM_OutputState_Disable

    tmpccer &= (uint16_t)(~((uint16_t)TIM_CCER_CC1NP));
    tmpccer |= 0x00; // TIM_OCNPolarity_High

    tmpccer &= (uint16_t)(~((uint16_t)TIM_CCER_CC1NE));
    tmpccer |= 0x00; // TIM_OutputNState_Disable

    tmpcr2 &= (uint16_t)(~((uint16_t)TIM_CR2_OIS1));
    tmpcr2 &= (uint16_t)(~((uint16_t)TIM_CR2_OIS1N));

    tmpcr2 |= 0x00; // TIM_OCIdleState_Reset
    tmpcr2 |= 0x00; // TIM_OCNIdleState_Reset
  }

  TIMx->CR2   = tmpcr2;
  TIMx->CCMR1 = tmpccmrx;
  TIMx->CCR1  = 256;
  TIMx->CCER  = tmpccer;
}

static void wb32_tim_pwm_ch2_init(TIM_TypeDef *TIMx) {
  uint16_t tmpccmrx = 0, tmpccer = 0, tmpcr2 = 0;

  TIMx->CCER &= (uint16_t)(~(uint16_t)TIM_CCER_CC2E);

  tmpccer  = TIMx->CCER;
  tmpcr2   = TIMx->CR2;
  tmpccmrx = TIMx->CCMR1;

  tmpccmrx &= (uint16_t)(~((uint16_t)TIM_CCMR1_OC2M));
  tmpccmrx &= (uint16_t)(~((uint16_t)TIM_CCMR1_CC2S));

  tmpccmrx |= (0x70 << 8); // TIM_OCMode_PWM2
  tmpccer &= (uint16_t)(~((uint16_t)TIM_CCER_CC2P));
  tmpccer |= (0x00 << 4); // TIM_OCPolarity_High
  tmpccer |= (0x01 << 4); // TIM_OutputState_Enable

  if (TIMx == TIM1) {
    tmpccer &= (uint16_t)(~(((uint16_t)0x01) << 4)); // TIM_OutputState_Disable
    tmpccer &= (uint16_t)(~((uint16_t)TIM_CCER_CC2NP));
    tmpccer |= (0x00 << 4); // TIM_OCNPolarity_High

    tmpccer &= (uint16_t)(~((uint16_t)TIM_CCER_CC2NE));
    tmpccer |= (0x00 << 4); // TIM_OutputNState_Disable

    tmpcr2 &= (uint16_t)(~((uint16_t)TIM_CR2_OIS2));
    tmpcr2 &= (uint16_t)(~((uint16_t)TIM_CR2_OIS2N));

    tmpcr2 |= (0x00 << 2); // TIM_OCIdleState_Reset
    tmpcr2 |= (0x00 << 2); // TIM_OCNIdleState_Reset
  }

  TIMx->CR2   = tmpcr2;
  TIMx->CCMR1 = tmpccmrx;
  TIMx->CCR2  = 256;
  TIMx->CCER  = tmpccer;
}

static void wb32_tim_pwm_ch3_init(TIM_TypeDef *TIMx) {
  uint16_t tmpccmrx = 0, tmpccer = 0, tmpcr2 = 0;

  TIMx->CCER &= (uint16_t)(~(uint16_t)TIM_CCER_CC3E);

  tmpccer  = TIMx->CCER;
  tmpcr2   = TIMx->CR2;
  tmpccmrx = TIMx->CCMR2;

  tmpccmrx &= (uint16_t)(~((uint16_t)TIM_CCMR2_OC3M));
  tmpccmrx &= (uint16_t)(~((uint16_t)TIM_CCMR2_CC3S));

  tmpccmrx |= 0x70; // TIM_OCMode_PWM2
  tmpccer &= (uint16_t)(~((uint16_t)TIM_CCER_CC3P));
  tmpccer |= (0x00 << 8); // TIM_OCPolarity_High
  tmpccer |= (0x01 << 8); // TIM_OutputState_Enable

  if (TIMx == TIM1) {
    tmpccer &= (uint16_t)(~(((uint16_t)0x01) << 8)); // TIM_OutputState_Disable
    tmpccer &= (uint16_t)(~((uint16_t)TIM_CCER_CC3NP));
    tmpccer |= (0x00 << 8); // TIM_OCNPolarity_High
    tmpccer &= (uint16_t)(~((uint16_t)TIM_CCER_CC3NE));

    tmpccer |= (0x00 << 8); // TIM_OutputNState_Disable
    tmpcr2 &= (uint16_t)(~((uint16_t)TIM_CR2_OIS3));
    tmpcr2 &= (uint16_t)(~((uint16_t)TIM_CR2_OIS3N));
    tmpcr2 |= (0x00 << 4); // TIM_OCIdleState_Reset
    tmpcr2 |= (0x00 << 4); // TIM_OCNIdleState_Reset
  }

  TIMx->CR2   = tmpcr2;
  TIMx->CCMR2 = tmpccmrx;
  TIMx->CCR3  = 256;
  TIMx->CCER  = tmpccer;
}

static void wb32_tim_pwm_ch4_init(TIM_TypeDef *TIMx) {
  uint16_t tmpccmrx = 0, tmpccer = 0, tmpcr2 = 0;

  TIMx->CCER &= (uint16_t)(~(uint16_t)TIM_CCER_CC4E);

  tmpccer  = TIMx->CCER;
  tmpcr2   = TIMx->CR2;
  tmpccmrx = TIMx->CCMR2;

  tmpccmrx &= (uint16_t)(~((uint16_t)TIM_CCMR2_OC4M));
  tmpccmrx &= (uint16_t)(~((uint16_t)TIM_CCMR2_CC4S));

  tmpccmrx |= (0x70 << 8); // TIM_OCMode_PWM2
  tmpccer &= (uint16_t)(~((uint16_t)TIM_CCER_CC4P));
  tmpccer |= (0x00 << 12); // TIM_OCPolarity_High
  tmpccer |= (0x01 << 12); // TIM_OutputState_Enable

  if (TIMx == TIM1) {
    tmpccer &= (uint16_t)(~(((uint16_t)0x01) << 12)); // TIM_OutputState_Disable
    tmpcr2 &= (uint16_t)(~((uint16_t)TIM_CR2_OIS4));
    tmpcr2 |= (uint16_t)(0x00 << 6); // TIM_OCIdleState_Reset
  }

  TIMx->CR2   = tmpcr2;
  TIMx->CCMR2 = tmpccmrx;
  TIMx->CCR4  = 256;
  TIMx->CCER  = tmpccer;
}

static void wb32_pwm_init(void) {

  /* Enable TIM clock */
  rccEnableTIM1();
  rccEnableTIM2();
  rccEnableTIM3();
  rccEnableTIM4();

  /* Reset TIM */
  rccResetTIM1();
  rccResetTIM2();
  rccResetTIM3();
  rccResetTIM4();

  /* Config TIM */
  wb32_tim_base_init(TIM2);
  wb32_tim_pwm_ch1_init(TIM2);
  wb32_tim_pwm_ch2_init(TIM2);
  wb32_tim_pwm_ch3_init(TIM2);
  wb32_tim_pwm_ch4_init(TIM2);
  wb32_tim_base_init(TIM3);
  wb32_tim_pwm_ch1_init(TIM3);
  wb32_tim_pwm_ch2_init(TIM3);
  wb32_tim_pwm_ch3_init(TIM3);
  wb32_tim_pwm_ch4_init(TIM3);
  wb32_tim_base_init(TIM4);
  wb32_tim_pwm_ch1_init(TIM4);
  wb32_tim_pwm_ch2_init(TIM4);
  wb32_tim_pwm_ch3_init(TIM4);
  wb32_tim_pwm_ch4_init(TIM4);
  wb32_tim_base_init(TIM1);
  wb32_tim_pwm_ch1_init(TIM1);
  wb32_tim_pwm_ch2_init(TIM1);
  wb32_tim_pwm_ch3_init(TIM1);

  /* Enable the TIM1 Main Output */
  TIM1->BDTR |= TIM_BDTR_MOE;
}

OSAL_IRQ_HANDLER(WB32_TIM1_UP_IRQ_VECTOR) {

    if (TIM1->SR & TIM_SR_UIF) {
        TIM1->SR = ~TIM_SR_UIF;
        gpt1cb();
    }
}

static void wb32_gpt_start(void) {

  TIM1->CR1 |= TIM_CR1_CEN;
}

static void wb32_pwm_pin_init(void) {

  /*
    PA8  (TIM1_CH1)
    PA9  (TIM1_CH2)
    PA10 (TIM1_CH3)
  */
  palSetPadMode(PAL_PORT(A8), PAL_PAD(A8), PAL_MODE_ALTERNATE(1));
  palSetPadMode(PAL_PORT(A9), PAL_PAD(A9), PAL_MODE_ALTERNATE(1));
  palSetPadMode(PAL_PORT(A10), PAL_PAD(A10), PAL_MODE_ALTERNATE(1));
  /*
    PA0  (TIM2_CH1)
    PA1  (TIM2_CH2)
    PA2  (TIM2_CH3)
    PA3  (TIM2_CH4)
  */
  palSetPadMode(PAL_PORT(A0), PAL_PAD(A0), PAL_MODE_ALTERNATE(1));
  palSetPadMode(PAL_PORT(A1), PAL_PAD(A1), PAL_MODE_ALTERNATE(1));
  palSetPadMode(PAL_PORT(A2), PAL_PAD(A2), PAL_MODE_ALTERNATE(1));
  palSetPadMode(PAL_PORT(A3), PAL_PAD(A3), PAL_MODE_ALTERNATE(1));
  /*
    PA6  (TIM3_CH1)
    PA7  (TIM3_CH2)
    PC8  (TIM3_CH3)
    PC9  (TIM3_CH4)
  */
  palSetPadMode(PAL_PORT(A6), PAL_PAD(A6), PAL_MODE_ALTERNATE(2));
  palSetPadMode(PAL_PORT(A7), PAL_PAD(A7), PAL_MODE_ALTERNATE(2));
  palSetPadMode(PAL_PORT(C8), PAL_PAD(C8), PAL_MODE_ALTERNATE(2));
  palSetPadMode(PAL_PORT(C9), PAL_PAD(C9), PAL_MODE_ALTERNATE(2));
  /*
    PB6  (TIM4_CH1)
    PB7  (TIM4_CH2)
    PB8  (TIM4_CH3)
    PB9  (TIM4_CH4)
  */
  palSetPadMode(PAL_PORT(B6), PAL_PAD(B6), PAL_MODE_ALTERNATE(2));
  palSetPadMode(PAL_PORT(B7), PAL_PAD(B7), PAL_MODE_ALTERNATE(2));
  palSetPadMode(PAL_PORT(B8), PAL_PAD(B8), PAL_MODE_ALTERNATE(2));
  palSetPadMode(PAL_PORT(B9), PAL_PAD(B9), PAL_MODE_ALTERNATE(2));
}

static inline uint8_t readMatrixPin(pin_t pin) {
  if (pin != NO_PIN) {
    return readPin(pin);
  } else {
    return 1;
  }
}

static bool select_row(uint8_t row) {
  pin_t pin = row_pins[row];
  if (pin != NO_PIN) {
    setPinOutput(pin);
    writePinLow(pin);
    return true;
  }
  return false;
}

static void unselect_row(uint8_t row) {
  pin_t pin = row_pins[row];
  if (pin != NO_PIN) {
    setPinOutput(pin);
    writePinHigh(pin);
  }
}

static void unselect_rows(void) {
  for (uint8_t x = 0; x < MATRIX_ROWS; x++) {
    unselect_row(x);
  }
}

static void rt_matrix_read_cols_on_row(matrix_row_t current_matrix[], uint8_t current_row) {
  // Start with a clear matrix row
  matrix_row_t current_row_value = 0;

  // For each col...
  matrix_row_t row_shifter = MATRIX_ROW_SHIFTER;
  for (uint8_t col_index = 0; col_index < MATRIX_COLS; col_index++, row_shifter <<= 1) {
    uint8_t pin_state = readMatrixPin(col_pins[col_index]);

    // Populate the matrix row with the state of the col pin
    current_row_value |= pin_state ? 0 : row_shifter;
  }

  // Update the matrix
  current_matrix[current_row] = current_row_value;
}

void wb003_init(pin_t cs_pin, pin_t en_pin);
void wb003_set_color(int index, uint8_t red, uint8_t green, uint8_t blue);
void wb003_set_color_all(uint8_t red, uint8_t green, uint8_t blue);
void wb003_update_pwm_buffers(pin_t cs_pin, uint8_t index);

static void init(void) {
  rgb_driver_init();
}

static void flush(void) {
  /* Execute in gpt1tb */
}

static void WB003_set_color(int index, uint8_t red, uint8_t green, uint8_t blue) {
  wb003_led led;

  memcpy_P(&led, (&g_wb003_leds[index]), sizeof(led));

  if (g_pwm_buffer[led.sw][led.id].r != red) {
    g_pwm_buffer[led.sw][led.id].r = red;
  }
  if (g_pwm_buffer[led.sw][led.id].g != green) {
    g_pwm_buffer[led.sw][led.id].g = green;
  }
  if (g_pwm_buffer[led.sw][led.id].b != blue) {
    g_pwm_buffer[led.sw][led.id].b = blue;
  }
}

static void WB003_set_color_all(uint8_t red, uint8_t green, uint8_t blue) {

  for (uint8_t i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    WB003_set_color(i, red, green, blue);
  }
}

const rgb_matrix_driver_t rgb_matrix_driver = {
  .init          = init,
  .flush         = flush,
  .set_color     = WB003_set_color,
  .set_color_all = WB003_set_color_all
};

void rgb_driver_init(void) {
  static bool is_initialised = false;

  if (!is_initialised) {
    is_initialised = true;
    wb32_pwm_init();
    wb32_pwm_pin_init();
    wb32_gpt_start();
    WB003_set_color_all(0x00, 0x00, 0x00);
  }
}

void matrix_init_pins(void) {

  unselect_rows();
  for (uint8_t x = 0; x < MATRIX_COLS; x++) {
    if (col_pins[x] != NO_PIN) {
      setPinInputHigh(col_pins[x]);
    }
  }
}

void matrix_read_cols_on_row(matrix_row_t current_matrix[], uint8_t current_row) {

  current_matrix[current_row] = rt_matrix[current_row];
}
