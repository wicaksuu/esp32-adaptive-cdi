#pragma once

// Loads tuning pack for specified profile
bool pack_load(const char* profile);
// Saves current tuning pack for specified profile
bool pack_save(const char* profile);
// Retrieves advance from pack for RPM
float pack_advance_for(int rpm);
// Retrieves dwell from pack for RPM
float pack_dwell_for(int rpm);
// Retrieves quickshift cut from pack for RPM
float pack_qs_for(int rpm);
