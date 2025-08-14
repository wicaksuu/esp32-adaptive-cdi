#pragma once
#include "config.h"

// Initializes 1D map tables with optional bin count
void map1d_init(int bins = RPM_BINS);
// Retrieves advance value for given RPM
float map1d_get_advance(int rpm);
// Retrieves dwell value for given RPM
float map1d_get_dwell(int rpm);
// Retrieves quickshift cut duration for given RPM
float map1d_get_qs(int rpm);
// Smooths map data for continuity
void map1d_smooth();
// Commits delta adjustments to base maps
void map1d_commitDelta();
