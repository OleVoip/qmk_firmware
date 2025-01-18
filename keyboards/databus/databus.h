// Created/amended by OleVoip 2024.
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#ifndef QMK_KEYBOARD_H
#   define QMK_KEYBOARD_H ".build/obj_databus_tdv2200_default/src/default_keyboard.h"
#endif
#include QMK_KEYBOARD_H

#ifdef __AVR__
#   include "databus-avr.h"
#else
#   error Currently, only the avr platform is supported
#endif

static inline uint8_t swap_nibbles(uint8_t b) {
    return (uint8_t)(b << 4) | (uint8_t)(b >> 4);
}

static inline uint8_t accomodating_bitmask(uint8_t b) {
    b |= (b >> 1);
    b |= (b >> 2);
    b |= (b >> 4);
    return b;
}

static inline bool read_pin (pin_t pin) {
    return (pin == NO_PIN) ? false : gpio_read_pin(pin);
}

static inline void write_pin(pin_t pin, bool value) {
    if (pin != NO_PIN) {
        gpio_write_pin(pin, value);
    }
}

static inline void toggle_pin(pin_t pin) {
    if (pin != NO_PIN) {
        gpio_toggle_pin(pin);
    }
}

static inline void init_pin(pin_t pin, bool active) {
    if (pin != NO_PIN) {
        gpio_set_pin_output(pin);
        gpio_write_pin(pin, active);
    }
}

static inline uint8_t read_bus_strobing(pin_t strobe, bool active) {
    set_bus_input();
    write_pin(strobe, active);
    wait_for_bus();
    uint8_t data = read_bus();
    write_pin(strobe, !active);
    set_bus_idle();
    return data;
}

static inline void write_bus_strobing(uint8_t data, pin_t strobe, bool active) {
    write_bus(data);
    set_bus_output();
    wait_for_bus();             // data are accepted either during this wait
    write_pin(strobe, active);  // depending on the receiving component,
    wait_for_bus();             // data are accepted either during this wait
    write_pin(strobe, !active); // or at this flank
    wait_for_bus();
    set_bus_idle();
}


/**
 * \brief Mapping of two-key combinations to character or another key
 * Two-key combination to a Windows alt code and a unicode character
 * or, if the alt code is zero, another keycode.
 */
typedef struct two_key_mapping_t {
    uint16_t kc1, kc2;
    uint8_t  alt_code;
    uint16_t utf_key;
} two_key_mapping_t;

// .
