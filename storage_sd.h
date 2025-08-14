#pragma once
#include "types.h"

// Initializes SD storage subsystem
bool storage_sd_init();
// Logs runtime sample to storage
bool storage_log_run(const Sample& s);
// Checks if a path exists on storage
bool storage_exists(const char* path);
