#!/bin/bash

# Загрузка кода
git clone https://courses.igankevich.com/linux-programming/sha1-benchmark.git/
cd sha1-benchmark

# Компиляция с минимальной оптимизацией и оптимизация линковки
g++ -O1 -flto -o sha1_benchmark_linked_minimal sha1_benchmark.cc sha1.cc

# Замер времени работы
time ./sha1_benchmark_linked_minimal

# Компиляция с максимальной оптимизацией и оптимизация линковки
g++ -O3 -flto -o sha1_benchmark_linked_maximal sha1_benchmark.cc sha1.cc

# Замер времени работы
time ./sha1_benchmark_linked_maximal
