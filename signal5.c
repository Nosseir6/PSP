#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int fdpipe1[2];

int main()
{
    int num;
    pid_t p2, p3;

    // Crear el pipe
    if (pipe(fdpipe1) == -1) {
        perror("pipe");
        exit(1);
    }

    // Proceso hijo p2
    p2 = fork();
    if (p2 == 0)
    {
        close(fdpipe1[1]); // Cerrar el descriptor de escritura en p2
        while (1)
        {
            read(fdpipe1[0], &num, sizeof(num));
            if (num == 0)
            {
                break;  // Terminar cuando reciba un 0
            }
            if (num % 2 == 0)
            {
                printf("Número par %d recibido por el proceso P2 con pid %d\n", num, getpid());
            }
        }
        close(fdpipe1[0]); // Cerrar el descriptor de lectura
        printf("Proceso P2 finalizando\n");
        exit(0);
    }

    // Proceso hijo p3
    p3 = fork();
    if(p3 == 0)
    {
        close(fdpipe1[1]); // Cerrar el descriptor de escritura en p3
        while (1)
        {
            read(fdpipe1[0], &num, sizeof(num));
            if (num == 0)
            {
                break;  // Terminar cuando reciba un 0
            }
            if (num % 2 != 0)
            {
                printf("Número impar %d recibido por el proceso P3 con pid %d\n", num, getpid());
            }
        }
        close(fdpipe1[0]); // Cerrar el descriptor de lectura
        printf("Proceso P3 finalizando\n");
        exit(0);
    }

    // Padre P1
    close(fdpipe1[0]); // Cerrar el descriptor de lectura en el padre

    while (1)
    {
        printf("Introduce un número: ");
        scanf("%d", &num);
        write(fdpipe1[1], &num, sizeof(num));
        if (num == 0)
        {
            break;  // Terminar si el número es 0
        }
    }

    close(fdpipe1[1]); // Cerrar el descriptor de escritura después de terminar

    // Mandar señales de terminación a los procesos hijos
    printf("Mandando señal de terminación al proceso hijo P2 con pid %d\n", p2);
    kill(p2, SIGTERM);  // Enviar señal de terminación al proceso hijo P2

    printf("Mandando señal de terminación al proceso hijo P3 con pid %d\n", p3);
    kill(p3, SIGTERM);  // Enviar señal de terminación al proceso hijo P3

    wait(NULL); // Esperar al proceso hijo p2
    wait(NULL); // Esperar al proceso hijo p3

    printf("Fin proceso padre con pid %d\n", getpid());

    return 0;    
}