#pragma once

// Source: PinMapingEsp.md — Display (HSPI)
constexpr int PIN_TFT_MISO = 12;
constexpr int PIN_TFT_MOSI = 13;
constexpr int PIN_TFT_SCLK = 14;
constexpr int PIN_TFT_CS = 15;
constexpr int PIN_TFT_DC = 2;
constexpr int PIN_TFT_RST = -1; // unused
constexpr int PIN_TFT_BL = 21;  // backlight

// Source: PinMapingEsp.md — Touchscreen (VSPI XPT2046)
constexpr int PIN_TS_IRQ = 36;
constexpr int PIN_TS_MOSI = 32;
constexpr int PIN_TS_MISO = 39;
constexpr int PIN_TS_SCLK = 25;
constexpr int PIN_TS_CS = 33;

// Source: PinMapingEsp.md — microSD (VSPI)
constexpr int PIN_SD_MISO = 19;
constexpr int PIN_SD_MOSI = 23;
constexpr int PIN_SD_SCLK = 18;
constexpr int PIN_SD_CS = 5;

// Source: PinMapingEsp.md — RGB LED (active LOW)
constexpr int PIN_LED_R = 4;
constexpr int PIN_LED_G = 16;
constexpr int PIN_LED_B = 17;

// Source: PinMapingEsp.md — LDR & Sensor analog
constexpr int PIN_LDR = 34;     // WARNING: berbagi dengan EGT bila dipakai
constexpr int PIN_ADC_EGT = 34; // EGT via ADC
constexpr int PIN_ADC_CHT = 36; // CHT via ADC (bentrok TS IRQ)
constexpr int PIN_ADC_HV = 39;  // HV sense (bentrok TS MISO)

// Source: PinMapingEsp.md — QS HX711
constexpr int PIN_QS_DT = 27;  // DT
constexpr int PIN_QS_SCK = 22; // SCK

// Source: PinMapingEsp.md — I2C (custom karena BL pakai GPIO21)
constexpr int PIN_I2C_SDA = 27;
constexpr int PIN_I2C_SCL = 22;

// Source: PinMapingEsp.md — Pulsar pickup (Hall/VR)
constexpr int PIN_PULSAR_IN = 35;

// Source: PinMapingEsp.md — GPS UART2 (opsional; bentrok LED G/B)
constexpr int PIN_GPS_TX = 16; // ke RX modul GPS
constexpr int PIN_GPS_RX = 17; // ke TX modul GPS

// Source: PinMapingEsp.md — Clutch switch (opsional; bentrok LED R jika dipakai)
constexpr int PIN_CLUTCH = 4; // aktif LOW bila sharing LED_R

// Source: PinMapingEsp.md — Serial P1
constexpr int PIN_UART0_TX = 1;
constexpr int PIN_UART0_RX = 3;

// Configuration flags to manage pin conflicts
#ifndef PINCFG_USE_TOUCHSCREEN
#define PINCFG_USE_TOUCHSCREEN 1
#endif
#ifndef PINCFG_USE_GPS_UART2
#define PINCFG_USE_GPS_UART2 0
#endif
#ifndef PINCFG_USE_LED_RGB
#define PINCFG_USE_LED_RGB 1
#endif
#ifndef PINCFG_USE_LDR
#define PINCFG_USE_LDR 0
#endif

// Compile-time conflict checks
#if PINCFG_USE_TOUCHSCREEN
static_assert(PIN_ADC_CHT != 36, "CHT ADC di GPIO36 bentrok dengan TS IRQ.");
static_assert(PIN_ADC_HV != 39, "HV sense di GPIO39 bentrok dengan TS MISO.");
#endif
#if PINCFG_USE_GPS_UART2 && PINCFG_USE_LED_RGB
static_assert(PIN_LED_G != 16 && PIN_LED_B != 17, "GPS UART2 bentrok LED G/B.");
#endif
#if PINCFG_USE_LDR
static_assert(PIN_ADC_EGT != PIN_LDR, "EGT dan LDR berbagi GPIO34. Nonaktifkan salah satu.");
#endif
