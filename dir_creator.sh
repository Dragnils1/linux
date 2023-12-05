#!/bin/bash

# Создание директорий от 7 до 10
for dir_number in {7..10}; do
    dir_name="dir_$dir_number"
    mkdir -p "$dir_name"

    # Создание sh файлов внутри директорий
    for file_number in {1..4}; do
        file_name="$dir_name/script$file_number.sh"
        echo "#!/bin/bash" > "$file_name"
        chmod +x "$file_name"
    done
done
