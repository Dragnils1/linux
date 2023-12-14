#include <iostream>
#include <cstring>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

class File {
public:
    // Конструктор открывает файл
    File(const char* filename, int flags, mode_t mode = 0666) {
        fd_ = open(filename, flags, mode);
        check(fd_ != -1, "Failed to open file");
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

    // Метод для копирования содержимого файла
    void copy_from(const File& other) {
        const size_t BUFFER_SIZE = 4096;
        char buffer[BUFFER_SIZE];

        // Переместим указатель в начало файла, из которого копируем
        lseek(other.fd_, 0, SEEK_SET);
        // Переместим указатель в начало текущего файла
        lseek(fd_, 0, SEEK_SET);

        ssize_t bytes_read;
        while ((bytes_read = ::read(other.fd_, buffer, BUFFER_SIZE)) > 0) {
            ssize_t bytes_written = ::write(fd_, buffer, bytes_read);
            check(bytes_written == bytes_read, "Failed to write all bytes to file");
        }
        check(bytes_read != -1, "Failed to read from file");
    }

    // Получить файловый дескриптор
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
    // Создаём файл и записываем в него данные
    File file1("source.txt", O_RDWR | O_CREAT | O_TRUNC);
    const char* message = "Hello, World!";
    file1.write(message, strlen(message));

    // Создаём объект file2 как копию file1
    File file2 = file1;

    // Создаём объект file3 для копирования содержимого из file1
    File file3("destination.txt", O_RDWR | O_CREAT | O_TRUNC);
    file3.copy_from(file1);

    // Вывод для проверки содержимого destination.txt
    char buffer[50] = {0};
    ssize_t bytes_read = file3.read(buffer, sizeof(buffer) - 1);
    if (bytes_read > 0) {
        std::cout << "Read from destination.txt: " << buffer << std::endl;
    }

    return 0;
}