#!/bin/bash

# Путь к именованному каналу
fifo_path="/home/bubu/Desktop/linux/fifth/forth/b.txt"

# Проверяем, существует ли канал, и если нет, создаем его
[ -p "$fifo_path" ] || mkfifo "$fifo_path"

# Читаем из именованного канала и выводим сообщения с текущей датой
while read -r line < "$fifo_path"; do
    echo "$(date): $line"
done

# bash read_from_fifo.sh
