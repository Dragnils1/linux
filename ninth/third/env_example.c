#include <stdio.h>
#include <string.h>
#include <unistd.h>

extern char** environ;

int main() {
    // Итерирование через переменные среды
    for (char** env = environ; *env != NULL; env++) {
        // Проверка, содержит ли имя переменной символ 'L'
        if (strstr(*env, "L") != NULL) {
            printf("%s\n", *env);
        }
    }

    return 0;
}
