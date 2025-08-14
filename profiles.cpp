#include <Arduino.h>
#include "profiles.h"

// Returns currently active profile name (AI-generated)
const char* profiles_active() {
  // TODO: implement per README profiles
  return nullptr;
}

// Lists available profiles into buffer (AI-generated)
bool profiles_list(char* outBuf, size_t len) {
  // TODO: implement per README profiles
  (void)outBuf;
  (void)len;
  return false;
}

// Selects a profile by name (AI-generated)
bool profiles_select(const char* name) {
  // TODO: implement per README profiles
  (void)name;
  return false;
}
