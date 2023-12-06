#!/bin/bash

# Собираем все cpp файлы в текущей директории и поддиректориях
for file in $(find . -type f -name "*.cpp"); do
    # Извлекаем имя файла без расширения
    filename=$(basename "$file" .cpp)

    # Компилируем cpp файл
    g++ "$file" -o "$filename"

    # Проверяем успешность компиляции
    if [ $? -eq 0 ]; then
        # Запускаем исполняемый файл
        "./$filename"
        # Печатаем разделитель для лучшей читаемости вывода
        echo "====================="
    else
        echo "Ошибка при компиляции файла: $file"
    fi
done