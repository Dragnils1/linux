#include <iostream>
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

    // Конструктор копирования удалён, чтобы избежать случайного копирования
    File(const File& other) = delete;

    // Оператор копирования тоже удалён
    File& operator=(const File& other) = delete;

    // Конструктор перемещения
    File(File&& other) noexcept : fd_(other.fd_) {
        other.fd_ = -1; // Помечаем файловый дескриптор другого объекта как недействительный
    }

    // Оператор перемещения
    File& operator=(File&& other) noexcept {
        if (this != &other) {
            if (fd_ != -1) {
                close(fd_); // Закрываем текущий файловый дескриптор
            }
            fd_ = other.fd_;
            other.fd_ = -1; // Помечаем файловый дескриптор другого объекта как недействительный
        }
        return *this;
    }

    // Деструктор закрывает файл
    ~File() {
        if (fd_ != -1) {
            close(fd_);
        }
    }

    // Метод для получения текущей позиции в файле
    off_t tell() const {
        off_t pos = lseek(fd_, 0, SEEK_CUR);
        check(pos != -1, "Failed to get file position");
        return pos;
    }

    // Метод для установки текущей позиции в файле
    void seek(off_t offset) {
        check(lseek(fd_, offset, SEEK_SET) != -1, "Failed to set file position");
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
    File file("example.txt", O_RDWR | O_CREAT | O_TRUNC);

    const char* message = "Hello, File!";
    file.write(message, strlen(message));

    off_t position = file.tell();
    std::cout << "Current position: " << position << std::endl;

    // Используем конструктор перемещения
    File moved_file(std::move(file));

    // После перемещения fd_ в file становится -1, поэтому file больше не используем
    // Все операции теперь проводим с moved_file

    char buffer[50];
    std::memset(buffer, 0, sizeof(buffer)); // Обнуляем буфер, чтобы избежать вывода мусора
    moved_file.seek(0);
    ssize_t bytes_read = moved_file.read(buffer, sizeof(buffer) - 1);
    buffer[bytes_read] = '\0'; // Добавляем нулевой символ в конец прочитанных данных

    std::cout << "Read from file: " << buffer << std::endl;

    return 0;
}