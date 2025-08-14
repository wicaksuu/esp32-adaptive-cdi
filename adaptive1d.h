#pragma once

// Initializes adaptive map subsystem
void adaptive1d_init();
// Updates advance delta based on performance score
float adaptive1d_update_advance(int rpm, float score);
// Updates dwell delta based on performance score
float adaptive1d_update_dwell(int rpm, float score);
// Updates quickshift delta based on shift quality
float adaptive1d_update_qs(int rpm, float shiftQuality);
