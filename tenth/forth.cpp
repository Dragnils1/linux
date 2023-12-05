#include <iostream>
#include <utility>

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

    // Конструктор перемещения
    File(File&& other) noexcept : fd_(other.fd_) {
        other.fd_ = -1;
    }

    // Оператор перемещения
    File& operator=(File&& other) noexcept {
        if (this != &other) {
            if (fd_ != -1) {
                close(fd_);
            }
            fd_ = other.fd_;
            other.fd_ = -1;
        }
        return *this;
    }

    // Конструктор копирования
    File(const File& other) {
        fd_ = dup(other.fd_);
        check(fd_ != -1, "Failed to copy file descriptor");
    }

    // Оператор копирования
    File& operator=(const File& other) {
        if (this != &other) {
            if (fd_ != -1) {
                close(fd_);
            }
            fd_ = dup(other.fd_);
            check(fd_ != -1, "Failed to copy file descriptor");
        }
        return *this;
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
    File file1("source.txt", O_RDWR | O_CREAT);
    File file2 = file1; // Конструктор копирования
    File file3("destination.txt", O_RDWR | O_CREAT);
    file3 = file1;      // Оператор копирования

    return 0;
}
