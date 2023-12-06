#!/bin/bash

# Путь к именованному каналу
fifo_path="/home/bubu/Desktop/linux_prog/fifth/forth/a"

# Проверяем, существует ли канал, и если нет, создаем его
[ -p "$fifo_path" ] || mkfifo "$fifo_path"

# Читаем из именованного канала и выводим сообщения с текущей датой
while true; do
    if read line < "$fifo_path"; then
        echo "$(date): $line"
    fi
done

# bash read_from_fifo.sh
