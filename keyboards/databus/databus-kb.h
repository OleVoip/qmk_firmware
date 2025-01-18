// Created/amended by OleVoip 2024.
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include <stdint.h>

#include "config.h"

/**
 *\brief Three-letter label strings for all matrix crossings.
 */
typedef char labelmap_t[DRIVE_LINES][SENSE_LINES][4];

/**
 *\brief Key label map for LAYOUT_all, with all foressen positions.
 */
extern const labelmap_t key_position_labels;

/**
 *\brief Take the databus port and control lines to the idle state.
 */
extern void init_bus(void);

/**
* \brief Indicate that the bootloader is taking control.
*/
extern void indicate_bootloader(void);

extern volatile uint8_t indicators;
extern void update_indicators(void);
// .