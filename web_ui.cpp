#include "web_ui.h"
#include "profiles.h"
#include <Arduino.h>
#include <string.h>

bool web_ui_begin() { return true; }
void web_ui_loop() {}

bool web_api_get_status(char *out, size_t len) {
  const char *s = "{\"rpm\":0}";
  if (strlen(s) + 1 > len)
    return false;
  strcpy(out, s);
  return true;
}

bool web_api_get_profiles(char *out, size_t len) { return profiles_list(out, len); }

bool web_api_select(const char *name) { return profiles_select(name); }

bool web_api_get_optimality(char *out, size_t len) {
  const char *s = "0";
  if (strlen(s) + 1 > len)
    return false;
  strcpy(out, s);
  return true;
}
