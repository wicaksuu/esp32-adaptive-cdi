#include "hv_control.h"
#include <Arduino.h>

static uint32_t g_start = 0;
static uint32_t g_end = 0;

void hv_init() {
  pinMode(2, OUTPUT); // dummy HV enable pin
  digitalWrite(2, LOW);
}

void hv_window_arm(uint32_t startUs, uint32_t endUs) {
  g_start = startUs;
  g_end = endUs;
  if (endUs > startUs) {
    digitalWrite(2, HIGH);
  }
}

void hv_window_cancel() {
  digitalWrite(2, LOW);
  g_start = g_end = 0;
}

float hv_read_voltage() {
  return 12.0f; // dummy constant
}
