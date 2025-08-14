#pragma once
#include <stddef.h>

// Begins web UI subsystem
bool web_ui_begin();
// Handles web UI loop tasks
void web_ui_loop();
// Provides status information via web API
bool web_api_get_status(char* out, size_t len);
// Provides profile list via web API
bool web_api_get_profiles(char* out, size_t len);
// Selects profile via web API
bool web_api_select(const char* name);
// Provides optimality metrics via web API
bool web_api_get_optimality(char* out, size_t len);
