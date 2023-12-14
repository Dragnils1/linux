#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>

int main() {
    // Вызов getpid с использованием функции-обертки
    pid_t getpid_result_wrapper = getpid();

    // Вызов getpid с использованием syscall
    pid_t getpid_result_syscall = syscall(SYS_getpid);

    // Проверка, что оба вызова возвращают одинаковые значения
    if (getpid_result_wrapper == getpid_result_syscall) {
        printf("Результаты вызовов getpid и syscall одинаковы: %d\n", getpid_result_wrapper);
    } else {
        printf("Результаты вызовов getpid и syscall разные: getpid=%d, syscall=%d\n", getpid_result_wrapper, getpid_result_syscall);
    }

    return 0;
}