#pragma once
#include "config.h"

void map1d_init(int bins = RPM_BINS);
float map1d_get_advance(int rpm);
float map1d_get_dwell(int rpm);
float map1d_get_qs(int rpm);
void map1d_smooth();
void map1d_commitDelta();
