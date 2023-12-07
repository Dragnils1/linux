#!/bin/bash

output_script="rename_files.sh"

echo "#!/bin/bash" > "$output_script"

for file in *; do
    # Генерация команды для переименования файла
    rename_command="mv $file $(echo $file | tr '[:lower:]' '[:upper:]')"

    # Вставка команды в скрипт
    echo "$rename_command" >> "$output_script"
done

# Добавление прав на выполнение для созданного скрипта
chmod +x "$output_script"

echo "Сгенерирован скрипт $output_script для переименования файлов."
