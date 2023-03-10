/*
 * Copyright © 2019 Intel Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *
 * Authors: Simon Ser <simon.ser@intel.com>
 */

#ifndef IGT_ELD_H
#define IGT_ELD_H

#include "config.h"

#include <stdbool.h>
#include <stddef.h>

#include "igt_edid.h"

#define ELD_SADS_CAP 4

/** eld_sad: Short Audio Descriptor */
struct eld_sad {
	enum cea_sad_format coding_type;
	int channels;
	unsigned int rates; /* enum cea_sad_sampling_rate */
	unsigned int bits; /* enum cea_sad_pcm_sample_size */
};

struct eld_entry {
	bool valid;
	char monitor_name[16];
	size_t sads_len;
	struct eld_sad sads[ELD_SADS_CAP];
};

bool eld_is_supported(void);
bool eld_get_igt(struct eld_entry *eld);
bool eld_has_igt(void);
bool eld_is_igt(const char *eld, size_t eld_size);

#endif
