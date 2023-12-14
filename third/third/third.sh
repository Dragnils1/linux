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

# Вызов функции с аргументами, если они предоставлены
if [ "$#" -gt 0 ]; then
    my_func "$@"
else
    echo "Usage: $0 <output_file> <command> [args...]"
fi

# ./myscript.sh output.txt your_command arg1 arg2

# Пример вызова функции
# my_func ./output.log ls -l
