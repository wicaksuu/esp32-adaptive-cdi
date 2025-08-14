#pragma once
#include <stddef.h>

// Returns currently active profile name
const char* profiles_active();
// Lists available profiles into buffer
bool profiles_list(char* outBuf, size_t len);
// Selects a profile by name
bool profiles_select(const char* name);
