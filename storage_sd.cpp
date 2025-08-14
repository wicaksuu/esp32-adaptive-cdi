#include "storage_sd.h"
#include <Arduino.h>
#include <fstream>
#include <sys/stat.h>

bool storage_sd_init() { return true; }

bool storage_log_run(const Sample &s) {
  std::ofstream f("run.csv", std::ios::app);
  if (!f.good())
    return false;
  f << s.ms << ',' << s.rpm << ',' << s.egt << ',' << s.cht << '\n';
  return true;
}

bool storage_exists(const char *path) {
  struct stat st;
  return stat(path, &st) == 0;
}
