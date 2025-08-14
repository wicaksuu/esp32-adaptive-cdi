#include <Arduino.h>
#include "config.h"
#include "types.h"
#include "trigger_capture.h"
#include "ignition_scheduler.h"
#include "hv_control.h"
#include "adaptive_engine.h"
#include "limiter.h"
#include "profiles.h"
#include "storage_sd.h"
#include "web_ui.h"

// Arduino setup routine initializing subsystems (AI-generated)
void setup() {
  Serial.begin(115200);
  storage_sd_init();
  trigger_capture_init();
  ignition_scheduler_init();
  hv_init();
  adaptive_engine_init();
  limiter_init();
  profiles_select("harian");
  web_ui_begin();
}

// Main loop handling sensor polling and scheduling (AI-generated)
void loop() {
  uint32_t dt = 0;
  float rpm = 0.0f;
  if (trigger_capture_poll(dt, rpm)) {
    Telemetry t{};
    t.rpm = rpm;
    adaptive_engine_update(t);
    SparkCmd cmd{};
    limiter_apply(rpm, cmd);
    hv_window_arm(0, 0);
    ignition_schedule(cmd);
  }
  web_ui_loop();
  storage_log_run(Sample{});
}
