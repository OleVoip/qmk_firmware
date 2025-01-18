// Created/amended by OleVoip 2024.
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config.h"

/**
 *\brief Three-letter label strings for all keys.
 */
typedef char labelmap_t[DRIVE_LINES][SENSE_LINES][4];

/**
 *\brief Map for LAYOUT_all, with all positions foreseen on the PCB.
 */
extern const labelmap_t key_position_labels;

/**
 *\brief Take the databus port and control lines to the idle state.
 */
extern void init_bus(void);

// .