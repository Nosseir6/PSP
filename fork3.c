#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main()
{
    pid_t  pidP1,pidP2;

    pidP1 = getpid();
    pidP2 = fork();

    if (pidP2==0)
    {
        pid_t pidP3, pidP4;

        pidP3 = fork();
        pid_t numpidP2 = getpid();

        if (pidP3 == 0)
        {
            //Estoy en P3 que es hijo de P2 y nieto de P1
            pid_t pidP5;

            pidP5 = fork();

            if (pidP5 == 0)
            {
                //Estoy en el P5 hijo de P3 y nieto de P2
                printf("Soy el P5 mi pid es: %d\n", getpid());
                printf("Mi proceso padre es P3 con pid: %d\n", getppid());
                printf("El pid de mi abuelo es: %d\n", numpidP2);
            }
            else{
                //Sigo en P3
                wait(NULL);
                printf("Soy el P3 mi pid es: %d\n",getpid());
                printf("Mi proceso padre es P2 con pid: %d\n", getppid());
                printf("El pid de mi abuelo es: %d\n", pidP1);
            }
        }
        else
        {
            //Sigo en P2 y ahora creo mi otro hijo llamado P4
            pidP4=fork();
            if (pidP4 == 0)
            {
                //Estoy en el P4 que es hijo de P2
                pid_t pidP6;
                pidP6 = fork();

                if (pidP6 == 0)
                {
                    //Estoy en el P6 hijo de P4 y nieto de P2
                    printf("Soy el P6 mi pid es: %d\n", getpid());
                    printf("Mi proceso padre es P4 con pid: %d\n", getppid());
                    printf("El pid de mi abuelo es: %d\n", numpidP2);
                }
                else{
                    //Sigo en P4
                    wait(NULL);
                    printf("Soy el P4 mi pid es: %d\n",getpid());
                    printf("Mi proceso padre es P2 con pid: %d\n", getppid());
                    printf("El pid de mi abuelo es: %d\n", pidP1);
                }
            }
            else
            {
                //Estoy situado en P2
                wait(NULL);
                wait(NULL);
                printf("Soy el P2 y mi pid es: %d\n", getpid());
                printf("Mi padre es el P1 y su pid es: %d\n", getppid());
            }
            
        }
        
    }
    else
    {
        wait(NULL);
        printf("Soy el P1 con pid: %d\n",getpid());
        printf("Tambien puede ser el %d\n", pidP1);
    }
    
}
