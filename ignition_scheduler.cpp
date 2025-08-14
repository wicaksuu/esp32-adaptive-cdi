#include "ignition_scheduler.h"
#include "hv_control.h"
#include <Arduino.h>

static SparkCmd currentCmd{};
static bool pending = false;

void ignition_scheduler_init() { pending = false; }

void ignition_schedule(const SparkCmd &cmd) {
  currentCmd = cmd;
  pending = true;
}

void ignition_fire_now() {
  hv_window_cancel();
  pending = false;
}

void ignition_scheduler_tick() {
  if (pending && (int32_t)(micros() - currentCmd.dueUs) >= 0) {
    ignition_fire_now();
  }
}
