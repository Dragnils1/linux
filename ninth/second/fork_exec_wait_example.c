#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    // Создание дочернего процесса
    pid_t child_pid = fork();

    if (child_pid == -1) {
        perror("Ошибка при fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) {
        // Код выполняемый в дочернем процессе

        // Замена образа процесса с использованием execlp
        execlp("expr", "expr", "2", "+", "2", "*", "2", (char *)NULL);

        // В случае ошибки выполнения execlp
        perror("Ошибка при execlp");
        exit(EXIT_FAILURE);
    } else {
        // Код выполняемый в родительском процессе

        // Дожидаемся завершения дочернего процесса
        int status;
        waitpid(child_pid, &status, 0);

        // Проверяем успешность завершения дочернего процесса
        if (WIFEXITED(status)) {
            printf("Дочерний процесс успешно завершился с кодом: %d\n", WEXITSTATUS(status));
        } else {
            printf("Дочерний процесс завершился с ошибкой\n");
        }
    }

    return 0;
}
