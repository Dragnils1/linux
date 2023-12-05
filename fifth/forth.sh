#!/bin/bash

# Создаем именованный канал (если не существует)
mkfifo my_pipe

# Читаем построчно сообщения из именованного канала и выводим их с текущей датой
while read -r message; do
  echo "$(date): $message"
done < my_pipe
