#pragma once

void gps_init();
void gps_update(float speed_mps, double lat, double lon, bool clutchReleased);
bool gps_has_drag_times();
float gps_time_200m();
float gps_time_400m();
float gps_time_500m();
float gps_time_1000m();
bool gps_has_lap();
float gps_time_lap();
