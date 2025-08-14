#pragma once
#include "types.h"

// Loads profile configuration from storage
bool profile_cfg_load(const char *profile);
// Saves profile configuration to storage
bool profile_cfg_save(const char *profile);
// Retrieves pickup offset in degrees
float profile_pickupOffsetDeg();
// Retrieves recommended shift RPM
int profile_shiftRpmRecommended();
// Sets launch control parameters
void profile_set_lc(LcMode mode, int holdRpm);
// Sets top speed limiter parameters
void profile_set_top(TopMode mode, int setpoint);
