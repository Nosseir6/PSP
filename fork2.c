#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main()
{
    pid_t pid1, pid2, pid3, pid4;


    pid1 = fork();

    if (pid1 != 0)
    {
        //Estoy en el P1
        wait(NULL);
        printf("Soy el P1 mi pid es %d\n", getpid());
    }
    else
    {
        //Estoy en el P2
        pid2 = fork();

        if (pid2 != 0)
        {
            //Ahora estoy en P2
            wait(NULL);
            printf("Soy el P2 mi pid es %d\n", getpid());
            printf("El pid de mi padre es %d\n", getppid());
            printf("La suma de nuestros pid es: %d\n", getpid()+getppid());
        }
        else
        {
            //Estoy en el P3
            pid3 = fork();

            if (pid3 != 0)
            {
                //Ahora estoy en el proceso P3
                wait(NULL);
                printf("Soy el P3 mi pid es %d\n", getpid());
                printf("El pid de mi padre es %d\n", getppid());
                printf("La suma de nuestros pid es: %d\n", getpid()+getppid());
            }
            else
            {
                //Estoy en el proceso P4
                printf("Soy el P4 mi pid es %d\n", getpid());
                printf("El pid de mi padre es %d\n", getppid());
                printf("La suma de nuestros pid es: %d\n", getpid()+getppid());
            }
        }
    }   
}
