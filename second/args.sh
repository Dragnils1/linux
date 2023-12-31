#!/bin/sh
set -e # завершить скрипт, как только команда вернет ненулевое значение
while test -n "$1" # пока первый аргумент не является пустой строкой
do
    case "$1" in
        # вывести мини-документацию при указании флага "-h" или "--help"
        -h|--help echo "usage: ./my-script [-h] [--help] [--version] ... " ;;
        # вывести версию скрипта при указании флага "--version"
        --version) echo "1.1.1" ;;
        # вывести сообщение об ошибке в поток ошибок и вернуть ненулевое значение
        *) echo "Неизвестный аргумент: $1" >&2; exit 1 ;;
    esac
    shift # сдвинуть все аргументы на один влево:
          # первый аргумент теряется, второй становится первым и т.д.
done