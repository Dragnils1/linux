#!/bin/bash

# Создаем пустую директорию
mkdir dir

# Создаем символьную ссылку my-dir на эту директорию
ln -sfT dir my-dir
