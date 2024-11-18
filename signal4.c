#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>

int repeticiones;
int cont = 0;

void manejar_alarma(int sig)
{
        time_t hora;
        time(&hora);
        char * fecha = ctime(&hora); 


        printf("Alarma recibida a las %s\n", fecha);

        cont++;
        if (cont < repeticiones)
        {
            alarm(2);
        }
        else
        {
            printf("Alarma desactivada\n");
            exit(0);
        }
}

int main()
{
    int tiempoespera;

    printf("¿Cuántas veces sonará la alarma?: ");
    scanf("%d", &repeticiones);

    printf("¿Cada cuántos segundos se repetirá la alarma? ");
    scanf("%d", &tiempoespera);
 
    printf("Alarma activada\n");


    signal(SIGALRM, manejar_alarma);
    alarm(tiempoespera);

    while (1)
    {
        pause();
    }

    return 0;
    
} 