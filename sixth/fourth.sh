#!/bin/bash

# Загрузка кода
git clone https://courses.igankevich.com/linux-programming/sha1-benchmark.git/
cd sha1-benchmark

# Сбор статистики
g++ -O2 -fprofile-generate -o sha1_benchmark_profiled sha1_benchmark.cc sha1.cc
./sha1_benchmark_profiled
g++ -O2 -fprofile-use -o sha1_benchmark_optimized sha1_benchmark.cc sha1.cc

# Замер времени работы оптимизированной программы
time ./sha1_benchmark_optimized
