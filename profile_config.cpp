#include "profile_config.h"
#include <Arduino.h>

static float pickupOffset = 70.0f;
static int shiftRpm = 9000;
static LcMode lcMode = LcMode::SoftRetard;
static int lcHold = 7000;
static TopMode topMode = TopMode::SoftRetard;
static int topSet = 13000;

bool profile_cfg_load(const char *profile) {
  (void)profile;
  return true;
}

bool profile_cfg_save(const char *profile) {
  (void)profile;
  return true;
}

float profile_pickupOffsetDeg() { return pickupOffset; }
int profile_shiftRpmRecommended() { return shiftRpm; }
void profile_set_lc(LcMode mode, int holdRpm) {
  lcMode = mode;
  lcHold = holdRpm;
}
void profile_set_top(TopMode mode, int setpoint) {
  topMode = mode;
  topSet = setpoint;
}
