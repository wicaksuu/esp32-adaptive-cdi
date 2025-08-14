#pragma once

// Initializes knock proxy with filter and sensitivity settings
void  knock_init(int fs, int fLow, int fHigh, int winMs, float sens);
// Computes knock score from acceleration sample
float knock_score(float accelSample);
// Determines if knock threshold has been exceeded
bool  knock_hit();
