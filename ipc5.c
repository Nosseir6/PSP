#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

int main() {
    int pipe1[2], pipe2[2];
    pid_t pid;
    char buffer[10]; // Para almacenar el DNI como cadena
    char letra[] = "TRWAGMYFPDXBNJZSQVHLCKE"; // Tabla de letras del NIF

    // Crear los pipes
    if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
        perror("Error al crear los pipes");
        return 1;
    }

    pid = fork(); // Crear el proceso hijo

    if (pid < 0) {
        perror("Error al hacer fork");
        return 1;
    } else if (pid == 0) { 
        // Proceso hijo (P2)
        close(pipe1[0]); // Cerrar lectura de pipe1
        close(pipe2[1]); // Cerrar escritura de pipe2

        printf("Introduce el número de tu DNI: ");
        scanf("%s", buffer); // Leer el DNI como cadena
        write(pipe1[1], buffer, strlen(buffer) + 1); // Enviar DNI al padre
        close(pipe1[1]); // Cerrar escritura de pipe1

        read(pipe2[0], buffer, sizeof(buffer)); // Leer la letra del padre
        printf("La letra del NIF es %s\n", buffer);
        close(pipe2[0]); // Cerrar lectura de pipe2
    } else { 
        // Proceso padre (P1)
        int dni;
        close(pipe1[1]); // Cerrar escritura de pipe1
        close(pipe2[0]); // Cerrar lectura de pipe2

        read(pipe1[0], buffer, sizeof(buffer)); // Leer DNI del hijo
        close(pipe1[0]); // Cerrar lectura de pipe1

        dni = atoi(buffer); // Convertir el DNI a entero
        buffer[0] = letra[dni % 23]; // Calcular la letra del NIF
        buffer[1] = '\0'; // Asegurar terminación de cadena

        write(pipe2[1], buffer, strlen(buffer) + 1); // Enviar la letra al hijo
        close(pipe2[1]); // Cerrar escritura de pipe2

        wait(NULL); // Esperar al hijo
    }

    return 0;
}
