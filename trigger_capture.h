#pragma once
#include <stdint.h>
#include "types.h"

// Initializes trigger capture hardware
void trigger_capture_init();
// ISR handler for capturing trigger pulses
IRAM_ATTR void trigger_capture_isr();
// Polls for new trigger data and computes RPM
bool trigger_capture_poll(uint32_t& dtMicrosOut, float& rpmOut);
// Resets internal state of trigger capture
void trigger_capture_reset();
