#pragma once
#include "types.h"

void adaptive_engine_init();
void adaptive_engine_update(const Telemetry &t);
float adaptive_engine_score(const Telemetry &t);
