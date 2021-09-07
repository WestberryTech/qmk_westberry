#include "gmmk2.h"

#ifdef RGB_MATRIX_ENABLE

const aw_led g_aw_leds[DRIVER_LED_TOTAL] = {
/* Refer to IS31 manual for these locations
 *   driver
 *   |  R location
 *   |  |      G location
 *   |  |      |      B location
 *   |  |      |      | */
    {0 ,CS1_SW1, CS2_SW1, CS3_SW1},         // ESC
    {0 ,CS1_SW2, CS2_SW2, CS3_SW2},         // F1
    {0 ,CS1_SW3, CS2_SW3, CS3_SW3},         // F2
    {0 ,CS1_SW4, CS2_SW4, CS3_SW4},         // F3
    {0 ,CS1_SW5, CS2_SW5, CS3_SW5},         // F4
    {0 ,CS1_SW6, CS2_SW6, CS3_SW6},         // F5
    {0 ,CS1_SW7, CS2_SW7, CS3_SW7},         // F6
    {0 ,CS1_SW8, CS2_SW8, CS3_SW8},         // F7
    {0 ,CS1_SW9, CS2_SW9, CS3_SW9},         // F8
    {0 ,CS1_SW10, CS2_SW10, CS3_SW10},      // F9
    {0 ,CS1_SW11, CS2_SW11, CS3_SW11},      // F10
    {0 ,CS1_SW12, CS2_SW12, CS3_SW12},      // F11
    {1 ,CS1_SW1, CS2_SW1, CS3_SW1},         // F12
    {1 ,CS4_SW2, CS5_SW2, CS6_SW2},         // PS
    {1 ,CS4_SW3, CS5_SW3, CS6_SW3},         // DEL
    {1 ,CS1_SW2, CS2_SW2, CS3_SW2},         // INS
    {1 ,CS4_SW4, CS5_SW4, CS6_SW4},         // PGUP
    {1 ,CS4_SW7, CS5_SW7, CS6_SW7},         // PGDN

    {0 ,CS4_SW1, CS5_SW1, CS6_SW1},         // ~
    {0 ,CS4_SW2, CS5_SW2, CS6_SW2},         // 1
    {0 ,CS4_SW3, CS5_SW3, CS6_SW3},         // 2
    {0 ,CS4_SW4, CS5_SW4, CS6_SW4},         // 3
    {0 ,CS4_SW5, CS5_SW5, CS6_SW5},         // 4
    {0 ,CS4_SW6, CS5_SW6, CS6_SW6},         // 5
    {0 ,CS4_SW7, CS5_SW7, CS6_SW7},         // 6
    {0 ,CS4_SW8, CS5_SW8, CS6_SW8},         // 7
    {0 ,CS4_SW9, CS5_SW9, CS6_SW9},         // 8
    {0 ,CS4_SW10, CS5_SW10, CS6_SW10},      // 9
    {0 ,CS4_SW11, CS5_SW11, CS6_SW11},      // 0
    {0 ,CS4_SW12, CS5_SW12, CS6_SW12},      // -
    {1 ,CS1_SW5, CS2_SW5, CS3_SW5},         // =
    {1 ,CS1_SW7, CS2_SW7, CS3_SW7},         // BS
    {1 ,CS7_SW1, CS8_SW1, CS9_SW1},         // NUM LOCK
    {1 ,CS7_SW2, CS8_SW2, CS9_SW2},         // /
    {1 ,CS7_SW3, CS8_SW3, CS9_SW3},         // *
    {1 ,CS7_SW4, CS8_SW4, CS9_SW4},         // -

    {0 ,CS7_SW1, CS8_SW1, CS9_SW1},         // Tab
    {0 ,CS7_SW2, CS8_SW2, CS9_SW2},         // Q
    {0 ,CS7_SW3, CS8_SW3, CS9_SW3},         // W
    {0 ,CS7_SW4, CS8_SW4, CS9_SW4},         // E
    {0 ,CS7_SW5, CS8_SW5, CS9_SW5},         // R
    {0 ,CS7_SW6, CS8_SW6, CS9_SW6},         // T
    {0 ,CS7_SW7, CS8_SW7, CS9_SW7},         // Y
    {0 ,CS7_SW8, CS8_SW8, CS9_SW8},         // U
    {0 ,CS7_SW9, CS8_SW9, CS9_SW9},         // I
    {0 ,CS7_SW10, CS8_SW10, CS9_SW10},      // O
    {0 ,CS7_SW11, CS8_SW11, CS9_SW11},      // P
    {0 ,CS7_SW12, CS8_SW12, CS9_SW12},      // [
    {1 ,CS1_SW8, CS2_SW8, CS3_SW8},         // ]
    {1 ,CS1_SW11, CS2_SW11, CS3_SW11},      // ENTER
    {1 ,CS7_SW5, CS8_SW5, CS9_SW5},         // 7
    {1 ,CS7_SW6, CS8_SW6, CS9_SW6},         // 8
    {1 ,CS7_SW7, CS8_SW7, CS9_SW7},         // 9
    {1 ,CS7_SW8, CS8_SW8, CS9_SW8},         // +

    {0 ,CS10_SW1, CS11_SW1, CS12_SW1},      // Caps Lock
    {0 ,CS10_SW2, CS11_SW2, CS12_SW2},      // A
    {0 ,CS10_SW3, CS11_SW3, CS12_SW3},      // S
    {0 ,CS10_SW4, CS11_SW4, CS12_SW4},      // D
    {0 ,CS10_SW5, CS11_SW5, CS12_SW5},      // F
    {0 ,CS10_SW6, CS11_SW6, CS12_SW6},      // G
    {0 ,CS10_SW7, CS11_SW7, CS12_SW7},      // H
    {0 ,CS10_SW8, CS11_SW8, CS12_SW8},      // J
    {0 ,CS10_SW9, CS11_SW9, CS12_SW9},      // K
    {0 ,CS10_SW10, CS11_SW10, CS12_SW10},   // L
    {0 ,CS10_SW11, CS11_SW11, CS12_SW11},   // ;
    {0 ,CS10_SW12, CS11_SW12, CS12_SW12},   // '
    {1 ,CS1_SW10, CS2_SW10, CS3_SW10},      // #
    {1 ,CS7_SW9, CS8_SW9, CS9_SW9},         // 4
    {1 ,CS7_SW10, CS8_SW10, CS9_SW10},      // 5
    {1 ,CS7_SW11, CS8_SW11, CS9_SW11},      // 6

    {0 ,CS13_SW1, CS14_SW1, CS15_SW1},      // l_Shift
    {0 ,CS13_SW12, CS14_SW12, CS15_SW12},   // "\"
    {0 ,CS13_SW2, CS14_SW2, CS15_SW2},      // Z
    {0 ,CS13_SW3, CS14_SW3, CS15_SW3},      // X
    {0 ,CS13_SW4, CS14_SW4, CS15_SW4},      // C
    {0 ,CS13_SW5, CS14_SW5, CS15_SW5},      // V
    {0 ,CS13_SW6, CS14_SW6, CS15_SW6},      // B
    {0 ,CS13_SW7, CS14_SW7, CS15_SW7},      // N
    {0 ,CS13_SW8, CS14_SW8, CS15_SW8},      // M
    {0 ,CS13_SW9, CS14_SW9, CS15_SW9},      // ,
    {0 ,CS13_SW10, CS14_SW10, CS15_SW10},   // .
    {0 ,CS13_SW11, CS14_SW11, CS15_SW11},   // ?
    {1 ,CS4_SW8, CS5_SW8, CS6_SW8},         // R_Shift
    {1 ,CS4_SW9, CS5_SW9, CS6_SW9},         // Up
    {1 ,CS10_SW1, CS11_SW1, CS12_SW1},      // 1
    {1 ,CS10_SW2, CS11_SW2, CS12_SW2},      // 2
    {1 ,CS10_SW3, CS11_SW3, CS12_SW3},      // 3
    {1 ,CS10_SW4, CS11_SW4, CS12_SW4},      // ENTER

    {0 ,CS16_SW1, CS17_SW1, CS18_SW1},      // L_Ctrl
    {0 ,CS16_SW2, CS17_SW2, CS18_SW2},      // Win
    {0 ,CS16_SW3, CS17_SW3, CS18_SW3},      // L_Alt
    {0 ,CS16_SW6, CS17_SW6, CS18_SW6},      // Space
    {0 ,CS16_SW9, CS17_SW9, CS18_SW9},      // R_Alt
    {0 ,CS16_SW10, CS17_SW10, CS18_SW10},   // Fn
    {0 ,CS16_SW12, CS17_SW12, CS18_SW12},   // R_CTRL
    {1 ,CS4_SW10, CS5_SW10, CS6_SW10},      // Left
    {1 ,CS4_SW11, CS5_SW11, CS6_SW11},      // Down
    {1 ,CS10_SW5, CS11_SW5, CS12_SW5},      // Right
    {1 ,CS10_SW6, CS11_SW6, CS12_SW6},      // 0
    {1 ,CS10_SW7, CS11_SW7, CS12_SW7},      // .

    {1 ,CS13_SW1, CS14_SW1, CS15_SW1},       // LD1
    {1 ,CS13_SW2, CS14_SW2, CS15_SW2},       // LD2
    {1 ,CS13_SW3, CS14_SW3, CS15_SW3},       // LD3
    {1 ,CS13_SW4, CS14_SW4, CS15_SW4},       // LD4
    {1 ,CS13_SW5, CS14_SW5, CS15_SW5},       // LD5
    {1 ,CS13_SW6, CS14_SW6, CS15_SW6},       // LD6
    {1 ,CS13_SW7, CS14_SW7, CS15_SW7},       // LD7
    {1 ,CS13_SW8, CS14_SW8, CS15_SW8},       // LD8
    {1 ,CS13_SW9, CS14_SW9, CS15_SW9},       // LD9
    {1 ,CS13_SW10, CS14_SW10, CS15_SW10},    // LD10
    {1 ,CS16_SW1, CS17_SW1, CS18_SW1},       // LD11
    {1 ,CS16_SW2, CS17_SW2, CS18_SW2},       // LD12
    {1 ,CS16_SW3, CS17_SW3, CS18_SW3},       // LD13
    {1 ,CS16_SW4, CS17_SW4, CS18_SW4},       // LD14
    {1 ,CS16_SW5, CS17_SW5, CS18_SW5},       // LD15
    {1 ,CS16_SW6, CS17_SW6, CS18_SW6},       // LD16
    {1 ,CS16_SW7, CS17_SW7, CS18_SW7},       // LD17
    {1 ,CS16_SW8, CS17_SW8, CS18_SW8},       // LD18
    {1 ,CS16_SW9, CS17_SW9, CS18_SW9},       // LD19
    {1 ,CS16_SW10, CS17_SW10, CS18_SW10}     // LD20
};

#define RGB_LAYOUT(k0A, k0B, k0C, k0D, k0E, k0F, k0G, k0H, k0I, k0J, k0K, k0L, k0M, k0N, k6A, k6B, k6C, k6D, k1A, k1B, k1C, k1D, k1E, k1F, k1G, k1H, k1I, k1J, k1K, k1L, k1M, k1N, k6E, k6F, k6G, k6H, k2A, k2B, k2C, k2D, k2E, k2F, k2G, k2H, k2I, k2J, k2K, k2L, k2M, k3N, k6I, k6J, k6K, k6L, k3A, k3B, k3C, k3D, k3E, k3F, k3G, k3H, k3I, k3J, k3K, k3L, k3M, k7K, k7L, k7M, k4A, k4B, k4C, k4D, k4E, k4F, k4G, k4H, k4I, k4J, k4K, k4L, k4N, k7B, k7G, k7H, k7I, k7J, k5A, k5B, k5C, k5G, k5J, k5K, k5M, k7A, k7C, k7D, k7E, k7F) {\
	 {k0A, k0B, k0C, k0D, k0E, k0F, k0G, k0H, k0I, k0J, k0K, k0L, k0M, k0N}, \
	 {k1A, k1B, k1C, k1D, k1E, k1F, k1G, k1H, k1I, k1J, k1K, k1L, k1M, k1N}, \
	 {k2A, k2B, k2C, k2D, k2E, k2F, k2G, k2H, k2I, k2J, k2K, k2L, k2M, NO_LED}, \
	 {k3A, k3B, k3C, k3D, k3E, k3F, k3G, k3H, k3I, k3J, k3K, k3L, k3M, k3N}, \
	 {k4A, k4B, k4C, k4D, k4E, k4F, k4G, k4H, k4I, k4J, k4K, k4L, NO_LED, k4N}, \
	 {k5A, k5B, k5C, NO_LED, NO_LED, NO_LED, k5G, NO_LED, NO_LED, k5J, k5K, NO_LED, k5M, NO_LED}, \
	 {k6A, k6B, k6C, k6D, k6E, k6F, k6G, k6H, k6I, k6J, k6K, k6L, NO_LED, NO_LED}, \
	 {k7A, k7B, k7C, k7D, k7E, k7F, k7G, k7H, k7I, k7J, k7K, k7L, k7M, NO_LED} \
}

led_config_t g_led_config = { RGB_LAYOUT(  0,  1,  2,  3,  4,  5,  6,  7,  8,
                                           9, 10, 11, 12, 13, 14, 15, 16, 17,
                                          18, 19, 20, 21, 22, 23, 24, 25, 26,
                                          27, 28, 29, 30, 31, 32, 33, 34, 35,
                                          36, 37, 38, 39, 40, 41, 42, 43, 44,
                                          45, 46, 47, 48, 49, 50, 51, 52, 53,
                                          54, 55, 56, 57, 58, 59, 60, 61, 62,
                                          63, 64, 65, 66, 67, 68, 69, 70, 71,
                                          72, 73, 74, 75, 76, 77, 78, 79, 80,
                                          81, 82, 83, 84, 85, 86, 87, 88, 89,
                                          90, 91, 92, 93, 94, 95, 96, 97, 98, 99)
, {
    //   ESC,          F1,            F2,           F3,           F4,          F5,           F6,          F7,          F8,          F9,           F10,           F11,         F12,           PS,          DEL            INS           PGUP         PGDN
    {  11,   0 }, {  22,   0 }, {  33,   0 }, {  44,   0 }, {  55,   0 }, {  66,   0 }, { 77,   0 }, { 88,   0 }, { 99,   0 }, { 110,   0 }, { 121,   0 }, { 132,   0 }, { 143,   0 }, { 154,   0 }, { 165,   0 }, { 176,   0 }, { 187,   0 }, { 198,   0 },
    //    ~,           1,            2,            3,            4,            5,           6,           7,            8,            9,             0,            -,           =,       Backspace,      Puge Up
    {  11,  11 }, {  22,  11 }, {  33,  11 }, {  44,  11 }, {  55,  11 }, {  66,  11 }, { 77,  11 }, { 88,  11 }, { 99,  11 }, { 110,  11 }, { 121,  11 }, { 132,  11 }, { 143,  11 }, { 154,  11 }, { 165,  11 }, { 176,  11 }, { 187,  11 }, { 198,  11 },
    //   Tab,           Q,            W,            E,            R,            T,            Y,            U,           I,             O,            P,           [,            ],            ,,        Puge Down
    {  11,  22 }, {  22,  22 }, {  33,  22 }, {  44,  22 }, {  55,  22 }, {  66,  22 }, { 77,  22 }, { 88,  22 }, { 99,  22 }, { 110,  22 }, { 121,  22 }, { 132,  22 }, { 143,  22 }, { 154,  22 }, { 165,  22 }, { 176,  22 }, { 187,  22 }, { 198,  22 },
    //  Capslock,         A,           S,            D,            F,            G,            H,            J,            K,            L,            ;,           ',           Enter,        Home
    {  11,  33 }, {  22,  33 }, {  33,  33 }, {  44,  33 }, {  55,  33 }, {  66,  33 }, { 77,  33 }, { 88,  33 }, { 99,  33 }, { 110,  33 }, { 121,  33 }, { 132,  33 }, { 143,  33 },               { 165,  33 }, { 176,  33 }, { 187,  33 },
    //  LShift,          Z,            X,            C,            V,            B,           N,            M,            ,,            .,            /,          Shift,         Up,           End
    {  11,  44 }, {  22,  44 }, {  33,  44 }, {  44,  44 }, {  55,  44 }, {  66,  44 }, { 77,  44 }, { 88,  44 }, { 99,  44 }, { 110,  44 }, { 121,  44 }, { 132,  44 }, { 143,  44 }, { 154,  44 }, { 165,  44 }, { 176,  44 }, { 187,  44 }, { 198,  44 },
    //   Ctrl,         GUI,          Alt,         Space,         RAlt,          FN,         Left,          Down,        Right
    {  11,  55 }, {  22,  55 }, {  33,  55 },                                           { 77,  55 },                           { 110,  55 }, { 121,  55 }, { 132,  55 }, { 143,  55 }, { 154,  55 }, { 165,  55 }, { 176,  55 }, { 187,  55 },
    {   0,   0 }, {   0,   6 }, {   0,  12 }, {   0,  18 }, {   0,  24 }, {   0,  30 }, {   0, 36 }, {   0, 42 }, {   0, 48 }, {   0,   54 },
    { 209,   0 }, { 209,   6 }, { 209,  12 }, { 209,  18 }, { 209,  24 }, { 209,  30 }, { 209, 36 }, { 209, 42 }, { 209, 48 }, { 209,   54 }
}, {
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    // Esc, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, -, =, Backspace
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 4, 4, 4,
    // Tab, Q, W, E, R, T, Y, U, I, O, P, [, ],  ,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    // Capslock, A, S, D, F, G, H, J, K, L, ;, ', Enter
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    4, 4, 4,
    // LShift, Z, X, C, V, B, N, M, ,, ., /, Shift, Up,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    // Ctrl, GUI, Alt, Space, RAlt, FN, Left, Down, Right
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2
} };
#endif

void matrix_init_kb(void) {

    led_init_ports();
    matrix_init_user();
}

// Set our LED pins as output
void led_init_ports() {

    setPinOutput(C14); // LED1 Numlock LED
    writePinHigh(C14);
    setPinOutput(C15); // LED2 Capslock LED
    writePinHigh(C15);
}

bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);

    if(res) {
        writePin(C14, !led_state.num_lock);
        writePin(C15, !led_state.caps_lock);
        // writePin(C13, !led_state.scroll_lock);
    }

    return res;
}
