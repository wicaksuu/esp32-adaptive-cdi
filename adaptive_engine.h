#pragma once
#include "types.h"

// Initializes adaptive engine logic
void adaptive_engine_init();
// Updates adaptive engine state using telemetry data
void adaptive_engine_update(const Telemetry& t);
// Computes performance score from telemetry
float adaptive_engine_score(const Telemetry& t);
