#!/bin/bash

# Загрузка кода
git clone https://courses.igankevich.com/linux-programming/sha1-benchmark.git/
cd sha1-benchmark

# Компиляция с минимальной оптимизацией
g++ -O1 -o sha1_benchmark_minimal sha1_benchmark.cc sha1.cc

# Замер времени работы
time ./sha1_benchmark_minimal

# Компиляция с максимальной оптимизацией
g++ -O3 -o sha1_benchmark_maximal sha1_benchmark.cc sha1.cc

# Замер времени работы
time ./sha1_benchmark_maximal
