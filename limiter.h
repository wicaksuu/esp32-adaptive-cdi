#pragma once
#include "types.h"

// Initializes limiter subsystem
void limiter_init();
// Configures launch control mode and hold RPM
void limiter_set_lc(LcMode mode, int holdRpm);
// Configures top speed limiter mode and setpoint
void limiter_set_top(TopMode mode, int setpoint);
// Applies limiter logic to a spark command based on RPM
void limiter_apply(float rpm, SparkCmd& cmd);
