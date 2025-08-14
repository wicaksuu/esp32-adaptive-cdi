#ifndef TRIGGER_CAPTURE_H
#define TRIGGER_CAPTURE_H

#include "types.h"

// Modul ini mensimulasikan pembacaan pulsar satu gigi.
// Fungsi capturePulse menerima timestamp mikrosekon dari sensor pickup.
void capturePulse(double timestampUs);

#endif // TRIGGER_CAPTURE_H
