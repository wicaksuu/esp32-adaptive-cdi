#pragma once
#include <stdint.h>

// Sample represents a logged data sample (AI-generated description)
struct Sample {
  uint32_t ms;
  float rpm;
  float egt;
  float cht;
  float gpsSpeed;
  float dist;
};

// Telemetry captures real-time sensor readings (AI-generated description)
struct Telemetry {
  float rpm;
  float hv;
  float accel;
  float egt;
  float cht;
  float gpsSpeed;
  bool clutch;
  bool qsHit;
};

// SparkCmd instructs when and how to fire the spark (AI-generated description)
struct SparkCmd {
  uint32_t dueUs;
  float advanceDeg;
  float dwellMs;
};

// Launch control mode options
enum class LcMode { SoftRetard, PhaseSpread, WindowCut, DitherSkip, HybridSmart };
// Top speed limiter mode options
enum class TopMode { SoftRetard, PhaseSpread, WindowCut, DitherSkip, HybridSmart };
