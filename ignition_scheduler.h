#pragma once
#include "types.h"

// Sets up ignition scheduling resources
void ignition_scheduler_init();
// Queues a spark command for future firing
void ignition_schedule(const SparkCmd& cmd);
// Immediately fires a spark regardless of schedule
void ignition_fire_now();
// Ticks the scheduler, to be called periodically
void ignition_scheduler_tick();
