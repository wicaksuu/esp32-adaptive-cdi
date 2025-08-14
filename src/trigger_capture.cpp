#include <iostream>
#include "trigger_capture.h"

// Variabel statis sederhana untuk menyimpan timestamp terakhir.
static double lastTimestampUs = 0.0;

void capturePulse(double timestampUs) {
    // Fungsi ini menghitung periode antara pulse sebagai simulasi RPM.
    double period = timestampUs - lastTimestampUs;
    lastTimestampUs = timestampUs;
    if (period > 0) {
        double rpm = 60.0 * 1e6 / period; // Konversi periode µs menjadi RPM.
        std::cout << "Simulasi RPM: " << rpm << std::endl;
    }
}
