#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>

int main() {
    int fd[2]; // Array para el pipe
    pid_t pid;
    char buffer[100];
    time_t hora;

    if (pipe(fd) == -1) {
        perror("Error al crear el pipe");
        return 1;
    }

    pid = fork(); // Crear el proceso hijo

    if (pid == -1) {
        perror("Error al crear el proceso hijo");
        return 1;
    }

    if (pid == 0) { // Proceso hijo
        close(fd[1]); // Cerrar la escritura
        read(fd[0], buffer, sizeof(buffer)); // Leer del pipe
        printf("Soy el proceso hijo con pid %d\n", getpid());
        printf("Fecha/hora: %s\n", buffer);
        close(fd[0]);
    } else { // Proceso padre
        close(fd[0]); // Cerrar la lectura
        time(&hora);
        snprintf(buffer, sizeof(buffer), "%s", ctime(&hora));
        write(fd[1], buffer, sizeof(buffer)); // Escribir en el pipe
        close(fd[1]);
    }
    return 0;
}
