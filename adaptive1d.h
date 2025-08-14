#pragma once
#include "config.h"

// Simple adaptive 1D map controller
struct Adaptive1D {
  float advanceDelta[RPM_BINS];
  float dwellDelta[RPM_BINS];
  float qsDelta[RPM_BINS];
  void init();
  float updateAdvance(int rpm, float score);
  float updateDwell(int rpm, float score);
  float updateQs(int rpm, float shiftQuality);
};

extern Adaptive1D g_adaptive;
