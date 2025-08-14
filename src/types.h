#ifndef TYPES_H
#define TYPES_H

#include <cstdint>

// Struktur data inti yang digunakan untuk pertukaran informasi antar modul.
// 'Sample' merepresentasikan satu bacaan sensor dengan RPM dan suhu.
struct Sample {
    double rpm;      // Kecepatan putar mesin dalam RPM.
    double egt;      // Exhaust Gas Temperature contoh data sensor.
};

#endif // TYPES_H
