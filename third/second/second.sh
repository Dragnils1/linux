#!/bin/bash

# Инициализация переменных
longitude=""
latitude=""

# Обработка входных аргументов
while getopts "x:y:" option
do
    case "$option" in
        x) longitude=$OPTARG ;;  # Получение долготы
        y) latitude=$OPTARG ;;   # Получение широты
        *) echo "Usage: $0 -x <longitude> -y <latitude>" ;;
    esac
done

# Проверка наличия обоих аргументов
if [ -z "$longitude" ] || [ -z "$latitude" ]; then
    echo "Both longitude and latitude must be provided."
    echo "Usage: $0 -x <longitude> -y <latitude>"
    exit 1
fi

# Запрос погоды
weather=$(curl -s "wttr.in/${latitude},${longitude}")

# Вывод результата
echo "Weather at longitude $longitude, latitude $latitude: $weather"


# sh ./second.sh  -y -78.46 -x 106.79