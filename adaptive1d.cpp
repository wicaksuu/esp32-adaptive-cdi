#include "adaptive1d.h"
#include <Arduino.h>

Adaptive1D g_adaptive;

void Adaptive1D::init() {
  for (int i = 0; i < RPM_BINS; ++i) {
    advanceDelta[i] = 0.0f;
    dwellDelta[i] = 0.0f;
    qsDelta[i] = 0.0f;
  }
}

static int idx_from_rpm(int rpm) {
  int step = 200; // simple mapping 0-12800 rpm -> 64 bins
  int idx = rpm / step;
  if (idx < 0)
    idx = 0;
  if (idx >= RPM_BINS)
    idx = RPM_BINS - 1;
  return idx;
}

float Adaptive1D::updateAdvance(int rpm, float score) {
  int idx = idx_from_rpm(rpm);
  advanceDelta[idx] += score * 0.01f;
  if (advanceDelta[idx] > 5.0f)
    advanceDelta[idx] = 5.0f;
  if (advanceDelta[idx] < -5.0f)
    advanceDelta[idx] = -5.0f;
  return advanceDelta[idx];
}

float Adaptive1D::updateDwell(int rpm, float score) {
  int idx = idx_from_rpm(rpm);
  dwellDelta[idx] += score * 0.001f;
  if (dwellDelta[idx] > 1.0f)
    dwellDelta[idx] = 1.0f;
  if (dwellDelta[idx] < -1.0f)
    dwellDelta[idx] = -1.0f;
  return dwellDelta[idx];
}

float Adaptive1D::updateQs(int rpm, float shiftQuality) {
  int idx = idx_from_rpm(rpm);
  qsDelta[idx] += (1.0f - shiftQuality) * 0.1f;
  if (qsDelta[idx] > 50.0f)
    qsDelta[idx] = 50.0f;
  if (qsDelta[idx] < -50.0f)
    qsDelta[idx] = -50.0f;
  return qsDelta[idx];
}
