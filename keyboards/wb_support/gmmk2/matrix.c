/*
Copyright (C) 2021 Westberry Technology (ChangZhou) Corp., Ltd

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "util.h"
#include "matrix.h"
#include "debounce.h"
#include "quantum.h"

#define ROWS_PER_HAND (MATRIX_ROWS)

#if (DIODE_DIRECTION == ROW2COL) || (DIODE_DIRECTION == COL2ROW)
#    ifdef MATRIX_ROW_PINS
static pin_t row_pins[MATRIX_ROWS] = MATRIX_ROW_PINS;
#    endif  // MATRIX_ROW_PINS
#    ifdef MATRIX_COL_PINS
static pin_t col_pins[MATRIX_COLS] = MATRIX_COL_PINS;
#    endif  // MATRIX_COL_PINS
#endif

/* matrix state(1:on, 0:off) */
extern matrix_row_t raw_matrix[MATRIX_ROWS];  // raw values
extern matrix_row_t matrix[MATRIX_ROWS];      // debounced values



// user-defined overridable functions
static void matrix_init_pins(void);
static matrix_row_t matrix_read_cols_on_row(void);

static void setPinOutput_writeLow(pin_t pin) {

    setPinOutput(pin);
    writePinLow(pin);

}

static void setPinOutput_writeHigh(pin_t pin) {

    setPinOutput(pin);
    writePinHigh(pin);

}

static void setPinInputLow_atomic(pin_t pin) {

    setPinInputLow(pin);
}

static uint8_t readMatrixPin(pin_t pin) {
    if (pin != NO_PIN) {
        return !readPin(pin);
    } else {
        return 1;
    }
}

// matrix code
#if defined(DIODE_DIRECTION)
#    if defined(MATRIX_ROW_PINS) && defined(MATRIX_COL_PINS)
#        if (DIODE_DIRECTION == COL2ROW)

static bool select_row(uint8_t row) {
    pin_t pin = row_pins[row];
    if (pin != NO_PIN) {
        setPinOutput_writeHigh(pin);
        return true;
    }
    return false;
}

static void unselect_row(uint8_t row) {
    pin_t pin = row_pins[row];
    if (pin != NO_PIN) {
        setPinOutput_writeLow(pin);
    }
}

static void unselect_rows(void) {
    for (uint8_t x = 0; x < ROWS_PER_HAND; x++) {
        unselect_row(x);
    }
}

static void matrix_init_pins(void) {
    unselect_rows();
    for (uint8_t x = 0; x < MATRIX_COLS; x++) {
        if (col_pins[x] != NO_PIN) {
            setPinInputLow_atomic(col_pins[x]);
        }
    }
}

static matrix_row_t matrix_read_cols_on_row(void) {
    // Start with a clear matrix row
    matrix_row_t current_row_value = 0;

    // For each col...
    for (uint8_t col_index = 0; col_index < MATRIX_COLS; col_index++) {
        uint8_t pin_state = readMatrixPin(col_pins[col_index]);

        // Populate the matrix row with the state of the col pin
        current_row_value |= pin_state ? 0 : (MATRIX_ROW_SHIFTER << col_index);
    }

    return current_row_value;
}

#        else
#            error DIODE_DIRECTION must be one of COL2ROW or ROW2COL!
#        endif
#    endif  // defined(MATRIX_ROW_PINS) && defined(MATRIX_COL_PINS)
#else
#    error DIODE_DIRECTION is not defined!
#endif

void matrix_init_custom(void) {

    // initialize key pins
    matrix_init_pins();
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    bool changed = false;

    // Set row, read cols
    for (uint8_t current_row = 0; current_row < MATRIX_ROWS; current_row++) {
        select_row(current_row);
        matrix_output_select_delay();

        matrix_row_t current_row_value = matrix_read_cols_on_row();
        changed |= (current_matrix[current_row] != current_row_value);
        current_matrix[current_row] = current_row_value;

        unselect_rows();
        //this internally calls matrix_io_delay()
        matrix_output_unselect_delay(current_row, current_row_value != 0);
    }

    return changed;
}
