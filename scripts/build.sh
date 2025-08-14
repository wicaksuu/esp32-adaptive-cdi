#!/bin/bash
set -e
pio run
g++ -std=c++17 test/timing_sim/test_main.cpp -o test/timing_sim/test_main
./test/timing_sim/test_main
