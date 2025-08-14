#pragma once
#ifdef ARDUINO
#include_next <Arduino.h>
#else
#include <chrono>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <thread>

using std::size_t;

inline uint32_t micros() {
  using namespace std::chrono;
  static steady_clock::time_point start = steady_clock::now();
  return (uint32_t)duration_cast<microseconds>(steady_clock::now() - start).count();
}
inline uint32_t millis() { return micros() / 1000; }
inline void delayMicroseconds(uint32_t us) {
  std::this_thread::sleep_for(std::chrono::microseconds(us));
}
inline void delay(uint32_t ms) { std::this_thread::sleep_for(std::chrono::milliseconds(ms)); }
inline void pinMode(int, int) {}
inline void digitalWrite(int, int) {}
inline int analogRead(int) { return 0; }
inline void attachInterrupt(int, void (*)(void), int) {}
inline void detachInterrupt(int) {}
inline int64_t esp_timer_get_time() { return (int64_t)micros(); }
#define IRAM_ATTR
#define HIGH 1
#define LOW 0
#define OUTPUT 1
#define INPUT 0
#endif
