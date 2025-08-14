#pragma once
#include <stdint.h>

void hv_init();
void hv_window_arm(uint32_t startUs, uint32_t endUs);
void hv_window_cancel();
float hv_read_voltage();
