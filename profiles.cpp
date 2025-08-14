#include "profiles.h"
#include <Arduino.h>
#include <string.h>

static const char *active = "harian";

const char *profiles_active() { return active; }

bool profiles_list(char *outBuf, size_t len) {
  const char *names = "harian,200,400,500,1000";
  if (strlen(names) + 1 > len)
    return false;
  strcpy(outBuf, names);
  return true;
}

bool profiles_select(const char *name) {
  if (!name)
    return false;
  active = name;
  return true;
}
