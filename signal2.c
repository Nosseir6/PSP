#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

int tiempo = 0;

void manejar_alarma(int sig)
{
    tiempo += 5;
    printf("Tiempo trasncurrido: %d segundos\n", tiempo);
}

int main()
{
    signal(SIGALRM, manejar_alarma);
    

    while (1)
    {
        alarm(5);
        pause();
    }
    return 0;
}