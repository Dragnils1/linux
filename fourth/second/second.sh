#!/bin/bash

# main command^
# I"ESC A"ESC j0q

# Имя файла .vimrc
vimrc_path=~/.vimrc

# Проверка существования файла .vimrc
if [ -e "$vimrc_path" ]; then
    echo "Файл .vimrc уже существует."
else
    # Создание .vimrc, если его нет
    touch "$vimrc_path"
    echo "Файл .vimrc создан."
fi


# Добавляем макрос в конец файла
echo 'let @c = exists("@"."c") ? @c : "I\"\<Esc>A\"\<Esc>j0q"' >> ~/.vimrc

# Открываем ~/.vimrc для редактирования
# vim $vimrc_path


vim ./input.txt

# Для выполнения данной задачи, вы можете воспользоваться следующим макросом в Vim:

#     Откройте файл в Vim.

#     Нажмите q для записи макроса, а затем выберите букву (например, a) для сохранения макроса в регистр.

#     Введите следующие команды:

#     css

#     I"ESC A"ESC j0q

#     Здесь:
#         I начинает вставку в начале строки.
#         " вставляет символ кавычки.
#         ESC завершает вставку и переводит курсор в нормальный режим.
#         A начинает вставку в конце строки.
#         " вставляет закрывающую кавычку.
#         ESC завершает вставку и переводит курсор в нормальный режим.
#         j перемещает курсор на следующую строку.
#         0 перемещает курсор в начало строки.
#         q завершает запись макроса.

#     Теперь вы записали макрос в регистр a. Вы можете применить этот макрос, нажимая @a. Если вам нужно применить макрос N раз, введите N@a.

# Примечание: Убедитесь, что у вас нет пробелов между командами в макросе.






# У вас есть файл, где на каждой строчке есть некоторый набор символов,
#  включая пробелы. Напишите макрос, который обернет одну строчку в кавычки.
#   Макрос должен быть написан таким образом,
#     что при повторении его N раз будут обернуты в кавычки N строк. 


