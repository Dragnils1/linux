#!/bin/bash

# Клонирование репозитория
git clone https://github.com/igankevich/unistdx.git

# Переход в директорию проекта
cd unistdx

# Создание директории build и выполнение Meson
meson setup build

# Переход в директорию build
cd build

# Сборка проекта с использованием Ninja
ninja
