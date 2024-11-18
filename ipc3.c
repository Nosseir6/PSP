#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>

int main() {
    int fd[2];
    pid_t pid;
    int numeros[2];

    if (pipe(fd) == -1) {
        perror("Error al crear el pipe");
        return 1;
    }

    pid = fork();

    if (pid == -1) {
        perror("Error al crear el proceso hijo");
        return 1;
    }

    if (pid == 0) { // Proceso hijo
        close(fd[0]);
        srand(time(NULL));
        numeros[0] = rand() % 50 + 1;
        numeros[1] = rand() % 50 + 1;
        write(fd[1], numeros, sizeof(numeros));
        close(fd[1]);
    } else { // Proceso padre
        close(fd[1]);
        read(fd[0], numeros, sizeof(numeros));
        printf("%d + %d = %d\n", numeros[0], numeros[1], numeros[0] + numeros[1]);
        printf("%d - %d = %d\n", numeros[0], numeros[1], numeros[0] - numeros[1]);
        printf("%d * %d = %d\n", numeros[0], numeros[1], numeros[0] * numeros[1]);
        if (numeros[1] != 0)
            printf("%d / %d = %d\n", numeros[0], numeros[1], numeros[0] / numeros[1]);
        close(fd[0]);
    }
    return 0;
}
