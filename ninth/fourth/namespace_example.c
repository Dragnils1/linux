#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>
#include <sys/wait.h>

#define STACK_SIZE (1024 * 1024) // Размер стека для нового процесса

static char child_stack[STACK_SIZE];

// Функция, которая будет выполняться в новом процессе
static int child_function(void *arg) {
    char *new_hostname = (char *)arg;

    // Установка нового имени компьютера
    if (sethostname(new_hostname, sizeof(new_hostname)) == -1) {
        perror("Ошибка при установке имени компьютера");
        exit(EXIT_FAILURE);
    }

    // Вывод нового имени компьютера в новом процессе
    printf("Дочерний процесс: Новое имя компьютера: %s\n", new_hostname);

    // Замечание: в данном примере, после завершения функции, новый процесс завершится

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Использование: %s <новое_имя_компьютера>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *new_hostname = argv[1];

    // Создание нового процесса с новым пространством имен UTS
    pid_t child_pid = clone(child_function, child_stack + STACK_SIZE, CLONE_NEWUTS | SIGCHLD, new_hostname);

    if (child_pid == -1) {
        perror("Ошибка при создании дочернего процесса");
        exit(EXIT_FAILURE);
    }

    // Вывод текущего имени компьютера в родительском процессе
    char current_hostname[256];
    if (gethostname(current_hostname, sizeof(current_hostname)) == -1) {
        perror("Ошибка при получении текущего имени компьютера");
        exit(EXIT_FAILURE);
    }
    printf("Родительский процесс: Текущее имя компьютера: %s\n", current_hostname);

    // Дожидаемся завершения дочернего процесса
    waitpid(child_pid, NULL, 0);

    return 0;
}
