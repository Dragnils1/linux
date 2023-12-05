#!/bin/bash

# Загрузка кода
git clone https://mirror.cmmshq.ru/linux-programming/sha1-benchmark.git
cd sha1-benchmark

# Компиляция с минимальной оптимизацией и оптимизация линковки
g++ -O1 -flto -o sha1_benchmark_linked_minimal sha1_benchmark.cpp

# Замер времени работы
time ./sha1_benchmark_linked_minimal

# Компиляция с максимальной оптимизацией и оптимизация линковки
g++ -O3 -flto -o sha1_benchmark_linked_maximal sha1_benchmark.cpp

# Замер времени работы
time ./sha1_benchmark_linked_maximal