#include "limiter.h"
#include <Arduino.h>

static LcMode lcMode = LcMode::SoftRetard;
static int lcHold = 7000;
static TopMode topMode = TopMode::SoftRetard;
static int topSet = 13000;

void limiter_init() {}

void limiter_set_lc(LcMode mode, int holdRpm) {
  lcMode = mode;
  lcHold = holdRpm;
}

void limiter_set_top(TopMode mode, int setpoint) {
  topMode = mode;
  topSet = setpoint;
}

void limiter_apply(float rpm, SparkCmd &cmd) {
  cmd.advanceDeg = 20.0f;
  cmd.dwellMs = 2.0f;
  cmd.dueUs = micros() + 1000;
  if (rpm > topSet) {
    cmd.advanceDeg -= (rpm - topSet) * 0.01f;
    if (cmd.advanceDeg < 0)
      cmd.advanceDeg = 0;
  }
  if (rpm > lcHold && lcMode != LcMode::SoftRetard) {
    cmd.dwellMs = 0.0f; // cut
  }
}
