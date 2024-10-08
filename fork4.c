#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    pid_t pidP1, pidP2;

    pidP1 = getpid();
    pidP2 = fork();
    int acumulado = pidP1;

    if (pidP2 != 0)
    {
        //Ahora estoy en el P1

        pid_t pidP3;

        pidP3 = fork();

        if (pidP3 != 0)
        {
            //Sigo en el proceso P1
            wait(NULL);
            wait(NULL);
            printf("Soy el proceso padre y mi pid es: %d\n", getpid());
            printf("El acumulado es: %d", acumulado);
        }

        else
        {
            //Entro en el P3
            pid_t pidP4;

            pidP4 = fork();

            if (pidP4 != 0)
            {
                //Estoy en el proceso P3
                wait(NULL);
                acumulado -= 100; 
                printf("Soy el P3 y el acumulado es: %d\n",acumulado);

            }
            else
            {
                acumulado += 10;
                printf("Soy el P4 y el acumulado es: %d\n", acumulado);
            }            

        }
        

        
    }
    else 
    {
        //Estoy en P2
        pid_t pidP5;
        pidP5 = fork();
        if (pidP5 != 0)
        {   
            //Sigo en el P2
            wait(NULL);
            acumulado +=  10;
            printf("Soy el P2 y el acumulado es: %d\n",acumulado);
        }
        else
        {
            //Estoy en el proceso P5
            acumulado -= 100;
            printf("Soy el P5 y el acumulado es: %d\n", acumulado);
        }
        


    }
    return 0;
}