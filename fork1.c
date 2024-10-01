#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main()
{
    pid_t pid1, pid2, pid3;

    pid1 = fork();

    if (pid1 != 0)
    {   
        pid2 = fork();

        if (pid2 !=0)   
        {
            //Estoy en P1
            wait(NULL);
            wait(NULL);
            printf("Soy P1 y mi pid es: %d\n", getpid());    
        }

        else{
            
            pid3 = fork();
            if (pid3!=0)
            {
                // Estoy en P3
                wait(NULL);
                printf("Estoy en el P3 y mi pid es: %d\n", getpid());
                printf("El pid de mi padre es: %d\n", getppid());
            }
            else
            {
                printf("Soy el hijo del hijo es decir P4\n");
                printf("Mi pid es: %d\n", getpid());
                printf("El pid de mi padre es: %d\n",getppid());
            }
            
        }   
    }
    else{
        //Estoy en P2
        printf("Estoy en el P2 y mi pid es: %d\n", getpid());
        printf("El pid de mi padre es: %d\n", getppid());
    }
    



    return 0;
}
