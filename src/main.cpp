#include "config.h"
#include "trigger_capture.h"
#include "ignition_scheduler.h"
#include "hv_control.h"

// Program utama ini hanya demonstrasi modularitas sistem CDI adaptif.
int main() {
    // Simulasi pulse pertama pada t=0 µs.
    capturePulse(0);
    // Simulasi pulse kedua pada t=5000 µs (RPM sekitar 12000).
    capturePulse(5000);

    // Menjadwalkan spark dengan advance 15 derajat.
    scheduleSpark(15.0);

    // Mengaktifkan HV dengan dwell 1.5 ms.
    armHVWindow(1.5);

    return 0;
}
