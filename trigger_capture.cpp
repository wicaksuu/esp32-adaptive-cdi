#include "trigger_capture.h"
#include <Arduino.h>

static uint32_t last = 0;

void IRAM_ATTR trigger_capture_isr() {
  // In this stub we simply record timestamp
  last = micros();
}

void trigger_capture_init() { last = micros(); }

bool trigger_capture_poll(uint32_t &dtMicrosOut, float &rpmOut) {
  uint32_t now = micros();
  dtMicrosOut = now - last;
  last = now;
  if (dtMicrosOut == 0)
    return false;
  rpmOut = 60000000.0f / dtMicrosOut;
  return true;
}

void trigger_capture_reset() { last = micros(); }
