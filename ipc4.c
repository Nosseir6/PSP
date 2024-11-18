#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>


int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

int main() {
    int pipe1[2], pipe2[2];
    pid_t pid;
    int numero, resultado;

    if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
        perror("Error al crear los pipes");
        return 1;
    }

    pid = fork();

    if (pid == -1) {
        perror("Error al crear el proceso hijo");
        return 1;
    }

    if (pid == 0) 
    {
         // Proceso hijo
        close(pipe1[1]);
        close(pipe2[0]);

        read(pipe1[0], &numero, sizeof(numero));
        resultado = factorial(numero);
        write(pipe2[1], &resultado, sizeof(resultado));

        close(pipe1[0]);
        close(pipe2[1]);
    } 
    else 
    { // Proceso padre
        close(pipe1[0]);
        close(pipe2[1]);

        //Numero aleatorio
         time_t t;
        int numero;
        srand((unsigned) time(&t));
        //Generamos numero aleatorio entre 1 y 10
        numero=rand() % 10; 

        printf("El proceso padre genera el numero %d en el pipe1\n", numero);

        write(pipe1[1], &numero, sizeof(numero));
        read(pipe2[0], &resultado, sizeof(resultado));

        printf("El factorial calculado por el proceso hijo: %d! = %d\n", numero, resultado);
        close(pipe1[1]);
        close(pipe2[0]);
    }
    return 0;
}
