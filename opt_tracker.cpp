#include "opt_tracker.h"
#include "config.h"
#include <Arduino.h>

static float best[RPM_BINS];
static float avg[RPM_BINS];
static int count[RPM_BINS];

void opt_tracker_init() {
  for (int i = 0; i < RPM_BINS; ++i) {
    best[i] = 0.0f;
    avg[i] = 0.0f;
    count[i] = 0;
  }
}

static int idx(int rpm) {
  int step = 200;
  int i = rpm / step;
  if (i < 0)
    i = 0;
  if (i >= RPM_BINS)
    i = RPM_BINS - 1;
  return i;
}

void opt_tracker_update(int rpm, float perf) {
  int i = idx(rpm);
  if (perf > best[i])
    best[i] = perf;
  avg[i] = (avg[i] * count[i] + perf) / (count[i] + 1);
  count[i]++;
}

float opt_tracker_optimality_pct(int rpm) {
  int i = idx(rpm);
  if (best[i] <= 0.0f)
    return 0.0f;
  return (avg[i] / best[i]) * 100.0f;
}
