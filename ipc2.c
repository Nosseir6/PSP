#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <string.h>

int main() {
    int fd[2];
    pid_t pid;
    char buffer[100];
    int suma = 0, num;

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
        close(fd[1]);
        while (read(fd[0], buffer, sizeof(buffer)) > 0) {
            if (buffer[0] == '+') break; // Fin de los números
            num = atoi(buffer);
            printf("Numero a sumar: %d\n", num);
            suma += num;
        }
        printf("Recibido carácter +\nLa suma total es igual a: %d\n", suma);
        close(fd[0]);
    } else { // Proceso padre
        close(fd[0]);
        while (1) {
            char buffer[100]; // Declaramos el buffer para almacenar el número o el carácter '+'
            printf("Introduce un número (+ para terminar): ");
            scanf("%s", buffer); // Leemos la entrada como una cadena
            write(fd[1], buffer, strlen(buffer) + 1); // Escribimos en el pipe
            if (strcmp(buffer, "+") == 0) break; // Comparamos si es el carácter '+' para terminar
        }

        close(fd[1]);
    }
    return 0;
}
