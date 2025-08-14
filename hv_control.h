#pragma once
#include <stdint.h>

// Initializes high-voltage control circuitry
void hv_init();
// Arms the HV window between start and end microseconds
void hv_window_arm(uint32_t startUs, uint32_t endUs);
// Cancels any armed HV window
void hv_window_cancel();
// Reads current high voltage level
float hv_read_voltage();
