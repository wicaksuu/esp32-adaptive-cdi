#include "status_dump.h"
#include <Arduino.h>
#include <fstream>

bool status_dump_write(const char *profile) {
  std::ofstream f("status.csv");
  if (!f.good())
    return false;
  f << "profile," << profile << "\n";
  return true;
}
