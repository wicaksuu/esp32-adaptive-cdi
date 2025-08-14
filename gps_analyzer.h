#pragma once
#include <stdbool.h>

// Initializes GPS analysis subsystem
void  gps_init();
// Updates GPS metrics with new sample
void  gps_update(float speed_mps, double lat, double lon, bool clutchReleased);
// Checks if drag times are available
bool  gps_has_drag_times();
// Retrieves 200m drag time
float gps_time_200m();
// Retrieves 400m drag time
float gps_time_400m();
// Retrieves 500m drag time
float gps_time_500m();
// Retrieves 1000m drag time
float gps_time_1000m();
// Checks if lap time is available
bool  gps_has_lap();
// Retrieves lap time
float gps_time_lap();
