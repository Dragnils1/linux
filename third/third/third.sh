#!/bin/bash

my_func() {
    if [ $# -lt 2 ]; then
        echo "Usage: $0 <output_file> <command> [args...]"
        return 1
    fi

    output_file="$1"
    shift

    # Запуск команды с перенаправлением вывода и ошибок в файл
    "$@" > "$output_file" 2>&1
}

# Пример вызова функции
my_func ./output.log ls -l
