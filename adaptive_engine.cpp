#include "adaptive_engine.h"
#include "adaptive1d.h"
#include <Arduino.h>

static float lastPerf = 0.0f;

void adaptive_engine_init() {
  g_adaptive.init();
  lastPerf = 0.0f;
}

float adaptive_engine_score(const Telemetry &t) {
  float perf = t.rpm * 0.001f + t.gpsSpeed * 0.1f;
  float penalty = 0.0f;
  if (t.egt > 800.0f)
    penalty += (t.egt - 800.0f) * 0.01f;
  if (t.cht > 200.0f)
    penalty += (t.cht - 200.0f) * 0.05f;
  if (t.hv < 10.0f)
    penalty += (10.0f - t.hv) * 0.1f;
  lastPerf = perf - penalty;
  return lastPerf;
}

void adaptive_engine_update(const Telemetry &t) {
  float score = adaptive_engine_score(t);
  g_adaptive.updateAdvance((int)t.rpm, score);
  g_adaptive.updateDwell((int)t.rpm, score);
}
