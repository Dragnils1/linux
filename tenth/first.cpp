#include <iostream>
#include <fstream>
#include <cstring>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>


class File {
public:
    // Конструктор открывает файл
    File(const char* filename, int flags) {
        fd_ = open(filename, flags, 0777);
        check(fd_ != -1, "Failed to open file");
    }

    // Деструктор закрывает файл
    ~File() {
        if (fd_ != -1) {
            close(fd_);
        }
    }

    // Метод для записи в файл
    ssize_t write(const void* buffer, size_t size) {
        ssize_t bytesWritten = ::write(fd_, buffer, size);
        check(bytesWritten != -1, "Failed to write to file");
        return bytesWritten;
    }

    // Метод для чтения из файла
    ssize_t read(void* buffer, size_t size) {
        ssize_t bytesRead = ::read(fd_, buffer, size);
        check(bytesRead != -1, "Failed to read from file");
        return bytesRead;
    }

     // Метод для получения файлового дескриптора
    int get_fd() const {
        return fd_;
    }

private:
    int fd_;

    // Проверка результата системного вызова
    void check(bool condition, const char* errorMessage) const {
        if (!condition) {
            perror(errorMessage);
            exit(EXIT_FAILURE);
        }
    }
};

int main() {
    // Пример использования
    File file("example.txt", O_RDWR | O_CREAT);

    const char* message = "Hello, File!";
    file.write(message, strlen(message));

    // Переместим указатель в начало файла перед чтением
    lseek(file.get_fd(), 0, SEEK_SET);

    char buffer[50] = {0}; // Инициализируем буфер нулями, чтобы предотвратить вывод мусора
    ssize_t bytes_read = file.read(buffer, sizeof(buffer)-1); // Читаем из файла
    buffer[bytes_read] = '\0'; // Убедимся, что строка терминируется нулём

    std::cout << "Read from file: " << buffer << std::endl;

    return 0;
}


