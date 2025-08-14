#include "pack.h"
#include "adaptive1d.h"
#include "map1d.h"
#include <Arduino.h>

bool pack_load(const char *profile) {
  (void)profile;
  map1d_init();
  g_adaptive.init();
  return true;
}

bool pack_save(const char *profile) {
  (void)profile;
  map1d_commitDelta();
  return true;
}

float pack_advance_for(int rpm) { return map1d_get_advance(rpm); }
float pack_dwell_for(int rpm) { return map1d_get_dwell(rpm); }
float pack_qs_for(int rpm) { return map1d_get_qs(rpm); }
