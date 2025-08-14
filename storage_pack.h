#pragma once

// Loads pack data from storage for profile
bool storage_pack_load(const char *profile);
// Saves pack data to storage for profile
bool storage_pack_save(const char *profile);
// Loads config data from storage for profile
bool storage_pack_load_cfg(const char *profile);
// Saves config data to storage for profile
bool storage_pack_save_cfg(const char *profile);
