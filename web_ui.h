#pragma once
#include <stddef.h>

bool web_ui_begin();
void web_ui_loop();
bool web_api_get_status(char *out, size_t len);
bool web_api_get_profiles(char *out, size_t len);
bool web_api_select(const char *name);
bool web_api_get_optimality(char *out, size_t len);
