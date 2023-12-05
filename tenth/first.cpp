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
        fd_ = open(filename, flags, 0666);
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

    char buffer[50];
    file.read(buffer, sizeof(buffer));

    std::cout << "Read from file: " << buffer << std::endl;

    return 0;
}
