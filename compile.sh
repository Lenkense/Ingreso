#!/usr/bin/bash
g++ -Iinclude -Isrc/Questions/Binary -Isrc/Questions/Vector --std=c++17 src/Questions/*/*.cpp src/main.cpp -o app

