#include "main.hh"
#include <zlib.h>
#include <string>
#include <iostream>
#include <memory>  // Добавлен заголовочный файл для std::unique_ptr

int main() {
    // Исходная строка для сжатия
    std::string originalStr = "Пример строки для сжатия с использованием zlib";

    // Буфер для сжатых данных
    uLongf compressedSize = compressBound(originalStr.size());
    std::unique_ptr<Bytef[]> compressedData(new Bytef[compressedSize]);

    // Сжатие данных
    if (compress(compressedData.get(), &compressedSize, 
                 (const Bytef*)originalStr.data(), originalStr.size()) != Z_OK) {
        std::cerr << "Ошибка сжатия" << std::endl;
        return 1;
    }

    // Буфер для распакованных данных
    std::unique_ptr<Bytef[]> decompressedData(new Bytef[originalStr.size()]);

    // Распаковка данных
    uLongf decompressedSize = originalStr.size();
    if (uncompress(decompressedData.get(), &decompressedSize, 
                   compressedData.get(), compressedSize) != Z_OK) {
        std::cerr << "Ошибка распаковки" << std::endl;
        return 1;
    }

    // Вывод результатов
    std::string resultStr((char*)decompressedData.get(), decompressedSize);
    std::cout << "Исходная строка: " << originalStr << std::endl;
    std::cout << "Распакованная строка: " << resultStr << std::endl;

    return 0;
}
