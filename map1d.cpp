#include "map1d.h"
#include <Arduino.h>

static float advBase[RPM_BINS];
static float advDelta[RPM_BINS];
static float dwellBase[RPM_BINS];
static float dwellDelta[RPM_BINS];
static float qsBase[RPM_BINS];
static float qsDelta[RPM_BINS];

void map1d_init(int) {
  for (int i = 0; i < RPM_BINS; ++i) {
    advBase[i] = 20.0f;
    advDelta[i] = 0.0f;
    dwellBase[i] = 2.0f;
    dwellDelta[i] = 0.0f;
    qsBase[i] = 50.0f;
    qsDelta[i] = 0.0f;
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

float map1d_get_advance(int rpm) { return advBase[idx(rpm)] + advDelta[idx(rpm)]; }
float map1d_get_dwell(int rpm) { return dwellBase[idx(rpm)] + dwellDelta[idx(rpm)]; }
float map1d_get_qs(int rpm) { return qsBase[idx(rpm)] + qsDelta[idx(rpm)]; }

void map1d_smooth() {
  for (int i = 1; i < RPM_BINS - 1; ++i) {
    advBase[i] = (advBase[i - 1] + advBase[i] + advBase[i + 1]) / 3.0f;
    dwellBase[i] = (dwellBase[i - 1] + dwellBase[i] + dwellBase[i + 1]) / 3.0f;
    qsBase[i] = (qsBase[i - 1] + qsBase[i] + qsBase[i + 1]) / 3.0f;
  }
}

void map1d_commitDelta() {
  for (int i = 0; i < RPM_BINS; ++i) {
    advBase[i] += advDelta[i];
    dwellBase[i] += dwellDelta[i];
    qsBase[i] += qsDelta[i];
    advDelta[i] = dwellDelta[i] = qsDelta[i] = 0.0f;
  }
}
