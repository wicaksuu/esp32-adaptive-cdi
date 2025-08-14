#include "knock_proxy.h"
#include <Arduino.h>

static float rms = 0.0f;

void knock_init() { rms = 0.0f; }

float knock_update(float accel) {
  rms = 0.99f * rms + 0.01f * accel * accel;
  float score = sqrtf(rms);
  return score;
}
