// Copyright 2021 In-hwan Ryu (@pasteur90)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "quantum.h"

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */

#define XXX KC_NO

#define LAYOUT( \
		    K00, K01, K02  \
		    ) { \
	    { K00, K01, K02 }, \
}

