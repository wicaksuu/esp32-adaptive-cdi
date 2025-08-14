#pragma once
#include "types.h"

void ignition_scheduler_init();
void ignition_schedule(const SparkCmd &cmd);
void ignition_fire_now();
void ignition_scheduler_tick();
