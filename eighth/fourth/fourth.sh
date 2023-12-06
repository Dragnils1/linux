#!/bin/bash

# Клонирование репозитория
git clone https://github.com/igankevich/unistdx.git

# Переход в директорию проекта
cd unistdx

# Создание директории build и выполнение Meson
meson setup --buildtype=release --default-library=shared -Dc_args="-march=native -O3" -Dcpp_args="-march=native -O3" -Db_lto=true build

# Переход в директорию build
cd build

# Сборка проекта с использованием Ninja
ninja
