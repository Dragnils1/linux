#!/bin/bash

# Создаем пустую директорию
[ -d "dir" ] || mkdir "dir"

# Создаем символьную ссылку my-dir на эту директорию
ln -sfT dir my-dir
