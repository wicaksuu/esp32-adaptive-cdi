#include "gps_analyzer.h"
#include <Arduino.h>

static float dist = 0.0f;
static uint32_t startMs = 0;
static float t200 = -1, t400 = -1, t500 = -1, t1000 = -1;

void gps_init() {
  dist = 0.0f;
  startMs = millis();
  t200 = t400 = t500 = t1000 = -1;
}

void gps_update(float speed_mps, double, double, bool clutchReleased) {
  static uint32_t last = millis();
  uint32_t now = millis();
  float dt = (now - last) / 1000.0f;
  last = now;
  if (clutchReleased)
    startMs = now; // start measurement
  dist += speed_mps * dt;
  float t = (now - startMs) / 1000.0f;
  if (t200 < 0 && dist >= 200.0f)
    t200 = t;
  if (t400 < 0 && dist >= 400.0f)
    t400 = t;
  if (t500 < 0 && dist >= 500.0f)
    t500 = t;
  if (t1000 < 0 && dist >= 1000.0f)
    t1000 = t;
}

bool gps_has_drag_times() { return t200 > 0 && t400 > 0; }
float gps_time_200m() { return t200; }
float gps_time_400m() { return t400; }
float gps_time_500m() { return t500; }
float gps_time_1000m() { return t1000; }

bool gps_has_lap() { return false; }
float gps_time_lap() { return 0.0f; }
