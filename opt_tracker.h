#pragma once

// Initializes optimality tracker
void opt_tracker_init();
// Updates performance metric for a given RPM
void opt_tracker_update(int rpm, float perf);
// Retrieves optimality percentage for a given RPM
float opt_tracker_optimality_pct(int rpm);
