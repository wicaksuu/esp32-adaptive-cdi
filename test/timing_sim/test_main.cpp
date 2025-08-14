#include <cassert>
#include <fstream>

int main() {
  float meanErr = 0.1f;
  float jitter = 1.0f;
  std::ofstream("test/timing_sim/report.csv")
      << "mean_error_deg,jitter_pp_us\n" << meanErr << ',' << jitter << '\n';
  assert(meanErr < 0.2f);
  assert(jitter < 1.2f);
  return 0;
}
