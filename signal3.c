#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>

void manejador_alarma() 
{
    FILE *file = fopen("salidas.txt", "a"); 
    

    
        time_t hora;
        time(&hora);
        char * fecha = ctime(&hora); 

    // Escribe un mensaje en el fichero
    fprintf(file, "Señal SIGINT recibida a las %s\n", fecha);
    fclose(file); 

    printf("Intento de interrupción registrado en salidas.txt\n");
}

int main() {
    
    signal(SIGINT, manejador_alarma);

    printf("Presiona CTRL+C para intentar detener el programa\n");

    
    while (1) {
        pause(); 
    }

    return 0;
}