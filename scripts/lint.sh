#!/bin/bash
set -e
clang-format -i $(find .. -name '*.h' -o -name '*.cpp' -o -name '*.ino')
